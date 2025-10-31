
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
    "DBC_mgcmdathis.pc"
};


static unsigned int sqlctx = 9099587;


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
            void  *sqhstv[43];
   unsigned int   sqhstl[43];
            int   sqhsts[43];
            void  *sqindv[43];
            int   sqinds[43];
   unsigned int   sqharm[43];
   unsigned int   *sqharc[43];
   unsigned short  sqadto[43];
   unsigned short  sqtdso[43];
} sqlstm = {13,43};

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
5,0,0,1,672,0,4,46,0,0,43,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1,97,0,0,1,97,0,0,1,3,0,0,
192,0,0,2,684,0,4,168,0,0,43,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,
379,0,0,3,100,0,4,293,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
410,0,0,4,92,0,4,302,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
437,0,0,5,82,0,2,339,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
464,0,0,6,63,0,2,346,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
487,0,0,7,42,0,2,352,0,0,1,1,0,1,0,1,97,0,0,
506,0,0,8,580,0,3,380,0,0,40,40,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,
681,0,0,9,820,0,3,482,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,
716,0,0,10,587,0,5,589,0,0,40,40,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
3,0,0,
891,0,0,11,0,0,17,770,0,0,1,1,0,1,0,1,97,0,0,
910,0,0,11,0,0,45,779,0,0,0,0,0,1,0,
925,0,0,11,0,0,13,808,0,0,40,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,
1100,0,0,11,0,0,15,878,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mgcmdathis.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2017-04-12 15:14:14
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
void DBC_add_null_mgcmdathis(struct MGCMDATHIS_N_TAG *MGCMDATHIS_N, struct MGCMDATHIS_TAG *MGCMDATHIS);
void DBC_del_null_mgcmdathis(struct MGCMDATHIS_N_TAG *MGCMDATHIS_N, struct MGCMDATHIS_TAG *MGCMDATHIS);


/* SQL SELECT Function */
void DBC_select_mgcmdathis(int sel_type, struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMDATHIS_N_TAG MGCMDATHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    TABLE_NAME,
                    HIST_SEQ,
                    KEY_1,
                    KEY_2,
                    KEY_3,
                    KEY_4,
                    KEY_5,
                    KEY_6,
                    KEY_7,
                    KEY_8,
                    KEY_9,
                    KEY_10,
                    DATA_1,
                    DATA_2,
                    DATA_3,
                    DATA_4,
                    DATA_5,
                    DATA_6,
                    DATA_7,
                    DATA_8,
                    DATA_9,
                    DATA_10,
                    OLD_DATA_1,
                    OLD_DATA_2,
                    OLD_DATA_3,
                    OLD_DATA_4,
                    OLD_DATA_5,
                    OLD_DATA_6,
                    OLD_DATA_7,
                    OLD_DATA_8,
                    OLD_DATA_9,
                    OLD_DATA_10,
                    DEL_FLAG,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    TRAN_USER_ID,
                    TRAN_TIME
                INTO 
                    :MGCMDATHIS_N.FACTORY,
                    :MGCMDATHIS_N.TABLE_NAME,
                    :MGCMDATHIS_N.HIST_SEQ,
                    :MGCMDATHIS_N.KEY_1,
                    :MGCMDATHIS_N.KEY_2,
                    :MGCMDATHIS_N.KEY_3,
                    :MGCMDATHIS_N.KEY_4,
                    :MGCMDATHIS_N.KEY_5,
                    :MGCMDATHIS_N.KEY_6,
                    :MGCMDATHIS_N.KEY_7,
                    :MGCMDATHIS_N.KEY_8,
                    :MGCMDATHIS_N.KEY_9,
                    :MGCMDATHIS_N.KEY_10,
                    :MGCMDATHIS_N.DATA_1,
                    :MGCMDATHIS_N.DATA_2,
                    :MGCMDATHIS_N.DATA_3,
                    :MGCMDATHIS_N.DATA_4,
                    :MGCMDATHIS_N.DATA_5,
                    :MGCMDATHIS_N.DATA_6,
                    :MGCMDATHIS_N.DATA_7,
                    :MGCMDATHIS_N.DATA_8,
                    :MGCMDATHIS_N.DATA_9,
                    :MGCMDATHIS_N.DATA_10,
                    :MGCMDATHIS_N.OLD_DATA_1,
                    :MGCMDATHIS_N.OLD_DATA_2,
                    :MGCMDATHIS_N.OLD_DATA_3,
                    :MGCMDATHIS_N.OLD_DATA_4,
                    :MGCMDATHIS_N.OLD_DATA_5,
                    :MGCMDATHIS_N.OLD_DATA_6,
                    :MGCMDATHIS_N.OLD_DATA_7,
                    :MGCMDATHIS_N.OLD_DATA_8,
                    :MGCMDATHIS_N.OLD_DATA_9,
                    :MGCMDATHIS_N.OLD_DATA_10,
                    :MGCMDATHIS_N.DEL_FLAG,
                    :MGCMDATHIS_N.CREATE_USER_ID,
                    :MGCMDATHIS_N.CREATE_TIME,
                    :MGCMDATHIS_N.UPDATE_USER_ID,
                    :MGCMDATHIS_N.UPDATE_TIME,
                    :MGCMDATHIS_N.TRAN_USER_ID,
                    :MGCMDATHIS_N.TRAN_TIME
                FROM MGCMDATHIS
                WHERE FACTORY = :MGCMDATHIS_N.FACTORY
                    AND TABLE_NAME = :MGCMDATHIS_N.TABLE_NAME
                    AND HIST_SEQ = :MGCMDATHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,TABLE_NAME ,HIST_SEQ ,KEY_1 ,KEY\
_2 ,KEY_3 ,KEY_4 ,KEY_5 ,KEY_6 ,KEY_7 ,KEY_8 ,KEY_9 ,KEY_10 ,DATA_1 ,DATA_2 ,\
DATA_3 ,DATA_4 ,DATA_5 ,DATA_6 ,DATA_7 ,DATA_8 ,DATA_9 ,DATA_10 ,OLD_DATA_1 ,\
OLD_DATA_2 ,OLD_DATA_3 ,OLD_DATA_4 ,OLD_DATA_5 ,OLD_DATA_6 ,OLD_DATA_7 ,OLD_D\
ATA_8 ,OLD_DATA_9 ,OLD_DATA_10 ,DEL_FLAG ,CREATE_USER_ID ,CREATE_TIME ,UPDATE\
_USER_ID ,UPDATE_TIME ,TRAN_USER_ID ,TRAN_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:\
b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b\
22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37\
,:b38,:b39  from MGCMDATHIS where ((FACTORY=:b0 and TABLE_NAME=:b1) and HIST_\
SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MGCMDATHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMDATHIS_N.KEY_1);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMDATHIS_N.KEY_2);
            sqlstm.sqhstl[4] = (unsigned int  )101;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MGCMDATHIS_N.KEY_3);
            sqlstm.sqhstl[5] = (unsigned int  )101;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MGCMDATHIS_N.KEY_4);
            sqlstm.sqhstl[6] = (unsigned int  )101;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MGCMDATHIS_N.KEY_5);
            sqlstm.sqhstl[7] = (unsigned int  )101;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MGCMDATHIS_N.KEY_6);
            sqlstm.sqhstl[8] = (unsigned int  )101;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MGCMDATHIS_N.KEY_7);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MGCMDATHIS_N.KEY_8);
            sqlstm.sqhstl[10] = (unsigned int  )101;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MGCMDATHIS_N.KEY_9);
            sqlstm.sqhstl[11] = (unsigned int  )101;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MGCMDATHIS_N.KEY_10);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MGCMDATHIS_N.DATA_1);
            sqlstm.sqhstl[13] = (unsigned int  )1001;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MGCMDATHIS_N.DATA_2);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MGCMDATHIS_N.DATA_3);
            sqlstm.sqhstl[15] = (unsigned int  )1001;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MGCMDATHIS_N.DATA_4);
            sqlstm.sqhstl[16] = (unsigned int  )1001;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MGCMDATHIS_N.DATA_5);
            sqlstm.sqhstl[17] = (unsigned int  )1001;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MGCMDATHIS_N.DATA_6);
            sqlstm.sqhstl[18] = (unsigned int  )1001;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MGCMDATHIS_N.DATA_7);
            sqlstm.sqhstl[19] = (unsigned int  )1001;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MGCMDATHIS_N.DATA_8);
            sqlstm.sqhstl[20] = (unsigned int  )1001;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MGCMDATHIS_N.DATA_9);
            sqlstm.sqhstl[21] = (unsigned int  )1001;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MGCMDATHIS_N.DATA_10);
            sqlstm.sqhstl[22] = (unsigned int  )1001;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MGCMDATHIS_N.OLD_DATA_1);
            sqlstm.sqhstl[23] = (unsigned int  )1001;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MGCMDATHIS_N.OLD_DATA_2);
            sqlstm.sqhstl[24] = (unsigned int  )1001;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MGCMDATHIS_N.OLD_DATA_3);
            sqlstm.sqhstl[25] = (unsigned int  )1001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MGCMDATHIS_N.OLD_DATA_4);
            sqlstm.sqhstl[26] = (unsigned int  )1001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MGCMDATHIS_N.OLD_DATA_5);
            sqlstm.sqhstl[27] = (unsigned int  )1001;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MGCMDATHIS_N.OLD_DATA_6);
            sqlstm.sqhstl[28] = (unsigned int  )1001;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MGCMDATHIS_N.OLD_DATA_7);
            sqlstm.sqhstl[29] = (unsigned int  )1001;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MGCMDATHIS_N.OLD_DATA_8);
            sqlstm.sqhstl[30] = (unsigned int  )1001;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MGCMDATHIS_N.OLD_DATA_9);
            sqlstm.sqhstl[31] = (unsigned int  )1001;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MGCMDATHIS_N.OLD_DATA_10);
            sqlstm.sqhstl[32] = (unsigned int  )1001;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MGCMDATHIS_N.DEL_FLAG);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MGCMDATHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MGCMDATHIS_N.CREATE_TIME);
            sqlstm.sqhstl[35] = (unsigned int  )15;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MGCMDATHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MGCMDATHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[37] = (unsigned int  )15;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MGCMDATHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MGCMDATHIS_N.TRAN_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )15;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[40] = (unsigned int  )11;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MGCMDATHIS_N.HIST_SEQ);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
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
        DBC_del_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    }

    DB_stop_query_timer("DBC_select_mgcmdathis", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mgcmdathis_for_update(int sel_type, struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMDATHIS_N_TAG MGCMDATHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    TABLE_NAME,
                    HIST_SEQ,
                    KEY_1,
                    KEY_2,
                    KEY_3,
                    KEY_4,
                    KEY_5,
                    KEY_6,
                    KEY_7,
                    KEY_8,
                    KEY_9,
                    KEY_10,
                    DATA_1,
                    DATA_2,
                    DATA_3,
                    DATA_4,
                    DATA_5,
                    DATA_6,
                    DATA_7,
                    DATA_8,
                    DATA_9,
                    DATA_10,
                    OLD_DATA_1,
                    OLD_DATA_2,
                    OLD_DATA_3,
                    OLD_DATA_4,
                    OLD_DATA_5,
                    OLD_DATA_6,
                    OLD_DATA_7,
                    OLD_DATA_8,
                    OLD_DATA_9,
                    OLD_DATA_10,
                    DEL_FLAG,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    TRAN_USER_ID,
                    TRAN_TIME
                INTO 
                    :MGCMDATHIS_N.FACTORY,
                    :MGCMDATHIS_N.TABLE_NAME,
                    :MGCMDATHIS_N.HIST_SEQ,
                    :MGCMDATHIS_N.KEY_1,
                    :MGCMDATHIS_N.KEY_2,
                    :MGCMDATHIS_N.KEY_3,
                    :MGCMDATHIS_N.KEY_4,
                    :MGCMDATHIS_N.KEY_5,
                    :MGCMDATHIS_N.KEY_6,
                    :MGCMDATHIS_N.KEY_7,
                    :MGCMDATHIS_N.KEY_8,
                    :MGCMDATHIS_N.KEY_9,
                    :MGCMDATHIS_N.KEY_10,
                    :MGCMDATHIS_N.DATA_1,
                    :MGCMDATHIS_N.DATA_2,
                    :MGCMDATHIS_N.DATA_3,
                    :MGCMDATHIS_N.DATA_4,
                    :MGCMDATHIS_N.DATA_5,
                    :MGCMDATHIS_N.DATA_6,
                    :MGCMDATHIS_N.DATA_7,
                    :MGCMDATHIS_N.DATA_8,
                    :MGCMDATHIS_N.DATA_9,
                    :MGCMDATHIS_N.DATA_10,
                    :MGCMDATHIS_N.OLD_DATA_1,
                    :MGCMDATHIS_N.OLD_DATA_2,
                    :MGCMDATHIS_N.OLD_DATA_3,
                    :MGCMDATHIS_N.OLD_DATA_4,
                    :MGCMDATHIS_N.OLD_DATA_5,
                    :MGCMDATHIS_N.OLD_DATA_6,
                    :MGCMDATHIS_N.OLD_DATA_7,
                    :MGCMDATHIS_N.OLD_DATA_8,
                    :MGCMDATHIS_N.OLD_DATA_9,
                    :MGCMDATHIS_N.OLD_DATA_10,
                    :MGCMDATHIS_N.DEL_FLAG,
                    :MGCMDATHIS_N.CREATE_USER_ID,
                    :MGCMDATHIS_N.CREATE_TIME,
                    :MGCMDATHIS_N.UPDATE_USER_ID,
                    :MGCMDATHIS_N.UPDATE_TIME,
                    :MGCMDATHIS_N.TRAN_USER_ID,
                    :MGCMDATHIS_N.TRAN_TIME
                FROM MGCMDATHIS
                WHERE FACTORY = :MGCMDATHIS_N.FACTORY
                    AND TABLE_NAME = :MGCMDATHIS_N.TABLE_NAME
                    AND HIST_SEQ = :MGCMDATHIS_N.HIST_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,TABLE_NAME ,HIST_SEQ ,KEY_1 ,KEY\
_2 ,KEY_3 ,KEY_4 ,KEY_5 ,KEY_6 ,KEY_7 ,KEY_8 ,KEY_9 ,KEY_10 ,DATA_1 ,DATA_2 ,\
DATA_3 ,DATA_4 ,DATA_5 ,DATA_6 ,DATA_7 ,DATA_8 ,DATA_9 ,DATA_10 ,OLD_DATA_1 ,\
OLD_DATA_2 ,OLD_DATA_3 ,OLD_DATA_4 ,OLD_DATA_5 ,OLD_DATA_6 ,OLD_DATA_7 ,OLD_D\
ATA_8 ,OLD_DATA_9 ,OLD_DATA_10 ,DEL_FLAG ,CREATE_USER_ID ,CREATE_TIME ,UPDATE\
_USER_ID ,UPDATE_TIME ,TRAN_USER_ID ,TRAN_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:\
b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b\
22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37\
,:b38,:b39  from MGCMDATHIS where ((FACTORY=:b0 and TABLE_NAME=:b1) and HIST_\
SEQ=:b2) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )192;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MGCMDATHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMDATHIS_N.KEY_1);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMDATHIS_N.KEY_2);
            sqlstm.sqhstl[4] = (unsigned int  )101;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MGCMDATHIS_N.KEY_3);
            sqlstm.sqhstl[5] = (unsigned int  )101;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MGCMDATHIS_N.KEY_4);
            sqlstm.sqhstl[6] = (unsigned int  )101;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MGCMDATHIS_N.KEY_5);
            sqlstm.sqhstl[7] = (unsigned int  )101;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MGCMDATHIS_N.KEY_6);
            sqlstm.sqhstl[8] = (unsigned int  )101;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MGCMDATHIS_N.KEY_7);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MGCMDATHIS_N.KEY_8);
            sqlstm.sqhstl[10] = (unsigned int  )101;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MGCMDATHIS_N.KEY_9);
            sqlstm.sqhstl[11] = (unsigned int  )101;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MGCMDATHIS_N.KEY_10);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MGCMDATHIS_N.DATA_1);
            sqlstm.sqhstl[13] = (unsigned int  )1001;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MGCMDATHIS_N.DATA_2);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MGCMDATHIS_N.DATA_3);
            sqlstm.sqhstl[15] = (unsigned int  )1001;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MGCMDATHIS_N.DATA_4);
            sqlstm.sqhstl[16] = (unsigned int  )1001;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MGCMDATHIS_N.DATA_5);
            sqlstm.sqhstl[17] = (unsigned int  )1001;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MGCMDATHIS_N.DATA_6);
            sqlstm.sqhstl[18] = (unsigned int  )1001;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MGCMDATHIS_N.DATA_7);
            sqlstm.sqhstl[19] = (unsigned int  )1001;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MGCMDATHIS_N.DATA_8);
            sqlstm.sqhstl[20] = (unsigned int  )1001;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MGCMDATHIS_N.DATA_9);
            sqlstm.sqhstl[21] = (unsigned int  )1001;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MGCMDATHIS_N.DATA_10);
            sqlstm.sqhstl[22] = (unsigned int  )1001;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MGCMDATHIS_N.OLD_DATA_1);
            sqlstm.sqhstl[23] = (unsigned int  )1001;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MGCMDATHIS_N.OLD_DATA_2);
            sqlstm.sqhstl[24] = (unsigned int  )1001;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MGCMDATHIS_N.OLD_DATA_3);
            sqlstm.sqhstl[25] = (unsigned int  )1001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MGCMDATHIS_N.OLD_DATA_4);
            sqlstm.sqhstl[26] = (unsigned int  )1001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MGCMDATHIS_N.OLD_DATA_5);
            sqlstm.sqhstl[27] = (unsigned int  )1001;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MGCMDATHIS_N.OLD_DATA_6);
            sqlstm.sqhstl[28] = (unsigned int  )1001;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MGCMDATHIS_N.OLD_DATA_7);
            sqlstm.sqhstl[29] = (unsigned int  )1001;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MGCMDATHIS_N.OLD_DATA_8);
            sqlstm.sqhstl[30] = (unsigned int  )1001;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MGCMDATHIS_N.OLD_DATA_9);
            sqlstm.sqhstl[31] = (unsigned int  )1001;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MGCMDATHIS_N.OLD_DATA_10);
            sqlstm.sqhstl[32] = (unsigned int  )1001;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MGCMDATHIS_N.DEL_FLAG);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MGCMDATHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MGCMDATHIS_N.CREATE_TIME);
            sqlstm.sqhstl[35] = (unsigned int  )15;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MGCMDATHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MGCMDATHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[37] = (unsigned int  )15;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MGCMDATHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MGCMDATHIS_N.TRAN_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )15;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[40] = (unsigned int  )11;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MGCMDATHIS_N.HIST_SEQ);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
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
        DBC_del_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    }

    DB_stop_query_timer("DBC_select_mgcmdathis_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mgcmdathis_scalar(int sel_type, struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMDATHIS_N_TAG MGCMDATHIS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MGCMDATHIS
                WHERE FACTORY = :MGCMDATHIS_N.FACTORY
                    AND TABLE_NAME = :MGCMDATHIS_N.TABLE_NAME
                    AND HIST_SEQ = :MGCMDATHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MGCMDATHIS where\
 ((FACTORY=:b1 and TABLE_NAME=:b2) and HIST_SEQ=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )379;
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
            sqlstm.sqhstv[1] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MGCMDATHIS_N.HIST_SEQ);
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

        case 2:
            /* EXEC SQL SELECT NVL(MAX(HIST_SEQ), 0)
                INTO :d_value
                FROM MGCMDATHIS
                WHERE FACTORY = :MGCMDATHIS_N.FACTORY
                    AND TABLE_NAME = :MGCMDATHIS_N.TABLE_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select NVL(max(HIST_SEQ),0) into :b0  from MGCMD\
ATHIS where (FACTORY=:b1 and TABLE_NAME=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )410;
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
            sqlstm.sqhstv[1] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
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

    DB_stop_query_timer("DBC_select_mgcmdathis_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mgcmdathis(int sel_type, struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMDATHIS_N_TAG MGCMDATHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MGCMDATHIS
                WHERE FACTORY = :MGCMDATHIS_N.FACTORY
                    AND TABLE_NAME = :MGCMDATHIS_N.TABLE_NAME
                    AND HIST_SEQ = :MGCMDATHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MGCMDATHIS  where ((FACTORY=:b0 and\
 TABLE_NAME=:b1) and HIST_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )437;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MGCMDATHIS_N.HIST_SEQ);
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
            /* EXEC SQL DELETE FROM MGCMDATHIS
                WHERE FACTORY = :MGCMDATHIS_N.FACTORY
                    AND TABLE_NAME = :MGCMDATHIS_N.TABLE_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MGCMDATHIS  where (FACTORY=:b0 and \
TABLE_NAME=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )464;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
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

        case 3:
            /* EXEC SQL DELETE FROM MGCMDATHIS
                WHERE FACTORY = :MGCMDATHIS_N.FACTORY; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MGCMDATHIS  where FACTORY=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )487;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMDATHIS_N.FACTORY);
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

    DB_stop_query_timer("DBC_delete_mgcmdathis", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mgcmdathis(struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMDATHIS_N_TAG MGCMDATHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MGCMDATHIS( 
                    FACTORY, 
                    TABLE_NAME, 
                    HIST_SEQ, 
                    KEY_1, 
                    KEY_2, 
                    KEY_3, 
                    KEY_4, 
                    KEY_5, 
                    KEY_6, 
                    KEY_7, 
                    KEY_8, 
                    KEY_9, 
                    KEY_10, 
                    DATA_1, 
                    DATA_2, 
                    DATA_3, 
                    DATA_4, 
                    DATA_5, 
                    DATA_6, 
                    DATA_7, 
                    DATA_8, 
                    DATA_9, 
                    DATA_10, 
                    OLD_DATA_1, 
                    OLD_DATA_2, 
                    OLD_DATA_3, 
                    OLD_DATA_4, 
                    OLD_DATA_5, 
                    OLD_DATA_6, 
                    OLD_DATA_7, 
                    OLD_DATA_8, 
                    OLD_DATA_9, 
                    OLD_DATA_10, 
                    DEL_FLAG, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    TRAN_USER_ID, 
                    TRAN_TIME
         ) 
        VALUES (
                    :MGCMDATHIS_N.FACTORY,
                    :MGCMDATHIS_N.TABLE_NAME,
                    :MGCMDATHIS_N.HIST_SEQ,
                    :MGCMDATHIS_N.KEY_1,
                    :MGCMDATHIS_N.KEY_2,
                    :MGCMDATHIS_N.KEY_3,
                    :MGCMDATHIS_N.KEY_4,
                    :MGCMDATHIS_N.KEY_5,
                    :MGCMDATHIS_N.KEY_6,
                    :MGCMDATHIS_N.KEY_7,
                    :MGCMDATHIS_N.KEY_8,
                    :MGCMDATHIS_N.KEY_9,
                    :MGCMDATHIS_N.KEY_10,
                    :MGCMDATHIS_N.DATA_1,
                    :MGCMDATHIS_N.DATA_2,
                    :MGCMDATHIS_N.DATA_3,
                    :MGCMDATHIS_N.DATA_4,
                    :MGCMDATHIS_N.DATA_5,
                    :MGCMDATHIS_N.DATA_6,
                    :MGCMDATHIS_N.DATA_7,
                    :MGCMDATHIS_N.DATA_8,
                    :MGCMDATHIS_N.DATA_9,
                    :MGCMDATHIS_N.DATA_10,
                    :MGCMDATHIS_N.OLD_DATA_1,
                    :MGCMDATHIS_N.OLD_DATA_2,
                    :MGCMDATHIS_N.OLD_DATA_3,
                    :MGCMDATHIS_N.OLD_DATA_4,
                    :MGCMDATHIS_N.OLD_DATA_5,
                    :MGCMDATHIS_N.OLD_DATA_6,
                    :MGCMDATHIS_N.OLD_DATA_7,
                    :MGCMDATHIS_N.OLD_DATA_8,
                    :MGCMDATHIS_N.OLD_DATA_9,
                    :MGCMDATHIS_N.OLD_DATA_10,
                    :MGCMDATHIS_N.DEL_FLAG,
                    :MGCMDATHIS_N.CREATE_USER_ID,
                    :MGCMDATHIS_N.CREATE_TIME,
                    :MGCMDATHIS_N.UPDATE_USER_ID,
                    :MGCMDATHIS_N.UPDATE_TIME,
                    :MGCMDATHIS_N.TRAN_USER_ID,
                    :MGCMDATHIS_N.TRAN_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 43;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into MGCMDATHIS (FACTORY,TABLE_NAME,HIST_SEQ,KEY_\
1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_10,DATA_1,DATA_2,DATA_3\
,DATA_4,DATA_5,DATA_6,DATA_7,DATA_8,DATA_9,DATA_10,OLD_DATA_1,OLD_DATA_2,OLD_\
DATA_3,OLD_DATA_4,OLD_DATA_5,OLD_DATA_6,OLD_DATA_7,OLD_DATA_8,OLD_DATA_9,OLD_\
DATA_10,DEL_FLAG,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME,TRAN_U\
SER_ID,TRAN_TIME) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:\
b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b2\
7,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )506;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MGCMDATHIS_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(MGCMDATHIS_N.HIST_SEQ);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MGCMDATHIS_N.KEY_1);
    sqlstm.sqhstl[3] = (unsigned int  )101;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MGCMDATHIS_N.KEY_2);
    sqlstm.sqhstl[4] = (unsigned int  )101;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MGCMDATHIS_N.KEY_3);
    sqlstm.sqhstl[5] = (unsigned int  )101;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MGCMDATHIS_N.KEY_4);
    sqlstm.sqhstl[6] = (unsigned int  )101;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MGCMDATHIS_N.KEY_5);
    sqlstm.sqhstl[7] = (unsigned int  )101;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MGCMDATHIS_N.KEY_6);
    sqlstm.sqhstl[8] = (unsigned int  )101;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MGCMDATHIS_N.KEY_7);
    sqlstm.sqhstl[9] = (unsigned int  )101;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MGCMDATHIS_N.KEY_8);
    sqlstm.sqhstl[10] = (unsigned int  )101;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MGCMDATHIS_N.KEY_9);
    sqlstm.sqhstl[11] = (unsigned int  )101;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MGCMDATHIS_N.KEY_10);
    sqlstm.sqhstl[12] = (unsigned int  )101;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MGCMDATHIS_N.DATA_1);
    sqlstm.sqhstl[13] = (unsigned int  )1001;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MGCMDATHIS_N.DATA_2);
    sqlstm.sqhstl[14] = (unsigned int  )1001;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MGCMDATHIS_N.DATA_3);
    sqlstm.sqhstl[15] = (unsigned int  )1001;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MGCMDATHIS_N.DATA_4);
    sqlstm.sqhstl[16] = (unsigned int  )1001;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MGCMDATHIS_N.DATA_5);
    sqlstm.sqhstl[17] = (unsigned int  )1001;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MGCMDATHIS_N.DATA_6);
    sqlstm.sqhstl[18] = (unsigned int  )1001;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MGCMDATHIS_N.DATA_7);
    sqlstm.sqhstl[19] = (unsigned int  )1001;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MGCMDATHIS_N.DATA_8);
    sqlstm.sqhstl[20] = (unsigned int  )1001;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MGCMDATHIS_N.DATA_9);
    sqlstm.sqhstl[21] = (unsigned int  )1001;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MGCMDATHIS_N.DATA_10);
    sqlstm.sqhstl[22] = (unsigned int  )1001;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MGCMDATHIS_N.OLD_DATA_1);
    sqlstm.sqhstl[23] = (unsigned int  )1001;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MGCMDATHIS_N.OLD_DATA_2);
    sqlstm.sqhstl[24] = (unsigned int  )1001;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MGCMDATHIS_N.OLD_DATA_3);
    sqlstm.sqhstl[25] = (unsigned int  )1001;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MGCMDATHIS_N.OLD_DATA_4);
    sqlstm.sqhstl[26] = (unsigned int  )1001;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MGCMDATHIS_N.OLD_DATA_5);
    sqlstm.sqhstl[27] = (unsigned int  )1001;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MGCMDATHIS_N.OLD_DATA_6);
    sqlstm.sqhstl[28] = (unsigned int  )1001;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MGCMDATHIS_N.OLD_DATA_7);
    sqlstm.sqhstl[29] = (unsigned int  )1001;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MGCMDATHIS_N.OLD_DATA_8);
    sqlstm.sqhstl[30] = (unsigned int  )1001;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MGCMDATHIS_N.OLD_DATA_9);
    sqlstm.sqhstl[31] = (unsigned int  )1001;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MGCMDATHIS_N.OLD_DATA_10);
    sqlstm.sqhstl[32] = (unsigned int  )1001;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MGCMDATHIS_N.DEL_FLAG);
    sqlstm.sqhstl[33] = (unsigned int  )2;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MGCMDATHIS_N.CREATE_USER_ID);
    sqlstm.sqhstl[34] = (unsigned int  )21;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MGCMDATHIS_N.CREATE_TIME);
    sqlstm.sqhstl[35] = (unsigned int  )15;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MGCMDATHIS_N.UPDATE_USER_ID);
    sqlstm.sqhstl[36] = (unsigned int  )21;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MGCMDATHIS_N.UPDATE_TIME);
    sqlstm.sqhstl[37] = (unsigned int  )15;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MGCMDATHIS_N.TRAN_USER_ID);
    sqlstm.sqhstl[38] = (unsigned int  )21;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MGCMDATHIS_N.TRAN_TIME);
    sqlstm.sqhstl[39] = (unsigned int  )15;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
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



    DB_stop_query_timer("DBC_insert_mgcmdathis", 0);
}

void DBC_select_insert_mgcmdathis(int sel_type, struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMDATHIS_N_TAG MGCMDATHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL INSERT INTO MGCMDATHIS (
                    FACTORY, 
                    TABLE_NAME, 
                    HIST_SEQ, 
                    KEY_1, 
                    KEY_2, 
                    KEY_3, 
                    KEY_4, 
                    KEY_5, 
                    KEY_6, 
                    KEY_7, 
                    KEY_8, 
                    KEY_9, 
                    KEY_10, 
                    DATA_1, 
                    DATA_2, 
                    DATA_3, 
                    DATA_4, 
                    DATA_5, 
                    DATA_6, 
                    DATA_7, 
                    DATA_8, 
                    DATA_9, 
                    DATA_10, 
                    OLD_DATA_1, 
                    OLD_DATA_2, 
                    OLD_DATA_3, 
                    OLD_DATA_4, 
                    OLD_DATA_5, 
                    OLD_DATA_6, 
                    OLD_DATA_7, 
                    OLD_DATA_8, 
                    OLD_DATA_9, 
                    OLD_DATA_10, 
                    DEL_FLAG, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    TRAN_USER_ID, 
                    TRAN_TIME)
                SELECT 
                    :DBC_Q_COND_N.KEY_1, 
                    TABLE_NAME, 
                    HIST_SEQ, 
                    KEY_1, 
                    KEY_2, 
                    KEY_3, 
                    KEY_4, 
                    KEY_5, 
                    KEY_6, 
                    KEY_7, 
                    KEY_8, 
                    KEY_9, 
                    KEY_10, 
                    DATA_1, 
                    DATA_2, 
                    DATA_3, 
                    DATA_4, 
                    DATA_5, 
                    DATA_6, 
                    DATA_7, 
                    DATA_8, 
                    DATA_9, 
                    DATA_10, 
                    OLD_DATA_1, 
                    OLD_DATA_2, 
                    OLD_DATA_3, 
                    OLD_DATA_4, 
                    OLD_DATA_5, 
                    OLD_DATA_6, 
                    OLD_DATA_7, 
                    OLD_DATA_8, 
                    OLD_DATA_9, 
                    OLD_DATA_10, 
                    DEL_FLAG, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    :DBC_Q_COND_N.KEY_2, 
                    :DBC_Q_COND_N.KEY_3
                FROM MGCMDATHIS
                WHERE FACTORY = :MGCMDATHIS_N.FACTORY
                  AND TABLE_NAME = :MGCMDATHIS_N.TABLE_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "insert into MGCMDATHIS (FACTORY,TABLE_NAME,HIST_\
SEQ,KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_10,DATA_1,DATA_\
2,DATA_3,DATA_4,DATA_5,DATA_6,DATA_7,DATA_8,DATA_9,DATA_10,OLD_DATA_1,OLD_DAT\
A_2,OLD_DATA_3,OLD_DATA_4,OLD_DATA_5,OLD_DATA_6,OLD_DATA_7,OLD_DATA_8,OLD_DAT\
A_9,OLD_DATA_10,DEL_FLAG,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIM\
E,TRAN_USER_ID,TRAN_TIME)select :b0 ,TABLE_NAME ,HIST_SEQ ,KEY_1 ,KEY_2 ,KEY_\
3 ,KEY_4 ,KEY_5 ,KEY_6 ,KEY_7 ,KEY_8 ,KEY_9 ,KEY_10 ,DATA_1 ,DATA_2 ,DATA_3 ,\
DATA_4 ,DATA_5 ,DATA_6 ,DATA_7 ,DATA_8 ,DATA_9 ,DATA_10 ,OLD_DATA_1 ,OLD_DATA\
_2 ,OLD_DATA_3 ,OLD_DATA_4 ,OLD_DATA_5 ,OLD_DATA_6 ,OLD_DATA_7 ,OLD_DATA_8 ,O\
LD_DATA_9 ,OLD_DATA_10 ,DEL_FLAG ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID\
 ,UPDATE_TIME ,:b1 ,:b2  from MGCMDATHIS where (FACTORY=:b3 and TABLE_NAME=:b\
4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )681;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(DBC_Q_COND_N.KEY_1);
            sqlstm.sqhstl[0] = (unsigned int  )51;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(DBC_Q_COND_N.KEY_2);
            sqlstm.sqhstl[1] = (unsigned int  )51;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(DBC_Q_COND_N.KEY_3);
            sqlstm.sqhstl[2] = (unsigned int  )51;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
            sqlstm.sqhstl[4] = (unsigned int  )21;
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
        }

    DB_stop_query_timer("DBC_select_insert_mgcmdathis", 0);
}

/* SQL UPDATE Function */
void DBC_update_mgcmdathis(int sel_type, struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMDATHIS_N_TAG MGCMDATHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MGCMDATHIS SET
                    KEY_1 = :MGCMDATHIS_N.KEY_1,
                    KEY_2 = :MGCMDATHIS_N.KEY_2,
                    KEY_3 = :MGCMDATHIS_N.KEY_3,
                    KEY_4 = :MGCMDATHIS_N.KEY_4,
                    KEY_5 = :MGCMDATHIS_N.KEY_5,
                    KEY_6 = :MGCMDATHIS_N.KEY_6,
                    KEY_7 = :MGCMDATHIS_N.KEY_7,
                    KEY_8 = :MGCMDATHIS_N.KEY_8,
                    KEY_9 = :MGCMDATHIS_N.KEY_9,
                    KEY_10 = :MGCMDATHIS_N.KEY_10,
                    DATA_1 = :MGCMDATHIS_N.DATA_1,
                    DATA_2 = :MGCMDATHIS_N.DATA_2,
                    DATA_3 = :MGCMDATHIS_N.DATA_3,
                    DATA_4 = :MGCMDATHIS_N.DATA_4,
                    DATA_5 = :MGCMDATHIS_N.DATA_5,
                    DATA_6 = :MGCMDATHIS_N.DATA_6,
                    DATA_7 = :MGCMDATHIS_N.DATA_7,
                    DATA_8 = :MGCMDATHIS_N.DATA_8,
                    DATA_9 = :MGCMDATHIS_N.DATA_9,
                    DATA_10 = :MGCMDATHIS_N.DATA_10,
                    OLD_DATA_1 = :MGCMDATHIS_N.OLD_DATA_1,
                    OLD_DATA_2 = :MGCMDATHIS_N.OLD_DATA_2,
                    OLD_DATA_3 = :MGCMDATHIS_N.OLD_DATA_3,
                    OLD_DATA_4 = :MGCMDATHIS_N.OLD_DATA_4,
                    OLD_DATA_5 = :MGCMDATHIS_N.OLD_DATA_5,
                    OLD_DATA_6 = :MGCMDATHIS_N.OLD_DATA_6,
                    OLD_DATA_7 = :MGCMDATHIS_N.OLD_DATA_7,
                    OLD_DATA_8 = :MGCMDATHIS_N.OLD_DATA_8,
                    OLD_DATA_9 = :MGCMDATHIS_N.OLD_DATA_9,
                    OLD_DATA_10 = :MGCMDATHIS_N.OLD_DATA_10,
                    DEL_FLAG = :MGCMDATHIS_N.DEL_FLAG,
                    CREATE_USER_ID = :MGCMDATHIS_N.CREATE_USER_ID,
                    CREATE_TIME = :MGCMDATHIS_N.CREATE_TIME,
                    UPDATE_USER_ID = :MGCMDATHIS_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MGCMDATHIS_N.UPDATE_TIME,
                    TRAN_USER_ID = :MGCMDATHIS_N.TRAN_USER_ID,
                    TRAN_TIME = :MGCMDATHIS_N.TRAN_TIME
                WHERE FACTORY = :MGCMDATHIS_N.FACTORY
                    AND TABLE_NAME = :MGCMDATHIS_N.TABLE_NAME
                    AND HIST_SEQ = :MGCMDATHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MGCMDATHIS  set KEY_1=:b0,KEY_2=:b1,KEY_3\
=:b2,KEY_4=:b3,KEY_5=:b4,KEY_6=:b5,KEY_7=:b6,KEY_8=:b7,KEY_9=:b8,KEY_10=:b9,D\
ATA_1=:b10,DATA_2=:b11,DATA_3=:b12,DATA_4=:b13,DATA_5=:b14,DATA_6=:b15,DATA_7\
=:b16,DATA_8=:b17,DATA_9=:b18,DATA_10=:b19,OLD_DATA_1=:b20,OLD_DATA_2=:b21,OL\
D_DATA_3=:b22,OLD_DATA_4=:b23,OLD_DATA_5=:b24,OLD_DATA_6=:b25,OLD_DATA_7=:b26\
,OLD_DATA_8=:b27,OLD_DATA_9=:b28,OLD_DATA_10=:b29,DEL_FLAG=:b30,CREATE_USER_I\
D=:b31,CREATE_TIME=:b32,UPDATE_USER_ID=:b33,UPDATE_TIME=:b34,TRAN_USER_ID=:b3\
5,TRAN_TIME=:b36 where ((FACTORY=:b37 and TABLE_NAME=:b38) and HIST_SEQ=:b39)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )716;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMDATHIS_N.KEY_1);
            sqlstm.sqhstl[0] = (unsigned int  )101;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMDATHIS_N.KEY_2);
            sqlstm.sqhstl[1] = (unsigned int  )101;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMDATHIS_N.KEY_3);
            sqlstm.sqhstl[2] = (unsigned int  )101;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMDATHIS_N.KEY_4);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMDATHIS_N.KEY_5);
            sqlstm.sqhstl[4] = (unsigned int  )101;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MGCMDATHIS_N.KEY_6);
            sqlstm.sqhstl[5] = (unsigned int  )101;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MGCMDATHIS_N.KEY_7);
            sqlstm.sqhstl[6] = (unsigned int  )101;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MGCMDATHIS_N.KEY_8);
            sqlstm.sqhstl[7] = (unsigned int  )101;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MGCMDATHIS_N.KEY_9);
            sqlstm.sqhstl[8] = (unsigned int  )101;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MGCMDATHIS_N.KEY_10);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MGCMDATHIS_N.DATA_1);
            sqlstm.sqhstl[10] = (unsigned int  )1001;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MGCMDATHIS_N.DATA_2);
            sqlstm.sqhstl[11] = (unsigned int  )1001;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MGCMDATHIS_N.DATA_3);
            sqlstm.sqhstl[12] = (unsigned int  )1001;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MGCMDATHIS_N.DATA_4);
            sqlstm.sqhstl[13] = (unsigned int  )1001;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MGCMDATHIS_N.DATA_5);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MGCMDATHIS_N.DATA_6);
            sqlstm.sqhstl[15] = (unsigned int  )1001;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MGCMDATHIS_N.DATA_7);
            sqlstm.sqhstl[16] = (unsigned int  )1001;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MGCMDATHIS_N.DATA_8);
            sqlstm.sqhstl[17] = (unsigned int  )1001;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MGCMDATHIS_N.DATA_9);
            sqlstm.sqhstl[18] = (unsigned int  )1001;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MGCMDATHIS_N.DATA_10);
            sqlstm.sqhstl[19] = (unsigned int  )1001;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MGCMDATHIS_N.OLD_DATA_1);
            sqlstm.sqhstl[20] = (unsigned int  )1001;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MGCMDATHIS_N.OLD_DATA_2);
            sqlstm.sqhstl[21] = (unsigned int  )1001;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MGCMDATHIS_N.OLD_DATA_3);
            sqlstm.sqhstl[22] = (unsigned int  )1001;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MGCMDATHIS_N.OLD_DATA_4);
            sqlstm.sqhstl[23] = (unsigned int  )1001;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MGCMDATHIS_N.OLD_DATA_5);
            sqlstm.sqhstl[24] = (unsigned int  )1001;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MGCMDATHIS_N.OLD_DATA_6);
            sqlstm.sqhstl[25] = (unsigned int  )1001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MGCMDATHIS_N.OLD_DATA_7);
            sqlstm.sqhstl[26] = (unsigned int  )1001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MGCMDATHIS_N.OLD_DATA_8);
            sqlstm.sqhstl[27] = (unsigned int  )1001;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MGCMDATHIS_N.OLD_DATA_9);
            sqlstm.sqhstl[28] = (unsigned int  )1001;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MGCMDATHIS_N.OLD_DATA_10);
            sqlstm.sqhstl[29] = (unsigned int  )1001;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MGCMDATHIS_N.DEL_FLAG);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MGCMDATHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MGCMDATHIS_N.CREATE_TIME);
            sqlstm.sqhstl[32] = (unsigned int  )15;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MGCMDATHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MGCMDATHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[34] = (unsigned int  )15;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MGCMDATHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MGCMDATHIS_N.TRAN_TIME);
            sqlstm.sqhstl[36] = (unsigned int  )15;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[37] = (unsigned int  )11;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(MGCMDATHIS_N.HIST_SEQ);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
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

    DB_stop_query_timer("DBC_update_mgcmdathis", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mgcmdathis(int sel_type, struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMDATHIS_N_TAG MGCMDATHIS_N;
        char sql[5120];
        char ts[1000];
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    memset(sql, 0x00, sizeof(sql));
    memset(ts, 0x00, sizeof(ts));

    DBC_add_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            sprintf(sql,               "SELECT ");
            sprintf(sql + strlen(sql),   "FACTORY, ");
            sprintf(sql + strlen(sql),   "TABLE_NAME, ");
            sprintf(sql + strlen(sql),   "HIST_SEQ, ");
            sprintf(sql + strlen(sql),   "KEY_1, ");
            sprintf(sql + strlen(sql),   "KEY_2, ");
            sprintf(sql + strlen(sql),   "KEY_3, ");
            sprintf(sql + strlen(sql),   "KEY_4, ");
            sprintf(sql + strlen(sql),   "KEY_5, ");
            sprintf(sql + strlen(sql),   "KEY_6, ");
            sprintf(sql + strlen(sql),   "KEY_7, ");
            sprintf(sql + strlen(sql),   "KEY_8, ");
            sprintf(sql + strlen(sql),   "KEY_9, ");
            sprintf(sql + strlen(sql),   "KEY_10, ");
            sprintf(sql + strlen(sql),   "DATA_1, ");
            sprintf(sql + strlen(sql),   "DATA_2, ");
            sprintf(sql + strlen(sql),   "DATA_3, ");
            sprintf(sql + strlen(sql),   "DATA_4, ");
            sprintf(sql + strlen(sql),   "DATA_5, ");
            sprintf(sql + strlen(sql),   "DATA_6, ");
            sprintf(sql + strlen(sql),   "DATA_7, ");
            sprintf(sql + strlen(sql),   "DATA_8, ");
            sprintf(sql + strlen(sql),   "DATA_9, ");
            sprintf(sql + strlen(sql),   "DATA_10, ");
            sprintf(sql + strlen(sql),   "OLD_DATA_1, ");
            sprintf(sql + strlen(sql),   "OLD_DATA_2, ");
            sprintf(sql + strlen(sql),   "OLD_DATA_3, ");
            sprintf(sql + strlen(sql),   "OLD_DATA_4, ");
            sprintf(sql + strlen(sql),   "OLD_DATA_5, ");
            sprintf(sql + strlen(sql),   "OLD_DATA_6, ");
            sprintf(sql + strlen(sql),   "OLD_DATA_7, ");
            sprintf(sql + strlen(sql),   "OLD_DATA_8, ");
            sprintf(sql + strlen(sql),   "OLD_DATA_9, ");
            sprintf(sql + strlen(sql),   "OLD_DATA_10, ");
            sprintf(sql + strlen(sql),   "DEL_FLAG, ");
            sprintf(sql + strlen(sql),   "CREATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "UPDATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "UPDATE_TIME, ");
            sprintf(sql + strlen(sql),   "TRAN_USER_ID, ");
            sprintf(sql + strlen(sql),   "TRAN_TIME ");
            sprintf(sql + strlen(sql), "FROM MGCMDATHIS WHERE ");
            make_valid_quote(ts, MGCMDATHIS_N.FACTORY);
            sprintf(sql + strlen(sql), "FACTORY='%s'",ts);                       
            make_valid_quote(ts, DBC_Q_COND_N.FROM_TIME);
            sprintf(sql + strlen(sql), "  AND TRAN_TIME >='%s'",ts);
            make_valid_quote(ts, DBC_Q_COND_N.TO_TIME);
            sprintf(sql + strlen(sql), "  AND TRAN_TIME <='%s'",ts); 
            make_valid_quote(ts, MGCMDATHIS_N.TABLE_NAME);
            sprintf(sql + strlen(sql), "  AND TABLE_NAME ='%s'",ts); 
            sprintf(sql + strlen(sql), "  AND HIST_SEQ <=%d", MGCMDATHIS_N.HIST_SEQ); 

            if(ISSPACE(MGCMDATHIS->KEY_1, sizeof(MGCMDATHIS->KEY_1)) == DB_FALSE)
            {
                make_valid_quote(ts, MGCMDATHIS_N.KEY_1);
                sprintf(sql + strlen(sql), "  AND KEY_1 ='%s'",ts);
            }
            if(ISSPACE(MGCMDATHIS->KEY_2, sizeof(MGCMDATHIS->KEY_2)) == DB_FALSE)
            {
                make_valid_quote(ts, MGCMDATHIS_N.KEY_2);
                sprintf(sql + strlen(sql), "  AND KEY_2 ='%s'",ts);
            }
            if(ISSPACE(MGCMDATHIS->KEY_3, sizeof(MGCMDATHIS->KEY_3)) == DB_FALSE)
            {
                make_valid_quote(ts, MGCMDATHIS_N.KEY_3);
                sprintf(sql + strlen(sql), "  AND KEY_3 ='%s'",ts);
            }
            if(ISSPACE(MGCMDATHIS->KEY_4, sizeof(MGCMDATHIS->KEY_4)) == DB_FALSE)
            {
                make_valid_quote(ts, MGCMDATHIS_N.KEY_4);
                sprintf(sql + strlen(sql), "  AND KEY_4 ='%s'",ts);
            }
            if(ISSPACE(MGCMDATHIS->KEY_5, sizeof(MGCMDATHIS->KEY_5)) == DB_FALSE)
            {
                make_valid_quote(ts, MGCMDATHIS_N.KEY_5);
                sprintf(sql + strlen(sql), "  AND KEY_5 ='%s'",ts);
            }
            if(ISSPACE(MGCMDATHIS->KEY_6, sizeof(MGCMDATHIS->KEY_6)) == DB_FALSE)
            {
                make_valid_quote(ts, MGCMDATHIS_N.KEY_6);
                sprintf(sql + strlen(sql), "  AND KEY_6 ='%s'",ts);
            }
            if(ISSPACE(MGCMDATHIS->KEY_7, sizeof(MGCMDATHIS->KEY_7)) == DB_FALSE)
            {
                make_valid_quote(ts, MGCMDATHIS_N.KEY_7);
                sprintf(sql + strlen(sql), "  AND KEY_7 ='%s'",ts);
            }
            if(ISSPACE(MGCMDATHIS->KEY_8, sizeof(MGCMDATHIS->KEY_8)) == DB_FALSE)
            {
                make_valid_quote(ts, MGCMDATHIS_N.KEY_8);
                sprintf(sql + strlen(sql), "  AND KEY_8 ='%s'",ts);
            }
            if(ISSPACE(MGCMDATHIS->KEY_9, sizeof(MGCMDATHIS->KEY_9)) == DB_FALSE)
            {
                make_valid_quote(ts, MGCMDATHIS_N.KEY_9);
                sprintf(sql + strlen(sql), "  AND KEY_9 ='%s'",ts);
            }
            if(ISSPACE(MGCMDATHIS->KEY_10, sizeof(MGCMDATHIS->KEY_10)) == DB_FALSE)
            {
                make_valid_quote(ts, MGCMDATHIS_N.KEY_10);
                sprintf(sql + strlen(sql), "  AND KEY_10 ='%s'",ts);
            }
            
            sprintf(sql + strlen(sql), " ORDER BY HIST_SEQ DESC");
 
            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )891;
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


            
            
            /*LOG_head("DB");
            LOG_add("len", 1, strlen(sql));
            LOG_add("sql", 4, strlen(sql), sql);
            COM_log_write('I', 'S' , 'S');*/

            /* EXEC SQL DECLARE DBC_MGCMDATHIS_CUR_1 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_MGCMDATHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )910;
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

    DB_stop_query_timer("DBC_open_mgcmdathis", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mgcmdathis(int sel_type, struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMDATHIS_N_TAG MGCMDATHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MGCMDATHIS_CUR_1 INTO
                :MGCMDATHIS_N.FACTORY,
                :MGCMDATHIS_N.TABLE_NAME,
                :MGCMDATHIS_N.HIST_SEQ,
                :MGCMDATHIS_N.KEY_1,
                :MGCMDATHIS_N.KEY_2,
                :MGCMDATHIS_N.KEY_3,
                :MGCMDATHIS_N.KEY_4,
                :MGCMDATHIS_N.KEY_5,
                :MGCMDATHIS_N.KEY_6,
                :MGCMDATHIS_N.KEY_7,
                :MGCMDATHIS_N.KEY_8,
                :MGCMDATHIS_N.KEY_9,
                :MGCMDATHIS_N.KEY_10,
                :MGCMDATHIS_N.DATA_1,
                :MGCMDATHIS_N.DATA_2,
                :MGCMDATHIS_N.DATA_3,
                :MGCMDATHIS_N.DATA_4,
                :MGCMDATHIS_N.DATA_5,
                :MGCMDATHIS_N.DATA_6,
                :MGCMDATHIS_N.DATA_7,
                :MGCMDATHIS_N.DATA_8,
                :MGCMDATHIS_N.DATA_9,
                :MGCMDATHIS_N.DATA_10,
                :MGCMDATHIS_N.OLD_DATA_1,
                :MGCMDATHIS_N.OLD_DATA_2,
                :MGCMDATHIS_N.OLD_DATA_3,
                :MGCMDATHIS_N.OLD_DATA_4,
                :MGCMDATHIS_N.OLD_DATA_5,
                :MGCMDATHIS_N.OLD_DATA_6,
                :MGCMDATHIS_N.OLD_DATA_7,
                :MGCMDATHIS_N.OLD_DATA_8,
                :MGCMDATHIS_N.OLD_DATA_9,
                :MGCMDATHIS_N.OLD_DATA_10,
                :MGCMDATHIS_N.DEL_FLAG,
                :MGCMDATHIS_N.CREATE_USER_ID,
                :MGCMDATHIS_N.CREATE_TIME,
                :MGCMDATHIS_N.UPDATE_USER_ID,
                :MGCMDATHIS_N.UPDATE_TIME,
                :MGCMDATHIS_N.TRAN_USER_ID,
                :MGCMDATHIS_N.TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )925;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MGCMDATHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMDATHIS_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MGCMDATHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMDATHIS_N.KEY_1);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMDATHIS_N.KEY_2);
            sqlstm.sqhstl[4] = (unsigned int  )101;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MGCMDATHIS_N.KEY_3);
            sqlstm.sqhstl[5] = (unsigned int  )101;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MGCMDATHIS_N.KEY_4);
            sqlstm.sqhstl[6] = (unsigned int  )101;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MGCMDATHIS_N.KEY_5);
            sqlstm.sqhstl[7] = (unsigned int  )101;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MGCMDATHIS_N.KEY_6);
            sqlstm.sqhstl[8] = (unsigned int  )101;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MGCMDATHIS_N.KEY_7);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MGCMDATHIS_N.KEY_8);
            sqlstm.sqhstl[10] = (unsigned int  )101;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MGCMDATHIS_N.KEY_9);
            sqlstm.sqhstl[11] = (unsigned int  )101;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MGCMDATHIS_N.KEY_10);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MGCMDATHIS_N.DATA_1);
            sqlstm.sqhstl[13] = (unsigned int  )1001;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MGCMDATHIS_N.DATA_2);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MGCMDATHIS_N.DATA_3);
            sqlstm.sqhstl[15] = (unsigned int  )1001;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MGCMDATHIS_N.DATA_4);
            sqlstm.sqhstl[16] = (unsigned int  )1001;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MGCMDATHIS_N.DATA_5);
            sqlstm.sqhstl[17] = (unsigned int  )1001;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MGCMDATHIS_N.DATA_6);
            sqlstm.sqhstl[18] = (unsigned int  )1001;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MGCMDATHIS_N.DATA_7);
            sqlstm.sqhstl[19] = (unsigned int  )1001;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MGCMDATHIS_N.DATA_8);
            sqlstm.sqhstl[20] = (unsigned int  )1001;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MGCMDATHIS_N.DATA_9);
            sqlstm.sqhstl[21] = (unsigned int  )1001;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MGCMDATHIS_N.DATA_10);
            sqlstm.sqhstl[22] = (unsigned int  )1001;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MGCMDATHIS_N.OLD_DATA_1);
            sqlstm.sqhstl[23] = (unsigned int  )1001;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MGCMDATHIS_N.OLD_DATA_2);
            sqlstm.sqhstl[24] = (unsigned int  )1001;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MGCMDATHIS_N.OLD_DATA_3);
            sqlstm.sqhstl[25] = (unsigned int  )1001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MGCMDATHIS_N.OLD_DATA_4);
            sqlstm.sqhstl[26] = (unsigned int  )1001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MGCMDATHIS_N.OLD_DATA_5);
            sqlstm.sqhstl[27] = (unsigned int  )1001;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MGCMDATHIS_N.OLD_DATA_6);
            sqlstm.sqhstl[28] = (unsigned int  )1001;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MGCMDATHIS_N.OLD_DATA_7);
            sqlstm.sqhstl[29] = (unsigned int  )1001;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MGCMDATHIS_N.OLD_DATA_8);
            sqlstm.sqhstl[30] = (unsigned int  )1001;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MGCMDATHIS_N.OLD_DATA_9);
            sqlstm.sqhstl[31] = (unsigned int  )1001;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MGCMDATHIS_N.OLD_DATA_10);
            sqlstm.sqhstl[32] = (unsigned int  )1001;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MGCMDATHIS_N.DEL_FLAG);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MGCMDATHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MGCMDATHIS_N.CREATE_TIME);
            sqlstm.sqhstl[35] = (unsigned int  )15;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MGCMDATHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MGCMDATHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[37] = (unsigned int  )15;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MGCMDATHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MGCMDATHIS_N.TRAN_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )15;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
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
        DBC_del_null_mgcmdathis(&MGCMDATHIS_N, MGCMDATHIS);
    }

    DB_stop_query_timer("DBC_fetch_mgcmdathis", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mgcmdathis(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MGCMDATHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1100;
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

    DB_stop_query_timer("DBC_close_mgcmdathis", sel_type);
}


/* Initialize Function */
void DBC_init_mgcmdathis(struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* memset by Space */
    memset(MGCMDATHIS, ' ', sizeof(struct MGCMDATHIS_TAG));
    
    MGCMDATHIS->HIST_SEQ = 0;
}


/* Add Null Function */
void DBC_add_null_mgcmdathis(struct MGCMDATHIS_N_TAG *MGCMDATHIS_N, struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    /* memset by NULL */
    memset(MGCMDATHIS_N, '\0', sizeof(struct MGCMDATHIS_N_TAG));
    
    MEMCPY_AN(MGCMDATHIS_N->FACTORY, MGCMDATHIS->FACTORY, sizeof(MGCMDATHIS->FACTORY));
    MEMCPY_AN(MGCMDATHIS_N->TABLE_NAME, MGCMDATHIS->TABLE_NAME, sizeof(MGCMDATHIS->TABLE_NAME));
    MGCMDATHIS_N->HIST_SEQ = MGCMDATHIS->HIST_SEQ;
    MEMCPY_AN(MGCMDATHIS_N->KEY_1, MGCMDATHIS->KEY_1, sizeof(MGCMDATHIS->KEY_1));
    MEMCPY_AN(MGCMDATHIS_N->KEY_2, MGCMDATHIS->KEY_2, sizeof(MGCMDATHIS->KEY_2));
    MEMCPY_AN(MGCMDATHIS_N->KEY_3, MGCMDATHIS->KEY_3, sizeof(MGCMDATHIS->KEY_3));
    MEMCPY_AN(MGCMDATHIS_N->KEY_4, MGCMDATHIS->KEY_4, sizeof(MGCMDATHIS->KEY_4));
    MEMCPY_AN(MGCMDATHIS_N->KEY_5, MGCMDATHIS->KEY_5, sizeof(MGCMDATHIS->KEY_5));
    MEMCPY_AN(MGCMDATHIS_N->KEY_6, MGCMDATHIS->KEY_6, sizeof(MGCMDATHIS->KEY_6));
    MEMCPY_AN(MGCMDATHIS_N->KEY_7, MGCMDATHIS->KEY_7, sizeof(MGCMDATHIS->KEY_7));
    MEMCPY_AN(MGCMDATHIS_N->KEY_8, MGCMDATHIS->KEY_8, sizeof(MGCMDATHIS->KEY_8));
    MEMCPY_AN(MGCMDATHIS_N->KEY_9, MGCMDATHIS->KEY_9, sizeof(MGCMDATHIS->KEY_9));
    MEMCPY_AN(MGCMDATHIS_N->KEY_10, MGCMDATHIS->KEY_10, sizeof(MGCMDATHIS->KEY_10));
    MEMCPY_AN(MGCMDATHIS_N->DATA_1, MGCMDATHIS->DATA_1, sizeof(MGCMDATHIS->DATA_1));
    MEMCPY_AN(MGCMDATHIS_N->DATA_2, MGCMDATHIS->DATA_2, sizeof(MGCMDATHIS->DATA_2));
    MEMCPY_AN(MGCMDATHIS_N->DATA_3, MGCMDATHIS->DATA_3, sizeof(MGCMDATHIS->DATA_3));
    MEMCPY_AN(MGCMDATHIS_N->DATA_4, MGCMDATHIS->DATA_4, sizeof(MGCMDATHIS->DATA_4));
    MEMCPY_AN(MGCMDATHIS_N->DATA_5, MGCMDATHIS->DATA_5, sizeof(MGCMDATHIS->DATA_5));
    MEMCPY_AN(MGCMDATHIS_N->DATA_6, MGCMDATHIS->DATA_6, sizeof(MGCMDATHIS->DATA_6));
    MEMCPY_AN(MGCMDATHIS_N->DATA_7, MGCMDATHIS->DATA_7, sizeof(MGCMDATHIS->DATA_7));
    MEMCPY_AN(MGCMDATHIS_N->DATA_8, MGCMDATHIS->DATA_8, sizeof(MGCMDATHIS->DATA_8));
    MEMCPY_AN(MGCMDATHIS_N->DATA_9, MGCMDATHIS->DATA_9, sizeof(MGCMDATHIS->DATA_9));
    MEMCPY_AN(MGCMDATHIS_N->DATA_10, MGCMDATHIS->DATA_10, sizeof(MGCMDATHIS->DATA_10));
    MEMCPY_AN(MGCMDATHIS_N->OLD_DATA_1, MGCMDATHIS->OLD_DATA_1, sizeof(MGCMDATHIS->OLD_DATA_1));
    MEMCPY_AN(MGCMDATHIS_N->OLD_DATA_2, MGCMDATHIS->OLD_DATA_2, sizeof(MGCMDATHIS->OLD_DATA_2));
    MEMCPY_AN(MGCMDATHIS_N->OLD_DATA_3, MGCMDATHIS->OLD_DATA_3, sizeof(MGCMDATHIS->OLD_DATA_3));
    MEMCPY_AN(MGCMDATHIS_N->OLD_DATA_4, MGCMDATHIS->OLD_DATA_4, sizeof(MGCMDATHIS->OLD_DATA_4));
    MEMCPY_AN(MGCMDATHIS_N->OLD_DATA_5, MGCMDATHIS->OLD_DATA_5, sizeof(MGCMDATHIS->OLD_DATA_5));
    MEMCPY_AN(MGCMDATHIS_N->OLD_DATA_6, MGCMDATHIS->OLD_DATA_6, sizeof(MGCMDATHIS->OLD_DATA_6));
    MEMCPY_AN(MGCMDATHIS_N->OLD_DATA_7, MGCMDATHIS->OLD_DATA_7, sizeof(MGCMDATHIS->OLD_DATA_7));
    MEMCPY_AN(MGCMDATHIS_N->OLD_DATA_8, MGCMDATHIS->OLD_DATA_8, sizeof(MGCMDATHIS->OLD_DATA_8));
    MEMCPY_AN(MGCMDATHIS_N->OLD_DATA_9, MGCMDATHIS->OLD_DATA_9, sizeof(MGCMDATHIS->OLD_DATA_9));
    MEMCPY_AN(MGCMDATHIS_N->OLD_DATA_10, MGCMDATHIS->OLD_DATA_10, sizeof(MGCMDATHIS->OLD_DATA_10));
    MGCMDATHIS_N->DEL_FLAG[0] = MGCMDATHIS->DEL_FLAG;
    MEMCPY_AN(MGCMDATHIS_N->CREATE_USER_ID, MGCMDATHIS->CREATE_USER_ID, sizeof(MGCMDATHIS->CREATE_USER_ID));
    MEMCPY_AN(MGCMDATHIS_N->CREATE_TIME, MGCMDATHIS->CREATE_TIME, sizeof(MGCMDATHIS->CREATE_TIME));
    MEMCPY_AN(MGCMDATHIS_N->UPDATE_USER_ID, MGCMDATHIS->UPDATE_USER_ID, sizeof(MGCMDATHIS->UPDATE_USER_ID));
    MEMCPY_AN(MGCMDATHIS_N->UPDATE_TIME, MGCMDATHIS->UPDATE_TIME, sizeof(MGCMDATHIS->UPDATE_TIME));
    MEMCPY_AN(MGCMDATHIS_N->TRAN_USER_ID, MGCMDATHIS->TRAN_USER_ID, sizeof(MGCMDATHIS->TRAN_USER_ID));
    MEMCPY_AN(MGCMDATHIS_N->TRAN_TIME, MGCMDATHIS->TRAN_TIME, sizeof(MGCMDATHIS->TRAN_TIME));
}


/* Del Null Function */
void DBC_del_null_mgcmdathis(struct MGCMDATHIS_N_TAG *MGCMDATHIS_N, struct MGCMDATHIS_TAG *MGCMDATHIS)
{
    MEMCPY_DN(MGCMDATHIS->FACTORY, MGCMDATHIS_N->FACTORY, sizeof(MGCMDATHIS->FACTORY));
    MEMCPY_DN(MGCMDATHIS->TABLE_NAME, MGCMDATHIS_N->TABLE_NAME, sizeof(MGCMDATHIS->TABLE_NAME));
    MGCMDATHIS->HIST_SEQ = MGCMDATHIS_N->HIST_SEQ;
    MEMCPY_DN(MGCMDATHIS->KEY_1, MGCMDATHIS_N->KEY_1, sizeof(MGCMDATHIS->KEY_1));
    MEMCPY_DN(MGCMDATHIS->KEY_2, MGCMDATHIS_N->KEY_2, sizeof(MGCMDATHIS->KEY_2));
    MEMCPY_DN(MGCMDATHIS->KEY_3, MGCMDATHIS_N->KEY_3, sizeof(MGCMDATHIS->KEY_3));
    MEMCPY_DN(MGCMDATHIS->KEY_4, MGCMDATHIS_N->KEY_4, sizeof(MGCMDATHIS->KEY_4));
    MEMCPY_DN(MGCMDATHIS->KEY_5, MGCMDATHIS_N->KEY_5, sizeof(MGCMDATHIS->KEY_5));
    MEMCPY_DN(MGCMDATHIS->KEY_6, MGCMDATHIS_N->KEY_6, sizeof(MGCMDATHIS->KEY_6));
    MEMCPY_DN(MGCMDATHIS->KEY_7, MGCMDATHIS_N->KEY_7, sizeof(MGCMDATHIS->KEY_7));
    MEMCPY_DN(MGCMDATHIS->KEY_8, MGCMDATHIS_N->KEY_8, sizeof(MGCMDATHIS->KEY_8));
    MEMCPY_DN(MGCMDATHIS->KEY_9, MGCMDATHIS_N->KEY_9, sizeof(MGCMDATHIS->KEY_9));
    MEMCPY_DN(MGCMDATHIS->KEY_10, MGCMDATHIS_N->KEY_10, sizeof(MGCMDATHIS->KEY_10));
    MEMCPY_DN(MGCMDATHIS->DATA_1, MGCMDATHIS_N->DATA_1, sizeof(MGCMDATHIS->DATA_1));
    MEMCPY_DN(MGCMDATHIS->DATA_2, MGCMDATHIS_N->DATA_2, sizeof(MGCMDATHIS->DATA_2));
    MEMCPY_DN(MGCMDATHIS->DATA_3, MGCMDATHIS_N->DATA_3, sizeof(MGCMDATHIS->DATA_3));
    MEMCPY_DN(MGCMDATHIS->DATA_4, MGCMDATHIS_N->DATA_4, sizeof(MGCMDATHIS->DATA_4));
    MEMCPY_DN(MGCMDATHIS->DATA_5, MGCMDATHIS_N->DATA_5, sizeof(MGCMDATHIS->DATA_5));
    MEMCPY_DN(MGCMDATHIS->DATA_6, MGCMDATHIS_N->DATA_6, sizeof(MGCMDATHIS->DATA_6));
    MEMCPY_DN(MGCMDATHIS->DATA_7, MGCMDATHIS_N->DATA_7, sizeof(MGCMDATHIS->DATA_7));
    MEMCPY_DN(MGCMDATHIS->DATA_8, MGCMDATHIS_N->DATA_8, sizeof(MGCMDATHIS->DATA_8));
    MEMCPY_DN(MGCMDATHIS->DATA_9, MGCMDATHIS_N->DATA_9, sizeof(MGCMDATHIS->DATA_9));
    MEMCPY_DN(MGCMDATHIS->DATA_10, MGCMDATHIS_N->DATA_10, sizeof(MGCMDATHIS->DATA_10));
    MEMCPY_DN(MGCMDATHIS->OLD_DATA_1, MGCMDATHIS_N->OLD_DATA_1, sizeof(MGCMDATHIS->OLD_DATA_1));
    MEMCPY_DN(MGCMDATHIS->OLD_DATA_2, MGCMDATHIS_N->OLD_DATA_2, sizeof(MGCMDATHIS->OLD_DATA_2));
    MEMCPY_DN(MGCMDATHIS->OLD_DATA_3, MGCMDATHIS_N->OLD_DATA_3, sizeof(MGCMDATHIS->OLD_DATA_3));
    MEMCPY_DN(MGCMDATHIS->OLD_DATA_4, MGCMDATHIS_N->OLD_DATA_4, sizeof(MGCMDATHIS->OLD_DATA_4));
    MEMCPY_DN(MGCMDATHIS->OLD_DATA_5, MGCMDATHIS_N->OLD_DATA_5, sizeof(MGCMDATHIS->OLD_DATA_5));
    MEMCPY_DN(MGCMDATHIS->OLD_DATA_6, MGCMDATHIS_N->OLD_DATA_6, sizeof(MGCMDATHIS->OLD_DATA_6));
    MEMCPY_DN(MGCMDATHIS->OLD_DATA_7, MGCMDATHIS_N->OLD_DATA_7, sizeof(MGCMDATHIS->OLD_DATA_7));
    MEMCPY_DN(MGCMDATHIS->OLD_DATA_8, MGCMDATHIS_N->OLD_DATA_8, sizeof(MGCMDATHIS->OLD_DATA_8));
    MEMCPY_DN(MGCMDATHIS->OLD_DATA_9, MGCMDATHIS_N->OLD_DATA_9, sizeof(MGCMDATHIS->OLD_DATA_9));
    MEMCPY_DN(MGCMDATHIS->OLD_DATA_10, MGCMDATHIS_N->OLD_DATA_10, sizeof(MGCMDATHIS->OLD_DATA_10));
    MGCMDATHIS->DEL_FLAG = MGCMDATHIS_N->DEL_FLAG[0];
    MEMCPY_DN(MGCMDATHIS->CREATE_USER_ID, MGCMDATHIS_N->CREATE_USER_ID, sizeof(MGCMDATHIS->CREATE_USER_ID));
    MEMCPY_DN(MGCMDATHIS->CREATE_TIME, MGCMDATHIS_N->CREATE_TIME, sizeof(MGCMDATHIS->CREATE_TIME));
    MEMCPY_DN(MGCMDATHIS->UPDATE_USER_ID, MGCMDATHIS_N->UPDATE_USER_ID, sizeof(MGCMDATHIS->UPDATE_USER_ID));
    MEMCPY_DN(MGCMDATHIS->UPDATE_TIME, MGCMDATHIS_N->UPDATE_TIME, sizeof(MGCMDATHIS->UPDATE_TIME));
    MEMCPY_DN(MGCMDATHIS->TRAN_USER_ID, MGCMDATHIS_N->TRAN_USER_ID, sizeof(MGCMDATHIS->TRAN_USER_ID));
    MEMCPY_DN(MGCMDATHIS->TRAN_TIME, MGCMDATHIS_N->TRAN_TIME, sizeof(MGCMDATHIS->TRAN_TIME));
}


