
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
    "DBC_mmsgbbshis.pc"
};


static unsigned int sqlctx = 9124739;


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
            void  *sqhstv[54];
   unsigned int   sqhstl[54];
            int   sqhsts[54];
            void  *sqindv[54];
            int   sqinds[54];
   unsigned int   sqharm[54];
   unsigned int   *sqharc[54];
   unsigned short  sqadto[54];
   unsigned short  sqtdso[54];
} sqlstm = {13,54};

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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,931,0,4,45,0,0,54,4,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
236,0,0,2,943,0,4,186,0,0,54,4,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
467,0,0,3,123,0,4,330,0,0,5,4,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
502,0,0,4,105,0,2,367,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
533,0,0,5,806,0,3,397,0,0,50,50,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,
748,0,0,6,819,0,5,520,0,0,50,50,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,
963,0,0,7,0,0,17,910,0,0,1,1,0,1,0,1,97,0,0,
982,0,0,7,0,0,45,912,0,0,0,0,0,1,0,
997,0,0,7,0,0,17,1239,0,0,1,1,0,1,0,1,97,0,0,
1016,0,0,7,0,0,45,1241,0,0,0,0,0,1,0,
1031,0,0,7,0,0,13,1270,0,0,51,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,
1250,0,0,7,0,0,13,1324,0,0,51,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,
1469,0,0,7,0,0,15,1404,0,0,0,0,0,1,0,
1484,0,0,7,0,0,15,1407,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mmsgbbshis.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2009/04/06 15:32:01
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2007 MIRACOM,INC.
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
void DBC_add_null_mmsgbbshis(struct MMSGBBSHIS_N_TAG *MMSGBBSHIS_N, struct MMSGBBSHIS_TAG *MMSGBBSHIS);
void DBC_del_null_mmsgbbshis(struct MMSGBBSHIS_N_TAG *MMSGBBSHIS_N, struct MMSGBBSHIS_TAG *MMSGBBSHIS);


/* SQL SELECT Function */
void DBC_select_mmsgbbshis(int sel_type, struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MMSGBBSHIS_N_TAG MMSGBBSHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mmsgbbshis(&MMSGBBSHIS_N, MMSGBBSHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         MAIN_MENU_ID,
                         SUB_MENU_ID,
                         BBS_SEQ,
                         TRAN_TIME,
                         LOT_ID,
                         SUBLOT_ID,
                         OPER,
                         RES_ID,
                         SUBRES_ID,
                         MSG_TYPE,
                         MSG_TITLE,
                         MSG_TAG,
                         BBS_CMF_1,
                         BBS_CMF_2,
                         BBS_CMF_3,
                         BBS_CMF_4,
                         BBS_CMF_5,
                         BBS_CMF_6,
                         BBS_CMF_7,
                         BBS_CMF_8,
                         BBS_CMF_9,
                         BBS_CMF_10,
                         REPLY_COUNT,
                         DELETE_FLAG,
                         CREATE_USER_ID,
                         CREATE_TIME,
                         UPDATE_USER_ID,
                         UPDATE_TIME,
                         SYS_MSG_FLAG,
                         POPUP_CYCLE,
                         PRIORITY,
                         APPLY_SHIFT,
                         APPLY_START_TIME,
                         APPLY_END_TIME,
                         AREA_ID,
                         SUB_AREA_ID,
                         RESG_ID,
                         MAT_ID,
                         FLOW,
                         RCV_USER_ID,
                         SEC_GRP_ID,
                         PRV_GRP_ID,
                         MODAL_FLAG,
                         AUTO_CLOSE_FLAG,
                         AUTO_CLOSE_TIME,
                         ACK_FLAG,
                         ACK_TIME,
                         ACK_USER_ID,
                         RCV_FACTORY
                INTO 
                    :MMSGBBSHIS_N.FACTORY,
                    :MMSGBBSHIS_N.MAIN_MENU_ID,
                    :MMSGBBSHIS_N.SUB_MENU_ID,
                    :MMSGBBSHIS_N.BBS_SEQ,
                    :MMSGBBSHIS_N.TRAN_TIME,
                    :MMSGBBSHIS_N.LOT_ID,
                    :MMSGBBSHIS_N.SUBLOT_ID,
                    :MMSGBBSHIS_N.OPER,
                    :MMSGBBSHIS_N.RES_ID,
                    :MMSGBBSHIS_N.SUBRES_ID,
                    :MMSGBBSHIS_N.MSG_TYPE,
                    :MMSGBBSHIS_N.MSG_TITLE,
                    :MMSGBBSHIS_N.MSG_TAG,
                    :MMSGBBSHIS_N.BBS_CMF_1,
                    :MMSGBBSHIS_N.BBS_CMF_2,
                    :MMSGBBSHIS_N.BBS_CMF_3,
                    :MMSGBBSHIS_N.BBS_CMF_4,
                    :MMSGBBSHIS_N.BBS_CMF_5,
                    :MMSGBBSHIS_N.BBS_CMF_6,
                    :MMSGBBSHIS_N.BBS_CMF_7,
                    :MMSGBBSHIS_N.BBS_CMF_8,
                    :MMSGBBSHIS_N.BBS_CMF_9,
                    :MMSGBBSHIS_N.BBS_CMF_10,
                    :MMSGBBSHIS_N.REPLY_COUNT,
                    :MMSGBBSHIS_N.DELETE_FLAG,
                    :MMSGBBSHIS_N.CREATE_USER_ID,
                    :MMSGBBSHIS_N.CREATE_TIME,
                    :MMSGBBSHIS_N.UPDATE_USER_ID,
                    :MMSGBBSHIS_N.UPDATE_TIME,
                    :MMSGBBSHIS_N.SYS_MSG_FLAG,
                    :MMSGBBSHIS_N.POPUP_CYCLE,
                    :MMSGBBSHIS_N.PRIORITY,
                    :MMSGBBSHIS_N.APPLY_SHIFT,
                    :MMSGBBSHIS_N.APPLY_START_TIME,
                    :MMSGBBSHIS_N.APPLY_END_TIME,
                    :MMSGBBSHIS_N.AREA_ID,
                    :MMSGBBSHIS_N.SUB_AREA_ID,
                    :MMSGBBSHIS_N.RESG_ID,
                    :MMSGBBSHIS_N.MAT_ID,
                    :MMSGBBSHIS_N.FLOW,
                    :MMSGBBSHIS_N.RCV_USER_ID,
                    :MMSGBBSHIS_N.SEC_GRP_ID,
                    :MMSGBBSHIS_N.PRV_GRP_ID,
                    :MMSGBBSHIS_N.MODAL_FLAG,
                    :MMSGBBSHIS_N.AUTO_CLOSE_FLAG,
                    :MMSGBBSHIS_N.AUTO_CLOSE_TIME,
                    :MMSGBBSHIS_N.ACK_FLAG,
                    :MMSGBBSHIS_N.ACK_TIME,
                    :MMSGBBSHIS_N.ACK_USER_ID,
                    :MMSGBBSHIS_N.RCV_FACTORY
                FROM MMSGBBSHIS
                WHERE FACTORY = :MMSGBBSHIS_N.FACTORY
                    AND MAIN_MENU_ID = :MMSGBBSHIS_N.MAIN_MENU_ID
                    AND SUB_MENU_ID = :MMSGBBSHIS_N.SUB_MENU_ID
                    AND BBS_SEQ = :MMSGBBSHIS_N.BBS_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,MAIN_MENU_ID ,SUB_MENU_ID ,BBS_S\
EQ ,TRAN_TIME ,LOT_ID ,SUBLOT_ID ,OPER ,RES_ID ,SUBRES_ID ,MSG_TYPE ,MSG_TITL\
E ,MSG_TAG ,BBS_CMF_1 ,BBS_CMF_2 ,BBS_CMF_3 ,BBS_CMF_4 ,BBS_CMF_5 ,BBS_CMF_6 \
,BBS_CMF_7 ,BBS_CMF_8 ,BBS_CMF_9 ,BBS_CMF_10 ,REPLY_COUNT ,DELETE_FLAG ,CREAT\
E_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,SYS_MSG_FLAG ,POPUP_CYCL\
E ,PRIORITY ,APPLY_SHIFT ,APPLY_START_TIME ,APPLY_END_TIME ,AREA_ID ,SUB_AREA\
_ID ,RESG_ID ,MAT_ID ,FLOW ,RCV_USER_ID ,SEC_GRP_ID ,PRV_GRP_ID ,MODAL_FLAG ,\
AUTO_CLOSE_FLAG ,AUTO_CLOSE_TIME ,ACK_FLAG ,ACK_TIME ,ACK_USER_ID ,RCV_FACTOR\
Y into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,\
:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b\
31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46\
,:b47,:b48,:b49  from MMSGBBSHIS where (((FACTORY=:b0 and MAIN_MENU_ID=:b1) a\
nd SUB_MENU_ID=:b2) and BBS_SEQ=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MMSGBBSHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MMSGBBSHIS_N.MAIN_MENU_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MMSGBBSHIS_N.SUB_MENU_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MMSGBBSHIS_N.BBS_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MMSGBBSHIS_N.TRAN_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MMSGBBSHIS_N.LOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MMSGBBSHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MMSGBBSHIS_N.OPER);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MMSGBBSHIS_N.RES_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MMSGBBSHIS_N.SUBRES_ID);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MMSGBBSHIS_N.MSG_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MMSGBBSHIS_N.MSG_TITLE);
            sqlstm.sqhstl[11] = (unsigned int  )201;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MMSGBBSHIS_N.MSG_TAG);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_1);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_2);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_3);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_4);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_5);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_6);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_7);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_8);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_9);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_10);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MMSGBBSHIS_N.REPLY_COUNT);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MMSGBBSHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MMSGBBSHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MMSGBBSHIS_N.CREATE_TIME);
            sqlstm.sqhstl[26] = (unsigned int  )15;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MMSGBBSHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MMSGBBSHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[28] = (unsigned int  )15;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MMSGBBSHIS_N.SYS_MSG_FLAG);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MMSGBBSHIS_N.POPUP_CYCLE);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MMSGBBSHIS_N.PRIORITY);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MMSGBBSHIS_N.APPLY_SHIFT);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MMSGBBSHIS_N.APPLY_START_TIME);
            sqlstm.sqhstl[33] = (unsigned int  )15;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MMSGBBSHIS_N.APPLY_END_TIME);
            sqlstm.sqhstl[34] = (unsigned int  )15;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MMSGBBSHIS_N.AREA_ID);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MMSGBBSHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MMSGBBSHIS_N.RESG_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MMSGBBSHIS_N.MAT_ID);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MMSGBBSHIS_N.FLOW);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MMSGBBSHIS_N.RCV_USER_ID);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MMSGBBSHIS_N.SEC_GRP_ID);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MMSGBBSHIS_N.PRV_GRP_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MMSGBBSHIS_N.MODAL_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MMSGBBSHIS_N.AUTO_CLOSE_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(MMSGBBSHIS_N.AUTO_CLOSE_TIME);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MMSGBBSHIS_N.ACK_FLAG);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MMSGBBSHIS_N.ACK_TIME);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MMSGBBSHIS_N.ACK_USER_ID);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MMSGBBSHIS_N.RCV_FACTORY);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MMSGBBSHIS_N.FACTORY);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MMSGBBSHIS_N.MAIN_MENU_ID);
            sqlstm.sqhstl[51] = (unsigned int  )21;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MMSGBBSHIS_N.SUB_MENU_ID);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MMSGBBSHIS_N.BBS_SEQ);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
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
        DBC_del_null_mmsgbbshis(&MMSGBBSHIS_N, MMSGBBSHIS);
    }
    DB_stop_query_timer("DBC_select_mmsgbbshis", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mmsgbbshis_for_update(int sel_type, struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MMSGBBSHIS_N_TAG MMSGBBSHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mmsgbbshis(&MMSGBBSHIS_N, MMSGBBSHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         MAIN_MENU_ID,
                         SUB_MENU_ID,
                         BBS_SEQ,
                         TRAN_TIME,
                         LOT_ID,
                         SUBLOT_ID,
                         OPER,
                         RES_ID,
                         SUBRES_ID,
                         MSG_TYPE,
                         MSG_TITLE,
                         MSG_TAG,
                         BBS_CMF_1,
                         BBS_CMF_2,
                         BBS_CMF_3,
                         BBS_CMF_4,
                         BBS_CMF_5,
                         BBS_CMF_6,
                         BBS_CMF_7,
                         BBS_CMF_8,
                         BBS_CMF_9,
                         BBS_CMF_10,
                         REPLY_COUNT,
                         DELETE_FLAG,
                         CREATE_USER_ID,
                         CREATE_TIME,
                         UPDATE_USER_ID,
                         UPDATE_TIME,
                         SYS_MSG_FLAG,
                         POPUP_CYCLE,
                         PRIORITY,
                         APPLY_SHIFT,
                         APPLY_START_TIME,
                         APPLY_END_TIME,
                         AREA_ID,
                         SUB_AREA_ID,
                         RESG_ID,
                         MAT_ID,
                         FLOW,
                         RCV_USER_ID,
                         SEC_GRP_ID,
                         PRV_GRP_ID,
                         MODAL_FLAG,
                         AUTO_CLOSE_FLAG,
                         AUTO_CLOSE_TIME,
                         ACK_FLAG,
                         ACK_TIME,
                         ACK_USER_ID,
                         RCV_FACTORY
                INTO 
                    :MMSGBBSHIS_N.FACTORY,
                    :MMSGBBSHIS_N.MAIN_MENU_ID,
                    :MMSGBBSHIS_N.SUB_MENU_ID,
                    :MMSGBBSHIS_N.BBS_SEQ,
                    :MMSGBBSHIS_N.TRAN_TIME,
                    :MMSGBBSHIS_N.LOT_ID,
                    :MMSGBBSHIS_N.SUBLOT_ID,
                    :MMSGBBSHIS_N.OPER,
                    :MMSGBBSHIS_N.RES_ID,
                    :MMSGBBSHIS_N.SUBRES_ID,
                    :MMSGBBSHIS_N.MSG_TYPE,
                    :MMSGBBSHIS_N.MSG_TITLE,
                    :MMSGBBSHIS_N.MSG_TAG,
                    :MMSGBBSHIS_N.BBS_CMF_1,
                    :MMSGBBSHIS_N.BBS_CMF_2,
                    :MMSGBBSHIS_N.BBS_CMF_3,
                    :MMSGBBSHIS_N.BBS_CMF_4,
                    :MMSGBBSHIS_N.BBS_CMF_5,
                    :MMSGBBSHIS_N.BBS_CMF_6,
                    :MMSGBBSHIS_N.BBS_CMF_7,
                    :MMSGBBSHIS_N.BBS_CMF_8,
                    :MMSGBBSHIS_N.BBS_CMF_9,
                    :MMSGBBSHIS_N.BBS_CMF_10,
                    :MMSGBBSHIS_N.REPLY_COUNT,
                    :MMSGBBSHIS_N.DELETE_FLAG,
                    :MMSGBBSHIS_N.CREATE_USER_ID,
                    :MMSGBBSHIS_N.CREATE_TIME,
                    :MMSGBBSHIS_N.UPDATE_USER_ID,
                    :MMSGBBSHIS_N.UPDATE_TIME,
                    :MMSGBBSHIS_N.SYS_MSG_FLAG,
                    :MMSGBBSHIS_N.POPUP_CYCLE,
                    :MMSGBBSHIS_N.PRIORITY,
                    :MMSGBBSHIS_N.APPLY_SHIFT,
                    :MMSGBBSHIS_N.APPLY_START_TIME,
                    :MMSGBBSHIS_N.APPLY_END_TIME,
                    :MMSGBBSHIS_N.AREA_ID,
                    :MMSGBBSHIS_N.SUB_AREA_ID,
                    :MMSGBBSHIS_N.RESG_ID,
                    :MMSGBBSHIS_N.MAT_ID,
                    :MMSGBBSHIS_N.FLOW,
                    :MMSGBBSHIS_N.RCV_USER_ID,
                    :MMSGBBSHIS_N.SEC_GRP_ID,
                    :MMSGBBSHIS_N.PRV_GRP_ID,
                    :MMSGBBSHIS_N.MODAL_FLAG,
                    :MMSGBBSHIS_N.AUTO_CLOSE_FLAG,
                    :MMSGBBSHIS_N.AUTO_CLOSE_TIME,
                    :MMSGBBSHIS_N.ACK_FLAG,
                    :MMSGBBSHIS_N.ACK_TIME,
                    :MMSGBBSHIS_N.ACK_USER_ID,
                    :MMSGBBSHIS_N.RCV_FACTORY
                FROM MMSGBBSHIS
                WHERE FACTORY = :MMSGBBSHIS_N.FACTORY
                    AND MAIN_MENU_ID = :MMSGBBSHIS_N.MAIN_MENU_ID
                    AND SUB_MENU_ID = :MMSGBBSHIS_N.SUB_MENU_ID
                    AND BBS_SEQ = :MMSGBBSHIS_N.BBS_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,MAIN_MENU_ID ,SUB_MENU_ID ,BBS_S\
EQ ,TRAN_TIME ,LOT_ID ,SUBLOT_ID ,OPER ,RES_ID ,SUBRES_ID ,MSG_TYPE ,MSG_TITL\
E ,MSG_TAG ,BBS_CMF_1 ,BBS_CMF_2 ,BBS_CMF_3 ,BBS_CMF_4 ,BBS_CMF_5 ,BBS_CMF_6 \
,BBS_CMF_7 ,BBS_CMF_8 ,BBS_CMF_9 ,BBS_CMF_10 ,REPLY_COUNT ,DELETE_FLAG ,CREAT\
E_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,SYS_MSG_FLAG ,POPUP_CYCL\
E ,PRIORITY ,APPLY_SHIFT ,APPLY_START_TIME ,APPLY_END_TIME ,AREA_ID ,SUB_AREA\
_ID ,RESG_ID ,MAT_ID ,FLOW ,RCV_USER_ID ,SEC_GRP_ID ,PRV_GRP_ID ,MODAL_FLAG ,\
AUTO_CLOSE_FLAG ,AUTO_CLOSE_TIME ,ACK_FLAG ,ACK_TIME ,ACK_USER_ID ,RCV_FACTOR\
Y into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,\
:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b\
31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46\
,:b47,:b48,:b49  from MMSGBBSHIS where (((FACTORY=:b0 and MAIN_MENU_ID=:b1) a\
nd SUB_MENU_ID=:b2) and BBS_SEQ=:b3) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )236;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MMSGBBSHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MMSGBBSHIS_N.MAIN_MENU_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MMSGBBSHIS_N.SUB_MENU_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MMSGBBSHIS_N.BBS_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MMSGBBSHIS_N.TRAN_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MMSGBBSHIS_N.LOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MMSGBBSHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MMSGBBSHIS_N.OPER);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MMSGBBSHIS_N.RES_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MMSGBBSHIS_N.SUBRES_ID);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MMSGBBSHIS_N.MSG_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MMSGBBSHIS_N.MSG_TITLE);
            sqlstm.sqhstl[11] = (unsigned int  )201;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MMSGBBSHIS_N.MSG_TAG);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_1);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_2);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_3);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_4);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_5);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_6);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_7);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_8);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_9);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_10);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MMSGBBSHIS_N.REPLY_COUNT);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MMSGBBSHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MMSGBBSHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MMSGBBSHIS_N.CREATE_TIME);
            sqlstm.sqhstl[26] = (unsigned int  )15;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MMSGBBSHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MMSGBBSHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[28] = (unsigned int  )15;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MMSGBBSHIS_N.SYS_MSG_FLAG);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MMSGBBSHIS_N.POPUP_CYCLE);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MMSGBBSHIS_N.PRIORITY);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MMSGBBSHIS_N.APPLY_SHIFT);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MMSGBBSHIS_N.APPLY_START_TIME);
            sqlstm.sqhstl[33] = (unsigned int  )15;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MMSGBBSHIS_N.APPLY_END_TIME);
            sqlstm.sqhstl[34] = (unsigned int  )15;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MMSGBBSHIS_N.AREA_ID);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MMSGBBSHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MMSGBBSHIS_N.RESG_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MMSGBBSHIS_N.MAT_ID);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MMSGBBSHIS_N.FLOW);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MMSGBBSHIS_N.RCV_USER_ID);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MMSGBBSHIS_N.SEC_GRP_ID);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MMSGBBSHIS_N.PRV_GRP_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MMSGBBSHIS_N.MODAL_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MMSGBBSHIS_N.AUTO_CLOSE_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(MMSGBBSHIS_N.AUTO_CLOSE_TIME);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MMSGBBSHIS_N.ACK_FLAG);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MMSGBBSHIS_N.ACK_TIME);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MMSGBBSHIS_N.ACK_USER_ID);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MMSGBBSHIS_N.RCV_FACTORY);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MMSGBBSHIS_N.FACTORY);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MMSGBBSHIS_N.MAIN_MENU_ID);
            sqlstm.sqhstl[51] = (unsigned int  )21;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MMSGBBSHIS_N.SUB_MENU_ID);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MMSGBBSHIS_N.BBS_SEQ);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
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
        DBC_del_null_mmsgbbshis(&MMSGBBSHIS_N, MMSGBBSHIS);
    }
    DB_stop_query_timer("DBC_select_mmsgbbshis_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mmsgbbshis_scalar(int sel_type, struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MMSGBBSHIS_N_TAG MMSGBBSHIS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
  
    DBC_add_null_mmsgbbshis(&MMSGBBSHIS_N, MMSGBBSHIS);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MMSGBBSHIS
                WHERE FACTORY = :MMSGBBSHIS_N.FACTORY
                    AND MAIN_MENU_ID = :MMSGBBSHIS_N.MAIN_MENU_ID
                    AND SUB_MENU_ID = :MMSGBBSHIS_N.SUB_MENU_ID
                    AND BBS_SEQ = :MMSGBBSHIS_N.BBS_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MMSGBBSHIS where\
 (((FACTORY=:b1 and MAIN_MENU_ID=:b2) and SUB_MENU_ID=:b3) and BBS_SEQ=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )467;
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
            sqlstm.sqhstv[1] = (         void  *)(MMSGBBSHIS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MMSGBBSHIS_N.MAIN_MENU_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MMSGBBSHIS_N.SUB_MENU_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MMSGBBSHIS_N.BBS_SEQ);
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBC_select_mmsgbbshis_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mmsgbbshis(int sel_type, struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MMSGBBSHIS_N_TAG MMSGBBSHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mmsgbbshis(&MMSGBBSHIS_N, MMSGBBSHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MMSGBBSHIS
                WHERE FACTORY = :MMSGBBSHIS_N.FACTORY
                    AND MAIN_MENU_ID = :MMSGBBSHIS_N.MAIN_MENU_ID
                    AND SUB_MENU_ID = :MMSGBBSHIS_N.SUB_MENU_ID
                    AND BBS_SEQ = :MMSGBBSHIS_N.BBS_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MMSGBBSHIS  where (((FACTORY=:b0 an\
d MAIN_MENU_ID=:b1) and SUB_MENU_ID=:b2) and BBS_SEQ=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )502;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MMSGBBSHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MMSGBBSHIS_N.MAIN_MENU_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MMSGBBSHIS_N.SUB_MENU_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MMSGBBSHIS_N.BBS_SEQ);
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
    DB_stop_query_timer("DBC_delete_mmsgbbshis", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mmsgbbshis(struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MMSGBBSHIS_N_TAG MMSGBBSHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mmsgbbshis(&MMSGBBSHIS_N, MMSGBBSHIS);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MMSGBBSHIS (
                    FACTORY,
                    MAIN_MENU_ID,
                    SUB_MENU_ID,
                    BBS_SEQ,
                    TRAN_TIME,
                    LOT_ID,
                    SUBLOT_ID,
                    OPER,
                    RES_ID,
                    SUBRES_ID,
                    MSG_TYPE,
                    MSG_TITLE,
                    MSG_TAG,
                    BBS_CMF_1,
                    BBS_CMF_2,
                    BBS_CMF_3,
                    BBS_CMF_4,
                    BBS_CMF_5,
                    BBS_CMF_6,
                    BBS_CMF_7,
                    BBS_CMF_8,
                    BBS_CMF_9,
                    BBS_CMF_10,
                    REPLY_COUNT,
                    DELETE_FLAG,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    SYS_MSG_FLAG,
                    POPUP_CYCLE,
                    PRIORITY,
                    APPLY_SHIFT,
                    APPLY_START_TIME,
                    APPLY_END_TIME,
                    AREA_ID,
                    SUB_AREA_ID,
                    RESG_ID,
                    MAT_ID,
                    FLOW,
                    RCV_USER_ID,
                    SEC_GRP_ID,
                    PRV_GRP_ID,
                    MODAL_FLAG,
                    AUTO_CLOSE_FLAG,
                    AUTO_CLOSE_TIME,
                    ACK_FLAG,
                    ACK_TIME,
                    ACK_USER_ID,
                    RCV_FACTORY
        )
        VALUES (
                    :MMSGBBSHIS_N.FACTORY,
                    :MMSGBBSHIS_N.MAIN_MENU_ID,
                    :MMSGBBSHIS_N.SUB_MENU_ID,
                    :MMSGBBSHIS_N.BBS_SEQ,
                    :MMSGBBSHIS_N.TRAN_TIME,
                    :MMSGBBSHIS_N.LOT_ID,
                    :MMSGBBSHIS_N.SUBLOT_ID,
                    :MMSGBBSHIS_N.OPER,
                    :MMSGBBSHIS_N.RES_ID,
                    :MMSGBBSHIS_N.SUBRES_ID,
                    :MMSGBBSHIS_N.MSG_TYPE,
                    :MMSGBBSHIS_N.MSG_TITLE,
                    :MMSGBBSHIS_N.MSG_TAG,
                    :MMSGBBSHIS_N.BBS_CMF_1,
                    :MMSGBBSHIS_N.BBS_CMF_2,
                    :MMSGBBSHIS_N.BBS_CMF_3,
                    :MMSGBBSHIS_N.BBS_CMF_4,
                    :MMSGBBSHIS_N.BBS_CMF_5,
                    :MMSGBBSHIS_N.BBS_CMF_6,
                    :MMSGBBSHIS_N.BBS_CMF_7,
                    :MMSGBBSHIS_N.BBS_CMF_8,
                    :MMSGBBSHIS_N.BBS_CMF_9,
                    :MMSGBBSHIS_N.BBS_CMF_10,
                    :MMSGBBSHIS_N.REPLY_COUNT,
                    :MMSGBBSHIS_N.DELETE_FLAG,
                    :MMSGBBSHIS_N.CREATE_USER_ID,
                    :MMSGBBSHIS_N.CREATE_TIME,
                    :MMSGBBSHIS_N.UPDATE_USER_ID,
                    :MMSGBBSHIS_N.UPDATE_TIME,
                    :MMSGBBSHIS_N.SYS_MSG_FLAG,
                    :MMSGBBSHIS_N.POPUP_CYCLE,
                    :MMSGBBSHIS_N.PRIORITY,
                    :MMSGBBSHIS_N.APPLY_SHIFT,
                    :MMSGBBSHIS_N.APPLY_START_TIME,
                    :MMSGBBSHIS_N.APPLY_END_TIME,
                    :MMSGBBSHIS_N.AREA_ID,
                    :MMSGBBSHIS_N.SUB_AREA_ID,
                    :MMSGBBSHIS_N.RESG_ID,
                    :MMSGBBSHIS_N.MAT_ID,
                    :MMSGBBSHIS_N.FLOW,
                    :MMSGBBSHIS_N.RCV_USER_ID,
                    :MMSGBBSHIS_N.SEC_GRP_ID,
                    :MMSGBBSHIS_N.PRV_GRP_ID,
                    :MMSGBBSHIS_N.MODAL_FLAG,
                    :MMSGBBSHIS_N.AUTO_CLOSE_FLAG,
                    :MMSGBBSHIS_N.AUTO_CLOSE_TIME,
                    :MMSGBBSHIS_N.ACK_FLAG,
                    :MMSGBBSHIS_N.ACK_TIME,
                    :MMSGBBSHIS_N.ACK_USER_ID,
                    :MMSGBBSHIS_N.RCV_FACTORY
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 54;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into MMSGBBSHIS (FACTORY,MAIN_MENU_ID,SUB_MENU_ID\
,BBS_SEQ,TRAN_TIME,LOT_ID,SUBLOT_ID,OPER,RES_ID,SUBRES_ID,MSG_TYPE,MSG_TITLE,\
MSG_TAG,BBS_CMF_1,BBS_CMF_2,BBS_CMF_3,BBS_CMF_4,BBS_CMF_5,BBS_CMF_6,BBS_CMF_7\
,BBS_CMF_8,BBS_CMF_9,BBS_CMF_10,REPLY_COUNT,DELETE_FLAG,CREATE_USER_ID,CREATE\
_TIME,UPDATE_USER_ID,UPDATE_TIME,SYS_MSG_FLAG,POPUP_CYCLE,PRIORITY,APPLY_SHIF\
T,APPLY_START_TIME,APPLY_END_TIME,AREA_ID,SUB_AREA_ID,RESG_ID,MAT_ID,FLOW,RCV\
_USER_ID,SEC_GRP_ID,PRV_GRP_ID,MODAL_FLAG,AUTO_CLOSE_FLAG,AUTO_CLOSE_TIME,ACK\
_FLAG,ACK_TIME,ACK_USER_ID,RCV_FACTORY) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:\
b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:\
b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b3\
8,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )533;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MMSGBBSHIS_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MMSGBBSHIS_N.MAIN_MENU_ID);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MMSGBBSHIS_N.SUB_MENU_ID);
    sqlstm.sqhstl[2] = (unsigned int  )21;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)&(MMSGBBSHIS_N.BBS_SEQ);
    sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MMSGBBSHIS_N.TRAN_TIME);
    sqlstm.sqhstl[4] = (unsigned int  )15;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MMSGBBSHIS_N.LOT_ID);
    sqlstm.sqhstl[5] = (unsigned int  )26;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MMSGBBSHIS_N.SUBLOT_ID);
    sqlstm.sqhstl[6] = (unsigned int  )31;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MMSGBBSHIS_N.OPER);
    sqlstm.sqhstl[7] = (unsigned int  )11;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MMSGBBSHIS_N.RES_ID);
    sqlstm.sqhstl[8] = (unsigned int  )21;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MMSGBBSHIS_N.SUBRES_ID);
    sqlstm.sqhstl[9] = (unsigned int  )21;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MMSGBBSHIS_N.MSG_TYPE);
    sqlstm.sqhstl[10] = (unsigned int  )11;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MMSGBBSHIS_N.MSG_TITLE);
    sqlstm.sqhstl[11] = (unsigned int  )201;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MMSGBBSHIS_N.MSG_TAG);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_1);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_2);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_3);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_4);
    sqlstm.sqhstl[16] = (unsigned int  )31;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_5);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_6);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_7);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_8);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_9);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_10);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)&(MMSGBBSHIS_N.REPLY_COUNT);
    sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MMSGBBSHIS_N.DELETE_FLAG);
    sqlstm.sqhstl[24] = (unsigned int  )2;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MMSGBBSHIS_N.CREATE_USER_ID);
    sqlstm.sqhstl[25] = (unsigned int  )21;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MMSGBBSHIS_N.CREATE_TIME);
    sqlstm.sqhstl[26] = (unsigned int  )15;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MMSGBBSHIS_N.UPDATE_USER_ID);
    sqlstm.sqhstl[27] = (unsigned int  )21;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MMSGBBSHIS_N.UPDATE_TIME);
    sqlstm.sqhstl[28] = (unsigned int  )15;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MMSGBBSHIS_N.SYS_MSG_FLAG);
    sqlstm.sqhstl[29] = (unsigned int  )2;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MMSGBBSHIS_N.POPUP_CYCLE);
    sqlstm.sqhstl[30] = (unsigned int  )2;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MMSGBBSHIS_N.PRIORITY);
    sqlstm.sqhstl[31] = (unsigned int  )2;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MMSGBBSHIS_N.APPLY_SHIFT);
    sqlstm.sqhstl[32] = (unsigned int  )2;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MMSGBBSHIS_N.APPLY_START_TIME);
    sqlstm.sqhstl[33] = (unsigned int  )15;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MMSGBBSHIS_N.APPLY_END_TIME);
    sqlstm.sqhstl[34] = (unsigned int  )15;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MMSGBBSHIS_N.AREA_ID);
    sqlstm.sqhstl[35] = (unsigned int  )21;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MMSGBBSHIS_N.SUB_AREA_ID);
    sqlstm.sqhstl[36] = (unsigned int  )21;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MMSGBBSHIS_N.RESG_ID);
    sqlstm.sqhstl[37] = (unsigned int  )21;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MMSGBBSHIS_N.MAT_ID);
    sqlstm.sqhstl[38] = (unsigned int  )31;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MMSGBBSHIS_N.FLOW);
    sqlstm.sqhstl[39] = (unsigned int  )21;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MMSGBBSHIS_N.RCV_USER_ID);
    sqlstm.sqhstl[40] = (unsigned int  )21;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MMSGBBSHIS_N.SEC_GRP_ID);
    sqlstm.sqhstl[41] = (unsigned int  )21;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MMSGBBSHIS_N.PRV_GRP_ID);
    sqlstm.sqhstl[42] = (unsigned int  )21;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MMSGBBSHIS_N.MODAL_FLAG);
    sqlstm.sqhstl[43] = (unsigned int  )2;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MMSGBBSHIS_N.AUTO_CLOSE_FLAG);
    sqlstm.sqhstl[44] = (unsigned int  )2;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)&(MMSGBBSHIS_N.AUTO_CLOSE_TIME);
    sqlstm.sqhstl[45] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MMSGBBSHIS_N.ACK_FLAG);
    sqlstm.sqhstl[46] = (unsigned int  )2;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MMSGBBSHIS_N.ACK_TIME);
    sqlstm.sqhstl[47] = (unsigned int  )21;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MMSGBBSHIS_N.ACK_USER_ID);
    sqlstm.sqhstl[48] = (unsigned int  )21;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MMSGBBSHIS_N.RCV_FACTORY);
    sqlstm.sqhstl[49] = (unsigned int  )11;
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


    DB_stop_query_timer("DBC_insert_mmsgbbshis", 0);
}


/* SQL UPDATE Function */
void DBC_update_mmsgbbshis(int sel_type, struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MMSGBBSHIS_N_TAG MMSGBBSHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mmsgbbshis(&MMSGBBSHIS_N, MMSGBBSHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MMSGBBSHIS SET
                    TRAN_TIME = :MMSGBBSHIS_N.TRAN_TIME,
                    LOT_ID = :MMSGBBSHIS_N.LOT_ID,
                    SUBLOT_ID = :MMSGBBSHIS_N.SUBLOT_ID,
                    OPER = :MMSGBBSHIS_N.OPER,
                    RES_ID = :MMSGBBSHIS_N.RES_ID,
                    SUBRES_ID = :MMSGBBSHIS_N.SUBRES_ID,
                    MSG_TYPE = :MMSGBBSHIS_N.MSG_TYPE,
                    MSG_TITLE = :MMSGBBSHIS_N.MSG_TITLE,
                    MSG_TAG = :MMSGBBSHIS_N.MSG_TAG,
                    BBS_CMF_1 = :MMSGBBSHIS_N.BBS_CMF_1,
                    BBS_CMF_2 = :MMSGBBSHIS_N.BBS_CMF_2,
                    BBS_CMF_3 = :MMSGBBSHIS_N.BBS_CMF_3,
                    BBS_CMF_4 = :MMSGBBSHIS_N.BBS_CMF_4,
                    BBS_CMF_5 = :MMSGBBSHIS_N.BBS_CMF_5,
                    BBS_CMF_6 = :MMSGBBSHIS_N.BBS_CMF_6,
                    BBS_CMF_7 = :MMSGBBSHIS_N.BBS_CMF_7,
                    BBS_CMF_8 = :MMSGBBSHIS_N.BBS_CMF_8,
                    BBS_CMF_9 = :MMSGBBSHIS_N.BBS_CMF_9,
                    BBS_CMF_10 = :MMSGBBSHIS_N.BBS_CMF_10,
                    REPLY_COUNT = :MMSGBBSHIS_N.REPLY_COUNT,
                    DELETE_FLAG = :MMSGBBSHIS_N.DELETE_FLAG,
                    CREATE_USER_ID = :MMSGBBSHIS_N.CREATE_USER_ID,
                    CREATE_TIME = :MMSGBBSHIS_N.CREATE_TIME,
                    UPDATE_USER_ID = :MMSGBBSHIS_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MMSGBBSHIS_N.UPDATE_TIME,
                    SYS_MSG_FLAG = :MMSGBBSHIS_N.SYS_MSG_FLAG,
                    POPUP_CYCLE = :MMSGBBSHIS_N.POPUP_CYCLE,
                    PRIORITY = :MMSGBBSHIS_N.PRIORITY,
                    APPLY_SHIFT = :MMSGBBSHIS_N.APPLY_SHIFT,
                    APPLY_START_TIME = :MMSGBBSHIS_N.APPLY_START_TIME,
                    APPLY_END_TIME = :MMSGBBSHIS_N.APPLY_END_TIME,
                    AREA_ID = :MMSGBBSHIS_N.AREA_ID,
                    SUB_AREA_ID = :MMSGBBSHIS_N.SUB_AREA_ID,
                    RESG_ID = :MMSGBBSHIS_N.RESG_ID,
                    MAT_ID = :MMSGBBSHIS_N.MAT_ID,
                    FLOW = :MMSGBBSHIS_N.FLOW,
                    RCV_USER_ID = :MMSGBBSHIS_N.RCV_USER_ID,
                    SEC_GRP_ID = :MMSGBBSHIS_N.SEC_GRP_ID,
                    PRV_GRP_ID = :MMSGBBSHIS_N.PRV_GRP_ID,
                    MODAL_FLAG = :MMSGBBSHIS_N.MODAL_FLAG,
                    AUTO_CLOSE_FLAG = :MMSGBBSHIS_N.AUTO_CLOSE_FLAG,
                    AUTO_CLOSE_TIME = :MMSGBBSHIS_N.AUTO_CLOSE_TIME,
                    ACK_FLAG = :MMSGBBSHIS_N.ACK_FLAG,
                    ACK_TIME = :MMSGBBSHIS_N.ACK_TIME,
                    ACK_USER_ID = :MMSGBBSHIS_N.ACK_USER_ID,
                    RCV_FACTORY = :MMSGBBSHIS_N.RCV_FACTORY
                WHERE FACTORY = :MMSGBBSHIS_N.FACTORY
                    AND MAIN_MENU_ID = :MMSGBBSHIS_N.MAIN_MENU_ID
                    AND SUB_MENU_ID = :MMSGBBSHIS_N.SUB_MENU_ID
                    AND BBS_SEQ = :MMSGBBSHIS_N.BBS_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MMSGBBSHIS  set TRAN_TIME=:b0,LOT_ID=:b1,\
SUBLOT_ID=:b2,OPER=:b3,RES_ID=:b4,SUBRES_ID=:b5,MSG_TYPE=:b6,MSG_TITLE=:b7,MS\
G_TAG=:b8,BBS_CMF_1=:b9,BBS_CMF_2=:b10,BBS_CMF_3=:b11,BBS_CMF_4=:b12,BBS_CMF_\
5=:b13,BBS_CMF_6=:b14,BBS_CMF_7=:b15,BBS_CMF_8=:b16,BBS_CMF_9=:b17,BBS_CMF_10\
=:b18,REPLY_COUNT=:b19,DELETE_FLAG=:b20,CREATE_USER_ID=:b21,CREATE_TIME=:b22,\
UPDATE_USER_ID=:b23,UPDATE_TIME=:b24,SYS_MSG_FLAG=:b25,POPUP_CYCLE=:b26,PRIOR\
ITY=:b27,APPLY_SHIFT=:b28,APPLY_START_TIME=:b29,APPLY_END_TIME=:b30,AREA_ID=:\
b31,SUB_AREA_ID=:b32,RESG_ID=:b33,MAT_ID=:b34,FLOW=:b35,RCV_USER_ID=:b36,SEC_\
GRP_ID=:b37,PRV_GRP_ID=:b38,MODAL_FLAG=:b39,AUTO_CLOSE_FLAG=:b40,AUTO_CLOSE_T\
IME=:b41,ACK_FLAG=:b42,ACK_TIME=:b43,ACK_USER_ID=:b44,RCV_FACTORY=:b45 where \
(((FACTORY=:b46 and MAIN_MENU_ID=:b47) and SUB_MENU_ID=:b48) and BBS_SEQ=:b49\
)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )748;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MMSGBBSHIS_N.TRAN_TIME);
            sqlstm.sqhstl[0] = (unsigned int  )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MMSGBBSHIS_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MMSGBBSHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MMSGBBSHIS_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MMSGBBSHIS_N.RES_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MMSGBBSHIS_N.SUBRES_ID);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MMSGBBSHIS_N.MSG_TYPE);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MMSGBBSHIS_N.MSG_TITLE);
            sqlstm.sqhstl[7] = (unsigned int  )201;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MMSGBBSHIS_N.MSG_TAG);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_1);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_2);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_3);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_4);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_5);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_6);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_7);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_8);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_9);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_10);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MMSGBBSHIS_N.REPLY_COUNT);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MMSGBBSHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[20] = (unsigned int  )2;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MMSGBBSHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MMSGBBSHIS_N.CREATE_TIME);
            sqlstm.sqhstl[22] = (unsigned int  )15;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MMSGBBSHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MMSGBBSHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[24] = (unsigned int  )15;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MMSGBBSHIS_N.SYS_MSG_FLAG);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MMSGBBSHIS_N.POPUP_CYCLE);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MMSGBBSHIS_N.PRIORITY);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MMSGBBSHIS_N.APPLY_SHIFT);
            sqlstm.sqhstl[28] = (unsigned int  )2;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MMSGBBSHIS_N.APPLY_START_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MMSGBBSHIS_N.APPLY_END_TIME);
            sqlstm.sqhstl[30] = (unsigned int  )15;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MMSGBBSHIS_N.AREA_ID);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MMSGBBSHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MMSGBBSHIS_N.RESG_ID);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MMSGBBSHIS_N.MAT_ID);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MMSGBBSHIS_N.FLOW);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MMSGBBSHIS_N.RCV_USER_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MMSGBBSHIS_N.SEC_GRP_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MMSGBBSHIS_N.PRV_GRP_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MMSGBBSHIS_N.MODAL_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MMSGBBSHIS_N.AUTO_CLOSE_FLAG);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(MMSGBBSHIS_N.AUTO_CLOSE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MMSGBBSHIS_N.ACK_FLAG);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MMSGBBSHIS_N.ACK_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )21;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MMSGBBSHIS_N.ACK_USER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MMSGBBSHIS_N.RCV_FACTORY);
            sqlstm.sqhstl[45] = (unsigned int  )11;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MMSGBBSHIS_N.FACTORY);
            sqlstm.sqhstl[46] = (unsigned int  )11;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MMSGBBSHIS_N.MAIN_MENU_ID);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MMSGBBSHIS_N.SUB_MENU_ID);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MMSGBBSHIS_N.BBS_SEQ);
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
    DB_stop_query_timer("DBC_update_mmsgbbshis", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mmsgbbshis(int sel_type, struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MMSGBBSHIS_N_TAG MMSGBBSHIS_N;
        char sql[5120];
        char ts1[201];
        char ts2[201];
        char ts3[201];
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    

    DBC_add_null_mmsgbbshis(&MMSGBBSHIS_N, MMSGBBSHIS);
    DB_error_code = 0;

    memset( ts1, 0x00, sizeof(ts1));
    memset( ts2, 0x00, sizeof(ts2));
    memset(ts3, 0x00, sizeof(ts3));
    switch(sel_type)
    {
        case 1:
            DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);

            memset( sql, 0x00, sizeof(sql));
            sprintf(sql,               "SELECT ");
            sprintf(sql + strlen(sql),   "SEQ, ");
            sprintf(sql + strlen(sql),   "FACTORY, ");
            sprintf(sql + strlen(sql),   "MAIN_MENU_ID, ");
            sprintf(sql + strlen(sql),   "SUB_MENU_ID, ");
            sprintf(sql + strlen(sql),   "BBS_SEQ, ");
            sprintf(sql + strlen(sql),   "TRAN_TIME, ");
            sprintf(sql + strlen(sql),   "LOT_ID, ");
            sprintf(sql + strlen(sql),   "SUBLOT_ID, ");
            sprintf(sql + strlen(sql),   "OPER, ");
            sprintf(sql + strlen(sql),   "RES_ID, ");
            sprintf(sql + strlen(sql),   "SUBRES_ID, ");
            sprintf(sql + strlen(sql),   "MSG_TYPE, ");
            sprintf(sql + strlen(sql),   "MSG_TITLE, ");
            sprintf(sql + strlen(sql),   "MSG_TAG, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_1, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_2, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_3, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_4, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_5, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_6, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_7, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_8, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_9, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_10, ");
            sprintf(sql + strlen(sql),   "REPLY_COUNT, ");
            sprintf(sql + strlen(sql),   "DELETE_FLAG, ");
            sprintf(sql + strlen(sql),   "CREATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "UPDATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "UPDATE_TIME, ");
            sprintf(sql + strlen(sql),   "SYS_MSG_FLAG, ");
            sprintf(sql + strlen(sql),   "POPUP_CYCLE, ");
            sprintf(sql + strlen(sql),   "PRIORITY, ");
            sprintf(sql + strlen(sql),   "APPLY_SHIFT, ");
            sprintf(sql + strlen(sql),   "APPLY_START_TIME, ");
            sprintf(sql + strlen(sql),   "APPLY_END_TIME, ");
            sprintf(sql + strlen(sql),   "AREA_ID, ");
            sprintf(sql + strlen(sql),   "SUB_AREA_ID, ");
            sprintf(sql + strlen(sql),   "RESG_ID, ");
            sprintf(sql + strlen(sql),   "MAT_ID, ");
            sprintf(sql + strlen(sql),   "FLOW, ");
            sprintf(sql + strlen(sql),   "RCV_USER_ID, ");
            sprintf(sql + strlen(sql),   "SEC_GRP_ID, ");
            sprintf(sql + strlen(sql),   "PRV_GRP_ID, ");
            sprintf(sql + strlen(sql),   "MODAL_FLAG, ");
            sprintf(sql + strlen(sql),   "AUTO_CLOSE_FLAG, ");
            sprintf(sql + strlen(sql),   "AUTO_CLOSE_TIME, ");
            sprintf(sql + strlen(sql),   "ACK_FLAG, ");
            sprintf(sql + strlen(sql),   "ACK_TIME, ");
            sprintf(sql + strlen(sql),   "ACK_USER_ID, ");
            sprintf(sql + strlen(sql),   "RCV_FACTORY ");
            sprintf(sql + strlen(sql), "FROM (SELECT ROWNUM AS SEQ, ");
            sprintf(sql + strlen(sql),   "A.FACTORY, ");
            sprintf(sql + strlen(sql),   "A.MAIN_MENU_ID, ");
            sprintf(sql + strlen(sql),   "A.SUB_MENU_ID, ");
            sprintf(sql + strlen(sql),   "A.BBS_SEQ, ");
            sprintf(sql + strlen(sql),   "A.TRAN_TIME, ");
            sprintf(sql + strlen(sql),   "A.LOT_ID, ");
            sprintf(sql + strlen(sql),   "A.SUBLOT_ID, ");
            sprintf(sql + strlen(sql),   "A.OPER, ");
            sprintf(sql + strlen(sql),   "A.RES_ID, ");
            sprintf(sql + strlen(sql),   "A.SUBRES_ID, ");
            sprintf(sql + strlen(sql),   "A.MSG_TYPE, ");
            sprintf(sql + strlen(sql),   "A.MSG_TITLE, ");
            sprintf(sql + strlen(sql),   "A.MSG_TAG, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_1, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_2, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_3, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_4, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_5, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_6, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_7, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_8, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_9, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_10, ");
            sprintf(sql + strlen(sql),   "A.REPLY_COUNT, ");
            sprintf(sql + strlen(sql),   "A.DELETE_FLAG, ");
            sprintf(sql + strlen(sql),   "A.CREATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "A.CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "A.UPDATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "A.UPDATE_TIME, ");
            sprintf(sql + strlen(sql),   "A.SYS_MSG_FLAG, ");
            sprintf(sql + strlen(sql),   "A.POPUP_CYCLE, ");
            sprintf(sql + strlen(sql),   "A.PRIORITY, ");
            sprintf(sql + strlen(sql),   "A.APPLY_SHIFT, ");
            sprintf(sql + strlen(sql),   "A.APPLY_START_TIME, ");
            sprintf(sql + strlen(sql),   "A.APPLY_END_TIME, ");
            sprintf(sql + strlen(sql),   "A.AREA_ID, ");
            sprintf(sql + strlen(sql),   "A.SUB_AREA_ID, ");
            sprintf(sql + strlen(sql),   "A.RESG_ID, ");
            sprintf(sql + strlen(sql),   "A.MAT_ID, ");
            sprintf(sql + strlen(sql),   "A.FLOW, ");
            sprintf(sql + strlen(sql),   "A.RCV_USER_ID, ");
            sprintf(sql + strlen(sql),   "A.SEC_GRP_ID, ");
            sprintf(sql + strlen(sql),   "A.PRV_GRP_ID, ");
            sprintf(sql + strlen(sql),   "A.MODAL_FLAG, ");
            sprintf(sql + strlen(sql),   "A.AUTO_CLOSE_FLAG, ");
            sprintf(sql + strlen(sql),   "A.AUTO_CLOSE_TIME, ");
            sprintf(sql + strlen(sql),   "A.ACK_FLAG, ");
            sprintf(sql + strlen(sql),   "A.ACK_TIME, ");
            sprintf(sql + strlen(sql),   "A.ACK_USER_ID, ");
            sprintf(sql + strlen(sql),   "A.RCV_FACTORY ");
            sprintf(sql + strlen(sql), "FROM (SELECT ");
            sprintf(sql + strlen(sql),   "FACTORY, ");
            sprintf(sql + strlen(sql),   "MAIN_MENU_ID, ");
            sprintf(sql + strlen(sql),   "SUB_MENU_ID, ");
            sprintf(sql + strlen(sql),   "BBS_SEQ, ");
            sprintf(sql + strlen(sql),   "TRAN_TIME, ");
            sprintf(sql + strlen(sql),   "LOT_ID, ");
            sprintf(sql + strlen(sql),   "SUBLOT_ID, ");
            sprintf(sql + strlen(sql),   "OPER, ");
            sprintf(sql + strlen(sql),   "RES_ID, ");
            sprintf(sql + strlen(sql),   "SUBRES_ID, ");
            sprintf(sql + strlen(sql),   "MSG_TYPE, ");
            sprintf(sql + strlen(sql),   "MSG_TITLE, ");
            sprintf(sql + strlen(sql),   "MSG_TAG, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_1, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_2, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_3, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_4, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_5, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_6, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_7, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_8, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_9, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_10, ");
            sprintf(sql + strlen(sql),   "REPLY_COUNT, ");
            sprintf(sql + strlen(sql),   "DELETE_FLAG, ");
            sprintf(sql + strlen(sql),   "CREATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "UPDATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "UPDATE_TIME, ");
            sprintf(sql + strlen(sql),   "SYS_MSG_FLAG, ");
            sprintf(sql + strlen(sql),   "POPUP_CYCLE, ");
            sprintf(sql + strlen(sql),   "PRIORITY, ");
            sprintf(sql + strlen(sql),   "APPLY_SHIFT, ");
            sprintf(sql + strlen(sql),   "APPLY_START_TIME, ");
            sprintf(sql + strlen(sql),   "APPLY_END_TIME, ");
            sprintf(sql + strlen(sql),   "AREA_ID, ");
            sprintf(sql + strlen(sql),   "SUB_AREA_ID, ");
            sprintf(sql + strlen(sql),   "RESG_ID, ");
            sprintf(sql + strlen(sql),   "MAT_ID, ");
            sprintf(sql + strlen(sql),   "FLOW, ");
            sprintf(sql + strlen(sql),   "RCV_USER_ID, ");
            sprintf(sql + strlen(sql),   "SEC_GRP_ID, ");
            sprintf(sql + strlen(sql),   "PRV_GRP_ID, ");
            sprintf(sql + strlen(sql),   "MODAL_FLAG, ");
            sprintf(sql + strlen(sql),   "AUTO_CLOSE_FLAG, ");
            sprintf(sql + strlen(sql),   "AUTO_CLOSE_TIME, ");
            sprintf(sql + strlen(sql),   "ACK_FLAG, ");
            sprintf(sql + strlen(sql),   "ACK_TIME, ");
            sprintf(sql + strlen(sql),   "ACK_USER_ID, ");
            sprintf(sql + strlen(sql),   "RCV_FACTORY ");
            sprintf(sql + strlen(sql), "FROM MMSGBBSHIS WHERE ");

            make_valid_quote(ts1, MMSGBBSHIS_N.FACTORY);
            sprintf(sql + strlen(sql), " FACTORY = '%s' ", ts1);
            make_valid_quote(ts1, DBC_Q_COND_N.FROM_TIME);
            sprintf(sql + strlen(sql), " AND (APPLY_START_TIME >= '%s' OR APPLY_START_TIME = ' ') ", ts1 );
            make_valid_quote(ts1, DBC_Q_COND_N.TO_TIME);
            sprintf(sql + strlen(sql), " AND (APPLY_END_TIME < '%s' OR APPLY_END_TIME = ' ') ", ts1 );

            if(ISSPACE(MMSGBBSHIS->MAIN_MENU_ID, sizeof(MMSGBBSHIS->MAIN_MENU_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.MAIN_MENU_ID);
                sprintf(sql + strlen(sql), "AND MAIN_MENU_ID = '%s' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->SUB_MENU_ID, sizeof(MMSGBBSHIS->SUB_MENU_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.SUB_MENU_ID);
                sprintf(sql + strlen(sql), "AND SUB_MENU_ID = '%s' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->LOT_ID, sizeof(MMSGBBSHIS->LOT_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.LOT_ID);
                sprintf(sql + strlen(sql), "AND LOT_ID LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->SUBLOT_ID, sizeof(MMSGBBSHIS->SUBLOT_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.SUBLOT_ID);
                sprintf(sql + strlen(sql), "AND SUBLOT_ID LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->MAT_ID, sizeof(MMSGBBSHIS->MAT_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.MAT_ID);
                sprintf(sql + strlen(sql), "AND MAT_ID LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->FLOW, sizeof(MMSGBBSHIS->FLOW)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.FLOW);
                sprintf(sql + strlen(sql), "AND FLOW LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->OPER, sizeof(MMSGBBSHIS->OPER)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.OPER);
                sprintf(sql + strlen(sql), "AND OPER LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->RES_ID, sizeof(MMSGBBSHIS->RES_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.RES_ID);
                sprintf(sql + strlen(sql), "AND RES_ID LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->SUBRES_ID, sizeof(MMSGBBSHIS->SUBRES_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.SUBRES_ID);
                sprintf(sql + strlen(sql), "AND SUBRES_ID LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->AREA_ID, sizeof(MMSGBBSHIS->AREA_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.AREA_ID);
                sprintf(sql + strlen(sql), "AND AREA_ID LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->SUB_AREA_ID, sizeof(MMSGBBSHIS->SUB_AREA_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.SUB_AREA_ID);
                sprintf(sql + strlen(sql), "AND SUB_AREA_ID LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->RESG_ID, sizeof(MMSGBBSHIS->RESG_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.RESG_ID);
                sprintf(sql + strlen(sql), "AND RESG_ID LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->MSG_TYPE, sizeof(MMSGBBSHIS->MSG_TYPE)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.MSG_TYPE);
                sprintf(sql + strlen(sql), "AND MSG_TYPE LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->MSG_TITLE, sizeof(MMSGBBSHIS->MSG_TITLE)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.MSG_TITLE);
                sprintf(sql + strlen(sql), "AND MSG_TITLE LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->MSG_TAG, sizeof(MMSGBBSHIS->MSG_TAG)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.MSG_TAG);
                sprintf(sql + strlen(sql), "AND MSG_TAG LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->UPDATE_USER_ID, sizeof(MMSGBBSHIS->UPDATE_USER_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.UPDATE_USER_ID);
                sprintf(sql + strlen(sql), "AND UPDATE_USER_ID LIKE '%%%s%%' ", ts1);
            }

            if(ISSPACE(MMSGBBSHIS->RCV_USER_ID, sizeof(MMSGBBSHIS->RCV_USER_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.RCV_USER_ID);
                sprintf(sql + strlen(sql), "AND RCV_USER_ID LIKE '%%%s%%' ", ts1);
            }

            if(MMSGBBSHIS->SYS_MSG_FLAG != ' ')
            {
                 /* Exclude system message */
                sprintf(sql + strlen(sql), "AND SYS_MSG_FLAG = ' ' ");
            }

            if(MMSGBBSHIS->DELETE_FLAG == ' ')
            {
                sprintf(sql + strlen(sql), "AND DELETE_FLAG = ' ' ");
            }

            if(MMSGBBSHIS->ACK_FLAG == ' ')
            {
                sprintf(sql + strlen(sql), "AND ACK_FLAG = ' ' ");
            }

            /* Added by DM KIM 2012.05.03 Add View Condition */
            if(MMSGBBSHIS->POPUP_CYCLE != ' ')
            {
                sprintf(sql + strlen(sql), "AND POPUP_CYCLE = '%c' ", MMSGBBSHIS_N.POPUP_CYCLE[0]);
            }

            if(MMSGBBSHIS->APPLY_SHIFT != ' ')
            {
                sprintf(sql + strlen(sql), "AND APPLY_SHIFT = '%c' ", MMSGBBSHIS_N.APPLY_SHIFT[0]);
            }

            sprintf(sql + strlen(sql), "ORDER BY PRIORITY ASC, UPDATE_TIME DESC ");
            sprintf(sql + strlen(sql), ") A ) ");
            
            if( MMSGBBSHIS_N.BBS_SEQ > 0 )
            {
                sprintf(sql + strlen(sql), "WHERE SEQ < %ld ", MMSGBBSHIS_N.BBS_SEQ);
            }

            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )963;
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


            /* EXEC SQL DECLARE DBC_MMSGBBSHIS_CUR_1 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_MMSGBBSHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )982;
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
            /* View BBS Message List */
            memset( sql, 0x00, sizeof(sql));
            sprintf(sql,               "SELECT ");
            sprintf(sql + strlen(sql),   "SEQ, ");
            sprintf(sql + strlen(sql),   "FACTORY, ");
            sprintf(sql + strlen(sql),   "MAIN_MENU_ID, ");
            sprintf(sql + strlen(sql),   "SUB_MENU_ID, ");
            sprintf(sql + strlen(sql),   "BBS_SEQ, ");
            sprintf(sql + strlen(sql),   "TRAN_TIME, ");
            sprintf(sql + strlen(sql),   "LOT_ID, ");
            sprintf(sql + strlen(sql),   "SUBLOT_ID, ");
            sprintf(sql + strlen(sql),   "OPER, ");
            sprintf(sql + strlen(sql),   "RES_ID, ");
            sprintf(sql + strlen(sql),   "SUBRES_ID, ");
            sprintf(sql + strlen(sql),   "MSG_TYPE, ");
            sprintf(sql + strlen(sql),   "MSG_TITLE, ");
            sprintf(sql + strlen(sql),   "MSG_TAG, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_1, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_2, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_3, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_4, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_5, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_6, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_7, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_8, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_9, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_10, ");
            sprintf(sql + strlen(sql),   "REPLY_COUNT, ");
            sprintf(sql + strlen(sql),   "DELETE_FLAG, ");
            sprintf(sql + strlen(sql),   "CREATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "UPDATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "UPDATE_TIME, ");
            sprintf(sql + strlen(sql),   "SYS_MSG_FLAG, ");
            sprintf(sql + strlen(sql),   "POPUP_CYCLE, ");
            sprintf(sql + strlen(sql),   "PRIORITY, ");
            sprintf(sql + strlen(sql),   "APPLY_SHIFT, ");
            sprintf(sql + strlen(sql),   "APPLY_START_TIME, ");
            sprintf(sql + strlen(sql),   "APPLY_END_TIME, ");
            sprintf(sql + strlen(sql),   "AREA_ID, ");
            sprintf(sql + strlen(sql),   "SUB_AREA_ID, ");
            sprintf(sql + strlen(sql),   "RESG_ID, ");
            sprintf(sql + strlen(sql),   "MAT_ID, ");
            sprintf(sql + strlen(sql),   "FLOW, ");
            sprintf(sql + strlen(sql),   "RCV_USER_ID, ");
            sprintf(sql + strlen(sql),   "SEC_GRP_ID, ");
            sprintf(sql + strlen(sql),   "PRV_GRP_ID, ");
            sprintf(sql + strlen(sql),   "MODAL_FLAG, ");
            sprintf(sql + strlen(sql),   "AUTO_CLOSE_FLAG, ");
            sprintf(sql + strlen(sql),   "AUTO_CLOSE_TIME, ");
            sprintf(sql + strlen(sql),   "ACK_FLAG, ");
            sprintf(sql + strlen(sql),   "ACK_TIME, ");
            sprintf(sql + strlen(sql),   "ACK_USER_ID, ");
            sprintf(sql + strlen(sql),   "RCV_FACTORY ");
            sprintf(sql + strlen(sql), "FROM (SELECT ROWNUM AS SEQ, ");
            sprintf(sql + strlen(sql),   "A.FACTORY, ");
            sprintf(sql + strlen(sql),   "A.MAIN_MENU_ID, ");
            sprintf(sql + strlen(sql),   "A.SUB_MENU_ID, ");
            sprintf(sql + strlen(sql),   "A.BBS_SEQ, ");
            sprintf(sql + strlen(sql),   "A.TRAN_TIME, ");
            sprintf(sql + strlen(sql),   "A.LOT_ID, ");
            sprintf(sql + strlen(sql),   "A.SUBLOT_ID, ");
            sprintf(sql + strlen(sql),   "A.OPER, ");
            sprintf(sql + strlen(sql),   "A.RES_ID, ");
            sprintf(sql + strlen(sql),   "A.SUBRES_ID, ");
            sprintf(sql + strlen(sql),   "A.MSG_TYPE, ");
            sprintf(sql + strlen(sql),   "A.MSG_TITLE, ");
            sprintf(sql + strlen(sql),   "A.MSG_TAG, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_1, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_2, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_3, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_4, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_5, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_6, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_7, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_8, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_9, ");
            sprintf(sql + strlen(sql),   "A.BBS_CMF_10, ");
            sprintf(sql + strlen(sql),   "A.REPLY_COUNT, ");
            sprintf(sql + strlen(sql),   "A.DELETE_FLAG, ");
            sprintf(sql + strlen(sql),   "A.CREATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "A.CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "A.UPDATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "A.UPDATE_TIME, ");
            sprintf(sql + strlen(sql),   "A.SYS_MSG_FLAG, ");
            sprintf(sql + strlen(sql),   "A.POPUP_CYCLE, ");
            sprintf(sql + strlen(sql),   "A.PRIORITY, ");
            sprintf(sql + strlen(sql),   "A.APPLY_SHIFT, ");
            sprintf(sql + strlen(sql),   "A.APPLY_START_TIME, ");
            sprintf(sql + strlen(sql),   "A.APPLY_END_TIME, ");
            sprintf(sql + strlen(sql),   "A.AREA_ID, ");
            sprintf(sql + strlen(sql),   "A.SUB_AREA_ID, ");
            sprintf(sql + strlen(sql),   "A.RESG_ID, ");
            sprintf(sql + strlen(sql),   "A.MAT_ID, ");
            sprintf(sql + strlen(sql),   "A.FLOW, ");
            sprintf(sql + strlen(sql),   "A.RCV_USER_ID, ");
            sprintf(sql + strlen(sql),   "A.SEC_GRP_ID, ");
            sprintf(sql + strlen(sql),   "A.PRV_GRP_ID, ");
            sprintf(sql + strlen(sql),   "A.MODAL_FLAG, ");
            sprintf(sql + strlen(sql),   "A.AUTO_CLOSE_FLAG, ");
            sprintf(sql + strlen(sql),   "A.AUTO_CLOSE_TIME, ");
            sprintf(sql + strlen(sql),   "A.ACK_FLAG, ");
            sprintf(sql + strlen(sql),   "A.ACK_TIME, ");
            sprintf(sql + strlen(sql),   "A.ACK_USER_ID, ");
            sprintf(sql + strlen(sql),   "A.RCV_FACTORY ");
            sprintf(sql + strlen(sql), "FROM (SELECT ");
            sprintf(sql + strlen(sql),   "FACTORY, ");
            sprintf(sql + strlen(sql),   "MAIN_MENU_ID, ");
            sprintf(sql + strlen(sql),   "SUB_MENU_ID, ");
            sprintf(sql + strlen(sql),   "BBS_SEQ, ");
            sprintf(sql + strlen(sql),   "TRAN_TIME, ");
            sprintf(sql + strlen(sql),   "LOT_ID, ");
            sprintf(sql + strlen(sql),   "SUBLOT_ID, ");
            sprintf(sql + strlen(sql),   "OPER, ");
            sprintf(sql + strlen(sql),   "RES_ID, ");
            sprintf(sql + strlen(sql),   "SUBRES_ID, ");
            sprintf(sql + strlen(sql),   "MSG_TYPE, ");
            sprintf(sql + strlen(sql),   "MSG_TITLE, ");
            sprintf(sql + strlen(sql),   "MSG_TAG, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_1, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_2, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_3, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_4, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_5, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_6, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_7, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_8, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_9, ");
            sprintf(sql + strlen(sql),   "BBS_CMF_10, ");
            sprintf(sql + strlen(sql),   "REPLY_COUNT, ");
            sprintf(sql + strlen(sql),   "DELETE_FLAG, ");
            sprintf(sql + strlen(sql),   "CREATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "UPDATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "UPDATE_TIME, ");
            sprintf(sql + strlen(sql),   "SYS_MSG_FLAG, ");
            sprintf(sql + strlen(sql),   "POPUP_CYCLE, ");
            sprintf(sql + strlen(sql),   "PRIORITY, ");
            sprintf(sql + strlen(sql),   "APPLY_SHIFT, ");
            sprintf(sql + strlen(sql),   "APPLY_START_TIME, ");
            sprintf(sql + strlen(sql),   "APPLY_END_TIME, ");
            sprintf(sql + strlen(sql),   "AREA_ID, ");
            sprintf(sql + strlen(sql),   "SUB_AREA_ID, ");
            sprintf(sql + strlen(sql),   "RESG_ID, ");
            sprintf(sql + strlen(sql),   "MAT_ID, ");
            sprintf(sql + strlen(sql),   "FLOW, ");
            sprintf(sql + strlen(sql),   "RCV_USER_ID, ");
            sprintf(sql + strlen(sql),   "SEC_GRP_ID, ");
            sprintf(sql + strlen(sql),   "PRV_GRP_ID, ");
            sprintf(sql + strlen(sql),   "MODAL_FLAG, ");
            sprintf(sql + strlen(sql),   "AUTO_CLOSE_FLAG, ");
            sprintf(sql + strlen(sql),   "AUTO_CLOSE_TIME, ");
            sprintf(sql + strlen(sql),   "ACK_FLAG, ");
            sprintf(sql + strlen(sql),   "ACK_TIME, ");
            sprintf(sql + strlen(sql),   "ACK_USER_ID, ");
            sprintf(sql + strlen(sql),   "RCV_FACTORY ");
            sprintf(sql + strlen(sql), "FROM MMSGBBSHIS WHERE ");
            
            /* Only for system bbs message */
            if(MMSGBBSHIS->SYS_MSG_FLAG == ' ')
            {
                sprintf(sql + strlen(sql), "(SYS_MSG_FLAG = 'Y' ");
                make_valid_quote(ts1, MMSGBBSHIS_N.APPLY_START_TIME);
                sprintf(sql + strlen(sql), "AND (APPLY_START_TIME = ' ' OR APPLY_START_TIME < '%s') ", ts1); 
                sprintf(sql + strlen(sql), "AND (APPLY_END_TIME = ' ' OR APPLY_END_TIME > '%s') ", ts1);

                make_valid_quote(ts1, MMSGBBSHIS_N.FACTORY);
                sprintf(sql + strlen(sql), "AND (RCV_FACTORY = '%s' OR (RCV_FACTORY = ' ' AND FACTORY = '%s')) ", ts1, ts1);

                if(MMSGBBSHIS->APPLY_SHIFT != ' ')
                {
                    sprintf(sql + strlen(sql), "AND (APPLY_SHIFT = 'N' OR APPLY_SHIFT = '%c') ", MMSGBBSHIS_N.APPLY_SHIFT[0]);
                }
			    if(MMSGBBSHIS->PRIORITY != ' ')
                {
                    sprintf(sql + strlen(sql), "AND PRIORITY = '%c' ", MMSGBBSHIS_N.PRIORITY[0]);
                }
                if(MMSGBBSHIS->DELETE_FLAG == ' ')
                {
                    sprintf(sql + strlen(sql), "AND DELETE_FLAG = ' ' ");
                }
                if(MMSGBBSHIS->ACK_FLAG == ' ')
                {
                    sprintf(sql + strlen(sql), "AND ACK_FLAG = ' ') OR ( ");
                }
            }

            sprintf(sql + strlen(sql), "SYS_MSG_FLAG = ' ' ");
            make_valid_quote(ts1, MMSGBBSHIS_N.APPLY_START_TIME);
            sprintf(sql + strlen(sql), "AND (APPLY_START_TIME = ' ' OR APPLY_START_TIME < '%s') ", ts1); 
            sprintf(sql + strlen(sql), "AND (APPLY_END_TIME = ' ' OR APPLY_END_TIME > '%s') ", ts1);

            make_valid_quote(ts1, MMSGBBSHIS_N.FACTORY);
            sprintf(sql + strlen(sql), "AND (RCV_FACTORY = '%s' OR (RCV_FACTORY = ' ' AND FACTORY = '%s')) ", ts1, ts1);

            if(MMSGBBSHIS->APPLY_SHIFT != ' ')
            {
                sprintf(sql + strlen(sql), "AND (APPLY_SHIFT = 'N' OR APPLY_SHIFT = '%c') ", MMSGBBSHIS_N.APPLY_SHIFT[0]);
            }
			if(MMSGBBSHIS->PRIORITY != ' ')
            {
                sprintf(sql + strlen(sql), "AND PRIORITY = '%c' ", MMSGBBSHIS_N.PRIORITY[0]);
            }
            if(MMSGBBSHIS->DELETE_FLAG == ' ')
            {
                sprintf(sql + strlen(sql), "AND DELETE_FLAG = ' ' ");
            }
            if(MMSGBBSHIS->ACK_FLAG == ' ')
            {
                sprintf(sql + strlen(sql), "AND ACK_FLAG = ' ' ");
            }

            if(ISSPACE(MMSGBBSHIS->RCV_USER_ID, sizeof(MMSGBBSHIS->RCV_USER_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.RCV_USER_ID);
                make_valid_quote(ts2, MMSGBBSHIS_N.FACTORY);

                sprintf(sql + strlen(sql), "AND (RCV_USER_ID = '%s' ", ts1);
                sprintf(sql + strlen(sql), "OR SEC_GRP_ID =  (SELECT SEC_GRP_ID FROM MSECUSRDEF WHERE FACTORY = '%s' AND USER_ID = '%s') ", ts2, ts1);
                sprintf(sql + strlen(sql), "OR PRV_GRP_ID IN (SELECT PRV_GRP_ID FROM MSECPRVUSR WHERE FACTORY = '%s' AND USER_ID = '%s')) ", ts2, ts1);
            }

            if(ISSPACE(MMSGBBSHIS->LOT_ID, sizeof(MMSGBBSHIS->LOT_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.LOT_ID);
                sprintf(sql + strlen(sql), "AND (LOT_ID = '%s' ", ts1);
                sprintf(sql + strlen(sql), "OR ((LOT_ID, MAT_ID, FLOW, OPER) = (SELECT ' ', MAT_ID, FLOW, OPER FROM MWIPLOTSTS WHERE LOT_ID = '%s')) ", ts1);
                sprintf(sql + strlen(sql), "OR ((LOT_ID, MAT_ID, OPER)       = (SELECT ' ', MAT_ID, OPER       FROM MWIPLOTSTS WHERE LOT_ID = '%s')) ", ts1);
                sprintf(sql + strlen(sql), "OR ((LOT_ID, MAT_ID)             = (SELECT ' ', MAT_ID             FROM MWIPLOTSTS WHERE LOT_ID = '%s')) ", ts1);
                sprintf(sql + strlen(sql), "OR ((LOT_ID, FLOW, OPER)         = (SELECT ' ', FLOW, OPER         FROM MWIPLOTSTS WHERE LOT_ID = '%s')) ", ts1);

                if(ISSPACE(MMSGBBSHIS->FLOW, sizeof(MMSGBBSHIS->FLOW)) == DB_FALSE)
                {
                    sprintf(sql + strlen(sql), "OR ((LOT_ID, FLOW)               = (SELECT ' ', FLOW               FROM MWIPLOTSTS WHERE LOT_ID = '%s')) ", ts1);
                }

                sprintf(sql + strlen(sql), "OR ((LOT_ID, OPER)               = (SELECT ' ', OPER               FROM MWIPLOTSTS WHERE LOT_ID = '%s'))) ", ts1);
            }
            else
            {
                if(ISSPACE(MMSGBBSHIS->MAT_ID, sizeof(MMSGBBSHIS->MAT_ID)) == DB_FALSE &&
                   ISSPACE(MMSGBBSHIS->FLOW, sizeof(MMSGBBSHIS->FLOW)) == DB_FALSE &&
                   ISSPACE(MMSGBBSHIS->OPER, sizeof(MMSGBBSHIS->OPER)) == DB_FALSE)
                {
                    make_valid_quote(ts1, MMSGBBSHIS_N.MAT_ID);
                    make_valid_quote(ts2, MMSGBBSHIS_N.FLOW);
                    make_valid_quote(ts3, MMSGBBSHIS_N.OPER);

                    sprintf(sql + strlen(sql), "AND ((MAT_ID = '%s' AND FLOW = '%s' AND OPER = '%s') ", ts1, ts2, ts3);
                    sprintf(sql + strlen(sql), "OR (MAT_ID = '%s' AND OPER = '%s') ", ts1, ts3);
                    sprintf(sql + strlen(sql), "OR (MAT_ID = '%s') ", ts1);
                    sprintf(sql + strlen(sql), "OR (FLOW = '%s' AND OPER = '%s') ", ts2, ts3);
                    sprintf(sql + strlen(sql), "OR (FLOW = '%s') ", ts2);
                    sprintf(sql + strlen(sql), "OR (OPER = '%s')) ", ts3);
                }
                else
                {
                    if(ISSPACE(MMSGBBSHIS->MAT_ID, sizeof(MMSGBBSHIS->MAT_ID)) == DB_FALSE)
                    {
                        make_valid_quote(ts1, MMSGBBSHIS_N.MAT_ID);
                        sprintf(sql + strlen(sql), "AND MAT_ID = '%s' ", ts1);
                    }
                    if(ISSPACE(MMSGBBSHIS->FLOW, sizeof(MMSGBBSHIS->FLOW)) == DB_FALSE)
                    {
                        make_valid_quote(ts1, MMSGBBSHIS_N.FLOW);
                        sprintf(sql + strlen(sql), "AND FLOW = '%s' ", ts1);
                    }
                    if(ISSPACE(MMSGBBSHIS->OPER, sizeof(MMSGBBSHIS->OPER)) == DB_FALSE)
                    {
                        make_valid_quote(ts1, MMSGBBSHIS_N.OPER);
                        sprintf(sql + strlen(sql), "AND OPER = '%s' ", ts1);
                    }
                }
            }

            if(ISSPACE(MMSGBBSHIS->RES_ID, sizeof(MMSGBBSHIS->RES_ID)) == DB_FALSE)
            {
                make_valid_quote(ts1, MMSGBBSHIS_N.RES_ID);
                make_valid_quote(ts2, MMSGBBSHIS_N.FACTORY);

                sprintf(sql + strlen(sql), "AND (RES_ID = '%s' ", ts1);
                sprintf(sql + strlen(sql), "OR RESG_ID IN    (SELECT RESG_ID     FROM MRASRSGRES WHERE FACTORY = '%s' AND RES_ID = '%s') ", ts2, ts1);
                sprintf(sql + strlen(sql), "OR AREA_ID =     (SELECT AREA_ID     FROM MRASRESDEF WHERE FACTORY = '%s' AND RES_ID = '%s') ", ts2, ts1);
                sprintf(sql + strlen(sql), "OR SUB_AREA_ID = (SELECT SUB_AREA_ID FROM MRASRESDEF WHERE FACTORY = '%s' AND RES_ID = '%s')) ", ts2, ts1);
            }
            else
            {
                if(ISSPACE(MMSGBBSHIS->AREA_ID, sizeof(MMSGBBSHIS->AREA_ID)) == DB_FALSE &&
                   ISSPACE(MMSGBBSHIS->SUB_AREA_ID, sizeof(MMSGBBSHIS->SUB_AREA_ID)) == DB_FALSE)
                {
                    make_valid_quote(ts1, MMSGBBSHIS_N.AREA_ID);
                    make_valid_quote(ts2, MMSGBBSHIS_N.SUB_AREA_ID);
                    sprintf(sql + strlen(sql), "AND (AREA_ID = '%s' OR SUB_AREA_ID = '%s') ", ts1, ts2);
                }
                else
                {
                    if(ISSPACE(MMSGBBSHIS->AREA_ID, sizeof(MMSGBBSHIS->AREA_ID)) == DB_FALSE)
                    {
                        make_valid_quote(ts1, MMSGBBSHIS_N.AREA_ID);
                        sprintf(sql + strlen(sql), "AND AREA_ID = '%s' ", ts1);
                    }
                    if(ISSPACE(MMSGBBSHIS->SUB_AREA_ID, sizeof(MMSGBBSHIS->SUB_AREA_ID)) == DB_FALSE)
                    {
                        make_valid_quote(ts1, MMSGBBSHIS_N.SUB_AREA_ID);
                        sprintf(sql + strlen(sql), "AND SUB_AREA_ID = '%s' ", ts1);
                    }
                }
            }

            if(MMSGBBSHIS->SYS_MSG_FLAG == ' ')
            {
                sprintf(sql + strlen(sql), ") ");
            }

            sprintf(sql + strlen(sql), "ORDER BY PRIORITY ASC, UPDATE_TIME DESC ");
            sprintf(sql + strlen(sql), ") A ) ");

            if( MMSGBBSHIS_N.BBS_SEQ > 0 )
            {
                sprintf(sql + strlen(sql), "WHERE SEQ < %ld ", MMSGBBSHIS_N.BBS_SEQ);
            }


            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )997;
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


            /* EXEC SQL DECLARE DBC_MMSGBBSHIS_CUR_2 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_MMSGBBSHIS_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1016;
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
    DB_stop_query_timer("DBC_open_mmsgbbshis", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mmsgbbshis(int sel_type, struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MMSGBBSHIS_N_TAG MMSGBBSHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MMSGBBSHIS_CUR_1 INTO :DBC_Q_COND_N.FROM_SEQ,
                                                     :MMSGBBSHIS_N.FACTORY,
                                                     :MMSGBBSHIS_N.MAIN_MENU_ID,
                                                     :MMSGBBSHIS_N.SUB_MENU_ID,
                                                     :MMSGBBSHIS_N.BBS_SEQ,
                                                     :MMSGBBSHIS_N.TRAN_TIME,
                                                     :MMSGBBSHIS_N.LOT_ID,
                                                     :MMSGBBSHIS_N.SUBLOT_ID,
                                                     :MMSGBBSHIS_N.OPER,
                                                     :MMSGBBSHIS_N.RES_ID,
                                                     :MMSGBBSHIS_N.SUBRES_ID,
                                                     :MMSGBBSHIS_N.MSG_TYPE,
                                                     :MMSGBBSHIS_N.MSG_TITLE,
                                                     :MMSGBBSHIS_N.MSG_TAG,
                                                     :MMSGBBSHIS_N.BBS_CMF_1,
                                                     :MMSGBBSHIS_N.BBS_CMF_2,
                                                     :MMSGBBSHIS_N.BBS_CMF_3,
                                                     :MMSGBBSHIS_N.BBS_CMF_4,
                                                     :MMSGBBSHIS_N.BBS_CMF_5,
                                                     :MMSGBBSHIS_N.BBS_CMF_6,
                                                     :MMSGBBSHIS_N.BBS_CMF_7,
                                                     :MMSGBBSHIS_N.BBS_CMF_8,
                                                     :MMSGBBSHIS_N.BBS_CMF_9,
                                                     :MMSGBBSHIS_N.BBS_CMF_10,
                                                     :MMSGBBSHIS_N.REPLY_COUNT,
                                                     :MMSGBBSHIS_N.DELETE_FLAG,
                                                     :MMSGBBSHIS_N.CREATE_USER_ID,
                                                     :MMSGBBSHIS_N.CREATE_TIME,
                                                     :MMSGBBSHIS_N.UPDATE_USER_ID,
                                                     :MMSGBBSHIS_N.UPDATE_TIME,
                                                     :MMSGBBSHIS_N.SYS_MSG_FLAG,
                                                     :MMSGBBSHIS_N.POPUP_CYCLE,
                                                     :MMSGBBSHIS_N.PRIORITY,
                                                     :MMSGBBSHIS_N.APPLY_SHIFT,
                                                     :MMSGBBSHIS_N.APPLY_START_TIME,
                                                     :MMSGBBSHIS_N.APPLY_END_TIME,
                                                     :MMSGBBSHIS_N.AREA_ID,
                                                     :MMSGBBSHIS_N.SUB_AREA_ID,
                                                     :MMSGBBSHIS_N.RESG_ID,
                                                     :MMSGBBSHIS_N.MAT_ID,
                                                     :MMSGBBSHIS_N.FLOW,
                                                     :MMSGBBSHIS_N.RCV_USER_ID,
                                                     :MMSGBBSHIS_N.SEC_GRP_ID,
                                                     :MMSGBBSHIS_N.PRV_GRP_ID,
                                                     :MMSGBBSHIS_N.MODAL_FLAG,
                                                     :MMSGBBSHIS_N.AUTO_CLOSE_FLAG,
                                                     :MMSGBBSHIS_N.AUTO_CLOSE_TIME,
                                                     :MMSGBBSHIS_N.ACK_FLAG,
                                                     :MMSGBBSHIS_N.ACK_TIME,
                                                     :MMSGBBSHIS_N.ACK_USER_ID,
                                                     :MMSGBBSHIS_N.RCV_FACTORY; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1031;
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
            sqlstm.sqhstv[1] = (         void  *)(MMSGBBSHIS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MMSGBBSHIS_N.MAIN_MENU_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MMSGBBSHIS_N.SUB_MENU_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MMSGBBSHIS_N.BBS_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MMSGBBSHIS_N.TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MMSGBBSHIS_N.LOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MMSGBBSHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MMSGBBSHIS_N.OPER);
            sqlstm.sqhstl[8] = (unsigned int  )11;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MMSGBBSHIS_N.RES_ID);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MMSGBBSHIS_N.SUBRES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MMSGBBSHIS_N.MSG_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MMSGBBSHIS_N.MSG_TITLE);
            sqlstm.sqhstl[12] = (unsigned int  )201;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MMSGBBSHIS_N.MSG_TAG);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_1);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_2);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_3);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_4);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_5);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_6);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_7);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_8);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_9);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_10);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MMSGBBSHIS_N.REPLY_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MMSGBBSHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MMSGBBSHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MMSGBBSHIS_N.CREATE_TIME);
            sqlstm.sqhstl[27] = (unsigned int  )15;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MMSGBBSHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MMSGBBSHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MMSGBBSHIS_N.SYS_MSG_FLAG);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MMSGBBSHIS_N.POPUP_CYCLE);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MMSGBBSHIS_N.PRIORITY);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MMSGBBSHIS_N.APPLY_SHIFT);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MMSGBBSHIS_N.APPLY_START_TIME);
            sqlstm.sqhstl[34] = (unsigned int  )15;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MMSGBBSHIS_N.APPLY_END_TIME);
            sqlstm.sqhstl[35] = (unsigned int  )15;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MMSGBBSHIS_N.AREA_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MMSGBBSHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MMSGBBSHIS_N.RESG_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MMSGBBSHIS_N.MAT_ID);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MMSGBBSHIS_N.FLOW);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MMSGBBSHIS_N.RCV_USER_ID);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MMSGBBSHIS_N.SEC_GRP_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MMSGBBSHIS_N.PRV_GRP_ID);
            sqlstm.sqhstl[43] = (unsigned int  )21;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MMSGBBSHIS_N.MODAL_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MMSGBBSHIS_N.AUTO_CLOSE_FLAG);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(MMSGBBSHIS_N.AUTO_CLOSE_TIME);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MMSGBBSHIS_N.ACK_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MMSGBBSHIS_N.ACK_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MMSGBBSHIS_N.ACK_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MMSGBBSHIS_N.RCV_FACTORY);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
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
        case 2:
            /* EXEC SQL FETCH DBC_MMSGBBSHIS_CUR_2 INTO :DBC_Q_COND_N.FROM_SEQ,
                                                     :MMSGBBSHIS_N.FACTORY,
                                                     :MMSGBBSHIS_N.MAIN_MENU_ID,
                                                     :MMSGBBSHIS_N.SUB_MENU_ID,
                                                     :MMSGBBSHIS_N.BBS_SEQ,
                                                     :MMSGBBSHIS_N.TRAN_TIME,
                                                     :MMSGBBSHIS_N.LOT_ID,
                                                     :MMSGBBSHIS_N.SUBLOT_ID,
                                                     :MMSGBBSHIS_N.OPER,
                                                     :MMSGBBSHIS_N.RES_ID,
                                                     :MMSGBBSHIS_N.SUBRES_ID,
                                                     :MMSGBBSHIS_N.MSG_TYPE,
                                                     :MMSGBBSHIS_N.MSG_TITLE,
                                                     :MMSGBBSHIS_N.MSG_TAG,
                                                     :MMSGBBSHIS_N.BBS_CMF_1,
                                                     :MMSGBBSHIS_N.BBS_CMF_2,
                                                     :MMSGBBSHIS_N.BBS_CMF_3,
                                                     :MMSGBBSHIS_N.BBS_CMF_4,
                                                     :MMSGBBSHIS_N.BBS_CMF_5,
                                                     :MMSGBBSHIS_N.BBS_CMF_6,
                                                     :MMSGBBSHIS_N.BBS_CMF_7,
                                                     :MMSGBBSHIS_N.BBS_CMF_8,
                                                     :MMSGBBSHIS_N.BBS_CMF_9,
                                                     :MMSGBBSHIS_N.BBS_CMF_10,
                                                     :MMSGBBSHIS_N.REPLY_COUNT,
                                                     :MMSGBBSHIS_N.DELETE_FLAG,
                                                     :MMSGBBSHIS_N.CREATE_USER_ID,
                                                     :MMSGBBSHIS_N.CREATE_TIME,
                                                     :MMSGBBSHIS_N.UPDATE_USER_ID,
                                                     :MMSGBBSHIS_N.UPDATE_TIME,
                                                     :MMSGBBSHIS_N.SYS_MSG_FLAG,
                                                     :MMSGBBSHIS_N.POPUP_CYCLE,
                                                     :MMSGBBSHIS_N.PRIORITY,
                                                     :MMSGBBSHIS_N.APPLY_SHIFT,
                                                     :MMSGBBSHIS_N.APPLY_START_TIME,
                                                     :MMSGBBSHIS_N.APPLY_END_TIME,
                                                     :MMSGBBSHIS_N.AREA_ID,
                                                     :MMSGBBSHIS_N.SUB_AREA_ID,
                                                     :MMSGBBSHIS_N.RESG_ID,
                                                     :MMSGBBSHIS_N.MAT_ID,
                                                     :MMSGBBSHIS_N.FLOW,
                                                     :MMSGBBSHIS_N.RCV_USER_ID,
                                                     :MMSGBBSHIS_N.SEC_GRP_ID,
                                                     :MMSGBBSHIS_N.PRV_GRP_ID,
                                                     :MMSGBBSHIS_N.MODAL_FLAG,
                                                     :MMSGBBSHIS_N.AUTO_CLOSE_FLAG,
                                                     :MMSGBBSHIS_N.AUTO_CLOSE_TIME,
                                                     :MMSGBBSHIS_N.ACK_FLAG,
                                                     :MMSGBBSHIS_N.ACK_TIME,
                                                     :MMSGBBSHIS_N.ACK_USER_ID,
                                                     :MMSGBBSHIS_N.RCV_FACTORY; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1250;
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
            sqlstm.sqhstv[1] = (         void  *)(MMSGBBSHIS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MMSGBBSHIS_N.MAIN_MENU_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MMSGBBSHIS_N.SUB_MENU_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MMSGBBSHIS_N.BBS_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MMSGBBSHIS_N.TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MMSGBBSHIS_N.LOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MMSGBBSHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MMSGBBSHIS_N.OPER);
            sqlstm.sqhstl[8] = (unsigned int  )11;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MMSGBBSHIS_N.RES_ID);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MMSGBBSHIS_N.SUBRES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MMSGBBSHIS_N.MSG_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MMSGBBSHIS_N.MSG_TITLE);
            sqlstm.sqhstl[12] = (unsigned int  )201;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MMSGBBSHIS_N.MSG_TAG);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_1);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_2);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_3);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_4);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_5);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_6);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_7);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_8);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_9);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MMSGBBSHIS_N.BBS_CMF_10);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MMSGBBSHIS_N.REPLY_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MMSGBBSHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MMSGBBSHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MMSGBBSHIS_N.CREATE_TIME);
            sqlstm.sqhstl[27] = (unsigned int  )15;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MMSGBBSHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MMSGBBSHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MMSGBBSHIS_N.SYS_MSG_FLAG);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MMSGBBSHIS_N.POPUP_CYCLE);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MMSGBBSHIS_N.PRIORITY);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MMSGBBSHIS_N.APPLY_SHIFT);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MMSGBBSHIS_N.APPLY_START_TIME);
            sqlstm.sqhstl[34] = (unsigned int  )15;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MMSGBBSHIS_N.APPLY_END_TIME);
            sqlstm.sqhstl[35] = (unsigned int  )15;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MMSGBBSHIS_N.AREA_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MMSGBBSHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MMSGBBSHIS_N.RESG_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MMSGBBSHIS_N.MAT_ID);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MMSGBBSHIS_N.FLOW);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MMSGBBSHIS_N.RCV_USER_ID);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MMSGBBSHIS_N.SEC_GRP_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MMSGBBSHIS_N.PRV_GRP_ID);
            sqlstm.sqhstl[43] = (unsigned int  )21;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MMSGBBSHIS_N.MODAL_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MMSGBBSHIS_N.AUTO_CLOSE_FLAG);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(MMSGBBSHIS_N.AUTO_CLOSE_TIME);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MMSGBBSHIS_N.ACK_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MMSGBBSHIS_N.ACK_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MMSGBBSHIS_N.ACK_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MMSGBBSHIS_N.RCV_FACTORY);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
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
        DBC_del_null_mmsgbbshis(&MMSGBBSHIS_N, MMSGBBSHIS);
    }
    DB_stop_query_timer("DBC_fetch_mmsgbbshis", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mmsgbbshis(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MMSGBBSHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1469;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 2:
            /* EXEC SQL CLOSE DBC_MMSGBBSHIS_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1484;
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
    DB_stop_query_timer("DBC_close_mmsgbbshis", sel_type);
}



/* Initialize Function */
void DBC_init_mmsgbbshis(struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    /* memset by Space */
    memset(MMSGBBSHIS, ' ', sizeof(struct MMSGBBSHIS_TAG));
    
    MMSGBBSHIS->BBS_SEQ = 0;
    MMSGBBSHIS->REPLY_COUNT = 0;
    MMSGBBSHIS->AUTO_CLOSE_TIME = 0;
}


/* Add Null Function */
void DBC_add_null_mmsgbbshis(struct MMSGBBSHIS_N_TAG *MMSGBBSHIS_N, struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    /* memset by NULL */
    memset(MMSGBBSHIS_N, '\0', sizeof(struct MMSGBBSHIS_N_TAG));
    
    MEMCPY_AN(MMSGBBSHIS_N->FACTORY, MMSGBBSHIS->FACTORY, sizeof(MMSGBBSHIS->FACTORY));
    MEMCPY_AN(MMSGBBSHIS_N->MAIN_MENU_ID, MMSGBBSHIS->MAIN_MENU_ID, sizeof(MMSGBBSHIS->MAIN_MENU_ID));
    MEMCPY_AN(MMSGBBSHIS_N->SUB_MENU_ID, MMSGBBSHIS->SUB_MENU_ID, sizeof(MMSGBBSHIS->SUB_MENU_ID));
    MMSGBBSHIS_N->BBS_SEQ = MMSGBBSHIS->BBS_SEQ;
    MEMCPY_AN(MMSGBBSHIS_N->TRAN_TIME, MMSGBBSHIS->TRAN_TIME, sizeof(MMSGBBSHIS->TRAN_TIME));
    MEMCPY_AN(MMSGBBSHIS_N->LOT_ID, MMSGBBSHIS->LOT_ID, sizeof(MMSGBBSHIS->LOT_ID));
    MEMCPY_AN(MMSGBBSHIS_N->SUBLOT_ID, MMSGBBSHIS->SUBLOT_ID, sizeof(MMSGBBSHIS->SUBLOT_ID));
    MEMCPY_AN(MMSGBBSHIS_N->OPER, MMSGBBSHIS->OPER, sizeof(MMSGBBSHIS->OPER));
    MEMCPY_AN(MMSGBBSHIS_N->RES_ID, MMSGBBSHIS->RES_ID, sizeof(MMSGBBSHIS->RES_ID));
    MEMCPY_AN(MMSGBBSHIS_N->SUBRES_ID, MMSGBBSHIS->SUBRES_ID, sizeof(MMSGBBSHIS->SUBRES_ID));
    MEMCPY_AN(MMSGBBSHIS_N->MSG_TYPE, MMSGBBSHIS->MSG_TYPE, sizeof(MMSGBBSHIS->MSG_TYPE));
    MEMCPY_AN(MMSGBBSHIS_N->MSG_TITLE, MMSGBBSHIS->MSG_TITLE, sizeof(MMSGBBSHIS->MSG_TITLE));
    MEMCPY_AN(MMSGBBSHIS_N->MSG_TAG, MMSGBBSHIS->MSG_TAG, sizeof(MMSGBBSHIS->MSG_TAG));
    MEMCPY_AN(MMSGBBSHIS_N->BBS_CMF_1, MMSGBBSHIS->BBS_CMF_1, sizeof(MMSGBBSHIS->BBS_CMF_1));
    MEMCPY_AN(MMSGBBSHIS_N->BBS_CMF_2, MMSGBBSHIS->BBS_CMF_2, sizeof(MMSGBBSHIS->BBS_CMF_2));
    MEMCPY_AN(MMSGBBSHIS_N->BBS_CMF_3, MMSGBBSHIS->BBS_CMF_3, sizeof(MMSGBBSHIS->BBS_CMF_3));
    MEMCPY_AN(MMSGBBSHIS_N->BBS_CMF_4, MMSGBBSHIS->BBS_CMF_4, sizeof(MMSGBBSHIS->BBS_CMF_4));
    MEMCPY_AN(MMSGBBSHIS_N->BBS_CMF_5, MMSGBBSHIS->BBS_CMF_5, sizeof(MMSGBBSHIS->BBS_CMF_5));
    MEMCPY_AN(MMSGBBSHIS_N->BBS_CMF_6, MMSGBBSHIS->BBS_CMF_6, sizeof(MMSGBBSHIS->BBS_CMF_6));
    MEMCPY_AN(MMSGBBSHIS_N->BBS_CMF_7, MMSGBBSHIS->BBS_CMF_7, sizeof(MMSGBBSHIS->BBS_CMF_7));
    MEMCPY_AN(MMSGBBSHIS_N->BBS_CMF_8, MMSGBBSHIS->BBS_CMF_8, sizeof(MMSGBBSHIS->BBS_CMF_8));
    MEMCPY_AN(MMSGBBSHIS_N->BBS_CMF_9, MMSGBBSHIS->BBS_CMF_9, sizeof(MMSGBBSHIS->BBS_CMF_9));
    MEMCPY_AN(MMSGBBSHIS_N->BBS_CMF_10, MMSGBBSHIS->BBS_CMF_10, sizeof(MMSGBBSHIS->BBS_CMF_10));
    MMSGBBSHIS_N->REPLY_COUNT = MMSGBBSHIS->REPLY_COUNT;
    MMSGBBSHIS_N->DELETE_FLAG[0] = MMSGBBSHIS->DELETE_FLAG;
    MEMCPY_AN(MMSGBBSHIS_N->CREATE_USER_ID, MMSGBBSHIS->CREATE_USER_ID, sizeof(MMSGBBSHIS->CREATE_USER_ID));
    MEMCPY_AN(MMSGBBSHIS_N->CREATE_TIME, MMSGBBSHIS->CREATE_TIME, sizeof(MMSGBBSHIS->CREATE_TIME));
    MEMCPY_AN(MMSGBBSHIS_N->UPDATE_USER_ID, MMSGBBSHIS->UPDATE_USER_ID, sizeof(MMSGBBSHIS->UPDATE_USER_ID));
    MEMCPY_AN(MMSGBBSHIS_N->UPDATE_TIME, MMSGBBSHIS->UPDATE_TIME, sizeof(MMSGBBSHIS->UPDATE_TIME));
    MMSGBBSHIS_N->SYS_MSG_FLAG[0] = MMSGBBSHIS->SYS_MSG_FLAG;
    MMSGBBSHIS_N->POPUP_CYCLE[0] = MMSGBBSHIS->POPUP_CYCLE;
    MMSGBBSHIS_N->PRIORITY[0] = MMSGBBSHIS->PRIORITY;
    MMSGBBSHIS_N->APPLY_SHIFT[0] = MMSGBBSHIS->APPLY_SHIFT;
    MEMCPY_AN(MMSGBBSHIS_N->APPLY_START_TIME, MMSGBBSHIS->APPLY_START_TIME, sizeof(MMSGBBSHIS->APPLY_START_TIME));
    MEMCPY_AN(MMSGBBSHIS_N->APPLY_END_TIME, MMSGBBSHIS->APPLY_END_TIME, sizeof(MMSGBBSHIS->APPLY_END_TIME));
    MEMCPY_AN(MMSGBBSHIS_N->AREA_ID, MMSGBBSHIS->AREA_ID, sizeof(MMSGBBSHIS->AREA_ID));
    MEMCPY_AN(MMSGBBSHIS_N->SUB_AREA_ID, MMSGBBSHIS->SUB_AREA_ID, sizeof(MMSGBBSHIS->SUB_AREA_ID));
    MEMCPY_AN(MMSGBBSHIS_N->RESG_ID, MMSGBBSHIS->RESG_ID, sizeof(MMSGBBSHIS->RESG_ID));
    MEMCPY_AN(MMSGBBSHIS_N->MAT_ID, MMSGBBSHIS->MAT_ID, sizeof(MMSGBBSHIS->MAT_ID));
    MEMCPY_AN(MMSGBBSHIS_N->FLOW, MMSGBBSHIS->FLOW, sizeof(MMSGBBSHIS->FLOW));
    MEMCPY_AN(MMSGBBSHIS_N->RCV_USER_ID, MMSGBBSHIS->RCV_USER_ID, sizeof(MMSGBBSHIS->RCV_USER_ID));
    MEMCPY_AN(MMSGBBSHIS_N->SEC_GRP_ID, MMSGBBSHIS->SEC_GRP_ID, sizeof(MMSGBBSHIS->SEC_GRP_ID));
    MEMCPY_AN(MMSGBBSHIS_N->PRV_GRP_ID, MMSGBBSHIS->PRV_GRP_ID, sizeof(MMSGBBSHIS->PRV_GRP_ID));
    MMSGBBSHIS_N->MODAL_FLAG[0] = MMSGBBSHIS->MODAL_FLAG;
    MMSGBBSHIS_N->AUTO_CLOSE_FLAG[0] = MMSGBBSHIS->AUTO_CLOSE_FLAG;
    MMSGBBSHIS_N->AUTO_CLOSE_TIME = MMSGBBSHIS->AUTO_CLOSE_TIME;
    MMSGBBSHIS_N->ACK_FLAG[0] = MMSGBBSHIS->ACK_FLAG;
    MEMCPY_AN(MMSGBBSHIS_N->ACK_TIME, MMSGBBSHIS->ACK_TIME, sizeof(MMSGBBSHIS->ACK_TIME));
    MEMCPY_AN(MMSGBBSHIS_N->ACK_USER_ID, MMSGBBSHIS->ACK_USER_ID, sizeof(MMSGBBSHIS->ACK_USER_ID));
    MEMCPY_AN(MMSGBBSHIS_N->RCV_FACTORY, MMSGBBSHIS->RCV_FACTORY, sizeof(MMSGBBSHIS->RCV_FACTORY));

}


/* Del Null Function */
void DBC_del_null_mmsgbbshis(struct MMSGBBSHIS_N_TAG *MMSGBBSHIS_N, struct MMSGBBSHIS_TAG *MMSGBBSHIS)
{
    MEMCPY_DN(MMSGBBSHIS->FACTORY, MMSGBBSHIS_N->FACTORY, sizeof(MMSGBBSHIS->FACTORY));
    MEMCPY_DN(MMSGBBSHIS->MAIN_MENU_ID, MMSGBBSHIS_N->MAIN_MENU_ID, sizeof(MMSGBBSHIS->MAIN_MENU_ID));
    MEMCPY_DN(MMSGBBSHIS->SUB_MENU_ID, MMSGBBSHIS_N->SUB_MENU_ID, sizeof(MMSGBBSHIS->SUB_MENU_ID));
    MMSGBBSHIS->BBS_SEQ = MMSGBBSHIS_N->BBS_SEQ;
    MEMCPY_DN(MMSGBBSHIS->TRAN_TIME, MMSGBBSHIS_N->TRAN_TIME, sizeof(MMSGBBSHIS->TRAN_TIME));
    MEMCPY_DN(MMSGBBSHIS->LOT_ID, MMSGBBSHIS_N->LOT_ID, sizeof(MMSGBBSHIS->LOT_ID));
    MEMCPY_DN(MMSGBBSHIS->SUBLOT_ID, MMSGBBSHIS_N->SUBLOT_ID, sizeof(MMSGBBSHIS->SUBLOT_ID));
    MEMCPY_DN(MMSGBBSHIS->OPER, MMSGBBSHIS_N->OPER, sizeof(MMSGBBSHIS->OPER));
    MEMCPY_DN(MMSGBBSHIS->RES_ID, MMSGBBSHIS_N->RES_ID, sizeof(MMSGBBSHIS->RES_ID));
    MEMCPY_DN(MMSGBBSHIS->SUBRES_ID, MMSGBBSHIS_N->SUBRES_ID, sizeof(MMSGBBSHIS->SUBRES_ID));
    MEMCPY_DN(MMSGBBSHIS->MSG_TYPE, MMSGBBSHIS_N->MSG_TYPE, sizeof(MMSGBBSHIS->MSG_TYPE));
    MEMCPY_DN(MMSGBBSHIS->MSG_TITLE, MMSGBBSHIS_N->MSG_TITLE, sizeof(MMSGBBSHIS->MSG_TITLE));
    MEMCPY_DN(MMSGBBSHIS->MSG_TAG, MMSGBBSHIS_N->MSG_TAG, sizeof(MMSGBBSHIS->MSG_TAG));
    MEMCPY_DN(MMSGBBSHIS->BBS_CMF_1, MMSGBBSHIS_N->BBS_CMF_1, sizeof(MMSGBBSHIS->BBS_CMF_1));
    MEMCPY_DN(MMSGBBSHIS->BBS_CMF_2, MMSGBBSHIS_N->BBS_CMF_2, sizeof(MMSGBBSHIS->BBS_CMF_2));
    MEMCPY_DN(MMSGBBSHIS->BBS_CMF_3, MMSGBBSHIS_N->BBS_CMF_3, sizeof(MMSGBBSHIS->BBS_CMF_3));
    MEMCPY_DN(MMSGBBSHIS->BBS_CMF_4, MMSGBBSHIS_N->BBS_CMF_4, sizeof(MMSGBBSHIS->BBS_CMF_4));
    MEMCPY_DN(MMSGBBSHIS->BBS_CMF_5, MMSGBBSHIS_N->BBS_CMF_5, sizeof(MMSGBBSHIS->BBS_CMF_5));
    MEMCPY_DN(MMSGBBSHIS->BBS_CMF_6, MMSGBBSHIS_N->BBS_CMF_6, sizeof(MMSGBBSHIS->BBS_CMF_6));
    MEMCPY_DN(MMSGBBSHIS->BBS_CMF_7, MMSGBBSHIS_N->BBS_CMF_7, sizeof(MMSGBBSHIS->BBS_CMF_7));
    MEMCPY_DN(MMSGBBSHIS->BBS_CMF_8, MMSGBBSHIS_N->BBS_CMF_8, sizeof(MMSGBBSHIS->BBS_CMF_8));
    MEMCPY_DN(MMSGBBSHIS->BBS_CMF_9, MMSGBBSHIS_N->BBS_CMF_9, sizeof(MMSGBBSHIS->BBS_CMF_9));
    MEMCPY_DN(MMSGBBSHIS->BBS_CMF_10, MMSGBBSHIS_N->BBS_CMF_10, sizeof(MMSGBBSHIS->BBS_CMF_10));
    MMSGBBSHIS->REPLY_COUNT = MMSGBBSHIS_N->REPLY_COUNT;
    MMSGBBSHIS->DELETE_FLAG = MMSGBBSHIS_N->DELETE_FLAG[0];
    MEMCPY_DN(MMSGBBSHIS->CREATE_USER_ID, MMSGBBSHIS_N->CREATE_USER_ID, sizeof(MMSGBBSHIS->CREATE_USER_ID));
    MEMCPY_DN(MMSGBBSHIS->CREATE_TIME, MMSGBBSHIS_N->CREATE_TIME, sizeof(MMSGBBSHIS->CREATE_TIME));
    MEMCPY_DN(MMSGBBSHIS->UPDATE_USER_ID, MMSGBBSHIS_N->UPDATE_USER_ID, sizeof(MMSGBBSHIS->UPDATE_USER_ID));
    MEMCPY_DN(MMSGBBSHIS->UPDATE_TIME, MMSGBBSHIS_N->UPDATE_TIME, sizeof(MMSGBBSHIS->UPDATE_TIME));
    MMSGBBSHIS->SYS_MSG_FLAG = MMSGBBSHIS_N->SYS_MSG_FLAG[0];
    MMSGBBSHIS->POPUP_CYCLE = MMSGBBSHIS_N->POPUP_CYCLE[0];
    MMSGBBSHIS->PRIORITY = MMSGBBSHIS_N->PRIORITY[0];
    MMSGBBSHIS->APPLY_SHIFT = MMSGBBSHIS_N->APPLY_SHIFT[0];
    MEMCPY_DN(MMSGBBSHIS->APPLY_START_TIME, MMSGBBSHIS_N->APPLY_START_TIME, sizeof(MMSGBBSHIS->APPLY_START_TIME));
    MEMCPY_DN(MMSGBBSHIS->APPLY_END_TIME, MMSGBBSHIS_N->APPLY_END_TIME, sizeof(MMSGBBSHIS->APPLY_END_TIME));
    MEMCPY_DN(MMSGBBSHIS->AREA_ID, MMSGBBSHIS_N->AREA_ID, sizeof(MMSGBBSHIS->AREA_ID));
    MEMCPY_DN(MMSGBBSHIS->SUB_AREA_ID, MMSGBBSHIS_N->SUB_AREA_ID, sizeof(MMSGBBSHIS->SUB_AREA_ID));
    MEMCPY_DN(MMSGBBSHIS->RESG_ID, MMSGBBSHIS_N->RESG_ID, sizeof(MMSGBBSHIS->RESG_ID));
    MEMCPY_DN(MMSGBBSHIS->MAT_ID, MMSGBBSHIS_N->MAT_ID, sizeof(MMSGBBSHIS->MAT_ID));
    MEMCPY_DN(MMSGBBSHIS->FLOW, MMSGBBSHIS_N->FLOW, sizeof(MMSGBBSHIS->FLOW));
    MEMCPY_DN(MMSGBBSHIS->RCV_USER_ID, MMSGBBSHIS_N->RCV_USER_ID, sizeof(MMSGBBSHIS->RCV_USER_ID));
    MEMCPY_DN(MMSGBBSHIS->SEC_GRP_ID, MMSGBBSHIS_N->SEC_GRP_ID, sizeof(MMSGBBSHIS->SEC_GRP_ID));
    MEMCPY_DN(MMSGBBSHIS->PRV_GRP_ID, MMSGBBSHIS_N->PRV_GRP_ID, sizeof(MMSGBBSHIS->PRV_GRP_ID));
    MMSGBBSHIS->MODAL_FLAG = MMSGBBSHIS_N->MODAL_FLAG[0];
    MMSGBBSHIS->AUTO_CLOSE_FLAG = MMSGBBSHIS_N->AUTO_CLOSE_FLAG[0];
    MMSGBBSHIS->AUTO_CLOSE_TIME = MMSGBBSHIS_N->AUTO_CLOSE_TIME;
    MMSGBBSHIS->ACK_FLAG = MMSGBBSHIS_N->ACK_FLAG[0];
    MEMCPY_DN(MMSGBBSHIS->ACK_TIME, MMSGBBSHIS_N->ACK_TIME, sizeof(MMSGBBSHIS->ACK_TIME));
    MEMCPY_DN(MMSGBBSHIS->ACK_USER_ID, MMSGBBSHIS_N->ACK_USER_ID, sizeof(MMSGBBSHIS->ACK_USER_ID));
    MEMCPY_DN(MMSGBBSHIS->RCV_FACTORY, MMSGBBSHIS_N->RCV_FACTORY, sizeof(MMSGBBSHIS->RCV_FACTORY));

}


