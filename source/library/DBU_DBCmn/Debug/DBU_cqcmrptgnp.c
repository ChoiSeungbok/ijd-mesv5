
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
    "DBU_cqcmrptgnp.pc"
};


static unsigned int sqlctx = 9379547;


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
            void  *sqhstv[39];
   unsigned int   sqhstl[39];
            int   sqhsts[39];
            void  *sqindv[39];
            int   sqinds[39];
   unsigned int   sqharm[39];
   unsigned int   *sqharc[39];
   unsigned short  sqadto[39];
   unsigned short  sqtdso[39];
} sqlstm = {13,39};

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
"select FACTORY ,REPORT_NO ,SORT_NO ,QC_NAME ,SPEC_VAL ,LOT_01 ,LOT_02 ,LOT_\
03 ,LOT_04 ,LOT_05 ,LOT_06 ,LOT_07 ,REMARKS ,USE_YN ,CREATE_USER_ID ,CREATE_T\
IME ,UPDATE_USER_ID ,UPDATE_TIME ,CUST_NO ,IMAGE_NUM ,IMAGE_NUM2 ,IMAGE_NUM3 \
,RPT_CMF_1 ,RPT_CMF_2 ,RPT_CMF_3 ,RPT_CMF_4 ,RPT_CMF_5 ,RPT_CMF_6 ,RPT_CMF_7 \
,RPT_CMF_8 ,RPT_CMF_9 ,RPT_CMF_10 ,RPT_CMF_11 ,RPT_CMF_12 ,RPT_CMF_13 ,RPT_CM\
F_14 ,RPT_CMF_15  from CQCMRPTGNP  order by REPORT_NO asc ,SORT_NO asc       \
      ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,634,0,4,46,0,0,39,2,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,
176,0,0,2,646,0,4,161,0,0,39,2,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,
347,0,0,3,80,0,4,279,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,
374,0,0,4,62,0,4,287,0,0,2,1,0,1,0,2,4,0,0,1,97,0,0,
397,0,0,5,62,0,2,323,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
420,0,0,6,44,0,2,329,0,0,1,1,0,1,0,1,97,0,0,
439,0,0,7,565,0,3,358,0,0,37,37,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
602,0,0,8,553,0,5,457,0,0,36,36,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
761,0,0,9,466,0,9,566,0,0,0,0,0,1,0,
776,0,0,9,0,0,13,595,0,0,37,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
939,0,0,9,0,0,15,662,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cqcmrptgnp.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-11-05 20:39:24
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
void DBU_add_null_cqcmrptgnp(struct CQCMRPTGNP_N_TAG *CQCMRPTGNP_N, struct CQCMRPTGNP_TAG *CQCMRPTGNP);
void DBU_del_null_cqcmrptgnp(struct CQCMRPTGNP_N_TAG *CQCMRPTGNP_N, struct CQCMRPTGNP_TAG *CQCMRPTGNP);


/* SQL SELECT Function */
void DBU_select_cqcmrptgnp(int sel_type, struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGNP_N_TAG CQCMRPTGNP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgnp(&CQCMRPTGNP_N, CQCMRPTGNP);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT
			        FACTORY, 
                    REPORT_NO,
                    SORT_NO,
                    QC_NAME,
                    SPEC_VAL,
                    LOT_01,
                    LOT_02,
                    LOT_03,
                    LOT_04,
                    LOT_05,
                    LOT_06,
                    LOT_07,
                    REMARKS,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    CUST_NO,
                    IMAGE_NUM,
                    IMAGE_NUM2,
                    IMAGE_NUM3,
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
				    :CQCMRPTGNP_N.FACTORY,
                    :CQCMRPTGNP_N.REPORT_NO,
                    :CQCMRPTGNP_N.SORT_NO,
                    :CQCMRPTGNP_N.QC_NAME,
                    :CQCMRPTGNP_N.SPEC_VAL,
                    :CQCMRPTGNP_N.LOT_01,
                    :CQCMRPTGNP_N.LOT_02,
                    :CQCMRPTGNP_N.LOT_03,
                    :CQCMRPTGNP_N.LOT_04,
                    :CQCMRPTGNP_N.LOT_05,
                    :CQCMRPTGNP_N.LOT_06,
                    :CQCMRPTGNP_N.LOT_07,
                    :CQCMRPTGNP_N.REMARKS,
                    :CQCMRPTGNP_N.USE_YN,
                    :CQCMRPTGNP_N.CREATE_USER_ID,
                    :CQCMRPTGNP_N.CREATE_TIME,
                    :CQCMRPTGNP_N.UPDATE_USER_ID,
                    :CQCMRPTGNP_N.UPDATE_TIME,
                    :CQCMRPTGNP_N.CUST_NO,
                    :CQCMRPTGNP_N.IMAGE_NUM,
                    :CQCMRPTGNP_N.IMAGE_NUM2,
                    :CQCMRPTGNP_N.IMAGE_NUM3,
                    :CQCMRPTGNP_N.RPT_CMF_1,
                    :CQCMRPTGNP_N.RPT_CMF_2,
                    :CQCMRPTGNP_N.RPT_CMF_3,
                    :CQCMRPTGNP_N.RPT_CMF_4,
                    :CQCMRPTGNP_N.RPT_CMF_5,
                    :CQCMRPTGNP_N.RPT_CMF_6,
                    :CQCMRPTGNP_N.RPT_CMF_7,
                    :CQCMRPTGNP_N.RPT_CMF_8,
                    :CQCMRPTGNP_N.RPT_CMF_9,
                    :CQCMRPTGNP_N.RPT_CMF_10,
                    :CQCMRPTGNP_N.RPT_CMF_11,
                    :CQCMRPTGNP_N.RPT_CMF_12,
                    :CQCMRPTGNP_N.RPT_CMF_13,
                    :CQCMRPTGNP_N.RPT_CMF_14,
                    :CQCMRPTGNP_N.RPT_CMF_15
                FROM CQCMRPTGNP
                WHERE REPORT_NO = :CQCMRPTGNP_N.REPORT_NO
                    AND SORT_NO = :CQCMRPTGNP_N.SORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,REPORT_NO ,SORT_NO ,QC_NAME ,SPE\
C_VAL ,LOT_01 ,LOT_02 ,LOT_03 ,LOT_04 ,LOT_05 ,LOT_06 ,LOT_07 ,REMARKS ,USE_Y\
N ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,CUST_NO ,IMAGE_N\
UM ,IMAGE_NUM2 ,IMAGE_NUM3 ,RPT_CMF_1 ,RPT_CMF_2 ,RPT_CMF_3 ,RPT_CMF_4 ,RPT_C\
MF_5 ,RPT_CMF_6 ,RPT_CMF_7 ,RPT_CMF_8 ,RPT_CMF_9 ,RPT_CMF_10 ,RPT_CMF_11 ,RPT\
_CMF_12 ,RPT_CMF_13 ,RPT_CMF_14 ,RPT_CMF_15 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,\
:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,\
:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36  from C\
QCMRPTGNP where (REPORT_NO=:b1 and SORT_NO=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGNP_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CQCMRPTGNP_N.SORT_NO);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGNP_N.QC_NAME);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGNP_N.SPEC_VAL);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGNP_N.LOT_01);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGNP_N.LOT_02);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGNP_N.LOT_03);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGNP_N.LOT_04);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGNP_N.LOT_05);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGNP_N.LOT_06);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGNP_N.LOT_07);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGNP_N.REMARKS);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGNP_N.USE_YN);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGNP_N.CREATE_USER_ID);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGNP_N.CREATE_TIME);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGNP_N.UPDATE_USER_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGNP_N.UPDATE_TIME);
            sqlstm.sqhstl[17] = (unsigned int  )15;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGNP_N.CUST_NO);
            sqlstm.sqhstl[18] = (unsigned int  )51;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM2);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM3);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_1);
            sqlstm.sqhstl[22] = (unsigned int  )51;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_2);
            sqlstm.sqhstl[23] = (unsigned int  )51;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_3);
            sqlstm.sqhstl[24] = (unsigned int  )51;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_4);
            sqlstm.sqhstl[25] = (unsigned int  )51;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_5);
            sqlstm.sqhstl[26] = (unsigned int  )51;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_6);
            sqlstm.sqhstl[27] = (unsigned int  )51;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_7);
            sqlstm.sqhstl[28] = (unsigned int  )51;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_8);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_9);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_10);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_11);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_12);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_13);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_14);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_15);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CQCMRPTGNP_N.SORT_NO);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
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
        DBU_del_null_cqcmrptgnp(&CQCMRPTGNP_N, CQCMRPTGNP);
    }

    DB_stop_query_timer("DBU_select_cqcmrptgnp", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cqcmrptgnp_for_update(int sel_type, struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGNP_N_TAG CQCMRPTGNP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgnp(&CQCMRPTGNP_N, CQCMRPTGNP);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT
			        FACTORY, 
                    REPORT_NO,
                    SORT_NO,
                    QC_NAME,
                    SPEC_VAL,
                    LOT_01,
                    LOT_02,
                    LOT_03,
                    LOT_04,
                    LOT_05,
                    LOT_06,
                    LOT_07,
                    REMARKS,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    CUST_NO,
                    IMAGE_NUM,
                    IMAGE_NUM2,
                    IMAGE_NUM3,
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
				     :CQCMRPTGNP_N.FACTORY,
                    :CQCMRPTGNP_N.REPORT_NO,
                    :CQCMRPTGNP_N.SORT_NO,
                    :CQCMRPTGNP_N.QC_NAME,
                    :CQCMRPTGNP_N.SPEC_VAL,
                    :CQCMRPTGNP_N.LOT_01,
                    :CQCMRPTGNP_N.LOT_02,
                    :CQCMRPTGNP_N.LOT_03,
                    :CQCMRPTGNP_N.LOT_04,
                    :CQCMRPTGNP_N.LOT_05,
                    :CQCMRPTGNP_N.LOT_06,
                    :CQCMRPTGNP_N.LOT_07,
                    :CQCMRPTGNP_N.REMARKS,
                    :CQCMRPTGNP_N.USE_YN,
                    :CQCMRPTGNP_N.CREATE_USER_ID,
                    :CQCMRPTGNP_N.CREATE_TIME,
                    :CQCMRPTGNP_N.UPDATE_USER_ID,
                    :CQCMRPTGNP_N.UPDATE_TIME,
                    :CQCMRPTGNP_N.CUST_NO,
                    :CQCMRPTGNP_N.IMAGE_NUM,
                    :CQCMRPTGNP_N.IMAGE_NUM2,
                    :CQCMRPTGNP_N.IMAGE_NUM3,
                    :CQCMRPTGNP_N.RPT_CMF_1,
                    :CQCMRPTGNP_N.RPT_CMF_2,
                    :CQCMRPTGNP_N.RPT_CMF_3,
                    :CQCMRPTGNP_N.RPT_CMF_4,
                    :CQCMRPTGNP_N.RPT_CMF_5,
                    :CQCMRPTGNP_N.RPT_CMF_6,
                    :CQCMRPTGNP_N.RPT_CMF_7,
                    :CQCMRPTGNP_N.RPT_CMF_8,
                    :CQCMRPTGNP_N.RPT_CMF_9,
                    :CQCMRPTGNP_N.RPT_CMF_10,
                    :CQCMRPTGNP_N.RPT_CMF_11,
                    :CQCMRPTGNP_N.RPT_CMF_12,
                    :CQCMRPTGNP_N.RPT_CMF_13,
                    :CQCMRPTGNP_N.RPT_CMF_14,
                    :CQCMRPTGNP_N.RPT_CMF_15
                FROM CQCMRPTGNP
                WHERE REPORT_NO = :CQCMRPTGNP_N.REPORT_NO
                    AND SORT_NO = :CQCMRPTGNP_N.SORT_NO
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,REPORT_NO ,SORT_NO ,QC_NAME ,SPE\
C_VAL ,LOT_01 ,LOT_02 ,LOT_03 ,LOT_04 ,LOT_05 ,LOT_06 ,LOT_07 ,REMARKS ,USE_Y\
N ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,CUST_NO ,IMAGE_N\
UM ,IMAGE_NUM2 ,IMAGE_NUM3 ,RPT_CMF_1 ,RPT_CMF_2 ,RPT_CMF_3 ,RPT_CMF_4 ,RPT_C\
MF_5 ,RPT_CMF_6 ,RPT_CMF_7 ,RPT_CMF_8 ,RPT_CMF_9 ,RPT_CMF_10 ,RPT_CMF_11 ,RPT\
_CMF_12 ,RPT_CMF_13 ,RPT_CMF_14 ,RPT_CMF_15 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,\
:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,\
:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36  from C\
QCMRPTGNP where (REPORT_NO=:b1 and SORT_NO=:b2) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )176;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGNP_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CQCMRPTGNP_N.SORT_NO);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGNP_N.QC_NAME);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGNP_N.SPEC_VAL);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGNP_N.LOT_01);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGNP_N.LOT_02);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGNP_N.LOT_03);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGNP_N.LOT_04);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGNP_N.LOT_05);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGNP_N.LOT_06);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGNP_N.LOT_07);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGNP_N.REMARKS);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGNP_N.USE_YN);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGNP_N.CREATE_USER_ID);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGNP_N.CREATE_TIME);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGNP_N.UPDATE_USER_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGNP_N.UPDATE_TIME);
            sqlstm.sqhstl[17] = (unsigned int  )15;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGNP_N.CUST_NO);
            sqlstm.sqhstl[18] = (unsigned int  )51;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM2);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM3);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_1);
            sqlstm.sqhstl[22] = (unsigned int  )51;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_2);
            sqlstm.sqhstl[23] = (unsigned int  )51;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_3);
            sqlstm.sqhstl[24] = (unsigned int  )51;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_4);
            sqlstm.sqhstl[25] = (unsigned int  )51;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_5);
            sqlstm.sqhstl[26] = (unsigned int  )51;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_6);
            sqlstm.sqhstl[27] = (unsigned int  )51;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_7);
            sqlstm.sqhstl[28] = (unsigned int  )51;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_8);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_9);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_10);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_11);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_12);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_13);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_14);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_15);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CQCMRPTGNP_N.SORT_NO);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
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
        DBU_del_null_cqcmrptgnp(&CQCMRPTGNP_N, CQCMRPTGNP);
    }

    DB_stop_query_timer("DBU_select_cqcmrptgnp_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cqcmrptgnp_scalar(int sel_type, struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGNP_N_TAG CQCMRPTGNP_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgnp(&CQCMRPTGNP_N, CQCMRPTGNP);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMRPTGNP
                WHERE REPORT_NO = :CQCMRPTGNP_N.REPORT_NO
                    AND SORT_NO = :CQCMRPTGNP_N.SORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMRPTGNP where\
 (REPORT_NO=:b1 and SORT_NO=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )347;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CQCMRPTGNP_N.SORT_NO);
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
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMRPTGNP
                WHERE REPORT_NO = :CQCMRPTGNP_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMRPTGNP where\
 REPORT_NO=:b1";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )374;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
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

    DB_stop_query_timer("DBU_select_cqcmrptgnp_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cqcmrptgnp(int sel_type, struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGNP_N_TAG CQCMRPTGNP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgnp(&CQCMRPTGNP_N, CQCMRPTGNP);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CQCMRPTGNP
                WHERE REPORT_NO = :CQCMRPTGNP_N.REPORT_NO
                    AND SORT_NO = :CQCMRPTGNP_N.SORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMRPTGNP  where (REPORT_NO=:b0 an\
d SORT_NO=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )397;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CQCMRPTGNP_N.SORT_NO);
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

		 case 2:
            /* EXEC SQL DELETE FROM CQCMRPTGNP
                WHERE REPORT_NO = :CQCMRPTGNP_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMRPTGNP  where REPORT_NO=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )420;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
            sqlstm.sqhstl[0] = (unsigned int  )21;
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

    DB_stop_query_timer("DBU_delete_cqcmrptgnp", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cqcmrptgnp(struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGNP_N_TAG CQCMRPTGNP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgnp(&CQCMRPTGNP_N, CQCMRPTGNP);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CQCMRPTGNP( 
	                FACTORY,
                    REPORT_NO, 
                    SORT_NO, 
                    QC_NAME, 
                    SPEC_VAL, 
                    LOT_01, 
                    LOT_02, 
                    LOT_03, 
                    LOT_04, 
                    LOT_05, 
                    LOT_06, 
                    LOT_07, 
                    REMARKS, 
                    USE_YN, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    CUST_NO, 
                    IMAGE_NUM, 
                    IMAGE_NUM2, 
                    IMAGE_NUM3, 
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
		             :CQCMRPTGNP_N.FACTORY,
                    :CQCMRPTGNP_N.REPORT_NO,
                    :CQCMRPTGNP_N.SORT_NO,
                    :CQCMRPTGNP_N.QC_NAME,
                    :CQCMRPTGNP_N.SPEC_VAL,
                    :CQCMRPTGNP_N.LOT_01,
                    :CQCMRPTGNP_N.LOT_02,
                    :CQCMRPTGNP_N.LOT_03,
                    :CQCMRPTGNP_N.LOT_04,
                    :CQCMRPTGNP_N.LOT_05,
                    :CQCMRPTGNP_N.LOT_06,
                    :CQCMRPTGNP_N.LOT_07,
                    :CQCMRPTGNP_N.REMARKS,
                    :CQCMRPTGNP_N.USE_YN,
                    :CQCMRPTGNP_N.CREATE_USER_ID,
                    :CQCMRPTGNP_N.CREATE_TIME,
                    :CQCMRPTGNP_N.UPDATE_USER_ID,
                    :CQCMRPTGNP_N.UPDATE_TIME,
                    :CQCMRPTGNP_N.CUST_NO,
                    :CQCMRPTGNP_N.IMAGE_NUM,
                    :CQCMRPTGNP_N.IMAGE_NUM2,
                    :CQCMRPTGNP_N.IMAGE_NUM3,
                    :CQCMRPTGNP_N.RPT_CMF_1,
                    :CQCMRPTGNP_N.RPT_CMF_2,
                    :CQCMRPTGNP_N.RPT_CMF_3,
                    :CQCMRPTGNP_N.RPT_CMF_4,
                    :CQCMRPTGNP_N.RPT_CMF_5,
                    :CQCMRPTGNP_N.RPT_CMF_6,
                    :CQCMRPTGNP_N.RPT_CMF_7,
                    :CQCMRPTGNP_N.RPT_CMF_8,
                    :CQCMRPTGNP_N.RPT_CMF_9,
                    :CQCMRPTGNP_N.RPT_CMF_10,
                    :CQCMRPTGNP_N.RPT_CMF_11,
                    :CQCMRPTGNP_N.RPT_CMF_12,
                    :CQCMRPTGNP_N.RPT_CMF_13,
                    :CQCMRPTGNP_N.RPT_CMF_14,
                    :CQCMRPTGNP_N.RPT_CMF_15
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 39;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into CQCMRPTGNP (FACTORY,REPORT_NO,SORT_NO,QC_NAM\
E,SPEC_VAL,LOT_01,LOT_02,LOT_03,LOT_04,LOT_05,LOT_06,LOT_07,REMARKS,USE_YN,CR\
EATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME,CUST_NO,IMAGE_NUM,IMAGE_N\
UM2,IMAGE_NUM3,RPT_CMF_1,RPT_CMF_2,RPT_CMF_3,RPT_CMF_4,RPT_CMF_5,RPT_CMF_6,RP\
T_CMF_7,RPT_CMF_8,RPT_CMF_9,RPT_CMF_10,RPT_CMF_11,RPT_CMF_12,RPT_CMF_13,RPT_C\
MF_14,RPT_CMF_15) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:\
b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b2\
7,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )439;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGNP_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(CQCMRPTGNP_N.SORT_NO);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGNP_N.QC_NAME);
    sqlstm.sqhstl[3] = (unsigned int  )31;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGNP_N.SPEC_VAL);
    sqlstm.sqhstl[4] = (unsigned int  )31;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGNP_N.LOT_01);
    sqlstm.sqhstl[5] = (unsigned int  )31;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGNP_N.LOT_02);
    sqlstm.sqhstl[6] = (unsigned int  )31;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGNP_N.LOT_03);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGNP_N.LOT_04);
    sqlstm.sqhstl[8] = (unsigned int  )31;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGNP_N.LOT_05);
    sqlstm.sqhstl[9] = (unsigned int  )31;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGNP_N.LOT_06);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGNP_N.LOT_07);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGNP_N.REMARKS);
    sqlstm.sqhstl[12] = (unsigned int  )101;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGNP_N.USE_YN);
    sqlstm.sqhstl[13] = (unsigned int  )2;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGNP_N.CREATE_USER_ID);
    sqlstm.sqhstl[14] = (unsigned int  )21;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGNP_N.CREATE_TIME);
    sqlstm.sqhstl[15] = (unsigned int  )15;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGNP_N.UPDATE_USER_ID);
    sqlstm.sqhstl[16] = (unsigned int  )21;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGNP_N.UPDATE_TIME);
    sqlstm.sqhstl[17] = (unsigned int  )15;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGNP_N.CUST_NO);
    sqlstm.sqhstl[18] = (unsigned int  )51;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM);
    sqlstm.sqhstl[19] = (unsigned int  )21;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM2);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM3);
    sqlstm.sqhstl[21] = (unsigned int  )21;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_1);
    sqlstm.sqhstl[22] = (unsigned int  )51;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_2);
    sqlstm.sqhstl[23] = (unsigned int  )51;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_3);
    sqlstm.sqhstl[24] = (unsigned int  )51;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_4);
    sqlstm.sqhstl[25] = (unsigned int  )51;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_5);
    sqlstm.sqhstl[26] = (unsigned int  )51;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_6);
    sqlstm.sqhstl[27] = (unsigned int  )51;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_7);
    sqlstm.sqhstl[28] = (unsigned int  )51;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_8);
    sqlstm.sqhstl[29] = (unsigned int  )51;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_9);
    sqlstm.sqhstl[30] = (unsigned int  )51;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_10);
    sqlstm.sqhstl[31] = (unsigned int  )51;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_11);
    sqlstm.sqhstl[32] = (unsigned int  )51;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_12);
    sqlstm.sqhstl[33] = (unsigned int  )51;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_13);
    sqlstm.sqhstl[34] = (unsigned int  )51;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_14);
    sqlstm.sqhstl[35] = (unsigned int  )51;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_15);
    sqlstm.sqhstl[36] = (unsigned int  )51;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_cqcmrptgnp", 0);
}


/* SQL UPDATE Function */
void DBU_update_cqcmrptgnp(int sel_type, struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGNP_N_TAG CQCMRPTGNP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgnp(&CQCMRPTGNP_N, CQCMRPTGNP);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CQCMRPTGNP SET
                    QC_NAME = :CQCMRPTGNP_N.QC_NAME,
                    SPEC_VAL = :CQCMRPTGNP_N.SPEC_VAL,
                    LOT_01 = :CQCMRPTGNP_N.LOT_01,
                    LOT_02 = :CQCMRPTGNP_N.LOT_02,
                    LOT_03 = :CQCMRPTGNP_N.LOT_03,
                    LOT_04 = :CQCMRPTGNP_N.LOT_04,
                    LOT_05 = :CQCMRPTGNP_N.LOT_05,
                    LOT_06 = :CQCMRPTGNP_N.LOT_06,
                    LOT_07 = :CQCMRPTGNP_N.LOT_07,
                    REMARKS = :CQCMRPTGNP_N.REMARKS,
                    USE_YN = :CQCMRPTGNP_N.USE_YN,
                    CREATE_USER_ID = :CQCMRPTGNP_N.CREATE_USER_ID,
                    CREATE_TIME = :CQCMRPTGNP_N.CREATE_TIME,
                    UPDATE_USER_ID = :CQCMRPTGNP_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CQCMRPTGNP_N.UPDATE_TIME,
                    CUST_NO = :CQCMRPTGNP_N.CUST_NO,
                    IMAGE_NUM = :CQCMRPTGNP_N.IMAGE_NUM,
                    IMAGE_NUM2 = :CQCMRPTGNP_N.IMAGE_NUM2,
                    IMAGE_NUM3 = :CQCMRPTGNP_N.IMAGE_NUM3,
                    RPT_CMF_1 = :CQCMRPTGNP_N.RPT_CMF_1,
                    RPT_CMF_2 = :CQCMRPTGNP_N.RPT_CMF_2,
                    RPT_CMF_3 = :CQCMRPTGNP_N.RPT_CMF_3,
                    RPT_CMF_4 = :CQCMRPTGNP_N.RPT_CMF_4,
                    RPT_CMF_5 = :CQCMRPTGNP_N.RPT_CMF_5,
                    RPT_CMF_6 = :CQCMRPTGNP_N.RPT_CMF_6,
                    RPT_CMF_7 = :CQCMRPTGNP_N.RPT_CMF_7,
                    RPT_CMF_8 = :CQCMRPTGNP_N.RPT_CMF_8,
                    RPT_CMF_9 = :CQCMRPTGNP_N.RPT_CMF_9,
                    RPT_CMF_10 = :CQCMRPTGNP_N.RPT_CMF_10,
                    RPT_CMF_11 = :CQCMRPTGNP_N.RPT_CMF_11,
                    RPT_CMF_12 = :CQCMRPTGNP_N.RPT_CMF_12,
                    RPT_CMF_13 = :CQCMRPTGNP_N.RPT_CMF_13,
                    RPT_CMF_14 = :CQCMRPTGNP_N.RPT_CMF_14,
                    RPT_CMF_15 = :CQCMRPTGNP_N.RPT_CMF_15
                WHERE REPORT_NO = :CQCMRPTGNP_N.REPORT_NO
                    AND SORT_NO = :CQCMRPTGNP_N.SORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CQCMRPTGNP  set QC_NAME=:b0,SPEC_VAL=:b1,\
LOT_01=:b2,LOT_02=:b3,LOT_03=:b4,LOT_04=:b5,LOT_05=:b6,LOT_06=:b7,LOT_07=:b8,\
REMARKS=:b9,USE_YN=:b10,CREATE_USER_ID=:b11,CREATE_TIME=:b12,UPDATE_USER_ID=:\
b13,UPDATE_TIME=:b14,CUST_NO=:b15,IMAGE_NUM=:b16,IMAGE_NUM2=:b17,IMAGE_NUM3=:\
b18,RPT_CMF_1=:b19,RPT_CMF_2=:b20,RPT_CMF_3=:b21,RPT_CMF_4=:b22,RPT_CMF_5=:b2\
3,RPT_CMF_6=:b24,RPT_CMF_7=:b25,RPT_CMF_8=:b26,RPT_CMF_9=:b27,RPT_CMF_10=:b28\
,RPT_CMF_11=:b29,RPT_CMF_12=:b30,RPT_CMF_13=:b31,RPT_CMF_14=:b32,RPT_CMF_15=:\
b33 where (REPORT_NO=:b34 and SORT_NO=:b35)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )602;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGNP_N.QC_NAME);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGNP_N.SPEC_VAL);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGNP_N.LOT_01);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGNP_N.LOT_02);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGNP_N.LOT_03);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGNP_N.LOT_04);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGNP_N.LOT_05);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGNP_N.LOT_06);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGNP_N.LOT_07);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGNP_N.REMARKS);
            sqlstm.sqhstl[9] = (unsigned int  )101;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGNP_N.USE_YN);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGNP_N.CREATE_USER_ID);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGNP_N.CREATE_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGNP_N.UPDATE_USER_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGNP_N.UPDATE_TIME);
            sqlstm.sqhstl[14] = (unsigned int  )15;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGNP_N.CUST_NO);
            sqlstm.sqhstl[15] = (unsigned int  )51;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM2);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM3);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_1);
            sqlstm.sqhstl[19] = (unsigned int  )51;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_2);
            sqlstm.sqhstl[20] = (unsigned int  )51;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_3);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_4);
            sqlstm.sqhstl[22] = (unsigned int  )51;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_5);
            sqlstm.sqhstl[23] = (unsigned int  )51;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_6);
            sqlstm.sqhstl[24] = (unsigned int  )51;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_7);
            sqlstm.sqhstl[25] = (unsigned int  )51;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_8);
            sqlstm.sqhstl[26] = (unsigned int  )51;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_9);
            sqlstm.sqhstl[27] = (unsigned int  )51;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_10);
            sqlstm.sqhstl[28] = (unsigned int  )51;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_11);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_12);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_13);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_14);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_15);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CQCMRPTGNP_N.SORT_NO);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_cqcmrptgnp", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cqcmrptgnp(int sel_type, struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGNP_N_TAG CQCMRPTGNP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgnp(&CQCMRPTGNP_N, CQCMRPTGNP);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CQCMRPTGNP_CUR_1 CURSOR FOR
                SELECT 
				    FACTORY,
                    REPORT_NO,
                    SORT_NO,
                    QC_NAME,
                    SPEC_VAL,
                    LOT_01,
                    LOT_02,
                    LOT_03,
                    LOT_04,
                    LOT_05,
                    LOT_06,
                    LOT_07,
                    REMARKS,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    CUST_NO,
                    IMAGE_NUM,
                    IMAGE_NUM2,
                    IMAGE_NUM3,
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
                FROM CQCMRPTGNP
                ORDER BY REPORT_NO ASC,
                    SORT_NO ASC; */ 

            /* EXEC SQL OPEN DBU_CQCMRPTGNP_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )761;
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

    DB_stop_query_timer("DBU_open_cqcmrptgnp", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cqcmrptgnp(int sel_type, struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGNP_N_TAG CQCMRPTGNP_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CQCMRPTGNP_CUR_1 INTO
			    :CQCMRPTGNP_N.FACTORY,
                :CQCMRPTGNP_N.REPORT_NO,
                :CQCMRPTGNP_N.SORT_NO,
                :CQCMRPTGNP_N.QC_NAME,
                :CQCMRPTGNP_N.SPEC_VAL,
                :CQCMRPTGNP_N.LOT_01,
                :CQCMRPTGNP_N.LOT_02,
                :CQCMRPTGNP_N.LOT_03,
                :CQCMRPTGNP_N.LOT_04,
                :CQCMRPTGNP_N.LOT_05,
                :CQCMRPTGNP_N.LOT_06,
                :CQCMRPTGNP_N.LOT_07,
                :CQCMRPTGNP_N.REMARKS,
                :CQCMRPTGNP_N.USE_YN,
                :CQCMRPTGNP_N.CREATE_USER_ID,
                :CQCMRPTGNP_N.CREATE_TIME,
                :CQCMRPTGNP_N.UPDATE_USER_ID,
                :CQCMRPTGNP_N.UPDATE_TIME,
                :CQCMRPTGNP_N.CUST_NO,
                :CQCMRPTGNP_N.IMAGE_NUM,
                :CQCMRPTGNP_N.IMAGE_NUM2,
                :CQCMRPTGNP_N.IMAGE_NUM3,
                :CQCMRPTGNP_N.RPT_CMF_1,
                :CQCMRPTGNP_N.RPT_CMF_2,
                :CQCMRPTGNP_N.RPT_CMF_3,
                :CQCMRPTGNP_N.RPT_CMF_4,
                :CQCMRPTGNP_N.RPT_CMF_5,
                :CQCMRPTGNP_N.RPT_CMF_6,
                :CQCMRPTGNP_N.RPT_CMF_7,
                :CQCMRPTGNP_N.RPT_CMF_8,
                :CQCMRPTGNP_N.RPT_CMF_9,
                :CQCMRPTGNP_N.RPT_CMF_10,
                :CQCMRPTGNP_N.RPT_CMF_11,
                :CQCMRPTGNP_N.RPT_CMF_12,
                :CQCMRPTGNP_N.RPT_CMF_13,
                :CQCMRPTGNP_N.RPT_CMF_14,
                :CQCMRPTGNP_N.RPT_CMF_15; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )776;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGNP_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGNP_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CQCMRPTGNP_N.SORT_NO);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGNP_N.QC_NAME);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGNP_N.SPEC_VAL);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGNP_N.LOT_01);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGNP_N.LOT_02);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGNP_N.LOT_03);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGNP_N.LOT_04);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGNP_N.LOT_05);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGNP_N.LOT_06);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGNP_N.LOT_07);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGNP_N.REMARKS);
            sqlstm.sqhstl[12] = (unsigned int  )101;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGNP_N.USE_YN);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGNP_N.CREATE_USER_ID);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGNP_N.CREATE_TIME);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGNP_N.UPDATE_USER_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGNP_N.UPDATE_TIME);
            sqlstm.sqhstl[17] = (unsigned int  )15;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGNP_N.CUST_NO);
            sqlstm.sqhstl[18] = (unsigned int  )51;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM2);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGNP_N.IMAGE_NUM3);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_1);
            sqlstm.sqhstl[22] = (unsigned int  )51;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_2);
            sqlstm.sqhstl[23] = (unsigned int  )51;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_3);
            sqlstm.sqhstl[24] = (unsigned int  )51;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_4);
            sqlstm.sqhstl[25] = (unsigned int  )51;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_5);
            sqlstm.sqhstl[26] = (unsigned int  )51;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_6);
            sqlstm.sqhstl[27] = (unsigned int  )51;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_7);
            sqlstm.sqhstl[28] = (unsigned int  )51;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_8);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_9);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_10);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_11);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_12);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_13);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_14);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGNP_N.RPT_CMF_15);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
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
        DBU_del_null_cqcmrptgnp(&CQCMRPTGNP_N, CQCMRPTGNP);
    }

    DB_stop_query_timer("DBU_fetch_cqcmrptgnp", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cqcmrptgnp(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CQCMRPTGNP_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )939;
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

    DB_stop_query_timer("DBU_close_cqcmrptgnp", sel_type);
}


/* Initialize Function */
void DBU_init_cqcmrptgnp(struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    /* memset by Space */
    memset(CQCMRPTGNP, ' ', sizeof(struct CQCMRPTGNP_TAG));
    
    CQCMRPTGNP->SORT_NO = 0;
}


/* Add Null Function */
void DBU_add_null_cqcmrptgnp(struct CQCMRPTGNP_N_TAG *CQCMRPTGNP_N, struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    /* memset by NULL */
    memset(CQCMRPTGNP_N, '\0', sizeof(struct CQCMRPTGNP_N_TAG));
    
	MEMCPY_AN(CQCMRPTGNP_N->FACTORY, CQCMRPTGNP->FACTORY, sizeof(CQCMRPTGNP->FACTORY));
    MEMCPY_AN(CQCMRPTGNP_N->REPORT_NO, CQCMRPTGNP->REPORT_NO, sizeof(CQCMRPTGNP->REPORT_NO));
    CQCMRPTGNP_N->SORT_NO = CQCMRPTGNP->SORT_NO;
    MEMCPY_AN(CQCMRPTGNP_N->QC_NAME, CQCMRPTGNP->QC_NAME, sizeof(CQCMRPTGNP->QC_NAME));
    MEMCPY_AN(CQCMRPTGNP_N->SPEC_VAL, CQCMRPTGNP->SPEC_VAL, sizeof(CQCMRPTGNP->SPEC_VAL));
    MEMCPY_AN(CQCMRPTGNP_N->LOT_01, CQCMRPTGNP->LOT_01, sizeof(CQCMRPTGNP->LOT_01));
    MEMCPY_AN(CQCMRPTGNP_N->LOT_02, CQCMRPTGNP->LOT_02, sizeof(CQCMRPTGNP->LOT_02));
    MEMCPY_AN(CQCMRPTGNP_N->LOT_03, CQCMRPTGNP->LOT_03, sizeof(CQCMRPTGNP->LOT_03));
    MEMCPY_AN(CQCMRPTGNP_N->LOT_04, CQCMRPTGNP->LOT_04, sizeof(CQCMRPTGNP->LOT_04));
    MEMCPY_AN(CQCMRPTGNP_N->LOT_05, CQCMRPTGNP->LOT_05, sizeof(CQCMRPTGNP->LOT_05));
    MEMCPY_AN(CQCMRPTGNP_N->LOT_06, CQCMRPTGNP->LOT_06, sizeof(CQCMRPTGNP->LOT_06));
    MEMCPY_AN(CQCMRPTGNP_N->LOT_07, CQCMRPTGNP->LOT_07, sizeof(CQCMRPTGNP->LOT_07));
    MEMCPY_AN(CQCMRPTGNP_N->REMARKS, CQCMRPTGNP->REMARKS, sizeof(CQCMRPTGNP->REMARKS));
    CQCMRPTGNP_N->USE_YN[0] = CQCMRPTGNP->USE_YN;
    MEMCPY_AN(CQCMRPTGNP_N->CREATE_USER_ID, CQCMRPTGNP->CREATE_USER_ID, sizeof(CQCMRPTGNP->CREATE_USER_ID));
    MEMCPY_AN(CQCMRPTGNP_N->CREATE_TIME, CQCMRPTGNP->CREATE_TIME, sizeof(CQCMRPTGNP->CREATE_TIME));
    MEMCPY_AN(CQCMRPTGNP_N->UPDATE_USER_ID, CQCMRPTGNP->UPDATE_USER_ID, sizeof(CQCMRPTGNP->UPDATE_USER_ID));
    MEMCPY_AN(CQCMRPTGNP_N->UPDATE_TIME, CQCMRPTGNP->UPDATE_TIME, sizeof(CQCMRPTGNP->UPDATE_TIME));
    MEMCPY_AN(CQCMRPTGNP_N->CUST_NO, CQCMRPTGNP->CUST_NO, sizeof(CQCMRPTGNP->CUST_NO));
    MEMCPY_AN(CQCMRPTGNP_N->IMAGE_NUM, CQCMRPTGNP->IMAGE_NUM, sizeof(CQCMRPTGNP->IMAGE_NUM));
    MEMCPY_AN(CQCMRPTGNP_N->IMAGE_NUM2, CQCMRPTGNP->IMAGE_NUM2, sizeof(CQCMRPTGNP->IMAGE_NUM2));
    MEMCPY_AN(CQCMRPTGNP_N->IMAGE_NUM3, CQCMRPTGNP->IMAGE_NUM3, sizeof(CQCMRPTGNP->IMAGE_NUM3));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_1, CQCMRPTGNP->RPT_CMF_1, sizeof(CQCMRPTGNP->RPT_CMF_1));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_2, CQCMRPTGNP->RPT_CMF_2, sizeof(CQCMRPTGNP->RPT_CMF_2));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_3, CQCMRPTGNP->RPT_CMF_3, sizeof(CQCMRPTGNP->RPT_CMF_3));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_4, CQCMRPTGNP->RPT_CMF_4, sizeof(CQCMRPTGNP->RPT_CMF_4));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_5, CQCMRPTGNP->RPT_CMF_5, sizeof(CQCMRPTGNP->RPT_CMF_5));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_6, CQCMRPTGNP->RPT_CMF_6, sizeof(CQCMRPTGNP->RPT_CMF_6));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_7, CQCMRPTGNP->RPT_CMF_7, sizeof(CQCMRPTGNP->RPT_CMF_7));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_8, CQCMRPTGNP->RPT_CMF_8, sizeof(CQCMRPTGNP->RPT_CMF_8));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_9, CQCMRPTGNP->RPT_CMF_9, sizeof(CQCMRPTGNP->RPT_CMF_9));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_10, CQCMRPTGNP->RPT_CMF_10, sizeof(CQCMRPTGNP->RPT_CMF_10));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_11, CQCMRPTGNP->RPT_CMF_11, sizeof(CQCMRPTGNP->RPT_CMF_11));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_12, CQCMRPTGNP->RPT_CMF_12, sizeof(CQCMRPTGNP->RPT_CMF_12));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_13, CQCMRPTGNP->RPT_CMF_13, sizeof(CQCMRPTGNP->RPT_CMF_13));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_14, CQCMRPTGNP->RPT_CMF_14, sizeof(CQCMRPTGNP->RPT_CMF_14));
    MEMCPY_AN(CQCMRPTGNP_N->RPT_CMF_15, CQCMRPTGNP->RPT_CMF_15, sizeof(CQCMRPTGNP->RPT_CMF_15));
}


/* Del Null Function */
void DBU_del_null_cqcmrptgnp(struct CQCMRPTGNP_N_TAG *CQCMRPTGNP_N, struct CQCMRPTGNP_TAG *CQCMRPTGNP)
{
    MEMCPY_DN(CQCMRPTGNP->FACTORY, CQCMRPTGNP_N->FACTORY, sizeof(CQCMRPTGNP->FACTORY));
    MEMCPY_DN(CQCMRPTGNP->REPORT_NO, CQCMRPTGNP_N->REPORT_NO, sizeof(CQCMRPTGNP->REPORT_NO));
    CQCMRPTGNP->SORT_NO = CQCMRPTGNP_N->SORT_NO;
    MEMCPY_DN(CQCMRPTGNP->QC_NAME, CQCMRPTGNP_N->QC_NAME, sizeof(CQCMRPTGNP->QC_NAME));
    MEMCPY_DN(CQCMRPTGNP->SPEC_VAL, CQCMRPTGNP_N->SPEC_VAL, sizeof(CQCMRPTGNP->SPEC_VAL));
    MEMCPY_DN(CQCMRPTGNP->LOT_01, CQCMRPTGNP_N->LOT_01, sizeof(CQCMRPTGNP->LOT_01));
    MEMCPY_DN(CQCMRPTGNP->LOT_02, CQCMRPTGNP_N->LOT_02, sizeof(CQCMRPTGNP->LOT_02));
    MEMCPY_DN(CQCMRPTGNP->LOT_03, CQCMRPTGNP_N->LOT_03, sizeof(CQCMRPTGNP->LOT_03));
    MEMCPY_DN(CQCMRPTGNP->LOT_04, CQCMRPTGNP_N->LOT_04, sizeof(CQCMRPTGNP->LOT_04));
    MEMCPY_DN(CQCMRPTGNP->LOT_05, CQCMRPTGNP_N->LOT_05, sizeof(CQCMRPTGNP->LOT_05));
    MEMCPY_DN(CQCMRPTGNP->LOT_06, CQCMRPTGNP_N->LOT_06, sizeof(CQCMRPTGNP->LOT_06));
    MEMCPY_DN(CQCMRPTGNP->LOT_07, CQCMRPTGNP_N->LOT_07, sizeof(CQCMRPTGNP->LOT_07));
    MEMCPY_DN(CQCMRPTGNP->REMARKS, CQCMRPTGNP_N->REMARKS, sizeof(CQCMRPTGNP->REMARKS));
    CQCMRPTGNP->USE_YN = CQCMRPTGNP_N->USE_YN[0];
    MEMCPY_DN(CQCMRPTGNP->CREATE_USER_ID, CQCMRPTGNP_N->CREATE_USER_ID, sizeof(CQCMRPTGNP->CREATE_USER_ID));
    MEMCPY_DN(CQCMRPTGNP->CREATE_TIME, CQCMRPTGNP_N->CREATE_TIME, sizeof(CQCMRPTGNP->CREATE_TIME));
    MEMCPY_DN(CQCMRPTGNP->UPDATE_USER_ID, CQCMRPTGNP_N->UPDATE_USER_ID, sizeof(CQCMRPTGNP->UPDATE_USER_ID));
    MEMCPY_DN(CQCMRPTGNP->UPDATE_TIME, CQCMRPTGNP_N->UPDATE_TIME, sizeof(CQCMRPTGNP->UPDATE_TIME));
    MEMCPY_DN(CQCMRPTGNP->CUST_NO, CQCMRPTGNP_N->CUST_NO, sizeof(CQCMRPTGNP->CUST_NO));
    MEMCPY_DN(CQCMRPTGNP->IMAGE_NUM, CQCMRPTGNP_N->IMAGE_NUM, sizeof(CQCMRPTGNP->IMAGE_NUM));
    MEMCPY_DN(CQCMRPTGNP->IMAGE_NUM2, CQCMRPTGNP_N->IMAGE_NUM2, sizeof(CQCMRPTGNP->IMAGE_NUM2));
    MEMCPY_DN(CQCMRPTGNP->IMAGE_NUM3, CQCMRPTGNP_N->IMAGE_NUM3, sizeof(CQCMRPTGNP->IMAGE_NUM3));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_1, CQCMRPTGNP_N->RPT_CMF_1, sizeof(CQCMRPTGNP->RPT_CMF_1));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_2, CQCMRPTGNP_N->RPT_CMF_2, sizeof(CQCMRPTGNP->RPT_CMF_2));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_3, CQCMRPTGNP_N->RPT_CMF_3, sizeof(CQCMRPTGNP->RPT_CMF_3));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_4, CQCMRPTGNP_N->RPT_CMF_4, sizeof(CQCMRPTGNP->RPT_CMF_4));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_5, CQCMRPTGNP_N->RPT_CMF_5, sizeof(CQCMRPTGNP->RPT_CMF_5));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_6, CQCMRPTGNP_N->RPT_CMF_6, sizeof(CQCMRPTGNP->RPT_CMF_6));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_7, CQCMRPTGNP_N->RPT_CMF_7, sizeof(CQCMRPTGNP->RPT_CMF_7));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_8, CQCMRPTGNP_N->RPT_CMF_8, sizeof(CQCMRPTGNP->RPT_CMF_8));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_9, CQCMRPTGNP_N->RPT_CMF_9, sizeof(CQCMRPTGNP->RPT_CMF_9));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_10, CQCMRPTGNP_N->RPT_CMF_10, sizeof(CQCMRPTGNP->RPT_CMF_10));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_11, CQCMRPTGNP_N->RPT_CMF_11, sizeof(CQCMRPTGNP->RPT_CMF_11));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_12, CQCMRPTGNP_N->RPT_CMF_12, sizeof(CQCMRPTGNP->RPT_CMF_12));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_13, CQCMRPTGNP_N->RPT_CMF_13, sizeof(CQCMRPTGNP->RPT_CMF_13));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_14, CQCMRPTGNP_N->RPT_CMF_14, sizeof(CQCMRPTGNP->RPT_CMF_14));
    MEMCPY_DN(CQCMRPTGNP->RPT_CMF_15, CQCMRPTGNP_N->RPT_CMF_15, sizeof(CQCMRPTGNP->RPT_CMF_15));
}


