
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
    "DBU_cwiplotcup.pc"
};


static unsigned int sqlctx = 9397835;


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
            void  *sqhstv[67];
   unsigned int   sqhstl[67];
            int   sqhsts[67];
            void  *sqindv[67];
            int   sqinds[67];
   unsigned int   sqharm[67];
   unsigned int   *sqharc[67];
   unsigned short  sqadto[67];
   unsigned short  sqtdso[67];
} sqlstm = {13,67};

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
"_TIME  from CWIPLOTCUP  order by LOT\
_ID asc ,HIST_SEQ asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1402,0,4,46,0,0,67,2,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,
288,0,0,2,1414,0,4,217,0,0,67,2,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,
0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,
571,0,0,3,78,0,4,391,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,
598,0,0,4,60,0,2,428,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
621,0,0,5,1307,0,3,458,0,0,65,65,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,
0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
896,0,0,6,1308,0,5,613,0,0,65,65,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,
4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,
4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1171,0,0,7,1094,0,9,779,0,0,0,0,0,1,0,
1186,0,0,7,0,0,13,808,0,0,65,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,
0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1461,0,0,7,0,0,15,903,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cwiplotcup.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-10-15 15:56:47
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
void DBU_add_null_cwiplotcup(struct CWIPLOTCUP_N_TAG *CWIPLOTCUP_N, struct CWIPLOTCUP_TAG *CWIPLOTCUP);
void DBU_del_null_cwiplotcup(struct CWIPLOTCUP_N_TAG *CWIPLOTCUP_N, struct CWIPLOTCUP_TAG *CWIPLOTCUP);


/* SQL SELECT Function */
void DBU_select_cwiplotcup(int sel_type, struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPLOTCUP_N_TAG CWIPLOTCUP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwiplotcup(&CWIPLOTCUP_N, CWIPLOTCUP);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    LOT_ID,
                    HIST_SEQ,
                    OPER,
                    MAT_ID,
                    FLOW,
                    FLOW_SEQ_NUM,
                    GRADE,
                    RES_ID,
                    FACTORY,
                    WORK_DATE,
                    WORK_TIME,
                    DAY_NIGHT,
                    EDC_HIST_SEQ,
                    MASTER_LOT_ID,
                    RECIPE_ID,
                    START_TIME,
                    END_TIME,
                    JUDGMENT,
                    INPUT_TIME,
                    CUP_INPUT_COUNTER,
                    CUP_TYPE,
                    CUP_WEIGHT_STANDARD,
                    CUP_WEIGHT_VALUE,
                    POWDER_INJECTION_LOCATION,
                    ROBOT_MEASURABLE_STANDARD,
                    ROBOT_MEASURABLE_VALUE,
                    PRECISION_WEIGH_STANDARD,
                    PRECISION_WEIGH_VALUE,
                    PRESS_TIME,
                    NUMBER_OF_PRESSES,
                    KNIFE_FLATTENING_USE,
                    CARBIDE_TYPE,
                    CARBIDE_SAMPLE_PASSED_NO,
                    CARBIDE_SAMPLE_RESULT,
                    CARBIDE_WEIGHT_STANDARD,
                    CARBIDE_WEIGHT_VALUE,
                    CARBIDE_HEIGHT_STANDARD,
                    CARBIDE_HEIGHT_P1,
                    CARBIDE_HEIGHT_P2,
                    CARBIDE_HEIGHT_P3,
                    CARBIDE_HEIGHT_P4,
                    CARBIDE_HEIGHT_P5,
                    CARBIDE_OUTER_DIAMETER_STANDARD,
                    CARBIDE_OUTER_DIAMETER_VALUE,
                    COMPLETE_FLATNESS_STANDARD,
                    COMPLETE_FLATNESS_VALUE,
                    COMPLETE_WEIGHT_STANDARD,
                    COMPLETE_WEIGHT_VALUE,
                    CARBIDE_INPUT_COUNT,
                    IMPACT_PROCESS_INPUT_COUNT,
                    NG_COUND,
                    CMF_1,
                    CMF_2,
                    CMF_3,
                    CMF_4,
                    CMF_5,
                    CMF_6,
                    CMF_7,
                    CMF_8,
                    CMF_9,
                    CMF_10,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :CWIPLOTCUP_N.LOT_ID,
                    :CWIPLOTCUP_N.HIST_SEQ,
                    :CWIPLOTCUP_N.OPER,
                    :CWIPLOTCUP_N.MAT_ID,
                    :CWIPLOTCUP_N.FLOW,
                    :CWIPLOTCUP_N.FLOW_SEQ_NUM,
                    :CWIPLOTCUP_N.GRADE,
                    :CWIPLOTCUP_N.RES_ID,
                    :CWIPLOTCUP_N.FACTORY,
                    :CWIPLOTCUP_N.WORK_DATE,
                    :CWIPLOTCUP_N.WORK_TIME,
                    :CWIPLOTCUP_N.DAY_NIGHT,
                    :CWIPLOTCUP_N.EDC_HIST_SEQ,
                    :CWIPLOTCUP_N.MASTER_LOT_ID,
                    :CWIPLOTCUP_N.RECIPE_ID,
                    :CWIPLOTCUP_N.START_TIME,
                    :CWIPLOTCUP_N.END_TIME,
                    :CWIPLOTCUP_N.JUDGMENT,
                    :CWIPLOTCUP_N.INPUT_TIME,
                    :CWIPLOTCUP_N.CUP_INPUT_COUNTER,
                    :CWIPLOTCUP_N.CUP_TYPE,
                    :CWIPLOTCUP_N.CUP_WEIGHT_STANDARD,
                    :CWIPLOTCUP_N.CUP_WEIGHT_VALUE,
                    :CWIPLOTCUP_N.POWDER_INJECTION_LOCATION,
                    :CWIPLOTCUP_N.ROBOT_MEASURABLE_STANDARD,
                    :CWIPLOTCUP_N.ROBOT_MEASURABLE_VALUE,
                    :CWIPLOTCUP_N.PRECISION_WEIGH_STANDARD,
                    :CWIPLOTCUP_N.PRECISION_WEIGH_VALUE,
                    :CWIPLOTCUP_N.PRESS_TIME,
                    :CWIPLOTCUP_N.NUMBER_OF_PRESSES,
                    :CWIPLOTCUP_N.KNIFE_FLATTENING_USE,
                    :CWIPLOTCUP_N.CARBIDE_TYPE,
                    :CWIPLOTCUP_N.CARBIDE_SAMPLE_PASSED_NO,
                    :CWIPLOTCUP_N.CARBIDE_SAMPLE_RESULT,
                    :CWIPLOTCUP_N.CARBIDE_WEIGHT_STANDARD,
                    :CWIPLOTCUP_N.CARBIDE_WEIGHT_VALUE,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_STANDARD,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P1,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P2,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P3,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P4,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P5,
                    :CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_STANDARD,
                    :CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_VALUE,
                    :CWIPLOTCUP_N.COMPLETE_FLATNESS_STANDARD,
                    :CWIPLOTCUP_N.COMPLETE_FLATNESS_VALUE,
                    :CWIPLOTCUP_N.COMPLETE_WEIGHT_STANDARD,
                    :CWIPLOTCUP_N.COMPLETE_WEIGHT_VALUE,
                    :CWIPLOTCUP_N.CARBIDE_INPUT_COUNT,
                    :CWIPLOTCUP_N.IMPACT_PROCESS_INPUT_COUNT,
                    :CWIPLOTCUP_N.NG_COUND,
                    :CWIPLOTCUP_N.CMF_1,
                    :CWIPLOTCUP_N.CMF_2,
                    :CWIPLOTCUP_N.CMF_3,
                    :CWIPLOTCUP_N.CMF_4,
                    :CWIPLOTCUP_N.CMF_5,
                    :CWIPLOTCUP_N.CMF_6,
                    :CWIPLOTCUP_N.CMF_7,
                    :CWIPLOTCUP_N.CMF_8,
                    :CWIPLOTCUP_N.CMF_9,
                    :CWIPLOTCUP_N.CMF_10,
                    :CWIPLOTCUP_N.CREATE_USER_ID,
                    :CWIPLOTCUP_N.CREATE_TIME,
                    :CWIPLOTCUP_N.UPDATE_USER_ID,
                    :CWIPLOTCUP_N.UPDATE_TIME
                FROM CWIPLOTCUP
                WHERE LOT_ID = :CWIPLOTCUP_N.LOT_ID
                    AND HIST_SEQ = :CWIPLOTCUP_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select LOT_ID ,HIST_SEQ ,OPER ,MAT_ID ,FLOW ,FLOW_SEQ_NUM ,GR\
ADE ,RES_ID ,FACTORY ,WORK_DATE ,WORK_TIME ,DAY_NIGHT ,EDC_HIST_SEQ ,MASTER_\
LOT_ID ,RECIPE_ID ,START_TIME ,END_TIME ,JUDGMENT ,INPUT_TIME ,CUP_INPUT_COU\
NTER ,CUP_TYPE ,CUP_WEIGHT_STANDARD ,CUP_WEIGHT_VALUE ,POWDER_INJECTION_LOCA\
TION ,ROBOT_MEASURABLE_STANDARD ,ROBOT_MEASURABLE_VALUE ,PRECISION_WEIGH_STA\
NDARD ,PRECISION_WEIGH_VALUE ,PRESS_TIME ,NUMBER_OF_PRESSES ,KNIFE_FLATTENIN\
G_USE ,CARBIDE_TYPE ,CARBIDE_SAMPLE_PASSED_NO ,CARBIDE_SAMPLE_RESULT ,CARBID\
E_WEIGHT_STANDARD ,CARBIDE_WEIGHT_VALUE ,CARBIDE_HEIGHT_STANDARD ,CARBIDE_HE\
IGHT_P1 ,CARBIDE_HEIGHT_P2 ,CARBIDE_HEIGHT_P3 ,CARBIDE_HEIGHT_P4 ,CARBIDE_HE\
IGHT_P5 ,CARBIDE_OUTER_DIAMETER_STANDARD ,CARBIDE_OUTER_DIAMETER_VALUE ,COMP\
LETE_FLATNESS_STANDARD ,COMPLETE_FLATNESS_VALUE ,COMPLETE_WEIGHT_STANDARD ,C\
OMPLETE_WEIGHT_VALUE ,CARBIDE_INPUT_COUNT ,IMPACT_PROCESS_INPUT_COUNT ,NG_CO\
UND ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,\
CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE");
            sqlstm.stmt = "_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:\
b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24\
,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:\
b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b5\
5,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64  from CWIPLOTCUP where (LOT_ID\
=:b0 and HIST_SEQ=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPLOTCUP_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CWIPLOTCUP_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPLOTCUP_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPLOTCUP_N.MAT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPLOTCUP_N.FLOW);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CWIPLOTCUP_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPLOTCUP_N.GRADE);
            sqlstm.sqhstl[6] = (unsigned int  )51;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPLOTCUP_N.RES_ID);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPLOTCUP_N.FACTORY);
            sqlstm.sqhstl[8] = (unsigned int  )11;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPLOTCUP_N.WORK_DATE);
            sqlstm.sqhstl[9] = (unsigned int  )9;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CWIPLOTCUP_N.WORK_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CWIPLOTCUP_N.DAY_NIGHT);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CWIPLOTCUP_N.EDC_HIST_SEQ);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPLOTCUP_N.MASTER_LOT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CWIPLOTCUP_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )51;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPLOTCUP_N.START_TIME);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPLOTCUP_N.END_TIME);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CWIPLOTCUP_N.JUDGMENT);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPLOTCUP_N.INPUT_TIME);
            sqlstm.sqhstl[18] = (unsigned int  )15;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CWIPLOTCUP_N.CUP_INPUT_COUNTER);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CWIPLOTCUP_N.CUP_TYPE);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(CWIPLOTCUP_N.CUP_WEIGHT_STANDARD);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CWIPLOTCUP_N.CUP_WEIGHT_VALUE);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CWIPLOTCUP_N.POWDER_INJECTION_LOCATION);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(CWIPLOTCUP_N.ROBOT_MEASURABLE_STANDARD);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(CWIPLOTCUP_N.ROBOT_MEASURABLE_VALUE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(CWIPLOTCUP_N.PRECISION_WEIGH_STANDARD);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CWIPLOTCUP_N.PRECISION_WEIGH_VALUE);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPLOTCUP_N.PRESS_TIME);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(CWIPLOTCUP_N.NUMBER_OF_PRESSES);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CWIPLOTCUP_N.KNIFE_FLATTENING_USE);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPLOTCUP_N.CARBIDE_TYPE);
            sqlstm.sqhstl[31] = (unsigned int  )11;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_SAMPLE_PASSED_NO);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CWIPLOTCUP_N.CARBIDE_SAMPLE_RESULT);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_WEIGHT_STANDARD);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_WEIGHT_VALUE);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_STANDARD);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P1);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P2);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P3);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P4);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P5);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_STANDARD);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_VALUE);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_FLATNESS_STANDARD);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_FLATNESS_VALUE);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_WEIGHT_STANDARD);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_WEIGHT_VALUE);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_INPUT_COUNT);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(CWIPLOTCUP_N.IMPACT_PROCESS_INPUT_COUNT);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(CWIPLOTCUP_N.NG_COUND);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CWIPLOTCUP_N.CMF_1);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CWIPLOTCUP_N.CMF_2);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CWIPLOTCUP_N.CMF_3);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CWIPLOTCUP_N.CMF_4);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CWIPLOTCUP_N.CMF_5);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CWIPLOTCUP_N.CMF_6);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CWIPLOTCUP_N.CMF_7);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CWIPLOTCUP_N.CMF_8);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CWIPLOTCUP_N.CMF_9);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CWIPLOTCUP_N.CMF_10);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CWIPLOTCUP_N.CREATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CWIPLOTCUP_N.CREATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CWIPLOTCUP_N.UPDATE_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CWIPLOTCUP_N.UPDATE_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CWIPLOTCUP_N.LOT_ID);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(CWIPLOTCUP_N.HIST_SEQ);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
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
        DBU_del_null_cwiplotcup(&CWIPLOTCUP_N, CWIPLOTCUP);
    }

    DB_stop_query_timer("DBU_select_cwiplotcup", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cwiplotcup_for_update(int sel_type, struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPLOTCUP_N_TAG CWIPLOTCUP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwiplotcup(&CWIPLOTCUP_N, CWIPLOTCUP);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    LOT_ID,
                    HIST_SEQ,
                    OPER,
                    MAT_ID,
                    FLOW,
                    FLOW_SEQ_NUM,
                    GRADE,
                    RES_ID,
                    FACTORY,
                    WORK_DATE,
                    WORK_TIME,
                    DAY_NIGHT,
                    EDC_HIST_SEQ,
                    MASTER_LOT_ID,
                    RECIPE_ID,
                    START_TIME,
                    END_TIME,
                    JUDGMENT,
                    INPUT_TIME,
                    CUP_INPUT_COUNTER,
                    CUP_TYPE,
                    CUP_WEIGHT_STANDARD,
                    CUP_WEIGHT_VALUE,
                    POWDER_INJECTION_LOCATION,
                    ROBOT_MEASURABLE_STANDARD,
                    ROBOT_MEASURABLE_VALUE,
                    PRECISION_WEIGH_STANDARD,
                    PRECISION_WEIGH_VALUE,
                    PRESS_TIME,
                    NUMBER_OF_PRESSES,
                    KNIFE_FLATTENING_USE,
                    CARBIDE_TYPE,
                    CARBIDE_SAMPLE_PASSED_NO,
                    CARBIDE_SAMPLE_RESULT,
                    CARBIDE_WEIGHT_STANDARD,
                    CARBIDE_WEIGHT_VALUE,
                    CARBIDE_HEIGHT_STANDARD,
                    CARBIDE_HEIGHT_P1,
                    CARBIDE_HEIGHT_P2,
                    CARBIDE_HEIGHT_P3,
                    CARBIDE_HEIGHT_P4,
                    CARBIDE_HEIGHT_P5,
                    CARBIDE_OUTER_DIAMETER_STANDARD,
                    CARBIDE_OUTER_DIAMETER_VALUE,
                    COMPLETE_FLATNESS_STANDARD,
                    COMPLETE_FLATNESS_VALUE,
                    COMPLETE_WEIGHT_STANDARD,
                    COMPLETE_WEIGHT_VALUE,
                    CARBIDE_INPUT_COUNT,
                    IMPACT_PROCESS_INPUT_COUNT,
                    NG_COUND,
                    CMF_1,
                    CMF_2,
                    CMF_3,
                    CMF_4,
                    CMF_5,
                    CMF_6,
                    CMF_7,
                    CMF_8,
                    CMF_9,
                    CMF_10,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :CWIPLOTCUP_N.LOT_ID,
                    :CWIPLOTCUP_N.HIST_SEQ,
                    :CWIPLOTCUP_N.OPER,
                    :CWIPLOTCUP_N.MAT_ID,
                    :CWIPLOTCUP_N.FLOW,
                    :CWIPLOTCUP_N.FLOW_SEQ_NUM,
                    :CWIPLOTCUP_N.GRADE,
                    :CWIPLOTCUP_N.RES_ID,
                    :CWIPLOTCUP_N.FACTORY,
                    :CWIPLOTCUP_N.WORK_DATE,
                    :CWIPLOTCUP_N.WORK_TIME,
                    :CWIPLOTCUP_N.DAY_NIGHT,
                    :CWIPLOTCUP_N.EDC_HIST_SEQ,
                    :CWIPLOTCUP_N.MASTER_LOT_ID,
                    :CWIPLOTCUP_N.RECIPE_ID,
                    :CWIPLOTCUP_N.START_TIME,
                    :CWIPLOTCUP_N.END_TIME,
                    :CWIPLOTCUP_N.JUDGMENT,
                    :CWIPLOTCUP_N.INPUT_TIME,
                    :CWIPLOTCUP_N.CUP_INPUT_COUNTER,
                    :CWIPLOTCUP_N.CUP_TYPE,
                    :CWIPLOTCUP_N.CUP_WEIGHT_STANDARD,
                    :CWIPLOTCUP_N.CUP_WEIGHT_VALUE,
                    :CWIPLOTCUP_N.POWDER_INJECTION_LOCATION,
                    :CWIPLOTCUP_N.ROBOT_MEASURABLE_STANDARD,
                    :CWIPLOTCUP_N.ROBOT_MEASURABLE_VALUE,
                    :CWIPLOTCUP_N.PRECISION_WEIGH_STANDARD,
                    :CWIPLOTCUP_N.PRECISION_WEIGH_VALUE,
                    :CWIPLOTCUP_N.PRESS_TIME,
                    :CWIPLOTCUP_N.NUMBER_OF_PRESSES,
                    :CWIPLOTCUP_N.KNIFE_FLATTENING_USE,
                    :CWIPLOTCUP_N.CARBIDE_TYPE,
                    :CWIPLOTCUP_N.CARBIDE_SAMPLE_PASSED_NO,
                    :CWIPLOTCUP_N.CARBIDE_SAMPLE_RESULT,
                    :CWIPLOTCUP_N.CARBIDE_WEIGHT_STANDARD,
                    :CWIPLOTCUP_N.CARBIDE_WEIGHT_VALUE,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_STANDARD,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P1,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P2,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P3,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P4,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P5,
                    :CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_STANDARD,
                    :CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_VALUE,
                    :CWIPLOTCUP_N.COMPLETE_FLATNESS_STANDARD,
                    :CWIPLOTCUP_N.COMPLETE_FLATNESS_VALUE,
                    :CWIPLOTCUP_N.COMPLETE_WEIGHT_STANDARD,
                    :CWIPLOTCUP_N.COMPLETE_WEIGHT_VALUE,
                    :CWIPLOTCUP_N.CARBIDE_INPUT_COUNT,
                    :CWIPLOTCUP_N.IMPACT_PROCESS_INPUT_COUNT,
                    :CWIPLOTCUP_N.NG_COUND,
                    :CWIPLOTCUP_N.CMF_1,
                    :CWIPLOTCUP_N.CMF_2,
                    :CWIPLOTCUP_N.CMF_3,
                    :CWIPLOTCUP_N.CMF_4,
                    :CWIPLOTCUP_N.CMF_5,
                    :CWIPLOTCUP_N.CMF_6,
                    :CWIPLOTCUP_N.CMF_7,
                    :CWIPLOTCUP_N.CMF_8,
                    :CWIPLOTCUP_N.CMF_9,
                    :CWIPLOTCUP_N.CMF_10,
                    :CWIPLOTCUP_N.CREATE_USER_ID,
                    :CWIPLOTCUP_N.CREATE_TIME,
                    :CWIPLOTCUP_N.UPDATE_USER_ID,
                    :CWIPLOTCUP_N.UPDATE_TIME
                FROM CWIPLOTCUP
                WHERE LOT_ID = :CWIPLOTCUP_N.LOT_ID
                    AND HIST_SEQ = :CWIPLOTCUP_N.HIST_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select LOT_ID ,HIST_SEQ ,OPER ,MAT_ID ,FLOW ,FLOW_SEQ_NUM ,GR\
ADE ,RES_ID ,FACTORY ,WORK_DATE ,WORK_TIME ,DAY_NIGHT ,EDC_HIST_SEQ ,MASTER_\
LOT_ID ,RECIPE_ID ,START_TIME ,END_TIME ,JUDGMENT ,INPUT_TIME ,CUP_INPUT_COU\
NTER ,CUP_TYPE ,CUP_WEIGHT_STANDARD ,CUP_WEIGHT_VALUE ,POWDER_INJECTION_LOCA\
TION ,ROBOT_MEASURABLE_STANDARD ,ROBOT_MEASURABLE_VALUE ,PRECISION_WEIGH_STA\
NDARD ,PRECISION_WEIGH_VALUE ,PRESS_TIME ,NUMBER_OF_PRESSES ,KNIFE_FLATTENIN\
G_USE ,CARBIDE_TYPE ,CARBIDE_SAMPLE_PASSED_NO ,CARBIDE_SAMPLE_RESULT ,CARBID\
E_WEIGHT_STANDARD ,CARBIDE_WEIGHT_VALUE ,CARBIDE_HEIGHT_STANDARD ,CARBIDE_HE\
IGHT_P1 ,CARBIDE_HEIGHT_P2 ,CARBIDE_HEIGHT_P3 ,CARBIDE_HEIGHT_P4 ,CARBIDE_HE\
IGHT_P5 ,CARBIDE_OUTER_DIAMETER_STANDARD ,CARBIDE_OUTER_DIAMETER_VALUE ,COMP\
LETE_FLATNESS_STANDARD ,COMPLETE_FLATNESS_VALUE ,COMPLETE_WEIGHT_STANDARD ,C\
OMPLETE_WEIGHT_VALUE ,CARBIDE_INPUT_COUNT ,IMPACT_PROCESS_INPUT_COUNT ,NG_CO\
UND ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,\
CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE");
            sqlstm.stmt = "_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:\
b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24\
,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:\
b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b5\
5,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64  from CWIPLOTCUP where (LOT_ID\
=:b0 and HIST_SEQ=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )288;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPLOTCUP_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CWIPLOTCUP_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPLOTCUP_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPLOTCUP_N.MAT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPLOTCUP_N.FLOW);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CWIPLOTCUP_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPLOTCUP_N.GRADE);
            sqlstm.sqhstl[6] = (unsigned int  )51;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPLOTCUP_N.RES_ID);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPLOTCUP_N.FACTORY);
            sqlstm.sqhstl[8] = (unsigned int  )11;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPLOTCUP_N.WORK_DATE);
            sqlstm.sqhstl[9] = (unsigned int  )9;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CWIPLOTCUP_N.WORK_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CWIPLOTCUP_N.DAY_NIGHT);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CWIPLOTCUP_N.EDC_HIST_SEQ);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPLOTCUP_N.MASTER_LOT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CWIPLOTCUP_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )51;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPLOTCUP_N.START_TIME);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPLOTCUP_N.END_TIME);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CWIPLOTCUP_N.JUDGMENT);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPLOTCUP_N.INPUT_TIME);
            sqlstm.sqhstl[18] = (unsigned int  )15;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CWIPLOTCUP_N.CUP_INPUT_COUNTER);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CWIPLOTCUP_N.CUP_TYPE);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(CWIPLOTCUP_N.CUP_WEIGHT_STANDARD);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CWIPLOTCUP_N.CUP_WEIGHT_VALUE);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CWIPLOTCUP_N.POWDER_INJECTION_LOCATION);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(CWIPLOTCUP_N.ROBOT_MEASURABLE_STANDARD);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(CWIPLOTCUP_N.ROBOT_MEASURABLE_VALUE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(CWIPLOTCUP_N.PRECISION_WEIGH_STANDARD);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CWIPLOTCUP_N.PRECISION_WEIGH_VALUE);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPLOTCUP_N.PRESS_TIME);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(CWIPLOTCUP_N.NUMBER_OF_PRESSES);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CWIPLOTCUP_N.KNIFE_FLATTENING_USE);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPLOTCUP_N.CARBIDE_TYPE);
            sqlstm.sqhstl[31] = (unsigned int  )11;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_SAMPLE_PASSED_NO);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CWIPLOTCUP_N.CARBIDE_SAMPLE_RESULT);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_WEIGHT_STANDARD);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_WEIGHT_VALUE);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_STANDARD);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P1);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P2);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P3);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P4);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P5);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_STANDARD);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_VALUE);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_FLATNESS_STANDARD);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_FLATNESS_VALUE);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_WEIGHT_STANDARD);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_WEIGHT_VALUE);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_INPUT_COUNT);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(CWIPLOTCUP_N.IMPACT_PROCESS_INPUT_COUNT);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(CWIPLOTCUP_N.NG_COUND);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CWIPLOTCUP_N.CMF_1);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CWIPLOTCUP_N.CMF_2);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CWIPLOTCUP_N.CMF_3);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CWIPLOTCUP_N.CMF_4);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CWIPLOTCUP_N.CMF_5);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CWIPLOTCUP_N.CMF_6);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CWIPLOTCUP_N.CMF_7);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CWIPLOTCUP_N.CMF_8);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CWIPLOTCUP_N.CMF_9);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CWIPLOTCUP_N.CMF_10);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CWIPLOTCUP_N.CREATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CWIPLOTCUP_N.CREATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CWIPLOTCUP_N.UPDATE_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CWIPLOTCUP_N.UPDATE_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CWIPLOTCUP_N.LOT_ID);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(CWIPLOTCUP_N.HIST_SEQ);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
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
        DBU_del_null_cwiplotcup(&CWIPLOTCUP_N, CWIPLOTCUP);
    }

    DB_stop_query_timer("DBU_select_cwiplotcup_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cwiplotcup_scalar(int sel_type, struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPLOTCUP_N_TAG CWIPLOTCUP_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwiplotcup(&CWIPLOTCUP_N, CWIPLOTCUP);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CWIPLOTCUP
                WHERE LOT_ID = :CWIPLOTCUP_N.LOT_ID
                    AND HIST_SEQ = :CWIPLOTCUP_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CWIPLOTCUP where\
 (LOT_ID=:b1 and HIST_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )571;
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
            sqlstm.sqhstv[1] = (         void  *)(CWIPLOTCUP_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CWIPLOTCUP_N.HIST_SEQ);
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

    DB_stop_query_timer("DBU_select_cwiplotcup_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cwiplotcup(int sel_type, struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPLOTCUP_N_TAG CWIPLOTCUP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwiplotcup(&CWIPLOTCUP_N, CWIPLOTCUP);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CWIPLOTCUP
                WHERE LOT_ID = :CWIPLOTCUP_N.LOT_ID
                    AND HIST_SEQ = :CWIPLOTCUP_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CWIPLOTCUP  where (LOT_ID=:b0 and H\
IST_SEQ=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )598;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPLOTCUP_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CWIPLOTCUP_N.HIST_SEQ);
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

    DB_stop_query_timer("DBU_delete_cwiplotcup", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cwiplotcup(struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPLOTCUP_N_TAG CWIPLOTCUP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwiplotcup(&CWIPLOTCUP_N, CWIPLOTCUP);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CWIPLOTCUP( 
                    LOT_ID, 
                    HIST_SEQ, 
                    OPER, 
                    MAT_ID, 
                    FLOW, 
                    FLOW_SEQ_NUM, 
                    GRADE, 
                    RES_ID, 
                    FACTORY, 
                    WORK_DATE, 
                    WORK_TIME, 
                    DAY_NIGHT, 
                    EDC_HIST_SEQ, 
                    MASTER_LOT_ID, 
                    RECIPE_ID, 
                    START_TIME, 
                    END_TIME, 
                    JUDGMENT, 
                    INPUT_TIME, 
                    CUP_INPUT_COUNTER, 
                    CUP_TYPE, 
                    CUP_WEIGHT_STANDARD, 
                    CUP_WEIGHT_VALUE, 
                    POWDER_INJECTION_LOCATION, 
                    ROBOT_MEASURABLE_STANDARD, 
                    ROBOT_MEASURABLE_VALUE, 
                    PRECISION_WEIGH_STANDARD, 
                    PRECISION_WEIGH_VALUE, 
                    PRESS_TIME, 
                    NUMBER_OF_PRESSES, 
                    KNIFE_FLATTENING_USE, 
                    CARBIDE_TYPE, 
                    CARBIDE_SAMPLE_PASSED_NO, 
                    CARBIDE_SAMPLE_RESULT, 
                    CARBIDE_WEIGHT_STANDARD, 
                    CARBIDE_WEIGHT_VALUE, 
                    CARBIDE_HEIGHT_STANDARD, 
                    CARBIDE_HEIGHT_P1, 
                    CARBIDE_HEIGHT_P2, 
                    CARBIDE_HEIGHT_P3, 
                    CARBIDE_HEIGHT_P4, 
                    CARBIDE_HEIGHT_P5, 
                    CARBIDE_OUTER_DIAMETER_STANDARD, 
                    CARBIDE_OUTER_DIAMETER_VALUE, 
                    COMPLETE_FLATNESS_STANDARD, 
                    COMPLETE_FLATNESS_VALUE, 
                    COMPLETE_WEIGHT_STANDARD, 
                    COMPLETE_WEIGHT_VALUE, 
                    CARBIDE_INPUT_COUNT, 
                    IMPACT_PROCESS_INPUT_COUNT, 
                    NG_COUND, 
                    CMF_1, 
                    CMF_2, 
                    CMF_3, 
                    CMF_4, 
                    CMF_5, 
                    CMF_6, 
                    CMF_7, 
                    CMF_8, 
                    CMF_9, 
                    CMF_10, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME
         ) 
        VALUES (
                    :CWIPLOTCUP_N.LOT_ID,
                    :CWIPLOTCUP_N.HIST_SEQ,
                    :CWIPLOTCUP_N.OPER,
                    :CWIPLOTCUP_N.MAT_ID,
                    :CWIPLOTCUP_N.FLOW,
                    :CWIPLOTCUP_N.FLOW_SEQ_NUM,
                    :CWIPLOTCUP_N.GRADE,
                    :CWIPLOTCUP_N.RES_ID,
                    :CWIPLOTCUP_N.FACTORY,
                    :CWIPLOTCUP_N.WORK_DATE,
                    :CWIPLOTCUP_N.WORK_TIME,
                    :CWIPLOTCUP_N.DAY_NIGHT,
                    :CWIPLOTCUP_N.EDC_HIST_SEQ,
                    :CWIPLOTCUP_N.MASTER_LOT_ID,
                    :CWIPLOTCUP_N.RECIPE_ID,
                    :CWIPLOTCUP_N.START_TIME,
                    :CWIPLOTCUP_N.END_TIME,
                    :CWIPLOTCUP_N.JUDGMENT,
                    :CWIPLOTCUP_N.INPUT_TIME,
                    :CWIPLOTCUP_N.CUP_INPUT_COUNTER,
                    :CWIPLOTCUP_N.CUP_TYPE,
                    :CWIPLOTCUP_N.CUP_WEIGHT_STANDARD,
                    :CWIPLOTCUP_N.CUP_WEIGHT_VALUE,
                    :CWIPLOTCUP_N.POWDER_INJECTION_LOCATION,
                    :CWIPLOTCUP_N.ROBOT_MEASURABLE_STANDARD,
                    :CWIPLOTCUP_N.ROBOT_MEASURABLE_VALUE,
                    :CWIPLOTCUP_N.PRECISION_WEIGH_STANDARD,
                    :CWIPLOTCUP_N.PRECISION_WEIGH_VALUE,
                    :CWIPLOTCUP_N.PRESS_TIME,
                    :CWIPLOTCUP_N.NUMBER_OF_PRESSES,
                    :CWIPLOTCUP_N.KNIFE_FLATTENING_USE,
                    :CWIPLOTCUP_N.CARBIDE_TYPE,
                    :CWIPLOTCUP_N.CARBIDE_SAMPLE_PASSED_NO,
                    :CWIPLOTCUP_N.CARBIDE_SAMPLE_RESULT,
                    :CWIPLOTCUP_N.CARBIDE_WEIGHT_STANDARD,
                    :CWIPLOTCUP_N.CARBIDE_WEIGHT_VALUE,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_STANDARD,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P1,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P2,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P3,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P4,
                    :CWIPLOTCUP_N.CARBIDE_HEIGHT_P5,
                    :CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_STANDARD,
                    :CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_VALUE,
                    :CWIPLOTCUP_N.COMPLETE_FLATNESS_STANDARD,
                    :CWIPLOTCUP_N.COMPLETE_FLATNESS_VALUE,
                    :CWIPLOTCUP_N.COMPLETE_WEIGHT_STANDARD,
                    :CWIPLOTCUP_N.COMPLETE_WEIGHT_VALUE,
                    :CWIPLOTCUP_N.CARBIDE_INPUT_COUNT,
                    :CWIPLOTCUP_N.IMPACT_PROCESS_INPUT_COUNT,
                    :CWIPLOTCUP_N.NG_COUND,
                    :CWIPLOTCUP_N.CMF_1,
                    :CWIPLOTCUP_N.CMF_2,
                    :CWIPLOTCUP_N.CMF_3,
                    :CWIPLOTCUP_N.CMF_4,
                    :CWIPLOTCUP_N.CMF_5,
                    :CWIPLOTCUP_N.CMF_6,
                    :CWIPLOTCUP_N.CMF_7,
                    :CWIPLOTCUP_N.CMF_8,
                    :CWIPLOTCUP_N.CMF_9,
                    :CWIPLOTCUP_N.CMF_10,
                    :CWIPLOTCUP_N.CREATE_USER_ID,
                    :CWIPLOTCUP_N.CREATE_TIME,
                    :CWIPLOTCUP_N.UPDATE_USER_ID,
                    :CWIPLOTCUP_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 67;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into CWIPLOTCUP (LOT_ID,HIST_SEQ,OPER,MAT_ID,FLOW,FLOW_SEQ_NUM\
,GRADE,RES_ID,FACTORY,WORK_DATE,WORK_TIME,DAY_NIGHT,EDC_HIST_SEQ,MASTER_LOT_\
ID,RECIPE_ID,START_TIME,END_TIME,JUDGMENT,INPUT_TIME,CUP_INPUT_COUNTER,CUP_T\
YPE,CUP_WEIGHT_STANDARD,CUP_WEIGHT_VALUE,POWDER_INJECTION_LOCATION,ROBOT_MEA\
SURABLE_STANDARD,ROBOT_MEASURABLE_VALUE,PRECISION_WEIGH_STANDARD,PRECISION_W\
EIGH_VALUE,PRESS_TIME,NUMBER_OF_PRESSES,KNIFE_FLATTENING_USE,CARBIDE_TYPE,CA\
RBIDE_SAMPLE_PASSED_NO,CARBIDE_SAMPLE_RESULT,CARBIDE_WEIGHT_STANDARD,CARBIDE\
_WEIGHT_VALUE,CARBIDE_HEIGHT_STANDARD,CARBIDE_HEIGHT_P1,CARBIDE_HEIGHT_P2,CA\
RBIDE_HEIGHT_P3,CARBIDE_HEIGHT_P4,CARBIDE_HEIGHT_P5,CARBIDE_OUTER_DIAMETER_S\
TANDARD,CARBIDE_OUTER_DIAMETER_VALUE,COMPLETE_FLATNESS_STANDARD,COMPLETE_FLA\
TNESS_VALUE,COMPLETE_WEIGHT_STANDARD,COMPLETE_WEIGHT_VALUE,CARBIDE_INPUT_COU\
NT,IMPACT_PROCESS_INPUT_COUNT,NG_COUND,CMF_1,CMF_2,CMF_3,CMF_4,CMF_5,CMF_6,C\
MF_7,CMF_8,CMF_9,CMF_10,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIM\
E) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,");
    sqlstm.stmt = ":b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b1\
9,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,\
:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b\
50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )621;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CWIPLOTCUP_N.LOT_ID);
    sqlstm.sqhstl[0] = (unsigned int  )26;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&(CWIPLOTCUP_N.HIST_SEQ);
    sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CWIPLOTCUP_N.OPER);
    sqlstm.sqhstl[2] = (unsigned int  )11;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(CWIPLOTCUP_N.MAT_ID);
    sqlstm.sqhstl[3] = (unsigned int  )31;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CWIPLOTCUP_N.FLOW);
    sqlstm.sqhstl[4] = (unsigned int  )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)&(CWIPLOTCUP_N.FLOW_SEQ_NUM);
    sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CWIPLOTCUP_N.GRADE);
    sqlstm.sqhstl[6] = (unsigned int  )51;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(CWIPLOTCUP_N.RES_ID);
    sqlstm.sqhstl[7] = (unsigned int  )21;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CWIPLOTCUP_N.FACTORY);
    sqlstm.sqhstl[8] = (unsigned int  )11;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CWIPLOTCUP_N.WORK_DATE);
    sqlstm.sqhstl[9] = (unsigned int  )9;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(CWIPLOTCUP_N.WORK_TIME);
    sqlstm.sqhstl[10] = (unsigned int  )15;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(CWIPLOTCUP_N.DAY_NIGHT);
    sqlstm.sqhstl[11] = (unsigned int  )11;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)&(CWIPLOTCUP_N.EDC_HIST_SEQ);
    sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CWIPLOTCUP_N.MASTER_LOT_ID);
    sqlstm.sqhstl[13] = (unsigned int  )26;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(CWIPLOTCUP_N.RECIPE_ID);
    sqlstm.sqhstl[14] = (unsigned int  )51;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CWIPLOTCUP_N.START_TIME);
    sqlstm.sqhstl[15] = (unsigned int  )15;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CWIPLOTCUP_N.END_TIME);
    sqlstm.sqhstl[16] = (unsigned int  )15;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CWIPLOTCUP_N.JUDGMENT);
    sqlstm.sqhstl[17] = (unsigned int  )11;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CWIPLOTCUP_N.INPUT_TIME);
    sqlstm.sqhstl[18] = (unsigned int  )15;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)&(CWIPLOTCUP_N.CUP_INPUT_COUNTER);
    sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CWIPLOTCUP_N.CUP_TYPE);
    sqlstm.sqhstl[20] = (unsigned int  )11;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)&(CWIPLOTCUP_N.CUP_WEIGHT_STANDARD);
    sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)&(CWIPLOTCUP_N.CUP_WEIGHT_VALUE);
    sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(CWIPLOTCUP_N.POWDER_INJECTION_LOCATION);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)&(CWIPLOTCUP_N.ROBOT_MEASURABLE_STANDARD);
    sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)&(CWIPLOTCUP_N.ROBOT_MEASURABLE_VALUE);
    sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)&(CWIPLOTCUP_N.PRECISION_WEIGH_STANDARD);
    sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)&(CWIPLOTCUP_N.PRECISION_WEIGH_VALUE);
    sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(CWIPLOTCUP_N.PRESS_TIME);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)&(CWIPLOTCUP_N.NUMBER_OF_PRESSES);
    sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(CWIPLOTCUP_N.KNIFE_FLATTENING_USE);
    sqlstm.sqhstl[30] = (unsigned int  )11;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(CWIPLOTCUP_N.CARBIDE_TYPE);
    sqlstm.sqhstl[31] = (unsigned int  )11;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_SAMPLE_PASSED_NO);
    sqlstm.sqhstl[32] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(CWIPLOTCUP_N.CARBIDE_SAMPLE_RESULT);
    sqlstm.sqhstl[33] = (unsigned int  )2;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_WEIGHT_STANDARD);
    sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_WEIGHT_VALUE);
    sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_STANDARD);
    sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P1);
    sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P2);
    sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P3);
    sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P4);
    sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P5);
    sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_STANDARD);
    sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_VALUE);
    sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_FLATNESS_STANDARD);
    sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_FLATNESS_VALUE);
    sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_WEIGHT_STANDARD);
    sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_WEIGHT_VALUE);
    sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_INPUT_COUNT);
    sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)&(CWIPLOTCUP_N.IMPACT_PROCESS_INPUT_COUNT);
    sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)&(CWIPLOTCUP_N.NG_COUND);
    sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(CWIPLOTCUP_N.CMF_1);
    sqlstm.sqhstl[51] = (unsigned int  )31;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(CWIPLOTCUP_N.CMF_2);
    sqlstm.sqhstl[52] = (unsigned int  )31;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(CWIPLOTCUP_N.CMF_3);
    sqlstm.sqhstl[53] = (unsigned int  )31;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(CWIPLOTCUP_N.CMF_4);
    sqlstm.sqhstl[54] = (unsigned int  )31;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(CWIPLOTCUP_N.CMF_5);
    sqlstm.sqhstl[55] = (unsigned int  )31;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(CWIPLOTCUP_N.CMF_6);
    sqlstm.sqhstl[56] = (unsigned int  )31;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(CWIPLOTCUP_N.CMF_7);
    sqlstm.sqhstl[57] = (unsigned int  )31;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(CWIPLOTCUP_N.CMF_8);
    sqlstm.sqhstl[58] = (unsigned int  )31;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(CWIPLOTCUP_N.CMF_9);
    sqlstm.sqhstl[59] = (unsigned int  )31;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(CWIPLOTCUP_N.CMF_10);
    sqlstm.sqhstl[60] = (unsigned int  )31;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(CWIPLOTCUP_N.CREATE_USER_ID);
    sqlstm.sqhstl[61] = (unsigned int  )21;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(CWIPLOTCUP_N.CREATE_TIME);
    sqlstm.sqhstl[62] = (unsigned int  )15;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(CWIPLOTCUP_N.UPDATE_USER_ID);
    sqlstm.sqhstl[63] = (unsigned int  )21;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(CWIPLOTCUP_N.UPDATE_TIME);
    sqlstm.sqhstl[64] = (unsigned int  )15;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_cwiplotcup", 0);
}


/* SQL UPDATE Function */
void DBU_update_cwiplotcup(int sel_type, struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPLOTCUP_N_TAG CWIPLOTCUP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwiplotcup(&CWIPLOTCUP_N, CWIPLOTCUP);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CWIPLOTCUP SET
                    OPER = :CWIPLOTCUP_N.OPER,
                    MAT_ID = :CWIPLOTCUP_N.MAT_ID,
                    FLOW = :CWIPLOTCUP_N.FLOW,
                    FLOW_SEQ_NUM = :CWIPLOTCUP_N.FLOW_SEQ_NUM,
                    GRADE = :CWIPLOTCUP_N.GRADE,
                    RES_ID = :CWIPLOTCUP_N.RES_ID,
                    FACTORY = :CWIPLOTCUP_N.FACTORY,
                    WORK_DATE = :CWIPLOTCUP_N.WORK_DATE,
                    WORK_TIME = :CWIPLOTCUP_N.WORK_TIME,
                    DAY_NIGHT = :CWIPLOTCUP_N.DAY_NIGHT,
                    EDC_HIST_SEQ = :CWIPLOTCUP_N.EDC_HIST_SEQ,
                    MASTER_LOT_ID = :CWIPLOTCUP_N.MASTER_LOT_ID,
                    RECIPE_ID = :CWIPLOTCUP_N.RECIPE_ID,
                    START_TIME = :CWIPLOTCUP_N.START_TIME,
                    END_TIME = :CWIPLOTCUP_N.END_TIME,
                    JUDGMENT = :CWIPLOTCUP_N.JUDGMENT,
                    INPUT_TIME = :CWIPLOTCUP_N.INPUT_TIME,
                    CUP_INPUT_COUNTER = :CWIPLOTCUP_N.CUP_INPUT_COUNTER,
                    CUP_TYPE = :CWIPLOTCUP_N.CUP_TYPE,
                    CUP_WEIGHT_STANDARD = :CWIPLOTCUP_N.CUP_WEIGHT_STANDARD,
                    CUP_WEIGHT_VALUE = :CWIPLOTCUP_N.CUP_WEIGHT_VALUE,
                    POWDER_INJECTION_LOCATION = :CWIPLOTCUP_N.POWDER_INJECTION_LOCATION,
                    ROBOT_MEASURABLE_STANDARD = :CWIPLOTCUP_N.ROBOT_MEASURABLE_STANDARD,
                    ROBOT_MEASURABLE_VALUE = :CWIPLOTCUP_N.ROBOT_MEASURABLE_VALUE,
                    PRECISION_WEIGH_STANDARD = :CWIPLOTCUP_N.PRECISION_WEIGH_STANDARD,
                    PRECISION_WEIGH_VALUE = :CWIPLOTCUP_N.PRECISION_WEIGH_VALUE,
                    PRESS_TIME = :CWIPLOTCUP_N.PRESS_TIME,
                    NUMBER_OF_PRESSES = :CWIPLOTCUP_N.NUMBER_OF_PRESSES,
                    KNIFE_FLATTENING_USE = :CWIPLOTCUP_N.KNIFE_FLATTENING_USE,
                    CARBIDE_TYPE = :CWIPLOTCUP_N.CARBIDE_TYPE,
                    CARBIDE_SAMPLE_PASSED_NO = :CWIPLOTCUP_N.CARBIDE_SAMPLE_PASSED_NO,
                    CARBIDE_SAMPLE_RESULT = :CWIPLOTCUP_N.CARBIDE_SAMPLE_RESULT,
                    CARBIDE_WEIGHT_STANDARD = :CWIPLOTCUP_N.CARBIDE_WEIGHT_STANDARD,
                    CARBIDE_WEIGHT_VALUE = :CWIPLOTCUP_N.CARBIDE_WEIGHT_VALUE,
                    CARBIDE_HEIGHT_STANDARD = :CWIPLOTCUP_N.CARBIDE_HEIGHT_STANDARD,
                    CARBIDE_HEIGHT_P1 = :CWIPLOTCUP_N.CARBIDE_HEIGHT_P1,
                    CARBIDE_HEIGHT_P2 = :CWIPLOTCUP_N.CARBIDE_HEIGHT_P2,
                    CARBIDE_HEIGHT_P3 = :CWIPLOTCUP_N.CARBIDE_HEIGHT_P3,
                    CARBIDE_HEIGHT_P4 = :CWIPLOTCUP_N.CARBIDE_HEIGHT_P4,
                    CARBIDE_HEIGHT_P5 = :CWIPLOTCUP_N.CARBIDE_HEIGHT_P5,
                    CARBIDE_OUTER_DIAMETER_STANDARD = :CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_STANDARD,
                    CARBIDE_OUTER_DIAMETER_VALUE = :CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_VALUE,
                    COMPLETE_FLATNESS_STANDARD = :CWIPLOTCUP_N.COMPLETE_FLATNESS_STANDARD,
                    COMPLETE_FLATNESS_VALUE = :CWIPLOTCUP_N.COMPLETE_FLATNESS_VALUE,
                    COMPLETE_WEIGHT_STANDARD = :CWIPLOTCUP_N.COMPLETE_WEIGHT_STANDARD,
                    COMPLETE_WEIGHT_VALUE = :CWIPLOTCUP_N.COMPLETE_WEIGHT_VALUE,
                    CARBIDE_INPUT_COUNT = :CWIPLOTCUP_N.CARBIDE_INPUT_COUNT,
                    IMPACT_PROCESS_INPUT_COUNT = :CWIPLOTCUP_N.IMPACT_PROCESS_INPUT_COUNT,
                    NG_COUND = :CWIPLOTCUP_N.NG_COUND,
                    CMF_1 = :CWIPLOTCUP_N.CMF_1,
                    CMF_2 = :CWIPLOTCUP_N.CMF_2,
                    CMF_3 = :CWIPLOTCUP_N.CMF_3,
                    CMF_4 = :CWIPLOTCUP_N.CMF_4,
                    CMF_5 = :CWIPLOTCUP_N.CMF_5,
                    CMF_6 = :CWIPLOTCUP_N.CMF_6,
                    CMF_7 = :CWIPLOTCUP_N.CMF_7,
                    CMF_8 = :CWIPLOTCUP_N.CMF_8,
                    CMF_9 = :CWIPLOTCUP_N.CMF_9,
                    CMF_10 = :CWIPLOTCUP_N.CMF_10,
                    CREATE_USER_ID = :CWIPLOTCUP_N.CREATE_USER_ID,
                    CREATE_TIME = :CWIPLOTCUP_N.CREATE_TIME,
                    UPDATE_USER_ID = :CWIPLOTCUP_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CWIPLOTCUP_N.UPDATE_TIME
                WHERE LOT_ID = :CWIPLOTCUP_N.LOT_ID
                    AND HIST_SEQ = :CWIPLOTCUP_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update CWIPLOTCUP  set OPER=:b0,MAT_ID=:b1,FLOW=:b2,FLOW_SEQ_\
NUM=:b3,GRADE=:b4,RES_ID=:b5,FACTORY=:b6,WORK_DATE=:b7,WORK_TIME=:b8,DAY_NIG\
HT=:b9,EDC_HIST_SEQ=:b10,MASTER_LOT_ID=:b11,RECIPE_ID=:b12,START_TIME=:b13,E\
ND_TIME=:b14,JUDGMENT=:b15,INPUT_TIME=:b16,CUP_INPUT_COUNTER=:b17,CUP_TYPE=:\
b18,CUP_WEIGHT_STANDARD=:b19,CUP_WEIGHT_VALUE=:b20,POWDER_INJECTION_LOCATION\
=:b21,ROBOT_MEASURABLE_STANDARD=:b22,ROBOT_MEASURABLE_VALUE=:b23,PRECISION_W\
EIGH_STANDARD=:b24,PRECISION_WEIGH_VALUE=:b25,PRESS_TIME=:b26,NUMBER_OF_PRES\
SES=:b27,KNIFE_FLATTENING_USE=:b28,CARBIDE_TYPE=:b29,CARBIDE_SAMPLE_PASSED_N\
O=:b30,CARBIDE_SAMPLE_RESULT=:b31,CARBIDE_WEIGHT_STANDARD=:b32,CARBIDE_WEIGH\
T_VALUE=:b33,CARBIDE_HEIGHT_STANDARD=:b34,CARBIDE_HEIGHT_P1=:b35,CARBIDE_HEI\
GHT_P2=:b36,CARBIDE_HEIGHT_P3=:b37,CARBIDE_HEIGHT_P4=:b38,CARBIDE_HEIGHT_P5=\
:b39,CARBIDE_OUTER_DIAMETER_STANDARD=:b40,CARBIDE_OUTER_DIAMETER_VALUE=:b41,\
COMPLETE_FLATNESS_STANDARD=:b42,COMPLETE_FLATNESS_VALUE=:b43,COMPLETE_WEIGHT\
_STANDARD=:b44,COMPLETE_WEIGHT_VALUE=:b45,CARBIDE_I");
            sqlstm.stmt = "NPUT_COUNT=:b46,IMPACT_PROCESS_INPUT_COUNT=:b47,\
NG_COUND=:b48,CMF_1=:b49,CMF_2=:b50,CMF_3=:b51,CMF_4=:b52,CMF_5=:b53,CMF_6=:b\
54,CMF_7=:b55,CMF_8=:b56,CMF_9=:b57,CMF_10=:b58,CREATE_USER_ID=:b59,CREATE_TI\
ME=:b60,UPDATE_USER_ID=:b61,UPDATE_TIME=:b62 where (LOT_ID=:b63 and HIST_SEQ=\
:b64)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )896;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPLOTCUP_N.OPER);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPLOTCUP_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPLOTCUP_N.FLOW);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CWIPLOTCUP_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPLOTCUP_N.GRADE);
            sqlstm.sqhstl[4] = (unsigned int  )51;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPLOTCUP_N.RES_ID);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPLOTCUP_N.FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPLOTCUP_N.WORK_DATE);
            sqlstm.sqhstl[7] = (unsigned int  )9;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPLOTCUP_N.WORK_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPLOTCUP_N.DAY_NIGHT);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CWIPLOTCUP_N.EDC_HIST_SEQ);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CWIPLOTCUP_N.MASTER_LOT_ID);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CWIPLOTCUP_N.RECIPE_ID);
            sqlstm.sqhstl[12] = (unsigned int  )51;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPLOTCUP_N.START_TIME);
            sqlstm.sqhstl[13] = (unsigned int  )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CWIPLOTCUP_N.END_TIME);
            sqlstm.sqhstl[14] = (unsigned int  )15;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPLOTCUP_N.JUDGMENT);
            sqlstm.sqhstl[15] = (unsigned int  )11;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPLOTCUP_N.INPUT_TIME);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(CWIPLOTCUP_N.CUP_INPUT_COUNTER);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPLOTCUP_N.CUP_TYPE);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CWIPLOTCUP_N.CUP_WEIGHT_STANDARD);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(CWIPLOTCUP_N.CUP_WEIGHT_VALUE);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CWIPLOTCUP_N.POWDER_INJECTION_LOCATION);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CWIPLOTCUP_N.ROBOT_MEASURABLE_STANDARD);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CWIPLOTCUP_N.ROBOT_MEASURABLE_VALUE);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(CWIPLOTCUP_N.PRECISION_WEIGH_STANDARD);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(CWIPLOTCUP_N.PRECISION_WEIGH_VALUE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CWIPLOTCUP_N.PRESS_TIME);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CWIPLOTCUP_N.NUMBER_OF_PRESSES);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPLOTCUP_N.KNIFE_FLATTENING_USE);
            sqlstm.sqhstl[28] = (unsigned int  )11;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CWIPLOTCUP_N.CARBIDE_TYPE);
            sqlstm.sqhstl[29] = (unsigned int  )11;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_SAMPLE_PASSED_NO);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPLOTCUP_N.CARBIDE_SAMPLE_RESULT);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_WEIGHT_STANDARD);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_WEIGHT_VALUE);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_STANDARD);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P1);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P2);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P3);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P4);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P5);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_STANDARD);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_VALUE);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_FLATNESS_STANDARD);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_FLATNESS_VALUE);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_WEIGHT_STANDARD);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_WEIGHT_VALUE);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_INPUT_COUNT);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(CWIPLOTCUP_N.IMPACT_PROCESS_INPUT_COUNT);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(CWIPLOTCUP_N.NG_COUND);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CWIPLOTCUP_N.CMF_1);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CWIPLOTCUP_N.CMF_2);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CWIPLOTCUP_N.CMF_3);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CWIPLOTCUP_N.CMF_4);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CWIPLOTCUP_N.CMF_5);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CWIPLOTCUP_N.CMF_6);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CWIPLOTCUP_N.CMF_7);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CWIPLOTCUP_N.CMF_8);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CWIPLOTCUP_N.CMF_9);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CWIPLOTCUP_N.CMF_10);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CWIPLOTCUP_N.CREATE_USER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CWIPLOTCUP_N.CREATE_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CWIPLOTCUP_N.UPDATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CWIPLOTCUP_N.UPDATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CWIPLOTCUP_N.LOT_ID);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)&(CWIPLOTCUP_N.HIST_SEQ);
            sqlstm.sqhstl[64] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_cwiplotcup", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cwiplotcup(int sel_type, struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPLOTCUP_N_TAG CWIPLOTCUP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwiplotcup(&CWIPLOTCUP_N, CWIPLOTCUP);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CWIPLOTCUP_CUR_1 CURSOR FOR
                SELECT 
                    LOT_ID,
                    HIST_SEQ,
                    OPER,
                    MAT_ID,
                    FLOW,
                    FLOW_SEQ_NUM,
                    GRADE,
                    RES_ID,
                    FACTORY,
                    WORK_DATE,
                    WORK_TIME,
                    DAY_NIGHT,
                    EDC_HIST_SEQ,
                    MASTER_LOT_ID,
                    RECIPE_ID,
                    START_TIME,
                    END_TIME,
                    JUDGMENT,
                    INPUT_TIME,
                    CUP_INPUT_COUNTER,
                    CUP_TYPE,
                    CUP_WEIGHT_STANDARD,
                    CUP_WEIGHT_VALUE,
                    POWDER_INJECTION_LOCATION,
                    ROBOT_MEASURABLE_STANDARD,
                    ROBOT_MEASURABLE_VALUE,
                    PRECISION_WEIGH_STANDARD,
                    PRECISION_WEIGH_VALUE,
                    PRESS_TIME,
                    NUMBER_OF_PRESSES,
                    KNIFE_FLATTENING_USE,
                    CARBIDE_TYPE,
                    CARBIDE_SAMPLE_PASSED_NO,
                    CARBIDE_SAMPLE_RESULT,
                    CARBIDE_WEIGHT_STANDARD,
                    CARBIDE_WEIGHT_VALUE,
                    CARBIDE_HEIGHT_STANDARD,
                    CARBIDE_HEIGHT_P1,
                    CARBIDE_HEIGHT_P2,
                    CARBIDE_HEIGHT_P3,
                    CARBIDE_HEIGHT_P4,
                    CARBIDE_HEIGHT_P5,
                    CARBIDE_OUTER_DIAMETER_STANDARD,
                    CARBIDE_OUTER_DIAMETER_VALUE,
                    COMPLETE_FLATNESS_STANDARD,
                    COMPLETE_FLATNESS_VALUE,
                    COMPLETE_WEIGHT_STANDARD,
                    COMPLETE_WEIGHT_VALUE,
                    CARBIDE_INPUT_COUNT,
                    IMPACT_PROCESS_INPUT_COUNT,
                    NG_COUND,
                    CMF_1,
                    CMF_2,
                    CMF_3,
                    CMF_4,
                    CMF_5,
                    CMF_6,
                    CMF_7,
                    CMF_8,
                    CMF_9,
                    CMF_10,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM CWIPLOTCUP
                ORDER BY LOT_ID ASC,
                    HIST_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_CWIPLOTCUP_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select LOT_ID ,HIST_SEQ ,OPER ,MAT_ID ,FLOW ,FLOW_SEQ_NUM ,GR\
ADE ,RES_ID ,FACTORY ,WORK_DATE ,WORK_TIME ,DAY_NIGHT ,EDC_HIST_SEQ ,MASTER_\
LOT_ID ,RECIPE_ID ,START_TIME ,END_TIME ,JUDGMENT ,INPUT_TIME ,CUP_INPUT_COU\
NTER ,CUP_TYPE ,CUP_WEIGHT_STANDARD ,CUP_WEIGHT_VALUE ,POWDER_INJECTION_LOCA\
TION ,ROBOT_MEASURABLE_STANDARD ,ROBOT_MEASURABLE_VALUE ,PRECISION_WEIGH_STA\
NDARD ,PRECISION_WEIGH_VALUE ,PRESS_TIME ,NUMBER_OF_PRESSES ,KNIFE_FLATTENIN\
G_USE ,CARBIDE_TYPE ,CARBIDE_SAMPLE_PASSED_NO ,CARBIDE_SAMPLE_RESULT ,CARBID\
E_WEIGHT_STANDARD ,CARBIDE_WEIGHT_VALUE ,CARBIDE_HEIGHT_STANDARD ,CARBIDE_HE\
IGHT_P1 ,CARBIDE_HEIGHT_P2 ,CARBIDE_HEIGHT_P3 ,CARBIDE_HEIGHT_P4 ,CARBIDE_HE\
IGHT_P5 ,CARBIDE_OUTER_DIAMETER_STANDARD ,CARBIDE_OUTER_DIAMETER_VALUE ,COMP\
LETE_FLATNESS_STANDARD ,COMPLETE_FLATNESS_VALUE ,COMPLETE_WEIGHT_STANDARD ,C\
OMPLETE_WEIGHT_VALUE ,CARBIDE_INPUT_COUNT ,IMPACT_PROCESS_INPUT_COUNT ,NG_CO\
UND ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,\
CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE");
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1171;
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

    DB_stop_query_timer("DBU_open_cwiplotcup", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cwiplotcup(int sel_type, struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPLOTCUP_N_TAG CWIPLOTCUP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CWIPLOTCUP_CUR_1 INTO
                :CWIPLOTCUP_N.LOT_ID,
                :CWIPLOTCUP_N.HIST_SEQ,
                :CWIPLOTCUP_N.OPER,
                :CWIPLOTCUP_N.MAT_ID,
                :CWIPLOTCUP_N.FLOW,
                :CWIPLOTCUP_N.FLOW_SEQ_NUM,
                :CWIPLOTCUP_N.GRADE,
                :CWIPLOTCUP_N.RES_ID,
                :CWIPLOTCUP_N.FACTORY,
                :CWIPLOTCUP_N.WORK_DATE,
                :CWIPLOTCUP_N.WORK_TIME,
                :CWIPLOTCUP_N.DAY_NIGHT,
                :CWIPLOTCUP_N.EDC_HIST_SEQ,
                :CWIPLOTCUP_N.MASTER_LOT_ID,
                :CWIPLOTCUP_N.RECIPE_ID,
                :CWIPLOTCUP_N.START_TIME,
                :CWIPLOTCUP_N.END_TIME,
                :CWIPLOTCUP_N.JUDGMENT,
                :CWIPLOTCUP_N.INPUT_TIME,
                :CWIPLOTCUP_N.CUP_INPUT_COUNTER,
                :CWIPLOTCUP_N.CUP_TYPE,
                :CWIPLOTCUP_N.CUP_WEIGHT_STANDARD,
                :CWIPLOTCUP_N.CUP_WEIGHT_VALUE,
                :CWIPLOTCUP_N.POWDER_INJECTION_LOCATION,
                :CWIPLOTCUP_N.ROBOT_MEASURABLE_STANDARD,
                :CWIPLOTCUP_N.ROBOT_MEASURABLE_VALUE,
                :CWIPLOTCUP_N.PRECISION_WEIGH_STANDARD,
                :CWIPLOTCUP_N.PRECISION_WEIGH_VALUE,
                :CWIPLOTCUP_N.PRESS_TIME,
                :CWIPLOTCUP_N.NUMBER_OF_PRESSES,
                :CWIPLOTCUP_N.KNIFE_FLATTENING_USE,
                :CWIPLOTCUP_N.CARBIDE_TYPE,
                :CWIPLOTCUP_N.CARBIDE_SAMPLE_PASSED_NO,
                :CWIPLOTCUP_N.CARBIDE_SAMPLE_RESULT,
                :CWIPLOTCUP_N.CARBIDE_WEIGHT_STANDARD,
                :CWIPLOTCUP_N.CARBIDE_WEIGHT_VALUE,
                :CWIPLOTCUP_N.CARBIDE_HEIGHT_STANDARD,
                :CWIPLOTCUP_N.CARBIDE_HEIGHT_P1,
                :CWIPLOTCUP_N.CARBIDE_HEIGHT_P2,
                :CWIPLOTCUP_N.CARBIDE_HEIGHT_P3,
                :CWIPLOTCUP_N.CARBIDE_HEIGHT_P4,
                :CWIPLOTCUP_N.CARBIDE_HEIGHT_P5,
                :CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_STANDARD,
                :CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_VALUE,
                :CWIPLOTCUP_N.COMPLETE_FLATNESS_STANDARD,
                :CWIPLOTCUP_N.COMPLETE_FLATNESS_VALUE,
                :CWIPLOTCUP_N.COMPLETE_WEIGHT_STANDARD,
                :CWIPLOTCUP_N.COMPLETE_WEIGHT_VALUE,
                :CWIPLOTCUP_N.CARBIDE_INPUT_COUNT,
                :CWIPLOTCUP_N.IMPACT_PROCESS_INPUT_COUNT,
                :CWIPLOTCUP_N.NG_COUND,
                :CWIPLOTCUP_N.CMF_1,
                :CWIPLOTCUP_N.CMF_2,
                :CWIPLOTCUP_N.CMF_3,
                :CWIPLOTCUP_N.CMF_4,
                :CWIPLOTCUP_N.CMF_5,
                :CWIPLOTCUP_N.CMF_6,
                :CWIPLOTCUP_N.CMF_7,
                :CWIPLOTCUP_N.CMF_8,
                :CWIPLOTCUP_N.CMF_9,
                :CWIPLOTCUP_N.CMF_10,
                :CWIPLOTCUP_N.CREATE_USER_ID,
                :CWIPLOTCUP_N.CREATE_TIME,
                :CWIPLOTCUP_N.UPDATE_USER_ID,
                :CWIPLOTCUP_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1186;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CWIPLOTCUP_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CWIPLOTCUP_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPLOTCUP_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPLOTCUP_N.MAT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPLOTCUP_N.FLOW);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CWIPLOTCUP_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPLOTCUP_N.GRADE);
            sqlstm.sqhstl[6] = (unsigned int  )51;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPLOTCUP_N.RES_ID);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPLOTCUP_N.FACTORY);
            sqlstm.sqhstl[8] = (unsigned int  )11;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPLOTCUP_N.WORK_DATE);
            sqlstm.sqhstl[9] = (unsigned int  )9;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CWIPLOTCUP_N.WORK_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CWIPLOTCUP_N.DAY_NIGHT);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CWIPLOTCUP_N.EDC_HIST_SEQ);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPLOTCUP_N.MASTER_LOT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CWIPLOTCUP_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )51;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPLOTCUP_N.START_TIME);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPLOTCUP_N.END_TIME);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CWIPLOTCUP_N.JUDGMENT);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPLOTCUP_N.INPUT_TIME);
            sqlstm.sqhstl[18] = (unsigned int  )15;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CWIPLOTCUP_N.CUP_INPUT_COUNTER);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CWIPLOTCUP_N.CUP_TYPE);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(CWIPLOTCUP_N.CUP_WEIGHT_STANDARD);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CWIPLOTCUP_N.CUP_WEIGHT_VALUE);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CWIPLOTCUP_N.POWDER_INJECTION_LOCATION);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(CWIPLOTCUP_N.ROBOT_MEASURABLE_STANDARD);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(CWIPLOTCUP_N.ROBOT_MEASURABLE_VALUE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(CWIPLOTCUP_N.PRECISION_WEIGH_STANDARD);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CWIPLOTCUP_N.PRECISION_WEIGH_VALUE);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPLOTCUP_N.PRESS_TIME);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(CWIPLOTCUP_N.NUMBER_OF_PRESSES);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CWIPLOTCUP_N.KNIFE_FLATTENING_USE);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPLOTCUP_N.CARBIDE_TYPE);
            sqlstm.sqhstl[31] = (unsigned int  )11;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_SAMPLE_PASSED_NO);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CWIPLOTCUP_N.CARBIDE_SAMPLE_RESULT);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_WEIGHT_STANDARD);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_WEIGHT_VALUE);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_STANDARD);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P1);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P2);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P3);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P4);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_HEIGHT_P5);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_STANDARD);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_OUTER_DIAMETER_VALUE);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_FLATNESS_STANDARD);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_FLATNESS_VALUE);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_WEIGHT_STANDARD);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(CWIPLOTCUP_N.COMPLETE_WEIGHT_VALUE);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(CWIPLOTCUP_N.CARBIDE_INPUT_COUNT);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(CWIPLOTCUP_N.IMPACT_PROCESS_INPUT_COUNT);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(CWIPLOTCUP_N.NG_COUND);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CWIPLOTCUP_N.CMF_1);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CWIPLOTCUP_N.CMF_2);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CWIPLOTCUP_N.CMF_3);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CWIPLOTCUP_N.CMF_4);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CWIPLOTCUP_N.CMF_5);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CWIPLOTCUP_N.CMF_6);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CWIPLOTCUP_N.CMF_7);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CWIPLOTCUP_N.CMF_8);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CWIPLOTCUP_N.CMF_9);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CWIPLOTCUP_N.CMF_10);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CWIPLOTCUP_N.CREATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CWIPLOTCUP_N.CREATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CWIPLOTCUP_N.UPDATE_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CWIPLOTCUP_N.UPDATE_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
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
        DBU_del_null_cwiplotcup(&CWIPLOTCUP_N, CWIPLOTCUP);
    }

    DB_stop_query_timer("DBU_fetch_cwiplotcup", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cwiplotcup(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CWIPLOTCUP_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1461;
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

    DB_stop_query_timer("DBU_close_cwiplotcup", sel_type);
}


/* Initialize Function */
void DBU_init_cwiplotcup(struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    /* memset by Space */
    memset(CWIPLOTCUP, ' ', sizeof(struct CWIPLOTCUP_TAG));
    
    CWIPLOTCUP->HIST_SEQ = 0;
    CWIPLOTCUP->FLOW_SEQ_NUM = 0;
    CWIPLOTCUP->EDC_HIST_SEQ = 0;
    CWIPLOTCUP->CUP_INPUT_COUNTER = 0;
    CWIPLOTCUP->CUP_WEIGHT_STANDARD = 0;
    CWIPLOTCUP->CUP_WEIGHT_VALUE = 0;
    CWIPLOTCUP->ROBOT_MEASURABLE_STANDARD = 0;
    CWIPLOTCUP->ROBOT_MEASURABLE_VALUE = 0;
    CWIPLOTCUP->PRECISION_WEIGH_STANDARD = 0;
    CWIPLOTCUP->PRECISION_WEIGH_VALUE = 0;
    CWIPLOTCUP->NUMBER_OF_PRESSES = 0;
    CWIPLOTCUP->CARBIDE_SAMPLE_PASSED_NO = 0;
    CWIPLOTCUP->CARBIDE_WEIGHT_STANDARD = 0;
    CWIPLOTCUP->CARBIDE_WEIGHT_VALUE = 0;
    CWIPLOTCUP->CARBIDE_HEIGHT_STANDARD = 0;
    CWIPLOTCUP->CARBIDE_HEIGHT_P1 = 0;
    CWIPLOTCUP->CARBIDE_HEIGHT_P2 = 0;
    CWIPLOTCUP->CARBIDE_HEIGHT_P3 = 0;
    CWIPLOTCUP->CARBIDE_HEIGHT_P4 = 0;
    CWIPLOTCUP->CARBIDE_HEIGHT_P5 = 0;
    CWIPLOTCUP->CARBIDE_OUTER_DIAMETER_STANDARD = 0;
    CWIPLOTCUP->CARBIDE_OUTER_DIAMETER_VALUE = 0;
    CWIPLOTCUP->COMPLETE_FLATNESS_STANDARD = 0;
    CWIPLOTCUP->COMPLETE_FLATNESS_VALUE = 0;
    CWIPLOTCUP->COMPLETE_WEIGHT_STANDARD = 0;
    CWIPLOTCUP->COMPLETE_WEIGHT_VALUE = 0;
    CWIPLOTCUP->CARBIDE_INPUT_COUNT = 0;
    CWIPLOTCUP->IMPACT_PROCESS_INPUT_COUNT = 0;
    CWIPLOTCUP->NG_COUND = 0;
}


/* Add Null Function */
void DBU_add_null_cwiplotcup(struct CWIPLOTCUP_N_TAG *CWIPLOTCUP_N, struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    /* memset by NULL */
    memset(CWIPLOTCUP_N, '\0', sizeof(struct CWIPLOTCUP_N_TAG));
    
    MEMCPY_AN(CWIPLOTCUP_N->LOT_ID, CWIPLOTCUP->LOT_ID, sizeof(CWIPLOTCUP->LOT_ID));
    CWIPLOTCUP_N->HIST_SEQ = CWIPLOTCUP->HIST_SEQ;
    MEMCPY_AN(CWIPLOTCUP_N->OPER, CWIPLOTCUP->OPER, sizeof(CWIPLOTCUP->OPER));
    MEMCPY_AN(CWIPLOTCUP_N->MAT_ID, CWIPLOTCUP->MAT_ID, sizeof(CWIPLOTCUP->MAT_ID));
    MEMCPY_AN(CWIPLOTCUP_N->FLOW, CWIPLOTCUP->FLOW, sizeof(CWIPLOTCUP->FLOW));
    CWIPLOTCUP_N->FLOW_SEQ_NUM = CWIPLOTCUP->FLOW_SEQ_NUM;
    MEMCPY_AN(CWIPLOTCUP_N->GRADE, CWIPLOTCUP->GRADE, sizeof(CWIPLOTCUP->GRADE));
    MEMCPY_AN(CWIPLOTCUP_N->RES_ID, CWIPLOTCUP->RES_ID, sizeof(CWIPLOTCUP->RES_ID));
    MEMCPY_AN(CWIPLOTCUP_N->FACTORY, CWIPLOTCUP->FACTORY, sizeof(CWIPLOTCUP->FACTORY));
    MEMCPY_AN(CWIPLOTCUP_N->WORK_DATE, CWIPLOTCUP->WORK_DATE, sizeof(CWIPLOTCUP->WORK_DATE));
    MEMCPY_AN(CWIPLOTCUP_N->WORK_TIME, CWIPLOTCUP->WORK_TIME, sizeof(CWIPLOTCUP->WORK_TIME));
    MEMCPY_AN(CWIPLOTCUP_N->DAY_NIGHT, CWIPLOTCUP->DAY_NIGHT, sizeof(CWIPLOTCUP->DAY_NIGHT));
    CWIPLOTCUP_N->EDC_HIST_SEQ = CWIPLOTCUP->EDC_HIST_SEQ;
    MEMCPY_AN(CWIPLOTCUP_N->MASTER_LOT_ID, CWIPLOTCUP->MASTER_LOT_ID, sizeof(CWIPLOTCUP->MASTER_LOT_ID));
    MEMCPY_AN(CWIPLOTCUP_N->RECIPE_ID, CWIPLOTCUP->RECIPE_ID, sizeof(CWIPLOTCUP->RECIPE_ID));
    MEMCPY_AN(CWIPLOTCUP_N->START_TIME, CWIPLOTCUP->START_TIME, sizeof(CWIPLOTCUP->START_TIME));
    MEMCPY_AN(CWIPLOTCUP_N->END_TIME, CWIPLOTCUP->END_TIME, sizeof(CWIPLOTCUP->END_TIME));
    MEMCPY_AN(CWIPLOTCUP_N->JUDGMENT, CWIPLOTCUP->JUDGMENT, sizeof(CWIPLOTCUP->JUDGMENT));
    MEMCPY_AN(CWIPLOTCUP_N->INPUT_TIME, CWIPLOTCUP->INPUT_TIME, sizeof(CWIPLOTCUP->INPUT_TIME));
    CWIPLOTCUP_N->CUP_INPUT_COUNTER = CWIPLOTCUP->CUP_INPUT_COUNTER;
    MEMCPY_AN(CWIPLOTCUP_N->CUP_TYPE, CWIPLOTCUP->CUP_TYPE, sizeof(CWIPLOTCUP->CUP_TYPE));
    CWIPLOTCUP_N->CUP_WEIGHT_STANDARD = CWIPLOTCUP->CUP_WEIGHT_STANDARD;
    CWIPLOTCUP_N->CUP_WEIGHT_VALUE = CWIPLOTCUP->CUP_WEIGHT_VALUE;
    MEMCPY_AN(CWIPLOTCUP_N->POWDER_INJECTION_LOCATION, CWIPLOTCUP->POWDER_INJECTION_LOCATION, sizeof(CWIPLOTCUP->POWDER_INJECTION_LOCATION));
    CWIPLOTCUP_N->ROBOT_MEASURABLE_STANDARD = CWIPLOTCUP->ROBOT_MEASURABLE_STANDARD;
    CWIPLOTCUP_N->ROBOT_MEASURABLE_VALUE = CWIPLOTCUP->ROBOT_MEASURABLE_VALUE;
    CWIPLOTCUP_N->PRECISION_WEIGH_STANDARD = CWIPLOTCUP->PRECISION_WEIGH_STANDARD;
    CWIPLOTCUP_N->PRECISION_WEIGH_VALUE = CWIPLOTCUP->PRECISION_WEIGH_VALUE;
    MEMCPY_AN(CWIPLOTCUP_N->PRESS_TIME, CWIPLOTCUP->PRESS_TIME, sizeof(CWIPLOTCUP->PRESS_TIME));
    CWIPLOTCUP_N->NUMBER_OF_PRESSES = CWIPLOTCUP->NUMBER_OF_PRESSES;
    MEMCPY_AN(CWIPLOTCUP_N->KNIFE_FLATTENING_USE, CWIPLOTCUP->KNIFE_FLATTENING_USE, sizeof(CWIPLOTCUP->KNIFE_FLATTENING_USE));
    MEMCPY_AN(CWIPLOTCUP_N->CARBIDE_TYPE, CWIPLOTCUP->CARBIDE_TYPE, sizeof(CWIPLOTCUP->CARBIDE_TYPE));
    CWIPLOTCUP_N->CARBIDE_SAMPLE_PASSED_NO = CWIPLOTCUP->CARBIDE_SAMPLE_PASSED_NO;
    CWIPLOTCUP_N->CARBIDE_SAMPLE_RESULT[0] = CWIPLOTCUP->CARBIDE_SAMPLE_RESULT;
    CWIPLOTCUP_N->CARBIDE_WEIGHT_STANDARD = CWIPLOTCUP->CARBIDE_WEIGHT_STANDARD;
    CWIPLOTCUP_N->CARBIDE_WEIGHT_VALUE = CWIPLOTCUP->CARBIDE_WEIGHT_VALUE;
    CWIPLOTCUP_N->CARBIDE_HEIGHT_STANDARD = CWIPLOTCUP->CARBIDE_HEIGHT_STANDARD;
    CWIPLOTCUP_N->CARBIDE_HEIGHT_P1 = CWIPLOTCUP->CARBIDE_HEIGHT_P1;
    CWIPLOTCUP_N->CARBIDE_HEIGHT_P2 = CWIPLOTCUP->CARBIDE_HEIGHT_P2;
    CWIPLOTCUP_N->CARBIDE_HEIGHT_P3 = CWIPLOTCUP->CARBIDE_HEIGHT_P3;
    CWIPLOTCUP_N->CARBIDE_HEIGHT_P4 = CWIPLOTCUP->CARBIDE_HEIGHT_P4;
    CWIPLOTCUP_N->CARBIDE_HEIGHT_P5 = CWIPLOTCUP->CARBIDE_HEIGHT_P5;
    CWIPLOTCUP_N->CARBIDE_OUTER_DIAMETER_STANDARD = CWIPLOTCUP->CARBIDE_OUTER_DIAMETER_STANDARD;
    CWIPLOTCUP_N->CARBIDE_OUTER_DIAMETER_VALUE = CWIPLOTCUP->CARBIDE_OUTER_DIAMETER_VALUE;
    CWIPLOTCUP_N->COMPLETE_FLATNESS_STANDARD = CWIPLOTCUP->COMPLETE_FLATNESS_STANDARD;
    CWIPLOTCUP_N->COMPLETE_FLATNESS_VALUE = CWIPLOTCUP->COMPLETE_FLATNESS_VALUE;
    CWIPLOTCUP_N->COMPLETE_WEIGHT_STANDARD = CWIPLOTCUP->COMPLETE_WEIGHT_STANDARD;
    CWIPLOTCUP_N->COMPLETE_WEIGHT_VALUE = CWIPLOTCUP->COMPLETE_WEIGHT_VALUE;
    CWIPLOTCUP_N->CARBIDE_INPUT_COUNT = CWIPLOTCUP->CARBIDE_INPUT_COUNT;
    CWIPLOTCUP_N->IMPACT_PROCESS_INPUT_COUNT = CWIPLOTCUP->IMPACT_PROCESS_INPUT_COUNT;
    CWIPLOTCUP_N->NG_COUND = CWIPLOTCUP->NG_COUND;
    MEMCPY_AN(CWIPLOTCUP_N->CMF_1, CWIPLOTCUP->CMF_1, sizeof(CWIPLOTCUP->CMF_1));
    MEMCPY_AN(CWIPLOTCUP_N->CMF_2, CWIPLOTCUP->CMF_2, sizeof(CWIPLOTCUP->CMF_2));
    MEMCPY_AN(CWIPLOTCUP_N->CMF_3, CWIPLOTCUP->CMF_3, sizeof(CWIPLOTCUP->CMF_3));
    MEMCPY_AN(CWIPLOTCUP_N->CMF_4, CWIPLOTCUP->CMF_4, sizeof(CWIPLOTCUP->CMF_4));
    MEMCPY_AN(CWIPLOTCUP_N->CMF_5, CWIPLOTCUP->CMF_5, sizeof(CWIPLOTCUP->CMF_5));
    MEMCPY_AN(CWIPLOTCUP_N->CMF_6, CWIPLOTCUP->CMF_6, sizeof(CWIPLOTCUP->CMF_6));
    MEMCPY_AN(CWIPLOTCUP_N->CMF_7, CWIPLOTCUP->CMF_7, sizeof(CWIPLOTCUP->CMF_7));
    MEMCPY_AN(CWIPLOTCUP_N->CMF_8, CWIPLOTCUP->CMF_8, sizeof(CWIPLOTCUP->CMF_8));
    MEMCPY_AN(CWIPLOTCUP_N->CMF_9, CWIPLOTCUP->CMF_9, sizeof(CWIPLOTCUP->CMF_9));
    MEMCPY_AN(CWIPLOTCUP_N->CMF_10, CWIPLOTCUP->CMF_10, sizeof(CWIPLOTCUP->CMF_10));
    MEMCPY_AN(CWIPLOTCUP_N->CREATE_USER_ID, CWIPLOTCUP->CREATE_USER_ID, sizeof(CWIPLOTCUP->CREATE_USER_ID));
    MEMCPY_AN(CWIPLOTCUP_N->CREATE_TIME, CWIPLOTCUP->CREATE_TIME, sizeof(CWIPLOTCUP->CREATE_TIME));
    MEMCPY_AN(CWIPLOTCUP_N->UPDATE_USER_ID, CWIPLOTCUP->UPDATE_USER_ID, sizeof(CWIPLOTCUP->UPDATE_USER_ID));
    MEMCPY_AN(CWIPLOTCUP_N->UPDATE_TIME, CWIPLOTCUP->UPDATE_TIME, sizeof(CWIPLOTCUP->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_cwiplotcup(struct CWIPLOTCUP_N_TAG *CWIPLOTCUP_N, struct CWIPLOTCUP_TAG *CWIPLOTCUP)
{
    MEMCPY_DN(CWIPLOTCUP->LOT_ID, CWIPLOTCUP_N->LOT_ID, sizeof(CWIPLOTCUP->LOT_ID));
    CWIPLOTCUP->HIST_SEQ = CWIPLOTCUP_N->HIST_SEQ;
    MEMCPY_DN(CWIPLOTCUP->OPER, CWIPLOTCUP_N->OPER, sizeof(CWIPLOTCUP->OPER));
    MEMCPY_DN(CWIPLOTCUP->MAT_ID, CWIPLOTCUP_N->MAT_ID, sizeof(CWIPLOTCUP->MAT_ID));
    MEMCPY_DN(CWIPLOTCUP->FLOW, CWIPLOTCUP_N->FLOW, sizeof(CWIPLOTCUP->FLOW));
    CWIPLOTCUP->FLOW_SEQ_NUM = CWIPLOTCUP_N->FLOW_SEQ_NUM;
    MEMCPY_DN(CWIPLOTCUP->GRADE, CWIPLOTCUP_N->GRADE, sizeof(CWIPLOTCUP->GRADE));
    MEMCPY_DN(CWIPLOTCUP->RES_ID, CWIPLOTCUP_N->RES_ID, sizeof(CWIPLOTCUP->RES_ID));
    MEMCPY_DN(CWIPLOTCUP->FACTORY, CWIPLOTCUP_N->FACTORY, sizeof(CWIPLOTCUP->FACTORY));
    MEMCPY_DN(CWIPLOTCUP->WORK_DATE, CWIPLOTCUP_N->WORK_DATE, sizeof(CWIPLOTCUP->WORK_DATE));
    MEMCPY_DN(CWIPLOTCUP->WORK_TIME, CWIPLOTCUP_N->WORK_TIME, sizeof(CWIPLOTCUP->WORK_TIME));
    MEMCPY_DN(CWIPLOTCUP->DAY_NIGHT, CWIPLOTCUP_N->DAY_NIGHT, sizeof(CWIPLOTCUP->DAY_NIGHT));
    CWIPLOTCUP->EDC_HIST_SEQ = CWIPLOTCUP_N->EDC_HIST_SEQ;
    MEMCPY_DN(CWIPLOTCUP->MASTER_LOT_ID, CWIPLOTCUP_N->MASTER_LOT_ID, sizeof(CWIPLOTCUP->MASTER_LOT_ID));
    MEMCPY_DN(CWIPLOTCUP->RECIPE_ID, CWIPLOTCUP_N->RECIPE_ID, sizeof(CWIPLOTCUP->RECIPE_ID));
    MEMCPY_DN(CWIPLOTCUP->START_TIME, CWIPLOTCUP_N->START_TIME, sizeof(CWIPLOTCUP->START_TIME));
    MEMCPY_DN(CWIPLOTCUP->END_TIME, CWIPLOTCUP_N->END_TIME, sizeof(CWIPLOTCUP->END_TIME));
    MEMCPY_DN(CWIPLOTCUP->JUDGMENT, CWIPLOTCUP_N->JUDGMENT, sizeof(CWIPLOTCUP->JUDGMENT));
    MEMCPY_DN(CWIPLOTCUP->INPUT_TIME, CWIPLOTCUP_N->INPUT_TIME, sizeof(CWIPLOTCUP->INPUT_TIME));
    CWIPLOTCUP->CUP_INPUT_COUNTER = CWIPLOTCUP_N->CUP_INPUT_COUNTER;
    MEMCPY_DN(CWIPLOTCUP->CUP_TYPE, CWIPLOTCUP_N->CUP_TYPE, sizeof(CWIPLOTCUP->CUP_TYPE));
    CWIPLOTCUP->CUP_WEIGHT_STANDARD = CWIPLOTCUP_N->CUP_WEIGHT_STANDARD;
    CWIPLOTCUP->CUP_WEIGHT_VALUE = CWIPLOTCUP_N->CUP_WEIGHT_VALUE;
    MEMCPY_DN(CWIPLOTCUP->POWDER_INJECTION_LOCATION, CWIPLOTCUP_N->POWDER_INJECTION_LOCATION, sizeof(CWIPLOTCUP->POWDER_INJECTION_LOCATION));
    CWIPLOTCUP->ROBOT_MEASURABLE_STANDARD = CWIPLOTCUP_N->ROBOT_MEASURABLE_STANDARD;
    CWIPLOTCUP->ROBOT_MEASURABLE_VALUE = CWIPLOTCUP_N->ROBOT_MEASURABLE_VALUE;
    CWIPLOTCUP->PRECISION_WEIGH_STANDARD = CWIPLOTCUP_N->PRECISION_WEIGH_STANDARD;
    CWIPLOTCUP->PRECISION_WEIGH_VALUE = CWIPLOTCUP_N->PRECISION_WEIGH_VALUE;
    MEMCPY_DN(CWIPLOTCUP->PRESS_TIME, CWIPLOTCUP_N->PRESS_TIME, sizeof(CWIPLOTCUP->PRESS_TIME));
    CWIPLOTCUP->NUMBER_OF_PRESSES = CWIPLOTCUP_N->NUMBER_OF_PRESSES;
    MEMCPY_DN(CWIPLOTCUP->KNIFE_FLATTENING_USE, CWIPLOTCUP_N->KNIFE_FLATTENING_USE, sizeof(CWIPLOTCUP->KNIFE_FLATTENING_USE));
    MEMCPY_DN(CWIPLOTCUP->CARBIDE_TYPE, CWIPLOTCUP_N->CARBIDE_TYPE, sizeof(CWIPLOTCUP->CARBIDE_TYPE));
    CWIPLOTCUP->CARBIDE_SAMPLE_PASSED_NO = CWIPLOTCUP_N->CARBIDE_SAMPLE_PASSED_NO;
    CWIPLOTCUP->CARBIDE_SAMPLE_RESULT = CWIPLOTCUP_N->CARBIDE_SAMPLE_RESULT[0];
    CWIPLOTCUP->CARBIDE_WEIGHT_STANDARD = CWIPLOTCUP_N->CARBIDE_WEIGHT_STANDARD;
    CWIPLOTCUP->CARBIDE_WEIGHT_VALUE = CWIPLOTCUP_N->CARBIDE_WEIGHT_VALUE;
    CWIPLOTCUP->CARBIDE_HEIGHT_STANDARD = CWIPLOTCUP_N->CARBIDE_HEIGHT_STANDARD;
    CWIPLOTCUP->CARBIDE_HEIGHT_P1 = CWIPLOTCUP_N->CARBIDE_HEIGHT_P1;
    CWIPLOTCUP->CARBIDE_HEIGHT_P2 = CWIPLOTCUP_N->CARBIDE_HEIGHT_P2;
    CWIPLOTCUP->CARBIDE_HEIGHT_P3 = CWIPLOTCUP_N->CARBIDE_HEIGHT_P3;
    CWIPLOTCUP->CARBIDE_HEIGHT_P4 = CWIPLOTCUP_N->CARBIDE_HEIGHT_P4;
    CWIPLOTCUP->CARBIDE_HEIGHT_P5 = CWIPLOTCUP_N->CARBIDE_HEIGHT_P5;
    CWIPLOTCUP->CARBIDE_OUTER_DIAMETER_STANDARD = CWIPLOTCUP_N->CARBIDE_OUTER_DIAMETER_STANDARD;
    CWIPLOTCUP->CARBIDE_OUTER_DIAMETER_VALUE = CWIPLOTCUP_N->CARBIDE_OUTER_DIAMETER_VALUE;
    CWIPLOTCUP->COMPLETE_FLATNESS_STANDARD = CWIPLOTCUP_N->COMPLETE_FLATNESS_STANDARD;
    CWIPLOTCUP->COMPLETE_FLATNESS_VALUE = CWIPLOTCUP_N->COMPLETE_FLATNESS_VALUE;
    CWIPLOTCUP->COMPLETE_WEIGHT_STANDARD = CWIPLOTCUP_N->COMPLETE_WEIGHT_STANDARD;
    CWIPLOTCUP->COMPLETE_WEIGHT_VALUE = CWIPLOTCUP_N->COMPLETE_WEIGHT_VALUE;
    CWIPLOTCUP->CARBIDE_INPUT_COUNT = CWIPLOTCUP_N->CARBIDE_INPUT_COUNT;
    CWIPLOTCUP->IMPACT_PROCESS_INPUT_COUNT = CWIPLOTCUP_N->IMPACT_PROCESS_INPUT_COUNT;
    CWIPLOTCUP->NG_COUND = CWIPLOTCUP_N->NG_COUND;
    MEMCPY_DN(CWIPLOTCUP->CMF_1, CWIPLOTCUP_N->CMF_1, sizeof(CWIPLOTCUP->CMF_1));
    MEMCPY_DN(CWIPLOTCUP->CMF_2, CWIPLOTCUP_N->CMF_2, sizeof(CWIPLOTCUP->CMF_2));
    MEMCPY_DN(CWIPLOTCUP->CMF_3, CWIPLOTCUP_N->CMF_3, sizeof(CWIPLOTCUP->CMF_3));
    MEMCPY_DN(CWIPLOTCUP->CMF_4, CWIPLOTCUP_N->CMF_4, sizeof(CWIPLOTCUP->CMF_4));
    MEMCPY_DN(CWIPLOTCUP->CMF_5, CWIPLOTCUP_N->CMF_5, sizeof(CWIPLOTCUP->CMF_5));
    MEMCPY_DN(CWIPLOTCUP->CMF_6, CWIPLOTCUP_N->CMF_6, sizeof(CWIPLOTCUP->CMF_6));
    MEMCPY_DN(CWIPLOTCUP->CMF_7, CWIPLOTCUP_N->CMF_7, sizeof(CWIPLOTCUP->CMF_7));
    MEMCPY_DN(CWIPLOTCUP->CMF_8, CWIPLOTCUP_N->CMF_8, sizeof(CWIPLOTCUP->CMF_8));
    MEMCPY_DN(CWIPLOTCUP->CMF_9, CWIPLOTCUP_N->CMF_9, sizeof(CWIPLOTCUP->CMF_9));
    MEMCPY_DN(CWIPLOTCUP->CMF_10, CWIPLOTCUP_N->CMF_10, sizeof(CWIPLOTCUP->CMF_10));
    MEMCPY_DN(CWIPLOTCUP->CREATE_USER_ID, CWIPLOTCUP_N->CREATE_USER_ID, sizeof(CWIPLOTCUP->CREATE_USER_ID));
    MEMCPY_DN(CWIPLOTCUP->CREATE_TIME, CWIPLOTCUP_N->CREATE_TIME, sizeof(CWIPLOTCUP->CREATE_TIME));
    MEMCPY_DN(CWIPLOTCUP->UPDATE_USER_ID, CWIPLOTCUP_N->UPDATE_USER_ID, sizeof(CWIPLOTCUP->UPDATE_USER_ID));
    MEMCPY_DN(CWIPLOTCUP->UPDATE_TIME, CWIPLOTCUP_N->UPDATE_TIME, sizeof(CWIPLOTCUP->UPDATE_TIME));
}


