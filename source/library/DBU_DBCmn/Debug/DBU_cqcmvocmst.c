
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
    "DBU_cqcmvocmst.pc"
};


static unsigned int sqlctx = 9379659;


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
            void  *sqhstv[53];
   unsigned int   sqhstl[53];
            int   sqhsts[53];
            void  *sqindv[53];
            int   sqinds[53];
   unsigned int   sqharm[53];
   unsigned int   *sqharc[53];
   unsigned short  sqadto[53];
   unsigned short  sqtdso[53];
} sqlstm = {13,53};

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
"select FACTORY ,REPORT_NO ,CUST_NO ,CUST_NAME ,CREATE_DATE ,RECEIVED_DATE_1\
 ,RECEIVED_DATE_2 ,RECEIVED_DATE_3 ,CLOSURE_DATE ,SAL_GROUP ,SAL_USER ,VOC_ST\
ATUS ,COST_QTY_01 ,COST_QTY_02 ,COST_QTY_03 ,COST_MONTH ,FILE_NO_01 ,FILE_PAT\
H_01 ,FILE_NO_02 ,FILE_PATH_02 ,FILE_NO_03 ,FILE_PATH_03 ,FILE_NO_04 ,FILE_PA\
TH_04 ,FILE_NO_05 ,FILE_PATH_05 ,COMMENT_01 ,COMMENT_02 ,COMMENT_03 ,COMMENT_\
04 ,COMMENT_05 ,COMMENT_06 ,COMMENT_07 ,COMMENT_08 ,COMMENT_09 ,COMMENT_10 ,C\
MF_01 ,CMF_02 ,CMF_03 ,CMF_04 ,CMF_05 ,CMF_06 ,CMF_07 ,CMF_08 ,CMF_09 ,CMF_10\
 ,USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from CQCM\
VOCMST  order by FACTORY asc ,REPORT_NO asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,908,0,4,46,0,0,53,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
232,0,0,2,920,0,4,189,0,0,53,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
459,0,0,3,80,0,4,335,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
486,0,0,4,62,0,2,372,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
509,0,0,5,825,0,3,402,0,0,51,51,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,
728,0,0,6,826,0,5,529,0,0,51,51,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,
947,0,0,7,670,0,9,667,0,0,0,0,0,1,0,
962,0,0,7,0,0,13,696,0,0,51,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,
1181,0,0,7,0,0,15,777,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cqcmvocmst.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2024-12-27 10:22:04
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2024 MIRACOM,INC.
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
void DBU_add_null_cqcmvocmst(struct CQCMVOCMST_N_TAG *CQCMVOCMST_N, struct CQCMVOCMST_TAG *CQCMVOCMST);
void DBU_del_null_cqcmvocmst(struct CQCMVOCMST_N_TAG *CQCMVOCMST_N, struct CQCMVOCMST_TAG *CQCMVOCMST);


/* SQL SELECT Function */
void DBU_select_cqcmvocmst(int sel_type, struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMVOCMST_N_TAG CQCMVOCMST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmvocmst(&CQCMVOCMST_N, CQCMVOCMST);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    REPORT_NO,
                    CUST_NO,
                    CUST_NAME,
                    CREATE_DATE,
                    RECEIVED_DATE_1,
                    RECEIVED_DATE_2,
                    RECEIVED_DATE_3,
                    CLOSURE_DATE,
                    SAL_GROUP,
                    SAL_USER,
                    VOC_STATUS,
                    COST_QTY_01,
                    COST_QTY_02,
                    COST_QTY_03,
                    COST_MONTH,
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
                    :CQCMVOCMST_N.FACTORY,
                    :CQCMVOCMST_N.REPORT_NO,
                    :CQCMVOCMST_N.CUST_NO,
                    :CQCMVOCMST_N.CUST_NAME,
                    :CQCMVOCMST_N.CREATE_DATE,
                    :CQCMVOCMST_N.RECEIVED_DATE_1,
                    :CQCMVOCMST_N.RECEIVED_DATE_2,
                    :CQCMVOCMST_N.RECEIVED_DATE_3,
                    :CQCMVOCMST_N.CLOSURE_DATE,
                    :CQCMVOCMST_N.SAL_GROUP,
                    :CQCMVOCMST_N.SAL_USER,
                    :CQCMVOCMST_N.VOC_STATUS,
                    :CQCMVOCMST_N.COST_QTY_01,
                    :CQCMVOCMST_N.COST_QTY_02,
                    :CQCMVOCMST_N.COST_QTY_03,
                    :CQCMVOCMST_N.COST_MONTH,
                    :CQCMVOCMST_N.FILE_NO_01,
                    :CQCMVOCMST_N.FILE_PATH_01,
                    :CQCMVOCMST_N.FILE_NO_02,
                    :CQCMVOCMST_N.FILE_PATH_02,
                    :CQCMVOCMST_N.FILE_NO_03,
                    :CQCMVOCMST_N.FILE_PATH_03,
                    :CQCMVOCMST_N.FILE_NO_04,
                    :CQCMVOCMST_N.FILE_PATH_04,
                    :CQCMVOCMST_N.FILE_NO_05,
                    :CQCMVOCMST_N.FILE_PATH_05,
                    :CQCMVOCMST_N.COMMENT_01,
                    :CQCMVOCMST_N.COMMENT_02,
                    :CQCMVOCMST_N.COMMENT_03,
                    :CQCMVOCMST_N.COMMENT_04,
                    :CQCMVOCMST_N.COMMENT_05,
                    :CQCMVOCMST_N.COMMENT_06,
                    :CQCMVOCMST_N.COMMENT_07,
                    :CQCMVOCMST_N.COMMENT_08,
                    :CQCMVOCMST_N.COMMENT_09,
                    :CQCMVOCMST_N.COMMENT_10,
                    :CQCMVOCMST_N.CMF_01,
                    :CQCMVOCMST_N.CMF_02,
                    :CQCMVOCMST_N.CMF_03,
                    :CQCMVOCMST_N.CMF_04,
                    :CQCMVOCMST_N.CMF_05,
                    :CQCMVOCMST_N.CMF_06,
                    :CQCMVOCMST_N.CMF_07,
                    :CQCMVOCMST_N.CMF_08,
                    :CQCMVOCMST_N.CMF_09,
                    :CQCMVOCMST_N.CMF_10,
                    :CQCMVOCMST_N.USE_YN,
                    :CQCMVOCMST_N.CREATE_USER_ID,
                    :CQCMVOCMST_N.CREATE_TIME,
                    :CQCMVOCMST_N.UPDATE_USER_ID,
                    :CQCMVOCMST_N.UPDATE_TIME
                FROM CQCMVOCMST
                WHERE FACTORY = :CQCMVOCMST_N.FACTORY
                    AND REPORT_NO = :CQCMVOCMST_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 53;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,REPORT_NO ,CUST_NO ,CUST_NAME ,C\
REATE_DATE ,RECEIVED_DATE_1 ,RECEIVED_DATE_2 ,RECEIVED_DATE_3 ,CLOSURE_DATE ,\
SAL_GROUP ,SAL_USER ,VOC_STATUS ,COST_QTY_01 ,COST_QTY_02 ,COST_QTY_03 ,COST_\
MONTH ,FILE_NO_01 ,FILE_PATH_01 ,FILE_NO_02 ,FILE_PATH_02 ,FILE_NO_03 ,FILE_P\
ATH_03 ,FILE_NO_04 ,FILE_PATH_04 ,FILE_NO_05 ,FILE_PATH_05 ,COMMENT_01 ,COMME\
NT_02 ,COMMENT_03 ,COMMENT_04 ,COMMENT_05 ,COMMENT_06 ,COMMENT_07 ,COMMENT_08\
 ,COMMENT_09 ,COMMENT_10 ,CMF_01 ,CMF_02 ,CMF_03 ,CMF_04 ,CMF_05 ,CMF_06 ,CMF\
_07 ,CMF_08 ,CMF_09 ,CMF_10 ,USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER\
_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,\
:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b\
28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43\
,:b44,:b45,:b46,:b47,:b48,:b49,:b50  from CQCMVOCMST where (FACTORY=:b0 and R\
EPORT_NO=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMVOCMST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMVOCMST_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMVOCMST_N.CUST_NO);
            sqlstm.sqhstl[2] = (unsigned int  )101;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMVOCMST_N.CUST_NAME);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMVOCMST_N.CREATE_DATE);
            sqlstm.sqhstl[4] = (unsigned int  )9;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_1);
            sqlstm.sqhstl[5] = (unsigned int  )9;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_2);
            sqlstm.sqhstl[6] = (unsigned int  )9;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_3);
            sqlstm.sqhstl[7] = (unsigned int  )9;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMVOCMST_N.CLOSURE_DATE);
            sqlstm.sqhstl[8] = (unsigned int  )9;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMVOCMST_N.SAL_GROUP);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMVOCMST_N.SAL_USER);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMVOCMST_N.VOC_STATUS);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CQCMVOCMST_N.COST_QTY_01);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(CQCMVOCMST_N.COST_QTY_02);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CQCMVOCMST_N.COST_QTY_03);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(CQCMVOCMST_N.COST_MONTH);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMVOCMST_N.FILE_NO_01);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMVOCMST_N.FILE_PATH_01);
            sqlstm.sqhstl[17] = (unsigned int  )301;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMVOCMST_N.FILE_NO_02);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMVOCMST_N.FILE_PATH_02);
            sqlstm.sqhstl[19] = (unsigned int  )301;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMVOCMST_N.FILE_NO_03);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMVOCMST_N.FILE_PATH_03);
            sqlstm.sqhstl[21] = (unsigned int  )301;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMVOCMST_N.FILE_NO_04);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMVOCMST_N.FILE_PATH_04);
            sqlstm.sqhstl[23] = (unsigned int  )301;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMVOCMST_N.FILE_NO_05);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMVOCMST_N.FILE_PATH_05);
            sqlstm.sqhstl[25] = (unsigned int  )301;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMVOCMST_N.COMMENT_01);
            sqlstm.sqhstl[26] = (unsigned int  )1001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMVOCMST_N.COMMENT_02);
            sqlstm.sqhstl[27] = (unsigned int  )1001;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMVOCMST_N.COMMENT_03);
            sqlstm.sqhstl[28] = (unsigned int  )1001;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMVOCMST_N.COMMENT_04);
            sqlstm.sqhstl[29] = (unsigned int  )1001;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMVOCMST_N.COMMENT_05);
            sqlstm.sqhstl[30] = (unsigned int  )1001;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMVOCMST_N.COMMENT_06);
            sqlstm.sqhstl[31] = (unsigned int  )1001;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMVOCMST_N.COMMENT_07);
            sqlstm.sqhstl[32] = (unsigned int  )1001;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMVOCMST_N.COMMENT_08);
            sqlstm.sqhstl[33] = (unsigned int  )1001;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMVOCMST_N.COMMENT_09);
            sqlstm.sqhstl[34] = (unsigned int  )1001;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMVOCMST_N.COMMENT_10);
            sqlstm.sqhstl[35] = (unsigned int  )1001;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMVOCMST_N.CMF_01);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMVOCMST_N.CMF_02);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMVOCMST_N.CMF_03);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMVOCMST_N.CMF_04);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMVOCMST_N.CMF_05);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMVOCMST_N.CMF_06);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMVOCMST_N.CMF_07);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMVOCMST_N.CMF_08);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMVOCMST_N.CMF_09);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMVOCMST_N.CMF_10);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMVOCMST_N.USE_YN);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMVOCMST_N.CREATE_USER_ID);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMVOCMST_N.CREATE_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMVOCMST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMVOCMST_N.UPDATE_TIME);
            sqlstm.sqhstl[50] = (unsigned int  )15;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMVOCMST_N.FACTORY);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMVOCMST_N.REPORT_NO);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
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
        DBU_del_null_cqcmvocmst(&CQCMVOCMST_N, CQCMVOCMST);
    }

    DB_stop_query_timer("DBU_select_cqcmvocmst", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cqcmvocmst_for_update(int sel_type, struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMVOCMST_N_TAG CQCMVOCMST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmvocmst(&CQCMVOCMST_N, CQCMVOCMST);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    REPORT_NO,
                    CUST_NO,
                    CUST_NAME,
                    CREATE_DATE,
                    RECEIVED_DATE_1,
                    RECEIVED_DATE_2,
                    RECEIVED_DATE_3,
                    CLOSURE_DATE,
                    SAL_GROUP,
                    SAL_USER,
                    VOC_STATUS,
                    COST_QTY_01,
                    COST_QTY_02,
                    COST_QTY_03,
                    COST_MONTH,
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
                    :CQCMVOCMST_N.FACTORY,
                    :CQCMVOCMST_N.REPORT_NO,
                    :CQCMVOCMST_N.CUST_NO,
                    :CQCMVOCMST_N.CUST_NAME,
                    :CQCMVOCMST_N.CREATE_DATE,
                    :CQCMVOCMST_N.RECEIVED_DATE_1,
                    :CQCMVOCMST_N.RECEIVED_DATE_2,
                    :CQCMVOCMST_N.RECEIVED_DATE_3,
                    :CQCMVOCMST_N.CLOSURE_DATE,
                    :CQCMVOCMST_N.SAL_GROUP,
                    :CQCMVOCMST_N.SAL_USER,
                    :CQCMVOCMST_N.VOC_STATUS,
                    :CQCMVOCMST_N.COST_QTY_01,
                    :CQCMVOCMST_N.COST_QTY_02,
                    :CQCMVOCMST_N.COST_QTY_03,
                    :CQCMVOCMST_N.COST_MONTH,
                    :CQCMVOCMST_N.FILE_NO_01,
                    :CQCMVOCMST_N.FILE_PATH_01,
                    :CQCMVOCMST_N.FILE_NO_02,
                    :CQCMVOCMST_N.FILE_PATH_02,
                    :CQCMVOCMST_N.FILE_NO_03,
                    :CQCMVOCMST_N.FILE_PATH_03,
                    :CQCMVOCMST_N.FILE_NO_04,
                    :CQCMVOCMST_N.FILE_PATH_04,
                    :CQCMVOCMST_N.FILE_NO_05,
                    :CQCMVOCMST_N.FILE_PATH_05,
                    :CQCMVOCMST_N.COMMENT_01,
                    :CQCMVOCMST_N.COMMENT_02,
                    :CQCMVOCMST_N.COMMENT_03,
                    :CQCMVOCMST_N.COMMENT_04,
                    :CQCMVOCMST_N.COMMENT_05,
                    :CQCMVOCMST_N.COMMENT_06,
                    :CQCMVOCMST_N.COMMENT_07,
                    :CQCMVOCMST_N.COMMENT_08,
                    :CQCMVOCMST_N.COMMENT_09,
                    :CQCMVOCMST_N.COMMENT_10,
                    :CQCMVOCMST_N.CMF_01,
                    :CQCMVOCMST_N.CMF_02,
                    :CQCMVOCMST_N.CMF_03,
                    :CQCMVOCMST_N.CMF_04,
                    :CQCMVOCMST_N.CMF_05,
                    :CQCMVOCMST_N.CMF_06,
                    :CQCMVOCMST_N.CMF_07,
                    :CQCMVOCMST_N.CMF_08,
                    :CQCMVOCMST_N.CMF_09,
                    :CQCMVOCMST_N.CMF_10,
                    :CQCMVOCMST_N.USE_YN,
                    :CQCMVOCMST_N.CREATE_USER_ID,
                    :CQCMVOCMST_N.CREATE_TIME,
                    :CQCMVOCMST_N.UPDATE_USER_ID,
                    :CQCMVOCMST_N.UPDATE_TIME
                FROM CQCMVOCMST
                WHERE FACTORY = :CQCMVOCMST_N.FACTORY
                    AND REPORT_NO = :CQCMVOCMST_N.REPORT_NO
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 53;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,REPORT_NO ,CUST_NO ,CUST_NAME ,C\
REATE_DATE ,RECEIVED_DATE_1 ,RECEIVED_DATE_2 ,RECEIVED_DATE_3 ,CLOSURE_DATE ,\
SAL_GROUP ,SAL_USER ,VOC_STATUS ,COST_QTY_01 ,COST_QTY_02 ,COST_QTY_03 ,COST_\
MONTH ,FILE_NO_01 ,FILE_PATH_01 ,FILE_NO_02 ,FILE_PATH_02 ,FILE_NO_03 ,FILE_P\
ATH_03 ,FILE_NO_04 ,FILE_PATH_04 ,FILE_NO_05 ,FILE_PATH_05 ,COMMENT_01 ,COMME\
NT_02 ,COMMENT_03 ,COMMENT_04 ,COMMENT_05 ,COMMENT_06 ,COMMENT_07 ,COMMENT_08\
 ,COMMENT_09 ,COMMENT_10 ,CMF_01 ,CMF_02 ,CMF_03 ,CMF_04 ,CMF_05 ,CMF_06 ,CMF\
_07 ,CMF_08 ,CMF_09 ,CMF_10 ,USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER\
_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,\
:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b\
28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43\
,:b44,:b45,:b46,:b47,:b48,:b49,:b50  from CQCMVOCMST where (FACTORY=:b0 and R\
EPORT_NO=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )232;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMVOCMST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMVOCMST_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMVOCMST_N.CUST_NO);
            sqlstm.sqhstl[2] = (unsigned int  )101;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMVOCMST_N.CUST_NAME);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMVOCMST_N.CREATE_DATE);
            sqlstm.sqhstl[4] = (unsigned int  )9;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_1);
            sqlstm.sqhstl[5] = (unsigned int  )9;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_2);
            sqlstm.sqhstl[6] = (unsigned int  )9;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_3);
            sqlstm.sqhstl[7] = (unsigned int  )9;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMVOCMST_N.CLOSURE_DATE);
            sqlstm.sqhstl[8] = (unsigned int  )9;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMVOCMST_N.SAL_GROUP);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMVOCMST_N.SAL_USER);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMVOCMST_N.VOC_STATUS);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CQCMVOCMST_N.COST_QTY_01);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(CQCMVOCMST_N.COST_QTY_02);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CQCMVOCMST_N.COST_QTY_03);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(CQCMVOCMST_N.COST_MONTH);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMVOCMST_N.FILE_NO_01);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMVOCMST_N.FILE_PATH_01);
            sqlstm.sqhstl[17] = (unsigned int  )301;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMVOCMST_N.FILE_NO_02);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMVOCMST_N.FILE_PATH_02);
            sqlstm.sqhstl[19] = (unsigned int  )301;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMVOCMST_N.FILE_NO_03);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMVOCMST_N.FILE_PATH_03);
            sqlstm.sqhstl[21] = (unsigned int  )301;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMVOCMST_N.FILE_NO_04);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMVOCMST_N.FILE_PATH_04);
            sqlstm.sqhstl[23] = (unsigned int  )301;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMVOCMST_N.FILE_NO_05);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMVOCMST_N.FILE_PATH_05);
            sqlstm.sqhstl[25] = (unsigned int  )301;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMVOCMST_N.COMMENT_01);
            sqlstm.sqhstl[26] = (unsigned int  )1001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMVOCMST_N.COMMENT_02);
            sqlstm.sqhstl[27] = (unsigned int  )1001;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMVOCMST_N.COMMENT_03);
            sqlstm.sqhstl[28] = (unsigned int  )1001;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMVOCMST_N.COMMENT_04);
            sqlstm.sqhstl[29] = (unsigned int  )1001;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMVOCMST_N.COMMENT_05);
            sqlstm.sqhstl[30] = (unsigned int  )1001;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMVOCMST_N.COMMENT_06);
            sqlstm.sqhstl[31] = (unsigned int  )1001;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMVOCMST_N.COMMENT_07);
            sqlstm.sqhstl[32] = (unsigned int  )1001;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMVOCMST_N.COMMENT_08);
            sqlstm.sqhstl[33] = (unsigned int  )1001;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMVOCMST_N.COMMENT_09);
            sqlstm.sqhstl[34] = (unsigned int  )1001;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMVOCMST_N.COMMENT_10);
            sqlstm.sqhstl[35] = (unsigned int  )1001;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMVOCMST_N.CMF_01);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMVOCMST_N.CMF_02);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMVOCMST_N.CMF_03);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMVOCMST_N.CMF_04);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMVOCMST_N.CMF_05);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMVOCMST_N.CMF_06);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMVOCMST_N.CMF_07);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMVOCMST_N.CMF_08);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMVOCMST_N.CMF_09);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMVOCMST_N.CMF_10);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMVOCMST_N.USE_YN);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMVOCMST_N.CREATE_USER_ID);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMVOCMST_N.CREATE_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMVOCMST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMVOCMST_N.UPDATE_TIME);
            sqlstm.sqhstl[50] = (unsigned int  )15;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMVOCMST_N.FACTORY);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMVOCMST_N.REPORT_NO);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
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
        DBU_del_null_cqcmvocmst(&CQCMVOCMST_N, CQCMVOCMST);
    }

    DB_stop_query_timer("DBU_select_cqcmvocmst_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cqcmvocmst_scalar(int sel_type, struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMVOCMST_N_TAG CQCMVOCMST_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmvocmst(&CQCMVOCMST_N, CQCMVOCMST);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMVOCMST
                WHERE FACTORY = :CQCMVOCMST_N.FACTORY
                    AND REPORT_NO = :CQCMVOCMST_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 53;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMVOCMST where\
 (FACTORY=:b1 and REPORT_NO=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )459;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMVOCMST_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMVOCMST_N.REPORT_NO);
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

    DB_stop_query_timer("DBU_select_cqcmvocmst_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cqcmvocmst(int sel_type, struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMVOCMST_N_TAG CQCMVOCMST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmvocmst(&CQCMVOCMST_N, CQCMVOCMST);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CQCMVOCMST
                WHERE FACTORY = :CQCMVOCMST_N.FACTORY
                    AND REPORT_NO = :CQCMVOCMST_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 53;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMVOCMST  where (FACTORY=:b0 and \
REPORT_NO=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )486;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMVOCMST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMVOCMST_N.REPORT_NO);
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

    DB_stop_query_timer("DBU_delete_cqcmvocmst", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cqcmvocmst(struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMVOCMST_N_TAG CQCMVOCMST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmvocmst(&CQCMVOCMST_N, CQCMVOCMST);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CQCMVOCMST( 
                    FACTORY, 
                    REPORT_NO, 
                    CUST_NO, 
                    CUST_NAME, 
                    CREATE_DATE, 
                    RECEIVED_DATE_1, 
                    RECEIVED_DATE_2, 
                    RECEIVED_DATE_3, 
                    CLOSURE_DATE, 
                    SAL_GROUP, 
                    SAL_USER, 
                    VOC_STATUS, 
                    COST_QTY_01, 
                    COST_QTY_02, 
                    COST_QTY_03, 
                    COST_MONTH, 
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
                    :CQCMVOCMST_N.FACTORY,
                    :CQCMVOCMST_N.REPORT_NO,
                    :CQCMVOCMST_N.CUST_NO,
                    :CQCMVOCMST_N.CUST_NAME,
                    :CQCMVOCMST_N.CREATE_DATE,
                    :CQCMVOCMST_N.RECEIVED_DATE_1,
                    :CQCMVOCMST_N.RECEIVED_DATE_2,
                    :CQCMVOCMST_N.RECEIVED_DATE_3,
                    :CQCMVOCMST_N.CLOSURE_DATE,
                    :CQCMVOCMST_N.SAL_GROUP,
                    :CQCMVOCMST_N.SAL_USER,
                    :CQCMVOCMST_N.VOC_STATUS,
                    :CQCMVOCMST_N.COST_QTY_01,
                    :CQCMVOCMST_N.COST_QTY_02,
                    :CQCMVOCMST_N.COST_QTY_03,
                    :CQCMVOCMST_N.COST_MONTH,
                    :CQCMVOCMST_N.FILE_NO_01,
                    :CQCMVOCMST_N.FILE_PATH_01,
                    :CQCMVOCMST_N.FILE_NO_02,
                    :CQCMVOCMST_N.FILE_PATH_02,
                    :CQCMVOCMST_N.FILE_NO_03,
                    :CQCMVOCMST_N.FILE_PATH_03,
                    :CQCMVOCMST_N.FILE_NO_04,
                    :CQCMVOCMST_N.FILE_PATH_04,
                    :CQCMVOCMST_N.FILE_NO_05,
                    :CQCMVOCMST_N.FILE_PATH_05,
                    :CQCMVOCMST_N.COMMENT_01,
                    :CQCMVOCMST_N.COMMENT_02,
                    :CQCMVOCMST_N.COMMENT_03,
                    :CQCMVOCMST_N.COMMENT_04,
                    :CQCMVOCMST_N.COMMENT_05,
                    :CQCMVOCMST_N.COMMENT_06,
                    :CQCMVOCMST_N.COMMENT_07,
                    :CQCMVOCMST_N.COMMENT_08,
                    :CQCMVOCMST_N.COMMENT_09,
                    :CQCMVOCMST_N.COMMENT_10,
                    :CQCMVOCMST_N.CMF_01,
                    :CQCMVOCMST_N.CMF_02,
                    :CQCMVOCMST_N.CMF_03,
                    :CQCMVOCMST_N.CMF_04,
                    :CQCMVOCMST_N.CMF_05,
                    :CQCMVOCMST_N.CMF_06,
                    :CQCMVOCMST_N.CMF_07,
                    :CQCMVOCMST_N.CMF_08,
                    :CQCMVOCMST_N.CMF_09,
                    :CQCMVOCMST_N.CMF_10,
                    :CQCMVOCMST_N.USE_YN,
                    :CQCMVOCMST_N.CREATE_USER_ID,
                    :CQCMVOCMST_N.CREATE_TIME,
                    :CQCMVOCMST_N.UPDATE_USER_ID,
                    :CQCMVOCMST_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 53;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into CQCMVOCMST (FACTORY,REPORT_NO,CUST_NO,CUST_N\
AME,CREATE_DATE,RECEIVED_DATE_1,RECEIVED_DATE_2,RECEIVED_DATE_3,CLOSURE_DATE,\
SAL_GROUP,SAL_USER,VOC_STATUS,COST_QTY_01,COST_QTY_02,COST_QTY_03,COST_MONTH,\
FILE_NO_01,FILE_PATH_01,FILE_NO_02,FILE_PATH_02,FILE_NO_03,FILE_PATH_03,FILE_\
NO_04,FILE_PATH_04,FILE_NO_05,FILE_PATH_05,COMMENT_01,COMMENT_02,COMMENT_03,C\
OMMENT_04,COMMENT_05,COMMENT_06,COMMENT_07,COMMENT_08,COMMENT_09,COMMENT_10,C\
MF_01,CMF_02,CMF_03,CMF_04,CMF_05,CMF_06,CMF_07,CMF_08,CMF_09,CMF_10,USE_YN,C\
REATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) values (:b0,:b1,:b2,:b3\
,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b\
20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35\
,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )509;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CQCMVOCMST_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CQCMVOCMST_N.REPORT_NO);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CQCMVOCMST_N.CUST_NO);
    sqlstm.sqhstl[2] = (unsigned int  )101;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(CQCMVOCMST_N.CUST_NAME);
    sqlstm.sqhstl[3] = (unsigned int  )101;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CQCMVOCMST_N.CREATE_DATE);
    sqlstm.sqhstl[4] = (unsigned int  )9;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_1);
    sqlstm.sqhstl[5] = (unsigned int  )9;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_2);
    sqlstm.sqhstl[6] = (unsigned int  )9;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_3);
    sqlstm.sqhstl[7] = (unsigned int  )9;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CQCMVOCMST_N.CLOSURE_DATE);
    sqlstm.sqhstl[8] = (unsigned int  )9;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CQCMVOCMST_N.SAL_GROUP);
    sqlstm.sqhstl[9] = (unsigned int  )21;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(CQCMVOCMST_N.SAL_USER);
    sqlstm.sqhstl[10] = (unsigned int  )201;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(CQCMVOCMST_N.VOC_STATUS);
    sqlstm.sqhstl[11] = (unsigned int  )2;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)&(CQCMVOCMST_N.COST_QTY_01);
    sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)&(CQCMVOCMST_N.COST_QTY_02);
    sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)&(CQCMVOCMST_N.COST_QTY_03);
    sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)&(CQCMVOCMST_N.COST_MONTH);
    sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CQCMVOCMST_N.FILE_NO_01);
    sqlstm.sqhstl[16] = (unsigned int  )21;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CQCMVOCMST_N.FILE_PATH_01);
    sqlstm.sqhstl[17] = (unsigned int  )301;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CQCMVOCMST_N.FILE_NO_02);
    sqlstm.sqhstl[18] = (unsigned int  )21;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(CQCMVOCMST_N.FILE_PATH_02);
    sqlstm.sqhstl[19] = (unsigned int  )301;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CQCMVOCMST_N.FILE_NO_03);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CQCMVOCMST_N.FILE_PATH_03);
    sqlstm.sqhstl[21] = (unsigned int  )301;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(CQCMVOCMST_N.FILE_NO_04);
    sqlstm.sqhstl[22] = (unsigned int  )21;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(CQCMVOCMST_N.FILE_PATH_04);
    sqlstm.sqhstl[23] = (unsigned int  )301;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CQCMVOCMST_N.FILE_NO_05);
    sqlstm.sqhstl[24] = (unsigned int  )21;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(CQCMVOCMST_N.FILE_PATH_05);
    sqlstm.sqhstl[25] = (unsigned int  )301;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(CQCMVOCMST_N.COMMENT_01);
    sqlstm.sqhstl[26] = (unsigned int  )1001;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(CQCMVOCMST_N.COMMENT_02);
    sqlstm.sqhstl[27] = (unsigned int  )1001;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(CQCMVOCMST_N.COMMENT_03);
    sqlstm.sqhstl[28] = (unsigned int  )1001;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(CQCMVOCMST_N.COMMENT_04);
    sqlstm.sqhstl[29] = (unsigned int  )1001;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(CQCMVOCMST_N.COMMENT_05);
    sqlstm.sqhstl[30] = (unsigned int  )1001;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(CQCMVOCMST_N.COMMENT_06);
    sqlstm.sqhstl[31] = (unsigned int  )1001;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(CQCMVOCMST_N.COMMENT_07);
    sqlstm.sqhstl[32] = (unsigned int  )1001;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(CQCMVOCMST_N.COMMENT_08);
    sqlstm.sqhstl[33] = (unsigned int  )1001;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(CQCMVOCMST_N.COMMENT_09);
    sqlstm.sqhstl[34] = (unsigned int  )1001;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(CQCMVOCMST_N.COMMENT_10);
    sqlstm.sqhstl[35] = (unsigned int  )1001;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(CQCMVOCMST_N.CMF_01);
    sqlstm.sqhstl[36] = (unsigned int  )51;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(CQCMVOCMST_N.CMF_02);
    sqlstm.sqhstl[37] = (unsigned int  )51;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(CQCMVOCMST_N.CMF_03);
    sqlstm.sqhstl[38] = (unsigned int  )51;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(CQCMVOCMST_N.CMF_04);
    sqlstm.sqhstl[39] = (unsigned int  )51;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(CQCMVOCMST_N.CMF_05);
    sqlstm.sqhstl[40] = (unsigned int  )51;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(CQCMVOCMST_N.CMF_06);
    sqlstm.sqhstl[41] = (unsigned int  )51;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(CQCMVOCMST_N.CMF_07);
    sqlstm.sqhstl[42] = (unsigned int  )51;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(CQCMVOCMST_N.CMF_08);
    sqlstm.sqhstl[43] = (unsigned int  )51;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(CQCMVOCMST_N.CMF_09);
    sqlstm.sqhstl[44] = (unsigned int  )51;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(CQCMVOCMST_N.CMF_10);
    sqlstm.sqhstl[45] = (unsigned int  )51;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(CQCMVOCMST_N.USE_YN);
    sqlstm.sqhstl[46] = (unsigned int  )2;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(CQCMVOCMST_N.CREATE_USER_ID);
    sqlstm.sqhstl[47] = (unsigned int  )21;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(CQCMVOCMST_N.CREATE_TIME);
    sqlstm.sqhstl[48] = (unsigned int  )15;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(CQCMVOCMST_N.UPDATE_USER_ID);
    sqlstm.sqhstl[49] = (unsigned int  )21;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(CQCMVOCMST_N.UPDATE_TIME);
    sqlstm.sqhstl[50] = (unsigned int  )15;
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



    DB_stop_query_timer("DBU_insert_cqcmvocmst", 0);
}


/* SQL UPDATE Function */
void DBU_update_cqcmvocmst(int sel_type, struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMVOCMST_N_TAG CQCMVOCMST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmvocmst(&CQCMVOCMST_N, CQCMVOCMST);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CQCMVOCMST SET
                    CUST_NO = :CQCMVOCMST_N.CUST_NO,
                    CUST_NAME = :CQCMVOCMST_N.CUST_NAME,
                    CREATE_DATE = :CQCMVOCMST_N.CREATE_DATE,
                    RECEIVED_DATE_1 = :CQCMVOCMST_N.RECEIVED_DATE_1,
                    RECEIVED_DATE_2 = :CQCMVOCMST_N.RECEIVED_DATE_2,
                    RECEIVED_DATE_3 = :CQCMVOCMST_N.RECEIVED_DATE_3,
                    CLOSURE_DATE = :CQCMVOCMST_N.CLOSURE_DATE,
                    SAL_GROUP = :CQCMVOCMST_N.SAL_GROUP,
                    SAL_USER = :CQCMVOCMST_N.SAL_USER,
                    VOC_STATUS = :CQCMVOCMST_N.VOC_STATUS,
                    COST_QTY_01 = :CQCMVOCMST_N.COST_QTY_01,
                    COST_QTY_02 = :CQCMVOCMST_N.COST_QTY_02,
                    COST_QTY_03 = :CQCMVOCMST_N.COST_QTY_03,
                    COST_MONTH = :CQCMVOCMST_N.COST_MONTH,
                    FILE_NO_01 = :CQCMVOCMST_N.FILE_NO_01,
                    FILE_PATH_01 = :CQCMVOCMST_N.FILE_PATH_01,
                    FILE_NO_02 = :CQCMVOCMST_N.FILE_NO_02,
                    FILE_PATH_02 = :CQCMVOCMST_N.FILE_PATH_02,
                    FILE_NO_03 = :CQCMVOCMST_N.FILE_NO_03,
                    FILE_PATH_03 = :CQCMVOCMST_N.FILE_PATH_03,
                    FILE_NO_04 = :CQCMVOCMST_N.FILE_NO_04,
                    FILE_PATH_04 = :CQCMVOCMST_N.FILE_PATH_04,
                    FILE_NO_05 = :CQCMVOCMST_N.FILE_NO_05,
                    FILE_PATH_05 = :CQCMVOCMST_N.FILE_PATH_05,
                    COMMENT_01 = :CQCMVOCMST_N.COMMENT_01,
                    COMMENT_02 = :CQCMVOCMST_N.COMMENT_02,
                    COMMENT_03 = :CQCMVOCMST_N.COMMENT_03,
                    COMMENT_04 = :CQCMVOCMST_N.COMMENT_04,
                    COMMENT_05 = :CQCMVOCMST_N.COMMENT_05,
                    COMMENT_06 = :CQCMVOCMST_N.COMMENT_06,
                    COMMENT_07 = :CQCMVOCMST_N.COMMENT_07,
                    COMMENT_08 = :CQCMVOCMST_N.COMMENT_08,
                    COMMENT_09 = :CQCMVOCMST_N.COMMENT_09,
                    COMMENT_10 = :CQCMVOCMST_N.COMMENT_10,
                    CMF_01 = :CQCMVOCMST_N.CMF_01,
                    CMF_02 = :CQCMVOCMST_N.CMF_02,
                    CMF_03 = :CQCMVOCMST_N.CMF_03,
                    CMF_04 = :CQCMVOCMST_N.CMF_04,
                    CMF_05 = :CQCMVOCMST_N.CMF_05,
                    CMF_06 = :CQCMVOCMST_N.CMF_06,
                    CMF_07 = :CQCMVOCMST_N.CMF_07,
                    CMF_08 = :CQCMVOCMST_N.CMF_08,
                    CMF_09 = :CQCMVOCMST_N.CMF_09,
                    CMF_10 = :CQCMVOCMST_N.CMF_10,
                    USE_YN = :CQCMVOCMST_N.USE_YN,
                    CREATE_USER_ID = :CQCMVOCMST_N.CREATE_USER_ID,
                    CREATE_TIME = :CQCMVOCMST_N.CREATE_TIME,
                    UPDATE_USER_ID = :CQCMVOCMST_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CQCMVOCMST_N.UPDATE_TIME
                WHERE FACTORY = :CQCMVOCMST_N.FACTORY
                    AND REPORT_NO = :CQCMVOCMST_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 53;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CQCMVOCMST  set CUST_NO=:b0,CUST_NAME=:b1\
,CREATE_DATE=:b2,RECEIVED_DATE_1=:b3,RECEIVED_DATE_2=:b4,RECEIVED_DATE_3=:b5,\
CLOSURE_DATE=:b6,SAL_GROUP=:b7,SAL_USER=:b8,VOC_STATUS=:b9,COST_QTY_01=:b10,C\
OST_QTY_02=:b11,COST_QTY_03=:b12,COST_MONTH=:b13,FILE_NO_01=:b14,FILE_PATH_01\
=:b15,FILE_NO_02=:b16,FILE_PATH_02=:b17,FILE_NO_03=:b18,FILE_PATH_03=:b19,FIL\
E_NO_04=:b20,FILE_PATH_04=:b21,FILE_NO_05=:b22,FILE_PATH_05=:b23,COMMENT_01=:\
b24,COMMENT_02=:b25,COMMENT_03=:b26,COMMENT_04=:b27,COMMENT_05=:b28,COMMENT_0\
6=:b29,COMMENT_07=:b30,COMMENT_08=:b31,COMMENT_09=:b32,COMMENT_10=:b33,CMF_01\
=:b34,CMF_02=:b35,CMF_03=:b36,CMF_04=:b37,CMF_05=:b38,CMF_06=:b39,CMF_07=:b40\
,CMF_08=:b41,CMF_09=:b42,CMF_10=:b43,USE_YN=:b44,CREATE_USER_ID=:b45,CREATE_T\
IME=:b46,UPDATE_USER_ID=:b47,UPDATE_TIME=:b48 where (FACTORY=:b49 and REPORT_\
NO=:b50)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )728;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMVOCMST_N.CUST_NO);
            sqlstm.sqhstl[0] = (unsigned int  )101;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMVOCMST_N.CUST_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )101;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMVOCMST_N.CREATE_DATE);
            sqlstm.sqhstl[2] = (unsigned int  )9;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_1);
            sqlstm.sqhstl[3] = (unsigned int  )9;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_2);
            sqlstm.sqhstl[4] = (unsigned int  )9;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_3);
            sqlstm.sqhstl[5] = (unsigned int  )9;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMVOCMST_N.CLOSURE_DATE);
            sqlstm.sqhstl[6] = (unsigned int  )9;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMVOCMST_N.SAL_GROUP);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMVOCMST_N.SAL_USER);
            sqlstm.sqhstl[8] = (unsigned int  )201;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMVOCMST_N.VOC_STATUS);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CQCMVOCMST_N.COST_QTY_01);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMVOCMST_N.COST_QTY_02);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CQCMVOCMST_N.COST_QTY_03);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(CQCMVOCMST_N.COST_MONTH);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMVOCMST_N.FILE_NO_01);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMVOCMST_N.FILE_PATH_01);
            sqlstm.sqhstl[15] = (unsigned int  )301;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMVOCMST_N.FILE_NO_02);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMVOCMST_N.FILE_PATH_02);
            sqlstm.sqhstl[17] = (unsigned int  )301;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMVOCMST_N.FILE_NO_03);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMVOCMST_N.FILE_PATH_03);
            sqlstm.sqhstl[19] = (unsigned int  )301;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMVOCMST_N.FILE_NO_04);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMVOCMST_N.FILE_PATH_04);
            sqlstm.sqhstl[21] = (unsigned int  )301;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMVOCMST_N.FILE_NO_05);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMVOCMST_N.FILE_PATH_05);
            sqlstm.sqhstl[23] = (unsigned int  )301;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMVOCMST_N.COMMENT_01);
            sqlstm.sqhstl[24] = (unsigned int  )1001;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMVOCMST_N.COMMENT_02);
            sqlstm.sqhstl[25] = (unsigned int  )1001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMVOCMST_N.COMMENT_03);
            sqlstm.sqhstl[26] = (unsigned int  )1001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMVOCMST_N.COMMENT_04);
            sqlstm.sqhstl[27] = (unsigned int  )1001;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMVOCMST_N.COMMENT_05);
            sqlstm.sqhstl[28] = (unsigned int  )1001;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMVOCMST_N.COMMENT_06);
            sqlstm.sqhstl[29] = (unsigned int  )1001;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMVOCMST_N.COMMENT_07);
            sqlstm.sqhstl[30] = (unsigned int  )1001;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMVOCMST_N.COMMENT_08);
            sqlstm.sqhstl[31] = (unsigned int  )1001;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMVOCMST_N.COMMENT_09);
            sqlstm.sqhstl[32] = (unsigned int  )1001;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMVOCMST_N.COMMENT_10);
            sqlstm.sqhstl[33] = (unsigned int  )1001;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMVOCMST_N.CMF_01);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMVOCMST_N.CMF_02);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMVOCMST_N.CMF_03);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMVOCMST_N.CMF_04);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMVOCMST_N.CMF_05);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMVOCMST_N.CMF_06);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMVOCMST_N.CMF_07);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMVOCMST_N.CMF_08);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMVOCMST_N.CMF_09);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMVOCMST_N.CMF_10);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMVOCMST_N.USE_YN);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMVOCMST_N.CREATE_USER_ID);
            sqlstm.sqhstl[45] = (unsigned int  )21;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMVOCMST_N.CREATE_TIME);
            sqlstm.sqhstl[46] = (unsigned int  )15;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMVOCMST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMVOCMST_N.UPDATE_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMVOCMST_N.FACTORY);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMVOCMST_N.REPORT_NO);
            sqlstm.sqhstl[50] = (unsigned int  )21;
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

    DB_stop_query_timer("DBU_update_cqcmvocmst", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cqcmvocmst(int sel_type, struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMVOCMST_N_TAG CQCMVOCMST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmvocmst(&CQCMVOCMST_N, CQCMVOCMST);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CQCMVOCMST_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    REPORT_NO,
                    CUST_NO,
                    CUST_NAME,
                    CREATE_DATE,
                    RECEIVED_DATE_1,
                    RECEIVED_DATE_2,
                    RECEIVED_DATE_3,
                    CLOSURE_DATE,
                    SAL_GROUP,
                    SAL_USER,
                    VOC_STATUS,
                    COST_QTY_01,
                    COST_QTY_02,
                    COST_QTY_03,
                    COST_MONTH,
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
                FROM CQCMVOCMST
                ORDER BY FACTORY ASC,
                    REPORT_NO ASC; */ 

            /* EXEC SQL OPEN DBU_CQCMVOCMST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 53;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )947;
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

    DB_stop_query_timer("DBU_open_cqcmvocmst", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cqcmvocmst(int sel_type, struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMVOCMST_N_TAG CQCMVOCMST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CQCMVOCMST_CUR_1 INTO
                :CQCMVOCMST_N.FACTORY,
                :CQCMVOCMST_N.REPORT_NO,
                :CQCMVOCMST_N.CUST_NO,
                :CQCMVOCMST_N.CUST_NAME,
                :CQCMVOCMST_N.CREATE_DATE,
                :CQCMVOCMST_N.RECEIVED_DATE_1,
                :CQCMVOCMST_N.RECEIVED_DATE_2,
                :CQCMVOCMST_N.RECEIVED_DATE_3,
                :CQCMVOCMST_N.CLOSURE_DATE,
                :CQCMVOCMST_N.SAL_GROUP,
                :CQCMVOCMST_N.SAL_USER,
                :CQCMVOCMST_N.VOC_STATUS,
                :CQCMVOCMST_N.COST_QTY_01,
                :CQCMVOCMST_N.COST_QTY_02,
                :CQCMVOCMST_N.COST_QTY_03,
                :CQCMVOCMST_N.COST_MONTH,
                :CQCMVOCMST_N.FILE_NO_01,
                :CQCMVOCMST_N.FILE_PATH_01,
                :CQCMVOCMST_N.FILE_NO_02,
                :CQCMVOCMST_N.FILE_PATH_02,
                :CQCMVOCMST_N.FILE_NO_03,
                :CQCMVOCMST_N.FILE_PATH_03,
                :CQCMVOCMST_N.FILE_NO_04,
                :CQCMVOCMST_N.FILE_PATH_04,
                :CQCMVOCMST_N.FILE_NO_05,
                :CQCMVOCMST_N.FILE_PATH_05,
                :CQCMVOCMST_N.COMMENT_01,
                :CQCMVOCMST_N.COMMENT_02,
                :CQCMVOCMST_N.COMMENT_03,
                :CQCMVOCMST_N.COMMENT_04,
                :CQCMVOCMST_N.COMMENT_05,
                :CQCMVOCMST_N.COMMENT_06,
                :CQCMVOCMST_N.COMMENT_07,
                :CQCMVOCMST_N.COMMENT_08,
                :CQCMVOCMST_N.COMMENT_09,
                :CQCMVOCMST_N.COMMENT_10,
                :CQCMVOCMST_N.CMF_01,
                :CQCMVOCMST_N.CMF_02,
                :CQCMVOCMST_N.CMF_03,
                :CQCMVOCMST_N.CMF_04,
                :CQCMVOCMST_N.CMF_05,
                :CQCMVOCMST_N.CMF_06,
                :CQCMVOCMST_N.CMF_07,
                :CQCMVOCMST_N.CMF_08,
                :CQCMVOCMST_N.CMF_09,
                :CQCMVOCMST_N.CMF_10,
                :CQCMVOCMST_N.USE_YN,
                :CQCMVOCMST_N.CREATE_USER_ID,
                :CQCMVOCMST_N.CREATE_TIME,
                :CQCMVOCMST_N.UPDATE_USER_ID,
                :CQCMVOCMST_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 53;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )962;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMVOCMST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMVOCMST_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMVOCMST_N.CUST_NO);
            sqlstm.sqhstl[2] = (unsigned int  )101;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMVOCMST_N.CUST_NAME);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMVOCMST_N.CREATE_DATE);
            sqlstm.sqhstl[4] = (unsigned int  )9;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_1);
            sqlstm.sqhstl[5] = (unsigned int  )9;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_2);
            sqlstm.sqhstl[6] = (unsigned int  )9;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMVOCMST_N.RECEIVED_DATE_3);
            sqlstm.sqhstl[7] = (unsigned int  )9;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMVOCMST_N.CLOSURE_DATE);
            sqlstm.sqhstl[8] = (unsigned int  )9;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMVOCMST_N.SAL_GROUP);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMVOCMST_N.SAL_USER);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMVOCMST_N.VOC_STATUS);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CQCMVOCMST_N.COST_QTY_01);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(CQCMVOCMST_N.COST_QTY_02);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CQCMVOCMST_N.COST_QTY_03);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(CQCMVOCMST_N.COST_MONTH);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMVOCMST_N.FILE_NO_01);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMVOCMST_N.FILE_PATH_01);
            sqlstm.sqhstl[17] = (unsigned int  )301;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMVOCMST_N.FILE_NO_02);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMVOCMST_N.FILE_PATH_02);
            sqlstm.sqhstl[19] = (unsigned int  )301;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMVOCMST_N.FILE_NO_03);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMVOCMST_N.FILE_PATH_03);
            sqlstm.sqhstl[21] = (unsigned int  )301;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMVOCMST_N.FILE_NO_04);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMVOCMST_N.FILE_PATH_04);
            sqlstm.sqhstl[23] = (unsigned int  )301;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMVOCMST_N.FILE_NO_05);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMVOCMST_N.FILE_PATH_05);
            sqlstm.sqhstl[25] = (unsigned int  )301;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMVOCMST_N.COMMENT_01);
            sqlstm.sqhstl[26] = (unsigned int  )1001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMVOCMST_N.COMMENT_02);
            sqlstm.sqhstl[27] = (unsigned int  )1001;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMVOCMST_N.COMMENT_03);
            sqlstm.sqhstl[28] = (unsigned int  )1001;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMVOCMST_N.COMMENT_04);
            sqlstm.sqhstl[29] = (unsigned int  )1001;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMVOCMST_N.COMMENT_05);
            sqlstm.sqhstl[30] = (unsigned int  )1001;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMVOCMST_N.COMMENT_06);
            sqlstm.sqhstl[31] = (unsigned int  )1001;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMVOCMST_N.COMMENT_07);
            sqlstm.sqhstl[32] = (unsigned int  )1001;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMVOCMST_N.COMMENT_08);
            sqlstm.sqhstl[33] = (unsigned int  )1001;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMVOCMST_N.COMMENT_09);
            sqlstm.sqhstl[34] = (unsigned int  )1001;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMVOCMST_N.COMMENT_10);
            sqlstm.sqhstl[35] = (unsigned int  )1001;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMVOCMST_N.CMF_01);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMVOCMST_N.CMF_02);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMVOCMST_N.CMF_03);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMVOCMST_N.CMF_04);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMVOCMST_N.CMF_05);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMVOCMST_N.CMF_06);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMVOCMST_N.CMF_07);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMVOCMST_N.CMF_08);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMVOCMST_N.CMF_09);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMVOCMST_N.CMF_10);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMVOCMST_N.USE_YN);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMVOCMST_N.CREATE_USER_ID);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMVOCMST_N.CREATE_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMVOCMST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMVOCMST_N.UPDATE_TIME);
            sqlstm.sqhstl[50] = (unsigned int  )15;
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
        DBU_del_null_cqcmvocmst(&CQCMVOCMST_N, CQCMVOCMST);
    }

    DB_stop_query_timer("DBU_fetch_cqcmvocmst", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cqcmvocmst(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CQCMVOCMST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 53;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1181;
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

    DB_stop_query_timer("DBU_close_cqcmvocmst", sel_type);
}


/* Initialize Function */
void DBU_init_cqcmvocmst(struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    /* memset by Space */
    memset(CQCMVOCMST, ' ', sizeof(struct CQCMVOCMST_TAG));
    
    CQCMVOCMST->COST_QTY_01 = 0;
    CQCMVOCMST->COST_QTY_02 = 0;
    CQCMVOCMST->COST_QTY_03 = 0;
    CQCMVOCMST->COST_MONTH = 0;
}


/* Add Null Function */
void DBU_add_null_cqcmvocmst(struct CQCMVOCMST_N_TAG *CQCMVOCMST_N, struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    /* memset by NULL */
    memset(CQCMVOCMST_N, '\0', sizeof(struct CQCMVOCMST_N_TAG));
    
    MEMCPY_AN(CQCMVOCMST_N->FACTORY, CQCMVOCMST->FACTORY, sizeof(CQCMVOCMST->FACTORY));
    MEMCPY_AN(CQCMVOCMST_N->REPORT_NO, CQCMVOCMST->REPORT_NO, sizeof(CQCMVOCMST->REPORT_NO));
    MEMCPY_AN(CQCMVOCMST_N->CUST_NO, CQCMVOCMST->CUST_NO, sizeof(CQCMVOCMST->CUST_NO));
    MEMCPY_AN(CQCMVOCMST_N->CUST_NAME, CQCMVOCMST->CUST_NAME, sizeof(CQCMVOCMST->CUST_NAME));
    MEMCPY_AN(CQCMVOCMST_N->CREATE_DATE, CQCMVOCMST->CREATE_DATE, sizeof(CQCMVOCMST->CREATE_DATE));
    MEMCPY_AN(CQCMVOCMST_N->RECEIVED_DATE_1, CQCMVOCMST->RECEIVED_DATE_1, sizeof(CQCMVOCMST->RECEIVED_DATE_1));
    MEMCPY_AN(CQCMVOCMST_N->RECEIVED_DATE_2, CQCMVOCMST->RECEIVED_DATE_2, sizeof(CQCMVOCMST->RECEIVED_DATE_2));
    MEMCPY_AN(CQCMVOCMST_N->RECEIVED_DATE_3, CQCMVOCMST->RECEIVED_DATE_3, sizeof(CQCMVOCMST->RECEIVED_DATE_3));
    MEMCPY_AN(CQCMVOCMST_N->CLOSURE_DATE, CQCMVOCMST->CLOSURE_DATE, sizeof(CQCMVOCMST->CLOSURE_DATE));
    MEMCPY_AN(CQCMVOCMST_N->SAL_GROUP, CQCMVOCMST->SAL_GROUP, sizeof(CQCMVOCMST->SAL_GROUP));
    MEMCPY_AN(CQCMVOCMST_N->SAL_USER, CQCMVOCMST->SAL_USER, sizeof(CQCMVOCMST->SAL_USER));
    CQCMVOCMST_N->VOC_STATUS[0] = CQCMVOCMST->VOC_STATUS;
    CQCMVOCMST_N->COST_QTY_01 = CQCMVOCMST->COST_QTY_01;
    CQCMVOCMST_N->COST_QTY_02 = CQCMVOCMST->COST_QTY_02;
    CQCMVOCMST_N->COST_QTY_03 = CQCMVOCMST->COST_QTY_03;
    CQCMVOCMST_N->COST_MONTH = CQCMVOCMST->COST_MONTH;
    MEMCPY_AN(CQCMVOCMST_N->FILE_NO_01, CQCMVOCMST->FILE_NO_01, sizeof(CQCMVOCMST->FILE_NO_01));
    MEMCPY_AN(CQCMVOCMST_N->FILE_PATH_01, CQCMVOCMST->FILE_PATH_01, sizeof(CQCMVOCMST->FILE_PATH_01));
    MEMCPY_AN(CQCMVOCMST_N->FILE_NO_02, CQCMVOCMST->FILE_NO_02, sizeof(CQCMVOCMST->FILE_NO_02));
    MEMCPY_AN(CQCMVOCMST_N->FILE_PATH_02, CQCMVOCMST->FILE_PATH_02, sizeof(CQCMVOCMST->FILE_PATH_02));
    MEMCPY_AN(CQCMVOCMST_N->FILE_NO_03, CQCMVOCMST->FILE_NO_03, sizeof(CQCMVOCMST->FILE_NO_03));
    MEMCPY_AN(CQCMVOCMST_N->FILE_PATH_03, CQCMVOCMST->FILE_PATH_03, sizeof(CQCMVOCMST->FILE_PATH_03));
    MEMCPY_AN(CQCMVOCMST_N->FILE_NO_04, CQCMVOCMST->FILE_NO_04, sizeof(CQCMVOCMST->FILE_NO_04));
    MEMCPY_AN(CQCMVOCMST_N->FILE_PATH_04, CQCMVOCMST->FILE_PATH_04, sizeof(CQCMVOCMST->FILE_PATH_04));
    MEMCPY_AN(CQCMVOCMST_N->FILE_NO_05, CQCMVOCMST->FILE_NO_05, sizeof(CQCMVOCMST->FILE_NO_05));
    MEMCPY_AN(CQCMVOCMST_N->FILE_PATH_05, CQCMVOCMST->FILE_PATH_05, sizeof(CQCMVOCMST->FILE_PATH_05));
    MEMCPY_AN(CQCMVOCMST_N->COMMENT_01, CQCMVOCMST->COMMENT_01, sizeof(CQCMVOCMST->COMMENT_01));
    MEMCPY_AN(CQCMVOCMST_N->COMMENT_02, CQCMVOCMST->COMMENT_02, sizeof(CQCMVOCMST->COMMENT_02));
    MEMCPY_AN(CQCMVOCMST_N->COMMENT_03, CQCMVOCMST->COMMENT_03, sizeof(CQCMVOCMST->COMMENT_03));
    MEMCPY_AN(CQCMVOCMST_N->COMMENT_04, CQCMVOCMST->COMMENT_04, sizeof(CQCMVOCMST->COMMENT_04));
    MEMCPY_AN(CQCMVOCMST_N->COMMENT_05, CQCMVOCMST->COMMENT_05, sizeof(CQCMVOCMST->COMMENT_05));
    MEMCPY_AN(CQCMVOCMST_N->COMMENT_06, CQCMVOCMST->COMMENT_06, sizeof(CQCMVOCMST->COMMENT_06));
    MEMCPY_AN(CQCMVOCMST_N->COMMENT_07, CQCMVOCMST->COMMENT_07, sizeof(CQCMVOCMST->COMMENT_07));
    MEMCPY_AN(CQCMVOCMST_N->COMMENT_08, CQCMVOCMST->COMMENT_08, sizeof(CQCMVOCMST->COMMENT_08));
    MEMCPY_AN(CQCMVOCMST_N->COMMENT_09, CQCMVOCMST->COMMENT_09, sizeof(CQCMVOCMST->COMMENT_09));
    MEMCPY_AN(CQCMVOCMST_N->COMMENT_10, CQCMVOCMST->COMMENT_10, sizeof(CQCMVOCMST->COMMENT_10));
    MEMCPY_AN(CQCMVOCMST_N->CMF_01, CQCMVOCMST->CMF_01, sizeof(CQCMVOCMST->CMF_01));
    MEMCPY_AN(CQCMVOCMST_N->CMF_02, CQCMVOCMST->CMF_02, sizeof(CQCMVOCMST->CMF_02));
    MEMCPY_AN(CQCMVOCMST_N->CMF_03, CQCMVOCMST->CMF_03, sizeof(CQCMVOCMST->CMF_03));
    MEMCPY_AN(CQCMVOCMST_N->CMF_04, CQCMVOCMST->CMF_04, sizeof(CQCMVOCMST->CMF_04));
    MEMCPY_AN(CQCMVOCMST_N->CMF_05, CQCMVOCMST->CMF_05, sizeof(CQCMVOCMST->CMF_05));
    MEMCPY_AN(CQCMVOCMST_N->CMF_06, CQCMVOCMST->CMF_06, sizeof(CQCMVOCMST->CMF_06));
    MEMCPY_AN(CQCMVOCMST_N->CMF_07, CQCMVOCMST->CMF_07, sizeof(CQCMVOCMST->CMF_07));
    MEMCPY_AN(CQCMVOCMST_N->CMF_08, CQCMVOCMST->CMF_08, sizeof(CQCMVOCMST->CMF_08));
    MEMCPY_AN(CQCMVOCMST_N->CMF_09, CQCMVOCMST->CMF_09, sizeof(CQCMVOCMST->CMF_09));
    MEMCPY_AN(CQCMVOCMST_N->CMF_10, CQCMVOCMST->CMF_10, sizeof(CQCMVOCMST->CMF_10));
    CQCMVOCMST_N->USE_YN[0] = CQCMVOCMST->USE_YN;
    MEMCPY_AN(CQCMVOCMST_N->CREATE_USER_ID, CQCMVOCMST->CREATE_USER_ID, sizeof(CQCMVOCMST->CREATE_USER_ID));
    MEMCPY_AN(CQCMVOCMST_N->CREATE_TIME, CQCMVOCMST->CREATE_TIME, sizeof(CQCMVOCMST->CREATE_TIME));
    MEMCPY_AN(CQCMVOCMST_N->UPDATE_USER_ID, CQCMVOCMST->UPDATE_USER_ID, sizeof(CQCMVOCMST->UPDATE_USER_ID));
    MEMCPY_AN(CQCMVOCMST_N->UPDATE_TIME, CQCMVOCMST->UPDATE_TIME, sizeof(CQCMVOCMST->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_cqcmvocmst(struct CQCMVOCMST_N_TAG *CQCMVOCMST_N, struct CQCMVOCMST_TAG *CQCMVOCMST)
{
    MEMCPY_DN(CQCMVOCMST->FACTORY, CQCMVOCMST_N->FACTORY, sizeof(CQCMVOCMST->FACTORY));
    MEMCPY_DN(CQCMVOCMST->REPORT_NO, CQCMVOCMST_N->REPORT_NO, sizeof(CQCMVOCMST->REPORT_NO));
    MEMCPY_DN(CQCMVOCMST->CUST_NO, CQCMVOCMST_N->CUST_NO, sizeof(CQCMVOCMST->CUST_NO));
    MEMCPY_DN(CQCMVOCMST->CUST_NAME, CQCMVOCMST_N->CUST_NAME, sizeof(CQCMVOCMST->CUST_NAME));
    MEMCPY_DN(CQCMVOCMST->CREATE_DATE, CQCMVOCMST_N->CREATE_DATE, sizeof(CQCMVOCMST->CREATE_DATE));
    MEMCPY_DN(CQCMVOCMST->RECEIVED_DATE_1, CQCMVOCMST_N->RECEIVED_DATE_1, sizeof(CQCMVOCMST->RECEIVED_DATE_1));
    MEMCPY_DN(CQCMVOCMST->RECEIVED_DATE_2, CQCMVOCMST_N->RECEIVED_DATE_2, sizeof(CQCMVOCMST->RECEIVED_DATE_2));
    MEMCPY_DN(CQCMVOCMST->RECEIVED_DATE_3, CQCMVOCMST_N->RECEIVED_DATE_3, sizeof(CQCMVOCMST->RECEIVED_DATE_3));
    MEMCPY_DN(CQCMVOCMST->CLOSURE_DATE, CQCMVOCMST_N->CLOSURE_DATE, sizeof(CQCMVOCMST->CLOSURE_DATE));
    MEMCPY_DN(CQCMVOCMST->SAL_GROUP, CQCMVOCMST_N->SAL_GROUP, sizeof(CQCMVOCMST->SAL_GROUP));
    MEMCPY_DN(CQCMVOCMST->SAL_USER, CQCMVOCMST_N->SAL_USER, sizeof(CQCMVOCMST->SAL_USER));
    CQCMVOCMST->VOC_STATUS = CQCMVOCMST_N->VOC_STATUS[0];
    CQCMVOCMST->COST_QTY_01 = CQCMVOCMST_N->COST_QTY_01;
    CQCMVOCMST->COST_QTY_02 = CQCMVOCMST_N->COST_QTY_02;
    CQCMVOCMST->COST_QTY_03 = CQCMVOCMST_N->COST_QTY_03;
    CQCMVOCMST->COST_MONTH = CQCMVOCMST_N->COST_MONTH;
    MEMCPY_DN(CQCMVOCMST->FILE_NO_01, CQCMVOCMST_N->FILE_NO_01, sizeof(CQCMVOCMST->FILE_NO_01));
    MEMCPY_DN(CQCMVOCMST->FILE_PATH_01, CQCMVOCMST_N->FILE_PATH_01, sizeof(CQCMVOCMST->FILE_PATH_01));
    MEMCPY_DN(CQCMVOCMST->FILE_NO_02, CQCMVOCMST_N->FILE_NO_02, sizeof(CQCMVOCMST->FILE_NO_02));
    MEMCPY_DN(CQCMVOCMST->FILE_PATH_02, CQCMVOCMST_N->FILE_PATH_02, sizeof(CQCMVOCMST->FILE_PATH_02));
    MEMCPY_DN(CQCMVOCMST->FILE_NO_03, CQCMVOCMST_N->FILE_NO_03, sizeof(CQCMVOCMST->FILE_NO_03));
    MEMCPY_DN(CQCMVOCMST->FILE_PATH_03, CQCMVOCMST_N->FILE_PATH_03, sizeof(CQCMVOCMST->FILE_PATH_03));
    MEMCPY_DN(CQCMVOCMST->FILE_NO_04, CQCMVOCMST_N->FILE_NO_04, sizeof(CQCMVOCMST->FILE_NO_04));
    MEMCPY_DN(CQCMVOCMST->FILE_PATH_04, CQCMVOCMST_N->FILE_PATH_04, sizeof(CQCMVOCMST->FILE_PATH_04));
    MEMCPY_DN(CQCMVOCMST->FILE_NO_05, CQCMVOCMST_N->FILE_NO_05, sizeof(CQCMVOCMST->FILE_NO_05));
    MEMCPY_DN(CQCMVOCMST->FILE_PATH_05, CQCMVOCMST_N->FILE_PATH_05, sizeof(CQCMVOCMST->FILE_PATH_05));
    MEMCPY_DN(CQCMVOCMST->COMMENT_01, CQCMVOCMST_N->COMMENT_01, sizeof(CQCMVOCMST->COMMENT_01));
    MEMCPY_DN(CQCMVOCMST->COMMENT_02, CQCMVOCMST_N->COMMENT_02, sizeof(CQCMVOCMST->COMMENT_02));
    MEMCPY_DN(CQCMVOCMST->COMMENT_03, CQCMVOCMST_N->COMMENT_03, sizeof(CQCMVOCMST->COMMENT_03));
    MEMCPY_DN(CQCMVOCMST->COMMENT_04, CQCMVOCMST_N->COMMENT_04, sizeof(CQCMVOCMST->COMMENT_04));
    MEMCPY_DN(CQCMVOCMST->COMMENT_05, CQCMVOCMST_N->COMMENT_05, sizeof(CQCMVOCMST->COMMENT_05));
    MEMCPY_DN(CQCMVOCMST->COMMENT_06, CQCMVOCMST_N->COMMENT_06, sizeof(CQCMVOCMST->COMMENT_06));
    MEMCPY_DN(CQCMVOCMST->COMMENT_07, CQCMVOCMST_N->COMMENT_07, sizeof(CQCMVOCMST->COMMENT_07));
    MEMCPY_DN(CQCMVOCMST->COMMENT_08, CQCMVOCMST_N->COMMENT_08, sizeof(CQCMVOCMST->COMMENT_08));
    MEMCPY_DN(CQCMVOCMST->COMMENT_09, CQCMVOCMST_N->COMMENT_09, sizeof(CQCMVOCMST->COMMENT_09));
    MEMCPY_DN(CQCMVOCMST->COMMENT_10, CQCMVOCMST_N->COMMENT_10, sizeof(CQCMVOCMST->COMMENT_10));
    MEMCPY_DN(CQCMVOCMST->CMF_01, CQCMVOCMST_N->CMF_01, sizeof(CQCMVOCMST->CMF_01));
    MEMCPY_DN(CQCMVOCMST->CMF_02, CQCMVOCMST_N->CMF_02, sizeof(CQCMVOCMST->CMF_02));
    MEMCPY_DN(CQCMVOCMST->CMF_03, CQCMVOCMST_N->CMF_03, sizeof(CQCMVOCMST->CMF_03));
    MEMCPY_DN(CQCMVOCMST->CMF_04, CQCMVOCMST_N->CMF_04, sizeof(CQCMVOCMST->CMF_04));
    MEMCPY_DN(CQCMVOCMST->CMF_05, CQCMVOCMST_N->CMF_05, sizeof(CQCMVOCMST->CMF_05));
    MEMCPY_DN(CQCMVOCMST->CMF_06, CQCMVOCMST_N->CMF_06, sizeof(CQCMVOCMST->CMF_06));
    MEMCPY_DN(CQCMVOCMST->CMF_07, CQCMVOCMST_N->CMF_07, sizeof(CQCMVOCMST->CMF_07));
    MEMCPY_DN(CQCMVOCMST->CMF_08, CQCMVOCMST_N->CMF_08, sizeof(CQCMVOCMST->CMF_08));
    MEMCPY_DN(CQCMVOCMST->CMF_09, CQCMVOCMST_N->CMF_09, sizeof(CQCMVOCMST->CMF_09));
    MEMCPY_DN(CQCMVOCMST->CMF_10, CQCMVOCMST_N->CMF_10, sizeof(CQCMVOCMST->CMF_10));
    CQCMVOCMST->USE_YN = CQCMVOCMST_N->USE_YN[0];
    MEMCPY_DN(CQCMVOCMST->CREATE_USER_ID, CQCMVOCMST_N->CREATE_USER_ID, sizeof(CQCMVOCMST->CREATE_USER_ID));
    MEMCPY_DN(CQCMVOCMST->CREATE_TIME, CQCMVOCMST_N->CREATE_TIME, sizeof(CQCMVOCMST->CREATE_TIME));
    MEMCPY_DN(CQCMVOCMST->UPDATE_USER_ID, CQCMVOCMST_N->UPDATE_USER_ID, sizeof(CQCMVOCMST->UPDATE_USER_ID));
    MEMCPY_DN(CQCMVOCMST->UPDATE_TIME, CQCMVOCMST_N->UPDATE_TIME, sizeof(CQCMVOCMST->UPDATE_TIME));
}


