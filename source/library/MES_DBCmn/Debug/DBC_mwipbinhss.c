
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
    "DBC_mwipbinhss.pc"
};


static unsigned int sqlctx = 9140323;


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
            void  *sqhstv[74];
   unsigned int   sqhstl[74];
            int   sqhsts[74];
            void  *sqindv[74];
            int   sqinds[74];
   unsigned int   sqharm[74];
   unsigned int   *sqharc[74];
   unsigned short  sqadto[74];
   unsigned short  sqtdso[74];
} sqlstm = {13,74};

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

 static const char *sq0011 = 
"OT_ID=:b4 and HIST_SEQ<=:b5) or SUBL\
OT_ID>:b4)) order by SUBLOT_ID asc ,HIST_SEQ asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1332,0,4,45,0,0,74,3,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
316,0,0,2,1382,0,4,196,0,0,73,2,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
623,0,0,3,1344,0,4,379,0,0,74,3,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
934,0,0,4,103,0,4,565,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
965,0,0,5,85,0,2,602,0,0,3,3,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,
992,0,0,6,44,0,2,609,0,0,1,1,0,1,0,1,97,0,0,
1011,0,0,7,1206,0,3,637,0,0,71,71,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1310,0,0,8,1213,0,5,803,0,0,71,71,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
1609,0,0,9,163,0,5,878,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,
1648,0,0,10,185,0,5,889,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,3,0,0,
1691,0,0,11,1121,0,9,1007,0,0,7,7,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,0,0,0,
1734,0,0,11,0,0,13,1035,0,0,71,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2033,0,0,11,0,0,15,1136,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mwipbinhss.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2013/02/07 21:22:38
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
void DBC_add_null_mwipbinhss(struct MWIPBINHSS_N_TAG *MWIPBINHSS_N, struct MWIPBINHSS_TAG *MWIPBINHSS);
void DBC_del_null_mwipbinhss(struct MWIPBINHSS_N_TAG *MWIPBINHSS_N, struct MWIPBINHSS_TAG *MWIPBINHSS);


/* SQL SELECT Function */
void DBC_select_mwipbinhss(int sel_type, struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINHSS_N_TAG MWIPBINHSS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinhss(&MWIPBINHSS_N, MWIPBINHSS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    SUBLOT_ID,
                    HIST_SEQ,
                    BIN_COL_SEQ,
                    FACTORY,
                    BIN_ID,
                    BIN_VERSION,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    LOT_ID,
                    LOT_HIST_SEQ,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    RES_ID,
                    RES_TYPE,
                    RESG_ID,
                    QTY_2,
                    QTY_3,
                    BIN_UNIT,
                    TOT_INPUT_QTY,
                    TOT_PASS_QTY,
                    TOT_FAIL_QTY,
                    TOT_YIELD_BASE_QTY,
                    TOT_YIELD,
                    YIELD_CALC_TYPE,
                    LOW_YIELD_FLAG,
                    BASE_UYL,
                    BASE_LYL,
                    TRAN_ALARM_ID,
                    BIN_COMMENT_1,
                    BIN_COMMENT_2,
                    BIN_COMMENT_3,
                    TRAN_COMMENT_1,
                    TRAN_COMMENT_2,
                    TRAN_COMMENT_3,
                    TRAN_CMF_1,
                    TRAN_CMF_2,
                    TRAN_CMF_3,
                    TRAN_CMF_4,
                    TRAN_CMF_5,
                    TRAN_CMF_6,
                    TRAN_CMF_7,
                    TRAN_CMF_8,
                    TRAN_CMF_9,
                    TRAN_CMF_10,
                    TRAN_CMF_11,
                    TRAN_CMF_12,
                    TRAN_CMF_13,
                    TRAN_CMF_14,
                    TRAN_CMF_15,
                    TRAN_CMF_16,
                    TRAN_CMF_17,
                    TRAN_CMF_18,
                    TRAN_CMF_19,
                    TRAN_CMF_20,
                    RESV_FIELD_1,
                    RESV_FIELD_2,
                    RESV_FIELD_3,
                    RESV_FIELD_4,
                    RESV_FIELD_5,
                    RESV_FIELD_6,
                    RESV_FIELD_7,
                    RESV_FIELD_8,
                    RESV_FIELD_9,
                    RESV_FIELD_10,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                INTO 
                    :MWIPBINHSS_N.SUBLOT_ID,
                    :MWIPBINHSS_N.HIST_SEQ,
                    :MWIPBINHSS_N.BIN_COL_SEQ,
                    :MWIPBINHSS_N.FACTORY,
                    :MWIPBINHSS_N.BIN_ID,
                    :MWIPBINHSS_N.BIN_VERSION,
                    :MWIPBINHSS_N.TRAN_TIME,
                    :MWIPBINHSS_N.SYS_TRAN_TIME,
                    :MWIPBINHSS_N.LOT_ID,
                    :MWIPBINHSS_N.LOT_HIST_SEQ,
                    :MWIPBINHSS_N.MAT_ID,
                    :MWIPBINHSS_N.MAT_VER,
                    :MWIPBINHSS_N.FLOW,
                    :MWIPBINHSS_N.FLOW_SEQ_NUM,
                    :MWIPBINHSS_N.OPER,
                    :MWIPBINHSS_N.RES_ID,
                    :MWIPBINHSS_N.RES_TYPE,
                    :MWIPBINHSS_N.RESG_ID,
                    :MWIPBINHSS_N.QTY_2,
                    :MWIPBINHSS_N.QTY_3,
                    :MWIPBINHSS_N.BIN_UNIT,
                    :MWIPBINHSS_N.TOT_INPUT_QTY,
                    :MWIPBINHSS_N.TOT_PASS_QTY,
                    :MWIPBINHSS_N.TOT_FAIL_QTY,
                    :MWIPBINHSS_N.TOT_YIELD_BASE_QTY,
                    :MWIPBINHSS_N.TOT_YIELD,
                    :MWIPBINHSS_N.YIELD_CALC_TYPE,
                    :MWIPBINHSS_N.LOW_YIELD_FLAG,
                    :MWIPBINHSS_N.BASE_UYL,
                    :MWIPBINHSS_N.BASE_LYL,
                    :MWIPBINHSS_N.TRAN_ALARM_ID,
                    :MWIPBINHSS_N.BIN_COMMENT_1,
                    :MWIPBINHSS_N.BIN_COMMENT_2,
                    :MWIPBINHSS_N.BIN_COMMENT_3,
                    :MWIPBINHSS_N.TRAN_COMMENT_1,
                    :MWIPBINHSS_N.TRAN_COMMENT_2,
                    :MWIPBINHSS_N.TRAN_COMMENT_3,
                    :MWIPBINHSS_N.TRAN_CMF_1,
                    :MWIPBINHSS_N.TRAN_CMF_2,
                    :MWIPBINHSS_N.TRAN_CMF_3,
                    :MWIPBINHSS_N.TRAN_CMF_4,
                    :MWIPBINHSS_N.TRAN_CMF_5,
                    :MWIPBINHSS_N.TRAN_CMF_6,
                    :MWIPBINHSS_N.TRAN_CMF_7,
                    :MWIPBINHSS_N.TRAN_CMF_8,
                    :MWIPBINHSS_N.TRAN_CMF_9,
                    :MWIPBINHSS_N.TRAN_CMF_10,
                    :MWIPBINHSS_N.TRAN_CMF_11,
                    :MWIPBINHSS_N.TRAN_CMF_12,
                    :MWIPBINHSS_N.TRAN_CMF_13,
                    :MWIPBINHSS_N.TRAN_CMF_14,
                    :MWIPBINHSS_N.TRAN_CMF_15,
                    :MWIPBINHSS_N.TRAN_CMF_16,
                    :MWIPBINHSS_N.TRAN_CMF_17,
                    :MWIPBINHSS_N.TRAN_CMF_18,
                    :MWIPBINHSS_N.TRAN_CMF_19,
                    :MWIPBINHSS_N.TRAN_CMF_20,
                    :MWIPBINHSS_N.RESV_FIELD_1,
                    :MWIPBINHSS_N.RESV_FIELD_2,
                    :MWIPBINHSS_N.RESV_FIELD_3,
                    :MWIPBINHSS_N.RESV_FIELD_4,
                    :MWIPBINHSS_N.RESV_FIELD_5,
                    :MWIPBINHSS_N.RESV_FIELD_6,
                    :MWIPBINHSS_N.RESV_FIELD_7,
                    :MWIPBINHSS_N.RESV_FIELD_8,
                    :MWIPBINHSS_N.RESV_FIELD_9,
                    :MWIPBINHSS_N.RESV_FIELD_10,
                    :MWIPBINHSS_N.HIST_DEL_FLAG,
                    :MWIPBINHSS_N.HIST_DEL_TIME,
                    :MWIPBINHSS_N.HIST_DEL_USER_ID,
                    :MWIPBINHSS_N.HIST_DEL_COMMENT
                FROM MWIPBINHSS
                WHERE SUBLOT_ID = :MWIPBINHSS_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINHSS_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINHSS_N.BIN_COL_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select SUBLOT_ID ,HIST_SEQ ,BIN_COL_SEQ ,FACTORY ,BIN_ID ,BIN\
_VERSION ,TRAN_TIME ,SYS_TRAN_TIME ,LOT_ID ,LOT_HIST_SEQ ,MAT_ID ,MAT_VER ,F\
LOW ,FLOW_SEQ_NUM ,OPER ,RES_ID ,RES_TYPE ,RESG_ID ,QTY_2 ,QTY_3 ,BIN_UNIT ,\
TOT_INPUT_QTY ,TOT_PASS_QTY ,TOT_FAIL_QTY ,TOT_YIELD_BASE_QTY ,TOT_YIELD ,YI\
ELD_CALC_TYPE ,LOW_YIELD_FLAG ,BASE_UYL ,BASE_LYL ,TRAN_ALARM_ID ,BIN_COMMEN\
T_1 ,BIN_COMMENT_2 ,BIN_COMMENT_3 ,TRAN_COMMENT_1 ,TRAN_COMMENT_2 ,TRAN_COMM\
ENT_3 ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_\
6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12\
 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_\
18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_FIELD_3 ,RESV\
_FIELD_4 ,RESV_FIELD_5 ,RESV_FIELD_6 ,RESV_FIELD_7 ,RESV_FIELD_8 ,RESV_FIELD\
_9 ,RESV_FIELD_10 ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_\
COMMENT into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b1\
4,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24");
            sqlstm.stmt = ",:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b\
34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49\
,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:\
b65,:b66,:b67,:b68,:b69,:b70  from MWIPBINHSS where ((SUBLOT_ID=:b0 and HIST_\
SEQ=:b1) and BIN_COL_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINHSS_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINHSS_N.BIN_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPBINHSS_N.BIN_VERSION);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPBINHSS_N.TRAN_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINHSS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPBINHSS_N.LOT_ID);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MWIPBINHSS_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINHSS_N.MAT_ID);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(MWIPBINHSS_N.MAT_VER);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINHSS_N.FLOW);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MWIPBINHSS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINHSS_N.OPER);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPBINHSS_N.RES_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINHSS_N.RES_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINHSS_N.RESG_ID);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MWIPBINHSS_N.QTY_2);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MWIPBINHSS_N.QTY_3);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINHSS_N.BIN_UNIT);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MWIPBINHSS_N.TOT_INPUT_QTY);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MWIPBINHSS_N.TOT_PASS_QTY);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPBINHSS_N.TOT_FAIL_QTY);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD_BASE_QTY);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINHSS_N.YIELD_CALC_TYPE);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINHSS_N.LOW_YIELD_FLAG);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINHSS_N.BASE_UYL);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINHSS_N.BASE_LYL);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINHSS_N.TRAN_ALARM_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_1);
            sqlstm.sqhstl[31] = (unsigned int  )401;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_2);
            sqlstm.sqhstl[32] = (unsigned int  )401;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_3);
            sqlstm.sqhstl[33] = (unsigned int  )401;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_1);
            sqlstm.sqhstl[34] = (unsigned int  )401;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_2);
            sqlstm.sqhstl[35] = (unsigned int  )401;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_3);
            sqlstm.sqhstl[36] = (unsigned int  )401;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_16);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_17);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_18);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_19);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_20);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_1);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_2);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_3);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_4);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_5);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_6);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_7);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_8);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_9);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_10);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPBINHSS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPBINHSS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPBINHSS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPBINHSS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[70] = (unsigned int  )401;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[72] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
            sqlstm.sqhstl[73] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
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
            /* EXEC SQL SELECT /o+ INDEX_DESC(BINHSS MWIPBINHSS_PK ) o/
                    SUBLOT_ID,
                    HIST_SEQ,
                    BIN_COL_SEQ,
                    FACTORY,
                    BIN_ID,
                    BIN_VERSION,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    LOT_ID,
                    LOT_HIST_SEQ,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    RES_ID,
                    RES_TYPE,
                    RESG_ID,
                    QTY_2,
                    QTY_3,
                    BIN_UNIT,
                    TOT_INPUT_QTY,
                    TOT_PASS_QTY,
                    TOT_FAIL_QTY,
                    TOT_YIELD_BASE_QTY,
                    TOT_YIELD,
                    YIELD_CALC_TYPE,
                    LOW_YIELD_FLAG,
                    BASE_UYL,
                    BASE_LYL,
                    TRAN_ALARM_ID,
                    BIN_COMMENT_1,
                    BIN_COMMENT_2,
                    BIN_COMMENT_3,
                    TRAN_COMMENT_1,
                    TRAN_COMMENT_2,
                    TRAN_COMMENT_3,
                    TRAN_CMF_1,
                    TRAN_CMF_2,
                    TRAN_CMF_3,
                    TRAN_CMF_4,
                    TRAN_CMF_5,
                    TRAN_CMF_6,
                    TRAN_CMF_7,
                    TRAN_CMF_8,
                    TRAN_CMF_9,
                    TRAN_CMF_10,
                    TRAN_CMF_11,
                    TRAN_CMF_12,
                    TRAN_CMF_13,
                    TRAN_CMF_14,
                    TRAN_CMF_15,
                    TRAN_CMF_16,
                    TRAN_CMF_17,
                    TRAN_CMF_18,
                    TRAN_CMF_19,
                    TRAN_CMF_20,
                    RESV_FIELD_1,
                    RESV_FIELD_2,
                    RESV_FIELD_3,
                    RESV_FIELD_4,
                    RESV_FIELD_5,
                    RESV_FIELD_6,
                    RESV_FIELD_7,
                    RESV_FIELD_8,
                    RESV_FIELD_9,
                    RESV_FIELD_10,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                INTO 
                    :MWIPBINHSS_N.SUBLOT_ID,
                    :MWIPBINHSS_N.HIST_SEQ,
                    :MWIPBINHSS_N.BIN_COL_SEQ,
                    :MWIPBINHSS_N.FACTORY,
                    :MWIPBINHSS_N.BIN_ID,
                    :MWIPBINHSS_N.BIN_VERSION,
                    :MWIPBINHSS_N.TRAN_TIME,
                    :MWIPBINHSS_N.SYS_TRAN_TIME,
                    :MWIPBINHSS_N.LOT_ID,
                    :MWIPBINHSS_N.LOT_HIST_SEQ,
                    :MWIPBINHSS_N.MAT_ID,
                    :MWIPBINHSS_N.MAT_VER,
                    :MWIPBINHSS_N.FLOW,
                    :MWIPBINHSS_N.FLOW_SEQ_NUM,
                    :MWIPBINHSS_N.OPER,
                    :MWIPBINHSS_N.RES_ID,
                    :MWIPBINHSS_N.RES_TYPE,
                    :MWIPBINHSS_N.RESG_ID,
                    :MWIPBINHSS_N.QTY_2,
                    :MWIPBINHSS_N.QTY_3,
                    :MWIPBINHSS_N.BIN_UNIT,
                    :MWIPBINHSS_N.TOT_INPUT_QTY,
                    :MWIPBINHSS_N.TOT_PASS_QTY,
                    :MWIPBINHSS_N.TOT_FAIL_QTY,
                    :MWIPBINHSS_N.TOT_YIELD_BASE_QTY,
                    :MWIPBINHSS_N.TOT_YIELD,
                    :MWIPBINHSS_N.YIELD_CALC_TYPE,
                    :MWIPBINHSS_N.LOW_YIELD_FLAG,
                    :MWIPBINHSS_N.BASE_UYL,
                    :MWIPBINHSS_N.BASE_LYL,
                    :MWIPBINHSS_N.TRAN_ALARM_ID,
                    :MWIPBINHSS_N.BIN_COMMENT_1,
                    :MWIPBINHSS_N.BIN_COMMENT_2,
                    :MWIPBINHSS_N.BIN_COMMENT_3,
                    :MWIPBINHSS_N.TRAN_COMMENT_1,
                    :MWIPBINHSS_N.TRAN_COMMENT_2,
                    :MWIPBINHSS_N.TRAN_COMMENT_3,
                    :MWIPBINHSS_N.TRAN_CMF_1,
                    :MWIPBINHSS_N.TRAN_CMF_2,
                    :MWIPBINHSS_N.TRAN_CMF_3,
                    :MWIPBINHSS_N.TRAN_CMF_4,
                    :MWIPBINHSS_N.TRAN_CMF_5,
                    :MWIPBINHSS_N.TRAN_CMF_6,
                    :MWIPBINHSS_N.TRAN_CMF_7,
                    :MWIPBINHSS_N.TRAN_CMF_8,
                    :MWIPBINHSS_N.TRAN_CMF_9,
                    :MWIPBINHSS_N.TRAN_CMF_10,
                    :MWIPBINHSS_N.TRAN_CMF_11,
                    :MWIPBINHSS_N.TRAN_CMF_12,
                    :MWIPBINHSS_N.TRAN_CMF_13,
                    :MWIPBINHSS_N.TRAN_CMF_14,
                    :MWIPBINHSS_N.TRAN_CMF_15,
                    :MWIPBINHSS_N.TRAN_CMF_16,
                    :MWIPBINHSS_N.TRAN_CMF_17,
                    :MWIPBINHSS_N.TRAN_CMF_18,
                    :MWIPBINHSS_N.TRAN_CMF_19,
                    :MWIPBINHSS_N.TRAN_CMF_20,
                    :MWIPBINHSS_N.RESV_FIELD_1,
                    :MWIPBINHSS_N.RESV_FIELD_2,
                    :MWIPBINHSS_N.RESV_FIELD_3,
                    :MWIPBINHSS_N.RESV_FIELD_4,
                    :MWIPBINHSS_N.RESV_FIELD_5,
                    :MWIPBINHSS_N.RESV_FIELD_6,
                    :MWIPBINHSS_N.RESV_FIELD_7,
                    :MWIPBINHSS_N.RESV_FIELD_8,
                    :MWIPBINHSS_N.RESV_FIELD_9,
                    :MWIPBINHSS_N.RESV_FIELD_10,
                    :MWIPBINHSS_N.HIST_DEL_FLAG,
                    :MWIPBINHSS_N.HIST_DEL_TIME,
                    :MWIPBINHSS_N.HIST_DEL_USER_ID,
                    :MWIPBINHSS_N.HIST_DEL_COMMENT
                FROM MWIPBINHSS BINHSS
                WHERE SUBLOT_ID = :MWIPBINHSS_N.SUBLOT_ID
                    AND HIST_DEL_FLAG = :MWIPBINHSS_N.HIST_DEL_FLAG
                    AND ROWNUM = 1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select  /*+  INDEX_DESC(BINHSS MWIPBINHSS_PK )  */ SUBLOT_ID \
,HIST_SEQ ,BIN_COL_SEQ ,FACTORY ,BIN_ID ,BIN_VERSION ,TRAN_TIME ,SYS_TRAN_TI\
ME ,LOT_ID ,LOT_HIST_SEQ ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,RES_ID \
,RES_TYPE ,RESG_ID ,QTY_2 ,QTY_3 ,BIN_UNIT ,TOT_INPUT_QTY ,TOT_PASS_QTY ,TOT\
_FAIL_QTY ,TOT_YIELD_BASE_QTY ,TOT_YIELD ,YIELD_CALC_TYPE ,LOW_YIELD_FLAG ,B\
ASE_UYL ,BASE_LYL ,TRAN_ALARM_ID ,BIN_COMMENT_1 ,BIN_COMMENT_2 ,BIN_COMMENT_\
3 ,TRAN_COMMENT_1 ,TRAN_COMMENT_2 ,TRAN_COMMENT_3 ,TRAN_CMF_1 ,TRAN_CMF_2 ,T\
RAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_\
CMF_9 ,TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN\
_CMF_15 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,RE\
SV_FIELD_1 ,RESV_FIELD_2 ,RESV_FIELD_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FIE\
LD_6 ,RESV_FIELD_7 ,RESV_FIELD_8 ,RESV_FIELD_9 ,RESV_FIELD_10 ,HIST_DEL_FLAG\
 ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT into :b0,:b1,:b2,:b3,:b4\
,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,");
            sqlstm.stmt = ":b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b2\
5,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,\
:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b\
56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70  fro\
m MWIPBINHSS BINHSS where ((SUBLOT_ID=:b0 and HIST_DEL_FLAG=:b67) and ROWNUM=\
1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )316;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINHSS_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINHSS_N.BIN_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPBINHSS_N.BIN_VERSION);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPBINHSS_N.TRAN_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINHSS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPBINHSS_N.LOT_ID);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MWIPBINHSS_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINHSS_N.MAT_ID);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(MWIPBINHSS_N.MAT_VER);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINHSS_N.FLOW);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MWIPBINHSS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINHSS_N.OPER);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPBINHSS_N.RES_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINHSS_N.RES_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINHSS_N.RESG_ID);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MWIPBINHSS_N.QTY_2);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MWIPBINHSS_N.QTY_3);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINHSS_N.BIN_UNIT);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MWIPBINHSS_N.TOT_INPUT_QTY);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MWIPBINHSS_N.TOT_PASS_QTY);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPBINHSS_N.TOT_FAIL_QTY);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD_BASE_QTY);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINHSS_N.YIELD_CALC_TYPE);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINHSS_N.LOW_YIELD_FLAG);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINHSS_N.BASE_UYL);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINHSS_N.BASE_LYL);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINHSS_N.TRAN_ALARM_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_1);
            sqlstm.sqhstl[31] = (unsigned int  )401;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_2);
            sqlstm.sqhstl[32] = (unsigned int  )401;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_3);
            sqlstm.sqhstl[33] = (unsigned int  )401;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_1);
            sqlstm.sqhstl[34] = (unsigned int  )401;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_2);
            sqlstm.sqhstl[35] = (unsigned int  )401;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_3);
            sqlstm.sqhstl[36] = (unsigned int  )401;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_16);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_17);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_18);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_19);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_20);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_1);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_2);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_3);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_4);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_5);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_6);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_7);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_8);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_9);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_10);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPBINHSS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPBINHSS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPBINHSS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPBINHSS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[70] = (unsigned int  )401;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPBINHSS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
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
        DBC_del_null_mwipbinhss(&MWIPBINHSS_N, MWIPBINHSS);
    }

    DB_stop_query_timer("DBC_select_mwipbinhss", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mwipbinhss_for_update(int sel_type, struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINHSS_N_TAG MWIPBINHSS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinhss(&MWIPBINHSS_N, MWIPBINHSS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    SUBLOT_ID,
                    HIST_SEQ,
                    BIN_COL_SEQ,
                    FACTORY,
                    BIN_ID,
                    BIN_VERSION,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    LOT_ID,
                    LOT_HIST_SEQ,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    RES_ID,
                    RES_TYPE,
                    RESG_ID,
                    QTY_2,
                    QTY_3,
                    BIN_UNIT,
                    TOT_INPUT_QTY,
                    TOT_PASS_QTY,
                    TOT_FAIL_QTY,
                    TOT_YIELD_BASE_QTY,
                    TOT_YIELD,
                    YIELD_CALC_TYPE,
                    LOW_YIELD_FLAG,
                    BASE_UYL,
                    BASE_LYL,
                    TRAN_ALARM_ID,
                    BIN_COMMENT_1,
                    BIN_COMMENT_2,
                    BIN_COMMENT_3,
                    TRAN_COMMENT_1,
                    TRAN_COMMENT_2,
                    TRAN_COMMENT_3,
                    TRAN_CMF_1,
                    TRAN_CMF_2,
                    TRAN_CMF_3,
                    TRAN_CMF_4,
                    TRAN_CMF_5,
                    TRAN_CMF_6,
                    TRAN_CMF_7,
                    TRAN_CMF_8,
                    TRAN_CMF_9,
                    TRAN_CMF_10,
                    TRAN_CMF_11,
                    TRAN_CMF_12,
                    TRAN_CMF_13,
                    TRAN_CMF_14,
                    TRAN_CMF_15,
                    TRAN_CMF_16,
                    TRAN_CMF_17,
                    TRAN_CMF_18,
                    TRAN_CMF_19,
                    TRAN_CMF_20,
                    RESV_FIELD_1,
                    RESV_FIELD_2,
                    RESV_FIELD_3,
                    RESV_FIELD_4,
                    RESV_FIELD_5,
                    RESV_FIELD_6,
                    RESV_FIELD_7,
                    RESV_FIELD_8,
                    RESV_FIELD_9,
                    RESV_FIELD_10,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                INTO 
                    :MWIPBINHSS_N.SUBLOT_ID,
                    :MWIPBINHSS_N.HIST_SEQ,
                    :MWIPBINHSS_N.BIN_COL_SEQ,
                    :MWIPBINHSS_N.FACTORY,
                    :MWIPBINHSS_N.BIN_ID,
                    :MWIPBINHSS_N.BIN_VERSION,
                    :MWIPBINHSS_N.TRAN_TIME,
                    :MWIPBINHSS_N.SYS_TRAN_TIME,
                    :MWIPBINHSS_N.LOT_ID,
                    :MWIPBINHSS_N.LOT_HIST_SEQ,
                    :MWIPBINHSS_N.MAT_ID,
                    :MWIPBINHSS_N.MAT_VER,
                    :MWIPBINHSS_N.FLOW,
                    :MWIPBINHSS_N.FLOW_SEQ_NUM,
                    :MWIPBINHSS_N.OPER,
                    :MWIPBINHSS_N.RES_ID,
                    :MWIPBINHSS_N.RES_TYPE,
                    :MWIPBINHSS_N.RESG_ID,
                    :MWIPBINHSS_N.QTY_2,
                    :MWIPBINHSS_N.QTY_3,
                    :MWIPBINHSS_N.BIN_UNIT,
                    :MWIPBINHSS_N.TOT_INPUT_QTY,
                    :MWIPBINHSS_N.TOT_PASS_QTY,
                    :MWIPBINHSS_N.TOT_FAIL_QTY,
                    :MWIPBINHSS_N.TOT_YIELD_BASE_QTY,
                    :MWIPBINHSS_N.TOT_YIELD,
                    :MWIPBINHSS_N.YIELD_CALC_TYPE,
                    :MWIPBINHSS_N.LOW_YIELD_FLAG,
                    :MWIPBINHSS_N.BASE_UYL,
                    :MWIPBINHSS_N.BASE_LYL,
                    :MWIPBINHSS_N.TRAN_ALARM_ID,
                    :MWIPBINHSS_N.BIN_COMMENT_1,
                    :MWIPBINHSS_N.BIN_COMMENT_2,
                    :MWIPBINHSS_N.BIN_COMMENT_3,
                    :MWIPBINHSS_N.TRAN_COMMENT_1,
                    :MWIPBINHSS_N.TRAN_COMMENT_2,
                    :MWIPBINHSS_N.TRAN_COMMENT_3,
                    :MWIPBINHSS_N.TRAN_CMF_1,
                    :MWIPBINHSS_N.TRAN_CMF_2,
                    :MWIPBINHSS_N.TRAN_CMF_3,
                    :MWIPBINHSS_N.TRAN_CMF_4,
                    :MWIPBINHSS_N.TRAN_CMF_5,
                    :MWIPBINHSS_N.TRAN_CMF_6,
                    :MWIPBINHSS_N.TRAN_CMF_7,
                    :MWIPBINHSS_N.TRAN_CMF_8,
                    :MWIPBINHSS_N.TRAN_CMF_9,
                    :MWIPBINHSS_N.TRAN_CMF_10,
                    :MWIPBINHSS_N.TRAN_CMF_11,
                    :MWIPBINHSS_N.TRAN_CMF_12,
                    :MWIPBINHSS_N.TRAN_CMF_13,
                    :MWIPBINHSS_N.TRAN_CMF_14,
                    :MWIPBINHSS_N.TRAN_CMF_15,
                    :MWIPBINHSS_N.TRAN_CMF_16,
                    :MWIPBINHSS_N.TRAN_CMF_17,
                    :MWIPBINHSS_N.TRAN_CMF_18,
                    :MWIPBINHSS_N.TRAN_CMF_19,
                    :MWIPBINHSS_N.TRAN_CMF_20,
                    :MWIPBINHSS_N.RESV_FIELD_1,
                    :MWIPBINHSS_N.RESV_FIELD_2,
                    :MWIPBINHSS_N.RESV_FIELD_3,
                    :MWIPBINHSS_N.RESV_FIELD_4,
                    :MWIPBINHSS_N.RESV_FIELD_5,
                    :MWIPBINHSS_N.RESV_FIELD_6,
                    :MWIPBINHSS_N.RESV_FIELD_7,
                    :MWIPBINHSS_N.RESV_FIELD_8,
                    :MWIPBINHSS_N.RESV_FIELD_9,
                    :MWIPBINHSS_N.RESV_FIELD_10,
                    :MWIPBINHSS_N.HIST_DEL_FLAG,
                    :MWIPBINHSS_N.HIST_DEL_TIME,
                    :MWIPBINHSS_N.HIST_DEL_USER_ID,
                    :MWIPBINHSS_N.HIST_DEL_COMMENT
                FROM MWIPBINHSS
                WHERE SUBLOT_ID = :MWIPBINHSS_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINHSS_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINHSS_N.BIN_COL_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select SUBLOT_ID ,HIST_SEQ ,BIN_COL_SEQ ,FACTORY ,BIN_ID ,BIN\
_VERSION ,TRAN_TIME ,SYS_TRAN_TIME ,LOT_ID ,LOT_HIST_SEQ ,MAT_ID ,MAT_VER ,F\
LOW ,FLOW_SEQ_NUM ,OPER ,RES_ID ,RES_TYPE ,RESG_ID ,QTY_2 ,QTY_3 ,BIN_UNIT ,\
TOT_INPUT_QTY ,TOT_PASS_QTY ,TOT_FAIL_QTY ,TOT_YIELD_BASE_QTY ,TOT_YIELD ,YI\
ELD_CALC_TYPE ,LOW_YIELD_FLAG ,BASE_UYL ,BASE_LYL ,TRAN_ALARM_ID ,BIN_COMMEN\
T_1 ,BIN_COMMENT_2 ,BIN_COMMENT_3 ,TRAN_COMMENT_1 ,TRAN_COMMENT_2 ,TRAN_COMM\
ENT_3 ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_\
6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12\
 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_\
18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_FIELD_3 ,RESV\
_FIELD_4 ,RESV_FIELD_5 ,RESV_FIELD_6 ,RESV_FIELD_7 ,RESV_FIELD_8 ,RESV_FIELD\
_9 ,RESV_FIELD_10 ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_\
COMMENT into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b1\
4,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24");
            sqlstm.stmt = ",:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b\
34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49\
,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:\
b65,:b66,:b67,:b68,:b69,:b70  from MWIPBINHSS where ((SUBLOT_ID=:b0 and HIST_\
SEQ=:b1) and BIN_COL_SEQ=:b2) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )623;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINHSS_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINHSS_N.BIN_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPBINHSS_N.BIN_VERSION);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPBINHSS_N.TRAN_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINHSS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPBINHSS_N.LOT_ID);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MWIPBINHSS_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINHSS_N.MAT_ID);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(MWIPBINHSS_N.MAT_VER);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINHSS_N.FLOW);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MWIPBINHSS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINHSS_N.OPER);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPBINHSS_N.RES_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINHSS_N.RES_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINHSS_N.RESG_ID);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MWIPBINHSS_N.QTY_2);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MWIPBINHSS_N.QTY_3);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINHSS_N.BIN_UNIT);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MWIPBINHSS_N.TOT_INPUT_QTY);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MWIPBINHSS_N.TOT_PASS_QTY);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPBINHSS_N.TOT_FAIL_QTY);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD_BASE_QTY);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINHSS_N.YIELD_CALC_TYPE);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINHSS_N.LOW_YIELD_FLAG);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINHSS_N.BASE_UYL);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINHSS_N.BASE_LYL);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINHSS_N.TRAN_ALARM_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_1);
            sqlstm.sqhstl[31] = (unsigned int  )401;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_2);
            sqlstm.sqhstl[32] = (unsigned int  )401;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_3);
            sqlstm.sqhstl[33] = (unsigned int  )401;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_1);
            sqlstm.sqhstl[34] = (unsigned int  )401;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_2);
            sqlstm.sqhstl[35] = (unsigned int  )401;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_3);
            sqlstm.sqhstl[36] = (unsigned int  )401;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_16);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_17);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_18);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_19);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_20);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_1);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_2);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_3);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_4);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_5);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_6);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_7);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_8);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_9);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_10);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPBINHSS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPBINHSS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPBINHSS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPBINHSS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[70] = (unsigned int  )401;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[72] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
            sqlstm.sqhstl[73] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
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
        DBC_del_null_mwipbinhss(&MWIPBINHSS_N, MWIPBINHSS);
    }

    DB_stop_query_timer("DBC_select_mwipbinhss_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mwipbinhss_scalar(int sel_type, struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINHSS_N_TAG MWIPBINHSS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinhss(&MWIPBINHSS_N, MWIPBINHSS);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPBINHSS
                WHERE SUBLOT_ID = :MWIPBINHSS_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINHSS_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINHSS_N.BIN_COL_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPBINHSS where\
 ((SUBLOT_ID=:b1 and HIST_SEQ=:b2) and BIN_COL_SEQ=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )934;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
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

    DB_stop_query_timer("DBC_select_mwipbinhss_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mwipbinhss(int sel_type, struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINHSS_N_TAG MWIPBINHSS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinhss(&MWIPBINHSS_N, MWIPBINHSS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MWIPBINHSS
                WHERE SUBLOT_ID = :MWIPBINHSS_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINHSS_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINHSS_N.BIN_COL_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPBINHSS  where ((SUBLOT_ID=:b0 a\
nd HIST_SEQ=:b1) and BIN_COL_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )965;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
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

        case 2:
            /* EXEC SQL DELETE FROM MWIPBINHSS
                WHERE SUBLOT_ID = :MWIPBINHSS_N.SUBLOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPBINHSS  where SUBLOT_ID=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )992;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
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

    DB_stop_query_timer("DBC_delete_mwipbinhss", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mwipbinhss(struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINHSS_N_TAG MWIPBINHSS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinhss(&MWIPBINHSS_N, MWIPBINHSS);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MWIPBINHSS( 
                    SUBLOT_ID, 
                    HIST_SEQ, 
                    BIN_COL_SEQ, 
                    FACTORY, 
                    BIN_ID, 
                    BIN_VERSION, 
                    TRAN_TIME, 
                    SYS_TRAN_TIME, 
                    LOT_ID, 
                    LOT_HIST_SEQ, 
                    MAT_ID, 
                    MAT_VER, 
                    FLOW, 
                    FLOW_SEQ_NUM, 
                    OPER, 
                    RES_ID, 
                    RES_TYPE, 
                    RESG_ID, 
                    QTY_2, 
                    QTY_3, 
                    BIN_UNIT, 
                    TOT_INPUT_QTY, 
                    TOT_PASS_QTY, 
                    TOT_FAIL_QTY, 
                    TOT_YIELD_BASE_QTY, 
                    TOT_YIELD, 
                    YIELD_CALC_TYPE, 
                    LOW_YIELD_FLAG, 
                    BASE_UYL, 
                    BASE_LYL, 
                    TRAN_ALARM_ID, 
                    BIN_COMMENT_1, 
                    BIN_COMMENT_2, 
                    BIN_COMMENT_3, 
                    TRAN_COMMENT_1, 
                    TRAN_COMMENT_2, 
                    TRAN_COMMENT_3, 
                    TRAN_CMF_1, 
                    TRAN_CMF_2, 
                    TRAN_CMF_3, 
                    TRAN_CMF_4, 
                    TRAN_CMF_5, 
                    TRAN_CMF_6, 
                    TRAN_CMF_7, 
                    TRAN_CMF_8, 
                    TRAN_CMF_9, 
                    TRAN_CMF_10, 
                    TRAN_CMF_11, 
                    TRAN_CMF_12, 
                    TRAN_CMF_13, 
                    TRAN_CMF_14, 
                    TRAN_CMF_15, 
                    TRAN_CMF_16, 
                    TRAN_CMF_17, 
                    TRAN_CMF_18, 
                    TRAN_CMF_19, 
                    TRAN_CMF_20, 
                    RESV_FIELD_1, 
                    RESV_FIELD_2, 
                    RESV_FIELD_3, 
                    RESV_FIELD_4, 
                    RESV_FIELD_5, 
                    RESV_FIELD_6, 
                    RESV_FIELD_7, 
                    RESV_FIELD_8, 
                    RESV_FIELD_9, 
                    RESV_FIELD_10, 
                    HIST_DEL_FLAG, 
                    HIST_DEL_TIME, 
                    HIST_DEL_USER_ID, 
                    HIST_DEL_COMMENT
         ) 
        VALUES (
                    :MWIPBINHSS_N.SUBLOT_ID,
                    :MWIPBINHSS_N.HIST_SEQ,
                    :MWIPBINHSS_N.BIN_COL_SEQ,
                    :MWIPBINHSS_N.FACTORY,
                    :MWIPBINHSS_N.BIN_ID,
                    :MWIPBINHSS_N.BIN_VERSION,
                    :MWIPBINHSS_N.TRAN_TIME,
                    :MWIPBINHSS_N.SYS_TRAN_TIME,
                    :MWIPBINHSS_N.LOT_ID,
                    :MWIPBINHSS_N.LOT_HIST_SEQ,
                    :MWIPBINHSS_N.MAT_ID,
                    :MWIPBINHSS_N.MAT_VER,
                    :MWIPBINHSS_N.FLOW,
                    :MWIPBINHSS_N.FLOW_SEQ_NUM,
                    :MWIPBINHSS_N.OPER,
                    :MWIPBINHSS_N.RES_ID,
                    :MWIPBINHSS_N.RES_TYPE,
                    :MWIPBINHSS_N.RESG_ID,
                    :MWIPBINHSS_N.QTY_2,
                    :MWIPBINHSS_N.QTY_3,
                    :MWIPBINHSS_N.BIN_UNIT,
                    :MWIPBINHSS_N.TOT_INPUT_QTY,
                    :MWIPBINHSS_N.TOT_PASS_QTY,
                    :MWIPBINHSS_N.TOT_FAIL_QTY,
                    :MWIPBINHSS_N.TOT_YIELD_BASE_QTY,
                    :MWIPBINHSS_N.TOT_YIELD,
                    :MWIPBINHSS_N.YIELD_CALC_TYPE,
                    :MWIPBINHSS_N.LOW_YIELD_FLAG,
                    :MWIPBINHSS_N.BASE_UYL,
                    :MWIPBINHSS_N.BASE_LYL,
                    :MWIPBINHSS_N.TRAN_ALARM_ID,
                    :MWIPBINHSS_N.BIN_COMMENT_1,
                    :MWIPBINHSS_N.BIN_COMMENT_2,
                    :MWIPBINHSS_N.BIN_COMMENT_3,
                    :MWIPBINHSS_N.TRAN_COMMENT_1,
                    :MWIPBINHSS_N.TRAN_COMMENT_2,
                    :MWIPBINHSS_N.TRAN_COMMENT_3,
                    :MWIPBINHSS_N.TRAN_CMF_1,
                    :MWIPBINHSS_N.TRAN_CMF_2,
                    :MWIPBINHSS_N.TRAN_CMF_3,
                    :MWIPBINHSS_N.TRAN_CMF_4,
                    :MWIPBINHSS_N.TRAN_CMF_5,
                    :MWIPBINHSS_N.TRAN_CMF_6,
                    :MWIPBINHSS_N.TRAN_CMF_7,
                    :MWIPBINHSS_N.TRAN_CMF_8,
                    :MWIPBINHSS_N.TRAN_CMF_9,
                    :MWIPBINHSS_N.TRAN_CMF_10,
                    :MWIPBINHSS_N.TRAN_CMF_11,
                    :MWIPBINHSS_N.TRAN_CMF_12,
                    :MWIPBINHSS_N.TRAN_CMF_13,
                    :MWIPBINHSS_N.TRAN_CMF_14,
                    :MWIPBINHSS_N.TRAN_CMF_15,
                    :MWIPBINHSS_N.TRAN_CMF_16,
                    :MWIPBINHSS_N.TRAN_CMF_17,
                    :MWIPBINHSS_N.TRAN_CMF_18,
                    :MWIPBINHSS_N.TRAN_CMF_19,
                    :MWIPBINHSS_N.TRAN_CMF_20,
                    :MWIPBINHSS_N.RESV_FIELD_1,
                    :MWIPBINHSS_N.RESV_FIELD_2,
                    :MWIPBINHSS_N.RESV_FIELD_3,
                    :MWIPBINHSS_N.RESV_FIELD_4,
                    :MWIPBINHSS_N.RESV_FIELD_5,
                    :MWIPBINHSS_N.RESV_FIELD_6,
                    :MWIPBINHSS_N.RESV_FIELD_7,
                    :MWIPBINHSS_N.RESV_FIELD_8,
                    :MWIPBINHSS_N.RESV_FIELD_9,
                    :MWIPBINHSS_N.RESV_FIELD_10,
                    :MWIPBINHSS_N.HIST_DEL_FLAG,
                    :MWIPBINHSS_N.HIST_DEL_TIME,
                    :MWIPBINHSS_N.HIST_DEL_USER_ID,
                    :MWIPBINHSS_N.HIST_DEL_COMMENT
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 74;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MWIPBINHSS (SUBLOT_ID,HIST_SEQ,BIN_COL_SEQ,FACTORY,BIN_ID\
,BIN_VERSION,TRAN_TIME,SYS_TRAN_TIME,LOT_ID,LOT_HIST_SEQ,MAT_ID,MAT_VER,FLOW\
,FLOW_SEQ_NUM,OPER,RES_ID,RES_TYPE,RESG_ID,QTY_2,QTY_3,BIN_UNIT,TOT_INPUT_QT\
Y,TOT_PASS_QTY,TOT_FAIL_QTY,TOT_YIELD_BASE_QTY,TOT_YIELD,YIELD_CALC_TYPE,LOW\
_YIELD_FLAG,BASE_UYL,BASE_LYL,TRAN_ALARM_ID,BIN_COMMENT_1,BIN_COMMENT_2,BIN_\
COMMENT_3,TRAN_COMMENT_1,TRAN_COMMENT_2,TRAN_COMMENT_3,TRAN_CMF_1,TRAN_CMF_2\
,TRAN_CMF_3,TRAN_CMF_4,TRAN_CMF_5,TRAN_CMF_6,TRAN_CMF_7,TRAN_CMF_8,TRAN_CMF_\
9,TRAN_CMF_10,TRAN_CMF_11,TRAN_CMF_12,TRAN_CMF_13,TRAN_CMF_14,TRAN_CMF_15,TR\
AN_CMF_16,TRAN_CMF_17,TRAN_CMF_18,TRAN_CMF_19,TRAN_CMF_20,RESV_FIELD_1,RESV_\
FIELD_2,RESV_FIELD_3,RESV_FIELD_4,RESV_FIELD_5,RESV_FIELD_6,RESV_FIELD_7,RES\
V_FIELD_8,RESV_FIELD_9,RESV_FIELD_10,HIST_DEL_FLAG,HIST_DEL_TIME,HIST_DEL_US\
ER_ID,HIST_DEL_COMMENT) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10\
,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,\
:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b3");
    sqlstm.stmt = "4,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45\
,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:\
b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1011;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
    sqlstm.sqhstl[0] = (unsigned int  )31;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
    sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MWIPBINHSS_N.FACTORY);
    sqlstm.sqhstl[3] = (unsigned int  )11;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MWIPBINHSS_N.BIN_ID);
    sqlstm.sqhstl[4] = (unsigned int  )31;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)&(MWIPBINHSS_N.BIN_VERSION);
    sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MWIPBINHSS_N.TRAN_TIME);
    sqlstm.sqhstl[6] = (unsigned int  )15;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MWIPBINHSS_N.SYS_TRAN_TIME);
    sqlstm.sqhstl[7] = (unsigned int  )15;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MWIPBINHSS_N.LOT_ID);
    sqlstm.sqhstl[8] = (unsigned int  )26;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)&(MWIPBINHSS_N.LOT_HIST_SEQ);
    sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MWIPBINHSS_N.MAT_ID);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)&(MWIPBINHSS_N.MAT_VER);
    sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MWIPBINHSS_N.FLOW);
    sqlstm.sqhstl[12] = (unsigned int  )21;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)&(MWIPBINHSS_N.FLOW_SEQ_NUM);
    sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MWIPBINHSS_N.OPER);
    sqlstm.sqhstl[14] = (unsigned int  )11;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MWIPBINHSS_N.RES_ID);
    sqlstm.sqhstl[15] = (unsigned int  )21;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MWIPBINHSS_N.RES_TYPE);
    sqlstm.sqhstl[16] = (unsigned int  )21;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MWIPBINHSS_N.RESG_ID);
    sqlstm.sqhstl[17] = (unsigned int  )21;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)&(MWIPBINHSS_N.QTY_2);
    sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)&(MWIPBINHSS_N.QTY_3);
    sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MWIPBINHSS_N.BIN_UNIT);
    sqlstm.sqhstl[20] = (unsigned int  )11;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)&(MWIPBINHSS_N.TOT_INPUT_QTY);
    sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)&(MWIPBINHSS_N.TOT_PASS_QTY);
    sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)&(MWIPBINHSS_N.TOT_FAIL_QTY);
    sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD_BASE_QTY);
    sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD);
    sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MWIPBINHSS_N.YIELD_CALC_TYPE);
    sqlstm.sqhstl[26] = (unsigned int  )2;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MWIPBINHSS_N.LOW_YIELD_FLAG);
    sqlstm.sqhstl[27] = (unsigned int  )2;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MWIPBINHSS_N.BASE_UYL);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MWIPBINHSS_N.BASE_LYL);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MWIPBINHSS_N.TRAN_ALARM_ID);
    sqlstm.sqhstl[30] = (unsigned int  )21;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_1);
    sqlstm.sqhstl[31] = (unsigned int  )401;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_2);
    sqlstm.sqhstl[32] = (unsigned int  )401;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_3);
    sqlstm.sqhstl[33] = (unsigned int  )401;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_1);
    sqlstm.sqhstl[34] = (unsigned int  )401;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_2);
    sqlstm.sqhstl[35] = (unsigned int  )401;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_3);
    sqlstm.sqhstl[36] = (unsigned int  )401;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_1);
    sqlstm.sqhstl[37] = (unsigned int  )31;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_2);
    sqlstm.sqhstl[38] = (unsigned int  )31;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_3);
    sqlstm.sqhstl[39] = (unsigned int  )31;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_4);
    sqlstm.sqhstl[40] = (unsigned int  )31;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_5);
    sqlstm.sqhstl[41] = (unsigned int  )31;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_6);
    sqlstm.sqhstl[42] = (unsigned int  )31;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_7);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_8);
    sqlstm.sqhstl[44] = (unsigned int  )31;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_9);
    sqlstm.sqhstl[45] = (unsigned int  )31;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_10);
    sqlstm.sqhstl[46] = (unsigned int  )31;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_11);
    sqlstm.sqhstl[47] = (unsigned int  )31;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_12);
    sqlstm.sqhstl[48] = (unsigned int  )31;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_13);
    sqlstm.sqhstl[49] = (unsigned int  )31;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_14);
    sqlstm.sqhstl[50] = (unsigned int  )31;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_15);
    sqlstm.sqhstl[51] = (unsigned int  )31;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_16);
    sqlstm.sqhstl[52] = (unsigned int  )31;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_17);
    sqlstm.sqhstl[53] = (unsigned int  )31;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_18);
    sqlstm.sqhstl[54] = (unsigned int  )31;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_19);
    sqlstm.sqhstl[55] = (unsigned int  )31;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_20);
    sqlstm.sqhstl[56] = (unsigned int  )31;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_1);
    sqlstm.sqhstl[57] = (unsigned int  )31;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_2);
    sqlstm.sqhstl[58] = (unsigned int  )31;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_3);
    sqlstm.sqhstl[59] = (unsigned int  )31;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_4);
    sqlstm.sqhstl[60] = (unsigned int  )31;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_5);
    sqlstm.sqhstl[61] = (unsigned int  )31;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_6);
    sqlstm.sqhstl[62] = (unsigned int  )31;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_7);
    sqlstm.sqhstl[63] = (unsigned int  )31;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_8);
    sqlstm.sqhstl[64] = (unsigned int  )31;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_9);
    sqlstm.sqhstl[65] = (unsigned int  )31;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_10);
    sqlstm.sqhstl[66] = (unsigned int  )31;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MWIPBINHSS_N.HIST_DEL_FLAG);
    sqlstm.sqhstl[67] = (unsigned int  )2;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MWIPBINHSS_N.HIST_DEL_TIME);
    sqlstm.sqhstl[68] = (unsigned int  )15;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MWIPBINHSS_N.HIST_DEL_USER_ID);
    sqlstm.sqhstl[69] = (unsigned int  )21;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MWIPBINHSS_N.HIST_DEL_COMMENT);
    sqlstm.sqhstl[70] = (unsigned int  )401;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
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



    DB_stop_query_timer("DBC_insert_mwipbinhss", 0);
}


/* SQL UPDATE Function */
void DBC_update_mwipbinhss(int sel_type, struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINHSS_N_TAG MWIPBINHSS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinhss(&MWIPBINHSS_N, MWIPBINHSS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MWIPBINHSS SET
                    FACTORY = :MWIPBINHSS_N.FACTORY,
                    BIN_ID = :MWIPBINHSS_N.BIN_ID,
                    BIN_VERSION = :MWIPBINHSS_N.BIN_VERSION,
                    TRAN_TIME = :MWIPBINHSS_N.TRAN_TIME,
                    SYS_TRAN_TIME = :MWIPBINHSS_N.SYS_TRAN_TIME,
                    LOT_ID = :MWIPBINHSS_N.LOT_ID,
                    LOT_HIST_SEQ = :MWIPBINHSS_N.LOT_HIST_SEQ,
                    MAT_ID = :MWIPBINHSS_N.MAT_ID,
                    MAT_VER = :MWIPBINHSS_N.MAT_VER,
                    FLOW = :MWIPBINHSS_N.FLOW,
                    FLOW_SEQ_NUM = :MWIPBINHSS_N.FLOW_SEQ_NUM,
                    OPER = :MWIPBINHSS_N.OPER,
                    RES_ID = :MWIPBINHSS_N.RES_ID,
                    RES_TYPE = :MWIPBINHSS_N.RES_TYPE,
                    RESG_ID = :MWIPBINHSS_N.RESG_ID,
                    QTY_2 = :MWIPBINHSS_N.QTY_2,
                    QTY_3 = :MWIPBINHSS_N.QTY_3,
                    BIN_UNIT = :MWIPBINHSS_N.BIN_UNIT,
                    TOT_INPUT_QTY = :MWIPBINHSS_N.TOT_INPUT_QTY,
                    TOT_PASS_QTY = :MWIPBINHSS_N.TOT_PASS_QTY,
                    TOT_FAIL_QTY = :MWIPBINHSS_N.TOT_FAIL_QTY,
                    TOT_YIELD_BASE_QTY = :MWIPBINHSS_N.TOT_YIELD_BASE_QTY,
                    TOT_YIELD = :MWIPBINHSS_N.TOT_YIELD,
                    YIELD_CALC_TYPE = :MWIPBINHSS_N.YIELD_CALC_TYPE,
                    LOW_YIELD_FLAG = :MWIPBINHSS_N.LOW_YIELD_FLAG,
                    BASE_UYL = :MWIPBINHSS_N.BASE_UYL,
                    BASE_LYL = :MWIPBINHSS_N.BASE_LYL,
                    TRAN_ALARM_ID = :MWIPBINHSS_N.TRAN_ALARM_ID,
                    BIN_COMMENT_1 = :MWIPBINHSS_N.BIN_COMMENT_1,
                    BIN_COMMENT_2 = :MWIPBINHSS_N.BIN_COMMENT_2,
                    BIN_COMMENT_3 = :MWIPBINHSS_N.BIN_COMMENT_3,
                    TRAN_COMMENT_1 = :MWIPBINHSS_N.TRAN_COMMENT_1,
                    TRAN_COMMENT_2 = :MWIPBINHSS_N.TRAN_COMMENT_2,
                    TRAN_COMMENT_3 = :MWIPBINHSS_N.TRAN_COMMENT_3,
                    TRAN_CMF_1 = :MWIPBINHSS_N.TRAN_CMF_1,
                    TRAN_CMF_2 = :MWIPBINHSS_N.TRAN_CMF_2,
                    TRAN_CMF_3 = :MWIPBINHSS_N.TRAN_CMF_3,
                    TRAN_CMF_4 = :MWIPBINHSS_N.TRAN_CMF_4,
                    TRAN_CMF_5 = :MWIPBINHSS_N.TRAN_CMF_5,
                    TRAN_CMF_6 = :MWIPBINHSS_N.TRAN_CMF_6,
                    TRAN_CMF_7 = :MWIPBINHSS_N.TRAN_CMF_7,
                    TRAN_CMF_8 = :MWIPBINHSS_N.TRAN_CMF_8,
                    TRAN_CMF_9 = :MWIPBINHSS_N.TRAN_CMF_9,
                    TRAN_CMF_10 = :MWIPBINHSS_N.TRAN_CMF_10,
                    TRAN_CMF_11 = :MWIPBINHSS_N.TRAN_CMF_11,
                    TRAN_CMF_12 = :MWIPBINHSS_N.TRAN_CMF_12,
                    TRAN_CMF_13 = :MWIPBINHSS_N.TRAN_CMF_13,
                    TRAN_CMF_14 = :MWIPBINHSS_N.TRAN_CMF_14,
                    TRAN_CMF_15 = :MWIPBINHSS_N.TRAN_CMF_15,
                    TRAN_CMF_16 = :MWIPBINHSS_N.TRAN_CMF_16,
                    TRAN_CMF_17 = :MWIPBINHSS_N.TRAN_CMF_17,
                    TRAN_CMF_18 = :MWIPBINHSS_N.TRAN_CMF_18,
                    TRAN_CMF_19 = :MWIPBINHSS_N.TRAN_CMF_19,
                    TRAN_CMF_20 = :MWIPBINHSS_N.TRAN_CMF_20,
                    RESV_FIELD_1 = :MWIPBINHSS_N.RESV_FIELD_1,
                    RESV_FIELD_2 = :MWIPBINHSS_N.RESV_FIELD_2,
                    RESV_FIELD_3 = :MWIPBINHSS_N.RESV_FIELD_3,
                    RESV_FIELD_4 = :MWIPBINHSS_N.RESV_FIELD_4,
                    RESV_FIELD_5 = :MWIPBINHSS_N.RESV_FIELD_5,
                    RESV_FIELD_6 = :MWIPBINHSS_N.RESV_FIELD_6,
                    RESV_FIELD_7 = :MWIPBINHSS_N.RESV_FIELD_7,
                    RESV_FIELD_8 = :MWIPBINHSS_N.RESV_FIELD_8,
                    RESV_FIELD_9 = :MWIPBINHSS_N.RESV_FIELD_9,
                    RESV_FIELD_10 = :MWIPBINHSS_N.RESV_FIELD_10,
                    HIST_DEL_FLAG = :MWIPBINHSS_N.HIST_DEL_FLAG,
                    HIST_DEL_TIME = :MWIPBINHSS_N.HIST_DEL_TIME,
                    HIST_DEL_USER_ID = :MWIPBINHSS_N.HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT = :MWIPBINHSS_N.HIST_DEL_COMMENT
                WHERE SUBLOT_ID = :MWIPBINHSS_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINHSS_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINHSS_N.BIN_COL_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MWIPBINHSS  set FACTORY=:b0,BIN_ID=:b1,BIN_VERSION=:b2\
,TRAN_TIME=:b3,SYS_TRAN_TIME=:b4,LOT_ID=:b5,LOT_HIST_SEQ=:b6,MAT_ID=:b7,MAT_\
VER=:b8,FLOW=:b9,FLOW_SEQ_NUM=:b10,OPER=:b11,RES_ID=:b12,RES_TYPE=:b13,RESG_\
ID=:b14,QTY_2=:b15,QTY_3=:b16,BIN_UNIT=:b17,TOT_INPUT_QTY=:b18,TOT_PASS_QTY=\
:b19,TOT_FAIL_QTY=:b20,TOT_YIELD_BASE_QTY=:b21,TOT_YIELD=:b22,YIELD_CALC_TYP\
E=:b23,LOW_YIELD_FLAG=:b24,BASE_UYL=:b25,BASE_LYL=:b26,TRAN_ALARM_ID=:b27,BI\
N_COMMENT_1=:b28,BIN_COMMENT_2=:b29,BIN_COMMENT_3=:b30,TRAN_COMMENT_1=:b31,T\
RAN_COMMENT_2=:b32,TRAN_COMMENT_3=:b33,TRAN_CMF_1=:b34,TRAN_CMF_2=:b35,TRAN_\
CMF_3=:b36,TRAN_CMF_4=:b37,TRAN_CMF_5=:b38,TRAN_CMF_6=:b39,TRAN_CMF_7=:b40,T\
RAN_CMF_8=:b41,TRAN_CMF_9=:b42,TRAN_CMF_10=:b43,TRAN_CMF_11=:b44,TRAN_CMF_12\
=:b45,TRAN_CMF_13=:b46,TRAN_CMF_14=:b47,TRAN_CMF_15=:b48,TRAN_CMF_16=:b49,TR\
AN_CMF_17=:b50,TRAN_CMF_18=:b51,TRAN_CMF_19=:b52,TRAN_CMF_20=:b53,RESV_FIELD\
_1=:b54,RESV_FIELD_2=:b55,RESV_FIELD_3=:b56,RESV_FIELD_4=:b57,RESV_FIELD_5=:\
b58,RESV_FIELD_6=:b59,RESV_FIELD_7=:b60,RESV_FIELD_");
            sqlstm.stmt = "8=:b61,RESV_FIELD_9=:b62,RESV_FIELD_10=:b63,HIST\
_DEL_FLAG=:b64,HIST_DEL_TIME=:b65,HIST_DEL_USER_ID=:b66,HIST_DEL_COMMENT=:b67\
 where ((SUBLOT_ID=:b68 and HIST_SEQ=:b69) and BIN_COL_SEQ=:b70)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1310;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINHSS_N.BIN_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINHSS_N.BIN_VERSION);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINHSS_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINHSS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINHSS_N.LOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPBINHSS_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINHSS_N.MAT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPBINHSS_N.MAT_VER);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINHSS_N.FLOW);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MWIPBINHSS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPBINHSS_N.OPER);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINHSS_N.RES_ID);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPBINHSS_N.RES_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINHSS_N.RESG_ID);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MWIPBINHSS_N.QTY_2);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MWIPBINHSS_N.QTY_3);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINHSS_N.BIN_UNIT);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MWIPBINHSS_N.TOT_INPUT_QTY);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MWIPBINHSS_N.TOT_PASS_QTY);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MWIPBINHSS_N.TOT_FAIL_QTY);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD_BASE_QTY);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPBINHSS_N.YIELD_CALC_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPBINHSS_N.LOW_YIELD_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPBINHSS_N.BASE_UYL);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINHSS_N.BASE_LYL);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINHSS_N.TRAN_ALARM_ID);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_1);
            sqlstm.sqhstl[28] = (unsigned int  )401;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_2);
            sqlstm.sqhstl[29] = (unsigned int  )401;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_3);
            sqlstm.sqhstl[30] = (unsigned int  )401;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_1);
            sqlstm.sqhstl[31] = (unsigned int  )401;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_2);
            sqlstm.sqhstl[32] = (unsigned int  )401;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_3);
            sqlstm.sqhstl[33] = (unsigned int  )401;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_1);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_2);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_3);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_4);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_5);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_6);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_7);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_8);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_9);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_10);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_11);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_12);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_13);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_14);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_15);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_16);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_17);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_18);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_19);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_20);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_1);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_2);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_3);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_4);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_5);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_6);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_7);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_8);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_9);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_10);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPBINHSS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPBINHSS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[65] = (unsigned int  )15;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPBINHSS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPBINHSS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[67] = (unsigned int  )401;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[69] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
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
            /* EXEC SQL UPDATE MWIPBINHSS SET
                    HIST_DEL_FLAG = :MWIPBINHSS_N.HIST_DEL_FLAG,
                    HIST_DEL_TIME = :MWIPBINHSS_N.HIST_DEL_TIME,
                    HIST_DEL_USER_ID = :MWIPBINHSS_N.HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT = :MWIPBINHSS_N.HIST_DEL_COMMENT
                WHERE SUBLOT_ID = :MWIPBINHSS_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINHSS_N.HIST_SEQ
                    AND HIST_DEL_FLAG = ' '; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPBINHSS  set HIST_DEL_FLAG=:b0,HIST_DE\
L_TIME=:b1,HIST_DEL_USER_ID=:b2,HIST_DEL_COMMENT=:b3 where ((SUBLOT_ID=:b4 an\
d HIST_SEQ=:b5) and HIST_DEL_FLAG=' ')";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1609;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINHSS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINHSS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINHSS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[3] = (unsigned int  )401;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
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
            /* EXEC SQL UPDATE MWIPBINHSS SET
                    HIST_DEL_FLAG = :MWIPBINHSS_N.HIST_DEL_FLAG,
                    HIST_DEL_TIME = :MWIPBINHSS_N.HIST_DEL_TIME,
                    HIST_DEL_USER_ID = :MWIPBINHSS_N.HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT = :MWIPBINHSS_N.HIST_DEL_COMMENT
                WHERE SUBLOT_ID = :MWIPBINHSS_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINHSS_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINHSS_N.BIN_COL_SEQ
                    AND HIST_DEL_FLAG = ' '; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPBINHSS  set HIST_DEL_FLAG=:b0,HIST_DE\
L_TIME=:b1,HIST_DEL_USER_ID=:b2,HIST_DEL_COMMENT=:b3 where (((SUBLOT_ID=:b4 a\
nd HIST_SEQ=:b5) and BIN_COL_SEQ=:b6) and HIST_DEL_FLAG=' ')";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1648;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINHSS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINHSS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINHSS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[3] = (unsigned int  )401;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
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

    DB_stop_query_timer("DBC_update_mwipbinhss", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mwipbinhss(int sel_type, struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINHSS_N_TAG MWIPBINHSS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinhss(&MWIPBINHSS_N, MWIPBINHSS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MWIPBINHSS_CUR_1 CURSOR FOR
                SELECT 
                    SUBLOT_ID,
                    HIST_SEQ,
                    BIN_COL_SEQ,
                    FACTORY,
                    BIN_ID,
                    BIN_VERSION,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    LOT_ID,
                    LOT_HIST_SEQ,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    RES_ID,
                    RES_TYPE,
                    RESG_ID,
                    QTY_2,
                    QTY_3,
                    BIN_UNIT,
                    TOT_INPUT_QTY,
                    TOT_PASS_QTY,
                    TOT_FAIL_QTY,
                    TOT_YIELD_BASE_QTY,
                    TOT_YIELD,
                    YIELD_CALC_TYPE,
                    LOW_YIELD_FLAG,
                    BASE_UYL,
                    BASE_LYL,
                    TRAN_ALARM_ID,
                    BIN_COMMENT_1,
                    BIN_COMMENT_2,
                    BIN_COMMENT_3,
                    TRAN_COMMENT_1,
                    TRAN_COMMENT_2,
                    TRAN_COMMENT_3,
                    TRAN_CMF_1,
                    TRAN_CMF_2,
                    TRAN_CMF_3,
                    TRAN_CMF_4,
                    TRAN_CMF_5,
                    TRAN_CMF_6,
                    TRAN_CMF_7,
                    TRAN_CMF_8,
                    TRAN_CMF_9,
                    TRAN_CMF_10,
                    TRAN_CMF_11,
                    TRAN_CMF_12,
                    TRAN_CMF_13,
                    TRAN_CMF_14,
                    TRAN_CMF_15,
                    TRAN_CMF_16,
                    TRAN_CMF_17,
                    TRAN_CMF_18,
                    TRAN_CMF_19,
                    TRAN_CMF_20,
                    RESV_FIELD_1,
                    RESV_FIELD_2,
                    RESV_FIELD_3,
                    RESV_FIELD_4,
                    RESV_FIELD_5,
                    RESV_FIELD_6,
                    RESV_FIELD_7,
                    RESV_FIELD_8,
                    RESV_FIELD_9,
                    RESV_FIELD_10,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                FROM MWIPBINHSS
                WHERE LOT_ID = :MWIPBINHSS_N.LOT_ID
                    AND LOT_HIST_SEQ = :MWIPBINHSS_N.LOT_HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINHSS_N.BIN_COL_SEQ
                    AND HIST_DEL_FLAG LIKE :MWIPBINHSS_N.HIST_DEL_FLAG
                    AND ((SUBLOT_ID = :MWIPBINHSS_N.SUBLOT_ID AND HIST_SEQ <= :MWIPBINHSS_N.HIST_SEQ) OR SUBLOT_ID > :MWIPBINHSS_N.SUBLOT_ID)
                ORDER BY SUBLOT_ID ASC, HIST_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_MWIPBINHSS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select SUBLOT_ID ,HIST_SEQ ,BIN_COL_SEQ ,FACTORY ,BIN_ID ,BIN\
_VERSION ,TRAN_TIME ,SYS_TRAN_TIME ,LOT_ID ,LOT_HIST_SEQ ,MAT_ID ,MAT_VER ,F\
LOW ,FLOW_SEQ_NUM ,OPER ,RES_ID ,RES_TYPE ,RESG_ID ,QTY_2 ,QTY_3 ,BIN_UNIT ,\
TOT_INPUT_QTY ,TOT_PASS_QTY ,TOT_FAIL_QTY ,TOT_YIELD_BASE_QTY ,TOT_YIELD ,YI\
ELD_CALC_TYPE ,LOW_YIELD_FLAG ,BASE_UYL ,BASE_LYL ,TRAN_ALARM_ID ,BIN_COMMEN\
T_1 ,BIN_COMMENT_2 ,BIN_COMMENT_3 ,TRAN_COMMENT_1 ,TRAN_COMMENT_2 ,TRAN_COMM\
ENT_3 ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_\
6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12\
 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_\
18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_FIELD_3 ,RESV\
_FIELD_4 ,RESV_FIELD_5 ,RESV_FIELD_6 ,RESV_FIELD_7 ,RESV_FIELD_8 ,RESV_FIELD\
_9 ,RESV_FIELD_10 ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_\
COMMENT  from MWIPBINHSS where ((((LOT_ID=:b0 and LOT_HIST_SEQ=:b1) and BIN_\
COL_SEQ=:b2) and HIST_DEL_FLAG like :b3) and ((SUBL");
            sqlstm.stmt = sq0011;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1691;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINHSS_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINHSS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
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

    DB_stop_query_timer("DBC_open_mwipbinhss", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mwipbinhss(int sel_type, struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINHSS_N_TAG MWIPBINHSS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MWIPBINHSS_CUR_1 INTO
                :MWIPBINHSS_N.SUBLOT_ID,
                :MWIPBINHSS_N.HIST_SEQ,
                :MWIPBINHSS_N.BIN_COL_SEQ,
                :MWIPBINHSS_N.FACTORY,
                :MWIPBINHSS_N.BIN_ID,
                :MWIPBINHSS_N.BIN_VERSION,
                :MWIPBINHSS_N.TRAN_TIME,
                :MWIPBINHSS_N.SYS_TRAN_TIME,
                :MWIPBINHSS_N.LOT_ID,
                :MWIPBINHSS_N.LOT_HIST_SEQ,
                :MWIPBINHSS_N.MAT_ID,
                :MWIPBINHSS_N.MAT_VER,
                :MWIPBINHSS_N.FLOW,
                :MWIPBINHSS_N.FLOW_SEQ_NUM,
                :MWIPBINHSS_N.OPER,
                :MWIPBINHSS_N.RES_ID,
                :MWIPBINHSS_N.RES_TYPE,
                :MWIPBINHSS_N.RESG_ID,
                :MWIPBINHSS_N.QTY_2,
                :MWIPBINHSS_N.QTY_3,
                :MWIPBINHSS_N.BIN_UNIT,
                :MWIPBINHSS_N.TOT_INPUT_QTY,
                :MWIPBINHSS_N.TOT_PASS_QTY,
                :MWIPBINHSS_N.TOT_FAIL_QTY,
                :MWIPBINHSS_N.TOT_YIELD_BASE_QTY,
                :MWIPBINHSS_N.TOT_YIELD,
                :MWIPBINHSS_N.YIELD_CALC_TYPE,
                :MWIPBINHSS_N.LOW_YIELD_FLAG,
                :MWIPBINHSS_N.BASE_UYL,
                :MWIPBINHSS_N.BASE_LYL,
                :MWIPBINHSS_N.TRAN_ALARM_ID,
                :MWIPBINHSS_N.BIN_COMMENT_1,
                :MWIPBINHSS_N.BIN_COMMENT_2,
                :MWIPBINHSS_N.BIN_COMMENT_3,
                :MWIPBINHSS_N.TRAN_COMMENT_1,
                :MWIPBINHSS_N.TRAN_COMMENT_2,
                :MWIPBINHSS_N.TRAN_COMMENT_3,
                :MWIPBINHSS_N.TRAN_CMF_1,
                :MWIPBINHSS_N.TRAN_CMF_2,
                :MWIPBINHSS_N.TRAN_CMF_3,
                :MWIPBINHSS_N.TRAN_CMF_4,
                :MWIPBINHSS_N.TRAN_CMF_5,
                :MWIPBINHSS_N.TRAN_CMF_6,
                :MWIPBINHSS_N.TRAN_CMF_7,
                :MWIPBINHSS_N.TRAN_CMF_8,
                :MWIPBINHSS_N.TRAN_CMF_9,
                :MWIPBINHSS_N.TRAN_CMF_10,
                :MWIPBINHSS_N.TRAN_CMF_11,
                :MWIPBINHSS_N.TRAN_CMF_12,
                :MWIPBINHSS_N.TRAN_CMF_13,
                :MWIPBINHSS_N.TRAN_CMF_14,
                :MWIPBINHSS_N.TRAN_CMF_15,
                :MWIPBINHSS_N.TRAN_CMF_16,
                :MWIPBINHSS_N.TRAN_CMF_17,
                :MWIPBINHSS_N.TRAN_CMF_18,
                :MWIPBINHSS_N.TRAN_CMF_19,
                :MWIPBINHSS_N.TRAN_CMF_20,
                :MWIPBINHSS_N.RESV_FIELD_1,
                :MWIPBINHSS_N.RESV_FIELD_2,
                :MWIPBINHSS_N.RESV_FIELD_3,
                :MWIPBINHSS_N.RESV_FIELD_4,
                :MWIPBINHSS_N.RESV_FIELD_5,
                :MWIPBINHSS_N.RESV_FIELD_6,
                :MWIPBINHSS_N.RESV_FIELD_7,
                :MWIPBINHSS_N.RESV_FIELD_8,
                :MWIPBINHSS_N.RESV_FIELD_9,
                :MWIPBINHSS_N.RESV_FIELD_10,
                :MWIPBINHSS_N.HIST_DEL_FLAG,
                :MWIPBINHSS_N.HIST_DEL_TIME,
                :MWIPBINHSS_N.HIST_DEL_USER_ID,
                :MWIPBINHSS_N.HIST_DEL_COMMENT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1734;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINHSS_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINHSS_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINHSS_N.BIN_COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINHSS_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINHSS_N.BIN_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPBINHSS_N.BIN_VERSION);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPBINHSS_N.TRAN_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINHSS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPBINHSS_N.LOT_ID);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MWIPBINHSS_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINHSS_N.MAT_ID);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(MWIPBINHSS_N.MAT_VER);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINHSS_N.FLOW);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MWIPBINHSS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINHSS_N.OPER);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPBINHSS_N.RES_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINHSS_N.RES_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINHSS_N.RESG_ID);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MWIPBINHSS_N.QTY_2);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MWIPBINHSS_N.QTY_3);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINHSS_N.BIN_UNIT);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MWIPBINHSS_N.TOT_INPUT_QTY);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MWIPBINHSS_N.TOT_PASS_QTY);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPBINHSS_N.TOT_FAIL_QTY);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD_BASE_QTY);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPBINHSS_N.TOT_YIELD);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINHSS_N.YIELD_CALC_TYPE);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINHSS_N.LOW_YIELD_FLAG);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINHSS_N.BASE_UYL);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINHSS_N.BASE_LYL);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINHSS_N.TRAN_ALARM_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_1);
            sqlstm.sqhstl[31] = (unsigned int  )401;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_2);
            sqlstm.sqhstl[32] = (unsigned int  )401;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINHSS_N.BIN_COMMENT_3);
            sqlstm.sqhstl[33] = (unsigned int  )401;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_1);
            sqlstm.sqhstl[34] = (unsigned int  )401;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_2);
            sqlstm.sqhstl[35] = (unsigned int  )401;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPBINHSS_N.TRAN_COMMENT_3);
            sqlstm.sqhstl[36] = (unsigned int  )401;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_16);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_17);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_18);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_19);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPBINHSS_N.TRAN_CMF_20);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_1);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_2);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_3);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_4);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_5);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_6);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_7);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_8);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_9);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPBINHSS_N.RESV_FIELD_10);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPBINHSS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPBINHSS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPBINHSS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPBINHSS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[70] = (unsigned int  )401;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
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
        DBC_del_null_mwipbinhss(&MWIPBINHSS_N, MWIPBINHSS);
    }

    DB_stop_query_timer("DBC_fetch_mwipbinhss", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mwipbinhss(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MWIPBINHSS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2033;
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

    DB_stop_query_timer("DBC_close_mwipbinhss", sel_type);
}


/* Initialize Function */
void DBC_init_mwipbinhss(struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    /* memset by Space */
    memset(MWIPBINHSS, ' ', sizeof(struct MWIPBINHSS_TAG));
    
    MWIPBINHSS->HIST_SEQ = 0;
    MWIPBINHSS->BIN_COL_SEQ = 0;
    MWIPBINHSS->BIN_VERSION = 0;
    MWIPBINHSS->LOT_HIST_SEQ = 0;
    MWIPBINHSS->MAT_VER = 0;
    MWIPBINHSS->FLOW_SEQ_NUM = 0;
    MWIPBINHSS->QTY_2 = 0;
    MWIPBINHSS->QTY_3 = 0;
    MWIPBINHSS->TOT_INPUT_QTY = 0;
    MWIPBINHSS->TOT_PASS_QTY = 0;
    MWIPBINHSS->TOT_FAIL_QTY = 0;
    MWIPBINHSS->TOT_YIELD_BASE_QTY = 0;
    MWIPBINHSS->TOT_YIELD = 0;
}


/* Add Null Function */
void DBC_add_null_mwipbinhss(struct MWIPBINHSS_N_TAG *MWIPBINHSS_N, struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    /* memset by NULL */
    memset(MWIPBINHSS_N, '\0', sizeof(struct MWIPBINHSS_N_TAG));
    
    MEMCPY_AN(MWIPBINHSS_N->SUBLOT_ID, MWIPBINHSS->SUBLOT_ID, sizeof(MWIPBINHSS->SUBLOT_ID));
    MWIPBINHSS_N->HIST_SEQ = MWIPBINHSS->HIST_SEQ;
    MWIPBINHSS_N->BIN_COL_SEQ = MWIPBINHSS->BIN_COL_SEQ;
    MEMCPY_AN(MWIPBINHSS_N->FACTORY, MWIPBINHSS->FACTORY, sizeof(MWIPBINHSS->FACTORY));
    MEMCPY_AN(MWIPBINHSS_N->BIN_ID, MWIPBINHSS->BIN_ID, sizeof(MWIPBINHSS->BIN_ID));
    MWIPBINHSS_N->BIN_VERSION = MWIPBINHSS->BIN_VERSION;
    MEMCPY_AN(MWIPBINHSS_N->TRAN_TIME, MWIPBINHSS->TRAN_TIME, sizeof(MWIPBINHSS->TRAN_TIME));
    MEMCPY_AN(MWIPBINHSS_N->SYS_TRAN_TIME, MWIPBINHSS->SYS_TRAN_TIME, sizeof(MWIPBINHSS->SYS_TRAN_TIME));
    MEMCPY_AN(MWIPBINHSS_N->LOT_ID, MWIPBINHSS->LOT_ID, sizeof(MWIPBINHSS->LOT_ID));
    MWIPBINHSS_N->LOT_HIST_SEQ = MWIPBINHSS->LOT_HIST_SEQ;
    MEMCPY_AN(MWIPBINHSS_N->MAT_ID, MWIPBINHSS->MAT_ID, sizeof(MWIPBINHSS->MAT_ID));
    MWIPBINHSS_N->MAT_VER = MWIPBINHSS->MAT_VER;
    MEMCPY_AN(MWIPBINHSS_N->FLOW, MWIPBINHSS->FLOW, sizeof(MWIPBINHSS->FLOW));
    MWIPBINHSS_N->FLOW_SEQ_NUM = MWIPBINHSS->FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPBINHSS_N->OPER, MWIPBINHSS->OPER, sizeof(MWIPBINHSS->OPER));
    MEMCPY_AN(MWIPBINHSS_N->RES_ID, MWIPBINHSS->RES_ID, sizeof(MWIPBINHSS->RES_ID));
    MEMCPY_AN(MWIPBINHSS_N->RES_TYPE, MWIPBINHSS->RES_TYPE, sizeof(MWIPBINHSS->RES_TYPE));
    MEMCPY_AN(MWIPBINHSS_N->RESG_ID, MWIPBINHSS->RESG_ID, sizeof(MWIPBINHSS->RESG_ID));
    MWIPBINHSS_N->QTY_2 = MWIPBINHSS->QTY_2;
    MWIPBINHSS_N->QTY_3 = MWIPBINHSS->QTY_3;
    MEMCPY_AN(MWIPBINHSS_N->BIN_UNIT, MWIPBINHSS->BIN_UNIT, sizeof(MWIPBINHSS->BIN_UNIT));
    MWIPBINHSS_N->TOT_INPUT_QTY = MWIPBINHSS->TOT_INPUT_QTY;
    MWIPBINHSS_N->TOT_PASS_QTY = MWIPBINHSS->TOT_PASS_QTY;
    MWIPBINHSS_N->TOT_FAIL_QTY = MWIPBINHSS->TOT_FAIL_QTY;
    MWIPBINHSS_N->TOT_YIELD_BASE_QTY = MWIPBINHSS->TOT_YIELD_BASE_QTY;
    MWIPBINHSS_N->TOT_YIELD = MWIPBINHSS->TOT_YIELD;
    MWIPBINHSS_N->YIELD_CALC_TYPE[0] = MWIPBINHSS->YIELD_CALC_TYPE;
    MWIPBINHSS_N->LOW_YIELD_FLAG[0] = MWIPBINHSS->LOW_YIELD_FLAG;
    MEMCPY_AN(MWIPBINHSS_N->BASE_UYL, MWIPBINHSS->BASE_UYL, sizeof(MWIPBINHSS->BASE_UYL));
    MEMCPY_AN(MWIPBINHSS_N->BASE_LYL, MWIPBINHSS->BASE_LYL, sizeof(MWIPBINHSS->BASE_LYL));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_ALARM_ID, MWIPBINHSS->TRAN_ALARM_ID, sizeof(MWIPBINHSS->TRAN_ALARM_ID));
    MEMCPY_AN(MWIPBINHSS_N->BIN_COMMENT_1, MWIPBINHSS->BIN_COMMENT_1, sizeof(MWIPBINHSS->BIN_COMMENT_1));
    MEMCPY_AN(MWIPBINHSS_N->BIN_COMMENT_2, MWIPBINHSS->BIN_COMMENT_2, sizeof(MWIPBINHSS->BIN_COMMENT_2));
    MEMCPY_AN(MWIPBINHSS_N->BIN_COMMENT_3, MWIPBINHSS->BIN_COMMENT_3, sizeof(MWIPBINHSS->BIN_COMMENT_3));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_COMMENT_1, MWIPBINHSS->TRAN_COMMENT_1, sizeof(MWIPBINHSS->TRAN_COMMENT_1));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_COMMENT_2, MWIPBINHSS->TRAN_COMMENT_2, sizeof(MWIPBINHSS->TRAN_COMMENT_2));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_COMMENT_3, MWIPBINHSS->TRAN_COMMENT_3, sizeof(MWIPBINHSS->TRAN_COMMENT_3));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_1, MWIPBINHSS->TRAN_CMF_1, sizeof(MWIPBINHSS->TRAN_CMF_1));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_2, MWIPBINHSS->TRAN_CMF_2, sizeof(MWIPBINHSS->TRAN_CMF_2));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_3, MWIPBINHSS->TRAN_CMF_3, sizeof(MWIPBINHSS->TRAN_CMF_3));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_4, MWIPBINHSS->TRAN_CMF_4, sizeof(MWIPBINHSS->TRAN_CMF_4));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_5, MWIPBINHSS->TRAN_CMF_5, sizeof(MWIPBINHSS->TRAN_CMF_5));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_6, MWIPBINHSS->TRAN_CMF_6, sizeof(MWIPBINHSS->TRAN_CMF_6));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_7, MWIPBINHSS->TRAN_CMF_7, sizeof(MWIPBINHSS->TRAN_CMF_7));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_8, MWIPBINHSS->TRAN_CMF_8, sizeof(MWIPBINHSS->TRAN_CMF_8));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_9, MWIPBINHSS->TRAN_CMF_9, sizeof(MWIPBINHSS->TRAN_CMF_9));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_10, MWIPBINHSS->TRAN_CMF_10, sizeof(MWIPBINHSS->TRAN_CMF_10));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_11, MWIPBINHSS->TRAN_CMF_11, sizeof(MWIPBINHSS->TRAN_CMF_11));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_12, MWIPBINHSS->TRAN_CMF_12, sizeof(MWIPBINHSS->TRAN_CMF_12));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_13, MWIPBINHSS->TRAN_CMF_13, sizeof(MWIPBINHSS->TRAN_CMF_13));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_14, MWIPBINHSS->TRAN_CMF_14, sizeof(MWIPBINHSS->TRAN_CMF_14));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_15, MWIPBINHSS->TRAN_CMF_15, sizeof(MWIPBINHSS->TRAN_CMF_15));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_16, MWIPBINHSS->TRAN_CMF_16, sizeof(MWIPBINHSS->TRAN_CMF_16));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_17, MWIPBINHSS->TRAN_CMF_17, sizeof(MWIPBINHSS->TRAN_CMF_17));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_18, MWIPBINHSS->TRAN_CMF_18, sizeof(MWIPBINHSS->TRAN_CMF_18));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_19, MWIPBINHSS->TRAN_CMF_19, sizeof(MWIPBINHSS->TRAN_CMF_19));
    MEMCPY_AN(MWIPBINHSS_N->TRAN_CMF_20, MWIPBINHSS->TRAN_CMF_20, sizeof(MWIPBINHSS->TRAN_CMF_20));
    MEMCPY_AN(MWIPBINHSS_N->RESV_FIELD_1, MWIPBINHSS->RESV_FIELD_1, sizeof(MWIPBINHSS->RESV_FIELD_1));
    MEMCPY_AN(MWIPBINHSS_N->RESV_FIELD_2, MWIPBINHSS->RESV_FIELD_2, sizeof(MWIPBINHSS->RESV_FIELD_2));
    MEMCPY_AN(MWIPBINHSS_N->RESV_FIELD_3, MWIPBINHSS->RESV_FIELD_3, sizeof(MWIPBINHSS->RESV_FIELD_3));
    MEMCPY_AN(MWIPBINHSS_N->RESV_FIELD_4, MWIPBINHSS->RESV_FIELD_4, sizeof(MWIPBINHSS->RESV_FIELD_4));
    MEMCPY_AN(MWIPBINHSS_N->RESV_FIELD_5, MWIPBINHSS->RESV_FIELD_5, sizeof(MWIPBINHSS->RESV_FIELD_5));
    MEMCPY_AN(MWIPBINHSS_N->RESV_FIELD_6, MWIPBINHSS->RESV_FIELD_6, sizeof(MWIPBINHSS->RESV_FIELD_6));
    MEMCPY_AN(MWIPBINHSS_N->RESV_FIELD_7, MWIPBINHSS->RESV_FIELD_7, sizeof(MWIPBINHSS->RESV_FIELD_7));
    MEMCPY_AN(MWIPBINHSS_N->RESV_FIELD_8, MWIPBINHSS->RESV_FIELD_8, sizeof(MWIPBINHSS->RESV_FIELD_8));
    MEMCPY_AN(MWIPBINHSS_N->RESV_FIELD_9, MWIPBINHSS->RESV_FIELD_9, sizeof(MWIPBINHSS->RESV_FIELD_9));
    MEMCPY_AN(MWIPBINHSS_N->RESV_FIELD_10, MWIPBINHSS->RESV_FIELD_10, sizeof(MWIPBINHSS->RESV_FIELD_10));
    MWIPBINHSS_N->HIST_DEL_FLAG[0] = MWIPBINHSS->HIST_DEL_FLAG;
    MEMCPY_AN(MWIPBINHSS_N->HIST_DEL_TIME, MWIPBINHSS->HIST_DEL_TIME, sizeof(MWIPBINHSS->HIST_DEL_TIME));
    MEMCPY_AN(MWIPBINHSS_N->HIST_DEL_USER_ID, MWIPBINHSS->HIST_DEL_USER_ID, sizeof(MWIPBINHSS->HIST_DEL_USER_ID));
    MEMCPY_AN(MWIPBINHSS_N->HIST_DEL_COMMENT, MWIPBINHSS->HIST_DEL_COMMENT, sizeof(MWIPBINHSS->HIST_DEL_COMMENT));
}


/* Del Null Function */
void DBC_del_null_mwipbinhss(struct MWIPBINHSS_N_TAG *MWIPBINHSS_N, struct MWIPBINHSS_TAG *MWIPBINHSS)
{
    MEMCPY_DN(MWIPBINHSS->SUBLOT_ID, MWIPBINHSS_N->SUBLOT_ID, sizeof(MWIPBINHSS->SUBLOT_ID));
    MWIPBINHSS->HIST_SEQ = MWIPBINHSS_N->HIST_SEQ;
    MWIPBINHSS->BIN_COL_SEQ = MWIPBINHSS_N->BIN_COL_SEQ;
    MEMCPY_DN(MWIPBINHSS->FACTORY, MWIPBINHSS_N->FACTORY, sizeof(MWIPBINHSS->FACTORY));
    MEMCPY_DN(MWIPBINHSS->BIN_ID, MWIPBINHSS_N->BIN_ID, sizeof(MWIPBINHSS->BIN_ID));
    MWIPBINHSS->BIN_VERSION = MWIPBINHSS_N->BIN_VERSION;
    MEMCPY_DN(MWIPBINHSS->TRAN_TIME, MWIPBINHSS_N->TRAN_TIME, sizeof(MWIPBINHSS->TRAN_TIME));
    MEMCPY_DN(MWIPBINHSS->SYS_TRAN_TIME, MWIPBINHSS_N->SYS_TRAN_TIME, sizeof(MWIPBINHSS->SYS_TRAN_TIME));
    MEMCPY_DN(MWIPBINHSS->LOT_ID, MWIPBINHSS_N->LOT_ID, sizeof(MWIPBINHSS->LOT_ID));
    MWIPBINHSS->LOT_HIST_SEQ = MWIPBINHSS_N->LOT_HIST_SEQ;
    MEMCPY_DN(MWIPBINHSS->MAT_ID, MWIPBINHSS_N->MAT_ID, sizeof(MWIPBINHSS->MAT_ID));
    MWIPBINHSS->MAT_VER = MWIPBINHSS_N->MAT_VER;
    MEMCPY_DN(MWIPBINHSS->FLOW, MWIPBINHSS_N->FLOW, sizeof(MWIPBINHSS->FLOW));
    MWIPBINHSS->FLOW_SEQ_NUM = MWIPBINHSS_N->FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPBINHSS->OPER, MWIPBINHSS_N->OPER, sizeof(MWIPBINHSS->OPER));
    MEMCPY_DN(MWIPBINHSS->RES_ID, MWIPBINHSS_N->RES_ID, sizeof(MWIPBINHSS->RES_ID));
    MEMCPY_DN(MWIPBINHSS->RES_TYPE, MWIPBINHSS_N->RES_TYPE, sizeof(MWIPBINHSS->RES_TYPE));
    MEMCPY_DN(MWIPBINHSS->RESG_ID, MWIPBINHSS_N->RESG_ID, sizeof(MWIPBINHSS->RESG_ID));
    MWIPBINHSS->QTY_2 = MWIPBINHSS_N->QTY_2;
    MWIPBINHSS->QTY_3 = MWIPBINHSS_N->QTY_3;
    MEMCPY_DN(MWIPBINHSS->BIN_UNIT, MWIPBINHSS_N->BIN_UNIT, sizeof(MWIPBINHSS->BIN_UNIT));
    MWIPBINHSS->TOT_INPUT_QTY = MWIPBINHSS_N->TOT_INPUT_QTY;
    MWIPBINHSS->TOT_PASS_QTY = MWIPBINHSS_N->TOT_PASS_QTY;
    MWIPBINHSS->TOT_FAIL_QTY = MWIPBINHSS_N->TOT_FAIL_QTY;
    MWIPBINHSS->TOT_YIELD_BASE_QTY = MWIPBINHSS_N->TOT_YIELD_BASE_QTY;
    MWIPBINHSS->TOT_YIELD = MWIPBINHSS_N->TOT_YIELD;
    MWIPBINHSS->YIELD_CALC_TYPE = MWIPBINHSS_N->YIELD_CALC_TYPE[0];
    MWIPBINHSS->LOW_YIELD_FLAG = MWIPBINHSS_N->LOW_YIELD_FLAG[0];
    MEMCPY_DN(MWIPBINHSS->BASE_UYL, MWIPBINHSS_N->BASE_UYL, sizeof(MWIPBINHSS->BASE_UYL));
    MEMCPY_DN(MWIPBINHSS->BASE_LYL, MWIPBINHSS_N->BASE_LYL, sizeof(MWIPBINHSS->BASE_LYL));
    MEMCPY_DN(MWIPBINHSS->TRAN_ALARM_ID, MWIPBINHSS_N->TRAN_ALARM_ID, sizeof(MWIPBINHSS->TRAN_ALARM_ID));
    MEMCPY_DN(MWIPBINHSS->BIN_COMMENT_1, MWIPBINHSS_N->BIN_COMMENT_1, sizeof(MWIPBINHSS->BIN_COMMENT_1));
    MEMCPY_DN(MWIPBINHSS->BIN_COMMENT_2, MWIPBINHSS_N->BIN_COMMENT_2, sizeof(MWIPBINHSS->BIN_COMMENT_2));
    MEMCPY_DN(MWIPBINHSS->BIN_COMMENT_3, MWIPBINHSS_N->BIN_COMMENT_3, sizeof(MWIPBINHSS->BIN_COMMENT_3));
    MEMCPY_DN(MWIPBINHSS->TRAN_COMMENT_1, MWIPBINHSS_N->TRAN_COMMENT_1, sizeof(MWIPBINHSS->TRAN_COMMENT_1));
    MEMCPY_DN(MWIPBINHSS->TRAN_COMMENT_2, MWIPBINHSS_N->TRAN_COMMENT_2, sizeof(MWIPBINHSS->TRAN_COMMENT_2));
    MEMCPY_DN(MWIPBINHSS->TRAN_COMMENT_3, MWIPBINHSS_N->TRAN_COMMENT_3, sizeof(MWIPBINHSS->TRAN_COMMENT_3));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_1, MWIPBINHSS_N->TRAN_CMF_1, sizeof(MWIPBINHSS->TRAN_CMF_1));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_2, MWIPBINHSS_N->TRAN_CMF_2, sizeof(MWIPBINHSS->TRAN_CMF_2));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_3, MWIPBINHSS_N->TRAN_CMF_3, sizeof(MWIPBINHSS->TRAN_CMF_3));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_4, MWIPBINHSS_N->TRAN_CMF_4, sizeof(MWIPBINHSS->TRAN_CMF_4));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_5, MWIPBINHSS_N->TRAN_CMF_5, sizeof(MWIPBINHSS->TRAN_CMF_5));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_6, MWIPBINHSS_N->TRAN_CMF_6, sizeof(MWIPBINHSS->TRAN_CMF_6));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_7, MWIPBINHSS_N->TRAN_CMF_7, sizeof(MWIPBINHSS->TRAN_CMF_7));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_8, MWIPBINHSS_N->TRAN_CMF_8, sizeof(MWIPBINHSS->TRAN_CMF_8));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_9, MWIPBINHSS_N->TRAN_CMF_9, sizeof(MWIPBINHSS->TRAN_CMF_9));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_10, MWIPBINHSS_N->TRAN_CMF_10, sizeof(MWIPBINHSS->TRAN_CMF_10));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_11, MWIPBINHSS_N->TRAN_CMF_11, sizeof(MWIPBINHSS->TRAN_CMF_11));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_12, MWIPBINHSS_N->TRAN_CMF_12, sizeof(MWIPBINHSS->TRAN_CMF_12));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_13, MWIPBINHSS_N->TRAN_CMF_13, sizeof(MWIPBINHSS->TRAN_CMF_13));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_14, MWIPBINHSS_N->TRAN_CMF_14, sizeof(MWIPBINHSS->TRAN_CMF_14));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_15, MWIPBINHSS_N->TRAN_CMF_15, sizeof(MWIPBINHSS->TRAN_CMF_15));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_16, MWIPBINHSS_N->TRAN_CMF_16, sizeof(MWIPBINHSS->TRAN_CMF_16));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_17, MWIPBINHSS_N->TRAN_CMF_17, sizeof(MWIPBINHSS->TRAN_CMF_17));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_18, MWIPBINHSS_N->TRAN_CMF_18, sizeof(MWIPBINHSS->TRAN_CMF_18));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_19, MWIPBINHSS_N->TRAN_CMF_19, sizeof(MWIPBINHSS->TRAN_CMF_19));
    MEMCPY_DN(MWIPBINHSS->TRAN_CMF_20, MWIPBINHSS_N->TRAN_CMF_20, sizeof(MWIPBINHSS->TRAN_CMF_20));
    MEMCPY_DN(MWIPBINHSS->RESV_FIELD_1, MWIPBINHSS_N->RESV_FIELD_1, sizeof(MWIPBINHSS->RESV_FIELD_1));
    MEMCPY_DN(MWIPBINHSS->RESV_FIELD_2, MWIPBINHSS_N->RESV_FIELD_2, sizeof(MWIPBINHSS->RESV_FIELD_2));
    MEMCPY_DN(MWIPBINHSS->RESV_FIELD_3, MWIPBINHSS_N->RESV_FIELD_3, sizeof(MWIPBINHSS->RESV_FIELD_3));
    MEMCPY_DN(MWIPBINHSS->RESV_FIELD_4, MWIPBINHSS_N->RESV_FIELD_4, sizeof(MWIPBINHSS->RESV_FIELD_4));
    MEMCPY_DN(MWIPBINHSS->RESV_FIELD_5, MWIPBINHSS_N->RESV_FIELD_5, sizeof(MWIPBINHSS->RESV_FIELD_5));
    MEMCPY_DN(MWIPBINHSS->RESV_FIELD_6, MWIPBINHSS_N->RESV_FIELD_6, sizeof(MWIPBINHSS->RESV_FIELD_6));
    MEMCPY_DN(MWIPBINHSS->RESV_FIELD_7, MWIPBINHSS_N->RESV_FIELD_7, sizeof(MWIPBINHSS->RESV_FIELD_7));
    MEMCPY_DN(MWIPBINHSS->RESV_FIELD_8, MWIPBINHSS_N->RESV_FIELD_8, sizeof(MWIPBINHSS->RESV_FIELD_8));
    MEMCPY_DN(MWIPBINHSS->RESV_FIELD_9, MWIPBINHSS_N->RESV_FIELD_9, sizeof(MWIPBINHSS->RESV_FIELD_9));
    MEMCPY_DN(MWIPBINHSS->RESV_FIELD_10, MWIPBINHSS_N->RESV_FIELD_10, sizeof(MWIPBINHSS->RESV_FIELD_10));
    MWIPBINHSS->HIST_DEL_FLAG = MWIPBINHSS_N->HIST_DEL_FLAG[0];
    MEMCPY_DN(MWIPBINHSS->HIST_DEL_TIME, MWIPBINHSS_N->HIST_DEL_TIME, sizeof(MWIPBINHSS->HIST_DEL_TIME));
    MEMCPY_DN(MWIPBINHSS->HIST_DEL_USER_ID, MWIPBINHSS_N->HIST_DEL_USER_ID, sizeof(MWIPBINHSS->HIST_DEL_USER_ID));
    MEMCPY_DN(MWIPBINHSS->HIST_DEL_COMMENT, MWIPBINHSS_N->HIST_DEL_COMMENT, sizeof(MWIPBINHSS->HIST_DEL_COMMENT));
}


