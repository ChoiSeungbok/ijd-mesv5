
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
    "DBU_cqcmcusspe.pc"
};


static unsigned int sqlctx = 9376611;


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
            void  *sqhstv[75];
   unsigned int   sqhstl[75];
            int   sqhsts[75];
            void  *sqindv[75];
            int   sqinds[75];
   unsigned int   sqharm[75];
   unsigned int   *sqharc[75];
   unsigned short  sqadto[75];
   unsigned short  sqtdso[75];
} sqlstm = {13,75};

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
"select FACTORY ,REPORT_NO ,REPORT_TYPE ,CUST_NO ,CUST_NAME ,SAL_GROUP ,CREA\
TE_DATE ,GRADE ,DATA_01 ,DATA_02 ,DATA_03 ,DATA_04 ,DATA_05 ,DATA_06 ,DATA_07\
 ,DATA_08 ,DATA_09 ,DATA_10 ,DATA_11 ,DATA_12 ,DATA_13 ,DATA_14 ,DATA_15 ,DAT\
A_16 ,DATA_17 ,DATA_18 ,DATA_19 ,DATA_20 ,DATA_21 ,DATA_22 ,DATA_23 ,DATA_24 \
,DATA_25 ,DATA_26 ,DATA_27 ,DATA_28 ,DATA_29 ,DATA_30 ,FILE_NO_01 ,FILE_PATH_\
01 ,FILE_NO_02 ,FILE_PATH_02 ,FILE_NO_03 ,FILE_PATH_03 ,FILE_NO_04 ,FILE_PATH\
_04 ,FILE_NO_05 ,FILE_PATH_05 ,COMMENT_01 ,COMMENT_02 ,COMMENT_03 ,COMMENT_04\
 ,COMMENT_05 ,COMMENT_06 ,COMMENT_07 ,COMMENT_08 ,COMMENT_09 ,COMMENT_10 ,CMF\
_01 ,CMF_02 ,CMF_03 ,CMF_04 ,CMF_05 ,CMF_06 ,CMF_07 ,CMF_08 ,CMF_09 ,CMF_10 ,\
USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from CQCMCU\
SSPE  order by FACTORY asc ,REPORT_NO asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,1170,0,4,46,0,0,75,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,
0,
320,0,0,2,1182,0,4,233,0,0,75,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,
0,0,
635,0,0,3,80,0,4,423,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
662,0,0,4,62,0,2,460,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
685,0,0,5,1065,0,3,490,0,0,73,73,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
992,0,0,6,1066,0,5,661,0,0,73,73,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1299,0,0,7,822,0,9,843,0,0,0,0,0,1,0,
1314,0,0,7,0,0,13,872,0,0,73,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1621,0,0,7,0,0,15,975,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cqcmcusspe.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2025-01-02 14:15:29
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2025 MIRACOM,INC.
**
*********************************************************************/
/* EXEC SQL BEGIN DECLARE SECTION; */ 

/*     EXEC SQL INCLUDE DBU_COMMON_N;
 */ 
#ifndef _DBU_COMMON_N_LOADED
#define _DBU_COMMON_N_LOADED

#include <DBC_common_n.h>
#include "dbu_q_cond_n.h"

//Custom Function


#include "DBU_cbascptdef_n.h"
#include "DBU_crassprsts_n.h"
#include "DBU_mwiplotstsx_n.h"
#include "DBU_mwiplothisx_n.h"
#include "DBU_mwipoprdef_n.h"
#include "DBU_mwipmatdef_n.h"
#include "DBU_mrasresdef_n.h"
#include "DBU_mrasreshis_n.h"
#include "DBU_mrasresmfo_n.h"
#include "DBU_mrastoldef_n.h"
#include "DBU_mwipflwdef_n.h"
#include "DBU_mwipflwopr_n.h"
#include "DBU_mwipmatflw_n.h"
#include "DBU_crasrprsts_n.h"
#include "DBU_crasrprspr_n.h"
#include "DBU_crasrprwrk_n.h"
#include "DBU_mwipordsts_n.h"
#include "DBU_cwiperpopr_n.h"
#include "DBU_cwipoprwrk_n.h"
#include "DBU_cwipordbom_n.h"
#include "DBU_cwipwrkdef_n.h"
#include "DBU_cwipwrkgrp_n.h"
#include "DBU_cwiplotlst_n.h"
#include "DBU_minvdlvdtl_n.h"
#include "DBU_minvdlvmst_n.h"
#include "DBU_minvlothis_n.h"
#include "DBU_minvlothld_n.h"
#include "DBU_minvlotiss_n.h"
#include "DBU_minvlotmvh_n.h"
#include "DBU_minvlotsts_n.h"
#include "DBU_minvlotswh_n.h"
#include "DBU_minvmatiss_n.h"
#include "DBU_minvreqdtl_n.h"
#include "DBU_minvreqmst_n.h"
#include "DBU_mgcmtbldat_n.h"
#include "DBU_mgcmtbldef_n.h"
#include "DBU_minvdlvlbl_n.h"
#include "DBU_minvdlvlot_n.h"
#include "DBU_mwipcoldef_n.h"
#include "DBU_cwipinvlod_n.h"
#include "DBU_cbasfildef_n.h"
#include "DBU_cwiplotmvm_n.h"
#include "DBU_cwiplotmvc_n.h"
#include "DBU_cwiplotmvr_n.h"
#include "DBU_minvreqlot_n.h"
#include "DBU_cwipdwnsts_n.h"
#include "DBU_cwipgrpsts_n.h"
#include "DBU_cwipgrplot_n.h"
#include "DBU_cpakordsts_n.h"
#include "DBU_cpaklotsts_n.h"
#include "DBU_cshpordmst_n.h"
#include "DBU_cshporddtl_n.h"
#include "DBU_cretordsts_n.h"
#include "DBU_crasdspreq_n.h"
#include "DBU_crasdsptol_n.h"
#include "DBU_cbaschkdef_n.h"
#include "DBU_medclotdat_n.h"
#include "DBU_medccolver_n.h"
#include "DBU_medccolchr_n.h"
#include "DBU_medccoldef_n.h"
#include "DBU_medcchrdef_n.h"
#include "DBU_medcresdat_n.h"
#include "DBU_cqcmispsts_n.h"
#include "DBU_cqcmispcol_n.h"
#include "DBU_cqcmispdat_n.h"
#include "DBU_cqcmisplos_n.h"
#include "DBU_cqcmispwrk_n.h"
#include "DBU_if_po_rcv_header_n.h"
#include "DBU_if_po_rcv_txns_n.h"
#include "DBU_if_po_rcv_txn_lots_n.h"
#include "DBU_if_inv_txns_n.h"
#include "DBU_if_inv_txn_lots_n.h"
#include "DBU_if_move_trx_n.h"
#include "DBU_if_move_trx_save_n.h"
#include "DBU_if_completion_trx_n.h"
#include "DBU_if_completion_trx_save_n.h"
#include "DBU_if_comp_issue_trx_n.h"
#include "DBU_if_comp_issue_trx_save_n.h"
#include "DBU_if_om_txns_n.h"
#include "DBU_if_om_txn_lots_n.h"
#include "DBU_if_om_ship_headers_n.h"
#include "DBU_if_om_ship_lines_n.h"
#include "DBU_if_om_ship_line_lots_n.h"
#include "DBU_if_po_rma_headers_n.h"
#include "DBU_if_po_rma_txns_n.h"
#include "DBU_if_po_rma_txn_lots_n.h"
#include "DBU_if_om_promise_date_n.h"
#include "DBU_if_std_bom_def_n.h"
#include "DBU_if_uom_conv_def_n.h"
#include "DBU_if_mat_def_n.h"
#include "DBU_if_vendor_def_n.h"
#include "DBU_if_customer_def_n.h"
#include "DBU_if_wh_def_n.h"
#include "DBU_if_sub_area_def_n.h"
#include "DBU_if_txn_type_def_n.h"
#include "DBU_if_po_info_n.h"
#include "DBU_if_wo_bom_info_n.h"
#include "DBU_if_wo_info_n.h"
#include "DBU_if_so_mst_n.h"
#include "DBU_if_so_dtl_n.h"
#include "DBU_if_ro_info_n.h"
#include "DBU_if_po_consign_txns_n.h"
#include "DBU_cwipgrtcss_n.h"
#include "DBU_cwipgrtbld_n.h"
#include "DBU_if_customer_def_his_n.h"
#include "DBU_if_mat_def_his_n.h"
#include "DBU_if_po_info_his_n.h"
#include "DBU_if_ro_info_his_n.h"
#include "DBU_if_so_dtl_his_n.h"
#include "DBU_if_so_mst_his_n.h"
#include "DBU_if_std_bom_def_his_n.h"
#include "DBU_if_sub_area_def_his_n.h"
#include "DBU_if_txn_type_def_his_n.h"
#include "DBU_if_uom_conv_def_his_n.h"
#include "DBU_if_vendor_def_his_n.h"
#include "DBU_if_wh_def_his_n.h"
#include "DBU_if_wo_bom_info_his_n.h"
#include "DBU_if_wo_info_his_n.h"
#include "DBU_if_pack_info_n.h"
#include "DBU_if_pack_info_his_n.h"
#include "DBU_if_p_wo_info_n.h"
#include "DBU_if_p_wo_info_his_n.h"
#include "DBU_if_po_requests_receipts_n.h"
#include "DBU_cwiplotcum_n.h"
#include "DBU_cwiplotdry_n.h"
#include "DBU_csecusedat_n.h"
#include "DBU_cwipgrtcls_n.h"
#include "DBU_cbastxndef_n.h"
#include "DBU_cqcmgrtsiv_n.h"
#include "DBU_cqcmgrthlt_n.h"
#include "DBU_cqcmgrtcot_n.h"
#include "DBU_mwipcaldef_n.h"
#include "DBU_cqcmgrtasp_n.h"
#include "DBU_cwiplotprs_n.h"
#include "DBU_cordprdpln_n.h"
#include "DBU_cwiprcpdef_n.h"

#include "DBU_cretlotsts_n.h"
#include "DBU_cwiplotrim_n.h"
#include "DBU_cwiplotrnd_n.h"
#include "DBU_cwiplotimp_n.h"
#include "DBU_cwiplotcup_n.h"
#include "DBU_cwiplotlmk_n.h"

#include "DBU_cwiplotcls_n.h"
#include "DBU_cwiplottrc_n.h"
#include "DBU_cwiplotbas_n.h"

#include "DBU_cwipordrwk_n.h"
#include "DBU_cbomstddef_n.h"
 
#include "DBU_ct_sal110t_n.h" 
#include "DBU_ct_packing_v_n.h"
#include "DBU_csumlotdat_n.h"
#include "DBU_mwiplotlos_n.h"
#include "DBU_cbaslbldat_n.h"
#include "DBU_cqcmrptctm_n.h"
#include "DBU_cqcmrpthmm_n.h"
#include "DBU_cbastaktim_n.h"
#include "DBU_minvmovsts_n.h"
#include "DBU_minvmovlot_n.h"

#include "DBU_cqcmrptgnp_n.h"
#include "DBU_cqcmrptgny_n.h"
#include "DBU_cqcmrptgrn_n.h"
#include "DBU_csumreswip_n.h"
#include "DBU_cwipprsrun_n.h"
#include "DBU_cwipuoplot_n.h"
#include "DBU_ct_mtl510t_n.h"
#include "DBU_mwipidghis_n.h"
#include "DBU_cqcmrptgrm_n.h"
#include "DBU_cqcmrptgmp_n.h"
#include "DBU_cwipordopr_n.h"
#include "DBU_cqcmcstspm_n.h"
#include "DBU_cwipinvldm_n.h"
#include "DBU_cqcmcstspg_n.h"

#include "DBU_mgcmlagdat_n.h" 
#include "DBU_cwipprdgol_n.h"
#include "DBU_batch_job_n.h"
#include "DBU_mrastevdef_n.h"
#include "DBU_esecusrdef_n.h"
#include "DBU_ct_mtl100t_n.h"
#include "DBU_cwiplotrec_n.h"
#include "DBU_ct_prd210t_n.h"
#include "DBU_ct_prd200t_n.h"
#include "DBU_ct_mold_v_n.h"
#include "DBU_cinvuoplot_n.h"
#include "DBU_cwipwrkinp_n.h"
#include "DBU_minvetclot_n.h"
#include "DBU_cwiplotchg_n.h"
#include "DBU_cpaklothis_n.h"
#include "DBU_ishplotiss_n.h"
#include "DBU_ishplotrcv_n.h"
#include "DBU_cwipbldavg_n.h"
#include "DBU_crasbasdat_n.h"
#include "DBU_cbasshpbom_n.h"
#include "DBU_crastolbrk_n.h"
#include "DBU_mrastolhis_n.h"
#include "DBU_cwippryer_n.h"
#include "DBU_ishpispiss_n.h"
#include "DBU_ishpisprcv_n.h"
#include "DBU_crashitfnc_n.h"
#include "DBU_cerpaststs_n.h"

#include "DBU_crasmdextd_n.h"
#include "DBU_crasvcmfnc_n.h"
#include "DBU_cras5thprs_n.h"
#include "DBU_cras4hrprs_n.h"
#include "DBU_craspntmix_n.h"
#include "DBU_crasbalmil_n.h"
#include "DBU_cwiplotrmk_n.h"
#include "DBU_csecusrdef_n.h"
#include "DBU_cqcmcplmst_n.h"
#include "DBU_cqcmsplmst_n.h"
#include "DBU_cqcmvocmst_n.h"
#include "DBU_cqcmcusspe_n.h"

#endif

/* EXEC SQL END DECLARE SECTION; */ 


/* SQL Common Header File */
#include "DBU_common.h"


/* SQL Error Handling */
/* EXEC SQL WHENEVER SQLERROR DO DB_usr_error(); */ 

/* EXEC SQL WHENEVER NOT FOUND DO DB_usr_error(); */ 



/* Function Declaration */
void DBU_add_null_cqcmcusspe(struct CQCMCUSSPE_N_TAG *CQCMCUSSPE_N, struct CQCMCUSSPE_TAG *CQCMCUSSPE);
void DBU_del_null_cqcmcusspe(struct CQCMCUSSPE_N_TAG *CQCMCUSSPE_N, struct CQCMCUSSPE_TAG *CQCMCUSSPE);


/* SQL SELECT Function */
void DBU_select_cqcmcusspe(int sel_type, struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMCUSSPE_N_TAG CQCMCUSSPE_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmcusspe(&CQCMCUSSPE_N, CQCMCUSSPE);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    REPORT_NO,
                    REPORT_TYPE,
                    CUST_NO,
                    CUST_NAME,
                    SAL_GROUP,
                    CREATE_DATE,
                    GRADE,
                    DATA_01,
                    DATA_02,
                    DATA_03,
                    DATA_04,
                    DATA_05,
                    DATA_06,
                    DATA_07,
                    DATA_08,
                    DATA_09,
                    DATA_10,
                    DATA_11,
                    DATA_12,
                    DATA_13,
                    DATA_14,
                    DATA_15,
                    DATA_16,
                    DATA_17,
                    DATA_18,
                    DATA_19,
                    DATA_20,
                    DATA_21,
                    DATA_22,
                    DATA_23,
                    DATA_24,
                    DATA_25,
                    DATA_26,
                    DATA_27,
                    DATA_28,
                    DATA_29,
                    DATA_30,
                    FILE_NO_01,
                    FILE_PATH_01,
                    FILE_NO_02,
                    FILE_PATH_02,
                    FILE_NO_03,
                    FILE_PATH_03,
                    FILE_NO_04,
                    FILE_PATH_04,
                    FILE_NO_05,
                    FILE_PATH_05,
                    COMMENT_01,
                    COMMENT_02,
                    COMMENT_03,
                    COMMENT_04,
                    COMMENT_05,
                    COMMENT_06,
                    COMMENT_07,
                    COMMENT_08,
                    COMMENT_09,
                    COMMENT_10,
                    CMF_01,
                    CMF_02,
                    CMF_03,
                    CMF_04,
                    CMF_05,
                    CMF_06,
                    CMF_07,
                    CMF_08,
                    CMF_09,
                    CMF_10,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :CQCMCUSSPE_N.FACTORY,
                    :CQCMCUSSPE_N.REPORT_NO,
                    :CQCMCUSSPE_N.REPORT_TYPE,
                    :CQCMCUSSPE_N.CUST_NO,
                    :CQCMCUSSPE_N.CUST_NAME,
                    :CQCMCUSSPE_N.SAL_GROUP,
                    :CQCMCUSSPE_N.CREATE_DATE,
                    :CQCMCUSSPE_N.GRADE,
                    :CQCMCUSSPE_N.DATA_01,
                    :CQCMCUSSPE_N.DATA_02,
                    :CQCMCUSSPE_N.DATA_03,
                    :CQCMCUSSPE_N.DATA_04,
                    :CQCMCUSSPE_N.DATA_05,
                    :CQCMCUSSPE_N.DATA_06,
                    :CQCMCUSSPE_N.DATA_07,
                    :CQCMCUSSPE_N.DATA_08,
                    :CQCMCUSSPE_N.DATA_09,
                    :CQCMCUSSPE_N.DATA_10,
                    :CQCMCUSSPE_N.DATA_11,
                    :CQCMCUSSPE_N.DATA_12,
                    :CQCMCUSSPE_N.DATA_13,
                    :CQCMCUSSPE_N.DATA_14,
                    :CQCMCUSSPE_N.DATA_15,
                    :CQCMCUSSPE_N.DATA_16,
                    :CQCMCUSSPE_N.DATA_17,
                    :CQCMCUSSPE_N.DATA_18,
                    :CQCMCUSSPE_N.DATA_19,
                    :CQCMCUSSPE_N.DATA_20,
                    :CQCMCUSSPE_N.DATA_21,
                    :CQCMCUSSPE_N.DATA_22,
                    :CQCMCUSSPE_N.DATA_23,
                    :CQCMCUSSPE_N.DATA_24,
                    :CQCMCUSSPE_N.DATA_25,
                    :CQCMCUSSPE_N.DATA_26,
                    :CQCMCUSSPE_N.DATA_27,
                    :CQCMCUSSPE_N.DATA_28,
                    :CQCMCUSSPE_N.DATA_29,
                    :CQCMCUSSPE_N.DATA_30,
                    :CQCMCUSSPE_N.FILE_NO_01,
                    :CQCMCUSSPE_N.FILE_PATH_01,
                    :CQCMCUSSPE_N.FILE_NO_02,
                    :CQCMCUSSPE_N.FILE_PATH_02,
                    :CQCMCUSSPE_N.FILE_NO_03,
                    :CQCMCUSSPE_N.FILE_PATH_03,
                    :CQCMCUSSPE_N.FILE_NO_04,
                    :CQCMCUSSPE_N.FILE_PATH_04,
                    :CQCMCUSSPE_N.FILE_NO_05,
                    :CQCMCUSSPE_N.FILE_PATH_05,
                    :CQCMCUSSPE_N.COMMENT_01,
                    :CQCMCUSSPE_N.COMMENT_02,
                    :CQCMCUSSPE_N.COMMENT_03,
                    :CQCMCUSSPE_N.COMMENT_04,
                    :CQCMCUSSPE_N.COMMENT_05,
                    :CQCMCUSSPE_N.COMMENT_06,
                    :CQCMCUSSPE_N.COMMENT_07,
                    :CQCMCUSSPE_N.COMMENT_08,
                    :CQCMCUSSPE_N.COMMENT_09,
                    :CQCMCUSSPE_N.COMMENT_10,
                    :CQCMCUSSPE_N.CMF_01,
                    :CQCMCUSSPE_N.CMF_02,
                    :CQCMCUSSPE_N.CMF_03,
                    :CQCMCUSSPE_N.CMF_04,
                    :CQCMCUSSPE_N.CMF_05,
                    :CQCMCUSSPE_N.CMF_06,
                    :CQCMCUSSPE_N.CMF_07,
                    :CQCMCUSSPE_N.CMF_08,
                    :CQCMCUSSPE_N.CMF_09,
                    :CQCMCUSSPE_N.CMF_10,
                    :CQCMCUSSPE_N.USE_YN,
                    :CQCMCUSSPE_N.CREATE_USER_ID,
                    :CQCMCUSSPE_N.CREATE_TIME,
                    :CQCMCUSSPE_N.UPDATE_USER_ID,
                    :CQCMCUSSPE_N.UPDATE_TIME
                FROM CQCMCUSSPE
                WHERE FACTORY = :CQCMCUSSPE_N.FACTORY
                    AND REPORT_NO = :CQCMCUSSPE_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 75;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,REPORT_NO ,REPORT_TYPE ,CUST_NO ,CUST_NAME ,S\
AL_GROUP ,CREATE_DATE ,GRADE ,DATA_01 ,DATA_02 ,DATA_03 ,DATA_04 ,DATA_05 ,D\
ATA_06 ,DATA_07 ,DATA_08 ,DATA_09 ,DATA_10 ,DATA_11 ,DATA_12 ,DATA_13 ,DATA_\
14 ,DATA_15 ,DATA_16 ,DATA_17 ,DATA_18 ,DATA_19 ,DATA_20 ,DATA_21 ,DATA_22 ,\
DATA_23 ,DATA_24 ,DATA_25 ,DATA_26 ,DATA_27 ,DATA_28 ,DATA_29 ,DATA_30 ,FILE\
_NO_01 ,FILE_PATH_01 ,FILE_NO_02 ,FILE_PATH_02 ,FILE_NO_03 ,FILE_PATH_03 ,FI\
LE_NO_04 ,FILE_PATH_04 ,FILE_NO_05 ,FILE_PATH_05 ,COMMENT_01 ,COMMENT_02 ,CO\
MMENT_03 ,COMMENT_04 ,COMMENT_05 ,COMMENT_06 ,COMMENT_07 ,COMMENT_08 ,COMMEN\
T_09 ,COMMENT_10 ,CMF_01 ,CMF_02 ,CMF_03 ,CMF_04 ,CMF_05 ,CMF_06 ,CMF_07 ,CM\
F_08 ,CMF_09 ,CMF_10 ,USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,U\
PDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,\
:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:\
b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b\
44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b5");
            sqlstm.stmt = "4,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:\
b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72  from CQCMCUSSPE where (FACTORY=:\
b0 and REPORT_NO=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMCUSSPE_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMCUSSPE_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMCUSSPE_N.REPORT_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMCUSSPE_N.CUST_NO);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMCUSSPE_N.CUST_NAME);
            sqlstm.sqhstl[4] = (unsigned int  )101;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMCUSSPE_N.SAL_GROUP);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMCUSSPE_N.CREATE_DATE);
            sqlstm.sqhstl[6] = (unsigned int  )9;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMCUSSPE_N.GRADE);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMCUSSPE_N.DATA_01);
            sqlstm.sqhstl[8] = (unsigned int  )101;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMCUSSPE_N.DATA_02);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMCUSSPE_N.DATA_03);
            sqlstm.sqhstl[10] = (unsigned int  )101;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMCUSSPE_N.DATA_04);
            sqlstm.sqhstl[11] = (unsigned int  )101;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMCUSSPE_N.DATA_05);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMCUSSPE_N.DATA_06);
            sqlstm.sqhstl[13] = (unsigned int  )101;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMCUSSPE_N.DATA_07);
            sqlstm.sqhstl[14] = (unsigned int  )101;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMCUSSPE_N.DATA_08);
            sqlstm.sqhstl[15] = (unsigned int  )101;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMCUSSPE_N.DATA_09);
            sqlstm.sqhstl[16] = (unsigned int  )101;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMCUSSPE_N.DATA_10);
            sqlstm.sqhstl[17] = (unsigned int  )101;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMCUSSPE_N.DATA_11);
            sqlstm.sqhstl[18] = (unsigned int  )101;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMCUSSPE_N.DATA_12);
            sqlstm.sqhstl[19] = (unsigned int  )101;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMCUSSPE_N.DATA_13);
            sqlstm.sqhstl[20] = (unsigned int  )101;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMCUSSPE_N.DATA_14);
            sqlstm.sqhstl[21] = (unsigned int  )101;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMCUSSPE_N.DATA_15);
            sqlstm.sqhstl[22] = (unsigned int  )101;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMCUSSPE_N.DATA_16);
            sqlstm.sqhstl[23] = (unsigned int  )101;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMCUSSPE_N.DATA_17);
            sqlstm.sqhstl[24] = (unsigned int  )101;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMCUSSPE_N.DATA_18);
            sqlstm.sqhstl[25] = (unsigned int  )101;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMCUSSPE_N.DATA_19);
            sqlstm.sqhstl[26] = (unsigned int  )101;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMCUSSPE_N.DATA_20);
            sqlstm.sqhstl[27] = (unsigned int  )101;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMCUSSPE_N.DATA_21);
            sqlstm.sqhstl[28] = (unsigned int  )101;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMCUSSPE_N.DATA_22);
            sqlstm.sqhstl[29] = (unsigned int  )101;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMCUSSPE_N.DATA_23);
            sqlstm.sqhstl[30] = (unsigned int  )101;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMCUSSPE_N.DATA_24);
            sqlstm.sqhstl[31] = (unsigned int  )101;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMCUSSPE_N.DATA_25);
            sqlstm.sqhstl[32] = (unsigned int  )101;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMCUSSPE_N.DATA_26);
            sqlstm.sqhstl[33] = (unsigned int  )101;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMCUSSPE_N.DATA_27);
            sqlstm.sqhstl[34] = (unsigned int  )101;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMCUSSPE_N.DATA_28);
            sqlstm.sqhstl[35] = (unsigned int  )101;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMCUSSPE_N.DATA_29);
            sqlstm.sqhstl[36] = (unsigned int  )101;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMCUSSPE_N.DATA_30);
            sqlstm.sqhstl[37] = (unsigned int  )101;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMCUSSPE_N.FILE_NO_01);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_01);
            sqlstm.sqhstl[39] = (unsigned int  )301;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMCUSSPE_N.FILE_NO_02);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_02);
            sqlstm.sqhstl[41] = (unsigned int  )301;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMCUSSPE_N.FILE_NO_03);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_03);
            sqlstm.sqhstl[43] = (unsigned int  )301;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMCUSSPE_N.FILE_NO_04);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_04);
            sqlstm.sqhstl[45] = (unsigned int  )301;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMCUSSPE_N.FILE_NO_05);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_05);
            sqlstm.sqhstl[47] = (unsigned int  )301;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMCUSSPE_N.COMMENT_01);
            sqlstm.sqhstl[48] = (unsigned int  )1001;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMCUSSPE_N.COMMENT_02);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMCUSSPE_N.COMMENT_03);
            sqlstm.sqhstl[50] = (unsigned int  )1001;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMCUSSPE_N.COMMENT_04);
            sqlstm.sqhstl[51] = (unsigned int  )1001;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMCUSSPE_N.COMMENT_05);
            sqlstm.sqhstl[52] = (unsigned int  )1001;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMCUSSPE_N.COMMENT_06);
            sqlstm.sqhstl[53] = (unsigned int  )1001;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMCUSSPE_N.COMMENT_07);
            sqlstm.sqhstl[54] = (unsigned int  )1001;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMCUSSPE_N.COMMENT_08);
            sqlstm.sqhstl[55] = (unsigned int  )1001;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMCUSSPE_N.COMMENT_09);
            sqlstm.sqhstl[56] = (unsigned int  )1001;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMCUSSPE_N.COMMENT_10);
            sqlstm.sqhstl[57] = (unsigned int  )1001;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMCUSSPE_N.CMF_01);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMCUSSPE_N.CMF_02);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMCUSSPE_N.CMF_03);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMCUSSPE_N.CMF_04);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMCUSSPE_N.CMF_05);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMCUSSPE_N.CMF_06);
            sqlstm.sqhstl[63] = (unsigned int  )51;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMCUSSPE_N.CMF_07);
            sqlstm.sqhstl[64] = (unsigned int  )51;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMCUSSPE_N.CMF_08);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMCUSSPE_N.CMF_09);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMCUSSPE_N.CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMCUSSPE_N.USE_YN);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMCUSSPE_N.CREATE_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMCUSSPE_N.CREATE_TIME);
            sqlstm.sqhstl[70] = (unsigned int  )15;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMCUSSPE_N.UPDATE_USER_ID);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMCUSSPE_N.UPDATE_TIME);
            sqlstm.sqhstl[72] = (unsigned int  )15;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(CQCMCUSSPE_N.FACTORY);
            sqlstm.sqhstl[73] = (unsigned int  )11;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(CQCMCUSSPE_N.REPORT_NO);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
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
        DBU_del_null_cqcmcusspe(&CQCMCUSSPE_N, CQCMCUSSPE);
    }

    DB_stop_query_timer("DBU_select_cqcmcusspe", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cqcmcusspe_for_update(int sel_type, struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMCUSSPE_N_TAG CQCMCUSSPE_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmcusspe(&CQCMCUSSPE_N, CQCMCUSSPE);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    REPORT_NO,
                    REPORT_TYPE,
                    CUST_NO,
                    CUST_NAME,
                    SAL_GROUP,
                    CREATE_DATE,
                    GRADE,
                    DATA_01,
                    DATA_02,
                    DATA_03,
                    DATA_04,
                    DATA_05,
                    DATA_06,
                    DATA_07,
                    DATA_08,
                    DATA_09,
                    DATA_10,
                    DATA_11,
                    DATA_12,
                    DATA_13,
                    DATA_14,
                    DATA_15,
                    DATA_16,
                    DATA_17,
                    DATA_18,
                    DATA_19,
                    DATA_20,
                    DATA_21,
                    DATA_22,
                    DATA_23,
                    DATA_24,
                    DATA_25,
                    DATA_26,
                    DATA_27,
                    DATA_28,
                    DATA_29,
                    DATA_30,
                    FILE_NO_01,
                    FILE_PATH_01,
                    FILE_NO_02,
                    FILE_PATH_02,
                    FILE_NO_03,
                    FILE_PATH_03,
                    FILE_NO_04,
                    FILE_PATH_04,
                    FILE_NO_05,
                    FILE_PATH_05,
                    COMMENT_01,
                    COMMENT_02,
                    COMMENT_03,
                    COMMENT_04,
                    COMMENT_05,
                    COMMENT_06,
                    COMMENT_07,
                    COMMENT_08,
                    COMMENT_09,
                    COMMENT_10,
                    CMF_01,
                    CMF_02,
                    CMF_03,
                    CMF_04,
                    CMF_05,
                    CMF_06,
                    CMF_07,
                    CMF_08,
                    CMF_09,
                    CMF_10,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :CQCMCUSSPE_N.FACTORY,
                    :CQCMCUSSPE_N.REPORT_NO,
                    :CQCMCUSSPE_N.REPORT_TYPE,
                    :CQCMCUSSPE_N.CUST_NO,
                    :CQCMCUSSPE_N.CUST_NAME,
                    :CQCMCUSSPE_N.SAL_GROUP,
                    :CQCMCUSSPE_N.CREATE_DATE,
                    :CQCMCUSSPE_N.GRADE,
                    :CQCMCUSSPE_N.DATA_01,
                    :CQCMCUSSPE_N.DATA_02,
                    :CQCMCUSSPE_N.DATA_03,
                    :CQCMCUSSPE_N.DATA_04,
                    :CQCMCUSSPE_N.DATA_05,
                    :CQCMCUSSPE_N.DATA_06,
                    :CQCMCUSSPE_N.DATA_07,
                    :CQCMCUSSPE_N.DATA_08,
                    :CQCMCUSSPE_N.DATA_09,
                    :CQCMCUSSPE_N.DATA_10,
                    :CQCMCUSSPE_N.DATA_11,
                    :CQCMCUSSPE_N.DATA_12,
                    :CQCMCUSSPE_N.DATA_13,
                    :CQCMCUSSPE_N.DATA_14,
                    :CQCMCUSSPE_N.DATA_15,
                    :CQCMCUSSPE_N.DATA_16,
                    :CQCMCUSSPE_N.DATA_17,
                    :CQCMCUSSPE_N.DATA_18,
                    :CQCMCUSSPE_N.DATA_19,
                    :CQCMCUSSPE_N.DATA_20,
                    :CQCMCUSSPE_N.DATA_21,
                    :CQCMCUSSPE_N.DATA_22,
                    :CQCMCUSSPE_N.DATA_23,
                    :CQCMCUSSPE_N.DATA_24,
                    :CQCMCUSSPE_N.DATA_25,
                    :CQCMCUSSPE_N.DATA_26,
                    :CQCMCUSSPE_N.DATA_27,
                    :CQCMCUSSPE_N.DATA_28,
                    :CQCMCUSSPE_N.DATA_29,
                    :CQCMCUSSPE_N.DATA_30,
                    :CQCMCUSSPE_N.FILE_NO_01,
                    :CQCMCUSSPE_N.FILE_PATH_01,
                    :CQCMCUSSPE_N.FILE_NO_02,
                    :CQCMCUSSPE_N.FILE_PATH_02,
                    :CQCMCUSSPE_N.FILE_NO_03,
                    :CQCMCUSSPE_N.FILE_PATH_03,
                    :CQCMCUSSPE_N.FILE_NO_04,
                    :CQCMCUSSPE_N.FILE_PATH_04,
                    :CQCMCUSSPE_N.FILE_NO_05,
                    :CQCMCUSSPE_N.FILE_PATH_05,
                    :CQCMCUSSPE_N.COMMENT_01,
                    :CQCMCUSSPE_N.COMMENT_02,
                    :CQCMCUSSPE_N.COMMENT_03,
                    :CQCMCUSSPE_N.COMMENT_04,
                    :CQCMCUSSPE_N.COMMENT_05,
                    :CQCMCUSSPE_N.COMMENT_06,
                    :CQCMCUSSPE_N.COMMENT_07,
                    :CQCMCUSSPE_N.COMMENT_08,
                    :CQCMCUSSPE_N.COMMENT_09,
                    :CQCMCUSSPE_N.COMMENT_10,
                    :CQCMCUSSPE_N.CMF_01,
                    :CQCMCUSSPE_N.CMF_02,
                    :CQCMCUSSPE_N.CMF_03,
                    :CQCMCUSSPE_N.CMF_04,
                    :CQCMCUSSPE_N.CMF_05,
                    :CQCMCUSSPE_N.CMF_06,
                    :CQCMCUSSPE_N.CMF_07,
                    :CQCMCUSSPE_N.CMF_08,
                    :CQCMCUSSPE_N.CMF_09,
                    :CQCMCUSSPE_N.CMF_10,
                    :CQCMCUSSPE_N.USE_YN,
                    :CQCMCUSSPE_N.CREATE_USER_ID,
                    :CQCMCUSSPE_N.CREATE_TIME,
                    :CQCMCUSSPE_N.UPDATE_USER_ID,
                    :CQCMCUSSPE_N.UPDATE_TIME
                FROM CQCMCUSSPE
                WHERE FACTORY = :CQCMCUSSPE_N.FACTORY
                    AND REPORT_NO = :CQCMCUSSPE_N.REPORT_NO
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 75;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,REPORT_NO ,REPORT_TYPE ,CUST_NO ,CUST_NAME ,S\
AL_GROUP ,CREATE_DATE ,GRADE ,DATA_01 ,DATA_02 ,DATA_03 ,DATA_04 ,DATA_05 ,D\
ATA_06 ,DATA_07 ,DATA_08 ,DATA_09 ,DATA_10 ,DATA_11 ,DATA_12 ,DATA_13 ,DATA_\
14 ,DATA_15 ,DATA_16 ,DATA_17 ,DATA_18 ,DATA_19 ,DATA_20 ,DATA_21 ,DATA_22 ,\
DATA_23 ,DATA_24 ,DATA_25 ,DATA_26 ,DATA_27 ,DATA_28 ,DATA_29 ,DATA_30 ,FILE\
_NO_01 ,FILE_PATH_01 ,FILE_NO_02 ,FILE_PATH_02 ,FILE_NO_03 ,FILE_PATH_03 ,FI\
LE_NO_04 ,FILE_PATH_04 ,FILE_NO_05 ,FILE_PATH_05 ,COMMENT_01 ,COMMENT_02 ,CO\
MMENT_03 ,COMMENT_04 ,COMMENT_05 ,COMMENT_06 ,COMMENT_07 ,COMMENT_08 ,COMMEN\
T_09 ,COMMENT_10 ,CMF_01 ,CMF_02 ,CMF_03 ,CMF_04 ,CMF_05 ,CMF_06 ,CMF_07 ,CM\
F_08 ,CMF_09 ,CMF_10 ,USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,U\
PDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,\
:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:\
b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b\
44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b5");
            sqlstm.stmt = "4,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:\
b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72  from CQCMCUSSPE where (FACTORY=:\
b0 and REPORT_NO=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )320;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMCUSSPE_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMCUSSPE_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMCUSSPE_N.REPORT_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMCUSSPE_N.CUST_NO);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMCUSSPE_N.CUST_NAME);
            sqlstm.sqhstl[4] = (unsigned int  )101;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMCUSSPE_N.SAL_GROUP);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMCUSSPE_N.CREATE_DATE);
            sqlstm.sqhstl[6] = (unsigned int  )9;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMCUSSPE_N.GRADE);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMCUSSPE_N.DATA_01);
            sqlstm.sqhstl[8] = (unsigned int  )101;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMCUSSPE_N.DATA_02);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMCUSSPE_N.DATA_03);
            sqlstm.sqhstl[10] = (unsigned int  )101;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMCUSSPE_N.DATA_04);
            sqlstm.sqhstl[11] = (unsigned int  )101;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMCUSSPE_N.DATA_05);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMCUSSPE_N.DATA_06);
            sqlstm.sqhstl[13] = (unsigned int  )101;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMCUSSPE_N.DATA_07);
            sqlstm.sqhstl[14] = (unsigned int  )101;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMCUSSPE_N.DATA_08);
            sqlstm.sqhstl[15] = (unsigned int  )101;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMCUSSPE_N.DATA_09);
            sqlstm.sqhstl[16] = (unsigned int  )101;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMCUSSPE_N.DATA_10);
            sqlstm.sqhstl[17] = (unsigned int  )101;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMCUSSPE_N.DATA_11);
            sqlstm.sqhstl[18] = (unsigned int  )101;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMCUSSPE_N.DATA_12);
            sqlstm.sqhstl[19] = (unsigned int  )101;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMCUSSPE_N.DATA_13);
            sqlstm.sqhstl[20] = (unsigned int  )101;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMCUSSPE_N.DATA_14);
            sqlstm.sqhstl[21] = (unsigned int  )101;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMCUSSPE_N.DATA_15);
            sqlstm.sqhstl[22] = (unsigned int  )101;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMCUSSPE_N.DATA_16);
            sqlstm.sqhstl[23] = (unsigned int  )101;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMCUSSPE_N.DATA_17);
            sqlstm.sqhstl[24] = (unsigned int  )101;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMCUSSPE_N.DATA_18);
            sqlstm.sqhstl[25] = (unsigned int  )101;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMCUSSPE_N.DATA_19);
            sqlstm.sqhstl[26] = (unsigned int  )101;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMCUSSPE_N.DATA_20);
            sqlstm.sqhstl[27] = (unsigned int  )101;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMCUSSPE_N.DATA_21);
            sqlstm.sqhstl[28] = (unsigned int  )101;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMCUSSPE_N.DATA_22);
            sqlstm.sqhstl[29] = (unsigned int  )101;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMCUSSPE_N.DATA_23);
            sqlstm.sqhstl[30] = (unsigned int  )101;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMCUSSPE_N.DATA_24);
            sqlstm.sqhstl[31] = (unsigned int  )101;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMCUSSPE_N.DATA_25);
            sqlstm.sqhstl[32] = (unsigned int  )101;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMCUSSPE_N.DATA_26);
            sqlstm.sqhstl[33] = (unsigned int  )101;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMCUSSPE_N.DATA_27);
            sqlstm.sqhstl[34] = (unsigned int  )101;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMCUSSPE_N.DATA_28);
            sqlstm.sqhstl[35] = (unsigned int  )101;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMCUSSPE_N.DATA_29);
            sqlstm.sqhstl[36] = (unsigned int  )101;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMCUSSPE_N.DATA_30);
            sqlstm.sqhstl[37] = (unsigned int  )101;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMCUSSPE_N.FILE_NO_01);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_01);
            sqlstm.sqhstl[39] = (unsigned int  )301;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMCUSSPE_N.FILE_NO_02);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_02);
            sqlstm.sqhstl[41] = (unsigned int  )301;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMCUSSPE_N.FILE_NO_03);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_03);
            sqlstm.sqhstl[43] = (unsigned int  )301;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMCUSSPE_N.FILE_NO_04);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_04);
            sqlstm.sqhstl[45] = (unsigned int  )301;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMCUSSPE_N.FILE_NO_05);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_05);
            sqlstm.sqhstl[47] = (unsigned int  )301;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMCUSSPE_N.COMMENT_01);
            sqlstm.sqhstl[48] = (unsigned int  )1001;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMCUSSPE_N.COMMENT_02);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMCUSSPE_N.COMMENT_03);
            sqlstm.sqhstl[50] = (unsigned int  )1001;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMCUSSPE_N.COMMENT_04);
            sqlstm.sqhstl[51] = (unsigned int  )1001;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMCUSSPE_N.COMMENT_05);
            sqlstm.sqhstl[52] = (unsigned int  )1001;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMCUSSPE_N.COMMENT_06);
            sqlstm.sqhstl[53] = (unsigned int  )1001;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMCUSSPE_N.COMMENT_07);
            sqlstm.sqhstl[54] = (unsigned int  )1001;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMCUSSPE_N.COMMENT_08);
            sqlstm.sqhstl[55] = (unsigned int  )1001;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMCUSSPE_N.COMMENT_09);
            sqlstm.sqhstl[56] = (unsigned int  )1001;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMCUSSPE_N.COMMENT_10);
            sqlstm.sqhstl[57] = (unsigned int  )1001;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMCUSSPE_N.CMF_01);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMCUSSPE_N.CMF_02);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMCUSSPE_N.CMF_03);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMCUSSPE_N.CMF_04);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMCUSSPE_N.CMF_05);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMCUSSPE_N.CMF_06);
            sqlstm.sqhstl[63] = (unsigned int  )51;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMCUSSPE_N.CMF_07);
            sqlstm.sqhstl[64] = (unsigned int  )51;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMCUSSPE_N.CMF_08);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMCUSSPE_N.CMF_09);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMCUSSPE_N.CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMCUSSPE_N.USE_YN);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMCUSSPE_N.CREATE_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMCUSSPE_N.CREATE_TIME);
            sqlstm.sqhstl[70] = (unsigned int  )15;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMCUSSPE_N.UPDATE_USER_ID);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMCUSSPE_N.UPDATE_TIME);
            sqlstm.sqhstl[72] = (unsigned int  )15;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(CQCMCUSSPE_N.FACTORY);
            sqlstm.sqhstl[73] = (unsigned int  )11;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(CQCMCUSSPE_N.REPORT_NO);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
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
        DBU_del_null_cqcmcusspe(&CQCMCUSSPE_N, CQCMCUSSPE);
    }

    DB_stop_query_timer("DBU_select_cqcmcusspe_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cqcmcusspe_scalar(int sel_type, struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMCUSSPE_N_TAG CQCMCUSSPE_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmcusspe(&CQCMCUSSPE_N, CQCMCUSSPE);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMCUSSPE
                WHERE FACTORY = :CQCMCUSSPE_N.FACTORY
                    AND REPORT_NO = :CQCMCUSSPE_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 75;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMCUSSPE where\
 (FACTORY=:b1 and REPORT_NO=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )635;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMCUSSPE_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMCUSSPE_N.REPORT_NO);
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

    DB_stop_query_timer("DBU_select_cqcmcusspe_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cqcmcusspe(int sel_type, struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMCUSSPE_N_TAG CQCMCUSSPE_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmcusspe(&CQCMCUSSPE_N, CQCMCUSSPE);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CQCMCUSSPE
                WHERE FACTORY = :CQCMCUSSPE_N.FACTORY
                    AND REPORT_NO = :CQCMCUSSPE_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 75;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMCUSSPE  where (FACTORY=:b0 and \
REPORT_NO=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )662;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMCUSSPE_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMCUSSPE_N.REPORT_NO);
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

    DB_stop_query_timer("DBU_delete_cqcmcusspe", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cqcmcusspe(struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMCUSSPE_N_TAG CQCMCUSSPE_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmcusspe(&CQCMCUSSPE_N, CQCMCUSSPE);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CQCMCUSSPE( 
                    FACTORY, 
                    REPORT_NO, 
                    REPORT_TYPE, 
                    CUST_NO, 
                    CUST_NAME, 
                    SAL_GROUP, 
                    CREATE_DATE, 
                    GRADE, 
                    DATA_01, 
                    DATA_02, 
                    DATA_03, 
                    DATA_04, 
                    DATA_05, 
                    DATA_06, 
                    DATA_07, 
                    DATA_08, 
                    DATA_09, 
                    DATA_10, 
                    DATA_11, 
                    DATA_12, 
                    DATA_13, 
                    DATA_14, 
                    DATA_15, 
                    DATA_16, 
                    DATA_17, 
                    DATA_18, 
                    DATA_19, 
                    DATA_20, 
                    DATA_21, 
                    DATA_22, 
                    DATA_23, 
                    DATA_24, 
                    DATA_25, 
                    DATA_26, 
                    DATA_27, 
                    DATA_28, 
                    DATA_29, 
                    DATA_30, 
                    FILE_NO_01, 
                    FILE_PATH_01, 
                    FILE_NO_02, 
                    FILE_PATH_02, 
                    FILE_NO_03, 
                    FILE_PATH_03, 
                    FILE_NO_04, 
                    FILE_PATH_04, 
                    FILE_NO_05, 
                    FILE_PATH_05, 
                    COMMENT_01, 
                    COMMENT_02, 
                    COMMENT_03, 
                    COMMENT_04, 
                    COMMENT_05, 
                    COMMENT_06, 
                    COMMENT_07, 
                    COMMENT_08, 
                    COMMENT_09, 
                    COMMENT_10, 
                    CMF_01, 
                    CMF_02, 
                    CMF_03, 
                    CMF_04, 
                    CMF_05, 
                    CMF_06, 
                    CMF_07, 
                    CMF_08, 
                    CMF_09, 
                    CMF_10, 
                    USE_YN, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME
         ) 
        VALUES (
                    :CQCMCUSSPE_N.FACTORY,
                    :CQCMCUSSPE_N.REPORT_NO,
                    :CQCMCUSSPE_N.REPORT_TYPE,
                    :CQCMCUSSPE_N.CUST_NO,
                    :CQCMCUSSPE_N.CUST_NAME,
                    :CQCMCUSSPE_N.SAL_GROUP,
                    :CQCMCUSSPE_N.CREATE_DATE,
                    :CQCMCUSSPE_N.GRADE,
                    :CQCMCUSSPE_N.DATA_01,
                    :CQCMCUSSPE_N.DATA_02,
                    :CQCMCUSSPE_N.DATA_03,
                    :CQCMCUSSPE_N.DATA_04,
                    :CQCMCUSSPE_N.DATA_05,
                    :CQCMCUSSPE_N.DATA_06,
                    :CQCMCUSSPE_N.DATA_07,
                    :CQCMCUSSPE_N.DATA_08,
                    :CQCMCUSSPE_N.DATA_09,
                    :CQCMCUSSPE_N.DATA_10,
                    :CQCMCUSSPE_N.DATA_11,
                    :CQCMCUSSPE_N.DATA_12,
                    :CQCMCUSSPE_N.DATA_13,
                    :CQCMCUSSPE_N.DATA_14,
                    :CQCMCUSSPE_N.DATA_15,
                    :CQCMCUSSPE_N.DATA_16,
                    :CQCMCUSSPE_N.DATA_17,
                    :CQCMCUSSPE_N.DATA_18,
                    :CQCMCUSSPE_N.DATA_19,
                    :CQCMCUSSPE_N.DATA_20,
                    :CQCMCUSSPE_N.DATA_21,
                    :CQCMCUSSPE_N.DATA_22,
                    :CQCMCUSSPE_N.DATA_23,
                    :CQCMCUSSPE_N.DATA_24,
                    :CQCMCUSSPE_N.DATA_25,
                    :CQCMCUSSPE_N.DATA_26,
                    :CQCMCUSSPE_N.DATA_27,
                    :CQCMCUSSPE_N.DATA_28,
                    :CQCMCUSSPE_N.DATA_29,
                    :CQCMCUSSPE_N.DATA_30,
                    :CQCMCUSSPE_N.FILE_NO_01,
                    :CQCMCUSSPE_N.FILE_PATH_01,
                    :CQCMCUSSPE_N.FILE_NO_02,
                    :CQCMCUSSPE_N.FILE_PATH_02,
                    :CQCMCUSSPE_N.FILE_NO_03,
                    :CQCMCUSSPE_N.FILE_PATH_03,
                    :CQCMCUSSPE_N.FILE_NO_04,
                    :CQCMCUSSPE_N.FILE_PATH_04,
                    :CQCMCUSSPE_N.FILE_NO_05,
                    :CQCMCUSSPE_N.FILE_PATH_05,
                    :CQCMCUSSPE_N.COMMENT_01,
                    :CQCMCUSSPE_N.COMMENT_02,
                    :CQCMCUSSPE_N.COMMENT_03,
                    :CQCMCUSSPE_N.COMMENT_04,
                    :CQCMCUSSPE_N.COMMENT_05,
                    :CQCMCUSSPE_N.COMMENT_06,
                    :CQCMCUSSPE_N.COMMENT_07,
                    :CQCMCUSSPE_N.COMMENT_08,
                    :CQCMCUSSPE_N.COMMENT_09,
                    :CQCMCUSSPE_N.COMMENT_10,
                    :CQCMCUSSPE_N.CMF_01,
                    :CQCMCUSSPE_N.CMF_02,
                    :CQCMCUSSPE_N.CMF_03,
                    :CQCMCUSSPE_N.CMF_04,
                    :CQCMCUSSPE_N.CMF_05,
                    :CQCMCUSSPE_N.CMF_06,
                    :CQCMCUSSPE_N.CMF_07,
                    :CQCMCUSSPE_N.CMF_08,
                    :CQCMCUSSPE_N.CMF_09,
                    :CQCMCUSSPE_N.CMF_10,
                    :CQCMCUSSPE_N.USE_YN,
                    :CQCMCUSSPE_N.CREATE_USER_ID,
                    :CQCMCUSSPE_N.CREATE_TIME,
                    :CQCMCUSSPE_N.UPDATE_USER_ID,
                    :CQCMCUSSPE_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 75;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into CQCMCUSSPE (FACTORY,REPORT_NO,REPORT_TYPE,CUST_NO,CUST_NA\
ME,SAL_GROUP,CREATE_DATE,GRADE,DATA_01,DATA_02,DATA_03,DATA_04,DATA_05,DATA_\
06,DATA_07,DATA_08,DATA_09,DATA_10,DATA_11,DATA_12,DATA_13,DATA_14,DATA_15,D\
ATA_16,DATA_17,DATA_18,DATA_19,DATA_20,DATA_21,DATA_22,DATA_23,DATA_24,DATA_\
25,DATA_26,DATA_27,DATA_28,DATA_29,DATA_30,FILE_NO_01,FILE_PATH_01,FILE_NO_0\
2,FILE_PATH_02,FILE_NO_03,FILE_PATH_03,FILE_NO_04,FILE_PATH_04,FILE_NO_05,FI\
LE_PATH_05,COMMENT_01,COMMENT_02,COMMENT_03,COMMENT_04,COMMENT_05,COMMENT_06\
,COMMENT_07,COMMENT_08,COMMENT_09,COMMENT_10,CMF_01,CMF_02,CMF_03,CMF_04,CMF\
_05,CMF_06,CMF_07,CMF_08,CMF_09,CMF_10,USE_YN,CREATE_USER_ID,CREATE_TIME,UPD\
ATE_USER_ID,UPDATE_TIME) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b1\
0,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25\
,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,\
:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:\
b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64");
    sqlstm.stmt = ",:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )685;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CQCMCUSSPE_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CQCMCUSSPE_N.REPORT_NO);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CQCMCUSSPE_N.REPORT_TYPE);
    sqlstm.sqhstl[2] = (unsigned int  )11;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(CQCMCUSSPE_N.CUST_NO);
    sqlstm.sqhstl[3] = (unsigned int  )101;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CQCMCUSSPE_N.CUST_NAME);
    sqlstm.sqhstl[4] = (unsigned int  )101;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(CQCMCUSSPE_N.SAL_GROUP);
    sqlstm.sqhstl[5] = (unsigned int  )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CQCMCUSSPE_N.CREATE_DATE);
    sqlstm.sqhstl[6] = (unsigned int  )9;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(CQCMCUSSPE_N.GRADE);
    sqlstm.sqhstl[7] = (unsigned int  )21;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CQCMCUSSPE_N.DATA_01);
    sqlstm.sqhstl[8] = (unsigned int  )101;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CQCMCUSSPE_N.DATA_02);
    sqlstm.sqhstl[9] = (unsigned int  )101;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(CQCMCUSSPE_N.DATA_03);
    sqlstm.sqhstl[10] = (unsigned int  )101;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(CQCMCUSSPE_N.DATA_04);
    sqlstm.sqhstl[11] = (unsigned int  )101;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(CQCMCUSSPE_N.DATA_05);
    sqlstm.sqhstl[12] = (unsigned int  )101;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CQCMCUSSPE_N.DATA_06);
    sqlstm.sqhstl[13] = (unsigned int  )101;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(CQCMCUSSPE_N.DATA_07);
    sqlstm.sqhstl[14] = (unsigned int  )101;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CQCMCUSSPE_N.DATA_08);
    sqlstm.sqhstl[15] = (unsigned int  )101;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CQCMCUSSPE_N.DATA_09);
    sqlstm.sqhstl[16] = (unsigned int  )101;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CQCMCUSSPE_N.DATA_10);
    sqlstm.sqhstl[17] = (unsigned int  )101;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CQCMCUSSPE_N.DATA_11);
    sqlstm.sqhstl[18] = (unsigned int  )101;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(CQCMCUSSPE_N.DATA_12);
    sqlstm.sqhstl[19] = (unsigned int  )101;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CQCMCUSSPE_N.DATA_13);
    sqlstm.sqhstl[20] = (unsigned int  )101;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CQCMCUSSPE_N.DATA_14);
    sqlstm.sqhstl[21] = (unsigned int  )101;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(CQCMCUSSPE_N.DATA_15);
    sqlstm.sqhstl[22] = (unsigned int  )101;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(CQCMCUSSPE_N.DATA_16);
    sqlstm.sqhstl[23] = (unsigned int  )101;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CQCMCUSSPE_N.DATA_17);
    sqlstm.sqhstl[24] = (unsigned int  )101;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(CQCMCUSSPE_N.DATA_18);
    sqlstm.sqhstl[25] = (unsigned int  )101;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(CQCMCUSSPE_N.DATA_19);
    sqlstm.sqhstl[26] = (unsigned int  )101;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(CQCMCUSSPE_N.DATA_20);
    sqlstm.sqhstl[27] = (unsigned int  )101;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(CQCMCUSSPE_N.DATA_21);
    sqlstm.sqhstl[28] = (unsigned int  )101;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(CQCMCUSSPE_N.DATA_22);
    sqlstm.sqhstl[29] = (unsigned int  )101;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(CQCMCUSSPE_N.DATA_23);
    sqlstm.sqhstl[30] = (unsigned int  )101;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(CQCMCUSSPE_N.DATA_24);
    sqlstm.sqhstl[31] = (unsigned int  )101;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(CQCMCUSSPE_N.DATA_25);
    sqlstm.sqhstl[32] = (unsigned int  )101;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(CQCMCUSSPE_N.DATA_26);
    sqlstm.sqhstl[33] = (unsigned int  )101;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(CQCMCUSSPE_N.DATA_27);
    sqlstm.sqhstl[34] = (unsigned int  )101;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(CQCMCUSSPE_N.DATA_28);
    sqlstm.sqhstl[35] = (unsigned int  )101;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(CQCMCUSSPE_N.DATA_29);
    sqlstm.sqhstl[36] = (unsigned int  )101;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(CQCMCUSSPE_N.DATA_30);
    sqlstm.sqhstl[37] = (unsigned int  )101;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(CQCMCUSSPE_N.FILE_NO_01);
    sqlstm.sqhstl[38] = (unsigned int  )21;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_01);
    sqlstm.sqhstl[39] = (unsigned int  )301;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(CQCMCUSSPE_N.FILE_NO_02);
    sqlstm.sqhstl[40] = (unsigned int  )21;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_02);
    sqlstm.sqhstl[41] = (unsigned int  )301;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(CQCMCUSSPE_N.FILE_NO_03);
    sqlstm.sqhstl[42] = (unsigned int  )21;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_03);
    sqlstm.sqhstl[43] = (unsigned int  )301;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(CQCMCUSSPE_N.FILE_NO_04);
    sqlstm.sqhstl[44] = (unsigned int  )21;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_04);
    sqlstm.sqhstl[45] = (unsigned int  )301;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(CQCMCUSSPE_N.FILE_NO_05);
    sqlstm.sqhstl[46] = (unsigned int  )21;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_05);
    sqlstm.sqhstl[47] = (unsigned int  )301;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(CQCMCUSSPE_N.COMMENT_01);
    sqlstm.sqhstl[48] = (unsigned int  )1001;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(CQCMCUSSPE_N.COMMENT_02);
    sqlstm.sqhstl[49] = (unsigned int  )1001;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(CQCMCUSSPE_N.COMMENT_03);
    sqlstm.sqhstl[50] = (unsigned int  )1001;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(CQCMCUSSPE_N.COMMENT_04);
    sqlstm.sqhstl[51] = (unsigned int  )1001;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(CQCMCUSSPE_N.COMMENT_05);
    sqlstm.sqhstl[52] = (unsigned int  )1001;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(CQCMCUSSPE_N.COMMENT_06);
    sqlstm.sqhstl[53] = (unsigned int  )1001;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(CQCMCUSSPE_N.COMMENT_07);
    sqlstm.sqhstl[54] = (unsigned int  )1001;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(CQCMCUSSPE_N.COMMENT_08);
    sqlstm.sqhstl[55] = (unsigned int  )1001;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(CQCMCUSSPE_N.COMMENT_09);
    sqlstm.sqhstl[56] = (unsigned int  )1001;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(CQCMCUSSPE_N.COMMENT_10);
    sqlstm.sqhstl[57] = (unsigned int  )1001;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(CQCMCUSSPE_N.CMF_01);
    sqlstm.sqhstl[58] = (unsigned int  )51;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(CQCMCUSSPE_N.CMF_02);
    sqlstm.sqhstl[59] = (unsigned int  )51;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(CQCMCUSSPE_N.CMF_03);
    sqlstm.sqhstl[60] = (unsigned int  )51;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(CQCMCUSSPE_N.CMF_04);
    sqlstm.sqhstl[61] = (unsigned int  )51;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(CQCMCUSSPE_N.CMF_05);
    sqlstm.sqhstl[62] = (unsigned int  )51;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(CQCMCUSSPE_N.CMF_06);
    sqlstm.sqhstl[63] = (unsigned int  )51;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(CQCMCUSSPE_N.CMF_07);
    sqlstm.sqhstl[64] = (unsigned int  )51;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(CQCMCUSSPE_N.CMF_08);
    sqlstm.sqhstl[65] = (unsigned int  )51;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(CQCMCUSSPE_N.CMF_09);
    sqlstm.sqhstl[66] = (unsigned int  )51;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(CQCMCUSSPE_N.CMF_10);
    sqlstm.sqhstl[67] = (unsigned int  )51;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(CQCMCUSSPE_N.USE_YN);
    sqlstm.sqhstl[68] = (unsigned int  )2;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(CQCMCUSSPE_N.CREATE_USER_ID);
    sqlstm.sqhstl[69] = (unsigned int  )21;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(CQCMCUSSPE_N.CREATE_TIME);
    sqlstm.sqhstl[70] = (unsigned int  )15;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(CQCMCUSSPE_N.UPDATE_USER_ID);
    sqlstm.sqhstl[71] = (unsigned int  )21;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(CQCMCUSSPE_N.UPDATE_TIME);
    sqlstm.sqhstl[72] = (unsigned int  )15;
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



    DB_stop_query_timer("DBU_insert_cqcmcusspe", 0);
}


/* SQL UPDATE Function */
void DBU_update_cqcmcusspe(int sel_type, struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMCUSSPE_N_TAG CQCMCUSSPE_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmcusspe(&CQCMCUSSPE_N, CQCMCUSSPE);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CQCMCUSSPE SET
                    REPORT_TYPE = :CQCMCUSSPE_N.REPORT_TYPE,
                    CUST_NO = :CQCMCUSSPE_N.CUST_NO,
                    CUST_NAME = :CQCMCUSSPE_N.CUST_NAME,
                    SAL_GROUP = :CQCMCUSSPE_N.SAL_GROUP,
                    CREATE_DATE = :CQCMCUSSPE_N.CREATE_DATE,
                    GRADE = :CQCMCUSSPE_N.GRADE,
                    DATA_01 = :CQCMCUSSPE_N.DATA_01,
                    DATA_02 = :CQCMCUSSPE_N.DATA_02,
                    DATA_03 = :CQCMCUSSPE_N.DATA_03,
                    DATA_04 = :CQCMCUSSPE_N.DATA_04,
                    DATA_05 = :CQCMCUSSPE_N.DATA_05,
                    DATA_06 = :CQCMCUSSPE_N.DATA_06,
                    DATA_07 = :CQCMCUSSPE_N.DATA_07,
                    DATA_08 = :CQCMCUSSPE_N.DATA_08,
                    DATA_09 = :CQCMCUSSPE_N.DATA_09,
                    DATA_10 = :CQCMCUSSPE_N.DATA_10,
                    DATA_11 = :CQCMCUSSPE_N.DATA_11,
                    DATA_12 = :CQCMCUSSPE_N.DATA_12,
                    DATA_13 = :CQCMCUSSPE_N.DATA_13,
                    DATA_14 = :CQCMCUSSPE_N.DATA_14,
                    DATA_15 = :CQCMCUSSPE_N.DATA_15,
                    DATA_16 = :CQCMCUSSPE_N.DATA_16,
                    DATA_17 = :CQCMCUSSPE_N.DATA_17,
                    DATA_18 = :CQCMCUSSPE_N.DATA_18,
                    DATA_19 = :CQCMCUSSPE_N.DATA_19,
                    DATA_20 = :CQCMCUSSPE_N.DATA_20,
                    DATA_21 = :CQCMCUSSPE_N.DATA_21,
                    DATA_22 = :CQCMCUSSPE_N.DATA_22,
                    DATA_23 = :CQCMCUSSPE_N.DATA_23,
                    DATA_24 = :CQCMCUSSPE_N.DATA_24,
                    DATA_25 = :CQCMCUSSPE_N.DATA_25,
                    DATA_26 = :CQCMCUSSPE_N.DATA_26,
                    DATA_27 = :CQCMCUSSPE_N.DATA_27,
                    DATA_28 = :CQCMCUSSPE_N.DATA_28,
                    DATA_29 = :CQCMCUSSPE_N.DATA_29,
                    DATA_30 = :CQCMCUSSPE_N.DATA_30,
                    FILE_NO_01 = :CQCMCUSSPE_N.FILE_NO_01,
                    FILE_PATH_01 = :CQCMCUSSPE_N.FILE_PATH_01,
                    FILE_NO_02 = :CQCMCUSSPE_N.FILE_NO_02,
                    FILE_PATH_02 = :CQCMCUSSPE_N.FILE_PATH_02,
                    FILE_NO_03 = :CQCMCUSSPE_N.FILE_NO_03,
                    FILE_PATH_03 = :CQCMCUSSPE_N.FILE_PATH_03,
                    FILE_NO_04 = :CQCMCUSSPE_N.FILE_NO_04,
                    FILE_PATH_04 = :CQCMCUSSPE_N.FILE_PATH_04,
                    FILE_NO_05 = :CQCMCUSSPE_N.FILE_NO_05,
                    FILE_PATH_05 = :CQCMCUSSPE_N.FILE_PATH_05,
                    COMMENT_01 = :CQCMCUSSPE_N.COMMENT_01,
                    COMMENT_02 = :CQCMCUSSPE_N.COMMENT_02,
                    COMMENT_03 = :CQCMCUSSPE_N.COMMENT_03,
                    COMMENT_04 = :CQCMCUSSPE_N.COMMENT_04,
                    COMMENT_05 = :CQCMCUSSPE_N.COMMENT_05,
                    COMMENT_06 = :CQCMCUSSPE_N.COMMENT_06,
                    COMMENT_07 = :CQCMCUSSPE_N.COMMENT_07,
                    COMMENT_08 = :CQCMCUSSPE_N.COMMENT_08,
                    COMMENT_09 = :CQCMCUSSPE_N.COMMENT_09,
                    COMMENT_10 = :CQCMCUSSPE_N.COMMENT_10,
                    CMF_01 = :CQCMCUSSPE_N.CMF_01,
                    CMF_02 = :CQCMCUSSPE_N.CMF_02,
                    CMF_03 = :CQCMCUSSPE_N.CMF_03,
                    CMF_04 = :CQCMCUSSPE_N.CMF_04,
                    CMF_05 = :CQCMCUSSPE_N.CMF_05,
                    CMF_06 = :CQCMCUSSPE_N.CMF_06,
                    CMF_07 = :CQCMCUSSPE_N.CMF_07,
                    CMF_08 = :CQCMCUSSPE_N.CMF_08,
                    CMF_09 = :CQCMCUSSPE_N.CMF_09,
                    CMF_10 = :CQCMCUSSPE_N.CMF_10,
                    USE_YN = :CQCMCUSSPE_N.USE_YN,
                    CREATE_USER_ID = :CQCMCUSSPE_N.CREATE_USER_ID,
                    CREATE_TIME = :CQCMCUSSPE_N.CREATE_TIME,
                    UPDATE_USER_ID = :CQCMCUSSPE_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CQCMCUSSPE_N.UPDATE_TIME
                WHERE FACTORY = :CQCMCUSSPE_N.FACTORY
                    AND REPORT_NO = :CQCMCUSSPE_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 75;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update CQCMCUSSPE  set REPORT_TYPE=:b0,CUST_NO=:b1,CUST_NAME=\
:b2,SAL_GROUP=:b3,CREATE_DATE=:b4,GRADE=:b5,DATA_01=:b6,DATA_02=:b7,DATA_03=\
:b8,DATA_04=:b9,DATA_05=:b10,DATA_06=:b11,DATA_07=:b12,DATA_08=:b13,DATA_09=\
:b14,DATA_10=:b15,DATA_11=:b16,DATA_12=:b17,DATA_13=:b18,DATA_14=:b19,DATA_1\
5=:b20,DATA_16=:b21,DATA_17=:b22,DATA_18=:b23,DATA_19=:b24,DATA_20=:b25,DATA\
_21=:b26,DATA_22=:b27,DATA_23=:b28,DATA_24=:b29,DATA_25=:b30,DATA_26=:b31,DA\
TA_27=:b32,DATA_28=:b33,DATA_29=:b34,DATA_30=:b35,FILE_NO_01=:b36,FILE_PATH_\
01=:b37,FILE_NO_02=:b38,FILE_PATH_02=:b39,FILE_NO_03=:b40,FILE_PATH_03=:b41,\
FILE_NO_04=:b42,FILE_PATH_04=:b43,FILE_NO_05=:b44,FILE_PATH_05=:b45,COMMENT_\
01=:b46,COMMENT_02=:b47,COMMENT_03=:b48,COMMENT_04=:b49,COMMENT_05=:b50,COMM\
ENT_06=:b51,COMMENT_07=:b52,COMMENT_08=:b53,COMMENT_09=:b54,COMMENT_10=:b55,\
CMF_01=:b56,CMF_02=:b57,CMF_03=:b58,CMF_04=:b59,CMF_05=:b60,CMF_06=:b61,CMF_\
07=:b62,CMF_08=:b63,CMF_09=:b64,CMF_10=:b65,USE_YN=:b66,CREATE_USER_ID=:b67,\
CREATE_TIME=:b68,UPDATE_USER_ID=:b69,UPDATE_TIME=:b");
            sqlstm.stmt = "70 where (FACTORY=:b71 and REPORT_NO=:b72)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )992;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMCUSSPE_N.REPORT_TYPE);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMCUSSPE_N.CUST_NO);
            sqlstm.sqhstl[1] = (unsigned int  )101;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMCUSSPE_N.CUST_NAME);
            sqlstm.sqhstl[2] = (unsigned int  )101;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMCUSSPE_N.SAL_GROUP);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMCUSSPE_N.CREATE_DATE);
            sqlstm.sqhstl[4] = (unsigned int  )9;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMCUSSPE_N.GRADE);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMCUSSPE_N.DATA_01);
            sqlstm.sqhstl[6] = (unsigned int  )101;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMCUSSPE_N.DATA_02);
            sqlstm.sqhstl[7] = (unsigned int  )101;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMCUSSPE_N.DATA_03);
            sqlstm.sqhstl[8] = (unsigned int  )101;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMCUSSPE_N.DATA_04);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMCUSSPE_N.DATA_05);
            sqlstm.sqhstl[10] = (unsigned int  )101;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMCUSSPE_N.DATA_06);
            sqlstm.sqhstl[11] = (unsigned int  )101;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMCUSSPE_N.DATA_07);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMCUSSPE_N.DATA_08);
            sqlstm.sqhstl[13] = (unsigned int  )101;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMCUSSPE_N.DATA_09);
            sqlstm.sqhstl[14] = (unsigned int  )101;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMCUSSPE_N.DATA_10);
            sqlstm.sqhstl[15] = (unsigned int  )101;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMCUSSPE_N.DATA_11);
            sqlstm.sqhstl[16] = (unsigned int  )101;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMCUSSPE_N.DATA_12);
            sqlstm.sqhstl[17] = (unsigned int  )101;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMCUSSPE_N.DATA_13);
            sqlstm.sqhstl[18] = (unsigned int  )101;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMCUSSPE_N.DATA_14);
            sqlstm.sqhstl[19] = (unsigned int  )101;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMCUSSPE_N.DATA_15);
            sqlstm.sqhstl[20] = (unsigned int  )101;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMCUSSPE_N.DATA_16);
            sqlstm.sqhstl[21] = (unsigned int  )101;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMCUSSPE_N.DATA_17);
            sqlstm.sqhstl[22] = (unsigned int  )101;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMCUSSPE_N.DATA_18);
            sqlstm.sqhstl[23] = (unsigned int  )101;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMCUSSPE_N.DATA_19);
            sqlstm.sqhstl[24] = (unsigned int  )101;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMCUSSPE_N.DATA_20);
            sqlstm.sqhstl[25] = (unsigned int  )101;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMCUSSPE_N.DATA_21);
            sqlstm.sqhstl[26] = (unsigned int  )101;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMCUSSPE_N.DATA_22);
            sqlstm.sqhstl[27] = (unsigned int  )101;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMCUSSPE_N.DATA_23);
            sqlstm.sqhstl[28] = (unsigned int  )101;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMCUSSPE_N.DATA_24);
            sqlstm.sqhstl[29] = (unsigned int  )101;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMCUSSPE_N.DATA_25);
            sqlstm.sqhstl[30] = (unsigned int  )101;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMCUSSPE_N.DATA_26);
            sqlstm.sqhstl[31] = (unsigned int  )101;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMCUSSPE_N.DATA_27);
            sqlstm.sqhstl[32] = (unsigned int  )101;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMCUSSPE_N.DATA_28);
            sqlstm.sqhstl[33] = (unsigned int  )101;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMCUSSPE_N.DATA_29);
            sqlstm.sqhstl[34] = (unsigned int  )101;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMCUSSPE_N.DATA_30);
            sqlstm.sqhstl[35] = (unsigned int  )101;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMCUSSPE_N.FILE_NO_01);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_01);
            sqlstm.sqhstl[37] = (unsigned int  )301;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMCUSSPE_N.FILE_NO_02);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_02);
            sqlstm.sqhstl[39] = (unsigned int  )301;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMCUSSPE_N.FILE_NO_03);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_03);
            sqlstm.sqhstl[41] = (unsigned int  )301;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMCUSSPE_N.FILE_NO_04);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_04);
            sqlstm.sqhstl[43] = (unsigned int  )301;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMCUSSPE_N.FILE_NO_05);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_05);
            sqlstm.sqhstl[45] = (unsigned int  )301;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMCUSSPE_N.COMMENT_01);
            sqlstm.sqhstl[46] = (unsigned int  )1001;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMCUSSPE_N.COMMENT_02);
            sqlstm.sqhstl[47] = (unsigned int  )1001;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMCUSSPE_N.COMMENT_03);
            sqlstm.sqhstl[48] = (unsigned int  )1001;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMCUSSPE_N.COMMENT_04);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMCUSSPE_N.COMMENT_05);
            sqlstm.sqhstl[50] = (unsigned int  )1001;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMCUSSPE_N.COMMENT_06);
            sqlstm.sqhstl[51] = (unsigned int  )1001;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMCUSSPE_N.COMMENT_07);
            sqlstm.sqhstl[52] = (unsigned int  )1001;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMCUSSPE_N.COMMENT_08);
            sqlstm.sqhstl[53] = (unsigned int  )1001;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMCUSSPE_N.COMMENT_09);
            sqlstm.sqhstl[54] = (unsigned int  )1001;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMCUSSPE_N.COMMENT_10);
            sqlstm.sqhstl[55] = (unsigned int  )1001;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMCUSSPE_N.CMF_01);
            sqlstm.sqhstl[56] = (unsigned int  )51;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMCUSSPE_N.CMF_02);
            sqlstm.sqhstl[57] = (unsigned int  )51;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMCUSSPE_N.CMF_03);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMCUSSPE_N.CMF_04);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMCUSSPE_N.CMF_05);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMCUSSPE_N.CMF_06);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMCUSSPE_N.CMF_07);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMCUSSPE_N.CMF_08);
            sqlstm.sqhstl[63] = (unsigned int  )51;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMCUSSPE_N.CMF_09);
            sqlstm.sqhstl[64] = (unsigned int  )51;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMCUSSPE_N.CMF_10);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMCUSSPE_N.USE_YN);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMCUSSPE_N.CREATE_USER_ID);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMCUSSPE_N.CREATE_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMCUSSPE_N.UPDATE_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMCUSSPE_N.UPDATE_TIME);
            sqlstm.sqhstl[70] = (unsigned int  )15;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMCUSSPE_N.FACTORY);
            sqlstm.sqhstl[71] = (unsigned int  )11;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMCUSSPE_N.REPORT_NO);
            sqlstm.sqhstl[72] = (unsigned int  )21;
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

    DB_stop_query_timer("DBU_update_cqcmcusspe", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cqcmcusspe(int sel_type, struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMCUSSPE_N_TAG CQCMCUSSPE_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmcusspe(&CQCMCUSSPE_N, CQCMCUSSPE);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CQCMCUSSPE_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    REPORT_NO,
                    REPORT_TYPE,
                    CUST_NO,
                    CUST_NAME,
                    SAL_GROUP,
                    CREATE_DATE,
                    GRADE,
                    DATA_01,
                    DATA_02,
                    DATA_03,
                    DATA_04,
                    DATA_05,
                    DATA_06,
                    DATA_07,
                    DATA_08,
                    DATA_09,
                    DATA_10,
                    DATA_11,
                    DATA_12,
                    DATA_13,
                    DATA_14,
                    DATA_15,
                    DATA_16,
                    DATA_17,
                    DATA_18,
                    DATA_19,
                    DATA_20,
                    DATA_21,
                    DATA_22,
                    DATA_23,
                    DATA_24,
                    DATA_25,
                    DATA_26,
                    DATA_27,
                    DATA_28,
                    DATA_29,
                    DATA_30,
                    FILE_NO_01,
                    FILE_PATH_01,
                    FILE_NO_02,
                    FILE_PATH_02,
                    FILE_NO_03,
                    FILE_PATH_03,
                    FILE_NO_04,
                    FILE_PATH_04,
                    FILE_NO_05,
                    FILE_PATH_05,
                    COMMENT_01,
                    COMMENT_02,
                    COMMENT_03,
                    COMMENT_04,
                    COMMENT_05,
                    COMMENT_06,
                    COMMENT_07,
                    COMMENT_08,
                    COMMENT_09,
                    COMMENT_10,
                    CMF_01,
                    CMF_02,
                    CMF_03,
                    CMF_04,
                    CMF_05,
                    CMF_06,
                    CMF_07,
                    CMF_08,
                    CMF_09,
                    CMF_10,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM CQCMCUSSPE
                ORDER BY FACTORY ASC,
                    REPORT_NO ASC; */ 

            /* EXEC SQL OPEN DBU_CQCMCUSSPE_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 75;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1299;
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

    DB_stop_query_timer("DBU_open_cqcmcusspe", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cqcmcusspe(int sel_type, struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMCUSSPE_N_TAG CQCMCUSSPE_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CQCMCUSSPE_CUR_1 INTO
                :CQCMCUSSPE_N.FACTORY,
                :CQCMCUSSPE_N.REPORT_NO,
                :CQCMCUSSPE_N.REPORT_TYPE,
                :CQCMCUSSPE_N.CUST_NO,
                :CQCMCUSSPE_N.CUST_NAME,
                :CQCMCUSSPE_N.SAL_GROUP,
                :CQCMCUSSPE_N.CREATE_DATE,
                :CQCMCUSSPE_N.GRADE,
                :CQCMCUSSPE_N.DATA_01,
                :CQCMCUSSPE_N.DATA_02,
                :CQCMCUSSPE_N.DATA_03,
                :CQCMCUSSPE_N.DATA_04,
                :CQCMCUSSPE_N.DATA_05,
                :CQCMCUSSPE_N.DATA_06,
                :CQCMCUSSPE_N.DATA_07,
                :CQCMCUSSPE_N.DATA_08,
                :CQCMCUSSPE_N.DATA_09,
                :CQCMCUSSPE_N.DATA_10,
                :CQCMCUSSPE_N.DATA_11,
                :CQCMCUSSPE_N.DATA_12,
                :CQCMCUSSPE_N.DATA_13,
                :CQCMCUSSPE_N.DATA_14,
                :CQCMCUSSPE_N.DATA_15,
                :CQCMCUSSPE_N.DATA_16,
                :CQCMCUSSPE_N.DATA_17,
                :CQCMCUSSPE_N.DATA_18,
                :CQCMCUSSPE_N.DATA_19,
                :CQCMCUSSPE_N.DATA_20,
                :CQCMCUSSPE_N.DATA_21,
                :CQCMCUSSPE_N.DATA_22,
                :CQCMCUSSPE_N.DATA_23,
                :CQCMCUSSPE_N.DATA_24,
                :CQCMCUSSPE_N.DATA_25,
                :CQCMCUSSPE_N.DATA_26,
                :CQCMCUSSPE_N.DATA_27,
                :CQCMCUSSPE_N.DATA_28,
                :CQCMCUSSPE_N.DATA_29,
                :CQCMCUSSPE_N.DATA_30,
                :CQCMCUSSPE_N.FILE_NO_01,
                :CQCMCUSSPE_N.FILE_PATH_01,
                :CQCMCUSSPE_N.FILE_NO_02,
                :CQCMCUSSPE_N.FILE_PATH_02,
                :CQCMCUSSPE_N.FILE_NO_03,
                :CQCMCUSSPE_N.FILE_PATH_03,
                :CQCMCUSSPE_N.FILE_NO_04,
                :CQCMCUSSPE_N.FILE_PATH_04,
                :CQCMCUSSPE_N.FILE_NO_05,
                :CQCMCUSSPE_N.FILE_PATH_05,
                :CQCMCUSSPE_N.COMMENT_01,
                :CQCMCUSSPE_N.COMMENT_02,
                :CQCMCUSSPE_N.COMMENT_03,
                :CQCMCUSSPE_N.COMMENT_04,
                :CQCMCUSSPE_N.COMMENT_05,
                :CQCMCUSSPE_N.COMMENT_06,
                :CQCMCUSSPE_N.COMMENT_07,
                :CQCMCUSSPE_N.COMMENT_08,
                :CQCMCUSSPE_N.COMMENT_09,
                :CQCMCUSSPE_N.COMMENT_10,
                :CQCMCUSSPE_N.CMF_01,
                :CQCMCUSSPE_N.CMF_02,
                :CQCMCUSSPE_N.CMF_03,
                :CQCMCUSSPE_N.CMF_04,
                :CQCMCUSSPE_N.CMF_05,
                :CQCMCUSSPE_N.CMF_06,
                :CQCMCUSSPE_N.CMF_07,
                :CQCMCUSSPE_N.CMF_08,
                :CQCMCUSSPE_N.CMF_09,
                :CQCMCUSSPE_N.CMF_10,
                :CQCMCUSSPE_N.USE_YN,
                :CQCMCUSSPE_N.CREATE_USER_ID,
                :CQCMCUSSPE_N.CREATE_TIME,
                :CQCMCUSSPE_N.UPDATE_USER_ID,
                :CQCMCUSSPE_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 75;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1314;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMCUSSPE_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMCUSSPE_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMCUSSPE_N.REPORT_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMCUSSPE_N.CUST_NO);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMCUSSPE_N.CUST_NAME);
            sqlstm.sqhstl[4] = (unsigned int  )101;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMCUSSPE_N.SAL_GROUP);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMCUSSPE_N.CREATE_DATE);
            sqlstm.sqhstl[6] = (unsigned int  )9;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMCUSSPE_N.GRADE);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMCUSSPE_N.DATA_01);
            sqlstm.sqhstl[8] = (unsigned int  )101;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMCUSSPE_N.DATA_02);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMCUSSPE_N.DATA_03);
            sqlstm.sqhstl[10] = (unsigned int  )101;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMCUSSPE_N.DATA_04);
            sqlstm.sqhstl[11] = (unsigned int  )101;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMCUSSPE_N.DATA_05);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMCUSSPE_N.DATA_06);
            sqlstm.sqhstl[13] = (unsigned int  )101;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMCUSSPE_N.DATA_07);
            sqlstm.sqhstl[14] = (unsigned int  )101;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMCUSSPE_N.DATA_08);
            sqlstm.sqhstl[15] = (unsigned int  )101;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMCUSSPE_N.DATA_09);
            sqlstm.sqhstl[16] = (unsigned int  )101;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMCUSSPE_N.DATA_10);
            sqlstm.sqhstl[17] = (unsigned int  )101;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMCUSSPE_N.DATA_11);
            sqlstm.sqhstl[18] = (unsigned int  )101;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMCUSSPE_N.DATA_12);
            sqlstm.sqhstl[19] = (unsigned int  )101;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMCUSSPE_N.DATA_13);
            sqlstm.sqhstl[20] = (unsigned int  )101;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMCUSSPE_N.DATA_14);
            sqlstm.sqhstl[21] = (unsigned int  )101;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMCUSSPE_N.DATA_15);
            sqlstm.sqhstl[22] = (unsigned int  )101;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMCUSSPE_N.DATA_16);
            sqlstm.sqhstl[23] = (unsigned int  )101;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMCUSSPE_N.DATA_17);
            sqlstm.sqhstl[24] = (unsigned int  )101;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMCUSSPE_N.DATA_18);
            sqlstm.sqhstl[25] = (unsigned int  )101;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMCUSSPE_N.DATA_19);
            sqlstm.sqhstl[26] = (unsigned int  )101;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMCUSSPE_N.DATA_20);
            sqlstm.sqhstl[27] = (unsigned int  )101;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMCUSSPE_N.DATA_21);
            sqlstm.sqhstl[28] = (unsigned int  )101;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMCUSSPE_N.DATA_22);
            sqlstm.sqhstl[29] = (unsigned int  )101;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMCUSSPE_N.DATA_23);
            sqlstm.sqhstl[30] = (unsigned int  )101;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMCUSSPE_N.DATA_24);
            sqlstm.sqhstl[31] = (unsigned int  )101;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMCUSSPE_N.DATA_25);
            sqlstm.sqhstl[32] = (unsigned int  )101;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMCUSSPE_N.DATA_26);
            sqlstm.sqhstl[33] = (unsigned int  )101;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMCUSSPE_N.DATA_27);
            sqlstm.sqhstl[34] = (unsigned int  )101;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMCUSSPE_N.DATA_28);
            sqlstm.sqhstl[35] = (unsigned int  )101;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMCUSSPE_N.DATA_29);
            sqlstm.sqhstl[36] = (unsigned int  )101;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMCUSSPE_N.DATA_30);
            sqlstm.sqhstl[37] = (unsigned int  )101;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMCUSSPE_N.FILE_NO_01);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_01);
            sqlstm.sqhstl[39] = (unsigned int  )301;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMCUSSPE_N.FILE_NO_02);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_02);
            sqlstm.sqhstl[41] = (unsigned int  )301;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMCUSSPE_N.FILE_NO_03);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_03);
            sqlstm.sqhstl[43] = (unsigned int  )301;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMCUSSPE_N.FILE_NO_04);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_04);
            sqlstm.sqhstl[45] = (unsigned int  )301;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMCUSSPE_N.FILE_NO_05);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMCUSSPE_N.FILE_PATH_05);
            sqlstm.sqhstl[47] = (unsigned int  )301;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMCUSSPE_N.COMMENT_01);
            sqlstm.sqhstl[48] = (unsigned int  )1001;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMCUSSPE_N.COMMENT_02);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMCUSSPE_N.COMMENT_03);
            sqlstm.sqhstl[50] = (unsigned int  )1001;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMCUSSPE_N.COMMENT_04);
            sqlstm.sqhstl[51] = (unsigned int  )1001;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMCUSSPE_N.COMMENT_05);
            sqlstm.sqhstl[52] = (unsigned int  )1001;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMCUSSPE_N.COMMENT_06);
            sqlstm.sqhstl[53] = (unsigned int  )1001;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMCUSSPE_N.COMMENT_07);
            sqlstm.sqhstl[54] = (unsigned int  )1001;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMCUSSPE_N.COMMENT_08);
            sqlstm.sqhstl[55] = (unsigned int  )1001;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMCUSSPE_N.COMMENT_09);
            sqlstm.sqhstl[56] = (unsigned int  )1001;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMCUSSPE_N.COMMENT_10);
            sqlstm.sqhstl[57] = (unsigned int  )1001;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMCUSSPE_N.CMF_01);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMCUSSPE_N.CMF_02);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMCUSSPE_N.CMF_03);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMCUSSPE_N.CMF_04);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMCUSSPE_N.CMF_05);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMCUSSPE_N.CMF_06);
            sqlstm.sqhstl[63] = (unsigned int  )51;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMCUSSPE_N.CMF_07);
            sqlstm.sqhstl[64] = (unsigned int  )51;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMCUSSPE_N.CMF_08);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMCUSSPE_N.CMF_09);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMCUSSPE_N.CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMCUSSPE_N.USE_YN);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMCUSSPE_N.CREATE_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMCUSSPE_N.CREATE_TIME);
            sqlstm.sqhstl[70] = (unsigned int  )15;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMCUSSPE_N.UPDATE_USER_ID);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMCUSSPE_N.UPDATE_TIME);
            sqlstm.sqhstl[72] = (unsigned int  )15;
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
        DBU_del_null_cqcmcusspe(&CQCMCUSSPE_N, CQCMCUSSPE);
    }

    DB_stop_query_timer("DBU_fetch_cqcmcusspe", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cqcmcusspe(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CQCMCUSSPE_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 75;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1621;
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

    DB_stop_query_timer("DBU_close_cqcmcusspe", sel_type);
}


/* Initialize Function */
void DBU_init_cqcmcusspe(struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    /* memset by Space */
    memset(CQCMCUSSPE, ' ', sizeof(struct CQCMCUSSPE_TAG));
    
}


/* Add Null Function */
void DBU_add_null_cqcmcusspe(struct CQCMCUSSPE_N_TAG *CQCMCUSSPE_N, struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    /* memset by NULL */
    memset(CQCMCUSSPE_N, '\0', sizeof(struct CQCMCUSSPE_N_TAG));
    
    MEMCPY_AN(CQCMCUSSPE_N->FACTORY, CQCMCUSSPE->FACTORY, sizeof(CQCMCUSSPE->FACTORY));
    MEMCPY_AN(CQCMCUSSPE_N->REPORT_NO, CQCMCUSSPE->REPORT_NO, sizeof(CQCMCUSSPE->REPORT_NO));
    MEMCPY_AN(CQCMCUSSPE_N->REPORT_TYPE, CQCMCUSSPE->REPORT_TYPE, sizeof(CQCMCUSSPE->REPORT_TYPE));
    MEMCPY_AN(CQCMCUSSPE_N->CUST_NO, CQCMCUSSPE->CUST_NO, sizeof(CQCMCUSSPE->CUST_NO));
    MEMCPY_AN(CQCMCUSSPE_N->CUST_NAME, CQCMCUSSPE->CUST_NAME, sizeof(CQCMCUSSPE->CUST_NAME));
    MEMCPY_AN(CQCMCUSSPE_N->SAL_GROUP, CQCMCUSSPE->SAL_GROUP, sizeof(CQCMCUSSPE->SAL_GROUP));
    MEMCPY_AN(CQCMCUSSPE_N->CREATE_DATE, CQCMCUSSPE->CREATE_DATE, sizeof(CQCMCUSSPE->CREATE_DATE));
    MEMCPY_AN(CQCMCUSSPE_N->GRADE, CQCMCUSSPE->GRADE, sizeof(CQCMCUSSPE->GRADE));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_01, CQCMCUSSPE->DATA_01, sizeof(CQCMCUSSPE->DATA_01));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_02, CQCMCUSSPE->DATA_02, sizeof(CQCMCUSSPE->DATA_02));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_03, CQCMCUSSPE->DATA_03, sizeof(CQCMCUSSPE->DATA_03));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_04, CQCMCUSSPE->DATA_04, sizeof(CQCMCUSSPE->DATA_04));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_05, CQCMCUSSPE->DATA_05, sizeof(CQCMCUSSPE->DATA_05));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_06, CQCMCUSSPE->DATA_06, sizeof(CQCMCUSSPE->DATA_06));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_07, CQCMCUSSPE->DATA_07, sizeof(CQCMCUSSPE->DATA_07));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_08, CQCMCUSSPE->DATA_08, sizeof(CQCMCUSSPE->DATA_08));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_09, CQCMCUSSPE->DATA_09, sizeof(CQCMCUSSPE->DATA_09));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_10, CQCMCUSSPE->DATA_10, sizeof(CQCMCUSSPE->DATA_10));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_11, CQCMCUSSPE->DATA_11, sizeof(CQCMCUSSPE->DATA_11));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_12, CQCMCUSSPE->DATA_12, sizeof(CQCMCUSSPE->DATA_12));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_13, CQCMCUSSPE->DATA_13, sizeof(CQCMCUSSPE->DATA_13));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_14, CQCMCUSSPE->DATA_14, sizeof(CQCMCUSSPE->DATA_14));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_15, CQCMCUSSPE->DATA_15, sizeof(CQCMCUSSPE->DATA_15));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_16, CQCMCUSSPE->DATA_16, sizeof(CQCMCUSSPE->DATA_16));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_17, CQCMCUSSPE->DATA_17, sizeof(CQCMCUSSPE->DATA_17));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_18, CQCMCUSSPE->DATA_18, sizeof(CQCMCUSSPE->DATA_18));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_19, CQCMCUSSPE->DATA_19, sizeof(CQCMCUSSPE->DATA_19));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_20, CQCMCUSSPE->DATA_20, sizeof(CQCMCUSSPE->DATA_20));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_21, CQCMCUSSPE->DATA_21, sizeof(CQCMCUSSPE->DATA_21));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_22, CQCMCUSSPE->DATA_22, sizeof(CQCMCUSSPE->DATA_22));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_23, CQCMCUSSPE->DATA_23, sizeof(CQCMCUSSPE->DATA_23));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_24, CQCMCUSSPE->DATA_24, sizeof(CQCMCUSSPE->DATA_24));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_25, CQCMCUSSPE->DATA_25, sizeof(CQCMCUSSPE->DATA_25));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_26, CQCMCUSSPE->DATA_26, sizeof(CQCMCUSSPE->DATA_26));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_27, CQCMCUSSPE->DATA_27, sizeof(CQCMCUSSPE->DATA_27));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_28, CQCMCUSSPE->DATA_28, sizeof(CQCMCUSSPE->DATA_28));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_29, CQCMCUSSPE->DATA_29, sizeof(CQCMCUSSPE->DATA_29));
    MEMCPY_AN(CQCMCUSSPE_N->DATA_30, CQCMCUSSPE->DATA_30, sizeof(CQCMCUSSPE->DATA_30));
    MEMCPY_AN(CQCMCUSSPE_N->FILE_NO_01, CQCMCUSSPE->FILE_NO_01, sizeof(CQCMCUSSPE->FILE_NO_01));
    MEMCPY_AN(CQCMCUSSPE_N->FILE_PATH_01, CQCMCUSSPE->FILE_PATH_01, sizeof(CQCMCUSSPE->FILE_PATH_01));
    MEMCPY_AN(CQCMCUSSPE_N->FILE_NO_02, CQCMCUSSPE->FILE_NO_02, sizeof(CQCMCUSSPE->FILE_NO_02));
    MEMCPY_AN(CQCMCUSSPE_N->FILE_PATH_02, CQCMCUSSPE->FILE_PATH_02, sizeof(CQCMCUSSPE->FILE_PATH_02));
    MEMCPY_AN(CQCMCUSSPE_N->FILE_NO_03, CQCMCUSSPE->FILE_NO_03, sizeof(CQCMCUSSPE->FILE_NO_03));
    MEMCPY_AN(CQCMCUSSPE_N->FILE_PATH_03, CQCMCUSSPE->FILE_PATH_03, sizeof(CQCMCUSSPE->FILE_PATH_03));
    MEMCPY_AN(CQCMCUSSPE_N->FILE_NO_04, CQCMCUSSPE->FILE_NO_04, sizeof(CQCMCUSSPE->FILE_NO_04));
    MEMCPY_AN(CQCMCUSSPE_N->FILE_PATH_04, CQCMCUSSPE->FILE_PATH_04, sizeof(CQCMCUSSPE->FILE_PATH_04));
    MEMCPY_AN(CQCMCUSSPE_N->FILE_NO_05, CQCMCUSSPE->FILE_NO_05, sizeof(CQCMCUSSPE->FILE_NO_05));
    MEMCPY_AN(CQCMCUSSPE_N->FILE_PATH_05, CQCMCUSSPE->FILE_PATH_05, sizeof(CQCMCUSSPE->FILE_PATH_05));
    MEMCPY_AN(CQCMCUSSPE_N->COMMENT_01, CQCMCUSSPE->COMMENT_01, sizeof(CQCMCUSSPE->COMMENT_01));
    MEMCPY_AN(CQCMCUSSPE_N->COMMENT_02, CQCMCUSSPE->COMMENT_02, sizeof(CQCMCUSSPE->COMMENT_02));
    MEMCPY_AN(CQCMCUSSPE_N->COMMENT_03, CQCMCUSSPE->COMMENT_03, sizeof(CQCMCUSSPE->COMMENT_03));
    MEMCPY_AN(CQCMCUSSPE_N->COMMENT_04, CQCMCUSSPE->COMMENT_04, sizeof(CQCMCUSSPE->COMMENT_04));
    MEMCPY_AN(CQCMCUSSPE_N->COMMENT_05, CQCMCUSSPE->COMMENT_05, sizeof(CQCMCUSSPE->COMMENT_05));
    MEMCPY_AN(CQCMCUSSPE_N->COMMENT_06, CQCMCUSSPE->COMMENT_06, sizeof(CQCMCUSSPE->COMMENT_06));
    MEMCPY_AN(CQCMCUSSPE_N->COMMENT_07, CQCMCUSSPE->COMMENT_07, sizeof(CQCMCUSSPE->COMMENT_07));
    MEMCPY_AN(CQCMCUSSPE_N->COMMENT_08, CQCMCUSSPE->COMMENT_08, sizeof(CQCMCUSSPE->COMMENT_08));
    MEMCPY_AN(CQCMCUSSPE_N->COMMENT_09, CQCMCUSSPE->COMMENT_09, sizeof(CQCMCUSSPE->COMMENT_09));
    MEMCPY_AN(CQCMCUSSPE_N->COMMENT_10, CQCMCUSSPE->COMMENT_10, sizeof(CQCMCUSSPE->COMMENT_10));
    MEMCPY_AN(CQCMCUSSPE_N->CMF_01, CQCMCUSSPE->CMF_01, sizeof(CQCMCUSSPE->CMF_01));
    MEMCPY_AN(CQCMCUSSPE_N->CMF_02, CQCMCUSSPE->CMF_02, sizeof(CQCMCUSSPE->CMF_02));
    MEMCPY_AN(CQCMCUSSPE_N->CMF_03, CQCMCUSSPE->CMF_03, sizeof(CQCMCUSSPE->CMF_03));
    MEMCPY_AN(CQCMCUSSPE_N->CMF_04, CQCMCUSSPE->CMF_04, sizeof(CQCMCUSSPE->CMF_04));
    MEMCPY_AN(CQCMCUSSPE_N->CMF_05, CQCMCUSSPE->CMF_05, sizeof(CQCMCUSSPE->CMF_05));
    MEMCPY_AN(CQCMCUSSPE_N->CMF_06, CQCMCUSSPE->CMF_06, sizeof(CQCMCUSSPE->CMF_06));
    MEMCPY_AN(CQCMCUSSPE_N->CMF_07, CQCMCUSSPE->CMF_07, sizeof(CQCMCUSSPE->CMF_07));
    MEMCPY_AN(CQCMCUSSPE_N->CMF_08, CQCMCUSSPE->CMF_08, sizeof(CQCMCUSSPE->CMF_08));
    MEMCPY_AN(CQCMCUSSPE_N->CMF_09, CQCMCUSSPE->CMF_09, sizeof(CQCMCUSSPE->CMF_09));
    MEMCPY_AN(CQCMCUSSPE_N->CMF_10, CQCMCUSSPE->CMF_10, sizeof(CQCMCUSSPE->CMF_10));
    CQCMCUSSPE_N->USE_YN[0] = CQCMCUSSPE->USE_YN;
    MEMCPY_AN(CQCMCUSSPE_N->CREATE_USER_ID, CQCMCUSSPE->CREATE_USER_ID, sizeof(CQCMCUSSPE->CREATE_USER_ID));
    MEMCPY_AN(CQCMCUSSPE_N->CREATE_TIME, CQCMCUSSPE->CREATE_TIME, sizeof(CQCMCUSSPE->CREATE_TIME));
    MEMCPY_AN(CQCMCUSSPE_N->UPDATE_USER_ID, CQCMCUSSPE->UPDATE_USER_ID, sizeof(CQCMCUSSPE->UPDATE_USER_ID));
    MEMCPY_AN(CQCMCUSSPE_N->UPDATE_TIME, CQCMCUSSPE->UPDATE_TIME, sizeof(CQCMCUSSPE->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_cqcmcusspe(struct CQCMCUSSPE_N_TAG *CQCMCUSSPE_N, struct CQCMCUSSPE_TAG *CQCMCUSSPE)
{
    MEMCPY_DN(CQCMCUSSPE->FACTORY, CQCMCUSSPE_N->FACTORY, sizeof(CQCMCUSSPE->FACTORY));
    MEMCPY_DN(CQCMCUSSPE->REPORT_NO, CQCMCUSSPE_N->REPORT_NO, sizeof(CQCMCUSSPE->REPORT_NO));
    MEMCPY_DN(CQCMCUSSPE->REPORT_TYPE, CQCMCUSSPE_N->REPORT_TYPE, sizeof(CQCMCUSSPE->REPORT_TYPE));
    MEMCPY_DN(CQCMCUSSPE->CUST_NO, CQCMCUSSPE_N->CUST_NO, sizeof(CQCMCUSSPE->CUST_NO));
    MEMCPY_DN(CQCMCUSSPE->CUST_NAME, CQCMCUSSPE_N->CUST_NAME, sizeof(CQCMCUSSPE->CUST_NAME));
    MEMCPY_DN(CQCMCUSSPE->SAL_GROUP, CQCMCUSSPE_N->SAL_GROUP, sizeof(CQCMCUSSPE->SAL_GROUP));
    MEMCPY_DN(CQCMCUSSPE->CREATE_DATE, CQCMCUSSPE_N->CREATE_DATE, sizeof(CQCMCUSSPE->CREATE_DATE));
    MEMCPY_DN(CQCMCUSSPE->GRADE, CQCMCUSSPE_N->GRADE, sizeof(CQCMCUSSPE->GRADE));
    MEMCPY_DN(CQCMCUSSPE->DATA_01, CQCMCUSSPE_N->DATA_01, sizeof(CQCMCUSSPE->DATA_01));
    MEMCPY_DN(CQCMCUSSPE->DATA_02, CQCMCUSSPE_N->DATA_02, sizeof(CQCMCUSSPE->DATA_02));
    MEMCPY_DN(CQCMCUSSPE->DATA_03, CQCMCUSSPE_N->DATA_03, sizeof(CQCMCUSSPE->DATA_03));
    MEMCPY_DN(CQCMCUSSPE->DATA_04, CQCMCUSSPE_N->DATA_04, sizeof(CQCMCUSSPE->DATA_04));
    MEMCPY_DN(CQCMCUSSPE->DATA_05, CQCMCUSSPE_N->DATA_05, sizeof(CQCMCUSSPE->DATA_05));
    MEMCPY_DN(CQCMCUSSPE->DATA_06, CQCMCUSSPE_N->DATA_06, sizeof(CQCMCUSSPE->DATA_06));
    MEMCPY_DN(CQCMCUSSPE->DATA_07, CQCMCUSSPE_N->DATA_07, sizeof(CQCMCUSSPE->DATA_07));
    MEMCPY_DN(CQCMCUSSPE->DATA_08, CQCMCUSSPE_N->DATA_08, sizeof(CQCMCUSSPE->DATA_08));
    MEMCPY_DN(CQCMCUSSPE->DATA_09, CQCMCUSSPE_N->DATA_09, sizeof(CQCMCUSSPE->DATA_09));
    MEMCPY_DN(CQCMCUSSPE->DATA_10, CQCMCUSSPE_N->DATA_10, sizeof(CQCMCUSSPE->DATA_10));
    MEMCPY_DN(CQCMCUSSPE->DATA_11, CQCMCUSSPE_N->DATA_11, sizeof(CQCMCUSSPE->DATA_11));
    MEMCPY_DN(CQCMCUSSPE->DATA_12, CQCMCUSSPE_N->DATA_12, sizeof(CQCMCUSSPE->DATA_12));
    MEMCPY_DN(CQCMCUSSPE->DATA_13, CQCMCUSSPE_N->DATA_13, sizeof(CQCMCUSSPE->DATA_13));
    MEMCPY_DN(CQCMCUSSPE->DATA_14, CQCMCUSSPE_N->DATA_14, sizeof(CQCMCUSSPE->DATA_14));
    MEMCPY_DN(CQCMCUSSPE->DATA_15, CQCMCUSSPE_N->DATA_15, sizeof(CQCMCUSSPE->DATA_15));
    MEMCPY_DN(CQCMCUSSPE->DATA_16, CQCMCUSSPE_N->DATA_16, sizeof(CQCMCUSSPE->DATA_16));
    MEMCPY_DN(CQCMCUSSPE->DATA_17, CQCMCUSSPE_N->DATA_17, sizeof(CQCMCUSSPE->DATA_17));
    MEMCPY_DN(CQCMCUSSPE->DATA_18, CQCMCUSSPE_N->DATA_18, sizeof(CQCMCUSSPE->DATA_18));
    MEMCPY_DN(CQCMCUSSPE->DATA_19, CQCMCUSSPE_N->DATA_19, sizeof(CQCMCUSSPE->DATA_19));
    MEMCPY_DN(CQCMCUSSPE->DATA_20, CQCMCUSSPE_N->DATA_20, sizeof(CQCMCUSSPE->DATA_20));
    MEMCPY_DN(CQCMCUSSPE->DATA_21, CQCMCUSSPE_N->DATA_21, sizeof(CQCMCUSSPE->DATA_21));
    MEMCPY_DN(CQCMCUSSPE->DATA_22, CQCMCUSSPE_N->DATA_22, sizeof(CQCMCUSSPE->DATA_22));
    MEMCPY_DN(CQCMCUSSPE->DATA_23, CQCMCUSSPE_N->DATA_23, sizeof(CQCMCUSSPE->DATA_23));
    MEMCPY_DN(CQCMCUSSPE->DATA_24, CQCMCUSSPE_N->DATA_24, sizeof(CQCMCUSSPE->DATA_24));
    MEMCPY_DN(CQCMCUSSPE->DATA_25, CQCMCUSSPE_N->DATA_25, sizeof(CQCMCUSSPE->DATA_25));
    MEMCPY_DN(CQCMCUSSPE->DATA_26, CQCMCUSSPE_N->DATA_26, sizeof(CQCMCUSSPE->DATA_26));
    MEMCPY_DN(CQCMCUSSPE->DATA_27, CQCMCUSSPE_N->DATA_27, sizeof(CQCMCUSSPE->DATA_27));
    MEMCPY_DN(CQCMCUSSPE->DATA_28, CQCMCUSSPE_N->DATA_28, sizeof(CQCMCUSSPE->DATA_28));
    MEMCPY_DN(CQCMCUSSPE->DATA_29, CQCMCUSSPE_N->DATA_29, sizeof(CQCMCUSSPE->DATA_29));
    MEMCPY_DN(CQCMCUSSPE->DATA_30, CQCMCUSSPE_N->DATA_30, sizeof(CQCMCUSSPE->DATA_30));
    MEMCPY_DN(CQCMCUSSPE->FILE_NO_01, CQCMCUSSPE_N->FILE_NO_01, sizeof(CQCMCUSSPE->FILE_NO_01));
    MEMCPY_DN(CQCMCUSSPE->FILE_PATH_01, CQCMCUSSPE_N->FILE_PATH_01, sizeof(CQCMCUSSPE->FILE_PATH_01));
    MEMCPY_DN(CQCMCUSSPE->FILE_NO_02, CQCMCUSSPE_N->FILE_NO_02, sizeof(CQCMCUSSPE->FILE_NO_02));
    MEMCPY_DN(CQCMCUSSPE->FILE_PATH_02, CQCMCUSSPE_N->FILE_PATH_02, sizeof(CQCMCUSSPE->FILE_PATH_02));
    MEMCPY_DN(CQCMCUSSPE->FILE_NO_03, CQCMCUSSPE_N->FILE_NO_03, sizeof(CQCMCUSSPE->FILE_NO_03));
    MEMCPY_DN(CQCMCUSSPE->FILE_PATH_03, CQCMCUSSPE_N->FILE_PATH_03, sizeof(CQCMCUSSPE->FILE_PATH_03));
    MEMCPY_DN(CQCMCUSSPE->FILE_NO_04, CQCMCUSSPE_N->FILE_NO_04, sizeof(CQCMCUSSPE->FILE_NO_04));
    MEMCPY_DN(CQCMCUSSPE->FILE_PATH_04, CQCMCUSSPE_N->FILE_PATH_04, sizeof(CQCMCUSSPE->FILE_PATH_04));
    MEMCPY_DN(CQCMCUSSPE->FILE_NO_05, CQCMCUSSPE_N->FILE_NO_05, sizeof(CQCMCUSSPE->FILE_NO_05));
    MEMCPY_DN(CQCMCUSSPE->FILE_PATH_05, CQCMCUSSPE_N->FILE_PATH_05, sizeof(CQCMCUSSPE->FILE_PATH_05));
    MEMCPY_DN(CQCMCUSSPE->COMMENT_01, CQCMCUSSPE_N->COMMENT_01, sizeof(CQCMCUSSPE->COMMENT_01));
    MEMCPY_DN(CQCMCUSSPE->COMMENT_02, CQCMCUSSPE_N->COMMENT_02, sizeof(CQCMCUSSPE->COMMENT_02));
    MEMCPY_DN(CQCMCUSSPE->COMMENT_03, CQCMCUSSPE_N->COMMENT_03, sizeof(CQCMCUSSPE->COMMENT_03));
    MEMCPY_DN(CQCMCUSSPE->COMMENT_04, CQCMCUSSPE_N->COMMENT_04, sizeof(CQCMCUSSPE->COMMENT_04));
    MEMCPY_DN(CQCMCUSSPE->COMMENT_05, CQCMCUSSPE_N->COMMENT_05, sizeof(CQCMCUSSPE->COMMENT_05));
    MEMCPY_DN(CQCMCUSSPE->COMMENT_06, CQCMCUSSPE_N->COMMENT_06, sizeof(CQCMCUSSPE->COMMENT_06));
    MEMCPY_DN(CQCMCUSSPE->COMMENT_07, CQCMCUSSPE_N->COMMENT_07, sizeof(CQCMCUSSPE->COMMENT_07));
    MEMCPY_DN(CQCMCUSSPE->COMMENT_08, CQCMCUSSPE_N->COMMENT_08, sizeof(CQCMCUSSPE->COMMENT_08));
    MEMCPY_DN(CQCMCUSSPE->COMMENT_09, CQCMCUSSPE_N->COMMENT_09, sizeof(CQCMCUSSPE->COMMENT_09));
    MEMCPY_DN(CQCMCUSSPE->COMMENT_10, CQCMCUSSPE_N->COMMENT_10, sizeof(CQCMCUSSPE->COMMENT_10));
    MEMCPY_DN(CQCMCUSSPE->CMF_01, CQCMCUSSPE_N->CMF_01, sizeof(CQCMCUSSPE->CMF_01));
    MEMCPY_DN(CQCMCUSSPE->CMF_02, CQCMCUSSPE_N->CMF_02, sizeof(CQCMCUSSPE->CMF_02));
    MEMCPY_DN(CQCMCUSSPE->CMF_03, CQCMCUSSPE_N->CMF_03, sizeof(CQCMCUSSPE->CMF_03));
    MEMCPY_DN(CQCMCUSSPE->CMF_04, CQCMCUSSPE_N->CMF_04, sizeof(CQCMCUSSPE->CMF_04));
    MEMCPY_DN(CQCMCUSSPE->CMF_05, CQCMCUSSPE_N->CMF_05, sizeof(CQCMCUSSPE->CMF_05));
    MEMCPY_DN(CQCMCUSSPE->CMF_06, CQCMCUSSPE_N->CMF_06, sizeof(CQCMCUSSPE->CMF_06));
    MEMCPY_DN(CQCMCUSSPE->CMF_07, CQCMCUSSPE_N->CMF_07, sizeof(CQCMCUSSPE->CMF_07));
    MEMCPY_DN(CQCMCUSSPE->CMF_08, CQCMCUSSPE_N->CMF_08, sizeof(CQCMCUSSPE->CMF_08));
    MEMCPY_DN(CQCMCUSSPE->CMF_09, CQCMCUSSPE_N->CMF_09, sizeof(CQCMCUSSPE->CMF_09));
    MEMCPY_DN(CQCMCUSSPE->CMF_10, CQCMCUSSPE_N->CMF_10, sizeof(CQCMCUSSPE->CMF_10));
    CQCMCUSSPE->USE_YN = CQCMCUSSPE_N->USE_YN[0];
    MEMCPY_DN(CQCMCUSSPE->CREATE_USER_ID, CQCMCUSSPE_N->CREATE_USER_ID, sizeof(CQCMCUSSPE->CREATE_USER_ID));
    MEMCPY_DN(CQCMCUSSPE->CREATE_TIME, CQCMCUSSPE_N->CREATE_TIME, sizeof(CQCMCUSSPE->CREATE_TIME));
    MEMCPY_DN(CQCMCUSSPE->UPDATE_USER_ID, CQCMCUSSPE_N->UPDATE_USER_ID, sizeof(CQCMCUSSPE->UPDATE_USER_ID));
    MEMCPY_DN(CQCMCUSSPE->UPDATE_TIME, CQCMCUSSPE_N->UPDATE_TIME, sizeof(CQCMCUSSPE->UPDATE_TIME));
}


