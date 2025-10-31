
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
    "DBC_mtmpcrrhis.pc"
};


static unsigned int sqlctx = 9139779;


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
            void  *sqhstv[80];
   unsigned int   sqhstl[80];
            int   sqhsts[80];
            void  *sqindv[80];
            int   sqinds[80];
   unsigned int   sqharm[80];
   unsigned int   *sqharc[80];
   unsigned short  sqadto[80];
   unsigned short  sqtdso[80];
} sqlstm = {13,80};

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
"select TABLE_UPDATE_SEQ ,CM_KEY_1 ,CM_KEY_2 ,CM_KEY_3 ,CM_KEY_4 ,CM_KEY_5 ,\
CRR_ID ,HIST_SEQ ,TRAN_TIME ,SYS_TRAN_TIME ,TRAN_CODE ,FACTORY ,CRR_STATUS ,C\
RR_STATUS_FLAG ,USAGE_COUNT ,CLEAN_COUNT ,RES_ID ,SUBRES_ID ,PORT_ID ,LOCATIO\
N_1 ,LOCATION_2 ,LOCATION_3 ,LOCATION_4 ,LOCATION_5 ,FINISH_CLEAN_FLAG ,LAST_\
CLEAN_TIME ,LOT_ID ,LOT_HIST_SEQ ,QTY_1 ,QTY_2 ,QTY_3 ,TBL_SLOT ,MOVE_FLAG ,E\
MPTY_FLAG ,STOCK_IN_TIME ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRA\
N_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_CM\
F_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,TRAN_CMF_16 ,TRAN_C\
MF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,TRAN_USER_ID ,TRAN_COMMENT ,PRO\
CESS_FLAG ,CRR_CMF_1 ,CRR_CMF_2 ,CRR_CMF_3 ,CRR_CMF_4 ,CRR_CMF_5 ,CRR_CMF_6 ,\
CRR_CMF_7 ,CRR_CMF_8 ,CRR_CMF_9 ,CRR_CMF_10 ,CRR_CMF_11 ,CRR_CMF_12 ,CRR_CMF_\
13 ,CRR_CMF_14 ,CRR_CMF_15 ,CRR_CMF_16 ,CRR_CMF_17 ,CRR_CMF_18 ,CRR_CMF_19 ,C\
RR_CMF_20 ,REUSE_COUNT  from MTMPCRRHIS  order by TABLE_UPDATE_SEQ asc       \
      ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1378,0,4,44,0,0,80,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,1,3,0,0,
340,0,0,2,1390,0,4,240,0,0,80,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,1,3,0,0,
675,0,0,3,69,0,4,440,0,0,2,1,0,1,0,2,4,0,0,1,3,0,0,
698,0,0,4,51,0,4,446,0,0,1,0,0,1,0,2,4,0,0,
717,0,0,5,51,0,2,479,0,0,1,1,0,1,0,1,3,0,0,
736,0,0,6,1278,0,3,506,0,0,79,79,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1067,0,0,7,1273,0,5,687,0,0,79,79,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
1398,0,0,8,1005,0,9,878,0,0,0,0,0,1,0,
1413,0,0,8,0,0,13,906,0,0,79,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,
1744,0,0,8,0,0,15,1015,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mtmpcrrhis.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2017-10-18 16:54:55
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2017 MIRACOM,INC.
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
void DBC_add_null_mtmpcrrhis(struct MTMPCRRHIS_N_TAG *MTMPCRRHIS_N, struct MTMPCRRHIS_TAG *MTMPCRRHIS);
void DBC_del_null_mtmpcrrhis(struct MTMPCRRHIS_N_TAG *MTMPCRRHIS_N, struct MTMPCRRHIS_TAG *MTMPCRRHIS);


/* SQL SELECT Function */
void DBC_select_mtmpcrrhis(int sel_type, struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       struct MTMPCRRHIS_N_TAG MTMPCRRHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmpcrrhis(&MTMPCRRHIS_N, MTMPCRRHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         TABLE_UPDATE_SEQ,
                         CM_KEY_1,
                         CM_KEY_2,
                         CM_KEY_3,
                         CM_KEY_4,
                         CM_KEY_5,
                         CRR_ID,
                         HIST_SEQ,
                         TRAN_TIME,
                         SYS_TRAN_TIME,
                         TRAN_CODE,
                         FACTORY,
                         CRR_STATUS,
                         CRR_STATUS_FLAG,
                         USAGE_COUNT,
                         CLEAN_COUNT,
                         RES_ID,
                         SUBRES_ID,
                         PORT_ID,
                         LOCATION_1,
                         LOCATION_2,
                         LOCATION_3,
                         LOCATION_4,
                         LOCATION_5,
                         FINISH_CLEAN_FLAG,
                         LAST_CLEAN_TIME,
                         LOT_ID,
                         LOT_HIST_SEQ,
                         QTY_1,
                         QTY_2,
                         QTY_3,
                         TBL_SLOT,
                         MOVE_FLAG,
                         EMPTY_FLAG,
                         STOCK_IN_TIME,
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
                         TRAN_USER_ID,
                         TRAN_COMMENT,
                    PROCESS_FLAG,
                    CRR_CMF_1,
                    CRR_CMF_2,
                    CRR_CMF_3,
                    CRR_CMF_4,
                    CRR_CMF_5,
                    CRR_CMF_6,
                    CRR_CMF_7,
                    CRR_CMF_8,
                    CRR_CMF_9,
                    CRR_CMF_10,
                    CRR_CMF_11,
                    CRR_CMF_12,
                    CRR_CMF_13,
                    CRR_CMF_14,
                    CRR_CMF_15,
                    CRR_CMF_16,
                    CRR_CMF_17,
                    CRR_CMF_18,
                    CRR_CMF_19,
                    CRR_CMF_20,
                    REUSE_COUNT
                INTO 
                    :MTMPCRRHIS_N.TABLE_UPDATE_SEQ,
                    :MTMPCRRHIS_N.CM_KEY_1,
                    :MTMPCRRHIS_N.CM_KEY_2,
                    :MTMPCRRHIS_N.CM_KEY_3,
                    :MTMPCRRHIS_N.CM_KEY_4,
                    :MTMPCRRHIS_N.CM_KEY_5,
                    :MTMPCRRHIS_N.CRR_ID,
                    :MTMPCRRHIS_N.HIST_SEQ,
                    :MTMPCRRHIS_N.TRAN_TIME,
                    :MTMPCRRHIS_N.SYS_TRAN_TIME,
                    :MTMPCRRHIS_N.TRAN_CODE,
                    :MTMPCRRHIS_N.FACTORY,
                    :MTMPCRRHIS_N.CRR_STATUS,
                    :MTMPCRRHIS_N.CRR_STATUS_FLAG,
                    :MTMPCRRHIS_N.USAGE_COUNT,
                    :MTMPCRRHIS_N.CLEAN_COUNT,
                    :MTMPCRRHIS_N.RES_ID,
                    :MTMPCRRHIS_N.SUBRES_ID,
                    :MTMPCRRHIS_N.PORT_ID,
                    :MTMPCRRHIS_N.LOCATION_1,
                    :MTMPCRRHIS_N.LOCATION_2,
                    :MTMPCRRHIS_N.LOCATION_3,
                    :MTMPCRRHIS_N.LOCATION_4,
                    :MTMPCRRHIS_N.LOCATION_5,
                    :MTMPCRRHIS_N.FINISH_CLEAN_FLAG,
                    :MTMPCRRHIS_N.LAST_CLEAN_TIME,
                    :MTMPCRRHIS_N.LOT_ID,
                    :MTMPCRRHIS_N.LOT_HIST_SEQ,
                    :MTMPCRRHIS_N.QTY_1,
                    :MTMPCRRHIS_N.QTY_2,
                    :MTMPCRRHIS_N.QTY_3,
                    :MTMPCRRHIS_N.TBL_SLOT,
                    :MTMPCRRHIS_N.MOVE_FLAG,
                    :MTMPCRRHIS_N.EMPTY_FLAG,
                    :MTMPCRRHIS_N.STOCK_IN_TIME,
                    :MTMPCRRHIS_N.TRAN_CMF_1,
                    :MTMPCRRHIS_N.TRAN_CMF_2,
                    :MTMPCRRHIS_N.TRAN_CMF_3,
                    :MTMPCRRHIS_N.TRAN_CMF_4,
                    :MTMPCRRHIS_N.TRAN_CMF_5,
                    :MTMPCRRHIS_N.TRAN_CMF_6,
                    :MTMPCRRHIS_N.TRAN_CMF_7,
                    :MTMPCRRHIS_N.TRAN_CMF_8,
                    :MTMPCRRHIS_N.TRAN_CMF_9,
                    :MTMPCRRHIS_N.TRAN_CMF_10,
                    :MTMPCRRHIS_N.TRAN_CMF_11,
                    :MTMPCRRHIS_N.TRAN_CMF_12,
                    :MTMPCRRHIS_N.TRAN_CMF_13,
                    :MTMPCRRHIS_N.TRAN_CMF_14,
                    :MTMPCRRHIS_N.TRAN_CMF_15,
                    :MTMPCRRHIS_N.TRAN_CMF_16,
                    :MTMPCRRHIS_N.TRAN_CMF_17,
                    :MTMPCRRHIS_N.TRAN_CMF_18,
                    :MTMPCRRHIS_N.TRAN_CMF_19,
                    :MTMPCRRHIS_N.TRAN_CMF_20,
                    :MTMPCRRHIS_N.TRAN_USER_ID,
                    :MTMPCRRHIS_N.TRAN_COMMENT,
                    :MTMPCRRHIS_N.PROCESS_FLAG,
                    :MTMPCRRHIS_N.CRR_CMF_1,
                    :MTMPCRRHIS_N.CRR_CMF_2,
                    :MTMPCRRHIS_N.CRR_CMF_3,
                    :MTMPCRRHIS_N.CRR_CMF_4,
                    :MTMPCRRHIS_N.CRR_CMF_5,
                    :MTMPCRRHIS_N.CRR_CMF_6,
                    :MTMPCRRHIS_N.CRR_CMF_7,
                    :MTMPCRRHIS_N.CRR_CMF_8,
                    :MTMPCRRHIS_N.CRR_CMF_9,
                    :MTMPCRRHIS_N.CRR_CMF_10,
                    :MTMPCRRHIS_N.CRR_CMF_11,
                    :MTMPCRRHIS_N.CRR_CMF_12,
                    :MTMPCRRHIS_N.CRR_CMF_13,
                    :MTMPCRRHIS_N.CRR_CMF_14,
                    :MTMPCRRHIS_N.CRR_CMF_15,
                    :MTMPCRRHIS_N.CRR_CMF_16,
                    :MTMPCRRHIS_N.CRR_CMF_17,
                    :MTMPCRRHIS_N.CRR_CMF_18,
                    :MTMPCRRHIS_N.CRR_CMF_19,
                    :MTMPCRRHIS_N.CRR_CMF_20,
                    :MTMPCRRHIS_N.REUSE_COUNT
                FROM MTMPCRRHIS
                WHERE TABLE_UPDATE_SEQ = :MTMPCRRHIS_N.TABLE_UPDATE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 80;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select TABLE_UPDATE_SEQ ,CM_KEY_1 ,CM_KEY_2 ,CM_KEY_3 ,CM_KEY\
_4 ,CM_KEY_5 ,CRR_ID ,HIST_SEQ ,TRAN_TIME ,SYS_TRAN_TIME ,TRAN_CODE ,FACTORY\
 ,CRR_STATUS ,CRR_STATUS_FLAG ,USAGE_COUNT ,CLEAN_COUNT ,RES_ID ,SUBRES_ID ,\
PORT_ID ,LOCATION_1 ,LOCATION_2 ,LOCATION_3 ,LOCATION_4 ,LOCATION_5 ,FINISH_\
CLEAN_FLAG ,LAST_CLEAN_TIME ,LOT_ID ,LOT_HIST_SEQ ,QTY_1 ,QTY_2 ,QTY_3 ,TBL_\
SLOT ,MOVE_FLAG ,EMPTY_FLAG ,STOCK_IN_TIME ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF\
_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,\
TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15\
 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,TRAN_USER\
_ID ,TRAN_COMMENT ,PROCESS_FLAG ,CRR_CMF_1 ,CRR_CMF_2 ,CRR_CMF_3 ,CRR_CMF_4 \
,CRR_CMF_5 ,CRR_CMF_6 ,CRR_CMF_7 ,CRR_CMF_8 ,CRR_CMF_9 ,CRR_CMF_10 ,CRR_CMF_\
11 ,CRR_CMF_12 ,CRR_CMF_13 ,CRR_CMF_14 ,CRR_CMF_15 ,CRR_CMF_16 ,CRR_CMF_17 ,\
CRR_CMF_18 ,CRR_CMF_19 ,CRR_CMF_20 ,REUSE_COUNT into :b0,:b1,:b2,:b3,:b4,:b5\
,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16");
            sqlstm.stmt = ",:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b\
26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41\
,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:\
b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b7\
2,:b73,:b74,:b75,:b76,:b77,:b78  from MTMPCRRHIS where TABLE_UPDATE_SEQ=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(MTMPCRRHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MTMPCRRHIS_N.CM_KEY_1);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MTMPCRRHIS_N.CM_KEY_2);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MTMPCRRHIS_N.CM_KEY_3);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MTMPCRRHIS_N.CM_KEY_4);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MTMPCRRHIS_N.CM_KEY_5);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MTMPCRRHIS_N.CRR_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MTMPCRRHIS_N.HIST_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MTMPCRRHIS_N.TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MTMPCRRHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MTMPCRRHIS_N.TRAN_CODE);
            sqlstm.sqhstl[10] = (unsigned int  )13;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MTMPCRRHIS_N.FACTORY);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MTMPCRRHIS_N.CRR_STATUS);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MTMPCRRHIS_N.CRR_STATUS_FLAG);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MTMPCRRHIS_N.USAGE_COUNT);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MTMPCRRHIS_N.CLEAN_COUNT);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MTMPCRRHIS_N.RES_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MTMPCRRHIS_N.SUBRES_ID);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MTMPCRRHIS_N.PORT_ID);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MTMPCRRHIS_N.LOCATION_1);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MTMPCRRHIS_N.LOCATION_2);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MTMPCRRHIS_N.LOCATION_3);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MTMPCRRHIS_N.LOCATION_4);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MTMPCRRHIS_N.LOCATION_5);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MTMPCRRHIS_N.FINISH_CLEAN_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MTMPCRRHIS_N.LAST_CLEAN_TIME);
            sqlstm.sqhstl[25] = (unsigned int  )15;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MTMPCRRHIS_N.LOT_ID);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MTMPCRRHIS_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MTMPCRRHIS_N.QTY_1);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MTMPCRRHIS_N.QTY_2);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(MTMPCRRHIS_N.QTY_3);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MTMPCRRHIS_N.TBL_SLOT);
            sqlstm.sqhstl[31] = (unsigned int  )101;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MTMPCRRHIS_N.MOVE_FLAG);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MTMPCRRHIS_N.EMPTY_FLAG);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MTMPCRRHIS_N.STOCK_IN_TIME);
            sqlstm.sqhstl[34] = (unsigned int  )15;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MTMPCRRHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[55] = (unsigned int  )21;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MTMPCRRHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[56] = (unsigned int  )401;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MTMPCRRHIS_N.PROCESS_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_11);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_12);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_13);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_14);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_15);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_16);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_17);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_18);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_19);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_20);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MTMPCRRHIS_N.REUSE_COUNT);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)&(MTMPCRRHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[79] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
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
        DBC_del_null_mtmpcrrhis(&MTMPCRRHIS_N, MTMPCRRHIS);
    }
    DB_stop_query_timer("DBC_select_mtmpcrrhis", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mtmpcrrhis_for_update(int sel_type, struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       struct MTMPCRRHIS_N_TAG MTMPCRRHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmpcrrhis(&MTMPCRRHIS_N, MTMPCRRHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         TABLE_UPDATE_SEQ,
                         CM_KEY_1,
                         CM_KEY_2,
                         CM_KEY_3,
                         CM_KEY_4,
                         CM_KEY_5,
                         CRR_ID,
                         HIST_SEQ,
                         TRAN_TIME,
                         SYS_TRAN_TIME,
                         TRAN_CODE,
                         FACTORY,
                         CRR_STATUS,
                         CRR_STATUS_FLAG,
                         USAGE_COUNT,
                         CLEAN_COUNT,
                         RES_ID,
                         SUBRES_ID,
                         PORT_ID,
                         LOCATION_1,
                         LOCATION_2,
                         LOCATION_3,
                         LOCATION_4,
                         LOCATION_5,
                         FINISH_CLEAN_FLAG,
                         LAST_CLEAN_TIME,
                         LOT_ID,
                         LOT_HIST_SEQ,
                         QTY_1,
                         QTY_2,
                         QTY_3,
                         TBL_SLOT,
                         MOVE_FLAG,
                         EMPTY_FLAG,
                         STOCK_IN_TIME,
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
                         TRAN_USER_ID,
                         TRAN_COMMENT,
                    PROCESS_FLAG,
                    CRR_CMF_1,
                    CRR_CMF_2,
                    CRR_CMF_3,
                    CRR_CMF_4,
                    CRR_CMF_5,
                    CRR_CMF_6,
                    CRR_CMF_7,
                    CRR_CMF_8,
                    CRR_CMF_9,
                    CRR_CMF_10,
                    CRR_CMF_11,
                    CRR_CMF_12,
                    CRR_CMF_13,
                    CRR_CMF_14,
                    CRR_CMF_15,
                    CRR_CMF_16,
                    CRR_CMF_17,
                    CRR_CMF_18,
                    CRR_CMF_19,
                    CRR_CMF_20,
                    REUSE_COUNT
                INTO 
                    :MTMPCRRHIS_N.TABLE_UPDATE_SEQ,
                    :MTMPCRRHIS_N.CM_KEY_1,
                    :MTMPCRRHIS_N.CM_KEY_2,
                    :MTMPCRRHIS_N.CM_KEY_3,
                    :MTMPCRRHIS_N.CM_KEY_4,
                    :MTMPCRRHIS_N.CM_KEY_5,
                    :MTMPCRRHIS_N.CRR_ID,
                    :MTMPCRRHIS_N.HIST_SEQ,
                    :MTMPCRRHIS_N.TRAN_TIME,
                    :MTMPCRRHIS_N.SYS_TRAN_TIME,
                    :MTMPCRRHIS_N.TRAN_CODE,
                    :MTMPCRRHIS_N.FACTORY,
                    :MTMPCRRHIS_N.CRR_STATUS,
                    :MTMPCRRHIS_N.CRR_STATUS_FLAG,
                    :MTMPCRRHIS_N.USAGE_COUNT,
                    :MTMPCRRHIS_N.CLEAN_COUNT,
                    :MTMPCRRHIS_N.RES_ID,
                    :MTMPCRRHIS_N.SUBRES_ID,
                    :MTMPCRRHIS_N.PORT_ID,
                    :MTMPCRRHIS_N.LOCATION_1,
                    :MTMPCRRHIS_N.LOCATION_2,
                    :MTMPCRRHIS_N.LOCATION_3,
                    :MTMPCRRHIS_N.LOCATION_4,
                    :MTMPCRRHIS_N.LOCATION_5,
                    :MTMPCRRHIS_N.FINISH_CLEAN_FLAG,
                    :MTMPCRRHIS_N.LAST_CLEAN_TIME,
                    :MTMPCRRHIS_N.LOT_ID,
                    :MTMPCRRHIS_N.LOT_HIST_SEQ,
                    :MTMPCRRHIS_N.QTY_1,
                    :MTMPCRRHIS_N.QTY_2,
                    :MTMPCRRHIS_N.QTY_3,
                    :MTMPCRRHIS_N.TBL_SLOT,
                    :MTMPCRRHIS_N.MOVE_FLAG,
                    :MTMPCRRHIS_N.EMPTY_FLAG,
                    :MTMPCRRHIS_N.STOCK_IN_TIME,
                    :MTMPCRRHIS_N.TRAN_CMF_1,
                    :MTMPCRRHIS_N.TRAN_CMF_2,
                    :MTMPCRRHIS_N.TRAN_CMF_3,
                    :MTMPCRRHIS_N.TRAN_CMF_4,
                    :MTMPCRRHIS_N.TRAN_CMF_5,
                    :MTMPCRRHIS_N.TRAN_CMF_6,
                    :MTMPCRRHIS_N.TRAN_CMF_7,
                    :MTMPCRRHIS_N.TRAN_CMF_8,
                    :MTMPCRRHIS_N.TRAN_CMF_9,
                    :MTMPCRRHIS_N.TRAN_CMF_10,
                    :MTMPCRRHIS_N.TRAN_CMF_11,
                    :MTMPCRRHIS_N.TRAN_CMF_12,
                    :MTMPCRRHIS_N.TRAN_CMF_13,
                    :MTMPCRRHIS_N.TRAN_CMF_14,
                    :MTMPCRRHIS_N.TRAN_CMF_15,
                    :MTMPCRRHIS_N.TRAN_CMF_16,
                    :MTMPCRRHIS_N.TRAN_CMF_17,
                    :MTMPCRRHIS_N.TRAN_CMF_18,
                    :MTMPCRRHIS_N.TRAN_CMF_19,
                    :MTMPCRRHIS_N.TRAN_CMF_20,
                    :MTMPCRRHIS_N.TRAN_USER_ID,
                    :MTMPCRRHIS_N.TRAN_COMMENT,
                    :MTMPCRRHIS_N.PROCESS_FLAG,
                    :MTMPCRRHIS_N.CRR_CMF_1,
                    :MTMPCRRHIS_N.CRR_CMF_2,
                    :MTMPCRRHIS_N.CRR_CMF_3,
                    :MTMPCRRHIS_N.CRR_CMF_4,
                    :MTMPCRRHIS_N.CRR_CMF_5,
                    :MTMPCRRHIS_N.CRR_CMF_6,
                    :MTMPCRRHIS_N.CRR_CMF_7,
                    :MTMPCRRHIS_N.CRR_CMF_8,
                    :MTMPCRRHIS_N.CRR_CMF_9,
                    :MTMPCRRHIS_N.CRR_CMF_10,
                    :MTMPCRRHIS_N.CRR_CMF_11,
                    :MTMPCRRHIS_N.CRR_CMF_12,
                    :MTMPCRRHIS_N.CRR_CMF_13,
                    :MTMPCRRHIS_N.CRR_CMF_14,
                    :MTMPCRRHIS_N.CRR_CMF_15,
                    :MTMPCRRHIS_N.CRR_CMF_16,
                    :MTMPCRRHIS_N.CRR_CMF_17,
                    :MTMPCRRHIS_N.CRR_CMF_18,
                    :MTMPCRRHIS_N.CRR_CMF_19,
                    :MTMPCRRHIS_N.CRR_CMF_20,
                    :MTMPCRRHIS_N.REUSE_COUNT
                FROM MTMPCRRHIS
                WHERE TABLE_UPDATE_SEQ = :MTMPCRRHIS_N.TABLE_UPDATE_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 80;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select TABLE_UPDATE_SEQ ,CM_KEY_1 ,CM_KEY_2 ,CM_KEY_3 ,CM_KEY\
_4 ,CM_KEY_5 ,CRR_ID ,HIST_SEQ ,TRAN_TIME ,SYS_TRAN_TIME ,TRAN_CODE ,FACTORY\
 ,CRR_STATUS ,CRR_STATUS_FLAG ,USAGE_COUNT ,CLEAN_COUNT ,RES_ID ,SUBRES_ID ,\
PORT_ID ,LOCATION_1 ,LOCATION_2 ,LOCATION_3 ,LOCATION_4 ,LOCATION_5 ,FINISH_\
CLEAN_FLAG ,LAST_CLEAN_TIME ,LOT_ID ,LOT_HIST_SEQ ,QTY_1 ,QTY_2 ,QTY_3 ,TBL_\
SLOT ,MOVE_FLAG ,EMPTY_FLAG ,STOCK_IN_TIME ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF\
_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,\
TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15\
 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,TRAN_USER\
_ID ,TRAN_COMMENT ,PROCESS_FLAG ,CRR_CMF_1 ,CRR_CMF_2 ,CRR_CMF_3 ,CRR_CMF_4 \
,CRR_CMF_5 ,CRR_CMF_6 ,CRR_CMF_7 ,CRR_CMF_8 ,CRR_CMF_9 ,CRR_CMF_10 ,CRR_CMF_\
11 ,CRR_CMF_12 ,CRR_CMF_13 ,CRR_CMF_14 ,CRR_CMF_15 ,CRR_CMF_16 ,CRR_CMF_17 ,\
CRR_CMF_18 ,CRR_CMF_19 ,CRR_CMF_20 ,REUSE_COUNT into :b0,:b1,:b2,:b3,:b4,:b5\
,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16");
            sqlstm.stmt = ",:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b\
26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41\
,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:\
b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b7\
2,:b73,:b74,:b75,:b76,:b77,:b78  from MTMPCRRHIS where TABLE_UPDATE_SEQ=:b0 f\
or update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )340;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(MTMPCRRHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MTMPCRRHIS_N.CM_KEY_1);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MTMPCRRHIS_N.CM_KEY_2);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MTMPCRRHIS_N.CM_KEY_3);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MTMPCRRHIS_N.CM_KEY_4);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MTMPCRRHIS_N.CM_KEY_5);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MTMPCRRHIS_N.CRR_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MTMPCRRHIS_N.HIST_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MTMPCRRHIS_N.TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MTMPCRRHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MTMPCRRHIS_N.TRAN_CODE);
            sqlstm.sqhstl[10] = (unsigned int  )13;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MTMPCRRHIS_N.FACTORY);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MTMPCRRHIS_N.CRR_STATUS);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MTMPCRRHIS_N.CRR_STATUS_FLAG);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MTMPCRRHIS_N.USAGE_COUNT);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MTMPCRRHIS_N.CLEAN_COUNT);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MTMPCRRHIS_N.RES_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MTMPCRRHIS_N.SUBRES_ID);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MTMPCRRHIS_N.PORT_ID);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MTMPCRRHIS_N.LOCATION_1);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MTMPCRRHIS_N.LOCATION_2);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MTMPCRRHIS_N.LOCATION_3);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MTMPCRRHIS_N.LOCATION_4);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MTMPCRRHIS_N.LOCATION_5);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MTMPCRRHIS_N.FINISH_CLEAN_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MTMPCRRHIS_N.LAST_CLEAN_TIME);
            sqlstm.sqhstl[25] = (unsigned int  )15;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MTMPCRRHIS_N.LOT_ID);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MTMPCRRHIS_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MTMPCRRHIS_N.QTY_1);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MTMPCRRHIS_N.QTY_2);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(MTMPCRRHIS_N.QTY_3);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MTMPCRRHIS_N.TBL_SLOT);
            sqlstm.sqhstl[31] = (unsigned int  )101;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MTMPCRRHIS_N.MOVE_FLAG);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MTMPCRRHIS_N.EMPTY_FLAG);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MTMPCRRHIS_N.STOCK_IN_TIME);
            sqlstm.sqhstl[34] = (unsigned int  )15;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MTMPCRRHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[55] = (unsigned int  )21;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MTMPCRRHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[56] = (unsigned int  )401;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MTMPCRRHIS_N.PROCESS_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_11);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_12);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_13);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_14);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_15);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_16);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_17);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_18);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_19);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_20);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MTMPCRRHIS_N.REUSE_COUNT);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)&(MTMPCRRHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[79] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
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
        DBC_del_null_mtmpcrrhis(&MTMPCRRHIS_N, MTMPCRRHIS);
    }
    DB_stop_query_timer("DBC_select_mtmpcrrhis_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mtmpcrrhis_scalar(int sel_type, struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       struct MTMPCRRHIS_N_TAG MTMPCRRHIS_N;
       double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
   

    DBC_add_null_mtmpcrrhis(&MTMPCRRHIS_N, MTMPCRRHIS);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MTMPCRRHIS
                WHERE TABLE_UPDATE_SEQ = :MTMPCRRHIS_N.TABLE_UPDATE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 80;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MTMPCRRHIS where\
 TABLE_UPDATE_SEQ=:b1";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )675;
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
            sqlstm.sqhstv[1] = (         void  *)&(MTMPCRRHIS_N.TABLE_UPDATE_SEQ);
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
        case 2:
            /* EXEC SQL SELECT MTMPCRRHIS_SEQ.NEXTVAL  
                INTO :d_value
                FROM DUAL; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 80;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select MTMPCRRHIS_SEQ.nextval  into :b0  from DU\
AL ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )698;
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

    DB_stop_query_timer("DBC_select_mtmpcrrhis_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mtmpcrrhis(int sel_type, struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       struct MTMPCRRHIS_N_TAG MTMPCRRHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmpcrrhis(&MTMPCRRHIS_N, MTMPCRRHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MTMPCRRHIS
                WHERE TABLE_UPDATE_SEQ = :MTMPCRRHIS_N.TABLE_UPDATE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 80;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MTMPCRRHIS  where TABLE_UPDATE_SEQ=\
:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )717;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(MTMPCRRHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
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
    DB_stop_query_timer("DBC_delete_mtmpcrrhis", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mtmpcrrhis(struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       struct MTMPCRRHIS_N_TAG MTMPCRRHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmpcrrhis(&MTMPCRRHIS_N, MTMPCRRHIS);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MTMPCRRHIS (
                    TABLE_UPDATE_SEQ,
                    CM_KEY_1,
                    CM_KEY_2,
                    CM_KEY_3,
                    CM_KEY_4,
                    CM_KEY_5,
                    CRR_ID,
                    HIST_SEQ,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TRAN_CODE,
                    FACTORY,
                    CRR_STATUS,
                    CRR_STATUS_FLAG,
                    USAGE_COUNT,
                    CLEAN_COUNT,
                    RES_ID,
                    SUBRES_ID,
                    PORT_ID,
                    LOCATION_1,
                    LOCATION_2,
                    LOCATION_3,
                    LOCATION_4,
                    LOCATION_5,
                    FINISH_CLEAN_FLAG,
                    LAST_CLEAN_TIME,
                    LOT_ID,
                    LOT_HIST_SEQ,
                    QTY_1,
                    QTY_2,
                    QTY_3,
                    TBL_SLOT,
                    MOVE_FLAG,
                    EMPTY_FLAG,
                    STOCK_IN_TIME,
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
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    PROCESS_FLAG, 
                    CRR_CMF_1, 
                    CRR_CMF_2, 
                    CRR_CMF_3, 
                    CRR_CMF_4, 
                    CRR_CMF_5, 
                    CRR_CMF_6, 
                    CRR_CMF_7, 
                    CRR_CMF_8, 
                    CRR_CMF_9, 
                    CRR_CMF_10, 
                    CRR_CMF_11, 
                    CRR_CMF_12, 
                    CRR_CMF_13, 
                    CRR_CMF_14, 
                    CRR_CMF_15, 
                    CRR_CMF_16, 
                    CRR_CMF_17, 
                    CRR_CMF_18, 
                    CRR_CMF_19, 
                    CRR_CMF_20, 
                    REUSE_COUNT
        )
        VALUES (
                    :MTMPCRRHIS_N.TABLE_UPDATE_SEQ,
                    :MTMPCRRHIS_N.CM_KEY_1,
                    :MTMPCRRHIS_N.CM_KEY_2,
                    :MTMPCRRHIS_N.CM_KEY_3,
                    :MTMPCRRHIS_N.CM_KEY_4,
                    :MTMPCRRHIS_N.CM_KEY_5,
                    :MTMPCRRHIS_N.CRR_ID,
                    :MTMPCRRHIS_N.HIST_SEQ,
                    :MTMPCRRHIS_N.TRAN_TIME,
                    :MTMPCRRHIS_N.SYS_TRAN_TIME,
                    :MTMPCRRHIS_N.TRAN_CODE,
                    :MTMPCRRHIS_N.FACTORY,
                    :MTMPCRRHIS_N.CRR_STATUS,
                    :MTMPCRRHIS_N.CRR_STATUS_FLAG,
                    :MTMPCRRHIS_N.USAGE_COUNT,
                    :MTMPCRRHIS_N.CLEAN_COUNT,
                    :MTMPCRRHIS_N.RES_ID,
                    :MTMPCRRHIS_N.SUBRES_ID,
                    :MTMPCRRHIS_N.PORT_ID,
                    :MTMPCRRHIS_N.LOCATION_1,
                    :MTMPCRRHIS_N.LOCATION_2,
                    :MTMPCRRHIS_N.LOCATION_3,
                    :MTMPCRRHIS_N.LOCATION_4,
                    :MTMPCRRHIS_N.LOCATION_5,
                    :MTMPCRRHIS_N.FINISH_CLEAN_FLAG,
                    :MTMPCRRHIS_N.LAST_CLEAN_TIME,
                    :MTMPCRRHIS_N.LOT_ID,
                    :MTMPCRRHIS_N.LOT_HIST_SEQ,
                    :MTMPCRRHIS_N.QTY_1,
                    :MTMPCRRHIS_N.QTY_2,
                    :MTMPCRRHIS_N.QTY_3,
                    :MTMPCRRHIS_N.TBL_SLOT,
                    :MTMPCRRHIS_N.MOVE_FLAG,
                    :MTMPCRRHIS_N.EMPTY_FLAG,
                    :MTMPCRRHIS_N.STOCK_IN_TIME,
                    :MTMPCRRHIS_N.TRAN_CMF_1,
                    :MTMPCRRHIS_N.TRAN_CMF_2,
                    :MTMPCRRHIS_N.TRAN_CMF_3,
                    :MTMPCRRHIS_N.TRAN_CMF_4,
                    :MTMPCRRHIS_N.TRAN_CMF_5,
                    :MTMPCRRHIS_N.TRAN_CMF_6,
                    :MTMPCRRHIS_N.TRAN_CMF_7,
                    :MTMPCRRHIS_N.TRAN_CMF_8,
                    :MTMPCRRHIS_N.TRAN_CMF_9,
                    :MTMPCRRHIS_N.TRAN_CMF_10,
                    :MTMPCRRHIS_N.TRAN_CMF_11,
                    :MTMPCRRHIS_N.TRAN_CMF_12,
                    :MTMPCRRHIS_N.TRAN_CMF_13,
                    :MTMPCRRHIS_N.TRAN_CMF_14,
                    :MTMPCRRHIS_N.TRAN_CMF_15,
                    :MTMPCRRHIS_N.TRAN_CMF_16,
                    :MTMPCRRHIS_N.TRAN_CMF_17,
                    :MTMPCRRHIS_N.TRAN_CMF_18,
                    :MTMPCRRHIS_N.TRAN_CMF_19,
                    :MTMPCRRHIS_N.TRAN_CMF_20,
                    :MTMPCRRHIS_N.TRAN_USER_ID,
                    :MTMPCRRHIS_N.TRAN_COMMENT,
                    :MTMPCRRHIS_N.PROCESS_FLAG,
                    :MTMPCRRHIS_N.CRR_CMF_1,
                    :MTMPCRRHIS_N.CRR_CMF_2,
                    :MTMPCRRHIS_N.CRR_CMF_3,
                    :MTMPCRRHIS_N.CRR_CMF_4,
                    :MTMPCRRHIS_N.CRR_CMF_5,
                    :MTMPCRRHIS_N.CRR_CMF_6,
                    :MTMPCRRHIS_N.CRR_CMF_7,
                    :MTMPCRRHIS_N.CRR_CMF_8,
                    :MTMPCRRHIS_N.CRR_CMF_9,
                    :MTMPCRRHIS_N.CRR_CMF_10,
                    :MTMPCRRHIS_N.CRR_CMF_11,
                    :MTMPCRRHIS_N.CRR_CMF_12,
                    :MTMPCRRHIS_N.CRR_CMF_13,
                    :MTMPCRRHIS_N.CRR_CMF_14,
                    :MTMPCRRHIS_N.CRR_CMF_15,
                    :MTMPCRRHIS_N.CRR_CMF_16,
                    :MTMPCRRHIS_N.CRR_CMF_17,
                    :MTMPCRRHIS_N.CRR_CMF_18,
                    :MTMPCRRHIS_N.CRR_CMF_19,
                    :MTMPCRRHIS_N.CRR_CMF_20,
                    :MTMPCRRHIS_N.REUSE_COUNT
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 80;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MTMPCRRHIS (TABLE_UPDATE_SEQ,CM_KEY_1,CM_KEY_2,CM_KEY_3,C\
M_KEY_4,CM_KEY_5,CRR_ID,HIST_SEQ,TRAN_TIME,SYS_TRAN_TIME,TRAN_CODE,FACTORY,C\
RR_STATUS,CRR_STATUS_FLAG,USAGE_COUNT,CLEAN_COUNT,RES_ID,SUBRES_ID,PORT_ID,L\
OCATION_1,LOCATION_2,LOCATION_3,LOCATION_4,LOCATION_5,FINISH_CLEAN_FLAG,LAST\
_CLEAN_TIME,LOT_ID,LOT_HIST_SEQ,QTY_1,QTY_2,QTY_3,TBL_SLOT,MOVE_FLAG,EMPTY_F\
LAG,STOCK_IN_TIME,TRAN_CMF_1,TRAN_CMF_2,TRAN_CMF_3,TRAN_CMF_4,TRAN_CMF_5,TRA\
N_CMF_6,TRAN_CMF_7,TRAN_CMF_8,TRAN_CMF_9,TRAN_CMF_10,TRAN_CMF_11,TRAN_CMF_12\
,TRAN_CMF_13,TRAN_CMF_14,TRAN_CMF_15,TRAN_CMF_16,TRAN_CMF_17,TRAN_CMF_18,TRA\
N_CMF_19,TRAN_CMF_20,TRAN_USER_ID,TRAN_COMMENT,PROCESS_FLAG,CRR_CMF_1,CRR_CM\
F_2,CRR_CMF_3,CRR_CMF_4,CRR_CMF_5,CRR_CMF_6,CRR_CMF_7,CRR_CMF_8,CRR_CMF_9,CR\
R_CMF_10,CRR_CMF_11,CRR_CMF_12,CRR_CMF_13,CRR_CMF_14,CRR_CMF_15,CRR_CMF_16,C\
RR_CMF_17,CRR_CMF_18,CRR_CMF_19,CRR_CMF_20,REUSE_COUNT) values (:b0,:b1,:b2,\
:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b1\
9,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:");
    sqlstm.stmt = "b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b\
39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54\
,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:\
b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )736;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&(MTMPCRRHIS_N.TABLE_UPDATE_SEQ);
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MTMPCRRHIS_N.CM_KEY_1);
    sqlstm.sqhstl[1] = (unsigned int  )31;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MTMPCRRHIS_N.CM_KEY_2);
    sqlstm.sqhstl[2] = (unsigned int  )31;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MTMPCRRHIS_N.CM_KEY_3);
    sqlstm.sqhstl[3] = (unsigned int  )31;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MTMPCRRHIS_N.CM_KEY_4);
    sqlstm.sqhstl[4] = (unsigned int  )31;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MTMPCRRHIS_N.CM_KEY_5);
    sqlstm.sqhstl[5] = (unsigned int  )31;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MTMPCRRHIS_N.CRR_ID);
    sqlstm.sqhstl[6] = (unsigned int  )21;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)&(MTMPCRRHIS_N.HIST_SEQ);
    sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MTMPCRRHIS_N.TRAN_TIME);
    sqlstm.sqhstl[8] = (unsigned int  )15;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MTMPCRRHIS_N.SYS_TRAN_TIME);
    sqlstm.sqhstl[9] = (unsigned int  )15;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MTMPCRRHIS_N.TRAN_CODE);
    sqlstm.sqhstl[10] = (unsigned int  )13;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MTMPCRRHIS_N.FACTORY);
    sqlstm.sqhstl[11] = (unsigned int  )11;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MTMPCRRHIS_N.CRR_STATUS);
    sqlstm.sqhstl[12] = (unsigned int  )11;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MTMPCRRHIS_N.CRR_STATUS_FLAG);
    sqlstm.sqhstl[13] = (unsigned int  )2;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)&(MTMPCRRHIS_N.USAGE_COUNT);
    sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)&(MTMPCRRHIS_N.CLEAN_COUNT);
    sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MTMPCRRHIS_N.RES_ID);
    sqlstm.sqhstl[16] = (unsigned int  )21;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MTMPCRRHIS_N.SUBRES_ID);
    sqlstm.sqhstl[17] = (unsigned int  )21;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MTMPCRRHIS_N.PORT_ID);
    sqlstm.sqhstl[18] = (unsigned int  )11;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MTMPCRRHIS_N.LOCATION_1);
    sqlstm.sqhstl[19] = (unsigned int  )21;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MTMPCRRHIS_N.LOCATION_2);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MTMPCRRHIS_N.LOCATION_3);
    sqlstm.sqhstl[21] = (unsigned int  )21;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MTMPCRRHIS_N.LOCATION_4);
    sqlstm.sqhstl[22] = (unsigned int  )21;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MTMPCRRHIS_N.LOCATION_5);
    sqlstm.sqhstl[23] = (unsigned int  )21;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MTMPCRRHIS_N.FINISH_CLEAN_FLAG);
    sqlstm.sqhstl[24] = (unsigned int  )2;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MTMPCRRHIS_N.LAST_CLEAN_TIME);
    sqlstm.sqhstl[25] = (unsigned int  )15;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MTMPCRRHIS_N.LOT_ID);
    sqlstm.sqhstl[26] = (unsigned int  )26;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)&(MTMPCRRHIS_N.LOT_HIST_SEQ);
    sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)&(MTMPCRRHIS_N.QTY_1);
    sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)&(MTMPCRRHIS_N.QTY_2);
    sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)&(MTMPCRRHIS_N.QTY_3);
    sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MTMPCRRHIS_N.TBL_SLOT);
    sqlstm.sqhstl[31] = (unsigned int  )101;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MTMPCRRHIS_N.MOVE_FLAG);
    sqlstm.sqhstl[32] = (unsigned int  )2;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MTMPCRRHIS_N.EMPTY_FLAG);
    sqlstm.sqhstl[33] = (unsigned int  )2;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MTMPCRRHIS_N.STOCK_IN_TIME);
    sqlstm.sqhstl[34] = (unsigned int  )15;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_1);
    sqlstm.sqhstl[35] = (unsigned int  )31;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_2);
    sqlstm.sqhstl[36] = (unsigned int  )31;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_3);
    sqlstm.sqhstl[37] = (unsigned int  )31;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_4);
    sqlstm.sqhstl[38] = (unsigned int  )31;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_5);
    sqlstm.sqhstl[39] = (unsigned int  )31;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_6);
    sqlstm.sqhstl[40] = (unsigned int  )31;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_7);
    sqlstm.sqhstl[41] = (unsigned int  )31;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_8);
    sqlstm.sqhstl[42] = (unsigned int  )31;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_9);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_10);
    sqlstm.sqhstl[44] = (unsigned int  )31;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_11);
    sqlstm.sqhstl[45] = (unsigned int  )31;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_12);
    sqlstm.sqhstl[46] = (unsigned int  )31;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_13);
    sqlstm.sqhstl[47] = (unsigned int  )31;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_14);
    sqlstm.sqhstl[48] = (unsigned int  )31;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_15);
    sqlstm.sqhstl[49] = (unsigned int  )31;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_16);
    sqlstm.sqhstl[50] = (unsigned int  )31;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_17);
    sqlstm.sqhstl[51] = (unsigned int  )31;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_18);
    sqlstm.sqhstl[52] = (unsigned int  )31;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_19);
    sqlstm.sqhstl[53] = (unsigned int  )31;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_20);
    sqlstm.sqhstl[54] = (unsigned int  )31;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MTMPCRRHIS_N.TRAN_USER_ID);
    sqlstm.sqhstl[55] = (unsigned int  )21;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MTMPCRRHIS_N.TRAN_COMMENT);
    sqlstm.sqhstl[56] = (unsigned int  )401;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MTMPCRRHIS_N.PROCESS_FLAG);
    sqlstm.sqhstl[57] = (unsigned int  )2;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_1);
    sqlstm.sqhstl[58] = (unsigned int  )31;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_2);
    sqlstm.sqhstl[59] = (unsigned int  )31;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_3);
    sqlstm.sqhstl[60] = (unsigned int  )31;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_4);
    sqlstm.sqhstl[61] = (unsigned int  )31;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_5);
    sqlstm.sqhstl[62] = (unsigned int  )31;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_6);
    sqlstm.sqhstl[63] = (unsigned int  )31;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_7);
    sqlstm.sqhstl[64] = (unsigned int  )31;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_8);
    sqlstm.sqhstl[65] = (unsigned int  )31;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_9);
    sqlstm.sqhstl[66] = (unsigned int  )31;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_10);
    sqlstm.sqhstl[67] = (unsigned int  )31;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_11);
    sqlstm.sqhstl[68] = (unsigned int  )31;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_12);
    sqlstm.sqhstl[69] = (unsigned int  )31;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_13);
    sqlstm.sqhstl[70] = (unsigned int  )31;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_14);
    sqlstm.sqhstl[71] = (unsigned int  )31;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_15);
    sqlstm.sqhstl[72] = (unsigned int  )31;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_16);
    sqlstm.sqhstl[73] = (unsigned int  )31;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_17);
    sqlstm.sqhstl[74] = (unsigned int  )31;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_18);
    sqlstm.sqhstl[75] = (unsigned int  )31;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_19);
    sqlstm.sqhstl[76] = (unsigned int  )31;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_20);
    sqlstm.sqhstl[77] = (unsigned int  )31;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)&(MTMPCRRHIS_N.REUSE_COUNT);
    sqlstm.sqhstl[78] = (unsigned int  )sizeof(int);
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


    DB_stop_query_timer("DBC_insert_mtmpcrrhis", 0);
}


/* SQL UPDATE Function */
void DBC_update_mtmpcrrhis(int sel_type, struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       struct MTMPCRRHIS_N_TAG MTMPCRRHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmpcrrhis(&MTMPCRRHIS_N, MTMPCRRHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MTMPCRRHIS SET
                    CM_KEY_1 = :MTMPCRRHIS_N.CM_KEY_1,
                    CM_KEY_2 = :MTMPCRRHIS_N.CM_KEY_2,
                    CM_KEY_3 = :MTMPCRRHIS_N.CM_KEY_3,
                    CM_KEY_4 = :MTMPCRRHIS_N.CM_KEY_4,
                    CM_KEY_5 = :MTMPCRRHIS_N.CM_KEY_5,
                    CRR_ID = :MTMPCRRHIS_N.CRR_ID,
                    HIST_SEQ = :MTMPCRRHIS_N.HIST_SEQ,
                    TRAN_TIME = :MTMPCRRHIS_N.TRAN_TIME,
                    SYS_TRAN_TIME = :MTMPCRRHIS_N.SYS_TRAN_TIME,
                    TRAN_CODE = :MTMPCRRHIS_N.TRAN_CODE,
                    FACTORY = :MTMPCRRHIS_N.FACTORY,
                    CRR_STATUS = :MTMPCRRHIS_N.CRR_STATUS,
                    CRR_STATUS_FLAG = :MTMPCRRHIS_N.CRR_STATUS_FLAG,
                    USAGE_COUNT = :MTMPCRRHIS_N.USAGE_COUNT,
                    CLEAN_COUNT = :MTMPCRRHIS_N.CLEAN_COUNT,
                    RES_ID = :MTMPCRRHIS_N.RES_ID,
                    SUBRES_ID = :MTMPCRRHIS_N.SUBRES_ID,
                    PORT_ID = :MTMPCRRHIS_N.PORT_ID,
                    LOCATION_1 = :MTMPCRRHIS_N.LOCATION_1,
                    LOCATION_2 = :MTMPCRRHIS_N.LOCATION_2,
                    LOCATION_3 = :MTMPCRRHIS_N.LOCATION_3,
                    LOCATION_4 = :MTMPCRRHIS_N.LOCATION_4,
                    LOCATION_5 = :MTMPCRRHIS_N.LOCATION_5,
                    FINISH_CLEAN_FLAG = :MTMPCRRHIS_N.FINISH_CLEAN_FLAG,
                    LAST_CLEAN_TIME = :MTMPCRRHIS_N.LAST_CLEAN_TIME,
                    LOT_ID = :MTMPCRRHIS_N.LOT_ID,
                    LOT_HIST_SEQ = :MTMPCRRHIS_N.LOT_HIST_SEQ,
                    QTY_1 = :MTMPCRRHIS_N.QTY_1,
                    QTY_2 = :MTMPCRRHIS_N.QTY_2,
                    QTY_3 = :MTMPCRRHIS_N.QTY_3,
                    TBL_SLOT = :MTMPCRRHIS_N.TBL_SLOT,
                    MOVE_FLAG = :MTMPCRRHIS_N.MOVE_FLAG,
                    EMPTY_FLAG = :MTMPCRRHIS_N.EMPTY_FLAG,
                    STOCK_IN_TIME = :MTMPCRRHIS_N.STOCK_IN_TIME,
                    TRAN_CMF_1 = :MTMPCRRHIS_N.TRAN_CMF_1,
                    TRAN_CMF_2 = :MTMPCRRHIS_N.TRAN_CMF_2,
                    TRAN_CMF_3 = :MTMPCRRHIS_N.TRAN_CMF_3,
                    TRAN_CMF_4 = :MTMPCRRHIS_N.TRAN_CMF_4,
                    TRAN_CMF_5 = :MTMPCRRHIS_N.TRAN_CMF_5,
                    TRAN_CMF_6 = :MTMPCRRHIS_N.TRAN_CMF_6,
                    TRAN_CMF_7 = :MTMPCRRHIS_N.TRAN_CMF_7,
                    TRAN_CMF_8 = :MTMPCRRHIS_N.TRAN_CMF_8,
                    TRAN_CMF_9 = :MTMPCRRHIS_N.TRAN_CMF_9,
                    TRAN_CMF_10 = :MTMPCRRHIS_N.TRAN_CMF_10,
                    TRAN_CMF_11 = :MTMPCRRHIS_N.TRAN_CMF_11,
                    TRAN_CMF_12 = :MTMPCRRHIS_N.TRAN_CMF_12,
                    TRAN_CMF_13 = :MTMPCRRHIS_N.TRAN_CMF_13,
                    TRAN_CMF_14 = :MTMPCRRHIS_N.TRAN_CMF_14,
                    TRAN_CMF_15 = :MTMPCRRHIS_N.TRAN_CMF_15,
                    TRAN_CMF_16 = :MTMPCRRHIS_N.TRAN_CMF_16,
                    TRAN_CMF_17 = :MTMPCRRHIS_N.TRAN_CMF_17,
                    TRAN_CMF_18 = :MTMPCRRHIS_N.TRAN_CMF_18,
                    TRAN_CMF_19 = :MTMPCRRHIS_N.TRAN_CMF_19,
                    TRAN_CMF_20 = :MTMPCRRHIS_N.TRAN_CMF_20,
                    TRAN_USER_ID = :MTMPCRRHIS_N.TRAN_USER_ID,
                    TRAN_COMMENT = :MTMPCRRHIS_N.TRAN_COMMENT,
                    PROCESS_FLAG = :MTMPCRRHIS_N.PROCESS_FLAG,
                    CRR_CMF_1 = :MTMPCRRHIS_N.CRR_CMF_1,
                    CRR_CMF_2 = :MTMPCRRHIS_N.CRR_CMF_2,
                    CRR_CMF_3 = :MTMPCRRHIS_N.CRR_CMF_3,
                    CRR_CMF_4 = :MTMPCRRHIS_N.CRR_CMF_4,
                    CRR_CMF_5 = :MTMPCRRHIS_N.CRR_CMF_5,
                    CRR_CMF_6 = :MTMPCRRHIS_N.CRR_CMF_6,
                    CRR_CMF_7 = :MTMPCRRHIS_N.CRR_CMF_7,
                    CRR_CMF_8 = :MTMPCRRHIS_N.CRR_CMF_8,
                    CRR_CMF_9 = :MTMPCRRHIS_N.CRR_CMF_9,
                    CRR_CMF_10 = :MTMPCRRHIS_N.CRR_CMF_10,
                    CRR_CMF_11 = :MTMPCRRHIS_N.CRR_CMF_11,
                    CRR_CMF_12 = :MTMPCRRHIS_N.CRR_CMF_12,
                    CRR_CMF_13 = :MTMPCRRHIS_N.CRR_CMF_13,
                    CRR_CMF_14 = :MTMPCRRHIS_N.CRR_CMF_14,
                    CRR_CMF_15 = :MTMPCRRHIS_N.CRR_CMF_15,
                    CRR_CMF_16 = :MTMPCRRHIS_N.CRR_CMF_16,
                    CRR_CMF_17 = :MTMPCRRHIS_N.CRR_CMF_17,
                    CRR_CMF_18 = :MTMPCRRHIS_N.CRR_CMF_18,
                    CRR_CMF_19 = :MTMPCRRHIS_N.CRR_CMF_19,
                    CRR_CMF_20 = :MTMPCRRHIS_N.CRR_CMF_20,
                    REUSE_COUNT = :MTMPCRRHIS_N.REUSE_COUNT
                WHERE TABLE_UPDATE_SEQ = :MTMPCRRHIS_N.TABLE_UPDATE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 80;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MTMPCRRHIS  set CM_KEY_1=:b0,CM_KEY_2=:b1,CM_KEY_3=:b2\
,CM_KEY_4=:b3,CM_KEY_5=:b4,CRR_ID=:b5,HIST_SEQ=:b6,TRAN_TIME=:b7,SYS_TRAN_TI\
ME=:b8,TRAN_CODE=:b9,FACTORY=:b10,CRR_STATUS=:b11,CRR_STATUS_FLAG=:b12,USAGE\
_COUNT=:b13,CLEAN_COUNT=:b14,RES_ID=:b15,SUBRES_ID=:b16,PORT_ID=:b17,LOCATIO\
N_1=:b18,LOCATION_2=:b19,LOCATION_3=:b20,LOCATION_4=:b21,LOCATION_5=:b22,FIN\
ISH_CLEAN_FLAG=:b23,LAST_CLEAN_TIME=:b24,LOT_ID=:b25,LOT_HIST_SEQ=:b26,QTY_1\
=:b27,QTY_2=:b28,QTY_3=:b29,TBL_SLOT=:b30,MOVE_FLAG=:b31,EMPTY_FLAG=:b32,STO\
CK_IN_TIME=:b33,TRAN_CMF_1=:b34,TRAN_CMF_2=:b35,TRAN_CMF_3=:b36,TRAN_CMF_4=:\
b37,TRAN_CMF_5=:b38,TRAN_CMF_6=:b39,TRAN_CMF_7=:b40,TRAN_CMF_8=:b41,TRAN_CMF\
_9=:b42,TRAN_CMF_10=:b43,TRAN_CMF_11=:b44,TRAN_CMF_12=:b45,TRAN_CMF_13=:b46,\
TRAN_CMF_14=:b47,TRAN_CMF_15=:b48,TRAN_CMF_16=:b49,TRAN_CMF_17=:b50,TRAN_CMF\
_18=:b51,TRAN_CMF_19=:b52,TRAN_CMF_20=:b53,TRAN_USER_ID=:b54,TRAN_COMMENT=:b\
55,PROCESS_FLAG=:b56,CRR_CMF_1=:b57,CRR_CMF_2=:b58,CRR_CMF_3=:b59,CRR_CMF_4=\
:b60,CRR_CMF_5=:b61,CRR_CMF_6=:b62,CRR_CMF_7=:b63,C");
            sqlstm.stmt = "RR_CMF_8=:b64,CRR_CMF_9=:b65,CRR_CMF_10=:b66,CRR\
_CMF_11=:b67,CRR_CMF_12=:b68,CRR_CMF_13=:b69,CRR_CMF_14=:b70,CRR_CMF_15=:b71,\
CRR_CMF_16=:b72,CRR_CMF_17=:b73,CRR_CMF_18=:b74,CRR_CMF_19=:b75,CRR_CMF_20=:b\
76,REUSE_COUNT=:b77 where TABLE_UPDATE_SEQ=:b78";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1067;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MTMPCRRHIS_N.CM_KEY_1);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MTMPCRRHIS_N.CM_KEY_2);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MTMPCRRHIS_N.CM_KEY_3);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MTMPCRRHIS_N.CM_KEY_4);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MTMPCRRHIS_N.CM_KEY_5);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MTMPCRRHIS_N.CRR_ID);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MTMPCRRHIS_N.HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MTMPCRRHIS_N.TRAN_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MTMPCRRHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MTMPCRRHIS_N.TRAN_CODE);
            sqlstm.sqhstl[9] = (unsigned int  )13;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MTMPCRRHIS_N.FACTORY);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MTMPCRRHIS_N.CRR_STATUS);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MTMPCRRHIS_N.CRR_STATUS_FLAG);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MTMPCRRHIS_N.USAGE_COUNT);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MTMPCRRHIS_N.CLEAN_COUNT);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MTMPCRRHIS_N.RES_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MTMPCRRHIS_N.SUBRES_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MTMPCRRHIS_N.PORT_ID);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MTMPCRRHIS_N.LOCATION_1);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MTMPCRRHIS_N.LOCATION_2);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MTMPCRRHIS_N.LOCATION_3);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MTMPCRRHIS_N.LOCATION_4);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MTMPCRRHIS_N.LOCATION_5);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MTMPCRRHIS_N.FINISH_CLEAN_FLAG);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MTMPCRRHIS_N.LAST_CLEAN_TIME);
            sqlstm.sqhstl[24] = (unsigned int  )15;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MTMPCRRHIS_N.LOT_ID);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MTMPCRRHIS_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MTMPCRRHIS_N.QTY_1);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MTMPCRRHIS_N.QTY_2);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MTMPCRRHIS_N.QTY_3);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MTMPCRRHIS_N.TBL_SLOT);
            sqlstm.sqhstl[30] = (unsigned int  )101;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MTMPCRRHIS_N.MOVE_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MTMPCRRHIS_N.EMPTY_FLAG);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MTMPCRRHIS_N.STOCK_IN_TIME);
            sqlstm.sqhstl[33] = (unsigned int  )15;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MTMPCRRHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MTMPCRRHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[55] = (unsigned int  )401;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MTMPCRRHIS_N.PROCESS_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_1);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_2);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_3);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_4);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_5);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_6);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_7);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_8);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_9);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_10);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_11);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_12);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_13);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_14);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_15);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_16);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_17);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_18);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_19);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_20);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)&(MTMPCRRHIS_N.REUSE_COUNT);
            sqlstm.sqhstl[77] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MTMPCRRHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(int);
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
    DB_stop_query_timer("DBC_update_mtmpcrrhis", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mtmpcrrhis(int sel_type, struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       struct MTMPCRRHIS_N_TAG MTMPCRRHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmpcrrhis(&MTMPCRRHIS_N, MTMPCRRHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MTMPCRRHIS_CUR_1 CURSOR FOR
                SELECT 
                    TABLE_UPDATE_SEQ,
                    CM_KEY_1,
                    CM_KEY_2,
                    CM_KEY_3,
                    CM_KEY_4,
                    CM_KEY_5,
                    CRR_ID,
                    HIST_SEQ,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TRAN_CODE,
                    FACTORY,
                    CRR_STATUS,
                    CRR_STATUS_FLAG,
                    USAGE_COUNT,
                    CLEAN_COUNT,
                    RES_ID,
                    SUBRES_ID,
                    PORT_ID,
                    LOCATION_1,
                    LOCATION_2,
                    LOCATION_3,
                    LOCATION_4,
                    LOCATION_5,
                    FINISH_CLEAN_FLAG,
                    LAST_CLEAN_TIME,
                    LOT_ID,
                    LOT_HIST_SEQ,
                    QTY_1,
                    QTY_2,
                    QTY_3,
                    TBL_SLOT,
                    MOVE_FLAG,
                    EMPTY_FLAG,
                    STOCK_IN_TIME,
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
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    PROCESS_FLAG,
                    CRR_CMF_1,
                    CRR_CMF_2,
                    CRR_CMF_3,
                    CRR_CMF_4,
                    CRR_CMF_5,
                    CRR_CMF_6,
                    CRR_CMF_7,
                    CRR_CMF_8,
                    CRR_CMF_9,
                    CRR_CMF_10,
                    CRR_CMF_11,
                    CRR_CMF_12,
                    CRR_CMF_13,
                    CRR_CMF_14,
                    CRR_CMF_15,
                    CRR_CMF_16,
                    CRR_CMF_17,
                    CRR_CMF_18,
                    CRR_CMF_19,
                    CRR_CMF_20,
                    REUSE_COUNT
                FROM MTMPCRRHIS
                ORDER BY TABLE_UPDATE_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_MTMPCRRHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 80;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1398;
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
    DB_stop_query_timer("DBC_open_mtmpcrrhis", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mtmpcrrhis(int sel_type, struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       struct MTMPCRRHIS_N_TAG MTMPCRRHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MTMPCRRHIS_CUR_1 INTO 
                                                    :MTMPCRRHIS_N.TABLE_UPDATE_SEQ,
                                                    :MTMPCRRHIS_N.CM_KEY_1,
                                                    :MTMPCRRHIS_N.CM_KEY_2,
                                                    :MTMPCRRHIS_N.CM_KEY_3,
                                                    :MTMPCRRHIS_N.CM_KEY_4,
                                                    :MTMPCRRHIS_N.CM_KEY_5,
                                                    :MTMPCRRHIS_N.CRR_ID,
                                                    :MTMPCRRHIS_N.HIST_SEQ,
                                                    :MTMPCRRHIS_N.TRAN_TIME,
                                                    :MTMPCRRHIS_N.SYS_TRAN_TIME,
                                                    :MTMPCRRHIS_N.TRAN_CODE,
                                                    :MTMPCRRHIS_N.FACTORY,
                                                    :MTMPCRRHIS_N.CRR_STATUS,
                                                    :MTMPCRRHIS_N.CRR_STATUS_FLAG,
                                                    :MTMPCRRHIS_N.USAGE_COUNT,
                                                    :MTMPCRRHIS_N.CLEAN_COUNT,
                                                    :MTMPCRRHIS_N.RES_ID,
                                                    :MTMPCRRHIS_N.SUBRES_ID,
                                                    :MTMPCRRHIS_N.PORT_ID,
                                                    :MTMPCRRHIS_N.LOCATION_1,
                                                    :MTMPCRRHIS_N.LOCATION_2,
                                                    :MTMPCRRHIS_N.LOCATION_3,
                                                    :MTMPCRRHIS_N.LOCATION_4,
                                                    :MTMPCRRHIS_N.LOCATION_5,
                                                    :MTMPCRRHIS_N.FINISH_CLEAN_FLAG,
                                                    :MTMPCRRHIS_N.LAST_CLEAN_TIME,
                                                    :MTMPCRRHIS_N.LOT_ID,
                                                    :MTMPCRRHIS_N.LOT_HIST_SEQ,
                                                    :MTMPCRRHIS_N.QTY_1,
                                                    :MTMPCRRHIS_N.QTY_2,
                                                    :MTMPCRRHIS_N.QTY_3,
                                                    :MTMPCRRHIS_N.TBL_SLOT,
                                                    :MTMPCRRHIS_N.MOVE_FLAG,
                                                    :MTMPCRRHIS_N.EMPTY_FLAG,
                                                    :MTMPCRRHIS_N.STOCK_IN_TIME,
                                                    :MTMPCRRHIS_N.TRAN_CMF_1,
                                                    :MTMPCRRHIS_N.TRAN_CMF_2,
                                                    :MTMPCRRHIS_N.TRAN_CMF_3,
                                                    :MTMPCRRHIS_N.TRAN_CMF_4,
                                                    :MTMPCRRHIS_N.TRAN_CMF_5,
                                                    :MTMPCRRHIS_N.TRAN_CMF_6,
                                                    :MTMPCRRHIS_N.TRAN_CMF_7,
                                                    :MTMPCRRHIS_N.TRAN_CMF_8,
                                                    :MTMPCRRHIS_N.TRAN_CMF_9,
                                                    :MTMPCRRHIS_N.TRAN_CMF_10,
                                                    :MTMPCRRHIS_N.TRAN_CMF_11,
                                                    :MTMPCRRHIS_N.TRAN_CMF_12,
                                                    :MTMPCRRHIS_N.TRAN_CMF_13,
                                                    :MTMPCRRHIS_N.TRAN_CMF_14,
                                                    :MTMPCRRHIS_N.TRAN_CMF_15,
                                                    :MTMPCRRHIS_N.TRAN_CMF_16,
                                                    :MTMPCRRHIS_N.TRAN_CMF_17,
                                                    :MTMPCRRHIS_N.TRAN_CMF_18,
                                                    :MTMPCRRHIS_N.TRAN_CMF_19,
                                                    :MTMPCRRHIS_N.TRAN_CMF_20,
                                                    :MTMPCRRHIS_N.TRAN_USER_ID,
                                                    :MTMPCRRHIS_N.TRAN_COMMENT,
                :MTMPCRRHIS_N.PROCESS_FLAG,
                :MTMPCRRHIS_N.CRR_CMF_1,
                :MTMPCRRHIS_N.CRR_CMF_2,
                :MTMPCRRHIS_N.CRR_CMF_3,
                :MTMPCRRHIS_N.CRR_CMF_4,
                :MTMPCRRHIS_N.CRR_CMF_5,
                :MTMPCRRHIS_N.CRR_CMF_6,
                :MTMPCRRHIS_N.CRR_CMF_7,
                :MTMPCRRHIS_N.CRR_CMF_8,
                :MTMPCRRHIS_N.CRR_CMF_9,
                :MTMPCRRHIS_N.CRR_CMF_10,
                :MTMPCRRHIS_N.CRR_CMF_11,
                :MTMPCRRHIS_N.CRR_CMF_12,
                :MTMPCRRHIS_N.CRR_CMF_13,
                :MTMPCRRHIS_N.CRR_CMF_14,
                :MTMPCRRHIS_N.CRR_CMF_15,
                :MTMPCRRHIS_N.CRR_CMF_16,
                :MTMPCRRHIS_N.CRR_CMF_17,
                :MTMPCRRHIS_N.CRR_CMF_18,
                :MTMPCRRHIS_N.CRR_CMF_19,
                :MTMPCRRHIS_N.CRR_CMF_20,
                :MTMPCRRHIS_N.REUSE_COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 80;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1413;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(MTMPCRRHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MTMPCRRHIS_N.CM_KEY_1);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MTMPCRRHIS_N.CM_KEY_2);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MTMPCRRHIS_N.CM_KEY_3);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MTMPCRRHIS_N.CM_KEY_4);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MTMPCRRHIS_N.CM_KEY_5);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MTMPCRRHIS_N.CRR_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MTMPCRRHIS_N.HIST_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MTMPCRRHIS_N.TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MTMPCRRHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MTMPCRRHIS_N.TRAN_CODE);
            sqlstm.sqhstl[10] = (unsigned int  )13;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MTMPCRRHIS_N.FACTORY);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MTMPCRRHIS_N.CRR_STATUS);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MTMPCRRHIS_N.CRR_STATUS_FLAG);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MTMPCRRHIS_N.USAGE_COUNT);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MTMPCRRHIS_N.CLEAN_COUNT);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MTMPCRRHIS_N.RES_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MTMPCRRHIS_N.SUBRES_ID);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MTMPCRRHIS_N.PORT_ID);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MTMPCRRHIS_N.LOCATION_1);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MTMPCRRHIS_N.LOCATION_2);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MTMPCRRHIS_N.LOCATION_3);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MTMPCRRHIS_N.LOCATION_4);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MTMPCRRHIS_N.LOCATION_5);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MTMPCRRHIS_N.FINISH_CLEAN_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MTMPCRRHIS_N.LAST_CLEAN_TIME);
            sqlstm.sqhstl[25] = (unsigned int  )15;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MTMPCRRHIS_N.LOT_ID);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MTMPCRRHIS_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MTMPCRRHIS_N.QTY_1);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MTMPCRRHIS_N.QTY_2);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(MTMPCRRHIS_N.QTY_3);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MTMPCRRHIS_N.TBL_SLOT);
            sqlstm.sqhstl[31] = (unsigned int  )101;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MTMPCRRHIS_N.MOVE_FLAG);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MTMPCRRHIS_N.EMPTY_FLAG);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MTMPCRRHIS_N.STOCK_IN_TIME);
            sqlstm.sqhstl[34] = (unsigned int  )15;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MTMPCRRHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MTMPCRRHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[55] = (unsigned int  )21;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MTMPCRRHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[56] = (unsigned int  )401;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MTMPCRRHIS_N.PROCESS_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_11);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_12);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_13);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_14);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_15);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_16);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_17);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_18);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_19);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MTMPCRRHIS_N.CRR_CMF_20);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MTMPCRRHIS_N.REUSE_COUNT);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(int);
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
        DBC_del_null_mtmpcrrhis(&MTMPCRRHIS_N, MTMPCRRHIS);
    }
    DB_stop_query_timer("DBC_fetch_mtmpcrrhis", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mtmpcrrhis(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MTMPCRRHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 80;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1744;
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
    DB_stop_query_timer("DBC_close_mtmpcrrhis", sel_type);
}


/* Initialize Function */
void DBC_init_mtmpcrrhis(struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    /* memset by Space */
    memset(MTMPCRRHIS, ' ', sizeof(struct MTMPCRRHIS_TAG));
    
    MTMPCRRHIS->TABLE_UPDATE_SEQ = 0;
    MTMPCRRHIS->HIST_SEQ = 0;
    MTMPCRRHIS->USAGE_COUNT = 0;
    MTMPCRRHIS->CLEAN_COUNT = 0;
    MTMPCRRHIS->LOT_HIST_SEQ = 0;
    MTMPCRRHIS->QTY_1 = 0;
    MTMPCRRHIS->QTY_2 = 0;
    MTMPCRRHIS->QTY_3 = 0;
    MTMPCRRHIS->REUSE_COUNT = 0;
}


/* Add Null Function */
void DBC_add_null_mtmpcrrhis(struct MTMPCRRHIS_N_TAG *MTMPCRRHIS_N, struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    /* memset by NULL */
    memset(MTMPCRRHIS_N, '\0', sizeof(struct MTMPCRRHIS_N_TAG));
    
    MTMPCRRHIS_N->TABLE_UPDATE_SEQ = MTMPCRRHIS->TABLE_UPDATE_SEQ;
    MEMCPY_AN(MTMPCRRHIS_N->CM_KEY_1, MTMPCRRHIS->CM_KEY_1, sizeof(MTMPCRRHIS->CM_KEY_1));
    MEMCPY_AN(MTMPCRRHIS_N->CM_KEY_2, MTMPCRRHIS->CM_KEY_2, sizeof(MTMPCRRHIS->CM_KEY_2));
    MEMCPY_AN(MTMPCRRHIS_N->CM_KEY_3, MTMPCRRHIS->CM_KEY_3, sizeof(MTMPCRRHIS->CM_KEY_3));
    MEMCPY_AN(MTMPCRRHIS_N->CM_KEY_4, MTMPCRRHIS->CM_KEY_4, sizeof(MTMPCRRHIS->CM_KEY_4));
    MEMCPY_AN(MTMPCRRHIS_N->CM_KEY_5, MTMPCRRHIS->CM_KEY_5, sizeof(MTMPCRRHIS->CM_KEY_5));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_ID, MTMPCRRHIS->CRR_ID, sizeof(MTMPCRRHIS->CRR_ID));
    MTMPCRRHIS_N->HIST_SEQ = MTMPCRRHIS->HIST_SEQ;
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_TIME, MTMPCRRHIS->TRAN_TIME, sizeof(MTMPCRRHIS->TRAN_TIME));
    MEMCPY_AN(MTMPCRRHIS_N->SYS_TRAN_TIME, MTMPCRRHIS->SYS_TRAN_TIME, sizeof(MTMPCRRHIS->SYS_TRAN_TIME));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CODE, MTMPCRRHIS->TRAN_CODE, sizeof(MTMPCRRHIS->TRAN_CODE));
    MEMCPY_AN(MTMPCRRHIS_N->FACTORY, MTMPCRRHIS->FACTORY, sizeof(MTMPCRRHIS->FACTORY));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_STATUS, MTMPCRRHIS->CRR_STATUS, sizeof(MTMPCRRHIS->CRR_STATUS));
    MTMPCRRHIS_N->CRR_STATUS_FLAG[0] = MTMPCRRHIS->CRR_STATUS_FLAG;
    MTMPCRRHIS_N->USAGE_COUNT = MTMPCRRHIS->USAGE_COUNT;
    MTMPCRRHIS_N->CLEAN_COUNT = MTMPCRRHIS->CLEAN_COUNT;
    MEMCPY_AN(MTMPCRRHIS_N->RES_ID, MTMPCRRHIS->RES_ID, sizeof(MTMPCRRHIS->RES_ID));
    MEMCPY_AN(MTMPCRRHIS_N->SUBRES_ID, MTMPCRRHIS->SUBRES_ID, sizeof(MTMPCRRHIS->SUBRES_ID));
    MEMCPY_AN(MTMPCRRHIS_N->PORT_ID, MTMPCRRHIS->PORT_ID, sizeof(MTMPCRRHIS->PORT_ID));
    MEMCPY_AN(MTMPCRRHIS_N->LOCATION_1, MTMPCRRHIS->LOCATION_1, sizeof(MTMPCRRHIS->LOCATION_1));
    MEMCPY_AN(MTMPCRRHIS_N->LOCATION_2, MTMPCRRHIS->LOCATION_2, sizeof(MTMPCRRHIS->LOCATION_2));
    MEMCPY_AN(MTMPCRRHIS_N->LOCATION_3, MTMPCRRHIS->LOCATION_3, sizeof(MTMPCRRHIS->LOCATION_3));
    MEMCPY_AN(MTMPCRRHIS_N->LOCATION_4, MTMPCRRHIS->LOCATION_4, sizeof(MTMPCRRHIS->LOCATION_4));
    MEMCPY_AN(MTMPCRRHIS_N->LOCATION_5, MTMPCRRHIS->LOCATION_5, sizeof(MTMPCRRHIS->LOCATION_5));
    MTMPCRRHIS_N->FINISH_CLEAN_FLAG[0] = MTMPCRRHIS->FINISH_CLEAN_FLAG;
    MEMCPY_AN(MTMPCRRHIS_N->LAST_CLEAN_TIME, MTMPCRRHIS->LAST_CLEAN_TIME, sizeof(MTMPCRRHIS->LAST_CLEAN_TIME));
    MEMCPY_AN(MTMPCRRHIS_N->LOT_ID, MTMPCRRHIS->LOT_ID, sizeof(MTMPCRRHIS->LOT_ID));
    MTMPCRRHIS_N->LOT_HIST_SEQ = MTMPCRRHIS->LOT_HIST_SEQ;
    MTMPCRRHIS_N->QTY_1 = MTMPCRRHIS->QTY_1;
    MTMPCRRHIS_N->QTY_2 = MTMPCRRHIS->QTY_2;
    MTMPCRRHIS_N->QTY_3 = MTMPCRRHIS->QTY_3;
    MEMCPY_AN(MTMPCRRHIS_N->TBL_SLOT, MTMPCRRHIS->TBL_SLOT, sizeof(MTMPCRRHIS->TBL_SLOT));
    MTMPCRRHIS_N->MOVE_FLAG[0] = MTMPCRRHIS->MOVE_FLAG;
    MTMPCRRHIS_N->EMPTY_FLAG[0] = MTMPCRRHIS->EMPTY_FLAG;
    MEMCPY_AN(MTMPCRRHIS_N->STOCK_IN_TIME, MTMPCRRHIS->STOCK_IN_TIME, sizeof(MTMPCRRHIS->STOCK_IN_TIME));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_1, MTMPCRRHIS->TRAN_CMF_1, sizeof(MTMPCRRHIS->TRAN_CMF_1));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_2, MTMPCRRHIS->TRAN_CMF_2, sizeof(MTMPCRRHIS->TRAN_CMF_2));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_3, MTMPCRRHIS->TRAN_CMF_3, sizeof(MTMPCRRHIS->TRAN_CMF_3));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_4, MTMPCRRHIS->TRAN_CMF_4, sizeof(MTMPCRRHIS->TRAN_CMF_4));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_5, MTMPCRRHIS->TRAN_CMF_5, sizeof(MTMPCRRHIS->TRAN_CMF_5));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_6, MTMPCRRHIS->TRAN_CMF_6, sizeof(MTMPCRRHIS->TRAN_CMF_6));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_7, MTMPCRRHIS->TRAN_CMF_7, sizeof(MTMPCRRHIS->TRAN_CMF_7));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_8, MTMPCRRHIS->TRAN_CMF_8, sizeof(MTMPCRRHIS->TRAN_CMF_8));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_9, MTMPCRRHIS->TRAN_CMF_9, sizeof(MTMPCRRHIS->TRAN_CMF_9));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_10, MTMPCRRHIS->TRAN_CMF_10, sizeof(MTMPCRRHIS->TRAN_CMF_10));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_11, MTMPCRRHIS->TRAN_CMF_11, sizeof(MTMPCRRHIS->TRAN_CMF_11));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_12, MTMPCRRHIS->TRAN_CMF_12, sizeof(MTMPCRRHIS->TRAN_CMF_12));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_13, MTMPCRRHIS->TRAN_CMF_13, sizeof(MTMPCRRHIS->TRAN_CMF_13));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_14, MTMPCRRHIS->TRAN_CMF_14, sizeof(MTMPCRRHIS->TRAN_CMF_14));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_15, MTMPCRRHIS->TRAN_CMF_15, sizeof(MTMPCRRHIS->TRAN_CMF_15));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_16, MTMPCRRHIS->TRAN_CMF_16, sizeof(MTMPCRRHIS->TRAN_CMF_16));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_17, MTMPCRRHIS->TRAN_CMF_17, sizeof(MTMPCRRHIS->TRAN_CMF_17));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_18, MTMPCRRHIS->TRAN_CMF_18, sizeof(MTMPCRRHIS->TRAN_CMF_18));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_19, MTMPCRRHIS->TRAN_CMF_19, sizeof(MTMPCRRHIS->TRAN_CMF_19));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_CMF_20, MTMPCRRHIS->TRAN_CMF_20, sizeof(MTMPCRRHIS->TRAN_CMF_20));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_USER_ID, MTMPCRRHIS->TRAN_USER_ID, sizeof(MTMPCRRHIS->TRAN_USER_ID));
    MEMCPY_AN(MTMPCRRHIS_N->TRAN_COMMENT, MTMPCRRHIS->TRAN_COMMENT, sizeof(MTMPCRRHIS->TRAN_COMMENT));
    MTMPCRRHIS_N->PROCESS_FLAG[0] = MTMPCRRHIS->PROCESS_FLAG;
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_1, MTMPCRRHIS->CRR_CMF_1, sizeof(MTMPCRRHIS->CRR_CMF_1));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_2, MTMPCRRHIS->CRR_CMF_2, sizeof(MTMPCRRHIS->CRR_CMF_2));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_3, MTMPCRRHIS->CRR_CMF_3, sizeof(MTMPCRRHIS->CRR_CMF_3));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_4, MTMPCRRHIS->CRR_CMF_4, sizeof(MTMPCRRHIS->CRR_CMF_4));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_5, MTMPCRRHIS->CRR_CMF_5, sizeof(MTMPCRRHIS->CRR_CMF_5));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_6, MTMPCRRHIS->CRR_CMF_6, sizeof(MTMPCRRHIS->CRR_CMF_6));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_7, MTMPCRRHIS->CRR_CMF_7, sizeof(MTMPCRRHIS->CRR_CMF_7));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_8, MTMPCRRHIS->CRR_CMF_8, sizeof(MTMPCRRHIS->CRR_CMF_8));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_9, MTMPCRRHIS->CRR_CMF_9, sizeof(MTMPCRRHIS->CRR_CMF_9));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_10, MTMPCRRHIS->CRR_CMF_10, sizeof(MTMPCRRHIS->CRR_CMF_10));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_11, MTMPCRRHIS->CRR_CMF_11, sizeof(MTMPCRRHIS->CRR_CMF_11));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_12, MTMPCRRHIS->CRR_CMF_12, sizeof(MTMPCRRHIS->CRR_CMF_12));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_13, MTMPCRRHIS->CRR_CMF_13, sizeof(MTMPCRRHIS->CRR_CMF_13));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_14, MTMPCRRHIS->CRR_CMF_14, sizeof(MTMPCRRHIS->CRR_CMF_14));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_15, MTMPCRRHIS->CRR_CMF_15, sizeof(MTMPCRRHIS->CRR_CMF_15));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_16, MTMPCRRHIS->CRR_CMF_16, sizeof(MTMPCRRHIS->CRR_CMF_16));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_17, MTMPCRRHIS->CRR_CMF_17, sizeof(MTMPCRRHIS->CRR_CMF_17));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_18, MTMPCRRHIS->CRR_CMF_18, sizeof(MTMPCRRHIS->CRR_CMF_18));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_19, MTMPCRRHIS->CRR_CMF_19, sizeof(MTMPCRRHIS->CRR_CMF_19));
    MEMCPY_AN(MTMPCRRHIS_N->CRR_CMF_20, MTMPCRRHIS->CRR_CMF_20, sizeof(MTMPCRRHIS->CRR_CMF_20));
    MTMPCRRHIS_N->REUSE_COUNT = MTMPCRRHIS->REUSE_COUNT;
}


/* Del Null Function */
void DBC_del_null_mtmpcrrhis(struct MTMPCRRHIS_N_TAG *MTMPCRRHIS_N, struct MTMPCRRHIS_TAG *MTMPCRRHIS)
{
    MTMPCRRHIS->TABLE_UPDATE_SEQ = MTMPCRRHIS_N->TABLE_UPDATE_SEQ;
    MEMCPY_DN(MTMPCRRHIS->CM_KEY_1, MTMPCRRHIS_N->CM_KEY_1, sizeof(MTMPCRRHIS->CM_KEY_1));
    MEMCPY_DN(MTMPCRRHIS->CM_KEY_2, MTMPCRRHIS_N->CM_KEY_2, sizeof(MTMPCRRHIS->CM_KEY_2));
    MEMCPY_DN(MTMPCRRHIS->CM_KEY_3, MTMPCRRHIS_N->CM_KEY_3, sizeof(MTMPCRRHIS->CM_KEY_3));
    MEMCPY_DN(MTMPCRRHIS->CM_KEY_4, MTMPCRRHIS_N->CM_KEY_4, sizeof(MTMPCRRHIS->CM_KEY_4));
    MEMCPY_DN(MTMPCRRHIS->CM_KEY_5, MTMPCRRHIS_N->CM_KEY_5, sizeof(MTMPCRRHIS->CM_KEY_5));
    MEMCPY_DN(MTMPCRRHIS->CRR_ID, MTMPCRRHIS_N->CRR_ID, sizeof(MTMPCRRHIS->CRR_ID));
    MTMPCRRHIS->HIST_SEQ = MTMPCRRHIS_N->HIST_SEQ;
    MEMCPY_DN(MTMPCRRHIS->TRAN_TIME, MTMPCRRHIS_N->TRAN_TIME, sizeof(MTMPCRRHIS->TRAN_TIME));
    MEMCPY_DN(MTMPCRRHIS->SYS_TRAN_TIME, MTMPCRRHIS_N->SYS_TRAN_TIME, sizeof(MTMPCRRHIS->SYS_TRAN_TIME));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CODE, MTMPCRRHIS_N->TRAN_CODE, sizeof(MTMPCRRHIS->TRAN_CODE));
    MEMCPY_DN(MTMPCRRHIS->FACTORY, MTMPCRRHIS_N->FACTORY, sizeof(MTMPCRRHIS->FACTORY));
    MEMCPY_DN(MTMPCRRHIS->CRR_STATUS, MTMPCRRHIS_N->CRR_STATUS, sizeof(MTMPCRRHIS->CRR_STATUS));
    MTMPCRRHIS->CRR_STATUS_FLAG = MTMPCRRHIS_N->CRR_STATUS_FLAG[0];
    MTMPCRRHIS->USAGE_COUNT = MTMPCRRHIS_N->USAGE_COUNT;
    MTMPCRRHIS->CLEAN_COUNT = MTMPCRRHIS_N->CLEAN_COUNT;
    MEMCPY_DN(MTMPCRRHIS->RES_ID, MTMPCRRHIS_N->RES_ID, sizeof(MTMPCRRHIS->RES_ID));
    MEMCPY_DN(MTMPCRRHIS->SUBRES_ID, MTMPCRRHIS_N->SUBRES_ID, sizeof(MTMPCRRHIS->SUBRES_ID));
    MEMCPY_DN(MTMPCRRHIS->PORT_ID, MTMPCRRHIS_N->PORT_ID, sizeof(MTMPCRRHIS->PORT_ID));
    MEMCPY_DN(MTMPCRRHIS->LOCATION_1, MTMPCRRHIS_N->LOCATION_1, sizeof(MTMPCRRHIS->LOCATION_1));
    MEMCPY_DN(MTMPCRRHIS->LOCATION_2, MTMPCRRHIS_N->LOCATION_2, sizeof(MTMPCRRHIS->LOCATION_2));
    MEMCPY_DN(MTMPCRRHIS->LOCATION_3, MTMPCRRHIS_N->LOCATION_3, sizeof(MTMPCRRHIS->LOCATION_3));
    MEMCPY_DN(MTMPCRRHIS->LOCATION_4, MTMPCRRHIS_N->LOCATION_4, sizeof(MTMPCRRHIS->LOCATION_4));
    MEMCPY_DN(MTMPCRRHIS->LOCATION_5, MTMPCRRHIS_N->LOCATION_5, sizeof(MTMPCRRHIS->LOCATION_5));
    MTMPCRRHIS->FINISH_CLEAN_FLAG = MTMPCRRHIS_N->FINISH_CLEAN_FLAG[0];
    MEMCPY_DN(MTMPCRRHIS->LAST_CLEAN_TIME, MTMPCRRHIS_N->LAST_CLEAN_TIME, sizeof(MTMPCRRHIS->LAST_CLEAN_TIME));
    MEMCPY_DN(MTMPCRRHIS->LOT_ID, MTMPCRRHIS_N->LOT_ID, sizeof(MTMPCRRHIS->LOT_ID));
    MTMPCRRHIS->LOT_HIST_SEQ = MTMPCRRHIS_N->LOT_HIST_SEQ;
    MTMPCRRHIS->QTY_1 = MTMPCRRHIS_N->QTY_1;
    MTMPCRRHIS->QTY_2 = MTMPCRRHIS_N->QTY_2;
    MTMPCRRHIS->QTY_3 = MTMPCRRHIS_N->QTY_3;
    MEMCPY_DN(MTMPCRRHIS->TBL_SLOT, MTMPCRRHIS_N->TBL_SLOT, sizeof(MTMPCRRHIS->TBL_SLOT));
    MTMPCRRHIS->MOVE_FLAG = MTMPCRRHIS_N->MOVE_FLAG[0];
    MTMPCRRHIS->EMPTY_FLAG = MTMPCRRHIS_N->EMPTY_FLAG[0];
    MEMCPY_DN(MTMPCRRHIS->STOCK_IN_TIME, MTMPCRRHIS_N->STOCK_IN_TIME, sizeof(MTMPCRRHIS->STOCK_IN_TIME));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_1, MTMPCRRHIS_N->TRAN_CMF_1, sizeof(MTMPCRRHIS->TRAN_CMF_1));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_2, MTMPCRRHIS_N->TRAN_CMF_2, sizeof(MTMPCRRHIS->TRAN_CMF_2));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_3, MTMPCRRHIS_N->TRAN_CMF_3, sizeof(MTMPCRRHIS->TRAN_CMF_3));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_4, MTMPCRRHIS_N->TRAN_CMF_4, sizeof(MTMPCRRHIS->TRAN_CMF_4));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_5, MTMPCRRHIS_N->TRAN_CMF_5, sizeof(MTMPCRRHIS->TRAN_CMF_5));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_6, MTMPCRRHIS_N->TRAN_CMF_6, sizeof(MTMPCRRHIS->TRAN_CMF_6));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_7, MTMPCRRHIS_N->TRAN_CMF_7, sizeof(MTMPCRRHIS->TRAN_CMF_7));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_8, MTMPCRRHIS_N->TRAN_CMF_8, sizeof(MTMPCRRHIS->TRAN_CMF_8));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_9, MTMPCRRHIS_N->TRAN_CMF_9, sizeof(MTMPCRRHIS->TRAN_CMF_9));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_10, MTMPCRRHIS_N->TRAN_CMF_10, sizeof(MTMPCRRHIS->TRAN_CMF_10));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_11, MTMPCRRHIS_N->TRAN_CMF_11, sizeof(MTMPCRRHIS->TRAN_CMF_11));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_12, MTMPCRRHIS_N->TRAN_CMF_12, sizeof(MTMPCRRHIS->TRAN_CMF_12));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_13, MTMPCRRHIS_N->TRAN_CMF_13, sizeof(MTMPCRRHIS->TRAN_CMF_13));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_14, MTMPCRRHIS_N->TRAN_CMF_14, sizeof(MTMPCRRHIS->TRAN_CMF_14));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_15, MTMPCRRHIS_N->TRAN_CMF_15, sizeof(MTMPCRRHIS->TRAN_CMF_15));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_16, MTMPCRRHIS_N->TRAN_CMF_16, sizeof(MTMPCRRHIS->TRAN_CMF_16));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_17, MTMPCRRHIS_N->TRAN_CMF_17, sizeof(MTMPCRRHIS->TRAN_CMF_17));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_18, MTMPCRRHIS_N->TRAN_CMF_18, sizeof(MTMPCRRHIS->TRAN_CMF_18));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_19, MTMPCRRHIS_N->TRAN_CMF_19, sizeof(MTMPCRRHIS->TRAN_CMF_19));
    MEMCPY_DN(MTMPCRRHIS->TRAN_CMF_20, MTMPCRRHIS_N->TRAN_CMF_20, sizeof(MTMPCRRHIS->TRAN_CMF_20));
    MEMCPY_DN(MTMPCRRHIS->TRAN_USER_ID, MTMPCRRHIS_N->TRAN_USER_ID, sizeof(MTMPCRRHIS->TRAN_USER_ID));
    MEMCPY_DN(MTMPCRRHIS->TRAN_COMMENT, MTMPCRRHIS_N->TRAN_COMMENT, sizeof(MTMPCRRHIS->TRAN_COMMENT));
    MTMPCRRHIS->PROCESS_FLAG = MTMPCRRHIS_N->PROCESS_FLAG[0];
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_1, MTMPCRRHIS_N->CRR_CMF_1, sizeof(MTMPCRRHIS->CRR_CMF_1));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_2, MTMPCRRHIS_N->CRR_CMF_2, sizeof(MTMPCRRHIS->CRR_CMF_2));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_3, MTMPCRRHIS_N->CRR_CMF_3, sizeof(MTMPCRRHIS->CRR_CMF_3));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_4, MTMPCRRHIS_N->CRR_CMF_4, sizeof(MTMPCRRHIS->CRR_CMF_4));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_5, MTMPCRRHIS_N->CRR_CMF_5, sizeof(MTMPCRRHIS->CRR_CMF_5));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_6, MTMPCRRHIS_N->CRR_CMF_6, sizeof(MTMPCRRHIS->CRR_CMF_6));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_7, MTMPCRRHIS_N->CRR_CMF_7, sizeof(MTMPCRRHIS->CRR_CMF_7));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_8, MTMPCRRHIS_N->CRR_CMF_8, sizeof(MTMPCRRHIS->CRR_CMF_8));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_9, MTMPCRRHIS_N->CRR_CMF_9, sizeof(MTMPCRRHIS->CRR_CMF_9));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_10, MTMPCRRHIS_N->CRR_CMF_10, sizeof(MTMPCRRHIS->CRR_CMF_10));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_11, MTMPCRRHIS_N->CRR_CMF_11, sizeof(MTMPCRRHIS->CRR_CMF_11));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_12, MTMPCRRHIS_N->CRR_CMF_12, sizeof(MTMPCRRHIS->CRR_CMF_12));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_13, MTMPCRRHIS_N->CRR_CMF_13, sizeof(MTMPCRRHIS->CRR_CMF_13));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_14, MTMPCRRHIS_N->CRR_CMF_14, sizeof(MTMPCRRHIS->CRR_CMF_14));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_15, MTMPCRRHIS_N->CRR_CMF_15, sizeof(MTMPCRRHIS->CRR_CMF_15));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_16, MTMPCRRHIS_N->CRR_CMF_16, sizeof(MTMPCRRHIS->CRR_CMF_16));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_17, MTMPCRRHIS_N->CRR_CMF_17, sizeof(MTMPCRRHIS->CRR_CMF_17));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_18, MTMPCRRHIS_N->CRR_CMF_18, sizeof(MTMPCRRHIS->CRR_CMF_18));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_19, MTMPCRRHIS_N->CRR_CMF_19, sizeof(MTMPCRRHIS->CRR_CMF_19));
    MEMCPY_DN(MTMPCRRHIS->CRR_CMF_20, MTMPCRRHIS_N->CRR_CMF_20, sizeof(MTMPCRRHIS->CRR_CMF_20));
    MTMPCRRHIS->REUSE_COUNT = MTMPCRRHIS_N->REUSE_COUNT;
}


