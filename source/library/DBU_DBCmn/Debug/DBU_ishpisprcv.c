
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
    "DBU_ishpisprcv.pc"
};


static unsigned int sqlctx = 9412923;


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
            void  *sqhstv[68];
   unsigned int   sqhstl[68];
            int   sqhsts[68];
            void  *sqindv[68];
            int   sqinds[68];
   unsigned int   sqharm[68];
   unsigned int   *sqharc[68];
   unsigned short  sqadto[68];
   unsigned short  sqtdso[68];
} sqlstm = {13,68};

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
"select FACTORY ,PACK_LOT_ID ,ORG_LOT_ID ,FROM_FACTORY ,INSP_ID ,COL_SET_ID \
,COL_SET_VER ,CHAR_ID ,CHAR_SEQ ,UNIT_SEQ ,VALUE_SEQ ,UNIT_ID ,VALUE_TYPE ,VA\
LUE_COUNT ,VALUE_1 ,VALUE_2 ,VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VAL\
UE_8 ,VALUE_9 ,VALUE_10 ,VALUE_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VA\
LUE_16 ,VALUE_17 ,VALUE_18 ,VALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 \
,VALUE_24 ,VALUE_25 ,SAMPLE_COUNT ,SPEC_OUT_MASK ,INSP_JUDGE_FLAG ,INSP_JUDGE\
_TYPE ,INSP_JUDGE_TIME ,RECEIVE_FLAG ,DELETE_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4\
 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPD\
ATE_USER_ID ,UPDATE_TIME  from ISHPISPRCV  order by FACTORY asc ,PACK_LOT_ID \
asc ,ORG_LOT_ID asc ,INSP_ID asc ,COL_SET_ID asc ,CHAR_SEQ asc ,UNIT_SEQ asc \
,VALUE_SEQ asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1109,0,4,46,0,0,68,8,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,
292,0,0,2,1121,0,4,213,0,0,68,8,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,
579,0,0,3,200,0,4,383,0,0,9,8,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
630,0,0,4,103,0,4,397,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
661,0,0,5,182,0,2,435,0,0,8,8,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,3,0,0,1,3,0,0,
708,0,0,6,896,0,3,471,0,0,60,60,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,
963,0,0,7,933,0,5,616,0,0,60,60,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,
1218,0,0,8,135,0,5,680,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,
1257,0,0,9,795,0,9,788,0,0,0,0,0,1,0,
1272,0,0,9,0,0,13,817,0,0,60,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,
1527,0,0,9,0,0,15,907,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_ishpisprcv.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2021-05-20 09:53:24
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
void DBU_add_null_ishpisprcv(struct ISHPISPRCV_N_TAG *ISHPISPRCV_N, struct ISHPISPRCV_TAG *ISHPISPRCV);
void DBU_del_null_ishpisprcv(struct ISHPISPRCV_N_TAG *ISHPISPRCV_N, struct ISHPISPRCV_TAG *ISHPISPRCV);


/* SQL SELECT Function */
void DBU_select_ishpisprcv(int sel_type, struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ISHPISPRCV_N_TAG ISHPISPRCV_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ishpisprcv(&ISHPISPRCV_N, ISHPISPRCV);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    PACK_LOT_ID,
                    ORG_LOT_ID,
                    FROM_FACTORY,
                    INSP_ID,
                    COL_SET_ID,
                    COL_SET_VER,
                    CHAR_ID,
                    CHAR_SEQ,
                    UNIT_SEQ,
                    VALUE_SEQ,
                    UNIT_ID,
                    VALUE_TYPE,
                    VALUE_COUNT,
                    VALUE_1,
                    VALUE_2,
                    VALUE_3,
                    VALUE_4,
                    VALUE_5,
                    VALUE_6,
                    VALUE_7,
                    VALUE_8,
                    VALUE_9,
                    VALUE_10,
                    VALUE_11,
                    VALUE_12,
                    VALUE_13,
                    VALUE_14,
                    VALUE_15,
                    VALUE_16,
                    VALUE_17,
                    VALUE_18,
                    VALUE_19,
                    VALUE_20,
                    VALUE_21,
                    VALUE_22,
                    VALUE_23,
                    VALUE_24,
                    VALUE_25,
                    SAMPLE_COUNT,
                    SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME,
                    RECEIVE_FLAG,
                    DELETE_FLAG,
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
                    :ISHPISPRCV_N.FACTORY,
                    :ISHPISPRCV_N.PACK_LOT_ID,
                    :ISHPISPRCV_N.ORG_LOT_ID,
                    :ISHPISPRCV_N.FROM_FACTORY,
                    :ISHPISPRCV_N.INSP_ID,
                    :ISHPISPRCV_N.COL_SET_ID,
                    :ISHPISPRCV_N.COL_SET_VER,
                    :ISHPISPRCV_N.CHAR_ID,
                    :ISHPISPRCV_N.CHAR_SEQ,
                    :ISHPISPRCV_N.UNIT_SEQ,
                    :ISHPISPRCV_N.VALUE_SEQ,
                    :ISHPISPRCV_N.UNIT_ID,
                    :ISHPISPRCV_N.VALUE_TYPE,
                    :ISHPISPRCV_N.VALUE_COUNT,
                    :ISHPISPRCV_N.VALUE_1,
                    :ISHPISPRCV_N.VALUE_2,
                    :ISHPISPRCV_N.VALUE_3,
                    :ISHPISPRCV_N.VALUE_4,
                    :ISHPISPRCV_N.VALUE_5,
                    :ISHPISPRCV_N.VALUE_6,
                    :ISHPISPRCV_N.VALUE_7,
                    :ISHPISPRCV_N.VALUE_8,
                    :ISHPISPRCV_N.VALUE_9,
                    :ISHPISPRCV_N.VALUE_10,
                    :ISHPISPRCV_N.VALUE_11,
                    :ISHPISPRCV_N.VALUE_12,
                    :ISHPISPRCV_N.VALUE_13,
                    :ISHPISPRCV_N.VALUE_14,
                    :ISHPISPRCV_N.VALUE_15,
                    :ISHPISPRCV_N.VALUE_16,
                    :ISHPISPRCV_N.VALUE_17,
                    :ISHPISPRCV_N.VALUE_18,
                    :ISHPISPRCV_N.VALUE_19,
                    :ISHPISPRCV_N.VALUE_20,
                    :ISHPISPRCV_N.VALUE_21,
                    :ISHPISPRCV_N.VALUE_22,
                    :ISHPISPRCV_N.VALUE_23,
                    :ISHPISPRCV_N.VALUE_24,
                    :ISHPISPRCV_N.VALUE_25,
                    :ISHPISPRCV_N.SAMPLE_COUNT,
                    :ISHPISPRCV_N.SPEC_OUT_MASK,
                    :ISHPISPRCV_N.INSP_JUDGE_FLAG,
                    :ISHPISPRCV_N.INSP_JUDGE_TYPE,
                    :ISHPISPRCV_N.INSP_JUDGE_TIME,
                    :ISHPISPRCV_N.RECEIVE_FLAG,
                    :ISHPISPRCV_N.DELETE_FLAG,
                    :ISHPISPRCV_N.CMF_1,
                    :ISHPISPRCV_N.CMF_2,
                    :ISHPISPRCV_N.CMF_3,
                    :ISHPISPRCV_N.CMF_4,
                    :ISHPISPRCV_N.CMF_5,
                    :ISHPISPRCV_N.CMF_6,
                    :ISHPISPRCV_N.CMF_7,
                    :ISHPISPRCV_N.CMF_8,
                    :ISHPISPRCV_N.CMF_9,
                    :ISHPISPRCV_N.CMF_10,
                    :ISHPISPRCV_N.CREATE_USER_ID,
                    :ISHPISPRCV_N.CREATE_TIME,
                    :ISHPISPRCV_N.UPDATE_USER_ID,
                    :ISHPISPRCV_N.UPDATE_TIME
                FROM ISHPISPRCV
                WHERE FACTORY = :ISHPISPRCV_N.FACTORY
                    AND PACK_LOT_ID = :ISHPISPRCV_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :ISHPISPRCV_N.ORG_LOT_ID
                    AND INSP_ID = :ISHPISPRCV_N.INSP_ID
                    AND COL_SET_ID = :ISHPISPRCV_N.COL_SET_ID
                    AND CHAR_SEQ = :ISHPISPRCV_N.CHAR_SEQ
                    AND UNIT_SEQ = :ISHPISPRCV_N.UNIT_SEQ
                    AND VALUE_SEQ = :ISHPISPRCV_N.VALUE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,PACK_LOT_ID ,ORG_LOT_ID ,FROM_FACTORY ,INSP_I\
D ,COL_SET_ID ,COL_SET_VER ,CHAR_ID ,CHAR_SEQ ,UNIT_SEQ ,VALUE_SEQ ,UNIT_ID \
,VALUE_TYPE ,VALUE_COUNT ,VALUE_1 ,VALUE_2 ,VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE\
_6 ,VALUE_7 ,VALUE_8 ,VALUE_9 ,VALUE_10 ,VALUE_11 ,VALUE_12 ,VALUE_13 ,VALUE\
_14 ,VALUE_15 ,VALUE_16 ,VALUE_17 ,VALUE_18 ,VALUE_19 ,VALUE_20 ,VALUE_21 ,V\
ALUE_22 ,VALUE_23 ,VALUE_24 ,VALUE_25 ,SAMPLE_COUNT ,SPEC_OUT_MASK ,INSP_JUD\
GE_FLAG ,INSP_JUDGE_TYPE ,INSP_JUDGE_TIME ,RECEIVE_FLAG ,DELETE_FLAG ,CMF_1 \
,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER\
_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:\
b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b\
37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b5\
2,:b53,:b54,:b55,:b56,:b57,:b58,:b59  from ISHPISPRCV where (((((((FACTORY=:\
b0 and PACK_LOT_ID=:b1) and ORG_LOT_ID=:b2) and INS");
            sqlstm.stmt = "P_ID=:b4) and COL_SET_ID=:b5) and CHAR_SEQ=:b8) \
and UNIT_SEQ=:b9) and VALUE_SEQ=:b10)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ISHPISPRCV_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ISHPISPRCV_N.FROM_FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ISHPISPRCV_N.INSP_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(ISHPISPRCV_N.COL_SET_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(ISHPISPRCV_N.COL_SET_VER);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(ISHPISPRCV_N.CHAR_ID);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(ISHPISPRCV_N.CHAR_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(ISHPISPRCV_N.UNIT_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(ISHPISPRCV_N.VALUE_SEQ);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(ISHPISPRCV_N.UNIT_ID);
            sqlstm.sqhstl[11] = (unsigned int  )51;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(ISHPISPRCV_N.VALUE_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(ISHPISPRCV_N.VALUE_COUNT);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(ISHPISPRCV_N.VALUE_1);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(ISHPISPRCV_N.VALUE_2);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(ISHPISPRCV_N.VALUE_3);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(ISHPISPRCV_N.VALUE_4);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(ISHPISPRCV_N.VALUE_5);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(ISHPISPRCV_N.VALUE_6);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(ISHPISPRCV_N.VALUE_7);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(ISHPISPRCV_N.VALUE_8);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(ISHPISPRCV_N.VALUE_9);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(ISHPISPRCV_N.VALUE_10);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(ISHPISPRCV_N.VALUE_11);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(ISHPISPRCV_N.VALUE_12);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(ISHPISPRCV_N.VALUE_13);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(ISHPISPRCV_N.VALUE_14);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(ISHPISPRCV_N.VALUE_15);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(ISHPISPRCV_N.VALUE_16);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(ISHPISPRCV_N.VALUE_17);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(ISHPISPRCV_N.VALUE_18);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(ISHPISPRCV_N.VALUE_19);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(ISHPISPRCV_N.VALUE_20);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(ISHPISPRCV_N.VALUE_21);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(ISHPISPRCV_N.VALUE_22);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(ISHPISPRCV_N.VALUE_23);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(ISHPISPRCV_N.VALUE_24);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(ISHPISPRCV_N.VALUE_25);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(ISHPISPRCV_N.SAMPLE_COUNT);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(ISHPISPRCV_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(ISHPISPRCV_N.RECEIVE_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(ISHPISPRCV_N.DELETE_FLAG);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(ISHPISPRCV_N.CMF_1);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(ISHPISPRCV_N.CMF_2);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(ISHPISPRCV_N.CMF_3);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(ISHPISPRCV_N.CMF_4);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(ISHPISPRCV_N.CMF_5);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(ISHPISPRCV_N.CMF_6);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(ISHPISPRCV_N.CMF_7);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(ISHPISPRCV_N.CMF_8);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(ISHPISPRCV_N.CMF_9);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(ISHPISPRCV_N.CMF_10);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(ISHPISPRCV_N.CREATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(ISHPISPRCV_N.CREATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(ISHPISPRCV_N.UPDATE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(ISHPISPRCV_N.UPDATE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(ISHPISPRCV_N.FACTORY);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(ISHPISPRCV_N.INSP_ID);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(ISHPISPRCV_N.COL_SET_ID);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(ISHPISPRCV_N.CHAR_SEQ);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(ISHPISPRCV_N.UNIT_SEQ);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(ISHPISPRCV_N.VALUE_SEQ);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
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
        DBU_del_null_ishpisprcv(&ISHPISPRCV_N, ISHPISPRCV);
    }

    DB_stop_query_timer("DBU_select_ishpisprcv", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_ishpisprcv_for_update(int sel_type, struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ISHPISPRCV_N_TAG ISHPISPRCV_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ishpisprcv(&ISHPISPRCV_N, ISHPISPRCV);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    PACK_LOT_ID,
                    ORG_LOT_ID,
                    FROM_FACTORY,
                    INSP_ID,
                    COL_SET_ID,
                    COL_SET_VER,
                    CHAR_ID,
                    CHAR_SEQ,
                    UNIT_SEQ,
                    VALUE_SEQ,
                    UNIT_ID,
                    VALUE_TYPE,
                    VALUE_COUNT,
                    VALUE_1,
                    VALUE_2,
                    VALUE_3,
                    VALUE_4,
                    VALUE_5,
                    VALUE_6,
                    VALUE_7,
                    VALUE_8,
                    VALUE_9,
                    VALUE_10,
                    VALUE_11,
                    VALUE_12,
                    VALUE_13,
                    VALUE_14,
                    VALUE_15,
                    VALUE_16,
                    VALUE_17,
                    VALUE_18,
                    VALUE_19,
                    VALUE_20,
                    VALUE_21,
                    VALUE_22,
                    VALUE_23,
                    VALUE_24,
                    VALUE_25,
                    SAMPLE_COUNT,
                    SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME,
                    RECEIVE_FLAG,
                    DELETE_FLAG,
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
                    :ISHPISPRCV_N.FACTORY,
                    :ISHPISPRCV_N.PACK_LOT_ID,
                    :ISHPISPRCV_N.ORG_LOT_ID,
                    :ISHPISPRCV_N.FROM_FACTORY,
                    :ISHPISPRCV_N.INSP_ID,
                    :ISHPISPRCV_N.COL_SET_ID,
                    :ISHPISPRCV_N.COL_SET_VER,
                    :ISHPISPRCV_N.CHAR_ID,
                    :ISHPISPRCV_N.CHAR_SEQ,
                    :ISHPISPRCV_N.UNIT_SEQ,
                    :ISHPISPRCV_N.VALUE_SEQ,
                    :ISHPISPRCV_N.UNIT_ID,
                    :ISHPISPRCV_N.VALUE_TYPE,
                    :ISHPISPRCV_N.VALUE_COUNT,
                    :ISHPISPRCV_N.VALUE_1,
                    :ISHPISPRCV_N.VALUE_2,
                    :ISHPISPRCV_N.VALUE_3,
                    :ISHPISPRCV_N.VALUE_4,
                    :ISHPISPRCV_N.VALUE_5,
                    :ISHPISPRCV_N.VALUE_6,
                    :ISHPISPRCV_N.VALUE_7,
                    :ISHPISPRCV_N.VALUE_8,
                    :ISHPISPRCV_N.VALUE_9,
                    :ISHPISPRCV_N.VALUE_10,
                    :ISHPISPRCV_N.VALUE_11,
                    :ISHPISPRCV_N.VALUE_12,
                    :ISHPISPRCV_N.VALUE_13,
                    :ISHPISPRCV_N.VALUE_14,
                    :ISHPISPRCV_N.VALUE_15,
                    :ISHPISPRCV_N.VALUE_16,
                    :ISHPISPRCV_N.VALUE_17,
                    :ISHPISPRCV_N.VALUE_18,
                    :ISHPISPRCV_N.VALUE_19,
                    :ISHPISPRCV_N.VALUE_20,
                    :ISHPISPRCV_N.VALUE_21,
                    :ISHPISPRCV_N.VALUE_22,
                    :ISHPISPRCV_N.VALUE_23,
                    :ISHPISPRCV_N.VALUE_24,
                    :ISHPISPRCV_N.VALUE_25,
                    :ISHPISPRCV_N.SAMPLE_COUNT,
                    :ISHPISPRCV_N.SPEC_OUT_MASK,
                    :ISHPISPRCV_N.INSP_JUDGE_FLAG,
                    :ISHPISPRCV_N.INSP_JUDGE_TYPE,
                    :ISHPISPRCV_N.INSP_JUDGE_TIME,
                    :ISHPISPRCV_N.RECEIVE_FLAG,
                    :ISHPISPRCV_N.DELETE_FLAG,
                    :ISHPISPRCV_N.CMF_1,
                    :ISHPISPRCV_N.CMF_2,
                    :ISHPISPRCV_N.CMF_3,
                    :ISHPISPRCV_N.CMF_4,
                    :ISHPISPRCV_N.CMF_5,
                    :ISHPISPRCV_N.CMF_6,
                    :ISHPISPRCV_N.CMF_7,
                    :ISHPISPRCV_N.CMF_8,
                    :ISHPISPRCV_N.CMF_9,
                    :ISHPISPRCV_N.CMF_10,
                    :ISHPISPRCV_N.CREATE_USER_ID,
                    :ISHPISPRCV_N.CREATE_TIME,
                    :ISHPISPRCV_N.UPDATE_USER_ID,
                    :ISHPISPRCV_N.UPDATE_TIME
                FROM ISHPISPRCV
                WHERE FACTORY = :ISHPISPRCV_N.FACTORY
                    AND PACK_LOT_ID = :ISHPISPRCV_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :ISHPISPRCV_N.ORG_LOT_ID
                    AND INSP_ID = :ISHPISPRCV_N.INSP_ID
                    AND COL_SET_ID = :ISHPISPRCV_N.COL_SET_ID
                    AND CHAR_SEQ = :ISHPISPRCV_N.CHAR_SEQ
                    AND UNIT_SEQ = :ISHPISPRCV_N.UNIT_SEQ
                    AND VALUE_SEQ = :ISHPISPRCV_N.VALUE_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,PACK_LOT_ID ,ORG_LOT_ID ,FROM_FACTORY ,INSP_I\
D ,COL_SET_ID ,COL_SET_VER ,CHAR_ID ,CHAR_SEQ ,UNIT_SEQ ,VALUE_SEQ ,UNIT_ID \
,VALUE_TYPE ,VALUE_COUNT ,VALUE_1 ,VALUE_2 ,VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE\
_6 ,VALUE_7 ,VALUE_8 ,VALUE_9 ,VALUE_10 ,VALUE_11 ,VALUE_12 ,VALUE_13 ,VALUE\
_14 ,VALUE_15 ,VALUE_16 ,VALUE_17 ,VALUE_18 ,VALUE_19 ,VALUE_20 ,VALUE_21 ,V\
ALUE_22 ,VALUE_23 ,VALUE_24 ,VALUE_25 ,SAMPLE_COUNT ,SPEC_OUT_MASK ,INSP_JUD\
GE_FLAG ,INSP_JUDGE_TYPE ,INSP_JUDGE_TIME ,RECEIVE_FLAG ,DELETE_FLAG ,CMF_1 \
,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER\
_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:\
b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b\
37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b5\
2,:b53,:b54,:b55,:b56,:b57,:b58,:b59  from ISHPISPRCV where (((((((FACTORY=:\
b0 and PACK_LOT_ID=:b1) and ORG_LOT_ID=:b2) and INS");
            sqlstm.stmt = "P_ID=:b4) and COL_SET_ID=:b5) and CHAR_SEQ=:b8) \
and UNIT_SEQ=:b9) and VALUE_SEQ=:b10) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )292;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ISHPISPRCV_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ISHPISPRCV_N.FROM_FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ISHPISPRCV_N.INSP_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(ISHPISPRCV_N.COL_SET_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(ISHPISPRCV_N.COL_SET_VER);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(ISHPISPRCV_N.CHAR_ID);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(ISHPISPRCV_N.CHAR_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(ISHPISPRCV_N.UNIT_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(ISHPISPRCV_N.VALUE_SEQ);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(ISHPISPRCV_N.UNIT_ID);
            sqlstm.sqhstl[11] = (unsigned int  )51;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(ISHPISPRCV_N.VALUE_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(ISHPISPRCV_N.VALUE_COUNT);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(ISHPISPRCV_N.VALUE_1);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(ISHPISPRCV_N.VALUE_2);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(ISHPISPRCV_N.VALUE_3);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(ISHPISPRCV_N.VALUE_4);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(ISHPISPRCV_N.VALUE_5);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(ISHPISPRCV_N.VALUE_6);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(ISHPISPRCV_N.VALUE_7);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(ISHPISPRCV_N.VALUE_8);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(ISHPISPRCV_N.VALUE_9);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(ISHPISPRCV_N.VALUE_10);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(ISHPISPRCV_N.VALUE_11);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(ISHPISPRCV_N.VALUE_12);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(ISHPISPRCV_N.VALUE_13);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(ISHPISPRCV_N.VALUE_14);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(ISHPISPRCV_N.VALUE_15);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(ISHPISPRCV_N.VALUE_16);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(ISHPISPRCV_N.VALUE_17);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(ISHPISPRCV_N.VALUE_18);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(ISHPISPRCV_N.VALUE_19);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(ISHPISPRCV_N.VALUE_20);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(ISHPISPRCV_N.VALUE_21);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(ISHPISPRCV_N.VALUE_22);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(ISHPISPRCV_N.VALUE_23);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(ISHPISPRCV_N.VALUE_24);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(ISHPISPRCV_N.VALUE_25);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(ISHPISPRCV_N.SAMPLE_COUNT);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(ISHPISPRCV_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(ISHPISPRCV_N.RECEIVE_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(ISHPISPRCV_N.DELETE_FLAG);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(ISHPISPRCV_N.CMF_1);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(ISHPISPRCV_N.CMF_2);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(ISHPISPRCV_N.CMF_3);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(ISHPISPRCV_N.CMF_4);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(ISHPISPRCV_N.CMF_5);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(ISHPISPRCV_N.CMF_6);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(ISHPISPRCV_N.CMF_7);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(ISHPISPRCV_N.CMF_8);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(ISHPISPRCV_N.CMF_9);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(ISHPISPRCV_N.CMF_10);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(ISHPISPRCV_N.CREATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(ISHPISPRCV_N.CREATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(ISHPISPRCV_N.UPDATE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(ISHPISPRCV_N.UPDATE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(ISHPISPRCV_N.FACTORY);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(ISHPISPRCV_N.INSP_ID);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(ISHPISPRCV_N.COL_SET_ID);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(ISHPISPRCV_N.CHAR_SEQ);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(ISHPISPRCV_N.UNIT_SEQ);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(ISHPISPRCV_N.VALUE_SEQ);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
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
        DBU_del_null_ishpisprcv(&ISHPISPRCV_N, ISHPISPRCV);
    }

    DB_stop_query_timer("DBU_select_ishpisprcv_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_ishpisprcv_scalar(int sel_type, struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ISHPISPRCV_N_TAG ISHPISPRCV_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ishpisprcv(&ISHPISPRCV_N, ISHPISPRCV);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM ISHPISPRCV
                WHERE FACTORY = :ISHPISPRCV_N.FACTORY
                    AND PACK_LOT_ID = :ISHPISPRCV_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :ISHPISPRCV_N.ORG_LOT_ID
                    AND INSP_ID = :ISHPISPRCV_N.INSP_ID
                    AND COL_SET_ID = :ISHPISPRCV_N.COL_SET_ID
                    AND CHAR_SEQ = :ISHPISPRCV_N.CHAR_SEQ
                    AND UNIT_SEQ = :ISHPISPRCV_N.UNIT_SEQ
                    AND VALUE_SEQ = :ISHPISPRCV_N.VALUE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from ISHPISPRCV where\
 (((((((FACTORY=:b1 and PACK_LOT_ID=:b2) and ORG_LOT_ID=:b3) and INSP_ID=:b4)\
 and COL_SET_ID=:b5) and CHAR_SEQ=:b6) and UNIT_SEQ=:b7) and VALUE_SEQ=:b8)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )579;
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
            sqlstm.sqhstv[1] = (         void  *)(ISHPISPRCV_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ISHPISPRCV_N.INSP_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(ISHPISPRCV_N.COL_SET_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(ISHPISPRCV_N.CHAR_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(ISHPISPRCV_N.UNIT_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(ISHPISPRCV_N.VALUE_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
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
                FROM ISHPISPRCV
                WHERE FACTORY = :ISHPISPRCV_N.FACTORY
                    AND PACK_LOT_ID = :ISHPISPRCV_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :ISHPISPRCV_N.ORG_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from ISHPISPRCV where\
 ((FACTORY=:b1 and PACK_LOT_ID=:b2) and ORG_LOT_ID=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )630;
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
            sqlstm.sqhstv[1] = (         void  *)(ISHPISPRCV_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_select_ishpisprcv_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_ishpisprcv(int sel_type, struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ISHPISPRCV_N_TAG ISHPISPRCV_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ishpisprcv(&ISHPISPRCV_N, ISHPISPRCV);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM ISHPISPRCV
                WHERE FACTORY = :ISHPISPRCV_N.FACTORY
                    AND PACK_LOT_ID = :ISHPISPRCV_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :ISHPISPRCV_N.ORG_LOT_ID
                    AND INSP_ID = :ISHPISPRCV_N.INSP_ID
                    AND COL_SET_ID = :ISHPISPRCV_N.COL_SET_ID
                    AND CHAR_SEQ = :ISHPISPRCV_N.CHAR_SEQ
                    AND UNIT_SEQ = :ISHPISPRCV_N.UNIT_SEQ
                    AND VALUE_SEQ = :ISHPISPRCV_N.VALUE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from ISHPISPRCV  where (((((((FACTORY=:b\
0 and PACK_LOT_ID=:b1) and ORG_LOT_ID=:b2) and INSP_ID=:b3) and COL_SET_ID=:b\
4) and CHAR_SEQ=:b5) and UNIT_SEQ=:b6) and VALUE_SEQ=:b7)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )661;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ISHPISPRCV_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ISHPISPRCV_N.INSP_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ISHPISPRCV_N.COL_SET_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(ISHPISPRCV_N.CHAR_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(ISHPISPRCV_N.UNIT_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(ISHPISPRCV_N.VALUE_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_delete_ishpisprcv", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_ishpisprcv(struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ISHPISPRCV_N_TAG ISHPISPRCV_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ishpisprcv(&ISHPISPRCV_N, ISHPISPRCV);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO ISHPISPRCV( 
                    FACTORY, 
                    PACK_LOT_ID, 
                    ORG_LOT_ID, 
                    FROM_FACTORY, 
                    INSP_ID, 
                    COL_SET_ID, 
                    COL_SET_VER, 
                    CHAR_ID, 
                    CHAR_SEQ, 
                    UNIT_SEQ, 
                    VALUE_SEQ, 
                    UNIT_ID, 
                    VALUE_TYPE, 
                    VALUE_COUNT, 
                    VALUE_1, 
                    VALUE_2, 
                    VALUE_3, 
                    VALUE_4, 
                    VALUE_5, 
                    VALUE_6, 
                    VALUE_7, 
                    VALUE_8, 
                    VALUE_9, 
                    VALUE_10, 
                    VALUE_11, 
                    VALUE_12, 
                    VALUE_13, 
                    VALUE_14, 
                    VALUE_15, 
                    VALUE_16, 
                    VALUE_17, 
                    VALUE_18, 
                    VALUE_19, 
                    VALUE_20, 
                    VALUE_21, 
                    VALUE_22, 
                    VALUE_23, 
                    VALUE_24, 
                    VALUE_25, 
                    SAMPLE_COUNT, 
                    SPEC_OUT_MASK, 
                    INSP_JUDGE_FLAG, 
                    INSP_JUDGE_TYPE, 
                    INSP_JUDGE_TIME, 
                    RECEIVE_FLAG, 
                    DELETE_FLAG, 
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
                    :ISHPISPRCV_N.FACTORY,
                    :ISHPISPRCV_N.PACK_LOT_ID,
                    :ISHPISPRCV_N.ORG_LOT_ID,
                    :ISHPISPRCV_N.FROM_FACTORY,
                    :ISHPISPRCV_N.INSP_ID,
                    :ISHPISPRCV_N.COL_SET_ID,
                    :ISHPISPRCV_N.COL_SET_VER,
                    :ISHPISPRCV_N.CHAR_ID,
                    :ISHPISPRCV_N.CHAR_SEQ,
                    :ISHPISPRCV_N.UNIT_SEQ,
                    :ISHPISPRCV_N.VALUE_SEQ,
                    :ISHPISPRCV_N.UNIT_ID,
                    :ISHPISPRCV_N.VALUE_TYPE,
                    :ISHPISPRCV_N.VALUE_COUNT,
                    :ISHPISPRCV_N.VALUE_1,
                    :ISHPISPRCV_N.VALUE_2,
                    :ISHPISPRCV_N.VALUE_3,
                    :ISHPISPRCV_N.VALUE_4,
                    :ISHPISPRCV_N.VALUE_5,
                    :ISHPISPRCV_N.VALUE_6,
                    :ISHPISPRCV_N.VALUE_7,
                    :ISHPISPRCV_N.VALUE_8,
                    :ISHPISPRCV_N.VALUE_9,
                    :ISHPISPRCV_N.VALUE_10,
                    :ISHPISPRCV_N.VALUE_11,
                    :ISHPISPRCV_N.VALUE_12,
                    :ISHPISPRCV_N.VALUE_13,
                    :ISHPISPRCV_N.VALUE_14,
                    :ISHPISPRCV_N.VALUE_15,
                    :ISHPISPRCV_N.VALUE_16,
                    :ISHPISPRCV_N.VALUE_17,
                    :ISHPISPRCV_N.VALUE_18,
                    :ISHPISPRCV_N.VALUE_19,
                    :ISHPISPRCV_N.VALUE_20,
                    :ISHPISPRCV_N.VALUE_21,
                    :ISHPISPRCV_N.VALUE_22,
                    :ISHPISPRCV_N.VALUE_23,
                    :ISHPISPRCV_N.VALUE_24,
                    :ISHPISPRCV_N.VALUE_25,
                    :ISHPISPRCV_N.SAMPLE_COUNT,
                    :ISHPISPRCV_N.SPEC_OUT_MASK,
                    :ISHPISPRCV_N.INSP_JUDGE_FLAG,
                    :ISHPISPRCV_N.INSP_JUDGE_TYPE,
                    :ISHPISPRCV_N.INSP_JUDGE_TIME,
                    :ISHPISPRCV_N.RECEIVE_FLAG,
                    :ISHPISPRCV_N.DELETE_FLAG,
                    :ISHPISPRCV_N.CMF_1,
                    :ISHPISPRCV_N.CMF_2,
                    :ISHPISPRCV_N.CMF_3,
                    :ISHPISPRCV_N.CMF_4,
                    :ISHPISPRCV_N.CMF_5,
                    :ISHPISPRCV_N.CMF_6,
                    :ISHPISPRCV_N.CMF_7,
                    :ISHPISPRCV_N.CMF_8,
                    :ISHPISPRCV_N.CMF_9,
                    :ISHPISPRCV_N.CMF_10,
                    :ISHPISPRCV_N.CREATE_USER_ID,
                    :ISHPISPRCV_N.CREATE_TIME,
                    :ISHPISPRCV_N.UPDATE_USER_ID,
                    :ISHPISPRCV_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 68;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into ISHPISPRCV (FACTORY,PACK_LOT_ID,ORG_LOT_ID,F\
ROM_FACTORY,INSP_ID,COL_SET_ID,COL_SET_VER,CHAR_ID,CHAR_SEQ,UNIT_SEQ,VALUE_SE\
Q,UNIT_ID,VALUE_TYPE,VALUE_COUNT,VALUE_1,VALUE_2,VALUE_3,VALUE_4,VALUE_5,VALU\
E_6,VALUE_7,VALUE_8,VALUE_9,VALUE_10,VALUE_11,VALUE_12,VALUE_13,VALUE_14,VALU\
E_15,VALUE_16,VALUE_17,VALUE_18,VALUE_19,VALUE_20,VALUE_21,VALUE_22,VALUE_23,\
VALUE_24,VALUE_25,SAMPLE_COUNT,SPEC_OUT_MASK,INSP_JUDGE_FLAG,INSP_JUDGE_TYPE,\
INSP_JUDGE_TIME,RECEIVE_FLAG,DELETE_FLAG,CMF_1,CMF_2,CMF_3,CMF_4,CMF_5,CMF_6,\
CMF_7,CMF_8,CMF_9,CMF_10,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIM\
E) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:\
b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b3\
0,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,\
:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )708;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(ISHPISPRCV_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
    sqlstm.sqhstl[1] = (unsigned int  )26;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
    sqlstm.sqhstl[2] = (unsigned int  )26;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(ISHPISPRCV_N.FROM_FACTORY);
    sqlstm.sqhstl[3] = (unsigned int  )11;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(ISHPISPRCV_N.INSP_ID);
    sqlstm.sqhstl[4] = (unsigned int  )31;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(ISHPISPRCV_N.COL_SET_ID);
    sqlstm.sqhstl[5] = (unsigned int  )26;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)&(ISHPISPRCV_N.COL_SET_VER);
    sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(ISHPISPRCV_N.CHAR_ID);
    sqlstm.sqhstl[7] = (unsigned int  )26;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)&(ISHPISPRCV_N.CHAR_SEQ);
    sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)&(ISHPISPRCV_N.UNIT_SEQ);
    sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)&(ISHPISPRCV_N.VALUE_SEQ);
    sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(ISHPISPRCV_N.UNIT_ID);
    sqlstm.sqhstl[11] = (unsigned int  )51;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(ISHPISPRCV_N.VALUE_TYPE);
    sqlstm.sqhstl[12] = (unsigned int  )2;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)&(ISHPISPRCV_N.VALUE_COUNT);
    sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(ISHPISPRCV_N.VALUE_1);
    sqlstm.sqhstl[14] = (unsigned int  )26;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(ISHPISPRCV_N.VALUE_2);
    sqlstm.sqhstl[15] = (unsigned int  )26;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(ISHPISPRCV_N.VALUE_3);
    sqlstm.sqhstl[16] = (unsigned int  )26;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(ISHPISPRCV_N.VALUE_4);
    sqlstm.sqhstl[17] = (unsigned int  )26;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(ISHPISPRCV_N.VALUE_5);
    sqlstm.sqhstl[18] = (unsigned int  )26;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(ISHPISPRCV_N.VALUE_6);
    sqlstm.sqhstl[19] = (unsigned int  )26;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(ISHPISPRCV_N.VALUE_7);
    sqlstm.sqhstl[20] = (unsigned int  )26;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(ISHPISPRCV_N.VALUE_8);
    sqlstm.sqhstl[21] = (unsigned int  )26;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(ISHPISPRCV_N.VALUE_9);
    sqlstm.sqhstl[22] = (unsigned int  )26;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(ISHPISPRCV_N.VALUE_10);
    sqlstm.sqhstl[23] = (unsigned int  )26;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(ISHPISPRCV_N.VALUE_11);
    sqlstm.sqhstl[24] = (unsigned int  )26;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(ISHPISPRCV_N.VALUE_12);
    sqlstm.sqhstl[25] = (unsigned int  )26;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(ISHPISPRCV_N.VALUE_13);
    sqlstm.sqhstl[26] = (unsigned int  )26;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(ISHPISPRCV_N.VALUE_14);
    sqlstm.sqhstl[27] = (unsigned int  )26;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(ISHPISPRCV_N.VALUE_15);
    sqlstm.sqhstl[28] = (unsigned int  )26;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(ISHPISPRCV_N.VALUE_16);
    sqlstm.sqhstl[29] = (unsigned int  )26;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(ISHPISPRCV_N.VALUE_17);
    sqlstm.sqhstl[30] = (unsigned int  )26;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(ISHPISPRCV_N.VALUE_18);
    sqlstm.sqhstl[31] = (unsigned int  )26;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(ISHPISPRCV_N.VALUE_19);
    sqlstm.sqhstl[32] = (unsigned int  )26;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(ISHPISPRCV_N.VALUE_20);
    sqlstm.sqhstl[33] = (unsigned int  )26;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(ISHPISPRCV_N.VALUE_21);
    sqlstm.sqhstl[34] = (unsigned int  )26;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(ISHPISPRCV_N.VALUE_22);
    sqlstm.sqhstl[35] = (unsigned int  )26;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(ISHPISPRCV_N.VALUE_23);
    sqlstm.sqhstl[36] = (unsigned int  )26;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(ISHPISPRCV_N.VALUE_24);
    sqlstm.sqhstl[37] = (unsigned int  )26;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(ISHPISPRCV_N.VALUE_25);
    sqlstm.sqhstl[38] = (unsigned int  )26;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)&(ISHPISPRCV_N.SAMPLE_COUNT);
    sqlstm.sqhstl[39] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(ISHPISPRCV_N.SPEC_OUT_MASK);
    sqlstm.sqhstl[40] = (unsigned int  )26;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_FLAG);
    sqlstm.sqhstl[41] = (unsigned int  )2;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_TYPE);
    sqlstm.sqhstl[42] = (unsigned int  )31;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_TIME);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(ISHPISPRCV_N.RECEIVE_FLAG);
    sqlstm.sqhstl[44] = (unsigned int  )2;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(ISHPISPRCV_N.DELETE_FLAG);
    sqlstm.sqhstl[45] = (unsigned int  )2;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(ISHPISPRCV_N.CMF_1);
    sqlstm.sqhstl[46] = (unsigned int  )51;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(ISHPISPRCV_N.CMF_2);
    sqlstm.sqhstl[47] = (unsigned int  )51;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(ISHPISPRCV_N.CMF_3);
    sqlstm.sqhstl[48] = (unsigned int  )51;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(ISHPISPRCV_N.CMF_4);
    sqlstm.sqhstl[49] = (unsigned int  )51;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(ISHPISPRCV_N.CMF_5);
    sqlstm.sqhstl[50] = (unsigned int  )51;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(ISHPISPRCV_N.CMF_6);
    sqlstm.sqhstl[51] = (unsigned int  )51;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(ISHPISPRCV_N.CMF_7);
    sqlstm.sqhstl[52] = (unsigned int  )51;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(ISHPISPRCV_N.CMF_8);
    sqlstm.sqhstl[53] = (unsigned int  )51;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(ISHPISPRCV_N.CMF_9);
    sqlstm.sqhstl[54] = (unsigned int  )51;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(ISHPISPRCV_N.CMF_10);
    sqlstm.sqhstl[55] = (unsigned int  )51;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(ISHPISPRCV_N.CREATE_USER_ID);
    sqlstm.sqhstl[56] = (unsigned int  )21;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(ISHPISPRCV_N.CREATE_TIME);
    sqlstm.sqhstl[57] = (unsigned int  )15;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(ISHPISPRCV_N.UPDATE_USER_ID);
    sqlstm.sqhstl[58] = (unsigned int  )21;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(ISHPISPRCV_N.UPDATE_TIME);
    sqlstm.sqhstl[59] = (unsigned int  )15;
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



    DB_stop_query_timer("DBU_insert_ishpisprcv", 0);
}


/* SQL UPDATE Function */
void DBU_update_ishpisprcv(int sel_type, struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ISHPISPRCV_N_TAG ISHPISPRCV_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ishpisprcv(&ISHPISPRCV_N, ISHPISPRCV);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE ISHPISPRCV SET
                    FROM_FACTORY = :ISHPISPRCV_N.FROM_FACTORY,
                    COL_SET_VER = :ISHPISPRCV_N.COL_SET_VER,
                    CHAR_ID = :ISHPISPRCV_N.CHAR_ID,
                    UNIT_ID = :ISHPISPRCV_N.UNIT_ID,
                    VALUE_TYPE = :ISHPISPRCV_N.VALUE_TYPE,
                    VALUE_COUNT = :ISHPISPRCV_N.VALUE_COUNT,
                    VALUE_1 = :ISHPISPRCV_N.VALUE_1,
                    VALUE_2 = :ISHPISPRCV_N.VALUE_2,
                    VALUE_3 = :ISHPISPRCV_N.VALUE_3,
                    VALUE_4 = :ISHPISPRCV_N.VALUE_4,
                    VALUE_5 = :ISHPISPRCV_N.VALUE_5,
                    VALUE_6 = :ISHPISPRCV_N.VALUE_6,
                    VALUE_7 = :ISHPISPRCV_N.VALUE_7,
                    VALUE_8 = :ISHPISPRCV_N.VALUE_8,
                    VALUE_9 = :ISHPISPRCV_N.VALUE_9,
                    VALUE_10 = :ISHPISPRCV_N.VALUE_10,
                    VALUE_11 = :ISHPISPRCV_N.VALUE_11,
                    VALUE_12 = :ISHPISPRCV_N.VALUE_12,
                    VALUE_13 = :ISHPISPRCV_N.VALUE_13,
                    VALUE_14 = :ISHPISPRCV_N.VALUE_14,
                    VALUE_15 = :ISHPISPRCV_N.VALUE_15,
                    VALUE_16 = :ISHPISPRCV_N.VALUE_16,
                    VALUE_17 = :ISHPISPRCV_N.VALUE_17,
                    VALUE_18 = :ISHPISPRCV_N.VALUE_18,
                    VALUE_19 = :ISHPISPRCV_N.VALUE_19,
                    VALUE_20 = :ISHPISPRCV_N.VALUE_20,
                    VALUE_21 = :ISHPISPRCV_N.VALUE_21,
                    VALUE_22 = :ISHPISPRCV_N.VALUE_22,
                    VALUE_23 = :ISHPISPRCV_N.VALUE_23,
                    VALUE_24 = :ISHPISPRCV_N.VALUE_24,
                    VALUE_25 = :ISHPISPRCV_N.VALUE_25,
                    SAMPLE_COUNT = :ISHPISPRCV_N.SAMPLE_COUNT,
                    SPEC_OUT_MASK = :ISHPISPRCV_N.SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG = :ISHPISPRCV_N.INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE = :ISHPISPRCV_N.INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME = :ISHPISPRCV_N.INSP_JUDGE_TIME,
                    RECEIVE_FLAG = :ISHPISPRCV_N.RECEIVE_FLAG,
                    DELETE_FLAG = :ISHPISPRCV_N.DELETE_FLAG,
                    CMF_1 = :ISHPISPRCV_N.CMF_1,
                    CMF_2 = :ISHPISPRCV_N.CMF_2,
                    CMF_3 = :ISHPISPRCV_N.CMF_3,
                    CMF_4 = :ISHPISPRCV_N.CMF_4,
                    CMF_5 = :ISHPISPRCV_N.CMF_5,
                    CMF_6 = :ISHPISPRCV_N.CMF_6,
                    CMF_7 = :ISHPISPRCV_N.CMF_7,
                    CMF_8 = :ISHPISPRCV_N.CMF_8,
                    CMF_9 = :ISHPISPRCV_N.CMF_9,
                    CMF_10 = :ISHPISPRCV_N.CMF_10,
                    CREATE_USER_ID = :ISHPISPRCV_N.CREATE_USER_ID,
                    CREATE_TIME = :ISHPISPRCV_N.CREATE_TIME,
                    UPDATE_USER_ID = :ISHPISPRCV_N.UPDATE_USER_ID,
                    UPDATE_TIME = :ISHPISPRCV_N.UPDATE_TIME
                WHERE FACTORY = :ISHPISPRCV_N.FACTORY
                    AND PACK_LOT_ID = :ISHPISPRCV_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :ISHPISPRCV_N.ORG_LOT_ID
                    AND INSP_ID = :ISHPISPRCV_N.INSP_ID
                    AND COL_SET_ID = :ISHPISPRCV_N.COL_SET_ID
                    AND CHAR_SEQ = :ISHPISPRCV_N.CHAR_SEQ
                    AND UNIT_SEQ = :ISHPISPRCV_N.UNIT_SEQ
                    AND VALUE_SEQ = :ISHPISPRCV_N.VALUE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update ISHPISPRCV  set FROM_FACTORY=:b0,COL_SET_\
VER=:b1,CHAR_ID=:b2,UNIT_ID=:b3,VALUE_TYPE=:b4,VALUE_COUNT=:b5,VALUE_1=:b6,VA\
LUE_2=:b7,VALUE_3=:b8,VALUE_4=:b9,VALUE_5=:b10,VALUE_6=:b11,VALUE_7=:b12,VALU\
E_8=:b13,VALUE_9=:b14,VALUE_10=:b15,VALUE_11=:b16,VALUE_12=:b17,VALUE_13=:b18\
,VALUE_14=:b19,VALUE_15=:b20,VALUE_16=:b21,VALUE_17=:b22,VALUE_18=:b23,VALUE_\
19=:b24,VALUE_20=:b25,VALUE_21=:b26,VALUE_22=:b27,VALUE_23=:b28,VALUE_24=:b29\
,VALUE_25=:b30,SAMPLE_COUNT=:b31,SPEC_OUT_MASK=:b32,INSP_JUDGE_FLAG=:b33,INSP\
_JUDGE_TYPE=:b34,INSP_JUDGE_TIME=:b35,RECEIVE_FLAG=:b36,DELETE_FLAG=:b37,CMF_\
1=:b38,CMF_2=:b39,CMF_3=:b40,CMF_4=:b41,CMF_5=:b42,CMF_6=:b43,CMF_7=:b44,CMF_\
8=:b45,CMF_9=:b46,CMF_10=:b47,CREATE_USER_ID=:b48,CREATE_TIME=:b49,UPDATE_USE\
R_ID=:b50,UPDATE_TIME=:b51 where (((((((FACTORY=:b52 and PACK_LOT_ID=:b53) an\
d ORG_LOT_ID=:b54) and INSP_ID=:b55) and COL_SET_ID=:b56) and CHAR_SEQ=:b57) \
and UNIT_SEQ=:b58) and VALUE_SEQ=:b59)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )963;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ISHPISPRCV_N.FROM_FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(ISHPISPRCV_N.COL_SET_VER);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ISHPISPRCV_N.CHAR_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ISHPISPRCV_N.UNIT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )51;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ISHPISPRCV_N.VALUE_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(ISHPISPRCV_N.VALUE_COUNT);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(ISHPISPRCV_N.VALUE_1);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(ISHPISPRCV_N.VALUE_2);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(ISHPISPRCV_N.VALUE_3);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(ISHPISPRCV_N.VALUE_4);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(ISHPISPRCV_N.VALUE_5);
            sqlstm.sqhstl[10] = (unsigned int  )26;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(ISHPISPRCV_N.VALUE_6);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(ISHPISPRCV_N.VALUE_7);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(ISHPISPRCV_N.VALUE_8);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(ISHPISPRCV_N.VALUE_9);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(ISHPISPRCV_N.VALUE_10);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(ISHPISPRCV_N.VALUE_11);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(ISHPISPRCV_N.VALUE_12);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(ISHPISPRCV_N.VALUE_13);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(ISHPISPRCV_N.VALUE_14);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(ISHPISPRCV_N.VALUE_15);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(ISHPISPRCV_N.VALUE_16);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(ISHPISPRCV_N.VALUE_17);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(ISHPISPRCV_N.VALUE_18);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(ISHPISPRCV_N.VALUE_19);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(ISHPISPRCV_N.VALUE_20);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(ISHPISPRCV_N.VALUE_21);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(ISHPISPRCV_N.VALUE_22);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(ISHPISPRCV_N.VALUE_23);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(ISHPISPRCV_N.VALUE_24);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(ISHPISPRCV_N.VALUE_25);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(ISHPISPRCV_N.SAMPLE_COUNT);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(ISHPISPRCV_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(ISHPISPRCV_N.RECEIVE_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(ISHPISPRCV_N.DELETE_FLAG);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(ISHPISPRCV_N.CMF_1);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(ISHPISPRCV_N.CMF_2);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(ISHPISPRCV_N.CMF_3);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(ISHPISPRCV_N.CMF_4);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(ISHPISPRCV_N.CMF_5);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(ISHPISPRCV_N.CMF_6);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(ISHPISPRCV_N.CMF_7);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(ISHPISPRCV_N.CMF_8);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(ISHPISPRCV_N.CMF_9);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(ISHPISPRCV_N.CMF_10);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(ISHPISPRCV_N.CREATE_USER_ID);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(ISHPISPRCV_N.CREATE_TIME);
            sqlstm.sqhstl[49] = (unsigned int  )15;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(ISHPISPRCV_N.UPDATE_USER_ID);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(ISHPISPRCV_N.UPDATE_TIME);
            sqlstm.sqhstl[51] = (unsigned int  )15;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(ISHPISPRCV_N.FACTORY);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
            sqlstm.sqhstl[54] = (unsigned int  )26;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(ISHPISPRCV_N.INSP_ID);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(ISHPISPRCV_N.COL_SET_ID);
            sqlstm.sqhstl[56] = (unsigned int  )26;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(ISHPISPRCV_N.CHAR_SEQ);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(ISHPISPRCV_N.UNIT_SEQ);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(ISHPISPRCV_N.VALUE_SEQ);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
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
            /* EXEC SQL UPDATE ISHPISPRCV SET                
                    RECEIVE_FLAG = :ISHPISPRCV_N.RECEIVE_FLAG,
                    UPDATE_USER_ID = :ISHPISPRCV_N.UPDATE_USER_ID,
                    UPDATE_TIME = :ISHPISPRCV_N.UPDATE_TIME
                WHERE FACTORY = :ISHPISPRCV_N.FACTORY
                    AND PACK_LOT_ID = :ISHPISPRCV_N.PACK_LOT_ID
                    AND ORG_LOT_ID = :ISHPISPRCV_N.ORG_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update ISHPISPRCV  set RECEIVE_FLAG=:b0,UPDATE_U\
SER_ID=:b1,UPDATE_TIME=:b2 where ((FACTORY=:b3 and PACK_LOT_ID=:b4) and ORG_L\
OT_ID=:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1218;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(ISHPISPRCV_N.RECEIVE_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ISHPISPRCV_N.UPDATE_USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ISHPISPRCV_N.UPDATE_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ISHPISPRCV_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_ishpisprcv", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_ishpisprcv(int sel_type, struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ISHPISPRCV_N_TAG ISHPISPRCV_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_ishpisprcv(&ISHPISPRCV_N, ISHPISPRCV);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_ISHPISPRCV_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    PACK_LOT_ID,
                    ORG_LOT_ID,
                    FROM_FACTORY,
                    INSP_ID,
                    COL_SET_ID,
                    COL_SET_VER,
                    CHAR_ID,
                    CHAR_SEQ,
                    UNIT_SEQ,
                    VALUE_SEQ,
                    UNIT_ID,
                    VALUE_TYPE,
                    VALUE_COUNT,
                    VALUE_1,
                    VALUE_2,
                    VALUE_3,
                    VALUE_4,
                    VALUE_5,
                    VALUE_6,
                    VALUE_7,
                    VALUE_8,
                    VALUE_9,
                    VALUE_10,
                    VALUE_11,
                    VALUE_12,
                    VALUE_13,
                    VALUE_14,
                    VALUE_15,
                    VALUE_16,
                    VALUE_17,
                    VALUE_18,
                    VALUE_19,
                    VALUE_20,
                    VALUE_21,
                    VALUE_22,
                    VALUE_23,
                    VALUE_24,
                    VALUE_25,
                    SAMPLE_COUNT,
                    SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME,
                    RECEIVE_FLAG,
                    DELETE_FLAG,
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
                FROM ISHPISPRCV
                ORDER BY FACTORY ASC,
                    PACK_LOT_ID ASC,
                    ORG_LOT_ID ASC,
                    INSP_ID ASC,
                    COL_SET_ID ASC,
                    CHAR_SEQ ASC,
                    UNIT_SEQ ASC,
                    VALUE_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_ISHPISPRCV_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1257;
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

    DB_stop_query_timer("DBU_open_ishpisprcv", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_ishpisprcv(int sel_type, struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct ISHPISPRCV_N_TAG ISHPISPRCV_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_ISHPISPRCV_CUR_1 INTO
                :ISHPISPRCV_N.FACTORY,
                :ISHPISPRCV_N.PACK_LOT_ID,
                :ISHPISPRCV_N.ORG_LOT_ID,
                :ISHPISPRCV_N.FROM_FACTORY,
                :ISHPISPRCV_N.INSP_ID,
                :ISHPISPRCV_N.COL_SET_ID,
                :ISHPISPRCV_N.COL_SET_VER,
                :ISHPISPRCV_N.CHAR_ID,
                :ISHPISPRCV_N.CHAR_SEQ,
                :ISHPISPRCV_N.UNIT_SEQ,
                :ISHPISPRCV_N.VALUE_SEQ,
                :ISHPISPRCV_N.UNIT_ID,
                :ISHPISPRCV_N.VALUE_TYPE,
                :ISHPISPRCV_N.VALUE_COUNT,
                :ISHPISPRCV_N.VALUE_1,
                :ISHPISPRCV_N.VALUE_2,
                :ISHPISPRCV_N.VALUE_3,
                :ISHPISPRCV_N.VALUE_4,
                :ISHPISPRCV_N.VALUE_5,
                :ISHPISPRCV_N.VALUE_6,
                :ISHPISPRCV_N.VALUE_7,
                :ISHPISPRCV_N.VALUE_8,
                :ISHPISPRCV_N.VALUE_9,
                :ISHPISPRCV_N.VALUE_10,
                :ISHPISPRCV_N.VALUE_11,
                :ISHPISPRCV_N.VALUE_12,
                :ISHPISPRCV_N.VALUE_13,
                :ISHPISPRCV_N.VALUE_14,
                :ISHPISPRCV_N.VALUE_15,
                :ISHPISPRCV_N.VALUE_16,
                :ISHPISPRCV_N.VALUE_17,
                :ISHPISPRCV_N.VALUE_18,
                :ISHPISPRCV_N.VALUE_19,
                :ISHPISPRCV_N.VALUE_20,
                :ISHPISPRCV_N.VALUE_21,
                :ISHPISPRCV_N.VALUE_22,
                :ISHPISPRCV_N.VALUE_23,
                :ISHPISPRCV_N.VALUE_24,
                :ISHPISPRCV_N.VALUE_25,
                :ISHPISPRCV_N.SAMPLE_COUNT,
                :ISHPISPRCV_N.SPEC_OUT_MASK,
                :ISHPISPRCV_N.INSP_JUDGE_FLAG,
                :ISHPISPRCV_N.INSP_JUDGE_TYPE,
                :ISHPISPRCV_N.INSP_JUDGE_TIME,
                :ISHPISPRCV_N.RECEIVE_FLAG,
                :ISHPISPRCV_N.DELETE_FLAG,
                :ISHPISPRCV_N.CMF_1,
                :ISHPISPRCV_N.CMF_2,
                :ISHPISPRCV_N.CMF_3,
                :ISHPISPRCV_N.CMF_4,
                :ISHPISPRCV_N.CMF_5,
                :ISHPISPRCV_N.CMF_6,
                :ISHPISPRCV_N.CMF_7,
                :ISHPISPRCV_N.CMF_8,
                :ISHPISPRCV_N.CMF_9,
                :ISHPISPRCV_N.CMF_10,
                :ISHPISPRCV_N.CREATE_USER_ID,
                :ISHPISPRCV_N.CREATE_TIME,
                :ISHPISPRCV_N.UPDATE_USER_ID,
                :ISHPISPRCV_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1272;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(ISHPISPRCV_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(ISHPISPRCV_N.PACK_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(ISHPISPRCV_N.ORG_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(ISHPISPRCV_N.FROM_FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(ISHPISPRCV_N.INSP_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(ISHPISPRCV_N.COL_SET_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(ISHPISPRCV_N.COL_SET_VER);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(ISHPISPRCV_N.CHAR_ID);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(ISHPISPRCV_N.CHAR_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(ISHPISPRCV_N.UNIT_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(ISHPISPRCV_N.VALUE_SEQ);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(ISHPISPRCV_N.UNIT_ID);
            sqlstm.sqhstl[11] = (unsigned int  )51;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(ISHPISPRCV_N.VALUE_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(ISHPISPRCV_N.VALUE_COUNT);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(ISHPISPRCV_N.VALUE_1);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(ISHPISPRCV_N.VALUE_2);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(ISHPISPRCV_N.VALUE_3);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(ISHPISPRCV_N.VALUE_4);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(ISHPISPRCV_N.VALUE_5);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(ISHPISPRCV_N.VALUE_6);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(ISHPISPRCV_N.VALUE_7);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(ISHPISPRCV_N.VALUE_8);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(ISHPISPRCV_N.VALUE_9);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(ISHPISPRCV_N.VALUE_10);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(ISHPISPRCV_N.VALUE_11);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(ISHPISPRCV_N.VALUE_12);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(ISHPISPRCV_N.VALUE_13);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(ISHPISPRCV_N.VALUE_14);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(ISHPISPRCV_N.VALUE_15);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(ISHPISPRCV_N.VALUE_16);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(ISHPISPRCV_N.VALUE_17);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(ISHPISPRCV_N.VALUE_18);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(ISHPISPRCV_N.VALUE_19);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(ISHPISPRCV_N.VALUE_20);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(ISHPISPRCV_N.VALUE_21);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(ISHPISPRCV_N.VALUE_22);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(ISHPISPRCV_N.VALUE_23);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(ISHPISPRCV_N.VALUE_24);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(ISHPISPRCV_N.VALUE_25);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(ISHPISPRCV_N.SAMPLE_COUNT);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(ISHPISPRCV_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(ISHPISPRCV_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(ISHPISPRCV_N.RECEIVE_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(ISHPISPRCV_N.DELETE_FLAG);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(ISHPISPRCV_N.CMF_1);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(ISHPISPRCV_N.CMF_2);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(ISHPISPRCV_N.CMF_3);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(ISHPISPRCV_N.CMF_4);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(ISHPISPRCV_N.CMF_5);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(ISHPISPRCV_N.CMF_6);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(ISHPISPRCV_N.CMF_7);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(ISHPISPRCV_N.CMF_8);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(ISHPISPRCV_N.CMF_9);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(ISHPISPRCV_N.CMF_10);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(ISHPISPRCV_N.CREATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(ISHPISPRCV_N.CREATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(ISHPISPRCV_N.UPDATE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(ISHPISPRCV_N.UPDATE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
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
        DBU_del_null_ishpisprcv(&ISHPISPRCV_N, ISHPISPRCV);
    }

    DB_stop_query_timer("DBU_fetch_ishpisprcv", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_ishpisprcv(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_ISHPISPRCV_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1527;
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

    DB_stop_query_timer("DBU_close_ishpisprcv", sel_type);
}


/* Initialize Function */
void DBU_init_ishpisprcv(struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    /* memset by Space */
    memset(ISHPISPRCV, ' ', sizeof(struct ISHPISPRCV_TAG));
    
    ISHPISPRCV->COL_SET_VER = 0;
    ISHPISPRCV->CHAR_SEQ = 0;
    ISHPISPRCV->UNIT_SEQ = 0;
    ISHPISPRCV->VALUE_SEQ = 0;
    ISHPISPRCV->VALUE_COUNT = 0;
    ISHPISPRCV->SAMPLE_COUNT = 0;
}


/* Add Null Function */
void DBU_add_null_ishpisprcv(struct ISHPISPRCV_N_TAG *ISHPISPRCV_N, struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    /* memset by NULL */
    memset(ISHPISPRCV_N, '\0', sizeof(struct ISHPISPRCV_N_TAG));
    
    MEMCPY_AN(ISHPISPRCV_N->FACTORY, ISHPISPRCV->FACTORY, sizeof(ISHPISPRCV->FACTORY));
    MEMCPY_AN(ISHPISPRCV_N->PACK_LOT_ID, ISHPISPRCV->PACK_LOT_ID, sizeof(ISHPISPRCV->PACK_LOT_ID));
    MEMCPY_AN(ISHPISPRCV_N->ORG_LOT_ID, ISHPISPRCV->ORG_LOT_ID, sizeof(ISHPISPRCV->ORG_LOT_ID));
    MEMCPY_AN(ISHPISPRCV_N->FROM_FACTORY, ISHPISPRCV->FROM_FACTORY, sizeof(ISHPISPRCV->FROM_FACTORY));
    MEMCPY_AN(ISHPISPRCV_N->INSP_ID, ISHPISPRCV->INSP_ID, sizeof(ISHPISPRCV->INSP_ID));
    MEMCPY_AN(ISHPISPRCV_N->COL_SET_ID, ISHPISPRCV->COL_SET_ID, sizeof(ISHPISPRCV->COL_SET_ID));
    ISHPISPRCV_N->COL_SET_VER = ISHPISPRCV->COL_SET_VER;
    MEMCPY_AN(ISHPISPRCV_N->CHAR_ID, ISHPISPRCV->CHAR_ID, sizeof(ISHPISPRCV->CHAR_ID));
    ISHPISPRCV_N->CHAR_SEQ = ISHPISPRCV->CHAR_SEQ;
    ISHPISPRCV_N->UNIT_SEQ = ISHPISPRCV->UNIT_SEQ;
    ISHPISPRCV_N->VALUE_SEQ = ISHPISPRCV->VALUE_SEQ;
    MEMCPY_AN(ISHPISPRCV_N->UNIT_ID, ISHPISPRCV->UNIT_ID, sizeof(ISHPISPRCV->UNIT_ID));
    ISHPISPRCV_N->VALUE_TYPE[0] = ISHPISPRCV->VALUE_TYPE;
    ISHPISPRCV_N->VALUE_COUNT = ISHPISPRCV->VALUE_COUNT;
    MEMCPY_AN(ISHPISPRCV_N->VALUE_1, ISHPISPRCV->VALUE_1, sizeof(ISHPISPRCV->VALUE_1));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_2, ISHPISPRCV->VALUE_2, sizeof(ISHPISPRCV->VALUE_2));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_3, ISHPISPRCV->VALUE_3, sizeof(ISHPISPRCV->VALUE_3));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_4, ISHPISPRCV->VALUE_4, sizeof(ISHPISPRCV->VALUE_4));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_5, ISHPISPRCV->VALUE_5, sizeof(ISHPISPRCV->VALUE_5));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_6, ISHPISPRCV->VALUE_6, sizeof(ISHPISPRCV->VALUE_6));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_7, ISHPISPRCV->VALUE_7, sizeof(ISHPISPRCV->VALUE_7));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_8, ISHPISPRCV->VALUE_8, sizeof(ISHPISPRCV->VALUE_8));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_9, ISHPISPRCV->VALUE_9, sizeof(ISHPISPRCV->VALUE_9));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_10, ISHPISPRCV->VALUE_10, sizeof(ISHPISPRCV->VALUE_10));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_11, ISHPISPRCV->VALUE_11, sizeof(ISHPISPRCV->VALUE_11));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_12, ISHPISPRCV->VALUE_12, sizeof(ISHPISPRCV->VALUE_12));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_13, ISHPISPRCV->VALUE_13, sizeof(ISHPISPRCV->VALUE_13));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_14, ISHPISPRCV->VALUE_14, sizeof(ISHPISPRCV->VALUE_14));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_15, ISHPISPRCV->VALUE_15, sizeof(ISHPISPRCV->VALUE_15));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_16, ISHPISPRCV->VALUE_16, sizeof(ISHPISPRCV->VALUE_16));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_17, ISHPISPRCV->VALUE_17, sizeof(ISHPISPRCV->VALUE_17));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_18, ISHPISPRCV->VALUE_18, sizeof(ISHPISPRCV->VALUE_18));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_19, ISHPISPRCV->VALUE_19, sizeof(ISHPISPRCV->VALUE_19));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_20, ISHPISPRCV->VALUE_20, sizeof(ISHPISPRCV->VALUE_20));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_21, ISHPISPRCV->VALUE_21, sizeof(ISHPISPRCV->VALUE_21));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_22, ISHPISPRCV->VALUE_22, sizeof(ISHPISPRCV->VALUE_22));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_23, ISHPISPRCV->VALUE_23, sizeof(ISHPISPRCV->VALUE_23));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_24, ISHPISPRCV->VALUE_24, sizeof(ISHPISPRCV->VALUE_24));
    MEMCPY_AN(ISHPISPRCV_N->VALUE_25, ISHPISPRCV->VALUE_25, sizeof(ISHPISPRCV->VALUE_25));
    ISHPISPRCV_N->SAMPLE_COUNT = ISHPISPRCV->SAMPLE_COUNT;
    MEMCPY_AN(ISHPISPRCV_N->SPEC_OUT_MASK, ISHPISPRCV->SPEC_OUT_MASK, sizeof(ISHPISPRCV->SPEC_OUT_MASK));
    ISHPISPRCV_N->INSP_JUDGE_FLAG[0] = ISHPISPRCV->INSP_JUDGE_FLAG;
    MEMCPY_AN(ISHPISPRCV_N->INSP_JUDGE_TYPE, ISHPISPRCV->INSP_JUDGE_TYPE, sizeof(ISHPISPRCV->INSP_JUDGE_TYPE));
    MEMCPY_AN(ISHPISPRCV_N->INSP_JUDGE_TIME, ISHPISPRCV->INSP_JUDGE_TIME, sizeof(ISHPISPRCV->INSP_JUDGE_TIME));
    ISHPISPRCV_N->RECEIVE_FLAG[0] = ISHPISPRCV->RECEIVE_FLAG;
    ISHPISPRCV_N->DELETE_FLAG[0] = ISHPISPRCV->DELETE_FLAG;
    MEMCPY_AN(ISHPISPRCV_N->CMF_1, ISHPISPRCV->CMF_1, sizeof(ISHPISPRCV->CMF_1));
    MEMCPY_AN(ISHPISPRCV_N->CMF_2, ISHPISPRCV->CMF_2, sizeof(ISHPISPRCV->CMF_2));
    MEMCPY_AN(ISHPISPRCV_N->CMF_3, ISHPISPRCV->CMF_3, sizeof(ISHPISPRCV->CMF_3));
    MEMCPY_AN(ISHPISPRCV_N->CMF_4, ISHPISPRCV->CMF_4, sizeof(ISHPISPRCV->CMF_4));
    MEMCPY_AN(ISHPISPRCV_N->CMF_5, ISHPISPRCV->CMF_5, sizeof(ISHPISPRCV->CMF_5));
    MEMCPY_AN(ISHPISPRCV_N->CMF_6, ISHPISPRCV->CMF_6, sizeof(ISHPISPRCV->CMF_6));
    MEMCPY_AN(ISHPISPRCV_N->CMF_7, ISHPISPRCV->CMF_7, sizeof(ISHPISPRCV->CMF_7));
    MEMCPY_AN(ISHPISPRCV_N->CMF_8, ISHPISPRCV->CMF_8, sizeof(ISHPISPRCV->CMF_8));
    MEMCPY_AN(ISHPISPRCV_N->CMF_9, ISHPISPRCV->CMF_9, sizeof(ISHPISPRCV->CMF_9));
    MEMCPY_AN(ISHPISPRCV_N->CMF_10, ISHPISPRCV->CMF_10, sizeof(ISHPISPRCV->CMF_10));
    MEMCPY_AN(ISHPISPRCV_N->CREATE_USER_ID, ISHPISPRCV->CREATE_USER_ID, sizeof(ISHPISPRCV->CREATE_USER_ID));
    MEMCPY_AN(ISHPISPRCV_N->CREATE_TIME, ISHPISPRCV->CREATE_TIME, sizeof(ISHPISPRCV->CREATE_TIME));
    MEMCPY_AN(ISHPISPRCV_N->UPDATE_USER_ID, ISHPISPRCV->UPDATE_USER_ID, sizeof(ISHPISPRCV->UPDATE_USER_ID));
    MEMCPY_AN(ISHPISPRCV_N->UPDATE_TIME, ISHPISPRCV->UPDATE_TIME, sizeof(ISHPISPRCV->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_ishpisprcv(struct ISHPISPRCV_N_TAG *ISHPISPRCV_N, struct ISHPISPRCV_TAG *ISHPISPRCV)
{
    MEMCPY_DN(ISHPISPRCV->FACTORY, ISHPISPRCV_N->FACTORY, sizeof(ISHPISPRCV->FACTORY));
    MEMCPY_DN(ISHPISPRCV->PACK_LOT_ID, ISHPISPRCV_N->PACK_LOT_ID, sizeof(ISHPISPRCV->PACK_LOT_ID));
    MEMCPY_DN(ISHPISPRCV->ORG_LOT_ID, ISHPISPRCV_N->ORG_LOT_ID, sizeof(ISHPISPRCV->ORG_LOT_ID));
    MEMCPY_DN(ISHPISPRCV->FROM_FACTORY, ISHPISPRCV_N->FROM_FACTORY, sizeof(ISHPISPRCV->FROM_FACTORY));
    MEMCPY_DN(ISHPISPRCV->INSP_ID, ISHPISPRCV_N->INSP_ID, sizeof(ISHPISPRCV->INSP_ID));
    MEMCPY_DN(ISHPISPRCV->COL_SET_ID, ISHPISPRCV_N->COL_SET_ID, sizeof(ISHPISPRCV->COL_SET_ID));
    ISHPISPRCV->COL_SET_VER = ISHPISPRCV_N->COL_SET_VER;
    MEMCPY_DN(ISHPISPRCV->CHAR_ID, ISHPISPRCV_N->CHAR_ID, sizeof(ISHPISPRCV->CHAR_ID));
    ISHPISPRCV->CHAR_SEQ = ISHPISPRCV_N->CHAR_SEQ;
    ISHPISPRCV->UNIT_SEQ = ISHPISPRCV_N->UNIT_SEQ;
    ISHPISPRCV->VALUE_SEQ = ISHPISPRCV_N->VALUE_SEQ;
    MEMCPY_DN(ISHPISPRCV->UNIT_ID, ISHPISPRCV_N->UNIT_ID, sizeof(ISHPISPRCV->UNIT_ID));
    ISHPISPRCV->VALUE_TYPE = ISHPISPRCV_N->VALUE_TYPE[0];
    ISHPISPRCV->VALUE_COUNT = ISHPISPRCV_N->VALUE_COUNT;
    MEMCPY_DN(ISHPISPRCV->VALUE_1, ISHPISPRCV_N->VALUE_1, sizeof(ISHPISPRCV->VALUE_1));
    MEMCPY_DN(ISHPISPRCV->VALUE_2, ISHPISPRCV_N->VALUE_2, sizeof(ISHPISPRCV->VALUE_2));
    MEMCPY_DN(ISHPISPRCV->VALUE_3, ISHPISPRCV_N->VALUE_3, sizeof(ISHPISPRCV->VALUE_3));
    MEMCPY_DN(ISHPISPRCV->VALUE_4, ISHPISPRCV_N->VALUE_4, sizeof(ISHPISPRCV->VALUE_4));
    MEMCPY_DN(ISHPISPRCV->VALUE_5, ISHPISPRCV_N->VALUE_5, sizeof(ISHPISPRCV->VALUE_5));
    MEMCPY_DN(ISHPISPRCV->VALUE_6, ISHPISPRCV_N->VALUE_6, sizeof(ISHPISPRCV->VALUE_6));
    MEMCPY_DN(ISHPISPRCV->VALUE_7, ISHPISPRCV_N->VALUE_7, sizeof(ISHPISPRCV->VALUE_7));
    MEMCPY_DN(ISHPISPRCV->VALUE_8, ISHPISPRCV_N->VALUE_8, sizeof(ISHPISPRCV->VALUE_8));
    MEMCPY_DN(ISHPISPRCV->VALUE_9, ISHPISPRCV_N->VALUE_9, sizeof(ISHPISPRCV->VALUE_9));
    MEMCPY_DN(ISHPISPRCV->VALUE_10, ISHPISPRCV_N->VALUE_10, sizeof(ISHPISPRCV->VALUE_10));
    MEMCPY_DN(ISHPISPRCV->VALUE_11, ISHPISPRCV_N->VALUE_11, sizeof(ISHPISPRCV->VALUE_11));
    MEMCPY_DN(ISHPISPRCV->VALUE_12, ISHPISPRCV_N->VALUE_12, sizeof(ISHPISPRCV->VALUE_12));
    MEMCPY_DN(ISHPISPRCV->VALUE_13, ISHPISPRCV_N->VALUE_13, sizeof(ISHPISPRCV->VALUE_13));
    MEMCPY_DN(ISHPISPRCV->VALUE_14, ISHPISPRCV_N->VALUE_14, sizeof(ISHPISPRCV->VALUE_14));
    MEMCPY_DN(ISHPISPRCV->VALUE_15, ISHPISPRCV_N->VALUE_15, sizeof(ISHPISPRCV->VALUE_15));
    MEMCPY_DN(ISHPISPRCV->VALUE_16, ISHPISPRCV_N->VALUE_16, sizeof(ISHPISPRCV->VALUE_16));
    MEMCPY_DN(ISHPISPRCV->VALUE_17, ISHPISPRCV_N->VALUE_17, sizeof(ISHPISPRCV->VALUE_17));
    MEMCPY_DN(ISHPISPRCV->VALUE_18, ISHPISPRCV_N->VALUE_18, sizeof(ISHPISPRCV->VALUE_18));
    MEMCPY_DN(ISHPISPRCV->VALUE_19, ISHPISPRCV_N->VALUE_19, sizeof(ISHPISPRCV->VALUE_19));
    MEMCPY_DN(ISHPISPRCV->VALUE_20, ISHPISPRCV_N->VALUE_20, sizeof(ISHPISPRCV->VALUE_20));
    MEMCPY_DN(ISHPISPRCV->VALUE_21, ISHPISPRCV_N->VALUE_21, sizeof(ISHPISPRCV->VALUE_21));
    MEMCPY_DN(ISHPISPRCV->VALUE_22, ISHPISPRCV_N->VALUE_22, sizeof(ISHPISPRCV->VALUE_22));
    MEMCPY_DN(ISHPISPRCV->VALUE_23, ISHPISPRCV_N->VALUE_23, sizeof(ISHPISPRCV->VALUE_23));
    MEMCPY_DN(ISHPISPRCV->VALUE_24, ISHPISPRCV_N->VALUE_24, sizeof(ISHPISPRCV->VALUE_24));
    MEMCPY_DN(ISHPISPRCV->VALUE_25, ISHPISPRCV_N->VALUE_25, sizeof(ISHPISPRCV->VALUE_25));
    ISHPISPRCV->SAMPLE_COUNT = ISHPISPRCV_N->SAMPLE_COUNT;
    MEMCPY_DN(ISHPISPRCV->SPEC_OUT_MASK, ISHPISPRCV_N->SPEC_OUT_MASK, sizeof(ISHPISPRCV->SPEC_OUT_MASK));
    ISHPISPRCV->INSP_JUDGE_FLAG = ISHPISPRCV_N->INSP_JUDGE_FLAG[0];
    MEMCPY_DN(ISHPISPRCV->INSP_JUDGE_TYPE, ISHPISPRCV_N->INSP_JUDGE_TYPE, sizeof(ISHPISPRCV->INSP_JUDGE_TYPE));
    MEMCPY_DN(ISHPISPRCV->INSP_JUDGE_TIME, ISHPISPRCV_N->INSP_JUDGE_TIME, sizeof(ISHPISPRCV->INSP_JUDGE_TIME));
    ISHPISPRCV->RECEIVE_FLAG = ISHPISPRCV_N->RECEIVE_FLAG[0];
    ISHPISPRCV->DELETE_FLAG = ISHPISPRCV_N->DELETE_FLAG[0];
    MEMCPY_DN(ISHPISPRCV->CMF_1, ISHPISPRCV_N->CMF_1, sizeof(ISHPISPRCV->CMF_1));
    MEMCPY_DN(ISHPISPRCV->CMF_2, ISHPISPRCV_N->CMF_2, sizeof(ISHPISPRCV->CMF_2));
    MEMCPY_DN(ISHPISPRCV->CMF_3, ISHPISPRCV_N->CMF_3, sizeof(ISHPISPRCV->CMF_3));
    MEMCPY_DN(ISHPISPRCV->CMF_4, ISHPISPRCV_N->CMF_4, sizeof(ISHPISPRCV->CMF_4));
    MEMCPY_DN(ISHPISPRCV->CMF_5, ISHPISPRCV_N->CMF_5, sizeof(ISHPISPRCV->CMF_5));
    MEMCPY_DN(ISHPISPRCV->CMF_6, ISHPISPRCV_N->CMF_6, sizeof(ISHPISPRCV->CMF_6));
    MEMCPY_DN(ISHPISPRCV->CMF_7, ISHPISPRCV_N->CMF_7, sizeof(ISHPISPRCV->CMF_7));
    MEMCPY_DN(ISHPISPRCV->CMF_8, ISHPISPRCV_N->CMF_8, sizeof(ISHPISPRCV->CMF_8));
    MEMCPY_DN(ISHPISPRCV->CMF_9, ISHPISPRCV_N->CMF_9, sizeof(ISHPISPRCV->CMF_9));
    MEMCPY_DN(ISHPISPRCV->CMF_10, ISHPISPRCV_N->CMF_10, sizeof(ISHPISPRCV->CMF_10));
    MEMCPY_DN(ISHPISPRCV->CREATE_USER_ID, ISHPISPRCV_N->CREATE_USER_ID, sizeof(ISHPISPRCV->CREATE_USER_ID));
    MEMCPY_DN(ISHPISPRCV->CREATE_TIME, ISHPISPRCV_N->CREATE_TIME, sizeof(ISHPISPRCV->CREATE_TIME));
    MEMCPY_DN(ISHPISPRCV->UPDATE_USER_ID, ISHPISPRCV_N->UPDATE_USER_ID, sizeof(ISHPISPRCV->UPDATE_USER_ID));
    MEMCPY_DN(ISHPISPRCV->UPDATE_TIME, ISHPISPRCV_N->UPDATE_TIME, sizeof(ISHPISPRCV->UPDATE_TIME));
}


