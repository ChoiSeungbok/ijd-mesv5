
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
           char  filnam[26];
};
static const struct sqlcxp sqlfpn =
{
    25,
    "DBU_if_std_bom_def_his.pc"
};


static unsigned int sqlctx = 1885213309;


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
            void  *sqhstv[47];
   unsigned int   sqhstl[47];
            int   sqhsts[47];
            void  *sqindv[47];
            int   sqinds[47];
   unsigned int   sqharm[47];
   unsigned int   *sqharc[47];
   unsigned short  sqadto[47];
   unsigned short  sqtdso[47];
} sqlstm = {13,47};

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
"select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY ,BOM_ID ,ORG_ID ,ORG_CODE \
,ITEM_ID ,ITEM_CODE ,ITEM_DESC ,ITEM_STATUS ,ITEM_UNIT ,ITEM_TYPE ,ALTERNATE_\
CODE ,BOM_COMP_ID ,COMP_SEQ ,OPER_SEQ ,STD_OPER_ID ,OPER ,OPER_DESC ,COMP_ITE\
M_ID ,COMP_ITEM_CODE ,COMP_ITEM_DESC ,COMP_ITEM_UNIT ,COMP_QTY ,COMP_YIELD_FA\
CTOR ,EFFECTIVITY_DATE ,WIP_SUPPLY_TYPE ,WIP_SUPPLY_TYPE_NAME ,SUPPLY_INV_OPE\
R ,TRAN_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,\
CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from IF_STD\
_BOM_DEF_HIS  order by IF_SEQ asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,791,0,4,46,0,0,47,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,
208,0,0,2,803,0,4,178,0,0,47,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,
411,0,0,3,67,0,4,313,0,0,2,1,0,1,0,2,4,0,0,1,3,0,0,
434,0,0,4,49,0,2,349,0,0,1,1,0,1,0,1,3,0,0,
453,0,0,5,734,0,3,378,0,0,46,46,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
652,0,0,6,729,0,5,495,0,0,46,46,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
851,0,0,7,583,0,9,622,0,0,0,0,0,1,0,
866,0,0,7,0,0,13,651,0,0,46,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1065,0,0,7,0,0,15,727,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_if_std_bom_def_his.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-09-28 11:32:41
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
void DBU_add_null_if_std_bom_def_his(struct IF_STD_BOM_DEF_HIS_N_TAG *IF_STD_BOM_DEF_HIS_N, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS);
void DBU_del_null_if_std_bom_def_his(struct IF_STD_BOM_DEF_HIS_N_TAG *IF_STD_BOM_DEF_HIS_N, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS);


/* SQL SELECT Function */
void DBU_select_if_std_bom_def_his(int sel_type, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_STD_BOM_DEF_HIS_N_TAG IF_STD_BOM_DEF_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS_N, IF_STD_BOM_DEF_HIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    IF_SEQ,
                    IF_TIME,
                    IF_CODE,
                    IF_MSG,
                    FACTORY,
                    BOM_ID,
                    ORG_ID,
                    ORG_CODE,
                    ITEM_ID,
                    ITEM_CODE,
                    ITEM_DESC,
                    ITEM_STATUS,
                    ITEM_UNIT,
                    ITEM_TYPE,
                    ALTERNATE_CODE,
                    BOM_COMP_ID,
                    COMP_SEQ,
                    OPER_SEQ,
                    STD_OPER_ID,
                    OPER,
                    OPER_DESC,
                    COMP_ITEM_ID,
                    COMP_ITEM_CODE,
                    COMP_ITEM_DESC,
                    COMP_ITEM_UNIT,
                    COMP_QTY,
                    COMP_YIELD_FACTOR,
                    EFFECTIVITY_DATE,
                    WIP_SUPPLY_TYPE,
                    WIP_SUPPLY_TYPE_NAME,
                    SUPPLY_INV_OPER,
                    TRAN_FLAG,
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
                    :IF_STD_BOM_DEF_HIS_N.IF_SEQ,
                    :IF_STD_BOM_DEF_HIS_N.IF_TIME,
                    :IF_STD_BOM_DEF_HIS_N.IF_CODE,
                    :IF_STD_BOM_DEF_HIS_N.IF_MSG,
                    :IF_STD_BOM_DEF_HIS_N.FACTORY,
                    :IF_STD_BOM_DEF_HIS_N.BOM_ID,
                    :IF_STD_BOM_DEF_HIS_N.ORG_ID,
                    :IF_STD_BOM_DEF_HIS_N.ORG_CODE,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_ID,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_CODE,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_DESC,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_STATUS,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_UNIT,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_TYPE,
                    :IF_STD_BOM_DEF_HIS_N.ALTERNATE_CODE,
                    :IF_STD_BOM_DEF_HIS_N.BOM_COMP_ID,
                    :IF_STD_BOM_DEF_HIS_N.COMP_SEQ,
                    :IF_STD_BOM_DEF_HIS_N.OPER_SEQ,
                    :IF_STD_BOM_DEF_HIS_N.STD_OPER_ID,
                    :IF_STD_BOM_DEF_HIS_N.OPER,
                    :IF_STD_BOM_DEF_HIS_N.OPER_DESC,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_ID,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_CODE,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_DESC,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_UNIT,
                    :IF_STD_BOM_DEF_HIS_N.COMP_QTY,
                    :IF_STD_BOM_DEF_HIS_N.COMP_YIELD_FACTOR,
                    :IF_STD_BOM_DEF_HIS_N.EFFECTIVITY_DATE,
                    :IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE,
                    :IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE_NAME,
                    :IF_STD_BOM_DEF_HIS_N.SUPPLY_INV_OPER,
                    :IF_STD_BOM_DEF_HIS_N.TRAN_FLAG,
                    :IF_STD_BOM_DEF_HIS_N.CMF_1,
                    :IF_STD_BOM_DEF_HIS_N.CMF_2,
                    :IF_STD_BOM_DEF_HIS_N.CMF_3,
                    :IF_STD_BOM_DEF_HIS_N.CMF_4,
                    :IF_STD_BOM_DEF_HIS_N.CMF_5,
                    :IF_STD_BOM_DEF_HIS_N.CMF_6,
                    :IF_STD_BOM_DEF_HIS_N.CMF_7,
                    :IF_STD_BOM_DEF_HIS_N.CMF_8,
                    :IF_STD_BOM_DEF_HIS_N.CMF_9,
                    :IF_STD_BOM_DEF_HIS_N.CMF_10,
                    :IF_STD_BOM_DEF_HIS_N.CREATE_USER_ID,
                    :IF_STD_BOM_DEF_HIS_N.CREATE_TIME,
                    :IF_STD_BOM_DEF_HIS_N.UPDATE_USER_ID,
                    :IF_STD_BOM_DEF_HIS_N.UPDATE_TIME
                FROM IF_STD_BOM_DEF_HIS
                WHERE IF_SEQ = :IF_STD_BOM_DEF_HIS_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY\
 ,BOM_ID ,ORG_ID ,ORG_CODE ,ITEM_ID ,ITEM_CODE ,ITEM_DESC ,ITEM_STATUS ,ITEM_\
UNIT ,ITEM_TYPE ,ALTERNATE_CODE ,BOM_COMP_ID ,COMP_SEQ ,OPER_SEQ ,STD_OPER_ID\
 ,OPER ,OPER_DESC ,COMP_ITEM_ID ,COMP_ITEM_CODE ,COMP_ITEM_DESC ,COMP_ITEM_UN\
IT ,COMP_QTY ,COMP_YIELD_FACTOR ,EFFECTIVITY_DATE ,WIP_SUPPLY_TYPE ,WIP_SUPPL\
Y_TYPE_NAME ,SUPPLY_INV_OPER ,TRAN_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,C\
MF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_I\
D ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b\
13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28\
,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:\
b44,:b45  from IF_STD_BOM_DEF_HIS where IF_SEQ=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_STD_BOM_DEF_HIS_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.BOM_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.ORG_ID);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ORG_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )4;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.ITEM_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_CODE);
            sqlstm.sqhstl[9] = (unsigned int  )41;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_DESC);
            sqlstm.sqhstl[10] = (unsigned int  )241;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_STATUS);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_UNIT);
            sqlstm.sqhstl[12] = (unsigned int  )4;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ALTERNATE_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.BOM_COMP_ID);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_SEQ);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.OPER_SEQ);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.STD_OPER_ID);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_STD_BOM_DEF_HIS_N.OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_STD_BOM_DEF_HIS_N.OPER_DESC);
            sqlstm.sqhstl[20] = (unsigned int  )241;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_ID);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_CODE);
            sqlstm.sqhstl[22] = (unsigned int  )41;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_DESC);
            sqlstm.sqhstl[23] = (unsigned int  )241;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_UNIT);
            sqlstm.sqhstl[24] = (unsigned int  )4;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_QTY);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_YIELD_FACTOR);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_STD_BOM_DEF_HIS_N.EFFECTIVITY_DATE);
            sqlstm.sqhstl[27] = (unsigned int  )15;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE_NAME);
            sqlstm.sqhstl[29] = (unsigned int  )81;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_STD_BOM_DEF_HIS_N.SUPPLY_INV_OPER);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_STD_BOM_DEF_HIS_N.TRAN_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_6);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_7);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_8);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_9);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_10);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CREATE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )15;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_STD_BOM_DEF_HIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_STD_BOM_DEF_HIS_N.UPDATE_TIME);
            sqlstm.sqhstl[45] = (unsigned int  )15;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.IF_SEQ);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
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
        DBU_del_null_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS_N, IF_STD_BOM_DEF_HIS);
    }

    DB_stop_query_timer("DBU_select_if_std_bom_def_his", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_if_std_bom_def_his_for_update(int sel_type, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_STD_BOM_DEF_HIS_N_TAG IF_STD_BOM_DEF_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS_N, IF_STD_BOM_DEF_HIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    IF_SEQ,
                    IF_TIME,
                    IF_CODE,
                    IF_MSG,
                    FACTORY,
                    BOM_ID,
                    ORG_ID,
                    ORG_CODE,
                    ITEM_ID,
                    ITEM_CODE,
                    ITEM_DESC,
                    ITEM_STATUS,
                    ITEM_UNIT,
                    ITEM_TYPE,
                    ALTERNATE_CODE,
                    BOM_COMP_ID,
                    COMP_SEQ,
                    OPER_SEQ,
                    STD_OPER_ID,
                    OPER,
                    OPER_DESC,
                    COMP_ITEM_ID,
                    COMP_ITEM_CODE,
                    COMP_ITEM_DESC,
                    COMP_ITEM_UNIT,
                    COMP_QTY,
                    COMP_YIELD_FACTOR,
                    EFFECTIVITY_DATE,
                    WIP_SUPPLY_TYPE,
                    WIP_SUPPLY_TYPE_NAME,
                    SUPPLY_INV_OPER,
                    TRAN_FLAG,
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
                    :IF_STD_BOM_DEF_HIS_N.IF_SEQ,
                    :IF_STD_BOM_DEF_HIS_N.IF_TIME,
                    :IF_STD_BOM_DEF_HIS_N.IF_CODE,
                    :IF_STD_BOM_DEF_HIS_N.IF_MSG,
                    :IF_STD_BOM_DEF_HIS_N.FACTORY,
                    :IF_STD_BOM_DEF_HIS_N.BOM_ID,
                    :IF_STD_BOM_DEF_HIS_N.ORG_ID,
                    :IF_STD_BOM_DEF_HIS_N.ORG_CODE,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_ID,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_CODE,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_DESC,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_STATUS,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_UNIT,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_TYPE,
                    :IF_STD_BOM_DEF_HIS_N.ALTERNATE_CODE,
                    :IF_STD_BOM_DEF_HIS_N.BOM_COMP_ID,
                    :IF_STD_BOM_DEF_HIS_N.COMP_SEQ,
                    :IF_STD_BOM_DEF_HIS_N.OPER_SEQ,
                    :IF_STD_BOM_DEF_HIS_N.STD_OPER_ID,
                    :IF_STD_BOM_DEF_HIS_N.OPER,
                    :IF_STD_BOM_DEF_HIS_N.OPER_DESC,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_ID,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_CODE,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_DESC,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_UNIT,
                    :IF_STD_BOM_DEF_HIS_N.COMP_QTY,
                    :IF_STD_BOM_DEF_HIS_N.COMP_YIELD_FACTOR,
                    :IF_STD_BOM_DEF_HIS_N.EFFECTIVITY_DATE,
                    :IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE,
                    :IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE_NAME,
                    :IF_STD_BOM_DEF_HIS_N.SUPPLY_INV_OPER,
                    :IF_STD_BOM_DEF_HIS_N.TRAN_FLAG,
                    :IF_STD_BOM_DEF_HIS_N.CMF_1,
                    :IF_STD_BOM_DEF_HIS_N.CMF_2,
                    :IF_STD_BOM_DEF_HIS_N.CMF_3,
                    :IF_STD_BOM_DEF_HIS_N.CMF_4,
                    :IF_STD_BOM_DEF_HIS_N.CMF_5,
                    :IF_STD_BOM_DEF_HIS_N.CMF_6,
                    :IF_STD_BOM_DEF_HIS_N.CMF_7,
                    :IF_STD_BOM_DEF_HIS_N.CMF_8,
                    :IF_STD_BOM_DEF_HIS_N.CMF_9,
                    :IF_STD_BOM_DEF_HIS_N.CMF_10,
                    :IF_STD_BOM_DEF_HIS_N.CREATE_USER_ID,
                    :IF_STD_BOM_DEF_HIS_N.CREATE_TIME,
                    :IF_STD_BOM_DEF_HIS_N.UPDATE_USER_ID,
                    :IF_STD_BOM_DEF_HIS_N.UPDATE_TIME
                FROM IF_STD_BOM_DEF_HIS
                WHERE IF_SEQ = :IF_STD_BOM_DEF_HIS_N.IF_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY\
 ,BOM_ID ,ORG_ID ,ORG_CODE ,ITEM_ID ,ITEM_CODE ,ITEM_DESC ,ITEM_STATUS ,ITEM_\
UNIT ,ITEM_TYPE ,ALTERNATE_CODE ,BOM_COMP_ID ,COMP_SEQ ,OPER_SEQ ,STD_OPER_ID\
 ,OPER ,OPER_DESC ,COMP_ITEM_ID ,COMP_ITEM_CODE ,COMP_ITEM_DESC ,COMP_ITEM_UN\
IT ,COMP_QTY ,COMP_YIELD_FACTOR ,EFFECTIVITY_DATE ,WIP_SUPPLY_TYPE ,WIP_SUPPL\
Y_TYPE_NAME ,SUPPLY_INV_OPER ,TRAN_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,C\
MF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_I\
D ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b\
13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28\
,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:\
b44,:b45  from IF_STD_BOM_DEF_HIS where IF_SEQ=:b0 for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )208;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_STD_BOM_DEF_HIS_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.BOM_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.ORG_ID);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ORG_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )4;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.ITEM_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_CODE);
            sqlstm.sqhstl[9] = (unsigned int  )41;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_DESC);
            sqlstm.sqhstl[10] = (unsigned int  )241;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_STATUS);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_UNIT);
            sqlstm.sqhstl[12] = (unsigned int  )4;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ALTERNATE_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.BOM_COMP_ID);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_SEQ);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.OPER_SEQ);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.STD_OPER_ID);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_STD_BOM_DEF_HIS_N.OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_STD_BOM_DEF_HIS_N.OPER_DESC);
            sqlstm.sqhstl[20] = (unsigned int  )241;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_ID);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_CODE);
            sqlstm.sqhstl[22] = (unsigned int  )41;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_DESC);
            sqlstm.sqhstl[23] = (unsigned int  )241;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_UNIT);
            sqlstm.sqhstl[24] = (unsigned int  )4;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_QTY);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_YIELD_FACTOR);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_STD_BOM_DEF_HIS_N.EFFECTIVITY_DATE);
            sqlstm.sqhstl[27] = (unsigned int  )15;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE_NAME);
            sqlstm.sqhstl[29] = (unsigned int  )81;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_STD_BOM_DEF_HIS_N.SUPPLY_INV_OPER);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_STD_BOM_DEF_HIS_N.TRAN_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_6);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_7);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_8);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_9);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_10);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CREATE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )15;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_STD_BOM_DEF_HIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_STD_BOM_DEF_HIS_N.UPDATE_TIME);
            sqlstm.sqhstl[45] = (unsigned int  )15;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.IF_SEQ);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
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
        DBU_del_null_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS_N, IF_STD_BOM_DEF_HIS);
    }

    DB_stop_query_timer("DBU_select_if_std_bom_def_his_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_if_std_bom_def_his_scalar(int sel_type, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_STD_BOM_DEF_HIS_N_TAG IF_STD_BOM_DEF_HIS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS_N, IF_STD_BOM_DEF_HIS);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM IF_STD_BOM_DEF_HIS
                WHERE IF_SEQ = :IF_STD_BOM_DEF_HIS_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from IF_STD_BOM_DEF_H\
IS where IF_SEQ=:b1";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )411;
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
            sqlstm.sqhstv[1] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.IF_SEQ);
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

    DB_stop_query_timer("DBU_select_if_std_bom_def_his_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_if_std_bom_def_his(int sel_type, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_STD_BOM_DEF_HIS_N_TAG IF_STD_BOM_DEF_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS_N, IF_STD_BOM_DEF_HIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM IF_STD_BOM_DEF_HIS
                WHERE IF_SEQ = :IF_STD_BOM_DEF_HIS_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from IF_STD_BOM_DEF_HIS  where IF_SEQ=:b\
0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )434;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
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

    DB_stop_query_timer("DBU_delete_if_std_bom_def_his", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_if_std_bom_def_his(struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_STD_BOM_DEF_HIS_N_TAG IF_STD_BOM_DEF_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS_N, IF_STD_BOM_DEF_HIS);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO IF_STD_BOM_DEF_HIS( 
                    IF_SEQ, 
                    IF_TIME, 
                    IF_CODE, 
                    IF_MSG, 
                    FACTORY, 
                    BOM_ID, 
                    ORG_ID, 
                    ORG_CODE, 
                    ITEM_ID, 
                    ITEM_CODE, 
                    ITEM_DESC, 
                    ITEM_STATUS, 
                    ITEM_UNIT, 
                    ITEM_TYPE, 
                    ALTERNATE_CODE, 
                    BOM_COMP_ID, 
                    COMP_SEQ, 
                    OPER_SEQ, 
                    STD_OPER_ID, 
                    OPER, 
                    OPER_DESC, 
                    COMP_ITEM_ID, 
                    COMP_ITEM_CODE, 
                    COMP_ITEM_DESC, 
                    COMP_ITEM_UNIT, 
                    COMP_QTY, 
                    COMP_YIELD_FACTOR, 
                    EFFECTIVITY_DATE, 
                    WIP_SUPPLY_TYPE, 
                    WIP_SUPPLY_TYPE_NAME, 
                    SUPPLY_INV_OPER, 
                    TRAN_FLAG, 
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
                    :IF_STD_BOM_DEF_HIS_N.IF_SEQ,
                    :IF_STD_BOM_DEF_HIS_N.IF_TIME,
                    :IF_STD_BOM_DEF_HIS_N.IF_CODE,
                    :IF_STD_BOM_DEF_HIS_N.IF_MSG,
                    :IF_STD_BOM_DEF_HIS_N.FACTORY,
                    :IF_STD_BOM_DEF_HIS_N.BOM_ID,
                    :IF_STD_BOM_DEF_HIS_N.ORG_ID,
                    :IF_STD_BOM_DEF_HIS_N.ORG_CODE,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_ID,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_CODE,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_DESC,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_STATUS,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_UNIT,
                    :IF_STD_BOM_DEF_HIS_N.ITEM_TYPE,
                    :IF_STD_BOM_DEF_HIS_N.ALTERNATE_CODE,
                    :IF_STD_BOM_DEF_HIS_N.BOM_COMP_ID,
                    :IF_STD_BOM_DEF_HIS_N.COMP_SEQ,
                    :IF_STD_BOM_DEF_HIS_N.OPER_SEQ,
                    :IF_STD_BOM_DEF_HIS_N.STD_OPER_ID,
                    :IF_STD_BOM_DEF_HIS_N.OPER,
                    :IF_STD_BOM_DEF_HIS_N.OPER_DESC,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_ID,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_CODE,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_DESC,
                    :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_UNIT,
                    :IF_STD_BOM_DEF_HIS_N.COMP_QTY,
                    :IF_STD_BOM_DEF_HIS_N.COMP_YIELD_FACTOR,
                    :IF_STD_BOM_DEF_HIS_N.EFFECTIVITY_DATE,
                    :IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE,
                    :IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE_NAME,
                    :IF_STD_BOM_DEF_HIS_N.SUPPLY_INV_OPER,
                    :IF_STD_BOM_DEF_HIS_N.TRAN_FLAG,
                    :IF_STD_BOM_DEF_HIS_N.CMF_1,
                    :IF_STD_BOM_DEF_HIS_N.CMF_2,
                    :IF_STD_BOM_DEF_HIS_N.CMF_3,
                    :IF_STD_BOM_DEF_HIS_N.CMF_4,
                    :IF_STD_BOM_DEF_HIS_N.CMF_5,
                    :IF_STD_BOM_DEF_HIS_N.CMF_6,
                    :IF_STD_BOM_DEF_HIS_N.CMF_7,
                    :IF_STD_BOM_DEF_HIS_N.CMF_8,
                    :IF_STD_BOM_DEF_HIS_N.CMF_9,
                    :IF_STD_BOM_DEF_HIS_N.CMF_10,
                    :IF_STD_BOM_DEF_HIS_N.CREATE_USER_ID,
                    :IF_STD_BOM_DEF_HIS_N.CREATE_TIME,
                    :IF_STD_BOM_DEF_HIS_N.UPDATE_USER_ID,
                    :IF_STD_BOM_DEF_HIS_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into IF_STD_BOM_DEF_HIS (IF_SEQ,IF_TIME,IF_CODE,I\
F_MSG,FACTORY,BOM_ID,ORG_ID,ORG_CODE,ITEM_ID,ITEM_CODE,ITEM_DESC,ITEM_STATUS,\
ITEM_UNIT,ITEM_TYPE,ALTERNATE_CODE,BOM_COMP_ID,COMP_SEQ,OPER_SEQ,STD_OPER_ID,\
OPER,OPER_DESC,COMP_ITEM_ID,COMP_ITEM_CODE,COMP_ITEM_DESC,COMP_ITEM_UNIT,COMP\
_QTY,COMP_YIELD_FACTOR,EFFECTIVITY_DATE,WIP_SUPPLY_TYPE,WIP_SUPPLY_TYPE_NAME,\
SUPPLY_INV_OPER,TRAN_FLAG,CMF_1,CMF_2,CMF_3,CMF_4,CMF_5,CMF_6,CMF_7,CMF_8,CMF\
_9,CMF_10,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) values (:b0,\
:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:\
b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b3\
3,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )453;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.IF_SEQ);
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_TIME);
    sqlstm.sqhstl[1] = (unsigned int  )15;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_CODE);
    sqlstm.sqhstl[2] = (unsigned int  )2;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_MSG);
    sqlstm.sqhstl[3] = (unsigned int  )201;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(IF_STD_BOM_DEF_HIS_N.FACTORY);
    sqlstm.sqhstl[4] = (unsigned int  )11;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.BOM_ID);
    sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.ORG_ID);
    sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ORG_CODE);
    sqlstm.sqhstl[7] = (unsigned int  )4;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.ITEM_ID);
    sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_CODE);
    sqlstm.sqhstl[9] = (unsigned int  )41;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_DESC);
    sqlstm.sqhstl[10] = (unsigned int  )241;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_STATUS);
    sqlstm.sqhstl[11] = (unsigned int  )11;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_UNIT);
    sqlstm.sqhstl[12] = (unsigned int  )4;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_TYPE);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ALTERNATE_CODE);
    sqlstm.sqhstl[14] = (unsigned int  )11;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.BOM_COMP_ID);
    sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_SEQ);
    sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.OPER_SEQ);
    sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.STD_OPER_ID);
    sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(IF_STD_BOM_DEF_HIS_N.OPER);
    sqlstm.sqhstl[19] = (unsigned int  )11;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(IF_STD_BOM_DEF_HIS_N.OPER_DESC);
    sqlstm.sqhstl[20] = (unsigned int  )241;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_ID);
    sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_CODE);
    sqlstm.sqhstl[22] = (unsigned int  )41;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_DESC);
    sqlstm.sqhstl[23] = (unsigned int  )241;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_UNIT);
    sqlstm.sqhstl[24] = (unsigned int  )4;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_QTY);
    sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_YIELD_FACTOR);
    sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(IF_STD_BOM_DEF_HIS_N.EFFECTIVITY_DATE);
    sqlstm.sqhstl[27] = (unsigned int  )15;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE);
    sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE_NAME);
    sqlstm.sqhstl[29] = (unsigned int  )81;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(IF_STD_BOM_DEF_HIS_N.SUPPLY_INV_OPER);
    sqlstm.sqhstl[30] = (unsigned int  )11;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(IF_STD_BOM_DEF_HIS_N.TRAN_FLAG);
    sqlstm.sqhstl[31] = (unsigned int  )2;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_1);
    sqlstm.sqhstl[32] = (unsigned int  )51;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_2);
    sqlstm.sqhstl[33] = (unsigned int  )51;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_3);
    sqlstm.sqhstl[34] = (unsigned int  )51;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_4);
    sqlstm.sqhstl[35] = (unsigned int  )51;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_5);
    sqlstm.sqhstl[36] = (unsigned int  )51;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_6);
    sqlstm.sqhstl[37] = (unsigned int  )51;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_7);
    sqlstm.sqhstl[38] = (unsigned int  )51;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_8);
    sqlstm.sqhstl[39] = (unsigned int  )51;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_9);
    sqlstm.sqhstl[40] = (unsigned int  )51;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_10);
    sqlstm.sqhstl[41] = (unsigned int  )51;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CREATE_USER_ID);
    sqlstm.sqhstl[42] = (unsigned int  )21;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CREATE_TIME);
    sqlstm.sqhstl[43] = (unsigned int  )15;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(IF_STD_BOM_DEF_HIS_N.UPDATE_USER_ID);
    sqlstm.sqhstl[44] = (unsigned int  )21;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(IF_STD_BOM_DEF_HIS_N.UPDATE_TIME);
    sqlstm.sqhstl[45] = (unsigned int  )15;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_if_std_bom_def_his", 0);
}


/* SQL UPDATE Function */
void DBU_update_if_std_bom_def_his(int sel_type, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_STD_BOM_DEF_HIS_N_TAG IF_STD_BOM_DEF_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS_N, IF_STD_BOM_DEF_HIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE IF_STD_BOM_DEF_HIS SET
                    IF_TIME = :IF_STD_BOM_DEF_HIS_N.IF_TIME,
                    IF_CODE = :IF_STD_BOM_DEF_HIS_N.IF_CODE,
                    IF_MSG = :IF_STD_BOM_DEF_HIS_N.IF_MSG,
                    FACTORY = :IF_STD_BOM_DEF_HIS_N.FACTORY,
                    BOM_ID = :IF_STD_BOM_DEF_HIS_N.BOM_ID,
                    ORG_ID = :IF_STD_BOM_DEF_HIS_N.ORG_ID,
                    ORG_CODE = :IF_STD_BOM_DEF_HIS_N.ORG_CODE,
                    ITEM_ID = :IF_STD_BOM_DEF_HIS_N.ITEM_ID,
                    ITEM_CODE = :IF_STD_BOM_DEF_HIS_N.ITEM_CODE,
                    ITEM_DESC = :IF_STD_BOM_DEF_HIS_N.ITEM_DESC,
                    ITEM_STATUS = :IF_STD_BOM_DEF_HIS_N.ITEM_STATUS,
                    ITEM_UNIT = :IF_STD_BOM_DEF_HIS_N.ITEM_UNIT,
                    ITEM_TYPE = :IF_STD_BOM_DEF_HIS_N.ITEM_TYPE,
                    ALTERNATE_CODE = :IF_STD_BOM_DEF_HIS_N.ALTERNATE_CODE,
                    BOM_COMP_ID = :IF_STD_BOM_DEF_HIS_N.BOM_COMP_ID,
                    COMP_SEQ = :IF_STD_BOM_DEF_HIS_N.COMP_SEQ,
                    OPER_SEQ = :IF_STD_BOM_DEF_HIS_N.OPER_SEQ,
                    STD_OPER_ID = :IF_STD_BOM_DEF_HIS_N.STD_OPER_ID,
                    OPER = :IF_STD_BOM_DEF_HIS_N.OPER,
                    OPER_DESC = :IF_STD_BOM_DEF_HIS_N.OPER_DESC,
                    COMP_ITEM_ID = :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_ID,
                    COMP_ITEM_CODE = :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_CODE,
                    COMP_ITEM_DESC = :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_DESC,
                    COMP_ITEM_UNIT = :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_UNIT,
                    COMP_QTY = :IF_STD_BOM_DEF_HIS_N.COMP_QTY,
                    COMP_YIELD_FACTOR = :IF_STD_BOM_DEF_HIS_N.COMP_YIELD_FACTOR,
                    EFFECTIVITY_DATE = :IF_STD_BOM_DEF_HIS_N.EFFECTIVITY_DATE,
                    WIP_SUPPLY_TYPE = :IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE,
                    WIP_SUPPLY_TYPE_NAME = :IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE_NAME,
                    SUPPLY_INV_OPER = :IF_STD_BOM_DEF_HIS_N.SUPPLY_INV_OPER,
                    TRAN_FLAG = :IF_STD_BOM_DEF_HIS_N.TRAN_FLAG,
                    CMF_1 = :IF_STD_BOM_DEF_HIS_N.CMF_1,
                    CMF_2 = :IF_STD_BOM_DEF_HIS_N.CMF_2,
                    CMF_3 = :IF_STD_BOM_DEF_HIS_N.CMF_3,
                    CMF_4 = :IF_STD_BOM_DEF_HIS_N.CMF_4,
                    CMF_5 = :IF_STD_BOM_DEF_HIS_N.CMF_5,
                    CMF_6 = :IF_STD_BOM_DEF_HIS_N.CMF_6,
                    CMF_7 = :IF_STD_BOM_DEF_HIS_N.CMF_7,
                    CMF_8 = :IF_STD_BOM_DEF_HIS_N.CMF_8,
                    CMF_9 = :IF_STD_BOM_DEF_HIS_N.CMF_9,
                    CMF_10 = :IF_STD_BOM_DEF_HIS_N.CMF_10,
                    CREATE_USER_ID = :IF_STD_BOM_DEF_HIS_N.CREATE_USER_ID,
                    CREATE_TIME = :IF_STD_BOM_DEF_HIS_N.CREATE_TIME,
                    UPDATE_USER_ID = :IF_STD_BOM_DEF_HIS_N.UPDATE_USER_ID,
                    UPDATE_TIME = :IF_STD_BOM_DEF_HIS_N.UPDATE_TIME
                WHERE IF_SEQ = :IF_STD_BOM_DEF_HIS_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update IF_STD_BOM_DEF_HIS  set IF_TIME=:b0,IF_CO\
DE=:b1,IF_MSG=:b2,FACTORY=:b3,BOM_ID=:b4,ORG_ID=:b5,ORG_CODE=:b6,ITEM_ID=:b7,\
ITEM_CODE=:b8,ITEM_DESC=:b9,ITEM_STATUS=:b10,ITEM_UNIT=:b11,ITEM_TYPE=:b12,AL\
TERNATE_CODE=:b13,BOM_COMP_ID=:b14,COMP_SEQ=:b15,OPER_SEQ=:b16,STD_OPER_ID=:b\
17,OPER=:b18,OPER_DESC=:b19,COMP_ITEM_ID=:b20,COMP_ITEM_CODE=:b21,COMP_ITEM_D\
ESC=:b22,COMP_ITEM_UNIT=:b23,COMP_QTY=:b24,COMP_YIELD_FACTOR=:b25,EFFECTIVITY\
_DATE=:b26,WIP_SUPPLY_TYPE=:b27,WIP_SUPPLY_TYPE_NAME=:b28,SUPPLY_INV_OPER=:b2\
9,TRAN_FLAG=:b30,CMF_1=:b31,CMF_2=:b32,CMF_3=:b33,CMF_4=:b34,CMF_5=:b35,CMF_6\
=:b36,CMF_7=:b37,CMF_8=:b38,CMF_9=:b39,CMF_10=:b40,CREATE_USER_ID=:b41,CREATE\
_TIME=:b42,UPDATE_USER_ID=:b43,UPDATE_TIME=:b44 where IF_SEQ=:b45";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )652;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_TIME);
            sqlstm.sqhstl[0] = (unsigned int  )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_MSG);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_STD_BOM_DEF_HIS_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.BOM_ID);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.ORG_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ORG_CODE);
            sqlstm.sqhstl[6] = (unsigned int  )4;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.ITEM_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_CODE);
            sqlstm.sqhstl[8] = (unsigned int  )41;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_DESC);
            sqlstm.sqhstl[9] = (unsigned int  )241;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_STATUS);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_UNIT);
            sqlstm.sqhstl[11] = (unsigned int  )4;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ALTERNATE_CODE);
            sqlstm.sqhstl[13] = (unsigned int  )11;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.BOM_COMP_ID);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.OPER_SEQ);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.STD_OPER_ID);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(IF_STD_BOM_DEF_HIS_N.OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_STD_BOM_DEF_HIS_N.OPER_DESC);
            sqlstm.sqhstl[19] = (unsigned int  )241;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_ID);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_CODE);
            sqlstm.sqhstl[21] = (unsigned int  )41;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_DESC);
            sqlstm.sqhstl[22] = (unsigned int  )241;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_UNIT);
            sqlstm.sqhstl[23] = (unsigned int  )4;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_QTY);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_YIELD_FACTOR);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(IF_STD_BOM_DEF_HIS_N.EFFECTIVITY_DATE);
            sqlstm.sqhstl[26] = (unsigned int  )15;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE_NAME);
            sqlstm.sqhstl[28] = (unsigned int  )81;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_STD_BOM_DEF_HIS_N.SUPPLY_INV_OPER);
            sqlstm.sqhstl[29] = (unsigned int  )11;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_STD_BOM_DEF_HIS_N.TRAN_FLAG);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_1);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_2);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_3);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_4);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_5);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_6);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_7);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_8);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_9);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_10);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CREATE_TIME);
            sqlstm.sqhstl[42] = (unsigned int  )15;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_STD_BOM_DEF_HIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[43] = (unsigned int  )21;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_STD_BOM_DEF_HIS_N.UPDATE_TIME);
            sqlstm.sqhstl[44] = (unsigned int  )15;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.IF_SEQ);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_if_std_bom_def_his", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_if_std_bom_def_his(int sel_type, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_STD_BOM_DEF_HIS_N_TAG IF_STD_BOM_DEF_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS_N, IF_STD_BOM_DEF_HIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_IF_STD_BOM_DEF_HIS_CUR_1 CURSOR FOR
                SELECT 
                    IF_SEQ,
                    IF_TIME,
                    IF_CODE,
                    IF_MSG,
                    FACTORY,
                    BOM_ID,
                    ORG_ID,
                    ORG_CODE,
                    ITEM_ID,
                    ITEM_CODE,
                    ITEM_DESC,
                    ITEM_STATUS,
                    ITEM_UNIT,
                    ITEM_TYPE,
                    ALTERNATE_CODE,
                    BOM_COMP_ID,
                    COMP_SEQ,
                    OPER_SEQ,
                    STD_OPER_ID,
                    OPER,
                    OPER_DESC,
                    COMP_ITEM_ID,
                    COMP_ITEM_CODE,
                    COMP_ITEM_DESC,
                    COMP_ITEM_UNIT,
                    COMP_QTY,
                    COMP_YIELD_FACTOR,
                    EFFECTIVITY_DATE,
                    WIP_SUPPLY_TYPE,
                    WIP_SUPPLY_TYPE_NAME,
                    SUPPLY_INV_OPER,
                    TRAN_FLAG,
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
                FROM IF_STD_BOM_DEF_HIS
                ORDER BY IF_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_IF_STD_BOM_DEF_HIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )851;
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

    DB_stop_query_timer("DBU_open_if_std_bom_def_his", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_if_std_bom_def_his(int sel_type, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_STD_BOM_DEF_HIS_N_TAG IF_STD_BOM_DEF_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_IF_STD_BOM_DEF_HIS_CUR_1 INTO
                :IF_STD_BOM_DEF_HIS_N.IF_SEQ,
                :IF_STD_BOM_DEF_HIS_N.IF_TIME,
                :IF_STD_BOM_DEF_HIS_N.IF_CODE,
                :IF_STD_BOM_DEF_HIS_N.IF_MSG,
                :IF_STD_BOM_DEF_HIS_N.FACTORY,
                :IF_STD_BOM_DEF_HIS_N.BOM_ID,
                :IF_STD_BOM_DEF_HIS_N.ORG_ID,
                :IF_STD_BOM_DEF_HIS_N.ORG_CODE,
                :IF_STD_BOM_DEF_HIS_N.ITEM_ID,
                :IF_STD_BOM_DEF_HIS_N.ITEM_CODE,
                :IF_STD_BOM_DEF_HIS_N.ITEM_DESC,
                :IF_STD_BOM_DEF_HIS_N.ITEM_STATUS,
                :IF_STD_BOM_DEF_HIS_N.ITEM_UNIT,
                :IF_STD_BOM_DEF_HIS_N.ITEM_TYPE,
                :IF_STD_BOM_DEF_HIS_N.ALTERNATE_CODE,
                :IF_STD_BOM_DEF_HIS_N.BOM_COMP_ID,
                :IF_STD_BOM_DEF_HIS_N.COMP_SEQ,
                :IF_STD_BOM_DEF_HIS_N.OPER_SEQ,
                :IF_STD_BOM_DEF_HIS_N.STD_OPER_ID,
                :IF_STD_BOM_DEF_HIS_N.OPER,
                :IF_STD_BOM_DEF_HIS_N.OPER_DESC,
                :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_ID,
                :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_CODE,
                :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_DESC,
                :IF_STD_BOM_DEF_HIS_N.COMP_ITEM_UNIT,
                :IF_STD_BOM_DEF_HIS_N.COMP_QTY,
                :IF_STD_BOM_DEF_HIS_N.COMP_YIELD_FACTOR,
                :IF_STD_BOM_DEF_HIS_N.EFFECTIVITY_DATE,
                :IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE,
                :IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE_NAME,
                :IF_STD_BOM_DEF_HIS_N.SUPPLY_INV_OPER,
                :IF_STD_BOM_DEF_HIS_N.TRAN_FLAG,
                :IF_STD_BOM_DEF_HIS_N.CMF_1,
                :IF_STD_BOM_DEF_HIS_N.CMF_2,
                :IF_STD_BOM_DEF_HIS_N.CMF_3,
                :IF_STD_BOM_DEF_HIS_N.CMF_4,
                :IF_STD_BOM_DEF_HIS_N.CMF_5,
                :IF_STD_BOM_DEF_HIS_N.CMF_6,
                :IF_STD_BOM_DEF_HIS_N.CMF_7,
                :IF_STD_BOM_DEF_HIS_N.CMF_8,
                :IF_STD_BOM_DEF_HIS_N.CMF_9,
                :IF_STD_BOM_DEF_HIS_N.CMF_10,
                :IF_STD_BOM_DEF_HIS_N.CREATE_USER_ID,
                :IF_STD_BOM_DEF_HIS_N.CREATE_TIME,
                :IF_STD_BOM_DEF_HIS_N.UPDATE_USER_ID,
                :IF_STD_BOM_DEF_HIS_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )866;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_STD_BOM_DEF_HIS_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_STD_BOM_DEF_HIS_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.BOM_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.ORG_ID);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ORG_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )4;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.ITEM_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_CODE);
            sqlstm.sqhstl[9] = (unsigned int  )41;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_DESC);
            sqlstm.sqhstl[10] = (unsigned int  )241;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_STATUS);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_UNIT);
            sqlstm.sqhstl[12] = (unsigned int  )4;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ITEM_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_STD_BOM_DEF_HIS_N.ALTERNATE_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.BOM_COMP_ID);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_SEQ);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.OPER_SEQ);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.STD_OPER_ID);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_STD_BOM_DEF_HIS_N.OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_STD_BOM_DEF_HIS_N.OPER_DESC);
            sqlstm.sqhstl[20] = (unsigned int  )241;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_ID);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_CODE);
            sqlstm.sqhstl[22] = (unsigned int  )41;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_DESC);
            sqlstm.sqhstl[23] = (unsigned int  )241;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_STD_BOM_DEF_HIS_N.COMP_ITEM_UNIT);
            sqlstm.sqhstl[24] = (unsigned int  )4;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_QTY);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.COMP_YIELD_FACTOR);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_STD_BOM_DEF_HIS_N.EFFECTIVITY_DATE);
            sqlstm.sqhstl[27] = (unsigned int  )15;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_STD_BOM_DEF_HIS_N.WIP_SUPPLY_TYPE_NAME);
            sqlstm.sqhstl[29] = (unsigned int  )81;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_STD_BOM_DEF_HIS_N.SUPPLY_INV_OPER);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_STD_BOM_DEF_HIS_N.TRAN_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_6);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_7);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_8);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_9);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CMF_10);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_STD_BOM_DEF_HIS_N.CREATE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )15;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_STD_BOM_DEF_HIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_STD_BOM_DEF_HIS_N.UPDATE_TIME);
            sqlstm.sqhstl[45] = (unsigned int  )15;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
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
        DBU_del_null_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS_N, IF_STD_BOM_DEF_HIS);
    }

    DB_stop_query_timer("DBU_fetch_if_std_bom_def_his", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_if_std_bom_def_his(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_IF_STD_BOM_DEF_HIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1065;
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

    DB_stop_query_timer("DBU_close_if_std_bom_def_his", sel_type);
}


/* Initialize Function */
void DBU_init_if_std_bom_def_his(struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    /* memset by Space */
    memset(IF_STD_BOM_DEF_HIS, ' ', sizeof(struct IF_STD_BOM_DEF_HIS_TAG));
    
    IF_STD_BOM_DEF_HIS->IF_SEQ = 0;
    IF_STD_BOM_DEF_HIS->BOM_ID = 0;
    IF_STD_BOM_DEF_HIS->ORG_ID = 0;
    IF_STD_BOM_DEF_HIS->ITEM_ID = 0;
    IF_STD_BOM_DEF_HIS->BOM_COMP_ID = 0;
    IF_STD_BOM_DEF_HIS->COMP_SEQ = 0;
    IF_STD_BOM_DEF_HIS->OPER_SEQ = 0;
    IF_STD_BOM_DEF_HIS->STD_OPER_ID = 0;
    IF_STD_BOM_DEF_HIS->COMP_ITEM_ID = 0;
    IF_STD_BOM_DEF_HIS->COMP_QTY = 0;
    IF_STD_BOM_DEF_HIS->COMP_YIELD_FACTOR = 0;
    IF_STD_BOM_DEF_HIS->WIP_SUPPLY_TYPE = 0;
}


/* Add Null Function */
void DBU_add_null_if_std_bom_def_his(struct IF_STD_BOM_DEF_HIS_N_TAG *IF_STD_BOM_DEF_HIS_N, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    /* memset by NULL */
    memset(IF_STD_BOM_DEF_HIS_N, '\0', sizeof(struct IF_STD_BOM_DEF_HIS_N_TAG));
    
    IF_STD_BOM_DEF_HIS_N->IF_SEQ = IF_STD_BOM_DEF_HIS->IF_SEQ;
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->IF_TIME, IF_STD_BOM_DEF_HIS->IF_TIME, sizeof(IF_STD_BOM_DEF_HIS->IF_TIME));
    IF_STD_BOM_DEF_HIS_N->IF_CODE[0] = IF_STD_BOM_DEF_HIS->IF_CODE;
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->IF_MSG, IF_STD_BOM_DEF_HIS->IF_MSG, sizeof(IF_STD_BOM_DEF_HIS->IF_MSG));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->FACTORY, IF_STD_BOM_DEF_HIS->FACTORY, sizeof(IF_STD_BOM_DEF_HIS->FACTORY));
    IF_STD_BOM_DEF_HIS_N->BOM_ID = IF_STD_BOM_DEF_HIS->BOM_ID;
    IF_STD_BOM_DEF_HIS_N->ORG_ID = IF_STD_BOM_DEF_HIS->ORG_ID;
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->ORG_CODE, IF_STD_BOM_DEF_HIS->ORG_CODE, sizeof(IF_STD_BOM_DEF_HIS->ORG_CODE));
    IF_STD_BOM_DEF_HIS_N->ITEM_ID = IF_STD_BOM_DEF_HIS->ITEM_ID;
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->ITEM_CODE, IF_STD_BOM_DEF_HIS->ITEM_CODE, sizeof(IF_STD_BOM_DEF_HIS->ITEM_CODE));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->ITEM_DESC, IF_STD_BOM_DEF_HIS->ITEM_DESC, sizeof(IF_STD_BOM_DEF_HIS->ITEM_DESC));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->ITEM_STATUS, IF_STD_BOM_DEF_HIS->ITEM_STATUS, sizeof(IF_STD_BOM_DEF_HIS->ITEM_STATUS));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->ITEM_UNIT, IF_STD_BOM_DEF_HIS->ITEM_UNIT, sizeof(IF_STD_BOM_DEF_HIS->ITEM_UNIT));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->ITEM_TYPE, IF_STD_BOM_DEF_HIS->ITEM_TYPE, sizeof(IF_STD_BOM_DEF_HIS->ITEM_TYPE));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->ALTERNATE_CODE, IF_STD_BOM_DEF_HIS->ALTERNATE_CODE, sizeof(IF_STD_BOM_DEF_HIS->ALTERNATE_CODE));
    IF_STD_BOM_DEF_HIS_N->BOM_COMP_ID = IF_STD_BOM_DEF_HIS->BOM_COMP_ID;
    IF_STD_BOM_DEF_HIS_N->COMP_SEQ = IF_STD_BOM_DEF_HIS->COMP_SEQ;
    IF_STD_BOM_DEF_HIS_N->OPER_SEQ = IF_STD_BOM_DEF_HIS->OPER_SEQ;
    IF_STD_BOM_DEF_HIS_N->STD_OPER_ID = IF_STD_BOM_DEF_HIS->STD_OPER_ID;
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->OPER, IF_STD_BOM_DEF_HIS->OPER, sizeof(IF_STD_BOM_DEF_HIS->OPER));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->OPER_DESC, IF_STD_BOM_DEF_HIS->OPER_DESC, sizeof(IF_STD_BOM_DEF_HIS->OPER_DESC));
    IF_STD_BOM_DEF_HIS_N->COMP_ITEM_ID = IF_STD_BOM_DEF_HIS->COMP_ITEM_ID;
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->COMP_ITEM_CODE, IF_STD_BOM_DEF_HIS->COMP_ITEM_CODE, sizeof(IF_STD_BOM_DEF_HIS->COMP_ITEM_CODE));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->COMP_ITEM_DESC, IF_STD_BOM_DEF_HIS->COMP_ITEM_DESC, sizeof(IF_STD_BOM_DEF_HIS->COMP_ITEM_DESC));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->COMP_ITEM_UNIT, IF_STD_BOM_DEF_HIS->COMP_ITEM_UNIT, sizeof(IF_STD_BOM_DEF_HIS->COMP_ITEM_UNIT));
    IF_STD_BOM_DEF_HIS_N->COMP_QTY = IF_STD_BOM_DEF_HIS->COMP_QTY;
    IF_STD_BOM_DEF_HIS_N->COMP_YIELD_FACTOR = IF_STD_BOM_DEF_HIS->COMP_YIELD_FACTOR;
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->EFFECTIVITY_DATE, IF_STD_BOM_DEF_HIS->EFFECTIVITY_DATE, sizeof(IF_STD_BOM_DEF_HIS->EFFECTIVITY_DATE));
    IF_STD_BOM_DEF_HIS_N->WIP_SUPPLY_TYPE = IF_STD_BOM_DEF_HIS->WIP_SUPPLY_TYPE;
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->WIP_SUPPLY_TYPE_NAME, IF_STD_BOM_DEF_HIS->WIP_SUPPLY_TYPE_NAME, sizeof(IF_STD_BOM_DEF_HIS->WIP_SUPPLY_TYPE_NAME));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->SUPPLY_INV_OPER, IF_STD_BOM_DEF_HIS->SUPPLY_INV_OPER, sizeof(IF_STD_BOM_DEF_HIS->SUPPLY_INV_OPER));
    IF_STD_BOM_DEF_HIS_N->TRAN_FLAG[0] = IF_STD_BOM_DEF_HIS->TRAN_FLAG;
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CMF_1, IF_STD_BOM_DEF_HIS->CMF_1, sizeof(IF_STD_BOM_DEF_HIS->CMF_1));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CMF_2, IF_STD_BOM_DEF_HIS->CMF_2, sizeof(IF_STD_BOM_DEF_HIS->CMF_2));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CMF_3, IF_STD_BOM_DEF_HIS->CMF_3, sizeof(IF_STD_BOM_DEF_HIS->CMF_3));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CMF_4, IF_STD_BOM_DEF_HIS->CMF_4, sizeof(IF_STD_BOM_DEF_HIS->CMF_4));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CMF_5, IF_STD_BOM_DEF_HIS->CMF_5, sizeof(IF_STD_BOM_DEF_HIS->CMF_5));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CMF_6, IF_STD_BOM_DEF_HIS->CMF_6, sizeof(IF_STD_BOM_DEF_HIS->CMF_6));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CMF_7, IF_STD_BOM_DEF_HIS->CMF_7, sizeof(IF_STD_BOM_DEF_HIS->CMF_7));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CMF_8, IF_STD_BOM_DEF_HIS->CMF_8, sizeof(IF_STD_BOM_DEF_HIS->CMF_8));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CMF_9, IF_STD_BOM_DEF_HIS->CMF_9, sizeof(IF_STD_BOM_DEF_HIS->CMF_9));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CMF_10, IF_STD_BOM_DEF_HIS->CMF_10, sizeof(IF_STD_BOM_DEF_HIS->CMF_10));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CREATE_USER_ID, IF_STD_BOM_DEF_HIS->CREATE_USER_ID, sizeof(IF_STD_BOM_DEF_HIS->CREATE_USER_ID));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->CREATE_TIME, IF_STD_BOM_DEF_HIS->CREATE_TIME, sizeof(IF_STD_BOM_DEF_HIS->CREATE_TIME));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->UPDATE_USER_ID, IF_STD_BOM_DEF_HIS->UPDATE_USER_ID, sizeof(IF_STD_BOM_DEF_HIS->UPDATE_USER_ID));
    MEMCPY_AN(IF_STD_BOM_DEF_HIS_N->UPDATE_TIME, IF_STD_BOM_DEF_HIS->UPDATE_TIME, sizeof(IF_STD_BOM_DEF_HIS->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_if_std_bom_def_his(struct IF_STD_BOM_DEF_HIS_N_TAG *IF_STD_BOM_DEF_HIS_N, struct IF_STD_BOM_DEF_HIS_TAG *IF_STD_BOM_DEF_HIS)
{
    IF_STD_BOM_DEF_HIS->IF_SEQ = IF_STD_BOM_DEF_HIS_N->IF_SEQ;
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->IF_TIME, IF_STD_BOM_DEF_HIS_N->IF_TIME, sizeof(IF_STD_BOM_DEF_HIS->IF_TIME));
    IF_STD_BOM_DEF_HIS->IF_CODE = IF_STD_BOM_DEF_HIS_N->IF_CODE[0];
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->IF_MSG, IF_STD_BOM_DEF_HIS_N->IF_MSG, sizeof(IF_STD_BOM_DEF_HIS->IF_MSG));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->FACTORY, IF_STD_BOM_DEF_HIS_N->FACTORY, sizeof(IF_STD_BOM_DEF_HIS->FACTORY));
    IF_STD_BOM_DEF_HIS->BOM_ID = IF_STD_BOM_DEF_HIS_N->BOM_ID;
    IF_STD_BOM_DEF_HIS->ORG_ID = IF_STD_BOM_DEF_HIS_N->ORG_ID;
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->ORG_CODE, IF_STD_BOM_DEF_HIS_N->ORG_CODE, sizeof(IF_STD_BOM_DEF_HIS->ORG_CODE));
    IF_STD_BOM_DEF_HIS->ITEM_ID = IF_STD_BOM_DEF_HIS_N->ITEM_ID;
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->ITEM_CODE, IF_STD_BOM_DEF_HIS_N->ITEM_CODE, sizeof(IF_STD_BOM_DEF_HIS->ITEM_CODE));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->ITEM_DESC, IF_STD_BOM_DEF_HIS_N->ITEM_DESC, sizeof(IF_STD_BOM_DEF_HIS->ITEM_DESC));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->ITEM_STATUS, IF_STD_BOM_DEF_HIS_N->ITEM_STATUS, sizeof(IF_STD_BOM_DEF_HIS->ITEM_STATUS));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->ITEM_UNIT, IF_STD_BOM_DEF_HIS_N->ITEM_UNIT, sizeof(IF_STD_BOM_DEF_HIS->ITEM_UNIT));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->ITEM_TYPE, IF_STD_BOM_DEF_HIS_N->ITEM_TYPE, sizeof(IF_STD_BOM_DEF_HIS->ITEM_TYPE));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->ALTERNATE_CODE, IF_STD_BOM_DEF_HIS_N->ALTERNATE_CODE, sizeof(IF_STD_BOM_DEF_HIS->ALTERNATE_CODE));
    IF_STD_BOM_DEF_HIS->BOM_COMP_ID = IF_STD_BOM_DEF_HIS_N->BOM_COMP_ID;
    IF_STD_BOM_DEF_HIS->COMP_SEQ = IF_STD_BOM_DEF_HIS_N->COMP_SEQ;
    IF_STD_BOM_DEF_HIS->OPER_SEQ = IF_STD_BOM_DEF_HIS_N->OPER_SEQ;
    IF_STD_BOM_DEF_HIS->STD_OPER_ID = IF_STD_BOM_DEF_HIS_N->STD_OPER_ID;
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->OPER, IF_STD_BOM_DEF_HIS_N->OPER, sizeof(IF_STD_BOM_DEF_HIS->OPER));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->OPER_DESC, IF_STD_BOM_DEF_HIS_N->OPER_DESC, sizeof(IF_STD_BOM_DEF_HIS->OPER_DESC));
    IF_STD_BOM_DEF_HIS->COMP_ITEM_ID = IF_STD_BOM_DEF_HIS_N->COMP_ITEM_ID;
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->COMP_ITEM_CODE, IF_STD_BOM_DEF_HIS_N->COMP_ITEM_CODE, sizeof(IF_STD_BOM_DEF_HIS->COMP_ITEM_CODE));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->COMP_ITEM_DESC, IF_STD_BOM_DEF_HIS_N->COMP_ITEM_DESC, sizeof(IF_STD_BOM_DEF_HIS->COMP_ITEM_DESC));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->COMP_ITEM_UNIT, IF_STD_BOM_DEF_HIS_N->COMP_ITEM_UNIT, sizeof(IF_STD_BOM_DEF_HIS->COMP_ITEM_UNIT));
    IF_STD_BOM_DEF_HIS->COMP_QTY = IF_STD_BOM_DEF_HIS_N->COMP_QTY;
    IF_STD_BOM_DEF_HIS->COMP_YIELD_FACTOR = IF_STD_BOM_DEF_HIS_N->COMP_YIELD_FACTOR;
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->EFFECTIVITY_DATE, IF_STD_BOM_DEF_HIS_N->EFFECTIVITY_DATE, sizeof(IF_STD_BOM_DEF_HIS->EFFECTIVITY_DATE));
    IF_STD_BOM_DEF_HIS->WIP_SUPPLY_TYPE = IF_STD_BOM_DEF_HIS_N->WIP_SUPPLY_TYPE;
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->WIP_SUPPLY_TYPE_NAME, IF_STD_BOM_DEF_HIS_N->WIP_SUPPLY_TYPE_NAME, sizeof(IF_STD_BOM_DEF_HIS->WIP_SUPPLY_TYPE_NAME));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->SUPPLY_INV_OPER, IF_STD_BOM_DEF_HIS_N->SUPPLY_INV_OPER, sizeof(IF_STD_BOM_DEF_HIS->SUPPLY_INV_OPER));
    IF_STD_BOM_DEF_HIS->TRAN_FLAG = IF_STD_BOM_DEF_HIS_N->TRAN_FLAG[0];
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CMF_1, IF_STD_BOM_DEF_HIS_N->CMF_1, sizeof(IF_STD_BOM_DEF_HIS->CMF_1));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CMF_2, IF_STD_BOM_DEF_HIS_N->CMF_2, sizeof(IF_STD_BOM_DEF_HIS->CMF_2));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CMF_3, IF_STD_BOM_DEF_HIS_N->CMF_3, sizeof(IF_STD_BOM_DEF_HIS->CMF_3));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CMF_4, IF_STD_BOM_DEF_HIS_N->CMF_4, sizeof(IF_STD_BOM_DEF_HIS->CMF_4));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CMF_5, IF_STD_BOM_DEF_HIS_N->CMF_5, sizeof(IF_STD_BOM_DEF_HIS->CMF_5));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CMF_6, IF_STD_BOM_DEF_HIS_N->CMF_6, sizeof(IF_STD_BOM_DEF_HIS->CMF_6));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CMF_7, IF_STD_BOM_DEF_HIS_N->CMF_7, sizeof(IF_STD_BOM_DEF_HIS->CMF_7));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CMF_8, IF_STD_BOM_DEF_HIS_N->CMF_8, sizeof(IF_STD_BOM_DEF_HIS->CMF_8));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CMF_9, IF_STD_BOM_DEF_HIS_N->CMF_9, sizeof(IF_STD_BOM_DEF_HIS->CMF_9));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CMF_10, IF_STD_BOM_DEF_HIS_N->CMF_10, sizeof(IF_STD_BOM_DEF_HIS->CMF_10));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CREATE_USER_ID, IF_STD_BOM_DEF_HIS_N->CREATE_USER_ID, sizeof(IF_STD_BOM_DEF_HIS->CREATE_USER_ID));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->CREATE_TIME, IF_STD_BOM_DEF_HIS_N->CREATE_TIME, sizeof(IF_STD_BOM_DEF_HIS->CREATE_TIME));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->UPDATE_USER_ID, IF_STD_BOM_DEF_HIS_N->UPDATE_USER_ID, sizeof(IF_STD_BOM_DEF_HIS->UPDATE_USER_ID));
    MEMCPY_DN(IF_STD_BOM_DEF_HIS->UPDATE_TIME, IF_STD_BOM_DEF_HIS_N->UPDATE_TIME, sizeof(IF_STD_BOM_DEF_HIS->UPDATE_TIME));
}


