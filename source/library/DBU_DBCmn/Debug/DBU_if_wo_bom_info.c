
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
           char  filnam[22];
};
static const struct sqlcxp sqlfpn =
{
    21,
    "DBU_if_wo_bom_info.pc"
};


static unsigned int sqlctx = 150654707;


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

 static const char *sq0008 = 
"select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY ,ORG_ID ,ORG_CODE ,WIP_ENT\
ITY_ID ,WIP_ENTITY_NAME ,ITEM_ID ,ITEM_CODE ,COMP_ITEM_ID ,COMP_ITEM_CODE ,CO\
MP_ITEM_DESC ,COMP_ITEM_TYPE ,COMP_ITEM_UNIT ,ALTERNATE_BOM_DESIGNATOR ,ALTER\
_RTG_NAME ,OPER_SEQ ,OPER_ID ,OPER ,OPER_DESC ,DEPT_ID ,DEPT_CODE ,DEPT_DESC \
,TOTAL_QTY ,ISSUED_QTY ,UNIT_QTY ,SUPPLY_TYPE ,SUPPLY_TYPE_NAME ,SUPPLY_INV_O\
PER ,TRAN_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9\
 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from IF_W\
O_BOM_INFO  order by IF_SEQ asc             ";

 static const char *sq0009 = 
"select *  from (select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY ,ORG_ID ,O\
RG_CODE ,WIP_ENTITY_ID ,WIP_ENTITY_NAME ,ITEM_ID ,ITEM_CODE ,COMP_ITEM_ID ,CO\
MP_ITEM_CODE ,COMP_ITEM_DESC ,COMP_ITEM_TYPE ,COMP_ITEM_UNIT ,ALTERNATE_BOM_D\
ESIGNATOR ,ALTER_RTG_NAME ,OPER_SEQ ,OPER_ID ,OPER ,OPER_DESC ,DEPT_ID ,DEPT_\
CODE ,DEPT_DESC ,TOTAL_QTY ,ISSUED_QTY ,UNIT_QTY ,SUPPLY_TYPE ,SUPPLY_TYPE_NA\
ME ,SUPPLY_INV_OPER ,TRAN_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF\
_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE\
_TIME  from IF_WO_BOM_INFO where IF_CODE in ('N','R') order by IF_SEQ asc  ) \
where ROWNUM<=10000           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,789,0,4,46,0,0,47,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,
208,0,0,2,801,0,4,178,0,0,47,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,
411,0,0,3,63,0,4,313,0,0,2,1,0,1,0,2,4,0,0,1,3,0,0,
434,0,0,4,45,0,2,349,0,0,1,1,0,1,0,1,3,0,0,
453,0,0,5,732,0,3,378,0,0,46,46,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
652,0,0,6,727,0,5,495,0,0,46,46,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
851,0,0,7,66,0,5,545,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
878,0,0,8,581,0,9,628,0,0,0,0,0,1,0,
893,0,0,9,644,0,9,686,0,0,0,0,0,1,0,
908,0,0,8,0,0,13,714,0,0,46,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1107,0,0,9,0,0,13,764,0,0,46,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1306,0,0,8,0,0,15,839,0,0,0,0,0,1,0,
1321,0,0,9,0,0,15,843,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_if_wo_bom_info.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-09-28 11:33:58
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
void DBU_add_null_if_wo_bom_info(struct IF_WO_BOM_INFO_N_TAG *IF_WO_BOM_INFO_N, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO);
void DBU_del_null_if_wo_bom_info(struct IF_WO_BOM_INFO_N_TAG *IF_WO_BOM_INFO_N, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO);


/* SQL SELECT Function */
void DBU_select_if_wo_bom_info(int sel_type, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_WO_BOM_INFO_N_TAG IF_WO_BOM_INFO_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_wo_bom_info(&IF_WO_BOM_INFO_N, IF_WO_BOM_INFO);
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
                    ORG_ID,
                    ORG_CODE,
                    WIP_ENTITY_ID,
                    WIP_ENTITY_NAME,
                    ITEM_ID,
                    ITEM_CODE,
                    COMP_ITEM_ID,
                    COMP_ITEM_CODE,
                    COMP_ITEM_DESC,
                    COMP_ITEM_TYPE,
                    COMP_ITEM_UNIT,
                    ALTERNATE_BOM_DESIGNATOR,
                    ALTER_RTG_NAME,
                    OPER_SEQ,
                    OPER_ID,
                    OPER,
                    OPER_DESC,
                    DEPT_ID,
                    DEPT_CODE,
                    DEPT_DESC,
                    TOTAL_QTY,
                    ISSUED_QTY,
                    UNIT_QTY,
                    SUPPLY_TYPE,
                    SUPPLY_TYPE_NAME,
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
                    :IF_WO_BOM_INFO_N.IF_SEQ,
                    :IF_WO_BOM_INFO_N.IF_TIME,
                    :IF_WO_BOM_INFO_N.IF_CODE,
                    :IF_WO_BOM_INFO_N.IF_MSG,
                    :IF_WO_BOM_INFO_N.FACTORY,
                    :IF_WO_BOM_INFO_N.ORG_ID,
                    :IF_WO_BOM_INFO_N.ORG_CODE,
                    :IF_WO_BOM_INFO_N.WIP_ENTITY_ID,
                    :IF_WO_BOM_INFO_N.WIP_ENTITY_NAME,
                    :IF_WO_BOM_INFO_N.ITEM_ID,
                    :IF_WO_BOM_INFO_N.ITEM_CODE,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_ID,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_CODE,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_DESC,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_TYPE,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_UNIT,
                    :IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR,
                    :IF_WO_BOM_INFO_N.ALTER_RTG_NAME,
                    :IF_WO_BOM_INFO_N.OPER_SEQ,
                    :IF_WO_BOM_INFO_N.OPER_ID,
                    :IF_WO_BOM_INFO_N.OPER,
                    :IF_WO_BOM_INFO_N.OPER_DESC,
                    :IF_WO_BOM_INFO_N.DEPT_ID,
                    :IF_WO_BOM_INFO_N.DEPT_CODE,
                    :IF_WO_BOM_INFO_N.DEPT_DESC,
                    :IF_WO_BOM_INFO_N.TOTAL_QTY,
                    :IF_WO_BOM_INFO_N.ISSUED_QTY,
                    :IF_WO_BOM_INFO_N.UNIT_QTY,
                    :IF_WO_BOM_INFO_N.SUPPLY_TYPE,
                    :IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME,
                    :IF_WO_BOM_INFO_N.SUPPLY_INV_OPER,
                    :IF_WO_BOM_INFO_N.TRAN_FLAG,
                    :IF_WO_BOM_INFO_N.CMF_1,
                    :IF_WO_BOM_INFO_N.CMF_2,
                    :IF_WO_BOM_INFO_N.CMF_3,
                    :IF_WO_BOM_INFO_N.CMF_4,
                    :IF_WO_BOM_INFO_N.CMF_5,
                    :IF_WO_BOM_INFO_N.CMF_6,
                    :IF_WO_BOM_INFO_N.CMF_7,
                    :IF_WO_BOM_INFO_N.CMF_8,
                    :IF_WO_BOM_INFO_N.CMF_9,
                    :IF_WO_BOM_INFO_N.CMF_10,
                    :IF_WO_BOM_INFO_N.CREATE_USER_ID,
                    :IF_WO_BOM_INFO_N.CREATE_TIME,
                    :IF_WO_BOM_INFO_N.UPDATE_USER_ID,
                    :IF_WO_BOM_INFO_N.UPDATE_TIME
                FROM IF_WO_BOM_INFO
                WHERE IF_SEQ = :IF_WO_BOM_INFO_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY\
 ,ORG_ID ,ORG_CODE ,WIP_ENTITY_ID ,WIP_ENTITY_NAME ,ITEM_ID ,ITEM_CODE ,COMP_\
ITEM_ID ,COMP_ITEM_CODE ,COMP_ITEM_DESC ,COMP_ITEM_TYPE ,COMP_ITEM_UNIT ,ALTE\
RNATE_BOM_DESIGNATOR ,ALTER_RTG_NAME ,OPER_SEQ ,OPER_ID ,OPER ,OPER_DESC ,DEP\
T_ID ,DEPT_CODE ,DEPT_DESC ,TOTAL_QTY ,ISSUED_QTY ,UNIT_QTY ,SUPPLY_TYPE ,SUP\
PLY_TYPE_NAME ,SUPPLY_INV_OPER ,TRAN_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 \
,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER\
_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,\
:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b\
28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43\
,:b44,:b45  from IF_WO_BOM_INFO where IF_SEQ=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_WO_BOM_INFO_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_WO_BOM_INFO_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_WO_BOM_INFO_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_WO_BOM_INFO_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_WO_BOM_INFO_N.ORG_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(IF_WO_BOM_INFO_N.ORG_CODE);
            sqlstm.sqhstl[6] = (unsigned int  )4;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_WO_BOM_INFO_N.WIP_ENTITY_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(IF_WO_BOM_INFO_N.WIP_ENTITY_NAME);
            sqlstm.sqhstl[8] = (unsigned int  )241;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_WO_BOM_INFO_N.ITEM_ID);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(IF_WO_BOM_INFO_N.ITEM_CODE);
            sqlstm.sqhstl[10] = (unsigned int  )41;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(IF_WO_BOM_INFO_N.COMP_ITEM_ID);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_CODE);
            sqlstm.sqhstl[12] = (unsigned int  )41;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_DESC);
            sqlstm.sqhstl[13] = (unsigned int  )241;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_TYPE);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_UNIT);
            sqlstm.sqhstl[15] = (unsigned int  )4;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_WO_BOM_INFO_N.ALTER_RTG_NAME);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_SEQ);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_ID);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_WO_BOM_INFO_N.OPER);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_WO_BOM_INFO_N.OPER_DESC);
            sqlstm.sqhstl[21] = (unsigned int  )241;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(IF_WO_BOM_INFO_N.DEPT_ID);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_CODE);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_DESC);
            sqlstm.sqhstl[24] = (unsigned int  )241;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(IF_WO_BOM_INFO_N.TOTAL_QTY);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(IF_WO_BOM_INFO_N.ISSUED_QTY);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(IF_WO_BOM_INFO_N.UNIT_QTY);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(IF_WO_BOM_INFO_N.SUPPLY_TYPE);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME);
            sqlstm.sqhstl[29] = (unsigned int  )241;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_INV_OPER);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_WO_BOM_INFO_N.TRAN_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_WO_BOM_INFO_N.CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_WO_BOM_INFO_N.CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_WO_BOM_INFO_N.CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_WO_BOM_INFO_N.CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_WO_BOM_INFO_N.CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_WO_BOM_INFO_N.CMF_6);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(IF_WO_BOM_INFO_N.CMF_7);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(IF_WO_BOM_INFO_N.CMF_8);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(IF_WO_BOM_INFO_N.CMF_9);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(IF_WO_BOM_INFO_N.CMF_10);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_USER_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )15;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_USER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_TIME);
            sqlstm.sqhstl[45] = (unsigned int  )15;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
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
        DBU_del_null_if_wo_bom_info(&IF_WO_BOM_INFO_N, IF_WO_BOM_INFO);
    }

    DB_stop_query_timer("DBU_select_if_wo_bom_info", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_if_wo_bom_info_for_update(int sel_type, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_WO_BOM_INFO_N_TAG IF_WO_BOM_INFO_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_wo_bom_info(&IF_WO_BOM_INFO_N, IF_WO_BOM_INFO);
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
                    ORG_ID,
                    ORG_CODE,
                    WIP_ENTITY_ID,
                    WIP_ENTITY_NAME,
                    ITEM_ID,
                    ITEM_CODE,
                    COMP_ITEM_ID,
                    COMP_ITEM_CODE,
                    COMP_ITEM_DESC,
                    COMP_ITEM_TYPE,
                    COMP_ITEM_UNIT,
                    ALTERNATE_BOM_DESIGNATOR,
                    ALTER_RTG_NAME,
                    OPER_SEQ,
                    OPER_ID,
                    OPER,
                    OPER_DESC,
                    DEPT_ID,
                    DEPT_CODE,
                    DEPT_DESC,
                    TOTAL_QTY,
                    ISSUED_QTY,
                    UNIT_QTY,
                    SUPPLY_TYPE,
                    SUPPLY_TYPE_NAME,
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
                    :IF_WO_BOM_INFO_N.IF_SEQ,
                    :IF_WO_BOM_INFO_N.IF_TIME,
                    :IF_WO_BOM_INFO_N.IF_CODE,
                    :IF_WO_BOM_INFO_N.IF_MSG,
                    :IF_WO_BOM_INFO_N.FACTORY,
                    :IF_WO_BOM_INFO_N.ORG_ID,
                    :IF_WO_BOM_INFO_N.ORG_CODE,
                    :IF_WO_BOM_INFO_N.WIP_ENTITY_ID,
                    :IF_WO_BOM_INFO_N.WIP_ENTITY_NAME,
                    :IF_WO_BOM_INFO_N.ITEM_ID,
                    :IF_WO_BOM_INFO_N.ITEM_CODE,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_ID,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_CODE,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_DESC,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_TYPE,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_UNIT,
                    :IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR,
                    :IF_WO_BOM_INFO_N.ALTER_RTG_NAME,
                    :IF_WO_BOM_INFO_N.OPER_SEQ,
                    :IF_WO_BOM_INFO_N.OPER_ID,
                    :IF_WO_BOM_INFO_N.OPER,
                    :IF_WO_BOM_INFO_N.OPER_DESC,
                    :IF_WO_BOM_INFO_N.DEPT_ID,
                    :IF_WO_BOM_INFO_N.DEPT_CODE,
                    :IF_WO_BOM_INFO_N.DEPT_DESC,
                    :IF_WO_BOM_INFO_N.TOTAL_QTY,
                    :IF_WO_BOM_INFO_N.ISSUED_QTY,
                    :IF_WO_BOM_INFO_N.UNIT_QTY,
                    :IF_WO_BOM_INFO_N.SUPPLY_TYPE,
                    :IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME,
                    :IF_WO_BOM_INFO_N.SUPPLY_INV_OPER,
                    :IF_WO_BOM_INFO_N.TRAN_FLAG,
                    :IF_WO_BOM_INFO_N.CMF_1,
                    :IF_WO_BOM_INFO_N.CMF_2,
                    :IF_WO_BOM_INFO_N.CMF_3,
                    :IF_WO_BOM_INFO_N.CMF_4,
                    :IF_WO_BOM_INFO_N.CMF_5,
                    :IF_WO_BOM_INFO_N.CMF_6,
                    :IF_WO_BOM_INFO_N.CMF_7,
                    :IF_WO_BOM_INFO_N.CMF_8,
                    :IF_WO_BOM_INFO_N.CMF_9,
                    :IF_WO_BOM_INFO_N.CMF_10,
                    :IF_WO_BOM_INFO_N.CREATE_USER_ID,
                    :IF_WO_BOM_INFO_N.CREATE_TIME,
                    :IF_WO_BOM_INFO_N.UPDATE_USER_ID,
                    :IF_WO_BOM_INFO_N.UPDATE_TIME
                FROM IF_WO_BOM_INFO
                WHERE IF_SEQ = :IF_WO_BOM_INFO_N.IF_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY\
 ,ORG_ID ,ORG_CODE ,WIP_ENTITY_ID ,WIP_ENTITY_NAME ,ITEM_ID ,ITEM_CODE ,COMP_\
ITEM_ID ,COMP_ITEM_CODE ,COMP_ITEM_DESC ,COMP_ITEM_TYPE ,COMP_ITEM_UNIT ,ALTE\
RNATE_BOM_DESIGNATOR ,ALTER_RTG_NAME ,OPER_SEQ ,OPER_ID ,OPER ,OPER_DESC ,DEP\
T_ID ,DEPT_CODE ,DEPT_DESC ,TOTAL_QTY ,ISSUED_QTY ,UNIT_QTY ,SUPPLY_TYPE ,SUP\
PLY_TYPE_NAME ,SUPPLY_INV_OPER ,TRAN_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 \
,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER\
_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,\
:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b\
28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43\
,:b44,:b45  from IF_WO_BOM_INFO where IF_SEQ=:b0 for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )208;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_WO_BOM_INFO_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_WO_BOM_INFO_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_WO_BOM_INFO_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_WO_BOM_INFO_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_WO_BOM_INFO_N.ORG_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(IF_WO_BOM_INFO_N.ORG_CODE);
            sqlstm.sqhstl[6] = (unsigned int  )4;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_WO_BOM_INFO_N.WIP_ENTITY_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(IF_WO_BOM_INFO_N.WIP_ENTITY_NAME);
            sqlstm.sqhstl[8] = (unsigned int  )241;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_WO_BOM_INFO_N.ITEM_ID);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(IF_WO_BOM_INFO_N.ITEM_CODE);
            sqlstm.sqhstl[10] = (unsigned int  )41;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(IF_WO_BOM_INFO_N.COMP_ITEM_ID);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_CODE);
            sqlstm.sqhstl[12] = (unsigned int  )41;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_DESC);
            sqlstm.sqhstl[13] = (unsigned int  )241;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_TYPE);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_UNIT);
            sqlstm.sqhstl[15] = (unsigned int  )4;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_WO_BOM_INFO_N.ALTER_RTG_NAME);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_SEQ);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_ID);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_WO_BOM_INFO_N.OPER);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_WO_BOM_INFO_N.OPER_DESC);
            sqlstm.sqhstl[21] = (unsigned int  )241;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(IF_WO_BOM_INFO_N.DEPT_ID);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_CODE);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_DESC);
            sqlstm.sqhstl[24] = (unsigned int  )241;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(IF_WO_BOM_INFO_N.TOTAL_QTY);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(IF_WO_BOM_INFO_N.ISSUED_QTY);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(IF_WO_BOM_INFO_N.UNIT_QTY);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(IF_WO_BOM_INFO_N.SUPPLY_TYPE);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME);
            sqlstm.sqhstl[29] = (unsigned int  )241;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_INV_OPER);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_WO_BOM_INFO_N.TRAN_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_WO_BOM_INFO_N.CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_WO_BOM_INFO_N.CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_WO_BOM_INFO_N.CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_WO_BOM_INFO_N.CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_WO_BOM_INFO_N.CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_WO_BOM_INFO_N.CMF_6);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(IF_WO_BOM_INFO_N.CMF_7);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(IF_WO_BOM_INFO_N.CMF_8);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(IF_WO_BOM_INFO_N.CMF_9);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(IF_WO_BOM_INFO_N.CMF_10);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_USER_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )15;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_USER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_TIME);
            sqlstm.sqhstl[45] = (unsigned int  )15;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
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
        DBU_del_null_if_wo_bom_info(&IF_WO_BOM_INFO_N, IF_WO_BOM_INFO);
    }

    DB_stop_query_timer("DBU_select_if_wo_bom_info_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_if_wo_bom_info_scalar(int sel_type, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_WO_BOM_INFO_N_TAG IF_WO_BOM_INFO_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_wo_bom_info(&IF_WO_BOM_INFO_N, IF_WO_BOM_INFO);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM IF_WO_BOM_INFO
                WHERE IF_SEQ = :IF_WO_BOM_INFO_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from IF_WO_BOM_INFO w\
here IF_SEQ=:b1";
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
            sqlstm.sqhstv[1] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
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

    DB_stop_query_timer("DBU_select_if_wo_bom_info_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_if_wo_bom_info(int sel_type, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_WO_BOM_INFO_N_TAG IF_WO_BOM_INFO_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_wo_bom_info(&IF_WO_BOM_INFO_N, IF_WO_BOM_INFO);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM IF_WO_BOM_INFO
                WHERE IF_SEQ = :IF_WO_BOM_INFO_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from IF_WO_BOM_INFO  where IF_SEQ=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )434;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
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

    DB_stop_query_timer("DBU_delete_if_wo_bom_info", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_if_wo_bom_info(struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_WO_BOM_INFO_N_TAG IF_WO_BOM_INFO_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_wo_bom_info(&IF_WO_BOM_INFO_N, IF_WO_BOM_INFO);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO IF_WO_BOM_INFO( 
                    IF_SEQ, 
                    IF_TIME, 
                    IF_CODE, 
                    IF_MSG, 
                    FACTORY, 
                    ORG_ID, 
                    ORG_CODE, 
                    WIP_ENTITY_ID, 
                    WIP_ENTITY_NAME, 
                    ITEM_ID, 
                    ITEM_CODE, 
                    COMP_ITEM_ID, 
                    COMP_ITEM_CODE, 
                    COMP_ITEM_DESC, 
                    COMP_ITEM_TYPE, 
                    COMP_ITEM_UNIT, 
                    ALTERNATE_BOM_DESIGNATOR, 
                    ALTER_RTG_NAME, 
                    OPER_SEQ, 
                    OPER_ID, 
                    OPER, 
                    OPER_DESC, 
                    DEPT_ID, 
                    DEPT_CODE, 
                    DEPT_DESC, 
                    TOTAL_QTY, 
                    ISSUED_QTY, 
                    UNIT_QTY, 
                    SUPPLY_TYPE, 
                    SUPPLY_TYPE_NAME, 
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
                    :IF_WO_BOM_INFO_N.IF_SEQ,
                    :IF_WO_BOM_INFO_N.IF_TIME,
                    :IF_WO_BOM_INFO_N.IF_CODE,
                    :IF_WO_BOM_INFO_N.IF_MSG,
                    :IF_WO_BOM_INFO_N.FACTORY,
                    :IF_WO_BOM_INFO_N.ORG_ID,
                    :IF_WO_BOM_INFO_N.ORG_CODE,
                    :IF_WO_BOM_INFO_N.WIP_ENTITY_ID,
                    :IF_WO_BOM_INFO_N.WIP_ENTITY_NAME,
                    :IF_WO_BOM_INFO_N.ITEM_ID,
                    :IF_WO_BOM_INFO_N.ITEM_CODE,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_ID,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_CODE,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_DESC,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_TYPE,
                    :IF_WO_BOM_INFO_N.COMP_ITEM_UNIT,
                    :IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR,
                    :IF_WO_BOM_INFO_N.ALTER_RTG_NAME,
                    :IF_WO_BOM_INFO_N.OPER_SEQ,
                    :IF_WO_BOM_INFO_N.OPER_ID,
                    :IF_WO_BOM_INFO_N.OPER,
                    :IF_WO_BOM_INFO_N.OPER_DESC,
                    :IF_WO_BOM_INFO_N.DEPT_ID,
                    :IF_WO_BOM_INFO_N.DEPT_CODE,
                    :IF_WO_BOM_INFO_N.DEPT_DESC,
                    :IF_WO_BOM_INFO_N.TOTAL_QTY,
                    :IF_WO_BOM_INFO_N.ISSUED_QTY,
                    :IF_WO_BOM_INFO_N.UNIT_QTY,
                    :IF_WO_BOM_INFO_N.SUPPLY_TYPE,
                    :IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME,
                    :IF_WO_BOM_INFO_N.SUPPLY_INV_OPER,
                    :IF_WO_BOM_INFO_N.TRAN_FLAG,
                    :IF_WO_BOM_INFO_N.CMF_1,
                    :IF_WO_BOM_INFO_N.CMF_2,
                    :IF_WO_BOM_INFO_N.CMF_3,
                    :IF_WO_BOM_INFO_N.CMF_4,
                    :IF_WO_BOM_INFO_N.CMF_5,
                    :IF_WO_BOM_INFO_N.CMF_6,
                    :IF_WO_BOM_INFO_N.CMF_7,
                    :IF_WO_BOM_INFO_N.CMF_8,
                    :IF_WO_BOM_INFO_N.CMF_9,
                    :IF_WO_BOM_INFO_N.CMF_10,
                    :IF_WO_BOM_INFO_N.CREATE_USER_ID,
                    :IF_WO_BOM_INFO_N.CREATE_TIME,
                    :IF_WO_BOM_INFO_N.UPDATE_USER_ID,
                    :IF_WO_BOM_INFO_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into IF_WO_BOM_INFO (IF_SEQ,IF_TIME,IF_CODE,IF_MS\
G,FACTORY,ORG_ID,ORG_CODE,WIP_ENTITY_ID,WIP_ENTITY_NAME,ITEM_ID,ITEM_CODE,COM\
P_ITEM_ID,COMP_ITEM_CODE,COMP_ITEM_DESC,COMP_ITEM_TYPE,COMP_ITEM_UNIT,ALTERNA\
TE_BOM_DESIGNATOR,ALTER_RTG_NAME,OPER_SEQ,OPER_ID,OPER,OPER_DESC,DEPT_ID,DEPT\
_CODE,DEPT_DESC,TOTAL_QTY,ISSUED_QTY,UNIT_QTY,SUPPLY_TYPE,SUPPLY_TYPE_NAME,SU\
PPLY_INV_OPER,TRAN_FLAG,CMF_1,CMF_2,CMF_3,CMF_4,CMF_5,CMF_6,CMF_7,CMF_8,CMF_9\
,CMF_10,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) values (:b0,:b\
1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b1\
8,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,\
:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )453;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(IF_WO_BOM_INFO_N.IF_TIME);
    sqlstm.sqhstl[1] = (unsigned int  )15;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(IF_WO_BOM_INFO_N.IF_CODE);
    sqlstm.sqhstl[2] = (unsigned int  )2;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(IF_WO_BOM_INFO_N.IF_MSG);
    sqlstm.sqhstl[3] = (unsigned int  )201;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(IF_WO_BOM_INFO_N.FACTORY);
    sqlstm.sqhstl[4] = (unsigned int  )11;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)&(IF_WO_BOM_INFO_N.ORG_ID);
    sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(IF_WO_BOM_INFO_N.ORG_CODE);
    sqlstm.sqhstl[6] = (unsigned int  )4;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)&(IF_WO_BOM_INFO_N.WIP_ENTITY_ID);
    sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(IF_WO_BOM_INFO_N.WIP_ENTITY_NAME);
    sqlstm.sqhstl[8] = (unsigned int  )241;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)&(IF_WO_BOM_INFO_N.ITEM_ID);
    sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(IF_WO_BOM_INFO_N.ITEM_CODE);
    sqlstm.sqhstl[10] = (unsigned int  )41;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)&(IF_WO_BOM_INFO_N.COMP_ITEM_ID);
    sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_CODE);
    sqlstm.sqhstl[12] = (unsigned int  )41;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_DESC);
    sqlstm.sqhstl[13] = (unsigned int  )241;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_TYPE);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_UNIT);
    sqlstm.sqhstl[15] = (unsigned int  )4;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR);
    sqlstm.sqhstl[16] = (unsigned int  )11;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(IF_WO_BOM_INFO_N.ALTER_RTG_NAME);
    sqlstm.sqhstl[17] = (unsigned int  )11;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_SEQ);
    sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_ID);
    sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(IF_WO_BOM_INFO_N.OPER);
    sqlstm.sqhstl[20] = (unsigned int  )11;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(IF_WO_BOM_INFO_N.OPER_DESC);
    sqlstm.sqhstl[21] = (unsigned int  )241;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)&(IF_WO_BOM_INFO_N.DEPT_ID);
    sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_CODE);
    sqlstm.sqhstl[23] = (unsigned int  )11;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_DESC);
    sqlstm.sqhstl[24] = (unsigned int  )241;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)&(IF_WO_BOM_INFO_N.TOTAL_QTY);
    sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)&(IF_WO_BOM_INFO_N.ISSUED_QTY);
    sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)&(IF_WO_BOM_INFO_N.UNIT_QTY);
    sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)&(IF_WO_BOM_INFO_N.SUPPLY_TYPE);
    sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME);
    sqlstm.sqhstl[29] = (unsigned int  )241;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_INV_OPER);
    sqlstm.sqhstl[30] = (unsigned int  )11;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(IF_WO_BOM_INFO_N.TRAN_FLAG);
    sqlstm.sqhstl[31] = (unsigned int  )2;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(IF_WO_BOM_INFO_N.CMF_1);
    sqlstm.sqhstl[32] = (unsigned int  )51;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(IF_WO_BOM_INFO_N.CMF_2);
    sqlstm.sqhstl[33] = (unsigned int  )51;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(IF_WO_BOM_INFO_N.CMF_3);
    sqlstm.sqhstl[34] = (unsigned int  )51;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(IF_WO_BOM_INFO_N.CMF_4);
    sqlstm.sqhstl[35] = (unsigned int  )51;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(IF_WO_BOM_INFO_N.CMF_5);
    sqlstm.sqhstl[36] = (unsigned int  )51;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(IF_WO_BOM_INFO_N.CMF_6);
    sqlstm.sqhstl[37] = (unsigned int  )51;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(IF_WO_BOM_INFO_N.CMF_7);
    sqlstm.sqhstl[38] = (unsigned int  )51;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(IF_WO_BOM_INFO_N.CMF_8);
    sqlstm.sqhstl[39] = (unsigned int  )51;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(IF_WO_BOM_INFO_N.CMF_9);
    sqlstm.sqhstl[40] = (unsigned int  )51;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(IF_WO_BOM_INFO_N.CMF_10);
    sqlstm.sqhstl[41] = (unsigned int  )51;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_USER_ID);
    sqlstm.sqhstl[42] = (unsigned int  )21;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_TIME);
    sqlstm.sqhstl[43] = (unsigned int  )15;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_USER_ID);
    sqlstm.sqhstl[44] = (unsigned int  )21;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_TIME);
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



    DB_stop_query_timer("DBU_insert_if_wo_bom_info", 0);
}


/* SQL UPDATE Function */
void DBU_update_if_wo_bom_info(int sel_type, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_WO_BOM_INFO_N_TAG IF_WO_BOM_INFO_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_wo_bom_info(&IF_WO_BOM_INFO_N, IF_WO_BOM_INFO);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE IF_WO_BOM_INFO SET
                    IF_TIME = :IF_WO_BOM_INFO_N.IF_TIME,
                    IF_CODE = :IF_WO_BOM_INFO_N.IF_CODE,
                    IF_MSG = :IF_WO_BOM_INFO_N.IF_MSG,
                    FACTORY = :IF_WO_BOM_INFO_N.FACTORY,
                    ORG_ID = :IF_WO_BOM_INFO_N.ORG_ID,
                    ORG_CODE = :IF_WO_BOM_INFO_N.ORG_CODE,
                    WIP_ENTITY_ID = :IF_WO_BOM_INFO_N.WIP_ENTITY_ID,
                    WIP_ENTITY_NAME = :IF_WO_BOM_INFO_N.WIP_ENTITY_NAME,
                    ITEM_ID = :IF_WO_BOM_INFO_N.ITEM_ID,
                    ITEM_CODE = :IF_WO_BOM_INFO_N.ITEM_CODE,
                    COMP_ITEM_ID = :IF_WO_BOM_INFO_N.COMP_ITEM_ID,
                    COMP_ITEM_CODE = :IF_WO_BOM_INFO_N.COMP_ITEM_CODE,
                    COMP_ITEM_DESC = :IF_WO_BOM_INFO_N.COMP_ITEM_DESC,
                    COMP_ITEM_TYPE = :IF_WO_BOM_INFO_N.COMP_ITEM_TYPE,
                    COMP_ITEM_UNIT = :IF_WO_BOM_INFO_N.COMP_ITEM_UNIT,
                    ALTERNATE_BOM_DESIGNATOR = :IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR,
                    ALTER_RTG_NAME = :IF_WO_BOM_INFO_N.ALTER_RTG_NAME,
                    OPER_SEQ = :IF_WO_BOM_INFO_N.OPER_SEQ,
                    OPER_ID = :IF_WO_BOM_INFO_N.OPER_ID,
                    OPER = :IF_WO_BOM_INFO_N.OPER,
                    OPER_DESC = :IF_WO_BOM_INFO_N.OPER_DESC,
                    DEPT_ID = :IF_WO_BOM_INFO_N.DEPT_ID,
                    DEPT_CODE = :IF_WO_BOM_INFO_N.DEPT_CODE,
                    DEPT_DESC = :IF_WO_BOM_INFO_N.DEPT_DESC,
                    TOTAL_QTY = :IF_WO_BOM_INFO_N.TOTAL_QTY,
                    ISSUED_QTY = :IF_WO_BOM_INFO_N.ISSUED_QTY,
                    UNIT_QTY = :IF_WO_BOM_INFO_N.UNIT_QTY,
                    SUPPLY_TYPE = :IF_WO_BOM_INFO_N.SUPPLY_TYPE,
                    SUPPLY_TYPE_NAME = :IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME,
                    SUPPLY_INV_OPER = :IF_WO_BOM_INFO_N.SUPPLY_INV_OPER,
                    TRAN_FLAG = :IF_WO_BOM_INFO_N.TRAN_FLAG,
                    CMF_1 = :IF_WO_BOM_INFO_N.CMF_1,
                    CMF_2 = :IF_WO_BOM_INFO_N.CMF_2,
                    CMF_3 = :IF_WO_BOM_INFO_N.CMF_3,
                    CMF_4 = :IF_WO_BOM_INFO_N.CMF_4,
                    CMF_5 = :IF_WO_BOM_INFO_N.CMF_5,
                    CMF_6 = :IF_WO_BOM_INFO_N.CMF_6,
                    CMF_7 = :IF_WO_BOM_INFO_N.CMF_7,
                    CMF_8 = :IF_WO_BOM_INFO_N.CMF_8,
                    CMF_9 = :IF_WO_BOM_INFO_N.CMF_9,
                    CMF_10 = :IF_WO_BOM_INFO_N.CMF_10,
                    CREATE_USER_ID = :IF_WO_BOM_INFO_N.CREATE_USER_ID,
                    CREATE_TIME = :IF_WO_BOM_INFO_N.CREATE_TIME,
                    UPDATE_USER_ID = :IF_WO_BOM_INFO_N.UPDATE_USER_ID,
                    UPDATE_TIME = :IF_WO_BOM_INFO_N.UPDATE_TIME
                WHERE IF_SEQ = :IF_WO_BOM_INFO_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update IF_WO_BOM_INFO  set IF_TIME=:b0,IF_CODE=:\
b1,IF_MSG=:b2,FACTORY=:b3,ORG_ID=:b4,ORG_CODE=:b5,WIP_ENTITY_ID=:b6,WIP_ENTIT\
Y_NAME=:b7,ITEM_ID=:b8,ITEM_CODE=:b9,COMP_ITEM_ID=:b10,COMP_ITEM_CODE=:b11,CO\
MP_ITEM_DESC=:b12,COMP_ITEM_TYPE=:b13,COMP_ITEM_UNIT=:b14,ALTERNATE_BOM_DESIG\
NATOR=:b15,ALTER_RTG_NAME=:b16,OPER_SEQ=:b17,OPER_ID=:b18,OPER=:b19,OPER_DESC\
=:b20,DEPT_ID=:b21,DEPT_CODE=:b22,DEPT_DESC=:b23,TOTAL_QTY=:b24,ISSUED_QTY=:b\
25,UNIT_QTY=:b26,SUPPLY_TYPE=:b27,SUPPLY_TYPE_NAME=:b28,SUPPLY_INV_OPER=:b29,\
TRAN_FLAG=:b30,CMF_1=:b31,CMF_2=:b32,CMF_3=:b33,CMF_4=:b34,CMF_5=:b35,CMF_6=:\
b36,CMF_7=:b37,CMF_8=:b38,CMF_9=:b39,CMF_10=:b40,CREATE_USER_ID=:b41,CREATE_T\
IME=:b42,UPDATE_USER_ID=:b43,UPDATE_TIME=:b44 where IF_SEQ=:b45";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )652;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(IF_WO_BOM_INFO_N.IF_TIME);
            sqlstm.sqhstl[0] = (unsigned int  )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_WO_BOM_INFO_N.IF_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_WO_BOM_INFO_N.IF_MSG);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_WO_BOM_INFO_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(IF_WO_BOM_INFO_N.ORG_ID);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(IF_WO_BOM_INFO_N.ORG_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )4;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_WO_BOM_INFO_N.WIP_ENTITY_ID);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(IF_WO_BOM_INFO_N.WIP_ENTITY_NAME);
            sqlstm.sqhstl[7] = (unsigned int  )241;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_WO_BOM_INFO_N.ITEM_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(IF_WO_BOM_INFO_N.ITEM_CODE);
            sqlstm.sqhstl[9] = (unsigned int  )41;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(IF_WO_BOM_INFO_N.COMP_ITEM_ID);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_CODE);
            sqlstm.sqhstl[11] = (unsigned int  )41;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_DESC);
            sqlstm.sqhstl[12] = (unsigned int  )241;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_UNIT);
            sqlstm.sqhstl[14] = (unsigned int  )4;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR);
            sqlstm.sqhstl[15] = (unsigned int  )11;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(IF_WO_BOM_INFO_N.ALTER_RTG_NAME);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_SEQ);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_ID);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_WO_BOM_INFO_N.OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_WO_BOM_INFO_N.OPER_DESC);
            sqlstm.sqhstl[20] = (unsigned int  )241;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(IF_WO_BOM_INFO_N.DEPT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_CODE);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_DESC);
            sqlstm.sqhstl[23] = (unsigned int  )241;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(IF_WO_BOM_INFO_N.TOTAL_QTY);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(IF_WO_BOM_INFO_N.ISSUED_QTY);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(IF_WO_BOM_INFO_N.UNIT_QTY);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(IF_WO_BOM_INFO_N.SUPPLY_TYPE);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME);
            sqlstm.sqhstl[28] = (unsigned int  )241;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_INV_OPER);
            sqlstm.sqhstl[29] = (unsigned int  )11;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_WO_BOM_INFO_N.TRAN_FLAG);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_WO_BOM_INFO_N.CMF_1);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_WO_BOM_INFO_N.CMF_2);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_WO_BOM_INFO_N.CMF_3);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_WO_BOM_INFO_N.CMF_4);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_WO_BOM_INFO_N.CMF_5);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_WO_BOM_INFO_N.CMF_6);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_WO_BOM_INFO_N.CMF_7);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(IF_WO_BOM_INFO_N.CMF_8);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(IF_WO_BOM_INFO_N.CMF_9);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(IF_WO_BOM_INFO_N.CMF_10);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_USER_ID);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_TIME);
            sqlstm.sqhstl[42] = (unsigned int  )15;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_USER_ID);
            sqlstm.sqhstl[43] = (unsigned int  )21;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_TIME);
            sqlstm.sqhstl[44] = (unsigned int  )15;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
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

		case 101:
            /* EXEC SQL UPDATE IF_WO_BOM_INFO SET
                    IF_CODE = :IF_WO_BOM_INFO_N.IF_CODE,
                    IF_MSG = :IF_WO_BOM_INFO_N.IF_MSG
                WHERE IF_SEQ = :IF_WO_BOM_INFO_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update IF_WO_BOM_INFO  set IF_CODE=:b0,IF_MSG=:b\
1 where IF_SEQ=:b2";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )851;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(IF_WO_BOM_INFO_N.IF_CODE);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_WO_BOM_INFO_N.IF_MSG);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
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

    DB_stop_query_timer("DBU_update_if_wo_bom_info", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_if_wo_bom_info(int sel_type, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_WO_BOM_INFO_N_TAG IF_WO_BOM_INFO_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_wo_bom_info(&IF_WO_BOM_INFO_N, IF_WO_BOM_INFO);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_IF_WO_BOM_INFO_CUR_1 CURSOR FOR
                SELECT 
                    IF_SEQ,
                    IF_TIME,
                    IF_CODE,
                    IF_MSG,
                    FACTORY,
                    ORG_ID,
                    ORG_CODE,
                    WIP_ENTITY_ID,
                    WIP_ENTITY_NAME,
                    ITEM_ID,
                    ITEM_CODE,
                    COMP_ITEM_ID,
                    COMP_ITEM_CODE,
                    COMP_ITEM_DESC,
                    COMP_ITEM_TYPE,
                    COMP_ITEM_UNIT,
                    ALTERNATE_BOM_DESIGNATOR,
                    ALTER_RTG_NAME,
                    OPER_SEQ,
                    OPER_ID,
                    OPER,
                    OPER_DESC,
                    DEPT_ID,
                    DEPT_CODE,
                    DEPT_DESC,
                    TOTAL_QTY,
                    ISSUED_QTY,
                    UNIT_QTY,
                    SUPPLY_TYPE,
                    SUPPLY_TYPE_NAME,
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
                FROM IF_WO_BOM_INFO
                ORDER BY IF_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_IF_WO_BOM_INFO_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )878;
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

		case 101:
            /* EXEC SQL DECLARE DBU_IF_WO_BOM_INFO_CUR_101 CURSOR FOR
                SELECT * FROM (
					SELECT 
						IF_SEQ,
						IF_TIME,
						IF_CODE,
						IF_MSG,
						FACTORY,
						ORG_ID,
						ORG_CODE,
						WIP_ENTITY_ID,
						WIP_ENTITY_NAME,
						ITEM_ID,
						ITEM_CODE,
						COMP_ITEM_ID,
						COMP_ITEM_CODE,
						COMP_ITEM_DESC,
						COMP_ITEM_TYPE,
						COMP_ITEM_UNIT,
						ALTERNATE_BOM_DESIGNATOR,
						ALTER_RTG_NAME,
						OPER_SEQ,
						OPER_ID,
						OPER,
						OPER_DESC,
						DEPT_ID,
						DEPT_CODE,
						DEPT_DESC,
						TOTAL_QTY,
						ISSUED_QTY,
						UNIT_QTY,
						SUPPLY_TYPE,
						SUPPLY_TYPE_NAME,
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
					FROM IF_WO_BOM_INFO
					WHERE IF_CODE in ( 'N', 'R')
					ORDER BY IF_SEQ ASC)
				WHERE ROWNUM <= 10000
				; */ 

            /* EXEC SQL OPEN DBU_IF_WO_BOM_INFO_CUR_101; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )893;
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

    DB_stop_query_timer("DBU_open_if_wo_bom_info", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_if_wo_bom_info(int sel_type, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_WO_BOM_INFO_N_TAG IF_WO_BOM_INFO_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_IF_WO_BOM_INFO_CUR_1 INTO
                :IF_WO_BOM_INFO_N.IF_SEQ,
                :IF_WO_BOM_INFO_N.IF_TIME,
                :IF_WO_BOM_INFO_N.IF_CODE,
                :IF_WO_BOM_INFO_N.IF_MSG,
                :IF_WO_BOM_INFO_N.FACTORY,
                :IF_WO_BOM_INFO_N.ORG_ID,
                :IF_WO_BOM_INFO_N.ORG_CODE,
                :IF_WO_BOM_INFO_N.WIP_ENTITY_ID,
                :IF_WO_BOM_INFO_N.WIP_ENTITY_NAME,
                :IF_WO_BOM_INFO_N.ITEM_ID,
                :IF_WO_BOM_INFO_N.ITEM_CODE,
                :IF_WO_BOM_INFO_N.COMP_ITEM_ID,
                :IF_WO_BOM_INFO_N.COMP_ITEM_CODE,
                :IF_WO_BOM_INFO_N.COMP_ITEM_DESC,
                :IF_WO_BOM_INFO_N.COMP_ITEM_TYPE,
                :IF_WO_BOM_INFO_N.COMP_ITEM_UNIT,
                :IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR,
                :IF_WO_BOM_INFO_N.ALTER_RTG_NAME,
                :IF_WO_BOM_INFO_N.OPER_SEQ,
                :IF_WO_BOM_INFO_N.OPER_ID,
                :IF_WO_BOM_INFO_N.OPER,
                :IF_WO_BOM_INFO_N.OPER_DESC,
                :IF_WO_BOM_INFO_N.DEPT_ID,
                :IF_WO_BOM_INFO_N.DEPT_CODE,
                :IF_WO_BOM_INFO_N.DEPT_DESC,
                :IF_WO_BOM_INFO_N.TOTAL_QTY,
                :IF_WO_BOM_INFO_N.ISSUED_QTY,
                :IF_WO_BOM_INFO_N.UNIT_QTY,
                :IF_WO_BOM_INFO_N.SUPPLY_TYPE,
                :IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME,
                :IF_WO_BOM_INFO_N.SUPPLY_INV_OPER,
                :IF_WO_BOM_INFO_N.TRAN_FLAG,
                :IF_WO_BOM_INFO_N.CMF_1,
                :IF_WO_BOM_INFO_N.CMF_2,
                :IF_WO_BOM_INFO_N.CMF_3,
                :IF_WO_BOM_INFO_N.CMF_4,
                :IF_WO_BOM_INFO_N.CMF_5,
                :IF_WO_BOM_INFO_N.CMF_6,
                :IF_WO_BOM_INFO_N.CMF_7,
                :IF_WO_BOM_INFO_N.CMF_8,
                :IF_WO_BOM_INFO_N.CMF_9,
                :IF_WO_BOM_INFO_N.CMF_10,
                :IF_WO_BOM_INFO_N.CREATE_USER_ID,
                :IF_WO_BOM_INFO_N.CREATE_TIME,
                :IF_WO_BOM_INFO_N.UPDATE_USER_ID,
                :IF_WO_BOM_INFO_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )908;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_WO_BOM_INFO_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_WO_BOM_INFO_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_WO_BOM_INFO_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_WO_BOM_INFO_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_WO_BOM_INFO_N.ORG_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(IF_WO_BOM_INFO_N.ORG_CODE);
            sqlstm.sqhstl[6] = (unsigned int  )4;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_WO_BOM_INFO_N.WIP_ENTITY_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(IF_WO_BOM_INFO_N.WIP_ENTITY_NAME);
            sqlstm.sqhstl[8] = (unsigned int  )241;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_WO_BOM_INFO_N.ITEM_ID);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(IF_WO_BOM_INFO_N.ITEM_CODE);
            sqlstm.sqhstl[10] = (unsigned int  )41;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(IF_WO_BOM_INFO_N.COMP_ITEM_ID);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_CODE);
            sqlstm.sqhstl[12] = (unsigned int  )41;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_DESC);
            sqlstm.sqhstl[13] = (unsigned int  )241;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_TYPE);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_UNIT);
            sqlstm.sqhstl[15] = (unsigned int  )4;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_WO_BOM_INFO_N.ALTER_RTG_NAME);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_SEQ);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_ID);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_WO_BOM_INFO_N.OPER);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_WO_BOM_INFO_N.OPER_DESC);
            sqlstm.sqhstl[21] = (unsigned int  )241;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(IF_WO_BOM_INFO_N.DEPT_ID);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_CODE);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_DESC);
            sqlstm.sqhstl[24] = (unsigned int  )241;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(IF_WO_BOM_INFO_N.TOTAL_QTY);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(IF_WO_BOM_INFO_N.ISSUED_QTY);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(IF_WO_BOM_INFO_N.UNIT_QTY);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(IF_WO_BOM_INFO_N.SUPPLY_TYPE);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME);
            sqlstm.sqhstl[29] = (unsigned int  )241;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_INV_OPER);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_WO_BOM_INFO_N.TRAN_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_WO_BOM_INFO_N.CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_WO_BOM_INFO_N.CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_WO_BOM_INFO_N.CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_WO_BOM_INFO_N.CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_WO_BOM_INFO_N.CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_WO_BOM_INFO_N.CMF_6);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(IF_WO_BOM_INFO_N.CMF_7);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(IF_WO_BOM_INFO_N.CMF_8);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(IF_WO_BOM_INFO_N.CMF_9);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(IF_WO_BOM_INFO_N.CMF_10);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_USER_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )15;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_USER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_TIME);
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

		case 101:
            /* EXEC SQL FETCH DBU_IF_WO_BOM_INFO_CUR_101 INTO
                :IF_WO_BOM_INFO_N.IF_SEQ,
                :IF_WO_BOM_INFO_N.IF_TIME,
                :IF_WO_BOM_INFO_N.IF_CODE,
                :IF_WO_BOM_INFO_N.IF_MSG,
                :IF_WO_BOM_INFO_N.FACTORY,
                :IF_WO_BOM_INFO_N.ORG_ID,
                :IF_WO_BOM_INFO_N.ORG_CODE,
                :IF_WO_BOM_INFO_N.WIP_ENTITY_ID,
                :IF_WO_BOM_INFO_N.WIP_ENTITY_NAME,
                :IF_WO_BOM_INFO_N.ITEM_ID,
                :IF_WO_BOM_INFO_N.ITEM_CODE,
                :IF_WO_BOM_INFO_N.COMP_ITEM_ID,
                :IF_WO_BOM_INFO_N.COMP_ITEM_CODE,
                :IF_WO_BOM_INFO_N.COMP_ITEM_DESC,
                :IF_WO_BOM_INFO_N.COMP_ITEM_TYPE,
                :IF_WO_BOM_INFO_N.COMP_ITEM_UNIT,
                :IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR,
                :IF_WO_BOM_INFO_N.ALTER_RTG_NAME,
                :IF_WO_BOM_INFO_N.OPER_SEQ,
                :IF_WO_BOM_INFO_N.OPER_ID,
                :IF_WO_BOM_INFO_N.OPER,
                :IF_WO_BOM_INFO_N.OPER_DESC,
                :IF_WO_BOM_INFO_N.DEPT_ID,
                :IF_WO_BOM_INFO_N.DEPT_CODE,
                :IF_WO_BOM_INFO_N.DEPT_DESC,
                :IF_WO_BOM_INFO_N.TOTAL_QTY,
                :IF_WO_BOM_INFO_N.ISSUED_QTY,
                :IF_WO_BOM_INFO_N.UNIT_QTY,
                :IF_WO_BOM_INFO_N.SUPPLY_TYPE,
                :IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME,
                :IF_WO_BOM_INFO_N.SUPPLY_INV_OPER,
                :IF_WO_BOM_INFO_N.TRAN_FLAG,
                :IF_WO_BOM_INFO_N.CMF_1,
                :IF_WO_BOM_INFO_N.CMF_2,
                :IF_WO_BOM_INFO_N.CMF_3,
                :IF_WO_BOM_INFO_N.CMF_4,
                :IF_WO_BOM_INFO_N.CMF_5,
                :IF_WO_BOM_INFO_N.CMF_6,
                :IF_WO_BOM_INFO_N.CMF_7,
                :IF_WO_BOM_INFO_N.CMF_8,
                :IF_WO_BOM_INFO_N.CMF_9,
                :IF_WO_BOM_INFO_N.CMF_10,
                :IF_WO_BOM_INFO_N.CREATE_USER_ID,
                :IF_WO_BOM_INFO_N.CREATE_TIME,
                :IF_WO_BOM_INFO_N.UPDATE_USER_ID,
                :IF_WO_BOM_INFO_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1107;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(IF_WO_BOM_INFO_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_WO_BOM_INFO_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_WO_BOM_INFO_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_WO_BOM_INFO_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_WO_BOM_INFO_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_WO_BOM_INFO_N.ORG_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(IF_WO_BOM_INFO_N.ORG_CODE);
            sqlstm.sqhstl[6] = (unsigned int  )4;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_WO_BOM_INFO_N.WIP_ENTITY_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(IF_WO_BOM_INFO_N.WIP_ENTITY_NAME);
            sqlstm.sqhstl[8] = (unsigned int  )241;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_WO_BOM_INFO_N.ITEM_ID);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(IF_WO_BOM_INFO_N.ITEM_CODE);
            sqlstm.sqhstl[10] = (unsigned int  )41;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(IF_WO_BOM_INFO_N.COMP_ITEM_ID);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_CODE);
            sqlstm.sqhstl[12] = (unsigned int  )41;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_DESC);
            sqlstm.sqhstl[13] = (unsigned int  )241;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_TYPE);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_WO_BOM_INFO_N.COMP_ITEM_UNIT);
            sqlstm.sqhstl[15] = (unsigned int  )4;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(IF_WO_BOM_INFO_N.ALTERNATE_BOM_DESIGNATOR);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_WO_BOM_INFO_N.ALTER_RTG_NAME);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_SEQ);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(IF_WO_BOM_INFO_N.OPER_ID);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_WO_BOM_INFO_N.OPER);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_WO_BOM_INFO_N.OPER_DESC);
            sqlstm.sqhstl[21] = (unsigned int  )241;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(IF_WO_BOM_INFO_N.DEPT_ID);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_CODE);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_WO_BOM_INFO_N.DEPT_DESC);
            sqlstm.sqhstl[24] = (unsigned int  )241;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(IF_WO_BOM_INFO_N.TOTAL_QTY);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(IF_WO_BOM_INFO_N.ISSUED_QTY);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(IF_WO_BOM_INFO_N.UNIT_QTY);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(IF_WO_BOM_INFO_N.SUPPLY_TYPE);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_TYPE_NAME);
            sqlstm.sqhstl[29] = (unsigned int  )241;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_WO_BOM_INFO_N.SUPPLY_INV_OPER);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_WO_BOM_INFO_N.TRAN_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_WO_BOM_INFO_N.CMF_1);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_WO_BOM_INFO_N.CMF_2);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_WO_BOM_INFO_N.CMF_3);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_WO_BOM_INFO_N.CMF_4);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_WO_BOM_INFO_N.CMF_5);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_WO_BOM_INFO_N.CMF_6);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(IF_WO_BOM_INFO_N.CMF_7);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(IF_WO_BOM_INFO_N.CMF_8);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(IF_WO_BOM_INFO_N.CMF_9);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(IF_WO_BOM_INFO_N.CMF_10);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_USER_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_WO_BOM_INFO_N.CREATE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )15;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_USER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_WO_BOM_INFO_N.UPDATE_TIME);
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
        DBU_del_null_if_wo_bom_info(&IF_WO_BOM_INFO_N, IF_WO_BOM_INFO);
    }

    DB_stop_query_timer("DBU_fetch_if_wo_bom_info", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_if_wo_bom_info(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_IF_WO_BOM_INFO_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1306;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 101:
            /* EXEC SQL CLOSE DBU_IF_WO_BOM_INFO_CUR_101; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1321;
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

    DB_stop_query_timer("DBU_close_if_wo_bom_info", sel_type);
}


/* Initialize Function */
void DBU_init_if_wo_bom_info(struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    /* memset by Space */
    memset(IF_WO_BOM_INFO, ' ', sizeof(struct IF_WO_BOM_INFO_TAG));
    
    IF_WO_BOM_INFO->IF_SEQ = 0;
    IF_WO_BOM_INFO->ORG_ID = 0;
    IF_WO_BOM_INFO->WIP_ENTITY_ID = 0;
    IF_WO_BOM_INFO->ITEM_ID = 0;
    IF_WO_BOM_INFO->COMP_ITEM_ID = 0;
    IF_WO_BOM_INFO->OPER_SEQ = 0;
    IF_WO_BOM_INFO->OPER_ID = 0;
    IF_WO_BOM_INFO->DEPT_ID = 0;
    IF_WO_BOM_INFO->TOTAL_QTY = 0;
    IF_WO_BOM_INFO->ISSUED_QTY = 0;
    IF_WO_BOM_INFO->UNIT_QTY = 0;
    IF_WO_BOM_INFO->SUPPLY_TYPE = 0;
}


/* Add Null Function */
void DBU_add_null_if_wo_bom_info(struct IF_WO_BOM_INFO_N_TAG *IF_WO_BOM_INFO_N, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    /* memset by NULL */
    memset(IF_WO_BOM_INFO_N, '\0', sizeof(struct IF_WO_BOM_INFO_N_TAG));
    
    IF_WO_BOM_INFO_N->IF_SEQ = IF_WO_BOM_INFO->IF_SEQ;
    MEMCPY_AN(IF_WO_BOM_INFO_N->IF_TIME, IF_WO_BOM_INFO->IF_TIME, sizeof(IF_WO_BOM_INFO->IF_TIME));
    IF_WO_BOM_INFO_N->IF_CODE[0] = IF_WO_BOM_INFO->IF_CODE;
    MEMCPY_AN(IF_WO_BOM_INFO_N->IF_MSG, IF_WO_BOM_INFO->IF_MSG, sizeof(IF_WO_BOM_INFO->IF_MSG));
    MEMCPY_AN(IF_WO_BOM_INFO_N->FACTORY, IF_WO_BOM_INFO->FACTORY, sizeof(IF_WO_BOM_INFO->FACTORY));
    IF_WO_BOM_INFO_N->ORG_ID = IF_WO_BOM_INFO->ORG_ID;
    MEMCPY_AN(IF_WO_BOM_INFO_N->ORG_CODE, IF_WO_BOM_INFO->ORG_CODE, sizeof(IF_WO_BOM_INFO->ORG_CODE));
    IF_WO_BOM_INFO_N->WIP_ENTITY_ID = IF_WO_BOM_INFO->WIP_ENTITY_ID;
    MEMCPY_AN(IF_WO_BOM_INFO_N->WIP_ENTITY_NAME, IF_WO_BOM_INFO->WIP_ENTITY_NAME, sizeof(IF_WO_BOM_INFO->WIP_ENTITY_NAME));
    IF_WO_BOM_INFO_N->ITEM_ID = IF_WO_BOM_INFO->ITEM_ID;
    MEMCPY_AN(IF_WO_BOM_INFO_N->ITEM_CODE, IF_WO_BOM_INFO->ITEM_CODE, sizeof(IF_WO_BOM_INFO->ITEM_CODE));
    IF_WO_BOM_INFO_N->COMP_ITEM_ID = IF_WO_BOM_INFO->COMP_ITEM_ID;
    MEMCPY_AN(IF_WO_BOM_INFO_N->COMP_ITEM_CODE, IF_WO_BOM_INFO->COMP_ITEM_CODE, sizeof(IF_WO_BOM_INFO->COMP_ITEM_CODE));
    MEMCPY_AN(IF_WO_BOM_INFO_N->COMP_ITEM_DESC, IF_WO_BOM_INFO->COMP_ITEM_DESC, sizeof(IF_WO_BOM_INFO->COMP_ITEM_DESC));
    MEMCPY_AN(IF_WO_BOM_INFO_N->COMP_ITEM_TYPE, IF_WO_BOM_INFO->COMP_ITEM_TYPE, sizeof(IF_WO_BOM_INFO->COMP_ITEM_TYPE));
    MEMCPY_AN(IF_WO_BOM_INFO_N->COMP_ITEM_UNIT, IF_WO_BOM_INFO->COMP_ITEM_UNIT, sizeof(IF_WO_BOM_INFO->COMP_ITEM_UNIT));
    MEMCPY_AN(IF_WO_BOM_INFO_N->ALTERNATE_BOM_DESIGNATOR, IF_WO_BOM_INFO->ALTERNATE_BOM_DESIGNATOR, sizeof(IF_WO_BOM_INFO->ALTERNATE_BOM_DESIGNATOR));
    MEMCPY_AN(IF_WO_BOM_INFO_N->ALTER_RTG_NAME, IF_WO_BOM_INFO->ALTER_RTG_NAME, sizeof(IF_WO_BOM_INFO->ALTER_RTG_NAME));
    IF_WO_BOM_INFO_N->OPER_SEQ = IF_WO_BOM_INFO->OPER_SEQ;
    IF_WO_BOM_INFO_N->OPER_ID = IF_WO_BOM_INFO->OPER_ID;
    MEMCPY_AN(IF_WO_BOM_INFO_N->OPER, IF_WO_BOM_INFO->OPER, sizeof(IF_WO_BOM_INFO->OPER));
    MEMCPY_AN(IF_WO_BOM_INFO_N->OPER_DESC, IF_WO_BOM_INFO->OPER_DESC, sizeof(IF_WO_BOM_INFO->OPER_DESC));
    IF_WO_BOM_INFO_N->DEPT_ID = IF_WO_BOM_INFO->DEPT_ID;
    MEMCPY_AN(IF_WO_BOM_INFO_N->DEPT_CODE, IF_WO_BOM_INFO->DEPT_CODE, sizeof(IF_WO_BOM_INFO->DEPT_CODE));
    MEMCPY_AN(IF_WO_BOM_INFO_N->DEPT_DESC, IF_WO_BOM_INFO->DEPT_DESC, sizeof(IF_WO_BOM_INFO->DEPT_DESC));
    IF_WO_BOM_INFO_N->TOTAL_QTY = IF_WO_BOM_INFO->TOTAL_QTY;
    IF_WO_BOM_INFO_N->ISSUED_QTY = IF_WO_BOM_INFO->ISSUED_QTY;
    IF_WO_BOM_INFO_N->UNIT_QTY = IF_WO_BOM_INFO->UNIT_QTY;
    IF_WO_BOM_INFO_N->SUPPLY_TYPE = IF_WO_BOM_INFO->SUPPLY_TYPE;
    MEMCPY_AN(IF_WO_BOM_INFO_N->SUPPLY_TYPE_NAME, IF_WO_BOM_INFO->SUPPLY_TYPE_NAME, sizeof(IF_WO_BOM_INFO->SUPPLY_TYPE_NAME));
    MEMCPY_AN(IF_WO_BOM_INFO_N->SUPPLY_INV_OPER, IF_WO_BOM_INFO->SUPPLY_INV_OPER, sizeof(IF_WO_BOM_INFO->SUPPLY_INV_OPER));
    IF_WO_BOM_INFO_N->TRAN_FLAG[0] = IF_WO_BOM_INFO->TRAN_FLAG;
    MEMCPY_AN(IF_WO_BOM_INFO_N->CMF_1, IF_WO_BOM_INFO->CMF_1, sizeof(IF_WO_BOM_INFO->CMF_1));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CMF_2, IF_WO_BOM_INFO->CMF_2, sizeof(IF_WO_BOM_INFO->CMF_2));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CMF_3, IF_WO_BOM_INFO->CMF_3, sizeof(IF_WO_BOM_INFO->CMF_3));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CMF_4, IF_WO_BOM_INFO->CMF_4, sizeof(IF_WO_BOM_INFO->CMF_4));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CMF_5, IF_WO_BOM_INFO->CMF_5, sizeof(IF_WO_BOM_INFO->CMF_5));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CMF_6, IF_WO_BOM_INFO->CMF_6, sizeof(IF_WO_BOM_INFO->CMF_6));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CMF_7, IF_WO_BOM_INFO->CMF_7, sizeof(IF_WO_BOM_INFO->CMF_7));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CMF_8, IF_WO_BOM_INFO->CMF_8, sizeof(IF_WO_BOM_INFO->CMF_8));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CMF_9, IF_WO_BOM_INFO->CMF_9, sizeof(IF_WO_BOM_INFO->CMF_9));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CMF_10, IF_WO_BOM_INFO->CMF_10, sizeof(IF_WO_BOM_INFO->CMF_10));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CREATE_USER_ID, IF_WO_BOM_INFO->CREATE_USER_ID, sizeof(IF_WO_BOM_INFO->CREATE_USER_ID));
    MEMCPY_AN(IF_WO_BOM_INFO_N->CREATE_TIME, IF_WO_BOM_INFO->CREATE_TIME, sizeof(IF_WO_BOM_INFO->CREATE_TIME));
    MEMCPY_AN(IF_WO_BOM_INFO_N->UPDATE_USER_ID, IF_WO_BOM_INFO->UPDATE_USER_ID, sizeof(IF_WO_BOM_INFO->UPDATE_USER_ID));
    MEMCPY_AN(IF_WO_BOM_INFO_N->UPDATE_TIME, IF_WO_BOM_INFO->UPDATE_TIME, sizeof(IF_WO_BOM_INFO->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_if_wo_bom_info(struct IF_WO_BOM_INFO_N_TAG *IF_WO_BOM_INFO_N, struct IF_WO_BOM_INFO_TAG *IF_WO_BOM_INFO)
{
    IF_WO_BOM_INFO->IF_SEQ = IF_WO_BOM_INFO_N->IF_SEQ;
    MEMCPY_DN(IF_WO_BOM_INFO->IF_TIME, IF_WO_BOM_INFO_N->IF_TIME, sizeof(IF_WO_BOM_INFO->IF_TIME));
    IF_WO_BOM_INFO->IF_CODE = IF_WO_BOM_INFO_N->IF_CODE[0];
    MEMCPY_DN(IF_WO_BOM_INFO->IF_MSG, IF_WO_BOM_INFO_N->IF_MSG, sizeof(IF_WO_BOM_INFO->IF_MSG));
    MEMCPY_DN(IF_WO_BOM_INFO->FACTORY, IF_WO_BOM_INFO_N->FACTORY, sizeof(IF_WO_BOM_INFO->FACTORY));
    IF_WO_BOM_INFO->ORG_ID = IF_WO_BOM_INFO_N->ORG_ID;
    MEMCPY_DN(IF_WO_BOM_INFO->ORG_CODE, IF_WO_BOM_INFO_N->ORG_CODE, sizeof(IF_WO_BOM_INFO->ORG_CODE));
    IF_WO_BOM_INFO->WIP_ENTITY_ID = IF_WO_BOM_INFO_N->WIP_ENTITY_ID;
    MEMCPY_DN(IF_WO_BOM_INFO->WIP_ENTITY_NAME, IF_WO_BOM_INFO_N->WIP_ENTITY_NAME, sizeof(IF_WO_BOM_INFO->WIP_ENTITY_NAME));
    IF_WO_BOM_INFO->ITEM_ID = IF_WO_BOM_INFO_N->ITEM_ID;
    MEMCPY_DN(IF_WO_BOM_INFO->ITEM_CODE, IF_WO_BOM_INFO_N->ITEM_CODE, sizeof(IF_WO_BOM_INFO->ITEM_CODE));
    IF_WO_BOM_INFO->COMP_ITEM_ID = IF_WO_BOM_INFO_N->COMP_ITEM_ID;
    MEMCPY_DN(IF_WO_BOM_INFO->COMP_ITEM_CODE, IF_WO_BOM_INFO_N->COMP_ITEM_CODE, sizeof(IF_WO_BOM_INFO->COMP_ITEM_CODE));
    MEMCPY_DN(IF_WO_BOM_INFO->COMP_ITEM_DESC, IF_WO_BOM_INFO_N->COMP_ITEM_DESC, sizeof(IF_WO_BOM_INFO->COMP_ITEM_DESC));
    MEMCPY_DN(IF_WO_BOM_INFO->COMP_ITEM_TYPE, IF_WO_BOM_INFO_N->COMP_ITEM_TYPE, sizeof(IF_WO_BOM_INFO->COMP_ITEM_TYPE));
    MEMCPY_DN(IF_WO_BOM_INFO->COMP_ITEM_UNIT, IF_WO_BOM_INFO_N->COMP_ITEM_UNIT, sizeof(IF_WO_BOM_INFO->COMP_ITEM_UNIT));
    MEMCPY_DN(IF_WO_BOM_INFO->ALTERNATE_BOM_DESIGNATOR, IF_WO_BOM_INFO_N->ALTERNATE_BOM_DESIGNATOR, sizeof(IF_WO_BOM_INFO->ALTERNATE_BOM_DESIGNATOR));
    MEMCPY_DN(IF_WO_BOM_INFO->ALTER_RTG_NAME, IF_WO_BOM_INFO_N->ALTER_RTG_NAME, sizeof(IF_WO_BOM_INFO->ALTER_RTG_NAME));
    IF_WO_BOM_INFO->OPER_SEQ = IF_WO_BOM_INFO_N->OPER_SEQ;
    IF_WO_BOM_INFO->OPER_ID = IF_WO_BOM_INFO_N->OPER_ID;
    MEMCPY_DN(IF_WO_BOM_INFO->OPER, IF_WO_BOM_INFO_N->OPER, sizeof(IF_WO_BOM_INFO->OPER));
    MEMCPY_DN(IF_WO_BOM_INFO->OPER_DESC, IF_WO_BOM_INFO_N->OPER_DESC, sizeof(IF_WO_BOM_INFO->OPER_DESC));
    IF_WO_BOM_INFO->DEPT_ID = IF_WO_BOM_INFO_N->DEPT_ID;
    MEMCPY_DN(IF_WO_BOM_INFO->DEPT_CODE, IF_WO_BOM_INFO_N->DEPT_CODE, sizeof(IF_WO_BOM_INFO->DEPT_CODE));
    MEMCPY_DN(IF_WO_BOM_INFO->DEPT_DESC, IF_WO_BOM_INFO_N->DEPT_DESC, sizeof(IF_WO_BOM_INFO->DEPT_DESC));
    IF_WO_BOM_INFO->TOTAL_QTY = IF_WO_BOM_INFO_N->TOTAL_QTY;
    IF_WO_BOM_INFO->ISSUED_QTY = IF_WO_BOM_INFO_N->ISSUED_QTY;
    IF_WO_BOM_INFO->UNIT_QTY = IF_WO_BOM_INFO_N->UNIT_QTY;
    IF_WO_BOM_INFO->SUPPLY_TYPE = IF_WO_BOM_INFO_N->SUPPLY_TYPE;
    MEMCPY_DN(IF_WO_BOM_INFO->SUPPLY_TYPE_NAME, IF_WO_BOM_INFO_N->SUPPLY_TYPE_NAME, sizeof(IF_WO_BOM_INFO->SUPPLY_TYPE_NAME));
    MEMCPY_DN(IF_WO_BOM_INFO->SUPPLY_INV_OPER, IF_WO_BOM_INFO_N->SUPPLY_INV_OPER, sizeof(IF_WO_BOM_INFO->SUPPLY_INV_OPER));
    IF_WO_BOM_INFO->TRAN_FLAG = IF_WO_BOM_INFO_N->TRAN_FLAG[0];
    MEMCPY_DN(IF_WO_BOM_INFO->CMF_1, IF_WO_BOM_INFO_N->CMF_1, sizeof(IF_WO_BOM_INFO->CMF_1));
    MEMCPY_DN(IF_WO_BOM_INFO->CMF_2, IF_WO_BOM_INFO_N->CMF_2, sizeof(IF_WO_BOM_INFO->CMF_2));
    MEMCPY_DN(IF_WO_BOM_INFO->CMF_3, IF_WO_BOM_INFO_N->CMF_3, sizeof(IF_WO_BOM_INFO->CMF_3));
    MEMCPY_DN(IF_WO_BOM_INFO->CMF_4, IF_WO_BOM_INFO_N->CMF_4, sizeof(IF_WO_BOM_INFO->CMF_4));
    MEMCPY_DN(IF_WO_BOM_INFO->CMF_5, IF_WO_BOM_INFO_N->CMF_5, sizeof(IF_WO_BOM_INFO->CMF_5));
    MEMCPY_DN(IF_WO_BOM_INFO->CMF_6, IF_WO_BOM_INFO_N->CMF_6, sizeof(IF_WO_BOM_INFO->CMF_6));
    MEMCPY_DN(IF_WO_BOM_INFO->CMF_7, IF_WO_BOM_INFO_N->CMF_7, sizeof(IF_WO_BOM_INFO->CMF_7));
    MEMCPY_DN(IF_WO_BOM_INFO->CMF_8, IF_WO_BOM_INFO_N->CMF_8, sizeof(IF_WO_BOM_INFO->CMF_8));
    MEMCPY_DN(IF_WO_BOM_INFO->CMF_9, IF_WO_BOM_INFO_N->CMF_9, sizeof(IF_WO_BOM_INFO->CMF_9));
    MEMCPY_DN(IF_WO_BOM_INFO->CMF_10, IF_WO_BOM_INFO_N->CMF_10, sizeof(IF_WO_BOM_INFO->CMF_10));
    MEMCPY_DN(IF_WO_BOM_INFO->CREATE_USER_ID, IF_WO_BOM_INFO_N->CREATE_USER_ID, sizeof(IF_WO_BOM_INFO->CREATE_USER_ID));
    MEMCPY_DN(IF_WO_BOM_INFO->CREATE_TIME, IF_WO_BOM_INFO_N->CREATE_TIME, sizeof(IF_WO_BOM_INFO->CREATE_TIME));
    MEMCPY_DN(IF_WO_BOM_INFO->UPDATE_USER_ID, IF_WO_BOM_INFO_N->UPDATE_USER_ID, sizeof(IF_WO_BOM_INFO->UPDATE_USER_ID));
    MEMCPY_DN(IF_WO_BOM_INFO->UPDATE_TIME, IF_WO_BOM_INFO_N->UPDATE_TIME, sizeof(IF_WO_BOM_INFO->UPDATE_TIME));
}


