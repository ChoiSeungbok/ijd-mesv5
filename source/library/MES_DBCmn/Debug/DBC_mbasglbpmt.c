
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
    "DBC_mbasglbpmt.pc"
};


static unsigned int sqlctx = 9091723;


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
            void  *sqhstv[23];
   unsigned int   sqhstl[23];
            int   sqhsts[23];
            void  *sqindv[23];
            int   sqinds[23];
   unsigned int   sqharm[23];
   unsigned int   *sqharc[23];
   unsigned short  sqadto[23];
   unsigned short  sqtdso[23];
} sqlstm = {13,23};

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
"select OPTION_NAME ,OPTION_DESC ,MESPLUS_FLAG ,VALUE_PMT_1 ,VALUE_PMT_2 ,VA\
LUE_PMT_3 ,VALUE_PMT_4 ,VALUE_PMT_5 ,VALUE_FMT_1 ,VALUE_FMT_2 ,VALUE_FMT_3 ,V\
ALUE_FMT_4 ,VALUE_FMT_5 ,VALUE_TBL_1 ,VALUE_TBL_2 ,VALUE_TBL_3 ,VALUE_TBL_4 ,\
VALUE_TBL_5 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from M\
BASGLBPMT  order by OPTION_NAME asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,442,0,4,44,0,0,23,1,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,
0,0,
112,0,0,2,454,0,4,126,0,0,23,1,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1,97,0,0,
219,0,0,3,64,0,4,211,0,0,2,1,0,1,0,2,4,0,0,1,97,0,0,
242,0,0,4,46,0,2,245,0,0,1,1,0,1,0,1,97,0,0,
261,0,0,5,404,0,3,272,0,0,22,22,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
364,0,0,6,399,0,5,339,0,0,22,22,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
467,0,0,7,354,0,9,416,0,0,0,0,0,1,0,
482,0,0,7,0,0,13,444,0,0,22,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
585,0,0,7,0,0,15,496,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mbasglbpmt.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2009/11/23 11:41:14
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
void DBC_add_null_mbasglbpmt(struct MBASGLBPMT_N_TAG *MBASGLBPMT_N, struct MBASGLBPMT_TAG *MBASGLBPMT);
void DBC_del_null_mbasglbpmt(struct MBASGLBPMT_N_TAG *MBASGLBPMT_N, struct MBASGLBPMT_TAG *MBASGLBPMT);


/* SQL SELECT Function */
void DBC_select_mbasglbpmt(int sel_type, struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASGLBPMT_N_TAG MBASGLBPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbasglbpmt(&MBASGLBPMT_N, MBASGLBPMT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         OPTION_NAME,
                         OPTION_DESC,
                         MESPLUS_FLAG,
                         VALUE_PMT_1,
                         VALUE_PMT_2,
                         VALUE_PMT_3,
                         VALUE_PMT_4,
                         VALUE_PMT_5,
                         VALUE_FMT_1,
                         VALUE_FMT_2,
                         VALUE_FMT_3,
                         VALUE_FMT_4,
                         VALUE_FMT_5,
                         VALUE_TBL_1,
                         VALUE_TBL_2,
                         VALUE_TBL_3,
                         VALUE_TBL_4,
                         VALUE_TBL_5,
                         CREATE_USER_ID,
                         CREATE_TIME,
                         UPDATE_USER_ID,
                         UPDATE_TIME
                INTO 
                    :MBASGLBPMT_N.OPTION_NAME,
                    :MBASGLBPMT_N.OPTION_DESC,
                    :MBASGLBPMT_N.MESPLUS_FLAG,
                    :MBASGLBPMT_N.VALUE_PMT_1,
                    :MBASGLBPMT_N.VALUE_PMT_2,
                    :MBASGLBPMT_N.VALUE_PMT_3,
                    :MBASGLBPMT_N.VALUE_PMT_4,
                    :MBASGLBPMT_N.VALUE_PMT_5,
                    :MBASGLBPMT_N.VALUE_FMT_1,
                    :MBASGLBPMT_N.VALUE_FMT_2,
                    :MBASGLBPMT_N.VALUE_FMT_3,
                    :MBASGLBPMT_N.VALUE_FMT_4,
                    :MBASGLBPMT_N.VALUE_FMT_5,
                    :MBASGLBPMT_N.VALUE_TBL_1,
                    :MBASGLBPMT_N.VALUE_TBL_2,
                    :MBASGLBPMT_N.VALUE_TBL_3,
                    :MBASGLBPMT_N.VALUE_TBL_4,
                    :MBASGLBPMT_N.VALUE_TBL_5,
                    :MBASGLBPMT_N.CREATE_USER_ID,
                    :MBASGLBPMT_N.CREATE_TIME,
                    :MBASGLBPMT_N.UPDATE_USER_ID,
                    :MBASGLBPMT_N.UPDATE_TIME
                FROM MBASGLBPMT
                WHERE OPTION_NAME = :MBASGLBPMT_N.OPTION_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 23;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select OPTION_NAME ,OPTION_DESC ,MESPLUS_FLAG ,V\
ALUE_PMT_1 ,VALUE_PMT_2 ,VALUE_PMT_3 ,VALUE_PMT_4 ,VALUE_PMT_5 ,VALUE_FMT_1 ,\
VALUE_FMT_2 ,VALUE_FMT_3 ,VALUE_FMT_4 ,VALUE_FMT_5 ,VALUE_TBL_1 ,VALUE_TBL_2 \
,VALUE_TBL_3 ,VALUE_TBL_4 ,VALUE_TBL_5 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_U\
SER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b\
12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21  from MBASGLBPMT where OPTION\
_NAME=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASGLBPMT_N.OPTION_NAME);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASGLBPMT_N.OPTION_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASGLBPMT_N.MESPLUS_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_1);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_2);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_3);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_4);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_5);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_1);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_2);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_3);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_4);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_5);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_1);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_2);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_3);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_4);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_5);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MBASGLBPMT_N.CREATE_USER_ID);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MBASGLBPMT_N.CREATE_TIME);
            sqlstm.sqhstl[19] = (unsigned int  )15;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MBASGLBPMT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MBASGLBPMT_N.UPDATE_TIME);
            sqlstm.sqhstl[21] = (unsigned int  )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MBASGLBPMT_N.OPTION_NAME);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
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
        DBC_del_null_mbasglbpmt(&MBASGLBPMT_N, MBASGLBPMT);
    }
    DB_stop_query_timer("DBC_select_mbasglbpmt", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mbasglbpmt_for_update(int sel_type, struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASGLBPMT_N_TAG MBASGLBPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbasglbpmt(&MBASGLBPMT_N, MBASGLBPMT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         OPTION_NAME,
                         OPTION_DESC,
                         MESPLUS_FLAG,
                         VALUE_PMT_1,
                         VALUE_PMT_2,
                         VALUE_PMT_3,
                         VALUE_PMT_4,
                         VALUE_PMT_5,
                         VALUE_FMT_1,
                         VALUE_FMT_2,
                         VALUE_FMT_3,
                         VALUE_FMT_4,
                         VALUE_FMT_5,
                         VALUE_TBL_1,
                         VALUE_TBL_2,
                         VALUE_TBL_3,
                         VALUE_TBL_4,
                         VALUE_TBL_5,
                         CREATE_USER_ID,
                         CREATE_TIME,
                         UPDATE_USER_ID,
                         UPDATE_TIME
                INTO 
                    :MBASGLBPMT_N.OPTION_NAME,
                    :MBASGLBPMT_N.OPTION_DESC,
                    :MBASGLBPMT_N.MESPLUS_FLAG,
                    :MBASGLBPMT_N.VALUE_PMT_1,
                    :MBASGLBPMT_N.VALUE_PMT_2,
                    :MBASGLBPMT_N.VALUE_PMT_3,
                    :MBASGLBPMT_N.VALUE_PMT_4,
                    :MBASGLBPMT_N.VALUE_PMT_5,
                    :MBASGLBPMT_N.VALUE_FMT_1,
                    :MBASGLBPMT_N.VALUE_FMT_2,
                    :MBASGLBPMT_N.VALUE_FMT_3,
                    :MBASGLBPMT_N.VALUE_FMT_4,
                    :MBASGLBPMT_N.VALUE_FMT_5,
                    :MBASGLBPMT_N.VALUE_TBL_1,
                    :MBASGLBPMT_N.VALUE_TBL_2,
                    :MBASGLBPMT_N.VALUE_TBL_3,
                    :MBASGLBPMT_N.VALUE_TBL_4,
                    :MBASGLBPMT_N.VALUE_TBL_5,
                    :MBASGLBPMT_N.CREATE_USER_ID,
                    :MBASGLBPMT_N.CREATE_TIME,
                    :MBASGLBPMT_N.UPDATE_USER_ID,
                    :MBASGLBPMT_N.UPDATE_TIME
                FROM MBASGLBPMT
                WHERE OPTION_NAME = :MBASGLBPMT_N.OPTION_NAME
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 23;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select OPTION_NAME ,OPTION_DESC ,MESPLUS_FLAG ,V\
ALUE_PMT_1 ,VALUE_PMT_2 ,VALUE_PMT_3 ,VALUE_PMT_4 ,VALUE_PMT_5 ,VALUE_FMT_1 ,\
VALUE_FMT_2 ,VALUE_FMT_3 ,VALUE_FMT_4 ,VALUE_FMT_5 ,VALUE_TBL_1 ,VALUE_TBL_2 \
,VALUE_TBL_3 ,VALUE_TBL_4 ,VALUE_TBL_5 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_U\
SER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b\
12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21  from MBASGLBPMT where OPTION\
_NAME=:b0 for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )112;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASGLBPMT_N.OPTION_NAME);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASGLBPMT_N.OPTION_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASGLBPMT_N.MESPLUS_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_1);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_2);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_3);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_4);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_5);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_1);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_2);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_3);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_4);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_5);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_1);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_2);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_3);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_4);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_5);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MBASGLBPMT_N.CREATE_USER_ID);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MBASGLBPMT_N.CREATE_TIME);
            sqlstm.sqhstl[19] = (unsigned int  )15;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MBASGLBPMT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MBASGLBPMT_N.UPDATE_TIME);
            sqlstm.sqhstl[21] = (unsigned int  )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MBASGLBPMT_N.OPTION_NAME);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
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
        DBC_del_null_mbasglbpmt(&MBASGLBPMT_N, MBASGLBPMT);
    }
    DB_stop_query_timer("DBC_select_mbasglbpmt_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mbasglbpmt_scalar(int sel_type, struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASGLBPMT_N_TAG MBASGLBPMT_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbasglbpmt(&MBASGLBPMT_N, MBASGLBPMT);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MBASGLBPMT
                WHERE OPTION_NAME = :MBASGLBPMT_N.OPTION_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 23;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MBASGLBPMT where\
 OPTION_NAME=:b1";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )219;
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
            sqlstm.sqhstv[1] = (         void  *)(MBASGLBPMT_N.OPTION_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )31;
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

    DB_stop_query_timer("DBC_select_mbasglbpmt_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mbasglbpmt(int sel_type, struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASGLBPMT_N_TAG MBASGLBPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbasglbpmt(&MBASGLBPMT_N, MBASGLBPMT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MBASGLBPMT
                WHERE OPTION_NAME = :MBASGLBPMT_N.OPTION_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 23;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MBASGLBPMT  where OPTION_NAME=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )242;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASGLBPMT_N.OPTION_NAME);
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
    DB_stop_query_timer("DBC_delete_mbasglbpmt", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mbasglbpmt(struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASGLBPMT_N_TAG MBASGLBPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbasglbpmt(&MBASGLBPMT_N, MBASGLBPMT);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MBASGLBPMT (
                    OPTION_NAME,
                    OPTION_DESC,
                    MESPLUS_FLAG,
                    VALUE_PMT_1,
                    VALUE_PMT_2,
                    VALUE_PMT_3,
                    VALUE_PMT_4,
                    VALUE_PMT_5,
                    VALUE_FMT_1,
                    VALUE_FMT_2,
                    VALUE_FMT_3,
                    VALUE_FMT_4,
                    VALUE_FMT_5,
                    VALUE_TBL_1,
                    VALUE_TBL_2,
                    VALUE_TBL_3,
                    VALUE_TBL_4,
                    VALUE_TBL_5,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
        )
        VALUES (
                    :MBASGLBPMT_N.OPTION_NAME,
                    :MBASGLBPMT_N.OPTION_DESC,
                    :MBASGLBPMT_N.MESPLUS_FLAG,
                    :MBASGLBPMT_N.VALUE_PMT_1,
                    :MBASGLBPMT_N.VALUE_PMT_2,
                    :MBASGLBPMT_N.VALUE_PMT_3,
                    :MBASGLBPMT_N.VALUE_PMT_4,
                    :MBASGLBPMT_N.VALUE_PMT_5,
                    :MBASGLBPMT_N.VALUE_FMT_1,
                    :MBASGLBPMT_N.VALUE_FMT_2,
                    :MBASGLBPMT_N.VALUE_FMT_3,
                    :MBASGLBPMT_N.VALUE_FMT_4,
                    :MBASGLBPMT_N.VALUE_FMT_5,
                    :MBASGLBPMT_N.VALUE_TBL_1,
                    :MBASGLBPMT_N.VALUE_TBL_2,
                    :MBASGLBPMT_N.VALUE_TBL_3,
                    :MBASGLBPMT_N.VALUE_TBL_4,
                    :MBASGLBPMT_N.VALUE_TBL_5,
                    :MBASGLBPMT_N.CREATE_USER_ID,
                    :MBASGLBPMT_N.CREATE_TIME,
                    :MBASGLBPMT_N.UPDATE_USER_ID,
                    :MBASGLBPMT_N.UPDATE_TIME
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 23;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into MBASGLBPMT (OPTION_NAME,OPTION_DESC,MESPLUS_\
FLAG,VALUE_PMT_1,VALUE_PMT_2,VALUE_PMT_3,VALUE_PMT_4,VALUE_PMT_5,VALUE_FMT_1,\
VALUE_FMT_2,VALUE_FMT_3,VALUE_FMT_4,VALUE_FMT_5,VALUE_TBL_1,VALUE_TBL_2,VALUE\
_TBL_3,VALUE_TBL_4,VALUE_TBL_5,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDA\
TE_TIME) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,\
:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )261;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MBASGLBPMT_N.OPTION_NAME);
    sqlstm.sqhstl[0] = (unsigned int  )31;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MBASGLBPMT_N.OPTION_DESC);
    sqlstm.sqhstl[1] = (unsigned int  )201;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MBASGLBPMT_N.MESPLUS_FLAG);
    sqlstm.sqhstl[2] = (unsigned int  )2;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_1);
    sqlstm.sqhstl[3] = (unsigned int  )21;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_2);
    sqlstm.sqhstl[4] = (unsigned int  )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_3);
    sqlstm.sqhstl[5] = (unsigned int  )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_4);
    sqlstm.sqhstl[6] = (unsigned int  )21;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_5);
    sqlstm.sqhstl[7] = (unsigned int  )21;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_1);
    sqlstm.sqhstl[8] = (unsigned int  )2;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_2);
    sqlstm.sqhstl[9] = (unsigned int  )2;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_3);
    sqlstm.sqhstl[10] = (unsigned int  )2;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_4);
    sqlstm.sqhstl[11] = (unsigned int  )2;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_5);
    sqlstm.sqhstl[12] = (unsigned int  )2;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_1);
    sqlstm.sqhstl[13] = (unsigned int  )21;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_2);
    sqlstm.sqhstl[14] = (unsigned int  )21;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_3);
    sqlstm.sqhstl[15] = (unsigned int  )21;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_4);
    sqlstm.sqhstl[16] = (unsigned int  )21;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_5);
    sqlstm.sqhstl[17] = (unsigned int  )21;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MBASGLBPMT_N.CREATE_USER_ID);
    sqlstm.sqhstl[18] = (unsigned int  )21;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MBASGLBPMT_N.CREATE_TIME);
    sqlstm.sqhstl[19] = (unsigned int  )15;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MBASGLBPMT_N.UPDATE_USER_ID);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MBASGLBPMT_N.UPDATE_TIME);
    sqlstm.sqhstl[21] = (unsigned int  )15;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
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


    DB_stop_query_timer("DBC_insert_mbasglbpmt", 0);
}


/* SQL UPDATE Function */
void DBC_update_mbasglbpmt(int sel_type, struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASGLBPMT_N_TAG MBASGLBPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbasglbpmt(&MBASGLBPMT_N, MBASGLBPMT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MBASGLBPMT SET
                    OPTION_DESC = :MBASGLBPMT_N.OPTION_DESC,
                    MESPLUS_FLAG = :MBASGLBPMT_N.MESPLUS_FLAG,
                    VALUE_PMT_1 = :MBASGLBPMT_N.VALUE_PMT_1,
                    VALUE_PMT_2 = :MBASGLBPMT_N.VALUE_PMT_2,
                    VALUE_PMT_3 = :MBASGLBPMT_N.VALUE_PMT_3,
                    VALUE_PMT_4 = :MBASGLBPMT_N.VALUE_PMT_4,
                    VALUE_PMT_5 = :MBASGLBPMT_N.VALUE_PMT_5,
                    VALUE_FMT_1 = :MBASGLBPMT_N.VALUE_FMT_1,
                    VALUE_FMT_2 = :MBASGLBPMT_N.VALUE_FMT_2,
                    VALUE_FMT_3 = :MBASGLBPMT_N.VALUE_FMT_3,
                    VALUE_FMT_4 = :MBASGLBPMT_N.VALUE_FMT_4,
                    VALUE_FMT_5 = :MBASGLBPMT_N.VALUE_FMT_5,
                    VALUE_TBL_1 = :MBASGLBPMT_N.VALUE_TBL_1,
                    VALUE_TBL_2 = :MBASGLBPMT_N.VALUE_TBL_2,
                    VALUE_TBL_3 = :MBASGLBPMT_N.VALUE_TBL_3,
                    VALUE_TBL_4 = :MBASGLBPMT_N.VALUE_TBL_4,
                    VALUE_TBL_5 = :MBASGLBPMT_N.VALUE_TBL_5,
                    CREATE_USER_ID = :MBASGLBPMT_N.CREATE_USER_ID,
                    CREATE_TIME = :MBASGLBPMT_N.CREATE_TIME,
                    UPDATE_USER_ID = :MBASGLBPMT_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MBASGLBPMT_N.UPDATE_TIME
                WHERE OPTION_NAME = :MBASGLBPMT_N.OPTION_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 23;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MBASGLBPMT  set OPTION_DESC=:b0,MESPLUS_F\
LAG=:b1,VALUE_PMT_1=:b2,VALUE_PMT_2=:b3,VALUE_PMT_3=:b4,VALUE_PMT_4=:b5,VALUE\
_PMT_5=:b6,VALUE_FMT_1=:b7,VALUE_FMT_2=:b8,VALUE_FMT_3=:b9,VALUE_FMT_4=:b10,V\
ALUE_FMT_5=:b11,VALUE_TBL_1=:b12,VALUE_TBL_2=:b13,VALUE_TBL_3=:b14,VALUE_TBL_\
4=:b15,VALUE_TBL_5=:b16,CREATE_USER_ID=:b17,CREATE_TIME=:b18,UPDATE_USER_ID=:\
b19,UPDATE_TIME=:b20 where OPTION_NAME=:b21";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )364;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASGLBPMT_N.OPTION_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASGLBPMT_N.MESPLUS_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_1);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_2);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_3);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_4);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_5);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_1);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_2);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_3);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_4);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_5);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_1);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_2);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_3);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_4);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_5);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MBASGLBPMT_N.CREATE_USER_ID);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MBASGLBPMT_N.CREATE_TIME);
            sqlstm.sqhstl[18] = (unsigned int  )15;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MBASGLBPMT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MBASGLBPMT_N.UPDATE_TIME);
            sqlstm.sqhstl[20] = (unsigned int  )15;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MBASGLBPMT_N.OPTION_NAME);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
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
    DB_stop_query_timer("DBC_update_mbasglbpmt", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mbasglbpmt(int sel_type, struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASGLBPMT_N_TAG MBASGLBPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbasglbpmt(&MBASGLBPMT_N, MBASGLBPMT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MBASGLBPMT_CUR_1 CURSOR FOR
                SELECT 
                    OPTION_NAME,
                    OPTION_DESC,
                    MESPLUS_FLAG,
                    VALUE_PMT_1,
                    VALUE_PMT_2,
                    VALUE_PMT_3,
                    VALUE_PMT_4,
                    VALUE_PMT_5,
                    VALUE_FMT_1,
                    VALUE_FMT_2,
                    VALUE_FMT_3,
                    VALUE_FMT_4,
                    VALUE_FMT_5,
                    VALUE_TBL_1,
                    VALUE_TBL_2,
                    VALUE_TBL_3,
                    VALUE_TBL_4,
                    VALUE_TBL_5,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM MBASGLBPMT
                ORDER BY OPTION_NAME ASC; */ 

            /* EXEC SQL OPEN DBC_MBASGLBPMT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 23;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )467;
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
    DB_stop_query_timer("DBC_open_mbasglbpmt", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mbasglbpmt(int sel_type, struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASGLBPMT_N_TAG MBASGLBPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MBASGLBPMT_CUR_1 INTO 
                                                    :MBASGLBPMT_N.OPTION_NAME,
                                                    :MBASGLBPMT_N.OPTION_DESC,
                                                    :MBASGLBPMT_N.MESPLUS_FLAG,
                                                    :MBASGLBPMT_N.VALUE_PMT_1,
                                                    :MBASGLBPMT_N.VALUE_PMT_2,
                                                    :MBASGLBPMT_N.VALUE_PMT_3,
                                                    :MBASGLBPMT_N.VALUE_PMT_4,
                                                    :MBASGLBPMT_N.VALUE_PMT_5,
                                                    :MBASGLBPMT_N.VALUE_FMT_1,
                                                    :MBASGLBPMT_N.VALUE_FMT_2,
                                                    :MBASGLBPMT_N.VALUE_FMT_3,
                                                    :MBASGLBPMT_N.VALUE_FMT_4,
                                                    :MBASGLBPMT_N.VALUE_FMT_5,
                                                    :MBASGLBPMT_N.VALUE_TBL_1,
                                                    :MBASGLBPMT_N.VALUE_TBL_2,
                                                    :MBASGLBPMT_N.VALUE_TBL_3,
                                                    :MBASGLBPMT_N.VALUE_TBL_4,
                                                    :MBASGLBPMT_N.VALUE_TBL_5,
                                                    :MBASGLBPMT_N.CREATE_USER_ID,
                                                    :MBASGLBPMT_N.CREATE_TIME,
                                                    :MBASGLBPMT_N.UPDATE_USER_ID,
                                                    :MBASGLBPMT_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 23;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )482;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MBASGLBPMT_N.OPTION_NAME);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASGLBPMT_N.OPTION_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASGLBPMT_N.MESPLUS_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_1);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_2);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_3);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_4);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MBASGLBPMT_N.VALUE_PMT_5);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_1);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_2);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_3);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_4);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MBASGLBPMT_N.VALUE_FMT_5);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_1);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_2);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_3);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_4);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MBASGLBPMT_N.VALUE_TBL_5);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MBASGLBPMT_N.CREATE_USER_ID);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MBASGLBPMT_N.CREATE_TIME);
            sqlstm.sqhstl[19] = (unsigned int  )15;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MBASGLBPMT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MBASGLBPMT_N.UPDATE_TIME);
            sqlstm.sqhstl[21] = (unsigned int  )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
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
        DBC_del_null_mbasglbpmt(&MBASGLBPMT_N, MBASGLBPMT);
    }
    DB_stop_query_timer("DBC_fetch_mbasglbpmt", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mbasglbpmt(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MBASGLBPMT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 23;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )585;
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
    DB_stop_query_timer("DBC_close_mbasglbpmt", sel_type);
}


/* Initialize Function */
void DBC_init_mbasglbpmt(struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    /* memset by Space */
    memset(MBASGLBPMT, ' ', sizeof(struct MBASGLBPMT_TAG));
    
}


/* Add Null Function */
void DBC_add_null_mbasglbpmt(struct MBASGLBPMT_N_TAG *MBASGLBPMT_N, struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    /* memset by NULL */
    memset(MBASGLBPMT_N, '\0', sizeof(struct MBASGLBPMT_N_TAG));
    
    MEMCPY_AN(MBASGLBPMT_N->OPTION_NAME, MBASGLBPMT->OPTION_NAME, sizeof(MBASGLBPMT->OPTION_NAME));
    MEMCPY_AN(MBASGLBPMT_N->OPTION_DESC, MBASGLBPMT->OPTION_DESC, sizeof(MBASGLBPMT->OPTION_DESC));
    MBASGLBPMT_N->MESPLUS_FLAG[0] = MBASGLBPMT->MESPLUS_FLAG;
    MEMCPY_AN(MBASGLBPMT_N->VALUE_PMT_1, MBASGLBPMT->VALUE_PMT_1, sizeof(MBASGLBPMT->VALUE_PMT_1));
    MEMCPY_AN(MBASGLBPMT_N->VALUE_PMT_2, MBASGLBPMT->VALUE_PMT_2, sizeof(MBASGLBPMT->VALUE_PMT_2));
    MEMCPY_AN(MBASGLBPMT_N->VALUE_PMT_3, MBASGLBPMT->VALUE_PMT_3, sizeof(MBASGLBPMT->VALUE_PMT_3));
    MEMCPY_AN(MBASGLBPMT_N->VALUE_PMT_4, MBASGLBPMT->VALUE_PMT_4, sizeof(MBASGLBPMT->VALUE_PMT_4));
    MEMCPY_AN(MBASGLBPMT_N->VALUE_PMT_5, MBASGLBPMT->VALUE_PMT_5, sizeof(MBASGLBPMT->VALUE_PMT_5));
    MBASGLBPMT_N->VALUE_FMT_1[0] = MBASGLBPMT->VALUE_FMT_1;
    MBASGLBPMT_N->VALUE_FMT_2[0] = MBASGLBPMT->VALUE_FMT_2;
    MBASGLBPMT_N->VALUE_FMT_3[0] = MBASGLBPMT->VALUE_FMT_3;
    MBASGLBPMT_N->VALUE_FMT_4[0] = MBASGLBPMT->VALUE_FMT_4;
    MBASGLBPMT_N->VALUE_FMT_5[0] = MBASGLBPMT->VALUE_FMT_5;
    MEMCPY_AN(MBASGLBPMT_N->VALUE_TBL_1, MBASGLBPMT->VALUE_TBL_1, sizeof(MBASGLBPMT->VALUE_TBL_1));
    MEMCPY_AN(MBASGLBPMT_N->VALUE_TBL_2, MBASGLBPMT->VALUE_TBL_2, sizeof(MBASGLBPMT->VALUE_TBL_2));
    MEMCPY_AN(MBASGLBPMT_N->VALUE_TBL_3, MBASGLBPMT->VALUE_TBL_3, sizeof(MBASGLBPMT->VALUE_TBL_3));
    MEMCPY_AN(MBASGLBPMT_N->VALUE_TBL_4, MBASGLBPMT->VALUE_TBL_4, sizeof(MBASGLBPMT->VALUE_TBL_4));
    MEMCPY_AN(MBASGLBPMT_N->VALUE_TBL_5, MBASGLBPMT->VALUE_TBL_5, sizeof(MBASGLBPMT->VALUE_TBL_5));
    MEMCPY_AN(MBASGLBPMT_N->CREATE_USER_ID, MBASGLBPMT->CREATE_USER_ID, sizeof(MBASGLBPMT->CREATE_USER_ID));
    MEMCPY_AN(MBASGLBPMT_N->CREATE_TIME, MBASGLBPMT->CREATE_TIME, sizeof(MBASGLBPMT->CREATE_TIME));
    MEMCPY_AN(MBASGLBPMT_N->UPDATE_USER_ID, MBASGLBPMT->UPDATE_USER_ID, sizeof(MBASGLBPMT->UPDATE_USER_ID));
    MEMCPY_AN(MBASGLBPMT_N->UPDATE_TIME, MBASGLBPMT->UPDATE_TIME, sizeof(MBASGLBPMT->UPDATE_TIME));
}


/* Del Null Function */
void DBC_del_null_mbasglbpmt(struct MBASGLBPMT_N_TAG *MBASGLBPMT_N, struct MBASGLBPMT_TAG *MBASGLBPMT)
{
    MEMCPY_DN(MBASGLBPMT->OPTION_NAME, MBASGLBPMT_N->OPTION_NAME, sizeof(MBASGLBPMT->OPTION_NAME));
    MEMCPY_DN(MBASGLBPMT->OPTION_DESC, MBASGLBPMT_N->OPTION_DESC, sizeof(MBASGLBPMT->OPTION_DESC));
    MBASGLBPMT->MESPLUS_FLAG = MBASGLBPMT_N->MESPLUS_FLAG[0];
    MEMCPY_DN(MBASGLBPMT->VALUE_PMT_1, MBASGLBPMT_N->VALUE_PMT_1, sizeof(MBASGLBPMT->VALUE_PMT_1));
    MEMCPY_DN(MBASGLBPMT->VALUE_PMT_2, MBASGLBPMT_N->VALUE_PMT_2, sizeof(MBASGLBPMT->VALUE_PMT_2));
    MEMCPY_DN(MBASGLBPMT->VALUE_PMT_3, MBASGLBPMT_N->VALUE_PMT_3, sizeof(MBASGLBPMT->VALUE_PMT_3));
    MEMCPY_DN(MBASGLBPMT->VALUE_PMT_4, MBASGLBPMT_N->VALUE_PMT_4, sizeof(MBASGLBPMT->VALUE_PMT_4));
    MEMCPY_DN(MBASGLBPMT->VALUE_PMT_5, MBASGLBPMT_N->VALUE_PMT_5, sizeof(MBASGLBPMT->VALUE_PMT_5));
    MBASGLBPMT->VALUE_FMT_1 = MBASGLBPMT_N->VALUE_FMT_1[0];
    MBASGLBPMT->VALUE_FMT_2 = MBASGLBPMT_N->VALUE_FMT_2[0];
    MBASGLBPMT->VALUE_FMT_3 = MBASGLBPMT_N->VALUE_FMT_3[0];
    MBASGLBPMT->VALUE_FMT_4 = MBASGLBPMT_N->VALUE_FMT_4[0];
    MBASGLBPMT->VALUE_FMT_5 = MBASGLBPMT_N->VALUE_FMT_5[0];
    MEMCPY_DN(MBASGLBPMT->VALUE_TBL_1, MBASGLBPMT_N->VALUE_TBL_1, sizeof(MBASGLBPMT->VALUE_TBL_1));
    MEMCPY_DN(MBASGLBPMT->VALUE_TBL_2, MBASGLBPMT_N->VALUE_TBL_2, sizeof(MBASGLBPMT->VALUE_TBL_2));
    MEMCPY_DN(MBASGLBPMT->VALUE_TBL_3, MBASGLBPMT_N->VALUE_TBL_3, sizeof(MBASGLBPMT->VALUE_TBL_3));
    MEMCPY_DN(MBASGLBPMT->VALUE_TBL_4, MBASGLBPMT_N->VALUE_TBL_4, sizeof(MBASGLBPMT->VALUE_TBL_4));
    MEMCPY_DN(MBASGLBPMT->VALUE_TBL_5, MBASGLBPMT_N->VALUE_TBL_5, sizeof(MBASGLBPMT->VALUE_TBL_5));
    MEMCPY_DN(MBASGLBPMT->CREATE_USER_ID, MBASGLBPMT_N->CREATE_USER_ID, sizeof(MBASGLBPMT->CREATE_USER_ID));
    MEMCPY_DN(MBASGLBPMT->CREATE_TIME, MBASGLBPMT_N->CREATE_TIME, sizeof(MBASGLBPMT->CREATE_TIME));
    MEMCPY_DN(MBASGLBPMT->UPDATE_USER_ID, MBASGLBPMT_N->UPDATE_USER_ID, sizeof(MBASGLBPMT->UPDATE_USER_ID));
    MEMCPY_DN(MBASGLBPMT->UPDATE_TIME, MBASGLBPMT_N->UPDATE_TIME, sizeof(MBASGLBPMT->UPDATE_TIME));
}


