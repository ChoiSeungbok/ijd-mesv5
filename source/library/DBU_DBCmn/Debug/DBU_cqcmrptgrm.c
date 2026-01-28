
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
    "DBU_cqcmrptgrm.pc"
};


static unsigned int sqlctx = 9379587;


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
            void  *sqhstv[92];
   unsigned int   sqhstl[92];
            int   sqhsts[92];
            void  *sqindv[92];
            int   sqinds[92];
   unsigned int   sqharm[92];
   unsigned int   *sqharc[92];
   unsigned short  sqadto[92];
   unsigned short  sqtdso[92];
} sqlstm = {13,92};

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

 static const char *sq0009 = 
"RPT_CMF_10 ,RPT_CMF_11 ,RPT_CMF_12 ,\
RPT_CMF_13 ,RPT_CMF_14 ,RPT_CMF_15  from CQCMRPTGRM  order by FACTORY asc ,RE\
PORT_NO asc ,LOT_ID asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,1606,0,4,46,0,0,92,3,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
388,0,0,2,1618,0,4,266,0,0,92,3,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
771,0,0,3,97,0,4,489,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
802,0,0,4,80,0,4,498,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
829,0,0,5,79,0,2,535,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
856,0,0,6,62,0,2,542,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
879,0,0,7,1468,0,3,572,0,0,89,89,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1250,0,0,8,1475,0,5,775,0,0,89,89,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1621,0,0,9,1173,0,9,990,0,0,0,0,0,1,0,
1636,0,0,9,0,0,13,1019,0,0,89,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2007,0,0,9,0,0,15,1138,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cqcmrptgrm.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-11-10 18:12:51
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2020 MIRACOM,INC.
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
void DBU_add_null_cqcmrptgrm(struct CQCMRPTGRM_N_TAG *CQCMRPTGRM_N, struct CQCMRPTGRM_TAG *CQCMRPTGRM);
void DBU_del_null_cqcmrptgrm(struct CQCMRPTGRM_N_TAG *CQCMRPTGRM_N, struct CQCMRPTGRM_TAG *CQCMRPTGRM);


/* SQL SELECT Function */
void DBU_select_cqcmrptgrm(int sel_type, struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRM_N_TAG CQCMRPTGRM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrm(&CQCMRPTGRM_N, CQCMRPTGRM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    REPORT_NO,
                    LOT_ID,
                    ITEM_CODE,
                    GRADE,
                    SIZES,
                    HEADER_ID,
                    LINE_NUMBER,
                    CUST_NO,
                    CUST_NAME,
                    REPORT_DATE,
                    INSP_VALUE,
                    SHIP_NAME,
                    WT,
                    MEAN,
                    SD,
                    LP,
                    ELEC_CONDUCTIVITY,
                    VOL_STATIC01,
                    VOL_STATIC02,
                    VOL_STATIC03,
                    VOL_STATIC04,
                    VOL_STATIC05,
                    VOL_STATIC06,
                    VOL_STATIC07,
                    VOL_STATIC08,
                    VOL_STATIC09,
                    IMAGE01,
                    IMAGE02,
                    IMAGE03,
                    IMAGE04,
                    IMAGE05,
                    ANALYZER,
                    WT_CHK,
                    MEAN_CHK,
                    SD_CHK,
                    LP_CHK,
                    ELEC_CONDUCTIVITY_CHK,
                    VOL_STATIC01_CHK,
                    VOL_STATIC02_CHK,
                    VOL_STATIC03_CHK,
                    VOL_STATIC04_CHK,
                    VOL_STATIC05_CHK,
                    VOL_STATIC06_CHK,
                    VOL_STATIC07_CHK,
                    VOL_STATIC08_CHK,
                    VOL_STATIC09_CHK,
                    IMAGE01_CHK,
                    IMAGE02_CHK,
                    IMAGE03_CHK,
                    IMAGE04_CHK,
                    IMAGE05_CHK,
                    ATTRIBUTE01,
                    ATTRIBUTE02,
                    ATTRIBUTE03,
                    ATTRIBUTE04,
                    ATTRIBUTE05,
                    ATTRIBUTE06,
                    ATTRIBUTE07,
                    ATTRIBUTE08,
                    ATTRIBUTE09,
                    ATTRIBUTE10,
                    REMARKS,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    SUB_IMAGE01,
                    SUB_IMAGE02,
                    SUB_IMAGE03,
                    SUB_IMAGE04,
                    SUB_IMAGE05,
                    SUB_IMAGE06,
                    RPT_CMF_1,
                    RPT_CMF_2,
                    RPT_CMF_3,
                    RPT_CMF_4,
                    RPT_CMF_5,
                    RPT_CMF_6,
                    RPT_CMF_7,
                    RPT_CMF_8,
                    RPT_CMF_9,
                    RPT_CMF_10,
                    RPT_CMF_11,
                    RPT_CMF_12,
                    RPT_CMF_13,
                    RPT_CMF_14,
                    RPT_CMF_15
                INTO 
                    :CQCMRPTGRM_N.FACTORY,
                    :CQCMRPTGRM_N.REPORT_NO,
                    :CQCMRPTGRM_N.LOT_ID,
                    :CQCMRPTGRM_N.ITEM_CODE,
                    :CQCMRPTGRM_N.GRADE,
                    :CQCMRPTGRM_N.SIZES,
                    :CQCMRPTGRM_N.HEADER_ID,
                    :CQCMRPTGRM_N.LINE_NUMBER,
                    :CQCMRPTGRM_N.CUST_NO,
                    :CQCMRPTGRM_N.CUST_NAME,
                    :CQCMRPTGRM_N.REPORT_DATE,
                    :CQCMRPTGRM_N.INSP_VALUE,
                    :CQCMRPTGRM_N.SHIP_NAME,
                    :CQCMRPTGRM_N.WT,
                    :CQCMRPTGRM_N.MEAN,
                    :CQCMRPTGRM_N.SD,
                    :CQCMRPTGRM_N.LP,
                    :CQCMRPTGRM_N.ELEC_CONDUCTIVITY,
                    :CQCMRPTGRM_N.VOL_STATIC01,
                    :CQCMRPTGRM_N.VOL_STATIC02,
                    :CQCMRPTGRM_N.VOL_STATIC03,
                    :CQCMRPTGRM_N.VOL_STATIC04,
                    :CQCMRPTGRM_N.VOL_STATIC05,
                    :CQCMRPTGRM_N.VOL_STATIC06,
                    :CQCMRPTGRM_N.VOL_STATIC07,
                    :CQCMRPTGRM_N.VOL_STATIC08,
                    :CQCMRPTGRM_N.VOL_STATIC09,
                    :CQCMRPTGRM_N.IMAGE01,
                    :CQCMRPTGRM_N.IMAGE02,
                    :CQCMRPTGRM_N.IMAGE03,
                    :CQCMRPTGRM_N.IMAGE04,
                    :CQCMRPTGRM_N.IMAGE05,
                    :CQCMRPTGRM_N.ANALYZER,
                    :CQCMRPTGRM_N.WT_CHK,
                    :CQCMRPTGRM_N.MEAN_CHK,
                    :CQCMRPTGRM_N.SD_CHK,
                    :CQCMRPTGRM_N.LP_CHK,
                    :CQCMRPTGRM_N.ELEC_CONDUCTIVITY_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC01_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC02_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC03_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC04_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC05_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC06_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC07_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC08_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC09_CHK,
                    :CQCMRPTGRM_N.IMAGE01_CHK,
                    :CQCMRPTGRM_N.IMAGE02_CHK,
                    :CQCMRPTGRM_N.IMAGE03_CHK,
                    :CQCMRPTGRM_N.IMAGE04_CHK,
                    :CQCMRPTGRM_N.IMAGE05_CHK,
                    :CQCMRPTGRM_N.ATTRIBUTE01,
                    :CQCMRPTGRM_N.ATTRIBUTE02,
                    :CQCMRPTGRM_N.ATTRIBUTE03,
                    :CQCMRPTGRM_N.ATTRIBUTE04,
                    :CQCMRPTGRM_N.ATTRIBUTE05,
                    :CQCMRPTGRM_N.ATTRIBUTE06,
                    :CQCMRPTGRM_N.ATTRIBUTE07,
                    :CQCMRPTGRM_N.ATTRIBUTE08,
                    :CQCMRPTGRM_N.ATTRIBUTE09,
                    :CQCMRPTGRM_N.ATTRIBUTE10,
                    :CQCMRPTGRM_N.REMARKS,
                    :CQCMRPTGRM_N.USE_YN,
                    :CQCMRPTGRM_N.CREATE_USER_ID,
                    :CQCMRPTGRM_N.CREATE_TIME,
                    :CQCMRPTGRM_N.UPDATE_USER_ID,
                    :CQCMRPTGRM_N.UPDATE_TIME,
                    :CQCMRPTGRM_N.SUB_IMAGE01,
                    :CQCMRPTGRM_N.SUB_IMAGE02,
                    :CQCMRPTGRM_N.SUB_IMAGE03,
                    :CQCMRPTGRM_N.SUB_IMAGE04,
                    :CQCMRPTGRM_N.SUB_IMAGE05,
                    :CQCMRPTGRM_N.SUB_IMAGE06,
                    :CQCMRPTGRM_N.RPT_CMF_1,
                    :CQCMRPTGRM_N.RPT_CMF_2,
                    :CQCMRPTGRM_N.RPT_CMF_3,
                    :CQCMRPTGRM_N.RPT_CMF_4,
                    :CQCMRPTGRM_N.RPT_CMF_5,
                    :CQCMRPTGRM_N.RPT_CMF_6,
                    :CQCMRPTGRM_N.RPT_CMF_7,
                    :CQCMRPTGRM_N.RPT_CMF_8,
                    :CQCMRPTGRM_N.RPT_CMF_9,
                    :CQCMRPTGRM_N.RPT_CMF_10,
                    :CQCMRPTGRM_N.RPT_CMF_11,
                    :CQCMRPTGRM_N.RPT_CMF_12,
                    :CQCMRPTGRM_N.RPT_CMF_13,
                    :CQCMRPTGRM_N.RPT_CMF_14,
                    :CQCMRPTGRM_N.RPT_CMF_15
                FROM CQCMRPTGRM
                WHERE FACTORY = :CQCMRPTGRM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTGRM_N.REPORT_NO
                    AND LOT_ID = :CQCMRPTGRM_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,REPORT_NO ,LOT_ID ,ITEM_CODE ,GRADE ,SIZES ,H\
EADER_ID ,LINE_NUMBER ,CUST_NO ,CUST_NAME ,REPORT_DATE ,INSP_VALUE ,SHIP_NAM\
E ,WT ,MEAN ,SD ,LP ,ELEC_CONDUCTIVITY ,VOL_STATIC01 ,VOL_STATIC02 ,VOL_STAT\
IC03 ,VOL_STATIC04 ,VOL_STATIC05 ,VOL_STATIC06 ,VOL_STATIC07 ,VOL_STATIC08 ,\
VOL_STATIC09 ,IMAGE01 ,IMAGE02 ,IMAGE03 ,IMAGE04 ,IMAGE05 ,ANALYZER ,WT_CHK \
,MEAN_CHK ,SD_CHK ,LP_CHK ,ELEC_CONDUCTIVITY_CHK ,VOL_STATIC01_CHK ,VOL_STAT\
IC02_CHK ,VOL_STATIC03_CHK ,VOL_STATIC04_CHK ,VOL_STATIC05_CHK ,VOL_STATIC06\
_CHK ,VOL_STATIC07_CHK ,VOL_STATIC08_CHK ,VOL_STATIC09_CHK ,IMAGE01_CHK ,IMA\
GE02_CHK ,IMAGE03_CHK ,IMAGE04_CHK ,IMAGE05_CHK ,ATTRIBUTE01 ,ATTRIBUTE02 ,A\
TTRIBUTE03 ,ATTRIBUTE04 ,ATTRIBUTE05 ,ATTRIBUTE06 ,ATTRIBUTE07 ,ATTRIBUTE08 \
,ATTRIBUTE09 ,ATTRIBUTE10 ,REMARKS ,USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPD\
ATE_USER_ID ,UPDATE_TIME ,SUB_IMAGE01 ,SUB_IMAGE02 ,SUB_IMAGE03 ,SUB_IMAGE04\
 ,SUB_IMAGE05 ,SUB_IMAGE06 ,RPT_CMF_1 ,RPT_CMF_2 ,RPT_CMF_3 ,RPT_CMF_4 ,RPT_\
CMF_5 ,RPT_CMF_6 ,RPT_CMF_7 ,RPT_CMF_8 ,RPT_CMF_9 ,");
            sqlstm.stmt = "RPT_CMF_10 ,RPT_CMF_11 ,RPT_CMF_12 ,RPT_CMF_13 ,\
RPT_CMF_14 ,RPT_CMF_15 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11\
,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:\
b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b4\
2,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,\
:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b\
73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88\
  from CQCMRPTGRM where ((FACTORY=:b0 and REPORT_NO=:b1) and LOT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRM_N.LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRM_N.ITEM_CODE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGRM_N.GRADE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGRM_N.SIZES);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGRM_N.HEADER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMRPTGRM_N.LINE_NUMBER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGRM_N.CUST_NO);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGRM_N.CUST_NAME);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGRM_N.REPORT_DATE);
            sqlstm.sqhstl[10] = (unsigned int  )9;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGRM_N.INSP_VALUE);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGRM_N.SHIP_NAME);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGRM_N.WT);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGRM_N.MEAN);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGRM_N.SD);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGRM_N.LP);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGRM_N.ELEC_CONDUCTIVITY);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC01);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC02);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC03);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC04);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC05);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC06);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC07);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC08);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC09);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGRM_N.IMAGE01);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGRM_N.IMAGE02);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGRM_N.IMAGE03);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGRM_N.IMAGE04);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGRM_N.IMAGE05);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGRM_N.ANALYZER);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGRM_N.WT_CHK);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGRM_N.MEAN_CHK);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGRM_N.SD_CHK);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGRM_N.LP_CHK);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGRM_N.ELEC_CONDUCTIVITY_CHK);
            sqlstm.sqhstl[37] = (unsigned int  )6;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC01_CHK);
            sqlstm.sqhstl[38] = (unsigned int  )6;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC02_CHK);
            sqlstm.sqhstl[39] = (unsigned int  )6;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC03_CHK);
            sqlstm.sqhstl[40] = (unsigned int  )6;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC04_CHK);
            sqlstm.sqhstl[41] = (unsigned int  )6;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC05_CHK);
            sqlstm.sqhstl[42] = (unsigned int  )6;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC06_CHK);
            sqlstm.sqhstl[43] = (unsigned int  )6;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC07_CHK);
            sqlstm.sqhstl[44] = (unsigned int  )6;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC08_CHK);
            sqlstm.sqhstl[45] = (unsigned int  )6;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC09_CHK);
            sqlstm.sqhstl[46] = (unsigned int  )6;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTGRM_N.IMAGE01_CHK);
            sqlstm.sqhstl[47] = (unsigned int  )6;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTGRM_N.IMAGE02_CHK);
            sqlstm.sqhstl[48] = (unsigned int  )6;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTGRM_N.IMAGE03_CHK);
            sqlstm.sqhstl[49] = (unsigned int  )6;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTGRM_N.IMAGE04_CHK);
            sqlstm.sqhstl[50] = (unsigned int  )6;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTGRM_N.IMAGE05_CHK);
            sqlstm.sqhstl[51] = (unsigned int  )6;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE01);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE02);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE03);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE04);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE05);
            sqlstm.sqhstl[56] = (unsigned int  )51;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE06);
            sqlstm.sqhstl[57] = (unsigned int  )51;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE07);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE08);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE09);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE10);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMRPTGRM_N.REMARKS);
            sqlstm.sqhstl[62] = (unsigned int  )101;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMRPTGRM_N.USE_YN);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMRPTGRM_N.CREATE_USER_ID);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMRPTGRM_N.CREATE_TIME);
            sqlstm.sqhstl[65] = (unsigned int  )15;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMRPTGRM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMRPTGRM_N.UPDATE_TIME);
            sqlstm.sqhstl[67] = (unsigned int  )15;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE01);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE02);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE03);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE04);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE05);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE06);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_1);
            sqlstm.sqhstl[74] = (unsigned int  )51;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_2);
            sqlstm.sqhstl[75] = (unsigned int  )51;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_3);
            sqlstm.sqhstl[76] = (unsigned int  )51;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_4);
            sqlstm.sqhstl[77] = (unsigned int  )51;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_5);
            sqlstm.sqhstl[78] = (unsigned int  )51;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_6);
            sqlstm.sqhstl[79] = (unsigned int  )51;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_7);
            sqlstm.sqhstl[80] = (unsigned int  )51;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_8);
            sqlstm.sqhstl[81] = (unsigned int  )51;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_9);
            sqlstm.sqhstl[82] = (unsigned int  )51;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_10);
            sqlstm.sqhstl[83] = (unsigned int  )51;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_11);
            sqlstm.sqhstl[84] = (unsigned int  )51;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_12);
            sqlstm.sqhstl[85] = (unsigned int  )51;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_13);
            sqlstm.sqhstl[86] = (unsigned int  )51;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_14);
            sqlstm.sqhstl[87] = (unsigned int  )51;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_15);
            sqlstm.sqhstl[88] = (unsigned int  )51;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(CQCMRPTGRM_N.FACTORY);
            sqlstm.sqhstl[89] = (unsigned int  )11;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
            sqlstm.sqhstl[90] = (unsigned int  )21;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(CQCMRPTGRM_N.LOT_ID);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
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
        DBU_del_null_cqcmrptgrm(&CQCMRPTGRM_N, CQCMRPTGRM);
    }

    DB_stop_query_timer("DBU_select_cqcmrptgrm", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cqcmrptgrm_for_update(int sel_type, struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRM_N_TAG CQCMRPTGRM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrm(&CQCMRPTGRM_N, CQCMRPTGRM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    REPORT_NO,
                    LOT_ID,
                    ITEM_CODE,
                    GRADE,
                    SIZES,
                    HEADER_ID,
                    LINE_NUMBER,
                    CUST_NO,
                    CUST_NAME,
                    REPORT_DATE,
                    INSP_VALUE,
                    SHIP_NAME,
                    WT,
                    MEAN,
                    SD,
                    LP,
                    ELEC_CONDUCTIVITY,
                    VOL_STATIC01,
                    VOL_STATIC02,
                    VOL_STATIC03,
                    VOL_STATIC04,
                    VOL_STATIC05,
                    VOL_STATIC06,
                    VOL_STATIC07,
                    VOL_STATIC08,
                    VOL_STATIC09,
                    IMAGE01,
                    IMAGE02,
                    IMAGE03,
                    IMAGE04,
                    IMAGE05,
                    ANALYZER,
                    WT_CHK,
                    MEAN_CHK,
                    SD_CHK,
                    LP_CHK,
                    ELEC_CONDUCTIVITY_CHK,
                    VOL_STATIC01_CHK,
                    VOL_STATIC02_CHK,
                    VOL_STATIC03_CHK,
                    VOL_STATIC04_CHK,
                    VOL_STATIC05_CHK,
                    VOL_STATIC06_CHK,
                    VOL_STATIC07_CHK,
                    VOL_STATIC08_CHK,
                    VOL_STATIC09_CHK,
                    IMAGE01_CHK,
                    IMAGE02_CHK,
                    IMAGE03_CHK,
                    IMAGE04_CHK,
                    IMAGE05_CHK,
                    ATTRIBUTE01,
                    ATTRIBUTE02,
                    ATTRIBUTE03,
                    ATTRIBUTE04,
                    ATTRIBUTE05,
                    ATTRIBUTE06,
                    ATTRIBUTE07,
                    ATTRIBUTE08,
                    ATTRIBUTE09,
                    ATTRIBUTE10,
                    REMARKS,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    SUB_IMAGE01,
                    SUB_IMAGE02,
                    SUB_IMAGE03,
                    SUB_IMAGE04,
                    SUB_IMAGE05,
                    SUB_IMAGE06,
                    RPT_CMF_1,
                    RPT_CMF_2,
                    RPT_CMF_3,
                    RPT_CMF_4,
                    RPT_CMF_5,
                    RPT_CMF_6,
                    RPT_CMF_7,
                    RPT_CMF_8,
                    RPT_CMF_9,
                    RPT_CMF_10,
                    RPT_CMF_11,
                    RPT_CMF_12,
                    RPT_CMF_13,
                    RPT_CMF_14,
                    RPT_CMF_15
                INTO 
                    :CQCMRPTGRM_N.FACTORY,
                    :CQCMRPTGRM_N.REPORT_NO,
                    :CQCMRPTGRM_N.LOT_ID,
                    :CQCMRPTGRM_N.ITEM_CODE,
                    :CQCMRPTGRM_N.GRADE,
                    :CQCMRPTGRM_N.SIZES,
                    :CQCMRPTGRM_N.HEADER_ID,
                    :CQCMRPTGRM_N.LINE_NUMBER,
                    :CQCMRPTGRM_N.CUST_NO,
                    :CQCMRPTGRM_N.CUST_NAME,
                    :CQCMRPTGRM_N.REPORT_DATE,
                    :CQCMRPTGRM_N.INSP_VALUE,
                    :CQCMRPTGRM_N.SHIP_NAME,
                    :CQCMRPTGRM_N.WT,
                    :CQCMRPTGRM_N.MEAN,
                    :CQCMRPTGRM_N.SD,
                    :CQCMRPTGRM_N.LP,
                    :CQCMRPTGRM_N.ELEC_CONDUCTIVITY,
                    :CQCMRPTGRM_N.VOL_STATIC01,
                    :CQCMRPTGRM_N.VOL_STATIC02,
                    :CQCMRPTGRM_N.VOL_STATIC03,
                    :CQCMRPTGRM_N.VOL_STATIC04,
                    :CQCMRPTGRM_N.VOL_STATIC05,
                    :CQCMRPTGRM_N.VOL_STATIC06,
                    :CQCMRPTGRM_N.VOL_STATIC07,
                    :CQCMRPTGRM_N.VOL_STATIC08,
                    :CQCMRPTGRM_N.VOL_STATIC09,
                    :CQCMRPTGRM_N.IMAGE01,
                    :CQCMRPTGRM_N.IMAGE02,
                    :CQCMRPTGRM_N.IMAGE03,
                    :CQCMRPTGRM_N.IMAGE04,
                    :CQCMRPTGRM_N.IMAGE05,
                    :CQCMRPTGRM_N.ANALYZER,
                    :CQCMRPTGRM_N.WT_CHK,
                    :CQCMRPTGRM_N.MEAN_CHK,
                    :CQCMRPTGRM_N.SD_CHK,
                    :CQCMRPTGRM_N.LP_CHK,
                    :CQCMRPTGRM_N.ELEC_CONDUCTIVITY_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC01_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC02_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC03_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC04_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC05_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC06_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC07_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC08_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC09_CHK,
                    :CQCMRPTGRM_N.IMAGE01_CHK,
                    :CQCMRPTGRM_N.IMAGE02_CHK,
                    :CQCMRPTGRM_N.IMAGE03_CHK,
                    :CQCMRPTGRM_N.IMAGE04_CHK,
                    :CQCMRPTGRM_N.IMAGE05_CHK,
                    :CQCMRPTGRM_N.ATTRIBUTE01,
                    :CQCMRPTGRM_N.ATTRIBUTE02,
                    :CQCMRPTGRM_N.ATTRIBUTE03,
                    :CQCMRPTGRM_N.ATTRIBUTE04,
                    :CQCMRPTGRM_N.ATTRIBUTE05,
                    :CQCMRPTGRM_N.ATTRIBUTE06,
                    :CQCMRPTGRM_N.ATTRIBUTE07,
                    :CQCMRPTGRM_N.ATTRIBUTE08,
                    :CQCMRPTGRM_N.ATTRIBUTE09,
                    :CQCMRPTGRM_N.ATTRIBUTE10,
                    :CQCMRPTGRM_N.REMARKS,
                    :CQCMRPTGRM_N.USE_YN,
                    :CQCMRPTGRM_N.CREATE_USER_ID,
                    :CQCMRPTGRM_N.CREATE_TIME,
                    :CQCMRPTGRM_N.UPDATE_USER_ID,
                    :CQCMRPTGRM_N.UPDATE_TIME,
                    :CQCMRPTGRM_N.SUB_IMAGE01,
                    :CQCMRPTGRM_N.SUB_IMAGE02,
                    :CQCMRPTGRM_N.SUB_IMAGE03,
                    :CQCMRPTGRM_N.SUB_IMAGE04,
                    :CQCMRPTGRM_N.SUB_IMAGE05,
                    :CQCMRPTGRM_N.SUB_IMAGE06,
                    :CQCMRPTGRM_N.RPT_CMF_1,
                    :CQCMRPTGRM_N.RPT_CMF_2,
                    :CQCMRPTGRM_N.RPT_CMF_3,
                    :CQCMRPTGRM_N.RPT_CMF_4,
                    :CQCMRPTGRM_N.RPT_CMF_5,
                    :CQCMRPTGRM_N.RPT_CMF_6,
                    :CQCMRPTGRM_N.RPT_CMF_7,
                    :CQCMRPTGRM_N.RPT_CMF_8,
                    :CQCMRPTGRM_N.RPT_CMF_9,
                    :CQCMRPTGRM_N.RPT_CMF_10,
                    :CQCMRPTGRM_N.RPT_CMF_11,
                    :CQCMRPTGRM_N.RPT_CMF_12,
                    :CQCMRPTGRM_N.RPT_CMF_13,
                    :CQCMRPTGRM_N.RPT_CMF_14,
                    :CQCMRPTGRM_N.RPT_CMF_15
                FROM CQCMRPTGRM
                WHERE FACTORY = :CQCMRPTGRM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTGRM_N.REPORT_NO
                    AND LOT_ID = :CQCMRPTGRM_N.LOT_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,REPORT_NO ,LOT_ID ,ITEM_CODE ,GRADE ,SIZES ,H\
EADER_ID ,LINE_NUMBER ,CUST_NO ,CUST_NAME ,REPORT_DATE ,INSP_VALUE ,SHIP_NAM\
E ,WT ,MEAN ,SD ,LP ,ELEC_CONDUCTIVITY ,VOL_STATIC01 ,VOL_STATIC02 ,VOL_STAT\
IC03 ,VOL_STATIC04 ,VOL_STATIC05 ,VOL_STATIC06 ,VOL_STATIC07 ,VOL_STATIC08 ,\
VOL_STATIC09 ,IMAGE01 ,IMAGE02 ,IMAGE03 ,IMAGE04 ,IMAGE05 ,ANALYZER ,WT_CHK \
,MEAN_CHK ,SD_CHK ,LP_CHK ,ELEC_CONDUCTIVITY_CHK ,VOL_STATIC01_CHK ,VOL_STAT\
IC02_CHK ,VOL_STATIC03_CHK ,VOL_STATIC04_CHK ,VOL_STATIC05_CHK ,VOL_STATIC06\
_CHK ,VOL_STATIC07_CHK ,VOL_STATIC08_CHK ,VOL_STATIC09_CHK ,IMAGE01_CHK ,IMA\
GE02_CHK ,IMAGE03_CHK ,IMAGE04_CHK ,IMAGE05_CHK ,ATTRIBUTE01 ,ATTRIBUTE02 ,A\
TTRIBUTE03 ,ATTRIBUTE04 ,ATTRIBUTE05 ,ATTRIBUTE06 ,ATTRIBUTE07 ,ATTRIBUTE08 \
,ATTRIBUTE09 ,ATTRIBUTE10 ,REMARKS ,USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPD\
ATE_USER_ID ,UPDATE_TIME ,SUB_IMAGE01 ,SUB_IMAGE02 ,SUB_IMAGE03 ,SUB_IMAGE04\
 ,SUB_IMAGE05 ,SUB_IMAGE06 ,RPT_CMF_1 ,RPT_CMF_2 ,RPT_CMF_3 ,RPT_CMF_4 ,RPT_\
CMF_5 ,RPT_CMF_6 ,RPT_CMF_7 ,RPT_CMF_8 ,RPT_CMF_9 ,");
            sqlstm.stmt = "RPT_CMF_10 ,RPT_CMF_11 ,RPT_CMF_12 ,RPT_CMF_13 ,\
RPT_CMF_14 ,RPT_CMF_15 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11\
,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:\
b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b4\
2,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,\
:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b\
73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88\
  from CQCMRPTGRM where ((FACTORY=:b0 and REPORT_NO=:b1) and LOT_ID=:b2) for \
update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )388;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRM_N.LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRM_N.ITEM_CODE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGRM_N.GRADE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGRM_N.SIZES);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGRM_N.HEADER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMRPTGRM_N.LINE_NUMBER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGRM_N.CUST_NO);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGRM_N.CUST_NAME);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGRM_N.REPORT_DATE);
            sqlstm.sqhstl[10] = (unsigned int  )9;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGRM_N.INSP_VALUE);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGRM_N.SHIP_NAME);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGRM_N.WT);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGRM_N.MEAN);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGRM_N.SD);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGRM_N.LP);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGRM_N.ELEC_CONDUCTIVITY);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC01);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC02);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC03);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC04);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC05);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC06);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC07);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC08);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC09);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGRM_N.IMAGE01);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGRM_N.IMAGE02);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGRM_N.IMAGE03);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGRM_N.IMAGE04);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGRM_N.IMAGE05);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGRM_N.ANALYZER);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGRM_N.WT_CHK);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGRM_N.MEAN_CHK);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGRM_N.SD_CHK);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGRM_N.LP_CHK);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGRM_N.ELEC_CONDUCTIVITY_CHK);
            sqlstm.sqhstl[37] = (unsigned int  )6;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC01_CHK);
            sqlstm.sqhstl[38] = (unsigned int  )6;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC02_CHK);
            sqlstm.sqhstl[39] = (unsigned int  )6;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC03_CHK);
            sqlstm.sqhstl[40] = (unsigned int  )6;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC04_CHK);
            sqlstm.sqhstl[41] = (unsigned int  )6;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC05_CHK);
            sqlstm.sqhstl[42] = (unsigned int  )6;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC06_CHK);
            sqlstm.sqhstl[43] = (unsigned int  )6;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC07_CHK);
            sqlstm.sqhstl[44] = (unsigned int  )6;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC08_CHK);
            sqlstm.sqhstl[45] = (unsigned int  )6;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC09_CHK);
            sqlstm.sqhstl[46] = (unsigned int  )6;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTGRM_N.IMAGE01_CHK);
            sqlstm.sqhstl[47] = (unsigned int  )6;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTGRM_N.IMAGE02_CHK);
            sqlstm.sqhstl[48] = (unsigned int  )6;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTGRM_N.IMAGE03_CHK);
            sqlstm.sqhstl[49] = (unsigned int  )6;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTGRM_N.IMAGE04_CHK);
            sqlstm.sqhstl[50] = (unsigned int  )6;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTGRM_N.IMAGE05_CHK);
            sqlstm.sqhstl[51] = (unsigned int  )6;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE01);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE02);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE03);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE04);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE05);
            sqlstm.sqhstl[56] = (unsigned int  )51;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE06);
            sqlstm.sqhstl[57] = (unsigned int  )51;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE07);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE08);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE09);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE10);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMRPTGRM_N.REMARKS);
            sqlstm.sqhstl[62] = (unsigned int  )101;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMRPTGRM_N.USE_YN);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMRPTGRM_N.CREATE_USER_ID);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMRPTGRM_N.CREATE_TIME);
            sqlstm.sqhstl[65] = (unsigned int  )15;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMRPTGRM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMRPTGRM_N.UPDATE_TIME);
            sqlstm.sqhstl[67] = (unsigned int  )15;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE01);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE02);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE03);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE04);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE05);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE06);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_1);
            sqlstm.sqhstl[74] = (unsigned int  )51;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_2);
            sqlstm.sqhstl[75] = (unsigned int  )51;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_3);
            sqlstm.sqhstl[76] = (unsigned int  )51;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_4);
            sqlstm.sqhstl[77] = (unsigned int  )51;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_5);
            sqlstm.sqhstl[78] = (unsigned int  )51;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_6);
            sqlstm.sqhstl[79] = (unsigned int  )51;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_7);
            sqlstm.sqhstl[80] = (unsigned int  )51;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_8);
            sqlstm.sqhstl[81] = (unsigned int  )51;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_9);
            sqlstm.sqhstl[82] = (unsigned int  )51;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_10);
            sqlstm.sqhstl[83] = (unsigned int  )51;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_11);
            sqlstm.sqhstl[84] = (unsigned int  )51;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_12);
            sqlstm.sqhstl[85] = (unsigned int  )51;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_13);
            sqlstm.sqhstl[86] = (unsigned int  )51;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_14);
            sqlstm.sqhstl[87] = (unsigned int  )51;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_15);
            sqlstm.sqhstl[88] = (unsigned int  )51;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(CQCMRPTGRM_N.FACTORY);
            sqlstm.sqhstl[89] = (unsigned int  )11;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
            sqlstm.sqhstl[90] = (unsigned int  )21;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(CQCMRPTGRM_N.LOT_ID);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
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
        DBU_del_null_cqcmrptgrm(&CQCMRPTGRM_N, CQCMRPTGRM);
    }

    DB_stop_query_timer("DBU_select_cqcmrptgrm_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cqcmrptgrm_scalar(int sel_type, struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRM_N_TAG CQCMRPTGRM_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrm(&CQCMRPTGRM_N, CQCMRPTGRM);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMRPTGRM
                WHERE FACTORY = :CQCMRPTGRM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTGRM_N.REPORT_NO
                    AND LOT_ID = :CQCMRPTGRM_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMRPTGRM where\
 ((FACTORY=:b1 and REPORT_NO=:b2) and LOT_ID=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )771;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRM_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRM_N.LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
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
                FROM CQCMRPTGRM
                WHERE FACTORY = :CQCMRPTGRM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTGRM_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMRPTGRM where\
 (FACTORY=:b1 and REPORT_NO=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )802;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRM_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
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

    DB_stop_query_timer("DBU_select_cqcmrptgrm_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cqcmrptgrm(int sel_type, struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRM_N_TAG CQCMRPTGRM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrm(&CQCMRPTGRM_N, CQCMRPTGRM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CQCMRPTGRM
                WHERE FACTORY = :CQCMRPTGRM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTGRM_N.REPORT_NO
                    AND LOT_ID = :CQCMRPTGRM_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMRPTGRM  where ((FACTORY=:b0 and\
 REPORT_NO=:b1) and LOT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )829;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRM_N.LOT_ID);
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

		case 2:
            /* EXEC SQL DELETE FROM CQCMRPTGRM
                WHERE FACTORY = :CQCMRPTGRM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTGRM_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMRPTGRM  where (FACTORY=:b0 and \
REPORT_NO=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )856;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
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

    DB_stop_query_timer("DBU_delete_cqcmrptgrm", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cqcmrptgrm(struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRM_N_TAG CQCMRPTGRM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrm(&CQCMRPTGRM_N, CQCMRPTGRM);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CQCMRPTGRM( 
                    FACTORY, 
                    REPORT_NO, 
                    LOT_ID, 
                    ITEM_CODE, 
                    GRADE, 
                    SIZES, 
                    HEADER_ID, 
                    LINE_NUMBER, 
                    CUST_NO, 
                    CUST_NAME, 
                    REPORT_DATE, 
                    INSP_VALUE, 
                    SHIP_NAME, 
                    WT, 
                    MEAN, 
                    SD, 
                    LP, 
                    ELEC_CONDUCTIVITY, 
                    VOL_STATIC01, 
                    VOL_STATIC02, 
                    VOL_STATIC03, 
                    VOL_STATIC04, 
                    VOL_STATIC05, 
                    VOL_STATIC06, 
                    VOL_STATIC07, 
                    VOL_STATIC08, 
                    VOL_STATIC09, 
                    IMAGE01, 
                    IMAGE02, 
                    IMAGE03, 
                    IMAGE04, 
                    IMAGE05, 
                    ANALYZER, 
                    WT_CHK, 
                    MEAN_CHK, 
                    SD_CHK, 
                    LP_CHK, 
                    ELEC_CONDUCTIVITY_CHK, 
                    VOL_STATIC01_CHK, 
                    VOL_STATIC02_CHK, 
                    VOL_STATIC03_CHK, 
                    VOL_STATIC04_CHK, 
                    VOL_STATIC05_CHK, 
                    VOL_STATIC06_CHK, 
                    VOL_STATIC07_CHK, 
                    VOL_STATIC08_CHK, 
                    VOL_STATIC09_CHK, 
                    IMAGE01_CHK, 
                    IMAGE02_CHK, 
                    IMAGE03_CHK, 
                    IMAGE04_CHK, 
                    IMAGE05_CHK, 
                    ATTRIBUTE01, 
                    ATTRIBUTE02, 
                    ATTRIBUTE03, 
                    ATTRIBUTE04, 
                    ATTRIBUTE05, 
                    ATTRIBUTE06, 
                    ATTRIBUTE07, 
                    ATTRIBUTE08, 
                    ATTRIBUTE09, 
                    ATTRIBUTE10, 
                    REMARKS, 
                    USE_YN, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    SUB_IMAGE01, 
                    SUB_IMAGE02, 
                    SUB_IMAGE03, 
                    SUB_IMAGE04, 
                    SUB_IMAGE05, 
                    SUB_IMAGE06, 
                    RPT_CMF_1, 
                    RPT_CMF_2, 
                    RPT_CMF_3, 
                    RPT_CMF_4, 
                    RPT_CMF_5, 
                    RPT_CMF_6, 
                    RPT_CMF_7, 
                    RPT_CMF_8, 
                    RPT_CMF_9, 
                    RPT_CMF_10, 
                    RPT_CMF_11, 
                    RPT_CMF_12, 
                    RPT_CMF_13, 
                    RPT_CMF_14, 
                    RPT_CMF_15
         ) 
        VALUES (
                    :CQCMRPTGRM_N.FACTORY,
                    :CQCMRPTGRM_N.REPORT_NO,
                    :CQCMRPTGRM_N.LOT_ID,
                    :CQCMRPTGRM_N.ITEM_CODE,
                    :CQCMRPTGRM_N.GRADE,
                    :CQCMRPTGRM_N.SIZES,
                    :CQCMRPTGRM_N.HEADER_ID,
                    :CQCMRPTGRM_N.LINE_NUMBER,
                    :CQCMRPTGRM_N.CUST_NO,
                    :CQCMRPTGRM_N.CUST_NAME,
                    :CQCMRPTGRM_N.REPORT_DATE,
                    :CQCMRPTGRM_N.INSP_VALUE,
                    :CQCMRPTGRM_N.SHIP_NAME,
                    :CQCMRPTGRM_N.WT,
                    :CQCMRPTGRM_N.MEAN,
                    :CQCMRPTGRM_N.SD,
                    :CQCMRPTGRM_N.LP,
                    :CQCMRPTGRM_N.ELEC_CONDUCTIVITY,
                    :CQCMRPTGRM_N.VOL_STATIC01,
                    :CQCMRPTGRM_N.VOL_STATIC02,
                    :CQCMRPTGRM_N.VOL_STATIC03,
                    :CQCMRPTGRM_N.VOL_STATIC04,
                    :CQCMRPTGRM_N.VOL_STATIC05,
                    :CQCMRPTGRM_N.VOL_STATIC06,
                    :CQCMRPTGRM_N.VOL_STATIC07,
                    :CQCMRPTGRM_N.VOL_STATIC08,
                    :CQCMRPTGRM_N.VOL_STATIC09,
                    :CQCMRPTGRM_N.IMAGE01,
                    :CQCMRPTGRM_N.IMAGE02,
                    :CQCMRPTGRM_N.IMAGE03,
                    :CQCMRPTGRM_N.IMAGE04,
                    :CQCMRPTGRM_N.IMAGE05,
                    :CQCMRPTGRM_N.ANALYZER,
                    :CQCMRPTGRM_N.WT_CHK,
                    :CQCMRPTGRM_N.MEAN_CHK,
                    :CQCMRPTGRM_N.SD_CHK,
                    :CQCMRPTGRM_N.LP_CHK,
                    :CQCMRPTGRM_N.ELEC_CONDUCTIVITY_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC01_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC02_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC03_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC04_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC05_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC06_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC07_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC08_CHK,
                    :CQCMRPTGRM_N.VOL_STATIC09_CHK,
                    :CQCMRPTGRM_N.IMAGE01_CHK,
                    :CQCMRPTGRM_N.IMAGE02_CHK,
                    :CQCMRPTGRM_N.IMAGE03_CHK,
                    :CQCMRPTGRM_N.IMAGE04_CHK,
                    :CQCMRPTGRM_N.IMAGE05_CHK,
                    :CQCMRPTGRM_N.ATTRIBUTE01,
                    :CQCMRPTGRM_N.ATTRIBUTE02,
                    :CQCMRPTGRM_N.ATTRIBUTE03,
                    :CQCMRPTGRM_N.ATTRIBUTE04,
                    :CQCMRPTGRM_N.ATTRIBUTE05,
                    :CQCMRPTGRM_N.ATTRIBUTE06,
                    :CQCMRPTGRM_N.ATTRIBUTE07,
                    :CQCMRPTGRM_N.ATTRIBUTE08,
                    :CQCMRPTGRM_N.ATTRIBUTE09,
                    :CQCMRPTGRM_N.ATTRIBUTE10,
                    :CQCMRPTGRM_N.REMARKS,
                    :CQCMRPTGRM_N.USE_YN,
                    :CQCMRPTGRM_N.CREATE_USER_ID,
                    :CQCMRPTGRM_N.CREATE_TIME,
                    :CQCMRPTGRM_N.UPDATE_USER_ID,
                    :CQCMRPTGRM_N.UPDATE_TIME,
                    :CQCMRPTGRM_N.SUB_IMAGE01,
                    :CQCMRPTGRM_N.SUB_IMAGE02,
                    :CQCMRPTGRM_N.SUB_IMAGE03,
                    :CQCMRPTGRM_N.SUB_IMAGE04,
                    :CQCMRPTGRM_N.SUB_IMAGE05,
                    :CQCMRPTGRM_N.SUB_IMAGE06,
                    :CQCMRPTGRM_N.RPT_CMF_1,
                    :CQCMRPTGRM_N.RPT_CMF_2,
                    :CQCMRPTGRM_N.RPT_CMF_3,
                    :CQCMRPTGRM_N.RPT_CMF_4,
                    :CQCMRPTGRM_N.RPT_CMF_5,
                    :CQCMRPTGRM_N.RPT_CMF_6,
                    :CQCMRPTGRM_N.RPT_CMF_7,
                    :CQCMRPTGRM_N.RPT_CMF_8,
                    :CQCMRPTGRM_N.RPT_CMF_9,
                    :CQCMRPTGRM_N.RPT_CMF_10,
                    :CQCMRPTGRM_N.RPT_CMF_11,
                    :CQCMRPTGRM_N.RPT_CMF_12,
                    :CQCMRPTGRM_N.RPT_CMF_13,
                    :CQCMRPTGRM_N.RPT_CMF_14,
                    :CQCMRPTGRM_N.RPT_CMF_15
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 92;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into CQCMRPTGRM (FACTORY,REPORT_NO,LOT_ID,ITEM_CODE,GRADE,SIZE\
S,HEADER_ID,LINE_NUMBER,CUST_NO,CUST_NAME,REPORT_DATE,INSP_VALUE,SHIP_NAME,W\
T,MEAN,SD,LP,ELEC_CONDUCTIVITY,VOL_STATIC01,VOL_STATIC02,VOL_STATIC03,VOL_ST\
ATIC04,VOL_STATIC05,VOL_STATIC06,VOL_STATIC07,VOL_STATIC08,VOL_STATIC09,IMAG\
E01,IMAGE02,IMAGE03,IMAGE04,IMAGE05,ANALYZER,WT_CHK,MEAN_CHK,SD_CHK,LP_CHK,E\
LEC_CONDUCTIVITY_CHK,VOL_STATIC01_CHK,VOL_STATIC02_CHK,VOL_STATIC03_CHK,VOL_\
STATIC04_CHK,VOL_STATIC05_CHK,VOL_STATIC06_CHK,VOL_STATIC07_CHK,VOL_STATIC08\
_CHK,VOL_STATIC09_CHK,IMAGE01_CHK,IMAGE02_CHK,IMAGE03_CHK,IMAGE04_CHK,IMAGE0\
5_CHK,ATTRIBUTE01,ATTRIBUTE02,ATTRIBUTE03,ATTRIBUTE04,ATTRIBUTE05,ATTRIBUTE0\
6,ATTRIBUTE07,ATTRIBUTE08,ATTRIBUTE09,ATTRIBUTE10,REMARKS,USE_YN,CREATE_USER\
_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME,SUB_IMAGE01,SUB_IMAGE02,SUB_IMAGE\
03,SUB_IMAGE04,SUB_IMAGE05,SUB_IMAGE06,RPT_CMF_1,RPT_CMF_2,RPT_CMF_3,RPT_CMF\
_4,RPT_CMF_5,RPT_CMF_6,RPT_CMF_7,RPT_CMF_8,RPT_CMF_9,RPT_CMF_10,RPT_CMF_11,R\
PT_CMF_12,RPT_CMF_13,RPT_CMF_14,RPT_CMF_15)");
    sqlstm.stmt = " values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b\
11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26\
,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:\
b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b5\
7,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,\
:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b\
88)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )879;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRM_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRM_N.LOT_ID);
    sqlstm.sqhstl[2] = (unsigned int  )21;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRM_N.ITEM_CODE);
    sqlstm.sqhstl[3] = (unsigned int  )21;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGRM_N.GRADE);
    sqlstm.sqhstl[4] = (unsigned int  )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGRM_N.SIZES);
    sqlstm.sqhstl[5] = (unsigned int  )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGRM_N.HEADER_ID);
    sqlstm.sqhstl[6] = (unsigned int  )21;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)&(CQCMRPTGRM_N.LINE_NUMBER);
    sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGRM_N.CUST_NO);
    sqlstm.sqhstl[8] = (unsigned int  )31;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGRM_N.CUST_NAME);
    sqlstm.sqhstl[9] = (unsigned int  )101;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGRM_N.REPORT_DATE);
    sqlstm.sqhstl[10] = (unsigned int  )9;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGRM_N.INSP_VALUE);
    sqlstm.sqhstl[11] = (unsigned int  )21;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGRM_N.SHIP_NAME);
    sqlstm.sqhstl[12] = (unsigned int  )101;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGRM_N.WT);
    sqlstm.sqhstl[13] = (unsigned int  )21;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGRM_N.MEAN);
    sqlstm.sqhstl[14] = (unsigned int  )21;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGRM_N.SD);
    sqlstm.sqhstl[15] = (unsigned int  )21;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGRM_N.LP);
    sqlstm.sqhstl[16] = (unsigned int  )21;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGRM_N.ELEC_CONDUCTIVITY);
    sqlstm.sqhstl[17] = (unsigned int  )21;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC01);
    sqlstm.sqhstl[18] = (unsigned int  )21;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC02);
    sqlstm.sqhstl[19] = (unsigned int  )21;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC03);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC04);
    sqlstm.sqhstl[21] = (unsigned int  )21;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC05);
    sqlstm.sqhstl[22] = (unsigned int  )21;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC06);
    sqlstm.sqhstl[23] = (unsigned int  )21;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC07);
    sqlstm.sqhstl[24] = (unsigned int  )21;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC08);
    sqlstm.sqhstl[25] = (unsigned int  )21;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC09);
    sqlstm.sqhstl[26] = (unsigned int  )21;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGRM_N.IMAGE01);
    sqlstm.sqhstl[27] = (unsigned int  )21;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGRM_N.IMAGE02);
    sqlstm.sqhstl[28] = (unsigned int  )21;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGRM_N.IMAGE03);
    sqlstm.sqhstl[29] = (unsigned int  )21;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGRM_N.IMAGE04);
    sqlstm.sqhstl[30] = (unsigned int  )21;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGRM_N.IMAGE05);
    sqlstm.sqhstl[31] = (unsigned int  )21;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGRM_N.ANALYZER);
    sqlstm.sqhstl[32] = (unsigned int  )21;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGRM_N.WT_CHK);
    sqlstm.sqhstl[33] = (unsigned int  )21;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGRM_N.MEAN_CHK);
    sqlstm.sqhstl[34] = (unsigned int  )21;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGRM_N.SD_CHK);
    sqlstm.sqhstl[35] = (unsigned int  )21;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGRM_N.LP_CHK);
    sqlstm.sqhstl[36] = (unsigned int  )21;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGRM_N.ELEC_CONDUCTIVITY_CHK);
    sqlstm.sqhstl[37] = (unsigned int  )6;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC01_CHK);
    sqlstm.sqhstl[38] = (unsigned int  )6;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC02_CHK);
    sqlstm.sqhstl[39] = (unsigned int  )6;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC03_CHK);
    sqlstm.sqhstl[40] = (unsigned int  )6;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC04_CHK);
    sqlstm.sqhstl[41] = (unsigned int  )6;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC05_CHK);
    sqlstm.sqhstl[42] = (unsigned int  )6;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC06_CHK);
    sqlstm.sqhstl[43] = (unsigned int  )6;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC07_CHK);
    sqlstm.sqhstl[44] = (unsigned int  )6;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC08_CHK);
    sqlstm.sqhstl[45] = (unsigned int  )6;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC09_CHK);
    sqlstm.sqhstl[46] = (unsigned int  )6;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(CQCMRPTGRM_N.IMAGE01_CHK);
    sqlstm.sqhstl[47] = (unsigned int  )6;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(CQCMRPTGRM_N.IMAGE02_CHK);
    sqlstm.sqhstl[48] = (unsigned int  )6;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(CQCMRPTGRM_N.IMAGE03_CHK);
    sqlstm.sqhstl[49] = (unsigned int  )6;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(CQCMRPTGRM_N.IMAGE04_CHK);
    sqlstm.sqhstl[50] = (unsigned int  )6;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(CQCMRPTGRM_N.IMAGE05_CHK);
    sqlstm.sqhstl[51] = (unsigned int  )6;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE01);
    sqlstm.sqhstl[52] = (unsigned int  )51;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE02);
    sqlstm.sqhstl[53] = (unsigned int  )51;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE03);
    sqlstm.sqhstl[54] = (unsigned int  )51;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE04);
    sqlstm.sqhstl[55] = (unsigned int  )51;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE05);
    sqlstm.sqhstl[56] = (unsigned int  )51;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE06);
    sqlstm.sqhstl[57] = (unsigned int  )51;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE07);
    sqlstm.sqhstl[58] = (unsigned int  )51;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE08);
    sqlstm.sqhstl[59] = (unsigned int  )51;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE09);
    sqlstm.sqhstl[60] = (unsigned int  )51;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE10);
    sqlstm.sqhstl[61] = (unsigned int  )51;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(CQCMRPTGRM_N.REMARKS);
    sqlstm.sqhstl[62] = (unsigned int  )101;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(CQCMRPTGRM_N.USE_YN);
    sqlstm.sqhstl[63] = (unsigned int  )2;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(CQCMRPTGRM_N.CREATE_USER_ID);
    sqlstm.sqhstl[64] = (unsigned int  )21;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(CQCMRPTGRM_N.CREATE_TIME);
    sqlstm.sqhstl[65] = (unsigned int  )15;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(CQCMRPTGRM_N.UPDATE_USER_ID);
    sqlstm.sqhstl[66] = (unsigned int  )21;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(CQCMRPTGRM_N.UPDATE_TIME);
    sqlstm.sqhstl[67] = (unsigned int  )15;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE01);
    sqlstm.sqhstl[68] = (unsigned int  )21;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE02);
    sqlstm.sqhstl[69] = (unsigned int  )21;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE03);
    sqlstm.sqhstl[70] = (unsigned int  )21;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE04);
    sqlstm.sqhstl[71] = (unsigned int  )21;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE05);
    sqlstm.sqhstl[72] = (unsigned int  )21;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE06);
    sqlstm.sqhstl[73] = (unsigned int  )21;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_1);
    sqlstm.sqhstl[74] = (unsigned int  )51;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_2);
    sqlstm.sqhstl[75] = (unsigned int  )51;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_3);
    sqlstm.sqhstl[76] = (unsigned int  )51;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_4);
    sqlstm.sqhstl[77] = (unsigned int  )51;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_5);
    sqlstm.sqhstl[78] = (unsigned int  )51;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_6);
    sqlstm.sqhstl[79] = (unsigned int  )51;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_7);
    sqlstm.sqhstl[80] = (unsigned int  )51;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_8);
    sqlstm.sqhstl[81] = (unsigned int  )51;
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_9);
    sqlstm.sqhstl[82] = (unsigned int  )51;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_10);
    sqlstm.sqhstl[83] = (unsigned int  )51;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_11);
    sqlstm.sqhstl[84] = (unsigned int  )51;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_12);
    sqlstm.sqhstl[85] = (unsigned int  )51;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_13);
    sqlstm.sqhstl[86] = (unsigned int  )51;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_14);
    sqlstm.sqhstl[87] = (unsigned int  )51;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
    sqlstm.sqhstv[88] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_15);
    sqlstm.sqhstl[88] = (unsigned int  )51;
    sqlstm.sqhsts[88] = (         int  )0;
    sqlstm.sqindv[88] = (         void  *)0;
    sqlstm.sqinds[88] = (         int  )0;
    sqlstm.sqharm[88] = (unsigned int  )0;
    sqlstm.sqadto[88] = (unsigned short )0;
    sqlstm.sqtdso[88] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_cqcmrptgrm", 0);
}


/* SQL UPDATE Function */
void DBU_update_cqcmrptgrm(int sel_type, struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRM_N_TAG CQCMRPTGRM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrm(&CQCMRPTGRM_N, CQCMRPTGRM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CQCMRPTGRM SET
                    ITEM_CODE = :CQCMRPTGRM_N.ITEM_CODE,
                    GRADE = :CQCMRPTGRM_N.GRADE,
                    SIZES = :CQCMRPTGRM_N.SIZES,
                    HEADER_ID = :CQCMRPTGRM_N.HEADER_ID,
                    LINE_NUMBER = :CQCMRPTGRM_N.LINE_NUMBER,
                    CUST_NO = :CQCMRPTGRM_N.CUST_NO,
                    CUST_NAME = :CQCMRPTGRM_N.CUST_NAME,
                    REPORT_DATE = :CQCMRPTGRM_N.REPORT_DATE,
                    INSP_VALUE = :CQCMRPTGRM_N.INSP_VALUE,
                    SHIP_NAME = :CQCMRPTGRM_N.SHIP_NAME,
                    WT = :CQCMRPTGRM_N.WT,
                    MEAN = :CQCMRPTGRM_N.MEAN,
                    SD = :CQCMRPTGRM_N.SD,
                    LP = :CQCMRPTGRM_N.LP,
                    ELEC_CONDUCTIVITY = :CQCMRPTGRM_N.ELEC_CONDUCTIVITY,
                    VOL_STATIC01 = :CQCMRPTGRM_N.VOL_STATIC01,
                    VOL_STATIC02 = :CQCMRPTGRM_N.VOL_STATIC02,
                    VOL_STATIC03 = :CQCMRPTGRM_N.VOL_STATIC03,
                    VOL_STATIC04 = :CQCMRPTGRM_N.VOL_STATIC04,
                    VOL_STATIC05 = :CQCMRPTGRM_N.VOL_STATIC05,
                    VOL_STATIC06 = :CQCMRPTGRM_N.VOL_STATIC06,
                    VOL_STATIC07 = :CQCMRPTGRM_N.VOL_STATIC07,
                    VOL_STATIC08 = :CQCMRPTGRM_N.VOL_STATIC08,
                    VOL_STATIC09 = :CQCMRPTGRM_N.VOL_STATIC09,
                    IMAGE01 = :CQCMRPTGRM_N.IMAGE01,
                    IMAGE02 = :CQCMRPTGRM_N.IMAGE02,
                    IMAGE03 = :CQCMRPTGRM_N.IMAGE03,
                    IMAGE04 = :CQCMRPTGRM_N.IMAGE04,
                    IMAGE05 = :CQCMRPTGRM_N.IMAGE05,
                    ANALYZER = :CQCMRPTGRM_N.ANALYZER,
                    WT_CHK = :CQCMRPTGRM_N.WT_CHK,
                    MEAN_CHK = :CQCMRPTGRM_N.MEAN_CHK,
                    SD_CHK = :CQCMRPTGRM_N.SD_CHK,
                    LP_CHK = :CQCMRPTGRM_N.LP_CHK,
                    ELEC_CONDUCTIVITY_CHK = :CQCMRPTGRM_N.ELEC_CONDUCTIVITY_CHK,
                    VOL_STATIC01_CHK = :CQCMRPTGRM_N.VOL_STATIC01_CHK,
                    VOL_STATIC02_CHK = :CQCMRPTGRM_N.VOL_STATIC02_CHK,
                    VOL_STATIC03_CHK = :CQCMRPTGRM_N.VOL_STATIC03_CHK,
                    VOL_STATIC04_CHK = :CQCMRPTGRM_N.VOL_STATIC04_CHK,
                    VOL_STATIC05_CHK = :CQCMRPTGRM_N.VOL_STATIC05_CHK,
                    VOL_STATIC06_CHK = :CQCMRPTGRM_N.VOL_STATIC06_CHK,
                    VOL_STATIC07_CHK = :CQCMRPTGRM_N.VOL_STATIC07_CHK,
                    VOL_STATIC08_CHK = :CQCMRPTGRM_N.VOL_STATIC08_CHK,
                    VOL_STATIC09_CHK = :CQCMRPTGRM_N.VOL_STATIC09_CHK,
                    IMAGE01_CHK = :CQCMRPTGRM_N.IMAGE01_CHK,
                    IMAGE02_CHK = :CQCMRPTGRM_N.IMAGE02_CHK,
                    IMAGE03_CHK = :CQCMRPTGRM_N.IMAGE03_CHK,
                    IMAGE04_CHK = :CQCMRPTGRM_N.IMAGE04_CHK,
                    IMAGE05_CHK = :CQCMRPTGRM_N.IMAGE05_CHK,
                    ATTRIBUTE01 = :CQCMRPTGRM_N.ATTRIBUTE01,
                    ATTRIBUTE02 = :CQCMRPTGRM_N.ATTRIBUTE02,
                    ATTRIBUTE03 = :CQCMRPTGRM_N.ATTRIBUTE03,
                    ATTRIBUTE04 = :CQCMRPTGRM_N.ATTRIBUTE04,
                    ATTRIBUTE05 = :CQCMRPTGRM_N.ATTRIBUTE05,
                    ATTRIBUTE06 = :CQCMRPTGRM_N.ATTRIBUTE06,
                    ATTRIBUTE07 = :CQCMRPTGRM_N.ATTRIBUTE07,
                    ATTRIBUTE08 = :CQCMRPTGRM_N.ATTRIBUTE08,
                    ATTRIBUTE09 = :CQCMRPTGRM_N.ATTRIBUTE09,
                    ATTRIBUTE10 = :CQCMRPTGRM_N.ATTRIBUTE10,
                    REMARKS = :CQCMRPTGRM_N.REMARKS,
                    USE_YN = :CQCMRPTGRM_N.USE_YN,
                    CREATE_USER_ID = :CQCMRPTGRM_N.CREATE_USER_ID,
                    CREATE_TIME = :CQCMRPTGRM_N.CREATE_TIME,
                    UPDATE_USER_ID = :CQCMRPTGRM_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CQCMRPTGRM_N.UPDATE_TIME,
                    SUB_IMAGE01 = :CQCMRPTGRM_N.SUB_IMAGE01,
                    SUB_IMAGE02 = :CQCMRPTGRM_N.SUB_IMAGE02,
                    SUB_IMAGE03 = :CQCMRPTGRM_N.SUB_IMAGE03,
                    SUB_IMAGE04 = :CQCMRPTGRM_N.SUB_IMAGE04,
                    SUB_IMAGE05 = :CQCMRPTGRM_N.SUB_IMAGE05,
                    SUB_IMAGE06 = :CQCMRPTGRM_N.SUB_IMAGE06,
                    RPT_CMF_1 = :CQCMRPTGRM_N.RPT_CMF_1,
                    RPT_CMF_2 = :CQCMRPTGRM_N.RPT_CMF_2,
                    RPT_CMF_3 = :CQCMRPTGRM_N.RPT_CMF_3,
                    RPT_CMF_4 = :CQCMRPTGRM_N.RPT_CMF_4,
                    RPT_CMF_5 = :CQCMRPTGRM_N.RPT_CMF_5,
                    RPT_CMF_6 = :CQCMRPTGRM_N.RPT_CMF_6,
                    RPT_CMF_7 = :CQCMRPTGRM_N.RPT_CMF_7,
                    RPT_CMF_8 = :CQCMRPTGRM_N.RPT_CMF_8,
                    RPT_CMF_9 = :CQCMRPTGRM_N.RPT_CMF_9,
                    RPT_CMF_10 = :CQCMRPTGRM_N.RPT_CMF_10,
                    RPT_CMF_11 = :CQCMRPTGRM_N.RPT_CMF_11,
                    RPT_CMF_12 = :CQCMRPTGRM_N.RPT_CMF_12,
                    RPT_CMF_13 = :CQCMRPTGRM_N.RPT_CMF_13,
                    RPT_CMF_14 = :CQCMRPTGRM_N.RPT_CMF_14,
                    RPT_CMF_15 = :CQCMRPTGRM_N.RPT_CMF_15
                WHERE FACTORY = :CQCMRPTGRM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTGRM_N.REPORT_NO
                    AND LOT_ID = :CQCMRPTGRM_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update CQCMRPTGRM  set ITEM_CODE=:b0,GRADE=:b1,SIZES=:b2,HEAD\
ER_ID=:b3,LINE_NUMBER=:b4,CUST_NO=:b5,CUST_NAME=:b6,REPORT_DATE=:b7,INSP_VAL\
UE=:b8,SHIP_NAME=:b9,WT=:b10,MEAN=:b11,SD=:b12,LP=:b13,ELEC_CONDUCTIVITY=:b1\
4,VOL_STATIC01=:b15,VOL_STATIC02=:b16,VOL_STATIC03=:b17,VOL_STATIC04=:b18,VO\
L_STATIC05=:b19,VOL_STATIC06=:b20,VOL_STATIC07=:b21,VOL_STATIC08=:b22,VOL_ST\
ATIC09=:b23,IMAGE01=:b24,IMAGE02=:b25,IMAGE03=:b26,IMAGE04=:b27,IMAGE05=:b28\
,ANALYZER=:b29,WT_CHK=:b30,MEAN_CHK=:b31,SD_CHK=:b32,LP_CHK=:b33,ELEC_CONDUC\
TIVITY_CHK=:b34,VOL_STATIC01_CHK=:b35,VOL_STATIC02_CHK=:b36,VOL_STATIC03_CHK\
=:b37,VOL_STATIC04_CHK=:b38,VOL_STATIC05_CHK=:b39,VOL_STATIC06_CHK=:b40,VOL_\
STATIC07_CHK=:b41,VOL_STATIC08_CHK=:b42,VOL_STATIC09_CHK=:b43,IMAGE01_CHK=:b\
44,IMAGE02_CHK=:b45,IMAGE03_CHK=:b46,IMAGE04_CHK=:b47,IMAGE05_CHK=:b48,ATTRI\
BUTE01=:b49,ATTRIBUTE02=:b50,ATTRIBUTE03=:b51,ATTRIBUTE04=:b52,ATTRIBUTE05=:\
b53,ATTRIBUTE06=:b54,ATTRIBUTE07=:b55,ATTRIBUTE08=:b56,ATTRIBUTE09=:b57,ATTR\
IBUTE10=:b58,REMARKS=:b59,USE_YN=:b60,CREATE_USER_I");
            sqlstm.stmt = "D=:b61,CREATE_TIME=:b62,UPDATE_USER_ID=:b63,UPDA\
TE_TIME=:b64,SUB_IMAGE01=:b65,SUB_IMAGE02=:b66,SUB_IMAGE03=:b67,SUB_IMAGE04=:\
b68,SUB_IMAGE05=:b69,SUB_IMAGE06=:b70,RPT_CMF_1=:b71,RPT_CMF_2=:b72,RPT_CMF_3\
=:b73,RPT_CMF_4=:b74,RPT_CMF_5=:b75,RPT_CMF_6=:b76,RPT_CMF_7=:b77,RPT_CMF_8=:\
b78,RPT_CMF_9=:b79,RPT_CMF_10=:b80,RPT_CMF_11=:b81,RPT_CMF_12=:b82,RPT_CMF_13\
=:b83,RPT_CMF_14=:b84,RPT_CMF_15=:b85 where ((FACTORY=:b86 and REPORT_NO=:b87\
) and LOT_ID=:b88)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1250;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRM_N.ITEM_CODE);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRM_N.GRADE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRM_N.SIZES);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRM_N.HEADER_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMRPTGRM_N.LINE_NUMBER);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGRM_N.CUST_NO);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGRM_N.CUST_NAME);
            sqlstm.sqhstl[6] = (unsigned int  )101;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGRM_N.REPORT_DATE);
            sqlstm.sqhstl[7] = (unsigned int  )9;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGRM_N.INSP_VALUE);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGRM_N.SHIP_NAME);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGRM_N.WT);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGRM_N.MEAN);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGRM_N.SD);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGRM_N.LP);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGRM_N.ELEC_CONDUCTIVITY);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC01);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC02);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC03);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC04);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC05);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC06);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC07);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC08);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC09);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGRM_N.IMAGE01);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGRM_N.IMAGE02);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGRM_N.IMAGE03);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGRM_N.IMAGE04);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGRM_N.IMAGE05);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGRM_N.ANALYZER);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGRM_N.WT_CHK);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGRM_N.MEAN_CHK);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGRM_N.SD_CHK);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGRM_N.LP_CHK);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGRM_N.ELEC_CONDUCTIVITY_CHK);
            sqlstm.sqhstl[34] = (unsigned int  )6;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC01_CHK);
            sqlstm.sqhstl[35] = (unsigned int  )6;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC02_CHK);
            sqlstm.sqhstl[36] = (unsigned int  )6;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC03_CHK);
            sqlstm.sqhstl[37] = (unsigned int  )6;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC04_CHK);
            sqlstm.sqhstl[38] = (unsigned int  )6;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC05_CHK);
            sqlstm.sqhstl[39] = (unsigned int  )6;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC06_CHK);
            sqlstm.sqhstl[40] = (unsigned int  )6;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC07_CHK);
            sqlstm.sqhstl[41] = (unsigned int  )6;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC08_CHK);
            sqlstm.sqhstl[42] = (unsigned int  )6;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC09_CHK);
            sqlstm.sqhstl[43] = (unsigned int  )6;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTGRM_N.IMAGE01_CHK);
            sqlstm.sqhstl[44] = (unsigned int  )6;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTGRM_N.IMAGE02_CHK);
            sqlstm.sqhstl[45] = (unsigned int  )6;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTGRM_N.IMAGE03_CHK);
            sqlstm.sqhstl[46] = (unsigned int  )6;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTGRM_N.IMAGE04_CHK);
            sqlstm.sqhstl[47] = (unsigned int  )6;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTGRM_N.IMAGE05_CHK);
            sqlstm.sqhstl[48] = (unsigned int  )6;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE01);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE02);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE03);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE04);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE05);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE06);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE07);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE08);
            sqlstm.sqhstl[56] = (unsigned int  )51;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE09);
            sqlstm.sqhstl[57] = (unsigned int  )51;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE10);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTGRM_N.REMARKS);
            sqlstm.sqhstl[59] = (unsigned int  )101;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMRPTGRM_N.USE_YN);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMRPTGRM_N.CREATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMRPTGRM_N.CREATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMRPTGRM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMRPTGRM_N.UPDATE_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE01);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE02);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE03);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE04);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE05);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE06);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_1);
            sqlstm.sqhstl[71] = (unsigned int  )51;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_2);
            sqlstm.sqhstl[72] = (unsigned int  )51;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_3);
            sqlstm.sqhstl[73] = (unsigned int  )51;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_4);
            sqlstm.sqhstl[74] = (unsigned int  )51;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_5);
            sqlstm.sqhstl[75] = (unsigned int  )51;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_6);
            sqlstm.sqhstl[76] = (unsigned int  )51;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_7);
            sqlstm.sqhstl[77] = (unsigned int  )51;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_8);
            sqlstm.sqhstl[78] = (unsigned int  )51;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_9);
            sqlstm.sqhstl[79] = (unsigned int  )51;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_10);
            sqlstm.sqhstl[80] = (unsigned int  )51;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_11);
            sqlstm.sqhstl[81] = (unsigned int  )51;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_12);
            sqlstm.sqhstl[82] = (unsigned int  )51;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_13);
            sqlstm.sqhstl[83] = (unsigned int  )51;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_14);
            sqlstm.sqhstl[84] = (unsigned int  )51;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_15);
            sqlstm.sqhstl[85] = (unsigned int  )51;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(CQCMRPTGRM_N.FACTORY);
            sqlstm.sqhstl[86] = (unsigned int  )11;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(CQCMRPTGRM_N.LOT_ID);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_cqcmrptgrm", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cqcmrptgrm(int sel_type, struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRM_N_TAG CQCMRPTGRM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrm(&CQCMRPTGRM_N, CQCMRPTGRM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CQCMRPTGRM_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    REPORT_NO,
                    LOT_ID,
                    ITEM_CODE,
                    GRADE,
                    SIZES,
                    HEADER_ID,
                    LINE_NUMBER,
                    CUST_NO,
                    CUST_NAME,
                    REPORT_DATE,
                    INSP_VALUE,
                    SHIP_NAME,
                    WT,
                    MEAN,
                    SD,
                    LP,
                    ELEC_CONDUCTIVITY,
                    VOL_STATIC01,
                    VOL_STATIC02,
                    VOL_STATIC03,
                    VOL_STATIC04,
                    VOL_STATIC05,
                    VOL_STATIC06,
                    VOL_STATIC07,
                    VOL_STATIC08,
                    VOL_STATIC09,
                    IMAGE01,
                    IMAGE02,
                    IMAGE03,
                    IMAGE04,
                    IMAGE05,
                    ANALYZER,
                    WT_CHK,
                    MEAN_CHK,
                    SD_CHK,
                    LP_CHK,
                    ELEC_CONDUCTIVITY_CHK,
                    VOL_STATIC01_CHK,
                    VOL_STATIC02_CHK,
                    VOL_STATIC03_CHK,
                    VOL_STATIC04_CHK,
                    VOL_STATIC05_CHK,
                    VOL_STATIC06_CHK,
                    VOL_STATIC07_CHK,
                    VOL_STATIC08_CHK,
                    VOL_STATIC09_CHK,
                    IMAGE01_CHK,
                    IMAGE02_CHK,
                    IMAGE03_CHK,
                    IMAGE04_CHK,
                    IMAGE05_CHK,
                    ATTRIBUTE01,
                    ATTRIBUTE02,
                    ATTRIBUTE03,
                    ATTRIBUTE04,
                    ATTRIBUTE05,
                    ATTRIBUTE06,
                    ATTRIBUTE07,
                    ATTRIBUTE08,
                    ATTRIBUTE09,
                    ATTRIBUTE10,
                    REMARKS,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    SUB_IMAGE01,
                    SUB_IMAGE02,
                    SUB_IMAGE03,
                    SUB_IMAGE04,
                    SUB_IMAGE05,
                    SUB_IMAGE06,
                    RPT_CMF_1,
                    RPT_CMF_2,
                    RPT_CMF_3,
                    RPT_CMF_4,
                    RPT_CMF_5,
                    RPT_CMF_6,
                    RPT_CMF_7,
                    RPT_CMF_8,
                    RPT_CMF_9,
                    RPT_CMF_10,
                    RPT_CMF_11,
                    RPT_CMF_12,
                    RPT_CMF_13,
                    RPT_CMF_14,
                    RPT_CMF_15
                FROM CQCMRPTGRM
                ORDER BY FACTORY ASC,
                    REPORT_NO ASC,
                    LOT_ID ASC; */ 

            /* EXEC SQL OPEN DBU_CQCMRPTGRM_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,REPORT_NO ,LOT_ID ,ITEM_CODE ,GRADE ,SIZES ,H\
EADER_ID ,LINE_NUMBER ,CUST_NO ,CUST_NAME ,REPORT_DATE ,INSP_VALUE ,SHIP_NAM\
E ,WT ,MEAN ,SD ,LP ,ELEC_CONDUCTIVITY ,VOL_STATIC01 ,VOL_STATIC02 ,VOL_STAT\
IC03 ,VOL_STATIC04 ,VOL_STATIC05 ,VOL_STATIC06 ,VOL_STATIC07 ,VOL_STATIC08 ,\
VOL_STATIC09 ,IMAGE01 ,IMAGE02 ,IMAGE03 ,IMAGE04 ,IMAGE05 ,ANALYZER ,WT_CHK \
,MEAN_CHK ,SD_CHK ,LP_CHK ,ELEC_CONDUCTIVITY_CHK ,VOL_STATIC01_CHK ,VOL_STAT\
IC02_CHK ,VOL_STATIC03_CHK ,VOL_STATIC04_CHK ,VOL_STATIC05_CHK ,VOL_STATIC06\
_CHK ,VOL_STATIC07_CHK ,VOL_STATIC08_CHK ,VOL_STATIC09_CHK ,IMAGE01_CHK ,IMA\
GE02_CHK ,IMAGE03_CHK ,IMAGE04_CHK ,IMAGE05_CHK ,ATTRIBUTE01 ,ATTRIBUTE02 ,A\
TTRIBUTE03 ,ATTRIBUTE04 ,ATTRIBUTE05 ,ATTRIBUTE06 ,ATTRIBUTE07 ,ATTRIBUTE08 \
,ATTRIBUTE09 ,ATTRIBUTE10 ,REMARKS ,USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPD\
ATE_USER_ID ,UPDATE_TIME ,SUB_IMAGE01 ,SUB_IMAGE02 ,SUB_IMAGE03 ,SUB_IMAGE04\
 ,SUB_IMAGE05 ,SUB_IMAGE06 ,RPT_CMF_1 ,RPT_CMF_2 ,RPT_CMF_3 ,RPT_CMF_4 ,RPT_\
CMF_5 ,RPT_CMF_6 ,RPT_CMF_7 ,RPT_CMF_8 ,RPT_CMF_9 ,");
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1621;
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

    DB_stop_query_timer("DBU_open_cqcmrptgrm", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cqcmrptgrm(int sel_type, struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRM_N_TAG CQCMRPTGRM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CQCMRPTGRM_CUR_1 INTO
                :CQCMRPTGRM_N.FACTORY,
                :CQCMRPTGRM_N.REPORT_NO,
                :CQCMRPTGRM_N.LOT_ID,
                :CQCMRPTGRM_N.ITEM_CODE,
                :CQCMRPTGRM_N.GRADE,
                :CQCMRPTGRM_N.SIZES,
                :CQCMRPTGRM_N.HEADER_ID,
                :CQCMRPTGRM_N.LINE_NUMBER,
                :CQCMRPTGRM_N.CUST_NO,
                :CQCMRPTGRM_N.CUST_NAME,
                :CQCMRPTGRM_N.REPORT_DATE,
                :CQCMRPTGRM_N.INSP_VALUE,
                :CQCMRPTGRM_N.SHIP_NAME,
                :CQCMRPTGRM_N.WT,
                :CQCMRPTGRM_N.MEAN,
                :CQCMRPTGRM_N.SD,
                :CQCMRPTGRM_N.LP,
                :CQCMRPTGRM_N.ELEC_CONDUCTIVITY,
                :CQCMRPTGRM_N.VOL_STATIC01,
                :CQCMRPTGRM_N.VOL_STATIC02,
                :CQCMRPTGRM_N.VOL_STATIC03,
                :CQCMRPTGRM_N.VOL_STATIC04,
                :CQCMRPTGRM_N.VOL_STATIC05,
                :CQCMRPTGRM_N.VOL_STATIC06,
                :CQCMRPTGRM_N.VOL_STATIC07,
                :CQCMRPTGRM_N.VOL_STATIC08,
                :CQCMRPTGRM_N.VOL_STATIC09,
                :CQCMRPTGRM_N.IMAGE01,
                :CQCMRPTGRM_N.IMAGE02,
                :CQCMRPTGRM_N.IMAGE03,
                :CQCMRPTGRM_N.IMAGE04,
                :CQCMRPTGRM_N.IMAGE05,
                :CQCMRPTGRM_N.ANALYZER,
                :CQCMRPTGRM_N.WT_CHK,
                :CQCMRPTGRM_N.MEAN_CHK,
                :CQCMRPTGRM_N.SD_CHK,
                :CQCMRPTGRM_N.LP_CHK,
                :CQCMRPTGRM_N.ELEC_CONDUCTIVITY_CHK,
                :CQCMRPTGRM_N.VOL_STATIC01_CHK,
                :CQCMRPTGRM_N.VOL_STATIC02_CHK,
                :CQCMRPTGRM_N.VOL_STATIC03_CHK,
                :CQCMRPTGRM_N.VOL_STATIC04_CHK,
                :CQCMRPTGRM_N.VOL_STATIC05_CHK,
                :CQCMRPTGRM_N.VOL_STATIC06_CHK,
                :CQCMRPTGRM_N.VOL_STATIC07_CHK,
                :CQCMRPTGRM_N.VOL_STATIC08_CHK,
                :CQCMRPTGRM_N.VOL_STATIC09_CHK,
                :CQCMRPTGRM_N.IMAGE01_CHK,
                :CQCMRPTGRM_N.IMAGE02_CHK,
                :CQCMRPTGRM_N.IMAGE03_CHK,
                :CQCMRPTGRM_N.IMAGE04_CHK,
                :CQCMRPTGRM_N.IMAGE05_CHK,
                :CQCMRPTGRM_N.ATTRIBUTE01,
                :CQCMRPTGRM_N.ATTRIBUTE02,
                :CQCMRPTGRM_N.ATTRIBUTE03,
                :CQCMRPTGRM_N.ATTRIBUTE04,
                :CQCMRPTGRM_N.ATTRIBUTE05,
                :CQCMRPTGRM_N.ATTRIBUTE06,
                :CQCMRPTGRM_N.ATTRIBUTE07,
                :CQCMRPTGRM_N.ATTRIBUTE08,
                :CQCMRPTGRM_N.ATTRIBUTE09,
                :CQCMRPTGRM_N.ATTRIBUTE10,
                :CQCMRPTGRM_N.REMARKS,
                :CQCMRPTGRM_N.USE_YN,
                :CQCMRPTGRM_N.CREATE_USER_ID,
                :CQCMRPTGRM_N.CREATE_TIME,
                :CQCMRPTGRM_N.UPDATE_USER_ID,
                :CQCMRPTGRM_N.UPDATE_TIME,
                :CQCMRPTGRM_N.SUB_IMAGE01,
                :CQCMRPTGRM_N.SUB_IMAGE02,
                :CQCMRPTGRM_N.SUB_IMAGE03,
                :CQCMRPTGRM_N.SUB_IMAGE04,
                :CQCMRPTGRM_N.SUB_IMAGE05,
                :CQCMRPTGRM_N.SUB_IMAGE06,
                :CQCMRPTGRM_N.RPT_CMF_1,
                :CQCMRPTGRM_N.RPT_CMF_2,
                :CQCMRPTGRM_N.RPT_CMF_3,
                :CQCMRPTGRM_N.RPT_CMF_4,
                :CQCMRPTGRM_N.RPT_CMF_5,
                :CQCMRPTGRM_N.RPT_CMF_6,
                :CQCMRPTGRM_N.RPT_CMF_7,
                :CQCMRPTGRM_N.RPT_CMF_8,
                :CQCMRPTGRM_N.RPT_CMF_9,
                :CQCMRPTGRM_N.RPT_CMF_10,
                :CQCMRPTGRM_N.RPT_CMF_11,
                :CQCMRPTGRM_N.RPT_CMF_12,
                :CQCMRPTGRM_N.RPT_CMF_13,
                :CQCMRPTGRM_N.RPT_CMF_14,
                :CQCMRPTGRM_N.RPT_CMF_15; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1636;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRM_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRM_N.LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRM_N.ITEM_CODE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGRM_N.GRADE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGRM_N.SIZES);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGRM_N.HEADER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMRPTGRM_N.LINE_NUMBER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGRM_N.CUST_NO);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGRM_N.CUST_NAME);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGRM_N.REPORT_DATE);
            sqlstm.sqhstl[10] = (unsigned int  )9;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGRM_N.INSP_VALUE);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGRM_N.SHIP_NAME);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGRM_N.WT);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGRM_N.MEAN);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGRM_N.SD);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGRM_N.LP);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGRM_N.ELEC_CONDUCTIVITY);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC01);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC02);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC03);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC04);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC05);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC06);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC07);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC08);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC09);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGRM_N.IMAGE01);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGRM_N.IMAGE02);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGRM_N.IMAGE03);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGRM_N.IMAGE04);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGRM_N.IMAGE05);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGRM_N.ANALYZER);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGRM_N.WT_CHK);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGRM_N.MEAN_CHK);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGRM_N.SD_CHK);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGRM_N.LP_CHK);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGRM_N.ELEC_CONDUCTIVITY_CHK);
            sqlstm.sqhstl[37] = (unsigned int  )6;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC01_CHK);
            sqlstm.sqhstl[38] = (unsigned int  )6;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC02_CHK);
            sqlstm.sqhstl[39] = (unsigned int  )6;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC03_CHK);
            sqlstm.sqhstl[40] = (unsigned int  )6;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC04_CHK);
            sqlstm.sqhstl[41] = (unsigned int  )6;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC05_CHK);
            sqlstm.sqhstl[42] = (unsigned int  )6;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC06_CHK);
            sqlstm.sqhstl[43] = (unsigned int  )6;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC07_CHK);
            sqlstm.sqhstl[44] = (unsigned int  )6;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC08_CHK);
            sqlstm.sqhstl[45] = (unsigned int  )6;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTGRM_N.VOL_STATIC09_CHK);
            sqlstm.sqhstl[46] = (unsigned int  )6;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTGRM_N.IMAGE01_CHK);
            sqlstm.sqhstl[47] = (unsigned int  )6;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTGRM_N.IMAGE02_CHK);
            sqlstm.sqhstl[48] = (unsigned int  )6;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTGRM_N.IMAGE03_CHK);
            sqlstm.sqhstl[49] = (unsigned int  )6;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTGRM_N.IMAGE04_CHK);
            sqlstm.sqhstl[50] = (unsigned int  )6;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTGRM_N.IMAGE05_CHK);
            sqlstm.sqhstl[51] = (unsigned int  )6;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE01);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE02);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE03);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE04);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE05);
            sqlstm.sqhstl[56] = (unsigned int  )51;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE06);
            sqlstm.sqhstl[57] = (unsigned int  )51;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE07);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE08);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE09);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMRPTGRM_N.ATTRIBUTE10);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMRPTGRM_N.REMARKS);
            sqlstm.sqhstl[62] = (unsigned int  )101;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMRPTGRM_N.USE_YN);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMRPTGRM_N.CREATE_USER_ID);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMRPTGRM_N.CREATE_TIME);
            sqlstm.sqhstl[65] = (unsigned int  )15;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMRPTGRM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMRPTGRM_N.UPDATE_TIME);
            sqlstm.sqhstl[67] = (unsigned int  )15;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE01);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE02);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE03);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE04);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE05);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(CQCMRPTGRM_N.SUB_IMAGE06);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_1);
            sqlstm.sqhstl[74] = (unsigned int  )51;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_2);
            sqlstm.sqhstl[75] = (unsigned int  )51;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_3);
            sqlstm.sqhstl[76] = (unsigned int  )51;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_4);
            sqlstm.sqhstl[77] = (unsigned int  )51;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_5);
            sqlstm.sqhstl[78] = (unsigned int  )51;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_6);
            sqlstm.sqhstl[79] = (unsigned int  )51;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_7);
            sqlstm.sqhstl[80] = (unsigned int  )51;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_8);
            sqlstm.sqhstl[81] = (unsigned int  )51;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_9);
            sqlstm.sqhstl[82] = (unsigned int  )51;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_10);
            sqlstm.sqhstl[83] = (unsigned int  )51;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_11);
            sqlstm.sqhstl[84] = (unsigned int  )51;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_12);
            sqlstm.sqhstl[85] = (unsigned int  )51;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_13);
            sqlstm.sqhstl[86] = (unsigned int  )51;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_14);
            sqlstm.sqhstl[87] = (unsigned int  )51;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(CQCMRPTGRM_N.RPT_CMF_15);
            sqlstm.sqhstl[88] = (unsigned int  )51;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
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
        DBU_del_null_cqcmrptgrm(&CQCMRPTGRM_N, CQCMRPTGRM);
    }

    DB_stop_query_timer("DBU_fetch_cqcmrptgrm", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cqcmrptgrm(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CQCMRPTGRM_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2007;
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

    DB_stop_query_timer("DBU_close_cqcmrptgrm", sel_type);
}


/* Initialize Function */
void DBU_init_cqcmrptgrm(struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    /* memset by Space */
    memset(CQCMRPTGRM, ' ', sizeof(struct CQCMRPTGRM_TAG));
    
    CQCMRPTGRM->LINE_NUMBER = 0;
}


/* Add Null Function */
void DBU_add_null_cqcmrptgrm(struct CQCMRPTGRM_N_TAG *CQCMRPTGRM_N, struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    /* memset by NULL */
    memset(CQCMRPTGRM_N, '\0', sizeof(struct CQCMRPTGRM_N_TAG));
    
    MEMCPY_AN(CQCMRPTGRM_N->FACTORY, CQCMRPTGRM->FACTORY, sizeof(CQCMRPTGRM->FACTORY));
    MEMCPY_AN(CQCMRPTGRM_N->REPORT_NO, CQCMRPTGRM->REPORT_NO, sizeof(CQCMRPTGRM->REPORT_NO));
    MEMCPY_AN(CQCMRPTGRM_N->LOT_ID, CQCMRPTGRM->LOT_ID, sizeof(CQCMRPTGRM->LOT_ID));
    MEMCPY_AN(CQCMRPTGRM_N->ITEM_CODE, CQCMRPTGRM->ITEM_CODE, sizeof(CQCMRPTGRM->ITEM_CODE));
    MEMCPY_AN(CQCMRPTGRM_N->GRADE, CQCMRPTGRM->GRADE, sizeof(CQCMRPTGRM->GRADE));
    MEMCPY_AN(CQCMRPTGRM_N->SIZES, CQCMRPTGRM->SIZES, sizeof(CQCMRPTGRM->SIZES));
    MEMCPY_AN(CQCMRPTGRM_N->HEADER_ID, CQCMRPTGRM->HEADER_ID, sizeof(CQCMRPTGRM->HEADER_ID));
    CQCMRPTGRM_N->LINE_NUMBER = CQCMRPTGRM->LINE_NUMBER;
    MEMCPY_AN(CQCMRPTGRM_N->CUST_NO, CQCMRPTGRM->CUST_NO, sizeof(CQCMRPTGRM->CUST_NO));
    MEMCPY_AN(CQCMRPTGRM_N->CUST_NAME, CQCMRPTGRM->CUST_NAME, sizeof(CQCMRPTGRM->CUST_NAME));
    MEMCPY_AN(CQCMRPTGRM_N->REPORT_DATE, CQCMRPTGRM->REPORT_DATE, sizeof(CQCMRPTGRM->REPORT_DATE));
    MEMCPY_AN(CQCMRPTGRM_N->INSP_VALUE, CQCMRPTGRM->INSP_VALUE, sizeof(CQCMRPTGRM->INSP_VALUE));
    MEMCPY_AN(CQCMRPTGRM_N->SHIP_NAME, CQCMRPTGRM->SHIP_NAME, sizeof(CQCMRPTGRM->SHIP_NAME));
    MEMCPY_AN(CQCMRPTGRM_N->WT, CQCMRPTGRM->WT, sizeof(CQCMRPTGRM->WT));
    MEMCPY_AN(CQCMRPTGRM_N->MEAN, CQCMRPTGRM->MEAN, sizeof(CQCMRPTGRM->MEAN));
    MEMCPY_AN(CQCMRPTGRM_N->SD, CQCMRPTGRM->SD, sizeof(CQCMRPTGRM->SD));
    MEMCPY_AN(CQCMRPTGRM_N->LP, CQCMRPTGRM->LP, sizeof(CQCMRPTGRM->LP));
    MEMCPY_AN(CQCMRPTGRM_N->ELEC_CONDUCTIVITY, CQCMRPTGRM->ELEC_CONDUCTIVITY, sizeof(CQCMRPTGRM->ELEC_CONDUCTIVITY));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC01, CQCMRPTGRM->VOL_STATIC01, sizeof(CQCMRPTGRM->VOL_STATIC01));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC02, CQCMRPTGRM->VOL_STATIC02, sizeof(CQCMRPTGRM->VOL_STATIC02));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC03, CQCMRPTGRM->VOL_STATIC03, sizeof(CQCMRPTGRM->VOL_STATIC03));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC04, CQCMRPTGRM->VOL_STATIC04, sizeof(CQCMRPTGRM->VOL_STATIC04));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC05, CQCMRPTGRM->VOL_STATIC05, sizeof(CQCMRPTGRM->VOL_STATIC05));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC06, CQCMRPTGRM->VOL_STATIC06, sizeof(CQCMRPTGRM->VOL_STATIC06));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC07, CQCMRPTGRM->VOL_STATIC07, sizeof(CQCMRPTGRM->VOL_STATIC07));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC08, CQCMRPTGRM->VOL_STATIC08, sizeof(CQCMRPTGRM->VOL_STATIC08));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC09, CQCMRPTGRM->VOL_STATIC09, sizeof(CQCMRPTGRM->VOL_STATIC09));
    MEMCPY_AN(CQCMRPTGRM_N->IMAGE01, CQCMRPTGRM->IMAGE01, sizeof(CQCMRPTGRM->IMAGE01));
    MEMCPY_AN(CQCMRPTGRM_N->IMAGE02, CQCMRPTGRM->IMAGE02, sizeof(CQCMRPTGRM->IMAGE02));
    MEMCPY_AN(CQCMRPTGRM_N->IMAGE03, CQCMRPTGRM->IMAGE03, sizeof(CQCMRPTGRM->IMAGE03));
    MEMCPY_AN(CQCMRPTGRM_N->IMAGE04, CQCMRPTGRM->IMAGE04, sizeof(CQCMRPTGRM->IMAGE04));
    MEMCPY_AN(CQCMRPTGRM_N->IMAGE05, CQCMRPTGRM->IMAGE05, sizeof(CQCMRPTGRM->IMAGE05));
    MEMCPY_AN(CQCMRPTGRM_N->ANALYZER, CQCMRPTGRM->ANALYZER, sizeof(CQCMRPTGRM->ANALYZER));
    MEMCPY_AN(CQCMRPTGRM_N->WT_CHK, CQCMRPTGRM->WT_CHK, sizeof(CQCMRPTGRM->WT_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->MEAN_CHK, CQCMRPTGRM->MEAN_CHK, sizeof(CQCMRPTGRM->MEAN_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->SD_CHK, CQCMRPTGRM->SD_CHK, sizeof(CQCMRPTGRM->SD_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->LP_CHK, CQCMRPTGRM->LP_CHK, sizeof(CQCMRPTGRM->LP_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->ELEC_CONDUCTIVITY_CHK, CQCMRPTGRM->ELEC_CONDUCTIVITY_CHK, sizeof(CQCMRPTGRM->ELEC_CONDUCTIVITY_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC01_CHK, CQCMRPTGRM->VOL_STATIC01_CHK, sizeof(CQCMRPTGRM->VOL_STATIC01_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC02_CHK, CQCMRPTGRM->VOL_STATIC02_CHK, sizeof(CQCMRPTGRM->VOL_STATIC02_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC03_CHK, CQCMRPTGRM->VOL_STATIC03_CHK, sizeof(CQCMRPTGRM->VOL_STATIC03_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC04_CHK, CQCMRPTGRM->VOL_STATIC04_CHK, sizeof(CQCMRPTGRM->VOL_STATIC04_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC05_CHK, CQCMRPTGRM->VOL_STATIC05_CHK, sizeof(CQCMRPTGRM->VOL_STATIC05_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC06_CHK, CQCMRPTGRM->VOL_STATIC06_CHK, sizeof(CQCMRPTGRM->VOL_STATIC06_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC07_CHK, CQCMRPTGRM->VOL_STATIC07_CHK, sizeof(CQCMRPTGRM->VOL_STATIC07_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC08_CHK, CQCMRPTGRM->VOL_STATIC08_CHK, sizeof(CQCMRPTGRM->VOL_STATIC08_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->VOL_STATIC09_CHK, CQCMRPTGRM->VOL_STATIC09_CHK, sizeof(CQCMRPTGRM->VOL_STATIC09_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->IMAGE01_CHK, CQCMRPTGRM->IMAGE01_CHK, sizeof(CQCMRPTGRM->IMAGE01_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->IMAGE02_CHK, CQCMRPTGRM->IMAGE02_CHK, sizeof(CQCMRPTGRM->IMAGE02_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->IMAGE03_CHK, CQCMRPTGRM->IMAGE03_CHK, sizeof(CQCMRPTGRM->IMAGE03_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->IMAGE04_CHK, CQCMRPTGRM->IMAGE04_CHK, sizeof(CQCMRPTGRM->IMAGE04_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->IMAGE05_CHK, CQCMRPTGRM->IMAGE05_CHK, sizeof(CQCMRPTGRM->IMAGE05_CHK));
    MEMCPY_AN(CQCMRPTGRM_N->ATTRIBUTE01, CQCMRPTGRM->ATTRIBUTE01, sizeof(CQCMRPTGRM->ATTRIBUTE01));
    MEMCPY_AN(CQCMRPTGRM_N->ATTRIBUTE02, CQCMRPTGRM->ATTRIBUTE02, sizeof(CQCMRPTGRM->ATTRIBUTE02));
    MEMCPY_AN(CQCMRPTGRM_N->ATTRIBUTE03, CQCMRPTGRM->ATTRIBUTE03, sizeof(CQCMRPTGRM->ATTRIBUTE03));
    MEMCPY_AN(CQCMRPTGRM_N->ATTRIBUTE04, CQCMRPTGRM->ATTRIBUTE04, sizeof(CQCMRPTGRM->ATTRIBUTE04));
    MEMCPY_AN(CQCMRPTGRM_N->ATTRIBUTE05, CQCMRPTGRM->ATTRIBUTE05, sizeof(CQCMRPTGRM->ATTRIBUTE05));
    MEMCPY_AN(CQCMRPTGRM_N->ATTRIBUTE06, CQCMRPTGRM->ATTRIBUTE06, sizeof(CQCMRPTGRM->ATTRIBUTE06));
    MEMCPY_AN(CQCMRPTGRM_N->ATTRIBUTE07, CQCMRPTGRM->ATTRIBUTE07, sizeof(CQCMRPTGRM->ATTRIBUTE07));
    MEMCPY_AN(CQCMRPTGRM_N->ATTRIBUTE08, CQCMRPTGRM->ATTRIBUTE08, sizeof(CQCMRPTGRM->ATTRIBUTE08));
    MEMCPY_AN(CQCMRPTGRM_N->ATTRIBUTE09, CQCMRPTGRM->ATTRIBUTE09, sizeof(CQCMRPTGRM->ATTRIBUTE09));
    MEMCPY_AN(CQCMRPTGRM_N->ATTRIBUTE10, CQCMRPTGRM->ATTRIBUTE10, sizeof(CQCMRPTGRM->ATTRIBUTE10));
    MEMCPY_AN(CQCMRPTGRM_N->REMARKS, CQCMRPTGRM->REMARKS, sizeof(CQCMRPTGRM->REMARKS));
    CQCMRPTGRM_N->USE_YN[0] = CQCMRPTGRM->USE_YN;
    MEMCPY_AN(CQCMRPTGRM_N->CREATE_USER_ID, CQCMRPTGRM->CREATE_USER_ID, sizeof(CQCMRPTGRM->CREATE_USER_ID));
    MEMCPY_AN(CQCMRPTGRM_N->CREATE_TIME, CQCMRPTGRM->CREATE_TIME, sizeof(CQCMRPTGRM->CREATE_TIME));
    MEMCPY_AN(CQCMRPTGRM_N->UPDATE_USER_ID, CQCMRPTGRM->UPDATE_USER_ID, sizeof(CQCMRPTGRM->UPDATE_USER_ID));
    MEMCPY_AN(CQCMRPTGRM_N->UPDATE_TIME, CQCMRPTGRM->UPDATE_TIME, sizeof(CQCMRPTGRM->UPDATE_TIME));
    MEMCPY_AN(CQCMRPTGRM_N->SUB_IMAGE01, CQCMRPTGRM->SUB_IMAGE01, sizeof(CQCMRPTGRM->SUB_IMAGE01));
    MEMCPY_AN(CQCMRPTGRM_N->SUB_IMAGE02, CQCMRPTGRM->SUB_IMAGE02, sizeof(CQCMRPTGRM->SUB_IMAGE02));
    MEMCPY_AN(CQCMRPTGRM_N->SUB_IMAGE03, CQCMRPTGRM->SUB_IMAGE03, sizeof(CQCMRPTGRM->SUB_IMAGE03));
    MEMCPY_AN(CQCMRPTGRM_N->SUB_IMAGE04, CQCMRPTGRM->SUB_IMAGE04, sizeof(CQCMRPTGRM->SUB_IMAGE04));
    MEMCPY_AN(CQCMRPTGRM_N->SUB_IMAGE05, CQCMRPTGRM->SUB_IMAGE05, sizeof(CQCMRPTGRM->SUB_IMAGE05));
    MEMCPY_AN(CQCMRPTGRM_N->SUB_IMAGE06, CQCMRPTGRM->SUB_IMAGE06, sizeof(CQCMRPTGRM->SUB_IMAGE06));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_1, CQCMRPTGRM->RPT_CMF_1, sizeof(CQCMRPTGRM->RPT_CMF_1));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_2, CQCMRPTGRM->RPT_CMF_2, sizeof(CQCMRPTGRM->RPT_CMF_2));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_3, CQCMRPTGRM->RPT_CMF_3, sizeof(CQCMRPTGRM->RPT_CMF_3));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_4, CQCMRPTGRM->RPT_CMF_4, sizeof(CQCMRPTGRM->RPT_CMF_4));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_5, CQCMRPTGRM->RPT_CMF_5, sizeof(CQCMRPTGRM->RPT_CMF_5));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_6, CQCMRPTGRM->RPT_CMF_6, sizeof(CQCMRPTGRM->RPT_CMF_6));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_7, CQCMRPTGRM->RPT_CMF_7, sizeof(CQCMRPTGRM->RPT_CMF_7));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_8, CQCMRPTGRM->RPT_CMF_8, sizeof(CQCMRPTGRM->RPT_CMF_8));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_9, CQCMRPTGRM->RPT_CMF_9, sizeof(CQCMRPTGRM->RPT_CMF_9));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_10, CQCMRPTGRM->RPT_CMF_10, sizeof(CQCMRPTGRM->RPT_CMF_10));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_11, CQCMRPTGRM->RPT_CMF_11, sizeof(CQCMRPTGRM->RPT_CMF_11));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_12, CQCMRPTGRM->RPT_CMF_12, sizeof(CQCMRPTGRM->RPT_CMF_12));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_13, CQCMRPTGRM->RPT_CMF_13, sizeof(CQCMRPTGRM->RPT_CMF_13));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_14, CQCMRPTGRM->RPT_CMF_14, sizeof(CQCMRPTGRM->RPT_CMF_14));
    MEMCPY_AN(CQCMRPTGRM_N->RPT_CMF_15, CQCMRPTGRM->RPT_CMF_15, sizeof(CQCMRPTGRM->RPT_CMF_15));
}


/* Del Null Function */
void DBU_del_null_cqcmrptgrm(struct CQCMRPTGRM_N_TAG *CQCMRPTGRM_N, struct CQCMRPTGRM_TAG *CQCMRPTGRM)
{
    MEMCPY_DN(CQCMRPTGRM->FACTORY, CQCMRPTGRM_N->FACTORY, sizeof(CQCMRPTGRM->FACTORY));
    MEMCPY_DN(CQCMRPTGRM->REPORT_NO, CQCMRPTGRM_N->REPORT_NO, sizeof(CQCMRPTGRM->REPORT_NO));
    MEMCPY_DN(CQCMRPTGRM->LOT_ID, CQCMRPTGRM_N->LOT_ID, sizeof(CQCMRPTGRM->LOT_ID));
    MEMCPY_DN(CQCMRPTGRM->ITEM_CODE, CQCMRPTGRM_N->ITEM_CODE, sizeof(CQCMRPTGRM->ITEM_CODE));
    MEMCPY_DN(CQCMRPTGRM->GRADE, CQCMRPTGRM_N->GRADE, sizeof(CQCMRPTGRM->GRADE));
    MEMCPY_DN(CQCMRPTGRM->SIZES, CQCMRPTGRM_N->SIZES, sizeof(CQCMRPTGRM->SIZES));
    MEMCPY_DN(CQCMRPTGRM->HEADER_ID, CQCMRPTGRM_N->HEADER_ID, sizeof(CQCMRPTGRM->HEADER_ID));
    CQCMRPTGRM->LINE_NUMBER = CQCMRPTGRM_N->LINE_NUMBER;
    MEMCPY_DN(CQCMRPTGRM->CUST_NO, CQCMRPTGRM_N->CUST_NO, sizeof(CQCMRPTGRM->CUST_NO));
    MEMCPY_DN(CQCMRPTGRM->CUST_NAME, CQCMRPTGRM_N->CUST_NAME, sizeof(CQCMRPTGRM->CUST_NAME));
    MEMCPY_DN(CQCMRPTGRM->REPORT_DATE, CQCMRPTGRM_N->REPORT_DATE, sizeof(CQCMRPTGRM->REPORT_DATE));
    MEMCPY_DN(CQCMRPTGRM->INSP_VALUE, CQCMRPTGRM_N->INSP_VALUE, sizeof(CQCMRPTGRM->INSP_VALUE));
    MEMCPY_DN(CQCMRPTGRM->SHIP_NAME, CQCMRPTGRM_N->SHIP_NAME, sizeof(CQCMRPTGRM->SHIP_NAME));
    MEMCPY_DN(CQCMRPTGRM->WT, CQCMRPTGRM_N->WT, sizeof(CQCMRPTGRM->WT));
    MEMCPY_DN(CQCMRPTGRM->MEAN, CQCMRPTGRM_N->MEAN, sizeof(CQCMRPTGRM->MEAN));
    MEMCPY_DN(CQCMRPTGRM->SD, CQCMRPTGRM_N->SD, sizeof(CQCMRPTGRM->SD));
    MEMCPY_DN(CQCMRPTGRM->LP, CQCMRPTGRM_N->LP, sizeof(CQCMRPTGRM->LP));
    MEMCPY_DN(CQCMRPTGRM->ELEC_CONDUCTIVITY, CQCMRPTGRM_N->ELEC_CONDUCTIVITY, sizeof(CQCMRPTGRM->ELEC_CONDUCTIVITY));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC01, CQCMRPTGRM_N->VOL_STATIC01, sizeof(CQCMRPTGRM->VOL_STATIC01));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC02, CQCMRPTGRM_N->VOL_STATIC02, sizeof(CQCMRPTGRM->VOL_STATIC02));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC03, CQCMRPTGRM_N->VOL_STATIC03, sizeof(CQCMRPTGRM->VOL_STATIC03));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC04, CQCMRPTGRM_N->VOL_STATIC04, sizeof(CQCMRPTGRM->VOL_STATIC04));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC05, CQCMRPTGRM_N->VOL_STATIC05, sizeof(CQCMRPTGRM->VOL_STATIC05));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC06, CQCMRPTGRM_N->VOL_STATIC06, sizeof(CQCMRPTGRM->VOL_STATIC06));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC07, CQCMRPTGRM_N->VOL_STATIC07, sizeof(CQCMRPTGRM->VOL_STATIC07));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC08, CQCMRPTGRM_N->VOL_STATIC08, sizeof(CQCMRPTGRM->VOL_STATIC08));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC09, CQCMRPTGRM_N->VOL_STATIC09, sizeof(CQCMRPTGRM->VOL_STATIC09));
    MEMCPY_DN(CQCMRPTGRM->IMAGE01, CQCMRPTGRM_N->IMAGE01, sizeof(CQCMRPTGRM->IMAGE01));
    MEMCPY_DN(CQCMRPTGRM->IMAGE02, CQCMRPTGRM_N->IMAGE02, sizeof(CQCMRPTGRM->IMAGE02));
    MEMCPY_DN(CQCMRPTGRM->IMAGE03, CQCMRPTGRM_N->IMAGE03, sizeof(CQCMRPTGRM->IMAGE03));
    MEMCPY_DN(CQCMRPTGRM->IMAGE04, CQCMRPTGRM_N->IMAGE04, sizeof(CQCMRPTGRM->IMAGE04));
    MEMCPY_DN(CQCMRPTGRM->IMAGE05, CQCMRPTGRM_N->IMAGE05, sizeof(CQCMRPTGRM->IMAGE05));
    MEMCPY_DN(CQCMRPTGRM->ANALYZER, CQCMRPTGRM_N->ANALYZER, sizeof(CQCMRPTGRM->ANALYZER));
    MEMCPY_DN(CQCMRPTGRM->WT_CHK, CQCMRPTGRM_N->WT_CHK, sizeof(CQCMRPTGRM->WT_CHK));
    MEMCPY_DN(CQCMRPTGRM->MEAN_CHK, CQCMRPTGRM_N->MEAN_CHK, sizeof(CQCMRPTGRM->MEAN_CHK));
    MEMCPY_DN(CQCMRPTGRM->SD_CHK, CQCMRPTGRM_N->SD_CHK, sizeof(CQCMRPTGRM->SD_CHK));
    MEMCPY_DN(CQCMRPTGRM->LP_CHK, CQCMRPTGRM_N->LP_CHK, sizeof(CQCMRPTGRM->LP_CHK));
    MEMCPY_DN(CQCMRPTGRM->ELEC_CONDUCTIVITY_CHK, CQCMRPTGRM_N->ELEC_CONDUCTIVITY_CHK, sizeof(CQCMRPTGRM->ELEC_CONDUCTIVITY_CHK));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC01_CHK, CQCMRPTGRM_N->VOL_STATIC01_CHK, sizeof(CQCMRPTGRM->VOL_STATIC01_CHK));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC02_CHK, CQCMRPTGRM_N->VOL_STATIC02_CHK, sizeof(CQCMRPTGRM->VOL_STATIC02_CHK));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC03_CHK, CQCMRPTGRM_N->VOL_STATIC03_CHK, sizeof(CQCMRPTGRM->VOL_STATIC03_CHK));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC04_CHK, CQCMRPTGRM_N->VOL_STATIC04_CHK, sizeof(CQCMRPTGRM->VOL_STATIC04_CHK));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC05_CHK, CQCMRPTGRM_N->VOL_STATIC05_CHK, sizeof(CQCMRPTGRM->VOL_STATIC05_CHK));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC06_CHK, CQCMRPTGRM_N->VOL_STATIC06_CHK, sizeof(CQCMRPTGRM->VOL_STATIC06_CHK));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC07_CHK, CQCMRPTGRM_N->VOL_STATIC07_CHK, sizeof(CQCMRPTGRM->VOL_STATIC07_CHK));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC08_CHK, CQCMRPTGRM_N->VOL_STATIC08_CHK, sizeof(CQCMRPTGRM->VOL_STATIC08_CHK));
    MEMCPY_DN(CQCMRPTGRM->VOL_STATIC09_CHK, CQCMRPTGRM_N->VOL_STATIC09_CHK, sizeof(CQCMRPTGRM->VOL_STATIC09_CHK));
    MEMCPY_DN(CQCMRPTGRM->IMAGE01_CHK, CQCMRPTGRM_N->IMAGE01_CHK, sizeof(CQCMRPTGRM->IMAGE01_CHK));
    MEMCPY_DN(CQCMRPTGRM->IMAGE02_CHK, CQCMRPTGRM_N->IMAGE02_CHK, sizeof(CQCMRPTGRM->IMAGE02_CHK));
    MEMCPY_DN(CQCMRPTGRM->IMAGE03_CHK, CQCMRPTGRM_N->IMAGE03_CHK, sizeof(CQCMRPTGRM->IMAGE03_CHK));
    MEMCPY_DN(CQCMRPTGRM->IMAGE04_CHK, CQCMRPTGRM_N->IMAGE04_CHK, sizeof(CQCMRPTGRM->IMAGE04_CHK));
    MEMCPY_DN(CQCMRPTGRM->IMAGE05_CHK, CQCMRPTGRM_N->IMAGE05_CHK, sizeof(CQCMRPTGRM->IMAGE05_CHK));
    MEMCPY_DN(CQCMRPTGRM->ATTRIBUTE01, CQCMRPTGRM_N->ATTRIBUTE01, sizeof(CQCMRPTGRM->ATTRIBUTE01));
    MEMCPY_DN(CQCMRPTGRM->ATTRIBUTE02, CQCMRPTGRM_N->ATTRIBUTE02, sizeof(CQCMRPTGRM->ATTRIBUTE02));
    MEMCPY_DN(CQCMRPTGRM->ATTRIBUTE03, CQCMRPTGRM_N->ATTRIBUTE03, sizeof(CQCMRPTGRM->ATTRIBUTE03));
    MEMCPY_DN(CQCMRPTGRM->ATTRIBUTE04, CQCMRPTGRM_N->ATTRIBUTE04, sizeof(CQCMRPTGRM->ATTRIBUTE04));
    MEMCPY_DN(CQCMRPTGRM->ATTRIBUTE05, CQCMRPTGRM_N->ATTRIBUTE05, sizeof(CQCMRPTGRM->ATTRIBUTE05));
    MEMCPY_DN(CQCMRPTGRM->ATTRIBUTE06, CQCMRPTGRM_N->ATTRIBUTE06, sizeof(CQCMRPTGRM->ATTRIBUTE06));
    MEMCPY_DN(CQCMRPTGRM->ATTRIBUTE07, CQCMRPTGRM_N->ATTRIBUTE07, sizeof(CQCMRPTGRM->ATTRIBUTE07));
    MEMCPY_DN(CQCMRPTGRM->ATTRIBUTE08, CQCMRPTGRM_N->ATTRIBUTE08, sizeof(CQCMRPTGRM->ATTRIBUTE08));
    MEMCPY_DN(CQCMRPTGRM->ATTRIBUTE09, CQCMRPTGRM_N->ATTRIBUTE09, sizeof(CQCMRPTGRM->ATTRIBUTE09));
    MEMCPY_DN(CQCMRPTGRM->ATTRIBUTE10, CQCMRPTGRM_N->ATTRIBUTE10, sizeof(CQCMRPTGRM->ATTRIBUTE10));
    MEMCPY_DN(CQCMRPTGRM->REMARKS, CQCMRPTGRM_N->REMARKS, sizeof(CQCMRPTGRM->REMARKS));
    CQCMRPTGRM->USE_YN = CQCMRPTGRM_N->USE_YN[0];
    MEMCPY_DN(CQCMRPTGRM->CREATE_USER_ID, CQCMRPTGRM_N->CREATE_USER_ID, sizeof(CQCMRPTGRM->CREATE_USER_ID));
    MEMCPY_DN(CQCMRPTGRM->CREATE_TIME, CQCMRPTGRM_N->CREATE_TIME, sizeof(CQCMRPTGRM->CREATE_TIME));
    MEMCPY_DN(CQCMRPTGRM->UPDATE_USER_ID, CQCMRPTGRM_N->UPDATE_USER_ID, sizeof(CQCMRPTGRM->UPDATE_USER_ID));
    MEMCPY_DN(CQCMRPTGRM->UPDATE_TIME, CQCMRPTGRM_N->UPDATE_TIME, sizeof(CQCMRPTGRM->UPDATE_TIME));
    MEMCPY_DN(CQCMRPTGRM->SUB_IMAGE01, CQCMRPTGRM_N->SUB_IMAGE01, sizeof(CQCMRPTGRM->SUB_IMAGE01));
    MEMCPY_DN(CQCMRPTGRM->SUB_IMAGE02, CQCMRPTGRM_N->SUB_IMAGE02, sizeof(CQCMRPTGRM->SUB_IMAGE02));
    MEMCPY_DN(CQCMRPTGRM->SUB_IMAGE03, CQCMRPTGRM_N->SUB_IMAGE03, sizeof(CQCMRPTGRM->SUB_IMAGE03));
    MEMCPY_DN(CQCMRPTGRM->SUB_IMAGE04, CQCMRPTGRM_N->SUB_IMAGE04, sizeof(CQCMRPTGRM->SUB_IMAGE04));
    MEMCPY_DN(CQCMRPTGRM->SUB_IMAGE05, CQCMRPTGRM_N->SUB_IMAGE05, sizeof(CQCMRPTGRM->SUB_IMAGE05));
    MEMCPY_DN(CQCMRPTGRM->SUB_IMAGE06, CQCMRPTGRM_N->SUB_IMAGE06, sizeof(CQCMRPTGRM->SUB_IMAGE06));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_1, CQCMRPTGRM_N->RPT_CMF_1, sizeof(CQCMRPTGRM->RPT_CMF_1));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_2, CQCMRPTGRM_N->RPT_CMF_2, sizeof(CQCMRPTGRM->RPT_CMF_2));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_3, CQCMRPTGRM_N->RPT_CMF_3, sizeof(CQCMRPTGRM->RPT_CMF_3));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_4, CQCMRPTGRM_N->RPT_CMF_4, sizeof(CQCMRPTGRM->RPT_CMF_4));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_5, CQCMRPTGRM_N->RPT_CMF_5, sizeof(CQCMRPTGRM->RPT_CMF_5));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_6, CQCMRPTGRM_N->RPT_CMF_6, sizeof(CQCMRPTGRM->RPT_CMF_6));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_7, CQCMRPTGRM_N->RPT_CMF_7, sizeof(CQCMRPTGRM->RPT_CMF_7));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_8, CQCMRPTGRM_N->RPT_CMF_8, sizeof(CQCMRPTGRM->RPT_CMF_8));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_9, CQCMRPTGRM_N->RPT_CMF_9, sizeof(CQCMRPTGRM->RPT_CMF_9));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_10, CQCMRPTGRM_N->RPT_CMF_10, sizeof(CQCMRPTGRM->RPT_CMF_10));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_11, CQCMRPTGRM_N->RPT_CMF_11, sizeof(CQCMRPTGRM->RPT_CMF_11));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_12, CQCMRPTGRM_N->RPT_CMF_12, sizeof(CQCMRPTGRM->RPT_CMF_12));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_13, CQCMRPTGRM_N->RPT_CMF_13, sizeof(CQCMRPTGRM->RPT_CMF_13));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_14, CQCMRPTGRM_N->RPT_CMF_14, sizeof(CQCMRPTGRM->RPT_CMF_14));
    MEMCPY_DN(CQCMRPTGRM->RPT_CMF_15, CQCMRPTGRM_N->RPT_CMF_15, sizeof(CQCMRPTGRM->RPT_CMF_15));
}


