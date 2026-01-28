
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
    "DBU_mrasreshis.pc"
};


static unsigned int sqlctx = 9422083;


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
            void  *sqhstv[74];
   unsigned int   sqhstl[74];
            int   sqhsts[74];
            void  *sqindv[74];
            int   sqinds[74];
   unsigned int   sqharm[74];
   unsigned int   *sqharc[74];
   unsigned short  sqadto[74];
   unsigned short  sqtdso[74];
} sqlstm = {13,74};

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
"select FACTORY ,RES_ID ,HIST_SEQ ,EVENT_ID ,TRAN_TIME ,SYS_TRAN_TIME ,OLD_E\
VENT_ID ,OLD_HIST_SEQ ,OLD_TRAN_TIME ,OLD_SYS_TRAN_TIME ,OLD_UP_DOWN_FLAG ,OL\
D_PRI_STS ,OLD_STS_1 ,OLD_STS_2 ,OLD_STS_3 ,OLD_STS_4 ,OLD_STS_5 ,OLD_STS_6 ,\
OLD_STS_7 ,OLD_STS_8 ,OLD_STS_9 ,OLD_STS_10 ,NEW_UP_DOWN_FLAG ,NEW_PRI_STS ,N\
EW_STS_1 ,NEW_STS_2 ,NEW_STS_3 ,NEW_STS_4 ,NEW_STS_5 ,NEW_STS_6 ,NEW_STS_7 ,N\
EW_STS_8 ,NEW_STS_9 ,NEW_STS_10 ,LOT_ID ,SUBLOT_ID ,CRR_ID ,RES_CTRL_MODE ,RE\
S_PROC_MODE ,LOT_EXIST_FLAG ,COL_SET_ID ,COL_SET_VERSION ,TRAN_CMF_1 ,TRAN_CM\
F_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,\
TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_CMF_14 ,\
TRAN_CMF_15 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN_CMF_20 \
,TRAN_USER_ID ,TRAN_COMMENT ,LAST_DOWN_TIME ,LAST_DOWN_HIST_SEQ ,HIST_START_S\
EQ ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT  from MR\
ASRESHIS  order by FACTORY asc ,RES_ID asc ,HIST_SEQ asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,1334,0,4,46,0,0,74,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
316,0,0,2,1346,0,4,230,0,0,74,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
627,0,0,3,96,0,4,417,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
658,0,0,4,78,0,2,455,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
685,0,0,5,1215,0,3,486,0,0,71,71,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
984,0,0,6,1222,0,5,653,0,0,71,71,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1283,0,0,7,991,0,9,832,0,0,0,0,0,1,0,
1298,0,0,7,0,0,13,861,0,0,71,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1597,0,0,7,0,0,15,962,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_mrasreshis.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-07-21 13:01:06
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
void DBU_add_null_mrasreshis(struct MRASRESHIS_N_TAG *MRASRESHIS_N, struct MRASRESHIS_TAG *MRASRESHIS);
void DBU_del_null_mrasreshis(struct MRASRESHIS_N_TAG *MRASRESHIS_N, struct MRASRESHIS_TAG *MRASRESHIS);


/* SQL SELECT Function */
void DBU_select_mrasreshis(int sel_type, struct MRASRESHIS_TAG *MRASRESHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESHIS_N_TAG MRASRESHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasreshis(&MRASRESHIS_N, MRASRESHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    RES_ID,
                    HIST_SEQ,
                    EVENT_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    OLD_EVENT_ID,
                    OLD_HIST_SEQ,
                    OLD_TRAN_TIME,
                    OLD_SYS_TRAN_TIME,
                    OLD_UP_DOWN_FLAG,
                    OLD_PRI_STS,
                    OLD_STS_1,
                    OLD_STS_2,
                    OLD_STS_3,
                    OLD_STS_4,
                    OLD_STS_5,
                    OLD_STS_6,
                    OLD_STS_7,
                    OLD_STS_8,
                    OLD_STS_9,
                    OLD_STS_10,
                    NEW_UP_DOWN_FLAG,
                    NEW_PRI_STS,
                    NEW_STS_1,
                    NEW_STS_2,
                    NEW_STS_3,
                    NEW_STS_4,
                    NEW_STS_5,
                    NEW_STS_6,
                    NEW_STS_7,
                    NEW_STS_8,
                    NEW_STS_9,
                    NEW_STS_10,
                    LOT_ID,
                    SUBLOT_ID,
                    CRR_ID,
                    RES_CTRL_MODE,
                    RES_PROC_MODE,
                    LOT_EXIST_FLAG,
                    COL_SET_ID,
                    COL_SET_VERSION,
                    TRAN_CMF_1,
                    TRAN_CMF_2,
                    TRAN_CMF_3,
                    TRAN_CMF_4,
                    TRAN_CMF_5,
                    TRAN_CMF_6,
                    TRAN_CMF_7,
                    TRAN_CMF_8,
                    TRAN_CMF_9,
                    TRAN_CMF_10,
                    TRAN_CMF_11,
                    TRAN_CMF_12,
                    TRAN_CMF_13,
                    TRAN_CMF_14,
                    TRAN_CMF_15,
                    TRAN_CMF_16,
                    TRAN_CMF_17,
                    TRAN_CMF_18,
                    TRAN_CMF_19,
                    TRAN_CMF_20,
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ,
                    HIST_START_SEQ,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                INTO 
                    :MRASRESHIS_N.FACTORY,
                    :MRASRESHIS_N.RES_ID,
                    :MRASRESHIS_N.HIST_SEQ,
                    :MRASRESHIS_N.EVENT_ID,
                    :MRASRESHIS_N.TRAN_TIME,
                    :MRASRESHIS_N.SYS_TRAN_TIME,
                    :MRASRESHIS_N.OLD_EVENT_ID,
                    :MRASRESHIS_N.OLD_HIST_SEQ,
                    :MRASRESHIS_N.OLD_TRAN_TIME,
                    :MRASRESHIS_N.OLD_SYS_TRAN_TIME,
                    :MRASRESHIS_N.OLD_UP_DOWN_FLAG,
                    :MRASRESHIS_N.OLD_PRI_STS,
                    :MRASRESHIS_N.OLD_STS_1,
                    :MRASRESHIS_N.OLD_STS_2,
                    :MRASRESHIS_N.OLD_STS_3,
                    :MRASRESHIS_N.OLD_STS_4,
                    :MRASRESHIS_N.OLD_STS_5,
                    :MRASRESHIS_N.OLD_STS_6,
                    :MRASRESHIS_N.OLD_STS_7,
                    :MRASRESHIS_N.OLD_STS_8,
                    :MRASRESHIS_N.OLD_STS_9,
                    :MRASRESHIS_N.OLD_STS_10,
                    :MRASRESHIS_N.NEW_UP_DOWN_FLAG,
                    :MRASRESHIS_N.NEW_PRI_STS,
                    :MRASRESHIS_N.NEW_STS_1,
                    :MRASRESHIS_N.NEW_STS_2,
                    :MRASRESHIS_N.NEW_STS_3,
                    :MRASRESHIS_N.NEW_STS_4,
                    :MRASRESHIS_N.NEW_STS_5,
                    :MRASRESHIS_N.NEW_STS_6,
                    :MRASRESHIS_N.NEW_STS_7,
                    :MRASRESHIS_N.NEW_STS_8,
                    :MRASRESHIS_N.NEW_STS_9,
                    :MRASRESHIS_N.NEW_STS_10,
                    :MRASRESHIS_N.LOT_ID,
                    :MRASRESHIS_N.SUBLOT_ID,
                    :MRASRESHIS_N.CRR_ID,
                    :MRASRESHIS_N.RES_CTRL_MODE,
                    :MRASRESHIS_N.RES_PROC_MODE,
                    :MRASRESHIS_N.LOT_EXIST_FLAG,
                    :MRASRESHIS_N.COL_SET_ID,
                    :MRASRESHIS_N.COL_SET_VERSION,
                    :MRASRESHIS_N.TRAN_CMF_1,
                    :MRASRESHIS_N.TRAN_CMF_2,
                    :MRASRESHIS_N.TRAN_CMF_3,
                    :MRASRESHIS_N.TRAN_CMF_4,
                    :MRASRESHIS_N.TRAN_CMF_5,
                    :MRASRESHIS_N.TRAN_CMF_6,
                    :MRASRESHIS_N.TRAN_CMF_7,
                    :MRASRESHIS_N.TRAN_CMF_8,
                    :MRASRESHIS_N.TRAN_CMF_9,
                    :MRASRESHIS_N.TRAN_CMF_10,
                    :MRASRESHIS_N.TRAN_CMF_11,
                    :MRASRESHIS_N.TRAN_CMF_12,
                    :MRASRESHIS_N.TRAN_CMF_13,
                    :MRASRESHIS_N.TRAN_CMF_14,
                    :MRASRESHIS_N.TRAN_CMF_15,
                    :MRASRESHIS_N.TRAN_CMF_16,
                    :MRASRESHIS_N.TRAN_CMF_17,
                    :MRASRESHIS_N.TRAN_CMF_18,
                    :MRASRESHIS_N.TRAN_CMF_19,
                    :MRASRESHIS_N.TRAN_CMF_20,
                    :MRASRESHIS_N.TRAN_USER_ID,
                    :MRASRESHIS_N.TRAN_COMMENT,
                    :MRASRESHIS_N.LAST_DOWN_TIME,
                    :MRASRESHIS_N.LAST_DOWN_HIST_SEQ,
                    :MRASRESHIS_N.HIST_START_SEQ,
                    :MRASRESHIS_N.HIST_DEL_FLAG,
                    :MRASRESHIS_N.HIST_DEL_TIME,
                    :MRASRESHIS_N.HIST_DEL_USER_ID,
                    :MRASRESHIS_N.HIST_DEL_COMMENT
                FROM MRASRESHIS
                WHERE FACTORY = :MRASRESHIS_N.FACTORY
                    AND RES_ID = :MRASRESHIS_N.RES_ID
                    AND HIST_SEQ = :MRASRESHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,RES_ID ,HIST_SEQ ,EVENT_ID ,TRAN_TIME ,SYS_TR\
AN_TIME ,OLD_EVENT_ID ,OLD_HIST_SEQ ,OLD_TRAN_TIME ,OLD_SYS_TRAN_TIME ,OLD_U\
P_DOWN_FLAG ,OLD_PRI_STS ,OLD_STS_1 ,OLD_STS_2 ,OLD_STS_3 ,OLD_STS_4 ,OLD_ST\
S_5 ,OLD_STS_6 ,OLD_STS_7 ,OLD_STS_8 ,OLD_STS_9 ,OLD_STS_10 ,NEW_UP_DOWN_FLA\
G ,NEW_PRI_STS ,NEW_STS_1 ,NEW_STS_2 ,NEW_STS_3 ,NEW_STS_4 ,NEW_STS_5 ,NEW_S\
TS_6 ,NEW_STS_7 ,NEW_STS_8 ,NEW_STS_9 ,NEW_STS_10 ,LOT_ID ,SUBLOT_ID ,CRR_ID\
 ,RES_CTRL_MODE ,RES_PROC_MODE ,LOT_EXIST_FLAG ,COL_SET_ID ,COL_SET_VERSION \
,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRA\
N_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN\
_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TR\
AN_CMF_19 ,TRAN_CMF_20 ,TRAN_USER_ID ,TRAN_COMMENT ,LAST_DOWN_TIME ,LAST_DOW\
N_HIST_SEQ ,HIST_START_SEQ ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,\
HIST_DEL_COMMENT into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12\
,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,");
            sqlstm.stmt = ":b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b3\
2,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,\
:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b\
63,:b64,:b65,:b66,:b67,:b68,:b69,:b70  from MRASRESHIS where ((FACTORY=:b0 an\
d RES_ID=:b1) and HIST_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESHIS_N.RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MRASRESHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESHIS_N.EVENT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )13;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESHIS_N.TRAN_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESHIS_N.OLD_EVENT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )13;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MRASRESHIS_N.OLD_HIST_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESHIS_N.OLD_TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESHIS_N.OLD_SYS_TRAN_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESHIS_N.OLD_UP_DOWN_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESHIS_N.OLD_PRI_STS);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESHIS_N.OLD_STS_1);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESHIS_N.OLD_STS_2);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESHIS_N.OLD_STS_3);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESHIS_N.OLD_STS_4);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESHIS_N.OLD_STS_5);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESHIS_N.OLD_STS_6);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESHIS_N.OLD_STS_7);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESHIS_N.OLD_STS_8);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESHIS_N.OLD_STS_9);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESHIS_N.OLD_STS_10);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESHIS_N.NEW_UP_DOWN_FLAG);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESHIS_N.NEW_PRI_STS);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESHIS_N.NEW_STS_1);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESHIS_N.NEW_STS_2);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESHIS_N.NEW_STS_3);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESHIS_N.NEW_STS_4);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESHIS_N.NEW_STS_5);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESHIS_N.NEW_STS_6);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESHIS_N.NEW_STS_7);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESHIS_N.NEW_STS_8);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESHIS_N.NEW_STS_9);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESHIS_N.NEW_STS_10);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESHIS_N.LOT_ID);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESHIS_N.CRR_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESHIS_N.RES_CTRL_MODE);
            sqlstm.sqhstl[37] = (unsigned int  )3;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASRESHIS_N.RES_PROC_MODE);
            sqlstm.sqhstl[38] = (unsigned int  )11;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESHIS_N.LOT_EXIST_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESHIS_N.COL_SET_ID);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(MRASRESHIS_N.COL_SET_VERSION);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASRESHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASRESHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASRESHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASRESHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[63] = (unsigned int  )401;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESHIS_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MRASRESHIS_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MRASRESHIS_N.HIST_START_SEQ);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASRESHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[70] = (unsigned int  )401;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASRESHIS_N.FACTORY);
            sqlstm.sqhstl[71] = (unsigned int  )11;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASRESHIS_N.RES_ID);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)&(MRASRESHIS_N.HIST_SEQ);
            sqlstm.sqhstl[73] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
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
        DBU_del_null_mrasreshis(&MRASRESHIS_N, MRASRESHIS);
    }

    DB_stop_query_timer("DBU_select_mrasreshis", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_mrasreshis_for_update(int sel_type, struct MRASRESHIS_TAG *MRASRESHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESHIS_N_TAG MRASRESHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasreshis(&MRASRESHIS_N, MRASRESHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    RES_ID,
                    HIST_SEQ,
                    EVENT_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    OLD_EVENT_ID,
                    OLD_HIST_SEQ,
                    OLD_TRAN_TIME,
                    OLD_SYS_TRAN_TIME,
                    OLD_UP_DOWN_FLAG,
                    OLD_PRI_STS,
                    OLD_STS_1,
                    OLD_STS_2,
                    OLD_STS_3,
                    OLD_STS_4,
                    OLD_STS_5,
                    OLD_STS_6,
                    OLD_STS_7,
                    OLD_STS_8,
                    OLD_STS_9,
                    OLD_STS_10,
                    NEW_UP_DOWN_FLAG,
                    NEW_PRI_STS,
                    NEW_STS_1,
                    NEW_STS_2,
                    NEW_STS_3,
                    NEW_STS_4,
                    NEW_STS_5,
                    NEW_STS_6,
                    NEW_STS_7,
                    NEW_STS_8,
                    NEW_STS_9,
                    NEW_STS_10,
                    LOT_ID,
                    SUBLOT_ID,
                    CRR_ID,
                    RES_CTRL_MODE,
                    RES_PROC_MODE,
                    LOT_EXIST_FLAG,
                    COL_SET_ID,
                    COL_SET_VERSION,
                    TRAN_CMF_1,
                    TRAN_CMF_2,
                    TRAN_CMF_3,
                    TRAN_CMF_4,
                    TRAN_CMF_5,
                    TRAN_CMF_6,
                    TRAN_CMF_7,
                    TRAN_CMF_8,
                    TRAN_CMF_9,
                    TRAN_CMF_10,
                    TRAN_CMF_11,
                    TRAN_CMF_12,
                    TRAN_CMF_13,
                    TRAN_CMF_14,
                    TRAN_CMF_15,
                    TRAN_CMF_16,
                    TRAN_CMF_17,
                    TRAN_CMF_18,
                    TRAN_CMF_19,
                    TRAN_CMF_20,
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ,
                    HIST_START_SEQ,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                INTO 
                    :MRASRESHIS_N.FACTORY,
                    :MRASRESHIS_N.RES_ID,
                    :MRASRESHIS_N.HIST_SEQ,
                    :MRASRESHIS_N.EVENT_ID,
                    :MRASRESHIS_N.TRAN_TIME,
                    :MRASRESHIS_N.SYS_TRAN_TIME,
                    :MRASRESHIS_N.OLD_EVENT_ID,
                    :MRASRESHIS_N.OLD_HIST_SEQ,
                    :MRASRESHIS_N.OLD_TRAN_TIME,
                    :MRASRESHIS_N.OLD_SYS_TRAN_TIME,
                    :MRASRESHIS_N.OLD_UP_DOWN_FLAG,
                    :MRASRESHIS_N.OLD_PRI_STS,
                    :MRASRESHIS_N.OLD_STS_1,
                    :MRASRESHIS_N.OLD_STS_2,
                    :MRASRESHIS_N.OLD_STS_3,
                    :MRASRESHIS_N.OLD_STS_4,
                    :MRASRESHIS_N.OLD_STS_5,
                    :MRASRESHIS_N.OLD_STS_6,
                    :MRASRESHIS_N.OLD_STS_7,
                    :MRASRESHIS_N.OLD_STS_8,
                    :MRASRESHIS_N.OLD_STS_9,
                    :MRASRESHIS_N.OLD_STS_10,
                    :MRASRESHIS_N.NEW_UP_DOWN_FLAG,
                    :MRASRESHIS_N.NEW_PRI_STS,
                    :MRASRESHIS_N.NEW_STS_1,
                    :MRASRESHIS_N.NEW_STS_2,
                    :MRASRESHIS_N.NEW_STS_3,
                    :MRASRESHIS_N.NEW_STS_4,
                    :MRASRESHIS_N.NEW_STS_5,
                    :MRASRESHIS_N.NEW_STS_6,
                    :MRASRESHIS_N.NEW_STS_7,
                    :MRASRESHIS_N.NEW_STS_8,
                    :MRASRESHIS_N.NEW_STS_9,
                    :MRASRESHIS_N.NEW_STS_10,
                    :MRASRESHIS_N.LOT_ID,
                    :MRASRESHIS_N.SUBLOT_ID,
                    :MRASRESHIS_N.CRR_ID,
                    :MRASRESHIS_N.RES_CTRL_MODE,
                    :MRASRESHIS_N.RES_PROC_MODE,
                    :MRASRESHIS_N.LOT_EXIST_FLAG,
                    :MRASRESHIS_N.COL_SET_ID,
                    :MRASRESHIS_N.COL_SET_VERSION,
                    :MRASRESHIS_N.TRAN_CMF_1,
                    :MRASRESHIS_N.TRAN_CMF_2,
                    :MRASRESHIS_N.TRAN_CMF_3,
                    :MRASRESHIS_N.TRAN_CMF_4,
                    :MRASRESHIS_N.TRAN_CMF_5,
                    :MRASRESHIS_N.TRAN_CMF_6,
                    :MRASRESHIS_N.TRAN_CMF_7,
                    :MRASRESHIS_N.TRAN_CMF_8,
                    :MRASRESHIS_N.TRAN_CMF_9,
                    :MRASRESHIS_N.TRAN_CMF_10,
                    :MRASRESHIS_N.TRAN_CMF_11,
                    :MRASRESHIS_N.TRAN_CMF_12,
                    :MRASRESHIS_N.TRAN_CMF_13,
                    :MRASRESHIS_N.TRAN_CMF_14,
                    :MRASRESHIS_N.TRAN_CMF_15,
                    :MRASRESHIS_N.TRAN_CMF_16,
                    :MRASRESHIS_N.TRAN_CMF_17,
                    :MRASRESHIS_N.TRAN_CMF_18,
                    :MRASRESHIS_N.TRAN_CMF_19,
                    :MRASRESHIS_N.TRAN_CMF_20,
                    :MRASRESHIS_N.TRAN_USER_ID,
                    :MRASRESHIS_N.TRAN_COMMENT,
                    :MRASRESHIS_N.LAST_DOWN_TIME,
                    :MRASRESHIS_N.LAST_DOWN_HIST_SEQ,
                    :MRASRESHIS_N.HIST_START_SEQ,
                    :MRASRESHIS_N.HIST_DEL_FLAG,
                    :MRASRESHIS_N.HIST_DEL_TIME,
                    :MRASRESHIS_N.HIST_DEL_USER_ID,
                    :MRASRESHIS_N.HIST_DEL_COMMENT
                FROM MRASRESHIS
                WHERE FACTORY = :MRASRESHIS_N.FACTORY
                    AND RES_ID = :MRASRESHIS_N.RES_ID
                    AND HIST_SEQ = :MRASRESHIS_N.HIST_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,RES_ID ,HIST_SEQ ,EVENT_ID ,TRAN_TIME ,SYS_TR\
AN_TIME ,OLD_EVENT_ID ,OLD_HIST_SEQ ,OLD_TRAN_TIME ,OLD_SYS_TRAN_TIME ,OLD_U\
P_DOWN_FLAG ,OLD_PRI_STS ,OLD_STS_1 ,OLD_STS_2 ,OLD_STS_3 ,OLD_STS_4 ,OLD_ST\
S_5 ,OLD_STS_6 ,OLD_STS_7 ,OLD_STS_8 ,OLD_STS_9 ,OLD_STS_10 ,NEW_UP_DOWN_FLA\
G ,NEW_PRI_STS ,NEW_STS_1 ,NEW_STS_2 ,NEW_STS_3 ,NEW_STS_4 ,NEW_STS_5 ,NEW_S\
TS_6 ,NEW_STS_7 ,NEW_STS_8 ,NEW_STS_9 ,NEW_STS_10 ,LOT_ID ,SUBLOT_ID ,CRR_ID\
 ,RES_CTRL_MODE ,RES_PROC_MODE ,LOT_EXIST_FLAG ,COL_SET_ID ,COL_SET_VERSION \
,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRA\
N_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN\
_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TR\
AN_CMF_19 ,TRAN_CMF_20 ,TRAN_USER_ID ,TRAN_COMMENT ,LAST_DOWN_TIME ,LAST_DOW\
N_HIST_SEQ ,HIST_START_SEQ ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,\
HIST_DEL_COMMENT into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12\
,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,");
            sqlstm.stmt = ":b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b3\
2,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,\
:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b\
63,:b64,:b65,:b66,:b67,:b68,:b69,:b70  from MRASRESHIS where ((FACTORY=:b0 an\
d RES_ID=:b1) and HIST_SEQ=:b2) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )316;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESHIS_N.RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MRASRESHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESHIS_N.EVENT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )13;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESHIS_N.TRAN_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESHIS_N.OLD_EVENT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )13;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MRASRESHIS_N.OLD_HIST_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESHIS_N.OLD_TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESHIS_N.OLD_SYS_TRAN_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESHIS_N.OLD_UP_DOWN_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESHIS_N.OLD_PRI_STS);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESHIS_N.OLD_STS_1);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESHIS_N.OLD_STS_2);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESHIS_N.OLD_STS_3);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESHIS_N.OLD_STS_4);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESHIS_N.OLD_STS_5);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESHIS_N.OLD_STS_6);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESHIS_N.OLD_STS_7);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESHIS_N.OLD_STS_8);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESHIS_N.OLD_STS_9);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESHIS_N.OLD_STS_10);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESHIS_N.NEW_UP_DOWN_FLAG);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESHIS_N.NEW_PRI_STS);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESHIS_N.NEW_STS_1);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESHIS_N.NEW_STS_2);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESHIS_N.NEW_STS_3);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESHIS_N.NEW_STS_4);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESHIS_N.NEW_STS_5);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESHIS_N.NEW_STS_6);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESHIS_N.NEW_STS_7);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESHIS_N.NEW_STS_8);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESHIS_N.NEW_STS_9);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESHIS_N.NEW_STS_10);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESHIS_N.LOT_ID);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESHIS_N.CRR_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESHIS_N.RES_CTRL_MODE);
            sqlstm.sqhstl[37] = (unsigned int  )3;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASRESHIS_N.RES_PROC_MODE);
            sqlstm.sqhstl[38] = (unsigned int  )11;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESHIS_N.LOT_EXIST_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESHIS_N.COL_SET_ID);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(MRASRESHIS_N.COL_SET_VERSION);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASRESHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASRESHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASRESHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASRESHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[63] = (unsigned int  )401;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESHIS_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MRASRESHIS_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MRASRESHIS_N.HIST_START_SEQ);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASRESHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[70] = (unsigned int  )401;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASRESHIS_N.FACTORY);
            sqlstm.sqhstl[71] = (unsigned int  )11;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASRESHIS_N.RES_ID);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)&(MRASRESHIS_N.HIST_SEQ);
            sqlstm.sqhstl[73] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
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
        DBU_del_null_mrasreshis(&MRASRESHIS_N, MRASRESHIS);
    }

    DB_stop_query_timer("DBU_select_mrasreshis_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_mrasreshis_scalar(int sel_type, struct MRASRESHIS_TAG *MRASRESHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESHIS_N_TAG MRASRESHIS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasreshis(&MRASRESHIS_N, MRASRESHIS);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MRASRESHIS
                WHERE FACTORY = :MRASRESHIS_N.FACTORY
                    AND RES_ID = :MRASRESHIS_N.RES_ID
                    AND HIST_SEQ = :MRASRESHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MRASRESHIS where\
 ((FACTORY=:b1 and RES_ID=:b2) and HIST_SEQ=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )627;
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
            sqlstm.sqhstv[1] = (         void  *)(MRASRESHIS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESHIS_N.RES_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MRASRESHIS_N.HIST_SEQ);
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

    DB_stop_query_timer("DBU_select_mrasreshis_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_mrasreshis(int sel_type, struct MRASRESHIS_TAG *MRASRESHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESHIS_N_TAG MRASRESHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasreshis(&MRASRESHIS_N, MRASRESHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MRASRESHIS
                WHERE FACTORY = :MRASRESHIS_N.FACTORY
                    AND RES_ID = :MRASRESHIS_N.RES_ID
                    AND HIST_SEQ = :MRASRESHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MRASRESHIS  where ((FACTORY=:b0 and\
 RES_ID=:b1) and HIST_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )658;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESHIS_N.RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MRASRESHIS_N.HIST_SEQ);
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

    DB_stop_query_timer("DBU_delete_mrasreshis", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_mrasreshis(struct MRASRESHIS_TAG *MRASRESHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESHIS_N_TAG MRASRESHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasreshis(&MRASRESHIS_N, MRASRESHIS);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MRASRESHIS( 
                    FACTORY, 
                    RES_ID, 
                    HIST_SEQ, 
                    EVENT_ID, 
                    TRAN_TIME, 
                    SYS_TRAN_TIME, 
                    OLD_EVENT_ID, 
                    OLD_HIST_SEQ, 
                    OLD_TRAN_TIME, 
                    OLD_SYS_TRAN_TIME, 
                    OLD_UP_DOWN_FLAG, 
                    OLD_PRI_STS, 
                    OLD_STS_1, 
                    OLD_STS_2, 
                    OLD_STS_3, 
                    OLD_STS_4, 
                    OLD_STS_5, 
                    OLD_STS_6, 
                    OLD_STS_7, 
                    OLD_STS_8, 
                    OLD_STS_9, 
                    OLD_STS_10, 
                    NEW_UP_DOWN_FLAG, 
                    NEW_PRI_STS, 
                    NEW_STS_1, 
                    NEW_STS_2, 
                    NEW_STS_3, 
                    NEW_STS_4, 
                    NEW_STS_5, 
                    NEW_STS_6, 
                    NEW_STS_7, 
                    NEW_STS_8, 
                    NEW_STS_9, 
                    NEW_STS_10, 
                    LOT_ID, 
                    SUBLOT_ID, 
                    CRR_ID, 
                    RES_CTRL_MODE, 
                    RES_PROC_MODE, 
                    LOT_EXIST_FLAG, 
                    COL_SET_ID, 
                    COL_SET_VERSION, 
                    TRAN_CMF_1, 
                    TRAN_CMF_2, 
                    TRAN_CMF_3, 
                    TRAN_CMF_4, 
                    TRAN_CMF_5, 
                    TRAN_CMF_6, 
                    TRAN_CMF_7, 
                    TRAN_CMF_8, 
                    TRAN_CMF_9, 
                    TRAN_CMF_10, 
                    TRAN_CMF_11, 
                    TRAN_CMF_12, 
                    TRAN_CMF_13, 
                    TRAN_CMF_14, 
                    TRAN_CMF_15, 
                    TRAN_CMF_16, 
                    TRAN_CMF_17, 
                    TRAN_CMF_18, 
                    TRAN_CMF_19, 
                    TRAN_CMF_20, 
                    TRAN_USER_ID, 
                    TRAN_COMMENT, 
                    LAST_DOWN_TIME, 
                    LAST_DOWN_HIST_SEQ, 
                    HIST_START_SEQ, 
                    HIST_DEL_FLAG, 
                    HIST_DEL_TIME, 
                    HIST_DEL_USER_ID, 
                    HIST_DEL_COMMENT
         ) 
        VALUES (
                    :MRASRESHIS_N.FACTORY,
                    :MRASRESHIS_N.RES_ID,
                    :MRASRESHIS_N.HIST_SEQ,
                    :MRASRESHIS_N.EVENT_ID,
                    :MRASRESHIS_N.TRAN_TIME,
                    :MRASRESHIS_N.SYS_TRAN_TIME,
                    :MRASRESHIS_N.OLD_EVENT_ID,
                    :MRASRESHIS_N.OLD_HIST_SEQ,
                    :MRASRESHIS_N.OLD_TRAN_TIME,
                    :MRASRESHIS_N.OLD_SYS_TRAN_TIME,
                    :MRASRESHIS_N.OLD_UP_DOWN_FLAG,
                    :MRASRESHIS_N.OLD_PRI_STS,
                    :MRASRESHIS_N.OLD_STS_1,
                    :MRASRESHIS_N.OLD_STS_2,
                    :MRASRESHIS_N.OLD_STS_3,
                    :MRASRESHIS_N.OLD_STS_4,
                    :MRASRESHIS_N.OLD_STS_5,
                    :MRASRESHIS_N.OLD_STS_6,
                    :MRASRESHIS_N.OLD_STS_7,
                    :MRASRESHIS_N.OLD_STS_8,
                    :MRASRESHIS_N.OLD_STS_9,
                    :MRASRESHIS_N.OLD_STS_10,
                    :MRASRESHIS_N.NEW_UP_DOWN_FLAG,
                    :MRASRESHIS_N.NEW_PRI_STS,
                    :MRASRESHIS_N.NEW_STS_1,
                    :MRASRESHIS_N.NEW_STS_2,
                    :MRASRESHIS_N.NEW_STS_3,
                    :MRASRESHIS_N.NEW_STS_4,
                    :MRASRESHIS_N.NEW_STS_5,
                    :MRASRESHIS_N.NEW_STS_6,
                    :MRASRESHIS_N.NEW_STS_7,
                    :MRASRESHIS_N.NEW_STS_8,
                    :MRASRESHIS_N.NEW_STS_9,
                    :MRASRESHIS_N.NEW_STS_10,
                    :MRASRESHIS_N.LOT_ID,
                    :MRASRESHIS_N.SUBLOT_ID,
                    :MRASRESHIS_N.CRR_ID,
                    :MRASRESHIS_N.RES_CTRL_MODE,
                    :MRASRESHIS_N.RES_PROC_MODE,
                    :MRASRESHIS_N.LOT_EXIST_FLAG,
                    :MRASRESHIS_N.COL_SET_ID,
                    :MRASRESHIS_N.COL_SET_VERSION,
                    :MRASRESHIS_N.TRAN_CMF_1,
                    :MRASRESHIS_N.TRAN_CMF_2,
                    :MRASRESHIS_N.TRAN_CMF_3,
                    :MRASRESHIS_N.TRAN_CMF_4,
                    :MRASRESHIS_N.TRAN_CMF_5,
                    :MRASRESHIS_N.TRAN_CMF_6,
                    :MRASRESHIS_N.TRAN_CMF_7,
                    :MRASRESHIS_N.TRAN_CMF_8,
                    :MRASRESHIS_N.TRAN_CMF_9,
                    :MRASRESHIS_N.TRAN_CMF_10,
                    :MRASRESHIS_N.TRAN_CMF_11,
                    :MRASRESHIS_N.TRAN_CMF_12,
                    :MRASRESHIS_N.TRAN_CMF_13,
                    :MRASRESHIS_N.TRAN_CMF_14,
                    :MRASRESHIS_N.TRAN_CMF_15,
                    :MRASRESHIS_N.TRAN_CMF_16,
                    :MRASRESHIS_N.TRAN_CMF_17,
                    :MRASRESHIS_N.TRAN_CMF_18,
                    :MRASRESHIS_N.TRAN_CMF_19,
                    :MRASRESHIS_N.TRAN_CMF_20,
                    :MRASRESHIS_N.TRAN_USER_ID,
                    :MRASRESHIS_N.TRAN_COMMENT,
                    :MRASRESHIS_N.LAST_DOWN_TIME,
                    :MRASRESHIS_N.LAST_DOWN_HIST_SEQ,
                    :MRASRESHIS_N.HIST_START_SEQ,
                    :MRASRESHIS_N.HIST_DEL_FLAG,
                    :MRASRESHIS_N.HIST_DEL_TIME,
                    :MRASRESHIS_N.HIST_DEL_USER_ID,
                    :MRASRESHIS_N.HIST_DEL_COMMENT
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 74;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MRASRESHIS (FACTORY,RES_ID,HIST_SEQ,EVENT_ID,TRAN_TIME,SY\
S_TRAN_TIME,OLD_EVENT_ID,OLD_HIST_SEQ,OLD_TRAN_TIME,OLD_SYS_TRAN_TIME,OLD_UP\
_DOWN_FLAG,OLD_PRI_STS,OLD_STS_1,OLD_STS_2,OLD_STS_3,OLD_STS_4,OLD_STS_5,OLD\
_STS_6,OLD_STS_7,OLD_STS_8,OLD_STS_9,OLD_STS_10,NEW_UP_DOWN_FLAG,NEW_PRI_STS\
,NEW_STS_1,NEW_STS_2,NEW_STS_3,NEW_STS_4,NEW_STS_5,NEW_STS_6,NEW_STS_7,NEW_S\
TS_8,NEW_STS_9,NEW_STS_10,LOT_ID,SUBLOT_ID,CRR_ID,RES_CTRL_MODE,RES_PROC_MOD\
E,LOT_EXIST_FLAG,COL_SET_ID,COL_SET_VERSION,TRAN_CMF_1,TRAN_CMF_2,TRAN_CMF_3\
,TRAN_CMF_4,TRAN_CMF_5,TRAN_CMF_6,TRAN_CMF_7,TRAN_CMF_8,TRAN_CMF_9,TRAN_CMF_\
10,TRAN_CMF_11,TRAN_CMF_12,TRAN_CMF_13,TRAN_CMF_14,TRAN_CMF_15,TRAN_CMF_16,T\
RAN_CMF_17,TRAN_CMF_18,TRAN_CMF_19,TRAN_CMF_20,TRAN_USER_ID,TRAN_COMMENT,LAS\
T_DOWN_TIME,LAST_DOWN_HIST_SEQ,HIST_START_SEQ,HIST_DEL_FLAG,HIST_DEL_TIME,HI\
ST_DEL_USER_ID,HIST_DEL_COMMENT) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8\
,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:\
b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32");
    sqlstm.stmt = ",:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,\
:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b\
59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )685;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MRASRESHIS_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MRASRESHIS_N.RES_ID);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(MRASRESHIS_N.HIST_SEQ);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MRASRESHIS_N.EVENT_ID);
    sqlstm.sqhstl[3] = (unsigned int  )13;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MRASRESHIS_N.TRAN_TIME);
    sqlstm.sqhstl[4] = (unsigned int  )15;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MRASRESHIS_N.SYS_TRAN_TIME);
    sqlstm.sqhstl[5] = (unsigned int  )15;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MRASRESHIS_N.OLD_EVENT_ID);
    sqlstm.sqhstl[6] = (unsigned int  )13;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)&(MRASRESHIS_N.OLD_HIST_SEQ);
    sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MRASRESHIS_N.OLD_TRAN_TIME);
    sqlstm.sqhstl[8] = (unsigned int  )15;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MRASRESHIS_N.OLD_SYS_TRAN_TIME);
    sqlstm.sqhstl[9] = (unsigned int  )15;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MRASRESHIS_N.OLD_UP_DOWN_FLAG);
    sqlstm.sqhstl[10] = (unsigned int  )2;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MRASRESHIS_N.OLD_PRI_STS);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MRASRESHIS_N.OLD_STS_1);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MRASRESHIS_N.OLD_STS_2);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MRASRESHIS_N.OLD_STS_3);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MRASRESHIS_N.OLD_STS_4);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MRASRESHIS_N.OLD_STS_5);
    sqlstm.sqhstl[16] = (unsigned int  )31;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MRASRESHIS_N.OLD_STS_6);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MRASRESHIS_N.OLD_STS_7);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MRASRESHIS_N.OLD_STS_8);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MRASRESHIS_N.OLD_STS_9);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MRASRESHIS_N.OLD_STS_10);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MRASRESHIS_N.NEW_UP_DOWN_FLAG);
    sqlstm.sqhstl[22] = (unsigned int  )2;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MRASRESHIS_N.NEW_PRI_STS);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MRASRESHIS_N.NEW_STS_1);
    sqlstm.sqhstl[24] = (unsigned int  )31;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MRASRESHIS_N.NEW_STS_2);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MRASRESHIS_N.NEW_STS_3);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MRASRESHIS_N.NEW_STS_4);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MRASRESHIS_N.NEW_STS_5);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MRASRESHIS_N.NEW_STS_6);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MRASRESHIS_N.NEW_STS_7);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MRASRESHIS_N.NEW_STS_8);
    sqlstm.sqhstl[31] = (unsigned int  )31;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MRASRESHIS_N.NEW_STS_9);
    sqlstm.sqhstl[32] = (unsigned int  )31;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MRASRESHIS_N.NEW_STS_10);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MRASRESHIS_N.LOT_ID);
    sqlstm.sqhstl[34] = (unsigned int  )26;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MRASRESHIS_N.SUBLOT_ID);
    sqlstm.sqhstl[35] = (unsigned int  )31;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MRASRESHIS_N.CRR_ID);
    sqlstm.sqhstl[36] = (unsigned int  )21;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MRASRESHIS_N.RES_CTRL_MODE);
    sqlstm.sqhstl[37] = (unsigned int  )3;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MRASRESHIS_N.RES_PROC_MODE);
    sqlstm.sqhstl[38] = (unsigned int  )11;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MRASRESHIS_N.LOT_EXIST_FLAG);
    sqlstm.sqhstl[39] = (unsigned int  )2;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MRASRESHIS_N.COL_SET_ID);
    sqlstm.sqhstl[40] = (unsigned int  )26;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)&(MRASRESHIS_N.COL_SET_VERSION);
    sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MRASRESHIS_N.TRAN_CMF_1);
    sqlstm.sqhstl[42] = (unsigned int  )31;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MRASRESHIS_N.TRAN_CMF_2);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MRASRESHIS_N.TRAN_CMF_3);
    sqlstm.sqhstl[44] = (unsigned int  )31;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MRASRESHIS_N.TRAN_CMF_4);
    sqlstm.sqhstl[45] = (unsigned int  )31;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MRASRESHIS_N.TRAN_CMF_5);
    sqlstm.sqhstl[46] = (unsigned int  )31;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MRASRESHIS_N.TRAN_CMF_6);
    sqlstm.sqhstl[47] = (unsigned int  )31;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MRASRESHIS_N.TRAN_CMF_7);
    sqlstm.sqhstl[48] = (unsigned int  )31;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MRASRESHIS_N.TRAN_CMF_8);
    sqlstm.sqhstl[49] = (unsigned int  )31;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MRASRESHIS_N.TRAN_CMF_9);
    sqlstm.sqhstl[50] = (unsigned int  )31;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MRASRESHIS_N.TRAN_CMF_10);
    sqlstm.sqhstl[51] = (unsigned int  )31;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MRASRESHIS_N.TRAN_CMF_11);
    sqlstm.sqhstl[52] = (unsigned int  )31;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MRASRESHIS_N.TRAN_CMF_12);
    sqlstm.sqhstl[53] = (unsigned int  )31;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MRASRESHIS_N.TRAN_CMF_13);
    sqlstm.sqhstl[54] = (unsigned int  )31;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MRASRESHIS_N.TRAN_CMF_14);
    sqlstm.sqhstl[55] = (unsigned int  )31;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MRASRESHIS_N.TRAN_CMF_15);
    sqlstm.sqhstl[56] = (unsigned int  )31;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MRASRESHIS_N.TRAN_CMF_16);
    sqlstm.sqhstl[57] = (unsigned int  )31;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MRASRESHIS_N.TRAN_CMF_17);
    sqlstm.sqhstl[58] = (unsigned int  )31;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MRASRESHIS_N.TRAN_CMF_18);
    sqlstm.sqhstl[59] = (unsigned int  )31;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MRASRESHIS_N.TRAN_CMF_19);
    sqlstm.sqhstl[60] = (unsigned int  )31;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MRASRESHIS_N.TRAN_CMF_20);
    sqlstm.sqhstl[61] = (unsigned int  )31;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MRASRESHIS_N.TRAN_USER_ID);
    sqlstm.sqhstl[62] = (unsigned int  )21;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MRASRESHIS_N.TRAN_COMMENT);
    sqlstm.sqhstl[63] = (unsigned int  )401;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MRASRESHIS_N.LAST_DOWN_TIME);
    sqlstm.sqhstl[64] = (unsigned int  )15;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)&(MRASRESHIS_N.LAST_DOWN_HIST_SEQ);
    sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)&(MRASRESHIS_N.HIST_START_SEQ);
    sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MRASRESHIS_N.HIST_DEL_FLAG);
    sqlstm.sqhstl[67] = (unsigned int  )2;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MRASRESHIS_N.HIST_DEL_TIME);
    sqlstm.sqhstl[68] = (unsigned int  )15;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MRASRESHIS_N.HIST_DEL_USER_ID);
    sqlstm.sqhstl[69] = (unsigned int  )21;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MRASRESHIS_N.HIST_DEL_COMMENT);
    sqlstm.sqhstl[70] = (unsigned int  )401;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_mrasreshis", 0);
}


/* SQL UPDATE Function */
void DBU_update_mrasreshis(int sel_type, struct MRASRESHIS_TAG *MRASRESHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESHIS_N_TAG MRASRESHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasreshis(&MRASRESHIS_N, MRASRESHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MRASRESHIS SET
                    EVENT_ID = :MRASRESHIS_N.EVENT_ID,
                    TRAN_TIME = :MRASRESHIS_N.TRAN_TIME,
                    SYS_TRAN_TIME = :MRASRESHIS_N.SYS_TRAN_TIME,
                    OLD_EVENT_ID = :MRASRESHIS_N.OLD_EVENT_ID,
                    OLD_HIST_SEQ = :MRASRESHIS_N.OLD_HIST_SEQ,
                    OLD_TRAN_TIME = :MRASRESHIS_N.OLD_TRAN_TIME,
                    OLD_SYS_TRAN_TIME = :MRASRESHIS_N.OLD_SYS_TRAN_TIME,
                    OLD_UP_DOWN_FLAG = :MRASRESHIS_N.OLD_UP_DOWN_FLAG,
                    OLD_PRI_STS = :MRASRESHIS_N.OLD_PRI_STS,
                    OLD_STS_1 = :MRASRESHIS_N.OLD_STS_1,
                    OLD_STS_2 = :MRASRESHIS_N.OLD_STS_2,
                    OLD_STS_3 = :MRASRESHIS_N.OLD_STS_3,
                    OLD_STS_4 = :MRASRESHIS_N.OLD_STS_4,
                    OLD_STS_5 = :MRASRESHIS_N.OLD_STS_5,
                    OLD_STS_6 = :MRASRESHIS_N.OLD_STS_6,
                    OLD_STS_7 = :MRASRESHIS_N.OLD_STS_7,
                    OLD_STS_8 = :MRASRESHIS_N.OLD_STS_8,
                    OLD_STS_9 = :MRASRESHIS_N.OLD_STS_9,
                    OLD_STS_10 = :MRASRESHIS_N.OLD_STS_10,
                    NEW_UP_DOWN_FLAG = :MRASRESHIS_N.NEW_UP_DOWN_FLAG,
                    NEW_PRI_STS = :MRASRESHIS_N.NEW_PRI_STS,
                    NEW_STS_1 = :MRASRESHIS_N.NEW_STS_1,
                    NEW_STS_2 = :MRASRESHIS_N.NEW_STS_2,
                    NEW_STS_3 = :MRASRESHIS_N.NEW_STS_3,
                    NEW_STS_4 = :MRASRESHIS_N.NEW_STS_4,
                    NEW_STS_5 = :MRASRESHIS_N.NEW_STS_5,
                    NEW_STS_6 = :MRASRESHIS_N.NEW_STS_6,
                    NEW_STS_7 = :MRASRESHIS_N.NEW_STS_7,
                    NEW_STS_8 = :MRASRESHIS_N.NEW_STS_8,
                    NEW_STS_9 = :MRASRESHIS_N.NEW_STS_9,
                    NEW_STS_10 = :MRASRESHIS_N.NEW_STS_10,
                    LOT_ID = :MRASRESHIS_N.LOT_ID,
                    SUBLOT_ID = :MRASRESHIS_N.SUBLOT_ID,
                    CRR_ID = :MRASRESHIS_N.CRR_ID,
                    RES_CTRL_MODE = :MRASRESHIS_N.RES_CTRL_MODE,
                    RES_PROC_MODE = :MRASRESHIS_N.RES_PROC_MODE,
                    LOT_EXIST_FLAG = :MRASRESHIS_N.LOT_EXIST_FLAG,
                    COL_SET_ID = :MRASRESHIS_N.COL_SET_ID,
                    COL_SET_VERSION = :MRASRESHIS_N.COL_SET_VERSION,
                    TRAN_CMF_1 = :MRASRESHIS_N.TRAN_CMF_1,
                    TRAN_CMF_2 = :MRASRESHIS_N.TRAN_CMF_2,
                    TRAN_CMF_3 = :MRASRESHIS_N.TRAN_CMF_3,
                    TRAN_CMF_4 = :MRASRESHIS_N.TRAN_CMF_4,
                    TRAN_CMF_5 = :MRASRESHIS_N.TRAN_CMF_5,
                    TRAN_CMF_6 = :MRASRESHIS_N.TRAN_CMF_6,
                    TRAN_CMF_7 = :MRASRESHIS_N.TRAN_CMF_7,
                    TRAN_CMF_8 = :MRASRESHIS_N.TRAN_CMF_8,
                    TRAN_CMF_9 = :MRASRESHIS_N.TRAN_CMF_9,
                    TRAN_CMF_10 = :MRASRESHIS_N.TRAN_CMF_10,
                    TRAN_CMF_11 = :MRASRESHIS_N.TRAN_CMF_11,
                    TRAN_CMF_12 = :MRASRESHIS_N.TRAN_CMF_12,
                    TRAN_CMF_13 = :MRASRESHIS_N.TRAN_CMF_13,
                    TRAN_CMF_14 = :MRASRESHIS_N.TRAN_CMF_14,
                    TRAN_CMF_15 = :MRASRESHIS_N.TRAN_CMF_15,
                    TRAN_CMF_16 = :MRASRESHIS_N.TRAN_CMF_16,
                    TRAN_CMF_17 = :MRASRESHIS_N.TRAN_CMF_17,
                    TRAN_CMF_18 = :MRASRESHIS_N.TRAN_CMF_18,
                    TRAN_CMF_19 = :MRASRESHIS_N.TRAN_CMF_19,
                    TRAN_CMF_20 = :MRASRESHIS_N.TRAN_CMF_20,
                    TRAN_USER_ID = :MRASRESHIS_N.TRAN_USER_ID,
                    TRAN_COMMENT = :MRASRESHIS_N.TRAN_COMMENT,
                    LAST_DOWN_TIME = :MRASRESHIS_N.LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ = :MRASRESHIS_N.LAST_DOWN_HIST_SEQ,
                    HIST_START_SEQ = :MRASRESHIS_N.HIST_START_SEQ,
                    HIST_DEL_FLAG = :MRASRESHIS_N.HIST_DEL_FLAG,
                    HIST_DEL_TIME = :MRASRESHIS_N.HIST_DEL_TIME,
                    HIST_DEL_USER_ID = :MRASRESHIS_N.HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT = :MRASRESHIS_N.HIST_DEL_COMMENT
                WHERE FACTORY = :MRASRESHIS_N.FACTORY
                    AND RES_ID = :MRASRESHIS_N.RES_ID
                    AND HIST_SEQ = :MRASRESHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MRASRESHIS  set EVENT_ID=:b0,TRAN_TIME=:b1,SYS_TRAN_TI\
ME=:b2,OLD_EVENT_ID=:b3,OLD_HIST_SEQ=:b4,OLD_TRAN_TIME=:b5,OLD_SYS_TRAN_TIME\
=:b6,OLD_UP_DOWN_FLAG=:b7,OLD_PRI_STS=:b8,OLD_STS_1=:b9,OLD_STS_2=:b10,OLD_S\
TS_3=:b11,OLD_STS_4=:b12,OLD_STS_5=:b13,OLD_STS_6=:b14,OLD_STS_7=:b15,OLD_ST\
S_8=:b16,OLD_STS_9=:b17,OLD_STS_10=:b18,NEW_UP_DOWN_FLAG=:b19,NEW_PRI_STS=:b\
20,NEW_STS_1=:b21,NEW_STS_2=:b22,NEW_STS_3=:b23,NEW_STS_4=:b24,NEW_STS_5=:b2\
5,NEW_STS_6=:b26,NEW_STS_7=:b27,NEW_STS_8=:b28,NEW_STS_9=:b29,NEW_STS_10=:b3\
0,LOT_ID=:b31,SUBLOT_ID=:b32,CRR_ID=:b33,RES_CTRL_MODE=:b34,RES_PROC_MODE=:b\
35,LOT_EXIST_FLAG=:b36,COL_SET_ID=:b37,COL_SET_VERSION=:b38,TRAN_CMF_1=:b39,\
TRAN_CMF_2=:b40,TRAN_CMF_3=:b41,TRAN_CMF_4=:b42,TRAN_CMF_5=:b43,TRAN_CMF_6=:\
b44,TRAN_CMF_7=:b45,TRAN_CMF_8=:b46,TRAN_CMF_9=:b47,TRAN_CMF_10=:b48,TRAN_CM\
F_11=:b49,TRAN_CMF_12=:b50,TRAN_CMF_13=:b51,TRAN_CMF_14=:b52,TRAN_CMF_15=:b5\
3,TRAN_CMF_16=:b54,TRAN_CMF_17=:b55,TRAN_CMF_18=:b56,TRAN_CMF_19=:b57,TRAN_C\
MF_20=:b58,TRAN_USER_ID=:b59,TRAN_COMMENT=:b60,LAST");
            sqlstm.stmt = "_DOWN_TIME=:b61,LAST_DOWN_HIST_SEQ=:b62,HIST_STA\
RT_SEQ=:b63,HIST_DEL_FLAG=:b64,HIST_DEL_TIME=:b65,HIST_DEL_USER_ID=:b66,HIST_\
DEL_COMMENT=:b67 where ((FACTORY=:b68 and RES_ID=:b69) and HIST_SEQ=:b70)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )984;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESHIS_N.EVENT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )13;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESHIS_N.TRAN_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESHIS_N.OLD_EVENT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )13;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MRASRESHIS_N.OLD_HIST_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESHIS_N.OLD_TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESHIS_N.OLD_SYS_TRAN_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASRESHIS_N.OLD_UP_DOWN_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESHIS_N.OLD_PRI_STS);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESHIS_N.OLD_STS_1);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESHIS_N.OLD_STS_2);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESHIS_N.OLD_STS_3);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESHIS_N.OLD_STS_4);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESHIS_N.OLD_STS_5);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESHIS_N.OLD_STS_6);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESHIS_N.OLD_STS_7);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESHIS_N.OLD_STS_8);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESHIS_N.OLD_STS_9);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESHIS_N.OLD_STS_10);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESHIS_N.NEW_UP_DOWN_FLAG);
            sqlstm.sqhstl[19] = (unsigned int  )2;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESHIS_N.NEW_PRI_STS);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESHIS_N.NEW_STS_1);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESHIS_N.NEW_STS_2);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESHIS_N.NEW_STS_3);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESHIS_N.NEW_STS_4);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESHIS_N.NEW_STS_5);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESHIS_N.NEW_STS_6);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESHIS_N.NEW_STS_7);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESHIS_N.NEW_STS_8);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESHIS_N.NEW_STS_9);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESHIS_N.NEW_STS_10);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESHIS_N.LOT_ID);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESHIS_N.CRR_ID);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESHIS_N.RES_CTRL_MODE);
            sqlstm.sqhstl[34] = (unsigned int  )3;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESHIS_N.RES_PROC_MODE);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESHIS_N.LOT_EXIST_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESHIS_N.COL_SET_ID);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MRASRESHIS_N.COL_SET_VERSION);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASRESHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASRESHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASRESHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[60] = (unsigned int  )401;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESHIS_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[61] = (unsigned int  )15;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(MRASRESHIS_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)&(MRASRESHIS_N.HIST_START_SEQ);
            sqlstm.sqhstl[63] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASRESHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[65] = (unsigned int  )15;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASRESHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[67] = (unsigned int  )401;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESHIS_N.FACTORY);
            sqlstm.sqhstl[68] = (unsigned int  )11;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESHIS_N.RES_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(MRASRESHIS_N.HIST_SEQ);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_mrasreshis", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_mrasreshis(int sel_type, struct MRASRESHIS_TAG *MRASRESHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESHIS_N_TAG MRASRESHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasreshis(&MRASRESHIS_N, MRASRESHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_MRASRESHIS_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    RES_ID,
                    HIST_SEQ,
                    EVENT_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    OLD_EVENT_ID,
                    OLD_HIST_SEQ,
                    OLD_TRAN_TIME,
                    OLD_SYS_TRAN_TIME,
                    OLD_UP_DOWN_FLAG,
                    OLD_PRI_STS,
                    OLD_STS_1,
                    OLD_STS_2,
                    OLD_STS_3,
                    OLD_STS_4,
                    OLD_STS_5,
                    OLD_STS_6,
                    OLD_STS_7,
                    OLD_STS_8,
                    OLD_STS_9,
                    OLD_STS_10,
                    NEW_UP_DOWN_FLAG,
                    NEW_PRI_STS,
                    NEW_STS_1,
                    NEW_STS_2,
                    NEW_STS_3,
                    NEW_STS_4,
                    NEW_STS_5,
                    NEW_STS_6,
                    NEW_STS_7,
                    NEW_STS_8,
                    NEW_STS_9,
                    NEW_STS_10,
                    LOT_ID,
                    SUBLOT_ID,
                    CRR_ID,
                    RES_CTRL_MODE,
                    RES_PROC_MODE,
                    LOT_EXIST_FLAG,
                    COL_SET_ID,
                    COL_SET_VERSION,
                    TRAN_CMF_1,
                    TRAN_CMF_2,
                    TRAN_CMF_3,
                    TRAN_CMF_4,
                    TRAN_CMF_5,
                    TRAN_CMF_6,
                    TRAN_CMF_7,
                    TRAN_CMF_8,
                    TRAN_CMF_9,
                    TRAN_CMF_10,
                    TRAN_CMF_11,
                    TRAN_CMF_12,
                    TRAN_CMF_13,
                    TRAN_CMF_14,
                    TRAN_CMF_15,
                    TRAN_CMF_16,
                    TRAN_CMF_17,
                    TRAN_CMF_18,
                    TRAN_CMF_19,
                    TRAN_CMF_20,
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ,
                    HIST_START_SEQ,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                FROM MRASRESHIS
                ORDER BY FACTORY ASC,
                    RES_ID ASC,
                    HIST_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_MRASRESHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1283;
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

    DB_stop_query_timer("DBU_open_mrasreshis", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_mrasreshis(int sel_type, struct MRASRESHIS_TAG *MRASRESHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESHIS_N_TAG MRASRESHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_MRASRESHIS_CUR_1 INTO
                :MRASRESHIS_N.FACTORY,
                :MRASRESHIS_N.RES_ID,
                :MRASRESHIS_N.HIST_SEQ,
                :MRASRESHIS_N.EVENT_ID,
                :MRASRESHIS_N.TRAN_TIME,
                :MRASRESHIS_N.SYS_TRAN_TIME,
                :MRASRESHIS_N.OLD_EVENT_ID,
                :MRASRESHIS_N.OLD_HIST_SEQ,
                :MRASRESHIS_N.OLD_TRAN_TIME,
                :MRASRESHIS_N.OLD_SYS_TRAN_TIME,
                :MRASRESHIS_N.OLD_UP_DOWN_FLAG,
                :MRASRESHIS_N.OLD_PRI_STS,
                :MRASRESHIS_N.OLD_STS_1,
                :MRASRESHIS_N.OLD_STS_2,
                :MRASRESHIS_N.OLD_STS_3,
                :MRASRESHIS_N.OLD_STS_4,
                :MRASRESHIS_N.OLD_STS_5,
                :MRASRESHIS_N.OLD_STS_6,
                :MRASRESHIS_N.OLD_STS_7,
                :MRASRESHIS_N.OLD_STS_8,
                :MRASRESHIS_N.OLD_STS_9,
                :MRASRESHIS_N.OLD_STS_10,
                :MRASRESHIS_N.NEW_UP_DOWN_FLAG,
                :MRASRESHIS_N.NEW_PRI_STS,
                :MRASRESHIS_N.NEW_STS_1,
                :MRASRESHIS_N.NEW_STS_2,
                :MRASRESHIS_N.NEW_STS_3,
                :MRASRESHIS_N.NEW_STS_4,
                :MRASRESHIS_N.NEW_STS_5,
                :MRASRESHIS_N.NEW_STS_6,
                :MRASRESHIS_N.NEW_STS_7,
                :MRASRESHIS_N.NEW_STS_8,
                :MRASRESHIS_N.NEW_STS_9,
                :MRASRESHIS_N.NEW_STS_10,
                :MRASRESHIS_N.LOT_ID,
                :MRASRESHIS_N.SUBLOT_ID,
                :MRASRESHIS_N.CRR_ID,
                :MRASRESHIS_N.RES_CTRL_MODE,
                :MRASRESHIS_N.RES_PROC_MODE,
                :MRASRESHIS_N.LOT_EXIST_FLAG,
                :MRASRESHIS_N.COL_SET_ID,
                :MRASRESHIS_N.COL_SET_VERSION,
                :MRASRESHIS_N.TRAN_CMF_1,
                :MRASRESHIS_N.TRAN_CMF_2,
                :MRASRESHIS_N.TRAN_CMF_3,
                :MRASRESHIS_N.TRAN_CMF_4,
                :MRASRESHIS_N.TRAN_CMF_5,
                :MRASRESHIS_N.TRAN_CMF_6,
                :MRASRESHIS_N.TRAN_CMF_7,
                :MRASRESHIS_N.TRAN_CMF_8,
                :MRASRESHIS_N.TRAN_CMF_9,
                :MRASRESHIS_N.TRAN_CMF_10,
                :MRASRESHIS_N.TRAN_CMF_11,
                :MRASRESHIS_N.TRAN_CMF_12,
                :MRASRESHIS_N.TRAN_CMF_13,
                :MRASRESHIS_N.TRAN_CMF_14,
                :MRASRESHIS_N.TRAN_CMF_15,
                :MRASRESHIS_N.TRAN_CMF_16,
                :MRASRESHIS_N.TRAN_CMF_17,
                :MRASRESHIS_N.TRAN_CMF_18,
                :MRASRESHIS_N.TRAN_CMF_19,
                :MRASRESHIS_N.TRAN_CMF_20,
                :MRASRESHIS_N.TRAN_USER_ID,
                :MRASRESHIS_N.TRAN_COMMENT,
                :MRASRESHIS_N.LAST_DOWN_TIME,
                :MRASRESHIS_N.LAST_DOWN_HIST_SEQ,
                :MRASRESHIS_N.HIST_START_SEQ,
                :MRASRESHIS_N.HIST_DEL_FLAG,
                :MRASRESHIS_N.HIST_DEL_TIME,
                :MRASRESHIS_N.HIST_DEL_USER_ID,
                :MRASRESHIS_N.HIST_DEL_COMMENT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1298;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESHIS_N.RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MRASRESHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESHIS_N.EVENT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )13;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESHIS_N.TRAN_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESHIS_N.OLD_EVENT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )13;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MRASRESHIS_N.OLD_HIST_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESHIS_N.OLD_TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESHIS_N.OLD_SYS_TRAN_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESHIS_N.OLD_UP_DOWN_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESHIS_N.OLD_PRI_STS);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESHIS_N.OLD_STS_1);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESHIS_N.OLD_STS_2);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESHIS_N.OLD_STS_3);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESHIS_N.OLD_STS_4);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESHIS_N.OLD_STS_5);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESHIS_N.OLD_STS_6);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESHIS_N.OLD_STS_7);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESHIS_N.OLD_STS_8);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESHIS_N.OLD_STS_9);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESHIS_N.OLD_STS_10);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESHIS_N.NEW_UP_DOWN_FLAG);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESHIS_N.NEW_PRI_STS);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESHIS_N.NEW_STS_1);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESHIS_N.NEW_STS_2);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESHIS_N.NEW_STS_3);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESHIS_N.NEW_STS_4);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESHIS_N.NEW_STS_5);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESHIS_N.NEW_STS_6);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESHIS_N.NEW_STS_7);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESHIS_N.NEW_STS_8);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESHIS_N.NEW_STS_9);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESHIS_N.NEW_STS_10);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESHIS_N.LOT_ID);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESHIS_N.CRR_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESHIS_N.RES_CTRL_MODE);
            sqlstm.sqhstl[37] = (unsigned int  )3;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASRESHIS_N.RES_PROC_MODE);
            sqlstm.sqhstl[38] = (unsigned int  )11;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESHIS_N.LOT_EXIST_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESHIS_N.COL_SET_ID);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(MRASRESHIS_N.COL_SET_VERSION);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASRESHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASRESHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASRESHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASRESHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[63] = (unsigned int  )401;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESHIS_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MRASRESHIS_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MRASRESHIS_N.HIST_START_SEQ);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASRESHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[70] = (unsigned int  )401;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
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
        DBU_del_null_mrasreshis(&MRASRESHIS_N, MRASRESHIS);
    }

    DB_stop_query_timer("DBU_fetch_mrasreshis", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_mrasreshis(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_MRASRESHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1597;
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

    DB_stop_query_timer("DBU_close_mrasreshis", sel_type);
}


/* Initialize Function */
void DBU_init_mrasreshis(struct MRASRESHIS_TAG *MRASRESHIS)
{
    /* memset by Space */
    memset(MRASRESHIS, ' ', sizeof(struct MRASRESHIS_TAG));
    
    MRASRESHIS->HIST_SEQ = 0;
    MRASRESHIS->OLD_HIST_SEQ = 0;
    MRASRESHIS->COL_SET_VERSION = 0;
    MRASRESHIS->LAST_DOWN_HIST_SEQ = 0;
    MRASRESHIS->HIST_START_SEQ = 0;
}


/* Add Null Function */
void DBU_add_null_mrasreshis(struct MRASRESHIS_N_TAG *MRASRESHIS_N, struct MRASRESHIS_TAG *MRASRESHIS)
{
    /* memset by NULL */
    memset(MRASRESHIS_N, '\0', sizeof(struct MRASRESHIS_N_TAG));
    
    MEMCPY_AN(MRASRESHIS_N->FACTORY, MRASRESHIS->FACTORY, sizeof(MRASRESHIS->FACTORY));
    MEMCPY_AN(MRASRESHIS_N->RES_ID, MRASRESHIS->RES_ID, sizeof(MRASRESHIS->RES_ID));
    MRASRESHIS_N->HIST_SEQ = MRASRESHIS->HIST_SEQ;
    MEMCPY_AN(MRASRESHIS_N->EVENT_ID, MRASRESHIS->EVENT_ID, sizeof(MRASRESHIS->EVENT_ID));
    MEMCPY_AN(MRASRESHIS_N->TRAN_TIME, MRASRESHIS->TRAN_TIME, sizeof(MRASRESHIS->TRAN_TIME));
    MEMCPY_AN(MRASRESHIS_N->SYS_TRAN_TIME, MRASRESHIS->SYS_TRAN_TIME, sizeof(MRASRESHIS->SYS_TRAN_TIME));
    MEMCPY_AN(MRASRESHIS_N->OLD_EVENT_ID, MRASRESHIS->OLD_EVENT_ID, sizeof(MRASRESHIS->OLD_EVENT_ID));
    MRASRESHIS_N->OLD_HIST_SEQ = MRASRESHIS->OLD_HIST_SEQ;
    MEMCPY_AN(MRASRESHIS_N->OLD_TRAN_TIME, MRASRESHIS->OLD_TRAN_TIME, sizeof(MRASRESHIS->OLD_TRAN_TIME));
    MEMCPY_AN(MRASRESHIS_N->OLD_SYS_TRAN_TIME, MRASRESHIS->OLD_SYS_TRAN_TIME, sizeof(MRASRESHIS->OLD_SYS_TRAN_TIME));
    MRASRESHIS_N->OLD_UP_DOWN_FLAG[0] = MRASRESHIS->OLD_UP_DOWN_FLAG;
    MEMCPY_AN(MRASRESHIS_N->OLD_PRI_STS, MRASRESHIS->OLD_PRI_STS, sizeof(MRASRESHIS->OLD_PRI_STS));
    MEMCPY_AN(MRASRESHIS_N->OLD_STS_1, MRASRESHIS->OLD_STS_1, sizeof(MRASRESHIS->OLD_STS_1));
    MEMCPY_AN(MRASRESHIS_N->OLD_STS_2, MRASRESHIS->OLD_STS_2, sizeof(MRASRESHIS->OLD_STS_2));
    MEMCPY_AN(MRASRESHIS_N->OLD_STS_3, MRASRESHIS->OLD_STS_3, sizeof(MRASRESHIS->OLD_STS_3));
    MEMCPY_AN(MRASRESHIS_N->OLD_STS_4, MRASRESHIS->OLD_STS_4, sizeof(MRASRESHIS->OLD_STS_4));
    MEMCPY_AN(MRASRESHIS_N->OLD_STS_5, MRASRESHIS->OLD_STS_5, sizeof(MRASRESHIS->OLD_STS_5));
    MEMCPY_AN(MRASRESHIS_N->OLD_STS_6, MRASRESHIS->OLD_STS_6, sizeof(MRASRESHIS->OLD_STS_6));
    MEMCPY_AN(MRASRESHIS_N->OLD_STS_7, MRASRESHIS->OLD_STS_7, sizeof(MRASRESHIS->OLD_STS_7));
    MEMCPY_AN(MRASRESHIS_N->OLD_STS_8, MRASRESHIS->OLD_STS_8, sizeof(MRASRESHIS->OLD_STS_8));
    MEMCPY_AN(MRASRESHIS_N->OLD_STS_9, MRASRESHIS->OLD_STS_9, sizeof(MRASRESHIS->OLD_STS_9));
    MEMCPY_AN(MRASRESHIS_N->OLD_STS_10, MRASRESHIS->OLD_STS_10, sizeof(MRASRESHIS->OLD_STS_10));
    MRASRESHIS_N->NEW_UP_DOWN_FLAG[0] = MRASRESHIS->NEW_UP_DOWN_FLAG;
    MEMCPY_AN(MRASRESHIS_N->NEW_PRI_STS, MRASRESHIS->NEW_PRI_STS, sizeof(MRASRESHIS->NEW_PRI_STS));
    MEMCPY_AN(MRASRESHIS_N->NEW_STS_1, MRASRESHIS->NEW_STS_1, sizeof(MRASRESHIS->NEW_STS_1));
    MEMCPY_AN(MRASRESHIS_N->NEW_STS_2, MRASRESHIS->NEW_STS_2, sizeof(MRASRESHIS->NEW_STS_2));
    MEMCPY_AN(MRASRESHIS_N->NEW_STS_3, MRASRESHIS->NEW_STS_3, sizeof(MRASRESHIS->NEW_STS_3));
    MEMCPY_AN(MRASRESHIS_N->NEW_STS_4, MRASRESHIS->NEW_STS_4, sizeof(MRASRESHIS->NEW_STS_4));
    MEMCPY_AN(MRASRESHIS_N->NEW_STS_5, MRASRESHIS->NEW_STS_5, sizeof(MRASRESHIS->NEW_STS_5));
    MEMCPY_AN(MRASRESHIS_N->NEW_STS_6, MRASRESHIS->NEW_STS_6, sizeof(MRASRESHIS->NEW_STS_6));
    MEMCPY_AN(MRASRESHIS_N->NEW_STS_7, MRASRESHIS->NEW_STS_7, sizeof(MRASRESHIS->NEW_STS_7));
    MEMCPY_AN(MRASRESHIS_N->NEW_STS_8, MRASRESHIS->NEW_STS_8, sizeof(MRASRESHIS->NEW_STS_8));
    MEMCPY_AN(MRASRESHIS_N->NEW_STS_9, MRASRESHIS->NEW_STS_9, sizeof(MRASRESHIS->NEW_STS_9));
    MEMCPY_AN(MRASRESHIS_N->NEW_STS_10, MRASRESHIS->NEW_STS_10, sizeof(MRASRESHIS->NEW_STS_10));
    MEMCPY_AN(MRASRESHIS_N->LOT_ID, MRASRESHIS->LOT_ID, sizeof(MRASRESHIS->LOT_ID));
    MEMCPY_AN(MRASRESHIS_N->SUBLOT_ID, MRASRESHIS->SUBLOT_ID, sizeof(MRASRESHIS->SUBLOT_ID));
    MEMCPY_AN(MRASRESHIS_N->CRR_ID, MRASRESHIS->CRR_ID, sizeof(MRASRESHIS->CRR_ID));
    MEMCPY_AN(MRASRESHIS_N->RES_CTRL_MODE, MRASRESHIS->RES_CTRL_MODE, sizeof(MRASRESHIS->RES_CTRL_MODE));
    MEMCPY_AN(MRASRESHIS_N->RES_PROC_MODE, MRASRESHIS->RES_PROC_MODE, sizeof(MRASRESHIS->RES_PROC_MODE));
    MRASRESHIS_N->LOT_EXIST_FLAG[0] = MRASRESHIS->LOT_EXIST_FLAG;
    MEMCPY_AN(MRASRESHIS_N->COL_SET_ID, MRASRESHIS->COL_SET_ID, sizeof(MRASRESHIS->COL_SET_ID));
    MRASRESHIS_N->COL_SET_VERSION = MRASRESHIS->COL_SET_VERSION;
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_1, MRASRESHIS->TRAN_CMF_1, sizeof(MRASRESHIS->TRAN_CMF_1));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_2, MRASRESHIS->TRAN_CMF_2, sizeof(MRASRESHIS->TRAN_CMF_2));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_3, MRASRESHIS->TRAN_CMF_3, sizeof(MRASRESHIS->TRAN_CMF_3));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_4, MRASRESHIS->TRAN_CMF_4, sizeof(MRASRESHIS->TRAN_CMF_4));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_5, MRASRESHIS->TRAN_CMF_5, sizeof(MRASRESHIS->TRAN_CMF_5));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_6, MRASRESHIS->TRAN_CMF_6, sizeof(MRASRESHIS->TRAN_CMF_6));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_7, MRASRESHIS->TRAN_CMF_7, sizeof(MRASRESHIS->TRAN_CMF_7));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_8, MRASRESHIS->TRAN_CMF_8, sizeof(MRASRESHIS->TRAN_CMF_8));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_9, MRASRESHIS->TRAN_CMF_9, sizeof(MRASRESHIS->TRAN_CMF_9));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_10, MRASRESHIS->TRAN_CMF_10, sizeof(MRASRESHIS->TRAN_CMF_10));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_11, MRASRESHIS->TRAN_CMF_11, sizeof(MRASRESHIS->TRAN_CMF_11));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_12, MRASRESHIS->TRAN_CMF_12, sizeof(MRASRESHIS->TRAN_CMF_12));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_13, MRASRESHIS->TRAN_CMF_13, sizeof(MRASRESHIS->TRAN_CMF_13));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_14, MRASRESHIS->TRAN_CMF_14, sizeof(MRASRESHIS->TRAN_CMF_14));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_15, MRASRESHIS->TRAN_CMF_15, sizeof(MRASRESHIS->TRAN_CMF_15));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_16, MRASRESHIS->TRAN_CMF_16, sizeof(MRASRESHIS->TRAN_CMF_16));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_17, MRASRESHIS->TRAN_CMF_17, sizeof(MRASRESHIS->TRAN_CMF_17));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_18, MRASRESHIS->TRAN_CMF_18, sizeof(MRASRESHIS->TRAN_CMF_18));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_19, MRASRESHIS->TRAN_CMF_19, sizeof(MRASRESHIS->TRAN_CMF_19));
    MEMCPY_AN(MRASRESHIS_N->TRAN_CMF_20, MRASRESHIS->TRAN_CMF_20, sizeof(MRASRESHIS->TRAN_CMF_20));
    MEMCPY_AN(MRASRESHIS_N->TRAN_USER_ID, MRASRESHIS->TRAN_USER_ID, sizeof(MRASRESHIS->TRAN_USER_ID));
    MEMCPY_AN(MRASRESHIS_N->TRAN_COMMENT, MRASRESHIS->TRAN_COMMENT, sizeof(MRASRESHIS->TRAN_COMMENT));
    MEMCPY_AN(MRASRESHIS_N->LAST_DOWN_TIME, MRASRESHIS->LAST_DOWN_TIME, sizeof(MRASRESHIS->LAST_DOWN_TIME));
    MRASRESHIS_N->LAST_DOWN_HIST_SEQ = MRASRESHIS->LAST_DOWN_HIST_SEQ;
    MRASRESHIS_N->HIST_START_SEQ = MRASRESHIS->HIST_START_SEQ;
    MRASRESHIS_N->HIST_DEL_FLAG[0] = MRASRESHIS->HIST_DEL_FLAG;
    MEMCPY_AN(MRASRESHIS_N->HIST_DEL_TIME, MRASRESHIS->HIST_DEL_TIME, sizeof(MRASRESHIS->HIST_DEL_TIME));
    MEMCPY_AN(MRASRESHIS_N->HIST_DEL_USER_ID, MRASRESHIS->HIST_DEL_USER_ID, sizeof(MRASRESHIS->HIST_DEL_USER_ID));
    MEMCPY_AN(MRASRESHIS_N->HIST_DEL_COMMENT, MRASRESHIS->HIST_DEL_COMMENT, sizeof(MRASRESHIS->HIST_DEL_COMMENT));
}


/* Del Null Function */
void DBU_del_null_mrasreshis(struct MRASRESHIS_N_TAG *MRASRESHIS_N, struct MRASRESHIS_TAG *MRASRESHIS)
{
    MEMCPY_DN(MRASRESHIS->FACTORY, MRASRESHIS_N->FACTORY, sizeof(MRASRESHIS->FACTORY));
    MEMCPY_DN(MRASRESHIS->RES_ID, MRASRESHIS_N->RES_ID, sizeof(MRASRESHIS->RES_ID));
    MRASRESHIS->HIST_SEQ = MRASRESHIS_N->HIST_SEQ;
    MEMCPY_DN(MRASRESHIS->EVENT_ID, MRASRESHIS_N->EVENT_ID, sizeof(MRASRESHIS->EVENT_ID));
    MEMCPY_DN(MRASRESHIS->TRAN_TIME, MRASRESHIS_N->TRAN_TIME, sizeof(MRASRESHIS->TRAN_TIME));
    MEMCPY_DN(MRASRESHIS->SYS_TRAN_TIME, MRASRESHIS_N->SYS_TRAN_TIME, sizeof(MRASRESHIS->SYS_TRAN_TIME));
    MEMCPY_DN(MRASRESHIS->OLD_EVENT_ID, MRASRESHIS_N->OLD_EVENT_ID, sizeof(MRASRESHIS->OLD_EVENT_ID));
    MRASRESHIS->OLD_HIST_SEQ = MRASRESHIS_N->OLD_HIST_SEQ;
    MEMCPY_DN(MRASRESHIS->OLD_TRAN_TIME, MRASRESHIS_N->OLD_TRAN_TIME, sizeof(MRASRESHIS->OLD_TRAN_TIME));
    MEMCPY_DN(MRASRESHIS->OLD_SYS_TRAN_TIME, MRASRESHIS_N->OLD_SYS_TRAN_TIME, sizeof(MRASRESHIS->OLD_SYS_TRAN_TIME));
    MRASRESHIS->OLD_UP_DOWN_FLAG = MRASRESHIS_N->OLD_UP_DOWN_FLAG[0];
    MEMCPY_DN(MRASRESHIS->OLD_PRI_STS, MRASRESHIS_N->OLD_PRI_STS, sizeof(MRASRESHIS->OLD_PRI_STS));
    MEMCPY_DN(MRASRESHIS->OLD_STS_1, MRASRESHIS_N->OLD_STS_1, sizeof(MRASRESHIS->OLD_STS_1));
    MEMCPY_DN(MRASRESHIS->OLD_STS_2, MRASRESHIS_N->OLD_STS_2, sizeof(MRASRESHIS->OLD_STS_2));
    MEMCPY_DN(MRASRESHIS->OLD_STS_3, MRASRESHIS_N->OLD_STS_3, sizeof(MRASRESHIS->OLD_STS_3));
    MEMCPY_DN(MRASRESHIS->OLD_STS_4, MRASRESHIS_N->OLD_STS_4, sizeof(MRASRESHIS->OLD_STS_4));
    MEMCPY_DN(MRASRESHIS->OLD_STS_5, MRASRESHIS_N->OLD_STS_5, sizeof(MRASRESHIS->OLD_STS_5));
    MEMCPY_DN(MRASRESHIS->OLD_STS_6, MRASRESHIS_N->OLD_STS_6, sizeof(MRASRESHIS->OLD_STS_6));
    MEMCPY_DN(MRASRESHIS->OLD_STS_7, MRASRESHIS_N->OLD_STS_7, sizeof(MRASRESHIS->OLD_STS_7));
    MEMCPY_DN(MRASRESHIS->OLD_STS_8, MRASRESHIS_N->OLD_STS_8, sizeof(MRASRESHIS->OLD_STS_8));
    MEMCPY_DN(MRASRESHIS->OLD_STS_9, MRASRESHIS_N->OLD_STS_9, sizeof(MRASRESHIS->OLD_STS_9));
    MEMCPY_DN(MRASRESHIS->OLD_STS_10, MRASRESHIS_N->OLD_STS_10, sizeof(MRASRESHIS->OLD_STS_10));
    MRASRESHIS->NEW_UP_DOWN_FLAG = MRASRESHIS_N->NEW_UP_DOWN_FLAG[0];
    MEMCPY_DN(MRASRESHIS->NEW_PRI_STS, MRASRESHIS_N->NEW_PRI_STS, sizeof(MRASRESHIS->NEW_PRI_STS));
    MEMCPY_DN(MRASRESHIS->NEW_STS_1, MRASRESHIS_N->NEW_STS_1, sizeof(MRASRESHIS->NEW_STS_1));
    MEMCPY_DN(MRASRESHIS->NEW_STS_2, MRASRESHIS_N->NEW_STS_2, sizeof(MRASRESHIS->NEW_STS_2));
    MEMCPY_DN(MRASRESHIS->NEW_STS_3, MRASRESHIS_N->NEW_STS_3, sizeof(MRASRESHIS->NEW_STS_3));
    MEMCPY_DN(MRASRESHIS->NEW_STS_4, MRASRESHIS_N->NEW_STS_4, sizeof(MRASRESHIS->NEW_STS_4));
    MEMCPY_DN(MRASRESHIS->NEW_STS_5, MRASRESHIS_N->NEW_STS_5, sizeof(MRASRESHIS->NEW_STS_5));
    MEMCPY_DN(MRASRESHIS->NEW_STS_6, MRASRESHIS_N->NEW_STS_6, sizeof(MRASRESHIS->NEW_STS_6));
    MEMCPY_DN(MRASRESHIS->NEW_STS_7, MRASRESHIS_N->NEW_STS_7, sizeof(MRASRESHIS->NEW_STS_7));
    MEMCPY_DN(MRASRESHIS->NEW_STS_8, MRASRESHIS_N->NEW_STS_8, sizeof(MRASRESHIS->NEW_STS_8));
    MEMCPY_DN(MRASRESHIS->NEW_STS_9, MRASRESHIS_N->NEW_STS_9, sizeof(MRASRESHIS->NEW_STS_9));
    MEMCPY_DN(MRASRESHIS->NEW_STS_10, MRASRESHIS_N->NEW_STS_10, sizeof(MRASRESHIS->NEW_STS_10));
    MEMCPY_DN(MRASRESHIS->LOT_ID, MRASRESHIS_N->LOT_ID, sizeof(MRASRESHIS->LOT_ID));
    MEMCPY_DN(MRASRESHIS->SUBLOT_ID, MRASRESHIS_N->SUBLOT_ID, sizeof(MRASRESHIS->SUBLOT_ID));
    MEMCPY_DN(MRASRESHIS->CRR_ID, MRASRESHIS_N->CRR_ID, sizeof(MRASRESHIS->CRR_ID));
    MEMCPY_DN(MRASRESHIS->RES_CTRL_MODE, MRASRESHIS_N->RES_CTRL_MODE, sizeof(MRASRESHIS->RES_CTRL_MODE));
    MEMCPY_DN(MRASRESHIS->RES_PROC_MODE, MRASRESHIS_N->RES_PROC_MODE, sizeof(MRASRESHIS->RES_PROC_MODE));
    MRASRESHIS->LOT_EXIST_FLAG = MRASRESHIS_N->LOT_EXIST_FLAG[0];
    MEMCPY_DN(MRASRESHIS->COL_SET_ID, MRASRESHIS_N->COL_SET_ID, sizeof(MRASRESHIS->COL_SET_ID));
    MRASRESHIS->COL_SET_VERSION = MRASRESHIS_N->COL_SET_VERSION;
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_1, MRASRESHIS_N->TRAN_CMF_1, sizeof(MRASRESHIS->TRAN_CMF_1));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_2, MRASRESHIS_N->TRAN_CMF_2, sizeof(MRASRESHIS->TRAN_CMF_2));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_3, MRASRESHIS_N->TRAN_CMF_3, sizeof(MRASRESHIS->TRAN_CMF_3));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_4, MRASRESHIS_N->TRAN_CMF_4, sizeof(MRASRESHIS->TRAN_CMF_4));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_5, MRASRESHIS_N->TRAN_CMF_5, sizeof(MRASRESHIS->TRAN_CMF_5));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_6, MRASRESHIS_N->TRAN_CMF_6, sizeof(MRASRESHIS->TRAN_CMF_6));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_7, MRASRESHIS_N->TRAN_CMF_7, sizeof(MRASRESHIS->TRAN_CMF_7));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_8, MRASRESHIS_N->TRAN_CMF_8, sizeof(MRASRESHIS->TRAN_CMF_8));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_9, MRASRESHIS_N->TRAN_CMF_9, sizeof(MRASRESHIS->TRAN_CMF_9));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_10, MRASRESHIS_N->TRAN_CMF_10, sizeof(MRASRESHIS->TRAN_CMF_10));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_11, MRASRESHIS_N->TRAN_CMF_11, sizeof(MRASRESHIS->TRAN_CMF_11));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_12, MRASRESHIS_N->TRAN_CMF_12, sizeof(MRASRESHIS->TRAN_CMF_12));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_13, MRASRESHIS_N->TRAN_CMF_13, sizeof(MRASRESHIS->TRAN_CMF_13));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_14, MRASRESHIS_N->TRAN_CMF_14, sizeof(MRASRESHIS->TRAN_CMF_14));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_15, MRASRESHIS_N->TRAN_CMF_15, sizeof(MRASRESHIS->TRAN_CMF_15));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_16, MRASRESHIS_N->TRAN_CMF_16, sizeof(MRASRESHIS->TRAN_CMF_16));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_17, MRASRESHIS_N->TRAN_CMF_17, sizeof(MRASRESHIS->TRAN_CMF_17));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_18, MRASRESHIS_N->TRAN_CMF_18, sizeof(MRASRESHIS->TRAN_CMF_18));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_19, MRASRESHIS_N->TRAN_CMF_19, sizeof(MRASRESHIS->TRAN_CMF_19));
    MEMCPY_DN(MRASRESHIS->TRAN_CMF_20, MRASRESHIS_N->TRAN_CMF_20, sizeof(MRASRESHIS->TRAN_CMF_20));
    MEMCPY_DN(MRASRESHIS->TRAN_USER_ID, MRASRESHIS_N->TRAN_USER_ID, sizeof(MRASRESHIS->TRAN_USER_ID));
    MEMCPY_DN(MRASRESHIS->TRAN_COMMENT, MRASRESHIS_N->TRAN_COMMENT, sizeof(MRASRESHIS->TRAN_COMMENT));
    MEMCPY_DN(MRASRESHIS->LAST_DOWN_TIME, MRASRESHIS_N->LAST_DOWN_TIME, sizeof(MRASRESHIS->LAST_DOWN_TIME));
    MRASRESHIS->LAST_DOWN_HIST_SEQ = MRASRESHIS_N->LAST_DOWN_HIST_SEQ;
    MRASRESHIS->HIST_START_SEQ = MRASRESHIS_N->HIST_START_SEQ;
    MRASRESHIS->HIST_DEL_FLAG = MRASRESHIS_N->HIST_DEL_FLAG[0];
    MEMCPY_DN(MRASRESHIS->HIST_DEL_TIME, MRASRESHIS_N->HIST_DEL_TIME, sizeof(MRASRESHIS->HIST_DEL_TIME));
    MEMCPY_DN(MRASRESHIS->HIST_DEL_USER_ID, MRASRESHIS_N->HIST_DEL_USER_ID, sizeof(MRASRESHIS->HIST_DEL_USER_ID));
    MEMCPY_DN(MRASRESHIS->HIST_DEL_COMMENT, MRASRESHIS_N->HIST_DEL_COMMENT, sizeof(MRASRESHIS->HIST_DEL_COMMENT));
}


