
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
    "DBU_cqcmrptctm.pc"
};


static unsigned int sqlctx = 9379491;


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
            void  *sqhstv[62];
   unsigned int   sqhstl[62];
            int   sqhsts[62];
            void  *sqindv[62];
            int   sqinds[62];
   unsigned int   sqharm[62];
   unsigned int   *sqharc[62];
   unsigned short  sqadto[62];
   unsigned short  sqtdso[62];
} sqlstm = {13,62};

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
") ,NVL(RPT_CMF_14,' ') ,NVL(RPT_CMF_\
15,' ') ,NVL(FIT_STANDARD,' ') ,NVL(FIT_SPEC,' ') ,NVL(FIT_MIN_VAL,' ') ,NVL(\
FIT_MAX_VAL,' ')  from CQCMRPTCTM  order by FACTORY asc ,REPORT_NO asc ,PACK_\
LOT_ID asc ,ORG_LOT_ID asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1526,0,4,46,0,0,60,4,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,
260,0,0,2,1624,0,4,168,0,0,62,6,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
523,0,0,3,1538,0,4,327,0,0,60,4,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,
778,0,0,4,123,0,4,485,0,0,5,4,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,
813,0,0,5,80,0,4,495,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
840,0,0,6,105,0,2,532,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
871,0,0,7,62,0,2,540,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
894,0,0,8,927,0,3,570,0,0,56,56,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1133,0,0,9,940,0,5,707,0,0,56,56,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1372,0,0,10,1253,0,9,857,0,0,0,0,0,1,0,
1387,0,0,10,0,0,13,886,0,0,56,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1626,0,0,10,0,0,15,972,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cqcmrptctm.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-10-30 15:23:11
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
void DBU_add_null_cqcmrptctm(struct CQCMRPTCTM_N_TAG *CQCMRPTCTM_N, struct CQCMRPTCTM_TAG *CQCMRPTCTM);
void DBU_del_null_cqcmrptctm(struct CQCMRPTCTM_N_TAG *CQCMRPTCTM_N, struct CQCMRPTCTM_TAG *CQCMRPTCTM);


/* SQL SELECT Function */
void DBU_select_cqcmrptctm(int sel_type, struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTCTM_N_TAG CQCMRPTCTM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptctm(&CQCMRPTCTM_N, CQCMRPTCTM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    REPORT_NO,
                    PACK_LOT_ID,
                    ORG_LOT_ID,
                    NVL(GRADE, ' '),
                    NVL(TYPES, ' '),
                    NVL(PACK_ORDER_ID, ' '),
                    NVL(CUSTOMER_ID, ' '),
                    NVL(OD_STANDARD, ' '),
                    NVL(OD_SPEC, ' '),
                    NVL(OD_MIN_VAL, ' '),
                    NVL(OD_MAX_VAL, ' '),
                    NVL(AT_STANDARD, ' '),
                    NVL(AT_SPEC, ' '),
                    NVL(AT_MIN_VAL, ' '),
                    NVL(AT_MAX_VAL, ' '),
                    NVL(GT_STANDARD, ' '),
                    NVL(GT_SPEC, ' '),
                    NVL(GT_MIN_VAL, ' '),
                    NVL(GT_MAX_VAL, ' '),
                    NVL(LEN01_STANDARD, ' '),
                    NVL(LEN01_SPEC, ' '),
                    NVL(LEN_MIN_VAL01, ' '),
                    NVL(LEN_MAX_VAL01, ' '),
                    NVL(LEN02_STANDARD, ' '),
                    NVL(LEN02_SPEC, ' '),
                    NVL(LEN_MIN_VAL02, ' '),
                    NVL(LEN_MAX_VAL02, ' '),
                    NVL(DMG_STANDARD, ' '),
                    NVL(DMG_SPEC, ' '),
                    NVL(DMG_MIN_VAL, ' '),
                    NVL(DMG_MAX_VAL, ' '),
                    NVL(RPT_CMF_1, ' '),
                    NVL(RPT_CMF_2, ' '),
                    NVL(RPT_CMF_3, ' '),
                    NVL(RPT_CMF_4, ' '),
                    NVL(RPT_CMF_5, ' '),
                    NVL(COMMENTS, ' '),
                    NVL(CREATE_USER_ID, ' '),
                    NVL(CREATE_TIME, ' '),
                    NVL(UPDATE_USER_ID, ' '),
                    NVL(UPDATE_TIME, ' '),
                    NVL(RPT_CMF_6, ' '),
                    NVL(RPT_CMF_7, ' '),
                    NVL(RPT_CMF_8, ' '),
                    NVL(RPT_CMF_9, ' '),
                    NVL(RPT_CMF_10, ' '),
                    NVL(RPT_CMF_11, ' '),
                    NVL(RPT_CMF_12, ' '),
                    NVL(RPT_CMF_13, ' '),
                    NVL(RPT_CMF_14, ' '),
                    NVL(RPT_CMF_15, ' '),
                    NVL(FIT_STANDARD, ' '),
                    NVL(FIT_SPEC, ' '),
                    NVL(FIT_MIN_VAL, ' '),
                    NVL(FIT_MAX_VAL, ' ')
                INTO 
                    :CQCMRPTCTM_N.FACTORY,
                    :CQCMRPTCTM_N.REPORT_NO,
                    :CQCMRPTCTM_N.PACK_LOT_ID,
                    :CQCMRPTCTM_N.ORG_LOT_ID,
                    :CQCMRPTCTM_N.GRADE,
                    :CQCMRPTCTM_N.TYPES,
                    :CQCMRPTCTM_N.PACK_ORDER_ID,
                    :CQCMRPTCTM_N.CUSTOMER_ID,
                    :CQCMRPTCTM_N.OD_STANDARD,
                    :CQCMRPTCTM_N.OD_SPEC,
                    :CQCMRPTCTM_N.OD_MIN_VAL,
                    :CQCMRPTCTM_N.OD_MAX_VAL,
                    :CQCMRPTCTM_N.AT_STANDARD,
                    :CQCMRPTCTM_N.AT_SPEC,
                    :CQCMRPTCTM_N.AT_MIN_VAL,
                    :CQCMRPTCTM_N.AT_MAX_VAL,
                    :CQCMRPTCTM_N.GT_STANDARD,
                    :CQCMRPTCTM_N.GT_SPEC,
                    :CQCMRPTCTM_N.GT_MIN_VAL,
                    :CQCMRPTCTM_N.GT_MAX_VAL,
                    :CQCMRPTCTM_N.LEN01_STANDARD,
                    :CQCMRPTCTM_N.LEN01_SPEC,
                    :CQCMRPTCTM_N.LEN_MIN_VAL01,
                    :CQCMRPTCTM_N.LEN_MAX_VAL01,
                    :CQCMRPTCTM_N.LEN02_STANDARD,
                    :CQCMRPTCTM_N.LEN02_SPEC,
                    :CQCMRPTCTM_N.LEN_MIN_VAL02,
                    :CQCMRPTCTM_N.LEN_MAX_VAL02,
                    :CQCMRPTCTM_N.DMG_STANDARD,
                    :CQCMRPTCTM_N.DMG_SPEC,
                    :CQCMRPTCTM_N.DMG_MIN_VAL,
                    :CQCMRPTCTM_N.DMG_MAX_VAL,
                    :CQCMRPTCTM_N.RPT_CMF_1,
                    :CQCMRPTCTM_N.RPT_CMF_2,
                    :CQCMRPTCTM_N.RPT_CMF_3,
                    :CQCMRPTCTM_N.RPT_CMF_4,
                    :CQCMRPTCTM_N.RPT_CMF_5,
                    :CQCMRPTCTM_N.COMMENTS,
                    :CQCMRPTCTM_N.CREATE_USER_ID,
                    :CQCMRPTCTM_N.CREATE_TIME,
                    :CQCMRPTCTM_N.UPDATE_USER_ID,
                    :CQCMRPTCTM_N.UPDATE_TIME,
                    :CQCMRPTCTM_N.RPT_CMF_6,
                    :CQCMRPTCTM_N.RPT_CMF_7,
                    :CQCMRPTCTM_N.RPT_CMF_8,
                    :CQCMRPTCTM_N.RPT_CMF_9,
                    :CQCMRPTCTM_N.RPT_CMF_10,
                    :CQCMRPTCTM_N.RPT_CMF_11,
                    :CQCMRPTCTM_N.RPT_CMF_12,
                    :CQCMRPTCTM_N.RPT_CMF_13,
                    :CQCMRPTCTM_N.RPT_CMF_14,
                    :CQCMRPTCTM_N.RPT_CMF_15,
                    :CQCMRPTCTM_N.FIT_STANDARD,
                    :CQCMRPTCTM_N.FIT_SPEC,
                    :CQCMRPTCTM_N.FIT_MIN_VAL,
                    :CQCMRPTCTM_N.FIT_MAX_VAL
                FROM CQCMRPTCTM
                WHERE FACTORY = :CQCMRPTCTM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTCTM_N.REPORT_NO
                    AND PACK_LOT_ID = :CQCMRPTCTM_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :CQCMRPTCTM_N.ORG_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 60;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,REPORT_NO ,PACK_LOT_ID ,ORG_LOT_ID ,NVL(GRADE\
,' ') ,NVL(TYPES,' ') ,NVL(PACK_ORDER_ID,' ') ,NVL(CUSTOMER_ID,' ') ,NVL(OD_\
STANDARD,' ') ,NVL(OD_SPEC,' ') ,NVL(OD_MIN_VAL,' ') ,NVL(OD_MAX_VAL,' ') ,N\
VL(AT_STANDARD,' ') ,NVL(AT_SPEC,' ') ,NVL(AT_MIN_VAL,' ') ,NVL(AT_MAX_VAL,'\
 ') ,NVL(GT_STANDARD,' ') ,NVL(GT_SPEC,' ') ,NVL(GT_MIN_VAL,' ') ,NVL(GT_MAX\
_VAL,' ') ,NVL(LEN01_STANDARD,' ') ,NVL(LEN01_SPEC,' ') ,NVL(LEN_MIN_VAL01,'\
 ') ,NVL(LEN_MAX_VAL01,' ') ,NVL(LEN02_STANDARD,' ') ,NVL(LEN02_SPEC,' ') ,N\
VL(LEN_MIN_VAL02,' ') ,NVL(LEN_MAX_VAL02,' ') ,NVL(DMG_STANDARD,' ') ,NVL(DM\
G_SPEC,' ') ,NVL(DMG_MIN_VAL,' ') ,NVL(DMG_MAX_VAL,' ') ,NVL(RPT_CMF_1,' ') \
,NVL(RPT_CMF_2,' ') ,NVL(RPT_CMF_3,' ') ,NVL(RPT_CMF_4,' ') ,NVL(RPT_CMF_5,'\
 ') ,NVL(COMMENTS,' ') ,NVL(CREATE_USER_ID,' ') ,NVL(CREATE_TIME,' ') ,NVL(U\
PDATE_USER_ID,' ') ,NVL(UPDATE_TIME,' ') ,NVL(RPT_CMF_6,' ') ,NVL(RPT_CMF_7,\
' ') ,NVL(RPT_CMF_8,' ') ,NVL(RPT_CMF_9,' ') ,NVL(RPT_CMF_10,' ') ,NVL(RPT_C\
MF_11,' ') ,NVL(RPT_CMF_12,' ') ,NVL(RPT_CMF_13,' '");
            sqlstm.stmt = ") ,NVL(RPT_CMF_14,' ') ,NVL(RPT_CMF_15,' ') ,NVL\
(FIT_STANDARD,' ') ,NVL(FIT_SPEC,' ') ,NVL(FIT_MIN_VAL,' ') ,NVL(FIT_MAX_VAL,\
' ') into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b\
15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30\
,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:\
b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55  from CQCMRPTCTM where (((FA\
CTORY=:b0 and REPORT_NO=:b1) and PACK_LOT_ID=:b2) and ORG_LOT_ID=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTCTM_N.GRADE);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTCTM_N.TYPES);
            sqlstm.sqhstl[5] = (unsigned int  )51;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTCTM_N.PACK_ORDER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTCTM_N.CUSTOMER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )41;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTCTM_N.OD_STANDARD);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTCTM_N.OD_SPEC);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTCTM_N.OD_MIN_VAL);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTCTM_N.OD_MAX_VAL);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTCTM_N.AT_STANDARD);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTCTM_N.AT_SPEC);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTCTM_N.AT_MIN_VAL);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTCTM_N.AT_MAX_VAL);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTCTM_N.GT_STANDARD);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTCTM_N.GT_SPEC);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTCTM_N.GT_MIN_VAL);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTCTM_N.GT_MAX_VAL);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTCTM_N.LEN01_STANDARD);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTCTM_N.LEN01_SPEC);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL01);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL01);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTCTM_N.LEN02_STANDARD);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTCTM_N.LEN02_SPEC);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL02);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL02);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTCTM_N.DMG_STANDARD);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTCTM_N.DMG_SPEC);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTCTM_N.DMG_MIN_VAL);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTCTM_N.DMG_MAX_VAL);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTCTM_N.COMMENTS);
            sqlstm.sqhstl[37] = (unsigned int  )101;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTCTM_N.CREATE_USER_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTCTM_N.CREATE_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )15;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTCTM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTCTM_N.UPDATE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )15;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTCTM_N.FIT_STANDARD);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTCTM_N.FIT_SPEC);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTCTM_N.FIT_MIN_VAL);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTCTM_N.FIT_MAX_VAL);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[58] = (unsigned int  )26;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
            sqlstm.sqhstl[59] = (unsigned int  )26;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
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
            /* EXEC SQL SELECT 
                    FACTORY,
                    REPORT_NO,
                    PACK_LOT_ID,
                    ORG_LOT_ID,
                    NVL(GRADE, ' '),
                    NVL(TYPES, ' '),
                    NVL(PACK_ORDER_ID, ' '),
                    NVL(CUSTOMER_ID, ' '),
                    NVL(OD_STANDARD, ' '),
                    NVL(OD_SPEC, ' '),
                    NVL(OD_MIN_VAL, ' '),
                    NVL(OD_MAX_VAL, ' '),
                    NVL(AT_STANDARD, ' '),
                    NVL(AT_SPEC, ' '),
                    NVL(AT_MIN_VAL, ' '),
                    NVL(AT_MAX_VAL, ' '),
                    NVL(GT_STANDARD, ' '),
                    NVL(GT_SPEC, ' '),
                    NVL(GT_MIN_VAL, ' '),
                    NVL(GT_MAX_VAL, ' '),
                    NVL(LEN01_STANDARD, ' '),
                    NVL(LEN01_SPEC, ' '),
                    NVL(LEN_MIN_VAL01, ' '),
                    NVL(LEN_MAX_VAL01, ' '),
                    NVL(LEN02_STANDARD, ' '),
                    NVL(LEN02_SPEC, ' '),
                    NVL(LEN_MIN_VAL02, ' '),
                    NVL(LEN_MAX_VAL02, ' '),
                    NVL(DMG_STANDARD, ' '),
                    NVL(DMG_SPEC, ' '),
                    NVL(DMG_MIN_VAL, ' '),
                    NVL(DMG_MAX_VAL, ' '),
                    NVL(RPT_CMF_1, ' '),
                    NVL(RPT_CMF_2, ' '),
                    NVL(RPT_CMF_3, ' '),
                    NVL(RPT_CMF_4, ' '),
                    NVL(RPT_CMF_5, ' '),
                    NVL(COMMENTS, ' '),
                    NVL(CREATE_USER_ID, ' '),
                    NVL(CREATE_TIME, ' '),
                    NVL(UPDATE_USER_ID, ' '),
                    NVL(UPDATE_TIME, ' '),
                    NVL(RPT_CMF_6, ' '),
                    NVL(RPT_CMF_7, ' '),
                    NVL(RPT_CMF_8, ' '),
                    NVL(RPT_CMF_9, ' '),
                    NVL(RPT_CMF_10, ' '),
                    NVL(RPT_CMF_11, ' '),
                    NVL(RPT_CMF_12, ' '),
                    NVL(RPT_CMF_13, ' '),
                    NVL(RPT_CMF_14, ' '),
                    NVL(RPT_CMF_15, ' '),
                    NVL(FIT_STANDARD, ' '),
                    NVL(FIT_SPEC, ' '),
                    NVL(FIT_MIN_VAL, ' '),
                    NVL(FIT_MAX_VAL, ' ')
                INTO 
                    :CQCMRPTCTM_N.FACTORY,
                    :CQCMRPTCTM_N.REPORT_NO,
                    :CQCMRPTCTM_N.PACK_LOT_ID,
                    :CQCMRPTCTM_N.ORG_LOT_ID,
                    :CQCMRPTCTM_N.GRADE,
                    :CQCMRPTCTM_N.TYPES,
                    :CQCMRPTCTM_N.PACK_ORDER_ID,
                    :CQCMRPTCTM_N.CUSTOMER_ID,
                    :CQCMRPTCTM_N.OD_STANDARD,
                    :CQCMRPTCTM_N.OD_SPEC,
                    :CQCMRPTCTM_N.OD_MIN_VAL,
                    :CQCMRPTCTM_N.OD_MAX_VAL,
                    :CQCMRPTCTM_N.AT_STANDARD,
                    :CQCMRPTCTM_N.AT_SPEC,
                    :CQCMRPTCTM_N.AT_MIN_VAL,
                    :CQCMRPTCTM_N.AT_MAX_VAL,
                    :CQCMRPTCTM_N.GT_STANDARD,
                    :CQCMRPTCTM_N.GT_SPEC,
                    :CQCMRPTCTM_N.GT_MIN_VAL,
                    :CQCMRPTCTM_N.GT_MAX_VAL,
                    :CQCMRPTCTM_N.LEN01_STANDARD,
                    :CQCMRPTCTM_N.LEN01_SPEC,
                    :CQCMRPTCTM_N.LEN_MIN_VAL01,
                    :CQCMRPTCTM_N.LEN_MAX_VAL01,
                    :CQCMRPTCTM_N.LEN02_STANDARD,
                    :CQCMRPTCTM_N.LEN02_SPEC,
                    :CQCMRPTCTM_N.LEN_MIN_VAL02,
                    :CQCMRPTCTM_N.LEN_MAX_VAL02,
                    :CQCMRPTCTM_N.DMG_STANDARD,
                    :CQCMRPTCTM_N.DMG_SPEC,
                    :CQCMRPTCTM_N.DMG_MIN_VAL,
                    :CQCMRPTCTM_N.DMG_MAX_VAL,
                    :CQCMRPTCTM_N.RPT_CMF_1,
                    :CQCMRPTCTM_N.RPT_CMF_2,
                    :CQCMRPTCTM_N.RPT_CMF_3,
                    :CQCMRPTCTM_N.RPT_CMF_4,
                    :CQCMRPTCTM_N.RPT_CMF_5,
                    :CQCMRPTCTM_N.COMMENTS,
                    :CQCMRPTCTM_N.CREATE_USER_ID,
                    :CQCMRPTCTM_N.CREATE_TIME,
                    :CQCMRPTCTM_N.UPDATE_USER_ID,
                    :CQCMRPTCTM_N.UPDATE_TIME,
                    :CQCMRPTCTM_N.RPT_CMF_6,
                    :CQCMRPTCTM_N.RPT_CMF_7,
                    :CQCMRPTCTM_N.RPT_CMF_8,
                    :CQCMRPTCTM_N.RPT_CMF_9,
                    :CQCMRPTCTM_N.RPT_CMF_10,
                    :CQCMRPTCTM_N.RPT_CMF_11,
                    :CQCMRPTCTM_N.RPT_CMF_12,
                    :CQCMRPTCTM_N.RPT_CMF_13,
                    :CQCMRPTCTM_N.RPT_CMF_14,
                    :CQCMRPTCTM_N.RPT_CMF_15,
                    :CQCMRPTCTM_N.FIT_STANDARD,
                    :CQCMRPTCTM_N.FIT_SPEC,
                    :CQCMRPTCTM_N.FIT_MIN_VAL,
                    :CQCMRPTCTM_N.FIT_MAX_VAL
                FROM CQCMRPTCTM
                WHERE FACTORY = :CQCMRPTCTM_N.FACTORY
                  AND PACK_LOT_ID = :CQCMRPTCTM_N.PACK_LOT_ID
                  AND ORG_LOT_ID = :CQCMRPTCTM_N.ORG_LOT_ID
                  AND REPORT_NO = (SELECT MAX(REPORT_NO) 
                                     FROM CQCMRPTCTM
                                    WHERE FACTORY = :CQCMRPTCTM_N.FACTORY
                                      AND PACK_LOT_ID = :CQCMRPTCTM_N.PACK_LOT_ID
                                      AND ORG_LOT_ID = :CQCMRPTCTM_N.ORG_LOT_ID); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 62;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,REPORT_NO ,PACK_LOT_ID ,ORG_LOT_ID ,NVL(GRADE\
,' ') ,NVL(TYPES,' ') ,NVL(PACK_ORDER_ID,' ') ,NVL(CUSTOMER_ID,' ') ,NVL(OD_\
STANDARD,' ') ,NVL(OD_SPEC,' ') ,NVL(OD_MIN_VAL,' ') ,NVL(OD_MAX_VAL,' ') ,N\
VL(AT_STANDARD,' ') ,NVL(AT_SPEC,' ') ,NVL(AT_MIN_VAL,' ') ,NVL(AT_MAX_VAL,'\
 ') ,NVL(GT_STANDARD,' ') ,NVL(GT_SPEC,' ') ,NVL(GT_MIN_VAL,' ') ,NVL(GT_MAX\
_VAL,' ') ,NVL(LEN01_STANDARD,' ') ,NVL(LEN01_SPEC,' ') ,NVL(LEN_MIN_VAL01,'\
 ') ,NVL(LEN_MAX_VAL01,' ') ,NVL(LEN02_STANDARD,' ') ,NVL(LEN02_SPEC,' ') ,N\
VL(LEN_MIN_VAL02,' ') ,NVL(LEN_MAX_VAL02,' ') ,NVL(DMG_STANDARD,' ') ,NVL(DM\
G_SPEC,' ') ,NVL(DMG_MIN_VAL,' ') ,NVL(DMG_MAX_VAL,' ') ,NVL(RPT_CMF_1,' ') \
,NVL(RPT_CMF_2,' ') ,NVL(RPT_CMF_3,' ') ,NVL(RPT_CMF_4,' ') ,NVL(RPT_CMF_5,'\
 ') ,NVL(COMMENTS,' ') ,NVL(CREATE_USER_ID,' ') ,NVL(CREATE_TIME,' ') ,NVL(U\
PDATE_USER_ID,' ') ,NVL(UPDATE_TIME,' ') ,NVL(RPT_CMF_6,' ') ,NVL(RPT_CMF_7,\
' ') ,NVL(RPT_CMF_8,' ') ,NVL(RPT_CMF_9,' ') ,NVL(RPT_CMF_10,' ') ,NVL(RPT_C\
MF_11,' ') ,NVL(RPT_CMF_12,' ') ,NVL(RPT_CMF_13,' '");
            sqlstm.stmt = ") ,NVL(RPT_CMF_14,' ') ,NVL(RPT_CMF_15,' ') ,NVL\
(FIT_STANDARD,' ') ,NVL(FIT_SPEC,' ') ,NVL(FIT_MIN_VAL,' ') ,NVL(FIT_MAX_VAL,\
' ') into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b\
15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30\
,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:\
b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55  from CQCMRPTCTM where (((FA\
CTORY=:b0 and PACK_LOT_ID=:b2) and ORG_LOT_ID=:b3) and REPORT_NO=(select max(\
REPORT_NO)  from CQCMRPTCTM where ((FACTORY=:b0 and PACK_LOT_ID=:b2) and ORG_\
LOT_ID=:b3)))";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )260;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTCTM_N.GRADE);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTCTM_N.TYPES);
            sqlstm.sqhstl[5] = (unsigned int  )51;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTCTM_N.PACK_ORDER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTCTM_N.CUSTOMER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )41;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTCTM_N.OD_STANDARD);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTCTM_N.OD_SPEC);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTCTM_N.OD_MIN_VAL);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTCTM_N.OD_MAX_VAL);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTCTM_N.AT_STANDARD);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTCTM_N.AT_SPEC);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTCTM_N.AT_MIN_VAL);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTCTM_N.AT_MAX_VAL);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTCTM_N.GT_STANDARD);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTCTM_N.GT_SPEC);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTCTM_N.GT_MIN_VAL);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTCTM_N.GT_MAX_VAL);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTCTM_N.LEN01_STANDARD);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTCTM_N.LEN01_SPEC);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL01);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL01);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTCTM_N.LEN02_STANDARD);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTCTM_N.LEN02_SPEC);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL02);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL02);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTCTM_N.DMG_STANDARD);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTCTM_N.DMG_SPEC);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTCTM_N.DMG_MIN_VAL);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTCTM_N.DMG_MAX_VAL);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTCTM_N.COMMENTS);
            sqlstm.sqhstl[37] = (unsigned int  )101;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTCTM_N.CREATE_USER_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTCTM_N.CREATE_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )15;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTCTM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTCTM_N.UPDATE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )15;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTCTM_N.FIT_STANDARD);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTCTM_N.FIT_SPEC);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTCTM_N.FIT_MIN_VAL);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTCTM_N.FIT_MAX_VAL);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[57] = (unsigned int  )26;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
            sqlstm.sqhstl[58] = (unsigned int  )26;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[59] = (unsigned int  )11;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )26;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
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
        DBU_del_null_cqcmrptctm(&CQCMRPTCTM_N, CQCMRPTCTM);
    }

    DB_stop_query_timer("DBU_select_cqcmrptctm", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cqcmrptctm_for_update(int sel_type, struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTCTM_N_TAG CQCMRPTCTM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptctm(&CQCMRPTCTM_N, CQCMRPTCTM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    REPORT_NO,
                    PACK_LOT_ID,
                    ORG_LOT_ID,
                    NVL(GRADE, ' '),
                    NVL(TYPES, ' '),
                    NVL(PACK_ORDER_ID, ' '),
                    NVL(CUSTOMER_ID, ' '),
                    NVL(OD_STANDARD, ' '),
                    NVL(OD_SPEC, ' '),
                    NVL(OD_MIN_VAL, ' '),
                    NVL(OD_MAX_VAL, ' '),
                    NVL(AT_STANDARD, ' '),
                    NVL(AT_SPEC, ' '),
                    NVL(AT_MIN_VAL, ' '),
                    NVL(AT_MAX_VAL, ' '),
                    NVL(GT_STANDARD, ' '),
                    NVL(GT_SPEC, ' '),
                    NVL(GT_MIN_VAL, ' '),
                    NVL(GT_MAX_VAL, ' '),
                    NVL(LEN01_STANDARD, ' '),
                    NVL(LEN01_SPEC, ' '),
                    NVL(LEN_MIN_VAL01, ' '),
                    NVL(LEN_MAX_VAL01, ' '),
                    NVL(LEN02_STANDARD, ' '),
                    NVL(LEN02_SPEC, ' '),
                    NVL(LEN_MIN_VAL02, ' '),
                    NVL(LEN_MAX_VAL02, ' '),
                    NVL(DMG_STANDARD, ' '),
                    NVL(DMG_SPEC, ' '),
                    NVL(DMG_MIN_VAL, ' '),
                    NVL(DMG_MAX_VAL, ' '),
                    NVL(RPT_CMF_1, ' '),
                    NVL(RPT_CMF_2, ' '),
                    NVL(RPT_CMF_3, ' '),
                    NVL(RPT_CMF_4, ' '),
                    NVL(RPT_CMF_5, ' '),
                    NVL(COMMENTS, ' '),
                    NVL(CREATE_USER_ID, ' '),
                    NVL(CREATE_TIME, ' '),
                    NVL(UPDATE_USER_ID, ' '),
                    NVL(UPDATE_TIME, ' '),
                    NVL(RPT_CMF_6, ' '),
                    NVL(RPT_CMF_7, ' '),
                    NVL(RPT_CMF_8, ' '),
                    NVL(RPT_CMF_9, ' '),
                    NVL(RPT_CMF_10, ' '),
                    NVL(RPT_CMF_11, ' '),
                    NVL(RPT_CMF_12, ' '),
                    NVL(RPT_CMF_13, ' '),
                    NVL(RPT_CMF_14, ' '),
                    NVL(RPT_CMF_15, ' '),
                    NVL(FIT_STANDARD, ' '),
                    NVL(FIT_SPEC, ' '),
                    NVL(FIT_MIN_VAL, ' '),
                    NVL(FIT_MAX_VAL, ' ')
                INTO 
                    :CQCMRPTCTM_N.FACTORY,
                    :CQCMRPTCTM_N.REPORT_NO,
                    :CQCMRPTCTM_N.PACK_LOT_ID,
                    :CQCMRPTCTM_N.ORG_LOT_ID,
                    :CQCMRPTCTM_N.GRADE,
                    :CQCMRPTCTM_N.TYPES,
                    :CQCMRPTCTM_N.PACK_ORDER_ID,
                    :CQCMRPTCTM_N.CUSTOMER_ID,
                    :CQCMRPTCTM_N.OD_STANDARD,
                    :CQCMRPTCTM_N.OD_SPEC,
                    :CQCMRPTCTM_N.OD_MIN_VAL,
                    :CQCMRPTCTM_N.OD_MAX_VAL,
                    :CQCMRPTCTM_N.AT_STANDARD,
                    :CQCMRPTCTM_N.AT_SPEC,
                    :CQCMRPTCTM_N.AT_MIN_VAL,
                    :CQCMRPTCTM_N.AT_MAX_VAL,
                    :CQCMRPTCTM_N.GT_STANDARD,
                    :CQCMRPTCTM_N.GT_SPEC,
                    :CQCMRPTCTM_N.GT_MIN_VAL,
                    :CQCMRPTCTM_N.GT_MAX_VAL,
                    :CQCMRPTCTM_N.LEN01_STANDARD,
                    :CQCMRPTCTM_N.LEN01_SPEC,
                    :CQCMRPTCTM_N.LEN_MIN_VAL01,
                    :CQCMRPTCTM_N.LEN_MAX_VAL01,
                    :CQCMRPTCTM_N.LEN02_STANDARD,
                    :CQCMRPTCTM_N.LEN02_SPEC,
                    :CQCMRPTCTM_N.LEN_MIN_VAL02,
                    :CQCMRPTCTM_N.LEN_MAX_VAL02,
                    :CQCMRPTCTM_N.DMG_STANDARD,
                    :CQCMRPTCTM_N.DMG_SPEC,
                    :CQCMRPTCTM_N.DMG_MIN_VAL,
                    :CQCMRPTCTM_N.DMG_MAX_VAL,
                    :CQCMRPTCTM_N.RPT_CMF_1,
                    :CQCMRPTCTM_N.RPT_CMF_2,
                    :CQCMRPTCTM_N.RPT_CMF_3,
                    :CQCMRPTCTM_N.RPT_CMF_4,
                    :CQCMRPTCTM_N.RPT_CMF_5,
                    :CQCMRPTCTM_N.COMMENTS,
                    :CQCMRPTCTM_N.CREATE_USER_ID,
                    :CQCMRPTCTM_N.CREATE_TIME,
                    :CQCMRPTCTM_N.UPDATE_USER_ID,
                    :CQCMRPTCTM_N.UPDATE_TIME,
                    :CQCMRPTCTM_N.RPT_CMF_6,
                    :CQCMRPTCTM_N.RPT_CMF_7,
                    :CQCMRPTCTM_N.RPT_CMF_8,
                    :CQCMRPTCTM_N.RPT_CMF_9,
                    :CQCMRPTCTM_N.RPT_CMF_10,
                    :CQCMRPTCTM_N.RPT_CMF_11,
                    :CQCMRPTCTM_N.RPT_CMF_12,
                    :CQCMRPTCTM_N.RPT_CMF_13,
                    :CQCMRPTCTM_N.RPT_CMF_14,
                    :CQCMRPTCTM_N.RPT_CMF_15,
                    :CQCMRPTCTM_N.FIT_STANDARD,
                    :CQCMRPTCTM_N.FIT_SPEC,
                    :CQCMRPTCTM_N.FIT_MIN_VAL,
                    :CQCMRPTCTM_N.FIT_MAX_VAL
                FROM CQCMRPTCTM
                WHERE FACTORY = :CQCMRPTCTM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTCTM_N.REPORT_NO
                    AND PACK_LOT_ID = :CQCMRPTCTM_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :CQCMRPTCTM_N.ORG_LOT_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 62;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,REPORT_NO ,PACK_LOT_ID ,ORG_LOT_ID ,NVL(GRADE\
,' ') ,NVL(TYPES,' ') ,NVL(PACK_ORDER_ID,' ') ,NVL(CUSTOMER_ID,' ') ,NVL(OD_\
STANDARD,' ') ,NVL(OD_SPEC,' ') ,NVL(OD_MIN_VAL,' ') ,NVL(OD_MAX_VAL,' ') ,N\
VL(AT_STANDARD,' ') ,NVL(AT_SPEC,' ') ,NVL(AT_MIN_VAL,' ') ,NVL(AT_MAX_VAL,'\
 ') ,NVL(GT_STANDARD,' ') ,NVL(GT_SPEC,' ') ,NVL(GT_MIN_VAL,' ') ,NVL(GT_MAX\
_VAL,' ') ,NVL(LEN01_STANDARD,' ') ,NVL(LEN01_SPEC,' ') ,NVL(LEN_MIN_VAL01,'\
 ') ,NVL(LEN_MAX_VAL01,' ') ,NVL(LEN02_STANDARD,' ') ,NVL(LEN02_SPEC,' ') ,N\
VL(LEN_MIN_VAL02,' ') ,NVL(LEN_MAX_VAL02,' ') ,NVL(DMG_STANDARD,' ') ,NVL(DM\
G_SPEC,' ') ,NVL(DMG_MIN_VAL,' ') ,NVL(DMG_MAX_VAL,' ') ,NVL(RPT_CMF_1,' ') \
,NVL(RPT_CMF_2,' ') ,NVL(RPT_CMF_3,' ') ,NVL(RPT_CMF_4,' ') ,NVL(RPT_CMF_5,'\
 ') ,NVL(COMMENTS,' ') ,NVL(CREATE_USER_ID,' ') ,NVL(CREATE_TIME,' ') ,NVL(U\
PDATE_USER_ID,' ') ,NVL(UPDATE_TIME,' ') ,NVL(RPT_CMF_6,' ') ,NVL(RPT_CMF_7,\
' ') ,NVL(RPT_CMF_8,' ') ,NVL(RPT_CMF_9,' ') ,NVL(RPT_CMF_10,' ') ,NVL(RPT_C\
MF_11,' ') ,NVL(RPT_CMF_12,' ') ,NVL(RPT_CMF_13,' '");
            sqlstm.stmt = ") ,NVL(RPT_CMF_14,' ') ,NVL(RPT_CMF_15,' ') ,NVL\
(FIT_STANDARD,' ') ,NVL(FIT_SPEC,' ') ,NVL(FIT_MIN_VAL,' ') ,NVL(FIT_MAX_VAL,\
' ') into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b\
15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30\
,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:\
b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55  from CQCMRPTCTM where (((FA\
CTORY=:b0 and REPORT_NO=:b1) and PACK_LOT_ID=:b2) and ORG_LOT_ID=:b3) for upd\
ate ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )523;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTCTM_N.GRADE);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTCTM_N.TYPES);
            sqlstm.sqhstl[5] = (unsigned int  )51;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTCTM_N.PACK_ORDER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTCTM_N.CUSTOMER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )41;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTCTM_N.OD_STANDARD);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTCTM_N.OD_SPEC);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTCTM_N.OD_MIN_VAL);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTCTM_N.OD_MAX_VAL);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTCTM_N.AT_STANDARD);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTCTM_N.AT_SPEC);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTCTM_N.AT_MIN_VAL);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTCTM_N.AT_MAX_VAL);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTCTM_N.GT_STANDARD);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTCTM_N.GT_SPEC);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTCTM_N.GT_MIN_VAL);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTCTM_N.GT_MAX_VAL);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTCTM_N.LEN01_STANDARD);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTCTM_N.LEN01_SPEC);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL01);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL01);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTCTM_N.LEN02_STANDARD);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTCTM_N.LEN02_SPEC);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL02);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL02);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTCTM_N.DMG_STANDARD);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTCTM_N.DMG_SPEC);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTCTM_N.DMG_MIN_VAL);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTCTM_N.DMG_MAX_VAL);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTCTM_N.COMMENTS);
            sqlstm.sqhstl[37] = (unsigned int  )101;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTCTM_N.CREATE_USER_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTCTM_N.CREATE_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )15;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTCTM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTCTM_N.UPDATE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )15;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTCTM_N.FIT_STANDARD);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTCTM_N.FIT_SPEC);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTCTM_N.FIT_MIN_VAL);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTCTM_N.FIT_MAX_VAL);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[58] = (unsigned int  )26;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
            sqlstm.sqhstl[59] = (unsigned int  )26;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
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
        DBU_del_null_cqcmrptctm(&CQCMRPTCTM_N, CQCMRPTCTM);
    }

    DB_stop_query_timer("DBU_select_cqcmrptctm_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cqcmrptctm_scalar(int sel_type, struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTCTM_N_TAG CQCMRPTCTM_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptctm(&CQCMRPTCTM_N, CQCMRPTCTM);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMRPTCTM
                WHERE FACTORY = :CQCMRPTCTM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTCTM_N.REPORT_NO
                    AND PACK_LOT_ID = :CQCMRPTCTM_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :CQCMRPTCTM_N.ORG_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 62;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMRPTCTM where\
 (((FACTORY=:b1 and REPORT_NO=:b2) and PACK_LOT_ID=:b3) and ORG_LOT_ID=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )778;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
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
            if (sqlca.sqlcode == 1403) DB_usr_error();
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 2:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMRPTCTM
                WHERE FACTORY = :CQCMRPTCTM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTCTM_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 62;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMRPTCTM where\
 (FACTORY=:b1 and REPORT_NO=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )813;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
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

    DB_stop_query_timer("DBU_select_cqcmrptctm_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cqcmrptctm(int sel_type, struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTCTM_N_TAG CQCMRPTCTM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptctm(&CQCMRPTCTM_N, CQCMRPTCTM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CQCMRPTCTM
                WHERE FACTORY = :CQCMRPTCTM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTCTM_N.REPORT_NO
                    AND PACK_LOT_ID = :CQCMRPTCTM_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :CQCMRPTCTM_N.ORG_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 62;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMRPTCTM  where (((FACTORY=:b0 an\
d REPORT_NO=:b1) and PACK_LOT_ID=:b2) and ORG_LOT_ID=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )840;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
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
            /* EXEC SQL DELETE FROM CQCMRPTCTM
                WHERE FACTORY = :CQCMRPTCTM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTCTM_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 62;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMRPTCTM  where (FACTORY=:b0 and \
REPORT_NO=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )871;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
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

    DB_stop_query_timer("DBU_delete_cqcmrptctm", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cqcmrptctm(struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTCTM_N_TAG CQCMRPTCTM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptctm(&CQCMRPTCTM_N, CQCMRPTCTM);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CQCMRPTCTM( 
                    FACTORY, 
                    REPORT_NO, 
                    PACK_LOT_ID, 
                    ORG_LOT_ID, 
                    GRADE, 
                    TYPES, 
                    PACK_ORDER_ID, 
                    CUSTOMER_ID, 
                    OD_STANDARD, 
                    OD_SPEC, 
                    OD_MIN_VAL, 
                    OD_MAX_VAL, 
                    AT_STANDARD, 
                    AT_SPEC, 
                    AT_MIN_VAL, 
                    AT_MAX_VAL, 
                    GT_STANDARD, 
                    GT_SPEC, 
                    GT_MIN_VAL, 
                    GT_MAX_VAL, 
                    LEN01_STANDARD, 
                    LEN01_SPEC, 
                    LEN_MIN_VAL01, 
                    LEN_MAX_VAL01, 
                    LEN02_STANDARD, 
                    LEN02_SPEC, 
                    LEN_MIN_VAL02, 
                    LEN_MAX_VAL02, 
                    DMG_STANDARD, 
                    DMG_SPEC, 
                    DMG_MIN_VAL, 
                    DMG_MAX_VAL, 
                    RPT_CMF_1, 
                    RPT_CMF_2, 
                    RPT_CMF_3, 
                    RPT_CMF_4, 
                    RPT_CMF_5, 
                    COMMENTS, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME,
                    RPT_CMF_6,
                    RPT_CMF_7,
                    RPT_CMF_8,
                    RPT_CMF_9,
                    RPT_CMF_10,
                    RPT_CMF_11,
                    RPT_CMF_12,
                    RPT_CMF_13,
                    RPT_CMF_14,
                    RPT_CMF_15,
                    FIT_STANDARD,
                    FIT_SPEC,
                    FIT_MIN_VAL,
                    FIT_MAX_VAL
         ) 
        VALUES (
                    :CQCMRPTCTM_N.FACTORY,
                    :CQCMRPTCTM_N.REPORT_NO,
                    :CQCMRPTCTM_N.PACK_LOT_ID,
                    :CQCMRPTCTM_N.ORG_LOT_ID,
                    :CQCMRPTCTM_N.GRADE,
                    :CQCMRPTCTM_N.TYPES,
                    :CQCMRPTCTM_N.PACK_ORDER_ID,
                    :CQCMRPTCTM_N.CUSTOMER_ID,
                    :CQCMRPTCTM_N.OD_STANDARD,
                    :CQCMRPTCTM_N.OD_SPEC,
                    :CQCMRPTCTM_N.OD_MIN_VAL,
                    :CQCMRPTCTM_N.OD_MAX_VAL,
                    :CQCMRPTCTM_N.AT_STANDARD,
                    :CQCMRPTCTM_N.AT_SPEC,
                    :CQCMRPTCTM_N.AT_MIN_VAL,
                    :CQCMRPTCTM_N.AT_MAX_VAL,
                    :CQCMRPTCTM_N.GT_STANDARD,
                    :CQCMRPTCTM_N.GT_SPEC,
                    :CQCMRPTCTM_N.GT_MIN_VAL,
                    :CQCMRPTCTM_N.GT_MAX_VAL,
                    :CQCMRPTCTM_N.LEN01_STANDARD,
                    :CQCMRPTCTM_N.LEN01_SPEC,
                    :CQCMRPTCTM_N.LEN_MIN_VAL01,
                    :CQCMRPTCTM_N.LEN_MAX_VAL01,
                    :CQCMRPTCTM_N.LEN02_STANDARD,
                    :CQCMRPTCTM_N.LEN02_SPEC,
                    :CQCMRPTCTM_N.LEN_MIN_VAL02,
                    :CQCMRPTCTM_N.LEN_MAX_VAL02,
                    :CQCMRPTCTM_N.DMG_STANDARD,
                    :CQCMRPTCTM_N.DMG_SPEC,
                    :CQCMRPTCTM_N.DMG_MIN_VAL,
                    :CQCMRPTCTM_N.DMG_MAX_VAL,
                    :CQCMRPTCTM_N.RPT_CMF_1,
                    :CQCMRPTCTM_N.RPT_CMF_2,
                    :CQCMRPTCTM_N.RPT_CMF_3,
                    :CQCMRPTCTM_N.RPT_CMF_4,
                    :CQCMRPTCTM_N.RPT_CMF_5,
                    :CQCMRPTCTM_N.COMMENTS,
                    :CQCMRPTCTM_N.CREATE_USER_ID,
                    :CQCMRPTCTM_N.CREATE_TIME,
                    :CQCMRPTCTM_N.UPDATE_USER_ID,
                    :CQCMRPTCTM_N.UPDATE_TIME,
                    :CQCMRPTCTM_N.RPT_CMF_6,
                    :CQCMRPTCTM_N.RPT_CMF_7,
                    :CQCMRPTCTM_N.RPT_CMF_8,
                    :CQCMRPTCTM_N.RPT_CMF_9,
                    :CQCMRPTCTM_N.RPT_CMF_10,
                    :CQCMRPTCTM_N.RPT_CMF_11,
                    :CQCMRPTCTM_N.RPT_CMF_12,
                    :CQCMRPTCTM_N.RPT_CMF_13,
                    :CQCMRPTCTM_N.RPT_CMF_14,
                    :CQCMRPTCTM_N.RPT_CMF_15,
                    :CQCMRPTCTM_N.FIT_STANDARD,
                    :CQCMRPTCTM_N.FIT_SPEC,
                    :CQCMRPTCTM_N.FIT_MIN_VAL,
                    :CQCMRPTCTM_N.FIT_MAX_VAL
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 62;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into CQCMRPTCTM (FACTORY,REPORT_NO,PACK_LOT_ID,OR\
G_LOT_ID,GRADE,TYPES,PACK_ORDER_ID,CUSTOMER_ID,OD_STANDARD,OD_SPEC,OD_MIN_VAL\
,OD_MAX_VAL,AT_STANDARD,AT_SPEC,AT_MIN_VAL,AT_MAX_VAL,GT_STANDARD,GT_SPEC,GT_\
MIN_VAL,GT_MAX_VAL,LEN01_STANDARD,LEN01_SPEC,LEN_MIN_VAL01,LEN_MAX_VAL01,LEN0\
2_STANDARD,LEN02_SPEC,LEN_MIN_VAL02,LEN_MAX_VAL02,DMG_STANDARD,DMG_SPEC,DMG_M\
IN_VAL,DMG_MAX_VAL,RPT_CMF_1,RPT_CMF_2,RPT_CMF_3,RPT_CMF_4,RPT_CMF_5,COMMENTS\
,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME,RPT_CMF_6,RPT_CMF_7,RP\
T_CMF_8,RPT_CMF_9,RPT_CMF_10,RPT_CMF_11,RPT_CMF_12,RPT_CMF_13,RPT_CMF_14,RPT_\
CMF_15,FIT_STANDARD,FIT_SPEC,FIT_MIN_VAL,FIT_MAX_VAL) values (:b0,:b1,:b2,:b3\
,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b\
20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35\
,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:\
b51,:b52,:b53,:b54,:b55)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )894;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CQCMRPTCTM_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
    sqlstm.sqhstl[2] = (unsigned int  )26;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
    sqlstm.sqhstl[3] = (unsigned int  )26;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CQCMRPTCTM_N.GRADE);
    sqlstm.sqhstl[4] = (unsigned int  )31;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(CQCMRPTCTM_N.TYPES);
    sqlstm.sqhstl[5] = (unsigned int  )51;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CQCMRPTCTM_N.PACK_ORDER_ID);
    sqlstm.sqhstl[6] = (unsigned int  )26;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(CQCMRPTCTM_N.CUSTOMER_ID);
    sqlstm.sqhstl[7] = (unsigned int  )41;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CQCMRPTCTM_N.OD_STANDARD);
    sqlstm.sqhstl[8] = (unsigned int  )31;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CQCMRPTCTM_N.OD_SPEC);
    sqlstm.sqhstl[9] = (unsigned int  )31;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(CQCMRPTCTM_N.OD_MIN_VAL);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(CQCMRPTCTM_N.OD_MAX_VAL);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(CQCMRPTCTM_N.AT_STANDARD);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CQCMRPTCTM_N.AT_SPEC);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(CQCMRPTCTM_N.AT_MIN_VAL);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CQCMRPTCTM_N.AT_MAX_VAL);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CQCMRPTCTM_N.GT_STANDARD);
    sqlstm.sqhstl[16] = (unsigned int  )31;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CQCMRPTCTM_N.GT_SPEC);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CQCMRPTCTM_N.GT_MIN_VAL);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(CQCMRPTCTM_N.GT_MAX_VAL);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CQCMRPTCTM_N.LEN01_STANDARD);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CQCMRPTCTM_N.LEN01_SPEC);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL01);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL01);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CQCMRPTCTM_N.LEN02_STANDARD);
    sqlstm.sqhstl[24] = (unsigned int  )31;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(CQCMRPTCTM_N.LEN02_SPEC);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL02);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL02);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(CQCMRPTCTM_N.DMG_STANDARD);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(CQCMRPTCTM_N.DMG_SPEC);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(CQCMRPTCTM_N.DMG_MIN_VAL);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(CQCMRPTCTM_N.DMG_MAX_VAL);
    sqlstm.sqhstl[31] = (unsigned int  )31;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_1);
    sqlstm.sqhstl[32] = (unsigned int  )51;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_2);
    sqlstm.sqhstl[33] = (unsigned int  )51;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_3);
    sqlstm.sqhstl[34] = (unsigned int  )51;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_4);
    sqlstm.sqhstl[35] = (unsigned int  )51;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_5);
    sqlstm.sqhstl[36] = (unsigned int  )51;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(CQCMRPTCTM_N.COMMENTS);
    sqlstm.sqhstl[37] = (unsigned int  )101;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(CQCMRPTCTM_N.CREATE_USER_ID);
    sqlstm.sqhstl[38] = (unsigned int  )21;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(CQCMRPTCTM_N.CREATE_TIME);
    sqlstm.sqhstl[39] = (unsigned int  )15;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(CQCMRPTCTM_N.UPDATE_USER_ID);
    sqlstm.sqhstl[40] = (unsigned int  )21;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(CQCMRPTCTM_N.UPDATE_TIME);
    sqlstm.sqhstl[41] = (unsigned int  )15;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_6);
    sqlstm.sqhstl[42] = (unsigned int  )51;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_7);
    sqlstm.sqhstl[43] = (unsigned int  )51;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_8);
    sqlstm.sqhstl[44] = (unsigned int  )51;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_9);
    sqlstm.sqhstl[45] = (unsigned int  )51;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_10);
    sqlstm.sqhstl[46] = (unsigned int  )51;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_11);
    sqlstm.sqhstl[47] = (unsigned int  )51;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_12);
    sqlstm.sqhstl[48] = (unsigned int  )51;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_13);
    sqlstm.sqhstl[49] = (unsigned int  )51;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_14);
    sqlstm.sqhstl[50] = (unsigned int  )51;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_15);
    sqlstm.sqhstl[51] = (unsigned int  )51;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(CQCMRPTCTM_N.FIT_STANDARD);
    sqlstm.sqhstl[52] = (unsigned int  )31;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(CQCMRPTCTM_N.FIT_SPEC);
    sqlstm.sqhstl[53] = (unsigned int  )31;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(CQCMRPTCTM_N.FIT_MIN_VAL);
    sqlstm.sqhstl[54] = (unsigned int  )31;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(CQCMRPTCTM_N.FIT_MAX_VAL);
    sqlstm.sqhstl[55] = (unsigned int  )31;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_cqcmrptctm", 0);
}


/* SQL UPDATE Function */
void DBU_update_cqcmrptctm(int sel_type, struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTCTM_N_TAG CQCMRPTCTM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptctm(&CQCMRPTCTM_N, CQCMRPTCTM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CQCMRPTCTM SET
                    GRADE = :CQCMRPTCTM_N.GRADE,
                    TYPES = :CQCMRPTCTM_N.TYPES,
                    PACK_ORDER_ID = :CQCMRPTCTM_N.PACK_ORDER_ID,
                    CUSTOMER_ID = :CQCMRPTCTM_N.CUSTOMER_ID,
                    OD_STANDARD = :CQCMRPTCTM_N.OD_STANDARD,
                    OD_SPEC = :CQCMRPTCTM_N.OD_SPEC,
                    OD_MIN_VAL = :CQCMRPTCTM_N.OD_MIN_VAL,
                    OD_MAX_VAL = :CQCMRPTCTM_N.OD_MAX_VAL,
                    AT_STANDARD = :CQCMRPTCTM_N.AT_STANDARD,
                    AT_SPEC = :CQCMRPTCTM_N.AT_SPEC,
                    AT_MIN_VAL = :CQCMRPTCTM_N.AT_MIN_VAL,
                    AT_MAX_VAL = :CQCMRPTCTM_N.AT_MAX_VAL,
                    GT_STANDARD = :CQCMRPTCTM_N.GT_STANDARD,
                    GT_SPEC = :CQCMRPTCTM_N.GT_SPEC,
                    GT_MIN_VAL = :CQCMRPTCTM_N.GT_MIN_VAL,
                    GT_MAX_VAL = :CQCMRPTCTM_N.GT_MAX_VAL,
                    LEN01_STANDARD = :CQCMRPTCTM_N.LEN01_STANDARD,
                    LEN01_SPEC = :CQCMRPTCTM_N.LEN01_SPEC,
                    LEN_MIN_VAL01 = :CQCMRPTCTM_N.LEN_MIN_VAL01,
                    LEN_MAX_VAL01 = :CQCMRPTCTM_N.LEN_MAX_VAL01,
                    LEN02_STANDARD = :CQCMRPTCTM_N.LEN02_STANDARD,
                    LEN02_SPEC = :CQCMRPTCTM_N.LEN02_SPEC,
                    LEN_MIN_VAL02 = :CQCMRPTCTM_N.LEN_MIN_VAL02,
                    LEN_MAX_VAL02 = :CQCMRPTCTM_N.LEN_MAX_VAL02,
                    DMG_STANDARD = :CQCMRPTCTM_N.DMG_STANDARD,
                    DMG_SPEC = :CQCMRPTCTM_N.DMG_SPEC,
                    DMG_MIN_VAL = :CQCMRPTCTM_N.DMG_MIN_VAL,
                    DMG_MAX_VAL = :CQCMRPTCTM_N.DMG_MAX_VAL,
                    RPT_CMF_1 = :CQCMRPTCTM_N.RPT_CMF_1,
                    RPT_CMF_2 = :CQCMRPTCTM_N.RPT_CMF_2,
                    RPT_CMF_3 = :CQCMRPTCTM_N.RPT_CMF_3,
                    RPT_CMF_4 = :CQCMRPTCTM_N.RPT_CMF_4,
                    RPT_CMF_5 = :CQCMRPTCTM_N.RPT_CMF_5,
                    COMMENTS = :CQCMRPTCTM_N.COMMENTS,
                    CREATE_USER_ID = :CQCMRPTCTM_N.CREATE_USER_ID,
                    CREATE_TIME = :CQCMRPTCTM_N.CREATE_TIME,
                    UPDATE_USER_ID = :CQCMRPTCTM_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CQCMRPTCTM_N.UPDATE_TIME,
                    RPT_CMF_6  = :CQCMRPTCTM_N.RPT_CMF_6,
                    RPT_CMF_7  = :CQCMRPTCTM_N.RPT_CMF_7,
                    RPT_CMF_8  = :CQCMRPTCTM_N.RPT_CMF_8,
                    RPT_CMF_9  = :CQCMRPTCTM_N.RPT_CMF_9,
                    RPT_CMF_10 = :CQCMRPTCTM_N.RPT_CMF_10,
                    RPT_CMF_11 = :CQCMRPTCTM_N.RPT_CMF_11,
                    RPT_CMF_12 = :CQCMRPTCTM_N.RPT_CMF_12,
                    RPT_CMF_13 = :CQCMRPTCTM_N.RPT_CMF_13,
                    RPT_CMF_14 = :CQCMRPTCTM_N.RPT_CMF_14,
                    RPT_CMF_15 = :CQCMRPTCTM_N.RPT_CMF_15,
                    FIT_STANDARD = :CQCMRPTCTM_N.FIT_STANDARD,
                    FIT_SPEC = :CQCMRPTCTM_N.FIT_SPEC,
                    FIT_MIN_VAL = :CQCMRPTCTM_N.FIT_MIN_VAL,
                    FIT_MAX_VAL = :CQCMRPTCTM_N.FIT_MAX_VAL
                WHERE FACTORY = :CQCMRPTCTM_N.FACTORY
                    AND REPORT_NO = :CQCMRPTCTM_N.REPORT_NO
                    AND PACK_LOT_ID = :CQCMRPTCTM_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :CQCMRPTCTM_N.ORG_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 62;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CQCMRPTCTM  set GRADE=:b0,TYPES=:b1,PACK_\
ORDER_ID=:b2,CUSTOMER_ID=:b3,OD_STANDARD=:b4,OD_SPEC=:b5,OD_MIN_VAL=:b6,OD_MA\
X_VAL=:b7,AT_STANDARD=:b8,AT_SPEC=:b9,AT_MIN_VAL=:b10,AT_MAX_VAL=:b11,GT_STAN\
DARD=:b12,GT_SPEC=:b13,GT_MIN_VAL=:b14,GT_MAX_VAL=:b15,LEN01_STANDARD=:b16,LE\
N01_SPEC=:b17,LEN_MIN_VAL01=:b18,LEN_MAX_VAL01=:b19,LEN02_STANDARD=:b20,LEN02\
_SPEC=:b21,LEN_MIN_VAL02=:b22,LEN_MAX_VAL02=:b23,DMG_STANDARD=:b24,DMG_SPEC=:\
b25,DMG_MIN_VAL=:b26,DMG_MAX_VAL=:b27,RPT_CMF_1=:b28,RPT_CMF_2=:b29,RPT_CMF_3\
=:b30,RPT_CMF_4=:b31,RPT_CMF_5=:b32,COMMENTS=:b33,CREATE_USER_ID=:b34,CREATE_\
TIME=:b35,UPDATE_USER_ID=:b36,UPDATE_TIME=:b37,RPT_CMF_6=:b38,RPT_CMF_7=:b39,\
RPT_CMF_8=:b40,RPT_CMF_9=:b41,RPT_CMF_10=:b42,RPT_CMF_11=:b43,RPT_CMF_12=:b44\
,RPT_CMF_13=:b45,RPT_CMF_14=:b46,RPT_CMF_15=:b47,FIT_STANDARD=:b48,FIT_SPEC=:\
b49,FIT_MIN_VAL=:b50,FIT_MAX_VAL=:b51 where (((FACTORY=:b52 and REPORT_NO=:b5\
3) and PACK_LOT_ID=:b54) and ORG_LOT_ID=:b55)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1133;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTCTM_N.GRADE);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTCTM_N.TYPES);
            sqlstm.sqhstl[1] = (unsigned int  )51;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTCTM_N.PACK_ORDER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTCTM_N.CUSTOMER_ID);
            sqlstm.sqhstl[3] = (unsigned int  )41;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTCTM_N.OD_STANDARD);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTCTM_N.OD_SPEC);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTCTM_N.OD_MIN_VAL);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTCTM_N.OD_MAX_VAL);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTCTM_N.AT_STANDARD);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTCTM_N.AT_SPEC);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTCTM_N.AT_MIN_VAL);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTCTM_N.AT_MAX_VAL);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTCTM_N.GT_STANDARD);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTCTM_N.GT_SPEC);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTCTM_N.GT_MIN_VAL);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTCTM_N.GT_MAX_VAL);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTCTM_N.LEN01_STANDARD);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTCTM_N.LEN01_SPEC);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL01);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL01);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTCTM_N.LEN02_STANDARD);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTCTM_N.LEN02_SPEC);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL02);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL02);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTCTM_N.DMG_STANDARD);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTCTM_N.DMG_SPEC);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTCTM_N.DMG_MIN_VAL);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTCTM_N.DMG_MAX_VAL);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_1);
            sqlstm.sqhstl[28] = (unsigned int  )51;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_2);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_3);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_4);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_5);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTCTM_N.COMMENTS);
            sqlstm.sqhstl[33] = (unsigned int  )101;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTCTM_N.CREATE_USER_ID);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTCTM_N.CREATE_TIME);
            sqlstm.sqhstl[35] = (unsigned int  )15;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTCTM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTCTM_N.UPDATE_TIME);
            sqlstm.sqhstl[37] = (unsigned int  )15;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_6);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_7);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_8);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_9);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_10);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_11);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_12);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_13);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_14);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_15);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTCTM_N.FIT_STANDARD);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTCTM_N.FIT_SPEC);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTCTM_N.FIT_MIN_VAL);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTCTM_N.FIT_MAX_VAL);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[54] = (unsigned int  )26;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
            sqlstm.sqhstl[55] = (unsigned int  )26;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_cqcmrptctm", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cqcmrptctm(int sel_type, struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTCTM_N_TAG CQCMRPTCTM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptctm(&CQCMRPTCTM_N, CQCMRPTCTM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CQCMRPTCTM_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    REPORT_NO,
                    PACK_LOT_ID,
                    ORG_LOT_ID,
                    NVL(GRADE, ' '),
                    NVL(TYPES, ' '),
                    NVL(PACK_ORDER_ID, ' '),
                    NVL(CUSTOMER_ID, ' '),
                    NVL(OD_STANDARD, ' '),
                    NVL(OD_SPEC, ' '),
                    NVL(OD_MIN_VAL, ' '),
                    NVL(OD_MAX_VAL, ' '),
                    NVL(AT_STANDARD, ' '),
                    NVL(AT_SPEC, ' '),
                    NVL(AT_MIN_VAL, ' '),
                    NVL(AT_MAX_VAL, ' '),
                    NVL(GT_STANDARD, ' '),
                    NVL(GT_SPEC, ' '),
                    NVL(GT_MIN_VAL, ' '),
                    NVL(GT_MAX_VAL, ' '),
                    NVL(LEN01_STANDARD, ' '),
                    NVL(LEN01_SPEC, ' '),
                    NVL(LEN_MIN_VAL01, ' '),
                    NVL(LEN_MAX_VAL01, ' '),
                    NVL(LEN02_STANDARD, ' '),
                    NVL(LEN02_SPEC, ' '),
                    NVL(LEN_MIN_VAL02, ' '),
                    NVL(LEN_MAX_VAL02, ' '),
                    NVL(DMG_STANDARD, ' '),
                    NVL(DMG_SPEC, ' '),
                    NVL(DMG_MIN_VAL, ' '),
                    NVL(DMG_MAX_VAL, ' '),
                    NVL(RPT_CMF_1, ' '),
                    NVL(RPT_CMF_2, ' '),
                    NVL(RPT_CMF_3, ' '),
                    NVL(RPT_CMF_4, ' '),
                    NVL(RPT_CMF_5, ' '),
                    NVL(COMMENTS, ' '),
                    NVL(CREATE_USER_ID, ' '),
                    NVL(CREATE_TIME, ' '),
                    NVL(UPDATE_USER_ID, ' '),
                    NVL(UPDATE_TIME, ' '),
                    NVL(RPT_CMF_6, ' '),
                    NVL(RPT_CMF_7, ' '),
                    NVL(RPT_CMF_8, ' '),
                    NVL(RPT_CMF_9, ' '),
                    NVL(RPT_CMF_10, ' '),
                    NVL(RPT_CMF_11, ' '),
                    NVL(RPT_CMF_12, ' '),
                    NVL(RPT_CMF_13, ' '),
                    NVL(RPT_CMF_14, ' '),
                    NVL(RPT_CMF_15, ' '),
                    NVL(FIT_STANDARD, ' '),
                    NVL(FIT_SPEC, ' '),
                    NVL(FIT_MIN_VAL, ' '),
                    NVL(FIT_MAX_VAL, ' ')
                FROM CQCMRPTCTM
                ORDER BY FACTORY ASC,
                    REPORT_NO ASC,
                    PACK_LOT_ID ASC,
                    ORG_LOT_ID ASC; */ 

            /* EXEC SQL OPEN DBU_CQCMRPTCTM_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 62;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,REPORT_NO ,PACK_LOT_ID ,ORG_LOT_ID ,NVL(GRADE\
,' ') ,NVL(TYPES,' ') ,NVL(PACK_ORDER_ID,' ') ,NVL(CUSTOMER_ID,' ') ,NVL(OD_\
STANDARD,' ') ,NVL(OD_SPEC,' ') ,NVL(OD_MIN_VAL,' ') ,NVL(OD_MAX_VAL,' ') ,N\
VL(AT_STANDARD,' ') ,NVL(AT_SPEC,' ') ,NVL(AT_MIN_VAL,' ') ,NVL(AT_MAX_VAL,'\
 ') ,NVL(GT_STANDARD,' ') ,NVL(GT_SPEC,' ') ,NVL(GT_MIN_VAL,' ') ,NVL(GT_MAX\
_VAL,' ') ,NVL(LEN01_STANDARD,' ') ,NVL(LEN01_SPEC,' ') ,NVL(LEN_MIN_VAL01,'\
 ') ,NVL(LEN_MAX_VAL01,' ') ,NVL(LEN02_STANDARD,' ') ,NVL(LEN02_SPEC,' ') ,N\
VL(LEN_MIN_VAL02,' ') ,NVL(LEN_MAX_VAL02,' ') ,NVL(DMG_STANDARD,' ') ,NVL(DM\
G_SPEC,' ') ,NVL(DMG_MIN_VAL,' ') ,NVL(DMG_MAX_VAL,' ') ,NVL(RPT_CMF_1,' ') \
,NVL(RPT_CMF_2,' ') ,NVL(RPT_CMF_3,' ') ,NVL(RPT_CMF_4,' ') ,NVL(RPT_CMF_5,'\
 ') ,NVL(COMMENTS,' ') ,NVL(CREATE_USER_ID,' ') ,NVL(CREATE_TIME,' ') ,NVL(U\
PDATE_USER_ID,' ') ,NVL(UPDATE_TIME,' ') ,NVL(RPT_CMF_6,' ') ,NVL(RPT_CMF_7,\
' ') ,NVL(RPT_CMF_8,' ') ,NVL(RPT_CMF_9,' ') ,NVL(RPT_CMF_10,' ') ,NVL(RPT_C\
MF_11,' ') ,NVL(RPT_CMF_12,' ') ,NVL(RPT_CMF_13,' '");
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1372;
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

    DB_stop_query_timer("DBU_open_cqcmrptctm", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cqcmrptctm(int sel_type, struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTCTM_N_TAG CQCMRPTCTM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CQCMRPTCTM_CUR_1 INTO
                :CQCMRPTCTM_N.FACTORY,
                :CQCMRPTCTM_N.REPORT_NO,
                :CQCMRPTCTM_N.PACK_LOT_ID,
                :CQCMRPTCTM_N.ORG_LOT_ID,
                :CQCMRPTCTM_N.GRADE,
                :CQCMRPTCTM_N.TYPES,
                :CQCMRPTCTM_N.PACK_ORDER_ID,
                :CQCMRPTCTM_N.CUSTOMER_ID,
                :CQCMRPTCTM_N.OD_STANDARD,
                :CQCMRPTCTM_N.OD_SPEC,
                :CQCMRPTCTM_N.OD_MIN_VAL,
                :CQCMRPTCTM_N.OD_MAX_VAL,
                :CQCMRPTCTM_N.AT_STANDARD,
                :CQCMRPTCTM_N.AT_SPEC,
                :CQCMRPTCTM_N.AT_MIN_VAL,
                :CQCMRPTCTM_N.AT_MAX_VAL,
                :CQCMRPTCTM_N.GT_STANDARD,
                :CQCMRPTCTM_N.GT_SPEC,
                :CQCMRPTCTM_N.GT_MIN_VAL,
                :CQCMRPTCTM_N.GT_MAX_VAL,
                :CQCMRPTCTM_N.LEN01_STANDARD,
                :CQCMRPTCTM_N.LEN01_SPEC,
                :CQCMRPTCTM_N.LEN_MIN_VAL01,
                :CQCMRPTCTM_N.LEN_MAX_VAL01,
                :CQCMRPTCTM_N.LEN02_STANDARD,
                :CQCMRPTCTM_N.LEN02_SPEC,
                :CQCMRPTCTM_N.LEN_MIN_VAL02,
                :CQCMRPTCTM_N.LEN_MAX_VAL02,
                :CQCMRPTCTM_N.DMG_STANDARD,
                :CQCMRPTCTM_N.DMG_SPEC,
                :CQCMRPTCTM_N.DMG_MIN_VAL,
                :CQCMRPTCTM_N.DMG_MAX_VAL,
                :CQCMRPTCTM_N.RPT_CMF_1,
                :CQCMRPTCTM_N.RPT_CMF_2,
                :CQCMRPTCTM_N.RPT_CMF_3,
                :CQCMRPTCTM_N.RPT_CMF_4,
                :CQCMRPTCTM_N.RPT_CMF_5,
                :CQCMRPTCTM_N.COMMENTS,
                :CQCMRPTCTM_N.CREATE_USER_ID,
                :CQCMRPTCTM_N.CREATE_TIME,
                :CQCMRPTCTM_N.UPDATE_USER_ID,
                :CQCMRPTCTM_N.UPDATE_TIME,
                :CQCMRPTCTM_N.RPT_CMF_6,
                :CQCMRPTCTM_N.RPT_CMF_7,
                :CQCMRPTCTM_N.RPT_CMF_8,
                :CQCMRPTCTM_N.RPT_CMF_9,
                :CQCMRPTCTM_N.RPT_CMF_10,
                :CQCMRPTCTM_N.RPT_CMF_11,
                :CQCMRPTCTM_N.RPT_CMF_12,
                :CQCMRPTCTM_N.RPT_CMF_13,
                :CQCMRPTCTM_N.RPT_CMF_14,
                :CQCMRPTCTM_N.RPT_CMF_15,
                :CQCMRPTCTM_N.FIT_STANDARD,
                :CQCMRPTCTM_N.FIT_SPEC,
                :CQCMRPTCTM_N.FIT_MIN_VAL,
                :CQCMRPTCTM_N.FIT_MAX_VAL; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 62;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1387;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTCTM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTCTM_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTCTM_N.PACK_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTCTM_N.ORG_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTCTM_N.GRADE);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTCTM_N.TYPES);
            sqlstm.sqhstl[5] = (unsigned int  )51;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTCTM_N.PACK_ORDER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTCTM_N.CUSTOMER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )41;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTCTM_N.OD_STANDARD);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTCTM_N.OD_SPEC);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTCTM_N.OD_MIN_VAL);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTCTM_N.OD_MAX_VAL);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTCTM_N.AT_STANDARD);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTCTM_N.AT_SPEC);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTCTM_N.AT_MIN_VAL);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTCTM_N.AT_MAX_VAL);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTCTM_N.GT_STANDARD);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTCTM_N.GT_SPEC);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTCTM_N.GT_MIN_VAL);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTCTM_N.GT_MAX_VAL);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTCTM_N.LEN01_STANDARD);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTCTM_N.LEN01_SPEC);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL01);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL01);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTCTM_N.LEN02_STANDARD);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTCTM_N.LEN02_SPEC);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTCTM_N.LEN_MIN_VAL02);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTCTM_N.LEN_MAX_VAL02);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTCTM_N.DMG_STANDARD);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTCTM_N.DMG_SPEC);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTCTM_N.DMG_MIN_VAL);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTCTM_N.DMG_MAX_VAL);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTCTM_N.COMMENTS);
            sqlstm.sqhstl[37] = (unsigned int  )101;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTCTM_N.CREATE_USER_ID);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTCTM_N.CREATE_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )15;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTCTM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTCTM_N.UPDATE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )15;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTCTM_N.RPT_CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTCTM_N.FIT_STANDARD);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTCTM_N.FIT_SPEC);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTCTM_N.FIT_MIN_VAL);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTCTM_N.FIT_MAX_VAL);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
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
        DBU_del_null_cqcmrptctm(&CQCMRPTCTM_N, CQCMRPTCTM);
    }

    DB_stop_query_timer("DBU_fetch_cqcmrptctm", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cqcmrptctm(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CQCMRPTCTM_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 62;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1626;
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

    DB_stop_query_timer("DBU_close_cqcmrptctm", sel_type);
}


/* Initialize Function */
void DBU_init_cqcmrptctm(struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    /* memset by Space */
    memset(CQCMRPTCTM, ' ', sizeof(struct CQCMRPTCTM_TAG));
    
}


/* Add Null Function */
void DBU_add_null_cqcmrptctm(struct CQCMRPTCTM_N_TAG *CQCMRPTCTM_N, struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    /* memset by NULL */
    memset(CQCMRPTCTM_N, '\0', sizeof(struct CQCMRPTCTM_N_TAG));
    
    MEMCPY_AN(CQCMRPTCTM_N->FACTORY, CQCMRPTCTM->FACTORY, sizeof(CQCMRPTCTM->FACTORY));
    MEMCPY_AN(CQCMRPTCTM_N->REPORT_NO, CQCMRPTCTM->REPORT_NO, sizeof(CQCMRPTCTM->REPORT_NO));
    MEMCPY_AN(CQCMRPTCTM_N->PACK_LOT_ID, CQCMRPTCTM->PACK_LOT_ID, sizeof(CQCMRPTCTM->PACK_LOT_ID));
    MEMCPY_AN(CQCMRPTCTM_N->ORG_LOT_ID, CQCMRPTCTM->ORG_LOT_ID, sizeof(CQCMRPTCTM->ORG_LOT_ID));
    MEMCPY_AN(CQCMRPTCTM_N->GRADE, CQCMRPTCTM->GRADE, sizeof(CQCMRPTCTM->GRADE));
    MEMCPY_AN(CQCMRPTCTM_N->TYPES, CQCMRPTCTM->TYPES, sizeof(CQCMRPTCTM->TYPES));
    MEMCPY_AN(CQCMRPTCTM_N->PACK_ORDER_ID, CQCMRPTCTM->PACK_ORDER_ID, sizeof(CQCMRPTCTM->PACK_ORDER_ID));
    MEMCPY_AN(CQCMRPTCTM_N->CUSTOMER_ID, CQCMRPTCTM->CUSTOMER_ID, sizeof(CQCMRPTCTM->CUSTOMER_ID));
    MEMCPY_AN(CQCMRPTCTM_N->OD_STANDARD, CQCMRPTCTM->OD_STANDARD, sizeof(CQCMRPTCTM->OD_STANDARD));
    MEMCPY_AN(CQCMRPTCTM_N->OD_SPEC, CQCMRPTCTM->OD_SPEC, sizeof(CQCMRPTCTM->OD_SPEC));
    MEMCPY_AN(CQCMRPTCTM_N->OD_MIN_VAL, CQCMRPTCTM->OD_MIN_VAL, sizeof(CQCMRPTCTM->OD_MIN_VAL));
    MEMCPY_AN(CQCMRPTCTM_N->OD_MAX_VAL, CQCMRPTCTM->OD_MAX_VAL, sizeof(CQCMRPTCTM->OD_MAX_VAL));
    MEMCPY_AN(CQCMRPTCTM_N->AT_STANDARD, CQCMRPTCTM->AT_STANDARD, sizeof(CQCMRPTCTM->AT_STANDARD));
    MEMCPY_AN(CQCMRPTCTM_N->AT_SPEC, CQCMRPTCTM->AT_SPEC, sizeof(CQCMRPTCTM->AT_SPEC));
    MEMCPY_AN(CQCMRPTCTM_N->AT_MIN_VAL, CQCMRPTCTM->AT_MIN_VAL, sizeof(CQCMRPTCTM->AT_MIN_VAL));
    MEMCPY_AN(CQCMRPTCTM_N->AT_MAX_VAL, CQCMRPTCTM->AT_MAX_VAL, sizeof(CQCMRPTCTM->AT_MAX_VAL));
    MEMCPY_AN(CQCMRPTCTM_N->GT_STANDARD, CQCMRPTCTM->GT_STANDARD, sizeof(CQCMRPTCTM->GT_STANDARD));
    MEMCPY_AN(CQCMRPTCTM_N->GT_SPEC, CQCMRPTCTM->GT_SPEC, sizeof(CQCMRPTCTM->GT_SPEC));
    MEMCPY_AN(CQCMRPTCTM_N->GT_MIN_VAL, CQCMRPTCTM->GT_MIN_VAL, sizeof(CQCMRPTCTM->GT_MIN_VAL));
    MEMCPY_AN(CQCMRPTCTM_N->GT_MAX_VAL, CQCMRPTCTM->GT_MAX_VAL, sizeof(CQCMRPTCTM->GT_MAX_VAL));
    MEMCPY_AN(CQCMRPTCTM_N->LEN01_STANDARD, CQCMRPTCTM->LEN01_STANDARD, sizeof(CQCMRPTCTM->LEN01_STANDARD));
    MEMCPY_AN(CQCMRPTCTM_N->LEN01_SPEC, CQCMRPTCTM->LEN01_SPEC, sizeof(CQCMRPTCTM->LEN01_SPEC));
    MEMCPY_AN(CQCMRPTCTM_N->LEN_MIN_VAL01, CQCMRPTCTM->LEN_MIN_VAL01, sizeof(CQCMRPTCTM->LEN_MIN_VAL01));
    MEMCPY_AN(CQCMRPTCTM_N->LEN_MAX_VAL01, CQCMRPTCTM->LEN_MAX_VAL01, sizeof(CQCMRPTCTM->LEN_MAX_VAL01));
    MEMCPY_AN(CQCMRPTCTM_N->LEN02_STANDARD, CQCMRPTCTM->LEN02_STANDARD, sizeof(CQCMRPTCTM->LEN02_STANDARD));
    MEMCPY_AN(CQCMRPTCTM_N->LEN02_SPEC, CQCMRPTCTM->LEN02_SPEC, sizeof(CQCMRPTCTM->LEN02_SPEC));
    MEMCPY_AN(CQCMRPTCTM_N->LEN_MIN_VAL02, CQCMRPTCTM->LEN_MIN_VAL02, sizeof(CQCMRPTCTM->LEN_MIN_VAL02));
    MEMCPY_AN(CQCMRPTCTM_N->LEN_MAX_VAL02, CQCMRPTCTM->LEN_MAX_VAL02, sizeof(CQCMRPTCTM->LEN_MAX_VAL02));
    MEMCPY_AN(CQCMRPTCTM_N->DMG_STANDARD, CQCMRPTCTM->DMG_STANDARD, sizeof(CQCMRPTCTM->DMG_STANDARD));
    MEMCPY_AN(CQCMRPTCTM_N->DMG_SPEC, CQCMRPTCTM->DMG_SPEC, sizeof(CQCMRPTCTM->DMG_SPEC));
    MEMCPY_AN(CQCMRPTCTM_N->DMG_MIN_VAL, CQCMRPTCTM->DMG_MIN_VAL, sizeof(CQCMRPTCTM->DMG_MIN_VAL));
    MEMCPY_AN(CQCMRPTCTM_N->DMG_MAX_VAL, CQCMRPTCTM->DMG_MAX_VAL, sizeof(CQCMRPTCTM->DMG_MAX_VAL));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_1, CQCMRPTCTM->RPT_CMF_1, sizeof(CQCMRPTCTM->RPT_CMF_1));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_2, CQCMRPTCTM->RPT_CMF_2, sizeof(CQCMRPTCTM->RPT_CMF_2));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_3, CQCMRPTCTM->RPT_CMF_3, sizeof(CQCMRPTCTM->RPT_CMF_3));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_4, CQCMRPTCTM->RPT_CMF_4, sizeof(CQCMRPTCTM->RPT_CMF_4));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_5, CQCMRPTCTM->RPT_CMF_5, sizeof(CQCMRPTCTM->RPT_CMF_5));
    MEMCPY_AN(CQCMRPTCTM_N->COMMENTS, CQCMRPTCTM->COMMENTS, sizeof(CQCMRPTCTM->COMMENTS));
    MEMCPY_AN(CQCMRPTCTM_N->CREATE_USER_ID, CQCMRPTCTM->CREATE_USER_ID, sizeof(CQCMRPTCTM->CREATE_USER_ID));
    MEMCPY_AN(CQCMRPTCTM_N->CREATE_TIME, CQCMRPTCTM->CREATE_TIME, sizeof(CQCMRPTCTM->CREATE_TIME));
    MEMCPY_AN(CQCMRPTCTM_N->UPDATE_USER_ID, CQCMRPTCTM->UPDATE_USER_ID, sizeof(CQCMRPTCTM->UPDATE_USER_ID));
    MEMCPY_AN(CQCMRPTCTM_N->UPDATE_TIME, CQCMRPTCTM->UPDATE_TIME, sizeof(CQCMRPTCTM->UPDATE_TIME));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_6, CQCMRPTCTM->RPT_CMF_6, sizeof(CQCMRPTCTM->RPT_CMF_6));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_7, CQCMRPTCTM->RPT_CMF_7, sizeof(CQCMRPTCTM->RPT_CMF_7));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_8, CQCMRPTCTM->RPT_CMF_8, sizeof(CQCMRPTCTM->RPT_CMF_8));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_9, CQCMRPTCTM->RPT_CMF_9, sizeof(CQCMRPTCTM->RPT_CMF_9));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_10, CQCMRPTCTM->RPT_CMF_10, sizeof(CQCMRPTCTM->RPT_CMF_10));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_11, CQCMRPTCTM->RPT_CMF_11, sizeof(CQCMRPTCTM->RPT_CMF_11));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_12, CQCMRPTCTM->RPT_CMF_12, sizeof(CQCMRPTCTM->RPT_CMF_12));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_13, CQCMRPTCTM->RPT_CMF_13, sizeof(CQCMRPTCTM->RPT_CMF_13));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_14, CQCMRPTCTM->RPT_CMF_14, sizeof(CQCMRPTCTM->RPT_CMF_14));
    MEMCPY_AN(CQCMRPTCTM_N->RPT_CMF_15, CQCMRPTCTM->RPT_CMF_15, sizeof(CQCMRPTCTM->RPT_CMF_15));
    MEMCPY_AN(CQCMRPTCTM_N->FIT_STANDARD, CQCMRPTCTM->FIT_STANDARD, sizeof(CQCMRPTCTM->FIT_STANDARD));
    MEMCPY_AN(CQCMRPTCTM_N->FIT_SPEC, CQCMRPTCTM->FIT_SPEC, sizeof(CQCMRPTCTM->FIT_SPEC));
    MEMCPY_AN(CQCMRPTCTM_N->FIT_MIN_VAL, CQCMRPTCTM->FIT_MIN_VAL, sizeof(CQCMRPTCTM->FIT_MIN_VAL));
    MEMCPY_AN(CQCMRPTCTM_N->FIT_MAX_VAL, CQCMRPTCTM->FIT_MAX_VAL, sizeof(CQCMRPTCTM->FIT_MAX_VAL));
}


/* Del Null Function */
void DBU_del_null_cqcmrptctm(struct CQCMRPTCTM_N_TAG *CQCMRPTCTM_N, struct CQCMRPTCTM_TAG *CQCMRPTCTM)
{
    MEMCPY_DN(CQCMRPTCTM->FACTORY, CQCMRPTCTM_N->FACTORY, sizeof(CQCMRPTCTM->FACTORY));
    MEMCPY_DN(CQCMRPTCTM->REPORT_NO, CQCMRPTCTM_N->REPORT_NO, sizeof(CQCMRPTCTM->REPORT_NO));
    MEMCPY_DN(CQCMRPTCTM->PACK_LOT_ID, CQCMRPTCTM_N->PACK_LOT_ID, sizeof(CQCMRPTCTM->PACK_LOT_ID));
    MEMCPY_DN(CQCMRPTCTM->ORG_LOT_ID, CQCMRPTCTM_N->ORG_LOT_ID, sizeof(CQCMRPTCTM->ORG_LOT_ID));
    MEMCPY_DN(CQCMRPTCTM->GRADE, CQCMRPTCTM_N->GRADE, sizeof(CQCMRPTCTM->GRADE));
    MEMCPY_DN(CQCMRPTCTM->TYPES, CQCMRPTCTM_N->TYPES, sizeof(CQCMRPTCTM->TYPES));
    MEMCPY_DN(CQCMRPTCTM->PACK_ORDER_ID, CQCMRPTCTM_N->PACK_ORDER_ID, sizeof(CQCMRPTCTM->PACK_ORDER_ID));
    MEMCPY_DN(CQCMRPTCTM->CUSTOMER_ID, CQCMRPTCTM_N->CUSTOMER_ID, sizeof(CQCMRPTCTM->CUSTOMER_ID));
    MEMCPY_DN(CQCMRPTCTM->OD_STANDARD, CQCMRPTCTM_N->OD_STANDARD, sizeof(CQCMRPTCTM->OD_STANDARD));
    MEMCPY_DN(CQCMRPTCTM->OD_SPEC, CQCMRPTCTM_N->OD_SPEC, sizeof(CQCMRPTCTM->OD_SPEC));
    MEMCPY_DN(CQCMRPTCTM->OD_MIN_VAL, CQCMRPTCTM_N->OD_MIN_VAL, sizeof(CQCMRPTCTM->OD_MIN_VAL));
    MEMCPY_DN(CQCMRPTCTM->OD_MAX_VAL, CQCMRPTCTM_N->OD_MAX_VAL, sizeof(CQCMRPTCTM->OD_MAX_VAL));
    MEMCPY_DN(CQCMRPTCTM->AT_STANDARD, CQCMRPTCTM_N->AT_STANDARD, sizeof(CQCMRPTCTM->AT_STANDARD));
    MEMCPY_DN(CQCMRPTCTM->AT_SPEC, CQCMRPTCTM_N->AT_SPEC, sizeof(CQCMRPTCTM->AT_SPEC));
    MEMCPY_DN(CQCMRPTCTM->AT_MIN_VAL, CQCMRPTCTM_N->AT_MIN_VAL, sizeof(CQCMRPTCTM->AT_MIN_VAL));
    MEMCPY_DN(CQCMRPTCTM->AT_MAX_VAL, CQCMRPTCTM_N->AT_MAX_VAL, sizeof(CQCMRPTCTM->AT_MAX_VAL));
    MEMCPY_DN(CQCMRPTCTM->GT_STANDARD, CQCMRPTCTM_N->GT_STANDARD, sizeof(CQCMRPTCTM->GT_STANDARD));
    MEMCPY_DN(CQCMRPTCTM->GT_SPEC, CQCMRPTCTM_N->GT_SPEC, sizeof(CQCMRPTCTM->GT_SPEC));
    MEMCPY_DN(CQCMRPTCTM->GT_MIN_VAL, CQCMRPTCTM_N->GT_MIN_VAL, sizeof(CQCMRPTCTM->GT_MIN_VAL));
    MEMCPY_DN(CQCMRPTCTM->GT_MAX_VAL, CQCMRPTCTM_N->GT_MAX_VAL, sizeof(CQCMRPTCTM->GT_MAX_VAL));
    MEMCPY_DN(CQCMRPTCTM->LEN01_STANDARD, CQCMRPTCTM_N->LEN01_STANDARD, sizeof(CQCMRPTCTM->LEN01_STANDARD));
    MEMCPY_DN(CQCMRPTCTM->LEN01_SPEC, CQCMRPTCTM_N->LEN01_SPEC, sizeof(CQCMRPTCTM->LEN01_SPEC));
    MEMCPY_DN(CQCMRPTCTM->LEN_MIN_VAL01, CQCMRPTCTM_N->LEN_MIN_VAL01, sizeof(CQCMRPTCTM->LEN_MIN_VAL01));
    MEMCPY_DN(CQCMRPTCTM->LEN_MAX_VAL01, CQCMRPTCTM_N->LEN_MAX_VAL01, sizeof(CQCMRPTCTM->LEN_MAX_VAL01));
    MEMCPY_DN(CQCMRPTCTM->LEN02_STANDARD, CQCMRPTCTM_N->LEN02_STANDARD, sizeof(CQCMRPTCTM->LEN02_STANDARD));
    MEMCPY_DN(CQCMRPTCTM->LEN02_SPEC, CQCMRPTCTM_N->LEN02_SPEC, sizeof(CQCMRPTCTM->LEN02_SPEC));
    MEMCPY_DN(CQCMRPTCTM->LEN_MIN_VAL02, CQCMRPTCTM_N->LEN_MIN_VAL02, sizeof(CQCMRPTCTM->LEN_MIN_VAL02));
    MEMCPY_DN(CQCMRPTCTM->LEN_MAX_VAL02, CQCMRPTCTM_N->LEN_MAX_VAL02, sizeof(CQCMRPTCTM->LEN_MAX_VAL02));
    MEMCPY_DN(CQCMRPTCTM->DMG_STANDARD, CQCMRPTCTM_N->DMG_STANDARD, sizeof(CQCMRPTCTM->DMG_STANDARD));
    MEMCPY_DN(CQCMRPTCTM->DMG_SPEC, CQCMRPTCTM_N->DMG_SPEC, sizeof(CQCMRPTCTM->DMG_SPEC));
    MEMCPY_DN(CQCMRPTCTM->DMG_MIN_VAL, CQCMRPTCTM_N->DMG_MIN_VAL, sizeof(CQCMRPTCTM->DMG_MIN_VAL));
    MEMCPY_DN(CQCMRPTCTM->DMG_MAX_VAL, CQCMRPTCTM_N->DMG_MAX_VAL, sizeof(CQCMRPTCTM->DMG_MAX_VAL));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_1, CQCMRPTCTM_N->RPT_CMF_1, sizeof(CQCMRPTCTM->RPT_CMF_1));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_2, CQCMRPTCTM_N->RPT_CMF_2, sizeof(CQCMRPTCTM->RPT_CMF_2));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_3, CQCMRPTCTM_N->RPT_CMF_3, sizeof(CQCMRPTCTM->RPT_CMF_3));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_4, CQCMRPTCTM_N->RPT_CMF_4, sizeof(CQCMRPTCTM->RPT_CMF_4));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_5, CQCMRPTCTM_N->RPT_CMF_5, sizeof(CQCMRPTCTM->RPT_CMF_5));
    MEMCPY_DN(CQCMRPTCTM->COMMENTS, CQCMRPTCTM_N->COMMENTS, sizeof(CQCMRPTCTM->COMMENTS));
    MEMCPY_DN(CQCMRPTCTM->CREATE_USER_ID, CQCMRPTCTM_N->CREATE_USER_ID, sizeof(CQCMRPTCTM->CREATE_USER_ID));
    MEMCPY_DN(CQCMRPTCTM->CREATE_TIME, CQCMRPTCTM_N->CREATE_TIME, sizeof(CQCMRPTCTM->CREATE_TIME));
    MEMCPY_DN(CQCMRPTCTM->UPDATE_USER_ID, CQCMRPTCTM_N->UPDATE_USER_ID, sizeof(CQCMRPTCTM->UPDATE_USER_ID));
    MEMCPY_DN(CQCMRPTCTM->UPDATE_TIME, CQCMRPTCTM_N->UPDATE_TIME, sizeof(CQCMRPTCTM->UPDATE_TIME));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_6, CQCMRPTCTM_N->RPT_CMF_6, sizeof(CQCMRPTCTM->RPT_CMF_6));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_7, CQCMRPTCTM_N->RPT_CMF_7, sizeof(CQCMRPTCTM->RPT_CMF_7));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_8, CQCMRPTCTM_N->RPT_CMF_8, sizeof(CQCMRPTCTM->RPT_CMF_8));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_9, CQCMRPTCTM_N->RPT_CMF_9, sizeof(CQCMRPTCTM->RPT_CMF_9));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_10, CQCMRPTCTM_N->RPT_CMF_10, sizeof(CQCMRPTCTM->RPT_CMF_10));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_11, CQCMRPTCTM_N->RPT_CMF_11, sizeof(CQCMRPTCTM->RPT_CMF_11));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_12, CQCMRPTCTM_N->RPT_CMF_12, sizeof(CQCMRPTCTM->RPT_CMF_12));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_13, CQCMRPTCTM_N->RPT_CMF_13, sizeof(CQCMRPTCTM->RPT_CMF_13));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_14, CQCMRPTCTM_N->RPT_CMF_14, sizeof(CQCMRPTCTM->RPT_CMF_14));
    MEMCPY_DN(CQCMRPTCTM->RPT_CMF_15, CQCMRPTCTM_N->RPT_CMF_15, sizeof(CQCMRPTCTM->RPT_CMF_15));
    MEMCPY_DN(CQCMRPTCTM->FIT_STANDARD, CQCMRPTCTM_N->FIT_STANDARD, sizeof(CQCMRPTCTM->FIT_STANDARD));
    MEMCPY_DN(CQCMRPTCTM->FIT_SPEC, CQCMRPTCTM_N->FIT_SPEC, sizeof(CQCMRPTCTM->FIT_SPEC));
    MEMCPY_DN(CQCMRPTCTM->FIT_MIN_VAL, CQCMRPTCTM_N->FIT_MIN_VAL, sizeof(CQCMRPTCTM->FIT_MIN_VAL));
    MEMCPY_DN(CQCMRPTCTM->FIT_MAX_VAL, CQCMRPTCTM_N->FIT_MAX_VAL, sizeof(CQCMRPTCTM->FIT_MAX_VAL));
}


