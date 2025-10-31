
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
    "DBC_mqcmitmdft.pc"
};


static unsigned int sqlctx = 9123163;


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
            void  *sqhstv[24];
   unsigned int   sqhstl[24];
            int   sqhsts[24];
            void  *sqindv[24];
            int   sqinds[24];
   unsigned int   sqharm[24];
   unsigned int   *sqharc[24];
   unsigned short  sqadto[24];
   unsigned short  sqtdso[24];
} sqlstm = {13,24};

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
"select QD.BATCH_ID BATCH_ID ,QD.INSP_SET_ID INSP_SET_ID ,QD.INSP_SET_VERSIO\
N INSP_SET_VERSION ,QD.INSP_ITEM INSP_ITEM ,QD.DEFECT_CODE DEFECT_CODE ,sum(Q\
D.QTY_1) DEFECT_QTY  from MQCMITMDFT QD ,MQCMITMISP QI where (((((((((QD.FACT\
ORY=QI.FACTORY and QD.BATCH_ID=QI.BATCH_ID) and QD.BATCH_HIST_SEQ=QI.BATCH_HI\
ST_SEQ) and QD.ITEM_ID=QI.ITEM_ID) and QD.INSP_ITEM=QI.INSP_ITEM) and QD.FACT\
ORY=:b0) and QD.BATCH_ID=:b1) and QD.INSP_ITEM=:b2) and QI.INSP_SEQ=:b3) and \
QI.HIST_DEL_FLAG<>'Y') group by QD.BATCH_ID,QD.INSP_SET_ID,QD.INSP_SET_VERSIO\
N,QD.INSP_ITEM,QD.DEFECT_CODE order by QD.BATCH_ID asc ,QD.INSP_SET_ID asc ,Q\
D.INSP_SET_VERSION asc ,QD.INSP_ITEM asc ,QD.DEFECT_CODE asc             ";

 static const char *sq0009 = 
"select FACTORY ,BATCH_ID ,BATCH_HIST_SEQ ,ITEM_ID ,INSP_ITEM ,DEFECT_CODE ,\
HIST_DEL_FLAG ,DEL_RESULT_SEQ ,INSP_SET_ID ,INSP_SET_VERSION ,INSP_METHOD ,DE\
FECT_GROUP ,QTY_1 ,QTY_2 ,QTY_3 ,INSP_SEQ ,USER_ID ,TRAN_TIME  from MQCMITMDF\
T where ((((((FACTORY=:b0 and BATCH_ID=:b1) and BATCH_HIST_SEQ=:b2) and ITEM_\
ID=:b3) and INSP_ITEM=:b4) and BATCH_ID=:b1) and HIST_DEL_FLAG='N') order by \
DEFECT_CODE asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,437,0,4,45,0,0,24,6,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,
116,0,0,2,449,0,4,124,0,0,24,6,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,
227,0,0,3,164,0,4,206,0,0,7,6,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,
270,0,0,4,168,0,4,218,0,0,6,5,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,
309,0,0,5,146,0,2,257,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,
348,0,0,6,303,0,3,289,0,0,18,18,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
435,0,0,7,328,0,5,348,0,0,18,18,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
522,0,0,8,687,0,9,415,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
553,0,0,9,411,0,9,448,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,0,0,0,
592,0,0,8,0,0,13,476,0,0,6,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,4,0,0,
631,0,0,9,0,0,13,485,0,0,18,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
718,0,0,8,0,0,15,533,0,0,0,0,0,1,0,
733,0,0,9,0,0,15,537,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mqcmitmdft.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2009/09/08 15:50:41
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
void DBC_add_null_mqcmitmdft(struct MQCMITMDFT_N_TAG *MQCMITMDFT_N, struct MQCMITMDFT_TAG *MQCMITMDFT);
void DBC_del_null_mqcmitmdft(struct MQCMITMDFT_N_TAG *MQCMITMDFT_N, struct MQCMITMDFT_TAG *MQCMITMDFT);


/* SQL SELECT Function */
void DBC_select_mqcmitmdft(int sel_type, struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MQCMITMDFT_N_TAG MQCMITMDFT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcmitmdft(&MQCMITMDFT_N, MQCMITMDFT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         BATCH_ID,
                         BATCH_HIST_SEQ,
                         ITEM_ID,
                         INSP_ITEM,
                         DEFECT_CODE,
                         HIST_DEL_FLAG,
                         DEL_RESULT_SEQ,
                         INSP_SET_ID,
                         INSP_SET_VERSION,
                         INSP_METHOD,
                         DEFECT_GROUP,
                         QTY_1,
                         QTY_2,
                         QTY_3,
                         INSP_SEQ,
                         USER_ID,
                         TRAN_TIME
                INTO 
                    :MQCMITMDFT_N.FACTORY,
                    :MQCMITMDFT_N.BATCH_ID,
                    :MQCMITMDFT_N.BATCH_HIST_SEQ,
                    :MQCMITMDFT_N.ITEM_ID,
                    :MQCMITMDFT_N.INSP_ITEM,
                    :MQCMITMDFT_N.DEFECT_CODE,
                    :MQCMITMDFT_N.HIST_DEL_FLAG,
                    :MQCMITMDFT_N.DEL_RESULT_SEQ,
                    :MQCMITMDFT_N.INSP_SET_ID,
                    :MQCMITMDFT_N.INSP_SET_VERSION,
                    :MQCMITMDFT_N.INSP_METHOD,
                    :MQCMITMDFT_N.DEFECT_GROUP,
                    :MQCMITMDFT_N.QTY_1,
                    :MQCMITMDFT_N.QTY_2,
                    :MQCMITMDFT_N.QTY_3,
                    :MQCMITMDFT_N.INSP_SEQ,
                    :MQCMITMDFT_N.USER_ID,
                    :MQCMITMDFT_N.TRAN_TIME
                FROM MQCMITMDFT
                WHERE FACTORY = :MQCMITMDFT_N.FACTORY
                    AND BATCH_ID = :MQCMITMDFT_N.BATCH_ID
                    AND BATCH_HIST_SEQ = :MQCMITMDFT_N.BATCH_HIST_SEQ
                    AND ITEM_ID = :MQCMITMDFT_N.ITEM_ID
                    AND INSP_ITEM = :MQCMITMDFT_N.INSP_ITEM
                    AND DEFECT_CODE = :MQCMITMDFT_N.DEFECT_CODE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,BATCH_ID ,BATCH_HIST_SEQ ,ITEM_I\
D ,INSP_ITEM ,DEFECT_CODE ,HIST_DEL_FLAG ,DEL_RESULT_SEQ ,INSP_SET_ID ,INSP_S\
ET_VERSION ,INSP_METHOD ,DEFECT_GROUP ,QTY_1 ,QTY_2 ,QTY_3 ,INSP_SEQ ,USER_ID\
 ,TRAN_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,\
:b14,:b15,:b16,:b17  from MQCMITMDFT where (((((FACTORY=:b0 and BATCH_ID=:b1)\
 and BATCH_HIST_SEQ=:b2) and ITEM_ID=:b3) and INSP_ITEM=:b4) and DEFECT_CODE=\
:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MQCMITMDFT_N.BATCH_HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCMITMDFT_N.DEFECT_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MQCMITMDFT_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MQCMITMDFT_N.DEL_RESULT_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MQCMITMDFT_N.INSP_SET_ID);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MQCMITMDFT_N.INSP_SET_VERSION);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MQCMITMDFT_N.INSP_METHOD);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MQCMITMDFT_N.DEFECT_GROUP);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MQCMITMDFT_N.QTY_1);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MQCMITMDFT_N.QTY_2);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MQCMITMDFT_N.QTY_3);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MQCMITMDFT_N.INSP_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MQCMITMDFT_N.USER_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MQCMITMDFT_N.TRAN_TIME);
            sqlstm.sqhstl[17] = (unsigned int  )15;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MQCMITMDFT_N.BATCH_HIST_SEQ);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MQCMITMDFT_N.DEFECT_CODE);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
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
        DBC_del_null_mqcmitmdft(&MQCMITMDFT_N, MQCMITMDFT);
    }
    DB_stop_query_timer("DBC_select_mqcmitmdft", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mqcmitmdft_for_update(int sel_type, struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MQCMITMDFT_N_TAG MQCMITMDFT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcmitmdft(&MQCMITMDFT_N, MQCMITMDFT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         BATCH_ID,
                         BATCH_HIST_SEQ,
                         ITEM_ID,
                         INSP_ITEM,
                         DEFECT_CODE,
                         HIST_DEL_FLAG,
                         DEL_RESULT_SEQ,
                         INSP_SET_ID,
                         INSP_SET_VERSION,
                         INSP_METHOD,
                         DEFECT_GROUP,
                         QTY_1,
                         QTY_2,
                         QTY_3,
                         INSP_SEQ,
                         USER_ID,
                         TRAN_TIME
                INTO 
                    :MQCMITMDFT_N.FACTORY,
                    :MQCMITMDFT_N.BATCH_ID,
                    :MQCMITMDFT_N.BATCH_HIST_SEQ,
                    :MQCMITMDFT_N.ITEM_ID,
                    :MQCMITMDFT_N.INSP_ITEM,
                    :MQCMITMDFT_N.DEFECT_CODE,
                    :MQCMITMDFT_N.HIST_DEL_FLAG,
                    :MQCMITMDFT_N.DEL_RESULT_SEQ,
                    :MQCMITMDFT_N.INSP_SET_ID,
                    :MQCMITMDFT_N.INSP_SET_VERSION,
                    :MQCMITMDFT_N.INSP_METHOD,
                    :MQCMITMDFT_N.DEFECT_GROUP,
                    :MQCMITMDFT_N.QTY_1,
                    :MQCMITMDFT_N.QTY_2,
                    :MQCMITMDFT_N.QTY_3,
                    :MQCMITMDFT_N.INSP_SEQ,
                    :MQCMITMDFT_N.USER_ID,
                    :MQCMITMDFT_N.TRAN_TIME
                FROM MQCMITMDFT
                WHERE FACTORY = :MQCMITMDFT_N.FACTORY
                    AND BATCH_ID = :MQCMITMDFT_N.BATCH_ID
                    AND BATCH_HIST_SEQ = :MQCMITMDFT_N.BATCH_HIST_SEQ
                    AND ITEM_ID = :MQCMITMDFT_N.ITEM_ID
                    AND INSP_ITEM = :MQCMITMDFT_N.INSP_ITEM
                    AND DEFECT_CODE = :MQCMITMDFT_N.DEFECT_CODE
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,BATCH_ID ,BATCH_HIST_SEQ ,ITEM_I\
D ,INSP_ITEM ,DEFECT_CODE ,HIST_DEL_FLAG ,DEL_RESULT_SEQ ,INSP_SET_ID ,INSP_S\
ET_VERSION ,INSP_METHOD ,DEFECT_GROUP ,QTY_1 ,QTY_2 ,QTY_3 ,INSP_SEQ ,USER_ID\
 ,TRAN_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,\
:b14,:b15,:b16,:b17  from MQCMITMDFT where (((((FACTORY=:b0 and BATCH_ID=:b1)\
 and BATCH_HIST_SEQ=:b2) and ITEM_ID=:b3) and INSP_ITEM=:b4) and DEFECT_CODE=\
:b5) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )116;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MQCMITMDFT_N.BATCH_HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCMITMDFT_N.DEFECT_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MQCMITMDFT_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MQCMITMDFT_N.DEL_RESULT_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MQCMITMDFT_N.INSP_SET_ID);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MQCMITMDFT_N.INSP_SET_VERSION);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MQCMITMDFT_N.INSP_METHOD);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MQCMITMDFT_N.DEFECT_GROUP);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MQCMITMDFT_N.QTY_1);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MQCMITMDFT_N.QTY_2);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MQCMITMDFT_N.QTY_3);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MQCMITMDFT_N.INSP_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MQCMITMDFT_N.USER_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MQCMITMDFT_N.TRAN_TIME);
            sqlstm.sqhstl[17] = (unsigned int  )15;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MQCMITMDFT_N.BATCH_HIST_SEQ);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MQCMITMDFT_N.DEFECT_CODE);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
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
        DBC_del_null_mqcmitmdft(&MQCMITMDFT_N, MQCMITMDFT);
    }
    DB_stop_query_timer("DBC_select_mqcmitmdft_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mqcmitmdft_scalar(int sel_type, struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MQCMITMDFT_N_TAG MQCMITMDFT_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcmitmdft(&MQCMITMDFT_N, MQCMITMDFT);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MQCMITMDFT
                WHERE FACTORY = :MQCMITMDFT_N.FACTORY
                    AND BATCH_ID = :MQCMITMDFT_N.BATCH_ID
                    AND BATCH_HIST_SEQ = :MQCMITMDFT_N.BATCH_HIST_SEQ
                    AND ITEM_ID = :MQCMITMDFT_N.ITEM_ID
                    AND INSP_ITEM = :MQCMITMDFT_N.INSP_ITEM
                    AND DEFECT_CODE = :MQCMITMDFT_N.DEFECT_CODE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MQCMITMDFT where\
 (((((FACTORY=:b1 and BATCH_ID=:b2) and BATCH_HIST_SEQ=:b3) and ITEM_ID=:b4) \
and INSP_ITEM=:b5) and DEFECT_CODE=:b6)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )227;
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
            sqlstm.sqhstv[1] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MQCMITMDFT_N.BATCH_HIST_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MQCMITMDFT_N.DEFECT_CODE);
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
            if (sqlca.sqlcode == 1403) DB_usr_error();
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL SELECT NVL(SUM(QTY_1), 0)
                INTO :d_value
                FROM MQCMITMDFT
                WHERE FACTORY = :MQCMITMDFT_N.FACTORY
                    AND BATCH_ID = :MQCMITMDFT_N.BATCH_ID
                    AND ITEM_ID = :MQCMITMDFT_N.ITEM_ID
                    AND INSP_ITEM = :MQCMITMDFT_N.INSP_ITEM
                    AND INSP_SEQ = :MQCMITMDFT_N.INSP_SEQ
                    AND HIST_DEL_FLAG = 'N'; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select NVL(sum(QTY_1),0) into :b0  from MQCMITMD\
FT where (((((FACTORY=:b1 and BATCH_ID=:b2) and ITEM_ID=:b3) and INSP_ITEM=:b\
4) and INSP_SEQ=:b5) and HIST_DEL_FLAG='N')";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )270;
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
            sqlstm.sqhstv[1] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MQCMITMDFT_N.INSP_SEQ);
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBC_select_mqcmitmdft_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mqcmitmdft(int sel_type, struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MQCMITMDFT_N_TAG MQCMITMDFT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcmitmdft(&MQCMITMDFT_N, MQCMITMDFT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MQCMITMDFT
                WHERE FACTORY = :MQCMITMDFT_N.FACTORY
                    AND BATCH_ID = :MQCMITMDFT_N.BATCH_ID
                    AND BATCH_HIST_SEQ = :MQCMITMDFT_N.BATCH_HIST_SEQ
                    AND ITEM_ID = :MQCMITMDFT_N.ITEM_ID
                    AND INSP_ITEM = :MQCMITMDFT_N.INSP_ITEM
                    AND DEFECT_CODE = :MQCMITMDFT_N.DEFECT_CODE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MQCMITMDFT  where (((((FACTORY=:b0 \
and BATCH_ID=:b1) and BATCH_HIST_SEQ=:b2) and ITEM_ID=:b3) and INSP_ITEM=:b4)\
 and DEFECT_CODE=:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )309;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MQCMITMDFT_N.BATCH_HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCMITMDFT_N.DEFECT_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )31;
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_delete_mqcmitmdft", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mqcmitmdft(struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MQCMITMDFT_N_TAG MQCMITMDFT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcmitmdft(&MQCMITMDFT_N, MQCMITMDFT);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MQCMITMDFT (
                    FACTORY,
                    BATCH_ID,
                    BATCH_HIST_SEQ,
                    ITEM_ID,
                    INSP_ITEM,
                    DEFECT_CODE,
                    HIST_DEL_FLAG,
                    DEL_RESULT_SEQ,
                    INSP_SET_ID,
                    INSP_SET_VERSION,
                    INSP_METHOD,
                    DEFECT_GROUP,
                    QTY_1,
                    QTY_2,
                    QTY_3,
                    INSP_SEQ,
                    USER_ID,
                    TRAN_TIME
        )
        VALUES (
                    :MQCMITMDFT_N.FACTORY,
                    :MQCMITMDFT_N.BATCH_ID,
                    :MQCMITMDFT_N.BATCH_HIST_SEQ,
                    :MQCMITMDFT_N.ITEM_ID,
                    :MQCMITMDFT_N.INSP_ITEM,
                    :MQCMITMDFT_N.DEFECT_CODE,
                    :MQCMITMDFT_N.HIST_DEL_FLAG,
                    :MQCMITMDFT_N.DEL_RESULT_SEQ,
                    :MQCMITMDFT_N.INSP_SET_ID,
                    :MQCMITMDFT_N.INSP_SET_VERSION,
                    :MQCMITMDFT_N.INSP_METHOD,
                    :MQCMITMDFT_N.DEFECT_GROUP,
                    :MQCMITMDFT_N.QTY_1,
                    :MQCMITMDFT_N.QTY_2,
                    :MQCMITMDFT_N.QTY_3,
                    :MQCMITMDFT_N.INSP_SEQ,
                    :MQCMITMDFT_N.USER_ID,
                    :MQCMITMDFT_N.TRAN_TIME
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into MQCMITMDFT (FACTORY,BATCH_ID,BATCH_HIST_SEQ,\
ITEM_ID,INSP_ITEM,DEFECT_CODE,HIST_DEL_FLAG,DEL_RESULT_SEQ,INSP_SET_ID,INSP_S\
ET_VERSION,INSP_METHOD,DEFECT_GROUP,QTY_1,QTY_2,QTY_3,INSP_SEQ,USER_ID,TRAN_T\
IME) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14\
,:b15,:b16,:b17)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )348;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MQCMITMDFT_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
    sqlstm.sqhstl[1] = (unsigned int  )31;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(MQCMITMDFT_N.BATCH_HIST_SEQ);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
    sqlstm.sqhstl[3] = (unsigned int  )31;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
    sqlstm.sqhstl[4] = (unsigned int  )26;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MQCMITMDFT_N.DEFECT_CODE);
    sqlstm.sqhstl[5] = (unsigned int  )31;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MQCMITMDFT_N.HIST_DEL_FLAG);
    sqlstm.sqhstl[6] = (unsigned int  )2;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)&(MQCMITMDFT_N.DEL_RESULT_SEQ);
    sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MQCMITMDFT_N.INSP_SET_ID);
    sqlstm.sqhstl[8] = (unsigned int  )26;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)&(MQCMITMDFT_N.INSP_SET_VERSION);
    sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MQCMITMDFT_N.INSP_METHOD);
    sqlstm.sqhstl[10] = (unsigned int  )11;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MQCMITMDFT_N.DEFECT_GROUP);
    sqlstm.sqhstl[11] = (unsigned int  )21;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)&(MQCMITMDFT_N.QTY_1);
    sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)&(MQCMITMDFT_N.QTY_2);
    sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)&(MQCMITMDFT_N.QTY_3);
    sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)&(MQCMITMDFT_N.INSP_SEQ);
    sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MQCMITMDFT_N.USER_ID);
    sqlstm.sqhstl[16] = (unsigned int  )21;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MQCMITMDFT_N.TRAN_TIME);
    sqlstm.sqhstl[17] = (unsigned int  )15;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
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


    DB_stop_query_timer("DBC_insert_mqcmitmdft", 0);
}


/* SQL UPDATE Function */
void DBC_update_mqcmitmdft(int sel_type, struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MQCMITMDFT_N_TAG MQCMITMDFT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcmitmdft(&MQCMITMDFT_N, MQCMITMDFT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MQCMITMDFT SET
                    HIST_DEL_FLAG = :MQCMITMDFT_N.HIST_DEL_FLAG,
                    DEL_RESULT_SEQ = :MQCMITMDFT_N.DEL_RESULT_SEQ,
                    INSP_SET_ID = :MQCMITMDFT_N.INSP_SET_ID,
                    INSP_SET_VERSION = :MQCMITMDFT_N.INSP_SET_VERSION,
                    INSP_METHOD = :MQCMITMDFT_N.INSP_METHOD,
                    DEFECT_GROUP = :MQCMITMDFT_N.DEFECT_GROUP,
                    QTY_1 = :MQCMITMDFT_N.QTY_1,
                    QTY_2 = :MQCMITMDFT_N.QTY_2,
                    QTY_3 = :MQCMITMDFT_N.QTY_3,
                    INSP_SEQ = :MQCMITMDFT_N.INSP_SEQ,
                    USER_ID = :MQCMITMDFT_N.USER_ID,
                    TRAN_TIME = :MQCMITMDFT_N.TRAN_TIME
                WHERE FACTORY = :MQCMITMDFT_N.FACTORY
                    AND BATCH_ID = :MQCMITMDFT_N.BATCH_ID
                    AND BATCH_HIST_SEQ = :MQCMITMDFT_N.BATCH_HIST_SEQ
                    AND ITEM_ID = :MQCMITMDFT_N.ITEM_ID
                    AND INSP_ITEM = :MQCMITMDFT_N.INSP_ITEM
                    AND DEFECT_CODE = :MQCMITMDFT_N.DEFECT_CODE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MQCMITMDFT  set HIST_DEL_FLAG=:b0,DEL_RES\
ULT_SEQ=:b1,INSP_SET_ID=:b2,INSP_SET_VERSION=:b3,INSP_METHOD=:b4,DEFECT_GROUP\
=:b5,QTY_1=:b6,QTY_2=:b7,QTY_3=:b8,INSP_SEQ=:b9,USER_ID=:b10,TRAN_TIME=:b11 w\
here (((((FACTORY=:b12 and BATCH_ID=:b13) and BATCH_HIST_SEQ=:b14) and ITEM_I\
D=:b15) and INSP_ITEM=:b16) and DEFECT_CODE=:b17)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )435;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCMITMDFT_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MQCMITMDFT_N.DEL_RESULT_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MQCMITMDFT_N.INSP_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MQCMITMDFT_N.INSP_SET_VERSION);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCMITMDFT_N.INSP_METHOD);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCMITMDFT_N.DEFECT_GROUP);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MQCMITMDFT_N.QTY_1);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MQCMITMDFT_N.QTY_2);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MQCMITMDFT_N.QTY_3);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MQCMITMDFT_N.INSP_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MQCMITMDFT_N.USER_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MQCMITMDFT_N.TRAN_TIME);
            sqlstm.sqhstl[11] = (unsigned int  )15;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MQCMITMDFT_N.BATCH_HIST_SEQ);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MQCMITMDFT_N.DEFECT_CODE);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
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
    DB_stop_query_timer("DBC_update_mqcmitmdft", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mqcmitmdft(int sel_type, struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MQCMITMDFT_N_TAG MQCMITMDFT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mqcmitmdft(&MQCMITMDFT_N, MQCMITMDFT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MQCMITMDFT_CUR_1 CURSOR FOR
                SELECT QD.BATCH_ID AS BATCH_ID, QD.INSP_SET_ID AS INSP_SET_ID, QD.INSP_SET_VERSION AS INSP_SET_VERSION, QD.INSP_ITEM AS INSP_ITEM, 
                        QD.DEFECT_CODE AS DEFECT_CODE, SUM(QD.QTY_1) AS DEFECT_QTY 
                FROM MQCMITMDFT QD, MQCMITMISP QI
                WHERE QD.FACTORY = QI.FACTORY
                  AND QD.BATCH_ID = QI.BATCH_ID
                  AND QD.BATCH_HIST_SEQ = QI.BATCH_HIST_SEQ
                  AND QD.ITEM_ID = QI.ITEM_ID
                  AND QD.INSP_ITEM = QI.INSP_ITEM
                  AND QD.FACTORY =:MQCMITMDFT_N.FACTORY
                  AND QD.BATCH_ID =:MQCMITMDFT_N.BATCH_ID 
                  AND QD.INSP_ITEM =:MQCMITMDFT_N.INSP_ITEM 
                  AND QI.INSP_SEQ =:MQCMITMDFT_N.INSP_SEQ 
                  AND QI.HIST_DEL_FLAG <> 'Y'                
                GROUP BY QD.BATCH_ID, QD.INSP_SET_ID, QD.INSP_SET_VERSION, QD.INSP_ITEM, QD.DEFECT_CODE
                ORDER BY QD.BATCH_ID ASC, 
                    QD.INSP_SET_ID ASC,
                    QD.INSP_SET_VERSION ASC,
                    QD.INSP_ITEM ASC,
                    QD.DEFECT_CODE ASC; */ 

            /* EXEC SQL OPEN DBC_MQCMITMDFT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )522;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MQCMITMDFT_N.INSP_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL DECLARE DBC_MQCMITMDFT_CUR_2 CURSOR FOR
                SELECT 
                    FACTORY,
                    BATCH_ID,
                    BATCH_HIST_SEQ,
                    ITEM_ID,
                    INSP_ITEM,
                    DEFECT_CODE,
                    HIST_DEL_FLAG,
                    DEL_RESULT_SEQ,
                    INSP_SET_ID,
                    INSP_SET_VERSION,
                    INSP_METHOD,
                    DEFECT_GROUP,
                    QTY_1,
                    QTY_2,
                    QTY_3,
                    INSP_SEQ,
                    USER_ID,
                    TRAN_TIME
                FROM MQCMITMDFT
                WHERE FACTORY = :MQCMITMDFT_N.FACTORY
                  AND BATCH_ID = :MQCMITMDFT_N.BATCH_ID
                  AND BATCH_HIST_SEQ = :MQCMITMDFT_N.BATCH_HIST_SEQ
                  AND ITEM_ID = :MQCMITMDFT_N.ITEM_ID
                  AND INSP_ITEM = :MQCMITMDFT_N.INSP_ITEM
                  AND BATCH_ID = :MQCMITMDFT_N.BATCH_ID  
                  AND HIST_DEL_FLAG = 'N'             
                ORDER BY DEFECT_CODE ASC; */ 

            /* EXEC SQL OPEN DBC_MQCMITMDFT_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )553;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MQCMITMDFT_N.BATCH_HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
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
    DB_stop_query_timer("DBC_open_mqcmitmdft", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mqcmitmdft(int sel_type, struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MQCMITMDFT_N_TAG MQCMITMDFT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MQCMITMDFT_CUR_1 INTO :MQCMITMDFT_N.BATCH_ID, 
                                                     :MQCMITMDFT_N.INSP_SET_ID, 
                                                     :MQCMITMDFT_N.INSP_SET_VERSION, 
                                                     :MQCMITMDFT_N.INSP_ITEM, 
                                                     :MQCMITMDFT_N.DEFECT_CODE, 
                                                     :MQCMITMDFT_N.QTY_1 ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )592;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCMITMDFT_N.INSP_SET_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MQCMITMDFT_N.INSP_SET_VERSION);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCMITMDFT_N.DEFECT_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MQCMITMDFT_N.QTY_1);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
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

        case 2:
            /* EXEC SQL FETCH DBC_MQCMITMDFT_CUR_2 INTO 
                                                    :MQCMITMDFT_N.FACTORY,
                                                    :MQCMITMDFT_N.BATCH_ID,
                                                    :MQCMITMDFT_N.BATCH_HIST_SEQ,
                                                    :MQCMITMDFT_N.ITEM_ID,
                                                    :MQCMITMDFT_N.INSP_ITEM,
                                                    :MQCMITMDFT_N.DEFECT_CODE,
                                                    :MQCMITMDFT_N.HIST_DEL_FLAG,
                                                    :MQCMITMDFT_N.DEL_RESULT_SEQ,
                                                    :MQCMITMDFT_N.INSP_SET_ID,
                                                    :MQCMITMDFT_N.INSP_SET_VERSION,
                                                    :MQCMITMDFT_N.INSP_METHOD,
                                                    :MQCMITMDFT_N.DEFECT_GROUP,
                                                    :MQCMITMDFT_N.QTY_1,
                                                    :MQCMITMDFT_N.QTY_2,
                                                    :MQCMITMDFT_N.QTY_3,
                                                    :MQCMITMDFT_N.INSP_SEQ,
                                                    :MQCMITMDFT_N.USER_ID,
                                                    :MQCMITMDFT_N.TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )631;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MQCMITMDFT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MQCMITMDFT_N.BATCH_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MQCMITMDFT_N.BATCH_HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MQCMITMDFT_N.ITEM_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MQCMITMDFT_N.INSP_ITEM);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MQCMITMDFT_N.DEFECT_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MQCMITMDFT_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MQCMITMDFT_N.DEL_RESULT_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MQCMITMDFT_N.INSP_SET_ID);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MQCMITMDFT_N.INSP_SET_VERSION);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MQCMITMDFT_N.INSP_METHOD);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MQCMITMDFT_N.DEFECT_GROUP);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MQCMITMDFT_N.QTY_1);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MQCMITMDFT_N.QTY_2);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MQCMITMDFT_N.QTY_3);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MQCMITMDFT_N.INSP_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MQCMITMDFT_N.USER_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MQCMITMDFT_N.TRAN_TIME);
            sqlstm.sqhstl[17] = (unsigned int  )15;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
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
        DBC_del_null_mqcmitmdft(&MQCMITMDFT_N, MQCMITMDFT);
    }
    DB_stop_query_timer("DBC_fetch_mqcmitmdft", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mqcmitmdft(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MQCMITMDFT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )718;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL CLOSE DBC_MQCMITMDFT_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )733;
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
    DB_stop_query_timer("DBC_close_mqcmitmdft", sel_type);
}


/* Initialize Function */
void DBC_init_mqcmitmdft(struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    /* memset by Space */
    memset(MQCMITMDFT, ' ', sizeof(struct MQCMITMDFT_TAG));
    
    MQCMITMDFT->BATCH_HIST_SEQ = 0;
    MQCMITMDFT->DEL_RESULT_SEQ = 0;
    MQCMITMDFT->INSP_SET_VERSION = 0;
    MQCMITMDFT->QTY_1 = 0;
    MQCMITMDFT->QTY_2 = 0;
    MQCMITMDFT->QTY_3 = 0;
    MQCMITMDFT->INSP_SEQ = 0;
}


/* Add Null Function */
void DBC_add_null_mqcmitmdft(struct MQCMITMDFT_N_TAG *MQCMITMDFT_N, struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    /* memset by NULL */
    memset(MQCMITMDFT_N, '\0', sizeof(struct MQCMITMDFT_N_TAG));
    
    MEMCPY_AN(MQCMITMDFT_N->FACTORY, MQCMITMDFT->FACTORY, sizeof(MQCMITMDFT->FACTORY));
    MEMCPY_AN(MQCMITMDFT_N->BATCH_ID, MQCMITMDFT->BATCH_ID, sizeof(MQCMITMDFT->BATCH_ID));
    MQCMITMDFT_N->BATCH_HIST_SEQ = MQCMITMDFT->BATCH_HIST_SEQ;
    MEMCPY_AN(MQCMITMDFT_N->ITEM_ID, MQCMITMDFT->ITEM_ID, sizeof(MQCMITMDFT->ITEM_ID));
    MEMCPY_AN(MQCMITMDFT_N->INSP_ITEM, MQCMITMDFT->INSP_ITEM, sizeof(MQCMITMDFT->INSP_ITEM));
    MEMCPY_AN(MQCMITMDFT_N->DEFECT_CODE, MQCMITMDFT->DEFECT_CODE, sizeof(MQCMITMDFT->DEFECT_CODE));
    MQCMITMDFT_N->HIST_DEL_FLAG[0] = MQCMITMDFT->HIST_DEL_FLAG;
    MQCMITMDFT_N->DEL_RESULT_SEQ = MQCMITMDFT->DEL_RESULT_SEQ;
    MEMCPY_AN(MQCMITMDFT_N->INSP_SET_ID, MQCMITMDFT->INSP_SET_ID, sizeof(MQCMITMDFT->INSP_SET_ID));
    MQCMITMDFT_N->INSP_SET_VERSION = MQCMITMDFT->INSP_SET_VERSION;
    MEMCPY_AN(MQCMITMDFT_N->INSP_METHOD, MQCMITMDFT->INSP_METHOD, sizeof(MQCMITMDFT->INSP_METHOD));
    MEMCPY_AN(MQCMITMDFT_N->DEFECT_GROUP, MQCMITMDFT->DEFECT_GROUP, sizeof(MQCMITMDFT->DEFECT_GROUP));
    MQCMITMDFT_N->QTY_1 = MQCMITMDFT->QTY_1;
    MQCMITMDFT_N->QTY_2 = MQCMITMDFT->QTY_2;
    MQCMITMDFT_N->QTY_3 = MQCMITMDFT->QTY_3;
    MQCMITMDFT_N->INSP_SEQ = MQCMITMDFT->INSP_SEQ;
    MEMCPY_AN(MQCMITMDFT_N->USER_ID, MQCMITMDFT->USER_ID, sizeof(MQCMITMDFT->USER_ID));
    MEMCPY_AN(MQCMITMDFT_N->TRAN_TIME, MQCMITMDFT->TRAN_TIME, sizeof(MQCMITMDFT->TRAN_TIME));
}


/* Del Null Function */
void DBC_del_null_mqcmitmdft(struct MQCMITMDFT_N_TAG *MQCMITMDFT_N, struct MQCMITMDFT_TAG *MQCMITMDFT)
{
    MEMCPY_DN(MQCMITMDFT->FACTORY, MQCMITMDFT_N->FACTORY, sizeof(MQCMITMDFT->FACTORY));
    MEMCPY_DN(MQCMITMDFT->BATCH_ID, MQCMITMDFT_N->BATCH_ID, sizeof(MQCMITMDFT->BATCH_ID));
    MQCMITMDFT->BATCH_HIST_SEQ = MQCMITMDFT_N->BATCH_HIST_SEQ;
    MEMCPY_DN(MQCMITMDFT->ITEM_ID, MQCMITMDFT_N->ITEM_ID, sizeof(MQCMITMDFT->ITEM_ID));
    MEMCPY_DN(MQCMITMDFT->INSP_ITEM, MQCMITMDFT_N->INSP_ITEM, sizeof(MQCMITMDFT->INSP_ITEM));
    MEMCPY_DN(MQCMITMDFT->DEFECT_CODE, MQCMITMDFT_N->DEFECT_CODE, sizeof(MQCMITMDFT->DEFECT_CODE));
    MQCMITMDFT->HIST_DEL_FLAG = MQCMITMDFT_N->HIST_DEL_FLAG[0];
    MQCMITMDFT->DEL_RESULT_SEQ = MQCMITMDFT_N->DEL_RESULT_SEQ;
    MEMCPY_DN(MQCMITMDFT->INSP_SET_ID, MQCMITMDFT_N->INSP_SET_ID, sizeof(MQCMITMDFT->INSP_SET_ID));
    MQCMITMDFT->INSP_SET_VERSION = MQCMITMDFT_N->INSP_SET_VERSION;
    MEMCPY_DN(MQCMITMDFT->INSP_METHOD, MQCMITMDFT_N->INSP_METHOD, sizeof(MQCMITMDFT->INSP_METHOD));
    MEMCPY_DN(MQCMITMDFT->DEFECT_GROUP, MQCMITMDFT_N->DEFECT_GROUP, sizeof(MQCMITMDFT->DEFECT_GROUP));
    MQCMITMDFT->QTY_1 = MQCMITMDFT_N->QTY_1;
    MQCMITMDFT->QTY_2 = MQCMITMDFT_N->QTY_2;
    MQCMITMDFT->QTY_3 = MQCMITMDFT_N->QTY_3;
    MQCMITMDFT->INSP_SEQ = MQCMITMDFT_N->INSP_SEQ;
    MEMCPY_DN(MQCMITMDFT->USER_ID, MQCMITMDFT_N->USER_ID, sizeof(MQCMITMDFT->USER_ID));
    MEMCPY_DN(MQCMITMDFT->TRAN_TIME, MQCMITMDFT_N->TRAN_TIME, sizeof(MQCMITMDFT->TRAN_TIME));
}


