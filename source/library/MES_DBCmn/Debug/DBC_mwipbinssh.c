
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
    "DBC_mwipbinssh.pc"
};


static unsigned int sqlctx = 9140587;


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
            void  *sqhstv[55];
   unsigned int   sqhstl[55];
            int   sqhsts[55];
            void  *sqindv[55];
            int   sqinds[55];
   unsigned int   sqharm[55];
   unsigned int   *sqharc[55];
   unsigned short  sqadto[55];
   unsigned short  sqtdso[55];
} sqlstm = {13,55};

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
"asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1099,0,4,45,0,0,55,4,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
240,0,0,2,1111,0,4,189,0,0,55,4,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
475,0,0,3,121,0,4,336,0,0,5,4,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
510,0,0,4,103,0,2,374,0,0,4,4,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
541,0,0,5,44,0,2,382,0,0,1,1,0,1,0,1,97,0,0,
560,0,0,6,975,0,3,410,0,0,51,51,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,
779,0,0,7,988,0,5,536,0,0,51,51,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,
998,0,0,8,163,0,5,591,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,
1037,0,0,9,185,0,5,602,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,3,0,0,
1080,0,0,10,1040,0,9,702,0,0,10,10,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,0,0,0,1,0,
0,0,1,0,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
1135,0,0,10,0,0,13,730,0,0,51,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,
1354,0,0,10,0,0,15,811,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mwipbinssh.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2013/02/27 11:41:25
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
void DBC_add_null_mwipbinssh(struct MWIPBINSSH_N_TAG *MWIPBINSSH_N, struct MWIPBINSSH_TAG *MWIPBINSSH);
void DBC_del_null_mwipbinssh(struct MWIPBINSSH_N_TAG *MWIPBINSSH_N, struct MWIPBINSSH_TAG *MWIPBINSSH);


/* SQL SELECT Function */
void DBC_select_mwipbinssh(int sel_type, struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINSSH_N_TAG MWIPBINSSH_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinssh(&MWIPBINSSH_N, MWIPBINSSH);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    SUBLOT_ID,
                    HIST_SEQ,
                    BIN_COL_SEQ,
                    BIN_SEQ,
                    FACTORY,
                    LOT_ID,
                    LOT_HIST_SEQ,
                    BIN_ID,
                    BIN_VERSION,
                    BIN_UNIT,
                    BIN_PROMPT,
                    BIN_PROMPT_DESC,
                    BIN_QTY,
                    BIN_TYPE,
                    LOGICAL_BIN_FLAG,
                    USE_BIN_PROMPT_FAIL_REASON,
                    KEEP_LOT_QTY_FAIL,
                    FAIL_REASON_CODE,
                    LOW_YIELD_FLAG,
                    CHECK_RESULT,
                    TRAN_CODE,
                    TRAN_KEY_CODE_1,
                    TRAN_KEY_CODE_2,
                    TRAN_KEY_CODE_3,
                    TRAN_KEY_CODE_4,
                    TRAN_KEY_CODE_5,
                    TRAN_KEY_CODE_6,
                    TRAN_KEY_CODE_7,
                    TRAN_KEY_CODE_8,
                    TRAN_KEY_CODE_9,
                    TRAN_KEY_CODE_10,
                    BIN_COMMENT_1,
                    BIN_COMMENT_2,
                    BIN_COMMENT_3,
                    TRAN_COMMENT_1,
                    TRAN_COMMENT_2,
                    TRAN_COMMENT_3,
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
                    :MWIPBINSSH_N.SUBLOT_ID,
                    :MWIPBINSSH_N.HIST_SEQ,
                    :MWIPBINSSH_N.BIN_COL_SEQ,
                    :MWIPBINSSH_N.BIN_SEQ,
                    :MWIPBINSSH_N.FACTORY,
                    :MWIPBINSSH_N.LOT_ID,
                    :MWIPBINSSH_N.LOT_HIST_SEQ,
                    :MWIPBINSSH_N.BIN_ID,
                    :MWIPBINSSH_N.BIN_VERSION,
                    :MWIPBINSSH_N.BIN_UNIT,
                    :MWIPBINSSH_N.BIN_PROMPT,
                    :MWIPBINSSH_N.BIN_PROMPT_DESC,
                    :MWIPBINSSH_N.BIN_QTY,
                    :MWIPBINSSH_N.BIN_TYPE,
                    :MWIPBINSSH_N.LOGICAL_BIN_FLAG,
                    :MWIPBINSSH_N.USE_BIN_PROMPT_FAIL_REASON,
                    :MWIPBINSSH_N.KEEP_LOT_QTY_FAIL,
                    :MWIPBINSSH_N.FAIL_REASON_CODE,
                    :MWIPBINSSH_N.LOW_YIELD_FLAG,
                    :MWIPBINSSH_N.CHECK_RESULT,
                    :MWIPBINSSH_N.TRAN_CODE,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_1,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_2,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_3,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_4,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_5,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_6,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_7,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_8,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_9,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_10,
                    :MWIPBINSSH_N.BIN_COMMENT_1,
                    :MWIPBINSSH_N.BIN_COMMENT_2,
                    :MWIPBINSSH_N.BIN_COMMENT_3,
                    :MWIPBINSSH_N.TRAN_COMMENT_1,
                    :MWIPBINSSH_N.TRAN_COMMENT_2,
                    :MWIPBINSSH_N.TRAN_COMMENT_3,
                    :MWIPBINSSH_N.RESV_FIELD_1,
                    :MWIPBINSSH_N.RESV_FIELD_2,
                    :MWIPBINSSH_N.RESV_FIELD_3,
                    :MWIPBINSSH_N.RESV_FIELD_4,
                    :MWIPBINSSH_N.RESV_FIELD_5,
                    :MWIPBINSSH_N.RESV_FIELD_6,
                    :MWIPBINSSH_N.RESV_FIELD_7,
                    :MWIPBINSSH_N.RESV_FIELD_8,
                    :MWIPBINSSH_N.RESV_FIELD_9,
                    :MWIPBINSSH_N.RESV_FIELD_10,
                    :MWIPBINSSH_N.HIST_DEL_FLAG,
                    :MWIPBINSSH_N.HIST_DEL_TIME,
                    :MWIPBINSSH_N.HIST_DEL_USER_ID,
                    :MWIPBINSSH_N.HIST_DEL_COMMENT
                FROM MWIPBINSSH
                WHERE SUBLOT_ID = :MWIPBINSSH_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINSSH_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINSSH_N.BIN_COL_SEQ
                    AND BIN_SEQ = :MWIPBINSSH_N.BIN_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select SUBLOT_ID ,HIST_SEQ ,BIN_COL_SEQ ,BIN_SEQ ,FACTORY ,LO\
T_ID ,LOT_HIST_SEQ ,BIN_ID ,BIN_VERSION ,BIN_UNIT ,BIN_PROMPT ,BIN_PROMPT_DE\
SC ,BIN_QTY ,BIN_TYPE ,LOGICAL_BIN_FLAG ,USE_BIN_PROMPT_FAIL_REASON ,KEEP_LO\
T_QTY_FAIL ,FAIL_REASON_CODE ,LOW_YIELD_FLAG ,CHECK_RESULT ,TRAN_CODE ,TRAN_\
KEY_CODE_1 ,TRAN_KEY_CODE_2 ,TRAN_KEY_CODE_3 ,TRAN_KEY_CODE_4 ,TRAN_KEY_CODE\
_5 ,TRAN_KEY_CODE_6 ,TRAN_KEY_CODE_7 ,TRAN_KEY_CODE_8 ,TRAN_KEY_CODE_9 ,TRAN\
_KEY_CODE_10 ,BIN_COMMENT_1 ,BIN_COMMENT_2 ,BIN_COMMENT_3 ,TRAN_COMMENT_1 ,T\
RAN_COMMENT_2 ,TRAN_COMMENT_3 ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_FIELD_3 ,RES\
V_FIELD_4 ,RESV_FIELD_5 ,RESV_FIELD_6 ,RESV_FIELD_7 ,RESV_FIELD_8 ,RESV_FIEL\
D_9 ,RESV_FIELD_10 ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL\
_COMMENT into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b\
14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b2\
9,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44\
,:b45,:b46,:b47,:b48,:b49,:b50  from MWIPBINSSH whe");
            sqlstm.stmt = "re (((SUBLOT_ID=:b0 and HIST_SEQ=:b1) and BIN_CO\
L_SEQ=:b2) and BIN_SEQ=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPBINSSH_N.BIN_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINSSH_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINSSH_N.LOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPBINSSH_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINSSH_N.BIN_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPBINSSH_N.BIN_VERSION);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINSSH_N.BIN_UNIT);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINSSH_N.BIN_PROMPT);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPBINSSH_N.BIN_PROMPT_DESC);
            sqlstm.sqhstl[11] = (unsigned int  )201;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MWIPBINSSH_N.BIN_QTY);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPBINSSH_N.BIN_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINSSH_N.LOGICAL_BIN_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPBINSSH_N.USE_BIN_PROMPT_FAIL_REASON);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINSSH_N.KEEP_LOT_QTY_FAIL);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINSSH_N.FAIL_REASON_CODE);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPBINSSH_N.LOW_YIELD_FLAG);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPBINSSH_N.CHECK_RESULT);
            sqlstm.sqhstl[19] = (unsigned int  )4001;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINSSH_N.TRAN_CODE);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_1);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_2);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_3);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_4);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_5);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_6);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_7);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_8);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_9);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_10);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_1);
            sqlstm.sqhstl[31] = (unsigned int  )401;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_2);
            sqlstm.sqhstl[32] = (unsigned int  )401;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_3);
            sqlstm.sqhstl[33] = (unsigned int  )401;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_1);
            sqlstm.sqhstl[34] = (unsigned int  )401;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_2);
            sqlstm.sqhstl[35] = (unsigned int  )401;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_3);
            sqlstm.sqhstl[36] = (unsigned int  )401;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINSSH_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINSSH_N.HIST_DEL_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINSSH_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINSSH_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[50] = (unsigned int  )401;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MWIPBINSSH_N.BIN_SEQ);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
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
        DBC_del_null_mwipbinssh(&MWIPBINSSH_N, MWIPBINSSH);
    }

    DB_stop_query_timer("DBC_select_mwipbinssh", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mwipbinssh_for_update(int sel_type, struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINSSH_N_TAG MWIPBINSSH_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinssh(&MWIPBINSSH_N, MWIPBINSSH);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    SUBLOT_ID,
                    HIST_SEQ,
                    BIN_COL_SEQ,
                    BIN_SEQ,
                    FACTORY,
                    LOT_ID,
                    LOT_HIST_SEQ,
                    BIN_ID,
                    BIN_VERSION,
                    BIN_UNIT,
                    BIN_PROMPT,
                    BIN_PROMPT_DESC,
                    BIN_QTY,
                    BIN_TYPE,
                    LOGICAL_BIN_FLAG,
                    USE_BIN_PROMPT_FAIL_REASON,
                    KEEP_LOT_QTY_FAIL,
                    FAIL_REASON_CODE,
                    LOW_YIELD_FLAG,
                    CHECK_RESULT,
                    TRAN_CODE,
                    TRAN_KEY_CODE_1,
                    TRAN_KEY_CODE_2,
                    TRAN_KEY_CODE_3,
                    TRAN_KEY_CODE_4,
                    TRAN_KEY_CODE_5,
                    TRAN_KEY_CODE_6,
                    TRAN_KEY_CODE_7,
                    TRAN_KEY_CODE_8,
                    TRAN_KEY_CODE_9,
                    TRAN_KEY_CODE_10,
                    BIN_COMMENT_1,
                    BIN_COMMENT_2,
                    BIN_COMMENT_3,
                    TRAN_COMMENT_1,
                    TRAN_COMMENT_2,
                    TRAN_COMMENT_3,
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
                    :MWIPBINSSH_N.SUBLOT_ID,
                    :MWIPBINSSH_N.HIST_SEQ,
                    :MWIPBINSSH_N.BIN_COL_SEQ,
                    :MWIPBINSSH_N.BIN_SEQ,
                    :MWIPBINSSH_N.FACTORY,
                    :MWIPBINSSH_N.LOT_ID,
                    :MWIPBINSSH_N.LOT_HIST_SEQ,
                    :MWIPBINSSH_N.BIN_ID,
                    :MWIPBINSSH_N.BIN_VERSION,
                    :MWIPBINSSH_N.BIN_UNIT,
                    :MWIPBINSSH_N.BIN_PROMPT,
                    :MWIPBINSSH_N.BIN_PROMPT_DESC,
                    :MWIPBINSSH_N.BIN_QTY,
                    :MWIPBINSSH_N.BIN_TYPE,
                    :MWIPBINSSH_N.LOGICAL_BIN_FLAG,
                    :MWIPBINSSH_N.USE_BIN_PROMPT_FAIL_REASON,
                    :MWIPBINSSH_N.KEEP_LOT_QTY_FAIL,
                    :MWIPBINSSH_N.FAIL_REASON_CODE,
                    :MWIPBINSSH_N.LOW_YIELD_FLAG,
                    :MWIPBINSSH_N.CHECK_RESULT,
                    :MWIPBINSSH_N.TRAN_CODE,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_1,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_2,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_3,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_4,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_5,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_6,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_7,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_8,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_9,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_10,
                    :MWIPBINSSH_N.BIN_COMMENT_1,
                    :MWIPBINSSH_N.BIN_COMMENT_2,
                    :MWIPBINSSH_N.BIN_COMMENT_3,
                    :MWIPBINSSH_N.TRAN_COMMENT_1,
                    :MWIPBINSSH_N.TRAN_COMMENT_2,
                    :MWIPBINSSH_N.TRAN_COMMENT_3,
                    :MWIPBINSSH_N.RESV_FIELD_1,
                    :MWIPBINSSH_N.RESV_FIELD_2,
                    :MWIPBINSSH_N.RESV_FIELD_3,
                    :MWIPBINSSH_N.RESV_FIELD_4,
                    :MWIPBINSSH_N.RESV_FIELD_5,
                    :MWIPBINSSH_N.RESV_FIELD_6,
                    :MWIPBINSSH_N.RESV_FIELD_7,
                    :MWIPBINSSH_N.RESV_FIELD_8,
                    :MWIPBINSSH_N.RESV_FIELD_9,
                    :MWIPBINSSH_N.RESV_FIELD_10,
                    :MWIPBINSSH_N.HIST_DEL_FLAG,
                    :MWIPBINSSH_N.HIST_DEL_TIME,
                    :MWIPBINSSH_N.HIST_DEL_USER_ID,
                    :MWIPBINSSH_N.HIST_DEL_COMMENT
                FROM MWIPBINSSH
                WHERE SUBLOT_ID = :MWIPBINSSH_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINSSH_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINSSH_N.BIN_COL_SEQ
                    AND BIN_SEQ = :MWIPBINSSH_N.BIN_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select SUBLOT_ID ,HIST_SEQ ,BIN_COL_SEQ ,BIN_SEQ ,FACTORY ,LO\
T_ID ,LOT_HIST_SEQ ,BIN_ID ,BIN_VERSION ,BIN_UNIT ,BIN_PROMPT ,BIN_PROMPT_DE\
SC ,BIN_QTY ,BIN_TYPE ,LOGICAL_BIN_FLAG ,USE_BIN_PROMPT_FAIL_REASON ,KEEP_LO\
T_QTY_FAIL ,FAIL_REASON_CODE ,LOW_YIELD_FLAG ,CHECK_RESULT ,TRAN_CODE ,TRAN_\
KEY_CODE_1 ,TRAN_KEY_CODE_2 ,TRAN_KEY_CODE_3 ,TRAN_KEY_CODE_4 ,TRAN_KEY_CODE\
_5 ,TRAN_KEY_CODE_6 ,TRAN_KEY_CODE_7 ,TRAN_KEY_CODE_8 ,TRAN_KEY_CODE_9 ,TRAN\
_KEY_CODE_10 ,BIN_COMMENT_1 ,BIN_COMMENT_2 ,BIN_COMMENT_3 ,TRAN_COMMENT_1 ,T\
RAN_COMMENT_2 ,TRAN_COMMENT_3 ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_FIELD_3 ,RES\
V_FIELD_4 ,RESV_FIELD_5 ,RESV_FIELD_6 ,RESV_FIELD_7 ,RESV_FIELD_8 ,RESV_FIEL\
D_9 ,RESV_FIELD_10 ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL\
_COMMENT into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b\
14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b2\
9,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44\
,:b45,:b46,:b47,:b48,:b49,:b50  from MWIPBINSSH whe");
            sqlstm.stmt = "re (((SUBLOT_ID=:b0 and HIST_SEQ=:b1) and BIN_CO\
L_SEQ=:b2) and BIN_SEQ=:b3) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )240;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPBINSSH_N.BIN_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINSSH_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINSSH_N.LOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPBINSSH_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINSSH_N.BIN_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPBINSSH_N.BIN_VERSION);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINSSH_N.BIN_UNIT);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINSSH_N.BIN_PROMPT);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPBINSSH_N.BIN_PROMPT_DESC);
            sqlstm.sqhstl[11] = (unsigned int  )201;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MWIPBINSSH_N.BIN_QTY);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPBINSSH_N.BIN_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINSSH_N.LOGICAL_BIN_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPBINSSH_N.USE_BIN_PROMPT_FAIL_REASON);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINSSH_N.KEEP_LOT_QTY_FAIL);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINSSH_N.FAIL_REASON_CODE);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPBINSSH_N.LOW_YIELD_FLAG);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPBINSSH_N.CHECK_RESULT);
            sqlstm.sqhstl[19] = (unsigned int  )4001;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINSSH_N.TRAN_CODE);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_1);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_2);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_3);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_4);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_5);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_6);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_7);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_8);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_9);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_10);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_1);
            sqlstm.sqhstl[31] = (unsigned int  )401;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_2);
            sqlstm.sqhstl[32] = (unsigned int  )401;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_3);
            sqlstm.sqhstl[33] = (unsigned int  )401;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_1);
            sqlstm.sqhstl[34] = (unsigned int  )401;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_2);
            sqlstm.sqhstl[35] = (unsigned int  )401;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_3);
            sqlstm.sqhstl[36] = (unsigned int  )401;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINSSH_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINSSH_N.HIST_DEL_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINSSH_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINSSH_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[50] = (unsigned int  )401;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MWIPBINSSH_N.BIN_SEQ);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
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
        DBC_del_null_mwipbinssh(&MWIPBINSSH_N, MWIPBINSSH);
    }

    DB_stop_query_timer("DBC_select_mwipbinssh_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mwipbinssh_scalar(int sel_type, struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINSSH_N_TAG MWIPBINSSH_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinssh(&MWIPBINSSH_N, MWIPBINSSH);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPBINSSH
                WHERE SUBLOT_ID = :MWIPBINSSH_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINSSH_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINSSH_N.BIN_COL_SEQ
                    AND BIN_SEQ = :MWIPBINSSH_N.BIN_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPBINSSH where\
 (((SUBLOT_ID=:b1 and HIST_SEQ=:b2) and BIN_COL_SEQ=:b3) and BIN_SEQ=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )475;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPBINSSH_N.BIN_SEQ);
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

    DB_stop_query_timer("DBC_select_mwipbinssh_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mwipbinssh(int sel_type, struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINSSH_N_TAG MWIPBINSSH_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinssh(&MWIPBINSSH_N, MWIPBINSSH);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MWIPBINSSH
                WHERE SUBLOT_ID = :MWIPBINSSH_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINSSH_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINSSH_N.BIN_COL_SEQ
                    AND BIN_SEQ = :MWIPBINSSH_N.BIN_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPBINSSH  where (((SUBLOT_ID=:b0 \
and HIST_SEQ=:b1) and BIN_COL_SEQ=:b2) and BIN_SEQ=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )510;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPBINSSH_N.BIN_SEQ);
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
            /* EXEC SQL DELETE FROM MWIPBINSSH
                WHERE SUBLOT_ID = :MWIPBINSSH_N.SUBLOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPBINSSH  where SUBLOT_ID=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )541;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
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

    DB_stop_query_timer("DBC_delete_mwipbinssh", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mwipbinssh(struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINSSH_N_TAG MWIPBINSSH_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinssh(&MWIPBINSSH_N, MWIPBINSSH);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MWIPBINSSH( 
                    SUBLOT_ID, 
                    HIST_SEQ, 
                    BIN_COL_SEQ, 
                    BIN_SEQ, 
                    FACTORY, 
                    LOT_ID, 
                    LOT_HIST_SEQ, 
                    BIN_ID, 
                    BIN_VERSION, 
                    BIN_UNIT, 
                    BIN_PROMPT, 
                    BIN_PROMPT_DESC, 
                    BIN_QTY, 
                    BIN_TYPE, 
                    LOGICAL_BIN_FLAG, 
                    USE_BIN_PROMPT_FAIL_REASON, 
                    KEEP_LOT_QTY_FAIL, 
                    FAIL_REASON_CODE, 
                    LOW_YIELD_FLAG, 
                    CHECK_RESULT, 
                    TRAN_CODE, 
                    TRAN_KEY_CODE_1, 
                    TRAN_KEY_CODE_2, 
                    TRAN_KEY_CODE_3, 
                    TRAN_KEY_CODE_4, 
                    TRAN_KEY_CODE_5, 
                    TRAN_KEY_CODE_6, 
                    TRAN_KEY_CODE_7, 
                    TRAN_KEY_CODE_8, 
                    TRAN_KEY_CODE_9, 
                    TRAN_KEY_CODE_10, 
                    BIN_COMMENT_1, 
                    BIN_COMMENT_2, 
                    BIN_COMMENT_3, 
                    TRAN_COMMENT_1, 
                    TRAN_COMMENT_2, 
                    TRAN_COMMENT_3, 
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
                    :MWIPBINSSH_N.SUBLOT_ID,
                    :MWIPBINSSH_N.HIST_SEQ,
                    :MWIPBINSSH_N.BIN_COL_SEQ,
                    :MWIPBINSSH_N.BIN_SEQ,
                    :MWIPBINSSH_N.FACTORY,
                    :MWIPBINSSH_N.LOT_ID,
                    :MWIPBINSSH_N.LOT_HIST_SEQ,
                    :MWIPBINSSH_N.BIN_ID,
                    :MWIPBINSSH_N.BIN_VERSION,
                    :MWIPBINSSH_N.BIN_UNIT,
                    :MWIPBINSSH_N.BIN_PROMPT,
                    :MWIPBINSSH_N.BIN_PROMPT_DESC,
                    :MWIPBINSSH_N.BIN_QTY,
                    :MWIPBINSSH_N.BIN_TYPE,
                    :MWIPBINSSH_N.LOGICAL_BIN_FLAG,
                    :MWIPBINSSH_N.USE_BIN_PROMPT_FAIL_REASON,
                    :MWIPBINSSH_N.KEEP_LOT_QTY_FAIL,
                    :MWIPBINSSH_N.FAIL_REASON_CODE,
                    :MWIPBINSSH_N.LOW_YIELD_FLAG,
                    :MWIPBINSSH_N.CHECK_RESULT,
                    :MWIPBINSSH_N.TRAN_CODE,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_1,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_2,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_3,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_4,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_5,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_6,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_7,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_8,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_9,
                    :MWIPBINSSH_N.TRAN_KEY_CODE_10,
                    :MWIPBINSSH_N.BIN_COMMENT_1,
                    :MWIPBINSSH_N.BIN_COMMENT_2,
                    :MWIPBINSSH_N.BIN_COMMENT_3,
                    :MWIPBINSSH_N.TRAN_COMMENT_1,
                    :MWIPBINSSH_N.TRAN_COMMENT_2,
                    :MWIPBINSSH_N.TRAN_COMMENT_3,
                    :MWIPBINSSH_N.RESV_FIELD_1,
                    :MWIPBINSSH_N.RESV_FIELD_2,
                    :MWIPBINSSH_N.RESV_FIELD_3,
                    :MWIPBINSSH_N.RESV_FIELD_4,
                    :MWIPBINSSH_N.RESV_FIELD_5,
                    :MWIPBINSSH_N.RESV_FIELD_6,
                    :MWIPBINSSH_N.RESV_FIELD_7,
                    :MWIPBINSSH_N.RESV_FIELD_8,
                    :MWIPBINSSH_N.RESV_FIELD_9,
                    :MWIPBINSSH_N.RESV_FIELD_10,
                    :MWIPBINSSH_N.HIST_DEL_FLAG,
                    :MWIPBINSSH_N.HIST_DEL_TIME,
                    :MWIPBINSSH_N.HIST_DEL_USER_ID,
                    :MWIPBINSSH_N.HIST_DEL_COMMENT
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 55;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into MWIPBINSSH (SUBLOT_ID,HIST_SEQ,BIN_COL_SEQ,B\
IN_SEQ,FACTORY,LOT_ID,LOT_HIST_SEQ,BIN_ID,BIN_VERSION,BIN_UNIT,BIN_PROMPT,BIN\
_PROMPT_DESC,BIN_QTY,BIN_TYPE,LOGICAL_BIN_FLAG,USE_BIN_PROMPT_FAIL_REASON,KEE\
P_LOT_QTY_FAIL,FAIL_REASON_CODE,LOW_YIELD_FLAG,CHECK_RESULT,TRAN_CODE,TRAN_KE\
Y_CODE_1,TRAN_KEY_CODE_2,TRAN_KEY_CODE_3,TRAN_KEY_CODE_4,TRAN_KEY_CODE_5,TRAN\
_KEY_CODE_6,TRAN_KEY_CODE_7,TRAN_KEY_CODE_8,TRAN_KEY_CODE_9,TRAN_KEY_CODE_10,\
BIN_COMMENT_1,BIN_COMMENT_2,BIN_COMMENT_3,TRAN_COMMENT_1,TRAN_COMMENT_2,TRAN_\
COMMENT_3,RESV_FIELD_1,RESV_FIELD_2,RESV_FIELD_3,RESV_FIELD_4,RESV_FIELD_5,RE\
SV_FIELD_6,RESV_FIELD_7,RESV_FIELD_8,RESV_FIELD_9,RESV_FIELD_10,HIST_DEL_FLAG\
,HIST_DEL_TIME,HIST_DEL_USER_ID,HIST_DEL_COMMENT) values (:b0,:b1,:b2,:b3,:b4\
,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:\
b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b3\
6,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )560;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
    sqlstm.sqhstl[0] = (unsigned int  )31;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
    sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)&(MWIPBINSSH_N.BIN_SEQ);
    sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MWIPBINSSH_N.FACTORY);
    sqlstm.sqhstl[4] = (unsigned int  )11;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MWIPBINSSH_N.LOT_ID);
    sqlstm.sqhstl[5] = (unsigned int  )26;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)&(MWIPBINSSH_N.LOT_HIST_SEQ);
    sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MWIPBINSSH_N.BIN_ID);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)&(MWIPBINSSH_N.BIN_VERSION);
    sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MWIPBINSSH_N.BIN_UNIT);
    sqlstm.sqhstl[9] = (unsigned int  )11;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MWIPBINSSH_N.BIN_PROMPT);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MWIPBINSSH_N.BIN_PROMPT_DESC);
    sqlstm.sqhstl[11] = (unsigned int  )201;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)&(MWIPBINSSH_N.BIN_QTY);
    sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MWIPBINSSH_N.BIN_TYPE);
    sqlstm.sqhstl[13] = (unsigned int  )2;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MWIPBINSSH_N.LOGICAL_BIN_FLAG);
    sqlstm.sqhstl[14] = (unsigned int  )2;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MWIPBINSSH_N.USE_BIN_PROMPT_FAIL_REASON);
    sqlstm.sqhstl[15] = (unsigned int  )2;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MWIPBINSSH_N.KEEP_LOT_QTY_FAIL);
    sqlstm.sqhstl[16] = (unsigned int  )2;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MWIPBINSSH_N.FAIL_REASON_CODE);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MWIPBINSSH_N.LOW_YIELD_FLAG);
    sqlstm.sqhstl[18] = (unsigned int  )2;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MWIPBINSSH_N.CHECK_RESULT);
    sqlstm.sqhstl[19] = (unsigned int  )4001;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MWIPBINSSH_N.TRAN_CODE);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_1);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_2);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_3);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_4);
    sqlstm.sqhstl[24] = (unsigned int  )31;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_5);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_6);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_7);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_8);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_9);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_10);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_1);
    sqlstm.sqhstl[31] = (unsigned int  )401;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_2);
    sqlstm.sqhstl[32] = (unsigned int  )401;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_3);
    sqlstm.sqhstl[33] = (unsigned int  )401;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_1);
    sqlstm.sqhstl[34] = (unsigned int  )401;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_2);
    sqlstm.sqhstl[35] = (unsigned int  )401;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_3);
    sqlstm.sqhstl[36] = (unsigned int  )401;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_1);
    sqlstm.sqhstl[37] = (unsigned int  )31;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_2);
    sqlstm.sqhstl[38] = (unsigned int  )31;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_3);
    sqlstm.sqhstl[39] = (unsigned int  )31;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_4);
    sqlstm.sqhstl[40] = (unsigned int  )31;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_5);
    sqlstm.sqhstl[41] = (unsigned int  )31;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_6);
    sqlstm.sqhstl[42] = (unsigned int  )31;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_7);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_8);
    sqlstm.sqhstl[44] = (unsigned int  )31;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_9);
    sqlstm.sqhstl[45] = (unsigned int  )31;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_10);
    sqlstm.sqhstl[46] = (unsigned int  )31;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MWIPBINSSH_N.HIST_DEL_FLAG);
    sqlstm.sqhstl[47] = (unsigned int  )2;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MWIPBINSSH_N.HIST_DEL_TIME);
    sqlstm.sqhstl[48] = (unsigned int  )15;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MWIPBINSSH_N.HIST_DEL_USER_ID);
    sqlstm.sqhstl[49] = (unsigned int  )21;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MWIPBINSSH_N.HIST_DEL_COMMENT);
    sqlstm.sqhstl[50] = (unsigned int  )401;
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



    DB_stop_query_timer("DBC_insert_mwipbinssh", 0);
}


/* SQL UPDATE Function */
void DBC_update_mwipbinssh(int sel_type, struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINSSH_N_TAG MWIPBINSSH_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinssh(&MWIPBINSSH_N, MWIPBINSSH);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MWIPBINSSH SET
                    FACTORY = :MWIPBINSSH_N.FACTORY,
                    LOT_ID = :MWIPBINSSH_N.LOT_ID,
                    LOT_HIST_SEQ = :MWIPBINSSH_N.LOT_HIST_SEQ,
                    BIN_ID = :MWIPBINSSH_N.BIN_ID,
                    BIN_VERSION = :MWIPBINSSH_N.BIN_VERSION,
                    BIN_UNIT = :MWIPBINSSH_N.BIN_UNIT,
                    BIN_PROMPT = :MWIPBINSSH_N.BIN_PROMPT,
                    BIN_PROMPT_DESC = :MWIPBINSSH_N.BIN_PROMPT_DESC,
                    BIN_QTY = :MWIPBINSSH_N.BIN_QTY,
                    BIN_TYPE = :MWIPBINSSH_N.BIN_TYPE,
                    LOGICAL_BIN_FLAG = :MWIPBINSSH_N.LOGICAL_BIN_FLAG,
                    USE_BIN_PROMPT_FAIL_REASON = :MWIPBINSSH_N.USE_BIN_PROMPT_FAIL_REASON,
                    KEEP_LOT_QTY_FAIL = :MWIPBINSSH_N.KEEP_LOT_QTY_FAIL,
                    FAIL_REASON_CODE = :MWIPBINSSH_N.FAIL_REASON_CODE,
                    LOW_YIELD_FLAG = :MWIPBINSSH_N.LOW_YIELD_FLAG,
                    CHECK_RESULT = :MWIPBINSSH_N.CHECK_RESULT,
                    TRAN_CODE = :MWIPBINSSH_N.TRAN_CODE,
                    TRAN_KEY_CODE_1 = :MWIPBINSSH_N.TRAN_KEY_CODE_1,
                    TRAN_KEY_CODE_2 = :MWIPBINSSH_N.TRAN_KEY_CODE_2,
                    TRAN_KEY_CODE_3 = :MWIPBINSSH_N.TRAN_KEY_CODE_3,
                    TRAN_KEY_CODE_4 = :MWIPBINSSH_N.TRAN_KEY_CODE_4,
                    TRAN_KEY_CODE_5 = :MWIPBINSSH_N.TRAN_KEY_CODE_5,
                    TRAN_KEY_CODE_6 = :MWIPBINSSH_N.TRAN_KEY_CODE_6,
                    TRAN_KEY_CODE_7 = :MWIPBINSSH_N.TRAN_KEY_CODE_7,
                    TRAN_KEY_CODE_8 = :MWIPBINSSH_N.TRAN_KEY_CODE_8,
                    TRAN_KEY_CODE_9 = :MWIPBINSSH_N.TRAN_KEY_CODE_9,
                    TRAN_KEY_CODE_10 = :MWIPBINSSH_N.TRAN_KEY_CODE_10,
                    BIN_COMMENT_1 = :MWIPBINSSH_N.BIN_COMMENT_1,
                    BIN_COMMENT_2 = :MWIPBINSSH_N.BIN_COMMENT_2,
                    BIN_COMMENT_3 = :MWIPBINSSH_N.BIN_COMMENT_3,
                    TRAN_COMMENT_1 = :MWIPBINSSH_N.TRAN_COMMENT_1,
                    TRAN_COMMENT_2 = :MWIPBINSSH_N.TRAN_COMMENT_2,
                    TRAN_COMMENT_3 = :MWIPBINSSH_N.TRAN_COMMENT_3,
                    RESV_FIELD_1 = :MWIPBINSSH_N.RESV_FIELD_1,
                    RESV_FIELD_2 = :MWIPBINSSH_N.RESV_FIELD_2,
                    RESV_FIELD_3 = :MWIPBINSSH_N.RESV_FIELD_3,
                    RESV_FIELD_4 = :MWIPBINSSH_N.RESV_FIELD_4,
                    RESV_FIELD_5 = :MWIPBINSSH_N.RESV_FIELD_5,
                    RESV_FIELD_6 = :MWIPBINSSH_N.RESV_FIELD_6,
                    RESV_FIELD_7 = :MWIPBINSSH_N.RESV_FIELD_7,
                    RESV_FIELD_8 = :MWIPBINSSH_N.RESV_FIELD_8,
                    RESV_FIELD_9 = :MWIPBINSSH_N.RESV_FIELD_9,
                    RESV_FIELD_10 = :MWIPBINSSH_N.RESV_FIELD_10,
                    HIST_DEL_FLAG = :MWIPBINSSH_N.HIST_DEL_FLAG,
                    HIST_DEL_TIME = :MWIPBINSSH_N.HIST_DEL_TIME,
                    HIST_DEL_USER_ID = :MWIPBINSSH_N.HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT = :MWIPBINSSH_N.HIST_DEL_COMMENT
                WHERE SUBLOT_ID = :MWIPBINSSH_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINSSH_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINSSH_N.BIN_COL_SEQ
                    AND BIN_SEQ = :MWIPBINSSH_N.BIN_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPBINSSH  set FACTORY=:b0,LOT_ID=:b1,LO\
T_HIST_SEQ=:b2,BIN_ID=:b3,BIN_VERSION=:b4,BIN_UNIT=:b5,BIN_PROMPT=:b6,BIN_PRO\
MPT_DESC=:b7,BIN_QTY=:b8,BIN_TYPE=:b9,LOGICAL_BIN_FLAG=:b10,USE_BIN_PROMPT_FA\
IL_REASON=:b11,KEEP_LOT_QTY_FAIL=:b12,FAIL_REASON_CODE=:b13,LOW_YIELD_FLAG=:b\
14,CHECK_RESULT=:b15,TRAN_CODE=:b16,TRAN_KEY_CODE_1=:b17,TRAN_KEY_CODE_2=:b18\
,TRAN_KEY_CODE_3=:b19,TRAN_KEY_CODE_4=:b20,TRAN_KEY_CODE_5=:b21,TRAN_KEY_CODE\
_6=:b22,TRAN_KEY_CODE_7=:b23,TRAN_KEY_CODE_8=:b24,TRAN_KEY_CODE_9=:b25,TRAN_K\
EY_CODE_10=:b26,BIN_COMMENT_1=:b27,BIN_COMMENT_2=:b28,BIN_COMMENT_3=:b29,TRAN\
_COMMENT_1=:b30,TRAN_COMMENT_2=:b31,TRAN_COMMENT_3=:b32,RESV_FIELD_1=:b33,RES\
V_FIELD_2=:b34,RESV_FIELD_3=:b35,RESV_FIELD_4=:b36,RESV_FIELD_5=:b37,RESV_FIE\
LD_6=:b38,RESV_FIELD_7=:b39,RESV_FIELD_8=:b40,RESV_FIELD_9=:b41,RESV_FIELD_10\
=:b42,HIST_DEL_FLAG=:b43,HIST_DEL_TIME=:b44,HIST_DEL_USER_ID=:b45,HIST_DEL_CO\
MMENT=:b46 where (((SUBLOT_ID=:b47 and HIST_SEQ=:b48) and BIN_COL_SEQ=:b49) a\
nd BIN_SEQ=:b50)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )779;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINSSH_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINSSH_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINSSH_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINSSH_N.BIN_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPBINSSH_N.BIN_VERSION);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINSSH_N.BIN_UNIT);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPBINSSH_N.BIN_PROMPT);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINSSH_N.BIN_PROMPT_DESC);
            sqlstm.sqhstl[7] = (unsigned int  )201;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPBINSSH_N.BIN_QTY);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINSSH_N.BIN_TYPE);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINSSH_N.LOGICAL_BIN_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPBINSSH_N.USE_BIN_PROMPT_FAIL_REASON);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINSSH_N.KEEP_LOT_QTY_FAIL);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPBINSSH_N.FAIL_REASON_CODE);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINSSH_N.LOW_YIELD_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPBINSSH_N.CHECK_RESULT);
            sqlstm.sqhstl[15] = (unsigned int  )4001;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINSSH_N.TRAN_CODE);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_1);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_2);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_3);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_4);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_5);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_6);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_7);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_8);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_9);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_10);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_1);
            sqlstm.sqhstl[27] = (unsigned int  )401;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_2);
            sqlstm.sqhstl[28] = (unsigned int  )401;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_3);
            sqlstm.sqhstl[29] = (unsigned int  )401;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_1);
            sqlstm.sqhstl[30] = (unsigned int  )401;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_2);
            sqlstm.sqhstl[31] = (unsigned int  )401;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_3);
            sqlstm.sqhstl[32] = (unsigned int  )401;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_1);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_2);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_3);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_4);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_5);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_6);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_7);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_8);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_9);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_10);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINSSH_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINSSH_N.HIST_DEL_TIME);
            sqlstm.sqhstl[44] = (unsigned int  )15;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINSSH_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[45] = (unsigned int  )21;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINSSH_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[46] = (unsigned int  )401;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(MWIPBINSSH_N.BIN_SEQ);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
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


            break;

        case 2:
            /* EXEC SQL UPDATE MWIPBINSSH SET
                    HIST_DEL_FLAG = :MWIPBINSSH_N.HIST_DEL_FLAG,
                    HIST_DEL_TIME = :MWIPBINSSH_N.HIST_DEL_TIME,
                    HIST_DEL_USER_ID = :MWIPBINSSH_N.HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT = :MWIPBINSSH_N.HIST_DEL_COMMENT
                WHERE SUBLOT_ID = :MWIPBINSSH_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINSSH_N.HIST_SEQ
                    AND HIST_DEL_FLAG = ' '; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPBINSSH  set HIST_DEL_FLAG=:b0,HIST_DE\
L_TIME=:b1,HIST_DEL_USER_ID=:b2,HIST_DEL_COMMENT=:b3 where ((SUBLOT_ID=:b4 an\
d HIST_SEQ=:b5) and HIST_DEL_FLAG=' ')";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )998;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINSSH_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINSSH_N.HIST_DEL_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINSSH_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINSSH_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[3] = (unsigned int  )401;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
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
            /* EXEC SQL UPDATE MWIPBINSSH SET
                    HIST_DEL_FLAG = :MWIPBINSSH_N.HIST_DEL_FLAG,
                    HIST_DEL_TIME = :MWIPBINSSH_N.HIST_DEL_TIME,
                    HIST_DEL_USER_ID = :MWIPBINSSH_N.HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT = :MWIPBINSSH_N.HIST_DEL_COMMENT
                WHERE SUBLOT_ID = :MWIPBINSSH_N.SUBLOT_ID
                    AND HIST_SEQ = :MWIPBINSSH_N.HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINSSH_N.BIN_COL_SEQ
                    AND HIST_DEL_FLAG = ' '; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPBINSSH  set HIST_DEL_FLAG=:b0,HIST_DE\
L_TIME=:b1,HIST_DEL_USER_ID=:b2,HIST_DEL_COMMENT=:b3 where (((SUBLOT_ID=:b4 a\
nd HIST_SEQ=:b5) and BIN_COL_SEQ=:b6) and HIST_DEL_FLAG=' ')";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1037;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINSSH_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINSSH_N.HIST_DEL_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINSSH_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINSSH_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[3] = (unsigned int  )401;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
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

    DB_stop_query_timer("DBC_update_mwipbinssh", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mwipbinssh(int sel_type, struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINSSH_N_TAG MWIPBINSSH_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbinssh(&MWIPBINSSH_N, MWIPBINSSH);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MWIPBINSSH_CUR_1 CURSOR FOR
                SELECT 
                    SUBLOT_ID,
                    HIST_SEQ,
                    BIN_COL_SEQ,
                    BIN_SEQ,
                    FACTORY,
                    LOT_ID,
                    LOT_HIST_SEQ,
                    BIN_ID,
                    BIN_VERSION,
                    BIN_UNIT,
                    BIN_PROMPT,
                    BIN_PROMPT_DESC,
                    BIN_QTY,
                    BIN_TYPE,
                    LOGICAL_BIN_FLAG,
                    USE_BIN_PROMPT_FAIL_REASON,
                    KEEP_LOT_QTY_FAIL,
                    FAIL_REASON_CODE,
                    LOW_YIELD_FLAG,
                    CHECK_RESULT,
                    TRAN_CODE,
                    TRAN_KEY_CODE_1,
                    TRAN_KEY_CODE_2,
                    TRAN_KEY_CODE_3,
                    TRAN_KEY_CODE_4,
                    TRAN_KEY_CODE_5,
                    TRAN_KEY_CODE_6,
                    TRAN_KEY_CODE_7,
                    TRAN_KEY_CODE_8,
                    TRAN_KEY_CODE_9,
                    TRAN_KEY_CODE_10,
                    BIN_COMMENT_1,
                    BIN_COMMENT_2,
                    BIN_COMMENT_3,
                    TRAN_COMMENT_1,
                    TRAN_COMMENT_2,
                    TRAN_COMMENT_3,
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
                FROM MWIPBINSSH
                WHERE ( (SUBLOT_ID = :MWIPBINSSH_N.SUBLOT_ID AND HIST_SEQ = :MWIPBINSSH_N.HIST_SEQ AND BIN_SEQ >= :MWIPBINSSH_N.BIN_SEQ) OR 
                        (SUBLOT_ID = :MWIPBINSSH_N.SUBLOT_ID AND HIST_SEQ < :MWIPBINSSH_N.HIST_SEQ) OR 
                        (SUBLOT_ID > :MWIPBINSSH_N.SUBLOT_ID) )
                    AND LOT_ID = :MWIPBINSSH_N.LOT_ID
                    AND LOT_HIST_SEQ = :MWIPBINSSH_N.LOT_HIST_SEQ
                    AND BIN_COL_SEQ = :MWIPBINSSH_N.BIN_COL_SEQ
                    AND HIST_DEL_FLAG LIKE :MWIPBINSSH_N.HIST_DEL_FLAG
                ORDER BY SUBLOT_ID ASC, HIST_SEQ DESC, BIN_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_MWIPBINSSH_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select SUBLOT_ID ,HIST_SEQ ,BIN_COL_SEQ ,BIN_SEQ ,FACTORY ,LO\
T_ID ,LOT_HIST_SEQ ,BIN_ID ,BIN_VERSION ,BIN_UNIT ,BIN_PROMPT ,BIN_PROMPT_DE\
SC ,BIN_QTY ,BIN_TYPE ,LOGICAL_BIN_FLAG ,USE_BIN_PROMPT_FAIL_REASON ,KEEP_LO\
T_QTY_FAIL ,FAIL_REASON_CODE ,LOW_YIELD_FLAG ,CHECK_RESULT ,TRAN_CODE ,TRAN_\
KEY_CODE_1 ,TRAN_KEY_CODE_2 ,TRAN_KEY_CODE_3 ,TRAN_KEY_CODE_4 ,TRAN_KEY_CODE\
_5 ,TRAN_KEY_CODE_6 ,TRAN_KEY_CODE_7 ,TRAN_KEY_CODE_8 ,TRAN_KEY_CODE_9 ,TRAN\
_KEY_CODE_10 ,BIN_COMMENT_1 ,BIN_COMMENT_2 ,BIN_COMMENT_3 ,TRAN_COMMENT_1 ,T\
RAN_COMMENT_2 ,TRAN_COMMENT_3 ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_FIELD_3 ,RES\
V_FIELD_4 ,RESV_FIELD_5 ,RESV_FIELD_6 ,RESV_FIELD_7 ,RESV_FIELD_8 ,RESV_FIEL\
D_9 ,RESV_FIELD_10 ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL\
_COMMENT  from MWIPBINSSH where ((((((((SUBLOT_ID=:b0 and HIST_SEQ=:b1) and \
BIN_SEQ>=:b2) or (SUBLOT_ID=:b0 and HIST_SEQ<:b1)) or SUBLOT_ID>:b0) and LOT\
_ID=:b6) and LOT_HIST_SEQ=:b7) and BIN_COL_SEQ=:b8) and HIST_DEL_FLAG like :\
b9) order by SUBLOT_ID asc ,HIST_SEQ desc ,BIN_SEQ ");
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1080;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINSSH_N.BIN_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPBINSSH_N.LOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MWIPBINSSH_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINSSH_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
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

    DB_stop_query_timer("DBC_open_mwipbinssh", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mwipbinssh(int sel_type, struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINSSH_N_TAG MWIPBINSSH_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MWIPBINSSH_CUR_1 INTO
                :MWIPBINSSH_N.SUBLOT_ID,
                :MWIPBINSSH_N.HIST_SEQ,
                :MWIPBINSSH_N.BIN_COL_SEQ,
                :MWIPBINSSH_N.BIN_SEQ,
                :MWIPBINSSH_N.FACTORY,
                :MWIPBINSSH_N.LOT_ID,
                :MWIPBINSSH_N.LOT_HIST_SEQ,
                :MWIPBINSSH_N.BIN_ID,
                :MWIPBINSSH_N.BIN_VERSION,
                :MWIPBINSSH_N.BIN_UNIT,
                :MWIPBINSSH_N.BIN_PROMPT,
                :MWIPBINSSH_N.BIN_PROMPT_DESC,
                :MWIPBINSSH_N.BIN_QTY,
                :MWIPBINSSH_N.BIN_TYPE,
                :MWIPBINSSH_N.LOGICAL_BIN_FLAG,
                :MWIPBINSSH_N.USE_BIN_PROMPT_FAIL_REASON,
                :MWIPBINSSH_N.KEEP_LOT_QTY_FAIL,
                :MWIPBINSSH_N.FAIL_REASON_CODE,
                :MWIPBINSSH_N.LOW_YIELD_FLAG,
                :MWIPBINSSH_N.CHECK_RESULT,
                :MWIPBINSSH_N.TRAN_CODE,
                :MWIPBINSSH_N.TRAN_KEY_CODE_1,
                :MWIPBINSSH_N.TRAN_KEY_CODE_2,
                :MWIPBINSSH_N.TRAN_KEY_CODE_3,
                :MWIPBINSSH_N.TRAN_KEY_CODE_4,
                :MWIPBINSSH_N.TRAN_KEY_CODE_5,
                :MWIPBINSSH_N.TRAN_KEY_CODE_6,
                :MWIPBINSSH_N.TRAN_KEY_CODE_7,
                :MWIPBINSSH_N.TRAN_KEY_CODE_8,
                :MWIPBINSSH_N.TRAN_KEY_CODE_9,
                :MWIPBINSSH_N.TRAN_KEY_CODE_10,
                :MWIPBINSSH_N.BIN_COMMENT_1,
                :MWIPBINSSH_N.BIN_COMMENT_2,
                :MWIPBINSSH_N.BIN_COMMENT_3,
                :MWIPBINSSH_N.TRAN_COMMENT_1,
                :MWIPBINSSH_N.TRAN_COMMENT_2,
                :MWIPBINSSH_N.TRAN_COMMENT_3,
                :MWIPBINSSH_N.RESV_FIELD_1,
                :MWIPBINSSH_N.RESV_FIELD_2,
                :MWIPBINSSH_N.RESV_FIELD_3,
                :MWIPBINSSH_N.RESV_FIELD_4,
                :MWIPBINSSH_N.RESV_FIELD_5,
                :MWIPBINSSH_N.RESV_FIELD_6,
                :MWIPBINSSH_N.RESV_FIELD_7,
                :MWIPBINSSH_N.RESV_FIELD_8,
                :MWIPBINSSH_N.RESV_FIELD_9,
                :MWIPBINSSH_N.RESV_FIELD_10,
                :MWIPBINSSH_N.HIST_DEL_FLAG,
                :MWIPBINSSH_N.HIST_DEL_TIME,
                :MWIPBINSSH_N.HIST_DEL_USER_ID,
                :MWIPBINSSH_N.HIST_DEL_COMMENT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1135;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINSSH_N.SUBLOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPBINSSH_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINSSH_N.BIN_COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPBINSSH_N.BIN_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINSSH_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINSSH_N.LOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPBINSSH_N.LOT_HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINSSH_N.BIN_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPBINSSH_N.BIN_VERSION);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINSSH_N.BIN_UNIT);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINSSH_N.BIN_PROMPT);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPBINSSH_N.BIN_PROMPT_DESC);
            sqlstm.sqhstl[11] = (unsigned int  )201;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MWIPBINSSH_N.BIN_QTY);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPBINSSH_N.BIN_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINSSH_N.LOGICAL_BIN_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPBINSSH_N.USE_BIN_PROMPT_FAIL_REASON);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINSSH_N.KEEP_LOT_QTY_FAIL);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINSSH_N.FAIL_REASON_CODE);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPBINSSH_N.LOW_YIELD_FLAG);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPBINSSH_N.CHECK_RESULT);
            sqlstm.sqhstl[19] = (unsigned int  )4001;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINSSH_N.TRAN_CODE);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_1);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_2);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_3);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_4);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_5);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_6);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_7);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_8);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_9);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINSSH_N.TRAN_KEY_CODE_10);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_1);
            sqlstm.sqhstl[31] = (unsigned int  )401;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_2);
            sqlstm.sqhstl[32] = (unsigned int  )401;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINSSH_N.BIN_COMMENT_3);
            sqlstm.sqhstl[33] = (unsigned int  )401;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_1);
            sqlstm.sqhstl[34] = (unsigned int  )401;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_2);
            sqlstm.sqhstl[35] = (unsigned int  )401;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPBINSSH_N.TRAN_COMMENT_3);
            sqlstm.sqhstl[36] = (unsigned int  )401;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINSSH_N.RESV_FIELD_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINSSH_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINSSH_N.HIST_DEL_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINSSH_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINSSH_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[50] = (unsigned int  )401;
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


            break;


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }


    if(DB_error_code == 0)
    {
        DBC_del_null_mwipbinssh(&MWIPBINSSH_N, MWIPBINSSH);
    }

    DB_stop_query_timer("DBC_fetch_mwipbinssh", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mwipbinssh(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MWIPBINSSH_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 55;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1354;
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

    DB_stop_query_timer("DBC_close_mwipbinssh", sel_type);
}


/* Initialize Function */
void DBC_init_mwipbinssh(struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    /* memset by Space */
    memset(MWIPBINSSH, ' ', sizeof(struct MWIPBINSSH_TAG));
    
    MWIPBINSSH->HIST_SEQ = 0;
    MWIPBINSSH->BIN_COL_SEQ = 0;
    MWIPBINSSH->BIN_SEQ = 0;
    MWIPBINSSH->LOT_HIST_SEQ = 0;
    MWIPBINSSH->BIN_VERSION = 0;
    MWIPBINSSH->BIN_QTY = 0;
}


/* Add Null Function */
void DBC_add_null_mwipbinssh(struct MWIPBINSSH_N_TAG *MWIPBINSSH_N, struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    /* memset by NULL */
    memset(MWIPBINSSH_N, '\0', sizeof(struct MWIPBINSSH_N_TAG));
    
    MEMCPY_AN(MWIPBINSSH_N->SUBLOT_ID, MWIPBINSSH->SUBLOT_ID, sizeof(MWIPBINSSH->SUBLOT_ID));
    MWIPBINSSH_N->HIST_SEQ = MWIPBINSSH->HIST_SEQ;
    MWIPBINSSH_N->BIN_COL_SEQ = MWIPBINSSH->BIN_COL_SEQ;
    MWIPBINSSH_N->BIN_SEQ = MWIPBINSSH->BIN_SEQ;
    MEMCPY_AN(MWIPBINSSH_N->FACTORY, MWIPBINSSH->FACTORY, sizeof(MWIPBINSSH->FACTORY));
    MEMCPY_AN(MWIPBINSSH_N->LOT_ID, MWIPBINSSH->LOT_ID, sizeof(MWIPBINSSH->LOT_ID));
    MWIPBINSSH_N->LOT_HIST_SEQ = MWIPBINSSH->LOT_HIST_SEQ;
    MEMCPY_AN(MWIPBINSSH_N->BIN_ID, MWIPBINSSH->BIN_ID, sizeof(MWIPBINSSH->BIN_ID));
    MWIPBINSSH_N->BIN_VERSION = MWIPBINSSH->BIN_VERSION;
    MEMCPY_AN(MWIPBINSSH_N->BIN_UNIT, MWIPBINSSH->BIN_UNIT, sizeof(MWIPBINSSH->BIN_UNIT));
    MEMCPY_AN(MWIPBINSSH_N->BIN_PROMPT, MWIPBINSSH->BIN_PROMPT, sizeof(MWIPBINSSH->BIN_PROMPT));
    MEMCPY_AN(MWIPBINSSH_N->BIN_PROMPT_DESC, MWIPBINSSH->BIN_PROMPT_DESC, sizeof(MWIPBINSSH->BIN_PROMPT_DESC));
    MWIPBINSSH_N->BIN_QTY = MWIPBINSSH->BIN_QTY;
    MWIPBINSSH_N->BIN_TYPE[0] = MWIPBINSSH->BIN_TYPE;
    MWIPBINSSH_N->LOGICAL_BIN_FLAG[0] = MWIPBINSSH->LOGICAL_BIN_FLAG;
    MWIPBINSSH_N->USE_BIN_PROMPT_FAIL_REASON[0] = MWIPBINSSH->USE_BIN_PROMPT_FAIL_REASON;
    MWIPBINSSH_N->KEEP_LOT_QTY_FAIL[0] = MWIPBINSSH->KEEP_LOT_QTY_FAIL;
    MEMCPY_AN(MWIPBINSSH_N->FAIL_REASON_CODE, MWIPBINSSH->FAIL_REASON_CODE, sizeof(MWIPBINSSH->FAIL_REASON_CODE));
    MWIPBINSSH_N->LOW_YIELD_FLAG[0] = MWIPBINSSH->LOW_YIELD_FLAG;
    MEMCPY_AN(MWIPBINSSH_N->CHECK_RESULT, MWIPBINSSH->CHECK_RESULT, sizeof(MWIPBINSSH->CHECK_RESULT));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_CODE, MWIPBINSSH->TRAN_CODE, sizeof(MWIPBINSSH->TRAN_CODE));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_KEY_CODE_1, MWIPBINSSH->TRAN_KEY_CODE_1, sizeof(MWIPBINSSH->TRAN_KEY_CODE_1));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_KEY_CODE_2, MWIPBINSSH->TRAN_KEY_CODE_2, sizeof(MWIPBINSSH->TRAN_KEY_CODE_2));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_KEY_CODE_3, MWIPBINSSH->TRAN_KEY_CODE_3, sizeof(MWIPBINSSH->TRAN_KEY_CODE_3));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_KEY_CODE_4, MWIPBINSSH->TRAN_KEY_CODE_4, sizeof(MWIPBINSSH->TRAN_KEY_CODE_4));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_KEY_CODE_5, MWIPBINSSH->TRAN_KEY_CODE_5, sizeof(MWIPBINSSH->TRAN_KEY_CODE_5));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_KEY_CODE_6, MWIPBINSSH->TRAN_KEY_CODE_6, sizeof(MWIPBINSSH->TRAN_KEY_CODE_6));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_KEY_CODE_7, MWIPBINSSH->TRAN_KEY_CODE_7, sizeof(MWIPBINSSH->TRAN_KEY_CODE_7));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_KEY_CODE_8, MWIPBINSSH->TRAN_KEY_CODE_8, sizeof(MWIPBINSSH->TRAN_KEY_CODE_8));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_KEY_CODE_9, MWIPBINSSH->TRAN_KEY_CODE_9, sizeof(MWIPBINSSH->TRAN_KEY_CODE_9));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_KEY_CODE_10, MWIPBINSSH->TRAN_KEY_CODE_10, sizeof(MWIPBINSSH->TRAN_KEY_CODE_10));
    MEMCPY_AN(MWIPBINSSH_N->BIN_COMMENT_1, MWIPBINSSH->BIN_COMMENT_1, sizeof(MWIPBINSSH->BIN_COMMENT_1));
    MEMCPY_AN(MWIPBINSSH_N->BIN_COMMENT_2, MWIPBINSSH->BIN_COMMENT_2, sizeof(MWIPBINSSH->BIN_COMMENT_2));
    MEMCPY_AN(MWIPBINSSH_N->BIN_COMMENT_3, MWIPBINSSH->BIN_COMMENT_3, sizeof(MWIPBINSSH->BIN_COMMENT_3));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_COMMENT_1, MWIPBINSSH->TRAN_COMMENT_1, sizeof(MWIPBINSSH->TRAN_COMMENT_1));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_COMMENT_2, MWIPBINSSH->TRAN_COMMENT_2, sizeof(MWIPBINSSH->TRAN_COMMENT_2));
    MEMCPY_AN(MWIPBINSSH_N->TRAN_COMMENT_3, MWIPBINSSH->TRAN_COMMENT_3, sizeof(MWIPBINSSH->TRAN_COMMENT_3));
    MEMCPY_AN(MWIPBINSSH_N->RESV_FIELD_1, MWIPBINSSH->RESV_FIELD_1, sizeof(MWIPBINSSH->RESV_FIELD_1));
    MEMCPY_AN(MWIPBINSSH_N->RESV_FIELD_2, MWIPBINSSH->RESV_FIELD_2, sizeof(MWIPBINSSH->RESV_FIELD_2));
    MEMCPY_AN(MWIPBINSSH_N->RESV_FIELD_3, MWIPBINSSH->RESV_FIELD_3, sizeof(MWIPBINSSH->RESV_FIELD_3));
    MEMCPY_AN(MWIPBINSSH_N->RESV_FIELD_4, MWIPBINSSH->RESV_FIELD_4, sizeof(MWIPBINSSH->RESV_FIELD_4));
    MEMCPY_AN(MWIPBINSSH_N->RESV_FIELD_5, MWIPBINSSH->RESV_FIELD_5, sizeof(MWIPBINSSH->RESV_FIELD_5));
    MEMCPY_AN(MWIPBINSSH_N->RESV_FIELD_6, MWIPBINSSH->RESV_FIELD_6, sizeof(MWIPBINSSH->RESV_FIELD_6));
    MEMCPY_AN(MWIPBINSSH_N->RESV_FIELD_7, MWIPBINSSH->RESV_FIELD_7, sizeof(MWIPBINSSH->RESV_FIELD_7));
    MEMCPY_AN(MWIPBINSSH_N->RESV_FIELD_8, MWIPBINSSH->RESV_FIELD_8, sizeof(MWIPBINSSH->RESV_FIELD_8));
    MEMCPY_AN(MWIPBINSSH_N->RESV_FIELD_9, MWIPBINSSH->RESV_FIELD_9, sizeof(MWIPBINSSH->RESV_FIELD_9));
    MEMCPY_AN(MWIPBINSSH_N->RESV_FIELD_10, MWIPBINSSH->RESV_FIELD_10, sizeof(MWIPBINSSH->RESV_FIELD_10));
    MWIPBINSSH_N->HIST_DEL_FLAG[0] = MWIPBINSSH->HIST_DEL_FLAG;
    MEMCPY_AN(MWIPBINSSH_N->HIST_DEL_TIME, MWIPBINSSH->HIST_DEL_TIME, sizeof(MWIPBINSSH->HIST_DEL_TIME));
    MEMCPY_AN(MWIPBINSSH_N->HIST_DEL_USER_ID, MWIPBINSSH->HIST_DEL_USER_ID, sizeof(MWIPBINSSH->HIST_DEL_USER_ID));
    MEMCPY_AN(MWIPBINSSH_N->HIST_DEL_COMMENT, MWIPBINSSH->HIST_DEL_COMMENT, sizeof(MWIPBINSSH->HIST_DEL_COMMENT));
}


/* Del Null Function */
void DBC_del_null_mwipbinssh(struct MWIPBINSSH_N_TAG *MWIPBINSSH_N, struct MWIPBINSSH_TAG *MWIPBINSSH)
{
    MEMCPY_DN(MWIPBINSSH->SUBLOT_ID, MWIPBINSSH_N->SUBLOT_ID, sizeof(MWIPBINSSH->SUBLOT_ID));
    MWIPBINSSH->HIST_SEQ = MWIPBINSSH_N->HIST_SEQ;
    MWIPBINSSH->BIN_COL_SEQ = MWIPBINSSH_N->BIN_COL_SEQ;
    MWIPBINSSH->BIN_SEQ = MWIPBINSSH_N->BIN_SEQ;
    MEMCPY_DN(MWIPBINSSH->FACTORY, MWIPBINSSH_N->FACTORY, sizeof(MWIPBINSSH->FACTORY));
    MEMCPY_DN(MWIPBINSSH->LOT_ID, MWIPBINSSH_N->LOT_ID, sizeof(MWIPBINSSH->LOT_ID));
    MWIPBINSSH->LOT_HIST_SEQ = MWIPBINSSH_N->LOT_HIST_SEQ;
    MEMCPY_DN(MWIPBINSSH->BIN_ID, MWIPBINSSH_N->BIN_ID, sizeof(MWIPBINSSH->BIN_ID));
    MWIPBINSSH->BIN_VERSION = MWIPBINSSH_N->BIN_VERSION;
    MEMCPY_DN(MWIPBINSSH->BIN_UNIT, MWIPBINSSH_N->BIN_UNIT, sizeof(MWIPBINSSH->BIN_UNIT));
    MEMCPY_DN(MWIPBINSSH->BIN_PROMPT, MWIPBINSSH_N->BIN_PROMPT, sizeof(MWIPBINSSH->BIN_PROMPT));
    MEMCPY_DN(MWIPBINSSH->BIN_PROMPT_DESC, MWIPBINSSH_N->BIN_PROMPT_DESC, sizeof(MWIPBINSSH->BIN_PROMPT_DESC));
    MWIPBINSSH->BIN_QTY = MWIPBINSSH_N->BIN_QTY;
    MWIPBINSSH->BIN_TYPE = MWIPBINSSH_N->BIN_TYPE[0];
    MWIPBINSSH->LOGICAL_BIN_FLAG = MWIPBINSSH_N->LOGICAL_BIN_FLAG[0];
    MWIPBINSSH->USE_BIN_PROMPT_FAIL_REASON = MWIPBINSSH_N->USE_BIN_PROMPT_FAIL_REASON[0];
    MWIPBINSSH->KEEP_LOT_QTY_FAIL = MWIPBINSSH_N->KEEP_LOT_QTY_FAIL[0];
    MEMCPY_DN(MWIPBINSSH->FAIL_REASON_CODE, MWIPBINSSH_N->FAIL_REASON_CODE, sizeof(MWIPBINSSH->FAIL_REASON_CODE));
    MWIPBINSSH->LOW_YIELD_FLAG = MWIPBINSSH_N->LOW_YIELD_FLAG[0];
    MEMCPY_DN(MWIPBINSSH->CHECK_RESULT, MWIPBINSSH_N->CHECK_RESULT, sizeof(MWIPBINSSH->CHECK_RESULT));
    MEMCPY_DN(MWIPBINSSH->TRAN_CODE, MWIPBINSSH_N->TRAN_CODE, sizeof(MWIPBINSSH->TRAN_CODE));
    MEMCPY_DN(MWIPBINSSH->TRAN_KEY_CODE_1, MWIPBINSSH_N->TRAN_KEY_CODE_1, sizeof(MWIPBINSSH->TRAN_KEY_CODE_1));
    MEMCPY_DN(MWIPBINSSH->TRAN_KEY_CODE_2, MWIPBINSSH_N->TRAN_KEY_CODE_2, sizeof(MWIPBINSSH->TRAN_KEY_CODE_2));
    MEMCPY_DN(MWIPBINSSH->TRAN_KEY_CODE_3, MWIPBINSSH_N->TRAN_KEY_CODE_3, sizeof(MWIPBINSSH->TRAN_KEY_CODE_3));
    MEMCPY_DN(MWIPBINSSH->TRAN_KEY_CODE_4, MWIPBINSSH_N->TRAN_KEY_CODE_4, sizeof(MWIPBINSSH->TRAN_KEY_CODE_4));
    MEMCPY_DN(MWIPBINSSH->TRAN_KEY_CODE_5, MWIPBINSSH_N->TRAN_KEY_CODE_5, sizeof(MWIPBINSSH->TRAN_KEY_CODE_5));
    MEMCPY_DN(MWIPBINSSH->TRAN_KEY_CODE_6, MWIPBINSSH_N->TRAN_KEY_CODE_6, sizeof(MWIPBINSSH->TRAN_KEY_CODE_6));
    MEMCPY_DN(MWIPBINSSH->TRAN_KEY_CODE_7, MWIPBINSSH_N->TRAN_KEY_CODE_7, sizeof(MWIPBINSSH->TRAN_KEY_CODE_7));
    MEMCPY_DN(MWIPBINSSH->TRAN_KEY_CODE_8, MWIPBINSSH_N->TRAN_KEY_CODE_8, sizeof(MWIPBINSSH->TRAN_KEY_CODE_8));
    MEMCPY_DN(MWIPBINSSH->TRAN_KEY_CODE_9, MWIPBINSSH_N->TRAN_KEY_CODE_9, sizeof(MWIPBINSSH->TRAN_KEY_CODE_9));
    MEMCPY_DN(MWIPBINSSH->TRAN_KEY_CODE_10, MWIPBINSSH_N->TRAN_KEY_CODE_10, sizeof(MWIPBINSSH->TRAN_KEY_CODE_10));
    MEMCPY_DN(MWIPBINSSH->BIN_COMMENT_1, MWIPBINSSH_N->BIN_COMMENT_1, sizeof(MWIPBINSSH->BIN_COMMENT_1));
    MEMCPY_DN(MWIPBINSSH->BIN_COMMENT_2, MWIPBINSSH_N->BIN_COMMENT_2, sizeof(MWIPBINSSH->BIN_COMMENT_2));
    MEMCPY_DN(MWIPBINSSH->BIN_COMMENT_3, MWIPBINSSH_N->BIN_COMMENT_3, sizeof(MWIPBINSSH->BIN_COMMENT_3));
    MEMCPY_DN(MWIPBINSSH->TRAN_COMMENT_1, MWIPBINSSH_N->TRAN_COMMENT_1, sizeof(MWIPBINSSH->TRAN_COMMENT_1));
    MEMCPY_DN(MWIPBINSSH->TRAN_COMMENT_2, MWIPBINSSH_N->TRAN_COMMENT_2, sizeof(MWIPBINSSH->TRAN_COMMENT_2));
    MEMCPY_DN(MWIPBINSSH->TRAN_COMMENT_3, MWIPBINSSH_N->TRAN_COMMENT_3, sizeof(MWIPBINSSH->TRAN_COMMENT_3));
    MEMCPY_DN(MWIPBINSSH->RESV_FIELD_1, MWIPBINSSH_N->RESV_FIELD_1, sizeof(MWIPBINSSH->RESV_FIELD_1));
    MEMCPY_DN(MWIPBINSSH->RESV_FIELD_2, MWIPBINSSH_N->RESV_FIELD_2, sizeof(MWIPBINSSH->RESV_FIELD_2));
    MEMCPY_DN(MWIPBINSSH->RESV_FIELD_3, MWIPBINSSH_N->RESV_FIELD_3, sizeof(MWIPBINSSH->RESV_FIELD_3));
    MEMCPY_DN(MWIPBINSSH->RESV_FIELD_4, MWIPBINSSH_N->RESV_FIELD_4, sizeof(MWIPBINSSH->RESV_FIELD_4));
    MEMCPY_DN(MWIPBINSSH->RESV_FIELD_5, MWIPBINSSH_N->RESV_FIELD_5, sizeof(MWIPBINSSH->RESV_FIELD_5));
    MEMCPY_DN(MWIPBINSSH->RESV_FIELD_6, MWIPBINSSH_N->RESV_FIELD_6, sizeof(MWIPBINSSH->RESV_FIELD_6));
    MEMCPY_DN(MWIPBINSSH->RESV_FIELD_7, MWIPBINSSH_N->RESV_FIELD_7, sizeof(MWIPBINSSH->RESV_FIELD_7));
    MEMCPY_DN(MWIPBINSSH->RESV_FIELD_8, MWIPBINSSH_N->RESV_FIELD_8, sizeof(MWIPBINSSH->RESV_FIELD_8));
    MEMCPY_DN(MWIPBINSSH->RESV_FIELD_9, MWIPBINSSH_N->RESV_FIELD_9, sizeof(MWIPBINSSH->RESV_FIELD_9));
    MEMCPY_DN(MWIPBINSSH->RESV_FIELD_10, MWIPBINSSH_N->RESV_FIELD_10, sizeof(MWIPBINSSH->RESV_FIELD_10));
    MWIPBINSSH->HIST_DEL_FLAG = MWIPBINSSH_N->HIST_DEL_FLAG[0];
    MEMCPY_DN(MWIPBINSSH->HIST_DEL_TIME, MWIPBINSSH_N->HIST_DEL_TIME, sizeof(MWIPBINSSH->HIST_DEL_TIME));
    MEMCPY_DN(MWIPBINSSH->HIST_DEL_USER_ID, MWIPBINSSH_N->HIST_DEL_USER_ID, sizeof(MWIPBINSSH->HIST_DEL_USER_ID));
    MEMCPY_DN(MWIPBINSSH->HIST_DEL_COMMENT, MWIPBINSSH_N->HIST_DEL_COMMENT, sizeof(MWIPBINSSH->HIST_DEL_COMMENT));
}


