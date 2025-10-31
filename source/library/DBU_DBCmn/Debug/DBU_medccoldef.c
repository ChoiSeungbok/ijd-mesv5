
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
    "DBU_medccoldef.pc"
};


static unsigned int sqlctx = 9387035;


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
            void  *sqhstv[36];
   unsigned int   sqhstl[36];
            int   sqhsts[36];
            void  *sqindv[36];
            int   sqinds[36];
   unsigned int   sqharm[36];
   unsigned int   *sqharc[36];
   unsigned short  sqadto[36];
   unsigned short  sqtdso[36];
} sqlstm = {13,36};

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
"select FACTORY ,COL_SET_ID ,COL_SET_DESC ,COL_GRP_1 ,COL_GRP_2 ,COL_GRP_3 ,\
COL_GRP_4 ,COL_GRP_5 ,COL_GRP_6 ,COL_GRP_7 ,COL_GRP_8 ,COL_GRP_9 ,COL_GRP_10 \
,COL_CMF_1 ,COL_CMF_2 ,COL_CMF_3 ,COL_CMF_4 ,COL_CMF_5 ,COL_CMF_6 ,COL_CMF_7 \
,COL_CMF_8 ,COL_CMF_9 ,COL_CMF_10 ,DEFAULT_COL_MODE_FLAG ,LOT_OR_RES_FLAG ,AP\
PROVAL_REQUIRE_FLAG ,APPROVAL_USER_ID ,DELETE_FLAG ,DELETE_USER_ID ,DELETE_TI\
ME ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from MEDCCOLDEF\
  order by FACTORY asc ,COL_SET_ID asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,664,0,4,46,0,0,36,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
164,0,0,2,676,0,4,155,0,0,36,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
323,0,0,3,81,0,4,267,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
350,0,0,4,63,0,2,304,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
373,0,0,5,597,0,3,334,0,0,34,34,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,
524,0,0,6,598,0,5,427,0,0,34,34,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,
675,0,0,7,511,0,9,531,0,0,0,0,0,1,0,
690,0,0,7,0,0,13,560,0,0,34,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,
841,0,0,7,0,0,15,624,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_medccoldef.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-09-08 16:50:24
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
void DBU_add_null_medccoldef(struct MEDCCOLDEF_N_TAG *MEDCCOLDEF_N, struct MEDCCOLDEF_TAG *MEDCCOLDEF);
void DBU_del_null_medccoldef(struct MEDCCOLDEF_N_TAG *MEDCCOLDEF_N, struct MEDCCOLDEF_TAG *MEDCCOLDEF);


/* SQL SELECT Function */
void DBU_select_medccoldef(int sel_type, struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCCOLDEF_N_TAG MEDCCOLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medccoldef(&MEDCCOLDEF_N, MEDCCOLDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    COL_SET_ID,
                    COL_SET_DESC,
                    COL_GRP_1,
                    COL_GRP_2,
                    COL_GRP_3,
                    COL_GRP_4,
                    COL_GRP_5,
                    COL_GRP_6,
                    COL_GRP_7,
                    COL_GRP_8,
                    COL_GRP_9,
                    COL_GRP_10,
                    COL_CMF_1,
                    COL_CMF_2,
                    COL_CMF_3,
                    COL_CMF_4,
                    COL_CMF_5,
                    COL_CMF_6,
                    COL_CMF_7,
                    COL_CMF_8,
                    COL_CMF_9,
                    COL_CMF_10,
                    DEFAULT_COL_MODE_FLAG,
                    LOT_OR_RES_FLAG,
                    APPROVAL_REQUIRE_FLAG,
                    APPROVAL_USER_ID,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :MEDCCOLDEF_N.FACTORY,
                    :MEDCCOLDEF_N.COL_SET_ID,
                    :MEDCCOLDEF_N.COL_SET_DESC,
                    :MEDCCOLDEF_N.COL_GRP_1,
                    :MEDCCOLDEF_N.COL_GRP_2,
                    :MEDCCOLDEF_N.COL_GRP_3,
                    :MEDCCOLDEF_N.COL_GRP_4,
                    :MEDCCOLDEF_N.COL_GRP_5,
                    :MEDCCOLDEF_N.COL_GRP_6,
                    :MEDCCOLDEF_N.COL_GRP_7,
                    :MEDCCOLDEF_N.COL_GRP_8,
                    :MEDCCOLDEF_N.COL_GRP_9,
                    :MEDCCOLDEF_N.COL_GRP_10,
                    :MEDCCOLDEF_N.COL_CMF_1,
                    :MEDCCOLDEF_N.COL_CMF_2,
                    :MEDCCOLDEF_N.COL_CMF_3,
                    :MEDCCOLDEF_N.COL_CMF_4,
                    :MEDCCOLDEF_N.COL_CMF_5,
                    :MEDCCOLDEF_N.COL_CMF_6,
                    :MEDCCOLDEF_N.COL_CMF_7,
                    :MEDCCOLDEF_N.COL_CMF_8,
                    :MEDCCOLDEF_N.COL_CMF_9,
                    :MEDCCOLDEF_N.COL_CMF_10,
                    :MEDCCOLDEF_N.DEFAULT_COL_MODE_FLAG,
                    :MEDCCOLDEF_N.LOT_OR_RES_FLAG,
                    :MEDCCOLDEF_N.APPROVAL_REQUIRE_FLAG,
                    :MEDCCOLDEF_N.APPROVAL_USER_ID,
                    :MEDCCOLDEF_N.DELETE_FLAG,
                    :MEDCCOLDEF_N.DELETE_USER_ID,
                    :MEDCCOLDEF_N.DELETE_TIME,
                    :MEDCCOLDEF_N.CREATE_USER_ID,
                    :MEDCCOLDEF_N.CREATE_TIME,
                    :MEDCCOLDEF_N.UPDATE_USER_ID,
                    :MEDCCOLDEF_N.UPDATE_TIME
                FROM MEDCCOLDEF
                WHERE FACTORY = :MEDCCOLDEF_N.FACTORY
                    AND COL_SET_ID = :MEDCCOLDEF_N.COL_SET_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 36;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,COL_SET_ID ,COL_SET_DESC ,COL_GR\
P_1 ,COL_GRP_2 ,COL_GRP_3 ,COL_GRP_4 ,COL_GRP_5 ,COL_GRP_6 ,COL_GRP_7 ,COL_GR\
P_8 ,COL_GRP_9 ,COL_GRP_10 ,COL_CMF_1 ,COL_CMF_2 ,COL_CMF_3 ,COL_CMF_4 ,COL_C\
MF_5 ,COL_CMF_6 ,COL_CMF_7 ,COL_CMF_8 ,COL_CMF_9 ,COL_CMF_10 ,DEFAULT_COL_MOD\
E_FLAG ,LOT_OR_RES_FLAG ,APPROVAL_REQUIRE_FLAG ,APPROVAL_USER_ID ,DELETE_FLAG\
 ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,U\
PDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:\
b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b2\
9,:b30,:b31,:b32,:b33  from MEDCCOLDEF where (FACTORY=:b0 and COL_SET_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MEDCCOLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MEDCCOLDEF_N.COL_SET_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MEDCCOLDEF_N.COL_SET_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCCOLDEF_N.COL_GRP_1);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCCOLDEF_N.COL_GRP_2);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MEDCCOLDEF_N.COL_GRP_3);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MEDCCOLDEF_N.COL_GRP_4);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MEDCCOLDEF_N.COL_GRP_5);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MEDCCOLDEF_N.COL_GRP_6);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MEDCCOLDEF_N.COL_GRP_7);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MEDCCOLDEF_N.COL_GRP_8);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MEDCCOLDEF_N.COL_GRP_9);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MEDCCOLDEF_N.COL_GRP_10);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MEDCCOLDEF_N.COL_CMF_1);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MEDCCOLDEF_N.COL_CMF_2);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MEDCCOLDEF_N.COL_CMF_3);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MEDCCOLDEF_N.COL_CMF_4);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MEDCCOLDEF_N.COL_CMF_5);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MEDCCOLDEF_N.COL_CMF_6);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MEDCCOLDEF_N.COL_CMF_7);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MEDCCOLDEF_N.COL_CMF_8);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MEDCCOLDEF_N.COL_CMF_9);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MEDCCOLDEF_N.COL_CMF_10);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MEDCCOLDEF_N.DEFAULT_COL_MODE_FLAG);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MEDCCOLDEF_N.LOT_OR_RES_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MEDCCOLDEF_N.APPROVAL_REQUIRE_FLAG);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MEDCCOLDEF_N.APPROVAL_USER_ID);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MEDCCOLDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MEDCCOLDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MEDCCOLDEF_N.DELETE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MEDCCOLDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MEDCCOLDEF_N.CREATE_TIME);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MEDCCOLDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MEDCCOLDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[33] = (unsigned int  )15;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MEDCCOLDEF_N.FACTORY);
            sqlstm.sqhstl[34] = (unsigned int  )11;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MEDCCOLDEF_N.COL_SET_ID);
            sqlstm.sqhstl[35] = (unsigned int  )26;
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


    if(DB_error_code == 0)
    {
        DBU_del_null_medccoldef(&MEDCCOLDEF_N, MEDCCOLDEF);
    }

    DB_stop_query_timer("DBU_select_medccoldef", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_medccoldef_for_update(int sel_type, struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCCOLDEF_N_TAG MEDCCOLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medccoldef(&MEDCCOLDEF_N, MEDCCOLDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    COL_SET_ID,
                    COL_SET_DESC,
                    COL_GRP_1,
                    COL_GRP_2,
                    COL_GRP_3,
                    COL_GRP_4,
                    COL_GRP_5,
                    COL_GRP_6,
                    COL_GRP_7,
                    COL_GRP_8,
                    COL_GRP_9,
                    COL_GRP_10,
                    COL_CMF_1,
                    COL_CMF_2,
                    COL_CMF_3,
                    COL_CMF_4,
                    COL_CMF_5,
                    COL_CMF_6,
                    COL_CMF_7,
                    COL_CMF_8,
                    COL_CMF_9,
                    COL_CMF_10,
                    DEFAULT_COL_MODE_FLAG,
                    LOT_OR_RES_FLAG,
                    APPROVAL_REQUIRE_FLAG,
                    APPROVAL_USER_ID,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :MEDCCOLDEF_N.FACTORY,
                    :MEDCCOLDEF_N.COL_SET_ID,
                    :MEDCCOLDEF_N.COL_SET_DESC,
                    :MEDCCOLDEF_N.COL_GRP_1,
                    :MEDCCOLDEF_N.COL_GRP_2,
                    :MEDCCOLDEF_N.COL_GRP_3,
                    :MEDCCOLDEF_N.COL_GRP_4,
                    :MEDCCOLDEF_N.COL_GRP_5,
                    :MEDCCOLDEF_N.COL_GRP_6,
                    :MEDCCOLDEF_N.COL_GRP_7,
                    :MEDCCOLDEF_N.COL_GRP_8,
                    :MEDCCOLDEF_N.COL_GRP_9,
                    :MEDCCOLDEF_N.COL_GRP_10,
                    :MEDCCOLDEF_N.COL_CMF_1,
                    :MEDCCOLDEF_N.COL_CMF_2,
                    :MEDCCOLDEF_N.COL_CMF_3,
                    :MEDCCOLDEF_N.COL_CMF_4,
                    :MEDCCOLDEF_N.COL_CMF_5,
                    :MEDCCOLDEF_N.COL_CMF_6,
                    :MEDCCOLDEF_N.COL_CMF_7,
                    :MEDCCOLDEF_N.COL_CMF_8,
                    :MEDCCOLDEF_N.COL_CMF_9,
                    :MEDCCOLDEF_N.COL_CMF_10,
                    :MEDCCOLDEF_N.DEFAULT_COL_MODE_FLAG,
                    :MEDCCOLDEF_N.LOT_OR_RES_FLAG,
                    :MEDCCOLDEF_N.APPROVAL_REQUIRE_FLAG,
                    :MEDCCOLDEF_N.APPROVAL_USER_ID,
                    :MEDCCOLDEF_N.DELETE_FLAG,
                    :MEDCCOLDEF_N.DELETE_USER_ID,
                    :MEDCCOLDEF_N.DELETE_TIME,
                    :MEDCCOLDEF_N.CREATE_USER_ID,
                    :MEDCCOLDEF_N.CREATE_TIME,
                    :MEDCCOLDEF_N.UPDATE_USER_ID,
                    :MEDCCOLDEF_N.UPDATE_TIME
                FROM MEDCCOLDEF
                WHERE FACTORY = :MEDCCOLDEF_N.FACTORY
                    AND COL_SET_ID = :MEDCCOLDEF_N.COL_SET_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 36;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,COL_SET_ID ,COL_SET_DESC ,COL_GR\
P_1 ,COL_GRP_2 ,COL_GRP_3 ,COL_GRP_4 ,COL_GRP_5 ,COL_GRP_6 ,COL_GRP_7 ,COL_GR\
P_8 ,COL_GRP_9 ,COL_GRP_10 ,COL_CMF_1 ,COL_CMF_2 ,COL_CMF_3 ,COL_CMF_4 ,COL_C\
MF_5 ,COL_CMF_6 ,COL_CMF_7 ,COL_CMF_8 ,COL_CMF_9 ,COL_CMF_10 ,DEFAULT_COL_MOD\
E_FLAG ,LOT_OR_RES_FLAG ,APPROVAL_REQUIRE_FLAG ,APPROVAL_USER_ID ,DELETE_FLAG\
 ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,U\
PDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:\
b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b2\
9,:b30,:b31,:b32,:b33  from MEDCCOLDEF where (FACTORY=:b0 and COL_SET_ID=:b1)\
 for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )164;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MEDCCOLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MEDCCOLDEF_N.COL_SET_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MEDCCOLDEF_N.COL_SET_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCCOLDEF_N.COL_GRP_1);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCCOLDEF_N.COL_GRP_2);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MEDCCOLDEF_N.COL_GRP_3);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MEDCCOLDEF_N.COL_GRP_4);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MEDCCOLDEF_N.COL_GRP_5);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MEDCCOLDEF_N.COL_GRP_6);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MEDCCOLDEF_N.COL_GRP_7);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MEDCCOLDEF_N.COL_GRP_8);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MEDCCOLDEF_N.COL_GRP_9);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MEDCCOLDEF_N.COL_GRP_10);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MEDCCOLDEF_N.COL_CMF_1);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MEDCCOLDEF_N.COL_CMF_2);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MEDCCOLDEF_N.COL_CMF_3);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MEDCCOLDEF_N.COL_CMF_4);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MEDCCOLDEF_N.COL_CMF_5);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MEDCCOLDEF_N.COL_CMF_6);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MEDCCOLDEF_N.COL_CMF_7);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MEDCCOLDEF_N.COL_CMF_8);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MEDCCOLDEF_N.COL_CMF_9);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MEDCCOLDEF_N.COL_CMF_10);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MEDCCOLDEF_N.DEFAULT_COL_MODE_FLAG);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MEDCCOLDEF_N.LOT_OR_RES_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MEDCCOLDEF_N.APPROVAL_REQUIRE_FLAG);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MEDCCOLDEF_N.APPROVAL_USER_ID);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MEDCCOLDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MEDCCOLDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MEDCCOLDEF_N.DELETE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MEDCCOLDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MEDCCOLDEF_N.CREATE_TIME);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MEDCCOLDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MEDCCOLDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[33] = (unsigned int  )15;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MEDCCOLDEF_N.FACTORY);
            sqlstm.sqhstl[34] = (unsigned int  )11;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MEDCCOLDEF_N.COL_SET_ID);
            sqlstm.sqhstl[35] = (unsigned int  )26;
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


    if(DB_error_code == 0)
    {
        DBU_del_null_medccoldef(&MEDCCOLDEF_N, MEDCCOLDEF);
    }

    DB_stop_query_timer("DBU_select_medccoldef_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_medccoldef_scalar(int sel_type, struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCCOLDEF_N_TAG MEDCCOLDEF_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medccoldef(&MEDCCOLDEF_N, MEDCCOLDEF);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MEDCCOLDEF
                WHERE FACTORY = :MEDCCOLDEF_N.FACTORY
                    AND COL_SET_ID = :MEDCCOLDEF_N.COL_SET_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 36;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MEDCCOLDEF where\
 (FACTORY=:b1 and COL_SET_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )323;
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
            sqlstm.sqhstv[1] = (         void  *)(MEDCCOLDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MEDCCOLDEF_N.COL_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
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

    DB_stop_query_timer("DBU_select_medccoldef_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_medccoldef(int sel_type, struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCCOLDEF_N_TAG MEDCCOLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medccoldef(&MEDCCOLDEF_N, MEDCCOLDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MEDCCOLDEF
                WHERE FACTORY = :MEDCCOLDEF_N.FACTORY
                    AND COL_SET_ID = :MEDCCOLDEF_N.COL_SET_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 36;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MEDCCOLDEF  where (FACTORY=:b0 and \
COL_SET_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )350;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MEDCCOLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MEDCCOLDEF_N.COL_SET_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
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

    DB_stop_query_timer("DBU_delete_medccoldef", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_medccoldef(struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCCOLDEF_N_TAG MEDCCOLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medccoldef(&MEDCCOLDEF_N, MEDCCOLDEF);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MEDCCOLDEF( 
                    FACTORY, 
                    COL_SET_ID, 
                    COL_SET_DESC, 
                    COL_GRP_1, 
                    COL_GRP_2, 
                    COL_GRP_3, 
                    COL_GRP_4, 
                    COL_GRP_5, 
                    COL_GRP_6, 
                    COL_GRP_7, 
                    COL_GRP_8, 
                    COL_GRP_9, 
                    COL_GRP_10, 
                    COL_CMF_1, 
                    COL_CMF_2, 
                    COL_CMF_3, 
                    COL_CMF_4, 
                    COL_CMF_5, 
                    COL_CMF_6, 
                    COL_CMF_7, 
                    COL_CMF_8, 
                    COL_CMF_9, 
                    COL_CMF_10, 
                    DEFAULT_COL_MODE_FLAG, 
                    LOT_OR_RES_FLAG, 
                    APPROVAL_REQUIRE_FLAG, 
                    APPROVAL_USER_ID, 
                    DELETE_FLAG, 
                    DELETE_USER_ID, 
                    DELETE_TIME, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME
         ) 
        VALUES (
                    :MEDCCOLDEF_N.FACTORY,
                    :MEDCCOLDEF_N.COL_SET_ID,
                    :MEDCCOLDEF_N.COL_SET_DESC,
                    :MEDCCOLDEF_N.COL_GRP_1,
                    :MEDCCOLDEF_N.COL_GRP_2,
                    :MEDCCOLDEF_N.COL_GRP_3,
                    :MEDCCOLDEF_N.COL_GRP_4,
                    :MEDCCOLDEF_N.COL_GRP_5,
                    :MEDCCOLDEF_N.COL_GRP_6,
                    :MEDCCOLDEF_N.COL_GRP_7,
                    :MEDCCOLDEF_N.COL_GRP_8,
                    :MEDCCOLDEF_N.COL_GRP_9,
                    :MEDCCOLDEF_N.COL_GRP_10,
                    :MEDCCOLDEF_N.COL_CMF_1,
                    :MEDCCOLDEF_N.COL_CMF_2,
                    :MEDCCOLDEF_N.COL_CMF_3,
                    :MEDCCOLDEF_N.COL_CMF_4,
                    :MEDCCOLDEF_N.COL_CMF_5,
                    :MEDCCOLDEF_N.COL_CMF_6,
                    :MEDCCOLDEF_N.COL_CMF_7,
                    :MEDCCOLDEF_N.COL_CMF_8,
                    :MEDCCOLDEF_N.COL_CMF_9,
                    :MEDCCOLDEF_N.COL_CMF_10,
                    :MEDCCOLDEF_N.DEFAULT_COL_MODE_FLAG,
                    :MEDCCOLDEF_N.LOT_OR_RES_FLAG,
                    :MEDCCOLDEF_N.APPROVAL_REQUIRE_FLAG,
                    :MEDCCOLDEF_N.APPROVAL_USER_ID,
                    :MEDCCOLDEF_N.DELETE_FLAG,
                    :MEDCCOLDEF_N.DELETE_USER_ID,
                    :MEDCCOLDEF_N.DELETE_TIME,
                    :MEDCCOLDEF_N.CREATE_USER_ID,
                    :MEDCCOLDEF_N.CREATE_TIME,
                    :MEDCCOLDEF_N.UPDATE_USER_ID,
                    :MEDCCOLDEF_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 36;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into MEDCCOLDEF (FACTORY,COL_SET_ID,COL_SET_DESC,\
COL_GRP_1,COL_GRP_2,COL_GRP_3,COL_GRP_4,COL_GRP_5,COL_GRP_6,COL_GRP_7,COL_GRP\
_8,COL_GRP_9,COL_GRP_10,COL_CMF_1,COL_CMF_2,COL_CMF_3,COL_CMF_4,COL_CMF_5,COL\
_CMF_6,COL_CMF_7,COL_CMF_8,COL_CMF_9,COL_CMF_10,DEFAULT_COL_MODE_FLAG,LOT_OR_\
RES_FLAG,APPROVAL_REQUIRE_FLAG,APPROVAL_USER_ID,DELETE_FLAG,DELETE_USER_ID,DE\
LETE_TIME,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) values (:b0,\
:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:\
b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b3\
3)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )373;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MEDCCOLDEF_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MEDCCOLDEF_N.COL_SET_ID);
    sqlstm.sqhstl[1] = (unsigned int  )26;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MEDCCOLDEF_N.COL_SET_DESC);
    sqlstm.sqhstl[2] = (unsigned int  )201;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MEDCCOLDEF_N.COL_GRP_1);
    sqlstm.sqhstl[3] = (unsigned int  )31;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MEDCCOLDEF_N.COL_GRP_2);
    sqlstm.sqhstl[4] = (unsigned int  )31;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MEDCCOLDEF_N.COL_GRP_3);
    sqlstm.sqhstl[5] = (unsigned int  )31;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MEDCCOLDEF_N.COL_GRP_4);
    sqlstm.sqhstl[6] = (unsigned int  )31;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MEDCCOLDEF_N.COL_GRP_5);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MEDCCOLDEF_N.COL_GRP_6);
    sqlstm.sqhstl[8] = (unsigned int  )31;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MEDCCOLDEF_N.COL_GRP_7);
    sqlstm.sqhstl[9] = (unsigned int  )31;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MEDCCOLDEF_N.COL_GRP_8);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MEDCCOLDEF_N.COL_GRP_9);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MEDCCOLDEF_N.COL_GRP_10);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MEDCCOLDEF_N.COL_CMF_1);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MEDCCOLDEF_N.COL_CMF_2);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MEDCCOLDEF_N.COL_CMF_3);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MEDCCOLDEF_N.COL_CMF_4);
    sqlstm.sqhstl[16] = (unsigned int  )31;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MEDCCOLDEF_N.COL_CMF_5);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MEDCCOLDEF_N.COL_CMF_6);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MEDCCOLDEF_N.COL_CMF_7);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MEDCCOLDEF_N.COL_CMF_8);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MEDCCOLDEF_N.COL_CMF_9);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MEDCCOLDEF_N.COL_CMF_10);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MEDCCOLDEF_N.DEFAULT_COL_MODE_FLAG);
    sqlstm.sqhstl[23] = (unsigned int  )2;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MEDCCOLDEF_N.LOT_OR_RES_FLAG);
    sqlstm.sqhstl[24] = (unsigned int  )2;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MEDCCOLDEF_N.APPROVAL_REQUIRE_FLAG);
    sqlstm.sqhstl[25] = (unsigned int  )2;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MEDCCOLDEF_N.APPROVAL_USER_ID);
    sqlstm.sqhstl[26] = (unsigned int  )21;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MEDCCOLDEF_N.DELETE_FLAG);
    sqlstm.sqhstl[27] = (unsigned int  )2;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MEDCCOLDEF_N.DELETE_USER_ID);
    sqlstm.sqhstl[28] = (unsigned int  )21;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MEDCCOLDEF_N.DELETE_TIME);
    sqlstm.sqhstl[29] = (unsigned int  )15;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MEDCCOLDEF_N.CREATE_USER_ID);
    sqlstm.sqhstl[30] = (unsigned int  )21;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MEDCCOLDEF_N.CREATE_TIME);
    sqlstm.sqhstl[31] = (unsigned int  )15;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MEDCCOLDEF_N.UPDATE_USER_ID);
    sqlstm.sqhstl[32] = (unsigned int  )21;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MEDCCOLDEF_N.UPDATE_TIME);
    sqlstm.sqhstl[33] = (unsigned int  )15;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_medccoldef", 0);
}


/* SQL UPDATE Function */
void DBU_update_medccoldef(int sel_type, struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCCOLDEF_N_TAG MEDCCOLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medccoldef(&MEDCCOLDEF_N, MEDCCOLDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MEDCCOLDEF SET
                    COL_SET_DESC = :MEDCCOLDEF_N.COL_SET_DESC,
                    COL_GRP_1 = :MEDCCOLDEF_N.COL_GRP_1,
                    COL_GRP_2 = :MEDCCOLDEF_N.COL_GRP_2,
                    COL_GRP_3 = :MEDCCOLDEF_N.COL_GRP_3,
                    COL_GRP_4 = :MEDCCOLDEF_N.COL_GRP_4,
                    COL_GRP_5 = :MEDCCOLDEF_N.COL_GRP_5,
                    COL_GRP_6 = :MEDCCOLDEF_N.COL_GRP_6,
                    COL_GRP_7 = :MEDCCOLDEF_N.COL_GRP_7,
                    COL_GRP_8 = :MEDCCOLDEF_N.COL_GRP_8,
                    COL_GRP_9 = :MEDCCOLDEF_N.COL_GRP_9,
                    COL_GRP_10 = :MEDCCOLDEF_N.COL_GRP_10,
                    COL_CMF_1 = :MEDCCOLDEF_N.COL_CMF_1,
                    COL_CMF_2 = :MEDCCOLDEF_N.COL_CMF_2,
                    COL_CMF_3 = :MEDCCOLDEF_N.COL_CMF_3,
                    COL_CMF_4 = :MEDCCOLDEF_N.COL_CMF_4,
                    COL_CMF_5 = :MEDCCOLDEF_N.COL_CMF_5,
                    COL_CMF_6 = :MEDCCOLDEF_N.COL_CMF_6,
                    COL_CMF_7 = :MEDCCOLDEF_N.COL_CMF_7,
                    COL_CMF_8 = :MEDCCOLDEF_N.COL_CMF_8,
                    COL_CMF_9 = :MEDCCOLDEF_N.COL_CMF_9,
                    COL_CMF_10 = :MEDCCOLDEF_N.COL_CMF_10,
                    DEFAULT_COL_MODE_FLAG = :MEDCCOLDEF_N.DEFAULT_COL_MODE_FLAG,
                    LOT_OR_RES_FLAG = :MEDCCOLDEF_N.LOT_OR_RES_FLAG,
                    APPROVAL_REQUIRE_FLAG = :MEDCCOLDEF_N.APPROVAL_REQUIRE_FLAG,
                    APPROVAL_USER_ID = :MEDCCOLDEF_N.APPROVAL_USER_ID,
                    DELETE_FLAG = :MEDCCOLDEF_N.DELETE_FLAG,
                    DELETE_USER_ID = :MEDCCOLDEF_N.DELETE_USER_ID,
                    DELETE_TIME = :MEDCCOLDEF_N.DELETE_TIME,
                    CREATE_USER_ID = :MEDCCOLDEF_N.CREATE_USER_ID,
                    CREATE_TIME = :MEDCCOLDEF_N.CREATE_TIME,
                    UPDATE_USER_ID = :MEDCCOLDEF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MEDCCOLDEF_N.UPDATE_TIME
                WHERE FACTORY = :MEDCCOLDEF_N.FACTORY
                    AND COL_SET_ID = :MEDCCOLDEF_N.COL_SET_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 36;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MEDCCOLDEF  set COL_SET_DESC=:b0,COL_GRP_\
1=:b1,COL_GRP_2=:b2,COL_GRP_3=:b3,COL_GRP_4=:b4,COL_GRP_5=:b5,COL_GRP_6=:b6,C\
OL_GRP_7=:b7,COL_GRP_8=:b8,COL_GRP_9=:b9,COL_GRP_10=:b10,COL_CMF_1=:b11,COL_C\
MF_2=:b12,COL_CMF_3=:b13,COL_CMF_4=:b14,COL_CMF_5=:b15,COL_CMF_6=:b16,COL_CMF\
_7=:b17,COL_CMF_8=:b18,COL_CMF_9=:b19,COL_CMF_10=:b20,DEFAULT_COL_MODE_FLAG=:\
b21,LOT_OR_RES_FLAG=:b22,APPROVAL_REQUIRE_FLAG=:b23,APPROVAL_USER_ID=:b24,DEL\
ETE_FLAG=:b25,DELETE_USER_ID=:b26,DELETE_TIME=:b27,CREATE_USER_ID=:b28,CREATE\
_TIME=:b29,UPDATE_USER_ID=:b30,UPDATE_TIME=:b31 where (FACTORY=:b32 and COL_S\
ET_ID=:b33)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )524;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MEDCCOLDEF_N.COL_SET_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MEDCCOLDEF_N.COL_GRP_1);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MEDCCOLDEF_N.COL_GRP_2);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCCOLDEF_N.COL_GRP_3);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCCOLDEF_N.COL_GRP_4);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MEDCCOLDEF_N.COL_GRP_5);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MEDCCOLDEF_N.COL_GRP_6);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MEDCCOLDEF_N.COL_GRP_7);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MEDCCOLDEF_N.COL_GRP_8);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MEDCCOLDEF_N.COL_GRP_9);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MEDCCOLDEF_N.COL_GRP_10);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MEDCCOLDEF_N.COL_CMF_1);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MEDCCOLDEF_N.COL_CMF_2);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MEDCCOLDEF_N.COL_CMF_3);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MEDCCOLDEF_N.COL_CMF_4);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MEDCCOLDEF_N.COL_CMF_5);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MEDCCOLDEF_N.COL_CMF_6);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MEDCCOLDEF_N.COL_CMF_7);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MEDCCOLDEF_N.COL_CMF_8);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MEDCCOLDEF_N.COL_CMF_9);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MEDCCOLDEF_N.COL_CMF_10);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MEDCCOLDEF_N.DEFAULT_COL_MODE_FLAG);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MEDCCOLDEF_N.LOT_OR_RES_FLAG);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MEDCCOLDEF_N.APPROVAL_REQUIRE_FLAG);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MEDCCOLDEF_N.APPROVAL_USER_ID);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MEDCCOLDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MEDCCOLDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MEDCCOLDEF_N.DELETE_TIME);
            sqlstm.sqhstl[27] = (unsigned int  )15;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MEDCCOLDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MEDCCOLDEF_N.CREATE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MEDCCOLDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MEDCCOLDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MEDCCOLDEF_N.FACTORY);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MEDCCOLDEF_N.COL_SET_ID);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_medccoldef", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_medccoldef(int sel_type, struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCCOLDEF_N_TAG MEDCCOLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medccoldef(&MEDCCOLDEF_N, MEDCCOLDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_MEDCCOLDEF_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    COL_SET_ID,
                    COL_SET_DESC,
                    COL_GRP_1,
                    COL_GRP_2,
                    COL_GRP_3,
                    COL_GRP_4,
                    COL_GRP_5,
                    COL_GRP_6,
                    COL_GRP_7,
                    COL_GRP_8,
                    COL_GRP_9,
                    COL_GRP_10,
                    COL_CMF_1,
                    COL_CMF_2,
                    COL_CMF_3,
                    COL_CMF_4,
                    COL_CMF_5,
                    COL_CMF_6,
                    COL_CMF_7,
                    COL_CMF_8,
                    COL_CMF_9,
                    COL_CMF_10,
                    DEFAULT_COL_MODE_FLAG,
                    LOT_OR_RES_FLAG,
                    APPROVAL_REQUIRE_FLAG,
                    APPROVAL_USER_ID,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM MEDCCOLDEF
                ORDER BY FACTORY ASC,
                    COL_SET_ID ASC; */ 

            /* EXEC SQL OPEN DBU_MEDCCOLDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 36;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )675;
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

    DB_stop_query_timer("DBU_open_medccoldef", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_medccoldef(int sel_type, struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCCOLDEF_N_TAG MEDCCOLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_MEDCCOLDEF_CUR_1 INTO
                :MEDCCOLDEF_N.FACTORY,
                :MEDCCOLDEF_N.COL_SET_ID,
                :MEDCCOLDEF_N.COL_SET_DESC,
                :MEDCCOLDEF_N.COL_GRP_1,
                :MEDCCOLDEF_N.COL_GRP_2,
                :MEDCCOLDEF_N.COL_GRP_3,
                :MEDCCOLDEF_N.COL_GRP_4,
                :MEDCCOLDEF_N.COL_GRP_5,
                :MEDCCOLDEF_N.COL_GRP_6,
                :MEDCCOLDEF_N.COL_GRP_7,
                :MEDCCOLDEF_N.COL_GRP_8,
                :MEDCCOLDEF_N.COL_GRP_9,
                :MEDCCOLDEF_N.COL_GRP_10,
                :MEDCCOLDEF_N.COL_CMF_1,
                :MEDCCOLDEF_N.COL_CMF_2,
                :MEDCCOLDEF_N.COL_CMF_3,
                :MEDCCOLDEF_N.COL_CMF_4,
                :MEDCCOLDEF_N.COL_CMF_5,
                :MEDCCOLDEF_N.COL_CMF_6,
                :MEDCCOLDEF_N.COL_CMF_7,
                :MEDCCOLDEF_N.COL_CMF_8,
                :MEDCCOLDEF_N.COL_CMF_9,
                :MEDCCOLDEF_N.COL_CMF_10,
                :MEDCCOLDEF_N.DEFAULT_COL_MODE_FLAG,
                :MEDCCOLDEF_N.LOT_OR_RES_FLAG,
                :MEDCCOLDEF_N.APPROVAL_REQUIRE_FLAG,
                :MEDCCOLDEF_N.APPROVAL_USER_ID,
                :MEDCCOLDEF_N.DELETE_FLAG,
                :MEDCCOLDEF_N.DELETE_USER_ID,
                :MEDCCOLDEF_N.DELETE_TIME,
                :MEDCCOLDEF_N.CREATE_USER_ID,
                :MEDCCOLDEF_N.CREATE_TIME,
                :MEDCCOLDEF_N.UPDATE_USER_ID,
                :MEDCCOLDEF_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 36;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )690;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MEDCCOLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MEDCCOLDEF_N.COL_SET_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MEDCCOLDEF_N.COL_SET_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCCOLDEF_N.COL_GRP_1);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCCOLDEF_N.COL_GRP_2);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MEDCCOLDEF_N.COL_GRP_3);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MEDCCOLDEF_N.COL_GRP_4);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MEDCCOLDEF_N.COL_GRP_5);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MEDCCOLDEF_N.COL_GRP_6);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MEDCCOLDEF_N.COL_GRP_7);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MEDCCOLDEF_N.COL_GRP_8);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MEDCCOLDEF_N.COL_GRP_9);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MEDCCOLDEF_N.COL_GRP_10);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MEDCCOLDEF_N.COL_CMF_1);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MEDCCOLDEF_N.COL_CMF_2);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MEDCCOLDEF_N.COL_CMF_3);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MEDCCOLDEF_N.COL_CMF_4);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MEDCCOLDEF_N.COL_CMF_5);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MEDCCOLDEF_N.COL_CMF_6);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MEDCCOLDEF_N.COL_CMF_7);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MEDCCOLDEF_N.COL_CMF_8);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MEDCCOLDEF_N.COL_CMF_9);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MEDCCOLDEF_N.COL_CMF_10);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MEDCCOLDEF_N.DEFAULT_COL_MODE_FLAG);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MEDCCOLDEF_N.LOT_OR_RES_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MEDCCOLDEF_N.APPROVAL_REQUIRE_FLAG);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MEDCCOLDEF_N.APPROVAL_USER_ID);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MEDCCOLDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MEDCCOLDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MEDCCOLDEF_N.DELETE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MEDCCOLDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MEDCCOLDEF_N.CREATE_TIME);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MEDCCOLDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MEDCCOLDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[33] = (unsigned int  )15;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
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
        DBU_del_null_medccoldef(&MEDCCOLDEF_N, MEDCCOLDEF);
    }

    DB_stop_query_timer("DBU_fetch_medccoldef", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_medccoldef(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_MEDCCOLDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 36;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )841;
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

    DB_stop_query_timer("DBU_close_medccoldef", sel_type);
}


/* Initialize Function */
void DBU_init_medccoldef(struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    /* memset by Space */
    memset(MEDCCOLDEF, ' ', sizeof(struct MEDCCOLDEF_TAG));
    
}


/* Add Null Function */
void DBU_add_null_medccoldef(struct MEDCCOLDEF_N_TAG *MEDCCOLDEF_N, struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    /* memset by NULL */
    memset(MEDCCOLDEF_N, '\0', sizeof(struct MEDCCOLDEF_N_TAG));
    
    MEMCPY_AN(MEDCCOLDEF_N->FACTORY, MEDCCOLDEF->FACTORY, sizeof(MEDCCOLDEF->FACTORY));
    MEMCPY_AN(MEDCCOLDEF_N->COL_SET_ID, MEDCCOLDEF->COL_SET_ID, sizeof(MEDCCOLDEF->COL_SET_ID));
    MEMCPY_AN(MEDCCOLDEF_N->COL_SET_DESC, MEDCCOLDEF->COL_SET_DESC, sizeof(MEDCCOLDEF->COL_SET_DESC));
    MEMCPY_AN(MEDCCOLDEF_N->COL_GRP_1, MEDCCOLDEF->COL_GRP_1, sizeof(MEDCCOLDEF->COL_GRP_1));
    MEMCPY_AN(MEDCCOLDEF_N->COL_GRP_2, MEDCCOLDEF->COL_GRP_2, sizeof(MEDCCOLDEF->COL_GRP_2));
    MEMCPY_AN(MEDCCOLDEF_N->COL_GRP_3, MEDCCOLDEF->COL_GRP_3, sizeof(MEDCCOLDEF->COL_GRP_3));
    MEMCPY_AN(MEDCCOLDEF_N->COL_GRP_4, MEDCCOLDEF->COL_GRP_4, sizeof(MEDCCOLDEF->COL_GRP_4));
    MEMCPY_AN(MEDCCOLDEF_N->COL_GRP_5, MEDCCOLDEF->COL_GRP_5, sizeof(MEDCCOLDEF->COL_GRP_5));
    MEMCPY_AN(MEDCCOLDEF_N->COL_GRP_6, MEDCCOLDEF->COL_GRP_6, sizeof(MEDCCOLDEF->COL_GRP_6));
    MEMCPY_AN(MEDCCOLDEF_N->COL_GRP_7, MEDCCOLDEF->COL_GRP_7, sizeof(MEDCCOLDEF->COL_GRP_7));
    MEMCPY_AN(MEDCCOLDEF_N->COL_GRP_8, MEDCCOLDEF->COL_GRP_8, sizeof(MEDCCOLDEF->COL_GRP_8));
    MEMCPY_AN(MEDCCOLDEF_N->COL_GRP_9, MEDCCOLDEF->COL_GRP_9, sizeof(MEDCCOLDEF->COL_GRP_9));
    MEMCPY_AN(MEDCCOLDEF_N->COL_GRP_10, MEDCCOLDEF->COL_GRP_10, sizeof(MEDCCOLDEF->COL_GRP_10));
    MEMCPY_AN(MEDCCOLDEF_N->COL_CMF_1, MEDCCOLDEF->COL_CMF_1, sizeof(MEDCCOLDEF->COL_CMF_1));
    MEMCPY_AN(MEDCCOLDEF_N->COL_CMF_2, MEDCCOLDEF->COL_CMF_2, sizeof(MEDCCOLDEF->COL_CMF_2));
    MEMCPY_AN(MEDCCOLDEF_N->COL_CMF_3, MEDCCOLDEF->COL_CMF_3, sizeof(MEDCCOLDEF->COL_CMF_3));
    MEMCPY_AN(MEDCCOLDEF_N->COL_CMF_4, MEDCCOLDEF->COL_CMF_4, sizeof(MEDCCOLDEF->COL_CMF_4));
    MEMCPY_AN(MEDCCOLDEF_N->COL_CMF_5, MEDCCOLDEF->COL_CMF_5, sizeof(MEDCCOLDEF->COL_CMF_5));
    MEMCPY_AN(MEDCCOLDEF_N->COL_CMF_6, MEDCCOLDEF->COL_CMF_6, sizeof(MEDCCOLDEF->COL_CMF_6));
    MEMCPY_AN(MEDCCOLDEF_N->COL_CMF_7, MEDCCOLDEF->COL_CMF_7, sizeof(MEDCCOLDEF->COL_CMF_7));
    MEMCPY_AN(MEDCCOLDEF_N->COL_CMF_8, MEDCCOLDEF->COL_CMF_8, sizeof(MEDCCOLDEF->COL_CMF_8));
    MEMCPY_AN(MEDCCOLDEF_N->COL_CMF_9, MEDCCOLDEF->COL_CMF_9, sizeof(MEDCCOLDEF->COL_CMF_9));
    MEMCPY_AN(MEDCCOLDEF_N->COL_CMF_10, MEDCCOLDEF->COL_CMF_10, sizeof(MEDCCOLDEF->COL_CMF_10));
    MEDCCOLDEF_N->DEFAULT_COL_MODE_FLAG[0] = MEDCCOLDEF->DEFAULT_COL_MODE_FLAG;
    MEDCCOLDEF_N->LOT_OR_RES_FLAG[0] = MEDCCOLDEF->LOT_OR_RES_FLAG;
    MEDCCOLDEF_N->APPROVAL_REQUIRE_FLAG[0] = MEDCCOLDEF->APPROVAL_REQUIRE_FLAG;
    MEMCPY_AN(MEDCCOLDEF_N->APPROVAL_USER_ID, MEDCCOLDEF->APPROVAL_USER_ID, sizeof(MEDCCOLDEF->APPROVAL_USER_ID));
    MEDCCOLDEF_N->DELETE_FLAG[0] = MEDCCOLDEF->DELETE_FLAG;
    MEMCPY_AN(MEDCCOLDEF_N->DELETE_USER_ID, MEDCCOLDEF->DELETE_USER_ID, sizeof(MEDCCOLDEF->DELETE_USER_ID));
    MEMCPY_AN(MEDCCOLDEF_N->DELETE_TIME, MEDCCOLDEF->DELETE_TIME, sizeof(MEDCCOLDEF->DELETE_TIME));
    MEMCPY_AN(MEDCCOLDEF_N->CREATE_USER_ID, MEDCCOLDEF->CREATE_USER_ID, sizeof(MEDCCOLDEF->CREATE_USER_ID));
    MEMCPY_AN(MEDCCOLDEF_N->CREATE_TIME, MEDCCOLDEF->CREATE_TIME, sizeof(MEDCCOLDEF->CREATE_TIME));
    MEMCPY_AN(MEDCCOLDEF_N->UPDATE_USER_ID, MEDCCOLDEF->UPDATE_USER_ID, sizeof(MEDCCOLDEF->UPDATE_USER_ID));
    MEMCPY_AN(MEDCCOLDEF_N->UPDATE_TIME, MEDCCOLDEF->UPDATE_TIME, sizeof(MEDCCOLDEF->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_medccoldef(struct MEDCCOLDEF_N_TAG *MEDCCOLDEF_N, struct MEDCCOLDEF_TAG *MEDCCOLDEF)
{
    MEMCPY_DN(MEDCCOLDEF->FACTORY, MEDCCOLDEF_N->FACTORY, sizeof(MEDCCOLDEF->FACTORY));
    MEMCPY_DN(MEDCCOLDEF->COL_SET_ID, MEDCCOLDEF_N->COL_SET_ID, sizeof(MEDCCOLDEF->COL_SET_ID));
    MEMCPY_DN(MEDCCOLDEF->COL_SET_DESC, MEDCCOLDEF_N->COL_SET_DESC, sizeof(MEDCCOLDEF->COL_SET_DESC));
    MEMCPY_DN(MEDCCOLDEF->COL_GRP_1, MEDCCOLDEF_N->COL_GRP_1, sizeof(MEDCCOLDEF->COL_GRP_1));
    MEMCPY_DN(MEDCCOLDEF->COL_GRP_2, MEDCCOLDEF_N->COL_GRP_2, sizeof(MEDCCOLDEF->COL_GRP_2));
    MEMCPY_DN(MEDCCOLDEF->COL_GRP_3, MEDCCOLDEF_N->COL_GRP_3, sizeof(MEDCCOLDEF->COL_GRP_3));
    MEMCPY_DN(MEDCCOLDEF->COL_GRP_4, MEDCCOLDEF_N->COL_GRP_4, sizeof(MEDCCOLDEF->COL_GRP_4));
    MEMCPY_DN(MEDCCOLDEF->COL_GRP_5, MEDCCOLDEF_N->COL_GRP_5, sizeof(MEDCCOLDEF->COL_GRP_5));
    MEMCPY_DN(MEDCCOLDEF->COL_GRP_6, MEDCCOLDEF_N->COL_GRP_6, sizeof(MEDCCOLDEF->COL_GRP_6));
    MEMCPY_DN(MEDCCOLDEF->COL_GRP_7, MEDCCOLDEF_N->COL_GRP_7, sizeof(MEDCCOLDEF->COL_GRP_7));
    MEMCPY_DN(MEDCCOLDEF->COL_GRP_8, MEDCCOLDEF_N->COL_GRP_8, sizeof(MEDCCOLDEF->COL_GRP_8));
    MEMCPY_DN(MEDCCOLDEF->COL_GRP_9, MEDCCOLDEF_N->COL_GRP_9, sizeof(MEDCCOLDEF->COL_GRP_9));
    MEMCPY_DN(MEDCCOLDEF->COL_GRP_10, MEDCCOLDEF_N->COL_GRP_10, sizeof(MEDCCOLDEF->COL_GRP_10));
    MEMCPY_DN(MEDCCOLDEF->COL_CMF_1, MEDCCOLDEF_N->COL_CMF_1, sizeof(MEDCCOLDEF->COL_CMF_1));
    MEMCPY_DN(MEDCCOLDEF->COL_CMF_2, MEDCCOLDEF_N->COL_CMF_2, sizeof(MEDCCOLDEF->COL_CMF_2));
    MEMCPY_DN(MEDCCOLDEF->COL_CMF_3, MEDCCOLDEF_N->COL_CMF_3, sizeof(MEDCCOLDEF->COL_CMF_3));
    MEMCPY_DN(MEDCCOLDEF->COL_CMF_4, MEDCCOLDEF_N->COL_CMF_4, sizeof(MEDCCOLDEF->COL_CMF_4));
    MEMCPY_DN(MEDCCOLDEF->COL_CMF_5, MEDCCOLDEF_N->COL_CMF_5, sizeof(MEDCCOLDEF->COL_CMF_5));
    MEMCPY_DN(MEDCCOLDEF->COL_CMF_6, MEDCCOLDEF_N->COL_CMF_6, sizeof(MEDCCOLDEF->COL_CMF_6));
    MEMCPY_DN(MEDCCOLDEF->COL_CMF_7, MEDCCOLDEF_N->COL_CMF_7, sizeof(MEDCCOLDEF->COL_CMF_7));
    MEMCPY_DN(MEDCCOLDEF->COL_CMF_8, MEDCCOLDEF_N->COL_CMF_8, sizeof(MEDCCOLDEF->COL_CMF_8));
    MEMCPY_DN(MEDCCOLDEF->COL_CMF_9, MEDCCOLDEF_N->COL_CMF_9, sizeof(MEDCCOLDEF->COL_CMF_9));
    MEMCPY_DN(MEDCCOLDEF->COL_CMF_10, MEDCCOLDEF_N->COL_CMF_10, sizeof(MEDCCOLDEF->COL_CMF_10));
    MEDCCOLDEF->DEFAULT_COL_MODE_FLAG = MEDCCOLDEF_N->DEFAULT_COL_MODE_FLAG[0];
    MEDCCOLDEF->LOT_OR_RES_FLAG = MEDCCOLDEF_N->LOT_OR_RES_FLAG[0];
    MEDCCOLDEF->APPROVAL_REQUIRE_FLAG = MEDCCOLDEF_N->APPROVAL_REQUIRE_FLAG[0];
    MEMCPY_DN(MEDCCOLDEF->APPROVAL_USER_ID, MEDCCOLDEF_N->APPROVAL_USER_ID, sizeof(MEDCCOLDEF->APPROVAL_USER_ID));
    MEDCCOLDEF->DELETE_FLAG = MEDCCOLDEF_N->DELETE_FLAG[0];
    MEMCPY_DN(MEDCCOLDEF->DELETE_USER_ID, MEDCCOLDEF_N->DELETE_USER_ID, sizeof(MEDCCOLDEF->DELETE_USER_ID));
    MEMCPY_DN(MEDCCOLDEF->DELETE_TIME, MEDCCOLDEF_N->DELETE_TIME, sizeof(MEDCCOLDEF->DELETE_TIME));
    MEMCPY_DN(MEDCCOLDEF->CREATE_USER_ID, MEDCCOLDEF_N->CREATE_USER_ID, sizeof(MEDCCOLDEF->CREATE_USER_ID));
    MEMCPY_DN(MEDCCOLDEF->CREATE_TIME, MEDCCOLDEF_N->CREATE_TIME, sizeof(MEDCCOLDEF->CREATE_TIME));
    MEMCPY_DN(MEDCCOLDEF->UPDATE_USER_ID, MEDCCOLDEF_N->UPDATE_USER_ID, sizeof(MEDCCOLDEF->UPDATE_USER_ID));
    MEMCPY_DN(MEDCCOLDEF->UPDATE_TIME, MEDCCOLDEF_N->UPDATE_TIME, sizeof(MEDCCOLDEF->UPDATE_TIME));
}


