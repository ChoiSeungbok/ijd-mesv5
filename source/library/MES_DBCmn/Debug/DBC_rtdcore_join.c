
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
           char  filnam[20];
};
static const struct sqlcxp sqlfpn =
{
    19,
    "DBC_rtdcore_join.pc"
};


static unsigned int sqlctx = 36589947;


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
            void  *sqhstv[64];
   unsigned int   sqhstl[64];
            int   sqhsts[64];
            void  *sqindv[64];
            int   sqinds[64];
   unsigned int   sqharm[64];
   unsigned int   *sqharc[64];
   unsigned short  sqadto[64];
   unsigned short  sqtdso[64];
} sqlstm = {13,64};

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

 static const char *sq0001 = 
"select A.LOT_ID ,A.LOT_DESC ,A.MAT_ID ,A.MAT_VER ,A.FLOW ,A.FLOW_SEQ_NUM ,A\
.OPER ,A.QTY_1 ,A.QTY_2 ,A.QTY_3 ,A.LOT_TYPE ,A.OWNER_CODE ,A.CREATE_CODE ,A.\
LOT_PRIORITY ,A.LOT_STATUS ,A.HOLD_FLAG ,A.RWK_FLAG ,A.NSTD_FLAG ,A.START_FLA\
G ,A.REP_FLAG ,A.ORG_DUE_TIME ,A.SCH_DUE_TIME ,A.OPER_IN_TIME ,A.LAST_TRAN_CO\
DE ,A.LAST_TRAN_TIME ,A.RESERVE_RES_ID  from MWIPLOTSTS A ,MRTDDSPOPR B where\
 (((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and B.DSP_ID=:b1) and A.OPER=B.O\
PER) and A.LOT_DEL_FLAG=' ') and (A.OPER>:b2 or (A.OPER=:b2 and A.LOT_ID>=:b4\
))) order by A.OPER,A.LOT_ID            ";

 static const char *sq0002 = 
"select LOT_ID ,LOT_DESC ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,QTY_1 ,\
QTY_2 ,QTY_3 ,LOT_TYPE ,OWNER_CODE ,CREATE_CODE ,LOT_PRIORITY ,LOT_STATUS ,HO\
LD_FLAG ,RWK_FLAG ,NSTD_FLAG ,START_FLAG ,REP_FLAG ,ORG_DUE_TIME ,SCH_DUE_TIM\
E ,OPER_IN_TIME ,LAST_TRAN_CODE ,LAST_TRAN_TIME ,RESERVE_RES_ID  from MWIPLOT\
STS where (((FACTORY=:b0 and OPER in (select distinct OPER  from MRASRESMFO w\
here (FACTORY=:b0 and RES_ID=:b2))) and LOT_DEL_FLAG=' ') and (OPER>:b3 or (O\
PER=:b3 and LOT_ID>=:b5))) order by OPER,LOT_ID            ";

 static const char *sq0003 = 
"select A.RES_ID ,A.RES_DESC ,A.RES_TYPE ,A.AREA_ID ,A.SUB_AREA_ID ,A.RES_UP\
_DOWN_FLAG ,A.RES_PRI_STS ,A.LAST_START_TIME ,A.LAST_END_TIME ,A.LAST_EVENT_I\
D ,A.LAST_EVENT_TIME  from MRASRESDEF A ,MRTDDSPRES B where (((((A.FACTORY=:b\
0 and A.FACTORY=B.FACTORY) and B.DSP_ID=:b1) and A.RES_ID=B.RES_ID) and A.DEL\
ETE_FLAG=' ') and B.RES_ID>=:b2) order by A.RES_ID            ";

 static const char *sq0004 = 
"select RES_ID ,RES_DESC ,RES_TYPE ,AREA_ID ,SUB_AREA_ID ,RES_UP_DOWN_FLAG ,\
RES_PRI_STS ,LAST_START_TIME ,LAST_END_TIME ,LAST_EVENT_ID ,LAST_EVENT_TIME  \
from MRASRESDEF where (((FACTORY=:b0 and RES_ID in (select distinct RES_ID  f\
rom MRASRESMFO where ((((FACTORY=:b0 and MAT_ID=:b2) and MAT_VER=:b3) and FLO\
W=:b4) and OPER=:b5))) and DELETE_FLAG=' ') and RES_ID>=:b6) order by RES_ID \
           ";

 static const char *sq0006 = 
"FACTORY=:b0 and RS.LOT_ID=WL.LOT_ID)\
 and RS.RES_OPER_FLAG=:b1) and RS.RES_OPER_ID=:b2) and ((RS.REFERENCE_OPER=' \
' and WL.LOT_STATUS='WAIT') or RS.REFERENCE_OPER<>' ')) and WL.HOLD_FLAG<>'Y'\
) and WL.QTY_1>=0.00009) order by RS.PRIORITY_SCORE desc ,RS.LOT_ID asc      \
       ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,577,0,9,60,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,0,0,0,1,97,0,0,
40,0,0,2,519,0,9,79,0,0,6,6,0,1,0,1,97,0,0,1,0,0,0,1,97,0,0,1,97,0,0,1,0,0,0,1,
97,0,0,
79,0,0,1,0,0,13,106,0,0,26,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,
198,0,0,2,0,0,13,135,0,0,26,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,
317,0,0,1,0,0,15,189,0,0,0,0,0,1,0,
332,0,0,2,0,0,15,192,0,0,0,0,0,1,0,
347,0,0,3,368,0,9,319,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
374,0,0,4,394,0,9,341,0,0,7,7,0,1,0,1,97,0,0,1,0,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,
417,0,0,3,0,0,13,368,0,0,11,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
476,0,0,4,0,0,13,382,0,0,11,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
535,0,0,3,0,0,15,420,0,0,0,0,0,1,0,
550,0,0,4,0,0,15,424,0,0,0,0,0,1,0,
565,0,0,5,0,0,17,592,0,0,1,1,0,1,0,1,97,0,0,
584,0,0,5,0,0,45,594,0,0,0,0,0,1,0,
599,0,0,6,1298,0,9,655,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
626,0,0,5,0,0,17,734,0,0,1,1,0,1,0,1,97,0,0,
645,0,0,5,0,0,45,736,0,0,0,0,0,1,0,
660,0,0,5,0,0,13,763,0,0,64,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
931,0,0,6,0,0,13,831,0,0,64,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1202,0,0,5,0,0,13,899,0,0,64,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1473,0,0,5,0,0,15,992,0,0,0,0,0,1,0,
1488,0,0,6,0,0,15,996,0,0,0,0,0,1,0,
1503,0,0,5,0,0,15,1000,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_rtdcore_join.pc
**    Description : Table Access Function Source File
**    Create date : 2004/12/01 16:36:50
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

/* Direct View ���� */
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
void DBC_add_null_dsp_lotlist(struct DSP_LOTLIST_N_TAG *DSP_LOTLIST_N, struct DSP_LOTLIST_TAG *DSP_LOTLIST);
void DBC_del_null_dsp_lotlist(struct DSP_LOTLIST_N_TAG *DSP_LOTLIST_N, struct DSP_LOTLIST_TAG *DSP_LOTLIST);
void DBC_add_null_dsp_reslist(struct DSP_RESLIST_N_TAG *DSP_RESLIST_N, struct DSP_RESLIST_TAG *DSP_RESLIST);
void DBC_del_null_dsp_reslist(struct DSP_RESLIST_N_TAG *DSP_RESLIST_N, struct DSP_RESLIST_TAG *DSP_RESLIST);
void DBC_add_null_lotpds_list(struct LOTPDS_LIST_N_TAG *LOTPDS_LIST_N, struct LOTPDS_LIST_TAG *LOTPDS_LIST);
void DBC_del_null_lotpds_list(struct LOTPDS_LIST_N_TAG *LOTPDS_LIST_N, struct LOTPDS_LIST_TAG *LOTPDS_LIST);

/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_dsp_lotlist(int sel_type, struct DSP_LOTLIST_TAG *DSP_LOTLIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct DSP_LOTLIST_N_TAG DSP_LOTLIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_dsp_lotlist(&DSP_LOTLIST_N, DSP_LOTLIST);
    DB_error_code = 0;

    switch(sel_type)
    {
         case 1:
            /* EXEC SQL DECLARE DBC_DSP_LOTLIST_CUR_1 CURSOR FOR
                SELECT A.LOT_ID, A.LOT_DESC, A.MAT_ID, A.MAT_VER, A.FLOW, A.FLOW_SEQ_NUM, A.OPER, A.QTY_1, A.QTY_2, A.QTY_3, A.LOT_TYPE,
                       A.OWNER_CODE, A.CREATE_CODE, A.LOT_PRIORITY, A.LOT_STATUS, A.HOLD_FLAG, A.RWK_FLAG,
                       A.NSTD_FLAG, A.START_FLAG, A.REP_FLAG, A.ORG_DUE_TIME, A.SCH_DUE_TIME, A.OPER_IN_TIME, A.LAST_TRAN_CODE, 
                       A.LAST_TRAN_TIME, A.RESERVE_RES_ID
                FROM MWIPLOTSTS A, MRTDDSPOPR B
                WHERE A.FACTORY = :DSP_LOTLIST_N.FACTORY
                    AND      A.FACTORY = B.FACTORY
                    AND      B.DSP_ID = :DSP_LOTLIST_N.DSP_ID
                    AND      A.OPER = B.OPER
                    AND   A.LOT_DEL_FLAG = ' '
                    AND (A.OPER > :DSP_LOTLIST_N.OPER OR (A.OPER = :DSP_LOTLIST_N.OPER AND A.LOT_ID >= :DSP_LOTLIST_N.LOT_ID)) 
                ORDER BY A.OPER,A.LOT_ID; */ 

            /* EXEC SQL OPEN DBC_DSP_LOTLIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 5;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0001;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(DSP_LOTLIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(DSP_LOTLIST_N.DSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(DSP_LOTLIST_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(DSP_LOTLIST_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DSP_LOTLIST_N.LOT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
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

         case 2:
            /* EXEC SQL DECLARE DBC_DSP_LOTLIST_CUR_2 CURSOR FOR
                SELECT LOT_ID, LOT_DESC, MAT_ID, MAT_VER, FLOW, FLOW_SEQ_NUM, OPER, QTY_1, QTY_2, QTY_3, LOT_TYPE,
                       OWNER_CODE, CREATE_CODE, LOT_PRIORITY, LOT_STATUS, HOLD_FLAG, RWK_FLAG,
                       NSTD_FLAG, START_FLAG, REP_FLAG, ORG_DUE_TIME, SCH_DUE_TIME, OPER_IN_TIME, LAST_TRAN_CODE,
                       LAST_TRAN_TIME, RESERVE_RES_ID
                FROM MWIPLOTSTS
                WHERE FACTORY = :DSP_LOTLIST_N.FACTORY
                    AND    OPER IN (
                        SELECT DISTINCT OPER FROM MRASRESMFO WHERE
                            FACTORY = :DSP_LOTLIST_N.FACTORY
                        AND    RES_ID = :DSP_LOTLIST_N.RES_ID
                        )
                    AND LOT_DEL_FLAG = ' '
                    AND (OPER > :DSP_LOTLIST_N.OPER OR (OPER = :DSP_LOTLIST_N.OPER AND LOT_ID >= :DSP_LOTLIST_N.LOT_ID)) 
                ORDER BY OPER, LOT_ID; */ 

            /* EXEC SQL OPEN DBC_DSP_LOTLIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 6;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0002;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )40;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(DSP_LOTLIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(DSP_LOTLIST_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(DSP_LOTLIST_N.RES_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(DSP_LOTLIST_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DSP_LOTLIST_N.OPER);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(DSP_LOTLIST_N.LOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_open_dsp_lotlist", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_dsp_lotlist(int sel_type, struct DSP_LOTLIST_TAG *DSP_LOTLIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct DSP_LOTLIST_N_TAG DSP_LOTLIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_DSP_LOTLIST_CUR_1 INTO :DSP_LOTLIST_N.LOT_ID,
                                                      :DSP_LOTLIST_N.LOT_DESC,
                                                      :DSP_LOTLIST_N.MAT_ID,
                                                      :DSP_LOTLIST_N.MAT_VER,
                                                      :DSP_LOTLIST_N.FLOW,
                                                      :DSP_LOTLIST_N.FLOW_SEQ_NUM,
                                                      :DSP_LOTLIST_N.OPER,
                                                      :DSP_LOTLIST_N.QTY_1,
                                                      :DSP_LOTLIST_N.QTY_2,
                                                      :DSP_LOTLIST_N.QTY_3,
                                                      :DSP_LOTLIST_N.LOT_TYPE,
                                                      :DSP_LOTLIST_N.OWNER_CODE,
                                                      :DSP_LOTLIST_N.CREATE_CODE,
                                                      :DSP_LOTLIST_N.LOT_PRIORITY,
                                                      :DSP_LOTLIST_N.LOT_STATUS,
                                                      :DSP_LOTLIST_N.HOLD_FLAG,
                                                      :DSP_LOTLIST_N.RWK_FLAG,
                                                      :DSP_LOTLIST_N.NSTD_FLAG,
                                                      :DSP_LOTLIST_N.START_FLAG,
                                                      :DSP_LOTLIST_N.REP_FLAG,
                                                      :DSP_LOTLIST_N.ORG_DUE_TIME,
                                                      :DSP_LOTLIST_N.SCH_DUE_TIME,
                                                      :DSP_LOTLIST_N.OPER_IN_TIME,
                                                      :DSP_LOTLIST_N.LAST_TRAN_CODE,
                                                      :DSP_LOTLIST_N.LAST_TRAN_TIME,
                                                      :DSP_LOTLIST_N.RESERVE_RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )79;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(DSP_LOTLIST_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(DSP_LOTLIST_N.LOT_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(DSP_LOTLIST_N.MAT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(DSP_LOTLIST_N.MAT_VER);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DSP_LOTLIST_N.FLOW);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(DSP_LOTLIST_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(DSP_LOTLIST_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(DSP_LOTLIST_N.QTY_1);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(DSP_LOTLIST_N.QTY_2);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(DSP_LOTLIST_N.QTY_3);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(DSP_LOTLIST_N.LOT_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(DSP_LOTLIST_N.OWNER_CODE);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(DSP_LOTLIST_N.CREATE_CODE);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(DSP_LOTLIST_N.LOT_PRIORITY);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(DSP_LOTLIST_N.LOT_STATUS);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(DSP_LOTLIST_N.HOLD_FLAG);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(DSP_LOTLIST_N.RWK_FLAG);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(DSP_LOTLIST_N.NSTD_FLAG);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(DSP_LOTLIST_N.START_FLAG);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(DSP_LOTLIST_N.REP_FLAG);
            sqlstm.sqhstl[19] = (unsigned int  )2;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(DSP_LOTLIST_N.ORG_DUE_TIME);
            sqlstm.sqhstl[20] = (unsigned int  )15;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(DSP_LOTLIST_N.SCH_DUE_TIME);
            sqlstm.sqhstl[21] = (unsigned int  )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(DSP_LOTLIST_N.OPER_IN_TIME);
            sqlstm.sqhstl[22] = (unsigned int  )15;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(DSP_LOTLIST_N.LAST_TRAN_CODE);
            sqlstm.sqhstl[23] = (unsigned int  )13;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(DSP_LOTLIST_N.LAST_TRAN_TIME);
            sqlstm.sqhstl[24] = (unsigned int  )15;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(DSP_LOTLIST_N.RESERVE_RES_ID);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_DSP_LOTLIST_CUR_2 INTO :DSP_LOTLIST_N.LOT_ID,
                                                      :DSP_LOTLIST_N.LOT_DESC,
                                                      :DSP_LOTLIST_N.MAT_ID,
                                                      :DSP_LOTLIST_N.MAT_VER,
                                                      :DSP_LOTLIST_N.FLOW,
                                                      :DSP_LOTLIST_N.FLOW_SEQ_NUM,
                                                      :DSP_LOTLIST_N.OPER,
                                                      :DSP_LOTLIST_N.QTY_1,
                                                      :DSP_LOTLIST_N.QTY_2,
                                                      :DSP_LOTLIST_N.QTY_3,
                                                      :DSP_LOTLIST_N.LOT_TYPE,
                                                      :DSP_LOTLIST_N.OWNER_CODE,
                                                      :DSP_LOTLIST_N.CREATE_CODE,
                                                      :DSP_LOTLIST_N.LOT_PRIORITY,
                                                      :DSP_LOTLIST_N.LOT_STATUS,
                                                      :DSP_LOTLIST_N.HOLD_FLAG,
                                                      :DSP_LOTLIST_N.RWK_FLAG,
                                                      :DSP_LOTLIST_N.NSTD_FLAG,
                                                      :DSP_LOTLIST_N.START_FLAG,
                                                      :DSP_LOTLIST_N.REP_FLAG,
                                                      :DSP_LOTLIST_N.ORG_DUE_TIME,
                                                      :DSP_LOTLIST_N.SCH_DUE_TIME,
                                                      :DSP_LOTLIST_N.OPER_IN_TIME,
                                                      :DSP_LOTLIST_N.LAST_TRAN_CODE,
                                                      :DSP_LOTLIST_N.LAST_TRAN_TIME,
                                                      :DSP_LOTLIST_N.RESERVE_RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )198;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(DSP_LOTLIST_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(DSP_LOTLIST_N.LOT_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(DSP_LOTLIST_N.MAT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(DSP_LOTLIST_N.MAT_VER);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DSP_LOTLIST_N.FLOW);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(DSP_LOTLIST_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(DSP_LOTLIST_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(DSP_LOTLIST_N.QTY_1);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(DSP_LOTLIST_N.QTY_2);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(DSP_LOTLIST_N.QTY_3);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(DSP_LOTLIST_N.LOT_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(DSP_LOTLIST_N.OWNER_CODE);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(DSP_LOTLIST_N.CREATE_CODE);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(DSP_LOTLIST_N.LOT_PRIORITY);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(DSP_LOTLIST_N.LOT_STATUS);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(DSP_LOTLIST_N.HOLD_FLAG);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(DSP_LOTLIST_N.RWK_FLAG);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(DSP_LOTLIST_N.NSTD_FLAG);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(DSP_LOTLIST_N.START_FLAG);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(DSP_LOTLIST_N.REP_FLAG);
            sqlstm.sqhstl[19] = (unsigned int  )2;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(DSP_LOTLIST_N.ORG_DUE_TIME);
            sqlstm.sqhstl[20] = (unsigned int  )15;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(DSP_LOTLIST_N.SCH_DUE_TIME);
            sqlstm.sqhstl[21] = (unsigned int  )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(DSP_LOTLIST_N.OPER_IN_TIME);
            sqlstm.sqhstl[22] = (unsigned int  )15;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(DSP_LOTLIST_N.LAST_TRAN_CODE);
            sqlstm.sqhstl[23] = (unsigned int  )13;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(DSP_LOTLIST_N.LAST_TRAN_TIME);
            sqlstm.sqhstl[24] = (unsigned int  )15;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(DSP_LOTLIST_N.RESERVE_RES_ID);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
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
        DBC_del_null_dsp_lotlist(&DSP_LOTLIST_N, DSP_LOTLIST);
    }
    DB_stop_query_timer("DBC_fetch_dsp_lotlist", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_dsp_lotlist(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_DSP_LOTLIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )317;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 2:
            /* EXEC SQL CLOSE DBC_DSP_LOTLIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )332;
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
    DB_stop_query_timer("DBC_close_dsp_lotlist", sel_type);
}

/* Initialize Function */
void DBC_init_dsp_lotlist(struct DSP_LOTLIST_TAG *DSP_LOTLIST)
{
    /* memset by Space */
    memset(DSP_LOTLIST, ' ', sizeof(struct DSP_LOTLIST_TAG));
    
    DSP_LOTLIST->QTY_1 = 0;
    DSP_LOTLIST->QTY_2 = 0;
    DSP_LOTLIST->QTY_3 = 0;
}


/* Add Null Function */
void DBC_add_null_dsp_lotlist(struct DSP_LOTLIST_N_TAG *DSP_LOTLIST_N, struct DSP_LOTLIST_TAG *DSP_LOTLIST)
{
    /* memset by NULL */
    memset(DSP_LOTLIST_N, '\0', sizeof(struct DSP_LOTLIST_N_TAG));
    
    MEMCPY_AN(DSP_LOTLIST_N->FACTORY, DSP_LOTLIST->FACTORY, sizeof(DSP_LOTLIST->FACTORY));
    MEMCPY_AN(DSP_LOTLIST_N->DSP_ID, DSP_LOTLIST->DSP_ID, sizeof(DSP_LOTLIST->DSP_ID));
    MEMCPY_AN(DSP_LOTLIST_N->RES_ID, DSP_LOTLIST->RES_ID, sizeof(DSP_LOTLIST->RES_ID));
    MEMCPY_AN(DSP_LOTLIST_N->LOT_ID, DSP_LOTLIST->LOT_ID, sizeof(DSP_LOTLIST->LOT_ID));
    MEMCPY_AN(DSP_LOTLIST_N->LOT_DESC, DSP_LOTLIST->LOT_DESC, sizeof(DSP_LOTLIST->LOT_DESC));
    MEMCPY_AN(DSP_LOTLIST_N->MAT_ID, DSP_LOTLIST->MAT_ID, sizeof(DSP_LOTLIST->MAT_ID));
    DSP_LOTLIST_N->MAT_VER = DSP_LOTLIST->MAT_VER;  
    MEMCPY_AN(DSP_LOTLIST_N->FLOW, DSP_LOTLIST->FLOW, sizeof(DSP_LOTLIST->FLOW));
    DSP_LOTLIST_N->FLOW_SEQ_NUM = DSP_LOTLIST->FLOW_SEQ_NUM;      
    MEMCPY_AN(DSP_LOTLIST_N->OPER, DSP_LOTLIST->OPER, sizeof(DSP_LOTLIST->OPER));
    DSP_LOTLIST_N->QTY_1 = DSP_LOTLIST->QTY_1;
    DSP_LOTLIST_N->QTY_2 = DSP_LOTLIST->QTY_2;
    DSP_LOTLIST_N->QTY_3 = DSP_LOTLIST->QTY_3;
    DSP_LOTLIST_N->LOT_TYPE[0] = DSP_LOTLIST->LOT_TYPE;
    MEMCPY_AN(DSP_LOTLIST_N->OWNER_CODE, DSP_LOTLIST->OWNER_CODE, sizeof(DSP_LOTLIST->OWNER_CODE));
    MEMCPY_AN(DSP_LOTLIST_N->CREATE_CODE, DSP_LOTLIST->CREATE_CODE, sizeof(DSP_LOTLIST->CREATE_CODE));
    DSP_LOTLIST_N->LOT_PRIORITY[0] = DSP_LOTLIST->LOT_PRIORITY;
    MEMCPY_AN(DSP_LOTLIST_N->LOT_STATUS, DSP_LOTLIST->LOT_STATUS, sizeof(DSP_LOTLIST->LOT_STATUS));
    DSP_LOTLIST_N->HOLD_FLAG[0] = DSP_LOTLIST->HOLD_FLAG;
    DSP_LOTLIST_N->RWK_FLAG[0] = DSP_LOTLIST->RWK_FLAG;
    DSP_LOTLIST_N->NSTD_FLAG[0] = DSP_LOTLIST->NSTD_FLAG;
    DSP_LOTLIST_N->START_FLAG[0] = DSP_LOTLIST->START_FLAG;
    DSP_LOTLIST_N->REP_FLAG[0] = DSP_LOTLIST->REP_FLAG;
    MEMCPY_AN(DSP_LOTLIST_N->ORG_DUE_TIME, DSP_LOTLIST->ORG_DUE_TIME, sizeof(DSP_LOTLIST->ORG_DUE_TIME));
    MEMCPY_AN(DSP_LOTLIST_N->SCH_DUE_TIME, DSP_LOTLIST->SCH_DUE_TIME, sizeof(DSP_LOTLIST->SCH_DUE_TIME));
    MEMCPY_AN(DSP_LOTLIST_N->OPER_IN_TIME, DSP_LOTLIST->OPER_IN_TIME, sizeof(DSP_LOTLIST->OPER_IN_TIME));
    MEMCPY_AN(DSP_LOTLIST_N->LAST_TRAN_CODE, DSP_LOTLIST->LAST_TRAN_CODE, sizeof(DSP_LOTLIST->LAST_TRAN_CODE));
    MEMCPY_AN(DSP_LOTLIST_N->RECIPE, DSP_LOTLIST->RECIPE, sizeof(DSP_LOTLIST->RECIPE));
    MEMCPY_AN(DSP_LOTLIST_N->LAST_TRAN_TIME, DSP_LOTLIST->LAST_TRAN_TIME, sizeof(DSP_LOTLIST->LAST_TRAN_TIME));
    MEMCPY_AN(DSP_LOTLIST_N->RESERVE_RES_ID, DSP_LOTLIST->RESERVE_RES_ID, sizeof(DSP_LOTLIST->RESERVE_RES_ID));
}


/* Del Null Function */
void DBC_del_null_dsp_lotlist(struct DSP_LOTLIST_N_TAG *DSP_LOTLIST_N, struct DSP_LOTLIST_TAG *DSP_LOTLIST)
{
    MEMCPY_DN(DSP_LOTLIST->FACTORY, DSP_LOTLIST_N->FACTORY, sizeof(DSP_LOTLIST->FACTORY));
    MEMCPY_DN(DSP_LOTLIST->DSP_ID, DSP_LOTLIST_N->DSP_ID, sizeof(DSP_LOTLIST->DSP_ID));
    MEMCPY_DN(DSP_LOTLIST->RES_ID, DSP_LOTLIST_N->RES_ID, sizeof(DSP_LOTLIST->RES_ID));
    MEMCPY_DN(DSP_LOTLIST->LOT_ID, DSP_LOTLIST_N->LOT_ID, sizeof(DSP_LOTLIST->LOT_ID));
    MEMCPY_DN(DSP_LOTLIST->LOT_DESC, DSP_LOTLIST_N->LOT_DESC, sizeof(DSP_LOTLIST->LOT_DESC));
    MEMCPY_DN(DSP_LOTLIST->MAT_ID, DSP_LOTLIST_N->MAT_ID, sizeof(DSP_LOTLIST->MAT_ID));
    DSP_LOTLIST->MAT_VER = DSP_LOTLIST_N->MAT_VER;
    MEMCPY_DN(DSP_LOTLIST->FLOW, DSP_LOTLIST_N->FLOW, sizeof(DSP_LOTLIST->FLOW));
    DSP_LOTLIST->FLOW_SEQ_NUM = DSP_LOTLIST_N->FLOW_SEQ_NUM;
    MEMCPY_DN(DSP_LOTLIST->OPER, DSP_LOTLIST_N->OPER, sizeof(DSP_LOTLIST->OPER));
    DSP_LOTLIST->QTY_1 = DSP_LOTLIST_N->QTY_1;
    DSP_LOTLIST->QTY_2 = DSP_LOTLIST_N->QTY_2;
    DSP_LOTLIST->QTY_3 = DSP_LOTLIST_N->QTY_3;
    DSP_LOTLIST->LOT_TYPE = DSP_LOTLIST_N->LOT_TYPE[0];
    MEMCPY_DN(DSP_LOTLIST->OWNER_CODE, DSP_LOTLIST_N->OWNER_CODE, sizeof(DSP_LOTLIST->OWNER_CODE));
    MEMCPY_DN(DSP_LOTLIST->CREATE_CODE, DSP_LOTLIST_N->CREATE_CODE, sizeof(DSP_LOTLIST->CREATE_CODE));
    DSP_LOTLIST->LOT_PRIORITY = DSP_LOTLIST_N->LOT_PRIORITY[0];
    MEMCPY_DN(DSP_LOTLIST->LOT_STATUS, DSP_LOTLIST_N->LOT_STATUS, sizeof(DSP_LOTLIST->LOT_STATUS));
    DSP_LOTLIST->HOLD_FLAG = DSP_LOTLIST_N->HOLD_FLAG[0];
    DSP_LOTLIST->RWK_FLAG = DSP_LOTLIST_N->RWK_FLAG[0];
    DSP_LOTLIST->NSTD_FLAG = DSP_LOTLIST_N->NSTD_FLAG[0];
    DSP_LOTLIST->START_FLAG = DSP_LOTLIST_N->START_FLAG[0];
    DSP_LOTLIST->REP_FLAG = DSP_LOTLIST_N->REP_FLAG[0];
    MEMCPY_DN(DSP_LOTLIST->ORG_DUE_TIME, DSP_LOTLIST_N->ORG_DUE_TIME, sizeof(DSP_LOTLIST->ORG_DUE_TIME));
    MEMCPY_DN(DSP_LOTLIST->SCH_DUE_TIME, DSP_LOTLIST_N->SCH_DUE_TIME, sizeof(DSP_LOTLIST->SCH_DUE_TIME));
    MEMCPY_DN(DSP_LOTLIST->OPER_IN_TIME, DSP_LOTLIST_N->OPER_IN_TIME, sizeof(DSP_LOTLIST->OPER_IN_TIME));
    MEMCPY_DN(DSP_LOTLIST->LAST_TRAN_CODE, DSP_LOTLIST_N->LAST_TRAN_CODE, sizeof(DSP_LOTLIST->LAST_TRAN_CODE));
    MEMCPY_DN(DSP_LOTLIST->RECIPE, DSP_LOTLIST_N->RECIPE, sizeof(DSP_LOTLIST->RECIPE));
    MEMCPY_DN(DSP_LOTLIST->LAST_TRAN_TIME, DSP_LOTLIST_N->LAST_TRAN_TIME, sizeof(DSP_LOTLIST->LAST_TRAN_TIME));
    MEMCPY_DN(DSP_LOTLIST->RESERVE_RES_ID, DSP_LOTLIST_N->RESERVE_RES_ID, sizeof(DSP_LOTLIST->RESERVE_RES_ID));
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_dsp_reslist(int sel_type, struct DSP_RESLIST_TAG *DSP_RESLIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct DSP_RESLIST_N_TAG DSP_RESLIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_dsp_reslist(&DSP_RESLIST_N, DSP_RESLIST);
    DB_error_code = 0;

    switch(sel_type)
    {
         case 1:
            /* EXEC SQL DECLARE DBC_DSP_RESLIST_CUR_1 CURSOR FOR
                SELECT A.RES_ID, A.RES_DESC, A.RES_TYPE, A.AREA_ID, A.SUB_AREA_ID, A.RES_UP_DOWN_FLAG, A.RES_PRI_STS, 
                       A.LAST_START_TIME, A.LAST_END_TIME, A.LAST_EVENT_ID, A.LAST_EVENT_TIME
                FROM MRASRESDEF A, MRTDDSPRES B
                 WHERE A.FACTORY = :DSP_RESLIST_N.FACTORY
                    AND A.FACTORY = B.FACTORY
                    AND B.DSP_ID = :DSP_RESLIST_N.DSP_ID
                    AND A.RES_ID = B.RES_ID 
                    AND A.DELETE_FLAG = ' ' 
                    AND B.RES_ID >= :DSP_RESLIST_N.RES_ID
                ORDER BY A.RES_ID; */ 


            /* EXEC SQL OPEN DBC_DSP_RESLIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0003;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )347;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(DSP_RESLIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(DSP_RESLIST_N.DSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(DSP_RESLIST_N.RES_ID);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

         case 2:
            /* EXEC SQL DECLARE DBC_DSP_RESLIST_CUR_2 CURSOR FOR
                SELECT RES_ID, RES_DESC, RES_TYPE, AREA_ID, SUB_AREA_ID, RES_UP_DOWN_FLAG, 
                       RES_PRI_STS, LAST_START_TIME, LAST_END_TIME, LAST_EVENT_ID, LAST_EVENT_TIME
                FROM MRASRESDEF
                 WHERE FACTORY = :DSP_RESLIST_N.FACTORY
                    AND RES_ID IN (
                        SELECT DISTINCT RES_ID 
                        FROM MRASRESMFO 
                        WHERE FACTORY = :DSP_RESLIST_N.FACTORY
                            AND MAT_ID = :DSP_RESLIST_N.MAT_ID
                            AND MAT_VER = :DSP_RESLIST_N.MAT_VER
                            AND FLOW = :DSP_RESLIST_N.FLOW
                            AND OPER = :DSP_RESLIST_N.OPER
                        )
                    AND DELETE_FLAG = ' ' 
                    AND RES_ID >= :DSP_RESLIST_N.RES_ID
                ORDER BY RES_ID; */ 


            /* EXEC SQL OPEN DBC_DSP_RESLIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0004;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )374;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(DSP_RESLIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(DSP_RESLIST_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(DSP_RESLIST_N.MAT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(DSP_RESLIST_N.MAT_VER);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DSP_RESLIST_N.FLOW);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(DSP_RESLIST_N.OPER);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(DSP_RESLIST_N.RES_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
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
    DB_stop_query_timer("DBC_open_dsp_reslist", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_dsp_reslist(int sel_type, struct DSP_RESLIST_TAG *DSP_RESLIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct DSP_RESLIST_N_TAG DSP_RESLIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_DSP_RESLIST_CUR_1 INTO :DSP_RESLIST_N.RES_ID,
                                                      :DSP_RESLIST_N.RES_DESC,
                                                      :DSP_RESLIST_N.RES_TYPE,
                                                      :DSP_RESLIST_N.AREA_ID,
                                                      :DSP_RESLIST_N.SUB_AREA_ID,
                                                      :DSP_RESLIST_N.RES_UP_DOWN_FLAG,
                                                      :DSP_RESLIST_N.RES_PRI_STS,
                                                      :DSP_RESLIST_N.LAST_START_TIME,
                                                      :DSP_RESLIST_N.LAST_END_TIME,
                                                      :DSP_RESLIST_N.LAST_EVENT_ID,
                                                      :DSP_RESLIST_N.LAST_EVENT_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )417;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(DSP_RESLIST_N.RES_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(DSP_RESLIST_N.RES_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )51;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(DSP_RESLIST_N.RES_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(DSP_RESLIST_N.AREA_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DSP_RESLIST_N.SUB_AREA_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(DSP_RESLIST_N.RES_UP_DOWN_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(DSP_RESLIST_N.RES_PRI_STS);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(DSP_RESLIST_N.LAST_START_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(DSP_RESLIST_N.LAST_END_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(DSP_RESLIST_N.LAST_EVENT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )13;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(DSP_RESLIST_N.LAST_EVENT_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_DSP_RESLIST_CUR_2 INTO :DSP_RESLIST_N.RES_ID,
                                                      :DSP_RESLIST_N.RES_DESC,
                                                      :DSP_RESLIST_N.RES_TYPE,
                                                      :DSP_RESLIST_N.AREA_ID,
                                                      :DSP_RESLIST_N.SUB_AREA_ID,
                                                      :DSP_RESLIST_N.RES_UP_DOWN_FLAG,
                                                      :DSP_RESLIST_N.RES_PRI_STS,
                                                      :DSP_RESLIST_N.LAST_START_TIME,
                                                      :DSP_RESLIST_N.LAST_END_TIME,
                                                      :DSP_RESLIST_N.LAST_EVENT_ID,
                                                      :DSP_RESLIST_N.LAST_EVENT_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )476;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(DSP_RESLIST_N.RES_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(DSP_RESLIST_N.RES_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )51;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(DSP_RESLIST_N.RES_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(DSP_RESLIST_N.AREA_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DSP_RESLIST_N.SUB_AREA_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(DSP_RESLIST_N.RES_UP_DOWN_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(DSP_RESLIST_N.RES_PRI_STS);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(DSP_RESLIST_N.LAST_START_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(DSP_RESLIST_N.LAST_END_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(DSP_RESLIST_N.LAST_EVENT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )13;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(DSP_RESLIST_N.LAST_EVENT_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
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
        DBC_del_null_dsp_reslist(&DSP_RESLIST_N, DSP_RESLIST);
    }
    DB_stop_query_timer("DBC_fetch_dsp_reslist", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_dsp_reslist(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_DSP_RESLIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )535;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL CLOSE DBC_DSP_RESLIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )550;
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
    DB_stop_query_timer("DBC_close_dsp_reslist", sel_type);
}

/* Initialize Function */
void DBC_init_dsp_reslist(struct DSP_RESLIST_TAG *DSP_RESLIST)
{
    /* memset by Space */
    memset(DSP_RESLIST, ' ', sizeof(struct DSP_RESLIST_TAG));
    DSP_RESLIST->MAT_VER = 0;    
}


/* Add Null Function */
void DBC_add_null_dsp_reslist(struct DSP_RESLIST_N_TAG *DSP_RESLIST_N, struct DSP_RESLIST_TAG *DSP_RESLIST)
{
    /* memset by NULL */
    memset(DSP_RESLIST_N, '\0', sizeof(struct DSP_RESLIST_N_TAG));
    
    MEMCPY_AN(DSP_RESLIST_N->FACTORY, DSP_RESLIST->FACTORY, sizeof(DSP_RESLIST->FACTORY));
    MEMCPY_AN(DSP_RESLIST_N->DSP_ID, DSP_RESLIST->DSP_ID, sizeof(DSP_RESLIST->DSP_ID));
    MEMCPY_AN(DSP_RESLIST_N->MAT_ID, DSP_RESLIST->MAT_ID, sizeof(DSP_RESLIST->MAT_ID));
    DSP_RESLIST_N->MAT_VER = DSP_RESLIST->MAT_VER;
    MEMCPY_AN(DSP_RESLIST_N->FLOW, DSP_RESLIST->FLOW, sizeof(DSP_RESLIST->FLOW));
    MEMCPY_AN(DSP_RESLIST_N->OPER, DSP_RESLIST->OPER, sizeof(DSP_RESLIST->OPER));
    MEMCPY_AN(DSP_RESLIST_N->RES_ID, DSP_RESLIST->RES_ID, sizeof(DSP_RESLIST->RES_ID));
    MEMCPY_AN(DSP_RESLIST_N->RES_DESC, DSP_RESLIST->RES_DESC, sizeof(DSP_RESLIST->RES_DESC));
    MEMCPY_AN(DSP_RESLIST_N->RES_TYPE, DSP_RESLIST->RES_TYPE, sizeof(DSP_RESLIST->RES_TYPE));
    MEMCPY_AN(DSP_RESLIST_N->AREA_ID, DSP_RESLIST->AREA_ID, sizeof(DSP_RESLIST->AREA_ID));
    MEMCPY_AN(DSP_RESLIST_N->SUB_AREA_ID, DSP_RESLIST->SUB_AREA_ID, sizeof(DSP_RESLIST->SUB_AREA_ID));
    DSP_RESLIST_N->RES_UP_DOWN_FLAG[0] = DSP_RESLIST->RES_UP_DOWN_FLAG;
    MEMCPY_AN(DSP_RESLIST_N->RES_PRI_STS, DSP_RESLIST->RES_PRI_STS, sizeof(DSP_RESLIST->RES_PRI_STS));
    MEMCPY_AN(DSP_RESLIST_N->LAST_START_TIME, DSP_RESLIST->LAST_START_TIME, sizeof(DSP_RESLIST->LAST_START_TIME));
    MEMCPY_AN(DSP_RESLIST_N->LAST_END_TIME, DSP_RESLIST->LAST_END_TIME, sizeof(DSP_RESLIST->LAST_END_TIME));
    MEMCPY_AN(DSP_RESLIST_N->LAST_EVENT_ID, DSP_RESLIST->LAST_EVENT_ID, sizeof(DSP_RESLIST->LAST_EVENT_ID));
    MEMCPY_AN(DSP_RESLIST_N->LAST_EVENT_TIME, DSP_RESLIST->LAST_EVENT_TIME, sizeof(DSP_RESLIST->LAST_EVENT_TIME));
}


/* Del Null Function */
void DBC_del_null_dsp_reslist(struct DSP_RESLIST_N_TAG *DSP_RESLIST_N, struct DSP_RESLIST_TAG *DSP_RESLIST)
{
    MEMCPY_DN(DSP_RESLIST->FACTORY, DSP_RESLIST_N->FACTORY, sizeof(DSP_RESLIST->FACTORY));
    MEMCPY_DN(DSP_RESLIST->DSP_ID, DSP_RESLIST_N->DSP_ID, sizeof(DSP_RESLIST->DSP_ID));
    MEMCPY_DN(DSP_RESLIST->MAT_ID, DSP_RESLIST_N->MAT_ID, sizeof(DSP_RESLIST->MAT_ID));
    DSP_RESLIST->MAT_VER = DSP_RESLIST_N->MAT_VER;
    MEMCPY_DN(DSP_RESLIST->FLOW, DSP_RESLIST_N->FLOW, sizeof(DSP_RESLIST->FLOW));
    MEMCPY_DN(DSP_RESLIST->OPER, DSP_RESLIST_N->OPER, sizeof(DSP_RESLIST->OPER));
    MEMCPY_DN(DSP_RESLIST->RES_ID, DSP_RESLIST_N->RES_ID, sizeof(DSP_RESLIST->RES_ID));
    MEMCPY_DN(DSP_RESLIST->RES_DESC, DSP_RESLIST_N->RES_DESC, sizeof(DSP_RESLIST->RES_DESC));
    MEMCPY_DN(DSP_RESLIST->RES_TYPE, DSP_RESLIST_N->RES_TYPE, sizeof(DSP_RESLIST->RES_TYPE));
    MEMCPY_DN(DSP_RESLIST->AREA_ID, DSP_RESLIST_N->AREA_ID, sizeof(DSP_RESLIST->AREA_ID));
    MEMCPY_DN(DSP_RESLIST->SUB_AREA_ID, DSP_RESLIST_N->SUB_AREA_ID, sizeof(DSP_RESLIST->SUB_AREA_ID));
    DSP_RESLIST->RES_UP_DOWN_FLAG = DSP_RESLIST_N->RES_UP_DOWN_FLAG[0];
    MEMCPY_DN(DSP_RESLIST->RES_PRI_STS, DSP_RESLIST_N->RES_PRI_STS, sizeof(DSP_RESLIST->RES_PRI_STS));
    MEMCPY_DN(DSP_RESLIST->LAST_START_TIME, DSP_RESLIST_N->LAST_START_TIME, sizeof(DSP_RESLIST->LAST_START_TIME));
    MEMCPY_DN(DSP_RESLIST->LAST_END_TIME, DSP_RESLIST_N->LAST_END_TIME, sizeof(DSP_RESLIST->LAST_END_TIME));
    MEMCPY_DN(DSP_RESLIST->LAST_EVENT_ID, DSP_RESLIST_N->LAST_EVENT_ID, sizeof(DSP_RESLIST->LAST_EVENT_ID));
    MEMCPY_DN(DSP_RESLIST->LAST_EVENT_TIME, DSP_RESLIST_N->LAST_EVENT_TIME, sizeof(DSP_RESLIST->LAST_EVENT_TIME));
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_lotpds_list(int sel_type, struct LOTPDS_LIST_TAG *LOTPDS_LIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct LOTPDS_LIST_N_TAG LOTPDS_LIST_N;
        char   sql[5120];
        char   ts1[100];
        char   ts2[100];
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_lotpds_list(&LOTPDS_LIST_N, LOTPDS_LIST);
    DB_error_code = 0;
    memset( ts1, 0x00, sizeof(ts1));
    memset( ts2, 0x00, sizeof(ts2));

    switch(sel_type)
    {
        //Modify by J.S. 2008.09.17 for reference oper
        //unselect, capable 고려 해서 가지고 온다.
         case 1:
            memset( sql, 0x00, sizeof(sql));
            sprintf(sql,               "SELECT ");
            sprintf(sql + strlen(sql),   "RS.FACTORY, ");
            sprintf(sql + strlen(sql),   "RS.RES_OPER_FLAG, ");
            sprintf(sql + strlen(sql),   "RS.RES_OPER_ID, ");
            sprintf(sql + strlen(sql),   "RS.LOT_ID, ");
            sprintf(sql + strlen(sql),   "RS.SET_OPER, ");
            sprintf(sql + strlen(sql),   "RS.SET_RESG_ID, ");
            sprintf(sql + strlen(sql),   "RS.SET_RES_ID, ");
            sprintf(sql + strlen(sql),   "RS.DSP_ID, ");
            sprintf(sql + strlen(sql),   "RS.RULE_ID, ");
            sprintf(sql + strlen(sql),   "RS.TEMP_BATCH_ID, ");
            sprintf(sql + strlen(sql),   "RS.TEMP_BATCH_SEQ, ");
            sprintf(sql + strlen(sql),   "RS.CUR_OPER, ");
            sprintf(sql + strlen(sql),   "RS.REFERENCE_OPER, ");
            sprintf(sql + strlen(sql),   "RS.UNSELECTED_FLAG, ");
            sprintf(sql + strlen(sql),   "RS.LOT_RESV_FLAG, ");
            sprintf(sql + strlen(sql),   "RS.LOT_RESV_TIME, ");
            sprintf(sql + strlen(sql),   "RS.CAPABLE_FLAG, ");
            sprintf(sql + strlen(sql),   "RS.PRI_ADJUST_FLAG, ");
            sprintf(sql + strlen(sql),   "RS.PRIORITY_SCORE, ");
            sprintf(sql + strlen(sql),   "RS.PRIORITY_SUPPORT, ");
            sprintf(sql + strlen(sql),   "RS.HIST_SEQ, ");
            sprintf(sql + strlen(sql),   "RS.PRI_ADJUST_REASON, ");
            sprintf(sql + strlen(sql),   "RS.TRIGGER_BY, ");
            sprintf(sql + strlen(sql),   "RS.DSP_REASON, ");
            sprintf(sql + strlen(sql),   "RS.UNSELECT_REASON, ");
            sprintf(sql + strlen(sql),   "RS.CAPABLE_REASON, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_1, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_2, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_3, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_4, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_5, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_6, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_7, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_8, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_9, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_10, ");
            sprintf(sql + strlen(sql),   "RS.CREATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "RS.CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "RS.UPDATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "RS.UPDATE_TIME, ");
            sprintf(sql + strlen(sql),   "WL.MAT_ID, WL.MAT_VER, WL.FLOW, WL.FLOW_SEQ_NUM, WL.OPER, WL.QTY_1, WL.QTY_2, WL.QTY_3, WL.LOT_TYPE, ");
            sprintf(sql + strlen(sql),   "WL.OWNER_CODE, WL.CREATE_CODE, WL.LOT_PRIORITY, WL.LOT_STATUS, WL.HOLD_FLAG, WL.RWK_FLAG, ");
            sprintf(sql + strlen(sql),   "WL.NSTD_FLAG, WL.START_FLAG, WL.REP_FLAG, WL.ORG_DUE_TIME, WL.SCH_DUE_TIME, WL.OPER_IN_TIME, WL.LAST_TRAN_CODE, ' ', ");
            sprintf(sql + strlen(sql),   "WL.RESERVE_RES_ID ");
            sprintf(sql + strlen(sql), "FROM MRTDLOTPDS RS, MWIPLOTSTS WL WHERE ");

            make_valid_quote(ts1, LOTPDS_LIST_N.FACTORY);
            sprintf(sql + strlen(sql), "RS.FACTORY = '%s' AND RS.LOT_ID = WL.LOT_ID AND RS.RES_OPER_FLAG = '%c' ", ts1, LOTPDS_LIST->RES_OPER_FLAG);
            make_valid_quote(ts1, LOTPDS_LIST_N.RES_OPER_ID);
            sprintf(sql + strlen(sql), "AND RS.RES_OPER_ID = '%s' AND RS.UNSELECTED_FLAG <> '%c' ", ts1, LOTPDS_LIST_N.UNSELECTED_FLAG[0]);
            sprintf(sql + strlen(sql), "AND RS.CAPABLE_FLAG <> '%c' ", LOTPDS_LIST_N.CAPABLE_FLAG[0]);
            
            if(DBC_Q_COND_N.KEY_2[0] == 'Y')
            {
                if(DBC_Q_COND_N.KEY_1[0] != 'Y')
                {
                    sprintf(sql + strlen(sql), "AND ((RS.REFERENCE_OPER = ' ' AND (WL.LOT_STATUS = 'WAIT' OR WL.LOT_STATUS = 'PROC')) OR (RS.REFERENCE_OPER <> ' ')) ");
                }
            }
            else
            {
                if(DBC_Q_COND_N.KEY_1[0] == 'Y')
                {
                    sprintf(sql + strlen(sql), "AND ((RS.REFERENCE_OPER = ' ' AND (WL.LOT_STATUS = 'WAIT' OR WL.LOT_STATUS = 'RESV')) OR (RS.REFERENCE_OPER <> ' ')) ");
                }
                else
                {        
                    sprintf(sql + strlen(sql), "AND ((RS.REFERENCE_OPER = ' ' AND WL.LOT_STATUS = 'WAIT') OR (RS.REFERENCE_OPER <> ' ')) ");
                }
                sprintf(sql + strlen(sql), "AND WL.HOLD_FLAG <> 'Y' ");                    
            }
            sprintf(sql + strlen(sql), "AND WL.QTY_1 >= 0.00009 ORDER BY RS.PRIORITY_SCORE DESC, RS.LOT_ID ASC");
                    
            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )565;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)sql;
            sqlstm.sqhstl[0] = (unsigned int  )5120;
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


            /* EXEC SQL DECLARE DBC_LOTPDS_LIST_CUR_1 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_LOTPDS_LIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )584;
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
            
        //unselect, capable 상관없이 모든 레코드 가지고 온다.
        case 2:
            /* EXEC SQL DECLARE DBC_LOTPDS_LIST_CUR_2 CURSOR FOR
                SELECT
                       RS.FACTORY,
                       RS.RES_OPER_FLAG,
                       RS.RES_OPER_ID,
                       RS.LOT_ID,
                       RS.SET_OPER,
                       RS.SET_RESG_ID,
                       RS.SET_RES_ID,
                       RS.DSP_ID,
                       RS.RULE_ID,
                       RS.TEMP_BATCH_ID,
                       RS.TEMP_BATCH_SEQ,
                       RS.CUR_OPER,
                       RS.REFERENCE_OPER,
                       RS.UNSELECTED_FLAG,
                       RS.LOT_RESV_FLAG,
                       RS.LOT_RESV_TIME,
                       RS.CAPABLE_FLAG,
                       RS.PRI_ADJUST_FLAG,
                       RS.PRIORITY_SCORE,
                       RS.PRIORITY_SUPPORT,
                       RS.HIST_SEQ,
                       RS.PRI_ADJUST_REASON,
                       RS.TRIGGER_BY,
                       RS.DSP_REASON,
                       RS.UNSELECT_REASON,
                       RS.CAPABLE_REASON,
                       RS.PDS_CMF_1,
                       RS.PDS_CMF_2,
                       RS.PDS_CMF_3,
                       RS.PDS_CMF_4,
                       RS.PDS_CMF_5,
                       RS.PDS_CMF_6,
                       RS.PDS_CMF_7,
                       RS.PDS_CMF_8,
                       RS.PDS_CMF_9,
                       RS.PDS_CMF_10,
                       RS.CREATE_USER_ID,
                       RS.CREATE_TIME,
                       RS.UPDATE_USER_ID,
                       RS.UPDATE_TIME,
                       WL.MAT_ID, WL.MAT_VER, WL.FLOW, WL.FLOW_SEQ_NUM, WL.OPER, WL.QTY_1, WL.QTY_2, WL.QTY_3, WL.LOT_TYPE,
                       WL.OWNER_CODE, WL.CREATE_CODE, WL.LOT_PRIORITY, WL.LOT_STATUS, WL.HOLD_FLAG, WL.RWK_FLAG,
                       WL.NSTD_FLAG, WL.START_FLAG, WL.REP_FLAG, WL.ORG_DUE_TIME, WL.SCH_DUE_TIME, WL.OPER_IN_TIME, WL.LAST_TRAN_CODE, ' ',
                       WL.RESERVE_RES_ID
                FROM MRTDLOTPDS RS, MWIPLOTSTS WL
                WHERE RS.FACTORY = :LOTPDS_LIST_N.FACTORY
                    AND RS.LOT_ID = WL.LOT_ID
                    AND RS.RES_OPER_FLAG = :LOTPDS_LIST_N.RES_OPER_FLAG
                    AND RS.RES_OPER_ID = :LOTPDS_LIST_N.RES_OPER_ID
                    //Modify by J.S. 2009.03.23
                    AND ((RS.REFERENCE_OPER = ' ' AND WL.LOT_STATUS = 'WAIT') OR (RS.REFERENCE_OPER <> ' '))
                    AND WL.HOLD_FLAG <> 'Y'
                    AND WL.QTY_1 >= 0.00009
                ORDER BY RS.PRIORITY_SCORE DESC, RS.LOT_ID ASC; */ 

            /* EXEC SQL OPEN DBC_LOTPDS_LIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select RS.FACTORY ,RS.RES_OPER_FLAG ,RS.RES_OPER_ID ,RS.LOT_I\
D ,RS.SET_OPER ,RS.SET_RESG_ID ,RS.SET_RES_ID ,RS.DSP_ID ,RS.RULE_ID ,RS.TEM\
P_BATCH_ID ,RS.TEMP_BATCH_SEQ ,RS.CUR_OPER ,RS.REFERENCE_OPER ,RS.UNSELECTED\
_FLAG ,RS.LOT_RESV_FLAG ,RS.LOT_RESV_TIME ,RS.CAPABLE_FLAG ,RS.PRI_ADJUST_FL\
AG ,RS.PRIORITY_SCORE ,RS.PRIORITY_SUPPORT ,RS.HIST_SEQ ,RS.PRI_ADJUST_REASO\
N ,RS.TRIGGER_BY ,RS.DSP_REASON ,RS.UNSELECT_REASON ,RS.CAPABLE_REASON ,RS.P\
DS_CMF_1 ,RS.PDS_CMF_2 ,RS.PDS_CMF_3 ,RS.PDS_CMF_4 ,RS.PDS_CMF_5 ,RS.PDS_CMF\
_6 ,RS.PDS_CMF_7 ,RS.PDS_CMF_8 ,RS.PDS_CMF_9 ,RS.PDS_CMF_10 ,RS.CREATE_USER_\
ID ,RS.CREATE_TIME ,RS.UPDATE_USER_ID ,RS.UPDATE_TIME ,WL.MAT_ID ,WL.MAT_VER\
 ,WL.FLOW ,WL.FLOW_SEQ_NUM ,WL.OPER ,WL.QTY_1 ,WL.QTY_2 ,WL.QTY_3 ,WL.LOT_TY\
PE ,WL.OWNER_CODE ,WL.CREATE_CODE ,WL.LOT_PRIORITY ,WL.LOT_STATUS ,WL.HOLD_F\
LAG ,WL.RWK_FLAG ,WL.NSTD_FLAG ,WL.START_FLAG ,WL.REP_FLAG ,WL.ORG_DUE_TIME \
,WL.SCH_DUE_TIME ,WL.OPER_IN_TIME ,WL.LAST_TRAN_CODE ,' ' ,WL.RESERVE_RES_ID\
  from MRTDLOTPDS RS ,MWIPLOTSTS WL where ((((((RS.");
            sqlstm.stmt = sq0006;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )599;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(LOTPDS_LIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(LOTPDS_LIST_N.RES_OPER_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(LOTPDS_LIST_N.RES_OPER_ID);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 3:
            memset( sql, 0x00, sizeof(sql));
            sprintf(sql,               "SELECT ");
            sprintf(sql + strlen(sql),   "RS.FACTORY, ");
            sprintf(sql + strlen(sql),   "RS.RES_OPER_FLAG, ");
            sprintf(sql + strlen(sql),   "RS.RES_OPER_ID, ");
            sprintf(sql + strlen(sql),   "RS.LOT_ID, ");
            sprintf(sql + strlen(sql),   "RS.SET_OPER, ");
            sprintf(sql + strlen(sql),   "RS.SET_RESG_ID, ");
            sprintf(sql + strlen(sql),   "RS.SET_RES_ID, ");
            sprintf(sql + strlen(sql),   "RS.DSP_ID, ");
            sprintf(sql + strlen(sql),   "RS.RULE_ID, ");
            sprintf(sql + strlen(sql),   "RS.TEMP_BATCH_ID, ");
            sprintf(sql + strlen(sql),   "RS.TEMP_BATCH_SEQ, ");
            sprintf(sql + strlen(sql),   "RS.CUR_OPER, ");
            sprintf(sql + strlen(sql),   "RS.REFERENCE_OPER, ");
            sprintf(sql + strlen(sql),   "RS.UNSELECTED_FLAG, ");
            sprintf(sql + strlen(sql),   "RS.LOT_RESV_FLAG, ");
            sprintf(sql + strlen(sql),   "RS.LOT_RESV_TIME, ");
            sprintf(sql + strlen(sql),   "RS.CAPABLE_FLAG, ");
            sprintf(sql + strlen(sql),   "RS.PRI_ADJUST_FLAG, ");
            sprintf(sql + strlen(sql),   "RS.PRIORITY_SCORE, ");
            sprintf(sql + strlen(sql),   "RS.PRIORITY_SUPPORT, ");
            sprintf(sql + strlen(sql),   "RS.HIST_SEQ, ");
            sprintf(sql + strlen(sql),   "RS.PRI_ADJUST_REASON, ");
            sprintf(sql + strlen(sql),   "RS.TRIGGER_BY, ");
            sprintf(sql + strlen(sql),   "RS.DSP_REASON, ");
            sprintf(sql + strlen(sql),   "RS.UNSELECT_REASON, ");
            sprintf(sql + strlen(sql),   "RS.CAPABLE_REASON, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_1, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_2, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_3, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_4, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_5, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_6, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_7, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_8, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_9, ");
            sprintf(sql + strlen(sql),   "RS.PDS_CMF_10, ");
            sprintf(sql + strlen(sql),   "RS.CREATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "RS.CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "RS.UPDATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "RS.UPDATE_TIME, ");
            sprintf(sql + strlen(sql),   "WL.MAT_ID, WL.MAT_VER, WL.FLOW, WL.FLOW_SEQ_NUM, WL.OPER, WL.QTY_1, WL.QTY_2, WL.QTY_3, WL.LOT_TYPE, ");
            sprintf(sql + strlen(sql),   "WL.OWNER_CODE, WL.CREATE_CODE, WL.LOT_PRIORITY, WL.LOT_STATUS, WL.HOLD_FLAG, WL.RWK_FLAG, ");
            sprintf(sql + strlen(sql),   "WL.NSTD_FLAG, WL.START_FLAG, WL.REP_FLAG, WL.ORG_DUE_TIME, WL.SCH_DUE_TIME, WL.OPER_IN_TIME, WL.LAST_TRAN_CODE, ' ', ");
            sprintf(sql + strlen(sql),   "WL.RESERVE_RES_ID ");
            sprintf(sql + strlen(sql), "FROM MRTDLOTPDS RS, MWIPLOTSTS WL WHERE ");

            make_valid_quote(ts1, LOTPDS_LIST_N.FACTORY);
            sprintf(sql + strlen(sql), "RS.FACTORY = '%s' AND RS.LOT_ID = WL.LOT_ID AND RS.RES_OPER_FLAG = '%c' ", ts1, LOTPDS_LIST->RES_OPER_FLAG);
            make_valid_quote(ts1, LOTPDS_LIST_N.RES_OPER_ID);
            sprintf(sql + strlen(sql), "AND RS.RES_OPER_ID = '%s' AND RS.UNSELECTED_FLAG <> '%c' ", ts1, LOTPDS_LIST_N.UNSELECTED_FLAG[0]);
            sprintf(sql + strlen(sql), "AND RS.CAPABLE_FLAG <> '%c' ", LOTPDS_LIST_N.CAPABLE_FLAG[0]);
            
            if(DBC_Q_COND_N.KEY_2[0] == 'Y')
            {
                if(DBC_Q_COND_N.KEY_1[0] != 'Y')
                {
                    sprintf(sql + strlen(sql), "AND ((RS.REFERENCE_OPER = ' ' AND (WL.LOT_STATUS = 'WAIT' OR WL.LOT_STATUS = 'PROC')) OR (RS.REFERENCE_OPER <> ' ')) ");
                }
            }
            else
            {
                if(DBC_Q_COND_N.KEY_1[0] == 'Y')
                {
                    sprintf(sql + strlen(sql), "AND ((RS.REFERENCE_OPER = ' ' AND (WL.LOT_STATUS = 'WAIT' OR WL.LOT_STATUS = 'RESV')) OR (RS.REFERENCE_OPER <> ' ')) ");
                }
                else
                {        
                    sprintf(sql + strlen(sql), "AND ((RS.REFERENCE_OPER = ' ' AND WL.LOT_STATUS = 'WAIT') OR (RS.REFERENCE_OPER <> ' ')) ");
                }
                sprintf(sql + strlen(sql), "AND WL.HOLD_FLAG <> 'Y' ");                    
            }
            sprintf(sql + strlen(sql), "AND WL.QTY_1 >= 0.0000 ORDER BY RS.PRIORITY_SCORE DESC, RS.LOT_ID ASC");
                    
            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )626;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)sql;
            sqlstm.sqhstl[0] = (unsigned int  )5120;
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


            /* EXEC SQL DECLARE DBC_LOTPDS_LIST_CUR_3 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_LOTPDS_LIST_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 26;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )645;
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
    DB_stop_query_timer("DBC_open_lotpds_list", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_lotpds_list(int sel_type, struct LOTPDS_LIST_TAG *LOTPDS_LIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct LOTPDS_LIST_N_TAG LOTPDS_LIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_LOTPDS_LIST_CUR_1 INTO
                                                    :LOTPDS_LIST_N.FACTORY,
                                                    :LOTPDS_LIST_N.RES_OPER_FLAG,
                                                    :LOTPDS_LIST_N.RES_OPER_ID,
                                                    :LOTPDS_LIST_N.LOT_ID,
                                                    :LOTPDS_LIST_N.SET_OPER,
                                                    :LOTPDS_LIST_N.SET_RESG_ID,
                                                    :LOTPDS_LIST_N.SET_RES_ID,
                                                    :LOTPDS_LIST_N.DSP_ID,
                                                    :LOTPDS_LIST_N.RULE_ID,
                                                    :LOTPDS_LIST_N.TEMP_BATCH_ID,
                                                    :LOTPDS_LIST_N.TEMP_BATCH_SEQ,
                                                    :LOTPDS_LIST_N.CUR_OPER,
                                                    :LOTPDS_LIST_N.REFERENCE_OPER,
                                                    :LOTPDS_LIST_N.UNSELECTED_FLAG,
                                                    :LOTPDS_LIST_N.LOT_RESV_FLAG,
                                                    :LOTPDS_LIST_N.LOT_RESV_TIME,
                                                    :LOTPDS_LIST_N.CAPABLE_FLAG,
                                                    :LOTPDS_LIST_N.PRI_ADJUST_FLAG,
                                                    :LOTPDS_LIST_N.PRIORITY_SCORE,
                                                    :LOTPDS_LIST_N.PRIORITY_SUPPORT,
                                                    :LOTPDS_LIST_N.HIST_SEQ,
                                                    :LOTPDS_LIST_N.PRI_ADJUST_REASON,
                                                    :LOTPDS_LIST_N.TRIGGER_BY,
                                                    :LOTPDS_LIST_N.DSP_REASON,
                                                    :LOTPDS_LIST_N.UNSELECT_REASON,
                                                    :LOTPDS_LIST_N.CAPABLE_REASON,
                                                    :LOTPDS_LIST_N.PDS_CMF_1,
                                                    :LOTPDS_LIST_N.PDS_CMF_2,
                                                    :LOTPDS_LIST_N.PDS_CMF_3,
                                                    :LOTPDS_LIST_N.PDS_CMF_4,
                                                    :LOTPDS_LIST_N.PDS_CMF_5,
                                                    :LOTPDS_LIST_N.PDS_CMF_6,
                                                    :LOTPDS_LIST_N.PDS_CMF_7,
                                                    :LOTPDS_LIST_N.PDS_CMF_8,
                                                    :LOTPDS_LIST_N.PDS_CMF_9,
                                                    :LOTPDS_LIST_N.PDS_CMF_10,
                                                    :LOTPDS_LIST_N.CREATE_USER_ID,
                                                    :LOTPDS_LIST_N.CREATE_TIME,
                                                    :LOTPDS_LIST_N.UPDATE_USER_ID,
                                                    :LOTPDS_LIST_N.UPDATE_TIME,
                                                    :LOTPDS_LIST_N.MAT_ID,
                                                    :LOTPDS_LIST_N.MAT_VER,
                                                    :LOTPDS_LIST_N.FLOW,
                                                    :LOTPDS_LIST_N.FLOW_SEQ_NUM,
                                                    :LOTPDS_LIST_N.OPER,
                                                    :LOTPDS_LIST_N.QTY_1,
                                                    :LOTPDS_LIST_N.QTY_2,
                                                    :LOTPDS_LIST_N.QTY_3,
                                                    :LOTPDS_LIST_N.LOT_TYPE,
                                                    :LOTPDS_LIST_N.OWNER_CODE,
                                                    :LOTPDS_LIST_N.CREATE_CODE,
                                                    :LOTPDS_LIST_N.LOT_PRIORITY,
                                                    :LOTPDS_LIST_N.LOT_STATUS,
                                                    :LOTPDS_LIST_N.HOLD_FLAG,
                                                    :LOTPDS_LIST_N.RWK_FLAG,
                                                    :LOTPDS_LIST_N.NSTD_FLAG,
                                                    :LOTPDS_LIST_N.START_FLAG,
                                                    :LOTPDS_LIST_N.REP_FLAG,
                                                    :LOTPDS_LIST_N.ORG_DUE_TIME,
                                                    :LOTPDS_LIST_N.SCH_DUE_TIME,
                                                    :LOTPDS_LIST_N.OPER_IN_TIME,
                                                    :LOTPDS_LIST_N.LAST_TRAN_CODE,
                                                    :LOTPDS_LIST_N.RECIPE,
                                                    :LOTPDS_LIST_N.RESERVE_RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 64;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )660;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(LOTPDS_LIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(LOTPDS_LIST_N.RES_OPER_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(LOTPDS_LIST_N.RES_OPER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(LOTPDS_LIST_N.LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(LOTPDS_LIST_N.SET_OPER);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(LOTPDS_LIST_N.SET_RESG_ID);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(LOTPDS_LIST_N.SET_RES_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(LOTPDS_LIST_N.DSP_ID);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(LOTPDS_LIST_N.RULE_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(LOTPDS_LIST_N.TEMP_BATCH_ID);
            sqlstm.sqhstl[9] = (unsigned int  )25;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(LOTPDS_LIST_N.TEMP_BATCH_SEQ);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(LOTPDS_LIST_N.CUR_OPER);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(LOTPDS_LIST_N.REFERENCE_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(LOTPDS_LIST_N.UNSELECTED_FLAG);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(LOTPDS_LIST_N.LOT_RESV_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(LOTPDS_LIST_N.LOT_RESV_TIME);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(LOTPDS_LIST_N.CAPABLE_FLAG);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(LOTPDS_LIST_N.PRI_ADJUST_FLAG);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(LOTPDS_LIST_N.PRIORITY_SCORE);
            sqlstm.sqhstl[18] = (unsigned int  )101;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(LOTPDS_LIST_N.PRIORITY_SUPPORT);
            sqlstm.sqhstl[19] = (unsigned int  )101;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(LOTPDS_LIST_N.HIST_SEQ);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(LOTPDS_LIST_N.PRI_ADJUST_REASON);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(LOTPDS_LIST_N.TRIGGER_BY);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(LOTPDS_LIST_N.DSP_REASON);
            sqlstm.sqhstl[23] = (unsigned int  )1001;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(LOTPDS_LIST_N.UNSELECT_REASON);
            sqlstm.sqhstl[24] = (unsigned int  )1001;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(LOTPDS_LIST_N.CAPABLE_REASON);
            sqlstm.sqhstl[25] = (unsigned int  )1001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_1);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_2);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_3);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_4);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_5);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_6);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_7);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_8);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_9);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_10);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(LOTPDS_LIST_N.CREATE_USER_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(LOTPDS_LIST_N.CREATE_TIME);
            sqlstm.sqhstl[37] = (unsigned int  )15;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(LOTPDS_LIST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(LOTPDS_LIST_N.UPDATE_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )15;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(LOTPDS_LIST_N.MAT_ID);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(LOTPDS_LIST_N.MAT_VER);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(LOTPDS_LIST_N.FLOW);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(LOTPDS_LIST_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(LOTPDS_LIST_N.OPER);
            sqlstm.sqhstl[44] = (unsigned int  )11;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(LOTPDS_LIST_N.QTY_1);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(LOTPDS_LIST_N.QTY_2);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(LOTPDS_LIST_N.QTY_3);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(LOTPDS_LIST_N.LOT_TYPE);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(LOTPDS_LIST_N.OWNER_CODE);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(LOTPDS_LIST_N.CREATE_CODE);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(LOTPDS_LIST_N.LOT_PRIORITY);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(LOTPDS_LIST_N.LOT_STATUS);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(LOTPDS_LIST_N.HOLD_FLAG);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(LOTPDS_LIST_N.RWK_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(LOTPDS_LIST_N.NSTD_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(LOTPDS_LIST_N.START_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(LOTPDS_LIST_N.REP_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(LOTPDS_LIST_N.ORG_DUE_TIME);
            sqlstm.sqhstl[58] = (unsigned int  )15;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(LOTPDS_LIST_N.SCH_DUE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(LOTPDS_LIST_N.OPER_IN_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(LOTPDS_LIST_N.LAST_TRAN_CODE);
            sqlstm.sqhstl[61] = (unsigned int  )13;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(LOTPDS_LIST_N.RECIPE);
            sqlstm.sqhstl[62] = (unsigned int  )25;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(LOTPDS_LIST_N.RESERVE_RES_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_LOTPDS_LIST_CUR_2 INTO
                                                    :LOTPDS_LIST_N.FACTORY,
                                                    :LOTPDS_LIST_N.RES_OPER_FLAG,
                                                    :LOTPDS_LIST_N.RES_OPER_ID,
                                                    :LOTPDS_LIST_N.LOT_ID,
                                                    :LOTPDS_LIST_N.SET_OPER,
                                                    :LOTPDS_LIST_N.SET_RESG_ID,
                                                    :LOTPDS_LIST_N.SET_RES_ID,
                                                    :LOTPDS_LIST_N.DSP_ID,
                                                    :LOTPDS_LIST_N.RULE_ID,
                                                    :LOTPDS_LIST_N.TEMP_BATCH_ID,
                                                    :LOTPDS_LIST_N.TEMP_BATCH_SEQ,
                                                    :LOTPDS_LIST_N.CUR_OPER,
                                                    :LOTPDS_LIST_N.REFERENCE_OPER,
                                                    :LOTPDS_LIST_N.UNSELECTED_FLAG,
                                                    :LOTPDS_LIST_N.LOT_RESV_FLAG,
                                                    :LOTPDS_LIST_N.LOT_RESV_TIME,
                                                    :LOTPDS_LIST_N.CAPABLE_FLAG,
                                                    :LOTPDS_LIST_N.PRI_ADJUST_FLAG,
                                                    :LOTPDS_LIST_N.PRIORITY_SCORE,
                                                    :LOTPDS_LIST_N.PRIORITY_SUPPORT,
                                                    :LOTPDS_LIST_N.HIST_SEQ,
                                                    :LOTPDS_LIST_N.PRI_ADJUST_REASON,
                                                    :LOTPDS_LIST_N.TRIGGER_BY,
                                                    :LOTPDS_LIST_N.DSP_REASON,
                                                    :LOTPDS_LIST_N.UNSELECT_REASON,
                                                    :LOTPDS_LIST_N.CAPABLE_REASON,
                                                    :LOTPDS_LIST_N.PDS_CMF_1,
                                                    :LOTPDS_LIST_N.PDS_CMF_2,
                                                    :LOTPDS_LIST_N.PDS_CMF_3,
                                                    :LOTPDS_LIST_N.PDS_CMF_4,
                                                    :LOTPDS_LIST_N.PDS_CMF_5,
                                                    :LOTPDS_LIST_N.PDS_CMF_6,
                                                    :LOTPDS_LIST_N.PDS_CMF_7,
                                                    :LOTPDS_LIST_N.PDS_CMF_8,
                                                    :LOTPDS_LIST_N.PDS_CMF_9,
                                                    :LOTPDS_LIST_N.PDS_CMF_10,
                                                    :LOTPDS_LIST_N.CREATE_USER_ID,
                                                    :LOTPDS_LIST_N.CREATE_TIME,
                                                    :LOTPDS_LIST_N.UPDATE_USER_ID,
                                                    :LOTPDS_LIST_N.UPDATE_TIME,
                                                    :LOTPDS_LIST_N.MAT_ID,
                                                    :LOTPDS_LIST_N.MAT_VER,
                                                    :LOTPDS_LIST_N.FLOW,
                                                    :LOTPDS_LIST_N.FLOW_SEQ_NUM,
                                                    :LOTPDS_LIST_N.OPER,
                                                    :LOTPDS_LIST_N.QTY_1,
                                                    :LOTPDS_LIST_N.QTY_2,
                                                    :LOTPDS_LIST_N.QTY_3,
                                                    :LOTPDS_LIST_N.LOT_TYPE,
                                                    :LOTPDS_LIST_N.OWNER_CODE,
                                                    :LOTPDS_LIST_N.CREATE_CODE,
                                                    :LOTPDS_LIST_N.LOT_PRIORITY,
                                                    :LOTPDS_LIST_N.LOT_STATUS,
                                                    :LOTPDS_LIST_N.HOLD_FLAG,
                                                    :LOTPDS_LIST_N.RWK_FLAG,
                                                    :LOTPDS_LIST_N.NSTD_FLAG,
                                                    :LOTPDS_LIST_N.START_FLAG,
                                                    :LOTPDS_LIST_N.REP_FLAG,
                                                    :LOTPDS_LIST_N.ORG_DUE_TIME,
                                                    :LOTPDS_LIST_N.SCH_DUE_TIME,
                                                    :LOTPDS_LIST_N.OPER_IN_TIME,
                                                    :LOTPDS_LIST_N.LAST_TRAN_CODE,
                                                    :LOTPDS_LIST_N.RECIPE,
                                                    :LOTPDS_LIST_N.RESERVE_RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 64;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )931;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(LOTPDS_LIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(LOTPDS_LIST_N.RES_OPER_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(LOTPDS_LIST_N.RES_OPER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(LOTPDS_LIST_N.LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(LOTPDS_LIST_N.SET_OPER);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(LOTPDS_LIST_N.SET_RESG_ID);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(LOTPDS_LIST_N.SET_RES_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(LOTPDS_LIST_N.DSP_ID);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(LOTPDS_LIST_N.RULE_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(LOTPDS_LIST_N.TEMP_BATCH_ID);
            sqlstm.sqhstl[9] = (unsigned int  )25;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(LOTPDS_LIST_N.TEMP_BATCH_SEQ);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(LOTPDS_LIST_N.CUR_OPER);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(LOTPDS_LIST_N.REFERENCE_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(LOTPDS_LIST_N.UNSELECTED_FLAG);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(LOTPDS_LIST_N.LOT_RESV_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(LOTPDS_LIST_N.LOT_RESV_TIME);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(LOTPDS_LIST_N.CAPABLE_FLAG);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(LOTPDS_LIST_N.PRI_ADJUST_FLAG);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(LOTPDS_LIST_N.PRIORITY_SCORE);
            sqlstm.sqhstl[18] = (unsigned int  )101;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(LOTPDS_LIST_N.PRIORITY_SUPPORT);
            sqlstm.sqhstl[19] = (unsigned int  )101;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(LOTPDS_LIST_N.HIST_SEQ);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(LOTPDS_LIST_N.PRI_ADJUST_REASON);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(LOTPDS_LIST_N.TRIGGER_BY);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(LOTPDS_LIST_N.DSP_REASON);
            sqlstm.sqhstl[23] = (unsigned int  )1001;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(LOTPDS_LIST_N.UNSELECT_REASON);
            sqlstm.sqhstl[24] = (unsigned int  )1001;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(LOTPDS_LIST_N.CAPABLE_REASON);
            sqlstm.sqhstl[25] = (unsigned int  )1001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_1);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_2);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_3);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_4);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_5);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_6);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_7);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_8);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_9);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_10);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(LOTPDS_LIST_N.CREATE_USER_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(LOTPDS_LIST_N.CREATE_TIME);
            sqlstm.sqhstl[37] = (unsigned int  )15;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(LOTPDS_LIST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(LOTPDS_LIST_N.UPDATE_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )15;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(LOTPDS_LIST_N.MAT_ID);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(LOTPDS_LIST_N.MAT_VER);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(LOTPDS_LIST_N.FLOW);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(LOTPDS_LIST_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(LOTPDS_LIST_N.OPER);
            sqlstm.sqhstl[44] = (unsigned int  )11;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(LOTPDS_LIST_N.QTY_1);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(LOTPDS_LIST_N.QTY_2);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(LOTPDS_LIST_N.QTY_3);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(LOTPDS_LIST_N.LOT_TYPE);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(LOTPDS_LIST_N.OWNER_CODE);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(LOTPDS_LIST_N.CREATE_CODE);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(LOTPDS_LIST_N.LOT_PRIORITY);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(LOTPDS_LIST_N.LOT_STATUS);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(LOTPDS_LIST_N.HOLD_FLAG);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(LOTPDS_LIST_N.RWK_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(LOTPDS_LIST_N.NSTD_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(LOTPDS_LIST_N.START_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(LOTPDS_LIST_N.REP_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(LOTPDS_LIST_N.ORG_DUE_TIME);
            sqlstm.sqhstl[58] = (unsigned int  )15;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(LOTPDS_LIST_N.SCH_DUE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(LOTPDS_LIST_N.OPER_IN_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(LOTPDS_LIST_N.LAST_TRAN_CODE);
            sqlstm.sqhstl[61] = (unsigned int  )13;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(LOTPDS_LIST_N.RECIPE);
            sqlstm.sqhstl[62] = (unsigned int  )25;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(LOTPDS_LIST_N.RESERVE_RES_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_LOTPDS_LIST_CUR_3 INTO
                                                    :LOTPDS_LIST_N.FACTORY,
                                                    :LOTPDS_LIST_N.RES_OPER_FLAG,
                                                    :LOTPDS_LIST_N.RES_OPER_ID,
                                                    :LOTPDS_LIST_N.LOT_ID,
                                                    :LOTPDS_LIST_N.SET_OPER,
                                                    :LOTPDS_LIST_N.SET_RESG_ID,
                                                    :LOTPDS_LIST_N.SET_RES_ID,
                                                    :LOTPDS_LIST_N.DSP_ID,
                                                    :LOTPDS_LIST_N.RULE_ID,
                                                    :LOTPDS_LIST_N.TEMP_BATCH_ID,
                                                    :LOTPDS_LIST_N.TEMP_BATCH_SEQ,
                                                    :LOTPDS_LIST_N.CUR_OPER,
                                                    :LOTPDS_LIST_N.REFERENCE_OPER,
                                                    :LOTPDS_LIST_N.UNSELECTED_FLAG,
                                                    :LOTPDS_LIST_N.LOT_RESV_FLAG,
                                                    :LOTPDS_LIST_N.LOT_RESV_TIME,
                                                    :LOTPDS_LIST_N.CAPABLE_FLAG,
                                                    :LOTPDS_LIST_N.PRI_ADJUST_FLAG,
                                                    :LOTPDS_LIST_N.PRIORITY_SCORE,
                                                    :LOTPDS_LIST_N.PRIORITY_SUPPORT,
                                                    :LOTPDS_LIST_N.HIST_SEQ,
                                                    :LOTPDS_LIST_N.PRI_ADJUST_REASON,
                                                    :LOTPDS_LIST_N.TRIGGER_BY,
                                                    :LOTPDS_LIST_N.DSP_REASON,
                                                    :LOTPDS_LIST_N.UNSELECT_REASON,
                                                    :LOTPDS_LIST_N.CAPABLE_REASON,
                                                    :LOTPDS_LIST_N.PDS_CMF_1,
                                                    :LOTPDS_LIST_N.PDS_CMF_2,
                                                    :LOTPDS_LIST_N.PDS_CMF_3,
                                                    :LOTPDS_LIST_N.PDS_CMF_4,
                                                    :LOTPDS_LIST_N.PDS_CMF_5,
                                                    :LOTPDS_LIST_N.PDS_CMF_6,
                                                    :LOTPDS_LIST_N.PDS_CMF_7,
                                                    :LOTPDS_LIST_N.PDS_CMF_8,
                                                    :LOTPDS_LIST_N.PDS_CMF_9,
                                                    :LOTPDS_LIST_N.PDS_CMF_10,
                                                    :LOTPDS_LIST_N.CREATE_USER_ID,
                                                    :LOTPDS_LIST_N.CREATE_TIME,
                                                    :LOTPDS_LIST_N.UPDATE_USER_ID,
                                                    :LOTPDS_LIST_N.UPDATE_TIME,
                                                    :LOTPDS_LIST_N.MAT_ID,
                                                    :LOTPDS_LIST_N.MAT_VER,
                                                    :LOTPDS_LIST_N.FLOW,
                                                    :LOTPDS_LIST_N.FLOW_SEQ_NUM,
                                                    :LOTPDS_LIST_N.OPER,
                                                    :LOTPDS_LIST_N.QTY_1,
                                                    :LOTPDS_LIST_N.QTY_2,
                                                    :LOTPDS_LIST_N.QTY_3,
                                                    :LOTPDS_LIST_N.LOT_TYPE,
                                                    :LOTPDS_LIST_N.OWNER_CODE,
                                                    :LOTPDS_LIST_N.CREATE_CODE,
                                                    :LOTPDS_LIST_N.LOT_PRIORITY,
                                                    :LOTPDS_LIST_N.LOT_STATUS,
                                                    :LOTPDS_LIST_N.HOLD_FLAG,
                                                    :LOTPDS_LIST_N.RWK_FLAG,
                                                    :LOTPDS_LIST_N.NSTD_FLAG,
                                                    :LOTPDS_LIST_N.START_FLAG,
                                                    :LOTPDS_LIST_N.REP_FLAG,
                                                    :LOTPDS_LIST_N.ORG_DUE_TIME,
                                                    :LOTPDS_LIST_N.SCH_DUE_TIME,
                                                    :LOTPDS_LIST_N.OPER_IN_TIME,
                                                    :LOTPDS_LIST_N.LAST_TRAN_CODE,
                                                    :LOTPDS_LIST_N.RECIPE,
                                                    :LOTPDS_LIST_N.RESERVE_RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 64;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1202;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(LOTPDS_LIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(LOTPDS_LIST_N.RES_OPER_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(LOTPDS_LIST_N.RES_OPER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(LOTPDS_LIST_N.LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(LOTPDS_LIST_N.SET_OPER);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(LOTPDS_LIST_N.SET_RESG_ID);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(LOTPDS_LIST_N.SET_RES_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(LOTPDS_LIST_N.DSP_ID);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(LOTPDS_LIST_N.RULE_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(LOTPDS_LIST_N.TEMP_BATCH_ID);
            sqlstm.sqhstl[9] = (unsigned int  )25;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(LOTPDS_LIST_N.TEMP_BATCH_SEQ);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(LOTPDS_LIST_N.CUR_OPER);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(LOTPDS_LIST_N.REFERENCE_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(LOTPDS_LIST_N.UNSELECTED_FLAG);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(LOTPDS_LIST_N.LOT_RESV_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(LOTPDS_LIST_N.LOT_RESV_TIME);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(LOTPDS_LIST_N.CAPABLE_FLAG);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(LOTPDS_LIST_N.PRI_ADJUST_FLAG);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(LOTPDS_LIST_N.PRIORITY_SCORE);
            sqlstm.sqhstl[18] = (unsigned int  )101;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(LOTPDS_LIST_N.PRIORITY_SUPPORT);
            sqlstm.sqhstl[19] = (unsigned int  )101;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(LOTPDS_LIST_N.HIST_SEQ);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(LOTPDS_LIST_N.PRI_ADJUST_REASON);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(LOTPDS_LIST_N.TRIGGER_BY);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(LOTPDS_LIST_N.DSP_REASON);
            sqlstm.sqhstl[23] = (unsigned int  )1001;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(LOTPDS_LIST_N.UNSELECT_REASON);
            sqlstm.sqhstl[24] = (unsigned int  )1001;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(LOTPDS_LIST_N.CAPABLE_REASON);
            sqlstm.sqhstl[25] = (unsigned int  )1001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_1);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_2);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_3);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_4);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_5);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_6);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_7);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_8);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_9);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(LOTPDS_LIST_N.PDS_CMF_10);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(LOTPDS_LIST_N.CREATE_USER_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(LOTPDS_LIST_N.CREATE_TIME);
            sqlstm.sqhstl[37] = (unsigned int  )15;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(LOTPDS_LIST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(LOTPDS_LIST_N.UPDATE_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )15;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(LOTPDS_LIST_N.MAT_ID);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(LOTPDS_LIST_N.MAT_VER);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(LOTPDS_LIST_N.FLOW);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(LOTPDS_LIST_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(LOTPDS_LIST_N.OPER);
            sqlstm.sqhstl[44] = (unsigned int  )11;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(LOTPDS_LIST_N.QTY_1);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(LOTPDS_LIST_N.QTY_2);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(LOTPDS_LIST_N.QTY_3);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(LOTPDS_LIST_N.LOT_TYPE);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(LOTPDS_LIST_N.OWNER_CODE);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(LOTPDS_LIST_N.CREATE_CODE);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(LOTPDS_LIST_N.LOT_PRIORITY);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(LOTPDS_LIST_N.LOT_STATUS);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(LOTPDS_LIST_N.HOLD_FLAG);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(LOTPDS_LIST_N.RWK_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(LOTPDS_LIST_N.NSTD_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(LOTPDS_LIST_N.START_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(LOTPDS_LIST_N.REP_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(LOTPDS_LIST_N.ORG_DUE_TIME);
            sqlstm.sqhstl[58] = (unsigned int  )15;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(LOTPDS_LIST_N.SCH_DUE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(LOTPDS_LIST_N.OPER_IN_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(LOTPDS_LIST_N.LAST_TRAN_CODE);
            sqlstm.sqhstl[61] = (unsigned int  )13;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(LOTPDS_LIST_N.RECIPE);
            sqlstm.sqhstl[62] = (unsigned int  )25;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(LOTPDS_LIST_N.RESERVE_RES_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
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
        DBC_del_null_lotpds_list(&LOTPDS_LIST_N, LOTPDS_LIST);
    }
    DB_stop_query_timer("DBC_fetch_lotpds_list", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_lotpds_list(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_LOTPDS_LIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 64;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1473;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 2:
            /* EXEC SQL CLOSE DBC_LOTPDS_LIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 64;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1488;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 3:
            /* EXEC SQL CLOSE DBC_LOTPDS_LIST_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 64;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1503;
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
    DB_stop_query_timer("DBC_close_lotpds_list", sel_type);
}

/* Initialize Function */
void DBC_init_lotpds_list(struct LOTPDS_LIST_TAG *LOTPDS_LIST)
{
    /* memset by Space */
    memset(LOTPDS_LIST, ' ', sizeof(struct LOTPDS_LIST_TAG));
    
    LOTPDS_LIST->HIST_SEQ = 0;
    LOTPDS_LIST->MAT_VER = 0;
    LOTPDS_LIST->FLOW_SEQ_NUM = 0;
    LOTPDS_LIST->QTY_1 = 0;
    LOTPDS_LIST->QTY_2 = 0;
    LOTPDS_LIST->QTY_3 = 0;
}


/* Add Null Function */
void DBC_add_null_lotpds_list(struct LOTPDS_LIST_N_TAG *LOTPDS_LIST_N, struct LOTPDS_LIST_TAG *LOTPDS_LIST)
{
    /* memset by NULL */
    memset(LOTPDS_LIST_N, '\0', sizeof(struct LOTPDS_LIST_N_TAG));
    
    MEMCPY_AN(LOTPDS_LIST_N->FACTORY, LOTPDS_LIST->FACTORY, sizeof(LOTPDS_LIST->FACTORY));
    LOTPDS_LIST_N->RES_OPER_FLAG[0] = LOTPDS_LIST->RES_OPER_FLAG;
    MEMCPY_AN(LOTPDS_LIST_N->RES_OPER_ID, LOTPDS_LIST->RES_OPER_ID, sizeof(LOTPDS_LIST->RES_OPER_ID));
    MEMCPY_AN(LOTPDS_LIST_N->LOT_ID, LOTPDS_LIST->LOT_ID, sizeof(LOTPDS_LIST->LOT_ID));
    MEMCPY_AN(LOTPDS_LIST_N->SET_OPER, LOTPDS_LIST->SET_OPER, sizeof(LOTPDS_LIST->SET_OPER));
    MEMCPY_AN(LOTPDS_LIST_N->SET_RESG_ID, LOTPDS_LIST->SET_RESG_ID, sizeof(LOTPDS_LIST->SET_RESG_ID));
    MEMCPY_AN(LOTPDS_LIST_N->SET_RES_ID, LOTPDS_LIST->SET_RES_ID, sizeof(LOTPDS_LIST->SET_RES_ID));
    MEMCPY_AN(LOTPDS_LIST_N->DSP_ID, LOTPDS_LIST->DSP_ID, sizeof(LOTPDS_LIST->DSP_ID));
    MEMCPY_AN(LOTPDS_LIST_N->RULE_ID, LOTPDS_LIST->RULE_ID, sizeof(LOTPDS_LIST->RULE_ID));
    MEMCPY_AN(LOTPDS_LIST_N->TEMP_BATCH_ID, LOTPDS_LIST->TEMP_BATCH_ID, sizeof(LOTPDS_LIST->TEMP_BATCH_ID));
    LOTPDS_LIST_N->TEMP_BATCH_SEQ = LOTPDS_LIST->TEMP_BATCH_SEQ;  
    MEMCPY_AN(LOTPDS_LIST_N->CUR_OPER, LOTPDS_LIST->CUR_OPER, sizeof(LOTPDS_LIST->CUR_OPER));
    MEMCPY_AN(LOTPDS_LIST_N->REFERENCE_OPER, LOTPDS_LIST->REFERENCE_OPER, sizeof(LOTPDS_LIST->REFERENCE_OPER));
    LOTPDS_LIST_N->UNSELECTED_FLAG[0] = LOTPDS_LIST->UNSELECTED_FLAG;
    LOTPDS_LIST_N->LOT_RESV_FLAG[0] = LOTPDS_LIST->LOT_RESV_FLAG;
    MEMCPY_AN(LOTPDS_LIST_N->LOT_RESV_TIME, LOTPDS_LIST->LOT_RESV_TIME, sizeof(LOTPDS_LIST->LOT_RESV_TIME));
    LOTPDS_LIST_N->CAPABLE_FLAG[0] = LOTPDS_LIST->CAPABLE_FLAG;
    LOTPDS_LIST_N->PRI_ADJUST_FLAG[0] = LOTPDS_LIST->PRI_ADJUST_FLAG;
    MEMCPY_AN(LOTPDS_LIST_N->PRIORITY_SCORE, LOTPDS_LIST->PRIORITY_SCORE, sizeof(LOTPDS_LIST->PRIORITY_SCORE));
    MEMCPY_AN(LOTPDS_LIST_N->PRIORITY_SUPPORT, LOTPDS_LIST->PRIORITY_SUPPORT, sizeof(LOTPDS_LIST->PRIORITY_SUPPORT));
    LOTPDS_LIST_N->HIST_SEQ = LOTPDS_LIST->HIST_SEQ;
    MEMCPY_AN(LOTPDS_LIST_N->PRI_ADJUST_REASON, LOTPDS_LIST->PRI_ADJUST_REASON, sizeof(LOTPDS_LIST->PRI_ADJUST_REASON));
    MEMCPY_AN(LOTPDS_LIST_N->TRIGGER_BY, LOTPDS_LIST->TRIGGER_BY, sizeof(LOTPDS_LIST->TRIGGER_BY));
    MEMCPY_AN(LOTPDS_LIST_N->DSP_REASON, LOTPDS_LIST->DSP_REASON, sizeof(LOTPDS_LIST->DSP_REASON));
    MEMCPY_AN(LOTPDS_LIST_N->UNSELECT_REASON, LOTPDS_LIST->UNSELECT_REASON, sizeof(LOTPDS_LIST->UNSELECT_REASON));
    MEMCPY_AN(LOTPDS_LIST_N->CAPABLE_REASON, LOTPDS_LIST->CAPABLE_REASON, sizeof(LOTPDS_LIST->CAPABLE_REASON));

    MEMCPY_AN(LOTPDS_LIST_N->PDS_CMF_1, LOTPDS_LIST->PDS_CMF_1, sizeof(LOTPDS_LIST->PDS_CMF_1));
    MEMCPY_AN(LOTPDS_LIST_N->PDS_CMF_2, LOTPDS_LIST->PDS_CMF_2, sizeof(LOTPDS_LIST->PDS_CMF_2));
    MEMCPY_AN(LOTPDS_LIST_N->PDS_CMF_3, LOTPDS_LIST->PDS_CMF_3, sizeof(LOTPDS_LIST->PDS_CMF_3));
    MEMCPY_AN(LOTPDS_LIST_N->PDS_CMF_4, LOTPDS_LIST->PDS_CMF_4, sizeof(LOTPDS_LIST->PDS_CMF_4));
    MEMCPY_AN(LOTPDS_LIST_N->PDS_CMF_5, LOTPDS_LIST->PDS_CMF_5, sizeof(LOTPDS_LIST->PDS_CMF_5));
    MEMCPY_AN(LOTPDS_LIST_N->PDS_CMF_6, LOTPDS_LIST->PDS_CMF_6, sizeof(LOTPDS_LIST->PDS_CMF_6));
    MEMCPY_AN(LOTPDS_LIST_N->PDS_CMF_7, LOTPDS_LIST->PDS_CMF_7, sizeof(LOTPDS_LIST->PDS_CMF_7));
    MEMCPY_AN(LOTPDS_LIST_N->PDS_CMF_8, LOTPDS_LIST->PDS_CMF_8, sizeof(LOTPDS_LIST->PDS_CMF_8));
    MEMCPY_AN(LOTPDS_LIST_N->PDS_CMF_9, LOTPDS_LIST->PDS_CMF_9, sizeof(LOTPDS_LIST->PDS_CMF_9));
    MEMCPY_AN(LOTPDS_LIST_N->PDS_CMF_10, LOTPDS_LIST->PDS_CMF_10, sizeof(LOTPDS_LIST->PDS_CMF_10));

    MEMCPY_AN(LOTPDS_LIST_N->CREATE_USER_ID, LOTPDS_LIST->CREATE_USER_ID, sizeof(LOTPDS_LIST->CREATE_USER_ID));
    MEMCPY_AN(LOTPDS_LIST_N->CREATE_TIME, LOTPDS_LIST->CREATE_TIME, sizeof(LOTPDS_LIST->CREATE_TIME));
    MEMCPY_AN(LOTPDS_LIST_N->UPDATE_USER_ID, LOTPDS_LIST->UPDATE_USER_ID, sizeof(LOTPDS_LIST->UPDATE_USER_ID));
    MEMCPY_AN(LOTPDS_LIST_N->UPDATE_TIME, LOTPDS_LIST->UPDATE_TIME, sizeof(LOTPDS_LIST->UPDATE_TIME));
    MEMCPY_AN(LOTPDS_LIST_N->MAT_ID, LOTPDS_LIST->MAT_ID, sizeof(LOTPDS_LIST->MAT_ID));
    LOTPDS_LIST_N->MAT_VER = LOTPDS_LIST->MAT_VER;  
    MEMCPY_AN(LOTPDS_LIST_N->FLOW, LOTPDS_LIST->FLOW, sizeof(LOTPDS_LIST->FLOW));
    LOTPDS_LIST_N->FLOW_SEQ_NUM = LOTPDS_LIST->FLOW_SEQ_NUM;      
    MEMCPY_AN(LOTPDS_LIST_N->OPER, LOTPDS_LIST->OPER, sizeof(LOTPDS_LIST->OPER));
    LOTPDS_LIST_N->QTY_1 = LOTPDS_LIST->QTY_1;
    LOTPDS_LIST_N->QTY_2 = LOTPDS_LIST->QTY_2;
    LOTPDS_LIST_N->QTY_3 = LOTPDS_LIST->QTY_3;
    LOTPDS_LIST_N->LOT_TYPE[0] = LOTPDS_LIST->LOT_TYPE;
    MEMCPY_AN(LOTPDS_LIST_N->OWNER_CODE, LOTPDS_LIST->OWNER_CODE, sizeof(LOTPDS_LIST->OWNER_CODE));
    MEMCPY_AN(LOTPDS_LIST_N->CREATE_CODE, LOTPDS_LIST->CREATE_CODE, sizeof(LOTPDS_LIST->CREATE_CODE));
    LOTPDS_LIST_N->LOT_PRIORITY[0] = LOTPDS_LIST->LOT_PRIORITY;
    MEMCPY_AN(LOTPDS_LIST_N->LOT_STATUS, LOTPDS_LIST->LOT_STATUS, sizeof(LOTPDS_LIST->LOT_STATUS));
    LOTPDS_LIST_N->HOLD_FLAG[0] = LOTPDS_LIST->HOLD_FLAG;
    LOTPDS_LIST_N->RWK_FLAG[0] = LOTPDS_LIST->RWK_FLAG;
    LOTPDS_LIST_N->NSTD_FLAG[0] = LOTPDS_LIST->NSTD_FLAG;
    LOTPDS_LIST_N->START_FLAG[0] = LOTPDS_LIST->START_FLAG;
    LOTPDS_LIST_N->REP_FLAG[0] = LOTPDS_LIST->REP_FLAG;
    MEMCPY_AN(LOTPDS_LIST_N->ORG_DUE_TIME, LOTPDS_LIST->ORG_DUE_TIME, sizeof(LOTPDS_LIST->ORG_DUE_TIME));
    MEMCPY_AN(LOTPDS_LIST_N->SCH_DUE_TIME, LOTPDS_LIST->SCH_DUE_TIME, sizeof(LOTPDS_LIST->SCH_DUE_TIME));
    MEMCPY_AN(LOTPDS_LIST_N->OPER_IN_TIME, LOTPDS_LIST->OPER_IN_TIME, sizeof(LOTPDS_LIST->OPER_IN_TIME));
    MEMCPY_AN(LOTPDS_LIST_N->LAST_TRAN_CODE, LOTPDS_LIST->LAST_TRAN_CODE, sizeof(LOTPDS_LIST->LAST_TRAN_CODE));
    MEMCPY_AN(LOTPDS_LIST_N->RECIPE, LOTPDS_LIST->RECIPE, sizeof(LOTPDS_LIST->RECIPE));
    MEMCPY_AN(LOTPDS_LIST_N->RESERVE_RES_ID, LOTPDS_LIST->RESERVE_RES_ID, sizeof(LOTPDS_LIST->RESERVE_RES_ID));
}


/* Del Null Function */
void DBC_del_null_lotpds_list(struct LOTPDS_LIST_N_TAG *LOTPDS_LIST_N, struct LOTPDS_LIST_TAG *LOTPDS_LIST)
{
    MEMCPY_DN(LOTPDS_LIST->FACTORY, LOTPDS_LIST_N->FACTORY, sizeof(LOTPDS_LIST->FACTORY));
    LOTPDS_LIST->RES_OPER_FLAG = LOTPDS_LIST_N->RES_OPER_FLAG[0];
    MEMCPY_DN(LOTPDS_LIST->RES_OPER_ID, LOTPDS_LIST_N->RES_OPER_ID, sizeof(LOTPDS_LIST->RES_OPER_ID));
    MEMCPY_DN(LOTPDS_LIST->LOT_ID, LOTPDS_LIST_N->LOT_ID, sizeof(LOTPDS_LIST->LOT_ID));
    MEMCPY_DN(LOTPDS_LIST->SET_OPER, LOTPDS_LIST_N->SET_OPER, sizeof(LOTPDS_LIST->SET_OPER));
    MEMCPY_DN(LOTPDS_LIST->SET_RESG_ID, LOTPDS_LIST_N->SET_RESG_ID, sizeof(LOTPDS_LIST->SET_RESG_ID));
    MEMCPY_DN(LOTPDS_LIST->SET_RES_ID, LOTPDS_LIST_N->SET_RES_ID, sizeof(LOTPDS_LIST->SET_RES_ID));
    MEMCPY_DN(LOTPDS_LIST->DSP_ID, LOTPDS_LIST_N->DSP_ID, sizeof(LOTPDS_LIST->DSP_ID));
    MEMCPY_DN(LOTPDS_LIST->RULE_ID, LOTPDS_LIST_N->RULE_ID, sizeof(LOTPDS_LIST->RULE_ID));
    MEMCPY_DN(LOTPDS_LIST->TEMP_BATCH_ID, LOTPDS_LIST_N->TEMP_BATCH_ID, sizeof(LOTPDS_LIST->TEMP_BATCH_ID));
    LOTPDS_LIST->TEMP_BATCH_SEQ = LOTPDS_LIST_N->TEMP_BATCH_SEQ;
    MEMCPY_DN(LOTPDS_LIST->CUR_OPER, LOTPDS_LIST_N->CUR_OPER, sizeof(LOTPDS_LIST->CUR_OPER));
    MEMCPY_DN(LOTPDS_LIST->REFERENCE_OPER, LOTPDS_LIST_N->REFERENCE_OPER, sizeof(LOTPDS_LIST->REFERENCE_OPER));
    LOTPDS_LIST->UNSELECTED_FLAG = LOTPDS_LIST_N->UNSELECTED_FLAG[0];
    LOTPDS_LIST->LOT_RESV_FLAG = LOTPDS_LIST_N->LOT_RESV_FLAG[0];
    MEMCPY_DN(LOTPDS_LIST->LOT_RESV_TIME, LOTPDS_LIST_N->LOT_RESV_TIME, sizeof(LOTPDS_LIST->LOT_RESV_TIME));
    LOTPDS_LIST->CAPABLE_FLAG = LOTPDS_LIST_N->CAPABLE_FLAG[0];
    LOTPDS_LIST->PRI_ADJUST_FLAG = LOTPDS_LIST_N->PRI_ADJUST_FLAG[0];
    MEMCPY_DN(LOTPDS_LIST->PRIORITY_SCORE, LOTPDS_LIST_N->PRIORITY_SCORE, sizeof(LOTPDS_LIST->PRIORITY_SCORE));
    MEMCPY_DN(LOTPDS_LIST->PRIORITY_SUPPORT, LOTPDS_LIST_N->PRIORITY_SUPPORT, sizeof(LOTPDS_LIST->PRIORITY_SUPPORT));
    LOTPDS_LIST->HIST_SEQ = LOTPDS_LIST_N->HIST_SEQ;
    MEMCPY_DN(LOTPDS_LIST->PRI_ADJUST_REASON, LOTPDS_LIST_N->PRI_ADJUST_REASON, sizeof(LOTPDS_LIST->PRI_ADJUST_REASON));
    MEMCPY_DN(LOTPDS_LIST->TRIGGER_BY, LOTPDS_LIST_N->TRIGGER_BY, sizeof(LOTPDS_LIST->TRIGGER_BY));
    MEMCPY_DN(LOTPDS_LIST->DSP_REASON, LOTPDS_LIST_N->DSP_REASON, sizeof(LOTPDS_LIST->DSP_REASON));
    MEMCPY_DN(LOTPDS_LIST->UNSELECT_REASON, LOTPDS_LIST_N->UNSELECT_REASON, sizeof(LOTPDS_LIST->UNSELECT_REASON));
    MEMCPY_DN(LOTPDS_LIST->CAPABLE_REASON, LOTPDS_LIST_N->CAPABLE_REASON, sizeof(LOTPDS_LIST->CAPABLE_REASON));
   
    MEMCPY_DN(LOTPDS_LIST->PDS_CMF_1, LOTPDS_LIST_N->PDS_CMF_1, sizeof(LOTPDS_LIST->PDS_CMF_1));
    MEMCPY_DN(LOTPDS_LIST->PDS_CMF_2, LOTPDS_LIST_N->PDS_CMF_2, sizeof(LOTPDS_LIST->PDS_CMF_2));
    MEMCPY_DN(LOTPDS_LIST->PDS_CMF_3, LOTPDS_LIST_N->PDS_CMF_3, sizeof(LOTPDS_LIST->PDS_CMF_3));
    MEMCPY_DN(LOTPDS_LIST->PDS_CMF_4, LOTPDS_LIST_N->PDS_CMF_4, sizeof(LOTPDS_LIST->PDS_CMF_4));
    MEMCPY_DN(LOTPDS_LIST->PDS_CMF_5, LOTPDS_LIST_N->PDS_CMF_5, sizeof(LOTPDS_LIST->PDS_CMF_5));
    MEMCPY_DN(LOTPDS_LIST->PDS_CMF_6, LOTPDS_LIST_N->PDS_CMF_6, sizeof(LOTPDS_LIST->PDS_CMF_6));
    MEMCPY_DN(LOTPDS_LIST->PDS_CMF_7, LOTPDS_LIST_N->PDS_CMF_7, sizeof(LOTPDS_LIST->PDS_CMF_7));
    MEMCPY_DN(LOTPDS_LIST->PDS_CMF_8, LOTPDS_LIST_N->PDS_CMF_8, sizeof(LOTPDS_LIST->PDS_CMF_8));
    MEMCPY_DN(LOTPDS_LIST->PDS_CMF_9, LOTPDS_LIST_N->PDS_CMF_9, sizeof(LOTPDS_LIST->PDS_CMF_9));
    MEMCPY_DN(LOTPDS_LIST->PDS_CMF_10, LOTPDS_LIST_N->PDS_CMF_10, sizeof(LOTPDS_LIST->PDS_CMF_10));

    MEMCPY_DN(LOTPDS_LIST->CREATE_USER_ID, LOTPDS_LIST_N->CREATE_USER_ID, sizeof(LOTPDS_LIST->CREATE_USER_ID));
    MEMCPY_DN(LOTPDS_LIST->CREATE_TIME, LOTPDS_LIST_N->CREATE_TIME, sizeof(LOTPDS_LIST->CREATE_TIME));
    MEMCPY_DN(LOTPDS_LIST->UPDATE_USER_ID, LOTPDS_LIST_N->UPDATE_USER_ID, sizeof(LOTPDS_LIST->UPDATE_USER_ID));
    MEMCPY_DN(LOTPDS_LIST->UPDATE_TIME, LOTPDS_LIST_N->UPDATE_TIME, sizeof(LOTPDS_LIST->UPDATE_TIME));
    
    MEMCPY_DN(LOTPDS_LIST->MAT_ID, LOTPDS_LIST_N->MAT_ID, sizeof(LOTPDS_LIST->MAT_ID));
    LOTPDS_LIST->MAT_VER = LOTPDS_LIST_N->MAT_VER;
    MEMCPY_DN(LOTPDS_LIST->FLOW, LOTPDS_LIST_N->FLOW, sizeof(LOTPDS_LIST->FLOW));
    LOTPDS_LIST->FLOW_SEQ_NUM = LOTPDS_LIST_N->FLOW_SEQ_NUM;
    MEMCPY_DN(LOTPDS_LIST->OPER, LOTPDS_LIST_N->OPER, sizeof(LOTPDS_LIST->OPER));
    LOTPDS_LIST->QTY_1 = LOTPDS_LIST_N->QTY_1;
    LOTPDS_LIST->QTY_2 = LOTPDS_LIST_N->QTY_2;
    LOTPDS_LIST->QTY_3 = LOTPDS_LIST_N->QTY_3;
    LOTPDS_LIST->LOT_TYPE = LOTPDS_LIST_N->LOT_TYPE[0];
    MEMCPY_DN(LOTPDS_LIST->OWNER_CODE, LOTPDS_LIST_N->OWNER_CODE, sizeof(LOTPDS_LIST->OWNER_CODE));
    MEMCPY_DN(LOTPDS_LIST->CREATE_CODE, LOTPDS_LIST_N->CREATE_CODE, sizeof(LOTPDS_LIST->CREATE_CODE));
    LOTPDS_LIST->LOT_PRIORITY = LOTPDS_LIST_N->LOT_PRIORITY[0];
    MEMCPY_DN(LOTPDS_LIST->LOT_STATUS, LOTPDS_LIST_N->LOT_STATUS, sizeof(LOTPDS_LIST->LOT_STATUS));
    LOTPDS_LIST->HOLD_FLAG = LOTPDS_LIST_N->HOLD_FLAG[0];
    LOTPDS_LIST->RWK_FLAG = LOTPDS_LIST_N->RWK_FLAG[0];
    LOTPDS_LIST->NSTD_FLAG = LOTPDS_LIST_N->NSTD_FLAG[0];
    LOTPDS_LIST->START_FLAG = LOTPDS_LIST_N->START_FLAG[0];
    LOTPDS_LIST->REP_FLAG = LOTPDS_LIST_N->REP_FLAG[0];
    MEMCPY_DN(LOTPDS_LIST->ORG_DUE_TIME, LOTPDS_LIST_N->ORG_DUE_TIME, sizeof(LOTPDS_LIST->ORG_DUE_TIME));
    MEMCPY_DN(LOTPDS_LIST->SCH_DUE_TIME, LOTPDS_LIST_N->SCH_DUE_TIME, sizeof(LOTPDS_LIST->SCH_DUE_TIME));
    MEMCPY_DN(LOTPDS_LIST->OPER_IN_TIME, LOTPDS_LIST_N->OPER_IN_TIME, sizeof(LOTPDS_LIST->OPER_IN_TIME));
    MEMCPY_DN(LOTPDS_LIST->LAST_TRAN_CODE, LOTPDS_LIST_N->LAST_TRAN_CODE, sizeof(LOTPDS_LIST->LAST_TRAN_CODE));
    MEMCPY_DN(LOTPDS_LIST->RECIPE, LOTPDS_LIST_N->RECIPE, sizeof(LOTPDS_LIST->RECIPE));
    MEMCPY_DN(LOTPDS_LIST->RESERVE_RES_ID, LOTPDS_LIST_N->RESERVE_RES_ID, sizeof(LOTPDS_LIST->RESERVE_RES_ID));
}
