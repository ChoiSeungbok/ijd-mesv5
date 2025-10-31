
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
           char  filnam[20];
};
static const struct sqlcxp sqlfpn =
{
    19,
    "DBU_ct_packing_v.pc"
};


static unsigned int sqlctx = 37638171;


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
            void  *sqhstv[24];
   unsigned int   sqhstl[24];
            int   sqhsts[24];
            void  *sqindv[24];
            int   sqinds[24];
   unsigned int   sqharm[24];
   unsigned int   *sqharc[24];
   unsigned short  sqadto[24];
   unsigned short  sqtdso[24];
} sqlstm = {13,24};

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
"select ORG_CODE ,LOT_ID ,WH_CODE ,NVL(TOTAL_QTY,'0.0') ,NVL(LOT_SEQ,'0') ,N\
VL(LABEL_QTY,'0.0') ,NVL(LOT_ADD,' ') ,ITEM_CODE ,NVL(ITEM_NAME,' ') ,NVL(ORD\
ER_NUMBER,'0') ,NVL(HEADER_ID,'0') ,NVL(LINE_NUMBER,'0') ,NVL(LABEL_TYPE,' ')\
 ,NVL(LABEL_MESH,' ') ,NVL(LABEL_NAME,' ') ,NVL(ORDERED_DATE,' ') ,DECODE(CON\
FIRM_DATE,'',' ',(CONFIRM_DATE||'000000')) ,NVL(CUSTOMER_NUMBER,' ') ,NVL(ORD\
ER_QTY,'0') ,NVL(COATING_RATE,'0') ,NVL(IF_SEQ,'0') ,NVL(REMARKS,' ')  from C\
T_PACKING_V where LOT_ID=:b0 order by LOT_ID asc ,LOT_SEQ asc             ";

 static const char *sq0010 = 
"select ORG_CODE ,LOT_ID ,WH_CODE ,NVL(TOTAL_QTY,'0.0') ,NVL(LOT_SEQ,'0') ,N\
VL(LABEL_QTY,'0.0') ,NVL(LOT_ADD,' ') ,ITEM_CODE ,NVL(ITEM_NAME,' ') ,NVL(ORD\
ER_NUMBER,'0') ,NVL(HEADER_ID,'0') ,NVL(LINE_NUMBER,'0') ,NVL(LABEL_TYPE,' ')\
 ,NVL(LABEL_MESH,' ') ,NVL(LABEL_NAME,' ') ,NVL(ORDERED_DATE,' ') ,DECODE(CON\
FIRM_DATE,'',' ',(CONFIRM_DATE||'000000')) ,NVL(CUSTOMER_NUMBER,' ') ,NVL(ORD\
ER_QTY,'0') ,NVL(COATING_RATE,'0') ,NVL(IF_SEQ,'0') ,NVL(REMARKS,' ')  from C\
T_PACKING_V where (LOT_ID=:b0 and LOT_SEQ=:b1) order by LOT_ID asc ,LOT_SEQ a\
sc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,611,0,4,46,0,0,24,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,3,0,0,2,
4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,97,0,0,1,97,0,0,1,
3,0,0,
116,0,0,2,623,0,4,131,0,0,24,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,3,0,
0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,97,0,0,1,97,0,0,
1,3,0,0,
227,0,0,3,79,0,4,219,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,
254,0,0,4,61,0,4,227,0,0,2,1,0,1,0,2,4,0,0,1,97,0,0,
277,0,0,5,79,0,4,234,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,
304,0,0,6,61,0,2,270,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
327,0,0,7,363,0,3,300,0,0,22,22,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,3,0,
0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,4,0,0,1,3,0,0,1,97,0,0,
430,0,0,8,364,0,5,369,0,0,22,22,0,1,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,1,4,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
533,0,0,9,534,0,9,450,0,0,1,1,0,1,0,1,97,0,0,
552,0,0,10,552,0,9,483,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
575,0,0,9,0,0,13,512,0,0,22,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,3,0,0,
2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,97,0,0,
678,0,0,10,0,0,13,538,0,0,22,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,3,0,
0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,97,0,0,
781,0,0,9,0,0,15,590,0,0,0,0,0,1,0,
796,0,0,10,0,0,15,594,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_ct_packing_v.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-10-26 09:24:53
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
void DBU_add_null_ct_packing_v(struct CT_PACKING_V_N_TAG *CT_PACKING_V_N, struct CT_PACKING_V_TAG *CT_PACKING_V);
void DBU_del_null_ct_packing_v(struct CT_PACKING_V_N_TAG *CT_PACKING_V_N, struct CT_PACKING_V_TAG *CT_PACKING_V);


/* SQL SELECT Function */
void DBU_select_ct_packing_v(int sel_type, struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_PACKING_V_N_TAG CT_PACKING_V_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_packing_v(&CT_PACKING_V_N, CT_PACKING_V);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    ORG_CODE,
                    LOT_ID,
                    WH_CODE,
                    NVL(TOTAL_QTY, '0.0'),
                    NVL(LOT_SEQ, '0'),
                    NVL(LABEL_QTY, '0.0'),
                    NVL(LOT_ADD, ' '),
                    ITEM_CODE,
                    NVL(ITEM_NAME, ' '),
                    NVL(ORDER_NUMBER, '0'),
                    NVL(HEADER_ID, '0'),
                    NVL(LINE_NUMBER, '0'),
                    NVL(LABEL_TYPE, ' '),
                    NVL(LABEL_MESH, ' '),
                    NVL(LABEL_NAME, ' '),
                    NVL(ORDERED_DATE, ' '),
					DECODE(CONFIRM_DATE, '', ' ', CONFIRM_DATE || '000000'),
                    NVL(CUSTOMER_NUMBER, ' '),
                    NVL(ORDER_QTY, '0'),
					NVL(COATING_RATE, '0'),
					NVL(IF_SEQ, '0'),
                    NVL(REMARKS, ' ')
                INTO 
                    :CT_PACKING_V_N.ORG_CODE,
                    :CT_PACKING_V_N.LOT_ID,
                    :CT_PACKING_V_N.WH_CODE,
                    :CT_PACKING_V_N.TOTAL_QTY,
                    :CT_PACKING_V_N.LOT_SEQ,
                    :CT_PACKING_V_N.LABEL_QTY,
                    :CT_PACKING_V_N.LOT_ADD,
                    :CT_PACKING_V_N.ITEM_CODE,
                    :CT_PACKING_V_N.ITEM_NAME,
                    :CT_PACKING_V_N.ORDER_NUMBER,
                    :CT_PACKING_V_N.HEADER_ID,
                    :CT_PACKING_V_N.LINE_NUMBER,
                    :CT_PACKING_V_N.LABEL_TYPE,
                    :CT_PACKING_V_N.LABEL_MESH,
                    :CT_PACKING_V_N.LABEL_NAME,
                    :CT_PACKING_V_N.ORDERED_DATE,
					:CT_PACKING_V_N.CONFIRM_DATE,
                    :CT_PACKING_V_N.CUSTOMER_NUMBER,
                    :CT_PACKING_V_N.ORDER_QTY,
					:CT_PACKING_V_N.COATING_RATE,
					:CT_PACKING_V_N.IF_SEQ,
                    :CT_PACKING_V_N.REMARKS
                FROM CT_PACKING_V
                WHERE LOT_ID = :CT_PACKING_V_N.LOT_ID
                    AND LOT_SEQ = :CT_PACKING_V_N.LOT_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select ORG_CODE ,LOT_ID ,WH_CODE ,NVL(TOTAL_QTY,\
'0.0') ,NVL(LOT_SEQ,'0') ,NVL(LABEL_QTY,'0.0') ,NVL(LOT_ADD,' ') ,ITEM_CODE ,\
NVL(ITEM_NAME,' ') ,NVL(ORDER_NUMBER,'0') ,NVL(HEADER_ID,'0') ,NVL(LINE_NUMBE\
R,'0') ,NVL(LABEL_TYPE,' ') ,NVL(LABEL_MESH,' ') ,NVL(LABEL_NAME,' ') ,NVL(OR\
DERED_DATE,' ') ,DECODE(CONFIRM_DATE,'',' ',(CONFIRM_DATE||'000000')) ,NVL(CU\
STOMER_NUMBER,' ') ,NVL(ORDER_QTY,'0') ,NVL(COATING_RATE,'0') ,NVL(IF_SEQ,'0'\
) ,NVL(REMARKS,' ') into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b\
12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21  from CT_PACKING_V where (LOT\
_ID=:b1 and LOT_SEQ=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CT_PACKING_V_N.ORG_CODE);
            sqlstm.sqhstl[0] = (unsigned int  )4;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CT_PACKING_V_N.WH_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CT_PACKING_V_N.TOTAL_QTY);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CT_PACKING_V_N.LABEL_QTY);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CT_PACKING_V_N.LOT_ADD);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CT_PACKING_V_N.ITEM_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CT_PACKING_V_N.ITEM_NAME);
            sqlstm.sqhstl[8] = (unsigned int  )241;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CT_PACKING_V_N.ORDER_NUMBER);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CT_PACKING_V_N.HEADER_ID);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CT_PACKING_V_N.LINE_NUMBER);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CT_PACKING_V_N.LABEL_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )241;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CT_PACKING_V_N.LABEL_MESH);
            sqlstm.sqhstl[13] = (unsigned int  )241;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CT_PACKING_V_N.LABEL_NAME);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CT_PACKING_V_N.ORDERED_DATE);
            sqlstm.sqhstl[15] = (unsigned int  )9;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CT_PACKING_V_N.CONFIRM_DATE);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CT_PACKING_V_N.CUSTOMER_NUMBER);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(CT_PACKING_V_N.ORDER_QTY);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CT_PACKING_V_N.COATING_RATE);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(CT_PACKING_V_N.IF_SEQ);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CT_PACKING_V_N.REMARKS);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
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
        DBU_del_null_ct_packing_v(&CT_PACKING_V_N, CT_PACKING_V);
    }

    DB_stop_query_timer("DBU_select_ct_packing_v", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_ct_packing_v_for_update(int sel_type, struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_PACKING_V_N_TAG CT_PACKING_V_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_packing_v(&CT_PACKING_V_N, CT_PACKING_V);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    ORG_CODE,
                    LOT_ID,
                    WH_CODE,
                    NVL(TOTAL_QTY, '0.0'),
                    NVL(LOT_SEQ, '0'),
                    NVL(LABEL_QTY, '0.0'),
                    NVL(LOT_ADD, ' '),
                    ITEM_CODE,
                    NVL(ITEM_NAME, ' '),
                    NVL(ORDER_NUMBER, '0'),
                    NVL(HEADER_ID, '0'),
                    NVL(LINE_NUMBER, '0'),
                    NVL(LABEL_TYPE, ' '),
                    NVL(LABEL_MESH, ' '),
                    NVL(LABEL_NAME, ' '),
                    NVL(ORDERED_DATE, ' '),
					DECODE(CONFIRM_DATE, '', ' ', CONFIRM_DATE || '000000'),
                    NVL(CUSTOMER_NUMBER, ' '),
                    NVL(ORDER_QTY, '0'),
					NVL(COATING_RATE, '0'),
					NVL(IF_SEQ, '0'),
                    NVL(REMARKS, ' ')
                INTO 
                    :CT_PACKING_V_N.ORG_CODE,
                    :CT_PACKING_V_N.LOT_ID,
                    :CT_PACKING_V_N.WH_CODE,
                    :CT_PACKING_V_N.TOTAL_QTY,
                    :CT_PACKING_V_N.LOT_SEQ,
                    :CT_PACKING_V_N.LABEL_QTY,
                    :CT_PACKING_V_N.LOT_ADD,
                    :CT_PACKING_V_N.ITEM_CODE,
                    :CT_PACKING_V_N.ITEM_NAME,
                    :CT_PACKING_V_N.ORDER_NUMBER,
                    :CT_PACKING_V_N.HEADER_ID,
                    :CT_PACKING_V_N.LINE_NUMBER,
                    :CT_PACKING_V_N.LABEL_TYPE,
                    :CT_PACKING_V_N.LABEL_MESH,
                    :CT_PACKING_V_N.LABEL_NAME,
                    :CT_PACKING_V_N.ORDERED_DATE,
					:CT_PACKING_V_N.CONFIRM_DATE,
                    :CT_PACKING_V_N.CUSTOMER_NUMBER,
                    :CT_PACKING_V_N.ORDER_QTY,
					:CT_PACKING_V_N.COATING_RATE,
					:CT_PACKING_V_N.IF_SEQ,
                    :CT_PACKING_V_N.REMARKS
                FROM CT_PACKING_V
                WHERE LOT_ID = :CT_PACKING_V_N.LOT_ID
                    AND LOT_SEQ = :CT_PACKING_V_N.LOT_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select ORG_CODE ,LOT_ID ,WH_CODE ,NVL(TOTAL_QTY,\
'0.0') ,NVL(LOT_SEQ,'0') ,NVL(LABEL_QTY,'0.0') ,NVL(LOT_ADD,' ') ,ITEM_CODE ,\
NVL(ITEM_NAME,' ') ,NVL(ORDER_NUMBER,'0') ,NVL(HEADER_ID,'0') ,NVL(LINE_NUMBE\
R,'0') ,NVL(LABEL_TYPE,' ') ,NVL(LABEL_MESH,' ') ,NVL(LABEL_NAME,' ') ,NVL(OR\
DERED_DATE,' ') ,DECODE(CONFIRM_DATE,'',' ',(CONFIRM_DATE||'000000')) ,NVL(CU\
STOMER_NUMBER,' ') ,NVL(ORDER_QTY,'0') ,NVL(COATING_RATE,'0') ,NVL(IF_SEQ,'0'\
) ,NVL(REMARKS,' ') into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b\
12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21  from CT_PACKING_V where (LOT\
_ID=:b1 and LOT_SEQ=:b4) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )116;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CT_PACKING_V_N.ORG_CODE);
            sqlstm.sqhstl[0] = (unsigned int  )4;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CT_PACKING_V_N.WH_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CT_PACKING_V_N.TOTAL_QTY);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CT_PACKING_V_N.LABEL_QTY);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CT_PACKING_V_N.LOT_ADD);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CT_PACKING_V_N.ITEM_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CT_PACKING_V_N.ITEM_NAME);
            sqlstm.sqhstl[8] = (unsigned int  )241;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CT_PACKING_V_N.ORDER_NUMBER);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CT_PACKING_V_N.HEADER_ID);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CT_PACKING_V_N.LINE_NUMBER);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CT_PACKING_V_N.LABEL_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )241;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CT_PACKING_V_N.LABEL_MESH);
            sqlstm.sqhstl[13] = (unsigned int  )241;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CT_PACKING_V_N.LABEL_NAME);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CT_PACKING_V_N.ORDERED_DATE);
            sqlstm.sqhstl[15] = (unsigned int  )9;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CT_PACKING_V_N.CONFIRM_DATE);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CT_PACKING_V_N.CUSTOMER_NUMBER);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(CT_PACKING_V_N.ORDER_QTY);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CT_PACKING_V_N.COATING_RATE);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(CT_PACKING_V_N.IF_SEQ);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CT_PACKING_V_N.REMARKS);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
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
        DBU_del_null_ct_packing_v(&CT_PACKING_V_N, CT_PACKING_V);
    }

    DB_stop_query_timer("DBU_select_ct_packing_v_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_ct_packing_v_scalar(int sel_type, struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_PACKING_V_N_TAG CT_PACKING_V_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_packing_v(&CT_PACKING_V_N, CT_PACKING_V);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CT_PACKING_V
                WHERE LOT_ID = :CT_PACKING_V_N.LOT_ID
                    AND LOT_SEQ = :CT_PACKING_V_N.LOT_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CT_PACKING_V whe\
re (LOT_ID=:b1 and LOT_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )227;
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
            sqlstm.sqhstv[1] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
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
                FROM CT_PACKING_V
                WHERE LOT_ID = :CT_PACKING_V_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CT_PACKING_V whe\
re LOT_ID=:b1";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )254;
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
            sqlstm.sqhstv[1] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
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

		case 3:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CT_PACKING_V
                WHERE LOT_ID = :CT_PACKING_V_N.LOT_ID
				 AND LOT_SEQ = :CT_PACKING_V_N.LOT_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CT_PACKING_V whe\
re (LOT_ID=:b1 and LOT_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )277;
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
            sqlstm.sqhstv[1] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
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

    DB_stop_query_timer("DBU_select_ct_packing_v_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_ct_packing_v(int sel_type, struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_PACKING_V_N_TAG CT_PACKING_V_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_packing_v(&CT_PACKING_V_N, CT_PACKING_V);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CT_PACKING_V
                WHERE LOT_ID = :CT_PACKING_V_N.LOT_ID
                    AND LOT_SEQ = :CT_PACKING_V_N.LOT_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CT_PACKING_V  where (LOT_ID=:b0 and\
 LOT_SEQ=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )304;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
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

    DB_stop_query_timer("DBU_delete_ct_packing_v", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_ct_packing_v(struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_PACKING_V_N_TAG CT_PACKING_V_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_packing_v(&CT_PACKING_V_N, CT_PACKING_V);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CT_PACKING_V( 
                    ORG_CODE, 
                    LOT_ID, 
                    WH_CODE, 
                    TOTAL_QTY, 
                    LOT_SEQ, 
                    LABEL_QTY, 
                    LOT_ADD,
                    ITEM_CODE, 
                    ITEM_NAME, 
                    ORDER_NUMBER, 
                    HEADER_ID, 
                    LINE_NUMBER, 
                    LABEL_TYPE, 
                    LABEL_MESH, 
                    LABEL_NAME, 
                    ORDERED_DATE, 
					CONFIRM_DATE,
                    CUSTOMER_NUMBER, 
                    ORDER_QTY, 
					COATING_RATE,
					IF_SEQ,
                    REMARKS
         ) 
        VALUES (
                    :CT_PACKING_V_N.ORG_CODE,
                    :CT_PACKING_V_N.LOT_ID,
                    :CT_PACKING_V_N.WH_CODE,
                    :CT_PACKING_V_N.TOTAL_QTY,
                    :CT_PACKING_V_N.LOT_SEQ,
                    :CT_PACKING_V_N.LABEL_QTY,
                    :CT_PACKING_V_N.LOT_ADD,
                    :CT_PACKING_V_N.ITEM_CODE,
                    :CT_PACKING_V_N.ITEM_NAME,
                    :CT_PACKING_V_N.ORDER_NUMBER,
                    :CT_PACKING_V_N.HEADER_ID,
                    :CT_PACKING_V_N.LINE_NUMBER,
                    :CT_PACKING_V_N.LABEL_TYPE,
                    :CT_PACKING_V_N.LABEL_MESH,
                    :CT_PACKING_V_N.LABEL_NAME,
                    :CT_PACKING_V_N.ORDERED_DATE,
					:CT_PACKING_V_N.CONFIRM_DATE,
                    :CT_PACKING_V_N.CUSTOMER_NUMBER,
                    :CT_PACKING_V_N.ORDER_QTY,
					:CT_PACKING_V_N.COATING_RATE,
					:CT_PACKING_V_N.IF_SEQ,
                    :CT_PACKING_V_N.REMARKS
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into CT_PACKING_V (ORG_CODE,LOT_ID,WH_CODE,TOTAL_\
QTY,LOT_SEQ,LABEL_QTY,LOT_ADD,ITEM_CODE,ITEM_NAME,ORDER_NUMBER,HEADER_ID,LINE\
_NUMBER,LABEL_TYPE,LABEL_MESH,LABEL_NAME,ORDERED_DATE,CONFIRM_DATE,CUSTOMER_N\
UMBER,ORDER_QTY,COATING_RATE,IF_SEQ,REMARKS) values (:b0,:b1,:b2,:b3,:b4,:b5,\
:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )327;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CT_PACKING_V_N.ORG_CODE);
    sqlstm.sqhstl[0] = (unsigned int  )4;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CT_PACKING_V_N.LOT_ID);
    sqlstm.sqhstl[1] = (unsigned int  )31;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CT_PACKING_V_N.WH_CODE);
    sqlstm.sqhstl[2] = (unsigned int  )21;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)&(CT_PACKING_V_N.TOTAL_QTY);
    sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
    sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)&(CT_PACKING_V_N.LABEL_QTY);
    sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CT_PACKING_V_N.LOT_ADD);
    sqlstm.sqhstl[6] = (unsigned int  )31;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(CT_PACKING_V_N.ITEM_CODE);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CT_PACKING_V_N.ITEM_NAME);
    sqlstm.sqhstl[8] = (unsigned int  )241;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)&(CT_PACKING_V_N.ORDER_NUMBER);
    sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)&(CT_PACKING_V_N.HEADER_ID);
    sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)&(CT_PACKING_V_N.LINE_NUMBER);
    sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(CT_PACKING_V_N.LABEL_TYPE);
    sqlstm.sqhstl[12] = (unsigned int  )241;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CT_PACKING_V_N.LABEL_MESH);
    sqlstm.sqhstl[13] = (unsigned int  )241;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(CT_PACKING_V_N.LABEL_NAME);
    sqlstm.sqhstl[14] = (unsigned int  )1001;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CT_PACKING_V_N.ORDERED_DATE);
    sqlstm.sqhstl[15] = (unsigned int  )9;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CT_PACKING_V_N.CONFIRM_DATE);
    sqlstm.sqhstl[16] = (unsigned int  )15;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CT_PACKING_V_N.CUSTOMER_NUMBER);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)&(CT_PACKING_V_N.ORDER_QTY);
    sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)&(CT_PACKING_V_N.COATING_RATE);
    sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)&(CT_PACKING_V_N.IF_SEQ);
    sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CT_PACKING_V_N.REMARKS);
    sqlstm.sqhstl[21] = (unsigned int  )201;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_ct_packing_v", 0);
}


/* SQL UPDATE Function */
void DBU_update_ct_packing_v(int sel_type, struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_PACKING_V_N_TAG CT_PACKING_V_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_packing_v(&CT_PACKING_V_N, CT_PACKING_V);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CT_PACKING_V SET
                    ORG_CODE = :CT_PACKING_V_N.ORG_CODE,
                    WH_CODE = :CT_PACKING_V_N.WH_CODE,
                    TOTAL_QTY = :CT_PACKING_V_N.TOTAL_QTY,
                    LABEL_QTY = :CT_PACKING_V_N.LABEL_QTY,
                    LOT_ADD = :CT_PACKING_V_N.LOT_ADD,
                    ITEM_CODE = :CT_PACKING_V_N.ITEM_CODE,
                    ITEM_NAME = :CT_PACKING_V_N.ITEM_NAME,
                    ORDER_NUMBER = :CT_PACKING_V_N.ORDER_NUMBER,
                    HEADER_ID = :CT_PACKING_V_N.HEADER_ID,
                    LINE_NUMBER = :CT_PACKING_V_N.LINE_NUMBER,
                    LABEL_TYPE = :CT_PACKING_V_N.LABEL_TYPE,
                    LABEL_MESH = :CT_PACKING_V_N.LABEL_MESH,
                    LABEL_NAME = :CT_PACKING_V_N.LABEL_NAME,
                    ORDERED_DATE = :CT_PACKING_V_N.ORDERED_DATE,
					CONFIRM_DATE = :CT_PACKING_V_N.CONFIRM_DATE,
                    CUSTOMER_NUMBER = :CT_PACKING_V_N.CUSTOMER_NUMBER,
                    ORDER_QTY = :CT_PACKING_V_N.ORDER_QTY,
					COATING_RATE = :CT_PACKING_V_N.COATING_RATE,
					IF_SEQ = :CT_PACKING_V_N.IF_SEQ,
                    REMARKS = :CT_PACKING_V_N.REMARKS
                WHERE LOT_ID = :CT_PACKING_V_N.LOT_ID
                    AND LOT_SEQ = :CT_PACKING_V_N.LOT_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CT_PACKING_V  set ORG_CODE=:b0,WH_CODE=:b\
1,TOTAL_QTY=:b2,LABEL_QTY=:b3,LOT_ADD=:b4,ITEM_CODE=:b5,ITEM_NAME=:b6,ORDER_N\
UMBER=:b7,HEADER_ID=:b8,LINE_NUMBER=:b9,LABEL_TYPE=:b10,LABEL_MESH=:b11,LABEL\
_NAME=:b12,ORDERED_DATE=:b13,CONFIRM_DATE=:b14,CUSTOMER_NUMBER=:b15,ORDER_QTY\
=:b16,COATING_RATE=:b17,IF_SEQ=:b18,REMARKS=:b19 where (LOT_ID=:b20 and LOT_S\
EQ=:b21)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )430;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CT_PACKING_V_N.ORG_CODE);
            sqlstm.sqhstl[0] = (unsigned int  )4;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CT_PACKING_V_N.WH_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CT_PACKING_V_N.TOTAL_QTY);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CT_PACKING_V_N.LABEL_QTY);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CT_PACKING_V_N.LOT_ADD);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CT_PACKING_V_N.ITEM_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CT_PACKING_V_N.ITEM_NAME);
            sqlstm.sqhstl[6] = (unsigned int  )241;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CT_PACKING_V_N.ORDER_NUMBER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CT_PACKING_V_N.HEADER_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CT_PACKING_V_N.LINE_NUMBER);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CT_PACKING_V_N.LABEL_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )241;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CT_PACKING_V_N.LABEL_MESH);
            sqlstm.sqhstl[11] = (unsigned int  )241;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CT_PACKING_V_N.LABEL_NAME);
            sqlstm.sqhstl[12] = (unsigned int  )1001;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CT_PACKING_V_N.ORDERED_DATE);
            sqlstm.sqhstl[13] = (unsigned int  )9;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CT_PACKING_V_N.CONFIRM_DATE);
            sqlstm.sqhstl[14] = (unsigned int  )15;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CT_PACKING_V_N.CUSTOMER_NUMBER);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(CT_PACKING_V_N.ORDER_QTY);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(CT_PACKING_V_N.COATING_RATE);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(CT_PACKING_V_N.IF_SEQ);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CT_PACKING_V_N.REMARKS);
            sqlstm.sqhstl[19] = (unsigned int  )201;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_ct_packing_v", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_ct_packing_v(int sel_type, struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_PACKING_V_N_TAG CT_PACKING_V_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ct_packing_v(&CT_PACKING_V_N, CT_PACKING_V);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CT_PACKING_V_CUR_1 CURSOR FOR
                SELECT 
                    ORG_CODE,
                    LOT_ID,
                    WH_CODE,
                    NVL(TOTAL_QTY, '0.0'),
                    NVL(LOT_SEQ, '0'),
                    NVL(LABEL_QTY, '0.0'),
                    NVL(LOT_ADD, ' '),
                    ITEM_CODE,
                    NVL(ITEM_NAME, ' '),
                    NVL(ORDER_NUMBER, '0'),
                    NVL(HEADER_ID, '0'),
                    NVL(LINE_NUMBER, '0'),
                    NVL(LABEL_TYPE, ' '),
                    NVL(LABEL_MESH, ' '),
                    NVL(LABEL_NAME, ' '),
                    NVL(ORDERED_DATE, ' '),
					DECODE(CONFIRM_DATE, '', ' ', CONFIRM_DATE || '000000'),
                    NVL(CUSTOMER_NUMBER, ' '),
                    NVL(ORDER_QTY, '0'),
					NVL(COATING_RATE, '0'),
					NVL(IF_SEQ, '0'),
                    NVL(REMARKS, ' ')
                FROM CT_PACKING_V
               WHERE LOT_ID = :CT_PACKING_V_N.LOT_ID
                ORDER BY LOT_ID ASC,
                    LOT_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_CT_PACKING_V_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )533;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 2:
            /* EXEC SQL DECLARE DBU_CT_PACKING_V_CUR_2 CURSOR FOR
                SELECT 
                    ORG_CODE,
                    LOT_ID,
                    WH_CODE,
                    NVL(TOTAL_QTY, '0.0'),
                    NVL(LOT_SEQ, '0'),
                    NVL(LABEL_QTY, '0.0'),
                    NVL(LOT_ADD, ' '),
                    ITEM_CODE,
                    NVL(ITEM_NAME, ' '),
                    NVL(ORDER_NUMBER, '0'),
                    NVL(HEADER_ID, '0'),
                    NVL(LINE_NUMBER, '0'),
                    NVL(LABEL_TYPE, ' '),
                    NVL(LABEL_MESH, ' '),
                    NVL(LABEL_NAME, ' '),
                    NVL(ORDERED_DATE, ' '),
					DECODE(CONFIRM_DATE, '', ' ', CONFIRM_DATE || '000000'),
                    NVL(CUSTOMER_NUMBER, ' '),
                    NVL(ORDER_QTY, '0'),
					NVL(COATING_RATE, '0'),
					NVL(IF_SEQ, '0'),
                    NVL(REMARKS, ' ')
                FROM CT_PACKING_V
               WHERE LOT_ID = :CT_PACKING_V_N.LOT_ID
			    AND LOT_SEQ = :CT_PACKING_V_N.LOT_SEQ
                ORDER BY LOT_ID ASC,
                    LOT_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_CT_PACKING_V_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )552;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_open_ct_packing_v", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_ct_packing_v(int sel_type, struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CT_PACKING_V_N_TAG CT_PACKING_V_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CT_PACKING_V_CUR_1 INTO
                :CT_PACKING_V_N.ORG_CODE,
                :CT_PACKING_V_N.LOT_ID,
                :CT_PACKING_V_N.WH_CODE,
                :CT_PACKING_V_N.TOTAL_QTY,
                :CT_PACKING_V_N.LOT_SEQ,
                :CT_PACKING_V_N.LABEL_QTY,
                :CT_PACKING_V_N.LOT_ADD,
                :CT_PACKING_V_N.ITEM_CODE,
                :CT_PACKING_V_N.ITEM_NAME,
                :CT_PACKING_V_N.ORDER_NUMBER,
                :CT_PACKING_V_N.HEADER_ID,
                :CT_PACKING_V_N.LINE_NUMBER,
                :CT_PACKING_V_N.LABEL_TYPE,
                :CT_PACKING_V_N.LABEL_MESH,
                :CT_PACKING_V_N.LABEL_NAME,
                :CT_PACKING_V_N.ORDERED_DATE,
				:CT_PACKING_V_N.CONFIRM_DATE,
                :CT_PACKING_V_N.CUSTOMER_NUMBER,
                :CT_PACKING_V_N.ORDER_QTY,
				:CT_PACKING_V_N.COATING_RATE,
				:CT_PACKING_V_N.IF_SEQ,
                :CT_PACKING_V_N.REMARKS; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )575;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CT_PACKING_V_N.ORG_CODE);
            sqlstm.sqhstl[0] = (unsigned int  )4;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CT_PACKING_V_N.WH_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CT_PACKING_V_N.TOTAL_QTY);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CT_PACKING_V_N.LABEL_QTY);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CT_PACKING_V_N.LOT_ADD);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CT_PACKING_V_N.ITEM_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CT_PACKING_V_N.ITEM_NAME);
            sqlstm.sqhstl[8] = (unsigned int  )241;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CT_PACKING_V_N.ORDER_NUMBER);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CT_PACKING_V_N.HEADER_ID);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CT_PACKING_V_N.LINE_NUMBER);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CT_PACKING_V_N.LABEL_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )241;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CT_PACKING_V_N.LABEL_MESH);
            sqlstm.sqhstl[13] = (unsigned int  )241;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CT_PACKING_V_N.LABEL_NAME);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CT_PACKING_V_N.ORDERED_DATE);
            sqlstm.sqhstl[15] = (unsigned int  )9;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CT_PACKING_V_N.CONFIRM_DATE);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CT_PACKING_V_N.CUSTOMER_NUMBER);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(CT_PACKING_V_N.ORDER_QTY);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CT_PACKING_V_N.COATING_RATE);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(CT_PACKING_V_N.IF_SEQ);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CT_PACKING_V_N.REMARKS);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_CT_PACKING_V_CUR_2 INTO
                :CT_PACKING_V_N.ORG_CODE,
                :CT_PACKING_V_N.LOT_ID,
                :CT_PACKING_V_N.WH_CODE,
                :CT_PACKING_V_N.TOTAL_QTY,
                :CT_PACKING_V_N.LOT_SEQ,
                :CT_PACKING_V_N.LABEL_QTY,
                :CT_PACKING_V_N.LOT_ADD,
                :CT_PACKING_V_N.ITEM_CODE,
                :CT_PACKING_V_N.ITEM_NAME,
                :CT_PACKING_V_N.ORDER_NUMBER,
                :CT_PACKING_V_N.HEADER_ID,
                :CT_PACKING_V_N.LINE_NUMBER,
                :CT_PACKING_V_N.LABEL_TYPE,
                :CT_PACKING_V_N.LABEL_MESH,
                :CT_PACKING_V_N.LABEL_NAME,
                :CT_PACKING_V_N.ORDERED_DATE,
				:CT_PACKING_V_N.CONFIRM_DATE,
                :CT_PACKING_V_N.CUSTOMER_NUMBER,
                :CT_PACKING_V_N.ORDER_QTY,
				:CT_PACKING_V_N.COATING_RATE,
				:CT_PACKING_V_N.IF_SEQ,
                :CT_PACKING_V_N.REMARKS; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )678;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CT_PACKING_V_N.ORG_CODE);
            sqlstm.sqhstl[0] = (unsigned int  )4;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CT_PACKING_V_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CT_PACKING_V_N.WH_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CT_PACKING_V_N.TOTAL_QTY);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CT_PACKING_V_N.LOT_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CT_PACKING_V_N.LABEL_QTY);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CT_PACKING_V_N.LOT_ADD);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CT_PACKING_V_N.ITEM_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CT_PACKING_V_N.ITEM_NAME);
            sqlstm.sqhstl[8] = (unsigned int  )241;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CT_PACKING_V_N.ORDER_NUMBER);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CT_PACKING_V_N.HEADER_ID);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CT_PACKING_V_N.LINE_NUMBER);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CT_PACKING_V_N.LABEL_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )241;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CT_PACKING_V_N.LABEL_MESH);
            sqlstm.sqhstl[13] = (unsigned int  )241;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CT_PACKING_V_N.LABEL_NAME);
            sqlstm.sqhstl[14] = (unsigned int  )1001;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CT_PACKING_V_N.ORDERED_DATE);
            sqlstm.sqhstl[15] = (unsigned int  )9;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CT_PACKING_V_N.CONFIRM_DATE);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CT_PACKING_V_N.CUSTOMER_NUMBER);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(CT_PACKING_V_N.ORDER_QTY);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CT_PACKING_V_N.COATING_RATE);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(CT_PACKING_V_N.IF_SEQ);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CT_PACKING_V_N.REMARKS);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
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
        DBU_del_null_ct_packing_v(&CT_PACKING_V_N, CT_PACKING_V);
    }

    DB_stop_query_timer("DBU_fetch_ct_packing_v", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_ct_packing_v(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CT_PACKING_V_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )781;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 2:
            /* EXEC SQL CLOSE DBU_CT_PACKING_V_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 24;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )796;
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

    DB_stop_query_timer("DBU_close_ct_packing_v", sel_type);
}


/* Initialize Function */
void DBU_init_ct_packing_v(struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    /* memset by Space */
    memset(CT_PACKING_V, ' ', sizeof(struct CT_PACKING_V_TAG));
    
    CT_PACKING_V->TOTAL_QTY = 0;
    CT_PACKING_V->LOT_SEQ = 0;
    CT_PACKING_V->LABEL_QTY = 0;
    CT_PACKING_V->ORDER_NUMBER = 0;
    CT_PACKING_V->HEADER_ID = 0;
    CT_PACKING_V->LINE_NUMBER = 0;
    CT_PACKING_V->ORDER_QTY = 0;
	CT_PACKING_V->COATING_RATE = 0;
	CT_PACKING_V->IF_SEQ = 0;
}


/* Add Null Function */
void DBU_add_null_ct_packing_v(struct CT_PACKING_V_N_TAG *CT_PACKING_V_N, struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    /* memset by NULL */
    memset(CT_PACKING_V_N, '\0', sizeof(struct CT_PACKING_V_N_TAG));
    
    MEMCPY_AN(CT_PACKING_V_N->ORG_CODE, CT_PACKING_V->ORG_CODE, sizeof(CT_PACKING_V->ORG_CODE));
    MEMCPY_AN(CT_PACKING_V_N->LOT_ID, CT_PACKING_V->LOT_ID, sizeof(CT_PACKING_V->LOT_ID));
    MEMCPY_AN(CT_PACKING_V_N->WH_CODE, CT_PACKING_V->WH_CODE, sizeof(CT_PACKING_V->WH_CODE));
    CT_PACKING_V_N->TOTAL_QTY = CT_PACKING_V->TOTAL_QTY;
    CT_PACKING_V_N->LOT_SEQ = CT_PACKING_V->LOT_SEQ;
    CT_PACKING_V_N->LABEL_QTY = CT_PACKING_V->LABEL_QTY;
    MEMCPY_AN(CT_PACKING_V_N->LOT_ADD, CT_PACKING_V->LOT_ADD, sizeof(CT_PACKING_V->LOT_ADD));
    MEMCPY_AN(CT_PACKING_V_N->ITEM_CODE, CT_PACKING_V->ITEM_CODE, sizeof(CT_PACKING_V->ITEM_CODE));
    MEMCPY_AN(CT_PACKING_V_N->ITEM_NAME, CT_PACKING_V->ITEM_NAME, sizeof(CT_PACKING_V->ITEM_NAME));
    CT_PACKING_V_N->ORDER_NUMBER = CT_PACKING_V->ORDER_NUMBER;
    CT_PACKING_V_N->HEADER_ID = CT_PACKING_V->HEADER_ID;
    CT_PACKING_V_N->LINE_NUMBER = CT_PACKING_V->LINE_NUMBER;
    MEMCPY_AN(CT_PACKING_V_N->LABEL_TYPE, CT_PACKING_V->LABEL_TYPE, sizeof(CT_PACKING_V->LABEL_TYPE));
    MEMCPY_AN(CT_PACKING_V_N->LABEL_MESH, CT_PACKING_V->LABEL_MESH, sizeof(CT_PACKING_V->LABEL_MESH));
    MEMCPY_AN(CT_PACKING_V_N->LABEL_NAME, CT_PACKING_V->LABEL_NAME, sizeof(CT_PACKING_V->LABEL_NAME));
    MEMCPY_AN(CT_PACKING_V_N->ORDERED_DATE, CT_PACKING_V->ORDERED_DATE, sizeof(CT_PACKING_V->ORDERED_DATE));
	MEMCPY_AN(CT_PACKING_V_N->CONFIRM_DATE, CT_PACKING_V->CONFIRM_DATE, sizeof(CT_PACKING_V->CONFIRM_DATE));
    MEMCPY_AN(CT_PACKING_V_N->CUSTOMER_NUMBER, CT_PACKING_V->CUSTOMER_NUMBER, sizeof(CT_PACKING_V->CUSTOMER_NUMBER));
    CT_PACKING_V_N->ORDER_QTY = CT_PACKING_V->ORDER_QTY;
	CT_PACKING_V_N->COATING_RATE = CT_PACKING_V->COATING_RATE;
	CT_PACKING_V_N->IF_SEQ = CT_PACKING_V->IF_SEQ;
    MEMCPY_AN(CT_PACKING_V_N->REMARKS, CT_PACKING_V->REMARKS, sizeof(CT_PACKING_V->REMARKS));
}


/* Del Null Function */
void DBU_del_null_ct_packing_v(struct CT_PACKING_V_N_TAG *CT_PACKING_V_N, struct CT_PACKING_V_TAG *CT_PACKING_V)
{
    MEMCPY_DN(CT_PACKING_V->ORG_CODE, CT_PACKING_V_N->ORG_CODE, sizeof(CT_PACKING_V->ORG_CODE));
    MEMCPY_DN(CT_PACKING_V->LOT_ID, CT_PACKING_V_N->LOT_ID, sizeof(CT_PACKING_V->LOT_ID));
    MEMCPY_DN(CT_PACKING_V->WH_CODE, CT_PACKING_V_N->WH_CODE, sizeof(CT_PACKING_V->WH_CODE));
    CT_PACKING_V->TOTAL_QTY = CT_PACKING_V_N->TOTAL_QTY;
    CT_PACKING_V->LOT_SEQ = CT_PACKING_V_N->LOT_SEQ;
    CT_PACKING_V->LABEL_QTY = CT_PACKING_V_N->LABEL_QTY;
    MEMCPY_DN(CT_PACKING_V->LOT_ADD, CT_PACKING_V_N->LOT_ADD, sizeof(CT_PACKING_V->LOT_ADD));
    MEMCPY_DN(CT_PACKING_V->ITEM_CODE, CT_PACKING_V_N->ITEM_CODE, sizeof(CT_PACKING_V->ITEM_CODE));
    MEMCPY_DN(CT_PACKING_V->ITEM_NAME, CT_PACKING_V_N->ITEM_NAME, sizeof(CT_PACKING_V->ITEM_NAME));
    CT_PACKING_V->ORDER_NUMBER = CT_PACKING_V_N->ORDER_NUMBER;
    CT_PACKING_V->HEADER_ID = CT_PACKING_V_N->HEADER_ID;
    CT_PACKING_V->LINE_NUMBER = CT_PACKING_V_N->LINE_NUMBER;
    MEMCPY_DN(CT_PACKING_V->LABEL_TYPE, CT_PACKING_V_N->LABEL_TYPE, sizeof(CT_PACKING_V->LABEL_TYPE));
    MEMCPY_DN(CT_PACKING_V->LABEL_MESH, CT_PACKING_V_N->LABEL_MESH, sizeof(CT_PACKING_V->LABEL_MESH));
    MEMCPY_DN(CT_PACKING_V->LABEL_NAME, CT_PACKING_V_N->LABEL_NAME, sizeof(CT_PACKING_V->LABEL_NAME));
    MEMCPY_DN(CT_PACKING_V->ORDERED_DATE, CT_PACKING_V_N->ORDERED_DATE, sizeof(CT_PACKING_V->ORDERED_DATE));
	MEMCPY_DN(CT_PACKING_V->CONFIRM_DATE, CT_PACKING_V_N->CONFIRM_DATE, sizeof(CT_PACKING_V->CONFIRM_DATE));
    MEMCPY_DN(CT_PACKING_V->CUSTOMER_NUMBER, CT_PACKING_V_N->CUSTOMER_NUMBER, sizeof(CT_PACKING_V->CUSTOMER_NUMBER));
    CT_PACKING_V->ORDER_QTY = CT_PACKING_V_N->ORDER_QTY;
	CT_PACKING_V->COATING_RATE = CT_PACKING_V_N->COATING_RATE;
	CT_PACKING_V->IF_SEQ = CT_PACKING_V_N->IF_SEQ;
    MEMCPY_DN(CT_PACKING_V->REMARKS, CT_PACKING_V_N->REMARKS, sizeof(CT_PACKING_V->REMARKS));
}


