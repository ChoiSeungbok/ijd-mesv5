
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
    "DBC_mqcgsmpdef.pc"
};


static unsigned int sqlctx = 9121819;


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
            void  *sqhstv[52];
   unsigned int   sqhstl[52];
            int   sqhsts[52];
            void  *sqindv[52];
            int   sqinds[52];
   unsigned int   sqharm[52];
   unsigned int   *sqharc[52];
   unsigned short  sqadto[52];
   unsigned short  sqtdso[52];
} sqlstm = {13,52};

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
"select FACTORY ,RULE_ID ,RULE_DESC ,SMP_TYPE ,UNIT1_SMP_FLAG ,UNIT1_SMP_TYP\
E ,UNIT1_SMP_SIZE ,UNIT1_SMP_SEL_TYPE ,UNIT1_SMP_FORMULA ,UNIT1_SMP_SEL_LOC ,\
UNIT2_SMP_FLAG ,UNIT2_SMP_TYPE ,UNIT2_SMP_SIZE ,UNIT2_SMP_SEL_TYPE ,UNIT2_SMP\
_FORMULA ,UNIT2_SMP_SEL_LOC ,LOT_SMP_FLAG ,SKIP_CNT_BY_PASS ,TST_CNT_BY_FAIL \
,TEST_COUNT ,TEST_TYPE_1 ,TEST_TYPE_2 ,TEST_TYPE_3 ,TEST_TYPE_4 ,TEST_TYPE_5 \
,QA_RUL_CMF_1 ,QA_RUL_CMF_2 ,QA_RUL_CMF_3 ,QA_RUL_CMF_4 ,QA_RUL_CMF_5 ,QA_RUL\
_CMF_6 ,QA_RUL_CMF_7 ,QA_RUL_CMF_8 ,QA_RUL_CMF_9 ,QA_RUL_CMF_10 ,CREATE_USER \
,CREATE_TIME ,UPDATE_USER ,UPDATE_TIME ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_FIEL\
D_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FIELD_6 ,RESV_FIELD_7 ,RESV_FIELD_8 ,RE\
SV_FIELD_9 ,RESV_FIELD_10 ,PASS_COUNT_FOR_SKIP  from MQCGSMPDEF  order by FAC\
TORY asc ,RULE_ID asc             ";

 static const char *sq0008 = 
"select FACTORY ,RULE_ID ,RULE_DESC ,SMP_TYPE ,UNIT1_SMP_FLAG ,UNIT1_SMP_TYP\
E ,UNIT1_SMP_SIZE ,UNIT1_SMP_SEL_TYPE ,UNIT1_SMP_FORMULA ,UNIT1_SMP_SEL_LOC ,\
UNIT2_SMP_FLAG ,UNIT2_SMP_TYPE ,UNIT2_SMP_SIZE ,UNIT2_SMP_SEL_TYPE ,UNIT2_SMP\
_FORMULA ,UNIT2_SMP_SEL_LOC ,LOT_SMP_FLAG ,SKIP_CNT_BY_PASS ,TST_CNT_BY_FAIL \
,TEST_COUNT ,TEST_TYPE_1 ,TEST_TYPE_2 ,TEST_TYPE_3 ,TEST_TYPE_4 ,TEST_TYPE_5 \
,QA_RUL_CMF_1 ,QA_RUL_CMF_2 ,QA_RUL_CMF_3 ,QA_RUL_CMF_4 ,QA_RUL_CMF_5 ,QA_RUL\
_CMF_6 ,QA_RUL_CMF_7 ,QA_RUL_CMF_8 ,QA_RUL_CMF_9 ,QA_RUL_CMF_10 ,CREATE_USER \
,CREATE_TIME ,UPDATE_USER ,UPDATE_TIME ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_FIEL\
D_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FIELD_6 ,RESV_FIELD_7 ,RESV_FIELD_8 ,RE\
SV_FIELD_9 ,RESV_FIELD_10 ,PASS_COUNT_FOR_SKIP  from MQCGSMPDEF where (FACTOR\
Y=:b0 and RULE_ID>=:b1) order by FACTORY asc ,RULE_ID asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1035,0,4,45,0,0,52,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,1,97,0,0,1,97,0,0,
228,0,0,2,1047,0,4,184,0,0,52,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,1,97,0,0,1,97,0,0,
451,0,0,3,78,0,4,326,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
478,0,0,4,60,0,2,361,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
501,0,0,5,955,0,3,389,0,0,50,50,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,
716,0,0,6,956,0,5,512,0,0,50,50,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,
931,0,0,7,802,0,9,646,0,0,0,0,0,1,0,
946,0,0,8,838,0,9,706,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
969,0,0,7,0,0,13,734,0,0,50,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,
1184,0,0,8,0,0,13,788,0,0,50,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,
1399,0,0,7,0,0,15,868,0,0,0,0,0,1,0,
1414,0,0,8,0,0,15,872,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mqcgsmpdef.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2008/08/25 15:04:48
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2007 MIRACOM,INC.
**
*********************************************************************/
/* EXEC SQL BEGIN DECLARE SECTION; */ 

/* EXEC SQL INCLUDE DBC_common_n;
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
void DBC_add_null_mqcgsmpdef(struct MQCGSMPDEF_N_TAG *MQCGSMPDEF_N, struct MQCGSMPDEF_TAG *MQCGSMPDEF);
void DBC_del_null_mqcgsmpdef(struct MQCGSMPDEF_N_TAG *MQCGSMPDEF_N, struct MQCGSMPDEF_TAG *MQCGSMPDEF);


/* SQL SELECT Function */
void DBC_select_mqcgsmpdef(int sel_type, struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
		/* EXEC SQL BEGIN DECLARE SECTION; */ 

    struct MQCGSMPDEF_N_TAG MQCGSMPDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcgsmpdef(&MQCGSMPDEF_N, MQCGSMPDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    RULE_ID,
                    RULE_DESC,
                    SMP_TYPE,
                    UNIT1_SMP_FLAG,
                    UNIT1_SMP_TYPE,
                    UNIT1_SMP_SIZE,
                    UNIT1_SMP_SEL_TYPE,
                    UNIT1_SMP_FORMULA,
                    UNIT1_SMP_SEL_LOC,
                    UNIT2_SMP_FLAG,
                    UNIT2_SMP_TYPE,
                    UNIT2_SMP_SIZE,
                    UNIT2_SMP_SEL_TYPE,
                    UNIT2_SMP_FORMULA,
                    UNIT2_SMP_SEL_LOC,
                    LOT_SMP_FLAG,
                    SKIP_CNT_BY_PASS,
                    TST_CNT_BY_FAIL,
                    TEST_COUNT,
                    TEST_TYPE_1,
                    TEST_TYPE_2,
                    TEST_TYPE_3,
                    TEST_TYPE_4,
                    TEST_TYPE_5,
                    QA_RUL_CMF_1,
                    QA_RUL_CMF_2,
                    QA_RUL_CMF_3,
                    QA_RUL_CMF_4,
                    QA_RUL_CMF_5,
                    QA_RUL_CMF_6,
                    QA_RUL_CMF_7,
                    QA_RUL_CMF_8,
                    QA_RUL_CMF_9,
                    QA_RUL_CMF_10,
                    CREATE_USER,
                    CREATE_TIME,
                    UPDATE_USER,
                    UPDATE_TIME,
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
                    PASS_COUNT_FOR_SKIP
                INTO 
                    :MQCGSMPDEF_N.FACTORY,
                    :MQCGSMPDEF_N.RULE_ID,
                    :MQCGSMPDEF_N.RULE_DESC,
                    :MQCGSMPDEF_N.SMP_TYPE,
                    :MQCGSMPDEF_N.UNIT1_SMP_FLAG,
                    :MQCGSMPDEF_N.UNIT1_SMP_TYPE,
                    :MQCGSMPDEF_N.UNIT1_SMP_SIZE,
                    :MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE,
                    :MQCGSMPDEF_N.UNIT1_SMP_FORMULA,
                    :MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC,
                    :MQCGSMPDEF_N.UNIT2_SMP_FLAG,
                    :MQCGSMPDEF_N.UNIT2_SMP_TYPE,
                    :MQCGSMPDEF_N.UNIT2_SMP_SIZE,
                    :MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE,
                    :MQCGSMPDEF_N.UNIT2_SMP_FORMULA,
                    :MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC,
                    :MQCGSMPDEF_N.LOT_SMP_FLAG,
                    :MQCGSMPDEF_N.SKIP_CNT_BY_PASS,
                    :MQCGSMPDEF_N.TST_CNT_BY_FAIL,
                    :MQCGSMPDEF_N.TEST_COUNT,
                    :MQCGSMPDEF_N.TEST_TYPE_1,
                    :MQCGSMPDEF_N.TEST_TYPE_2,
                    :MQCGSMPDEF_N.TEST_TYPE_3,
                    :MQCGSMPDEF_N.TEST_TYPE_4,
                    :MQCGSMPDEF_N.TEST_TYPE_5,
                    :MQCGSMPDEF_N.QA_RUL_CMF_1,
                    :MQCGSMPDEF_N.QA_RUL_CMF_2,
                    :MQCGSMPDEF_N.QA_RUL_CMF_3,
                    :MQCGSMPDEF_N.QA_RUL_CMF_4,
                    :MQCGSMPDEF_N.QA_RUL_CMF_5,
                    :MQCGSMPDEF_N.QA_RUL_CMF_6,
                    :MQCGSMPDEF_N.QA_RUL_CMF_7,
                    :MQCGSMPDEF_N.QA_RUL_CMF_8,
                    :MQCGSMPDEF_N.QA_RUL_CMF_9,
                    :MQCGSMPDEF_N.QA_RUL_CMF_10,
                    :MQCGSMPDEF_N.CREATE_USER,
                    :MQCGSMPDEF_N.CREATE_TIME,
                    :MQCGSMPDEF_N.UPDATE_USER,
                    :MQCGSMPDEF_N.UPDATE_TIME,
                    :MQCGSMPDEF_N.RESV_FIELD_1,
                    :MQCGSMPDEF_N.RESV_FIELD_2,
                    :MQCGSMPDEF_N.RESV_FIELD_3,
                    :MQCGSMPDEF_N.RESV_FIELD_4,
                    :MQCGSMPDEF_N.RESV_FIELD_5,
                    :MQCGSMPDEF_N.RESV_FIELD_6,
                    :MQCGSMPDEF_N.RESV_FIELD_7,
                    :MQCGSMPDEF_N.RESV_FIELD_8,
                    :MQCGSMPDEF_N.RESV_FIELD_9,
                    :MQCGSMPDEF_N.RESV_FIELD_10,
                    :MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP
                FROM MQCGSMPDEF
                WHERE FACTORY = :MQCGSMPDEF_N.FACTORY
                    AND RULE_ID = :MQCGSMPDEF_N.RULE_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,RULE_ID ,RULE_DESC ,SMP_TYPE ,UNIT1_SMP_FLAG \
,UNIT1_SMP_TYPE ,UNIT1_SMP_SIZE ,UNIT1_SMP_SEL_TYPE ,UNIT1_SMP_FORMULA ,UNIT\
1_SMP_SEL_LOC ,UNIT2_SMP_FLAG ,UNIT2_SMP_TYPE ,UNIT2_SMP_SIZE ,UNIT2_SMP_SEL\
_TYPE ,UNIT2_SMP_FORMULA ,UNIT2_SMP_SEL_LOC ,LOT_SMP_FLAG ,SKIP_CNT_BY_PASS \
,TST_CNT_BY_FAIL ,TEST_COUNT ,TEST_TYPE_1 ,TEST_TYPE_2 ,TEST_TYPE_3 ,TEST_TY\
PE_4 ,TEST_TYPE_5 ,QA_RUL_CMF_1 ,QA_RUL_CMF_2 ,QA_RUL_CMF_3 ,QA_RUL_CMF_4 ,Q\
A_RUL_CMF_5 ,QA_RUL_CMF_6 ,QA_RUL_CMF_7 ,QA_RUL_CMF_8 ,QA_RUL_CMF_9 ,QA_RUL_\
CMF_10 ,CREATE_USER ,CREATE_TIME ,UPDATE_USER ,UPDATE_TIME ,RESV_FIELD_1 ,RE\
SV_FIELD_2 ,RESV_FIELD_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FIELD_6 ,RESV_FIE\
LD_7 ,RESV_FIELD_8 ,RESV_FIELD_9 ,RESV_FIELD_10 ,PASS_COUNT_FOR_SKIP into :b\
0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b1\
7,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32\
,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,\
:b48,:b49  from MQCGSMPDEF where (FACTO");
            sqlstm.stmt = "RY=:b0 and RULE_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCGSMPDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MQCGSMPDEF_N.RULE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )51;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCGSMPDEF_N.SMP_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_TYPE);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MQCGSMPDEF_N.UNIT1_SMP_SIZE);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FORMULA);
            sqlstm.sqhstl[8] = (unsigned int  )201;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC);
            sqlstm.sqhstl[9] = (unsigned int  )201;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MQCGSMPDEF_N.UNIT2_SMP_SIZE);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )11;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FORMULA);
            sqlstm.sqhstl[14] = (unsigned int  )201;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC);
            sqlstm.sqhstl[15] = (unsigned int  )201;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MQCGSMPDEF_N.LOT_SMP_FLAG);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MQCGSMPDEF_N.SKIP_CNT_BY_PASS);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MQCGSMPDEF_N.TST_CNT_BY_FAIL);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MQCGSMPDEF_N.TEST_COUNT);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_1);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_2);
            sqlstm.sqhstl[21] = (unsigned int  )11;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_3);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_4);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_5);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MQCGSMPDEF_N.CREATE_USER);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MQCGSMPDEF_N.CREATE_TIME);
            sqlstm.sqhstl[36] = (unsigned int  )15;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MQCGSMPDEF_N.UPDATE_USER);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MQCGSMPDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[38] = (unsigned int  )15;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_1);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_2);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_3);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_4);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_5);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_6);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_7);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_8);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_9);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_10);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MQCGSMPDEF_N.FACTORY);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
            sqlstm.sqhstl[51] = (unsigned int  )21;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
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
        DBC_del_null_mqcgsmpdef(&MQCGSMPDEF_N, MQCGSMPDEF);
    }
    DB_stop_query_timer("DBC_select_mqcgsmpdef", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mqcgsmpdef_for_update(int sel_type, struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    struct MQCGSMPDEF_N_TAG MQCGSMPDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcgsmpdef(&MQCGSMPDEF_N, MQCGSMPDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    RULE_ID,
                    RULE_DESC,
                    SMP_TYPE,
                    UNIT1_SMP_FLAG,
                    UNIT1_SMP_TYPE,
                    UNIT1_SMP_SIZE,
                    UNIT1_SMP_SEL_TYPE,
                    UNIT1_SMP_FORMULA,
                    UNIT1_SMP_SEL_LOC,
                    UNIT2_SMP_FLAG,
                    UNIT2_SMP_TYPE,
                    UNIT2_SMP_SIZE,
                    UNIT2_SMP_SEL_TYPE,
                    UNIT2_SMP_FORMULA,
                    UNIT2_SMP_SEL_LOC,
                    LOT_SMP_FLAG,
                    SKIP_CNT_BY_PASS,
                    TST_CNT_BY_FAIL,
                    TEST_COUNT,
                    TEST_TYPE_1,
                    TEST_TYPE_2,
                    TEST_TYPE_3,
                    TEST_TYPE_4,
                    TEST_TYPE_5,
                    QA_RUL_CMF_1,
                    QA_RUL_CMF_2,
                    QA_RUL_CMF_3,
                    QA_RUL_CMF_4,
                    QA_RUL_CMF_5,
                    QA_RUL_CMF_6,
                    QA_RUL_CMF_7,
                    QA_RUL_CMF_8,
                    QA_RUL_CMF_9,
                    QA_RUL_CMF_10,
                    CREATE_USER,
                    CREATE_TIME,
                    UPDATE_USER,
                    UPDATE_TIME,
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
                    PASS_COUNT_FOR_SKIP
                INTO 
                    :MQCGSMPDEF_N.FACTORY,
                    :MQCGSMPDEF_N.RULE_ID,
                    :MQCGSMPDEF_N.RULE_DESC,
                    :MQCGSMPDEF_N.SMP_TYPE,
                    :MQCGSMPDEF_N.UNIT1_SMP_FLAG,
                    :MQCGSMPDEF_N.UNIT1_SMP_TYPE,
                    :MQCGSMPDEF_N.UNIT1_SMP_SIZE,
                    :MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE,
                    :MQCGSMPDEF_N.UNIT1_SMP_FORMULA,
                    :MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC,
                    :MQCGSMPDEF_N.UNIT2_SMP_FLAG,
                    :MQCGSMPDEF_N.UNIT2_SMP_TYPE,
                    :MQCGSMPDEF_N.UNIT2_SMP_SIZE,
                    :MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE,
                    :MQCGSMPDEF_N.UNIT2_SMP_FORMULA,
                    :MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC,
                    :MQCGSMPDEF_N.LOT_SMP_FLAG,
                    :MQCGSMPDEF_N.SKIP_CNT_BY_PASS,
                    :MQCGSMPDEF_N.TST_CNT_BY_FAIL,
                    :MQCGSMPDEF_N.TEST_COUNT,
                    :MQCGSMPDEF_N.TEST_TYPE_1,
                    :MQCGSMPDEF_N.TEST_TYPE_2,
                    :MQCGSMPDEF_N.TEST_TYPE_3,
                    :MQCGSMPDEF_N.TEST_TYPE_4,
                    :MQCGSMPDEF_N.TEST_TYPE_5,
                    :MQCGSMPDEF_N.QA_RUL_CMF_1,
                    :MQCGSMPDEF_N.QA_RUL_CMF_2,
                    :MQCGSMPDEF_N.QA_RUL_CMF_3,
                    :MQCGSMPDEF_N.QA_RUL_CMF_4,
                    :MQCGSMPDEF_N.QA_RUL_CMF_5,
                    :MQCGSMPDEF_N.QA_RUL_CMF_6,
                    :MQCGSMPDEF_N.QA_RUL_CMF_7,
                    :MQCGSMPDEF_N.QA_RUL_CMF_8,
                    :MQCGSMPDEF_N.QA_RUL_CMF_9,
                    :MQCGSMPDEF_N.QA_RUL_CMF_10,
                    :MQCGSMPDEF_N.CREATE_USER,
                    :MQCGSMPDEF_N.CREATE_TIME,
                    :MQCGSMPDEF_N.UPDATE_USER,
                    :MQCGSMPDEF_N.UPDATE_TIME,
                    :MQCGSMPDEF_N.RESV_FIELD_1,
                    :MQCGSMPDEF_N.RESV_FIELD_2,
                    :MQCGSMPDEF_N.RESV_FIELD_3,
                    :MQCGSMPDEF_N.RESV_FIELD_4,
                    :MQCGSMPDEF_N.RESV_FIELD_5,
                    :MQCGSMPDEF_N.RESV_FIELD_6,
                    :MQCGSMPDEF_N.RESV_FIELD_7,
                    :MQCGSMPDEF_N.RESV_FIELD_8,
                    :MQCGSMPDEF_N.RESV_FIELD_9,
                    :MQCGSMPDEF_N.RESV_FIELD_10,
                    :MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP
                FROM MQCGSMPDEF
                WHERE FACTORY = :MQCGSMPDEF_N.FACTORY
                    AND RULE_ID = :MQCGSMPDEF_N.RULE_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,RULE_ID ,RULE_DESC ,SMP_TYPE ,UNIT1_SMP_FLAG \
,UNIT1_SMP_TYPE ,UNIT1_SMP_SIZE ,UNIT1_SMP_SEL_TYPE ,UNIT1_SMP_FORMULA ,UNIT\
1_SMP_SEL_LOC ,UNIT2_SMP_FLAG ,UNIT2_SMP_TYPE ,UNIT2_SMP_SIZE ,UNIT2_SMP_SEL\
_TYPE ,UNIT2_SMP_FORMULA ,UNIT2_SMP_SEL_LOC ,LOT_SMP_FLAG ,SKIP_CNT_BY_PASS \
,TST_CNT_BY_FAIL ,TEST_COUNT ,TEST_TYPE_1 ,TEST_TYPE_2 ,TEST_TYPE_3 ,TEST_TY\
PE_4 ,TEST_TYPE_5 ,QA_RUL_CMF_1 ,QA_RUL_CMF_2 ,QA_RUL_CMF_3 ,QA_RUL_CMF_4 ,Q\
A_RUL_CMF_5 ,QA_RUL_CMF_6 ,QA_RUL_CMF_7 ,QA_RUL_CMF_8 ,QA_RUL_CMF_9 ,QA_RUL_\
CMF_10 ,CREATE_USER ,CREATE_TIME ,UPDATE_USER ,UPDATE_TIME ,RESV_FIELD_1 ,RE\
SV_FIELD_2 ,RESV_FIELD_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FIELD_6 ,RESV_FIE\
LD_7 ,RESV_FIELD_8 ,RESV_FIELD_9 ,RESV_FIELD_10 ,PASS_COUNT_FOR_SKIP into :b\
0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b1\
7,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32\
,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,\
:b48,:b49  from MQCGSMPDEF where (FACTORY=:b0 and R");
            sqlstm.stmt = "ULE_ID=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )228;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCGSMPDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MQCGSMPDEF_N.RULE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )51;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCGSMPDEF_N.SMP_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_TYPE);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MQCGSMPDEF_N.UNIT1_SMP_SIZE);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FORMULA);
            sqlstm.sqhstl[8] = (unsigned int  )201;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC);
            sqlstm.sqhstl[9] = (unsigned int  )201;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MQCGSMPDEF_N.UNIT2_SMP_SIZE);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )11;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FORMULA);
            sqlstm.sqhstl[14] = (unsigned int  )201;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC);
            sqlstm.sqhstl[15] = (unsigned int  )201;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MQCGSMPDEF_N.LOT_SMP_FLAG);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MQCGSMPDEF_N.SKIP_CNT_BY_PASS);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MQCGSMPDEF_N.TST_CNT_BY_FAIL);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MQCGSMPDEF_N.TEST_COUNT);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_1);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_2);
            sqlstm.sqhstl[21] = (unsigned int  )11;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_3);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_4);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_5);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MQCGSMPDEF_N.CREATE_USER);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MQCGSMPDEF_N.CREATE_TIME);
            sqlstm.sqhstl[36] = (unsigned int  )15;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MQCGSMPDEF_N.UPDATE_USER);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MQCGSMPDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[38] = (unsigned int  )15;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_1);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_2);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_3);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_4);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_5);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_6);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_7);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_8);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_9);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_10);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MQCGSMPDEF_N.FACTORY);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
            sqlstm.sqhstl[51] = (unsigned int  )21;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
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
        DBC_del_null_mqcgsmpdef(&MQCGSMPDEF_N, MQCGSMPDEF);
    }
    DB_stop_query_timer("DBC_select_mqcgsmpdef_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mqcgsmpdef_scalar(int sel_type, struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    struct MQCGSMPDEF_N_TAG MQCGSMPDEF_N;
    double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcgsmpdef(&MQCGSMPDEF_N, MQCGSMPDEF);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MQCGSMPDEF
                WHERE FACTORY = :MQCGSMPDEF_N.FACTORY
                    AND RULE_ID = :MQCGSMPDEF_N.RULE_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MQCGSMPDEF where\
 (FACTORY=:b1 and RULE_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )451;
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
            sqlstm.sqhstv[1] = (         void  *)(MQCGSMPDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
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

    DB_stop_query_timer("DBC_select_mqcgsmpdef_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mqcgsmpdef(int sel_type, struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    struct MQCGSMPDEF_N_TAG MQCGSMPDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcgsmpdef(&MQCGSMPDEF_N, MQCGSMPDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MQCGSMPDEF
                WHERE FACTORY = :MQCGSMPDEF_N.FACTORY
                    AND RULE_ID = :MQCGSMPDEF_N.RULE_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MQCGSMPDEF  where (FACTORY=:b0 and \
RULE_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )478;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCGSMPDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
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
    DB_stop_query_timer("DBC_delete_mqcgsmpdef", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mqcgsmpdef(struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    struct MQCGSMPDEF_N_TAG MQCGSMPDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcgsmpdef(&MQCGSMPDEF_N, MQCGSMPDEF);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MQCGSMPDEF( 
                    FACTORY, 
                    RULE_ID, 
                    RULE_DESC, 
                    SMP_TYPE, 
                    UNIT1_SMP_FLAG, 
                    UNIT1_SMP_TYPE, 
                    UNIT1_SMP_SIZE, 
                    UNIT1_SMP_SEL_TYPE, 
                    UNIT1_SMP_FORMULA, 
                    UNIT1_SMP_SEL_LOC, 
                    UNIT2_SMP_FLAG, 
                    UNIT2_SMP_TYPE, 
                    UNIT2_SMP_SIZE, 
                    UNIT2_SMP_SEL_TYPE, 
                    UNIT2_SMP_FORMULA, 
                    UNIT2_SMP_SEL_LOC, 
                    LOT_SMP_FLAG, 
                    SKIP_CNT_BY_PASS, 
                    TST_CNT_BY_FAIL, 
                    TEST_COUNT, 
                    TEST_TYPE_1, 
                    TEST_TYPE_2, 
                    TEST_TYPE_3, 
                    TEST_TYPE_4, 
                    TEST_TYPE_5, 
                    QA_RUL_CMF_1, 
                    QA_RUL_CMF_2, 
                    QA_RUL_CMF_3, 
                    QA_RUL_CMF_4, 
                    QA_RUL_CMF_5, 
                    QA_RUL_CMF_6, 
                    QA_RUL_CMF_7, 
                    QA_RUL_CMF_8, 
                    QA_RUL_CMF_9, 
                    QA_RUL_CMF_10, 
                    CREATE_USER, 
                    CREATE_TIME, 
                    UPDATE_USER, 
                    UPDATE_TIME, 
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
                    PASS_COUNT_FOR_SKIP
         ) 
        VALUES (
                    :MQCGSMPDEF_N.FACTORY,
                    :MQCGSMPDEF_N.RULE_ID,
                    :MQCGSMPDEF_N.RULE_DESC,
                    :MQCGSMPDEF_N.SMP_TYPE,
                    :MQCGSMPDEF_N.UNIT1_SMP_FLAG,
                    :MQCGSMPDEF_N.UNIT1_SMP_TYPE,
                    :MQCGSMPDEF_N.UNIT1_SMP_SIZE,
                    :MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE,
                    :MQCGSMPDEF_N.UNIT1_SMP_FORMULA,
                    :MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC,
                    :MQCGSMPDEF_N.UNIT2_SMP_FLAG,
                    :MQCGSMPDEF_N.UNIT2_SMP_TYPE,
                    :MQCGSMPDEF_N.UNIT2_SMP_SIZE,
                    :MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE,
                    :MQCGSMPDEF_N.UNIT2_SMP_FORMULA,
                    :MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC,
                    :MQCGSMPDEF_N.LOT_SMP_FLAG,
                    :MQCGSMPDEF_N.SKIP_CNT_BY_PASS,
                    :MQCGSMPDEF_N.TST_CNT_BY_FAIL,
                    :MQCGSMPDEF_N.TEST_COUNT,
                    :MQCGSMPDEF_N.TEST_TYPE_1,
                    :MQCGSMPDEF_N.TEST_TYPE_2,
                    :MQCGSMPDEF_N.TEST_TYPE_3,
                    :MQCGSMPDEF_N.TEST_TYPE_4,
                    :MQCGSMPDEF_N.TEST_TYPE_5,
                    :MQCGSMPDEF_N.QA_RUL_CMF_1,
                    :MQCGSMPDEF_N.QA_RUL_CMF_2,
                    :MQCGSMPDEF_N.QA_RUL_CMF_3,
                    :MQCGSMPDEF_N.QA_RUL_CMF_4,
                    :MQCGSMPDEF_N.QA_RUL_CMF_5,
                    :MQCGSMPDEF_N.QA_RUL_CMF_6,
                    :MQCGSMPDEF_N.QA_RUL_CMF_7,
                    :MQCGSMPDEF_N.QA_RUL_CMF_8,
                    :MQCGSMPDEF_N.QA_RUL_CMF_9,
                    :MQCGSMPDEF_N.QA_RUL_CMF_10,
                    :MQCGSMPDEF_N.CREATE_USER,
                    :MQCGSMPDEF_N.CREATE_TIME,
                    :MQCGSMPDEF_N.UPDATE_USER,
                    :MQCGSMPDEF_N.UPDATE_TIME,
                    :MQCGSMPDEF_N.RESV_FIELD_1,
                    :MQCGSMPDEF_N.RESV_FIELD_2,
                    :MQCGSMPDEF_N.RESV_FIELD_3,
                    :MQCGSMPDEF_N.RESV_FIELD_4,
                    :MQCGSMPDEF_N.RESV_FIELD_5,
                    :MQCGSMPDEF_N.RESV_FIELD_6,
                    :MQCGSMPDEF_N.RESV_FIELD_7,
                    :MQCGSMPDEF_N.RESV_FIELD_8,
                    :MQCGSMPDEF_N.RESV_FIELD_9,
                    :MQCGSMPDEF_N.RESV_FIELD_10,
                    :MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 52;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into MQCGSMPDEF (FACTORY,RULE_ID,RULE_DESC,SMP_TY\
PE,UNIT1_SMP_FLAG,UNIT1_SMP_TYPE,UNIT1_SMP_SIZE,UNIT1_SMP_SEL_TYPE,UNIT1_SMP_\
FORMULA,UNIT1_SMP_SEL_LOC,UNIT2_SMP_FLAG,UNIT2_SMP_TYPE,UNIT2_SMP_SIZE,UNIT2_\
SMP_SEL_TYPE,UNIT2_SMP_FORMULA,UNIT2_SMP_SEL_LOC,LOT_SMP_FLAG,SKIP_CNT_BY_PAS\
S,TST_CNT_BY_FAIL,TEST_COUNT,TEST_TYPE_1,TEST_TYPE_2,TEST_TYPE_3,TEST_TYPE_4,\
TEST_TYPE_5,QA_RUL_CMF_1,QA_RUL_CMF_2,QA_RUL_CMF_3,QA_RUL_CMF_4,QA_RUL_CMF_5,\
QA_RUL_CMF_6,QA_RUL_CMF_7,QA_RUL_CMF_8,QA_RUL_CMF_9,QA_RUL_CMF_10,CREATE_USER\
,CREATE_TIME,UPDATE_USER,UPDATE_TIME,RESV_FIELD_1,RESV_FIELD_2,RESV_FIELD_3,R\
ESV_FIELD_4,RESV_FIELD_5,RESV_FIELD_6,RESV_FIELD_7,RESV_FIELD_8,RESV_FIELD_9,\
RESV_FIELD_10,PASS_COUNT_FOR_SKIP) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b\
8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:\
b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b3\
9,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )501;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MQCGSMPDEF_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MQCGSMPDEF_N.RULE_DESC);
    sqlstm.sqhstl[2] = (unsigned int  )51;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MQCGSMPDEF_N.SMP_TYPE);
    sqlstm.sqhstl[3] = (unsigned int  )11;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FLAG);
    sqlstm.sqhstl[4] = (unsigned int  )2;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_TYPE);
    sqlstm.sqhstl[5] = (unsigned int  )11;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)&(MQCGSMPDEF_N.UNIT1_SMP_SIZE);
    sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE);
    sqlstm.sqhstl[7] = (unsigned int  )11;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FORMULA);
    sqlstm.sqhstl[8] = (unsigned int  )201;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC);
    sqlstm.sqhstl[9] = (unsigned int  )201;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FLAG);
    sqlstm.sqhstl[10] = (unsigned int  )2;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_TYPE);
    sqlstm.sqhstl[11] = (unsigned int  )11;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)&(MQCGSMPDEF_N.UNIT2_SMP_SIZE);
    sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE);
    sqlstm.sqhstl[13] = (unsigned int  )11;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FORMULA);
    sqlstm.sqhstl[14] = (unsigned int  )201;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC);
    sqlstm.sqhstl[15] = (unsigned int  )201;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MQCGSMPDEF_N.LOT_SMP_FLAG);
    sqlstm.sqhstl[16] = (unsigned int  )2;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)&(MQCGSMPDEF_N.SKIP_CNT_BY_PASS);
    sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)&(MQCGSMPDEF_N.TST_CNT_BY_FAIL);
    sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)&(MQCGSMPDEF_N.TEST_COUNT);
    sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_1);
    sqlstm.sqhstl[20] = (unsigned int  )11;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_2);
    sqlstm.sqhstl[21] = (unsigned int  )11;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_3);
    sqlstm.sqhstl[22] = (unsigned int  )11;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_4);
    sqlstm.sqhstl[23] = (unsigned int  )11;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_5);
    sqlstm.sqhstl[24] = (unsigned int  )11;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_1);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_2);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_3);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_4);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_5);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_6);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_7);
    sqlstm.sqhstl[31] = (unsigned int  )31;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_8);
    sqlstm.sqhstl[32] = (unsigned int  )31;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_9);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_10);
    sqlstm.sqhstl[34] = (unsigned int  )31;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MQCGSMPDEF_N.CREATE_USER);
    sqlstm.sqhstl[35] = (unsigned int  )21;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MQCGSMPDEF_N.CREATE_TIME);
    sqlstm.sqhstl[36] = (unsigned int  )15;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MQCGSMPDEF_N.UPDATE_USER);
    sqlstm.sqhstl[37] = (unsigned int  )21;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MQCGSMPDEF_N.UPDATE_TIME);
    sqlstm.sqhstl[38] = (unsigned int  )15;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_1);
    sqlstm.sqhstl[39] = (unsigned int  )31;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_2);
    sqlstm.sqhstl[40] = (unsigned int  )31;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_3);
    sqlstm.sqhstl[41] = (unsigned int  )31;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_4);
    sqlstm.sqhstl[42] = (unsigned int  )31;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_5);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_6);
    sqlstm.sqhstl[44] = (unsigned int  )31;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_7);
    sqlstm.sqhstl[45] = (unsigned int  )31;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_8);
    sqlstm.sqhstl[46] = (unsigned int  )31;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_9);
    sqlstm.sqhstl[47] = (unsigned int  )31;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_10);
    sqlstm.sqhstl[48] = (unsigned int  )31;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)&(MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP);
    sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
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


    DB_stop_query_timer("DBC_insert_mqcgsmpdef", 0);
}


/* SQL UPDATE Function */
void DBC_update_mqcgsmpdef(int sel_type, struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    struct MQCGSMPDEF_N_TAG MQCGSMPDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcgsmpdef(&MQCGSMPDEF_N, MQCGSMPDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MQCGSMPDEF SET
                    RULE_DESC = :MQCGSMPDEF_N.RULE_DESC,
                    SMP_TYPE = :MQCGSMPDEF_N.SMP_TYPE,
                    UNIT1_SMP_FLAG = :MQCGSMPDEF_N.UNIT1_SMP_FLAG,
                    UNIT1_SMP_TYPE = :MQCGSMPDEF_N.UNIT1_SMP_TYPE,
                    UNIT1_SMP_SIZE = :MQCGSMPDEF_N.UNIT1_SMP_SIZE,
                    UNIT1_SMP_SEL_TYPE = :MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE,
                    UNIT1_SMP_FORMULA = :MQCGSMPDEF_N.UNIT1_SMP_FORMULA,
                    UNIT1_SMP_SEL_LOC = :MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC,
                    UNIT2_SMP_FLAG = :MQCGSMPDEF_N.UNIT2_SMP_FLAG,
                    UNIT2_SMP_TYPE = :MQCGSMPDEF_N.UNIT2_SMP_TYPE,
                    UNIT2_SMP_SIZE = :MQCGSMPDEF_N.UNIT2_SMP_SIZE,
                    UNIT2_SMP_SEL_TYPE = :MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE,
                    UNIT2_SMP_FORMULA = :MQCGSMPDEF_N.UNIT2_SMP_FORMULA,
                    UNIT2_SMP_SEL_LOC = :MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC,
                    LOT_SMP_FLAG = :MQCGSMPDEF_N.LOT_SMP_FLAG,
                    SKIP_CNT_BY_PASS = :MQCGSMPDEF_N.SKIP_CNT_BY_PASS,
                    TST_CNT_BY_FAIL = :MQCGSMPDEF_N.TST_CNT_BY_FAIL,
                    TEST_COUNT = :MQCGSMPDEF_N.TEST_COUNT,
                    TEST_TYPE_1 = :MQCGSMPDEF_N.TEST_TYPE_1,
                    TEST_TYPE_2 = :MQCGSMPDEF_N.TEST_TYPE_2,
                    TEST_TYPE_3 = :MQCGSMPDEF_N.TEST_TYPE_3,
                    TEST_TYPE_4 = :MQCGSMPDEF_N.TEST_TYPE_4,
                    TEST_TYPE_5 = :MQCGSMPDEF_N.TEST_TYPE_5,
                    QA_RUL_CMF_1 = :MQCGSMPDEF_N.QA_RUL_CMF_1,
                    QA_RUL_CMF_2 = :MQCGSMPDEF_N.QA_RUL_CMF_2,
                    QA_RUL_CMF_3 = :MQCGSMPDEF_N.QA_RUL_CMF_3,
                    QA_RUL_CMF_4 = :MQCGSMPDEF_N.QA_RUL_CMF_4,
                    QA_RUL_CMF_5 = :MQCGSMPDEF_N.QA_RUL_CMF_5,
                    QA_RUL_CMF_6 = :MQCGSMPDEF_N.QA_RUL_CMF_6,
                    QA_RUL_CMF_7 = :MQCGSMPDEF_N.QA_RUL_CMF_7,
                    QA_RUL_CMF_8 = :MQCGSMPDEF_N.QA_RUL_CMF_8,
                    QA_RUL_CMF_9 = :MQCGSMPDEF_N.QA_RUL_CMF_9,
                    QA_RUL_CMF_10 = :MQCGSMPDEF_N.QA_RUL_CMF_10,
                    CREATE_USER = :MQCGSMPDEF_N.CREATE_USER,
                    CREATE_TIME = :MQCGSMPDEF_N.CREATE_TIME,
                    UPDATE_USER = :MQCGSMPDEF_N.UPDATE_USER,
                    UPDATE_TIME = :MQCGSMPDEF_N.UPDATE_TIME,
                    RESV_FIELD_1 = :MQCGSMPDEF_N.RESV_FIELD_1,
                    RESV_FIELD_2 = :MQCGSMPDEF_N.RESV_FIELD_2,
                    RESV_FIELD_3 = :MQCGSMPDEF_N.RESV_FIELD_3,
                    RESV_FIELD_4 = :MQCGSMPDEF_N.RESV_FIELD_4,
                    RESV_FIELD_5 = :MQCGSMPDEF_N.RESV_FIELD_5,
                    RESV_FIELD_6 = :MQCGSMPDEF_N.RESV_FIELD_6,
                    RESV_FIELD_7 = :MQCGSMPDEF_N.RESV_FIELD_7,
                    RESV_FIELD_8 = :MQCGSMPDEF_N.RESV_FIELD_8,
                    RESV_FIELD_9 = :MQCGSMPDEF_N.RESV_FIELD_9,
                    RESV_FIELD_10 = :MQCGSMPDEF_N.RESV_FIELD_10,
					PASS_COUNT_FOR_SKIP = :MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP
                WHERE FACTORY = :MQCGSMPDEF_N.FACTORY
                    AND RULE_ID = :MQCGSMPDEF_N.RULE_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MQCGSMPDEF  set RULE_DESC=:b0,SMP_TYPE=:b\
1,UNIT1_SMP_FLAG=:b2,UNIT1_SMP_TYPE=:b3,UNIT1_SMP_SIZE=:b4,UNIT1_SMP_SEL_TYPE\
=:b5,UNIT1_SMP_FORMULA=:b6,UNIT1_SMP_SEL_LOC=:b7,UNIT2_SMP_FLAG=:b8,UNIT2_SMP\
_TYPE=:b9,UNIT2_SMP_SIZE=:b10,UNIT2_SMP_SEL_TYPE=:b11,UNIT2_SMP_FORMULA=:b12,\
UNIT2_SMP_SEL_LOC=:b13,LOT_SMP_FLAG=:b14,SKIP_CNT_BY_PASS=:b15,TST_CNT_BY_FAI\
L=:b16,TEST_COUNT=:b17,TEST_TYPE_1=:b18,TEST_TYPE_2=:b19,TEST_TYPE_3=:b20,TES\
T_TYPE_4=:b21,TEST_TYPE_5=:b22,QA_RUL_CMF_1=:b23,QA_RUL_CMF_2=:b24,QA_RUL_CMF\
_3=:b25,QA_RUL_CMF_4=:b26,QA_RUL_CMF_5=:b27,QA_RUL_CMF_6=:b28,QA_RUL_CMF_7=:b\
29,QA_RUL_CMF_8=:b30,QA_RUL_CMF_9=:b31,QA_RUL_CMF_10=:b32,CREATE_USER=:b33,CR\
EATE_TIME=:b34,UPDATE_USER=:b35,UPDATE_TIME=:b36,RESV_FIELD_1=:b37,RESV_FIELD\
_2=:b38,RESV_FIELD_3=:b39,RESV_FIELD_4=:b40,RESV_FIELD_5=:b41,RESV_FIELD_6=:b\
42,RESV_FIELD_7=:b43,RESV_FIELD_8=:b44,RESV_FIELD_9=:b45,RESV_FIELD_10=:b46,P\
ASS_COUNT_FOR_SKIP=:b47 where (FACTORY=:b48 and RULE_ID=:b49)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )716;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCGSMPDEF_N.RULE_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )51;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCGSMPDEF_N.SMP_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MQCGSMPDEF_N.UNIT1_SMP_SIZE);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FORMULA);
            sqlstm.sqhstl[6] = (unsigned int  )201;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC);
            sqlstm.sqhstl[7] = (unsigned int  )201;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_TYPE);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MQCGSMPDEF_N.UNIT2_SMP_SIZE);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FORMULA);
            sqlstm.sqhstl[12] = (unsigned int  )201;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC);
            sqlstm.sqhstl[13] = (unsigned int  )201;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MQCGSMPDEF_N.LOT_SMP_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MQCGSMPDEF_N.SKIP_CNT_BY_PASS);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MQCGSMPDEF_N.TST_CNT_BY_FAIL);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MQCGSMPDEF_N.TEST_COUNT);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_1);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_2);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_3);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_4);
            sqlstm.sqhstl[21] = (unsigned int  )11;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_5);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_1);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_2);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_3);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_4);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_5);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_6);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_7);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_8);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_9);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_10);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MQCGSMPDEF_N.CREATE_USER);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MQCGSMPDEF_N.CREATE_TIME);
            sqlstm.sqhstl[34] = (unsigned int  )15;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MQCGSMPDEF_N.UPDATE_USER);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MQCGSMPDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[36] = (unsigned int  )15;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MQCGSMPDEF_N.FACTORY);
            sqlstm.sqhstl[48] = (unsigned int  )11;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
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
    DB_stop_query_timer("DBC_update_mqcgsmpdef", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mqcgsmpdef(int sel_type, struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    struct MQCGSMPDEF_N_TAG MQCGSMPDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcgsmpdef(&MQCGSMPDEF_N, MQCGSMPDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MQCGSMPDEF_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    RULE_ID,
                    RULE_DESC,
                    SMP_TYPE,
                    UNIT1_SMP_FLAG,
                    UNIT1_SMP_TYPE,
                    UNIT1_SMP_SIZE,
                    UNIT1_SMP_SEL_TYPE,
                    UNIT1_SMP_FORMULA,
                    UNIT1_SMP_SEL_LOC,
                    UNIT2_SMP_FLAG,
                    UNIT2_SMP_TYPE,
                    UNIT2_SMP_SIZE,
                    UNIT2_SMP_SEL_TYPE,
                    UNIT2_SMP_FORMULA,
                    UNIT2_SMP_SEL_LOC,
                    LOT_SMP_FLAG,
                    SKIP_CNT_BY_PASS,
                    TST_CNT_BY_FAIL,
                    TEST_COUNT,
                    TEST_TYPE_1,
                    TEST_TYPE_2,
                    TEST_TYPE_3,
                    TEST_TYPE_4,
                    TEST_TYPE_5,
                    QA_RUL_CMF_1,
                    QA_RUL_CMF_2,
                    QA_RUL_CMF_3,
                    QA_RUL_CMF_4,
                    QA_RUL_CMF_5,
                    QA_RUL_CMF_6,
                    QA_RUL_CMF_7,
                    QA_RUL_CMF_8,
                    QA_RUL_CMF_9,
                    QA_RUL_CMF_10,
                    CREATE_USER,
                    CREATE_TIME,
                    UPDATE_USER,
                    UPDATE_TIME,
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
                    PASS_COUNT_FOR_SKIP
                FROM MQCGSMPDEF
                ORDER BY FACTORY ASC,
                    RULE_ID ASC; */ 

            /* EXEC SQL OPEN DBC_MQCGSMPDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )931;
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
		case 2:
            /* EXEC SQL DECLARE DBC_MQCGSMPDEF_CUR_2 CURSOR FOR
                SELECT 
                    FACTORY,
                    RULE_ID,
                    RULE_DESC,
                    SMP_TYPE,
                    UNIT1_SMP_FLAG,
                    UNIT1_SMP_TYPE,
                    UNIT1_SMP_SIZE,
                    UNIT1_SMP_SEL_TYPE,
                    UNIT1_SMP_FORMULA,
                    UNIT1_SMP_SEL_LOC,
                    UNIT2_SMP_FLAG,
                    UNIT2_SMP_TYPE,
                    UNIT2_SMP_SIZE,
                    UNIT2_SMP_SEL_TYPE,
                    UNIT2_SMP_FORMULA,
                    UNIT2_SMP_SEL_LOC,
                    LOT_SMP_FLAG,
                    SKIP_CNT_BY_PASS,
                    TST_CNT_BY_FAIL,
                    TEST_COUNT,
                    TEST_TYPE_1,
                    TEST_TYPE_2,
                    TEST_TYPE_3,
                    TEST_TYPE_4,
                    TEST_TYPE_5,
                    QA_RUL_CMF_1,
                    QA_RUL_CMF_2,
                    QA_RUL_CMF_3,
                    QA_RUL_CMF_4,
                    QA_RUL_CMF_5,
                    QA_RUL_CMF_6,
                    QA_RUL_CMF_7,
                    QA_RUL_CMF_8,
                    QA_RUL_CMF_9,
                    QA_RUL_CMF_10,
                    CREATE_USER,
                    CREATE_TIME,
                    UPDATE_USER,
                    UPDATE_TIME,
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
                    PASS_COUNT_FOR_SKIP
                FROM MQCGSMPDEF
                WHERE FACTORY =: MQCGSMPDEF_N.FACTORY AND
                RULE_ID >=: MQCGSMPDEF_N.RULE_ID
                ORDER BY FACTORY ASC,
                    RULE_ID ASC; */ 

            /* EXEC SQL OPEN DBC_MQCGSMPDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )946;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCGSMPDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_open_mqcgsmpdef", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mqcgsmpdef(int sel_type, struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    struct MQCGSMPDEF_N_TAG MQCGSMPDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MQCGSMPDEF_CUR_1 INTO
                :MQCGSMPDEF_N.FACTORY,
                :MQCGSMPDEF_N.RULE_ID,
                :MQCGSMPDEF_N.RULE_DESC,
                :MQCGSMPDEF_N.SMP_TYPE,
                :MQCGSMPDEF_N.UNIT1_SMP_FLAG,
                :MQCGSMPDEF_N.UNIT1_SMP_TYPE,
                :MQCGSMPDEF_N.UNIT1_SMP_SIZE,
                :MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE,
                :MQCGSMPDEF_N.UNIT1_SMP_FORMULA,
                :MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC,
                :MQCGSMPDEF_N.UNIT2_SMP_FLAG,
                :MQCGSMPDEF_N.UNIT2_SMP_TYPE,
                :MQCGSMPDEF_N.UNIT2_SMP_SIZE,
                :MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE,
                :MQCGSMPDEF_N.UNIT2_SMP_FORMULA,
                :MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC,
                :MQCGSMPDEF_N.LOT_SMP_FLAG,
                :MQCGSMPDEF_N.SKIP_CNT_BY_PASS,
                :MQCGSMPDEF_N.TST_CNT_BY_FAIL,
                :MQCGSMPDEF_N.TEST_COUNT,
                :MQCGSMPDEF_N.TEST_TYPE_1,
                :MQCGSMPDEF_N.TEST_TYPE_2,
                :MQCGSMPDEF_N.TEST_TYPE_3,
                :MQCGSMPDEF_N.TEST_TYPE_4,
                :MQCGSMPDEF_N.TEST_TYPE_5,
                :MQCGSMPDEF_N.QA_RUL_CMF_1,
                :MQCGSMPDEF_N.QA_RUL_CMF_2,
                :MQCGSMPDEF_N.QA_RUL_CMF_3,
                :MQCGSMPDEF_N.QA_RUL_CMF_4,
                :MQCGSMPDEF_N.QA_RUL_CMF_5,
                :MQCGSMPDEF_N.QA_RUL_CMF_6,
                :MQCGSMPDEF_N.QA_RUL_CMF_7,
                :MQCGSMPDEF_N.QA_RUL_CMF_8,
                :MQCGSMPDEF_N.QA_RUL_CMF_9,
                :MQCGSMPDEF_N.QA_RUL_CMF_10,
                :MQCGSMPDEF_N.CREATE_USER,
                :MQCGSMPDEF_N.CREATE_TIME,
                :MQCGSMPDEF_N.UPDATE_USER,
                :MQCGSMPDEF_N.UPDATE_TIME,
                :MQCGSMPDEF_N.RESV_FIELD_1,
                :MQCGSMPDEF_N.RESV_FIELD_2,
                :MQCGSMPDEF_N.RESV_FIELD_3,
                :MQCGSMPDEF_N.RESV_FIELD_4,
                :MQCGSMPDEF_N.RESV_FIELD_5,
                :MQCGSMPDEF_N.RESV_FIELD_6,
                :MQCGSMPDEF_N.RESV_FIELD_7,
                :MQCGSMPDEF_N.RESV_FIELD_8,
                :MQCGSMPDEF_N.RESV_FIELD_9,
                :MQCGSMPDEF_N.RESV_FIELD_10,
                :MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )969;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MQCGSMPDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MQCGSMPDEF_N.RULE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )51;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCGSMPDEF_N.SMP_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_TYPE);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MQCGSMPDEF_N.UNIT1_SMP_SIZE);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FORMULA);
            sqlstm.sqhstl[8] = (unsigned int  )201;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC);
            sqlstm.sqhstl[9] = (unsigned int  )201;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MQCGSMPDEF_N.UNIT2_SMP_SIZE);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )11;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FORMULA);
            sqlstm.sqhstl[14] = (unsigned int  )201;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC);
            sqlstm.sqhstl[15] = (unsigned int  )201;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MQCGSMPDEF_N.LOT_SMP_FLAG);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MQCGSMPDEF_N.SKIP_CNT_BY_PASS);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MQCGSMPDEF_N.TST_CNT_BY_FAIL);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MQCGSMPDEF_N.TEST_COUNT);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_1);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_2);
            sqlstm.sqhstl[21] = (unsigned int  )11;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_3);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_4);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_5);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MQCGSMPDEF_N.CREATE_USER);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MQCGSMPDEF_N.CREATE_TIME);
            sqlstm.sqhstl[36] = (unsigned int  )15;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MQCGSMPDEF_N.UPDATE_USER);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MQCGSMPDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[38] = (unsigned int  )15;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_1);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_2);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_3);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_4);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_5);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_6);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_7);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_8);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_9);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_10);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_MQCGSMPDEF_CUR_2 INTO
                :MQCGSMPDEF_N.FACTORY,
                :MQCGSMPDEF_N.RULE_ID,
                :MQCGSMPDEF_N.RULE_DESC,
                :MQCGSMPDEF_N.SMP_TYPE,
                :MQCGSMPDEF_N.UNIT1_SMP_FLAG,
                :MQCGSMPDEF_N.UNIT1_SMP_TYPE,
                :MQCGSMPDEF_N.UNIT1_SMP_SIZE,
                :MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE,
                :MQCGSMPDEF_N.UNIT1_SMP_FORMULA,
                :MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC,
                :MQCGSMPDEF_N.UNIT2_SMP_FLAG,
                :MQCGSMPDEF_N.UNIT2_SMP_TYPE,
                :MQCGSMPDEF_N.UNIT2_SMP_SIZE,
                :MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE,
                :MQCGSMPDEF_N.UNIT2_SMP_FORMULA,
                :MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC,
                :MQCGSMPDEF_N.LOT_SMP_FLAG,
                :MQCGSMPDEF_N.SKIP_CNT_BY_PASS,
                :MQCGSMPDEF_N.TST_CNT_BY_FAIL,
                :MQCGSMPDEF_N.TEST_COUNT,
                :MQCGSMPDEF_N.TEST_TYPE_1,
                :MQCGSMPDEF_N.TEST_TYPE_2,
                :MQCGSMPDEF_N.TEST_TYPE_3,
                :MQCGSMPDEF_N.TEST_TYPE_4,
                :MQCGSMPDEF_N.TEST_TYPE_5,
                :MQCGSMPDEF_N.QA_RUL_CMF_1,
                :MQCGSMPDEF_N.QA_RUL_CMF_2,
                :MQCGSMPDEF_N.QA_RUL_CMF_3,
                :MQCGSMPDEF_N.QA_RUL_CMF_4,
                :MQCGSMPDEF_N.QA_RUL_CMF_5,
                :MQCGSMPDEF_N.QA_RUL_CMF_6,
                :MQCGSMPDEF_N.QA_RUL_CMF_7,
                :MQCGSMPDEF_N.QA_RUL_CMF_8,
                :MQCGSMPDEF_N.QA_RUL_CMF_9,
                :MQCGSMPDEF_N.QA_RUL_CMF_10,
                :MQCGSMPDEF_N.CREATE_USER,
                :MQCGSMPDEF_N.CREATE_TIME,
                :MQCGSMPDEF_N.UPDATE_USER,
                :MQCGSMPDEF_N.UPDATE_TIME,
                :MQCGSMPDEF_N.RESV_FIELD_1,
                :MQCGSMPDEF_N.RESV_FIELD_2,
                :MQCGSMPDEF_N.RESV_FIELD_3,
                :MQCGSMPDEF_N.RESV_FIELD_4,
                :MQCGSMPDEF_N.RESV_FIELD_5,
                :MQCGSMPDEF_N.RESV_FIELD_6,
                :MQCGSMPDEF_N.RESV_FIELD_7,
                :MQCGSMPDEF_N.RESV_FIELD_8,
                :MQCGSMPDEF_N.RESV_FIELD_9,
                :MQCGSMPDEF_N.RESV_FIELD_10,
                :MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1184;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MQCGSMPDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCGSMPDEF_N.RULE_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MQCGSMPDEF_N.RULE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )51;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCGSMPDEF_N.SMP_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_TYPE);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MQCGSMPDEF_N.UNIT1_SMP_SIZE);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_TYPE);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_FORMULA);
            sqlstm.sqhstl[8] = (unsigned int  )201;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MQCGSMPDEF_N.UNIT1_SMP_SEL_LOC);
            sqlstm.sqhstl[9] = (unsigned int  )201;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MQCGSMPDEF_N.UNIT2_SMP_SIZE);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )11;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_FORMULA);
            sqlstm.sqhstl[14] = (unsigned int  )201;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MQCGSMPDEF_N.UNIT2_SMP_SEL_LOC);
            sqlstm.sqhstl[15] = (unsigned int  )201;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MQCGSMPDEF_N.LOT_SMP_FLAG);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MQCGSMPDEF_N.SKIP_CNT_BY_PASS);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MQCGSMPDEF_N.TST_CNT_BY_FAIL);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MQCGSMPDEF_N.TEST_COUNT);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_1);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_2);
            sqlstm.sqhstl[21] = (unsigned int  )11;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_3);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_4);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MQCGSMPDEF_N.TEST_TYPE_5);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MQCGSMPDEF_N.QA_RUL_CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MQCGSMPDEF_N.CREATE_USER);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MQCGSMPDEF_N.CREATE_TIME);
            sqlstm.sqhstl[36] = (unsigned int  )15;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MQCGSMPDEF_N.UPDATE_USER);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MQCGSMPDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[38] = (unsigned int  )15;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_1);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_2);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_3);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_4);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_5);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_6);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_7);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_8);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_9);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MQCGSMPDEF_N.RESV_FIELD_10);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MQCGSMPDEF_N.PASS_COUNT_FOR_SKIP);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
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
        DBC_del_null_mqcgsmpdef(&MQCGSMPDEF_N, MQCGSMPDEF);
    }
    DB_stop_query_timer("DBC_fetch_mqcgsmpdef", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mqcgsmpdef(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MQCGSMPDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1399;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL CLOSE DBC_MQCGSMPDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 52;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1414;
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
    DB_stop_query_timer("DBC_close_mqcgsmpdef", sel_type);
}


/* Initialize Function */
void DBC_init_mqcgsmpdef(struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
    /* memset by Space */
    memset(MQCGSMPDEF, ' ', sizeof(struct MQCGSMPDEF_TAG));
    
    MQCGSMPDEF->UNIT1_SMP_SIZE = 0;
    MQCGSMPDEF->UNIT2_SMP_SIZE = 0;
    MQCGSMPDEF->SKIP_CNT_BY_PASS = 0;
    MQCGSMPDEF->TST_CNT_BY_FAIL = 0;
    MQCGSMPDEF->TEST_COUNT = 0;
	MQCGSMPDEF->PASS_COUNT_FOR_SKIP = 0;
}


/* Add Null Function */
void DBC_add_null_mqcgsmpdef(struct MQCGSMPDEF_N_TAG *MQCGSMPDEF_N, struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
    /* memset by NULL */
    memset(MQCGSMPDEF_N, '\0', sizeof(struct MQCGSMPDEF_N_TAG));
    
    MEMCPY_AN(MQCGSMPDEF_N->FACTORY, MQCGSMPDEF->FACTORY, sizeof(MQCGSMPDEF->FACTORY));
    MEMCPY_AN(MQCGSMPDEF_N->RULE_ID, MQCGSMPDEF->RULE_ID, sizeof(MQCGSMPDEF->RULE_ID));
    MEMCPY_AN(MQCGSMPDEF_N->RULE_DESC, MQCGSMPDEF->RULE_DESC, sizeof(MQCGSMPDEF->RULE_DESC));
    MEMCPY_AN(MQCGSMPDEF_N->SMP_TYPE, MQCGSMPDEF->SMP_TYPE, sizeof(MQCGSMPDEF->SMP_TYPE));
    MQCGSMPDEF_N->UNIT1_SMP_FLAG[0] = MQCGSMPDEF->UNIT1_SMP_FLAG;
    MEMCPY_AN(MQCGSMPDEF_N->UNIT1_SMP_TYPE, MQCGSMPDEF->UNIT1_SMP_TYPE, sizeof(MQCGSMPDEF->UNIT1_SMP_TYPE));
    MQCGSMPDEF_N->UNIT1_SMP_SIZE = MQCGSMPDEF->UNIT1_SMP_SIZE;
    MEMCPY_AN(MQCGSMPDEF_N->UNIT1_SMP_SEL_TYPE, MQCGSMPDEF->UNIT1_SMP_SEL_TYPE, sizeof(MQCGSMPDEF->UNIT1_SMP_SEL_TYPE));
    MEMCPY_AN(MQCGSMPDEF_N->UNIT1_SMP_FORMULA, MQCGSMPDEF->UNIT1_SMP_FORMULA, sizeof(MQCGSMPDEF->UNIT1_SMP_FORMULA));
    MEMCPY_AN(MQCGSMPDEF_N->UNIT1_SMP_SEL_LOC, MQCGSMPDEF->UNIT1_SMP_SEL_LOC, sizeof(MQCGSMPDEF->UNIT1_SMP_SEL_LOC));
    MQCGSMPDEF_N->UNIT2_SMP_FLAG[0] = MQCGSMPDEF->UNIT2_SMP_FLAG;
    MEMCPY_AN(MQCGSMPDEF_N->UNIT2_SMP_TYPE, MQCGSMPDEF->UNIT2_SMP_TYPE, sizeof(MQCGSMPDEF->UNIT2_SMP_TYPE));
    MQCGSMPDEF_N->UNIT2_SMP_SIZE = MQCGSMPDEF->UNIT2_SMP_SIZE;
    MEMCPY_AN(MQCGSMPDEF_N->UNIT2_SMP_SEL_TYPE, MQCGSMPDEF->UNIT2_SMP_SEL_TYPE, sizeof(MQCGSMPDEF->UNIT2_SMP_SEL_TYPE));
    MEMCPY_AN(MQCGSMPDEF_N->UNIT2_SMP_FORMULA, MQCGSMPDEF->UNIT2_SMP_FORMULA, sizeof(MQCGSMPDEF->UNIT2_SMP_FORMULA));
    MEMCPY_AN(MQCGSMPDEF_N->UNIT2_SMP_SEL_LOC, MQCGSMPDEF->UNIT2_SMP_SEL_LOC, sizeof(MQCGSMPDEF->UNIT2_SMP_SEL_LOC));
    MQCGSMPDEF_N->LOT_SMP_FLAG[0] = MQCGSMPDEF->LOT_SMP_FLAG;
    MQCGSMPDEF_N->SKIP_CNT_BY_PASS = MQCGSMPDEF->SKIP_CNT_BY_PASS;
    MQCGSMPDEF_N->TST_CNT_BY_FAIL = MQCGSMPDEF->TST_CNT_BY_FAIL;
    MQCGSMPDEF_N->TEST_COUNT = MQCGSMPDEF->TEST_COUNT;
    MEMCPY_AN(MQCGSMPDEF_N->TEST_TYPE_1, MQCGSMPDEF->TEST_TYPE_1, sizeof(MQCGSMPDEF->TEST_TYPE_1));
    MEMCPY_AN(MQCGSMPDEF_N->TEST_TYPE_2, MQCGSMPDEF->TEST_TYPE_2, sizeof(MQCGSMPDEF->TEST_TYPE_2));
    MEMCPY_AN(MQCGSMPDEF_N->TEST_TYPE_3, MQCGSMPDEF->TEST_TYPE_3, sizeof(MQCGSMPDEF->TEST_TYPE_3));
    MEMCPY_AN(MQCGSMPDEF_N->TEST_TYPE_4, MQCGSMPDEF->TEST_TYPE_4, sizeof(MQCGSMPDEF->TEST_TYPE_4));
    MEMCPY_AN(MQCGSMPDEF_N->TEST_TYPE_5, MQCGSMPDEF->TEST_TYPE_5, sizeof(MQCGSMPDEF->TEST_TYPE_5));
    MEMCPY_AN(MQCGSMPDEF_N->QA_RUL_CMF_1, MQCGSMPDEF->QA_RUL_CMF_1, sizeof(MQCGSMPDEF->QA_RUL_CMF_1));
    MEMCPY_AN(MQCGSMPDEF_N->QA_RUL_CMF_2, MQCGSMPDEF->QA_RUL_CMF_2, sizeof(MQCGSMPDEF->QA_RUL_CMF_2));
    MEMCPY_AN(MQCGSMPDEF_N->QA_RUL_CMF_3, MQCGSMPDEF->QA_RUL_CMF_3, sizeof(MQCGSMPDEF->QA_RUL_CMF_3));
    MEMCPY_AN(MQCGSMPDEF_N->QA_RUL_CMF_4, MQCGSMPDEF->QA_RUL_CMF_4, sizeof(MQCGSMPDEF->QA_RUL_CMF_4));
    MEMCPY_AN(MQCGSMPDEF_N->QA_RUL_CMF_5, MQCGSMPDEF->QA_RUL_CMF_5, sizeof(MQCGSMPDEF->QA_RUL_CMF_5));
    MEMCPY_AN(MQCGSMPDEF_N->QA_RUL_CMF_6, MQCGSMPDEF->QA_RUL_CMF_6, sizeof(MQCGSMPDEF->QA_RUL_CMF_6));
    MEMCPY_AN(MQCGSMPDEF_N->QA_RUL_CMF_7, MQCGSMPDEF->QA_RUL_CMF_7, sizeof(MQCGSMPDEF->QA_RUL_CMF_7));
    MEMCPY_AN(MQCGSMPDEF_N->QA_RUL_CMF_8, MQCGSMPDEF->QA_RUL_CMF_8, sizeof(MQCGSMPDEF->QA_RUL_CMF_8));
    MEMCPY_AN(MQCGSMPDEF_N->QA_RUL_CMF_9, MQCGSMPDEF->QA_RUL_CMF_9, sizeof(MQCGSMPDEF->QA_RUL_CMF_9));
    MEMCPY_AN(MQCGSMPDEF_N->QA_RUL_CMF_10, MQCGSMPDEF->QA_RUL_CMF_10, sizeof(MQCGSMPDEF->QA_RUL_CMF_10));
    MEMCPY_AN(MQCGSMPDEF_N->CREATE_USER, MQCGSMPDEF->CREATE_USER, sizeof(MQCGSMPDEF->CREATE_USER));
    MEMCPY_AN(MQCGSMPDEF_N->CREATE_TIME, MQCGSMPDEF->CREATE_TIME, sizeof(MQCGSMPDEF->CREATE_TIME));
    MEMCPY_AN(MQCGSMPDEF_N->UPDATE_USER, MQCGSMPDEF->UPDATE_USER, sizeof(MQCGSMPDEF->UPDATE_USER));
    MEMCPY_AN(MQCGSMPDEF_N->UPDATE_TIME, MQCGSMPDEF->UPDATE_TIME, sizeof(MQCGSMPDEF->UPDATE_TIME));
    MEMCPY_AN(MQCGSMPDEF_N->RESV_FIELD_1, MQCGSMPDEF->RESV_FIELD_1, sizeof(MQCGSMPDEF->RESV_FIELD_1));
    MEMCPY_AN(MQCGSMPDEF_N->RESV_FIELD_2, MQCGSMPDEF->RESV_FIELD_2, sizeof(MQCGSMPDEF->RESV_FIELD_2));
    MEMCPY_AN(MQCGSMPDEF_N->RESV_FIELD_3, MQCGSMPDEF->RESV_FIELD_3, sizeof(MQCGSMPDEF->RESV_FIELD_3));
    MEMCPY_AN(MQCGSMPDEF_N->RESV_FIELD_4, MQCGSMPDEF->RESV_FIELD_4, sizeof(MQCGSMPDEF->RESV_FIELD_4));
    MEMCPY_AN(MQCGSMPDEF_N->RESV_FIELD_5, MQCGSMPDEF->RESV_FIELD_5, sizeof(MQCGSMPDEF->RESV_FIELD_5));
    MEMCPY_AN(MQCGSMPDEF_N->RESV_FIELD_6, MQCGSMPDEF->RESV_FIELD_6, sizeof(MQCGSMPDEF->RESV_FIELD_6));
    MEMCPY_AN(MQCGSMPDEF_N->RESV_FIELD_7, MQCGSMPDEF->RESV_FIELD_7, sizeof(MQCGSMPDEF->RESV_FIELD_7));
    MEMCPY_AN(MQCGSMPDEF_N->RESV_FIELD_8, MQCGSMPDEF->RESV_FIELD_8, sizeof(MQCGSMPDEF->RESV_FIELD_8));
    MEMCPY_AN(MQCGSMPDEF_N->RESV_FIELD_9, MQCGSMPDEF->RESV_FIELD_9, sizeof(MQCGSMPDEF->RESV_FIELD_9));
    MEMCPY_AN(MQCGSMPDEF_N->RESV_FIELD_10, MQCGSMPDEF->RESV_FIELD_10, sizeof(MQCGSMPDEF->RESV_FIELD_10));
	MQCGSMPDEF_N->PASS_COUNT_FOR_SKIP = MQCGSMPDEF->PASS_COUNT_FOR_SKIP;
}


/* Del Null Function */
void DBC_del_null_mqcgsmpdef(struct MQCGSMPDEF_N_TAG *MQCGSMPDEF_N, struct MQCGSMPDEF_TAG *MQCGSMPDEF)
{
    MEMCPY_DN(MQCGSMPDEF->FACTORY, MQCGSMPDEF_N->FACTORY, sizeof(MQCGSMPDEF->FACTORY));
    MEMCPY_DN(MQCGSMPDEF->RULE_ID, MQCGSMPDEF_N->RULE_ID, sizeof(MQCGSMPDEF->RULE_ID));
    MEMCPY_DN(MQCGSMPDEF->RULE_DESC, MQCGSMPDEF_N->RULE_DESC, sizeof(MQCGSMPDEF->RULE_DESC));
    MEMCPY_DN(MQCGSMPDEF->SMP_TYPE, MQCGSMPDEF_N->SMP_TYPE, sizeof(MQCGSMPDEF->SMP_TYPE));
    MQCGSMPDEF->UNIT1_SMP_FLAG = MQCGSMPDEF_N->UNIT1_SMP_FLAG[0];
    MEMCPY_DN(MQCGSMPDEF->UNIT1_SMP_TYPE, MQCGSMPDEF_N->UNIT1_SMP_TYPE, sizeof(MQCGSMPDEF->UNIT1_SMP_TYPE));
    MQCGSMPDEF->UNIT1_SMP_SIZE = MQCGSMPDEF_N->UNIT1_SMP_SIZE;
    MEMCPY_DN(MQCGSMPDEF->UNIT1_SMP_SEL_TYPE, MQCGSMPDEF_N->UNIT1_SMP_SEL_TYPE, sizeof(MQCGSMPDEF->UNIT1_SMP_SEL_TYPE));
    MEMCPY_DN(MQCGSMPDEF->UNIT1_SMP_FORMULA, MQCGSMPDEF_N->UNIT1_SMP_FORMULA, sizeof(MQCGSMPDEF->UNIT1_SMP_FORMULA));
    MEMCPY_DN(MQCGSMPDEF->UNIT1_SMP_SEL_LOC, MQCGSMPDEF_N->UNIT1_SMP_SEL_LOC, sizeof(MQCGSMPDEF->UNIT1_SMP_SEL_LOC));
    MQCGSMPDEF->UNIT2_SMP_FLAG = MQCGSMPDEF_N->UNIT2_SMP_FLAG[0];
    MEMCPY_DN(MQCGSMPDEF->UNIT2_SMP_TYPE, MQCGSMPDEF_N->UNIT2_SMP_TYPE, sizeof(MQCGSMPDEF->UNIT2_SMP_TYPE));
    MQCGSMPDEF->UNIT2_SMP_SIZE = MQCGSMPDEF_N->UNIT2_SMP_SIZE;
    MEMCPY_DN(MQCGSMPDEF->UNIT2_SMP_SEL_TYPE, MQCGSMPDEF_N->UNIT2_SMP_SEL_TYPE, sizeof(MQCGSMPDEF->UNIT2_SMP_SEL_TYPE));
    MEMCPY_DN(MQCGSMPDEF->UNIT2_SMP_FORMULA, MQCGSMPDEF_N->UNIT2_SMP_FORMULA, sizeof(MQCGSMPDEF->UNIT2_SMP_FORMULA));
    MEMCPY_DN(MQCGSMPDEF->UNIT2_SMP_SEL_LOC, MQCGSMPDEF_N->UNIT2_SMP_SEL_LOC, sizeof(MQCGSMPDEF->UNIT2_SMP_SEL_LOC));
    MQCGSMPDEF->LOT_SMP_FLAG = MQCGSMPDEF_N->LOT_SMP_FLAG[0];
    MQCGSMPDEF->SKIP_CNT_BY_PASS = MQCGSMPDEF_N->SKIP_CNT_BY_PASS;
    MQCGSMPDEF->TST_CNT_BY_FAIL = MQCGSMPDEF_N->TST_CNT_BY_FAIL;
    MQCGSMPDEF->TEST_COUNT = MQCGSMPDEF_N->TEST_COUNT;
    MEMCPY_DN(MQCGSMPDEF->TEST_TYPE_1, MQCGSMPDEF_N->TEST_TYPE_1, sizeof(MQCGSMPDEF->TEST_TYPE_1));
    MEMCPY_DN(MQCGSMPDEF->TEST_TYPE_2, MQCGSMPDEF_N->TEST_TYPE_2, sizeof(MQCGSMPDEF->TEST_TYPE_2));
    MEMCPY_DN(MQCGSMPDEF->TEST_TYPE_3, MQCGSMPDEF_N->TEST_TYPE_3, sizeof(MQCGSMPDEF->TEST_TYPE_3));
    MEMCPY_DN(MQCGSMPDEF->TEST_TYPE_4, MQCGSMPDEF_N->TEST_TYPE_4, sizeof(MQCGSMPDEF->TEST_TYPE_4));
    MEMCPY_DN(MQCGSMPDEF->TEST_TYPE_5, MQCGSMPDEF_N->TEST_TYPE_5, sizeof(MQCGSMPDEF->TEST_TYPE_5));
    MEMCPY_DN(MQCGSMPDEF->QA_RUL_CMF_1, MQCGSMPDEF_N->QA_RUL_CMF_1, sizeof(MQCGSMPDEF->QA_RUL_CMF_1));
    MEMCPY_DN(MQCGSMPDEF->QA_RUL_CMF_2, MQCGSMPDEF_N->QA_RUL_CMF_2, sizeof(MQCGSMPDEF->QA_RUL_CMF_2));
    MEMCPY_DN(MQCGSMPDEF->QA_RUL_CMF_3, MQCGSMPDEF_N->QA_RUL_CMF_3, sizeof(MQCGSMPDEF->QA_RUL_CMF_3));
    MEMCPY_DN(MQCGSMPDEF->QA_RUL_CMF_4, MQCGSMPDEF_N->QA_RUL_CMF_4, sizeof(MQCGSMPDEF->QA_RUL_CMF_4));
    MEMCPY_DN(MQCGSMPDEF->QA_RUL_CMF_5, MQCGSMPDEF_N->QA_RUL_CMF_5, sizeof(MQCGSMPDEF->QA_RUL_CMF_5));
    MEMCPY_DN(MQCGSMPDEF->QA_RUL_CMF_6, MQCGSMPDEF_N->QA_RUL_CMF_6, sizeof(MQCGSMPDEF->QA_RUL_CMF_6));
    MEMCPY_DN(MQCGSMPDEF->QA_RUL_CMF_7, MQCGSMPDEF_N->QA_RUL_CMF_7, sizeof(MQCGSMPDEF->QA_RUL_CMF_7));
    MEMCPY_DN(MQCGSMPDEF->QA_RUL_CMF_8, MQCGSMPDEF_N->QA_RUL_CMF_8, sizeof(MQCGSMPDEF->QA_RUL_CMF_8));
    MEMCPY_DN(MQCGSMPDEF->QA_RUL_CMF_9, MQCGSMPDEF_N->QA_RUL_CMF_9, sizeof(MQCGSMPDEF->QA_RUL_CMF_9));
    MEMCPY_DN(MQCGSMPDEF->QA_RUL_CMF_10, MQCGSMPDEF_N->QA_RUL_CMF_10, sizeof(MQCGSMPDEF->QA_RUL_CMF_10));
    MEMCPY_DN(MQCGSMPDEF->CREATE_USER, MQCGSMPDEF_N->CREATE_USER, sizeof(MQCGSMPDEF->CREATE_USER));
    MEMCPY_DN(MQCGSMPDEF->CREATE_TIME, MQCGSMPDEF_N->CREATE_TIME, sizeof(MQCGSMPDEF->CREATE_TIME));
    MEMCPY_DN(MQCGSMPDEF->UPDATE_USER, MQCGSMPDEF_N->UPDATE_USER, sizeof(MQCGSMPDEF->UPDATE_USER));
    MEMCPY_DN(MQCGSMPDEF->UPDATE_TIME, MQCGSMPDEF_N->UPDATE_TIME, sizeof(MQCGSMPDEF->UPDATE_TIME));
    MEMCPY_DN(MQCGSMPDEF->RESV_FIELD_1, MQCGSMPDEF_N->RESV_FIELD_1, sizeof(MQCGSMPDEF->RESV_FIELD_1));
    MEMCPY_DN(MQCGSMPDEF->RESV_FIELD_2, MQCGSMPDEF_N->RESV_FIELD_2, sizeof(MQCGSMPDEF->RESV_FIELD_2));
    MEMCPY_DN(MQCGSMPDEF->RESV_FIELD_3, MQCGSMPDEF_N->RESV_FIELD_3, sizeof(MQCGSMPDEF->RESV_FIELD_3));
    MEMCPY_DN(MQCGSMPDEF->RESV_FIELD_4, MQCGSMPDEF_N->RESV_FIELD_4, sizeof(MQCGSMPDEF->RESV_FIELD_4));
    MEMCPY_DN(MQCGSMPDEF->RESV_FIELD_5, MQCGSMPDEF_N->RESV_FIELD_5, sizeof(MQCGSMPDEF->RESV_FIELD_5));
    MEMCPY_DN(MQCGSMPDEF->RESV_FIELD_6, MQCGSMPDEF_N->RESV_FIELD_6, sizeof(MQCGSMPDEF->RESV_FIELD_6));
    MEMCPY_DN(MQCGSMPDEF->RESV_FIELD_7, MQCGSMPDEF_N->RESV_FIELD_7, sizeof(MQCGSMPDEF->RESV_FIELD_7));
    MEMCPY_DN(MQCGSMPDEF->RESV_FIELD_8, MQCGSMPDEF_N->RESV_FIELD_8, sizeof(MQCGSMPDEF->RESV_FIELD_8));
    MEMCPY_DN(MQCGSMPDEF->RESV_FIELD_9, MQCGSMPDEF_N->RESV_FIELD_9, sizeof(MQCGSMPDEF->RESV_FIELD_9));
    MEMCPY_DN(MQCGSMPDEF->RESV_FIELD_10, MQCGSMPDEF_N->RESV_FIELD_10, sizeof(MQCGSMPDEF->RESV_FIELD_10));
	MQCGSMPDEF->PASS_COUNT_FOR_SKIP = MQCGSMPDEF_N->PASS_COUNT_FOR_SKIP;
}


