
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
    "DBU_cerpaststs.pc"
};


static unsigned int sqlctx = 9368403;


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
            void  *sqhstv[54];
   unsigned int   sqhstl[54];
            int   sqhsts[54];
            void  *sqindv[54];
            int   sqinds[54];
   unsigned int   sqharm[54];
   unsigned int   *sqharc[54];
   unsigned short  sqadto[54];
   unsigned short  sqtdso[54];
} sqlstm = {13,54};

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
"select FACTORY ,BOOK_TYPE_CODE ,ASSET_NUMBER ,ASSET_NAME ,ATTRIBUTE_CATEGOR\
Y_CODE ,CATEGORY_CODE ,CURRENT_UNITS ,ORIGINAL_COST ,DATE_PLACED_IN_SERVICE ,\
OPERATING_UNIT_SEG ,OPERATING_UNIT ,DEPARTMENT_SEG ,DEPARTMENTS ,PRODUCT_FAMI\
LY_SEG ,PRODUCT_FAMILY ,BUSINESS_UNIT ,TAG_NUMBER ,SERIAL_NUMBER ,MANUFACTURE\
R_NAME ,MODEL_NUMBER ,EMPLOYEE_NUMBER ,EMPLOYEE_NAME ,IN_USE_FLAG ,PRORATE_DA\
TE ,LOCATION_ID ,LOCATION_DESCRIPTION ,DEPRN_METHOD_CODE ,PLC ,PURCHASING_DAT\
E ,CONFIRMATION_DATE ,CONFIRMED_PLC ,RES_ID ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_\
5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CMF_11 ,CMF_12 ,CMF_13 ,CMF_14 ,CMF_15\
 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from CERPASTSTS  \
order by FACTORY asc ,BOOK_TYPE_CODE asc ,ASSET_NUMBER asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,1005,0,4,46,0,0,54,3,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
236,0,0,2,1017,0,4,190,0,0,54,3,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
467,0,0,3,108,0,4,337,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
498,0,0,4,90,0,2,375,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
525,0,0,5,894,0,3,406,0,0,51,51,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,
744,0,0,6,901,0,5,533,0,0,51,51,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,
963,0,0,7,762,0,9,672,0,0,0,0,0,1,0,
978,0,0,7,0,0,13,701,0,0,51,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,
1197,0,0,7,0,0,15,782,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cerpaststs.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2021-09-16 08:37:47
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2021 MIRACOM,INC.
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
void DBU_add_null_cerpaststs(struct CERPASTSTS_N_TAG *CERPASTSTS_N, struct CERPASTSTS_TAG *CERPASTSTS);
void DBU_del_null_cerpaststs(struct CERPASTSTS_N_TAG *CERPASTSTS_N, struct CERPASTSTS_TAG *CERPASTSTS);


/* SQL SELECT Function */
void DBU_select_cerpaststs(int sel_type, struct CERPASTSTS_TAG *CERPASTSTS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CERPASTSTS_N_TAG CERPASTSTS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cerpaststs(&CERPASTSTS_N, CERPASTSTS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    BOOK_TYPE_CODE,
                    ASSET_NUMBER,
                    ASSET_NAME,
                    ATTRIBUTE_CATEGORY_CODE,
                    CATEGORY_CODE,
                    CURRENT_UNITS,
                    ORIGINAL_COST,
                    DATE_PLACED_IN_SERVICE,
                    OPERATING_UNIT_SEG,
                    OPERATING_UNIT,
                    DEPARTMENT_SEG,
                    DEPARTMENTS,
                    PRODUCT_FAMILY_SEG,
                    PRODUCT_FAMILY,
                    BUSINESS_UNIT,
                    TAG_NUMBER,
                    SERIAL_NUMBER,
                    MANUFACTURER_NAME,
                    MODEL_NUMBER,
                    EMPLOYEE_NUMBER,
                    EMPLOYEE_NAME,
                    IN_USE_FLAG,
                    PRORATE_DATE,
                    LOCATION_ID,
                    LOCATION_DESCRIPTION,
                    DEPRN_METHOD_CODE,
                    PLC,
                    PURCHASING_DATE,
                    CONFIRMATION_DATE,
                    CONFIRMED_PLC,
                    RES_ID,
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
                    CMF_11,
                    CMF_12,
                    CMF_13,
                    CMF_14,
                    CMF_15,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :CERPASTSTS_N.FACTORY,
                    :CERPASTSTS_N.BOOK_TYPE_CODE,
                    :CERPASTSTS_N.ASSET_NUMBER,
                    :CERPASTSTS_N.ASSET_NAME,
                    :CERPASTSTS_N.ATTRIBUTE_CATEGORY_CODE,
                    :CERPASTSTS_N.CATEGORY_CODE,
                    :CERPASTSTS_N.CURRENT_UNITS,
                    :CERPASTSTS_N.ORIGINAL_COST,
                    :CERPASTSTS_N.DATE_PLACED_IN_SERVICE,
                    :CERPASTSTS_N.OPERATING_UNIT_SEG,
                    :CERPASTSTS_N.OPERATING_UNIT,
                    :CERPASTSTS_N.DEPARTMENT_SEG,
                    :CERPASTSTS_N.DEPARTMENTS,
                    :CERPASTSTS_N.PRODUCT_FAMILY_SEG,
                    :CERPASTSTS_N.PRODUCT_FAMILY,
                    :CERPASTSTS_N.BUSINESS_UNIT,
                    :CERPASTSTS_N.TAG_NUMBER,
                    :CERPASTSTS_N.SERIAL_NUMBER,
                    :CERPASTSTS_N.MANUFACTURER_NAME,
                    :CERPASTSTS_N.MODEL_NUMBER,
                    :CERPASTSTS_N.EMPLOYEE_NUMBER,
                    :CERPASTSTS_N.EMPLOYEE_NAME,
                    :CERPASTSTS_N.IN_USE_FLAG,
                    :CERPASTSTS_N.PRORATE_DATE,
                    :CERPASTSTS_N.LOCATION_ID,
                    :CERPASTSTS_N.LOCATION_DESCRIPTION,
                    :CERPASTSTS_N.DEPRN_METHOD_CODE,
                    :CERPASTSTS_N.PLC,
                    :CERPASTSTS_N.PURCHASING_DATE,
                    :CERPASTSTS_N.CONFIRMATION_DATE,
                    :CERPASTSTS_N.CONFIRMED_PLC,
                    :CERPASTSTS_N.RES_ID,
                    :CERPASTSTS_N.CMF_1,
                    :CERPASTSTS_N.CMF_2,
                    :CERPASTSTS_N.CMF_3,
                    :CERPASTSTS_N.CMF_4,
                    :CERPASTSTS_N.CMF_5,
                    :CERPASTSTS_N.CMF_6,
                    :CERPASTSTS_N.CMF_7,
                    :CERPASTSTS_N.CMF_8,
                    :CERPASTSTS_N.CMF_9,
                    :CERPASTSTS_N.CMF_10,
                    :CERPASTSTS_N.CMF_11,
                    :CERPASTSTS_N.CMF_12,
                    :CERPASTSTS_N.CMF_13,
                    :CERPASTSTS_N.CMF_14,
                    :CERPASTSTS_N.CMF_15,
                    :CERPASTSTS_N.CREATE_USER_ID,
                    :CERPASTSTS_N.CREATE_TIME,
                    :CERPASTSTS_N.UPDATE_USER_ID,
                    :CERPASTSTS_N.UPDATE_TIME
                FROM CERPASTSTS
                WHERE FACTORY = :CERPASTSTS_N.FACTORY
                    AND BOOK_TYPE_CODE = :CERPASTSTS_N.BOOK_TYPE_CODE
                    AND ASSET_NUMBER = :CERPASTSTS_N.ASSET_NUMBER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,BOOK_TYPE_CODE ,ASSET_NUMBER ,AS\
SET_NAME ,ATTRIBUTE_CATEGORY_CODE ,CATEGORY_CODE ,CURRENT_UNITS ,ORIGINAL_COS\
T ,DATE_PLACED_IN_SERVICE ,OPERATING_UNIT_SEG ,OPERATING_UNIT ,DEPARTMENT_SEG\
 ,DEPARTMENTS ,PRODUCT_FAMILY_SEG ,PRODUCT_FAMILY ,BUSINESS_UNIT ,TAG_NUMBER \
,SERIAL_NUMBER ,MANUFACTURER_NAME ,MODEL_NUMBER ,EMPLOYEE_NUMBER ,EMPLOYEE_NA\
ME ,IN_USE_FLAG ,PRORATE_DATE ,LOCATION_ID ,LOCATION_DESCRIPTION ,DEPRN_METHO\
D_CODE ,PLC ,PURCHASING_DATE ,CONFIRMATION_DATE ,CONFIRMED_PLC ,RES_ID ,CMF_1\
 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CMF_11 ,CMF\
_12 ,CMF_13 ,CMF_14 ,CMF_15 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPD\
ATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b1\
4,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,\
:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b\
45,:b46,:b47,:b48,:b49,:b50  from CERPASTSTS where ((FACTORY=:b0 and BOOK_TYP\
E_CODE=:b1) and ASSET_NUMBER=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CERPASTSTS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CERPASTSTS_N.BOOK_TYPE_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CERPASTSTS_N.ASSET_NUMBER);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CERPASTSTS_N.ASSET_NAME);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CERPASTSTS_N.ATTRIBUTE_CATEGORY_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CERPASTSTS_N.CATEGORY_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CERPASTSTS_N.CURRENT_UNITS);
            sqlstm.sqhstl[6] = (unsigned int  )201;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CERPASTSTS_N.ORIGINAL_COST);
            sqlstm.sqhstl[7] = (unsigned int  )201;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CERPASTSTS_N.DATE_PLACED_IN_SERVICE);
            sqlstm.sqhstl[8] = (unsigned int  )201;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CERPASTSTS_N.OPERATING_UNIT_SEG);
            sqlstm.sqhstl[9] = (unsigned int  )201;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CERPASTSTS_N.OPERATING_UNIT);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CERPASTSTS_N.DEPARTMENT_SEG);
            sqlstm.sqhstl[11] = (unsigned int  )201;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CERPASTSTS_N.DEPARTMENTS);
            sqlstm.sqhstl[12] = (unsigned int  )201;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CERPASTSTS_N.PRODUCT_FAMILY_SEG);
            sqlstm.sqhstl[13] = (unsigned int  )201;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CERPASTSTS_N.PRODUCT_FAMILY);
            sqlstm.sqhstl[14] = (unsigned int  )201;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CERPASTSTS_N.BUSINESS_UNIT);
            sqlstm.sqhstl[15] = (unsigned int  )201;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CERPASTSTS_N.TAG_NUMBER);
            sqlstm.sqhstl[16] = (unsigned int  )201;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CERPASTSTS_N.SERIAL_NUMBER);
            sqlstm.sqhstl[17] = (unsigned int  )201;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CERPASTSTS_N.MANUFACTURER_NAME);
            sqlstm.sqhstl[18] = (unsigned int  )201;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CERPASTSTS_N.MODEL_NUMBER);
            sqlstm.sqhstl[19] = (unsigned int  )201;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CERPASTSTS_N.EMPLOYEE_NUMBER);
            sqlstm.sqhstl[20] = (unsigned int  )201;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CERPASTSTS_N.EMPLOYEE_NAME);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CERPASTSTS_N.IN_USE_FLAG);
            sqlstm.sqhstl[22] = (unsigned int  )201;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CERPASTSTS_N.PRORATE_DATE);
            sqlstm.sqhstl[23] = (unsigned int  )201;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CERPASTSTS_N.LOCATION_ID);
            sqlstm.sqhstl[24] = (unsigned int  )201;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CERPASTSTS_N.LOCATION_DESCRIPTION);
            sqlstm.sqhstl[25] = (unsigned int  )201;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CERPASTSTS_N.DEPRN_METHOD_CODE);
            sqlstm.sqhstl[26] = (unsigned int  )201;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CERPASTSTS_N.PLC);
            sqlstm.sqhstl[27] = (unsigned int  )201;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CERPASTSTS_N.PURCHASING_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )201;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CERPASTSTS_N.CONFIRMATION_DATE);
            sqlstm.sqhstl[29] = (unsigned int  )201;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CERPASTSTS_N.CONFIRMED_PLC);
            sqlstm.sqhstl[30] = (unsigned int  )201;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CERPASTSTS_N.RES_ID);
            sqlstm.sqhstl[31] = (unsigned int  )201;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CERPASTSTS_N.CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )501;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CERPASTSTS_N.CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )501;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CERPASTSTS_N.CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )501;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CERPASTSTS_N.CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )501;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CERPASTSTS_N.CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )501;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CERPASTSTS_N.CMF_6);
            sqlstm.sqhstl[37] = (unsigned int  )501;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CERPASTSTS_N.CMF_7);
            sqlstm.sqhstl[38] = (unsigned int  )501;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CERPASTSTS_N.CMF_8);
            sqlstm.sqhstl[39] = (unsigned int  )501;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CERPASTSTS_N.CMF_9);
            sqlstm.sqhstl[40] = (unsigned int  )501;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CERPASTSTS_N.CMF_10);
            sqlstm.sqhstl[41] = (unsigned int  )501;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CERPASTSTS_N.CMF_11);
            sqlstm.sqhstl[42] = (unsigned int  )501;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CERPASTSTS_N.CMF_12);
            sqlstm.sqhstl[43] = (unsigned int  )501;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CERPASTSTS_N.CMF_13);
            sqlstm.sqhstl[44] = (unsigned int  )501;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CERPASTSTS_N.CMF_14);
            sqlstm.sqhstl[45] = (unsigned int  )501;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CERPASTSTS_N.CMF_15);
            sqlstm.sqhstl[46] = (unsigned int  )501;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CERPASTSTS_N.CREATE_USER_ID);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CERPASTSTS_N.CREATE_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CERPASTSTS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CERPASTSTS_N.UPDATE_TIME);
            sqlstm.sqhstl[50] = (unsigned int  )15;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CERPASTSTS_N.FACTORY);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CERPASTSTS_N.BOOK_TYPE_CODE);
            sqlstm.sqhstl[52] = (unsigned int  )201;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CERPASTSTS_N.ASSET_NUMBER);
            sqlstm.sqhstl[53] = (unsigned int  )201;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
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
        DBU_del_null_cerpaststs(&CERPASTSTS_N, CERPASTSTS);
    }

    DB_stop_query_timer("DBU_select_cerpaststs", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cerpaststs_for_update(int sel_type, struct CERPASTSTS_TAG *CERPASTSTS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CERPASTSTS_N_TAG CERPASTSTS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cerpaststs(&CERPASTSTS_N, CERPASTSTS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    BOOK_TYPE_CODE,
                    ASSET_NUMBER,
                    ASSET_NAME,
                    ATTRIBUTE_CATEGORY_CODE,
                    CATEGORY_CODE,
                    CURRENT_UNITS,
                    ORIGINAL_COST,
                    DATE_PLACED_IN_SERVICE,
                    OPERATING_UNIT_SEG,
                    OPERATING_UNIT,
                    DEPARTMENT_SEG,
                    DEPARTMENTS,
                    PRODUCT_FAMILY_SEG,
                    PRODUCT_FAMILY,
                    BUSINESS_UNIT,
                    TAG_NUMBER,
                    SERIAL_NUMBER,
                    MANUFACTURER_NAME,
                    MODEL_NUMBER,
                    EMPLOYEE_NUMBER,
                    EMPLOYEE_NAME,
                    IN_USE_FLAG,
                    PRORATE_DATE,
                    LOCATION_ID,
                    LOCATION_DESCRIPTION,
                    DEPRN_METHOD_CODE,
                    PLC,
                    PURCHASING_DATE,
                    CONFIRMATION_DATE,
                    CONFIRMED_PLC,
                    RES_ID,
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
                    CMF_11,
                    CMF_12,
                    CMF_13,
                    CMF_14,
                    CMF_15,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :CERPASTSTS_N.FACTORY,
                    :CERPASTSTS_N.BOOK_TYPE_CODE,
                    :CERPASTSTS_N.ASSET_NUMBER,
                    :CERPASTSTS_N.ASSET_NAME,
                    :CERPASTSTS_N.ATTRIBUTE_CATEGORY_CODE,
                    :CERPASTSTS_N.CATEGORY_CODE,
                    :CERPASTSTS_N.CURRENT_UNITS,
                    :CERPASTSTS_N.ORIGINAL_COST,
                    :CERPASTSTS_N.DATE_PLACED_IN_SERVICE,
                    :CERPASTSTS_N.OPERATING_UNIT_SEG,
                    :CERPASTSTS_N.OPERATING_UNIT,
                    :CERPASTSTS_N.DEPARTMENT_SEG,
                    :CERPASTSTS_N.DEPARTMENTS,
                    :CERPASTSTS_N.PRODUCT_FAMILY_SEG,
                    :CERPASTSTS_N.PRODUCT_FAMILY,
                    :CERPASTSTS_N.BUSINESS_UNIT,
                    :CERPASTSTS_N.TAG_NUMBER,
                    :CERPASTSTS_N.SERIAL_NUMBER,
                    :CERPASTSTS_N.MANUFACTURER_NAME,
                    :CERPASTSTS_N.MODEL_NUMBER,
                    :CERPASTSTS_N.EMPLOYEE_NUMBER,
                    :CERPASTSTS_N.EMPLOYEE_NAME,
                    :CERPASTSTS_N.IN_USE_FLAG,
                    :CERPASTSTS_N.PRORATE_DATE,
                    :CERPASTSTS_N.LOCATION_ID,
                    :CERPASTSTS_N.LOCATION_DESCRIPTION,
                    :CERPASTSTS_N.DEPRN_METHOD_CODE,
                    :CERPASTSTS_N.PLC,
                    :CERPASTSTS_N.PURCHASING_DATE,
                    :CERPASTSTS_N.CONFIRMATION_DATE,
                    :CERPASTSTS_N.CONFIRMED_PLC,
                    :CERPASTSTS_N.RES_ID,
                    :CERPASTSTS_N.CMF_1,
                    :CERPASTSTS_N.CMF_2,
                    :CERPASTSTS_N.CMF_3,
                    :CERPASTSTS_N.CMF_4,
                    :CERPASTSTS_N.CMF_5,
                    :CERPASTSTS_N.CMF_6,
                    :CERPASTSTS_N.CMF_7,
                    :CERPASTSTS_N.CMF_8,
                    :CERPASTSTS_N.CMF_9,
                    :CERPASTSTS_N.CMF_10,
                    :CERPASTSTS_N.CMF_11,
                    :CERPASTSTS_N.CMF_12,
                    :CERPASTSTS_N.CMF_13,
                    :CERPASTSTS_N.CMF_14,
                    :CERPASTSTS_N.CMF_15,
                    :CERPASTSTS_N.CREATE_USER_ID,
                    :CERPASTSTS_N.CREATE_TIME,
                    :CERPASTSTS_N.UPDATE_USER_ID,
                    :CERPASTSTS_N.UPDATE_TIME
                FROM CERPASTSTS
                WHERE FACTORY = :CERPASTSTS_N.FACTORY
                    AND BOOK_TYPE_CODE = :CERPASTSTS_N.BOOK_TYPE_CODE
                    AND ASSET_NUMBER = :CERPASTSTS_N.ASSET_NUMBER
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,BOOK_TYPE_CODE ,ASSET_NUMBER ,AS\
SET_NAME ,ATTRIBUTE_CATEGORY_CODE ,CATEGORY_CODE ,CURRENT_UNITS ,ORIGINAL_COS\
T ,DATE_PLACED_IN_SERVICE ,OPERATING_UNIT_SEG ,OPERATING_UNIT ,DEPARTMENT_SEG\
 ,DEPARTMENTS ,PRODUCT_FAMILY_SEG ,PRODUCT_FAMILY ,BUSINESS_UNIT ,TAG_NUMBER \
,SERIAL_NUMBER ,MANUFACTURER_NAME ,MODEL_NUMBER ,EMPLOYEE_NUMBER ,EMPLOYEE_NA\
ME ,IN_USE_FLAG ,PRORATE_DATE ,LOCATION_ID ,LOCATION_DESCRIPTION ,DEPRN_METHO\
D_CODE ,PLC ,PURCHASING_DATE ,CONFIRMATION_DATE ,CONFIRMED_PLC ,RES_ID ,CMF_1\
 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CMF_11 ,CMF\
_12 ,CMF_13 ,CMF_14 ,CMF_15 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPD\
ATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b1\
4,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,\
:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b\
45,:b46,:b47,:b48,:b49,:b50  from CERPASTSTS where ((FACTORY=:b0 and BOOK_TYP\
E_CODE=:b1) and ASSET_NUMBER=:b2) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )236;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CERPASTSTS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CERPASTSTS_N.BOOK_TYPE_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CERPASTSTS_N.ASSET_NUMBER);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CERPASTSTS_N.ASSET_NAME);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CERPASTSTS_N.ATTRIBUTE_CATEGORY_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CERPASTSTS_N.CATEGORY_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CERPASTSTS_N.CURRENT_UNITS);
            sqlstm.sqhstl[6] = (unsigned int  )201;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CERPASTSTS_N.ORIGINAL_COST);
            sqlstm.sqhstl[7] = (unsigned int  )201;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CERPASTSTS_N.DATE_PLACED_IN_SERVICE);
            sqlstm.sqhstl[8] = (unsigned int  )201;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CERPASTSTS_N.OPERATING_UNIT_SEG);
            sqlstm.sqhstl[9] = (unsigned int  )201;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CERPASTSTS_N.OPERATING_UNIT);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CERPASTSTS_N.DEPARTMENT_SEG);
            sqlstm.sqhstl[11] = (unsigned int  )201;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CERPASTSTS_N.DEPARTMENTS);
            sqlstm.sqhstl[12] = (unsigned int  )201;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CERPASTSTS_N.PRODUCT_FAMILY_SEG);
            sqlstm.sqhstl[13] = (unsigned int  )201;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CERPASTSTS_N.PRODUCT_FAMILY);
            sqlstm.sqhstl[14] = (unsigned int  )201;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CERPASTSTS_N.BUSINESS_UNIT);
            sqlstm.sqhstl[15] = (unsigned int  )201;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CERPASTSTS_N.TAG_NUMBER);
            sqlstm.sqhstl[16] = (unsigned int  )201;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CERPASTSTS_N.SERIAL_NUMBER);
            sqlstm.sqhstl[17] = (unsigned int  )201;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CERPASTSTS_N.MANUFACTURER_NAME);
            sqlstm.sqhstl[18] = (unsigned int  )201;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CERPASTSTS_N.MODEL_NUMBER);
            sqlstm.sqhstl[19] = (unsigned int  )201;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CERPASTSTS_N.EMPLOYEE_NUMBER);
            sqlstm.sqhstl[20] = (unsigned int  )201;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CERPASTSTS_N.EMPLOYEE_NAME);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CERPASTSTS_N.IN_USE_FLAG);
            sqlstm.sqhstl[22] = (unsigned int  )201;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CERPASTSTS_N.PRORATE_DATE);
            sqlstm.sqhstl[23] = (unsigned int  )201;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CERPASTSTS_N.LOCATION_ID);
            sqlstm.sqhstl[24] = (unsigned int  )201;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CERPASTSTS_N.LOCATION_DESCRIPTION);
            sqlstm.sqhstl[25] = (unsigned int  )201;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CERPASTSTS_N.DEPRN_METHOD_CODE);
            sqlstm.sqhstl[26] = (unsigned int  )201;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CERPASTSTS_N.PLC);
            sqlstm.sqhstl[27] = (unsigned int  )201;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CERPASTSTS_N.PURCHASING_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )201;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CERPASTSTS_N.CONFIRMATION_DATE);
            sqlstm.sqhstl[29] = (unsigned int  )201;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CERPASTSTS_N.CONFIRMED_PLC);
            sqlstm.sqhstl[30] = (unsigned int  )201;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CERPASTSTS_N.RES_ID);
            sqlstm.sqhstl[31] = (unsigned int  )201;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CERPASTSTS_N.CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )501;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CERPASTSTS_N.CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )501;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CERPASTSTS_N.CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )501;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CERPASTSTS_N.CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )501;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CERPASTSTS_N.CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )501;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CERPASTSTS_N.CMF_6);
            sqlstm.sqhstl[37] = (unsigned int  )501;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CERPASTSTS_N.CMF_7);
            sqlstm.sqhstl[38] = (unsigned int  )501;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CERPASTSTS_N.CMF_8);
            sqlstm.sqhstl[39] = (unsigned int  )501;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CERPASTSTS_N.CMF_9);
            sqlstm.sqhstl[40] = (unsigned int  )501;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CERPASTSTS_N.CMF_10);
            sqlstm.sqhstl[41] = (unsigned int  )501;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CERPASTSTS_N.CMF_11);
            sqlstm.sqhstl[42] = (unsigned int  )501;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CERPASTSTS_N.CMF_12);
            sqlstm.sqhstl[43] = (unsigned int  )501;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CERPASTSTS_N.CMF_13);
            sqlstm.sqhstl[44] = (unsigned int  )501;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CERPASTSTS_N.CMF_14);
            sqlstm.sqhstl[45] = (unsigned int  )501;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CERPASTSTS_N.CMF_15);
            sqlstm.sqhstl[46] = (unsigned int  )501;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CERPASTSTS_N.CREATE_USER_ID);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CERPASTSTS_N.CREATE_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CERPASTSTS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CERPASTSTS_N.UPDATE_TIME);
            sqlstm.sqhstl[50] = (unsigned int  )15;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CERPASTSTS_N.FACTORY);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CERPASTSTS_N.BOOK_TYPE_CODE);
            sqlstm.sqhstl[52] = (unsigned int  )201;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CERPASTSTS_N.ASSET_NUMBER);
            sqlstm.sqhstl[53] = (unsigned int  )201;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
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
        DBU_del_null_cerpaststs(&CERPASTSTS_N, CERPASTSTS);
    }

    DB_stop_query_timer("DBU_select_cerpaststs_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cerpaststs_scalar(int sel_type, struct CERPASTSTS_TAG *CERPASTSTS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CERPASTSTS_N_TAG CERPASTSTS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cerpaststs(&CERPASTSTS_N, CERPASTSTS);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CERPASTSTS
                WHERE FACTORY = :CERPASTSTS_N.FACTORY
                    AND BOOK_TYPE_CODE = :CERPASTSTS_N.BOOK_TYPE_CODE
                    AND ASSET_NUMBER = :CERPASTSTS_N.ASSET_NUMBER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CERPASTSTS where\
 ((FACTORY=:b1 and BOOK_TYPE_CODE=:b2) and ASSET_NUMBER=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )467;
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
            sqlstm.sqhstv[1] = (         void  *)(CERPASTSTS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CERPASTSTS_N.BOOK_TYPE_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CERPASTSTS_N.ASSET_NUMBER);
            sqlstm.sqhstl[3] = (unsigned int  )201;
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

    DB_stop_query_timer("DBU_select_cerpaststs_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cerpaststs(int sel_type, struct CERPASTSTS_TAG *CERPASTSTS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CERPASTSTS_N_TAG CERPASTSTS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cerpaststs(&CERPASTSTS_N, CERPASTSTS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CERPASTSTS
                WHERE FACTORY = :CERPASTSTS_N.FACTORY
                    AND BOOK_TYPE_CODE = :CERPASTSTS_N.BOOK_TYPE_CODE
                    AND ASSET_NUMBER = :CERPASTSTS_N.ASSET_NUMBER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CERPASTSTS  where ((FACTORY=:b0 and\
 BOOK_TYPE_CODE=:b1) and ASSET_NUMBER=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )498;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CERPASTSTS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CERPASTSTS_N.BOOK_TYPE_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CERPASTSTS_N.ASSET_NUMBER);
            sqlstm.sqhstl[2] = (unsigned int  )201;
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

    DB_stop_query_timer("DBU_delete_cerpaststs", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cerpaststs(struct CERPASTSTS_TAG *CERPASTSTS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CERPASTSTS_N_TAG CERPASTSTS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cerpaststs(&CERPASTSTS_N, CERPASTSTS);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CERPASTSTS( 
                    FACTORY, 
                    BOOK_TYPE_CODE, 
                    ASSET_NUMBER, 
                    ASSET_NAME, 
                    ATTRIBUTE_CATEGORY_CODE, 
                    CATEGORY_CODE, 
                    CURRENT_UNITS, 
                    ORIGINAL_COST, 
                    DATE_PLACED_IN_SERVICE, 
                    OPERATING_UNIT_SEG, 
                    OPERATING_UNIT, 
                    DEPARTMENT_SEG, 
                    DEPARTMENTS, 
                    PRODUCT_FAMILY_SEG, 
                    PRODUCT_FAMILY, 
                    BUSINESS_UNIT, 
                    TAG_NUMBER, 
                    SERIAL_NUMBER, 
                    MANUFACTURER_NAME, 
                    MODEL_NUMBER, 
                    EMPLOYEE_NUMBER, 
                    EMPLOYEE_NAME, 
                    IN_USE_FLAG, 
                    PRORATE_DATE, 
                    LOCATION_ID, 
                    LOCATION_DESCRIPTION, 
                    DEPRN_METHOD_CODE, 
                    PLC, 
                    PURCHASING_DATE, 
                    CONFIRMATION_DATE, 
                    CONFIRMED_PLC, 
                    RES_ID, 
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
                    CMF_11, 
                    CMF_12, 
                    CMF_13, 
                    CMF_14, 
                    CMF_15, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME
         ) 
        VALUES (
                    :CERPASTSTS_N.FACTORY,
                    :CERPASTSTS_N.BOOK_TYPE_CODE,
                    :CERPASTSTS_N.ASSET_NUMBER,
                    :CERPASTSTS_N.ASSET_NAME,
                    :CERPASTSTS_N.ATTRIBUTE_CATEGORY_CODE,
                    :CERPASTSTS_N.CATEGORY_CODE,
                    :CERPASTSTS_N.CURRENT_UNITS,
                    :CERPASTSTS_N.ORIGINAL_COST,
                    :CERPASTSTS_N.DATE_PLACED_IN_SERVICE,
                    :CERPASTSTS_N.OPERATING_UNIT_SEG,
                    :CERPASTSTS_N.OPERATING_UNIT,
                    :CERPASTSTS_N.DEPARTMENT_SEG,
                    :CERPASTSTS_N.DEPARTMENTS,
                    :CERPASTSTS_N.PRODUCT_FAMILY_SEG,
                    :CERPASTSTS_N.PRODUCT_FAMILY,
                    :CERPASTSTS_N.BUSINESS_UNIT,
                    :CERPASTSTS_N.TAG_NUMBER,
                    :CERPASTSTS_N.SERIAL_NUMBER,
                    :CERPASTSTS_N.MANUFACTURER_NAME,
                    :CERPASTSTS_N.MODEL_NUMBER,
                    :CERPASTSTS_N.EMPLOYEE_NUMBER,
                    :CERPASTSTS_N.EMPLOYEE_NAME,
                    :CERPASTSTS_N.IN_USE_FLAG,
                    :CERPASTSTS_N.PRORATE_DATE,
                    :CERPASTSTS_N.LOCATION_ID,
                    :CERPASTSTS_N.LOCATION_DESCRIPTION,
                    :CERPASTSTS_N.DEPRN_METHOD_CODE,
                    :CERPASTSTS_N.PLC,
                    :CERPASTSTS_N.PURCHASING_DATE,
                    :CERPASTSTS_N.CONFIRMATION_DATE,
                    :CERPASTSTS_N.CONFIRMED_PLC,
                    :CERPASTSTS_N.RES_ID,
                    :CERPASTSTS_N.CMF_1,
                    :CERPASTSTS_N.CMF_2,
                    :CERPASTSTS_N.CMF_3,
                    :CERPASTSTS_N.CMF_4,
                    :CERPASTSTS_N.CMF_5,
                    :CERPASTSTS_N.CMF_6,
                    :CERPASTSTS_N.CMF_7,
                    :CERPASTSTS_N.CMF_8,
                    :CERPASTSTS_N.CMF_9,
                    :CERPASTSTS_N.CMF_10,
                    :CERPASTSTS_N.CMF_11,
                    :CERPASTSTS_N.CMF_12,
                    :CERPASTSTS_N.CMF_13,
                    :CERPASTSTS_N.CMF_14,
                    :CERPASTSTS_N.CMF_15,
                    :CERPASTSTS_N.CREATE_USER_ID,
                    :CERPASTSTS_N.CREATE_TIME,
                    :CERPASTSTS_N.UPDATE_USER_ID,
                    :CERPASTSTS_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 54;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into CERPASTSTS (FACTORY,BOOK_TYPE_CODE,ASSET_NUM\
BER,ASSET_NAME,ATTRIBUTE_CATEGORY_CODE,CATEGORY_CODE,CURRENT_UNITS,ORIGINAL_C\
OST,DATE_PLACED_IN_SERVICE,OPERATING_UNIT_SEG,OPERATING_UNIT,DEPARTMENT_SEG,D\
EPARTMENTS,PRODUCT_FAMILY_SEG,PRODUCT_FAMILY,BUSINESS_UNIT,TAG_NUMBER,SERIAL_\
NUMBER,MANUFACTURER_NAME,MODEL_NUMBER,EMPLOYEE_NUMBER,EMPLOYEE_NAME,IN_USE_FL\
AG,PRORATE_DATE,LOCATION_ID,LOCATION_DESCRIPTION,DEPRN_METHOD_CODE,PLC,PURCHA\
SING_DATE,CONFIRMATION_DATE,CONFIRMED_PLC,RES_ID,CMF_1,CMF_2,CMF_3,CMF_4,CMF_\
5,CMF_6,CMF_7,CMF_8,CMF_9,CMF_10,CMF_11,CMF_12,CMF_13,CMF_14,CMF_15,CREATE_US\
ER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) values (:b0,:b1,:b2,:b3,:b4,:b5\
,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,\
:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b\
37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )525;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CERPASTSTS_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CERPASTSTS_N.BOOK_TYPE_CODE);
    sqlstm.sqhstl[1] = (unsigned int  )201;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CERPASTSTS_N.ASSET_NUMBER);
    sqlstm.sqhstl[2] = (unsigned int  )201;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(CERPASTSTS_N.ASSET_NAME);
    sqlstm.sqhstl[3] = (unsigned int  )201;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CERPASTSTS_N.ATTRIBUTE_CATEGORY_CODE);
    sqlstm.sqhstl[4] = (unsigned int  )201;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(CERPASTSTS_N.CATEGORY_CODE);
    sqlstm.sqhstl[5] = (unsigned int  )201;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CERPASTSTS_N.CURRENT_UNITS);
    sqlstm.sqhstl[6] = (unsigned int  )201;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(CERPASTSTS_N.ORIGINAL_COST);
    sqlstm.sqhstl[7] = (unsigned int  )201;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CERPASTSTS_N.DATE_PLACED_IN_SERVICE);
    sqlstm.sqhstl[8] = (unsigned int  )201;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CERPASTSTS_N.OPERATING_UNIT_SEG);
    sqlstm.sqhstl[9] = (unsigned int  )201;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(CERPASTSTS_N.OPERATING_UNIT);
    sqlstm.sqhstl[10] = (unsigned int  )201;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(CERPASTSTS_N.DEPARTMENT_SEG);
    sqlstm.sqhstl[11] = (unsigned int  )201;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(CERPASTSTS_N.DEPARTMENTS);
    sqlstm.sqhstl[12] = (unsigned int  )201;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CERPASTSTS_N.PRODUCT_FAMILY_SEG);
    sqlstm.sqhstl[13] = (unsigned int  )201;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(CERPASTSTS_N.PRODUCT_FAMILY);
    sqlstm.sqhstl[14] = (unsigned int  )201;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CERPASTSTS_N.BUSINESS_UNIT);
    sqlstm.sqhstl[15] = (unsigned int  )201;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CERPASTSTS_N.TAG_NUMBER);
    sqlstm.sqhstl[16] = (unsigned int  )201;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CERPASTSTS_N.SERIAL_NUMBER);
    sqlstm.sqhstl[17] = (unsigned int  )201;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CERPASTSTS_N.MANUFACTURER_NAME);
    sqlstm.sqhstl[18] = (unsigned int  )201;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(CERPASTSTS_N.MODEL_NUMBER);
    sqlstm.sqhstl[19] = (unsigned int  )201;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CERPASTSTS_N.EMPLOYEE_NUMBER);
    sqlstm.sqhstl[20] = (unsigned int  )201;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CERPASTSTS_N.EMPLOYEE_NAME);
    sqlstm.sqhstl[21] = (unsigned int  )201;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(CERPASTSTS_N.IN_USE_FLAG);
    sqlstm.sqhstl[22] = (unsigned int  )201;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(CERPASTSTS_N.PRORATE_DATE);
    sqlstm.sqhstl[23] = (unsigned int  )201;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CERPASTSTS_N.LOCATION_ID);
    sqlstm.sqhstl[24] = (unsigned int  )201;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(CERPASTSTS_N.LOCATION_DESCRIPTION);
    sqlstm.sqhstl[25] = (unsigned int  )201;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(CERPASTSTS_N.DEPRN_METHOD_CODE);
    sqlstm.sqhstl[26] = (unsigned int  )201;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(CERPASTSTS_N.PLC);
    sqlstm.sqhstl[27] = (unsigned int  )201;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(CERPASTSTS_N.PURCHASING_DATE);
    sqlstm.sqhstl[28] = (unsigned int  )201;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(CERPASTSTS_N.CONFIRMATION_DATE);
    sqlstm.sqhstl[29] = (unsigned int  )201;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(CERPASTSTS_N.CONFIRMED_PLC);
    sqlstm.sqhstl[30] = (unsigned int  )201;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(CERPASTSTS_N.RES_ID);
    sqlstm.sqhstl[31] = (unsigned int  )201;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(CERPASTSTS_N.CMF_1);
    sqlstm.sqhstl[32] = (unsigned int  )501;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(CERPASTSTS_N.CMF_2);
    sqlstm.sqhstl[33] = (unsigned int  )501;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(CERPASTSTS_N.CMF_3);
    sqlstm.sqhstl[34] = (unsigned int  )501;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(CERPASTSTS_N.CMF_4);
    sqlstm.sqhstl[35] = (unsigned int  )501;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(CERPASTSTS_N.CMF_5);
    sqlstm.sqhstl[36] = (unsigned int  )501;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(CERPASTSTS_N.CMF_6);
    sqlstm.sqhstl[37] = (unsigned int  )501;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(CERPASTSTS_N.CMF_7);
    sqlstm.sqhstl[38] = (unsigned int  )501;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(CERPASTSTS_N.CMF_8);
    sqlstm.sqhstl[39] = (unsigned int  )501;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(CERPASTSTS_N.CMF_9);
    sqlstm.sqhstl[40] = (unsigned int  )501;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(CERPASTSTS_N.CMF_10);
    sqlstm.sqhstl[41] = (unsigned int  )501;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(CERPASTSTS_N.CMF_11);
    sqlstm.sqhstl[42] = (unsigned int  )501;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(CERPASTSTS_N.CMF_12);
    sqlstm.sqhstl[43] = (unsigned int  )501;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(CERPASTSTS_N.CMF_13);
    sqlstm.sqhstl[44] = (unsigned int  )501;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(CERPASTSTS_N.CMF_14);
    sqlstm.sqhstl[45] = (unsigned int  )501;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(CERPASTSTS_N.CMF_15);
    sqlstm.sqhstl[46] = (unsigned int  )501;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(CERPASTSTS_N.CREATE_USER_ID);
    sqlstm.sqhstl[47] = (unsigned int  )21;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(CERPASTSTS_N.CREATE_TIME);
    sqlstm.sqhstl[48] = (unsigned int  )15;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(CERPASTSTS_N.UPDATE_USER_ID);
    sqlstm.sqhstl[49] = (unsigned int  )21;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(CERPASTSTS_N.UPDATE_TIME);
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



    DB_stop_query_timer("DBU_insert_cerpaststs", 0);
}


/* SQL UPDATE Function */
void DBU_update_cerpaststs(int sel_type, struct CERPASTSTS_TAG *CERPASTSTS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CERPASTSTS_N_TAG CERPASTSTS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cerpaststs(&CERPASTSTS_N, CERPASTSTS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CERPASTSTS SET
                    ASSET_NAME = :CERPASTSTS_N.ASSET_NAME,
                    ATTRIBUTE_CATEGORY_CODE = :CERPASTSTS_N.ATTRIBUTE_CATEGORY_CODE,
                    CATEGORY_CODE = :CERPASTSTS_N.CATEGORY_CODE,
                    CURRENT_UNITS = :CERPASTSTS_N.CURRENT_UNITS,
                    ORIGINAL_COST = :CERPASTSTS_N.ORIGINAL_COST,
                    DATE_PLACED_IN_SERVICE = :CERPASTSTS_N.DATE_PLACED_IN_SERVICE,
                    OPERATING_UNIT_SEG = :CERPASTSTS_N.OPERATING_UNIT_SEG,
                    OPERATING_UNIT = :CERPASTSTS_N.OPERATING_UNIT,
                    DEPARTMENT_SEG = :CERPASTSTS_N.DEPARTMENT_SEG,
                    DEPARTMENTS = :CERPASTSTS_N.DEPARTMENTS,
                    PRODUCT_FAMILY_SEG = :CERPASTSTS_N.PRODUCT_FAMILY_SEG,
                    PRODUCT_FAMILY = :CERPASTSTS_N.PRODUCT_FAMILY,
                    BUSINESS_UNIT = :CERPASTSTS_N.BUSINESS_UNIT,
                    TAG_NUMBER = :CERPASTSTS_N.TAG_NUMBER,
                    SERIAL_NUMBER = :CERPASTSTS_N.SERIAL_NUMBER,
                    MANUFACTURER_NAME = :CERPASTSTS_N.MANUFACTURER_NAME,
                    MODEL_NUMBER = :CERPASTSTS_N.MODEL_NUMBER,
                    EMPLOYEE_NUMBER = :CERPASTSTS_N.EMPLOYEE_NUMBER,
                    EMPLOYEE_NAME = :CERPASTSTS_N.EMPLOYEE_NAME,
                    IN_USE_FLAG = :CERPASTSTS_N.IN_USE_FLAG,
                    PRORATE_DATE = :CERPASTSTS_N.PRORATE_DATE,
                    LOCATION_ID = :CERPASTSTS_N.LOCATION_ID,
                    LOCATION_DESCRIPTION = :CERPASTSTS_N.LOCATION_DESCRIPTION,
                    DEPRN_METHOD_CODE = :CERPASTSTS_N.DEPRN_METHOD_CODE,
                    PLC = :CERPASTSTS_N.PLC,
                    PURCHASING_DATE = :CERPASTSTS_N.PURCHASING_DATE,
                    CONFIRMATION_DATE = :CERPASTSTS_N.CONFIRMATION_DATE,
                    CONFIRMED_PLC = :CERPASTSTS_N.CONFIRMED_PLC,
                    RES_ID = :CERPASTSTS_N.RES_ID,
                    CMF_1 = :CERPASTSTS_N.CMF_1,
                    CMF_2 = :CERPASTSTS_N.CMF_2,
                    CMF_3 = :CERPASTSTS_N.CMF_3,
                    CMF_4 = :CERPASTSTS_N.CMF_4,
                    CMF_5 = :CERPASTSTS_N.CMF_5,
                    CMF_6 = :CERPASTSTS_N.CMF_6,
                    CMF_7 = :CERPASTSTS_N.CMF_7,
                    CMF_8 = :CERPASTSTS_N.CMF_8,
                    CMF_9 = :CERPASTSTS_N.CMF_9,
                    CMF_10 = :CERPASTSTS_N.CMF_10,
                    CMF_11 = :CERPASTSTS_N.CMF_11,
                    CMF_12 = :CERPASTSTS_N.CMF_12,
                    CMF_13 = :CERPASTSTS_N.CMF_13,
                    CMF_14 = :CERPASTSTS_N.CMF_14,
                    CMF_15 = :CERPASTSTS_N.CMF_15,
                    CREATE_USER_ID = :CERPASTSTS_N.CREATE_USER_ID,
                    CREATE_TIME = :CERPASTSTS_N.CREATE_TIME,
                    UPDATE_USER_ID = :CERPASTSTS_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CERPASTSTS_N.UPDATE_TIME
                WHERE FACTORY = :CERPASTSTS_N.FACTORY
                    AND BOOK_TYPE_CODE = :CERPASTSTS_N.BOOK_TYPE_CODE
                    AND ASSET_NUMBER = :CERPASTSTS_N.ASSET_NUMBER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CERPASTSTS  set ASSET_NAME=:b0,ATTRIBUTE_\
CATEGORY_CODE=:b1,CATEGORY_CODE=:b2,CURRENT_UNITS=:b3,ORIGINAL_COST=:b4,DATE_\
PLACED_IN_SERVICE=:b5,OPERATING_UNIT_SEG=:b6,OPERATING_UNIT=:b7,DEPARTMENT_SE\
G=:b8,DEPARTMENTS=:b9,PRODUCT_FAMILY_SEG=:b10,PRODUCT_FAMILY=:b11,BUSINESS_UN\
IT=:b12,TAG_NUMBER=:b13,SERIAL_NUMBER=:b14,MANUFACTURER_NAME=:b15,MODEL_NUMBE\
R=:b16,EMPLOYEE_NUMBER=:b17,EMPLOYEE_NAME=:b18,IN_USE_FLAG=:b19,PRORATE_DATE=\
:b20,LOCATION_ID=:b21,LOCATION_DESCRIPTION=:b22,DEPRN_METHOD_CODE=:b23,PLC=:b\
24,PURCHASING_DATE=:b25,CONFIRMATION_DATE=:b26,CONFIRMED_PLC=:b27,RES_ID=:b28\
,CMF_1=:b29,CMF_2=:b30,CMF_3=:b31,CMF_4=:b32,CMF_5=:b33,CMF_6=:b34,CMF_7=:b35\
,CMF_8=:b36,CMF_9=:b37,CMF_10=:b38,CMF_11=:b39,CMF_12=:b40,CMF_13=:b41,CMF_14\
=:b42,CMF_15=:b43,CREATE_USER_ID=:b44,CREATE_TIME=:b45,UPDATE_USER_ID=:b46,UP\
DATE_TIME=:b47 where ((FACTORY=:b48 and BOOK_TYPE_CODE=:b49) and ASSET_NUMBER\
=:b50)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )744;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CERPASTSTS_N.ASSET_NAME);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CERPASTSTS_N.ATTRIBUTE_CATEGORY_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CERPASTSTS_N.CATEGORY_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CERPASTSTS_N.CURRENT_UNITS);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CERPASTSTS_N.ORIGINAL_COST);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CERPASTSTS_N.DATE_PLACED_IN_SERVICE);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CERPASTSTS_N.OPERATING_UNIT_SEG);
            sqlstm.sqhstl[6] = (unsigned int  )201;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CERPASTSTS_N.OPERATING_UNIT);
            sqlstm.sqhstl[7] = (unsigned int  )201;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CERPASTSTS_N.DEPARTMENT_SEG);
            sqlstm.sqhstl[8] = (unsigned int  )201;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CERPASTSTS_N.DEPARTMENTS);
            sqlstm.sqhstl[9] = (unsigned int  )201;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CERPASTSTS_N.PRODUCT_FAMILY_SEG);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CERPASTSTS_N.PRODUCT_FAMILY);
            sqlstm.sqhstl[11] = (unsigned int  )201;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CERPASTSTS_N.BUSINESS_UNIT);
            sqlstm.sqhstl[12] = (unsigned int  )201;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CERPASTSTS_N.TAG_NUMBER);
            sqlstm.sqhstl[13] = (unsigned int  )201;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CERPASTSTS_N.SERIAL_NUMBER);
            sqlstm.sqhstl[14] = (unsigned int  )201;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CERPASTSTS_N.MANUFACTURER_NAME);
            sqlstm.sqhstl[15] = (unsigned int  )201;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CERPASTSTS_N.MODEL_NUMBER);
            sqlstm.sqhstl[16] = (unsigned int  )201;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CERPASTSTS_N.EMPLOYEE_NUMBER);
            sqlstm.sqhstl[17] = (unsigned int  )201;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CERPASTSTS_N.EMPLOYEE_NAME);
            sqlstm.sqhstl[18] = (unsigned int  )201;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CERPASTSTS_N.IN_USE_FLAG);
            sqlstm.sqhstl[19] = (unsigned int  )201;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CERPASTSTS_N.PRORATE_DATE);
            sqlstm.sqhstl[20] = (unsigned int  )201;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CERPASTSTS_N.LOCATION_ID);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CERPASTSTS_N.LOCATION_DESCRIPTION);
            sqlstm.sqhstl[22] = (unsigned int  )201;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CERPASTSTS_N.DEPRN_METHOD_CODE);
            sqlstm.sqhstl[23] = (unsigned int  )201;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CERPASTSTS_N.PLC);
            sqlstm.sqhstl[24] = (unsigned int  )201;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CERPASTSTS_N.PURCHASING_DATE);
            sqlstm.sqhstl[25] = (unsigned int  )201;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CERPASTSTS_N.CONFIRMATION_DATE);
            sqlstm.sqhstl[26] = (unsigned int  )201;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CERPASTSTS_N.CONFIRMED_PLC);
            sqlstm.sqhstl[27] = (unsigned int  )201;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CERPASTSTS_N.RES_ID);
            sqlstm.sqhstl[28] = (unsigned int  )201;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CERPASTSTS_N.CMF_1);
            sqlstm.sqhstl[29] = (unsigned int  )501;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CERPASTSTS_N.CMF_2);
            sqlstm.sqhstl[30] = (unsigned int  )501;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CERPASTSTS_N.CMF_3);
            sqlstm.sqhstl[31] = (unsigned int  )501;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CERPASTSTS_N.CMF_4);
            sqlstm.sqhstl[32] = (unsigned int  )501;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CERPASTSTS_N.CMF_5);
            sqlstm.sqhstl[33] = (unsigned int  )501;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CERPASTSTS_N.CMF_6);
            sqlstm.sqhstl[34] = (unsigned int  )501;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CERPASTSTS_N.CMF_7);
            sqlstm.sqhstl[35] = (unsigned int  )501;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CERPASTSTS_N.CMF_8);
            sqlstm.sqhstl[36] = (unsigned int  )501;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CERPASTSTS_N.CMF_9);
            sqlstm.sqhstl[37] = (unsigned int  )501;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CERPASTSTS_N.CMF_10);
            sqlstm.sqhstl[38] = (unsigned int  )501;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CERPASTSTS_N.CMF_11);
            sqlstm.sqhstl[39] = (unsigned int  )501;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CERPASTSTS_N.CMF_12);
            sqlstm.sqhstl[40] = (unsigned int  )501;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CERPASTSTS_N.CMF_13);
            sqlstm.sqhstl[41] = (unsigned int  )501;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CERPASTSTS_N.CMF_14);
            sqlstm.sqhstl[42] = (unsigned int  )501;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CERPASTSTS_N.CMF_15);
            sqlstm.sqhstl[43] = (unsigned int  )501;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CERPASTSTS_N.CREATE_USER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CERPASTSTS_N.CREATE_TIME);
            sqlstm.sqhstl[45] = (unsigned int  )15;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CERPASTSTS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CERPASTSTS_N.UPDATE_TIME);
            sqlstm.sqhstl[47] = (unsigned int  )15;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CERPASTSTS_N.FACTORY);
            sqlstm.sqhstl[48] = (unsigned int  )11;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CERPASTSTS_N.BOOK_TYPE_CODE);
            sqlstm.sqhstl[49] = (unsigned int  )201;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CERPASTSTS_N.ASSET_NUMBER);
            sqlstm.sqhstl[50] = (unsigned int  )201;
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

    DB_stop_query_timer("DBU_update_cerpaststs", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cerpaststs(int sel_type, struct CERPASTSTS_TAG *CERPASTSTS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CERPASTSTS_N_TAG CERPASTSTS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cerpaststs(&CERPASTSTS_N, CERPASTSTS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CERPASTSTS_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    BOOK_TYPE_CODE,
                    ASSET_NUMBER,
                    ASSET_NAME,
                    ATTRIBUTE_CATEGORY_CODE,
                    CATEGORY_CODE,
                    CURRENT_UNITS,
                    ORIGINAL_COST,
                    DATE_PLACED_IN_SERVICE,
                    OPERATING_UNIT_SEG,
                    OPERATING_UNIT,
                    DEPARTMENT_SEG,
                    DEPARTMENTS,
                    PRODUCT_FAMILY_SEG,
                    PRODUCT_FAMILY,
                    BUSINESS_UNIT,
                    TAG_NUMBER,
                    SERIAL_NUMBER,
                    MANUFACTURER_NAME,
                    MODEL_NUMBER,
                    EMPLOYEE_NUMBER,
                    EMPLOYEE_NAME,
                    IN_USE_FLAG,
                    PRORATE_DATE,
                    LOCATION_ID,
                    LOCATION_DESCRIPTION,
                    DEPRN_METHOD_CODE,
                    PLC,
                    PURCHASING_DATE,
                    CONFIRMATION_DATE,
                    CONFIRMED_PLC,
                    RES_ID,
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
                    CMF_11,
                    CMF_12,
                    CMF_13,
                    CMF_14,
                    CMF_15,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM CERPASTSTS
                ORDER BY FACTORY ASC,
                    BOOK_TYPE_CODE ASC,
                    ASSET_NUMBER ASC; */ 

            /* EXEC SQL OPEN DBU_CERPASTSTS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )963;
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

    DB_stop_query_timer("DBU_open_cerpaststs", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cerpaststs(int sel_type, struct CERPASTSTS_TAG *CERPASTSTS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CERPASTSTS_N_TAG CERPASTSTS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CERPASTSTS_CUR_1 INTO
                :CERPASTSTS_N.FACTORY,
                :CERPASTSTS_N.BOOK_TYPE_CODE,
                :CERPASTSTS_N.ASSET_NUMBER,
                :CERPASTSTS_N.ASSET_NAME,
                :CERPASTSTS_N.ATTRIBUTE_CATEGORY_CODE,
                :CERPASTSTS_N.CATEGORY_CODE,
                :CERPASTSTS_N.CURRENT_UNITS,
                :CERPASTSTS_N.ORIGINAL_COST,
                :CERPASTSTS_N.DATE_PLACED_IN_SERVICE,
                :CERPASTSTS_N.OPERATING_UNIT_SEG,
                :CERPASTSTS_N.OPERATING_UNIT,
                :CERPASTSTS_N.DEPARTMENT_SEG,
                :CERPASTSTS_N.DEPARTMENTS,
                :CERPASTSTS_N.PRODUCT_FAMILY_SEG,
                :CERPASTSTS_N.PRODUCT_FAMILY,
                :CERPASTSTS_N.BUSINESS_UNIT,
                :CERPASTSTS_N.TAG_NUMBER,
                :CERPASTSTS_N.SERIAL_NUMBER,
                :CERPASTSTS_N.MANUFACTURER_NAME,
                :CERPASTSTS_N.MODEL_NUMBER,
                :CERPASTSTS_N.EMPLOYEE_NUMBER,
                :CERPASTSTS_N.EMPLOYEE_NAME,
                :CERPASTSTS_N.IN_USE_FLAG,
                :CERPASTSTS_N.PRORATE_DATE,
                :CERPASTSTS_N.LOCATION_ID,
                :CERPASTSTS_N.LOCATION_DESCRIPTION,
                :CERPASTSTS_N.DEPRN_METHOD_CODE,
                :CERPASTSTS_N.PLC,
                :CERPASTSTS_N.PURCHASING_DATE,
                :CERPASTSTS_N.CONFIRMATION_DATE,
                :CERPASTSTS_N.CONFIRMED_PLC,
                :CERPASTSTS_N.RES_ID,
                :CERPASTSTS_N.CMF_1,
                :CERPASTSTS_N.CMF_2,
                :CERPASTSTS_N.CMF_3,
                :CERPASTSTS_N.CMF_4,
                :CERPASTSTS_N.CMF_5,
                :CERPASTSTS_N.CMF_6,
                :CERPASTSTS_N.CMF_7,
                :CERPASTSTS_N.CMF_8,
                :CERPASTSTS_N.CMF_9,
                :CERPASTSTS_N.CMF_10,
                :CERPASTSTS_N.CMF_11,
                :CERPASTSTS_N.CMF_12,
                :CERPASTSTS_N.CMF_13,
                :CERPASTSTS_N.CMF_14,
                :CERPASTSTS_N.CMF_15,
                :CERPASTSTS_N.CREATE_USER_ID,
                :CERPASTSTS_N.CREATE_TIME,
                :CERPASTSTS_N.UPDATE_USER_ID,
                :CERPASTSTS_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )978;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CERPASTSTS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CERPASTSTS_N.BOOK_TYPE_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CERPASTSTS_N.ASSET_NUMBER);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CERPASTSTS_N.ASSET_NAME);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CERPASTSTS_N.ATTRIBUTE_CATEGORY_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CERPASTSTS_N.CATEGORY_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CERPASTSTS_N.CURRENT_UNITS);
            sqlstm.sqhstl[6] = (unsigned int  )201;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CERPASTSTS_N.ORIGINAL_COST);
            sqlstm.sqhstl[7] = (unsigned int  )201;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CERPASTSTS_N.DATE_PLACED_IN_SERVICE);
            sqlstm.sqhstl[8] = (unsigned int  )201;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CERPASTSTS_N.OPERATING_UNIT_SEG);
            sqlstm.sqhstl[9] = (unsigned int  )201;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CERPASTSTS_N.OPERATING_UNIT);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CERPASTSTS_N.DEPARTMENT_SEG);
            sqlstm.sqhstl[11] = (unsigned int  )201;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CERPASTSTS_N.DEPARTMENTS);
            sqlstm.sqhstl[12] = (unsigned int  )201;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CERPASTSTS_N.PRODUCT_FAMILY_SEG);
            sqlstm.sqhstl[13] = (unsigned int  )201;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CERPASTSTS_N.PRODUCT_FAMILY);
            sqlstm.sqhstl[14] = (unsigned int  )201;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CERPASTSTS_N.BUSINESS_UNIT);
            sqlstm.sqhstl[15] = (unsigned int  )201;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CERPASTSTS_N.TAG_NUMBER);
            sqlstm.sqhstl[16] = (unsigned int  )201;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CERPASTSTS_N.SERIAL_NUMBER);
            sqlstm.sqhstl[17] = (unsigned int  )201;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CERPASTSTS_N.MANUFACTURER_NAME);
            sqlstm.sqhstl[18] = (unsigned int  )201;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CERPASTSTS_N.MODEL_NUMBER);
            sqlstm.sqhstl[19] = (unsigned int  )201;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CERPASTSTS_N.EMPLOYEE_NUMBER);
            sqlstm.sqhstl[20] = (unsigned int  )201;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CERPASTSTS_N.EMPLOYEE_NAME);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CERPASTSTS_N.IN_USE_FLAG);
            sqlstm.sqhstl[22] = (unsigned int  )201;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CERPASTSTS_N.PRORATE_DATE);
            sqlstm.sqhstl[23] = (unsigned int  )201;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CERPASTSTS_N.LOCATION_ID);
            sqlstm.sqhstl[24] = (unsigned int  )201;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CERPASTSTS_N.LOCATION_DESCRIPTION);
            sqlstm.sqhstl[25] = (unsigned int  )201;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CERPASTSTS_N.DEPRN_METHOD_CODE);
            sqlstm.sqhstl[26] = (unsigned int  )201;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CERPASTSTS_N.PLC);
            sqlstm.sqhstl[27] = (unsigned int  )201;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CERPASTSTS_N.PURCHASING_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )201;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CERPASTSTS_N.CONFIRMATION_DATE);
            sqlstm.sqhstl[29] = (unsigned int  )201;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CERPASTSTS_N.CONFIRMED_PLC);
            sqlstm.sqhstl[30] = (unsigned int  )201;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CERPASTSTS_N.RES_ID);
            sqlstm.sqhstl[31] = (unsigned int  )201;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CERPASTSTS_N.CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )501;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CERPASTSTS_N.CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )501;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CERPASTSTS_N.CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )501;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CERPASTSTS_N.CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )501;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CERPASTSTS_N.CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )501;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CERPASTSTS_N.CMF_6);
            sqlstm.sqhstl[37] = (unsigned int  )501;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CERPASTSTS_N.CMF_7);
            sqlstm.sqhstl[38] = (unsigned int  )501;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CERPASTSTS_N.CMF_8);
            sqlstm.sqhstl[39] = (unsigned int  )501;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CERPASTSTS_N.CMF_9);
            sqlstm.sqhstl[40] = (unsigned int  )501;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CERPASTSTS_N.CMF_10);
            sqlstm.sqhstl[41] = (unsigned int  )501;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CERPASTSTS_N.CMF_11);
            sqlstm.sqhstl[42] = (unsigned int  )501;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CERPASTSTS_N.CMF_12);
            sqlstm.sqhstl[43] = (unsigned int  )501;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CERPASTSTS_N.CMF_13);
            sqlstm.sqhstl[44] = (unsigned int  )501;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CERPASTSTS_N.CMF_14);
            sqlstm.sqhstl[45] = (unsigned int  )501;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CERPASTSTS_N.CMF_15);
            sqlstm.sqhstl[46] = (unsigned int  )501;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CERPASTSTS_N.CREATE_USER_ID);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CERPASTSTS_N.CREATE_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CERPASTSTS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CERPASTSTS_N.UPDATE_TIME);
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
        DBU_del_null_cerpaststs(&CERPASTSTS_N, CERPASTSTS);
    }

    DB_stop_query_timer("DBU_fetch_cerpaststs", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cerpaststs(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CERPASTSTS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 54;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1197;
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

    DB_stop_query_timer("DBU_close_cerpaststs", sel_type);
}


/* Initialize Function */
void DBU_init_cerpaststs(struct CERPASTSTS_TAG *CERPASTSTS)
{
    /* memset by Space */
    memset(CERPASTSTS, ' ', sizeof(struct CERPASTSTS_TAG));
    
}


/* Add Null Function */
void DBU_add_null_cerpaststs(struct CERPASTSTS_N_TAG *CERPASTSTS_N, struct CERPASTSTS_TAG *CERPASTSTS)
{
    /* memset by NULL */
    memset(CERPASTSTS_N, '\0', sizeof(struct CERPASTSTS_N_TAG));
    
    MEMCPY_AN(CERPASTSTS_N->FACTORY, CERPASTSTS->FACTORY, sizeof(CERPASTSTS->FACTORY));
    MEMCPY_AN(CERPASTSTS_N->BOOK_TYPE_CODE, CERPASTSTS->BOOK_TYPE_CODE, sizeof(CERPASTSTS->BOOK_TYPE_CODE));
    MEMCPY_AN(CERPASTSTS_N->ASSET_NUMBER, CERPASTSTS->ASSET_NUMBER, sizeof(CERPASTSTS->ASSET_NUMBER));
    MEMCPY_AN(CERPASTSTS_N->ASSET_NAME, CERPASTSTS->ASSET_NAME, sizeof(CERPASTSTS->ASSET_NAME));
    MEMCPY_AN(CERPASTSTS_N->ATTRIBUTE_CATEGORY_CODE, CERPASTSTS->ATTRIBUTE_CATEGORY_CODE, sizeof(CERPASTSTS->ATTRIBUTE_CATEGORY_CODE));
    MEMCPY_AN(CERPASTSTS_N->CATEGORY_CODE, CERPASTSTS->CATEGORY_CODE, sizeof(CERPASTSTS->CATEGORY_CODE));
    MEMCPY_AN(CERPASTSTS_N->CURRENT_UNITS, CERPASTSTS->CURRENT_UNITS, sizeof(CERPASTSTS->CURRENT_UNITS));
    MEMCPY_AN(CERPASTSTS_N->ORIGINAL_COST, CERPASTSTS->ORIGINAL_COST, sizeof(CERPASTSTS->ORIGINAL_COST));
    MEMCPY_AN(CERPASTSTS_N->DATE_PLACED_IN_SERVICE, CERPASTSTS->DATE_PLACED_IN_SERVICE, sizeof(CERPASTSTS->DATE_PLACED_IN_SERVICE));
    MEMCPY_AN(CERPASTSTS_N->OPERATING_UNIT_SEG, CERPASTSTS->OPERATING_UNIT_SEG, sizeof(CERPASTSTS->OPERATING_UNIT_SEG));
    MEMCPY_AN(CERPASTSTS_N->OPERATING_UNIT, CERPASTSTS->OPERATING_UNIT, sizeof(CERPASTSTS->OPERATING_UNIT));
    MEMCPY_AN(CERPASTSTS_N->DEPARTMENT_SEG, CERPASTSTS->DEPARTMENT_SEG, sizeof(CERPASTSTS->DEPARTMENT_SEG));
    MEMCPY_AN(CERPASTSTS_N->DEPARTMENTS, CERPASTSTS->DEPARTMENTS, sizeof(CERPASTSTS->DEPARTMENTS));
    MEMCPY_AN(CERPASTSTS_N->PRODUCT_FAMILY_SEG, CERPASTSTS->PRODUCT_FAMILY_SEG, sizeof(CERPASTSTS->PRODUCT_FAMILY_SEG));
    MEMCPY_AN(CERPASTSTS_N->PRODUCT_FAMILY, CERPASTSTS->PRODUCT_FAMILY, sizeof(CERPASTSTS->PRODUCT_FAMILY));
    MEMCPY_AN(CERPASTSTS_N->BUSINESS_UNIT, CERPASTSTS->BUSINESS_UNIT, sizeof(CERPASTSTS->BUSINESS_UNIT));
    MEMCPY_AN(CERPASTSTS_N->TAG_NUMBER, CERPASTSTS->TAG_NUMBER, sizeof(CERPASTSTS->TAG_NUMBER));
    MEMCPY_AN(CERPASTSTS_N->SERIAL_NUMBER, CERPASTSTS->SERIAL_NUMBER, sizeof(CERPASTSTS->SERIAL_NUMBER));
    MEMCPY_AN(CERPASTSTS_N->MANUFACTURER_NAME, CERPASTSTS->MANUFACTURER_NAME, sizeof(CERPASTSTS->MANUFACTURER_NAME));
    MEMCPY_AN(CERPASTSTS_N->MODEL_NUMBER, CERPASTSTS->MODEL_NUMBER, sizeof(CERPASTSTS->MODEL_NUMBER));
    MEMCPY_AN(CERPASTSTS_N->EMPLOYEE_NUMBER, CERPASTSTS->EMPLOYEE_NUMBER, sizeof(CERPASTSTS->EMPLOYEE_NUMBER));
    MEMCPY_AN(CERPASTSTS_N->EMPLOYEE_NAME, CERPASTSTS->EMPLOYEE_NAME, sizeof(CERPASTSTS->EMPLOYEE_NAME));
    MEMCPY_AN(CERPASTSTS_N->IN_USE_FLAG, CERPASTSTS->IN_USE_FLAG, sizeof(CERPASTSTS->IN_USE_FLAG));
    MEMCPY_AN(CERPASTSTS_N->PRORATE_DATE, CERPASTSTS->PRORATE_DATE, sizeof(CERPASTSTS->PRORATE_DATE));
    MEMCPY_AN(CERPASTSTS_N->LOCATION_ID, CERPASTSTS->LOCATION_ID, sizeof(CERPASTSTS->LOCATION_ID));
    MEMCPY_AN(CERPASTSTS_N->LOCATION_DESCRIPTION, CERPASTSTS->LOCATION_DESCRIPTION, sizeof(CERPASTSTS->LOCATION_DESCRIPTION));
    MEMCPY_AN(CERPASTSTS_N->DEPRN_METHOD_CODE, CERPASTSTS->DEPRN_METHOD_CODE, sizeof(CERPASTSTS->DEPRN_METHOD_CODE));
    MEMCPY_AN(CERPASTSTS_N->PLC, CERPASTSTS->PLC, sizeof(CERPASTSTS->PLC));
    MEMCPY_AN(CERPASTSTS_N->PURCHASING_DATE, CERPASTSTS->PURCHASING_DATE, sizeof(CERPASTSTS->PURCHASING_DATE));
    MEMCPY_AN(CERPASTSTS_N->CONFIRMATION_DATE, CERPASTSTS->CONFIRMATION_DATE, sizeof(CERPASTSTS->CONFIRMATION_DATE));
    MEMCPY_AN(CERPASTSTS_N->CONFIRMED_PLC, CERPASTSTS->CONFIRMED_PLC, sizeof(CERPASTSTS->CONFIRMED_PLC));
    MEMCPY_AN(CERPASTSTS_N->RES_ID, CERPASTSTS->RES_ID, sizeof(CERPASTSTS->RES_ID));
    MEMCPY_AN(CERPASTSTS_N->CMF_1, CERPASTSTS->CMF_1, sizeof(CERPASTSTS->CMF_1));
    MEMCPY_AN(CERPASTSTS_N->CMF_2, CERPASTSTS->CMF_2, sizeof(CERPASTSTS->CMF_2));
    MEMCPY_AN(CERPASTSTS_N->CMF_3, CERPASTSTS->CMF_3, sizeof(CERPASTSTS->CMF_3));
    MEMCPY_AN(CERPASTSTS_N->CMF_4, CERPASTSTS->CMF_4, sizeof(CERPASTSTS->CMF_4));
    MEMCPY_AN(CERPASTSTS_N->CMF_5, CERPASTSTS->CMF_5, sizeof(CERPASTSTS->CMF_5));
    MEMCPY_AN(CERPASTSTS_N->CMF_6, CERPASTSTS->CMF_6, sizeof(CERPASTSTS->CMF_6));
    MEMCPY_AN(CERPASTSTS_N->CMF_7, CERPASTSTS->CMF_7, sizeof(CERPASTSTS->CMF_7));
    MEMCPY_AN(CERPASTSTS_N->CMF_8, CERPASTSTS->CMF_8, sizeof(CERPASTSTS->CMF_8));
    MEMCPY_AN(CERPASTSTS_N->CMF_9, CERPASTSTS->CMF_9, sizeof(CERPASTSTS->CMF_9));
    MEMCPY_AN(CERPASTSTS_N->CMF_10, CERPASTSTS->CMF_10, sizeof(CERPASTSTS->CMF_10));
    MEMCPY_AN(CERPASTSTS_N->CMF_11, CERPASTSTS->CMF_11, sizeof(CERPASTSTS->CMF_11));
    MEMCPY_AN(CERPASTSTS_N->CMF_12, CERPASTSTS->CMF_12, sizeof(CERPASTSTS->CMF_12));
    MEMCPY_AN(CERPASTSTS_N->CMF_13, CERPASTSTS->CMF_13, sizeof(CERPASTSTS->CMF_13));
    MEMCPY_AN(CERPASTSTS_N->CMF_14, CERPASTSTS->CMF_14, sizeof(CERPASTSTS->CMF_14));
    MEMCPY_AN(CERPASTSTS_N->CMF_15, CERPASTSTS->CMF_15, sizeof(CERPASTSTS->CMF_15));
    MEMCPY_AN(CERPASTSTS_N->CREATE_USER_ID, CERPASTSTS->CREATE_USER_ID, sizeof(CERPASTSTS->CREATE_USER_ID));
    MEMCPY_AN(CERPASTSTS_N->CREATE_TIME, CERPASTSTS->CREATE_TIME, sizeof(CERPASTSTS->CREATE_TIME));
    MEMCPY_AN(CERPASTSTS_N->UPDATE_USER_ID, CERPASTSTS->UPDATE_USER_ID, sizeof(CERPASTSTS->UPDATE_USER_ID));
    MEMCPY_AN(CERPASTSTS_N->UPDATE_TIME, CERPASTSTS->UPDATE_TIME, sizeof(CERPASTSTS->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_cerpaststs(struct CERPASTSTS_N_TAG *CERPASTSTS_N, struct CERPASTSTS_TAG *CERPASTSTS)
{
    MEMCPY_DN(CERPASTSTS->FACTORY, CERPASTSTS_N->FACTORY, sizeof(CERPASTSTS->FACTORY));
    MEMCPY_DN(CERPASTSTS->BOOK_TYPE_CODE, CERPASTSTS_N->BOOK_TYPE_CODE, sizeof(CERPASTSTS->BOOK_TYPE_CODE));
    MEMCPY_DN(CERPASTSTS->ASSET_NUMBER, CERPASTSTS_N->ASSET_NUMBER, sizeof(CERPASTSTS->ASSET_NUMBER));
    MEMCPY_DN(CERPASTSTS->ASSET_NAME, CERPASTSTS_N->ASSET_NAME, sizeof(CERPASTSTS->ASSET_NAME));
    MEMCPY_DN(CERPASTSTS->ATTRIBUTE_CATEGORY_CODE, CERPASTSTS_N->ATTRIBUTE_CATEGORY_CODE, sizeof(CERPASTSTS->ATTRIBUTE_CATEGORY_CODE));
    MEMCPY_DN(CERPASTSTS->CATEGORY_CODE, CERPASTSTS_N->CATEGORY_CODE, sizeof(CERPASTSTS->CATEGORY_CODE));
    MEMCPY_DN(CERPASTSTS->CURRENT_UNITS, CERPASTSTS_N->CURRENT_UNITS, sizeof(CERPASTSTS->CURRENT_UNITS));
    MEMCPY_DN(CERPASTSTS->ORIGINAL_COST, CERPASTSTS_N->ORIGINAL_COST, sizeof(CERPASTSTS->ORIGINAL_COST));
    MEMCPY_DN(CERPASTSTS->DATE_PLACED_IN_SERVICE, CERPASTSTS_N->DATE_PLACED_IN_SERVICE, sizeof(CERPASTSTS->DATE_PLACED_IN_SERVICE));
    MEMCPY_DN(CERPASTSTS->OPERATING_UNIT_SEG, CERPASTSTS_N->OPERATING_UNIT_SEG, sizeof(CERPASTSTS->OPERATING_UNIT_SEG));
    MEMCPY_DN(CERPASTSTS->OPERATING_UNIT, CERPASTSTS_N->OPERATING_UNIT, sizeof(CERPASTSTS->OPERATING_UNIT));
    MEMCPY_DN(CERPASTSTS->DEPARTMENT_SEG, CERPASTSTS_N->DEPARTMENT_SEG, sizeof(CERPASTSTS->DEPARTMENT_SEG));
    MEMCPY_DN(CERPASTSTS->DEPARTMENTS, CERPASTSTS_N->DEPARTMENTS, sizeof(CERPASTSTS->DEPARTMENTS));
    MEMCPY_DN(CERPASTSTS->PRODUCT_FAMILY_SEG, CERPASTSTS_N->PRODUCT_FAMILY_SEG, sizeof(CERPASTSTS->PRODUCT_FAMILY_SEG));
    MEMCPY_DN(CERPASTSTS->PRODUCT_FAMILY, CERPASTSTS_N->PRODUCT_FAMILY, sizeof(CERPASTSTS->PRODUCT_FAMILY));
    MEMCPY_DN(CERPASTSTS->BUSINESS_UNIT, CERPASTSTS_N->BUSINESS_UNIT, sizeof(CERPASTSTS->BUSINESS_UNIT));
    MEMCPY_DN(CERPASTSTS->TAG_NUMBER, CERPASTSTS_N->TAG_NUMBER, sizeof(CERPASTSTS->TAG_NUMBER));
    MEMCPY_DN(CERPASTSTS->SERIAL_NUMBER, CERPASTSTS_N->SERIAL_NUMBER, sizeof(CERPASTSTS->SERIAL_NUMBER));
    MEMCPY_DN(CERPASTSTS->MANUFACTURER_NAME, CERPASTSTS_N->MANUFACTURER_NAME, sizeof(CERPASTSTS->MANUFACTURER_NAME));
    MEMCPY_DN(CERPASTSTS->MODEL_NUMBER, CERPASTSTS_N->MODEL_NUMBER, sizeof(CERPASTSTS->MODEL_NUMBER));
    MEMCPY_DN(CERPASTSTS->EMPLOYEE_NUMBER, CERPASTSTS_N->EMPLOYEE_NUMBER, sizeof(CERPASTSTS->EMPLOYEE_NUMBER));
    MEMCPY_DN(CERPASTSTS->EMPLOYEE_NAME, CERPASTSTS_N->EMPLOYEE_NAME, sizeof(CERPASTSTS->EMPLOYEE_NAME));
    MEMCPY_DN(CERPASTSTS->IN_USE_FLAG, CERPASTSTS_N->IN_USE_FLAG, sizeof(CERPASTSTS->IN_USE_FLAG));
    MEMCPY_DN(CERPASTSTS->PRORATE_DATE, CERPASTSTS_N->PRORATE_DATE, sizeof(CERPASTSTS->PRORATE_DATE));
    MEMCPY_DN(CERPASTSTS->LOCATION_ID, CERPASTSTS_N->LOCATION_ID, sizeof(CERPASTSTS->LOCATION_ID));
    MEMCPY_DN(CERPASTSTS->LOCATION_DESCRIPTION, CERPASTSTS_N->LOCATION_DESCRIPTION, sizeof(CERPASTSTS->LOCATION_DESCRIPTION));
    MEMCPY_DN(CERPASTSTS->DEPRN_METHOD_CODE, CERPASTSTS_N->DEPRN_METHOD_CODE, sizeof(CERPASTSTS->DEPRN_METHOD_CODE));
    MEMCPY_DN(CERPASTSTS->PLC, CERPASTSTS_N->PLC, sizeof(CERPASTSTS->PLC));
    MEMCPY_DN(CERPASTSTS->PURCHASING_DATE, CERPASTSTS_N->PURCHASING_DATE, sizeof(CERPASTSTS->PURCHASING_DATE));
    MEMCPY_DN(CERPASTSTS->CONFIRMATION_DATE, CERPASTSTS_N->CONFIRMATION_DATE, sizeof(CERPASTSTS->CONFIRMATION_DATE));
    MEMCPY_DN(CERPASTSTS->CONFIRMED_PLC, CERPASTSTS_N->CONFIRMED_PLC, sizeof(CERPASTSTS->CONFIRMED_PLC));
    MEMCPY_DN(CERPASTSTS->RES_ID, CERPASTSTS_N->RES_ID, sizeof(CERPASTSTS->RES_ID));
    MEMCPY_DN(CERPASTSTS->CMF_1, CERPASTSTS_N->CMF_1, sizeof(CERPASTSTS->CMF_1));
    MEMCPY_DN(CERPASTSTS->CMF_2, CERPASTSTS_N->CMF_2, sizeof(CERPASTSTS->CMF_2));
    MEMCPY_DN(CERPASTSTS->CMF_3, CERPASTSTS_N->CMF_3, sizeof(CERPASTSTS->CMF_3));
    MEMCPY_DN(CERPASTSTS->CMF_4, CERPASTSTS_N->CMF_4, sizeof(CERPASTSTS->CMF_4));
    MEMCPY_DN(CERPASTSTS->CMF_5, CERPASTSTS_N->CMF_5, sizeof(CERPASTSTS->CMF_5));
    MEMCPY_DN(CERPASTSTS->CMF_6, CERPASTSTS_N->CMF_6, sizeof(CERPASTSTS->CMF_6));
    MEMCPY_DN(CERPASTSTS->CMF_7, CERPASTSTS_N->CMF_7, sizeof(CERPASTSTS->CMF_7));
    MEMCPY_DN(CERPASTSTS->CMF_8, CERPASTSTS_N->CMF_8, sizeof(CERPASTSTS->CMF_8));
    MEMCPY_DN(CERPASTSTS->CMF_9, CERPASTSTS_N->CMF_9, sizeof(CERPASTSTS->CMF_9));
    MEMCPY_DN(CERPASTSTS->CMF_10, CERPASTSTS_N->CMF_10, sizeof(CERPASTSTS->CMF_10));
    MEMCPY_DN(CERPASTSTS->CMF_11, CERPASTSTS_N->CMF_11, sizeof(CERPASTSTS->CMF_11));
    MEMCPY_DN(CERPASTSTS->CMF_12, CERPASTSTS_N->CMF_12, sizeof(CERPASTSTS->CMF_12));
    MEMCPY_DN(CERPASTSTS->CMF_13, CERPASTSTS_N->CMF_13, sizeof(CERPASTSTS->CMF_13));
    MEMCPY_DN(CERPASTSTS->CMF_14, CERPASTSTS_N->CMF_14, sizeof(CERPASTSTS->CMF_14));
    MEMCPY_DN(CERPASTSTS->CMF_15, CERPASTSTS_N->CMF_15, sizeof(CERPASTSTS->CMF_15));
    MEMCPY_DN(CERPASTSTS->CREATE_USER_ID, CERPASTSTS_N->CREATE_USER_ID, sizeof(CERPASTSTS->CREATE_USER_ID));
    MEMCPY_DN(CERPASTSTS->CREATE_TIME, CERPASTSTS_N->CREATE_TIME, sizeof(CERPASTSTS->CREATE_TIME));
    MEMCPY_DN(CERPASTSTS->UPDATE_USER_ID, CERPASTSTS_N->UPDATE_USER_ID, sizeof(CERPASTSTS->UPDATE_USER_ID));
    MEMCPY_DN(CERPASTSTS->UPDATE_TIME, CERPASTSTS_N->UPDATE_TIME, sizeof(CERPASTSTS->UPDATE_TIME));
}


