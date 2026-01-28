
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
    "DBU_esecusrdef.pc"
};


static unsigned int sqlctx = 9389467;


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
            void  *sqhstv[43];
   unsigned int   sqhstl[43];
            int   sqhsts[43];
            void  *sqindv[43];
            int   sqinds[43];
   unsigned int   sqharm[43];
   unsigned int   *sqharc[43];
   unsigned short  sqadto[43];
   unsigned short  sqtdso[43];
} sqlstm = {13,43};

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

 static const char *sq0011 = 
"select FACTORY ,USER_ID ,USER_DESC ,PASSWORD ,CHG_PASS_FLAG ,USER_GRP_1 ,US\
ER_GRP_2 ,USER_GRP_3 ,USER_GRP_4 ,USER_GRP_5 ,USER_GRP_6 ,USER_GRP_7 ,USER_GR\
P_8 ,USER_GRP_9 ,USER_GRP_10 ,USER_CMF_1 ,USER_CMF_2 ,USER_CMF_3 ,USER_CMF_4 \
,USER_CMF_5 ,USER_CMF_6 ,USER_CMF_7 ,USER_CMF_8 ,USER_CMF_9 ,USER_CMF_10 ,SEC\
_GRP_ID ,PHONE_OFFICE ,PHONE_MOBILE ,PHONE_HOME ,PHONE_OTHER ,EXPIRE_DATE ,PA\
SS_EXPIRE_DATE ,ENTER_DATE ,RETIRE_DATE ,EMAIL_ID ,BIRTHDAY ,SEX_FLAG ,CREATE\
_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from ESECUSRDEF  order by\
 FACTORY asc ,USER_ID asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,763,0,4,46,0,0,43,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,1,97,0,0,1,97,0,0,
192,0,0,2,105,0,4,135,0,0,5,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,
0,
227,0,0,3,775,0,4,181,0,0,43,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,1,97,0,0,1,97,0,0,
414,0,0,4,78,0,4,307,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
441,0,0,5,60,0,2,344,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
464,0,0,6,60,0,2,349,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
487,0,0,7,692,0,3,380,0,0,41,41,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,
666,0,0,8,142,0,3,468,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,
709,0,0,9,693,0,5,514,0,0,41,41,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,
888,0,0,10,143,0,5,558,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,
931,0,0,11,575,0,9,642,0,0,0,0,0,1,0,
946,0,0,11,0,0,13,671,0,0,41,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,
1125,0,0,11,0,0,15,742,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_esecusrdef.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-11-25 23:39:43
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
void DBU_add_null_esecusrdef(struct ESECUSRDEF_N_TAG *ESECUSRDEF_N, struct ESECUSRDEF_TAG *ESECUSRDEF);
void DBU_del_null_esecusrdef(struct ESECUSRDEF_N_TAG *ESECUSRDEF_N, struct ESECUSRDEF_TAG *ESECUSRDEF);


/* SQL SELECT Function */
void DBU_select_esecusrdef(int sel_type, struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ESECUSRDEF_N_TAG ESECUSRDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_esecusrdef(&ESECUSRDEF_N, ESECUSRDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    USER_ID,
                    USER_DESC,
                    PASSWORD,
                    CHG_PASS_FLAG,
                    USER_GRP_1,
                    USER_GRP_2,
                    USER_GRP_3,
                    USER_GRP_4,
                    USER_GRP_5,
                    USER_GRP_6,
                    USER_GRP_7,
                    USER_GRP_8,
                    USER_GRP_9,
                    USER_GRP_10,
                    USER_CMF_1,
                    USER_CMF_2,
                    USER_CMF_3,
                    USER_CMF_4,
                    USER_CMF_5,
                    USER_CMF_6,
                    USER_CMF_7,
                    USER_CMF_8,
                    USER_CMF_9,
                    USER_CMF_10,
                    SEC_GRP_ID,
                    PHONE_OFFICE,
                    PHONE_MOBILE,
                    PHONE_HOME,
                    PHONE_OTHER,
                    EXPIRE_DATE,
                    PASS_EXPIRE_DATE,
                    ENTER_DATE,
                    RETIRE_DATE,
                    EMAIL_ID,
                    BIRTHDAY,
                    SEX_FLAG,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :ESECUSRDEF_N.FACTORY,
                    :ESECUSRDEF_N.USER_ID,
                    :ESECUSRDEF_N.USER_DESC,
                    :ESECUSRDEF_N.PASSWORD,
                    :ESECUSRDEF_N.CHG_PASS_FLAG,
                    :ESECUSRDEF_N.USER_GRP_1,
                    :ESECUSRDEF_N.USER_GRP_2,
                    :ESECUSRDEF_N.USER_GRP_3,
                    :ESECUSRDEF_N.USER_GRP_4,
                    :ESECUSRDEF_N.USER_GRP_5,
                    :ESECUSRDEF_N.USER_GRP_6,
                    :ESECUSRDEF_N.USER_GRP_7,
                    :ESECUSRDEF_N.USER_GRP_8,
                    :ESECUSRDEF_N.USER_GRP_9,
                    :ESECUSRDEF_N.USER_GRP_10,
                    :ESECUSRDEF_N.USER_CMF_1,
                    :ESECUSRDEF_N.USER_CMF_2,
                    :ESECUSRDEF_N.USER_CMF_3,
                    :ESECUSRDEF_N.USER_CMF_4,
                    :ESECUSRDEF_N.USER_CMF_5,
                    :ESECUSRDEF_N.USER_CMF_6,
                    :ESECUSRDEF_N.USER_CMF_7,
                    :ESECUSRDEF_N.USER_CMF_8,
                    :ESECUSRDEF_N.USER_CMF_9,
                    :ESECUSRDEF_N.USER_CMF_10,
                    :ESECUSRDEF_N.SEC_GRP_ID,
                    :ESECUSRDEF_N.PHONE_OFFICE,
                    :ESECUSRDEF_N.PHONE_MOBILE,
                    :ESECUSRDEF_N.PHONE_HOME,
                    :ESECUSRDEF_N.PHONE_OTHER,
                    :ESECUSRDEF_N.EXPIRE_DATE,
                    :ESECUSRDEF_N.PASS_EXPIRE_DATE,
                    :ESECUSRDEF_N.ENTER_DATE,
                    :ESECUSRDEF_N.RETIRE_DATE,
                    :ESECUSRDEF_N.EMAIL_ID,
                    :ESECUSRDEF_N.BIRTHDAY,
                    :ESECUSRDEF_N.SEX_FLAG,
                    :ESECUSRDEF_N.CREATE_USER_ID,
                    :ESECUSRDEF_N.CREATE_TIME,
                    :ESECUSRDEF_N.UPDATE_USER_ID,
                    :ESECUSRDEF_N.UPDATE_TIME
                FROM ESECUSRDEF
                WHERE FACTORY = :ESECUSRDEF_N.FACTORY
                    AND USER_ID = :ESECUSRDEF_N.USER_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,USER_ID ,USER_DESC ,PASSWORD ,CH\
G_PASS_FLAG ,USER_GRP_1 ,USER_GRP_2 ,USER_GRP_3 ,USER_GRP_4 ,USER_GRP_5 ,USER\
_GRP_6 ,USER_GRP_7 ,USER_GRP_8 ,USER_GRP_9 ,USER_GRP_10 ,USER_CMF_1 ,USER_CMF\
_2 ,USER_CMF_3 ,USER_CMF_4 ,USER_CMF_5 ,USER_CMF_6 ,USER_CMF_7 ,USER_CMF_8 ,U\
SER_CMF_9 ,USER_CMF_10 ,SEC_GRP_ID ,PHONE_OFFICE ,PHONE_MOBILE ,PHONE_HOME ,P\
HONE_OTHER ,EXPIRE_DATE ,PASS_EXPIRE_DATE ,ENTER_DATE ,RETIRE_DATE ,EMAIL_ID \
,BIRTHDAY ,SEX_FLAG ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME\
 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:\
b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b3\
1,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40  from ESECUSRDEF where (FACTOR\
Y=:b0 and USER_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ESECUSRDEF_N.USER_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ESECUSRDEF_N.PASSWORD);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ESECUSRDEF_N.CHG_PASS_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(ESECUSRDEF_N.USER_GRP_1);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(ESECUSRDEF_N.USER_GRP_2);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(ESECUSRDEF_N.USER_GRP_3);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(ESECUSRDEF_N.USER_GRP_4);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(ESECUSRDEF_N.USER_GRP_5);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(ESECUSRDEF_N.USER_GRP_6);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(ESECUSRDEF_N.USER_GRP_7);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(ESECUSRDEF_N.USER_GRP_8);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(ESECUSRDEF_N.USER_GRP_9);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(ESECUSRDEF_N.USER_GRP_10);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(ESECUSRDEF_N.USER_CMF_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(ESECUSRDEF_N.USER_CMF_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(ESECUSRDEF_N.USER_CMF_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(ESECUSRDEF_N.USER_CMF_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(ESECUSRDEF_N.USER_CMF_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(ESECUSRDEF_N.USER_CMF_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(ESECUSRDEF_N.USER_CMF_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(ESECUSRDEF_N.USER_CMF_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(ESECUSRDEF_N.USER_CMF_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(ESECUSRDEF_N.USER_CMF_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(ESECUSRDEF_N.SEC_GRP_ID);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(ESECUSRDEF_N.PHONE_OFFICE);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(ESECUSRDEF_N.PHONE_MOBILE);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(ESECUSRDEF_N.PHONE_HOME);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(ESECUSRDEF_N.PHONE_OTHER);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(ESECUSRDEF_N.EXPIRE_DATE);
            sqlstm.sqhstl[30] = (unsigned int  )9;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(ESECUSRDEF_N.PASS_EXPIRE_DATE);
            sqlstm.sqhstl[31] = (unsigned int  )9;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(ESECUSRDEF_N.ENTER_DATE);
            sqlstm.sqhstl[32] = (unsigned int  )9;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(ESECUSRDEF_N.RETIRE_DATE);
            sqlstm.sqhstl[33] = (unsigned int  )9;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(ESECUSRDEF_N.EMAIL_ID);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(ESECUSRDEF_N.BIRTHDAY);
            sqlstm.sqhstl[35] = (unsigned int  )9;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(ESECUSRDEF_N.SEX_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(ESECUSRDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(ESECUSRDEF_N.CREATE_TIME);
            sqlstm.sqhstl[38] = (unsigned int  )15;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(ESECUSRDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(ESECUSRDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[40] = (unsigned int  )15;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[41] = (unsigned int  )11;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(ESECUSRDEF_N.USER_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
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
                USER_ID,             
                SEC_GRP_ID
                INTO
                :ESECUSRDEF_N.FACTORY,
                :ESECUSRDEF_N.USER_ID,                
                :ESECUSRDEF_N.SEC_GRP_ID
                FROM ESECFACUSR
                WHERE FACTORY = :ESECUSRDEF_N.FACTORY
                AND USER_ID = :ESECUSRDEF_N.USER_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,USER_ID ,SEC_GRP_ID into :b0,:b1\
,:b2  from ESECFACUSR where (FACTORY=:b0 and USER_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )192;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ESECUSRDEF_N.SEC_GRP_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ESECUSRDEF_N.USER_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
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

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }


    if(DB_error_code == 0)
    {
        DBU_del_null_esecusrdef(&ESECUSRDEF_N, ESECUSRDEF);
    }

    DB_stop_query_timer("DBU_select_esecusrdef", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_esecusrdef_for_update(int sel_type, struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ESECUSRDEF_N_TAG ESECUSRDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_esecusrdef(&ESECUSRDEF_N, ESECUSRDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    USER_ID,
                    USER_DESC,
                    PASSWORD,
                    CHG_PASS_FLAG,
                    USER_GRP_1,
                    USER_GRP_2,
                    USER_GRP_3,
                    USER_GRP_4,
                    USER_GRP_5,
                    USER_GRP_6,
                    USER_GRP_7,
                    USER_GRP_8,
                    USER_GRP_9,
                    USER_GRP_10,
                    USER_CMF_1,
                    USER_CMF_2,
                    USER_CMF_3,
                    USER_CMF_4,
                    USER_CMF_5,
                    USER_CMF_6,
                    USER_CMF_7,
                    USER_CMF_8,
                    USER_CMF_9,
                    USER_CMF_10,
                    SEC_GRP_ID,
                    PHONE_OFFICE,
                    PHONE_MOBILE,
                    PHONE_HOME,
                    PHONE_OTHER,
                    EXPIRE_DATE,
                    PASS_EXPIRE_DATE,
                    ENTER_DATE,
                    RETIRE_DATE,
                    EMAIL_ID,
                    BIRTHDAY,
                    SEX_FLAG,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :ESECUSRDEF_N.FACTORY,
                    :ESECUSRDEF_N.USER_ID,
                    :ESECUSRDEF_N.USER_DESC,
                    :ESECUSRDEF_N.PASSWORD,
                    :ESECUSRDEF_N.CHG_PASS_FLAG,
                    :ESECUSRDEF_N.USER_GRP_1,
                    :ESECUSRDEF_N.USER_GRP_2,
                    :ESECUSRDEF_N.USER_GRP_3,
                    :ESECUSRDEF_N.USER_GRP_4,
                    :ESECUSRDEF_N.USER_GRP_5,
                    :ESECUSRDEF_N.USER_GRP_6,
                    :ESECUSRDEF_N.USER_GRP_7,
                    :ESECUSRDEF_N.USER_GRP_8,
                    :ESECUSRDEF_N.USER_GRP_9,
                    :ESECUSRDEF_N.USER_GRP_10,
                    :ESECUSRDEF_N.USER_CMF_1,
                    :ESECUSRDEF_N.USER_CMF_2,
                    :ESECUSRDEF_N.USER_CMF_3,
                    :ESECUSRDEF_N.USER_CMF_4,
                    :ESECUSRDEF_N.USER_CMF_5,
                    :ESECUSRDEF_N.USER_CMF_6,
                    :ESECUSRDEF_N.USER_CMF_7,
                    :ESECUSRDEF_N.USER_CMF_8,
                    :ESECUSRDEF_N.USER_CMF_9,
                    :ESECUSRDEF_N.USER_CMF_10,
                    :ESECUSRDEF_N.SEC_GRP_ID,
                    :ESECUSRDEF_N.PHONE_OFFICE,
                    :ESECUSRDEF_N.PHONE_MOBILE,
                    :ESECUSRDEF_N.PHONE_HOME,
                    :ESECUSRDEF_N.PHONE_OTHER,
                    :ESECUSRDEF_N.EXPIRE_DATE,
                    :ESECUSRDEF_N.PASS_EXPIRE_DATE,
                    :ESECUSRDEF_N.ENTER_DATE,
                    :ESECUSRDEF_N.RETIRE_DATE,
                    :ESECUSRDEF_N.EMAIL_ID,
                    :ESECUSRDEF_N.BIRTHDAY,
                    :ESECUSRDEF_N.SEX_FLAG,
                    :ESECUSRDEF_N.CREATE_USER_ID,
                    :ESECUSRDEF_N.CREATE_TIME,
                    :ESECUSRDEF_N.UPDATE_USER_ID,
                    :ESECUSRDEF_N.UPDATE_TIME
                FROM ESECUSRDEF
                WHERE FACTORY = :ESECUSRDEF_N.FACTORY
                    AND USER_ID = :ESECUSRDEF_N.USER_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,USER_ID ,USER_DESC ,PASSWORD ,CH\
G_PASS_FLAG ,USER_GRP_1 ,USER_GRP_2 ,USER_GRP_3 ,USER_GRP_4 ,USER_GRP_5 ,USER\
_GRP_6 ,USER_GRP_7 ,USER_GRP_8 ,USER_GRP_9 ,USER_GRP_10 ,USER_CMF_1 ,USER_CMF\
_2 ,USER_CMF_3 ,USER_CMF_4 ,USER_CMF_5 ,USER_CMF_6 ,USER_CMF_7 ,USER_CMF_8 ,U\
SER_CMF_9 ,USER_CMF_10 ,SEC_GRP_ID ,PHONE_OFFICE ,PHONE_MOBILE ,PHONE_HOME ,P\
HONE_OTHER ,EXPIRE_DATE ,PASS_EXPIRE_DATE ,ENTER_DATE ,RETIRE_DATE ,EMAIL_ID \
,BIRTHDAY ,SEX_FLAG ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME\
 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:\
b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b3\
1,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40  from ESECUSRDEF where (FACTOR\
Y=:b0 and USER_ID=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )227;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ESECUSRDEF_N.USER_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ESECUSRDEF_N.PASSWORD);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ESECUSRDEF_N.CHG_PASS_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(ESECUSRDEF_N.USER_GRP_1);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(ESECUSRDEF_N.USER_GRP_2);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(ESECUSRDEF_N.USER_GRP_3);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(ESECUSRDEF_N.USER_GRP_4);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(ESECUSRDEF_N.USER_GRP_5);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(ESECUSRDEF_N.USER_GRP_6);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(ESECUSRDEF_N.USER_GRP_7);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(ESECUSRDEF_N.USER_GRP_8);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(ESECUSRDEF_N.USER_GRP_9);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(ESECUSRDEF_N.USER_GRP_10);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(ESECUSRDEF_N.USER_CMF_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(ESECUSRDEF_N.USER_CMF_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(ESECUSRDEF_N.USER_CMF_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(ESECUSRDEF_N.USER_CMF_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(ESECUSRDEF_N.USER_CMF_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(ESECUSRDEF_N.USER_CMF_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(ESECUSRDEF_N.USER_CMF_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(ESECUSRDEF_N.USER_CMF_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(ESECUSRDEF_N.USER_CMF_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(ESECUSRDEF_N.USER_CMF_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(ESECUSRDEF_N.SEC_GRP_ID);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(ESECUSRDEF_N.PHONE_OFFICE);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(ESECUSRDEF_N.PHONE_MOBILE);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(ESECUSRDEF_N.PHONE_HOME);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(ESECUSRDEF_N.PHONE_OTHER);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(ESECUSRDEF_N.EXPIRE_DATE);
            sqlstm.sqhstl[30] = (unsigned int  )9;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(ESECUSRDEF_N.PASS_EXPIRE_DATE);
            sqlstm.sqhstl[31] = (unsigned int  )9;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(ESECUSRDEF_N.ENTER_DATE);
            sqlstm.sqhstl[32] = (unsigned int  )9;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(ESECUSRDEF_N.RETIRE_DATE);
            sqlstm.sqhstl[33] = (unsigned int  )9;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(ESECUSRDEF_N.EMAIL_ID);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(ESECUSRDEF_N.BIRTHDAY);
            sqlstm.sqhstl[35] = (unsigned int  )9;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(ESECUSRDEF_N.SEX_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(ESECUSRDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(ESECUSRDEF_N.CREATE_TIME);
            sqlstm.sqhstl[38] = (unsigned int  )15;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(ESECUSRDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(ESECUSRDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[40] = (unsigned int  )15;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[41] = (unsigned int  )11;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(ESECUSRDEF_N.USER_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
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
        DBU_del_null_esecusrdef(&ESECUSRDEF_N, ESECUSRDEF);
    }

    DB_stop_query_timer("DBU_select_esecusrdef_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_esecusrdef_scalar(int sel_type, struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ESECUSRDEF_N_TAG ESECUSRDEF_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_esecusrdef(&ESECUSRDEF_N, ESECUSRDEF);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM ESECUSRDEF
                WHERE FACTORY = :ESECUSRDEF_N.FACTORY
                    AND USER_ID = :ESECUSRDEF_N.USER_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from ESECUSRDEF where\
 (FACTORY=:b1 and USER_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )414;
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
            sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ESECUSRDEF_N.USER_ID);
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

    DB_stop_query_timer("DBU_select_esecusrdef_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_esecusrdef(int sel_type, struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ESECUSRDEF_N_TAG ESECUSRDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_esecusrdef(&ESECUSRDEF_N, ESECUSRDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM ESECUSRDEF
                WHERE FACTORY = :ESECUSRDEF_N.FACTORY
                    AND USER_ID = :ESECUSRDEF_N.USER_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from ESECUSRDEF  where (FACTORY=:b0 and \
USER_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )441;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.USER_ID);
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
        case 2:
            /* EXEC SQL DELETE FROM ESECFACUSR
                WHERE FACTORY = :ESECUSRDEF_N.FACTORY
                AND USER_ID = :ESECUSRDEF_N.USER_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from ESECFACUSR  where (FACTORY=:b0 and \
USER_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )464;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.USER_ID);
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

    DB_stop_query_timer("DBU_delete_esecusrdef", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_esecusrdef(int sel_type, struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ESECUSRDEF_N_TAG ESECUSRDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_esecusrdef(&ESECUSRDEF_N, ESECUSRDEF);
    DB_error_code = 0;

    switch (sel_type)
    {
         case 1:
             /* EXEC SQL INSERT INTO ESECUSRDEF( 
                        FACTORY, 
                        USER_ID, 
                        USER_DESC, 
                        PASSWORD, 
                        CHG_PASS_FLAG, 
                        USER_GRP_1, 
                        USER_GRP_2, 
                        USER_GRP_3, 
                        USER_GRP_4, 
                        USER_GRP_5, 
                        USER_GRP_6, 
                        USER_GRP_7, 
                        USER_GRP_8, 
                        USER_GRP_9, 
                        USER_GRP_10, 
                        USER_CMF_1, 
                        USER_CMF_2, 
                        USER_CMF_3, 
                        USER_CMF_4, 
                        USER_CMF_5, 
                        USER_CMF_6, 
                        USER_CMF_7, 
                        USER_CMF_8, 
                        USER_CMF_9, 
                        USER_CMF_10, 
                        SEC_GRP_ID, 
                        PHONE_OFFICE, 
                        PHONE_MOBILE, 
                        PHONE_HOME, 
                        PHONE_OTHER, 
                        EXPIRE_DATE, 
                        PASS_EXPIRE_DATE, 
                        ENTER_DATE, 
                        RETIRE_DATE, 
                        EMAIL_ID, 
                        BIRTHDAY, 
                        SEX_FLAG, 
                        CREATE_USER_ID, 
                        CREATE_TIME, 
                        UPDATE_USER_ID, 
                        UPDATE_TIME
             ) 
            VALUES (
                        :ESECUSRDEF_N.FACTORY,
                        :ESECUSRDEF_N.USER_ID,
                        :ESECUSRDEF_N.USER_DESC,
                        :ESECUSRDEF_N.PASSWORD,
                        :ESECUSRDEF_N.CHG_PASS_FLAG,
                        :ESECUSRDEF_N.USER_GRP_1,
                        :ESECUSRDEF_N.USER_GRP_2,
                        :ESECUSRDEF_N.USER_GRP_3,
                        :ESECUSRDEF_N.USER_GRP_4,
                        :ESECUSRDEF_N.USER_GRP_5,
                        :ESECUSRDEF_N.USER_GRP_6,
                        :ESECUSRDEF_N.USER_GRP_7,
                        :ESECUSRDEF_N.USER_GRP_8,
                        :ESECUSRDEF_N.USER_GRP_9,
                        :ESECUSRDEF_N.USER_GRP_10,
                        :ESECUSRDEF_N.USER_CMF_1,
                        :ESECUSRDEF_N.USER_CMF_2,
                        :ESECUSRDEF_N.USER_CMF_3,
                        :ESECUSRDEF_N.USER_CMF_4,
                        :ESECUSRDEF_N.USER_CMF_5,
                        :ESECUSRDEF_N.USER_CMF_6,
                        :ESECUSRDEF_N.USER_CMF_7,
                        :ESECUSRDEF_N.USER_CMF_8,
                        :ESECUSRDEF_N.USER_CMF_9,
                        :ESECUSRDEF_N.USER_CMF_10,
                        :ESECUSRDEF_N.SEC_GRP_ID,
                        :ESECUSRDEF_N.PHONE_OFFICE,
                        :ESECUSRDEF_N.PHONE_MOBILE,
                        :ESECUSRDEF_N.PHONE_HOME,
                        :ESECUSRDEF_N.PHONE_OTHER,
                        :ESECUSRDEF_N.EXPIRE_DATE,
                        :ESECUSRDEF_N.PASS_EXPIRE_DATE,
                        :ESECUSRDEF_N.ENTER_DATE,
                        :ESECUSRDEF_N.RETIRE_DATE,
                        :ESECUSRDEF_N.EMAIL_ID,
                        :ESECUSRDEF_N.BIRTHDAY,
                        :ESECUSRDEF_N.SEX_FLAG,
                        :ESECUSRDEF_N.CREATE_USER_ID,
                        :ESECUSRDEF_N.CREATE_TIME,
                        :ESECUSRDEF_N.UPDATE_USER_ID,
                        :ESECUSRDEF_N.UPDATE_TIME
             ); */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 13;
             sqlstm.arrsiz = 43;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = "insert into ESECUSRDEF (FACTORY,USER_ID,USER_DE\
SC,PASSWORD,CHG_PASS_FLAG,USER_GRP_1,USER_GRP_2,USER_GRP_3,USER_GRP_4,USER_GR\
P_5,USER_GRP_6,USER_GRP_7,USER_GRP_8,USER_GRP_9,USER_GRP_10,USER_CMF_1,USER_C\
MF_2,USER_CMF_3,USER_CMF_4,USER_CMF_5,USER_CMF_6,USER_CMF_7,USER_CMF_8,USER_C\
MF_9,USER_CMF_10,SEC_GRP_ID,PHONE_OFFICE,PHONE_MOBILE,PHONE_HOME,PHONE_OTHER,\
EXPIRE_DATE,PASS_EXPIRE_DATE,ENTER_DATE,RETIRE_DATE,EMAIL_ID,BIRTHDAY,SEX_FLA\
G,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) values (:b0,:b1,:b2,\
:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19\
,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:\
b35,:b36,:b37,:b38,:b39,:b40)";
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )487;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqhstv[0] = (         void  *)(ESECUSRDEF_N.FACTORY);
             sqlstm.sqhstl[0] = (unsigned int  )11;
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         void  *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned int  )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.USER_ID);
             sqlstm.sqhstl[1] = (unsigned int  )21;
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         void  *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned int  )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
             sqlstm.sqhstv[2] = (         void  *)(ESECUSRDEF_N.USER_DESC);
             sqlstm.sqhstl[2] = (unsigned int  )201;
             sqlstm.sqhsts[2] = (         int  )0;
             sqlstm.sqindv[2] = (         void  *)0;
             sqlstm.sqinds[2] = (         int  )0;
             sqlstm.sqharm[2] = (unsigned int  )0;
             sqlstm.sqadto[2] = (unsigned short )0;
             sqlstm.sqtdso[2] = (unsigned short )0;
             sqlstm.sqhstv[3] = (         void  *)(ESECUSRDEF_N.PASSWORD);
             sqlstm.sqhstl[3] = (unsigned int  )21;
             sqlstm.sqhsts[3] = (         int  )0;
             sqlstm.sqindv[3] = (         void  *)0;
             sqlstm.sqinds[3] = (         int  )0;
             sqlstm.sqharm[3] = (unsigned int  )0;
             sqlstm.sqadto[3] = (unsigned short )0;
             sqlstm.sqtdso[3] = (unsigned short )0;
             sqlstm.sqhstv[4] = (         void  *)(ESECUSRDEF_N.CHG_PASS_FLAG);
             sqlstm.sqhstl[4] = (unsigned int  )2;
             sqlstm.sqhsts[4] = (         int  )0;
             sqlstm.sqindv[4] = (         void  *)0;
             sqlstm.sqinds[4] = (         int  )0;
             sqlstm.sqharm[4] = (unsigned int  )0;
             sqlstm.sqadto[4] = (unsigned short )0;
             sqlstm.sqtdso[4] = (unsigned short )0;
             sqlstm.sqhstv[5] = (         void  *)(ESECUSRDEF_N.USER_GRP_1);
             sqlstm.sqhstl[5] = (unsigned int  )31;
             sqlstm.sqhsts[5] = (         int  )0;
             sqlstm.sqindv[5] = (         void  *)0;
             sqlstm.sqinds[5] = (         int  )0;
             sqlstm.sqharm[5] = (unsigned int  )0;
             sqlstm.sqadto[5] = (unsigned short )0;
             sqlstm.sqtdso[5] = (unsigned short )0;
             sqlstm.sqhstv[6] = (         void  *)(ESECUSRDEF_N.USER_GRP_2);
             sqlstm.sqhstl[6] = (unsigned int  )31;
             sqlstm.sqhsts[6] = (         int  )0;
             sqlstm.sqindv[6] = (         void  *)0;
             sqlstm.sqinds[6] = (         int  )0;
             sqlstm.sqharm[6] = (unsigned int  )0;
             sqlstm.sqadto[6] = (unsigned short )0;
             sqlstm.sqtdso[6] = (unsigned short )0;
             sqlstm.sqhstv[7] = (         void  *)(ESECUSRDEF_N.USER_GRP_3);
             sqlstm.sqhstl[7] = (unsigned int  )31;
             sqlstm.sqhsts[7] = (         int  )0;
             sqlstm.sqindv[7] = (         void  *)0;
             sqlstm.sqinds[7] = (         int  )0;
             sqlstm.sqharm[7] = (unsigned int  )0;
             sqlstm.sqadto[7] = (unsigned short )0;
             sqlstm.sqtdso[7] = (unsigned short )0;
             sqlstm.sqhstv[8] = (         void  *)(ESECUSRDEF_N.USER_GRP_4);
             sqlstm.sqhstl[8] = (unsigned int  )31;
             sqlstm.sqhsts[8] = (         int  )0;
             sqlstm.sqindv[8] = (         void  *)0;
             sqlstm.sqinds[8] = (         int  )0;
             sqlstm.sqharm[8] = (unsigned int  )0;
             sqlstm.sqadto[8] = (unsigned short )0;
             sqlstm.sqtdso[8] = (unsigned short )0;
             sqlstm.sqhstv[9] = (         void  *)(ESECUSRDEF_N.USER_GRP_5);
             sqlstm.sqhstl[9] = (unsigned int  )31;
             sqlstm.sqhsts[9] = (         int  )0;
             sqlstm.sqindv[9] = (         void  *)0;
             sqlstm.sqinds[9] = (         int  )0;
             sqlstm.sqharm[9] = (unsigned int  )0;
             sqlstm.sqadto[9] = (unsigned short )0;
             sqlstm.sqtdso[9] = (unsigned short )0;
             sqlstm.sqhstv[10] = (         void  *)(ESECUSRDEF_N.USER_GRP_6);
             sqlstm.sqhstl[10] = (unsigned int  )31;
             sqlstm.sqhsts[10] = (         int  )0;
             sqlstm.sqindv[10] = (         void  *)0;
             sqlstm.sqinds[10] = (         int  )0;
             sqlstm.sqharm[10] = (unsigned int  )0;
             sqlstm.sqadto[10] = (unsigned short )0;
             sqlstm.sqtdso[10] = (unsigned short )0;
             sqlstm.sqhstv[11] = (         void  *)(ESECUSRDEF_N.USER_GRP_7);
             sqlstm.sqhstl[11] = (unsigned int  )31;
             sqlstm.sqhsts[11] = (         int  )0;
             sqlstm.sqindv[11] = (         void  *)0;
             sqlstm.sqinds[11] = (         int  )0;
             sqlstm.sqharm[11] = (unsigned int  )0;
             sqlstm.sqadto[11] = (unsigned short )0;
             sqlstm.sqtdso[11] = (unsigned short )0;
             sqlstm.sqhstv[12] = (         void  *)(ESECUSRDEF_N.USER_GRP_8);
             sqlstm.sqhstl[12] = (unsigned int  )31;
             sqlstm.sqhsts[12] = (         int  )0;
             sqlstm.sqindv[12] = (         void  *)0;
             sqlstm.sqinds[12] = (         int  )0;
             sqlstm.sqharm[12] = (unsigned int  )0;
             sqlstm.sqadto[12] = (unsigned short )0;
             sqlstm.sqtdso[12] = (unsigned short )0;
             sqlstm.sqhstv[13] = (         void  *)(ESECUSRDEF_N.USER_GRP_9);
             sqlstm.sqhstl[13] = (unsigned int  )31;
             sqlstm.sqhsts[13] = (         int  )0;
             sqlstm.sqindv[13] = (         void  *)0;
             sqlstm.sqinds[13] = (         int  )0;
             sqlstm.sqharm[13] = (unsigned int  )0;
             sqlstm.sqadto[13] = (unsigned short )0;
             sqlstm.sqtdso[13] = (unsigned short )0;
             sqlstm.sqhstv[14] = (         void  *)(ESECUSRDEF_N.USER_GRP_10);
             sqlstm.sqhstl[14] = (unsigned int  )31;
             sqlstm.sqhsts[14] = (         int  )0;
             sqlstm.sqindv[14] = (         void  *)0;
             sqlstm.sqinds[14] = (         int  )0;
             sqlstm.sqharm[14] = (unsigned int  )0;
             sqlstm.sqadto[14] = (unsigned short )0;
             sqlstm.sqtdso[14] = (unsigned short )0;
             sqlstm.sqhstv[15] = (         void  *)(ESECUSRDEF_N.USER_CMF_1);
             sqlstm.sqhstl[15] = (unsigned int  )31;
             sqlstm.sqhsts[15] = (         int  )0;
             sqlstm.sqindv[15] = (         void  *)0;
             sqlstm.sqinds[15] = (         int  )0;
             sqlstm.sqharm[15] = (unsigned int  )0;
             sqlstm.sqadto[15] = (unsigned short )0;
             sqlstm.sqtdso[15] = (unsigned short )0;
             sqlstm.sqhstv[16] = (         void  *)(ESECUSRDEF_N.USER_CMF_2);
             sqlstm.sqhstl[16] = (unsigned int  )31;
             sqlstm.sqhsts[16] = (         int  )0;
             sqlstm.sqindv[16] = (         void  *)0;
             sqlstm.sqinds[16] = (         int  )0;
             sqlstm.sqharm[16] = (unsigned int  )0;
             sqlstm.sqadto[16] = (unsigned short )0;
             sqlstm.sqtdso[16] = (unsigned short )0;
             sqlstm.sqhstv[17] = (         void  *)(ESECUSRDEF_N.USER_CMF_3);
             sqlstm.sqhstl[17] = (unsigned int  )31;
             sqlstm.sqhsts[17] = (         int  )0;
             sqlstm.sqindv[17] = (         void  *)0;
             sqlstm.sqinds[17] = (         int  )0;
             sqlstm.sqharm[17] = (unsigned int  )0;
             sqlstm.sqadto[17] = (unsigned short )0;
             sqlstm.sqtdso[17] = (unsigned short )0;
             sqlstm.sqhstv[18] = (         void  *)(ESECUSRDEF_N.USER_CMF_4);
             sqlstm.sqhstl[18] = (unsigned int  )31;
             sqlstm.sqhsts[18] = (         int  )0;
             sqlstm.sqindv[18] = (         void  *)0;
             sqlstm.sqinds[18] = (         int  )0;
             sqlstm.sqharm[18] = (unsigned int  )0;
             sqlstm.sqadto[18] = (unsigned short )0;
             sqlstm.sqtdso[18] = (unsigned short )0;
             sqlstm.sqhstv[19] = (         void  *)(ESECUSRDEF_N.USER_CMF_5);
             sqlstm.sqhstl[19] = (unsigned int  )31;
             sqlstm.sqhsts[19] = (         int  )0;
             sqlstm.sqindv[19] = (         void  *)0;
             sqlstm.sqinds[19] = (         int  )0;
             sqlstm.sqharm[19] = (unsigned int  )0;
             sqlstm.sqadto[19] = (unsigned short )0;
             sqlstm.sqtdso[19] = (unsigned short )0;
             sqlstm.sqhstv[20] = (         void  *)(ESECUSRDEF_N.USER_CMF_6);
             sqlstm.sqhstl[20] = (unsigned int  )31;
             sqlstm.sqhsts[20] = (         int  )0;
             sqlstm.sqindv[20] = (         void  *)0;
             sqlstm.sqinds[20] = (         int  )0;
             sqlstm.sqharm[20] = (unsigned int  )0;
             sqlstm.sqadto[20] = (unsigned short )0;
             sqlstm.sqtdso[20] = (unsigned short )0;
             sqlstm.sqhstv[21] = (         void  *)(ESECUSRDEF_N.USER_CMF_7);
             sqlstm.sqhstl[21] = (unsigned int  )31;
             sqlstm.sqhsts[21] = (         int  )0;
             sqlstm.sqindv[21] = (         void  *)0;
             sqlstm.sqinds[21] = (         int  )0;
             sqlstm.sqharm[21] = (unsigned int  )0;
             sqlstm.sqadto[21] = (unsigned short )0;
             sqlstm.sqtdso[21] = (unsigned short )0;
             sqlstm.sqhstv[22] = (         void  *)(ESECUSRDEF_N.USER_CMF_8);
             sqlstm.sqhstl[22] = (unsigned int  )31;
             sqlstm.sqhsts[22] = (         int  )0;
             sqlstm.sqindv[22] = (         void  *)0;
             sqlstm.sqinds[22] = (         int  )0;
             sqlstm.sqharm[22] = (unsigned int  )0;
             sqlstm.sqadto[22] = (unsigned short )0;
             sqlstm.sqtdso[22] = (unsigned short )0;
             sqlstm.sqhstv[23] = (         void  *)(ESECUSRDEF_N.USER_CMF_9);
             sqlstm.sqhstl[23] = (unsigned int  )31;
             sqlstm.sqhsts[23] = (         int  )0;
             sqlstm.sqindv[23] = (         void  *)0;
             sqlstm.sqinds[23] = (         int  )0;
             sqlstm.sqharm[23] = (unsigned int  )0;
             sqlstm.sqadto[23] = (unsigned short )0;
             sqlstm.sqtdso[23] = (unsigned short )0;
             sqlstm.sqhstv[24] = (         void  *)(ESECUSRDEF_N.USER_CMF_10);
             sqlstm.sqhstl[24] = (unsigned int  )31;
             sqlstm.sqhsts[24] = (         int  )0;
             sqlstm.sqindv[24] = (         void  *)0;
             sqlstm.sqinds[24] = (         int  )0;
             sqlstm.sqharm[24] = (unsigned int  )0;
             sqlstm.sqadto[24] = (unsigned short )0;
             sqlstm.sqtdso[24] = (unsigned short )0;
             sqlstm.sqhstv[25] = (         void  *)(ESECUSRDEF_N.SEC_GRP_ID);
             sqlstm.sqhstl[25] = (unsigned int  )21;
             sqlstm.sqhsts[25] = (         int  )0;
             sqlstm.sqindv[25] = (         void  *)0;
             sqlstm.sqinds[25] = (         int  )0;
             sqlstm.sqharm[25] = (unsigned int  )0;
             sqlstm.sqadto[25] = (unsigned short )0;
             sqlstm.sqtdso[25] = (unsigned short )0;
             sqlstm.sqhstv[26] = (         void  *)(ESECUSRDEF_N.PHONE_OFFICE);
             sqlstm.sqhstl[26] = (unsigned int  )21;
             sqlstm.sqhsts[26] = (         int  )0;
             sqlstm.sqindv[26] = (         void  *)0;
             sqlstm.sqinds[26] = (         int  )0;
             sqlstm.sqharm[26] = (unsigned int  )0;
             sqlstm.sqadto[26] = (unsigned short )0;
             sqlstm.sqtdso[26] = (unsigned short )0;
             sqlstm.sqhstv[27] = (         void  *)(ESECUSRDEF_N.PHONE_MOBILE);
             sqlstm.sqhstl[27] = (unsigned int  )21;
             sqlstm.sqhsts[27] = (         int  )0;
             sqlstm.sqindv[27] = (         void  *)0;
             sqlstm.sqinds[27] = (         int  )0;
             sqlstm.sqharm[27] = (unsigned int  )0;
             sqlstm.sqadto[27] = (unsigned short )0;
             sqlstm.sqtdso[27] = (unsigned short )0;
             sqlstm.sqhstv[28] = (         void  *)(ESECUSRDEF_N.PHONE_HOME);
             sqlstm.sqhstl[28] = (unsigned int  )21;
             sqlstm.sqhsts[28] = (         int  )0;
             sqlstm.sqindv[28] = (         void  *)0;
             sqlstm.sqinds[28] = (         int  )0;
             sqlstm.sqharm[28] = (unsigned int  )0;
             sqlstm.sqadto[28] = (unsigned short )0;
             sqlstm.sqtdso[28] = (unsigned short )0;
             sqlstm.sqhstv[29] = (         void  *)(ESECUSRDEF_N.PHONE_OTHER);
             sqlstm.sqhstl[29] = (unsigned int  )21;
             sqlstm.sqhsts[29] = (         int  )0;
             sqlstm.sqindv[29] = (         void  *)0;
             sqlstm.sqinds[29] = (         int  )0;
             sqlstm.sqharm[29] = (unsigned int  )0;
             sqlstm.sqadto[29] = (unsigned short )0;
             sqlstm.sqtdso[29] = (unsigned short )0;
             sqlstm.sqhstv[30] = (         void  *)(ESECUSRDEF_N.EXPIRE_DATE);
             sqlstm.sqhstl[30] = (unsigned int  )9;
             sqlstm.sqhsts[30] = (         int  )0;
             sqlstm.sqindv[30] = (         void  *)0;
             sqlstm.sqinds[30] = (         int  )0;
             sqlstm.sqharm[30] = (unsigned int  )0;
             sqlstm.sqadto[30] = (unsigned short )0;
             sqlstm.sqtdso[30] = (unsigned short )0;
             sqlstm.sqhstv[31] = (         void  *)(ESECUSRDEF_N.PASS_EXPIRE_DATE);
             sqlstm.sqhstl[31] = (unsigned int  )9;
             sqlstm.sqhsts[31] = (         int  )0;
             sqlstm.sqindv[31] = (         void  *)0;
             sqlstm.sqinds[31] = (         int  )0;
             sqlstm.sqharm[31] = (unsigned int  )0;
             sqlstm.sqadto[31] = (unsigned short )0;
             sqlstm.sqtdso[31] = (unsigned short )0;
             sqlstm.sqhstv[32] = (         void  *)(ESECUSRDEF_N.ENTER_DATE);
             sqlstm.sqhstl[32] = (unsigned int  )9;
             sqlstm.sqhsts[32] = (         int  )0;
             sqlstm.sqindv[32] = (         void  *)0;
             sqlstm.sqinds[32] = (         int  )0;
             sqlstm.sqharm[32] = (unsigned int  )0;
             sqlstm.sqadto[32] = (unsigned short )0;
             sqlstm.sqtdso[32] = (unsigned short )0;
             sqlstm.sqhstv[33] = (         void  *)(ESECUSRDEF_N.RETIRE_DATE);
             sqlstm.sqhstl[33] = (unsigned int  )9;
             sqlstm.sqhsts[33] = (         int  )0;
             sqlstm.sqindv[33] = (         void  *)0;
             sqlstm.sqinds[33] = (         int  )0;
             sqlstm.sqharm[33] = (unsigned int  )0;
             sqlstm.sqadto[33] = (unsigned short )0;
             sqlstm.sqtdso[33] = (unsigned short )0;
             sqlstm.sqhstv[34] = (         void  *)(ESECUSRDEF_N.EMAIL_ID);
             sqlstm.sqhstl[34] = (unsigned int  )51;
             sqlstm.sqhsts[34] = (         int  )0;
             sqlstm.sqindv[34] = (         void  *)0;
             sqlstm.sqinds[34] = (         int  )0;
             sqlstm.sqharm[34] = (unsigned int  )0;
             sqlstm.sqadto[34] = (unsigned short )0;
             sqlstm.sqtdso[34] = (unsigned short )0;
             sqlstm.sqhstv[35] = (         void  *)(ESECUSRDEF_N.BIRTHDAY);
             sqlstm.sqhstl[35] = (unsigned int  )9;
             sqlstm.sqhsts[35] = (         int  )0;
             sqlstm.sqindv[35] = (         void  *)0;
             sqlstm.sqinds[35] = (         int  )0;
             sqlstm.sqharm[35] = (unsigned int  )0;
             sqlstm.sqadto[35] = (unsigned short )0;
             sqlstm.sqtdso[35] = (unsigned short )0;
             sqlstm.sqhstv[36] = (         void  *)(ESECUSRDEF_N.SEX_FLAG);
             sqlstm.sqhstl[36] = (unsigned int  )2;
             sqlstm.sqhsts[36] = (         int  )0;
             sqlstm.sqindv[36] = (         void  *)0;
             sqlstm.sqinds[36] = (         int  )0;
             sqlstm.sqharm[36] = (unsigned int  )0;
             sqlstm.sqadto[36] = (unsigned short )0;
             sqlstm.sqtdso[36] = (unsigned short )0;
             sqlstm.sqhstv[37] = (         void  *)(ESECUSRDEF_N.CREATE_USER_ID);
             sqlstm.sqhstl[37] = (unsigned int  )21;
             sqlstm.sqhsts[37] = (         int  )0;
             sqlstm.sqindv[37] = (         void  *)0;
             sqlstm.sqinds[37] = (         int  )0;
             sqlstm.sqharm[37] = (unsigned int  )0;
             sqlstm.sqadto[37] = (unsigned short )0;
             sqlstm.sqtdso[37] = (unsigned short )0;
             sqlstm.sqhstv[38] = (         void  *)(ESECUSRDEF_N.CREATE_TIME);
             sqlstm.sqhstl[38] = (unsigned int  )15;
             sqlstm.sqhsts[38] = (         int  )0;
             sqlstm.sqindv[38] = (         void  *)0;
             sqlstm.sqinds[38] = (         int  )0;
             sqlstm.sqharm[38] = (unsigned int  )0;
             sqlstm.sqadto[38] = (unsigned short )0;
             sqlstm.sqtdso[38] = (unsigned short )0;
             sqlstm.sqhstv[39] = (         void  *)(ESECUSRDEF_N.UPDATE_USER_ID);
             sqlstm.sqhstl[39] = (unsigned int  )21;
             sqlstm.sqhsts[39] = (         int  )0;
             sqlstm.sqindv[39] = (         void  *)0;
             sqlstm.sqinds[39] = (         int  )0;
             sqlstm.sqharm[39] = (unsigned int  )0;
             sqlstm.sqadto[39] = (unsigned short )0;
             sqlstm.sqtdso[39] = (unsigned short )0;
             sqlstm.sqhstv[40] = (         void  *)(ESECUSRDEF_N.UPDATE_TIME);
             sqlstm.sqhstl[40] = (unsigned int  )15;
             sqlstm.sqhsts[40] = (         int  )0;
             sqlstm.sqindv[40] = (         void  *)0;
             sqlstm.sqinds[40] = (         int  )0;
             sqlstm.sqharm[40] = (unsigned int  )0;
             sqlstm.sqadto[40] = (unsigned short )0;
             sqlstm.sqtdso[40] = (unsigned short )0;
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
             /* EXEC SQL INSERT INTO ESECFACUSR(
                 FACTORY,
                 USER_ID,              
                 SEC_GRP_ID,                
                 CREATE_USER_ID,
                 CREATE_TIME,
                 UPDATE_USER_ID,
                 UPDATE_TIME
             )
                 VALUES(
                     :ESECUSRDEF_N.FACTORY,
                     :ESECUSRDEF_N.USER_ID,                    
                     :ESECUSRDEF_N.SEC_GRP_ID,                    
                     :ESECUSRDEF_N.CREATE_USER_ID,
                     :ESECUSRDEF_N.CREATE_TIME,
                     :ESECUSRDEF_N.UPDATE_USER_ID,
                     :ESECUSRDEF_N.UPDATE_TIME
                 ); */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 13;
             sqlstm.arrsiz = 43;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = "insert into ESECFACUSR (FACTORY,USER_ID,SEC_GRP\
_ID,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) values (:b0,:b1,:b\
2,:b3,:b4,:b5,:b6)";
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )666;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqhstv[0] = (         void  *)(ESECUSRDEF_N.FACTORY);
             sqlstm.sqhstl[0] = (unsigned int  )11;
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         void  *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned int  )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.USER_ID);
             sqlstm.sqhstl[1] = (unsigned int  )21;
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         void  *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned int  )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
             sqlstm.sqhstv[2] = (         void  *)(ESECUSRDEF_N.SEC_GRP_ID);
             sqlstm.sqhstl[2] = (unsigned int  )21;
             sqlstm.sqhsts[2] = (         int  )0;
             sqlstm.sqindv[2] = (         void  *)0;
             sqlstm.sqinds[2] = (         int  )0;
             sqlstm.sqharm[2] = (unsigned int  )0;
             sqlstm.sqadto[2] = (unsigned short )0;
             sqlstm.sqtdso[2] = (unsigned short )0;
             sqlstm.sqhstv[3] = (         void  *)(ESECUSRDEF_N.CREATE_USER_ID);
             sqlstm.sqhstl[3] = (unsigned int  )21;
             sqlstm.sqhsts[3] = (         int  )0;
             sqlstm.sqindv[3] = (         void  *)0;
             sqlstm.sqinds[3] = (         int  )0;
             sqlstm.sqharm[3] = (unsigned int  )0;
             sqlstm.sqadto[3] = (unsigned short )0;
             sqlstm.sqtdso[3] = (unsigned short )0;
             sqlstm.sqhstv[4] = (         void  *)(ESECUSRDEF_N.CREATE_TIME);
             sqlstm.sqhstl[4] = (unsigned int  )15;
             sqlstm.sqhsts[4] = (         int  )0;
             sqlstm.sqindv[4] = (         void  *)0;
             sqlstm.sqinds[4] = (         int  )0;
             sqlstm.sqharm[4] = (unsigned int  )0;
             sqlstm.sqadto[4] = (unsigned short )0;
             sqlstm.sqtdso[4] = (unsigned short )0;
             sqlstm.sqhstv[5] = (         void  *)(ESECUSRDEF_N.UPDATE_USER_ID);
             sqlstm.sqhstl[5] = (unsigned int  )21;
             sqlstm.sqhsts[5] = (         int  )0;
             sqlstm.sqindv[5] = (         void  *)0;
             sqlstm.sqinds[5] = (         int  )0;
             sqlstm.sqharm[5] = (unsigned int  )0;
             sqlstm.sqadto[5] = (unsigned short )0;
             sqlstm.sqtdso[5] = (unsigned short )0;
             sqlstm.sqhstv[6] = (         void  *)(ESECUSRDEF_N.UPDATE_TIME);
             sqlstm.sqhstl[6] = (unsigned int  )15;
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
         default:
             DB_error_code = 9999;
             memset(DB_error_msg, ' ', sizeof(DB_error_msg));
             memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
             break;
    }

    DB_stop_query_timer("DBU_insert_esecusrdef", 0);
}


/* SQL UPDATE Function */
void DBU_update_esecusrdef(int sel_type, struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ESECUSRDEF_N_TAG ESECUSRDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_esecusrdef(&ESECUSRDEF_N, ESECUSRDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE ESECUSRDEF SET
                    USER_DESC = :ESECUSRDEF_N.USER_DESC,
                    PASSWORD = :ESECUSRDEF_N.PASSWORD,
                    CHG_PASS_FLAG = :ESECUSRDEF_N.CHG_PASS_FLAG,
                    USER_GRP_1 = :ESECUSRDEF_N.USER_GRP_1,
                    USER_GRP_2 = :ESECUSRDEF_N.USER_GRP_2,
                    USER_GRP_3 = :ESECUSRDEF_N.USER_GRP_3,
                    USER_GRP_4 = :ESECUSRDEF_N.USER_GRP_4,
                    USER_GRP_5 = :ESECUSRDEF_N.USER_GRP_5,
                    USER_GRP_6 = :ESECUSRDEF_N.USER_GRP_6,
                    USER_GRP_7 = :ESECUSRDEF_N.USER_GRP_7,
                    USER_GRP_8 = :ESECUSRDEF_N.USER_GRP_8,
                    USER_GRP_9 = :ESECUSRDEF_N.USER_GRP_9,
                    USER_GRP_10 = :ESECUSRDEF_N.USER_GRP_10,
                    USER_CMF_1 = :ESECUSRDEF_N.USER_CMF_1,
                    USER_CMF_2 = :ESECUSRDEF_N.USER_CMF_2,
                    USER_CMF_3 = :ESECUSRDEF_N.USER_CMF_3,
                    USER_CMF_4 = :ESECUSRDEF_N.USER_CMF_4,
                    USER_CMF_5 = :ESECUSRDEF_N.USER_CMF_5,
                    USER_CMF_6 = :ESECUSRDEF_N.USER_CMF_6,
                    USER_CMF_7 = :ESECUSRDEF_N.USER_CMF_7,
                    USER_CMF_8 = :ESECUSRDEF_N.USER_CMF_8,
                    USER_CMF_9 = :ESECUSRDEF_N.USER_CMF_9,
                    USER_CMF_10 = :ESECUSRDEF_N.USER_CMF_10,
                    SEC_GRP_ID = :ESECUSRDEF_N.SEC_GRP_ID,
                    PHONE_OFFICE = :ESECUSRDEF_N.PHONE_OFFICE,
                    PHONE_MOBILE = :ESECUSRDEF_N.PHONE_MOBILE,
                    PHONE_HOME = :ESECUSRDEF_N.PHONE_HOME,
                    PHONE_OTHER = :ESECUSRDEF_N.PHONE_OTHER,
                    EXPIRE_DATE = :ESECUSRDEF_N.EXPIRE_DATE,
                    PASS_EXPIRE_DATE = :ESECUSRDEF_N.PASS_EXPIRE_DATE,
                    ENTER_DATE = :ESECUSRDEF_N.ENTER_DATE,
                    RETIRE_DATE = :ESECUSRDEF_N.RETIRE_DATE,
                    EMAIL_ID = :ESECUSRDEF_N.EMAIL_ID,
                    BIRTHDAY = :ESECUSRDEF_N.BIRTHDAY,
                    SEX_FLAG = :ESECUSRDEF_N.SEX_FLAG,
                    CREATE_USER_ID = :ESECUSRDEF_N.CREATE_USER_ID,
                    CREATE_TIME = :ESECUSRDEF_N.CREATE_TIME,
                    UPDATE_USER_ID = :ESECUSRDEF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :ESECUSRDEF_N.UPDATE_TIME
                WHERE FACTORY = :ESECUSRDEF_N.FACTORY
                    AND USER_ID = :ESECUSRDEF_N.USER_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update ESECUSRDEF  set USER_DESC=:b0,PASSWORD=:b\
1,CHG_PASS_FLAG=:b2,USER_GRP_1=:b3,USER_GRP_2=:b4,USER_GRP_3=:b5,USER_GRP_4=:\
b6,USER_GRP_5=:b7,USER_GRP_6=:b8,USER_GRP_7=:b9,USER_GRP_8=:b10,USER_GRP_9=:b\
11,USER_GRP_10=:b12,USER_CMF_1=:b13,USER_CMF_2=:b14,USER_CMF_3=:b15,USER_CMF_\
4=:b16,USER_CMF_5=:b17,USER_CMF_6=:b18,USER_CMF_7=:b19,USER_CMF_8=:b20,USER_C\
MF_9=:b21,USER_CMF_10=:b22,SEC_GRP_ID=:b23,PHONE_OFFICE=:b24,PHONE_MOBILE=:b2\
5,PHONE_HOME=:b26,PHONE_OTHER=:b27,EXPIRE_DATE=:b28,PASS_EXPIRE_DATE=:b29,ENT\
ER_DATE=:b30,RETIRE_DATE=:b31,EMAIL_ID=:b32,BIRTHDAY=:b33,SEX_FLAG=:b34,CREAT\
E_USER_ID=:b35,CREATE_TIME=:b36,UPDATE_USER_ID=:b37,UPDATE_TIME=:b38 where (F\
ACTORY=:b39 and USER_ID=:b40)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )709;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ESECUSRDEF_N.USER_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.PASSWORD);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ESECUSRDEF_N.CHG_PASS_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ESECUSRDEF_N.USER_GRP_1);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ESECUSRDEF_N.USER_GRP_2);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(ESECUSRDEF_N.USER_GRP_3);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(ESECUSRDEF_N.USER_GRP_4);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(ESECUSRDEF_N.USER_GRP_5);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(ESECUSRDEF_N.USER_GRP_6);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(ESECUSRDEF_N.USER_GRP_7);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(ESECUSRDEF_N.USER_GRP_8);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(ESECUSRDEF_N.USER_GRP_9);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(ESECUSRDEF_N.USER_GRP_10);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(ESECUSRDEF_N.USER_CMF_1);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(ESECUSRDEF_N.USER_CMF_2);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(ESECUSRDEF_N.USER_CMF_3);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(ESECUSRDEF_N.USER_CMF_4);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(ESECUSRDEF_N.USER_CMF_5);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(ESECUSRDEF_N.USER_CMF_6);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(ESECUSRDEF_N.USER_CMF_7);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(ESECUSRDEF_N.USER_CMF_8);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(ESECUSRDEF_N.USER_CMF_9);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(ESECUSRDEF_N.USER_CMF_10);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(ESECUSRDEF_N.SEC_GRP_ID);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(ESECUSRDEF_N.PHONE_OFFICE);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(ESECUSRDEF_N.PHONE_MOBILE);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(ESECUSRDEF_N.PHONE_HOME);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(ESECUSRDEF_N.PHONE_OTHER);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(ESECUSRDEF_N.EXPIRE_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )9;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(ESECUSRDEF_N.PASS_EXPIRE_DATE);
            sqlstm.sqhstl[29] = (unsigned int  )9;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(ESECUSRDEF_N.ENTER_DATE);
            sqlstm.sqhstl[30] = (unsigned int  )9;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(ESECUSRDEF_N.RETIRE_DATE);
            sqlstm.sqhstl[31] = (unsigned int  )9;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(ESECUSRDEF_N.EMAIL_ID);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(ESECUSRDEF_N.BIRTHDAY);
            sqlstm.sqhstl[33] = (unsigned int  )9;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(ESECUSRDEF_N.SEX_FLAG);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(ESECUSRDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(ESECUSRDEF_N.CREATE_TIME);
            sqlstm.sqhstl[36] = (unsigned int  )15;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(ESECUSRDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(ESECUSRDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[38] = (unsigned int  )15;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(ESECUSRDEF_N.USER_ID);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
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
            /* EXEC SQL UPDATE ESECFACUSR SET            
                SEC_GRP_ID = :ESECUSRDEF_N.SEC_GRP_ID,             
                CREATE_USER_ID = :ESECUSRDEF_N.CREATE_USER_ID,
                CREATE_TIME = :ESECUSRDEF_N.CREATE_TIME,
                UPDATE_USER_ID = :ESECUSRDEF_N.UPDATE_USER_ID,
                UPDATE_TIME = :ESECUSRDEF_N.UPDATE_TIME
                WHERE FACTORY = :ESECUSRDEF_N.FACTORY
                AND USER_ID = :ESECUSRDEF_N.USER_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update ESECFACUSR  set SEC_GRP_ID=:b0,CREATE_USE\
R_ID=:b1,CREATE_TIME=:b2,UPDATE_USER_ID=:b3,UPDATE_TIME=:b4 where (FACTORY=:b\
5 and USER_ID=:b6)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )888;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ESECUSRDEF_N.SEC_GRP_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ESECUSRDEF_N.CREATE_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ESECUSRDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ESECUSRDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(ESECUSRDEF_N.USER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_update_esecusrdef", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_esecusrdef(int sel_type, struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ESECUSRDEF_N_TAG ESECUSRDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_esecusrdef(&ESECUSRDEF_N, ESECUSRDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_ESECUSRDEF_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    USER_ID,
                    USER_DESC,
                    PASSWORD,
                    CHG_PASS_FLAG,
                    USER_GRP_1,
                    USER_GRP_2,
                    USER_GRP_3,
                    USER_GRP_4,
                    USER_GRP_5,
                    USER_GRP_6,
                    USER_GRP_7,
                    USER_GRP_8,
                    USER_GRP_9,
                    USER_GRP_10,
                    USER_CMF_1,
                    USER_CMF_2,
                    USER_CMF_3,
                    USER_CMF_4,
                    USER_CMF_5,
                    USER_CMF_6,
                    USER_CMF_7,
                    USER_CMF_8,
                    USER_CMF_9,
                    USER_CMF_10,
                    SEC_GRP_ID,
                    PHONE_OFFICE,
                    PHONE_MOBILE,
                    PHONE_HOME,
                    PHONE_OTHER,
                    EXPIRE_DATE,
                    PASS_EXPIRE_DATE,
                    ENTER_DATE,
                    RETIRE_DATE,
                    EMAIL_ID,
                    BIRTHDAY,
                    SEX_FLAG,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM ESECUSRDEF
                ORDER BY FACTORY ASC,
                    USER_ID ASC; */ 

            /* EXEC SQL OPEN DBU_ESECUSRDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0011;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )931;
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

    DB_stop_query_timer("DBU_open_esecusrdef", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_esecusrdef(int sel_type, struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ESECUSRDEF_N_TAG ESECUSRDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_ESECUSRDEF_CUR_1 INTO
                :ESECUSRDEF_N.FACTORY,
                :ESECUSRDEF_N.USER_ID,
                :ESECUSRDEF_N.USER_DESC,
                :ESECUSRDEF_N.PASSWORD,
                :ESECUSRDEF_N.CHG_PASS_FLAG,
                :ESECUSRDEF_N.USER_GRP_1,
                :ESECUSRDEF_N.USER_GRP_2,
                :ESECUSRDEF_N.USER_GRP_3,
                :ESECUSRDEF_N.USER_GRP_4,
                :ESECUSRDEF_N.USER_GRP_5,
                :ESECUSRDEF_N.USER_GRP_6,
                :ESECUSRDEF_N.USER_GRP_7,
                :ESECUSRDEF_N.USER_GRP_8,
                :ESECUSRDEF_N.USER_GRP_9,
                :ESECUSRDEF_N.USER_GRP_10,
                :ESECUSRDEF_N.USER_CMF_1,
                :ESECUSRDEF_N.USER_CMF_2,
                :ESECUSRDEF_N.USER_CMF_3,
                :ESECUSRDEF_N.USER_CMF_4,
                :ESECUSRDEF_N.USER_CMF_5,
                :ESECUSRDEF_N.USER_CMF_6,
                :ESECUSRDEF_N.USER_CMF_7,
                :ESECUSRDEF_N.USER_CMF_8,
                :ESECUSRDEF_N.USER_CMF_9,
                :ESECUSRDEF_N.USER_CMF_10,
                :ESECUSRDEF_N.SEC_GRP_ID,
                :ESECUSRDEF_N.PHONE_OFFICE,
                :ESECUSRDEF_N.PHONE_MOBILE,
                :ESECUSRDEF_N.PHONE_HOME,
                :ESECUSRDEF_N.PHONE_OTHER,
                :ESECUSRDEF_N.EXPIRE_DATE,
                :ESECUSRDEF_N.PASS_EXPIRE_DATE,
                :ESECUSRDEF_N.ENTER_DATE,
                :ESECUSRDEF_N.RETIRE_DATE,
                :ESECUSRDEF_N.EMAIL_ID,
                :ESECUSRDEF_N.BIRTHDAY,
                :ESECUSRDEF_N.SEX_FLAG,
                :ESECUSRDEF_N.CREATE_USER_ID,
                :ESECUSRDEF_N.CREATE_TIME,
                :ESECUSRDEF_N.UPDATE_USER_ID,
                :ESECUSRDEF_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )946;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(ESECUSRDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ESECUSRDEF_N.USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ESECUSRDEF_N.USER_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ESECUSRDEF_N.PASSWORD);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ESECUSRDEF_N.CHG_PASS_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(ESECUSRDEF_N.USER_GRP_1);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(ESECUSRDEF_N.USER_GRP_2);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(ESECUSRDEF_N.USER_GRP_3);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(ESECUSRDEF_N.USER_GRP_4);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(ESECUSRDEF_N.USER_GRP_5);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(ESECUSRDEF_N.USER_GRP_6);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(ESECUSRDEF_N.USER_GRP_7);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(ESECUSRDEF_N.USER_GRP_8);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(ESECUSRDEF_N.USER_GRP_9);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(ESECUSRDEF_N.USER_GRP_10);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(ESECUSRDEF_N.USER_CMF_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(ESECUSRDEF_N.USER_CMF_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(ESECUSRDEF_N.USER_CMF_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(ESECUSRDEF_N.USER_CMF_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(ESECUSRDEF_N.USER_CMF_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(ESECUSRDEF_N.USER_CMF_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(ESECUSRDEF_N.USER_CMF_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(ESECUSRDEF_N.USER_CMF_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(ESECUSRDEF_N.USER_CMF_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(ESECUSRDEF_N.USER_CMF_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(ESECUSRDEF_N.SEC_GRP_ID);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(ESECUSRDEF_N.PHONE_OFFICE);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(ESECUSRDEF_N.PHONE_MOBILE);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(ESECUSRDEF_N.PHONE_HOME);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(ESECUSRDEF_N.PHONE_OTHER);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(ESECUSRDEF_N.EXPIRE_DATE);
            sqlstm.sqhstl[30] = (unsigned int  )9;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(ESECUSRDEF_N.PASS_EXPIRE_DATE);
            sqlstm.sqhstl[31] = (unsigned int  )9;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(ESECUSRDEF_N.ENTER_DATE);
            sqlstm.sqhstl[32] = (unsigned int  )9;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(ESECUSRDEF_N.RETIRE_DATE);
            sqlstm.sqhstl[33] = (unsigned int  )9;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(ESECUSRDEF_N.EMAIL_ID);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(ESECUSRDEF_N.BIRTHDAY);
            sqlstm.sqhstl[35] = (unsigned int  )9;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(ESECUSRDEF_N.SEX_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(ESECUSRDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(ESECUSRDEF_N.CREATE_TIME);
            sqlstm.sqhstl[38] = (unsigned int  )15;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(ESECUSRDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(ESECUSRDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[40] = (unsigned int  )15;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
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
        DBU_del_null_esecusrdef(&ESECUSRDEF_N, ESECUSRDEF);
    }

    DB_stop_query_timer("DBU_fetch_esecusrdef", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_esecusrdef(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_ESECUSRDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 43;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1125;
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

    DB_stop_query_timer("DBU_close_esecusrdef", sel_type);
}


/* Initialize Function */
void DBU_init_esecusrdef(struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    /* memset by Space */
    memset(ESECUSRDEF, ' ', sizeof(struct ESECUSRDEF_TAG));
    
}


/* Add Null Function */
void DBU_add_null_esecusrdef(struct ESECUSRDEF_N_TAG *ESECUSRDEF_N, struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    /* memset by NULL */
    memset(ESECUSRDEF_N, '\0', sizeof(struct ESECUSRDEF_N_TAG));
    
    MEMCPY_AN(ESECUSRDEF_N->FACTORY, ESECUSRDEF->FACTORY, sizeof(ESECUSRDEF->FACTORY));
    MEMCPY_AN(ESECUSRDEF_N->USER_ID, ESECUSRDEF->USER_ID, sizeof(ESECUSRDEF->USER_ID));
    MEMCPY_AN(ESECUSRDEF_N->USER_DESC, ESECUSRDEF->USER_DESC, sizeof(ESECUSRDEF->USER_DESC));
    MEMCPY_AN(ESECUSRDEF_N->PASSWORD, ESECUSRDEF->PASSWORD, sizeof(ESECUSRDEF->PASSWORD));
    ESECUSRDEF_N->CHG_PASS_FLAG[0] = ESECUSRDEF->CHG_PASS_FLAG;
    MEMCPY_AN(ESECUSRDEF_N->USER_GRP_1, ESECUSRDEF->USER_GRP_1, sizeof(ESECUSRDEF->USER_GRP_1));
    MEMCPY_AN(ESECUSRDEF_N->USER_GRP_2, ESECUSRDEF->USER_GRP_2, sizeof(ESECUSRDEF->USER_GRP_2));
    MEMCPY_AN(ESECUSRDEF_N->USER_GRP_3, ESECUSRDEF->USER_GRP_3, sizeof(ESECUSRDEF->USER_GRP_3));
    MEMCPY_AN(ESECUSRDEF_N->USER_GRP_4, ESECUSRDEF->USER_GRP_4, sizeof(ESECUSRDEF->USER_GRP_4));
    MEMCPY_AN(ESECUSRDEF_N->USER_GRP_5, ESECUSRDEF->USER_GRP_5, sizeof(ESECUSRDEF->USER_GRP_5));
    MEMCPY_AN(ESECUSRDEF_N->USER_GRP_6, ESECUSRDEF->USER_GRP_6, sizeof(ESECUSRDEF->USER_GRP_6));
    MEMCPY_AN(ESECUSRDEF_N->USER_GRP_7, ESECUSRDEF->USER_GRP_7, sizeof(ESECUSRDEF->USER_GRP_7));
    MEMCPY_AN(ESECUSRDEF_N->USER_GRP_8, ESECUSRDEF->USER_GRP_8, sizeof(ESECUSRDEF->USER_GRP_8));
    MEMCPY_AN(ESECUSRDEF_N->USER_GRP_9, ESECUSRDEF->USER_GRP_9, sizeof(ESECUSRDEF->USER_GRP_9));
    MEMCPY_AN(ESECUSRDEF_N->USER_GRP_10, ESECUSRDEF->USER_GRP_10, sizeof(ESECUSRDEF->USER_GRP_10));
    MEMCPY_AN(ESECUSRDEF_N->USER_CMF_1, ESECUSRDEF->USER_CMF_1, sizeof(ESECUSRDEF->USER_CMF_1));
    MEMCPY_AN(ESECUSRDEF_N->USER_CMF_2, ESECUSRDEF->USER_CMF_2, sizeof(ESECUSRDEF->USER_CMF_2));
    MEMCPY_AN(ESECUSRDEF_N->USER_CMF_3, ESECUSRDEF->USER_CMF_3, sizeof(ESECUSRDEF->USER_CMF_3));
    MEMCPY_AN(ESECUSRDEF_N->USER_CMF_4, ESECUSRDEF->USER_CMF_4, sizeof(ESECUSRDEF->USER_CMF_4));
    MEMCPY_AN(ESECUSRDEF_N->USER_CMF_5, ESECUSRDEF->USER_CMF_5, sizeof(ESECUSRDEF->USER_CMF_5));
    MEMCPY_AN(ESECUSRDEF_N->USER_CMF_6, ESECUSRDEF->USER_CMF_6, sizeof(ESECUSRDEF->USER_CMF_6));
    MEMCPY_AN(ESECUSRDEF_N->USER_CMF_7, ESECUSRDEF->USER_CMF_7, sizeof(ESECUSRDEF->USER_CMF_7));
    MEMCPY_AN(ESECUSRDEF_N->USER_CMF_8, ESECUSRDEF->USER_CMF_8, sizeof(ESECUSRDEF->USER_CMF_8));
    MEMCPY_AN(ESECUSRDEF_N->USER_CMF_9, ESECUSRDEF->USER_CMF_9, sizeof(ESECUSRDEF->USER_CMF_9));
    MEMCPY_AN(ESECUSRDEF_N->USER_CMF_10, ESECUSRDEF->USER_CMF_10, sizeof(ESECUSRDEF->USER_CMF_10));
    MEMCPY_AN(ESECUSRDEF_N->SEC_GRP_ID, ESECUSRDEF->SEC_GRP_ID, sizeof(ESECUSRDEF->SEC_GRP_ID));
    MEMCPY_AN(ESECUSRDEF_N->PHONE_OFFICE, ESECUSRDEF->PHONE_OFFICE, sizeof(ESECUSRDEF->PHONE_OFFICE));
    MEMCPY_AN(ESECUSRDEF_N->PHONE_MOBILE, ESECUSRDEF->PHONE_MOBILE, sizeof(ESECUSRDEF->PHONE_MOBILE));
    MEMCPY_AN(ESECUSRDEF_N->PHONE_HOME, ESECUSRDEF->PHONE_HOME, sizeof(ESECUSRDEF->PHONE_HOME));
    MEMCPY_AN(ESECUSRDEF_N->PHONE_OTHER, ESECUSRDEF->PHONE_OTHER, sizeof(ESECUSRDEF->PHONE_OTHER));
    MEMCPY_AN(ESECUSRDEF_N->EXPIRE_DATE, ESECUSRDEF->EXPIRE_DATE, sizeof(ESECUSRDEF->EXPIRE_DATE));
    MEMCPY_AN(ESECUSRDEF_N->PASS_EXPIRE_DATE, ESECUSRDEF->PASS_EXPIRE_DATE, sizeof(ESECUSRDEF->PASS_EXPIRE_DATE));
    MEMCPY_AN(ESECUSRDEF_N->ENTER_DATE, ESECUSRDEF->ENTER_DATE, sizeof(ESECUSRDEF->ENTER_DATE));
    MEMCPY_AN(ESECUSRDEF_N->RETIRE_DATE, ESECUSRDEF->RETIRE_DATE, sizeof(ESECUSRDEF->RETIRE_DATE));
    MEMCPY_AN(ESECUSRDEF_N->EMAIL_ID, ESECUSRDEF->EMAIL_ID, sizeof(ESECUSRDEF->EMAIL_ID));
    MEMCPY_AN(ESECUSRDEF_N->BIRTHDAY, ESECUSRDEF->BIRTHDAY, sizeof(ESECUSRDEF->BIRTHDAY));
    ESECUSRDEF_N->SEX_FLAG[0] = ESECUSRDEF->SEX_FLAG;
    MEMCPY_AN(ESECUSRDEF_N->CREATE_USER_ID, ESECUSRDEF->CREATE_USER_ID, sizeof(ESECUSRDEF->CREATE_USER_ID));
    MEMCPY_AN(ESECUSRDEF_N->CREATE_TIME, ESECUSRDEF->CREATE_TIME, sizeof(ESECUSRDEF->CREATE_TIME));
    MEMCPY_AN(ESECUSRDEF_N->UPDATE_USER_ID, ESECUSRDEF->UPDATE_USER_ID, sizeof(ESECUSRDEF->UPDATE_USER_ID));
    MEMCPY_AN(ESECUSRDEF_N->UPDATE_TIME, ESECUSRDEF->UPDATE_TIME, sizeof(ESECUSRDEF->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_esecusrdef(struct ESECUSRDEF_N_TAG *ESECUSRDEF_N, struct ESECUSRDEF_TAG *ESECUSRDEF)
{
    MEMCPY_DN(ESECUSRDEF->FACTORY, ESECUSRDEF_N->FACTORY, sizeof(ESECUSRDEF->FACTORY));
    MEMCPY_DN(ESECUSRDEF->USER_ID, ESECUSRDEF_N->USER_ID, sizeof(ESECUSRDEF->USER_ID));
    MEMCPY_DN(ESECUSRDEF->USER_DESC, ESECUSRDEF_N->USER_DESC, sizeof(ESECUSRDEF->USER_DESC));
    MEMCPY_DN(ESECUSRDEF->PASSWORD, ESECUSRDEF_N->PASSWORD, sizeof(ESECUSRDEF->PASSWORD));
    ESECUSRDEF->CHG_PASS_FLAG = ESECUSRDEF_N->CHG_PASS_FLAG[0];
    MEMCPY_DN(ESECUSRDEF->USER_GRP_1, ESECUSRDEF_N->USER_GRP_1, sizeof(ESECUSRDEF->USER_GRP_1));
    MEMCPY_DN(ESECUSRDEF->USER_GRP_2, ESECUSRDEF_N->USER_GRP_2, sizeof(ESECUSRDEF->USER_GRP_2));
    MEMCPY_DN(ESECUSRDEF->USER_GRP_3, ESECUSRDEF_N->USER_GRP_3, sizeof(ESECUSRDEF->USER_GRP_3));
    MEMCPY_DN(ESECUSRDEF->USER_GRP_4, ESECUSRDEF_N->USER_GRP_4, sizeof(ESECUSRDEF->USER_GRP_4));
    MEMCPY_DN(ESECUSRDEF->USER_GRP_5, ESECUSRDEF_N->USER_GRP_5, sizeof(ESECUSRDEF->USER_GRP_5));
    MEMCPY_DN(ESECUSRDEF->USER_GRP_6, ESECUSRDEF_N->USER_GRP_6, sizeof(ESECUSRDEF->USER_GRP_6));
    MEMCPY_DN(ESECUSRDEF->USER_GRP_7, ESECUSRDEF_N->USER_GRP_7, sizeof(ESECUSRDEF->USER_GRP_7));
    MEMCPY_DN(ESECUSRDEF->USER_GRP_8, ESECUSRDEF_N->USER_GRP_8, sizeof(ESECUSRDEF->USER_GRP_8));
    MEMCPY_DN(ESECUSRDEF->USER_GRP_9, ESECUSRDEF_N->USER_GRP_9, sizeof(ESECUSRDEF->USER_GRP_9));
    MEMCPY_DN(ESECUSRDEF->USER_GRP_10, ESECUSRDEF_N->USER_GRP_10, sizeof(ESECUSRDEF->USER_GRP_10));
    MEMCPY_DN(ESECUSRDEF->USER_CMF_1, ESECUSRDEF_N->USER_CMF_1, sizeof(ESECUSRDEF->USER_CMF_1));
    MEMCPY_DN(ESECUSRDEF->USER_CMF_2, ESECUSRDEF_N->USER_CMF_2, sizeof(ESECUSRDEF->USER_CMF_2));
    MEMCPY_DN(ESECUSRDEF->USER_CMF_3, ESECUSRDEF_N->USER_CMF_3, sizeof(ESECUSRDEF->USER_CMF_3));
    MEMCPY_DN(ESECUSRDEF->USER_CMF_4, ESECUSRDEF_N->USER_CMF_4, sizeof(ESECUSRDEF->USER_CMF_4));
    MEMCPY_DN(ESECUSRDEF->USER_CMF_5, ESECUSRDEF_N->USER_CMF_5, sizeof(ESECUSRDEF->USER_CMF_5));
    MEMCPY_DN(ESECUSRDEF->USER_CMF_6, ESECUSRDEF_N->USER_CMF_6, sizeof(ESECUSRDEF->USER_CMF_6));
    MEMCPY_DN(ESECUSRDEF->USER_CMF_7, ESECUSRDEF_N->USER_CMF_7, sizeof(ESECUSRDEF->USER_CMF_7));
    MEMCPY_DN(ESECUSRDEF->USER_CMF_8, ESECUSRDEF_N->USER_CMF_8, sizeof(ESECUSRDEF->USER_CMF_8));
    MEMCPY_DN(ESECUSRDEF->USER_CMF_9, ESECUSRDEF_N->USER_CMF_9, sizeof(ESECUSRDEF->USER_CMF_9));
    MEMCPY_DN(ESECUSRDEF->USER_CMF_10, ESECUSRDEF_N->USER_CMF_10, sizeof(ESECUSRDEF->USER_CMF_10));
    MEMCPY_DN(ESECUSRDEF->SEC_GRP_ID, ESECUSRDEF_N->SEC_GRP_ID, sizeof(ESECUSRDEF->SEC_GRP_ID));
    MEMCPY_DN(ESECUSRDEF->PHONE_OFFICE, ESECUSRDEF_N->PHONE_OFFICE, sizeof(ESECUSRDEF->PHONE_OFFICE));
    MEMCPY_DN(ESECUSRDEF->PHONE_MOBILE, ESECUSRDEF_N->PHONE_MOBILE, sizeof(ESECUSRDEF->PHONE_MOBILE));
    MEMCPY_DN(ESECUSRDEF->PHONE_HOME, ESECUSRDEF_N->PHONE_HOME, sizeof(ESECUSRDEF->PHONE_HOME));
    MEMCPY_DN(ESECUSRDEF->PHONE_OTHER, ESECUSRDEF_N->PHONE_OTHER, sizeof(ESECUSRDEF->PHONE_OTHER));
    MEMCPY_DN(ESECUSRDEF->EXPIRE_DATE, ESECUSRDEF_N->EXPIRE_DATE, sizeof(ESECUSRDEF->EXPIRE_DATE));
    MEMCPY_DN(ESECUSRDEF->PASS_EXPIRE_DATE, ESECUSRDEF_N->PASS_EXPIRE_DATE, sizeof(ESECUSRDEF->PASS_EXPIRE_DATE));
    MEMCPY_DN(ESECUSRDEF->ENTER_DATE, ESECUSRDEF_N->ENTER_DATE, sizeof(ESECUSRDEF->ENTER_DATE));
    MEMCPY_DN(ESECUSRDEF->RETIRE_DATE, ESECUSRDEF_N->RETIRE_DATE, sizeof(ESECUSRDEF->RETIRE_DATE));
    MEMCPY_DN(ESECUSRDEF->EMAIL_ID, ESECUSRDEF_N->EMAIL_ID, sizeof(ESECUSRDEF->EMAIL_ID));
    MEMCPY_DN(ESECUSRDEF->BIRTHDAY, ESECUSRDEF_N->BIRTHDAY, sizeof(ESECUSRDEF->BIRTHDAY));
    ESECUSRDEF->SEX_FLAG = ESECUSRDEF_N->SEX_FLAG[0];
    MEMCPY_DN(ESECUSRDEF->CREATE_USER_ID, ESECUSRDEF_N->CREATE_USER_ID, sizeof(ESECUSRDEF->CREATE_USER_ID));
    MEMCPY_DN(ESECUSRDEF->CREATE_TIME, ESECUSRDEF_N->CREATE_TIME, sizeof(ESECUSRDEF->CREATE_TIME));
    MEMCPY_DN(ESECUSRDEF->UPDATE_USER_ID, ESECUSRDEF_N->UPDATE_USER_ID, sizeof(ESECUSRDEF->UPDATE_USER_ID));
    MEMCPY_DN(ESECUSRDEF->UPDATE_TIME, ESECUSRDEF_N->UPDATE_TIME, sizeof(ESECUSRDEF->UPDATE_TIME));
}


