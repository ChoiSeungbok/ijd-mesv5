
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
    "DBU_ct_mtl510t.pc"
};


static unsigned int sqlctx = 9411227;


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
            void  *sqhstv[29];
   unsigned int   sqhstl[29];
            int   sqhsts[29];
            void  *sqindv[29];
            int   sqinds[29];
   unsigned int   sqharm[29];
   unsigned int   *sqharc[29];
   unsigned short  sqadto[29];
   unsigned short  sqtdso[29];
} sqlstm = {13,29};

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
"select LOT_ID ,LOT_SEQ ,NVL(M_S_GBN,' ') ,NVL(UP_LOT_ID,' ') ,NVL(ORG_CODE,\
' ') ,NVL(WC_CODE,' ') ,WH_CODE ,NVL(ITEM_CODE,' ') ,NVL(PUSH_DATE,' ') ,NVL(\
PUSH_TIME,' ') ,NVL(PUSH_QTY,'0') ,NVL(REMAIN_QTY,'0') ,NVL(WORK_FLAG,' ') ,N\
VL(USE_YN,' ') ,NVL(REMARKS,' ') ,NVL(PUSH_SEQ,' ') ,NVL(TO_CHAR(INSERT_DATE,\
'YYYYMMDDHH24MISS'),' ') ,NVL(INSERT_USER,' ') ,NVL(TO_CHAR(UPDATE_DATE,'YYYY\
MMDDHH24MISS'),' ') ,NVL(UPDATE_USER,' ') ,NVL(VENDOR_CODE,' ') ,NVL(CUST_COD\
E,' ') ,NVL(CUST_SITE_ID,'0') ,NVL(END_CUST_ID,'0') ,NVL(QC_START_DT,' ') ,NV\
L(QC_END_DT,' ')  from CT_MTL510T  order by LOT_ID asc ,LOT_SEQ asc ,WH_CODE \
asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,748,0,4,46,0,0,29,3,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
136,0,0,2,760,0,4,140,0,0,29,3,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
267,0,0,3,95,0,4,237,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
298,0,0,4,77,0,2,275,0,0,3,3,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,
325,0,0,5,480,0,3,306,0,0,26,26,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
444,0,0,6,487,0,5,383,0,0,26,26,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,
563,0,0,7,630,0,9,472,0,0,0,0,0,1,0,
578,0,0,7,0,0,13,501,0,0,26,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,
697,0,0,7,0,0,15,557,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_ct_mtl510t.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-11-06 20:20:21
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
void DBU_add_null_ct_mtl510t(struct CT_MTL510T_N_TAG *CT_MTL510T_N, struct CT_MTL510T_TAG *CT_MTL510T);
void DBU_del_null_ct_mtl510t(struct CT_MTL510T_N_TAG *CT_MTL510T_N, struct CT_MTL510T_TAG *CT_MTL510T);


/* SQL SELECT Function */
void DBU_select_ct_mtl510t(int sel_type, struct CT_MTL510T_TAG *CT_MTL510T)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_MTL510T_N_TAG CT_MTL510T_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_mtl510t(&CT_MTL510T_N, CT_MTL510T);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    LOT_ID,
                    LOT_SEQ,
                    NVL(M_S_GBN, ' '),
                    NVL(UP_LOT_ID, ' '),
                    NVL(ORG_CODE, ' '),
                    NVL(WC_CODE, ' '),
                    WH_CODE,
                    NVL(ITEM_CODE, ' '),
                    NVL(PUSH_DATE, ' '),
                    NVL(PUSH_TIME, ' '),
                    NVL(PUSH_QTY, '0'),
                    NVL(REMAIN_QTY, '0'),
                    NVL(WORK_FLAG, ' '),
                    NVL(USE_YN, ' '),
                    NVL(REMARKS, ' '),
                    NVL(PUSH_SEQ, ' '),
                    NVL(TO_CHAR(INSERT_DATE, 'YYYYMMDDHH24MISS'), ' '),
                    NVL(INSERT_USER, ' '),
                    NVL(TO_CHAR(UPDATE_DATE, 'YYYYMMDDHH24MISS'), ' '),
                    NVL(UPDATE_USER, ' '),
                    NVL(VENDOR_CODE, ' '),
                    NVL(CUST_CODE, ' '),
                    NVL(CUST_SITE_ID, '0'),
                    NVL(END_CUST_ID, '0'),
                    NVL(QC_START_DT, ' '),
                    NVL(QC_END_DT, ' ')
                INTO 
                    :CT_MTL510T_N.LOT_ID,
                    :CT_MTL510T_N.LOT_SEQ,
                    :CT_MTL510T_N.M_S_GBN,
                    :CT_MTL510T_N.UP_LOT_ID,
                    :CT_MTL510T_N.ORG_CODE,
                    :CT_MTL510T_N.WC_CODE,
                    :CT_MTL510T_N.WH_CODE,
                    :CT_MTL510T_N.ITEM_CODE,
                    :CT_MTL510T_N.PUSH_DATE,
                    :CT_MTL510T_N.PUSH_TIME,
                    :CT_MTL510T_N.PUSH_QTY,
                    :CT_MTL510T_N.REMAIN_QTY,
                    :CT_MTL510T_N.WORK_FLAG,
                    :CT_MTL510T_N.USE_YN,
                    :CT_MTL510T_N.REMARKS,
                    :CT_MTL510T_N.PUSH_SEQ,
                    :CT_MTL510T_N.INSERT_DATE,
                    :CT_MTL510T_N.INSERT_USER,
                    :CT_MTL510T_N.UPDATE_DATE,
                    :CT_MTL510T_N.UPDATE_USER,
                    :CT_MTL510T_N.VENDOR_CODE,
                    :CT_MTL510T_N.CUST_CODE,
                    :CT_MTL510T_N.CUST_SITE_ID,
                    :CT_MTL510T_N.END_CUST_ID,
                    :CT_MTL510T_N.QC_START_DT,
                    :CT_MTL510T_N.QC_END_DT
                FROM CT_MTL510T
                WHERE LOT_ID = :CT_MTL510T_N.LOT_ID
                    AND LOT_SEQ = :CT_MTL510T_N.LOT_SEQ
                    AND WH_CODE = :CT_MTL510T_N.WH_CODE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select LOT_ID ,LOT_SEQ ,NVL(M_S_GBN,' ') ,NVL(UP\
_LOT_ID,' ') ,NVL(ORG_CODE,' ') ,NVL(WC_CODE,' ') ,WH_CODE ,NVL(ITEM_CODE,' '\
) ,NVL(PUSH_DATE,' ') ,NVL(PUSH_TIME,' ') ,NVL(PUSH_QTY,'0') ,NVL(REMAIN_QTY,\
'0') ,NVL(WORK_FLAG,' ') ,NVL(USE_YN,' ') ,NVL(REMARKS,' ') ,NVL(PUSH_SEQ,' '\
) ,NVL(TO_CHAR(INSERT_DATE,'YYYYMMDDHH24MISS'),' ') ,NVL(INSERT_USER,' ') ,NV\
L(TO_CHAR(UPDATE_DATE,'YYYYMMDDHH24MISS'),' ') ,NVL(UPDATE_USER,' ') ,NVL(VEN\
DOR_CODE,' ') ,NVL(CUST_CODE,' ') ,NVL(CUST_SITE_ID,'0') ,NVL(END_CUST_ID,'0'\
) ,NVL(QC_START_DT,' ') ,NVL(QC_END_DT,' ') into :b0,:b1,:b2,:b3,:b4,:b5,:b6,\
:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,\
:b23,:b24,:b25  from CT_MTL510T where ((LOT_ID=:b0 and LOT_SEQ=:b1) and WH_CO\
DE=:b6)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CT_MTL510T_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CT_MTL510T_N.LOT_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CT_MTL510T_N.M_S_GBN);
            sqlstm.sqhstl[2] = (unsigned int  )4;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CT_MTL510T_N.UP_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CT_MTL510T_N.ORG_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )4;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CT_MTL510T_N.WC_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CT_MTL510T_N.WH_CODE);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CT_MTL510T_N.ITEM_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CT_MTL510T_N.PUSH_DATE);
            sqlstm.sqhstl[8] = (unsigned int  )9;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CT_MTL510T_N.PUSH_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CT_MTL510T_N.PUSH_QTY);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CT_MTL510T_N.REMAIN_QTY);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CT_MTL510T_N.WORK_FLAG);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CT_MTL510T_N.USE_YN);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CT_MTL510T_N.REMARKS);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CT_MTL510T_N.PUSH_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CT_MTL510T_N.INSERT_DATE);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CT_MTL510T_N.INSERT_USER);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CT_MTL510T_N.UPDATE_DATE);
            sqlstm.sqhstl[18] = (unsigned int  )15;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CT_MTL510T_N.UPDATE_USER);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CT_MTL510T_N.VENDOR_CODE);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CT_MTL510T_N.CUST_CODE);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CT_MTL510T_N.CUST_SITE_ID);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CT_MTL510T_N.END_CUST_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CT_MTL510T_N.QC_START_DT);
            sqlstm.sqhstl[24] = (unsigned int  )15;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CT_MTL510T_N.QC_END_DT);
            sqlstm.sqhstl[25] = (unsigned int  )15;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CT_MTL510T_N.LOT_ID);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CT_MTL510T_N.LOT_SEQ);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CT_MTL510T_N.WH_CODE);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
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
        DBU_del_null_ct_mtl510t(&CT_MTL510T_N, CT_MTL510T);
    }

    DB_stop_query_timer("DBU_select_ct_mtl510t", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_ct_mtl510t_for_update(int sel_type, struct CT_MTL510T_TAG *CT_MTL510T)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_MTL510T_N_TAG CT_MTL510T_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_mtl510t(&CT_MTL510T_N, CT_MTL510T);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    LOT_ID,
                    LOT_SEQ,
                    NVL(M_S_GBN, ' '),
                    NVL(UP_LOT_ID, ' '),
                    NVL(ORG_CODE, ' '),
                    NVL(WC_CODE, ' '),
                    WH_CODE,
                    NVL(ITEM_CODE, ' '),
                    NVL(PUSH_DATE, ' '),
                    NVL(PUSH_TIME, ' '),
                    NVL(PUSH_QTY, '0'),
                    NVL(REMAIN_QTY, '0'),
                    NVL(WORK_FLAG, ' '),
                    NVL(USE_YN, ' '),
                    NVL(REMARKS, ' '),
                    NVL(PUSH_SEQ, ' '),
                    NVL(TO_CHAR(INSERT_DATE, 'YYYYMMDDHH24MISS'), ' '),
                    NVL(INSERT_USER, ' '),
                    NVL(TO_CHAR(UPDATE_DATE, 'YYYYMMDDHH24MISS'), ' '),
                    NVL(UPDATE_USER, ' '),
                    NVL(VENDOR_CODE, ' '),
                    NVL(CUST_CODE, ' '),
                    NVL(CUST_SITE_ID, '0'),
                    NVL(END_CUST_ID, '0'),
                    NVL(QC_START_DT, ' '),
                    NVL(QC_END_DT, ' ')
                INTO 
                    :CT_MTL510T_N.LOT_ID,
                    :CT_MTL510T_N.LOT_SEQ,
                    :CT_MTL510T_N.M_S_GBN,
                    :CT_MTL510T_N.UP_LOT_ID,
                    :CT_MTL510T_N.ORG_CODE,
                    :CT_MTL510T_N.WC_CODE,
                    :CT_MTL510T_N.WH_CODE,
                    :CT_MTL510T_N.ITEM_CODE,
                    :CT_MTL510T_N.PUSH_DATE,
                    :CT_MTL510T_N.PUSH_TIME,
                    :CT_MTL510T_N.PUSH_QTY,
                    :CT_MTL510T_N.REMAIN_QTY,
                    :CT_MTL510T_N.WORK_FLAG,
                    :CT_MTL510T_N.USE_YN,
                    :CT_MTL510T_N.REMARKS,
                    :CT_MTL510T_N.PUSH_SEQ,
                    :CT_MTL510T_N.INSERT_DATE,
                    :CT_MTL510T_N.INSERT_USER,
                    :CT_MTL510T_N.UPDATE_DATE,
                    :CT_MTL510T_N.UPDATE_USER,
                    :CT_MTL510T_N.VENDOR_CODE,
                    :CT_MTL510T_N.CUST_CODE,
                    :CT_MTL510T_N.CUST_SITE_ID,
                    :CT_MTL510T_N.END_CUST_ID,
                    :CT_MTL510T_N.QC_START_DT,
                    :CT_MTL510T_N.QC_END_DT
                FROM CT_MTL510T
                WHERE LOT_ID = :CT_MTL510T_N.LOT_ID
                    AND LOT_SEQ = :CT_MTL510T_N.LOT_SEQ
                    AND WH_CODE = :CT_MTL510T_N.WH_CODE
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select LOT_ID ,LOT_SEQ ,NVL(M_S_GBN,' ') ,NVL(UP\
_LOT_ID,' ') ,NVL(ORG_CODE,' ') ,NVL(WC_CODE,' ') ,WH_CODE ,NVL(ITEM_CODE,' '\
) ,NVL(PUSH_DATE,' ') ,NVL(PUSH_TIME,' ') ,NVL(PUSH_QTY,'0') ,NVL(REMAIN_QTY,\
'0') ,NVL(WORK_FLAG,' ') ,NVL(USE_YN,' ') ,NVL(REMARKS,' ') ,NVL(PUSH_SEQ,' '\
) ,NVL(TO_CHAR(INSERT_DATE,'YYYYMMDDHH24MISS'),' ') ,NVL(INSERT_USER,' ') ,NV\
L(TO_CHAR(UPDATE_DATE,'YYYYMMDDHH24MISS'),' ') ,NVL(UPDATE_USER,' ') ,NVL(VEN\
DOR_CODE,' ') ,NVL(CUST_CODE,' ') ,NVL(CUST_SITE_ID,'0') ,NVL(END_CUST_ID,'0'\
) ,NVL(QC_START_DT,' ') ,NVL(QC_END_DT,' ') into :b0,:b1,:b2,:b3,:b4,:b5,:b6,\
:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,\
:b23,:b24,:b25  from CT_MTL510T where ((LOT_ID=:b0 and LOT_SEQ=:b1) and WH_CO\
DE=:b6) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )136;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CT_MTL510T_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CT_MTL510T_N.LOT_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CT_MTL510T_N.M_S_GBN);
            sqlstm.sqhstl[2] = (unsigned int  )4;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CT_MTL510T_N.UP_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CT_MTL510T_N.ORG_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )4;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CT_MTL510T_N.WC_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CT_MTL510T_N.WH_CODE);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CT_MTL510T_N.ITEM_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CT_MTL510T_N.PUSH_DATE);
            sqlstm.sqhstl[8] = (unsigned int  )9;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CT_MTL510T_N.PUSH_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CT_MTL510T_N.PUSH_QTY);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CT_MTL510T_N.REMAIN_QTY);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CT_MTL510T_N.WORK_FLAG);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CT_MTL510T_N.USE_YN);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CT_MTL510T_N.REMARKS);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CT_MTL510T_N.PUSH_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CT_MTL510T_N.INSERT_DATE);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CT_MTL510T_N.INSERT_USER);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CT_MTL510T_N.UPDATE_DATE);
            sqlstm.sqhstl[18] = (unsigned int  )15;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CT_MTL510T_N.UPDATE_USER);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CT_MTL510T_N.VENDOR_CODE);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CT_MTL510T_N.CUST_CODE);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CT_MTL510T_N.CUST_SITE_ID);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CT_MTL510T_N.END_CUST_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CT_MTL510T_N.QC_START_DT);
            sqlstm.sqhstl[24] = (unsigned int  )15;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CT_MTL510T_N.QC_END_DT);
            sqlstm.sqhstl[25] = (unsigned int  )15;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CT_MTL510T_N.LOT_ID);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CT_MTL510T_N.LOT_SEQ);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CT_MTL510T_N.WH_CODE);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
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
        DBU_del_null_ct_mtl510t(&CT_MTL510T_N, CT_MTL510T);
    }

    DB_stop_query_timer("DBU_select_ct_mtl510t_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_ct_mtl510t_scalar(int sel_type, struct CT_MTL510T_TAG *CT_MTL510T)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_MTL510T_N_TAG CT_MTL510T_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_mtl510t(&CT_MTL510T_N, CT_MTL510T);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CT_MTL510T
                WHERE LOT_ID = :CT_MTL510T_N.LOT_ID
                    AND LOT_SEQ = :CT_MTL510T_N.LOT_SEQ
                    AND WH_CODE = :CT_MTL510T_N.WH_CODE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CT_MTL510T where\
 ((LOT_ID=:b1 and LOT_SEQ=:b2) and WH_CODE=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )267;
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
            sqlstm.sqhstv[1] = (         void  *)(CT_MTL510T_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CT_MTL510T_N.LOT_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CT_MTL510T_N.WH_CODE);
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_select_ct_mtl510t_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_ct_mtl510t(int sel_type, struct CT_MTL510T_TAG *CT_MTL510T)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_MTL510T_N_TAG CT_MTL510T_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_mtl510t(&CT_MTL510T_N, CT_MTL510T);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CT_MTL510T
                WHERE LOT_ID = :CT_MTL510T_N.LOT_ID
                    AND LOT_SEQ = :CT_MTL510T_N.LOT_SEQ
                    AND WH_CODE = :CT_MTL510T_N.WH_CODE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CT_MTL510T  where ((LOT_ID=:b0 and \
LOT_SEQ=:b1) and WH_CODE=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )298;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CT_MTL510T_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CT_MTL510T_N.LOT_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CT_MTL510T_N.WH_CODE);
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

    DB_stop_query_timer("DBU_delete_ct_mtl510t", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_ct_mtl510t(struct CT_MTL510T_TAG *CT_MTL510T)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_MTL510T_N_TAG CT_MTL510T_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_mtl510t(&CT_MTL510T_N, CT_MTL510T);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CT_MTL510T( 
                    LOT_ID, 
                    LOT_SEQ, 
                    M_S_GBN, 
                    UP_LOT_ID, 
                    ORG_CODE, 
                    WC_CODE, 
                    WH_CODE, 
                    ITEM_CODE, 
                    PUSH_DATE, 
                    PUSH_TIME, 
                    PUSH_QTY, 
                    REMAIN_QTY, 
                    WORK_FLAG, 
                    USE_YN, 
                    REMARKS, 
                    PUSH_SEQ, 
                    INSERT_DATE, 
                    INSERT_USER, 
                    UPDATE_DATE, 
                    UPDATE_USER, 
                    VENDOR_CODE, 
                    CUST_CODE, 
                    CUST_SITE_ID, 
                    END_CUST_ID, 
                    QC_START_DT, 
                    QC_END_DT
         ) 
        VALUES (
                    :CT_MTL510T_N.LOT_ID,
                    :CT_MTL510T_N.LOT_SEQ,
                    :CT_MTL510T_N.M_S_GBN,
                    :CT_MTL510T_N.UP_LOT_ID,
                    :CT_MTL510T_N.ORG_CODE,
                    :CT_MTL510T_N.WC_CODE,
                    :CT_MTL510T_N.WH_CODE,
                    :CT_MTL510T_N.ITEM_CODE,
                    :CT_MTL510T_N.PUSH_DATE,
                    :CT_MTL510T_N.PUSH_TIME,
                    :CT_MTL510T_N.PUSH_QTY,
                    :CT_MTL510T_N.REMAIN_QTY,
                    :CT_MTL510T_N.WORK_FLAG,
                    :CT_MTL510T_N.USE_YN,
                    :CT_MTL510T_N.REMARKS,
                    :CT_MTL510T_N.PUSH_SEQ,
                    TO_DATE(TRIM(:CT_MTL510T_N.INSERT_DATE), 'YYYYMMDDHH24MISS'),
                    :CT_MTL510T_N.INSERT_USER,
                    TO_DATE(TRIM(:CT_MTL510T_N.UPDATE_DATE), 'YYYYMMDDHH24MISS'),
                    :CT_MTL510T_N.UPDATE_USER,
                    :CT_MTL510T_N.VENDOR_CODE,
                    :CT_MTL510T_N.CUST_CODE,
                    :CT_MTL510T_N.CUST_SITE_ID,
                    :CT_MTL510T_N.END_CUST_ID,
                    :CT_MTL510T_N.QC_START_DT,
                    :CT_MTL510T_N.QC_END_DT
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 29;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into CT_MTL510T (LOT_ID,LOT_SEQ,M_S_GBN,UP_LOT_ID\
,ORG_CODE,WC_CODE,WH_CODE,ITEM_CODE,PUSH_DATE,PUSH_TIME,PUSH_QTY,REMAIN_QTY,W\
ORK_FLAG,USE_YN,REMARKS,PUSH_SEQ,INSERT_DATE,INSERT_USER,UPDATE_DATE,UPDATE_U\
SER,VENDOR_CODE,CUST_CODE,CUST_SITE_ID,END_CUST_ID,QC_START_DT,QC_END_DT) val\
ues (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,TO\
_DATE(trim(:b16),'YYYYMMDDHH24MISS'),:b17,TO_DATE(trim(:b18),'YYYYMMDDHH24MIS\
S'),:b19,:b20,:b21,:b22,:b23,:b24,:b25)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )325;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CT_MTL510T_N.LOT_ID);
    sqlstm.sqhstl[0] = (unsigned int  )31;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&(CT_MTL510T_N.LOT_SEQ);
    sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CT_MTL510T_N.M_S_GBN);
    sqlstm.sqhstl[2] = (unsigned int  )4;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(CT_MTL510T_N.UP_LOT_ID);
    sqlstm.sqhstl[3] = (unsigned int  )31;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CT_MTL510T_N.ORG_CODE);
    sqlstm.sqhstl[4] = (unsigned int  )4;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(CT_MTL510T_N.WC_CODE);
    sqlstm.sqhstl[5] = (unsigned int  )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CT_MTL510T_N.WH_CODE);
    sqlstm.sqhstl[6] = (unsigned int  )21;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(CT_MTL510T_N.ITEM_CODE);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CT_MTL510T_N.PUSH_DATE);
    sqlstm.sqhstl[8] = (unsigned int  )9;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CT_MTL510T_N.PUSH_TIME);
    sqlstm.sqhstl[9] = (unsigned int  )21;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)&(CT_MTL510T_N.PUSH_QTY);
    sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)&(CT_MTL510T_N.REMAIN_QTY);
    sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(CT_MTL510T_N.WORK_FLAG);
    sqlstm.sqhstl[12] = (unsigned int  )2;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CT_MTL510T_N.USE_YN);
    sqlstm.sqhstl[13] = (unsigned int  )2;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(CT_MTL510T_N.REMARKS);
    sqlstm.sqhstl[14] = (unsigned int  )1001;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CT_MTL510T_N.PUSH_SEQ);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CT_MTL510T_N.INSERT_DATE);
    sqlstm.sqhstl[16] = (unsigned int  )15;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CT_MTL510T_N.INSERT_USER);
    sqlstm.sqhstl[17] = (unsigned int  )21;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CT_MTL510T_N.UPDATE_DATE);
    sqlstm.sqhstl[18] = (unsigned int  )15;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(CT_MTL510T_N.UPDATE_USER);
    sqlstm.sqhstl[19] = (unsigned int  )21;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CT_MTL510T_N.VENDOR_CODE);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CT_MTL510T_N.CUST_CODE);
    sqlstm.sqhstl[21] = (unsigned int  )21;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)&(CT_MTL510T_N.CUST_SITE_ID);
    sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)&(CT_MTL510T_N.END_CUST_ID);
    sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CT_MTL510T_N.QC_START_DT);
    sqlstm.sqhstl[24] = (unsigned int  )15;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(CT_MTL510T_N.QC_END_DT);
    sqlstm.sqhstl[25] = (unsigned int  )15;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_ct_mtl510t", 0);
}


/* SQL UPDATE Function */
void DBU_update_ct_mtl510t(int sel_type, struct CT_MTL510T_TAG *CT_MTL510T)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_MTL510T_N_TAG CT_MTL510T_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_mtl510t(&CT_MTL510T_N, CT_MTL510T);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CT_MTL510T SET
                    M_S_GBN = :CT_MTL510T_N.M_S_GBN,
                    UP_LOT_ID = :CT_MTL510T_N.UP_LOT_ID,
                    ORG_CODE = :CT_MTL510T_N.ORG_CODE,
                    WC_CODE = :CT_MTL510T_N.WC_CODE,
                    ITEM_CODE = :CT_MTL510T_N.ITEM_CODE,
                    PUSH_DATE = :CT_MTL510T_N.PUSH_DATE,
                    PUSH_TIME = :CT_MTL510T_N.PUSH_TIME,
                    PUSH_QTY = :CT_MTL510T_N.PUSH_QTY,
                    REMAIN_QTY = :CT_MTL510T_N.REMAIN_QTY,
                    WORK_FLAG = :CT_MTL510T_N.WORK_FLAG,
                    USE_YN = :CT_MTL510T_N.USE_YN,
                    REMARKS = :CT_MTL510T_N.REMARKS,
                    PUSH_SEQ = :CT_MTL510T_N.PUSH_SEQ,
                    INSERT_DATE = TO_DATE(TRIM(:CT_MTL510T_N.INSERT_DATE), 'YYYYMMDDHH24MISS'),
                    INSERT_USER = :CT_MTL510T_N.INSERT_USER,
                    UPDATE_DATE = TO_DATE(TRIM(:CT_MTL510T_N.UPDATE_DATE), 'YYYYMMDDHH24MISS'),
                    UPDATE_USER = :CT_MTL510T_N.UPDATE_USER,
                    VENDOR_CODE = :CT_MTL510T_N.VENDOR_CODE,
                    CUST_CODE = :CT_MTL510T_N.CUST_CODE,
                    CUST_SITE_ID = :CT_MTL510T_N.CUST_SITE_ID,
                    END_CUST_ID = :CT_MTL510T_N.END_CUST_ID,
                    QC_START_DT = :CT_MTL510T_N.QC_START_DT,
                    QC_END_DT = :CT_MTL510T_N.QC_END_DT
                WHERE LOT_ID = :CT_MTL510T_N.LOT_ID
                    AND LOT_SEQ = :CT_MTL510T_N.LOT_SEQ
                    AND WH_CODE = :CT_MTL510T_N.WH_CODE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CT_MTL510T  set M_S_GBN=:b0,UP_LOT_ID=:b1\
,ORG_CODE=:b2,WC_CODE=:b3,ITEM_CODE=:b4,PUSH_DATE=:b5,PUSH_TIME=:b6,PUSH_QTY=\
:b7,REMAIN_QTY=:b8,WORK_FLAG=:b9,USE_YN=:b10,REMARKS=:b11,PUSH_SEQ=:b12,INSER\
T_DATE=TO_DATE(trim(:b13),'YYYYMMDDHH24MISS'),INSERT_USER=:b14,UPDATE_DATE=TO\
_DATE(trim(:b15),'YYYYMMDDHH24MISS'),UPDATE_USER=:b16,VENDOR_CODE=:b17,CUST_C\
ODE=:b18,CUST_SITE_ID=:b19,END_CUST_ID=:b20,QC_START_DT=:b21,QC_END_DT=:b22 w\
here ((LOT_ID=:b23 and LOT_SEQ=:b24) and WH_CODE=:b25)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )444;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CT_MTL510T_N.M_S_GBN);
            sqlstm.sqhstl[0] = (unsigned int  )4;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CT_MTL510T_N.UP_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CT_MTL510T_N.ORG_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )4;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CT_MTL510T_N.WC_CODE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CT_MTL510T_N.ITEM_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CT_MTL510T_N.PUSH_DATE);
            sqlstm.sqhstl[5] = (unsigned int  )9;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CT_MTL510T_N.PUSH_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CT_MTL510T_N.PUSH_QTY);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CT_MTL510T_N.REMAIN_QTY);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CT_MTL510T_N.WORK_FLAG);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CT_MTL510T_N.USE_YN);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CT_MTL510T_N.REMARKS);
            sqlstm.sqhstl[11] = (unsigned int  )1001;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CT_MTL510T_N.PUSH_SEQ);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CT_MTL510T_N.INSERT_DATE);
            sqlstm.sqhstl[13] = (unsigned int  )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CT_MTL510T_N.INSERT_USER);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CT_MTL510T_N.UPDATE_DATE);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CT_MTL510T_N.UPDATE_USER);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CT_MTL510T_N.VENDOR_CODE);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CT_MTL510T_N.CUST_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CT_MTL510T_N.CUST_SITE_ID);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(CT_MTL510T_N.END_CUST_ID);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CT_MTL510T_N.QC_START_DT);
            sqlstm.sqhstl[21] = (unsigned int  )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CT_MTL510T_N.QC_END_DT);
            sqlstm.sqhstl[22] = (unsigned int  )15;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CT_MTL510T_N.LOT_ID);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(CT_MTL510T_N.LOT_SEQ);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CT_MTL510T_N.WH_CODE);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_ct_mtl510t", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_ct_mtl510t(int sel_type, struct CT_MTL510T_TAG *CT_MTL510T)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_MTL510T_N_TAG CT_MTL510T_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_mtl510t(&CT_MTL510T_N, CT_MTL510T);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CT_MTL510T_CUR_1 CURSOR FOR
                SELECT 
                    LOT_ID,
                    LOT_SEQ,
                    NVL(M_S_GBN, ' '),
                    NVL(UP_LOT_ID, ' '),
                    NVL(ORG_CODE, ' '),
                    NVL(WC_CODE, ' '),
                    WH_CODE,
                    NVL(ITEM_CODE, ' '),
                    NVL(PUSH_DATE, ' '),
                    NVL(PUSH_TIME, ' '),
                    NVL(PUSH_QTY, '0'),
                    NVL(REMAIN_QTY, '0'),
                    NVL(WORK_FLAG, ' '),
                    NVL(USE_YN, ' '),
                    NVL(REMARKS, ' '),
                    NVL(PUSH_SEQ, ' '),
                    NVL(TO_CHAR(INSERT_DATE, 'YYYYMMDDHH24MISS'), ' '),
                    NVL(INSERT_USER, ' '),
                    NVL(TO_CHAR(UPDATE_DATE, 'YYYYMMDDHH24MISS'), ' '),
                    NVL(UPDATE_USER, ' '),
                    NVL(VENDOR_CODE, ' '),
                    NVL(CUST_CODE, ' '),
                    NVL(CUST_SITE_ID, '0'),
                    NVL(END_CUST_ID, '0'),
                    NVL(QC_START_DT, ' '),
                    NVL(QC_END_DT, ' ')
                FROM CT_MTL510T
                ORDER BY LOT_ID ASC,
                    LOT_SEQ ASC,
                    WH_CODE ASC; */ 

            /* EXEC SQL OPEN DBU_CT_MTL510T_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )563;
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

    DB_stop_query_timer("DBU_open_ct_mtl510t", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_ct_mtl510t(int sel_type, struct CT_MTL510T_TAG *CT_MTL510T)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_MTL510T_N_TAG CT_MTL510T_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CT_MTL510T_CUR_1 INTO
                :CT_MTL510T_N.LOT_ID,
                :CT_MTL510T_N.LOT_SEQ,
                :CT_MTL510T_N.M_S_GBN,
                :CT_MTL510T_N.UP_LOT_ID,
                :CT_MTL510T_N.ORG_CODE,
                :CT_MTL510T_N.WC_CODE,
                :CT_MTL510T_N.WH_CODE,
                :CT_MTL510T_N.ITEM_CODE,
                :CT_MTL510T_N.PUSH_DATE,
                :CT_MTL510T_N.PUSH_TIME,
                :CT_MTL510T_N.PUSH_QTY,
                :CT_MTL510T_N.REMAIN_QTY,
                :CT_MTL510T_N.WORK_FLAG,
                :CT_MTL510T_N.USE_YN,
                :CT_MTL510T_N.REMARKS,
                :CT_MTL510T_N.PUSH_SEQ,
                :CT_MTL510T_N.INSERT_DATE,
                :CT_MTL510T_N.INSERT_USER,
                :CT_MTL510T_N.UPDATE_DATE,
                :CT_MTL510T_N.UPDATE_USER,
                :CT_MTL510T_N.VENDOR_CODE,
                :CT_MTL510T_N.CUST_CODE,
                :CT_MTL510T_N.CUST_SITE_ID,
                :CT_MTL510T_N.END_CUST_ID,
                :CT_MTL510T_N.QC_START_DT,
                :CT_MTL510T_N.QC_END_DT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )578;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CT_MTL510T_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CT_MTL510T_N.LOT_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CT_MTL510T_N.M_S_GBN);
            sqlstm.sqhstl[2] = (unsigned int  )4;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CT_MTL510T_N.UP_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CT_MTL510T_N.ORG_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )4;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CT_MTL510T_N.WC_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CT_MTL510T_N.WH_CODE);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CT_MTL510T_N.ITEM_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CT_MTL510T_N.PUSH_DATE);
            sqlstm.sqhstl[8] = (unsigned int  )9;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CT_MTL510T_N.PUSH_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CT_MTL510T_N.PUSH_QTY);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CT_MTL510T_N.REMAIN_QTY);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CT_MTL510T_N.WORK_FLAG);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CT_MTL510T_N.USE_YN);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CT_MTL510T_N.REMARKS);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CT_MTL510T_N.PUSH_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CT_MTL510T_N.INSERT_DATE);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CT_MTL510T_N.INSERT_USER);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CT_MTL510T_N.UPDATE_DATE);
            sqlstm.sqhstl[18] = (unsigned int  )15;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CT_MTL510T_N.UPDATE_USER);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CT_MTL510T_N.VENDOR_CODE);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CT_MTL510T_N.CUST_CODE);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CT_MTL510T_N.CUST_SITE_ID);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CT_MTL510T_N.END_CUST_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CT_MTL510T_N.QC_START_DT);
            sqlstm.sqhstl[24] = (unsigned int  )15;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CT_MTL510T_N.QC_END_DT);
            sqlstm.sqhstl[25] = (unsigned int  )15;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
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
        DBU_del_null_ct_mtl510t(&CT_MTL510T_N, CT_MTL510T);
    }

    DB_stop_query_timer("DBU_fetch_ct_mtl510t", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_ct_mtl510t(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CT_MTL510T_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )697;
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

    DB_stop_query_timer("DBU_close_ct_mtl510t", sel_type);
}


/* Initialize Function */
void DBU_init_ct_mtl510t(struct CT_MTL510T_TAG *CT_MTL510T)
{
    /* memset by Space */
    memset(CT_MTL510T, ' ', sizeof(struct CT_MTL510T_TAG));
    
    CT_MTL510T->LOT_SEQ = 0;
    CT_MTL510T->PUSH_QTY = 0;
    CT_MTL510T->REMAIN_QTY = 0;
    CT_MTL510T->CUST_SITE_ID = 0;
    CT_MTL510T->END_CUST_ID = 0;
}


/* Add Null Function */
void DBU_add_null_ct_mtl510t(struct CT_MTL510T_N_TAG *CT_MTL510T_N, struct CT_MTL510T_TAG *CT_MTL510T)
{
    /* memset by NULL */
    memset(CT_MTL510T_N, '\0', sizeof(struct CT_MTL510T_N_TAG));
    
    MEMCPY_AN(CT_MTL510T_N->LOT_ID, CT_MTL510T->LOT_ID, sizeof(CT_MTL510T->LOT_ID));
    CT_MTL510T_N->LOT_SEQ = CT_MTL510T->LOT_SEQ;
    MEMCPY_AN(CT_MTL510T_N->M_S_GBN, CT_MTL510T->M_S_GBN, sizeof(CT_MTL510T->M_S_GBN));
    MEMCPY_AN(CT_MTL510T_N->UP_LOT_ID, CT_MTL510T->UP_LOT_ID, sizeof(CT_MTL510T->UP_LOT_ID));
    MEMCPY_AN(CT_MTL510T_N->ORG_CODE, CT_MTL510T->ORG_CODE, sizeof(CT_MTL510T->ORG_CODE));
    MEMCPY_AN(CT_MTL510T_N->WC_CODE, CT_MTL510T->WC_CODE, sizeof(CT_MTL510T->WC_CODE));
    MEMCPY_AN(CT_MTL510T_N->WH_CODE, CT_MTL510T->WH_CODE, sizeof(CT_MTL510T->WH_CODE));
    MEMCPY_AN(CT_MTL510T_N->ITEM_CODE, CT_MTL510T->ITEM_CODE, sizeof(CT_MTL510T->ITEM_CODE));
    MEMCPY_AN(CT_MTL510T_N->PUSH_DATE, CT_MTL510T->PUSH_DATE, sizeof(CT_MTL510T->PUSH_DATE));
    MEMCPY_AN(CT_MTL510T_N->PUSH_TIME, CT_MTL510T->PUSH_TIME, sizeof(CT_MTL510T->PUSH_TIME));
    CT_MTL510T_N->PUSH_QTY = CT_MTL510T->PUSH_QTY;
    CT_MTL510T_N->REMAIN_QTY = CT_MTL510T->REMAIN_QTY;
    CT_MTL510T_N->WORK_FLAG[0] = CT_MTL510T->WORK_FLAG;
    CT_MTL510T_N->USE_YN[0] = CT_MTL510T->USE_YN;
    MEMCPY_AN(CT_MTL510T_N->REMARKS, CT_MTL510T->REMARKS, sizeof(CT_MTL510T->REMARKS));
    MEMCPY_AN(CT_MTL510T_N->PUSH_SEQ, CT_MTL510T->PUSH_SEQ, sizeof(CT_MTL510T->PUSH_SEQ));
    MEMCPY_AN(CT_MTL510T_N->INSERT_DATE, CT_MTL510T->INSERT_DATE, sizeof(CT_MTL510T->INSERT_DATE));
    MEMCPY_AN(CT_MTL510T_N->INSERT_USER, CT_MTL510T->INSERT_USER, sizeof(CT_MTL510T->INSERT_USER));
    MEMCPY_AN(CT_MTL510T_N->UPDATE_DATE, CT_MTL510T->UPDATE_DATE, sizeof(CT_MTL510T->UPDATE_DATE));
    MEMCPY_AN(CT_MTL510T_N->UPDATE_USER, CT_MTL510T->UPDATE_USER, sizeof(CT_MTL510T->UPDATE_USER));
    MEMCPY_AN(CT_MTL510T_N->VENDOR_CODE, CT_MTL510T->VENDOR_CODE, sizeof(CT_MTL510T->VENDOR_CODE));
    MEMCPY_AN(CT_MTL510T_N->CUST_CODE, CT_MTL510T->CUST_CODE, sizeof(CT_MTL510T->CUST_CODE));
    CT_MTL510T_N->CUST_SITE_ID = CT_MTL510T->CUST_SITE_ID;
    CT_MTL510T_N->END_CUST_ID = CT_MTL510T->END_CUST_ID;
    MEMCPY_AN(CT_MTL510T_N->QC_START_DT, CT_MTL510T->QC_START_DT, sizeof(CT_MTL510T->QC_START_DT));
    MEMCPY_AN(CT_MTL510T_N->QC_END_DT, CT_MTL510T->QC_END_DT, sizeof(CT_MTL510T->QC_END_DT));
}


/* Del Null Function */
void DBU_del_null_ct_mtl510t(struct CT_MTL510T_N_TAG *CT_MTL510T_N, struct CT_MTL510T_TAG *CT_MTL510T)
{
    MEMCPY_DN(CT_MTL510T->LOT_ID, CT_MTL510T_N->LOT_ID, sizeof(CT_MTL510T->LOT_ID));
    CT_MTL510T->LOT_SEQ = CT_MTL510T_N->LOT_SEQ;
    MEMCPY_DN(CT_MTL510T->M_S_GBN, CT_MTL510T_N->M_S_GBN, sizeof(CT_MTL510T->M_S_GBN));
    MEMCPY_DN(CT_MTL510T->UP_LOT_ID, CT_MTL510T_N->UP_LOT_ID, sizeof(CT_MTL510T->UP_LOT_ID));
    MEMCPY_DN(CT_MTL510T->ORG_CODE, CT_MTL510T_N->ORG_CODE, sizeof(CT_MTL510T->ORG_CODE));
    MEMCPY_DN(CT_MTL510T->WC_CODE, CT_MTL510T_N->WC_CODE, sizeof(CT_MTL510T->WC_CODE));
    MEMCPY_DN(CT_MTL510T->WH_CODE, CT_MTL510T_N->WH_CODE, sizeof(CT_MTL510T->WH_CODE));
    MEMCPY_DN(CT_MTL510T->ITEM_CODE, CT_MTL510T_N->ITEM_CODE, sizeof(CT_MTL510T->ITEM_CODE));
    MEMCPY_DN(CT_MTL510T->PUSH_DATE, CT_MTL510T_N->PUSH_DATE, sizeof(CT_MTL510T->PUSH_DATE));
    MEMCPY_DN(CT_MTL510T->PUSH_TIME, CT_MTL510T_N->PUSH_TIME, sizeof(CT_MTL510T->PUSH_TIME));
    CT_MTL510T->PUSH_QTY = CT_MTL510T_N->PUSH_QTY;
    CT_MTL510T->REMAIN_QTY = CT_MTL510T_N->REMAIN_QTY;
    CT_MTL510T->WORK_FLAG = CT_MTL510T_N->WORK_FLAG[0];
    CT_MTL510T->USE_YN = CT_MTL510T_N->USE_YN[0];
    MEMCPY_DN(CT_MTL510T->REMARKS, CT_MTL510T_N->REMARKS, sizeof(CT_MTL510T->REMARKS));
    MEMCPY_DN(CT_MTL510T->PUSH_SEQ, CT_MTL510T_N->PUSH_SEQ, sizeof(CT_MTL510T->PUSH_SEQ));
    MEMCPY_DN(CT_MTL510T->INSERT_DATE, CT_MTL510T_N->INSERT_DATE, sizeof(CT_MTL510T->INSERT_DATE));
    MEMCPY_DN(CT_MTL510T->INSERT_USER, CT_MTL510T_N->INSERT_USER, sizeof(CT_MTL510T->INSERT_USER));
    MEMCPY_DN(CT_MTL510T->UPDATE_DATE, CT_MTL510T_N->UPDATE_DATE, sizeof(CT_MTL510T->UPDATE_DATE));
    MEMCPY_DN(CT_MTL510T->UPDATE_USER, CT_MTL510T_N->UPDATE_USER, sizeof(CT_MTL510T->UPDATE_USER));
    MEMCPY_DN(CT_MTL510T->VENDOR_CODE, CT_MTL510T_N->VENDOR_CODE, sizeof(CT_MTL510T->VENDOR_CODE));
    MEMCPY_DN(CT_MTL510T->CUST_CODE, CT_MTL510T_N->CUST_CODE, sizeof(CT_MTL510T->CUST_CODE));
    CT_MTL510T->CUST_SITE_ID = CT_MTL510T_N->CUST_SITE_ID;
    CT_MTL510T->END_CUST_ID = CT_MTL510T_N->END_CUST_ID;
    MEMCPY_DN(CT_MTL510T->QC_START_DT, CT_MTL510T_N->QC_START_DT, sizeof(CT_MTL510T->QC_START_DT));
    MEMCPY_DN(CT_MTL510T->QC_END_DT, CT_MTL510T_N->QC_END_DT, sizeof(CT_MTL510T->QC_END_DT));
}


