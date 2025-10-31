
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
    "DBC_mwiplotlos.pc"
};


static unsigned int sqlctx = 9144099;


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
            void  *sqhstv[44];
   unsigned int   sqhstl[44];
            int   sqhsts[44];
            void  *sqindv[44];
            int   sqinds[44];
   unsigned int   sqharm[44];
   unsigned int   *sqharc[44];
   unsigned short  sqadto[44];
   unsigned short  sqtdso[44];
} sqlstm = {13,44};

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
"select LOT_ID ,HIST_SEQ ,QTY_FLAG ,TRAN_TIME ,HIST_DEL_FLAG ,FACTORY ,MAT_I\
D ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,RES_ID ,CAUSE_FLOW ,CAUSE_OPER ,CAUSE_R\
ES_ID ,NEW_QTY ,OLD_QTY ,TOTAL_LOSS_QTY ,LOSS_CODE_1 ,LOSS_CODE_2 ,LOSS_CODE_\
3 ,LOSS_CODE_4 ,LOSS_CODE_5 ,LOSS_CODE_6 ,LOSS_CODE_7 ,LOSS_CODE_8 ,LOSS_CODE\
_9 ,LOSS_CODE_10 ,LOSS_QTY_1 ,LOSS_QTY_2 ,LOSS_QTY_3 ,LOSS_QTY_4 ,LOSS_QTY_5 \
,LOSS_QTY_6 ,LOSS_QTY_7 ,LOSS_QTY_8 ,LOSS_QTY_9 ,LOSS_QTY_10 ,LOSS_COMMENT_1 \
,LOSS_COMMENT_2 ,LOSS_COMMENT_3  from MWIPLOTLOS where (LOT_ID=:b0 and HIST_S\
EQ=:b1) order by QTY_FLAG asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,763,0,4,42,0,0,44,3,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,
196,0,0,2,775,0,4,164,0,0,44,3,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,
97,0,0,1,3,0,0,1,97,0,0,
387,0,0,3,97,0,4,290,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
418,0,0,4,78,0,4,299,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,
445,0,0,5,79,0,2,334,0,0,3,3,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,
472,0,0,6,41,0,2,341,0,0,1,1,0,1,0,1,97,0,0,
491,0,0,7,673,0,3,368,0,0,41,41,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
670,0,0,8,680,0,5,473,0,0,41,41,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,
0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
849,0,0,9,76,0,5,518,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
876,0,0,10,579,0,9,606,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
899,0,0,11,0,0,17,719,0,0,1,1,0,1,0,1,97,0,0,
918,0,0,11,0,0,45,721,0,0,0,0,0,1,0,
933,0,0,10,0,0,13,751,0,0,41,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1112,0,0,11,0,0,13,796,0,0,42,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,
1295,0,0,10,0,0,15,868,0,0,0,0,0,1,0,
1310,0,0,11,0,0,15,872,0,0,0,0,0,1,0,
};


/*********************************************************************
**
** File Name : DBC_mwiplotlos.pc
** Description : Table Access Function Source File
** Create date : 2004/12/14 14:26:26
**
** Generated by DB Common Generator
** Copyright (C), MIRACOM,INC.
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
void DBC_add_null_mwiplotlos(struct MWIPLOTLOS_N_TAG *MWIPLOTLOS_N, struct MWIPLOTLOS_TAG *MWIPLOTLOS);
void DBC_del_null_mwiplotlos(struct MWIPLOTLOS_N_TAG *MWIPLOTLOS_N, struct MWIPLOTLOS_TAG *MWIPLOTLOS);


/* SQL SELECT Function */
void DBC_select_mwiplotlos(int sel_type, struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTLOS_N_TAG MWIPLOTLOS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwiplotlos(&MWIPLOTLOS_N, MWIPLOTLOS);
    DB_error_code = 0;

    switch(sel_type)
    {
    case 1:
        /* EXEC SQL SELECT 
                     LOT_ID,
                     HIST_SEQ,
                     QTY_FLAG,
                     TRAN_TIME,
                     HIST_DEL_FLAG,
                     FACTORY,
                     MAT_ID,
                     MAT_VER,
                     FLOW,
                     FLOW_SEQ_NUM,
                     OPER,
                     RES_ID,
                     CAUSE_FLOW,
                     CAUSE_OPER,
                     CAUSE_RES_ID,
                     NEW_QTY,
                     OLD_QTY,
                     TOTAL_LOSS_QTY,
                     LOSS_CODE_1,
                     LOSS_CODE_2,
                     LOSS_CODE_3,
                     LOSS_CODE_4,
                     LOSS_CODE_5,
                     LOSS_CODE_6,
                     LOSS_CODE_7,
                     LOSS_CODE_8,
                     LOSS_CODE_9,
                     LOSS_CODE_10,
                     LOSS_QTY_1,
                     LOSS_QTY_2,
                     LOSS_QTY_3,
                     LOSS_QTY_4,
                     LOSS_QTY_5,
                     LOSS_QTY_6,
                     LOSS_QTY_7,
                     LOSS_QTY_8,
                     LOSS_QTY_9,
                     LOSS_QTY_10,
                     LOSS_COMMENT_1,
                     LOSS_COMMENT_2,
                     LOSS_COMMENT_3
          INTO 
              :MWIPLOTLOS_N.LOT_ID,
              :MWIPLOTLOS_N.HIST_SEQ,
              :MWIPLOTLOS_N.QTY_FLAG,
              :MWIPLOTLOS_N.TRAN_TIME,
              :MWIPLOTLOS_N.HIST_DEL_FLAG,
              :MWIPLOTLOS_N.FACTORY,
              :MWIPLOTLOS_N.MAT_ID,
              :MWIPLOTLOS_N.MAT_VER,
              :MWIPLOTLOS_N.FLOW,
              :MWIPLOTLOS_N.FLOW_SEQ_NUM,
              :MWIPLOTLOS_N.OPER,
              :MWIPLOTLOS_N.RES_ID,
              :MWIPLOTLOS_N.CAUSE_FLOW,
              :MWIPLOTLOS_N.CAUSE_OPER,
              :MWIPLOTLOS_N.CAUSE_RES_ID,
              :MWIPLOTLOS_N.NEW_QTY,
              :MWIPLOTLOS_N.OLD_QTY,
              :MWIPLOTLOS_N.TOTAL_LOSS_QTY,
              :MWIPLOTLOS_N.LOSS_CODE_1,
              :MWIPLOTLOS_N.LOSS_CODE_2,
              :MWIPLOTLOS_N.LOSS_CODE_3,
              :MWIPLOTLOS_N.LOSS_CODE_4,
              :MWIPLOTLOS_N.LOSS_CODE_5,
              :MWIPLOTLOS_N.LOSS_CODE_6,
              :MWIPLOTLOS_N.LOSS_CODE_7,
              :MWIPLOTLOS_N.LOSS_CODE_8,
              :MWIPLOTLOS_N.LOSS_CODE_9,
              :MWIPLOTLOS_N.LOSS_CODE_10,
              :MWIPLOTLOS_N.LOSS_QTY_1,
              :MWIPLOTLOS_N.LOSS_QTY_2,
              :MWIPLOTLOS_N.LOSS_QTY_3,
              :MWIPLOTLOS_N.LOSS_QTY_4,
              :MWIPLOTLOS_N.LOSS_QTY_5,
              :MWIPLOTLOS_N.LOSS_QTY_6,
              :MWIPLOTLOS_N.LOSS_QTY_7,
              :MWIPLOTLOS_N.LOSS_QTY_8,
              :MWIPLOTLOS_N.LOSS_QTY_9,
              :MWIPLOTLOS_N.LOSS_QTY_10,
              :MWIPLOTLOS_N.LOSS_COMMENT_1,
              :MWIPLOTLOS_N.LOSS_COMMENT_2,
              :MWIPLOTLOS_N.LOSS_COMMENT_3
          FROM MWIPLOTLOS
          WHERE LOT_ID = :MWIPLOTLOS_N.LOT_ID
              AND HIST_SEQ = :MWIPLOTLOS_N.HIST_SEQ
              AND QTY_FLAG = :MWIPLOTLOS_N.QTY_FLAG; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select LOT_ID ,HIST_SEQ ,QTY_FLAG ,TRAN_TIME ,HIST_D\
EL_FLAG ,FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,RES_ID ,CAUSE_FL\
OW ,CAUSE_OPER ,CAUSE_RES_ID ,NEW_QTY ,OLD_QTY ,TOTAL_LOSS_QTY ,LOSS_CODE_1 ,\
LOSS_CODE_2 ,LOSS_CODE_3 ,LOSS_CODE_4 ,LOSS_CODE_5 ,LOSS_CODE_6 ,LOSS_CODE_7 \
,LOSS_CODE_8 ,LOSS_CODE_9 ,LOSS_CODE_10 ,LOSS_QTY_1 ,LOSS_QTY_2 ,LOSS_QTY_3 ,\
LOSS_QTY_4 ,LOSS_QTY_5 ,LOSS_QTY_6 ,LOSS_QTY_7 ,LOSS_QTY_8 ,LOSS_QTY_9 ,LOSS_\
QTY_10 ,LOSS_COMMENT_1 ,LOSS_COMMENT_2 ,LOSS_COMMENT_3 into :b0,:b1,:b2,:b3,:\
b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20\
,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:\
b36,:b37,:b38,:b39,:b40  from MWIPLOTLOS where ((LOT_ID=:b0 and HIST_SEQ=:b1)\
 and QTY_FLAG=:b2)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[0] = (unsigned int  )26;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
        sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)(MWIPLOTLOS_N.QTY_FLAG);
        sqlstm.sqhstl[2] = (unsigned int  )2;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (         void  *)(MWIPLOTLOS_N.TRAN_TIME);
        sqlstm.sqhstl[3] = (unsigned int  )15;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         void  *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned int  )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (         void  *)(MWIPLOTLOS_N.HIST_DEL_FLAG);
        sqlstm.sqhstl[4] = (unsigned int  )2;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         void  *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned int  )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (         void  *)(MWIPLOTLOS_N.FACTORY);
        sqlstm.sqhstl[5] = (unsigned int  )11;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         void  *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned int  )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (         void  *)(MWIPLOTLOS_N.MAT_ID);
        sqlstm.sqhstl[6] = (unsigned int  )31;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         void  *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned int  )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (         void  *)&(MWIPLOTLOS_N.MAT_VER);
        sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         void  *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned int  )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (         void  *)(MWIPLOTLOS_N.FLOW);
        sqlstm.sqhstl[8] = (unsigned int  )21;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         void  *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned int  )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (         void  *)&(MWIPLOTLOS_N.FLOW_SEQ_NUM);
        sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         void  *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned int  )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (         void  *)(MWIPLOTLOS_N.OPER);
        sqlstm.sqhstl[10] = (unsigned int  )11;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         void  *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned int  )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (         void  *)(MWIPLOTLOS_N.RES_ID);
        sqlstm.sqhstl[11] = (unsigned int  )21;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         void  *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned int  )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (         void  *)(MWIPLOTLOS_N.CAUSE_FLOW);
        sqlstm.sqhstl[12] = (unsigned int  )21;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         void  *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned int  )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (         void  *)(MWIPLOTLOS_N.CAUSE_OPER);
        sqlstm.sqhstl[13] = (unsigned int  )11;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         void  *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned int  )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (         void  *)(MWIPLOTLOS_N.CAUSE_RES_ID);
        sqlstm.sqhstl[14] = (unsigned int  )21;
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         void  *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned int  )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (         void  *)&(MWIPLOTLOS_N.NEW_QTY);
        sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         void  *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned int  )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (         void  *)&(MWIPLOTLOS_N.OLD_QTY);
        sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         void  *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned int  )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (         void  *)&(MWIPLOTLOS_N.TOTAL_LOSS_QTY);
        sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         void  *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned int  )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_1);
        sqlstm.sqhstl[18] = (unsigned int  )11;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         void  *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned int  )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_2);
        sqlstm.sqhstl[19] = (unsigned int  )11;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         void  *)0;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned int  )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_3);
        sqlstm.sqhstl[20] = (unsigned int  )11;
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         void  *)0;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned int  )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_4);
        sqlstm.sqhstl[21] = (unsigned int  )11;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         void  *)0;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned int  )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_5);
        sqlstm.sqhstl[22] = (unsigned int  )11;
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         void  *)0;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned int  )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_6);
        sqlstm.sqhstl[23] = (unsigned int  )11;
        sqlstm.sqhsts[23] = (         int  )0;
        sqlstm.sqindv[23] = (         void  *)0;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned int  )0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqhstv[24] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_7);
        sqlstm.sqhstl[24] = (unsigned int  )11;
        sqlstm.sqhsts[24] = (         int  )0;
        sqlstm.sqindv[24] = (         void  *)0;
        sqlstm.sqinds[24] = (         int  )0;
        sqlstm.sqharm[24] = (unsigned int  )0;
        sqlstm.sqadto[24] = (unsigned short )0;
        sqlstm.sqtdso[24] = (unsigned short )0;
        sqlstm.sqhstv[25] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_8);
        sqlstm.sqhstl[25] = (unsigned int  )11;
        sqlstm.sqhsts[25] = (         int  )0;
        sqlstm.sqindv[25] = (         void  *)0;
        sqlstm.sqinds[25] = (         int  )0;
        sqlstm.sqharm[25] = (unsigned int  )0;
        sqlstm.sqadto[25] = (unsigned short )0;
        sqlstm.sqtdso[25] = (unsigned short )0;
        sqlstm.sqhstv[26] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_9);
        sqlstm.sqhstl[26] = (unsigned int  )11;
        sqlstm.sqhsts[26] = (         int  )0;
        sqlstm.sqindv[26] = (         void  *)0;
        sqlstm.sqinds[26] = (         int  )0;
        sqlstm.sqharm[26] = (unsigned int  )0;
        sqlstm.sqadto[26] = (unsigned short )0;
        sqlstm.sqtdso[26] = (unsigned short )0;
        sqlstm.sqhstv[27] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_10);
        sqlstm.sqhstl[27] = (unsigned int  )11;
        sqlstm.sqhsts[27] = (         int  )0;
        sqlstm.sqindv[27] = (         void  *)0;
        sqlstm.sqinds[27] = (         int  )0;
        sqlstm.sqharm[27] = (unsigned int  )0;
        sqlstm.sqadto[27] = (unsigned short )0;
        sqlstm.sqtdso[27] = (unsigned short )0;
        sqlstm.sqhstv[28] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_1);
        sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[28] = (         int  )0;
        sqlstm.sqindv[28] = (         void  *)0;
        sqlstm.sqinds[28] = (         int  )0;
        sqlstm.sqharm[28] = (unsigned int  )0;
        sqlstm.sqadto[28] = (unsigned short )0;
        sqlstm.sqtdso[28] = (unsigned short )0;
        sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_2);
        sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[29] = (         int  )0;
        sqlstm.sqindv[29] = (         void  *)0;
        sqlstm.sqinds[29] = (         int  )0;
        sqlstm.sqharm[29] = (unsigned int  )0;
        sqlstm.sqadto[29] = (unsigned short )0;
        sqlstm.sqtdso[29] = (unsigned short )0;
        sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_3);
        sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[30] = (         int  )0;
        sqlstm.sqindv[30] = (         void  *)0;
        sqlstm.sqinds[30] = (         int  )0;
        sqlstm.sqharm[30] = (unsigned int  )0;
        sqlstm.sqadto[30] = (unsigned short )0;
        sqlstm.sqtdso[30] = (unsigned short )0;
        sqlstm.sqhstv[31] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_4);
        sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[31] = (         int  )0;
        sqlstm.sqindv[31] = (         void  *)0;
        sqlstm.sqinds[31] = (         int  )0;
        sqlstm.sqharm[31] = (unsigned int  )0;
        sqlstm.sqadto[31] = (unsigned short )0;
        sqlstm.sqtdso[31] = (unsigned short )0;
        sqlstm.sqhstv[32] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_5);
        sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[32] = (         int  )0;
        sqlstm.sqindv[32] = (         void  *)0;
        sqlstm.sqinds[32] = (         int  )0;
        sqlstm.sqharm[32] = (unsigned int  )0;
        sqlstm.sqadto[32] = (unsigned short )0;
        sqlstm.sqtdso[32] = (unsigned short )0;
        sqlstm.sqhstv[33] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_6);
        sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[33] = (         int  )0;
        sqlstm.sqindv[33] = (         void  *)0;
        sqlstm.sqinds[33] = (         int  )0;
        sqlstm.sqharm[33] = (unsigned int  )0;
        sqlstm.sqadto[33] = (unsigned short )0;
        sqlstm.sqtdso[33] = (unsigned short )0;
        sqlstm.sqhstv[34] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_7);
        sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[34] = (         int  )0;
        sqlstm.sqindv[34] = (         void  *)0;
        sqlstm.sqinds[34] = (         int  )0;
        sqlstm.sqharm[34] = (unsigned int  )0;
        sqlstm.sqadto[34] = (unsigned short )0;
        sqlstm.sqtdso[34] = (unsigned short )0;
        sqlstm.sqhstv[35] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_8);
        sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[35] = (         int  )0;
        sqlstm.sqindv[35] = (         void  *)0;
        sqlstm.sqinds[35] = (         int  )0;
        sqlstm.sqharm[35] = (unsigned int  )0;
        sqlstm.sqadto[35] = (unsigned short )0;
        sqlstm.sqtdso[35] = (unsigned short )0;
        sqlstm.sqhstv[36] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_9);
        sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[36] = (         int  )0;
        sqlstm.sqindv[36] = (         void  *)0;
        sqlstm.sqinds[36] = (         int  )0;
        sqlstm.sqharm[36] = (unsigned int  )0;
        sqlstm.sqadto[36] = (unsigned short )0;
        sqlstm.sqtdso[36] = (unsigned short )0;
        sqlstm.sqhstv[37] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_10);
        sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[37] = (         int  )0;
        sqlstm.sqindv[37] = (         void  *)0;
        sqlstm.sqinds[37] = (         int  )0;
        sqlstm.sqharm[37] = (unsigned int  )0;
        sqlstm.sqadto[37] = (unsigned short )0;
        sqlstm.sqtdso[37] = (unsigned short )0;
        sqlstm.sqhstv[38] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_1);
        sqlstm.sqhstl[38] = (unsigned int  )401;
        sqlstm.sqhsts[38] = (         int  )0;
        sqlstm.sqindv[38] = (         void  *)0;
        sqlstm.sqinds[38] = (         int  )0;
        sqlstm.sqharm[38] = (unsigned int  )0;
        sqlstm.sqadto[38] = (unsigned short )0;
        sqlstm.sqtdso[38] = (unsigned short )0;
        sqlstm.sqhstv[39] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_2);
        sqlstm.sqhstl[39] = (unsigned int  )401;
        sqlstm.sqhsts[39] = (         int  )0;
        sqlstm.sqindv[39] = (         void  *)0;
        sqlstm.sqinds[39] = (         int  )0;
        sqlstm.sqharm[39] = (unsigned int  )0;
        sqlstm.sqadto[39] = (unsigned short )0;
        sqlstm.sqtdso[39] = (unsigned short )0;
        sqlstm.sqhstv[40] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_3);
        sqlstm.sqhstl[40] = (unsigned int  )401;
        sqlstm.sqhsts[40] = (         int  )0;
        sqlstm.sqindv[40] = (         void  *)0;
        sqlstm.sqinds[40] = (         int  )0;
        sqlstm.sqharm[40] = (unsigned int  )0;
        sqlstm.sqadto[40] = (unsigned short )0;
        sqlstm.sqtdso[40] = (unsigned short )0;
        sqlstm.sqhstv[41] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[41] = (unsigned int  )26;
        sqlstm.sqhsts[41] = (         int  )0;
        sqlstm.sqindv[41] = (         void  *)0;
        sqlstm.sqinds[41] = (         int  )0;
        sqlstm.sqharm[41] = (unsigned int  )0;
        sqlstm.sqadto[41] = (unsigned short )0;
        sqlstm.sqtdso[41] = (unsigned short )0;
        sqlstm.sqhstv[42] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
        sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[42] = (         int  )0;
        sqlstm.sqindv[42] = (         void  *)0;
        sqlstm.sqinds[42] = (         int  )0;
        sqlstm.sqharm[42] = (unsigned int  )0;
        sqlstm.sqadto[42] = (unsigned short )0;
        sqlstm.sqtdso[42] = (unsigned short )0;
        sqlstm.sqhstv[43] = (         void  *)(MWIPLOTLOS_N.QTY_FLAG);
        sqlstm.sqhstl[43] = (unsigned int  )2;
        sqlstm.sqhsts[43] = (         int  )0;
        sqlstm.sqindv[43] = (         void  *)0;
        sqlstm.sqinds[43] = (         int  )0;
        sqlstm.sqharm[43] = (unsigned int  )0;
        sqlstm.sqadto[43] = (unsigned short )0;
        sqlstm.sqtdso[43] = (unsigned short )0;
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
        DBC_del_null_mwiplotlos(&MWIPLOTLOS_N, MWIPLOTLOS);
    }
    DB_stop_query_timer("DBC_select_mwiplotlos", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mwiplotlos_for_update(int sel_type, struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTLOS_N_TAG MWIPLOTLOS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwiplotlos(&MWIPLOTLOS_N, MWIPLOTLOS);
    DB_error_code = 0;

    switch(sel_type)
    {
    case 1:
        /* EXEC SQL SELECT 
                     LOT_ID,
                     HIST_SEQ,
                     QTY_FLAG,
                     TRAN_TIME,
                     HIST_DEL_FLAG,
                     FACTORY,
                     MAT_ID,
                     MAT_VER,
                     FLOW,
                     FLOW_SEQ_NUM,
                     OPER,
                     RES_ID,
                     CAUSE_FLOW,
                     CAUSE_OPER,
                     CAUSE_RES_ID,
                     NEW_QTY,
                     OLD_QTY,
                     TOTAL_LOSS_QTY,
                     LOSS_CODE_1,
                     LOSS_CODE_2,
                     LOSS_CODE_3,
                     LOSS_CODE_4,
                     LOSS_CODE_5,
                     LOSS_CODE_6,
                     LOSS_CODE_7,
                     LOSS_CODE_8,
                     LOSS_CODE_9,
                     LOSS_CODE_10,
                     LOSS_QTY_1,
                     LOSS_QTY_2,
                     LOSS_QTY_3,
                     LOSS_QTY_4,
                     LOSS_QTY_5,
                     LOSS_QTY_6,
                     LOSS_QTY_7,
                     LOSS_QTY_8,
                     LOSS_QTY_9,
                     LOSS_QTY_10,
                     LOSS_COMMENT_1,
                     LOSS_COMMENT_2,
                     LOSS_COMMENT_3
          INTO 
              :MWIPLOTLOS_N.LOT_ID,
              :MWIPLOTLOS_N.HIST_SEQ,
              :MWIPLOTLOS_N.QTY_FLAG,
              :MWIPLOTLOS_N.TRAN_TIME,
              :MWIPLOTLOS_N.HIST_DEL_FLAG,
              :MWIPLOTLOS_N.FACTORY,
              :MWIPLOTLOS_N.MAT_ID,
              :MWIPLOTLOS_N.MAT_VER,
              :MWIPLOTLOS_N.FLOW,
              :MWIPLOTLOS_N.FLOW_SEQ_NUM,
              :MWIPLOTLOS_N.OPER,
              :MWIPLOTLOS_N.RES_ID,
              :MWIPLOTLOS_N.CAUSE_FLOW,
              :MWIPLOTLOS_N.CAUSE_OPER,
              :MWIPLOTLOS_N.CAUSE_RES_ID,
              :MWIPLOTLOS_N.NEW_QTY,
              :MWIPLOTLOS_N.OLD_QTY,
              :MWIPLOTLOS_N.TOTAL_LOSS_QTY,
              :MWIPLOTLOS_N.LOSS_CODE_1,
              :MWIPLOTLOS_N.LOSS_CODE_2,
              :MWIPLOTLOS_N.LOSS_CODE_3,
              :MWIPLOTLOS_N.LOSS_CODE_4,
              :MWIPLOTLOS_N.LOSS_CODE_5,
              :MWIPLOTLOS_N.LOSS_CODE_6,
              :MWIPLOTLOS_N.LOSS_CODE_7,
              :MWIPLOTLOS_N.LOSS_CODE_8,
              :MWIPLOTLOS_N.LOSS_CODE_9,
              :MWIPLOTLOS_N.LOSS_CODE_10,
              :MWIPLOTLOS_N.LOSS_QTY_1,
              :MWIPLOTLOS_N.LOSS_QTY_2,
              :MWIPLOTLOS_N.LOSS_QTY_3,
              :MWIPLOTLOS_N.LOSS_QTY_4,
              :MWIPLOTLOS_N.LOSS_QTY_5,
              :MWIPLOTLOS_N.LOSS_QTY_6,
              :MWIPLOTLOS_N.LOSS_QTY_7,
              :MWIPLOTLOS_N.LOSS_QTY_8,
              :MWIPLOTLOS_N.LOSS_QTY_9,
              :MWIPLOTLOS_N.LOSS_QTY_10,
              :MWIPLOTLOS_N.LOSS_COMMENT_1,
              :MWIPLOTLOS_N.LOSS_COMMENT_2,
              :MWIPLOTLOS_N.LOSS_COMMENT_3
          FROM MWIPLOTLOS
          WHERE LOT_ID = :MWIPLOTLOS_N.LOT_ID
              AND HIST_SEQ = :MWIPLOTLOS_N.HIST_SEQ
              AND QTY_FLAG = :MWIPLOTLOS_N.QTY_FLAG
          FOR UPDATE; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select LOT_ID ,HIST_SEQ ,QTY_FLAG ,TRAN_TIME ,HIST_D\
EL_FLAG ,FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,RES_ID ,CAUSE_FL\
OW ,CAUSE_OPER ,CAUSE_RES_ID ,NEW_QTY ,OLD_QTY ,TOTAL_LOSS_QTY ,LOSS_CODE_1 ,\
LOSS_CODE_2 ,LOSS_CODE_3 ,LOSS_CODE_4 ,LOSS_CODE_5 ,LOSS_CODE_6 ,LOSS_CODE_7 \
,LOSS_CODE_8 ,LOSS_CODE_9 ,LOSS_CODE_10 ,LOSS_QTY_1 ,LOSS_QTY_2 ,LOSS_QTY_3 ,\
LOSS_QTY_4 ,LOSS_QTY_5 ,LOSS_QTY_6 ,LOSS_QTY_7 ,LOSS_QTY_8 ,LOSS_QTY_9 ,LOSS_\
QTY_10 ,LOSS_COMMENT_1 ,LOSS_COMMENT_2 ,LOSS_COMMENT_3 into :b0,:b1,:b2,:b3,:\
b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20\
,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:\
b36,:b37,:b38,:b39,:b40  from MWIPLOTLOS where ((LOT_ID=:b0 and HIST_SEQ=:b1)\
 and QTY_FLAG=:b2) for update ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )196;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[0] = (unsigned int  )26;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
        sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)(MWIPLOTLOS_N.QTY_FLAG);
        sqlstm.sqhstl[2] = (unsigned int  )2;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (         void  *)(MWIPLOTLOS_N.TRAN_TIME);
        sqlstm.sqhstl[3] = (unsigned int  )15;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         void  *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned int  )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (         void  *)(MWIPLOTLOS_N.HIST_DEL_FLAG);
        sqlstm.sqhstl[4] = (unsigned int  )2;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         void  *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned int  )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (         void  *)(MWIPLOTLOS_N.FACTORY);
        sqlstm.sqhstl[5] = (unsigned int  )11;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         void  *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned int  )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (         void  *)(MWIPLOTLOS_N.MAT_ID);
        sqlstm.sqhstl[6] = (unsigned int  )31;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         void  *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned int  )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (         void  *)&(MWIPLOTLOS_N.MAT_VER);
        sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         void  *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned int  )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (         void  *)(MWIPLOTLOS_N.FLOW);
        sqlstm.sqhstl[8] = (unsigned int  )21;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         void  *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned int  )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (         void  *)&(MWIPLOTLOS_N.FLOW_SEQ_NUM);
        sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         void  *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned int  )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (         void  *)(MWIPLOTLOS_N.OPER);
        sqlstm.sqhstl[10] = (unsigned int  )11;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         void  *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned int  )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (         void  *)(MWIPLOTLOS_N.RES_ID);
        sqlstm.sqhstl[11] = (unsigned int  )21;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         void  *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned int  )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (         void  *)(MWIPLOTLOS_N.CAUSE_FLOW);
        sqlstm.sqhstl[12] = (unsigned int  )21;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         void  *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned int  )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (         void  *)(MWIPLOTLOS_N.CAUSE_OPER);
        sqlstm.sqhstl[13] = (unsigned int  )11;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         void  *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned int  )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (         void  *)(MWIPLOTLOS_N.CAUSE_RES_ID);
        sqlstm.sqhstl[14] = (unsigned int  )21;
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         void  *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned int  )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (         void  *)&(MWIPLOTLOS_N.NEW_QTY);
        sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         void  *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned int  )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (         void  *)&(MWIPLOTLOS_N.OLD_QTY);
        sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         void  *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned int  )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (         void  *)&(MWIPLOTLOS_N.TOTAL_LOSS_QTY);
        sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         void  *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned int  )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_1);
        sqlstm.sqhstl[18] = (unsigned int  )11;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         void  *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned int  )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_2);
        sqlstm.sqhstl[19] = (unsigned int  )11;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         void  *)0;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned int  )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_3);
        sqlstm.sqhstl[20] = (unsigned int  )11;
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         void  *)0;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned int  )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_4);
        sqlstm.sqhstl[21] = (unsigned int  )11;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         void  *)0;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned int  )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_5);
        sqlstm.sqhstl[22] = (unsigned int  )11;
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         void  *)0;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned int  )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_6);
        sqlstm.sqhstl[23] = (unsigned int  )11;
        sqlstm.sqhsts[23] = (         int  )0;
        sqlstm.sqindv[23] = (         void  *)0;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned int  )0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqhstv[24] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_7);
        sqlstm.sqhstl[24] = (unsigned int  )11;
        sqlstm.sqhsts[24] = (         int  )0;
        sqlstm.sqindv[24] = (         void  *)0;
        sqlstm.sqinds[24] = (         int  )0;
        sqlstm.sqharm[24] = (unsigned int  )0;
        sqlstm.sqadto[24] = (unsigned short )0;
        sqlstm.sqtdso[24] = (unsigned short )0;
        sqlstm.sqhstv[25] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_8);
        sqlstm.sqhstl[25] = (unsigned int  )11;
        sqlstm.sqhsts[25] = (         int  )0;
        sqlstm.sqindv[25] = (         void  *)0;
        sqlstm.sqinds[25] = (         int  )0;
        sqlstm.sqharm[25] = (unsigned int  )0;
        sqlstm.sqadto[25] = (unsigned short )0;
        sqlstm.sqtdso[25] = (unsigned short )0;
        sqlstm.sqhstv[26] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_9);
        sqlstm.sqhstl[26] = (unsigned int  )11;
        sqlstm.sqhsts[26] = (         int  )0;
        sqlstm.sqindv[26] = (         void  *)0;
        sqlstm.sqinds[26] = (         int  )0;
        sqlstm.sqharm[26] = (unsigned int  )0;
        sqlstm.sqadto[26] = (unsigned short )0;
        sqlstm.sqtdso[26] = (unsigned short )0;
        sqlstm.sqhstv[27] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_10);
        sqlstm.sqhstl[27] = (unsigned int  )11;
        sqlstm.sqhsts[27] = (         int  )0;
        sqlstm.sqindv[27] = (         void  *)0;
        sqlstm.sqinds[27] = (         int  )0;
        sqlstm.sqharm[27] = (unsigned int  )0;
        sqlstm.sqadto[27] = (unsigned short )0;
        sqlstm.sqtdso[27] = (unsigned short )0;
        sqlstm.sqhstv[28] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_1);
        sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[28] = (         int  )0;
        sqlstm.sqindv[28] = (         void  *)0;
        sqlstm.sqinds[28] = (         int  )0;
        sqlstm.sqharm[28] = (unsigned int  )0;
        sqlstm.sqadto[28] = (unsigned short )0;
        sqlstm.sqtdso[28] = (unsigned short )0;
        sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_2);
        sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[29] = (         int  )0;
        sqlstm.sqindv[29] = (         void  *)0;
        sqlstm.sqinds[29] = (         int  )0;
        sqlstm.sqharm[29] = (unsigned int  )0;
        sqlstm.sqadto[29] = (unsigned short )0;
        sqlstm.sqtdso[29] = (unsigned short )0;
        sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_3);
        sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[30] = (         int  )0;
        sqlstm.sqindv[30] = (         void  *)0;
        sqlstm.sqinds[30] = (         int  )0;
        sqlstm.sqharm[30] = (unsigned int  )0;
        sqlstm.sqadto[30] = (unsigned short )0;
        sqlstm.sqtdso[30] = (unsigned short )0;
        sqlstm.sqhstv[31] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_4);
        sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[31] = (         int  )0;
        sqlstm.sqindv[31] = (         void  *)0;
        sqlstm.sqinds[31] = (         int  )0;
        sqlstm.sqharm[31] = (unsigned int  )0;
        sqlstm.sqadto[31] = (unsigned short )0;
        sqlstm.sqtdso[31] = (unsigned short )0;
        sqlstm.sqhstv[32] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_5);
        sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[32] = (         int  )0;
        sqlstm.sqindv[32] = (         void  *)0;
        sqlstm.sqinds[32] = (         int  )0;
        sqlstm.sqharm[32] = (unsigned int  )0;
        sqlstm.sqadto[32] = (unsigned short )0;
        sqlstm.sqtdso[32] = (unsigned short )0;
        sqlstm.sqhstv[33] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_6);
        sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[33] = (         int  )0;
        sqlstm.sqindv[33] = (         void  *)0;
        sqlstm.sqinds[33] = (         int  )0;
        sqlstm.sqharm[33] = (unsigned int  )0;
        sqlstm.sqadto[33] = (unsigned short )0;
        sqlstm.sqtdso[33] = (unsigned short )0;
        sqlstm.sqhstv[34] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_7);
        sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[34] = (         int  )0;
        sqlstm.sqindv[34] = (         void  *)0;
        sqlstm.sqinds[34] = (         int  )0;
        sqlstm.sqharm[34] = (unsigned int  )0;
        sqlstm.sqadto[34] = (unsigned short )0;
        sqlstm.sqtdso[34] = (unsigned short )0;
        sqlstm.sqhstv[35] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_8);
        sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[35] = (         int  )0;
        sqlstm.sqindv[35] = (         void  *)0;
        sqlstm.sqinds[35] = (         int  )0;
        sqlstm.sqharm[35] = (unsigned int  )0;
        sqlstm.sqadto[35] = (unsigned short )0;
        sqlstm.sqtdso[35] = (unsigned short )0;
        sqlstm.sqhstv[36] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_9);
        sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[36] = (         int  )0;
        sqlstm.sqindv[36] = (         void  *)0;
        sqlstm.sqinds[36] = (         int  )0;
        sqlstm.sqharm[36] = (unsigned int  )0;
        sqlstm.sqadto[36] = (unsigned short )0;
        sqlstm.sqtdso[36] = (unsigned short )0;
        sqlstm.sqhstv[37] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_10);
        sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[37] = (         int  )0;
        sqlstm.sqindv[37] = (         void  *)0;
        sqlstm.sqinds[37] = (         int  )0;
        sqlstm.sqharm[37] = (unsigned int  )0;
        sqlstm.sqadto[37] = (unsigned short )0;
        sqlstm.sqtdso[37] = (unsigned short )0;
        sqlstm.sqhstv[38] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_1);
        sqlstm.sqhstl[38] = (unsigned int  )401;
        sqlstm.sqhsts[38] = (         int  )0;
        sqlstm.sqindv[38] = (         void  *)0;
        sqlstm.sqinds[38] = (         int  )0;
        sqlstm.sqharm[38] = (unsigned int  )0;
        sqlstm.sqadto[38] = (unsigned short )0;
        sqlstm.sqtdso[38] = (unsigned short )0;
        sqlstm.sqhstv[39] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_2);
        sqlstm.sqhstl[39] = (unsigned int  )401;
        sqlstm.sqhsts[39] = (         int  )0;
        sqlstm.sqindv[39] = (         void  *)0;
        sqlstm.sqinds[39] = (         int  )0;
        sqlstm.sqharm[39] = (unsigned int  )0;
        sqlstm.sqadto[39] = (unsigned short )0;
        sqlstm.sqtdso[39] = (unsigned short )0;
        sqlstm.sqhstv[40] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_3);
        sqlstm.sqhstl[40] = (unsigned int  )401;
        sqlstm.sqhsts[40] = (         int  )0;
        sqlstm.sqindv[40] = (         void  *)0;
        sqlstm.sqinds[40] = (         int  )0;
        sqlstm.sqharm[40] = (unsigned int  )0;
        sqlstm.sqadto[40] = (unsigned short )0;
        sqlstm.sqtdso[40] = (unsigned short )0;
        sqlstm.sqhstv[41] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[41] = (unsigned int  )26;
        sqlstm.sqhsts[41] = (         int  )0;
        sqlstm.sqindv[41] = (         void  *)0;
        sqlstm.sqinds[41] = (         int  )0;
        sqlstm.sqharm[41] = (unsigned int  )0;
        sqlstm.sqadto[41] = (unsigned short )0;
        sqlstm.sqtdso[41] = (unsigned short )0;
        sqlstm.sqhstv[42] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
        sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[42] = (         int  )0;
        sqlstm.sqindv[42] = (         void  *)0;
        sqlstm.sqinds[42] = (         int  )0;
        sqlstm.sqharm[42] = (unsigned int  )0;
        sqlstm.sqadto[42] = (unsigned short )0;
        sqlstm.sqtdso[42] = (unsigned short )0;
        sqlstm.sqhstv[43] = (         void  *)(MWIPLOTLOS_N.QTY_FLAG);
        sqlstm.sqhstl[43] = (unsigned int  )2;
        sqlstm.sqhsts[43] = (         int  )0;
        sqlstm.sqindv[43] = (         void  *)0;
        sqlstm.sqinds[43] = (         int  )0;
        sqlstm.sqharm[43] = (unsigned int  )0;
        sqlstm.sqadto[43] = (unsigned short )0;
        sqlstm.sqtdso[43] = (unsigned short )0;
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
        DBC_del_null_mwiplotlos(&MWIPLOTLOS_N, MWIPLOTLOS);
    }
    DB_stop_query_timer("DBC_select_mwiplotlos_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mwiplotlos_scalar(int sel_type, struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTLOS_N_TAG MWIPLOTLOS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    

    DBC_add_null_mwiplotlos(&MWIPLOTLOS_N, MWIPLOTLOS);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
    case 1:
        /* EXEC SQL SELECT count(*)
          INTO :d_value
          FROM MWIPLOTLOS
          WHERE LOT_ID = :MWIPLOTLOS_N.LOT_ID
              AND HIST_SEQ = :MWIPLOTLOS_N.HIST_SEQ
              AND QTY_FLAG = :MWIPLOTLOS_N.QTY_FLAG; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count(*)  into :b0  from MWIPLOTLOS where ((L\
OT_ID=:b1 and HIST_SEQ=:b2) and QTY_FLAG=:b3)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )387;
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
        sqlstm.sqhstv[1] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[1] = (unsigned int  )26;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
        sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (         void  *)(MWIPLOTLOS_N.QTY_FLAG);
        sqlstm.sqhstl[3] = (unsigned int  )2;
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

    case 2:
        /* EXEC SQL SELECT count(*)
          INTO :d_value
          FROM MWIPLOTLOS
          WHERE LOT_ID = :MWIPLOTLOS_N.LOT_ID
              AND HIST_SEQ = :MWIPLOTLOS_N.HIST_SEQ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count(*)  into :b0  from MWIPLOTLOS where (LO\
T_ID=:b1 and HIST_SEQ=:b2)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )418;
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
        sqlstm.sqhstv[1] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[1] = (unsigned int  )26;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
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

    DB_stop_query_timer("DBC_select_mwiplotlos_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mwiplotlos(int sel_type, struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTLOS_N_TAG MWIPLOTLOS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwiplotlos(&MWIPLOTLOS_N, MWIPLOTLOS);
    DB_error_code = 0;

    switch(sel_type)
    {
    case 1:
        /* EXEC SQL DELETE FROM MWIPLOTLOS
            WHERE LOT_ID = :MWIPLOTLOS_N.LOT_ID
                AND HIST_SEQ = :MWIPLOTLOS_N.HIST_SEQ
                AND QTY_FLAG = :MWIPLOTLOS_N.QTY_FLAG; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "delete  from MWIPLOTLOS  where ((LOT_ID=:b0 and HIST\
_SEQ=:b1) and QTY_FLAG=:b2)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )445;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[0] = (unsigned int  )26;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
        sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)(MWIPLOTLOS_N.QTY_FLAG);
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
        if (sqlca.sqlcode == 1403) DB_usr_error();
        if (sqlca.sqlcode < 0) DB_usr_error();
}


        break;

    case 2:
        /* EXEC SQL DELETE FROM MWIPLOTLOS
            WHERE LOT_ID = :MWIPLOTLOS_N.LOT_ID; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "delete  from MWIPLOTLOS  where LOT_ID=:b0";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )472;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
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
    DB_stop_query_timer("DBC_delete_mwiplotlos", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mwiplotlos(struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTLOS_N_TAG MWIPLOTLOS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwiplotlos(&MWIPLOTLOS_N, MWIPLOTLOS);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MWIPLOTLOS (
                    LOT_ID,
                    HIST_SEQ,
                    QTY_FLAG,
                    TRAN_TIME,
                    HIST_DEL_FLAG,
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    RES_ID,
                    CAUSE_FLOW,
                    CAUSE_OPER,
                    CAUSE_RES_ID,
                    NEW_QTY,
                    OLD_QTY,
                    TOTAL_LOSS_QTY,
                    LOSS_CODE_1,
                    LOSS_CODE_2,
                    LOSS_CODE_3,
                    LOSS_CODE_4,
                    LOSS_CODE_5,
                    LOSS_CODE_6,
                    LOSS_CODE_7,
                    LOSS_CODE_8,
                    LOSS_CODE_9,
                    LOSS_CODE_10,
                    LOSS_QTY_1,
                    LOSS_QTY_2,
                    LOSS_QTY_3,
                    LOSS_QTY_4,
                    LOSS_QTY_5,
                    LOSS_QTY_6,
                    LOSS_QTY_7,
                    LOSS_QTY_8,
                    LOSS_QTY_9,
                    LOSS_QTY_10,
                    LOSS_COMMENT_1,
                    LOSS_COMMENT_2,
                    LOSS_COMMENT_3
        )
        VALUES (
                    :MWIPLOTLOS_N.LOT_ID,
                    :MWIPLOTLOS_N.HIST_SEQ,
                    :MWIPLOTLOS_N.QTY_FLAG,
                    :MWIPLOTLOS_N.TRAN_TIME,
                    :MWIPLOTLOS_N.HIST_DEL_FLAG,
                    :MWIPLOTLOS_N.FACTORY,
                    :MWIPLOTLOS_N.MAT_ID,
                    :MWIPLOTLOS_N.MAT_VER,
                    :MWIPLOTLOS_N.FLOW,
                    :MWIPLOTLOS_N.FLOW_SEQ_NUM,
                    :MWIPLOTLOS_N.OPER,
                    :MWIPLOTLOS_N.RES_ID,
                    :MWIPLOTLOS_N.CAUSE_FLOW,
                    :MWIPLOTLOS_N.CAUSE_OPER,
                    :MWIPLOTLOS_N.CAUSE_RES_ID,
                    :MWIPLOTLOS_N.NEW_QTY,
                    :MWIPLOTLOS_N.OLD_QTY,
                    :MWIPLOTLOS_N.TOTAL_LOSS_QTY,
                    :MWIPLOTLOS_N.LOSS_CODE_1,
                    :MWIPLOTLOS_N.LOSS_CODE_2,
                    :MWIPLOTLOS_N.LOSS_CODE_3,
                    :MWIPLOTLOS_N.LOSS_CODE_4,
                    :MWIPLOTLOS_N.LOSS_CODE_5,
                    :MWIPLOTLOS_N.LOSS_CODE_6,
                    :MWIPLOTLOS_N.LOSS_CODE_7,
                    :MWIPLOTLOS_N.LOSS_CODE_8,
                    :MWIPLOTLOS_N.LOSS_CODE_9,
                    :MWIPLOTLOS_N.LOSS_CODE_10,
                    :MWIPLOTLOS_N.LOSS_QTY_1,
                    :MWIPLOTLOS_N.LOSS_QTY_2,
                    :MWIPLOTLOS_N.LOSS_QTY_3,
                    :MWIPLOTLOS_N.LOSS_QTY_4,
                    :MWIPLOTLOS_N.LOSS_QTY_5,
                    :MWIPLOTLOS_N.LOSS_QTY_6,
                    :MWIPLOTLOS_N.LOSS_QTY_7,
                    :MWIPLOTLOS_N.LOSS_QTY_8,
                    :MWIPLOTLOS_N.LOSS_QTY_9,
                    :MWIPLOTLOS_N.LOSS_QTY_10,
                    :MWIPLOTLOS_N.LOSS_COMMENT_1,
                    :MWIPLOTLOS_N.LOSS_COMMENT_2,
                    :MWIPLOTLOS_N.LOSS_COMMENT_3
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 44;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into MWIPLOTLOS (LOT_ID,HIST_SEQ,QTY_FLAG,TRAN_TI\
ME,HIST_DEL_FLAG,FACTORY,MAT_ID,MAT_VER,FLOW,FLOW_SEQ_NUM,OPER,RES_ID,CAUSE_F\
LOW,CAUSE_OPER,CAUSE_RES_ID,NEW_QTY,OLD_QTY,TOTAL_LOSS_QTY,LOSS_CODE_1,LOSS_C\
ODE_2,LOSS_CODE_3,LOSS_CODE_4,LOSS_CODE_5,LOSS_CODE_6,LOSS_CODE_7,LOSS_CODE_8\
,LOSS_CODE_9,LOSS_CODE_10,LOSS_QTY_1,LOSS_QTY_2,LOSS_QTY_3,LOSS_QTY_4,LOSS_QT\
Y_5,LOSS_QTY_6,LOSS_QTY_7,LOSS_QTY_8,LOSS_QTY_9,LOSS_QTY_10,LOSS_COMMENT_1,LO\
SS_COMMENT_2,LOSS_COMMENT_3) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,\
:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b\
25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40\
)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )491;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
    sqlstm.sqhstl[0] = (unsigned int  )26;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
    sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MWIPLOTLOS_N.QTY_FLAG);
    sqlstm.sqhstl[2] = (unsigned int  )2;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MWIPLOTLOS_N.TRAN_TIME);
    sqlstm.sqhstl[3] = (unsigned int  )15;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MWIPLOTLOS_N.HIST_DEL_FLAG);
    sqlstm.sqhstl[4] = (unsigned int  )2;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MWIPLOTLOS_N.FACTORY);
    sqlstm.sqhstl[5] = (unsigned int  )11;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MWIPLOTLOS_N.MAT_ID);
    sqlstm.sqhstl[6] = (unsigned int  )31;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)&(MWIPLOTLOS_N.MAT_VER);
    sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MWIPLOTLOS_N.FLOW);
    sqlstm.sqhstl[8] = (unsigned int  )21;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)&(MWIPLOTLOS_N.FLOW_SEQ_NUM);
    sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MWIPLOTLOS_N.OPER);
    sqlstm.sqhstl[10] = (unsigned int  )11;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MWIPLOTLOS_N.RES_ID);
    sqlstm.sqhstl[11] = (unsigned int  )21;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MWIPLOTLOS_N.CAUSE_FLOW);
    sqlstm.sqhstl[12] = (unsigned int  )21;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MWIPLOTLOS_N.CAUSE_OPER);
    sqlstm.sqhstl[13] = (unsigned int  )11;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MWIPLOTLOS_N.CAUSE_RES_ID);
    sqlstm.sqhstl[14] = (unsigned int  )21;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)&(MWIPLOTLOS_N.NEW_QTY);
    sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)&(MWIPLOTLOS_N.OLD_QTY);
    sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)&(MWIPLOTLOS_N.TOTAL_LOSS_QTY);
    sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_1);
    sqlstm.sqhstl[18] = (unsigned int  )11;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_2);
    sqlstm.sqhstl[19] = (unsigned int  )11;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_3);
    sqlstm.sqhstl[20] = (unsigned int  )11;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_4);
    sqlstm.sqhstl[21] = (unsigned int  )11;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_5);
    sqlstm.sqhstl[22] = (unsigned int  )11;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_6);
    sqlstm.sqhstl[23] = (unsigned int  )11;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_7);
    sqlstm.sqhstl[24] = (unsigned int  )11;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_8);
    sqlstm.sqhstl[25] = (unsigned int  )11;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_9);
    sqlstm.sqhstl[26] = (unsigned int  )11;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_10);
    sqlstm.sqhstl[27] = (unsigned int  )11;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_1);
    sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_2);
    sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_3);
    sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_4);
    sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_5);
    sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_6);
    sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_7);
    sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_8);
    sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_9);
    sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_10);
    sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_1);
    sqlstm.sqhstl[38] = (unsigned int  )401;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_2);
    sqlstm.sqhstl[39] = (unsigned int  )401;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_3);
    sqlstm.sqhstl[40] = (unsigned int  )401;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
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


    DB_stop_query_timer("DBC_insert_mwiplotlos", 0);
}


/* SQL UPDATE Function */
void DBC_update_mwiplotlos(int sel_type, struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTLOS_N_TAG MWIPLOTLOS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwiplotlos(&MWIPLOTLOS_N, MWIPLOTLOS);
    DB_error_code = 0;

    switch(sel_type)
    {
    case 1:
        /* EXEC SQL UPDATE MWIPLOTLOS SET
                TRAN_TIME = :MWIPLOTLOS_N.TRAN_TIME,
                HIST_DEL_FLAG = :MWIPLOTLOS_N.HIST_DEL_FLAG,
                FACTORY = :MWIPLOTLOS_N.FACTORY,
                MAT_ID = :MWIPLOTLOS_N.MAT_ID,
                MAT_VER = :MWIPLOTLOS_N.MAT_VER,
                FLOW = :MWIPLOTLOS_N.FLOW,
                FLOW_SEQ_NUM = :MWIPLOTLOS_N.FLOW_SEQ_NUM,
                OPER = :MWIPLOTLOS_N.OPER,
                RES_ID = :MWIPLOTLOS_N.RES_ID,
                CAUSE_FLOW = :MWIPLOTLOS_N.CAUSE_FLOW,
                CAUSE_OPER = :MWIPLOTLOS_N.CAUSE_OPER,
                CAUSE_RES_ID = :MWIPLOTLOS_N.CAUSE_RES_ID,
                NEW_QTY = :MWIPLOTLOS_N.NEW_QTY,
                OLD_QTY = :MWIPLOTLOS_N.OLD_QTY,
                TOTAL_LOSS_QTY = :MWIPLOTLOS_N.TOTAL_LOSS_QTY,
                LOSS_CODE_1 = :MWIPLOTLOS_N.LOSS_CODE_1,
                LOSS_CODE_2 = :MWIPLOTLOS_N.LOSS_CODE_2,
                LOSS_CODE_3 = :MWIPLOTLOS_N.LOSS_CODE_3,
                LOSS_CODE_4 = :MWIPLOTLOS_N.LOSS_CODE_4,
                LOSS_CODE_5 = :MWIPLOTLOS_N.LOSS_CODE_5,
                LOSS_CODE_6 = :MWIPLOTLOS_N.LOSS_CODE_6,
                LOSS_CODE_7 = :MWIPLOTLOS_N.LOSS_CODE_7,
                LOSS_CODE_8 = :MWIPLOTLOS_N.LOSS_CODE_8,
                LOSS_CODE_9 = :MWIPLOTLOS_N.LOSS_CODE_9,
                LOSS_CODE_10 = :MWIPLOTLOS_N.LOSS_CODE_10,
                LOSS_QTY_1 = :MWIPLOTLOS_N.LOSS_QTY_1,
                LOSS_QTY_2 = :MWIPLOTLOS_N.LOSS_QTY_2,
                LOSS_QTY_3 = :MWIPLOTLOS_N.LOSS_QTY_3,
                LOSS_QTY_4 = :MWIPLOTLOS_N.LOSS_QTY_4,
                LOSS_QTY_5 = :MWIPLOTLOS_N.LOSS_QTY_5,
                LOSS_QTY_6 = :MWIPLOTLOS_N.LOSS_QTY_6,
                LOSS_QTY_7 = :MWIPLOTLOS_N.LOSS_QTY_7,
                LOSS_QTY_8 = :MWIPLOTLOS_N.LOSS_QTY_8,
                LOSS_QTY_9 = :MWIPLOTLOS_N.LOSS_QTY_9,
                LOSS_QTY_10 = :MWIPLOTLOS_N.LOSS_QTY_10,
                LOSS_COMMENT_1 = :MWIPLOTLOS_N.LOSS_COMMENT_1,
                LOSS_COMMENT_2 = :MWIPLOTLOS_N.LOSS_COMMENT_2,
                LOSS_COMMENT_3 = :MWIPLOTLOS_N.LOSS_COMMENT_3
            WHERE LOT_ID = :MWIPLOTLOS_N.LOT_ID
                AND HIST_SEQ = :MWIPLOTLOS_N.HIST_SEQ
                AND QTY_FLAG = :MWIPLOTLOS_N.QTY_FLAG; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update MWIPLOTLOS  set TRAN_TIME=:b0,HIST_DEL_FLAG=:\
b1,FACTORY=:b2,MAT_ID=:b3,MAT_VER=:b4,FLOW=:b5,FLOW_SEQ_NUM=:b6,OPER=:b7,RES_\
ID=:b8,CAUSE_FLOW=:b9,CAUSE_OPER=:b10,CAUSE_RES_ID=:b11,NEW_QTY=:b12,OLD_QTY=\
:b13,TOTAL_LOSS_QTY=:b14,LOSS_CODE_1=:b15,LOSS_CODE_2=:b16,LOSS_CODE_3=:b17,L\
OSS_CODE_4=:b18,LOSS_CODE_5=:b19,LOSS_CODE_6=:b20,LOSS_CODE_7=:b21,LOSS_CODE_\
8=:b22,LOSS_CODE_9=:b23,LOSS_CODE_10=:b24,LOSS_QTY_1=:b25,LOSS_QTY_2=:b26,LOS\
S_QTY_3=:b27,LOSS_QTY_4=:b28,LOSS_QTY_5=:b29,LOSS_QTY_6=:b30,LOSS_QTY_7=:b31,\
LOSS_QTY_8=:b32,LOSS_QTY_9=:b33,LOSS_QTY_10=:b34,LOSS_COMMENT_1=:b35,LOSS_COM\
MENT_2=:b36,LOSS_COMMENT_3=:b37 where ((LOT_ID=:b38 and HIST_SEQ=:b39) and QT\
Y_FLAG=:b40)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )670;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)(MWIPLOTLOS_N.TRAN_TIME);
        sqlstm.sqhstl[0] = (unsigned int  )15;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)(MWIPLOTLOS_N.HIST_DEL_FLAG);
        sqlstm.sqhstl[1] = (unsigned int  )2;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)(MWIPLOTLOS_N.FACTORY);
        sqlstm.sqhstl[2] = (unsigned int  )11;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (         void  *)(MWIPLOTLOS_N.MAT_ID);
        sqlstm.sqhstl[3] = (unsigned int  )31;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         void  *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned int  )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (         void  *)&(MWIPLOTLOS_N.MAT_VER);
        sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         void  *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned int  )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (         void  *)(MWIPLOTLOS_N.FLOW);
        sqlstm.sqhstl[5] = (unsigned int  )21;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         void  *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned int  )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (         void  *)&(MWIPLOTLOS_N.FLOW_SEQ_NUM);
        sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         void  *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned int  )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (         void  *)(MWIPLOTLOS_N.OPER);
        sqlstm.sqhstl[7] = (unsigned int  )11;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         void  *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned int  )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (         void  *)(MWIPLOTLOS_N.RES_ID);
        sqlstm.sqhstl[8] = (unsigned int  )21;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         void  *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned int  )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (         void  *)(MWIPLOTLOS_N.CAUSE_FLOW);
        sqlstm.sqhstl[9] = (unsigned int  )21;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         void  *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned int  )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (         void  *)(MWIPLOTLOS_N.CAUSE_OPER);
        sqlstm.sqhstl[10] = (unsigned int  )11;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         void  *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned int  )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (         void  *)(MWIPLOTLOS_N.CAUSE_RES_ID);
        sqlstm.sqhstl[11] = (unsigned int  )21;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         void  *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned int  )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (         void  *)&(MWIPLOTLOS_N.NEW_QTY);
        sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         void  *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned int  )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (         void  *)&(MWIPLOTLOS_N.OLD_QTY);
        sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         void  *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned int  )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (         void  *)&(MWIPLOTLOS_N.TOTAL_LOSS_QTY);
        sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         void  *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned int  )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_1);
        sqlstm.sqhstl[15] = (unsigned int  )11;
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         void  *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned int  )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_2);
        sqlstm.sqhstl[16] = (unsigned int  )11;
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         void  *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned int  )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_3);
        sqlstm.sqhstl[17] = (unsigned int  )11;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         void  *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned int  )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_4);
        sqlstm.sqhstl[18] = (unsigned int  )11;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         void  *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned int  )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_5);
        sqlstm.sqhstl[19] = (unsigned int  )11;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         void  *)0;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned int  )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_6);
        sqlstm.sqhstl[20] = (unsigned int  )11;
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         void  *)0;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned int  )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_7);
        sqlstm.sqhstl[21] = (unsigned int  )11;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         void  *)0;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned int  )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_8);
        sqlstm.sqhstl[22] = (unsigned int  )11;
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         void  *)0;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned int  )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_9);
        sqlstm.sqhstl[23] = (unsigned int  )11;
        sqlstm.sqhsts[23] = (         int  )0;
        sqlstm.sqindv[23] = (         void  *)0;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned int  )0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqhstv[24] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_10);
        sqlstm.sqhstl[24] = (unsigned int  )11;
        sqlstm.sqhsts[24] = (         int  )0;
        sqlstm.sqindv[24] = (         void  *)0;
        sqlstm.sqinds[24] = (         int  )0;
        sqlstm.sqharm[24] = (unsigned int  )0;
        sqlstm.sqadto[24] = (unsigned short )0;
        sqlstm.sqtdso[24] = (unsigned short )0;
        sqlstm.sqhstv[25] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_1);
        sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[25] = (         int  )0;
        sqlstm.sqindv[25] = (         void  *)0;
        sqlstm.sqinds[25] = (         int  )0;
        sqlstm.sqharm[25] = (unsigned int  )0;
        sqlstm.sqadto[25] = (unsigned short )0;
        sqlstm.sqtdso[25] = (unsigned short )0;
        sqlstm.sqhstv[26] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_2);
        sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[26] = (         int  )0;
        sqlstm.sqindv[26] = (         void  *)0;
        sqlstm.sqinds[26] = (         int  )0;
        sqlstm.sqharm[26] = (unsigned int  )0;
        sqlstm.sqadto[26] = (unsigned short )0;
        sqlstm.sqtdso[26] = (unsigned short )0;
        sqlstm.sqhstv[27] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_3);
        sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[27] = (         int  )0;
        sqlstm.sqindv[27] = (         void  *)0;
        sqlstm.sqinds[27] = (         int  )0;
        sqlstm.sqharm[27] = (unsigned int  )0;
        sqlstm.sqadto[27] = (unsigned short )0;
        sqlstm.sqtdso[27] = (unsigned short )0;
        sqlstm.sqhstv[28] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_4);
        sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[28] = (         int  )0;
        sqlstm.sqindv[28] = (         void  *)0;
        sqlstm.sqinds[28] = (         int  )0;
        sqlstm.sqharm[28] = (unsigned int  )0;
        sqlstm.sqadto[28] = (unsigned short )0;
        sqlstm.sqtdso[28] = (unsigned short )0;
        sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_5);
        sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[29] = (         int  )0;
        sqlstm.sqindv[29] = (         void  *)0;
        sqlstm.sqinds[29] = (         int  )0;
        sqlstm.sqharm[29] = (unsigned int  )0;
        sqlstm.sqadto[29] = (unsigned short )0;
        sqlstm.sqtdso[29] = (unsigned short )0;
        sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_6);
        sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[30] = (         int  )0;
        sqlstm.sqindv[30] = (         void  *)0;
        sqlstm.sqinds[30] = (         int  )0;
        sqlstm.sqharm[30] = (unsigned int  )0;
        sqlstm.sqadto[30] = (unsigned short )0;
        sqlstm.sqtdso[30] = (unsigned short )0;
        sqlstm.sqhstv[31] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_7);
        sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[31] = (         int  )0;
        sqlstm.sqindv[31] = (         void  *)0;
        sqlstm.sqinds[31] = (         int  )0;
        sqlstm.sqharm[31] = (unsigned int  )0;
        sqlstm.sqadto[31] = (unsigned short )0;
        sqlstm.sqtdso[31] = (unsigned short )0;
        sqlstm.sqhstv[32] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_8);
        sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[32] = (         int  )0;
        sqlstm.sqindv[32] = (         void  *)0;
        sqlstm.sqinds[32] = (         int  )0;
        sqlstm.sqharm[32] = (unsigned int  )0;
        sqlstm.sqadto[32] = (unsigned short )0;
        sqlstm.sqtdso[32] = (unsigned short )0;
        sqlstm.sqhstv[33] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_9);
        sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[33] = (         int  )0;
        sqlstm.sqindv[33] = (         void  *)0;
        sqlstm.sqinds[33] = (         int  )0;
        sqlstm.sqharm[33] = (unsigned int  )0;
        sqlstm.sqadto[33] = (unsigned short )0;
        sqlstm.sqtdso[33] = (unsigned short )0;
        sqlstm.sqhstv[34] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_10);
        sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[34] = (         int  )0;
        sqlstm.sqindv[34] = (         void  *)0;
        sqlstm.sqinds[34] = (         int  )0;
        sqlstm.sqharm[34] = (unsigned int  )0;
        sqlstm.sqadto[34] = (unsigned short )0;
        sqlstm.sqtdso[34] = (unsigned short )0;
        sqlstm.sqhstv[35] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_1);
        sqlstm.sqhstl[35] = (unsigned int  )401;
        sqlstm.sqhsts[35] = (         int  )0;
        sqlstm.sqindv[35] = (         void  *)0;
        sqlstm.sqinds[35] = (         int  )0;
        sqlstm.sqharm[35] = (unsigned int  )0;
        sqlstm.sqadto[35] = (unsigned short )0;
        sqlstm.sqtdso[35] = (unsigned short )0;
        sqlstm.sqhstv[36] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_2);
        sqlstm.sqhstl[36] = (unsigned int  )401;
        sqlstm.sqhsts[36] = (         int  )0;
        sqlstm.sqindv[36] = (         void  *)0;
        sqlstm.sqinds[36] = (         int  )0;
        sqlstm.sqharm[36] = (unsigned int  )0;
        sqlstm.sqadto[36] = (unsigned short )0;
        sqlstm.sqtdso[36] = (unsigned short )0;
        sqlstm.sqhstv[37] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_3);
        sqlstm.sqhstl[37] = (unsigned int  )401;
        sqlstm.sqhsts[37] = (         int  )0;
        sqlstm.sqindv[37] = (         void  *)0;
        sqlstm.sqinds[37] = (         int  )0;
        sqlstm.sqharm[37] = (unsigned int  )0;
        sqlstm.sqadto[37] = (unsigned short )0;
        sqlstm.sqtdso[37] = (unsigned short )0;
        sqlstm.sqhstv[38] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[38] = (unsigned int  )26;
        sqlstm.sqhsts[38] = (         int  )0;
        sqlstm.sqindv[38] = (         void  *)0;
        sqlstm.sqinds[38] = (         int  )0;
        sqlstm.sqharm[38] = (unsigned int  )0;
        sqlstm.sqadto[38] = (unsigned short )0;
        sqlstm.sqtdso[38] = (unsigned short )0;
        sqlstm.sqhstv[39] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
        sqlstm.sqhstl[39] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[39] = (         int  )0;
        sqlstm.sqindv[39] = (         void  *)0;
        sqlstm.sqinds[39] = (         int  )0;
        sqlstm.sqharm[39] = (unsigned int  )0;
        sqlstm.sqadto[39] = (unsigned short )0;
        sqlstm.sqtdso[39] = (unsigned short )0;
        sqlstm.sqhstv[40] = (         void  *)(MWIPLOTLOS_N.QTY_FLAG);
        sqlstm.sqhstl[40] = (unsigned int  )2;
        sqlstm.sqhsts[40] = (         int  )0;
        sqlstm.sqindv[40] = (         void  *)0;
        sqlstm.sqinds[40] = (         int  )0;
        sqlstm.sqharm[40] = (unsigned int  )0;
        sqlstm.sqadto[40] = (unsigned short )0;
        sqlstm.sqtdso[40] = (unsigned short )0;
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
        /* EXEC SQL UPDATE MWIPLOTLOS SET
                HIST_DEL_FLAG = :MWIPLOTLOS_N.HIST_DEL_FLAG
            WHERE LOT_ID = :MWIPLOTLOS_N.LOT_ID
                AND HIST_SEQ = :MWIPLOTLOS_N.HIST_SEQ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update MWIPLOTLOS  set HIST_DEL_FLAG=:b0 where (LOT_\
ID=:b1 and HIST_SEQ=:b2)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )849;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)(MWIPLOTLOS_N.HIST_DEL_FLAG);
        sqlstm.sqhstl[0] = (unsigned int  )2;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[1] = (unsigned int  )26;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
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
    DB_stop_query_timer("DBC_update_mwiplotlos", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mwiplotlos(int sel_type, struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTLOS_N_TAG MWIPLOTLOS_N;
        char sql[5120]; /* the variable for buffering the sql statement */
        char ts1[100], ts2[100], ts3[100]; /* temporary variables */
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    
    //FILE *fp;

    DBC_add_null_mwiplotlos(&MWIPLOTLOS_N, MWIPLOTLOS);
    DB_error_code = 0;

    /* Initialize the temporary variables */
    memset( ts1, 0x00, sizeof(ts1));
    memset( ts2, 0x00, sizeof(ts2));
    memset( ts3, 0x00, sizeof(ts3));

    switch(sel_type)
    {
    case 1:
        /* EXEC SQL DECLARE DBC_MWIPLOTLOS_CUR_1 CURSOR FOR
            SELECT 
                LOT_ID,
                HIST_SEQ,
                QTY_FLAG,
                TRAN_TIME,
                HIST_DEL_FLAG,
                FACTORY,
                MAT_ID,
                MAT_VER,
                FLOW,
                FLOW_SEQ_NUM,
                OPER,
                RES_ID,
                CAUSE_FLOW,
                CAUSE_OPER,
                CAUSE_RES_ID,
                NEW_QTY,
                OLD_QTY,
                TOTAL_LOSS_QTY,
                LOSS_CODE_1,
                LOSS_CODE_2,
                LOSS_CODE_3,
                LOSS_CODE_4,
                LOSS_CODE_5,
                LOSS_CODE_6,
                LOSS_CODE_7,
                LOSS_CODE_8,
                LOSS_CODE_9,
                LOSS_CODE_10,
                LOSS_QTY_1,
                LOSS_QTY_2,
                LOSS_QTY_3,
                LOSS_QTY_4,
                LOSS_QTY_5,
                LOSS_QTY_6,
                LOSS_QTY_7,
                LOSS_QTY_8,
                LOSS_QTY_9,
                LOSS_QTY_10,
                LOSS_COMMENT_1,
                LOSS_COMMENT_2,
                LOSS_COMMENT_3
            FROM MWIPLOTLOS
            WHERE LOT_ID = :MWIPLOTLOS_N.LOT_ID
                AND HIST_SEQ = :MWIPLOTLOS_N.HIST_SEQ
            ORDER BY QTY_FLAG ASC; */ 

        /* EXEC SQL OPEN DBC_MWIPLOTLOS_CUR_1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0010;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )876;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[0] = (unsigned int  )26;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
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
        if (sqlca.sqlcode < 0) DB_usr_error();
}


        break;

    case 2:
        /* Initialize the sql variable */
        memset( sql, 0x00, sizeof(sql));

        /* Begin making the sql */
        sprintf(sql,"SELECT * FROM (SELECT ROWNUM ROWSEQ, LOS.* FROM (SELECT ");
        sprintf(sql + strlen(sql),   "LOT_ID, ");
        sprintf(sql + strlen(sql),   "HIST_SEQ, ");
        sprintf(sql + strlen(sql),   "QTY_FLAG, ");
        sprintf(sql + strlen(sql),   "TRAN_TIME, ");
        sprintf(sql + strlen(sql),   "HIST_DEL_FLAG, ");
        sprintf(sql + strlen(sql),   "FACTORY, ");
        sprintf(sql + strlen(sql),   "MAT_ID, ");
        sprintf(sql + strlen(sql),   "MAT_VER, ");
        sprintf(sql + strlen(sql),   "FLOW, ");
        sprintf(sql + strlen(sql),   "FLOW_SEQ_NUM, ");
        sprintf(sql + strlen(sql),   "OPER, ");
        sprintf(sql + strlen(sql),   "RES_ID, ");
        sprintf(sql + strlen(sql),   "CAUSE_FLOW, ");
        sprintf(sql + strlen(sql),   "CAUSE_OPER, ");
        sprintf(sql + strlen(sql),   "CAUSE_RES_ID, ");
        sprintf(sql + strlen(sql),   "NEW_QTY, ");
        sprintf(sql + strlen(sql),   "OLD_QTY, ");
        sprintf(sql + strlen(sql),   "TOTAL_LOSS_QTY, ");
        sprintf(sql + strlen(sql),   "LOSS_CODE_1, ");
        sprintf(sql + strlen(sql),   "LOSS_CODE_2, ");
        sprintf(sql + strlen(sql),   "LOSS_CODE_3, ");
        sprintf(sql + strlen(sql),   "LOSS_CODE_4, ");
        sprintf(sql + strlen(sql),   "LOSS_CODE_5, ");
        sprintf(sql + strlen(sql),   "LOSS_CODE_6, ");
        sprintf(sql + strlen(sql),   "LOSS_CODE_7, ");
        sprintf(sql + strlen(sql),   "LOSS_CODE_8, ");
        sprintf(sql + strlen(sql),   "LOSS_CODE_9, ");
        sprintf(sql + strlen(sql),   "LOSS_CODE_10, ");
        sprintf(sql + strlen(sql),   "LOSS_QTY_1, ");
        sprintf(sql + strlen(sql),   "LOSS_QTY_2, ");
        sprintf(sql + strlen(sql),   "LOSS_QTY_3, ");
        sprintf(sql + strlen(sql),   "LOSS_QTY_4, ");
        sprintf(sql + strlen(sql),   "LOSS_QTY_5, ");
        sprintf(sql + strlen(sql),   "LOSS_QTY_6, ");
        sprintf(sql + strlen(sql),   "LOSS_QTY_7, ");
        sprintf(sql + strlen(sql),   "LOSS_QTY_8, ");
        sprintf(sql + strlen(sql),   "LOSS_QTY_9, ");
        sprintf(sql + strlen(sql),   "LOSS_QTY_10, ");
        sprintf(sql + strlen(sql),   "LOSS_COMMENT_1, ");
        sprintf(sql + strlen(sql),   "LOSS_COMMENT_2, ");
        sprintf(sql + strlen(sql),   "LOSS_COMMENT_3 ");
        sprintf(sql + strlen(sql), "FROM MWIPLOTLOS WHERE ");

        make_valid_quote(ts1, MWIPLOTLOS_N.FACTORY);
        sprintf(sql + strlen(sql), "FACTORY = '%s' ", ts1);

        make_valid_quote(ts2, DBC_Q_COND_N.FROM_TIME);
        make_valid_quote(ts3, DBC_Q_COND_N.TO_TIME);
        sprintf(sql + strlen(sql), "AND TRAN_TIME >= '%s' AND TRAN_TIME < '%s' ", ts2, ts3);

        //Adding of the filtering conditions into the SQL statement
        if(ISSPACE(MWIPLOTLOS->LOT_ID, sizeof(MWIPLOTLOS->LOT_ID)) == DB_FALSE)
        {
            make_valid_quote(ts1, MWIPLOTLOS_N.LOT_ID);
            sprintf(sql + strlen(sql), "AND LOT_ID = '%s' ", ts1);
        }

        if(ISSPACE(MWIPLOTLOS->MAT_ID, sizeof(MWIPLOTLOS->MAT_ID)) == DB_FALSE)
        {
            make_valid_quote(ts1, MWIPLOTLOS_N.MAT_ID);
            sprintf(sql + strlen(sql), "AND MAT_ID = '%s' ", ts1);
        }

        if(MWIPLOTLOS->MAT_VER > 0)
        {
            sprintf(sql + strlen(sql), "AND MAT_VER = %d ", MWIPLOTLOS->MAT_VER);
        }

        if(ISSPACE(MWIPLOTLOS->FLOW, sizeof(MWIPLOTLOS->FLOW)) == DB_FALSE)
        {
            make_valid_quote(ts1, MWIPLOTLOS_N.FLOW);
            sprintf(sql + strlen(sql), "AND FLOW = '%s' ", ts1);
        }

        if(ISSPACE(MWIPLOTLOS->OPER, sizeof(MWIPLOTLOS->OPER)) == DB_FALSE)
        {
            make_valid_quote(ts1, MWIPLOTLOS_N.OPER);
            sprintf(sql + strlen(sql), "AND OPER = '%s' ", ts1);
        }

        if(ISSPACE(MWIPLOTLOS->RES_ID, sizeof(MWIPLOTLOS->RES_ID)) == DB_FALSE)
        {
            make_valid_quote(ts1, MWIPLOTLOS_N.RES_ID);
            sprintf(sql + strlen(sql), "AND RES_ID = '%s' ", ts1);
        }

        if(MWIPLOTLOS->QTY_FLAG != ' ')
        {
            sprintf(sql + strlen(sql), "AND QTY_FLAG = '%c' ", MWIPLOTLOS->QTY_FLAG);        
        }
        if(MWIPLOTLOS->HIST_DEL_FLAG != 'Y')
        {
            sprintf(sql + strlen(sql), "AND HIST_DEL_FLAG = ' ' ");
        }

        //This is the sorting statement of the SQL
        sprintf(sql + strlen(sql), "ORDER BY TRAN_TIME DESC, LOT_ID ASC, HIST_SEQ DESC, QTY_FLAG ASC) LOS ) WHERE ROWSEQ >= %d ORDER BY ROWSEQ ASC", DBC_Q_COND_N.FROM_SEQ);

        ///* Check the sql */
        //fp=fopen("loss_sql.txt","w");
        //fprintf(fp,"%s",sql);
        //fclose(fp);

        /* Open the cursor */
        /* EXEC SQL PREPARE S FROM :sql; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )899;
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


        /* EXEC SQL DECLARE DBC_MWIPLOTLOS_CUR_2 CURSOR FOR S; */ 

        /* EXEC SQL OPEN DBC_MWIPLOTLOS_CUR_2; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )918;
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
    DB_stop_query_timer("DBC_open_mwiplotlos", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mwiplotlos(int sel_type, struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTLOS_N_TAG MWIPLOTLOS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
    case 1:
        /* EXEC SQL FETCH DBC_MWIPLOTLOS_CUR_1 INTO 
                                                :MWIPLOTLOS_N.LOT_ID,
                                                :MWIPLOTLOS_N.HIST_SEQ,
                                                :MWIPLOTLOS_N.QTY_FLAG,
                                                :MWIPLOTLOS_N.TRAN_TIME,
                                                :MWIPLOTLOS_N.HIST_DEL_FLAG,
                                                :MWIPLOTLOS_N.FACTORY,
                                                :MWIPLOTLOS_N.MAT_ID,
                                                :MWIPLOTLOS_N.MAT_VER,
                                                :MWIPLOTLOS_N.FLOW,
                                                :MWIPLOTLOS_N.FLOW_SEQ_NUM,
                                                :MWIPLOTLOS_N.OPER,
                                                :MWIPLOTLOS_N.RES_ID,
                                                :MWIPLOTLOS_N.CAUSE_FLOW,
                                                :MWIPLOTLOS_N.CAUSE_OPER,
                                                :MWIPLOTLOS_N.CAUSE_RES_ID,
                                                :MWIPLOTLOS_N.NEW_QTY,
                                                :MWIPLOTLOS_N.OLD_QTY,
                                                :MWIPLOTLOS_N.TOTAL_LOSS_QTY,
                                                :MWIPLOTLOS_N.LOSS_CODE_1,
                                                :MWIPLOTLOS_N.LOSS_CODE_2,
                                                :MWIPLOTLOS_N.LOSS_CODE_3,
                                                :MWIPLOTLOS_N.LOSS_CODE_4,
                                                :MWIPLOTLOS_N.LOSS_CODE_5,
                                                :MWIPLOTLOS_N.LOSS_CODE_6,
                                                :MWIPLOTLOS_N.LOSS_CODE_7,
                                                :MWIPLOTLOS_N.LOSS_CODE_8,
                                                :MWIPLOTLOS_N.LOSS_CODE_9,
                                                :MWIPLOTLOS_N.LOSS_CODE_10,
                                                :MWIPLOTLOS_N.LOSS_QTY_1,
                                                :MWIPLOTLOS_N.LOSS_QTY_2,
                                                :MWIPLOTLOS_N.LOSS_QTY_3,
                                                :MWIPLOTLOS_N.LOSS_QTY_4,
                                                :MWIPLOTLOS_N.LOSS_QTY_5,
                                                :MWIPLOTLOS_N.LOSS_QTY_6,
                                                :MWIPLOTLOS_N.LOSS_QTY_7,
                                                :MWIPLOTLOS_N.LOSS_QTY_8,
                                                :MWIPLOTLOS_N.LOSS_QTY_9,
                                                :MWIPLOTLOS_N.LOSS_QTY_10,
                                                :MWIPLOTLOS_N.LOSS_COMMENT_1,
                                                :MWIPLOTLOS_N.LOSS_COMMENT_2,
                                                :MWIPLOTLOS_N.LOSS_COMMENT_3; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )933;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (           int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[0] = (unsigned int  )26;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
        sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)(MWIPLOTLOS_N.QTY_FLAG);
        sqlstm.sqhstl[2] = (unsigned int  )2;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (         void  *)(MWIPLOTLOS_N.TRAN_TIME);
        sqlstm.sqhstl[3] = (unsigned int  )15;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         void  *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned int  )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (         void  *)(MWIPLOTLOS_N.HIST_DEL_FLAG);
        sqlstm.sqhstl[4] = (unsigned int  )2;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         void  *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned int  )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (         void  *)(MWIPLOTLOS_N.FACTORY);
        sqlstm.sqhstl[5] = (unsigned int  )11;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         void  *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned int  )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (         void  *)(MWIPLOTLOS_N.MAT_ID);
        sqlstm.sqhstl[6] = (unsigned int  )31;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         void  *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned int  )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (         void  *)&(MWIPLOTLOS_N.MAT_VER);
        sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         void  *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned int  )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (         void  *)(MWIPLOTLOS_N.FLOW);
        sqlstm.sqhstl[8] = (unsigned int  )21;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         void  *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned int  )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (         void  *)&(MWIPLOTLOS_N.FLOW_SEQ_NUM);
        sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         void  *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned int  )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (         void  *)(MWIPLOTLOS_N.OPER);
        sqlstm.sqhstl[10] = (unsigned int  )11;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         void  *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned int  )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (         void  *)(MWIPLOTLOS_N.RES_ID);
        sqlstm.sqhstl[11] = (unsigned int  )21;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         void  *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned int  )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (         void  *)(MWIPLOTLOS_N.CAUSE_FLOW);
        sqlstm.sqhstl[12] = (unsigned int  )21;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         void  *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned int  )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (         void  *)(MWIPLOTLOS_N.CAUSE_OPER);
        sqlstm.sqhstl[13] = (unsigned int  )11;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         void  *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned int  )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (         void  *)(MWIPLOTLOS_N.CAUSE_RES_ID);
        sqlstm.sqhstl[14] = (unsigned int  )21;
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         void  *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned int  )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (         void  *)&(MWIPLOTLOS_N.NEW_QTY);
        sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         void  *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned int  )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (         void  *)&(MWIPLOTLOS_N.OLD_QTY);
        sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         void  *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned int  )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (         void  *)&(MWIPLOTLOS_N.TOTAL_LOSS_QTY);
        sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         void  *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned int  )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_1);
        sqlstm.sqhstl[18] = (unsigned int  )11;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         void  *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned int  )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_2);
        sqlstm.sqhstl[19] = (unsigned int  )11;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         void  *)0;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned int  )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_3);
        sqlstm.sqhstl[20] = (unsigned int  )11;
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         void  *)0;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned int  )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_4);
        sqlstm.sqhstl[21] = (unsigned int  )11;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         void  *)0;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned int  )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_5);
        sqlstm.sqhstl[22] = (unsigned int  )11;
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         void  *)0;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned int  )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_6);
        sqlstm.sqhstl[23] = (unsigned int  )11;
        sqlstm.sqhsts[23] = (         int  )0;
        sqlstm.sqindv[23] = (         void  *)0;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned int  )0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqhstv[24] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_7);
        sqlstm.sqhstl[24] = (unsigned int  )11;
        sqlstm.sqhsts[24] = (         int  )0;
        sqlstm.sqindv[24] = (         void  *)0;
        sqlstm.sqinds[24] = (         int  )0;
        sqlstm.sqharm[24] = (unsigned int  )0;
        sqlstm.sqadto[24] = (unsigned short )0;
        sqlstm.sqtdso[24] = (unsigned short )0;
        sqlstm.sqhstv[25] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_8);
        sqlstm.sqhstl[25] = (unsigned int  )11;
        sqlstm.sqhsts[25] = (         int  )0;
        sqlstm.sqindv[25] = (         void  *)0;
        sqlstm.sqinds[25] = (         int  )0;
        sqlstm.sqharm[25] = (unsigned int  )0;
        sqlstm.sqadto[25] = (unsigned short )0;
        sqlstm.sqtdso[25] = (unsigned short )0;
        sqlstm.sqhstv[26] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_9);
        sqlstm.sqhstl[26] = (unsigned int  )11;
        sqlstm.sqhsts[26] = (         int  )0;
        sqlstm.sqindv[26] = (         void  *)0;
        sqlstm.sqinds[26] = (         int  )0;
        sqlstm.sqharm[26] = (unsigned int  )0;
        sqlstm.sqadto[26] = (unsigned short )0;
        sqlstm.sqtdso[26] = (unsigned short )0;
        sqlstm.sqhstv[27] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_10);
        sqlstm.sqhstl[27] = (unsigned int  )11;
        sqlstm.sqhsts[27] = (         int  )0;
        sqlstm.sqindv[27] = (         void  *)0;
        sqlstm.sqinds[27] = (         int  )0;
        sqlstm.sqharm[27] = (unsigned int  )0;
        sqlstm.sqadto[27] = (unsigned short )0;
        sqlstm.sqtdso[27] = (unsigned short )0;
        sqlstm.sqhstv[28] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_1);
        sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[28] = (         int  )0;
        sqlstm.sqindv[28] = (         void  *)0;
        sqlstm.sqinds[28] = (         int  )0;
        sqlstm.sqharm[28] = (unsigned int  )0;
        sqlstm.sqadto[28] = (unsigned short )0;
        sqlstm.sqtdso[28] = (unsigned short )0;
        sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_2);
        sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[29] = (         int  )0;
        sqlstm.sqindv[29] = (         void  *)0;
        sqlstm.sqinds[29] = (         int  )0;
        sqlstm.sqharm[29] = (unsigned int  )0;
        sqlstm.sqadto[29] = (unsigned short )0;
        sqlstm.sqtdso[29] = (unsigned short )0;
        sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_3);
        sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[30] = (         int  )0;
        sqlstm.sqindv[30] = (         void  *)0;
        sqlstm.sqinds[30] = (         int  )0;
        sqlstm.sqharm[30] = (unsigned int  )0;
        sqlstm.sqadto[30] = (unsigned short )0;
        sqlstm.sqtdso[30] = (unsigned short )0;
        sqlstm.sqhstv[31] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_4);
        sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[31] = (         int  )0;
        sqlstm.sqindv[31] = (         void  *)0;
        sqlstm.sqinds[31] = (         int  )0;
        sqlstm.sqharm[31] = (unsigned int  )0;
        sqlstm.sqadto[31] = (unsigned short )0;
        sqlstm.sqtdso[31] = (unsigned short )0;
        sqlstm.sqhstv[32] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_5);
        sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[32] = (         int  )0;
        sqlstm.sqindv[32] = (         void  *)0;
        sqlstm.sqinds[32] = (         int  )0;
        sqlstm.sqharm[32] = (unsigned int  )0;
        sqlstm.sqadto[32] = (unsigned short )0;
        sqlstm.sqtdso[32] = (unsigned short )0;
        sqlstm.sqhstv[33] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_6);
        sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[33] = (         int  )0;
        sqlstm.sqindv[33] = (         void  *)0;
        sqlstm.sqinds[33] = (         int  )0;
        sqlstm.sqharm[33] = (unsigned int  )0;
        sqlstm.sqadto[33] = (unsigned short )0;
        sqlstm.sqtdso[33] = (unsigned short )0;
        sqlstm.sqhstv[34] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_7);
        sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[34] = (         int  )0;
        sqlstm.sqindv[34] = (         void  *)0;
        sqlstm.sqinds[34] = (         int  )0;
        sqlstm.sqharm[34] = (unsigned int  )0;
        sqlstm.sqadto[34] = (unsigned short )0;
        sqlstm.sqtdso[34] = (unsigned short )0;
        sqlstm.sqhstv[35] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_8);
        sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[35] = (         int  )0;
        sqlstm.sqindv[35] = (         void  *)0;
        sqlstm.sqinds[35] = (         int  )0;
        sqlstm.sqharm[35] = (unsigned int  )0;
        sqlstm.sqadto[35] = (unsigned short )0;
        sqlstm.sqtdso[35] = (unsigned short )0;
        sqlstm.sqhstv[36] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_9);
        sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[36] = (         int  )0;
        sqlstm.sqindv[36] = (         void  *)0;
        sqlstm.sqinds[36] = (         int  )0;
        sqlstm.sqharm[36] = (unsigned int  )0;
        sqlstm.sqadto[36] = (unsigned short )0;
        sqlstm.sqtdso[36] = (unsigned short )0;
        sqlstm.sqhstv[37] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_10);
        sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[37] = (         int  )0;
        sqlstm.sqindv[37] = (         void  *)0;
        sqlstm.sqinds[37] = (         int  )0;
        sqlstm.sqharm[37] = (unsigned int  )0;
        sqlstm.sqadto[37] = (unsigned short )0;
        sqlstm.sqtdso[37] = (unsigned short )0;
        sqlstm.sqhstv[38] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_1);
        sqlstm.sqhstl[38] = (unsigned int  )401;
        sqlstm.sqhsts[38] = (         int  )0;
        sqlstm.sqindv[38] = (         void  *)0;
        sqlstm.sqinds[38] = (         int  )0;
        sqlstm.sqharm[38] = (unsigned int  )0;
        sqlstm.sqadto[38] = (unsigned short )0;
        sqlstm.sqtdso[38] = (unsigned short )0;
        sqlstm.sqhstv[39] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_2);
        sqlstm.sqhstl[39] = (unsigned int  )401;
        sqlstm.sqhsts[39] = (         int  )0;
        sqlstm.sqindv[39] = (         void  *)0;
        sqlstm.sqinds[39] = (         int  )0;
        sqlstm.sqharm[39] = (unsigned int  )0;
        sqlstm.sqadto[39] = (unsigned short )0;
        sqlstm.sqtdso[39] = (unsigned short )0;
        sqlstm.sqhstv[40] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_3);
        sqlstm.sqhstl[40] = (unsigned int  )401;
        sqlstm.sqhsts[40] = (         int  )0;
        sqlstm.sqindv[40] = (         void  *)0;
        sqlstm.sqinds[40] = (         int  )0;
        sqlstm.sqharm[40] = (unsigned int  )0;
        sqlstm.sqadto[40] = (unsigned short )0;
        sqlstm.sqtdso[40] = (unsigned short )0;
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
        /* EXEC SQL FETCH DBC_MWIPLOTLOS_CUR_2 INTO :DBC_Q_COND_N.FROM_SEQ,
                                                 :MWIPLOTLOS_N.LOT_ID,
                                                 :MWIPLOTLOS_N.HIST_SEQ,
                                                 :MWIPLOTLOS_N.QTY_FLAG,
                                                 :MWIPLOTLOS_N.TRAN_TIME,
                                                 :MWIPLOTLOS_N.HIST_DEL_FLAG,
                                                 :MWIPLOTLOS_N.FACTORY,
                                                 :MWIPLOTLOS_N.MAT_ID,
                                                 :MWIPLOTLOS_N.MAT_VER,
                                                 :MWIPLOTLOS_N.FLOW,
                                                 :MWIPLOTLOS_N.FLOW_SEQ_NUM,
                                                 :MWIPLOTLOS_N.OPER,
                                                 :MWIPLOTLOS_N.RES_ID,
                                                 :MWIPLOTLOS_N.CAUSE_FLOW,
                                                 :MWIPLOTLOS_N.CAUSE_OPER,
                                                 :MWIPLOTLOS_N.CAUSE_RES_ID,
                                                 :MWIPLOTLOS_N.NEW_QTY,
                                                 :MWIPLOTLOS_N.OLD_QTY,
                                                 :MWIPLOTLOS_N.TOTAL_LOSS_QTY,
                                                 :MWIPLOTLOS_N.LOSS_CODE_1,
                                                 :MWIPLOTLOS_N.LOSS_CODE_2,
                                                 :MWIPLOTLOS_N.LOSS_CODE_3,
                                                 :MWIPLOTLOS_N.LOSS_CODE_4,
                                                 :MWIPLOTLOS_N.LOSS_CODE_5,
                                                 :MWIPLOTLOS_N.LOSS_CODE_6,
                                                 :MWIPLOTLOS_N.LOSS_CODE_7,
                                                 :MWIPLOTLOS_N.LOSS_CODE_8,
                                                 :MWIPLOTLOS_N.LOSS_CODE_9,
                                                 :MWIPLOTLOS_N.LOSS_CODE_10,
                                                 :MWIPLOTLOS_N.LOSS_QTY_1,
                                                 :MWIPLOTLOS_N.LOSS_QTY_2,
                                                 :MWIPLOTLOS_N.LOSS_QTY_3,
                                                 :MWIPLOTLOS_N.LOSS_QTY_4,
                                                 :MWIPLOTLOS_N.LOSS_QTY_5,
                                                 :MWIPLOTLOS_N.LOSS_QTY_6,
                                                 :MWIPLOTLOS_N.LOSS_QTY_7,
                                                 :MWIPLOTLOS_N.LOSS_QTY_8,
                                                 :MWIPLOTLOS_N.LOSS_QTY_9,
                                                 :MWIPLOTLOS_N.LOSS_QTY_10,
                                                 :MWIPLOTLOS_N.LOSS_COMMENT_1,
                                                 :MWIPLOTLOS_N.LOSS_COMMENT_2,
                                                 :MWIPLOTLOS_N.LOSS_COMMENT_3; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1112;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (           int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (         void  *)&(DBC_Q_COND_N.FROM_SEQ);
        sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)(MWIPLOTLOS_N.LOT_ID);
        sqlstm.sqhstl[1] = (unsigned int  )26;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&(MWIPLOTLOS_N.HIST_SEQ);
        sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (         void  *)(MWIPLOTLOS_N.QTY_FLAG);
        sqlstm.sqhstl[3] = (unsigned int  )2;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         void  *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned int  )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (         void  *)(MWIPLOTLOS_N.TRAN_TIME);
        sqlstm.sqhstl[4] = (unsigned int  )15;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         void  *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned int  )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (         void  *)(MWIPLOTLOS_N.HIST_DEL_FLAG);
        sqlstm.sqhstl[5] = (unsigned int  )2;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         void  *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned int  )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (         void  *)(MWIPLOTLOS_N.FACTORY);
        sqlstm.sqhstl[6] = (unsigned int  )11;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         void  *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned int  )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (         void  *)(MWIPLOTLOS_N.MAT_ID);
        sqlstm.sqhstl[7] = (unsigned int  )31;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         void  *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned int  )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (         void  *)&(MWIPLOTLOS_N.MAT_VER);
        sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         void  *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned int  )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (         void  *)(MWIPLOTLOS_N.FLOW);
        sqlstm.sqhstl[9] = (unsigned int  )21;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         void  *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned int  )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (         void  *)&(MWIPLOTLOS_N.FLOW_SEQ_NUM);
        sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         void  *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned int  )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (         void  *)(MWIPLOTLOS_N.OPER);
        sqlstm.sqhstl[11] = (unsigned int  )11;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         void  *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned int  )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (         void  *)(MWIPLOTLOS_N.RES_ID);
        sqlstm.sqhstl[12] = (unsigned int  )21;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         void  *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned int  )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (         void  *)(MWIPLOTLOS_N.CAUSE_FLOW);
        sqlstm.sqhstl[13] = (unsigned int  )21;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         void  *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned int  )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (         void  *)(MWIPLOTLOS_N.CAUSE_OPER);
        sqlstm.sqhstl[14] = (unsigned int  )11;
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         void  *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned int  )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (         void  *)(MWIPLOTLOS_N.CAUSE_RES_ID);
        sqlstm.sqhstl[15] = (unsigned int  )21;
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         void  *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned int  )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (         void  *)&(MWIPLOTLOS_N.NEW_QTY);
        sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         void  *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned int  )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (         void  *)&(MWIPLOTLOS_N.OLD_QTY);
        sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         void  *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned int  )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (         void  *)&(MWIPLOTLOS_N.TOTAL_LOSS_QTY);
        sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         void  *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned int  )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_1);
        sqlstm.sqhstl[19] = (unsigned int  )11;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         void  *)0;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned int  )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_2);
        sqlstm.sqhstl[20] = (unsigned int  )11;
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         void  *)0;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned int  )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_3);
        sqlstm.sqhstl[21] = (unsigned int  )11;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         void  *)0;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned int  )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_4);
        sqlstm.sqhstl[22] = (unsigned int  )11;
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         void  *)0;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned int  )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_5);
        sqlstm.sqhstl[23] = (unsigned int  )11;
        sqlstm.sqhsts[23] = (         int  )0;
        sqlstm.sqindv[23] = (         void  *)0;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned int  )0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqhstv[24] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_6);
        sqlstm.sqhstl[24] = (unsigned int  )11;
        sqlstm.sqhsts[24] = (         int  )0;
        sqlstm.sqindv[24] = (         void  *)0;
        sqlstm.sqinds[24] = (         int  )0;
        sqlstm.sqharm[24] = (unsigned int  )0;
        sqlstm.sqadto[24] = (unsigned short )0;
        sqlstm.sqtdso[24] = (unsigned short )0;
        sqlstm.sqhstv[25] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_7);
        sqlstm.sqhstl[25] = (unsigned int  )11;
        sqlstm.sqhsts[25] = (         int  )0;
        sqlstm.sqindv[25] = (         void  *)0;
        sqlstm.sqinds[25] = (         int  )0;
        sqlstm.sqharm[25] = (unsigned int  )0;
        sqlstm.sqadto[25] = (unsigned short )0;
        sqlstm.sqtdso[25] = (unsigned short )0;
        sqlstm.sqhstv[26] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_8);
        sqlstm.sqhstl[26] = (unsigned int  )11;
        sqlstm.sqhsts[26] = (         int  )0;
        sqlstm.sqindv[26] = (         void  *)0;
        sqlstm.sqinds[26] = (         int  )0;
        sqlstm.sqharm[26] = (unsigned int  )0;
        sqlstm.sqadto[26] = (unsigned short )0;
        sqlstm.sqtdso[26] = (unsigned short )0;
        sqlstm.sqhstv[27] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_9);
        sqlstm.sqhstl[27] = (unsigned int  )11;
        sqlstm.sqhsts[27] = (         int  )0;
        sqlstm.sqindv[27] = (         void  *)0;
        sqlstm.sqinds[27] = (         int  )0;
        sqlstm.sqharm[27] = (unsigned int  )0;
        sqlstm.sqadto[27] = (unsigned short )0;
        sqlstm.sqtdso[27] = (unsigned short )0;
        sqlstm.sqhstv[28] = (         void  *)(MWIPLOTLOS_N.LOSS_CODE_10);
        sqlstm.sqhstl[28] = (unsigned int  )11;
        sqlstm.sqhsts[28] = (         int  )0;
        sqlstm.sqindv[28] = (         void  *)0;
        sqlstm.sqinds[28] = (         int  )0;
        sqlstm.sqharm[28] = (unsigned int  )0;
        sqlstm.sqadto[28] = (unsigned short )0;
        sqlstm.sqtdso[28] = (unsigned short )0;
        sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_1);
        sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[29] = (         int  )0;
        sqlstm.sqindv[29] = (         void  *)0;
        sqlstm.sqinds[29] = (         int  )0;
        sqlstm.sqharm[29] = (unsigned int  )0;
        sqlstm.sqadto[29] = (unsigned short )0;
        sqlstm.sqtdso[29] = (unsigned short )0;
        sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_2);
        sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[30] = (         int  )0;
        sqlstm.sqindv[30] = (         void  *)0;
        sqlstm.sqinds[30] = (         int  )0;
        sqlstm.sqharm[30] = (unsigned int  )0;
        sqlstm.sqadto[30] = (unsigned short )0;
        sqlstm.sqtdso[30] = (unsigned short )0;
        sqlstm.sqhstv[31] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_3);
        sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[31] = (         int  )0;
        sqlstm.sqindv[31] = (         void  *)0;
        sqlstm.sqinds[31] = (         int  )0;
        sqlstm.sqharm[31] = (unsigned int  )0;
        sqlstm.sqadto[31] = (unsigned short )0;
        sqlstm.sqtdso[31] = (unsigned short )0;
        sqlstm.sqhstv[32] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_4);
        sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[32] = (         int  )0;
        sqlstm.sqindv[32] = (         void  *)0;
        sqlstm.sqinds[32] = (         int  )0;
        sqlstm.sqharm[32] = (unsigned int  )0;
        sqlstm.sqadto[32] = (unsigned short )0;
        sqlstm.sqtdso[32] = (unsigned short )0;
        sqlstm.sqhstv[33] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_5);
        sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[33] = (         int  )0;
        sqlstm.sqindv[33] = (         void  *)0;
        sqlstm.sqinds[33] = (         int  )0;
        sqlstm.sqharm[33] = (unsigned int  )0;
        sqlstm.sqadto[33] = (unsigned short )0;
        sqlstm.sqtdso[33] = (unsigned short )0;
        sqlstm.sqhstv[34] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_6);
        sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[34] = (         int  )0;
        sqlstm.sqindv[34] = (         void  *)0;
        sqlstm.sqinds[34] = (         int  )0;
        sqlstm.sqharm[34] = (unsigned int  )0;
        sqlstm.sqadto[34] = (unsigned short )0;
        sqlstm.sqtdso[34] = (unsigned short )0;
        sqlstm.sqhstv[35] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_7);
        sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[35] = (         int  )0;
        sqlstm.sqindv[35] = (         void  *)0;
        sqlstm.sqinds[35] = (         int  )0;
        sqlstm.sqharm[35] = (unsigned int  )0;
        sqlstm.sqadto[35] = (unsigned short )0;
        sqlstm.sqtdso[35] = (unsigned short )0;
        sqlstm.sqhstv[36] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_8);
        sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[36] = (         int  )0;
        sqlstm.sqindv[36] = (         void  *)0;
        sqlstm.sqinds[36] = (         int  )0;
        sqlstm.sqharm[36] = (unsigned int  )0;
        sqlstm.sqadto[36] = (unsigned short )0;
        sqlstm.sqtdso[36] = (unsigned short )0;
        sqlstm.sqhstv[37] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_9);
        sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[37] = (         int  )0;
        sqlstm.sqindv[37] = (         void  *)0;
        sqlstm.sqinds[37] = (         int  )0;
        sqlstm.sqharm[37] = (unsigned int  )0;
        sqlstm.sqadto[37] = (unsigned short )0;
        sqlstm.sqtdso[37] = (unsigned short )0;
        sqlstm.sqhstv[38] = (         void  *)&(MWIPLOTLOS_N.LOSS_QTY_10);
        sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
        sqlstm.sqhsts[38] = (         int  )0;
        sqlstm.sqindv[38] = (         void  *)0;
        sqlstm.sqinds[38] = (         int  )0;
        sqlstm.sqharm[38] = (unsigned int  )0;
        sqlstm.sqadto[38] = (unsigned short )0;
        sqlstm.sqtdso[38] = (unsigned short )0;
        sqlstm.sqhstv[39] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_1);
        sqlstm.sqhstl[39] = (unsigned int  )401;
        sqlstm.sqhsts[39] = (         int  )0;
        sqlstm.sqindv[39] = (         void  *)0;
        sqlstm.sqinds[39] = (         int  )0;
        sqlstm.sqharm[39] = (unsigned int  )0;
        sqlstm.sqadto[39] = (unsigned short )0;
        sqlstm.sqtdso[39] = (unsigned short )0;
        sqlstm.sqhstv[40] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_2);
        sqlstm.sqhstl[40] = (unsigned int  )401;
        sqlstm.sqhsts[40] = (         int  )0;
        sqlstm.sqindv[40] = (         void  *)0;
        sqlstm.sqinds[40] = (         int  )0;
        sqlstm.sqharm[40] = (unsigned int  )0;
        sqlstm.sqadto[40] = (unsigned short )0;
        sqlstm.sqtdso[40] = (unsigned short )0;
        sqlstm.sqhstv[41] = (         void  *)(MWIPLOTLOS_N.LOSS_COMMENT_3);
        sqlstm.sqhstl[41] = (unsigned int  )401;
        sqlstm.sqhsts[41] = (         int  )0;
        sqlstm.sqindv[41] = (         void  *)0;
        sqlstm.sqinds[41] = (         int  )0;
        sqlstm.sqharm[41] = (unsigned int  )0;
        sqlstm.sqadto[41] = (unsigned short )0;
        sqlstm.sqtdso[41] = (unsigned short )0;
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


            DB_del_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);
        break;


    default:
        DB_error_code = 9999;
        memset(DB_error_msg, ' ', sizeof(DB_error_msg));
        memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
        break;
    }


    if(DB_error_code == 0)
    {
        DBC_del_null_mwiplotlos(&MWIPLOTLOS_N, MWIPLOTLOS);
    }
    DB_stop_query_timer("DBC_fetch_mwiplotlos", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mwiplotlos(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
    case 1:
        /* EXEC SQL CLOSE DBC_MWIPLOTLOS_CUR_1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1295;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) DB_usr_error();
}


        break;

    case 2:
        /* EXEC SQL CLOSE DBC_MWIPLOTLOS_CUR_2; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1310;
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
    DB_stop_query_timer("DBC_close_mwiplotlos", sel_type);
}


/* Initialize Function */
void DBC_init_mwiplotlos(struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    /* memset by Space */
    memset(MWIPLOTLOS, ' ', sizeof(struct MWIPLOTLOS_TAG));

    MWIPLOTLOS->HIST_SEQ = 0;
    MWIPLOTLOS->MAT_VER = 0;
    MWIPLOTLOS->FLOW_SEQ_NUM = 0;
    MWIPLOTLOS->NEW_QTY = 0;
    MWIPLOTLOS->OLD_QTY = 0;
    MWIPLOTLOS->TOTAL_LOSS_QTY = 0;
    MWIPLOTLOS->LOSS_QTY_1 = 0;
    MWIPLOTLOS->LOSS_QTY_2 = 0;
    MWIPLOTLOS->LOSS_QTY_3 = 0;
    MWIPLOTLOS->LOSS_QTY_4 = 0;
    MWIPLOTLOS->LOSS_QTY_5 = 0;
    MWIPLOTLOS->LOSS_QTY_6 = 0;
    MWIPLOTLOS->LOSS_QTY_7 = 0;
    MWIPLOTLOS->LOSS_QTY_8 = 0;
    MWIPLOTLOS->LOSS_QTY_9 = 0;
    MWIPLOTLOS->LOSS_QTY_10 = 0;
}


/* Add Null Function */
void DBC_add_null_mwiplotlos(struct MWIPLOTLOS_N_TAG *MWIPLOTLOS_N, struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    /* memset by NULL */
    memset(MWIPLOTLOS_N, '\0', sizeof(struct MWIPLOTLOS_N_TAG));

    MEMCPY_AN(MWIPLOTLOS_N->LOT_ID, MWIPLOTLOS->LOT_ID, sizeof(MWIPLOTLOS->LOT_ID));
    MWIPLOTLOS_N->HIST_SEQ = MWIPLOTLOS->HIST_SEQ;
    MWIPLOTLOS_N->QTY_FLAG[0] = MWIPLOTLOS->QTY_FLAG;
    MEMCPY_AN(MWIPLOTLOS_N->TRAN_TIME, MWIPLOTLOS->TRAN_TIME, sizeof(MWIPLOTLOS->TRAN_TIME));
    MWIPLOTLOS_N->HIST_DEL_FLAG[0] = MWIPLOTLOS->HIST_DEL_FLAG;
    MEMCPY_AN(MWIPLOTLOS_N->FACTORY, MWIPLOTLOS->FACTORY, sizeof(MWIPLOTLOS->FACTORY));
    MEMCPY_AN(MWIPLOTLOS_N->MAT_ID, MWIPLOTLOS->MAT_ID, sizeof(MWIPLOTLOS->MAT_ID));
    MWIPLOTLOS_N->MAT_VER = MWIPLOTLOS->MAT_VER;
    MEMCPY_AN(MWIPLOTLOS_N->FLOW, MWIPLOTLOS->FLOW, sizeof(MWIPLOTLOS->FLOW));
    MWIPLOTLOS_N->FLOW_SEQ_NUM = MWIPLOTLOS->FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPLOTLOS_N->OPER, MWIPLOTLOS->OPER, sizeof(MWIPLOTLOS->OPER));
    MEMCPY_AN(MWIPLOTLOS_N->RES_ID, MWIPLOTLOS->RES_ID, sizeof(MWIPLOTLOS->RES_ID));
    MEMCPY_AN(MWIPLOTLOS_N->CAUSE_FLOW, MWIPLOTLOS->CAUSE_FLOW, sizeof(MWIPLOTLOS->CAUSE_FLOW));
    MEMCPY_AN(MWIPLOTLOS_N->CAUSE_OPER, MWIPLOTLOS->CAUSE_OPER, sizeof(MWIPLOTLOS->CAUSE_OPER));
    MEMCPY_AN(MWIPLOTLOS_N->CAUSE_RES_ID, MWIPLOTLOS->CAUSE_RES_ID, sizeof(MWIPLOTLOS->CAUSE_RES_ID));
    MWIPLOTLOS_N->NEW_QTY = MWIPLOTLOS->NEW_QTY;
    MWIPLOTLOS_N->OLD_QTY = MWIPLOTLOS->OLD_QTY;
    MWIPLOTLOS_N->TOTAL_LOSS_QTY = MWIPLOTLOS->TOTAL_LOSS_QTY;
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_CODE_1, MWIPLOTLOS->LOSS_CODE_1, sizeof(MWIPLOTLOS->LOSS_CODE_1));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_CODE_2, MWIPLOTLOS->LOSS_CODE_2, sizeof(MWIPLOTLOS->LOSS_CODE_2));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_CODE_3, MWIPLOTLOS->LOSS_CODE_3, sizeof(MWIPLOTLOS->LOSS_CODE_3));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_CODE_4, MWIPLOTLOS->LOSS_CODE_4, sizeof(MWIPLOTLOS->LOSS_CODE_4));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_CODE_5, MWIPLOTLOS->LOSS_CODE_5, sizeof(MWIPLOTLOS->LOSS_CODE_5));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_CODE_6, MWIPLOTLOS->LOSS_CODE_6, sizeof(MWIPLOTLOS->LOSS_CODE_6));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_CODE_7, MWIPLOTLOS->LOSS_CODE_7, sizeof(MWIPLOTLOS->LOSS_CODE_7));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_CODE_8, MWIPLOTLOS->LOSS_CODE_8, sizeof(MWIPLOTLOS->LOSS_CODE_8));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_CODE_9, MWIPLOTLOS->LOSS_CODE_9, sizeof(MWIPLOTLOS->LOSS_CODE_9));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_CODE_10, MWIPLOTLOS->LOSS_CODE_10, sizeof(MWIPLOTLOS->LOSS_CODE_10));
    MWIPLOTLOS_N->LOSS_QTY_1 = MWIPLOTLOS->LOSS_QTY_1;
    MWIPLOTLOS_N->LOSS_QTY_2 = MWIPLOTLOS->LOSS_QTY_2;
    MWIPLOTLOS_N->LOSS_QTY_3 = MWIPLOTLOS->LOSS_QTY_3;
    MWIPLOTLOS_N->LOSS_QTY_4 = MWIPLOTLOS->LOSS_QTY_4;
    MWIPLOTLOS_N->LOSS_QTY_5 = MWIPLOTLOS->LOSS_QTY_5;
    MWIPLOTLOS_N->LOSS_QTY_6 = MWIPLOTLOS->LOSS_QTY_6;
    MWIPLOTLOS_N->LOSS_QTY_7 = MWIPLOTLOS->LOSS_QTY_7;
    MWIPLOTLOS_N->LOSS_QTY_8 = MWIPLOTLOS->LOSS_QTY_8;
    MWIPLOTLOS_N->LOSS_QTY_9 = MWIPLOTLOS->LOSS_QTY_9;
    MWIPLOTLOS_N->LOSS_QTY_10 = MWIPLOTLOS->LOSS_QTY_10;
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_COMMENT_1, MWIPLOTLOS->LOSS_COMMENT_1, sizeof(MWIPLOTLOS->LOSS_COMMENT_1));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_COMMENT_2, MWIPLOTLOS->LOSS_COMMENT_2, sizeof(MWIPLOTLOS->LOSS_COMMENT_2));
    MEMCPY_AN(MWIPLOTLOS_N->LOSS_COMMENT_3, MWIPLOTLOS->LOSS_COMMENT_3, sizeof(MWIPLOTLOS->LOSS_COMMENT_3));
}


/* Del Null Function */
void DBC_del_null_mwiplotlos(struct MWIPLOTLOS_N_TAG *MWIPLOTLOS_N, struct MWIPLOTLOS_TAG *MWIPLOTLOS)
{
    MEMCPY_DN(MWIPLOTLOS->LOT_ID, MWIPLOTLOS_N->LOT_ID, sizeof(MWIPLOTLOS->LOT_ID));
    MWIPLOTLOS->HIST_SEQ = MWIPLOTLOS_N->HIST_SEQ;
    MWIPLOTLOS->QTY_FLAG = MWIPLOTLOS_N->QTY_FLAG[0];
    MEMCPY_DN(MWIPLOTLOS->TRAN_TIME, MWIPLOTLOS_N->TRAN_TIME, sizeof(MWIPLOTLOS->TRAN_TIME));
    MWIPLOTLOS->HIST_DEL_FLAG = MWIPLOTLOS_N->HIST_DEL_FLAG[0];
    MEMCPY_DN(MWIPLOTLOS->FACTORY, MWIPLOTLOS_N->FACTORY, sizeof(MWIPLOTLOS->FACTORY));
    MEMCPY_DN(MWIPLOTLOS->MAT_ID, MWIPLOTLOS_N->MAT_ID, sizeof(MWIPLOTLOS->MAT_ID));
    MWIPLOTLOS->MAT_VER = MWIPLOTLOS_N->MAT_VER;
    MEMCPY_DN(MWIPLOTLOS->FLOW, MWIPLOTLOS_N->FLOW, sizeof(MWIPLOTLOS->FLOW));
    MWIPLOTLOS->FLOW_SEQ_NUM = MWIPLOTLOS_N->FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPLOTLOS->OPER, MWIPLOTLOS_N->OPER, sizeof(MWIPLOTLOS->OPER));
    MEMCPY_DN(MWIPLOTLOS->RES_ID, MWIPLOTLOS_N->RES_ID, sizeof(MWIPLOTLOS->RES_ID));
    MEMCPY_DN(MWIPLOTLOS->CAUSE_FLOW, MWIPLOTLOS_N->CAUSE_FLOW, sizeof(MWIPLOTLOS->CAUSE_FLOW));
    MEMCPY_DN(MWIPLOTLOS->CAUSE_OPER, MWIPLOTLOS_N->CAUSE_OPER, sizeof(MWIPLOTLOS->CAUSE_OPER));
    MEMCPY_DN(MWIPLOTLOS->CAUSE_RES_ID, MWIPLOTLOS_N->CAUSE_RES_ID, sizeof(MWIPLOTLOS->CAUSE_RES_ID));
    MWIPLOTLOS->NEW_QTY = MWIPLOTLOS_N->NEW_QTY;
    MWIPLOTLOS->OLD_QTY = MWIPLOTLOS_N->OLD_QTY;
    MWIPLOTLOS->TOTAL_LOSS_QTY = MWIPLOTLOS_N->TOTAL_LOSS_QTY;
    MEMCPY_DN(MWIPLOTLOS->LOSS_CODE_1, MWIPLOTLOS_N->LOSS_CODE_1, sizeof(MWIPLOTLOS->LOSS_CODE_1));
    MEMCPY_DN(MWIPLOTLOS->LOSS_CODE_2, MWIPLOTLOS_N->LOSS_CODE_2, sizeof(MWIPLOTLOS->LOSS_CODE_2));
    MEMCPY_DN(MWIPLOTLOS->LOSS_CODE_3, MWIPLOTLOS_N->LOSS_CODE_3, sizeof(MWIPLOTLOS->LOSS_CODE_3));
    MEMCPY_DN(MWIPLOTLOS->LOSS_CODE_4, MWIPLOTLOS_N->LOSS_CODE_4, sizeof(MWIPLOTLOS->LOSS_CODE_4));
    MEMCPY_DN(MWIPLOTLOS->LOSS_CODE_5, MWIPLOTLOS_N->LOSS_CODE_5, sizeof(MWIPLOTLOS->LOSS_CODE_5));
    MEMCPY_DN(MWIPLOTLOS->LOSS_CODE_6, MWIPLOTLOS_N->LOSS_CODE_6, sizeof(MWIPLOTLOS->LOSS_CODE_6));
    MEMCPY_DN(MWIPLOTLOS->LOSS_CODE_7, MWIPLOTLOS_N->LOSS_CODE_7, sizeof(MWIPLOTLOS->LOSS_CODE_7));
    MEMCPY_DN(MWIPLOTLOS->LOSS_CODE_8, MWIPLOTLOS_N->LOSS_CODE_8, sizeof(MWIPLOTLOS->LOSS_CODE_8));
    MEMCPY_DN(MWIPLOTLOS->LOSS_CODE_9, MWIPLOTLOS_N->LOSS_CODE_9, sizeof(MWIPLOTLOS->LOSS_CODE_9));
    MEMCPY_DN(MWIPLOTLOS->LOSS_CODE_10, MWIPLOTLOS_N->LOSS_CODE_10, sizeof(MWIPLOTLOS->LOSS_CODE_10));
    MWIPLOTLOS->LOSS_QTY_1 = MWIPLOTLOS_N->LOSS_QTY_1;
    MWIPLOTLOS->LOSS_QTY_2 = MWIPLOTLOS_N->LOSS_QTY_2;
    MWIPLOTLOS->LOSS_QTY_3 = MWIPLOTLOS_N->LOSS_QTY_3;
    MWIPLOTLOS->LOSS_QTY_4 = MWIPLOTLOS_N->LOSS_QTY_4;
    MWIPLOTLOS->LOSS_QTY_5 = MWIPLOTLOS_N->LOSS_QTY_5;
    MWIPLOTLOS->LOSS_QTY_6 = MWIPLOTLOS_N->LOSS_QTY_6;
    MWIPLOTLOS->LOSS_QTY_7 = MWIPLOTLOS_N->LOSS_QTY_7;
    MWIPLOTLOS->LOSS_QTY_8 = MWIPLOTLOS_N->LOSS_QTY_8;
    MWIPLOTLOS->LOSS_QTY_9 = MWIPLOTLOS_N->LOSS_QTY_9;
    MWIPLOTLOS->LOSS_QTY_10 = MWIPLOTLOS_N->LOSS_QTY_10;
    MEMCPY_DN(MWIPLOTLOS->LOSS_COMMENT_1, MWIPLOTLOS_N->LOSS_COMMENT_1, sizeof(MWIPLOTLOS->LOSS_COMMENT_1));
    MEMCPY_DN(MWIPLOTLOS->LOSS_COMMENT_2, MWIPLOTLOS_N->LOSS_COMMENT_2, sizeof(MWIPLOTLOS->LOSS_COMMENT_2));
    MEMCPY_DN(MWIPLOTLOS->LOSS_COMMENT_3, MWIPLOTLOS_N->LOSS_COMMENT_3, sizeof(MWIPLOTLOS->LOSS_COMMENT_3));
}



