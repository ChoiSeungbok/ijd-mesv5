
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
           char  filnam[24];
};
static const struct sqlcxp sqlfpn =
{
    23,
    "DBU_if_pack_info_his.pc"
};


static unsigned int sqlctx = 601988867;


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

 static const char *sq0007 = 
"select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY ,OU_ID ,ORG_ID ,ORG_CODE ,\
ORDER_HEADER_ID ,ORDER_NUMBER ,LINE_NUMBER ,ORDER_TYPE_ID ,ORDERED_DATE ,BOOK\
ED_DATE ,ITEM_ID ,ITEM_CODE ,ITEM_DESC ,LABEL_NAME ,CUSTOMER_ID ,CUSTOMER_NUM\
BER ,CUSTOMER_NAME ,SHIP_TO_SITE_USE_ID ,SHIP_TO_NAME ,END_SHIP_TO_ID ,END_SH\
IP_TO_NAME ,DRAWING_FLAG ,PACKING_INSTRUCTIONS ,ORDER_TYPE ,REQUEST_DATE ,SCH\
EDULE_SHIP_DATE ,SCHEDULE_ARRIVAL_DATE ,PROMISE_DATE ,INCLUDE_INSPECTION ,LAB\
EL_TYPE ,LABEL_MESH ,LINE_DESC ,ORDER_UNIT ,CURRENCY_CODE ,ORDERED_QTY ,SHIPE\
D_QTY ,CANCELED_QTY ,UNIT_SELLING_PRICE ,UNIT_SELLING_PRICE_KR ,ALLOCATE_FLAG\
 ,CUSTOMER_PO_NO ,CUST_ITME_NAME ,CUST_ITEM_TYPE ,REST ,CUSTOMER_PO_LINE ,FOR\
MAT_ID ,CUSTOMER_PO ,PO_GUBUN ,TRAN_FLAG ,IF_GROUP_ID ,CMF_2 ,CMF_3 ,CMF_4 ,C\
MF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE\
_USER_ID ,UPDATE_TIME  from IF_PACK_INFO_HIS  order by IF_SEQ asc            \
 ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1236,0,4,46,0,0,68,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,
0,
292,0,0,2,1248,0,4,220,0,0,68,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,
3,0,0,
579,0,0,3,65,0,4,397,0,0,2,1,0,1,0,2,4,0,0,1,3,0,0,
602,0,0,4,47,0,2,433,0,0,1,1,0,1,0,1,3,0,0,
621,0,0,5,1158,0,3,462,0,0,67,67,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
904,0,0,6,1153,0,5,621,0,0,67,67,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1187,0,0,7,923,0,9,790,0,0,0,0,0,1,0,
1202,0,0,7,0,0,13,819,0,0,67,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1485,0,0,7,0,0,15,916,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_if_pack_info_his.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-10-23 15:43:26
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
void DBU_add_null_if_pack_info_his(struct IF_PACK_INFO_HIS_N_TAG *IF_PACK_INFO_HIS_N, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS);
void DBU_del_null_if_pack_info_his(struct IF_PACK_INFO_HIS_N_TAG *IF_PACK_INFO_HIS_N, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS); 


/* SQL SELECT Function */
void DBU_select_if_pack_info_his(int sel_type, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_PACK_INFO_HIS_N_TAG IF_PACK_INFO_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_pack_info_his(&IF_PACK_INFO_HIS_N, IF_PACK_INFO_HIS);
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
                    OU_ID,
                    ORG_ID,
                    ORG_CODE,
                    ORDER_HEADER_ID,
                    ORDER_NUMBER,
                    LINE_NUMBER,
                    ORDER_TYPE_ID,
                    ORDERED_DATE,
                    BOOKED_DATE,
                    ITEM_ID,
                    ITEM_CODE,
                    ITEM_DESC,
                    LABEL_NAME,
                    CUSTOMER_ID,
                    CUSTOMER_NUMBER,
                    CUSTOMER_NAME,
                    SHIP_TO_SITE_USE_ID,
                    SHIP_TO_NAME,
                    END_SHIP_TO_ID,
                    END_SHIP_TO_NAME,
                    DRAWING_FLAG,
                    PACKING_INSTRUCTIONS,
                    ORDER_TYPE,
                    REQUEST_DATE,
                    SCHEDULE_SHIP_DATE,
                    SCHEDULE_ARRIVAL_DATE,
                    PROMISE_DATE,
                    INCLUDE_INSPECTION,
                    LABEL_TYPE,
                    LABEL_MESH,
                    LINE_DESC,
                    ORDER_UNIT,
                    CURRENCY_CODE,
                    ORDERED_QTY,
                    SHIPED_QTY,
                    CANCELED_QTY,
                    UNIT_SELLING_PRICE,
                    UNIT_SELLING_PRICE_KR,
                    ALLOCATE_FLAG,
                    CUSTOMER_PO_NO,
                    CUST_ITME_NAME,
                    CUST_ITEM_TYPE,
                    REST,
                    CUSTOMER_PO_LINE,
                    FORMAT_ID,
                    CUSTOMER_PO,
                    PO_GUBUN,
                    TRAN_FLAG,
                    IF_GROUP_ID,
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
                    :IF_PACK_INFO_HIS_N.IF_SEQ,
                    :IF_PACK_INFO_HIS_N.IF_TIME,
                    :IF_PACK_INFO_HIS_N.IF_CODE,
                    :IF_PACK_INFO_HIS_N.IF_MSG,
                    :IF_PACK_INFO_HIS_N.FACTORY,
                    :IF_PACK_INFO_HIS_N.OU_ID,
                    :IF_PACK_INFO_HIS_N.ORG_ID,
                    :IF_PACK_INFO_HIS_N.ORG_CODE,
                    :IF_PACK_INFO_HIS_N.ORDER_HEADER_ID,
                    :IF_PACK_INFO_HIS_N.ORDER_NUMBER,
                    :IF_PACK_INFO_HIS_N.LINE_NUMBER,
                    :IF_PACK_INFO_HIS_N.ORDER_TYPE_ID,
                    :IF_PACK_INFO_HIS_N.ORDERED_DATE,
                    :IF_PACK_INFO_HIS_N.BOOKED_DATE,
                    :IF_PACK_INFO_HIS_N.ITEM_ID,
                    :IF_PACK_INFO_HIS_N.ITEM_CODE,
                    :IF_PACK_INFO_HIS_N.ITEM_DESC,
                    :IF_PACK_INFO_HIS_N.LABEL_NAME,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_ID,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_NUMBER,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_NAME,
                    :IF_PACK_INFO_HIS_N.SHIP_TO_SITE_USE_ID,
                    :IF_PACK_INFO_HIS_N.SHIP_TO_NAME,
                    :IF_PACK_INFO_HIS_N.END_SHIP_TO_ID,
                    :IF_PACK_INFO_HIS_N.END_SHIP_TO_NAME,
                    :IF_PACK_INFO_HIS_N.DRAWING_FLAG,
                    :IF_PACK_INFO_HIS_N.PACKING_INSTRUCTIONS,
                    :IF_PACK_INFO_HIS_N.ORDER_TYPE,
                    :IF_PACK_INFO_HIS_N.REQUEST_DATE,
                    :IF_PACK_INFO_HIS_N.SCHEDULE_SHIP_DATE,
                    :IF_PACK_INFO_HIS_N.SCHEDULE_ARRIVAL_DATE,
                    :IF_PACK_INFO_HIS_N.PROMISE_DATE,
                    :IF_PACK_INFO_HIS_N.INCLUDE_INSPECTION,
                    :IF_PACK_INFO_HIS_N.LABEL_TYPE,
                    :IF_PACK_INFO_HIS_N.LABEL_MESH,
                    :IF_PACK_INFO_HIS_N.LINE_DESC,
                    :IF_PACK_INFO_HIS_N.ORDER_UNIT,
                    :IF_PACK_INFO_HIS_N.CURRENCY_CODE,
                    :IF_PACK_INFO_HIS_N.ORDERED_QTY,
                    :IF_PACK_INFO_HIS_N.SHIPED_QTY,
                    :IF_PACK_INFO_HIS_N.CANCELED_QTY,
                    :IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE,
                    :IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE_KR,
                    :IF_PACK_INFO_HIS_N.ALLOCATE_FLAG,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_PO_NO,
                    :IF_PACK_INFO_HIS_N.CUST_ITME_NAME,
                    :IF_PACK_INFO_HIS_N.CUST_ITEM_TYPE,
                    :IF_PACK_INFO_HIS_N.REST,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_PO_LINE,
                    :IF_PACK_INFO_HIS_N.FORMAT_ID,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_PO,
                    :IF_PACK_INFO_HIS_N.PO_GUBUN,
                    :IF_PACK_INFO_HIS_N.TRAN_FLAG,
                    :IF_PACK_INFO_HIS_N.IF_GROUP_ID,
                    :IF_PACK_INFO_HIS_N.CMF_2,
                    :IF_PACK_INFO_HIS_N.CMF_3,
                    :IF_PACK_INFO_HIS_N.CMF_4,
                    :IF_PACK_INFO_HIS_N.CMF_5,
                    :IF_PACK_INFO_HIS_N.CMF_6,
                    :IF_PACK_INFO_HIS_N.CMF_7,
                    :IF_PACK_INFO_HIS_N.CMF_8,
                    :IF_PACK_INFO_HIS_N.CMF_9,
                    :IF_PACK_INFO_HIS_N.CMF_10,
                    :IF_PACK_INFO_HIS_N.CREATE_USER_ID,
                    :IF_PACK_INFO_HIS_N.CREATE_TIME,
                    :IF_PACK_INFO_HIS_N.UPDATE_USER_ID,
                    :IF_PACK_INFO_HIS_N.UPDATE_TIME
                FROM IF_PACK_INFO_HIS
                WHERE IF_SEQ = :IF_PACK_INFO_HIS_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY ,OU_ID ,ORG_\
ID ,ORG_CODE ,ORDER_HEADER_ID ,ORDER_NUMBER ,LINE_NUMBER ,ORDER_TYPE_ID ,ORD\
ERED_DATE ,BOOKED_DATE ,ITEM_ID ,ITEM_CODE ,ITEM_DESC ,LABEL_NAME ,CUSTOMER_\
ID ,CUSTOMER_NUMBER ,CUSTOMER_NAME ,SHIP_TO_SITE_USE_ID ,SHIP_TO_NAME ,END_S\
HIP_TO_ID ,END_SHIP_TO_NAME ,DRAWING_FLAG ,PACKING_INSTRUCTIONS ,ORDER_TYPE \
,REQUEST_DATE ,SCHEDULE_SHIP_DATE ,SCHEDULE_ARRIVAL_DATE ,PROMISE_DATE ,INCL\
UDE_INSPECTION ,LABEL_TYPE ,LABEL_MESH ,LINE_DESC ,ORDER_UNIT ,CURRENCY_CODE\
 ,ORDERED_QTY ,SHIPED_QTY ,CANCELED_QTY ,UNIT_SELLING_PRICE ,UNIT_SELLING_PR\
ICE_KR ,ALLOCATE_FLAG ,CUSTOMER_PO_NO ,CUST_ITME_NAME ,CUST_ITEM_TYPE ,REST \
,CUSTOMER_PO_LINE ,FORMAT_ID ,CUSTOMER_PO ,PO_GUBUN ,TRAN_FLAG ,IF_GROUP_ID \
,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER\
_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:\
b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b");
            sqlstm.stmt = "32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,\
:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b\
57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66  from IF_PACK_INFO_HIS where \
IF_SEQ=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_PACK_INFO_HIS_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_PACK_INFO_HIS_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_PACK_INFO_HIS_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_PACK_INFO_HIS_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_PACK_INFO_HIS_N.OU_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_PACK_INFO_HIS_N.ORG_ID);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(IF_PACK_INFO_HIS_N.ORG_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )4;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_HEADER_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_NUMBER);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(IF_PACK_INFO_HIS_N.LINE_NUMBER);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_TYPE_ID);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_PACK_INFO_HIS_N.ORDERED_DATE);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_PACK_INFO_HIS_N.BOOKED_DATE);
            sqlstm.sqhstl[13] = (unsigned int  )4;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(IF_PACK_INFO_HIS_N.ITEM_ID);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_PACK_INFO_HIS_N.ITEM_CODE);
            sqlstm.sqhstl[15] = (unsigned int  )41;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(IF_PACK_INFO_HIS_N.ITEM_DESC);
            sqlstm.sqhstl[16] = (unsigned int  )241;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_NAME);
            sqlstm.sqhstl[17] = (unsigned int  )1001;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_PACK_INFO_HIS_N.CUSTOMER_ID);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_NUMBER);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_NAME);
            sqlstm.sqhstl[20] = (unsigned int  )51;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(IF_PACK_INFO_HIS_N.SHIP_TO_SITE_USE_ID);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_PACK_INFO_HIS_N.SHIP_TO_NAME);
            sqlstm.sqhstl[22] = (unsigned int  )41;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(IF_PACK_INFO_HIS_N.END_SHIP_TO_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_PACK_INFO_HIS_N.END_SHIP_TO_NAME);
            sqlstm.sqhstl[24] = (unsigned int  )241;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(IF_PACK_INFO_HIS_N.DRAWING_FLAG);
            sqlstm.sqhstl[25] = (unsigned int  )2001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(IF_PACK_INFO_HIS_N.PACKING_INSTRUCTIONS);
            sqlstm.sqhstl[26] = (unsigned int  )2001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_PACK_INFO_HIS_N.ORDER_TYPE);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_PACK_INFO_HIS_N.REQUEST_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )15;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_PACK_INFO_HIS_N.SCHEDULE_SHIP_DATE);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_PACK_INFO_HIS_N.SCHEDULE_ARRIVAL_DATE);
            sqlstm.sqhstl[30] = (unsigned int  )15;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_PACK_INFO_HIS_N.PROMISE_DATE);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_PACK_INFO_HIS_N.INCLUDE_INSPECTION);
            sqlstm.sqhstl[32] = (unsigned int  )241;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_TYPE);
            sqlstm.sqhstl[33] = (unsigned int  )241;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_MESH);
            sqlstm.sqhstl[34] = (unsigned int  )241;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_PACK_INFO_HIS_N.LINE_DESC);
            sqlstm.sqhstl[35] = (unsigned int  )241;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_PACK_INFO_HIS_N.ORDER_UNIT);
            sqlstm.sqhstl[36] = (unsigned int  )4;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_PACK_INFO_HIS_N.CURRENCY_CODE);
            sqlstm.sqhstl[37] = (unsigned int  )16;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDERED_QTY);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(IF_PACK_INFO_HIS_N.SHIPED_QTY);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(IF_PACK_INFO_HIS_N.CANCELED_QTY);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE_KR);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_PACK_INFO_HIS_N.ALLOCATE_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )241;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO_NO);
            sqlstm.sqhstl[44] = (unsigned int  )241;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_PACK_INFO_HIS_N.CUST_ITME_NAME);
            sqlstm.sqhstl[45] = (unsigned int  )241;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(IF_PACK_INFO_HIS_N.CUST_ITEM_TYPE);
            sqlstm.sqhstl[46] = (unsigned int  )241;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(IF_PACK_INFO_HIS_N.REST);
            sqlstm.sqhstl[47] = (unsigned int  )241;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO_LINE);
            sqlstm.sqhstl[48] = (unsigned int  )241;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(IF_PACK_INFO_HIS_N.FORMAT_ID);
            sqlstm.sqhstl[49] = (unsigned int  )241;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO);
            sqlstm.sqhstl[50] = (unsigned int  )241;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(IF_PACK_INFO_HIS_N.PO_GUBUN);
            sqlstm.sqhstl[51] = (unsigned int  )241;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(IF_PACK_INFO_HIS_N.TRAN_FLAG);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_GROUP_ID);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_2);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_3);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_4);
            sqlstm.sqhstl[56] = (unsigned int  )51;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_5);
            sqlstm.sqhstl[57] = (unsigned int  )51;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_6);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_7);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_8);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_9);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_10);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(IF_PACK_INFO_HIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(IF_PACK_INFO_HIS_N.CREATE_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(IF_PACK_INFO_HIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(IF_PACK_INFO_HIS_N.UPDATE_TIME);
            sqlstm.sqhstl[66] = (unsigned int  )15;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_SEQ);
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
        DBU_del_null_if_pack_info_his(&IF_PACK_INFO_HIS_N, IF_PACK_INFO_HIS);
    }

    DB_stop_query_timer("DBU_select_if_pack_info_his", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_if_pack_info_his_for_update(int sel_type, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_PACK_INFO_HIS_N_TAG IF_PACK_INFO_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_pack_info_his(&IF_PACK_INFO_HIS_N, IF_PACK_INFO_HIS);
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
                    OU_ID,
                    ORG_ID,
                    ORG_CODE,
                    ORDER_HEADER_ID,
                    ORDER_NUMBER,
                    LINE_NUMBER,
                    ORDER_TYPE_ID,
                    ORDERED_DATE,
                    BOOKED_DATE,
                    ITEM_ID,
                    ITEM_CODE,
                    ITEM_DESC,
                    LABEL_NAME,
                    CUSTOMER_ID,
                    CUSTOMER_NUMBER,
                    CUSTOMER_NAME,
                    SHIP_TO_SITE_USE_ID,
                    SHIP_TO_NAME,
                    END_SHIP_TO_ID,
                    END_SHIP_TO_NAME,
                    DRAWING_FLAG,
                    PACKING_INSTRUCTIONS,
                    ORDER_TYPE,
                    REQUEST_DATE,
                    SCHEDULE_SHIP_DATE,
                    SCHEDULE_ARRIVAL_DATE,
                    PROMISE_DATE,
                    INCLUDE_INSPECTION,
                    LABEL_TYPE,
                    LABEL_MESH,
                    LINE_DESC,
                    ORDER_UNIT,
                    CURRENCY_CODE,
                    ORDERED_QTY,
                    SHIPED_QTY,
                    CANCELED_QTY,
                    UNIT_SELLING_PRICE,
                    UNIT_SELLING_PRICE_KR,
                    ALLOCATE_FLAG,
                    CUSTOMER_PO_NO,
                    CUST_ITME_NAME,
                    CUST_ITEM_TYPE,
                    REST,
                    CUSTOMER_PO_LINE,
                    FORMAT_ID,
                    CUSTOMER_PO,
                    PO_GUBUN,
                    TRAN_FLAG,
                    IF_GROUP_ID,
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
                    :IF_PACK_INFO_HIS_N.IF_SEQ,
                    :IF_PACK_INFO_HIS_N.IF_TIME,
                    :IF_PACK_INFO_HIS_N.IF_CODE,
                    :IF_PACK_INFO_HIS_N.IF_MSG,
                    :IF_PACK_INFO_HIS_N.FACTORY,
                    :IF_PACK_INFO_HIS_N.OU_ID,
                    :IF_PACK_INFO_HIS_N.ORG_ID,
                    :IF_PACK_INFO_HIS_N.ORG_CODE,
                    :IF_PACK_INFO_HIS_N.ORDER_HEADER_ID,
                    :IF_PACK_INFO_HIS_N.ORDER_NUMBER,
                    :IF_PACK_INFO_HIS_N.LINE_NUMBER,
                    :IF_PACK_INFO_HIS_N.ORDER_TYPE_ID,
                    :IF_PACK_INFO_HIS_N.ORDERED_DATE,
                    :IF_PACK_INFO_HIS_N.BOOKED_DATE,
                    :IF_PACK_INFO_HIS_N.ITEM_ID,
                    :IF_PACK_INFO_HIS_N.ITEM_CODE,
                    :IF_PACK_INFO_HIS_N.ITEM_DESC,
                    :IF_PACK_INFO_HIS_N.LABEL_NAME,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_ID,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_NUMBER,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_NAME,
                    :IF_PACK_INFO_HIS_N.SHIP_TO_SITE_USE_ID,
                    :IF_PACK_INFO_HIS_N.SHIP_TO_NAME,
                    :IF_PACK_INFO_HIS_N.END_SHIP_TO_ID,
                    :IF_PACK_INFO_HIS_N.END_SHIP_TO_NAME,
                    :IF_PACK_INFO_HIS_N.DRAWING_FLAG,
                    :IF_PACK_INFO_HIS_N.PACKING_INSTRUCTIONS,
                    :IF_PACK_INFO_HIS_N.ORDER_TYPE,
                    :IF_PACK_INFO_HIS_N.REQUEST_DATE,
                    :IF_PACK_INFO_HIS_N.SCHEDULE_SHIP_DATE,
                    :IF_PACK_INFO_HIS_N.SCHEDULE_ARRIVAL_DATE,
                    :IF_PACK_INFO_HIS_N.PROMISE_DATE,
                    :IF_PACK_INFO_HIS_N.INCLUDE_INSPECTION,
                    :IF_PACK_INFO_HIS_N.LABEL_TYPE,
                    :IF_PACK_INFO_HIS_N.LABEL_MESH,
                    :IF_PACK_INFO_HIS_N.LINE_DESC,
                    :IF_PACK_INFO_HIS_N.ORDER_UNIT,
                    :IF_PACK_INFO_HIS_N.CURRENCY_CODE,
                    :IF_PACK_INFO_HIS_N.ORDERED_QTY,
                    :IF_PACK_INFO_HIS_N.SHIPED_QTY,
                    :IF_PACK_INFO_HIS_N.CANCELED_QTY,
                    :IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE,
                    :IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE_KR,
                    :IF_PACK_INFO_HIS_N.ALLOCATE_FLAG,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_PO_NO,
                    :IF_PACK_INFO_HIS_N.CUST_ITME_NAME,
                    :IF_PACK_INFO_HIS_N.CUST_ITEM_TYPE,
                    :IF_PACK_INFO_HIS_N.REST,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_PO_LINE,
                    :IF_PACK_INFO_HIS_N.FORMAT_ID,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_PO,
                    :IF_PACK_INFO_HIS_N.PO_GUBUN,
                    :IF_PACK_INFO_HIS_N.TRAN_FLAG,
                    :IF_PACK_INFO_HIS_N.IF_GROUP_ID,
                    :IF_PACK_INFO_HIS_N.CMF_2,
                    :IF_PACK_INFO_HIS_N.CMF_3,
                    :IF_PACK_INFO_HIS_N.CMF_4,
                    :IF_PACK_INFO_HIS_N.CMF_5,
                    :IF_PACK_INFO_HIS_N.CMF_6,
                    :IF_PACK_INFO_HIS_N.CMF_7,
                    :IF_PACK_INFO_HIS_N.CMF_8,
                    :IF_PACK_INFO_HIS_N.CMF_9,
                    :IF_PACK_INFO_HIS_N.CMF_10,
                    :IF_PACK_INFO_HIS_N.CREATE_USER_ID,
                    :IF_PACK_INFO_HIS_N.CREATE_TIME,
                    :IF_PACK_INFO_HIS_N.UPDATE_USER_ID,
                    :IF_PACK_INFO_HIS_N.UPDATE_TIME
                FROM IF_PACK_INFO_HIS
                WHERE IF_SEQ = :IF_PACK_INFO_HIS_N.IF_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY ,OU_ID ,ORG_\
ID ,ORG_CODE ,ORDER_HEADER_ID ,ORDER_NUMBER ,LINE_NUMBER ,ORDER_TYPE_ID ,ORD\
ERED_DATE ,BOOKED_DATE ,ITEM_ID ,ITEM_CODE ,ITEM_DESC ,LABEL_NAME ,CUSTOMER_\
ID ,CUSTOMER_NUMBER ,CUSTOMER_NAME ,SHIP_TO_SITE_USE_ID ,SHIP_TO_NAME ,END_S\
HIP_TO_ID ,END_SHIP_TO_NAME ,DRAWING_FLAG ,PACKING_INSTRUCTIONS ,ORDER_TYPE \
,REQUEST_DATE ,SCHEDULE_SHIP_DATE ,SCHEDULE_ARRIVAL_DATE ,PROMISE_DATE ,INCL\
UDE_INSPECTION ,LABEL_TYPE ,LABEL_MESH ,LINE_DESC ,ORDER_UNIT ,CURRENCY_CODE\
 ,ORDERED_QTY ,SHIPED_QTY ,CANCELED_QTY ,UNIT_SELLING_PRICE ,UNIT_SELLING_PR\
ICE_KR ,ALLOCATE_FLAG ,CUSTOMER_PO_NO ,CUST_ITME_NAME ,CUST_ITEM_TYPE ,REST \
,CUSTOMER_PO_LINE ,FORMAT_ID ,CUSTOMER_PO ,PO_GUBUN ,TRAN_FLAG ,IF_GROUP_ID \
,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER\
_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:\
b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b");
            sqlstm.stmt = "32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,\
:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b\
57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66  from IF_PACK_INFO_HIS where \
IF_SEQ=:b0 for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )292;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_PACK_INFO_HIS_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_PACK_INFO_HIS_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_PACK_INFO_HIS_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_PACK_INFO_HIS_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_PACK_INFO_HIS_N.OU_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_PACK_INFO_HIS_N.ORG_ID);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(IF_PACK_INFO_HIS_N.ORG_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )4;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_HEADER_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_NUMBER);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(IF_PACK_INFO_HIS_N.LINE_NUMBER);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_TYPE_ID);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_PACK_INFO_HIS_N.ORDERED_DATE);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_PACK_INFO_HIS_N.BOOKED_DATE);
            sqlstm.sqhstl[13] = (unsigned int  )4;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(IF_PACK_INFO_HIS_N.ITEM_ID);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_PACK_INFO_HIS_N.ITEM_CODE);
            sqlstm.sqhstl[15] = (unsigned int  )41;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(IF_PACK_INFO_HIS_N.ITEM_DESC);
            sqlstm.sqhstl[16] = (unsigned int  )241;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_NAME);
            sqlstm.sqhstl[17] = (unsigned int  )1001;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_PACK_INFO_HIS_N.CUSTOMER_ID);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_NUMBER);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_NAME);
            sqlstm.sqhstl[20] = (unsigned int  )51;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(IF_PACK_INFO_HIS_N.SHIP_TO_SITE_USE_ID);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_PACK_INFO_HIS_N.SHIP_TO_NAME);
            sqlstm.sqhstl[22] = (unsigned int  )41;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(IF_PACK_INFO_HIS_N.END_SHIP_TO_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_PACK_INFO_HIS_N.END_SHIP_TO_NAME);
            sqlstm.sqhstl[24] = (unsigned int  )241;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(IF_PACK_INFO_HIS_N.DRAWING_FLAG);
            sqlstm.sqhstl[25] = (unsigned int  )2001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(IF_PACK_INFO_HIS_N.PACKING_INSTRUCTIONS);
            sqlstm.sqhstl[26] = (unsigned int  )2001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_PACK_INFO_HIS_N.ORDER_TYPE);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_PACK_INFO_HIS_N.REQUEST_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )15;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_PACK_INFO_HIS_N.SCHEDULE_SHIP_DATE);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_PACK_INFO_HIS_N.SCHEDULE_ARRIVAL_DATE);
            sqlstm.sqhstl[30] = (unsigned int  )15;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_PACK_INFO_HIS_N.PROMISE_DATE);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_PACK_INFO_HIS_N.INCLUDE_INSPECTION);
            sqlstm.sqhstl[32] = (unsigned int  )241;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_TYPE);
            sqlstm.sqhstl[33] = (unsigned int  )241;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_MESH);
            sqlstm.sqhstl[34] = (unsigned int  )241;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_PACK_INFO_HIS_N.LINE_DESC);
            sqlstm.sqhstl[35] = (unsigned int  )241;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_PACK_INFO_HIS_N.ORDER_UNIT);
            sqlstm.sqhstl[36] = (unsigned int  )4;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_PACK_INFO_HIS_N.CURRENCY_CODE);
            sqlstm.sqhstl[37] = (unsigned int  )16;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDERED_QTY);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(IF_PACK_INFO_HIS_N.SHIPED_QTY);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(IF_PACK_INFO_HIS_N.CANCELED_QTY);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE_KR);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_PACK_INFO_HIS_N.ALLOCATE_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )241;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO_NO);
            sqlstm.sqhstl[44] = (unsigned int  )241;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_PACK_INFO_HIS_N.CUST_ITME_NAME);
            sqlstm.sqhstl[45] = (unsigned int  )241;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(IF_PACK_INFO_HIS_N.CUST_ITEM_TYPE);
            sqlstm.sqhstl[46] = (unsigned int  )241;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(IF_PACK_INFO_HIS_N.REST);
            sqlstm.sqhstl[47] = (unsigned int  )241;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO_LINE);
            sqlstm.sqhstl[48] = (unsigned int  )241;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(IF_PACK_INFO_HIS_N.FORMAT_ID);
            sqlstm.sqhstl[49] = (unsigned int  )241;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO);
            sqlstm.sqhstl[50] = (unsigned int  )241;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(IF_PACK_INFO_HIS_N.PO_GUBUN);
            sqlstm.sqhstl[51] = (unsigned int  )241;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(IF_PACK_INFO_HIS_N.TRAN_FLAG);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_GROUP_ID);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_2);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_3);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_4);
            sqlstm.sqhstl[56] = (unsigned int  )51;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_5);
            sqlstm.sqhstl[57] = (unsigned int  )51;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_6);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_7);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_8);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_9);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_10);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(IF_PACK_INFO_HIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(IF_PACK_INFO_HIS_N.CREATE_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(IF_PACK_INFO_HIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(IF_PACK_INFO_HIS_N.UPDATE_TIME);
            sqlstm.sqhstl[66] = (unsigned int  )15;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_SEQ);
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
        DBU_del_null_if_pack_info_his(&IF_PACK_INFO_HIS_N, IF_PACK_INFO_HIS);
    }

    DB_stop_query_timer("DBU_select_if_pack_info_his_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_if_pack_info_his_scalar(int sel_type, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_PACK_INFO_HIS_N_TAG IF_PACK_INFO_HIS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_pack_info_his(&IF_PACK_INFO_HIS_N, IF_PACK_INFO_HIS);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM IF_PACK_INFO_HIS
                WHERE IF_SEQ = :IF_PACK_INFO_HIS_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from IF_PACK_INFO_HIS\
 where IF_SEQ=:b1";
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
            sqlstm.sqhstv[1] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_SEQ);
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

    DB_stop_query_timer("DBU_select_if_pack_info_his_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_if_pack_info_his(int sel_type, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_PACK_INFO_HIS_N_TAG IF_PACK_INFO_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_pack_info_his(&IF_PACK_INFO_HIS_N, IF_PACK_INFO_HIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM IF_PACK_INFO_HIS
                WHERE IF_SEQ = :IF_PACK_INFO_HIS_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from IF_PACK_INFO_HIS  where IF_SEQ=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )602;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_SEQ);
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

    DB_stop_query_timer("DBU_delete_if_pack_info_his", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_if_pack_info_his(struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_PACK_INFO_HIS_N_TAG IF_PACK_INFO_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_pack_info_his(&IF_PACK_INFO_HIS_N, IF_PACK_INFO_HIS);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO IF_PACK_INFO_HIS( 
                    IF_SEQ, 
                    IF_TIME, 
                    IF_CODE, 
                    IF_MSG, 
                    FACTORY, 
                    OU_ID, 
                    ORG_ID, 
                    ORG_CODE, 
                    ORDER_HEADER_ID, 
                    ORDER_NUMBER, 
                    LINE_NUMBER, 
                    ORDER_TYPE_ID, 
                    ORDERED_DATE, 
                    BOOKED_DATE, 
                    ITEM_ID, 
                    ITEM_CODE, 
                    ITEM_DESC, 
                    LABEL_NAME, 
                    CUSTOMER_ID, 
                    CUSTOMER_NUMBER, 
                    CUSTOMER_NAME, 
                    SHIP_TO_SITE_USE_ID, 
                    SHIP_TO_NAME, 
                    END_SHIP_TO_ID, 
                    END_SHIP_TO_NAME, 
                    DRAWING_FLAG, 
                    PACKING_INSTRUCTIONS, 
                    ORDER_TYPE, 
                    REQUEST_DATE, 
                    SCHEDULE_SHIP_DATE, 
                    SCHEDULE_ARRIVAL_DATE, 
                    PROMISE_DATE, 
                    INCLUDE_INSPECTION, 
                    LABEL_TYPE, 
                    LABEL_MESH, 
                    LINE_DESC, 
                    ORDER_UNIT, 
                    CURRENCY_CODE, 
                    ORDERED_QTY, 
                    SHIPED_QTY, 
                    CANCELED_QTY, 
                    UNIT_SELLING_PRICE, 
                    UNIT_SELLING_PRICE_KR, 
                    ALLOCATE_FLAG, 
                    CUSTOMER_PO_NO, 
                    CUST_ITME_NAME, 
                    CUST_ITEM_TYPE, 
                    REST, 
                    CUSTOMER_PO_LINE, 
                    FORMAT_ID, 
                    CUSTOMER_PO, 
                    PO_GUBUN, 
                    TRAN_FLAG, 
                    IF_GROUP_ID, 
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
                    :IF_PACK_INFO_HIS_N.IF_SEQ,
                    :IF_PACK_INFO_HIS_N.IF_TIME,
                    :IF_PACK_INFO_HIS_N.IF_CODE,
                    :IF_PACK_INFO_HIS_N.IF_MSG,
                    :IF_PACK_INFO_HIS_N.FACTORY,
                    :IF_PACK_INFO_HIS_N.OU_ID,
                    :IF_PACK_INFO_HIS_N.ORG_ID,
                    :IF_PACK_INFO_HIS_N.ORG_CODE,
                    :IF_PACK_INFO_HIS_N.ORDER_HEADER_ID,
                    :IF_PACK_INFO_HIS_N.ORDER_NUMBER,
                    :IF_PACK_INFO_HIS_N.LINE_NUMBER,
                    :IF_PACK_INFO_HIS_N.ORDER_TYPE_ID,
                    :IF_PACK_INFO_HIS_N.ORDERED_DATE,
                    :IF_PACK_INFO_HIS_N.BOOKED_DATE,
                    :IF_PACK_INFO_HIS_N.ITEM_ID,
                    :IF_PACK_INFO_HIS_N.ITEM_CODE,
                    :IF_PACK_INFO_HIS_N.ITEM_DESC,
                    :IF_PACK_INFO_HIS_N.LABEL_NAME,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_ID,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_NUMBER,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_NAME,
                    :IF_PACK_INFO_HIS_N.SHIP_TO_SITE_USE_ID,
                    :IF_PACK_INFO_HIS_N.SHIP_TO_NAME,
                    :IF_PACK_INFO_HIS_N.END_SHIP_TO_ID,
                    :IF_PACK_INFO_HIS_N.END_SHIP_TO_NAME,
                    :IF_PACK_INFO_HIS_N.DRAWING_FLAG,
                    :IF_PACK_INFO_HIS_N.PACKING_INSTRUCTIONS,
                    :IF_PACK_INFO_HIS_N.ORDER_TYPE,
                    :IF_PACK_INFO_HIS_N.REQUEST_DATE,
                    :IF_PACK_INFO_HIS_N.SCHEDULE_SHIP_DATE,
                    :IF_PACK_INFO_HIS_N.SCHEDULE_ARRIVAL_DATE,
                    :IF_PACK_INFO_HIS_N.PROMISE_DATE,
                    :IF_PACK_INFO_HIS_N.INCLUDE_INSPECTION,
                    :IF_PACK_INFO_HIS_N.LABEL_TYPE,
                    :IF_PACK_INFO_HIS_N.LABEL_MESH,
                    :IF_PACK_INFO_HIS_N.LINE_DESC,
                    :IF_PACK_INFO_HIS_N.ORDER_UNIT,
                    :IF_PACK_INFO_HIS_N.CURRENCY_CODE,
                    :IF_PACK_INFO_HIS_N.ORDERED_QTY,
                    :IF_PACK_INFO_HIS_N.SHIPED_QTY,
                    :IF_PACK_INFO_HIS_N.CANCELED_QTY,
                    :IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE,
                    :IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE_KR,
                    :IF_PACK_INFO_HIS_N.ALLOCATE_FLAG,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_PO_NO,
                    :IF_PACK_INFO_HIS_N.CUST_ITME_NAME,
                    :IF_PACK_INFO_HIS_N.CUST_ITEM_TYPE,
                    :IF_PACK_INFO_HIS_N.REST,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_PO_LINE,
                    :IF_PACK_INFO_HIS_N.FORMAT_ID,
                    :IF_PACK_INFO_HIS_N.CUSTOMER_PO,
                    :IF_PACK_INFO_HIS_N.PO_GUBUN,
                    :IF_PACK_INFO_HIS_N.TRAN_FLAG,
                    :IF_PACK_INFO_HIS_N.IF_GROUP_ID,
                    :IF_PACK_INFO_HIS_N.CMF_2,
                    :IF_PACK_INFO_HIS_N.CMF_3,
                    :IF_PACK_INFO_HIS_N.CMF_4,
                    :IF_PACK_INFO_HIS_N.CMF_5,
                    :IF_PACK_INFO_HIS_N.CMF_6,
                    :IF_PACK_INFO_HIS_N.CMF_7,
                    :IF_PACK_INFO_HIS_N.CMF_8,
                    :IF_PACK_INFO_HIS_N.CMF_9,
                    :IF_PACK_INFO_HIS_N.CMF_10,
                    :IF_PACK_INFO_HIS_N.CREATE_USER_ID,
                    :IF_PACK_INFO_HIS_N.CREATE_TIME,
                    :IF_PACK_INFO_HIS_N.UPDATE_USER_ID,
                    :IF_PACK_INFO_HIS_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 68;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into IF_PACK_INFO_HIS (IF_SEQ,IF_TIME,IF_CODE,IF_MSG,FACTORY,O\
U_ID,ORG_ID,ORG_CODE,ORDER_HEADER_ID,ORDER_NUMBER,LINE_NUMBER,ORDER_TYPE_ID,\
ORDERED_DATE,BOOKED_DATE,ITEM_ID,ITEM_CODE,ITEM_DESC,LABEL_NAME,CUSTOMER_ID,\
CUSTOMER_NUMBER,CUSTOMER_NAME,SHIP_TO_SITE_USE_ID,SHIP_TO_NAME,END_SHIP_TO_I\
D,END_SHIP_TO_NAME,DRAWING_FLAG,PACKING_INSTRUCTIONS,ORDER_TYPE,REQUEST_DATE\
,SCHEDULE_SHIP_DATE,SCHEDULE_ARRIVAL_DATE,PROMISE_DATE,INCLUDE_INSPECTION,LA\
BEL_TYPE,LABEL_MESH,LINE_DESC,ORDER_UNIT,CURRENCY_CODE,ORDERED_QTY,SHIPED_QT\
Y,CANCELED_QTY,UNIT_SELLING_PRICE,UNIT_SELLING_PRICE_KR,ALLOCATE_FLAG,CUSTOM\
ER_PO_NO,CUST_ITME_NAME,CUST_ITEM_TYPE,REST,CUSTOMER_PO_LINE,FORMAT_ID,CUSTO\
MER_PO,PO_GUBUN,TRAN_FLAG,IF_GROUP_ID,CMF_2,CMF_3,CMF_4,CMF_5,CMF_6,CMF_7,CM\
F_8,CMF_9,CMF_10,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) valu\
es (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b\
16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b3\
1,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:");
    sqlstm.stmt = "b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b\
51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66\
)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )621;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_SEQ);
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(IF_PACK_INFO_HIS_N.IF_TIME);
    sqlstm.sqhstl[1] = (unsigned int  )15;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(IF_PACK_INFO_HIS_N.IF_CODE);
    sqlstm.sqhstl[2] = (unsigned int  )2;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(IF_PACK_INFO_HIS_N.IF_MSG);
    sqlstm.sqhstl[3] = (unsigned int  )201;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(IF_PACK_INFO_HIS_N.FACTORY);
    sqlstm.sqhstl[4] = (unsigned int  )11;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)&(IF_PACK_INFO_HIS_N.OU_ID);
    sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)&(IF_PACK_INFO_HIS_N.ORG_ID);
    sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(IF_PACK_INFO_HIS_N.ORG_CODE);
    sqlstm.sqhstl[7] = (unsigned int  )4;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_HEADER_ID);
    sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_NUMBER);
    sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)&(IF_PACK_INFO_HIS_N.LINE_NUMBER);
    sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_TYPE_ID);
    sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(IF_PACK_INFO_HIS_N.ORDERED_DATE);
    sqlstm.sqhstl[12] = (unsigned int  )15;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(IF_PACK_INFO_HIS_N.BOOKED_DATE);
    sqlstm.sqhstl[13] = (unsigned int  )4;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)&(IF_PACK_INFO_HIS_N.ITEM_ID);
    sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(IF_PACK_INFO_HIS_N.ITEM_CODE);
    sqlstm.sqhstl[15] = (unsigned int  )41;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(IF_PACK_INFO_HIS_N.ITEM_DESC);
    sqlstm.sqhstl[16] = (unsigned int  )241;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_NAME);
    sqlstm.sqhstl[17] = (unsigned int  )1001;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)&(IF_PACK_INFO_HIS_N.CUSTOMER_ID);
    sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_NUMBER);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_NAME);
    sqlstm.sqhstl[20] = (unsigned int  )51;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)&(IF_PACK_INFO_HIS_N.SHIP_TO_SITE_USE_ID);
    sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(IF_PACK_INFO_HIS_N.SHIP_TO_NAME);
    sqlstm.sqhstl[22] = (unsigned int  )41;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)&(IF_PACK_INFO_HIS_N.END_SHIP_TO_ID);
    sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(IF_PACK_INFO_HIS_N.END_SHIP_TO_NAME);
    sqlstm.sqhstl[24] = (unsigned int  )241;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(IF_PACK_INFO_HIS_N.DRAWING_FLAG);
    sqlstm.sqhstl[25] = (unsigned int  )2001;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(IF_PACK_INFO_HIS_N.PACKING_INSTRUCTIONS);
    sqlstm.sqhstl[26] = (unsigned int  )2001;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(IF_PACK_INFO_HIS_N.ORDER_TYPE);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(IF_PACK_INFO_HIS_N.REQUEST_DATE);
    sqlstm.sqhstl[28] = (unsigned int  )15;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(IF_PACK_INFO_HIS_N.SCHEDULE_SHIP_DATE);
    sqlstm.sqhstl[29] = (unsigned int  )15;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(IF_PACK_INFO_HIS_N.SCHEDULE_ARRIVAL_DATE);
    sqlstm.sqhstl[30] = (unsigned int  )15;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(IF_PACK_INFO_HIS_N.PROMISE_DATE);
    sqlstm.sqhstl[31] = (unsigned int  )15;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(IF_PACK_INFO_HIS_N.INCLUDE_INSPECTION);
    sqlstm.sqhstl[32] = (unsigned int  )241;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_TYPE);
    sqlstm.sqhstl[33] = (unsigned int  )241;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_MESH);
    sqlstm.sqhstl[34] = (unsigned int  )241;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(IF_PACK_INFO_HIS_N.LINE_DESC);
    sqlstm.sqhstl[35] = (unsigned int  )241;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(IF_PACK_INFO_HIS_N.ORDER_UNIT);
    sqlstm.sqhstl[36] = (unsigned int  )4;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(IF_PACK_INFO_HIS_N.CURRENCY_CODE);
    sqlstm.sqhstl[37] = (unsigned int  )16;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDERED_QTY);
    sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)&(IF_PACK_INFO_HIS_N.SHIPED_QTY);
    sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)&(IF_PACK_INFO_HIS_N.CANCELED_QTY);
    sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)&(IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE);
    sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)&(IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE_KR);
    sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(IF_PACK_INFO_HIS_N.ALLOCATE_FLAG);
    sqlstm.sqhstl[43] = (unsigned int  )241;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO_NO);
    sqlstm.sqhstl[44] = (unsigned int  )241;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(IF_PACK_INFO_HIS_N.CUST_ITME_NAME);
    sqlstm.sqhstl[45] = (unsigned int  )241;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(IF_PACK_INFO_HIS_N.CUST_ITEM_TYPE);
    sqlstm.sqhstl[46] = (unsigned int  )241;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(IF_PACK_INFO_HIS_N.REST);
    sqlstm.sqhstl[47] = (unsigned int  )241;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO_LINE);
    sqlstm.sqhstl[48] = (unsigned int  )241;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(IF_PACK_INFO_HIS_N.FORMAT_ID);
    sqlstm.sqhstl[49] = (unsigned int  )241;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO);
    sqlstm.sqhstl[50] = (unsigned int  )241;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(IF_PACK_INFO_HIS_N.PO_GUBUN);
    sqlstm.sqhstl[51] = (unsigned int  )241;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(IF_PACK_INFO_HIS_N.TRAN_FLAG);
    sqlstm.sqhstl[52] = (unsigned int  )2;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_GROUP_ID);
    sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_2);
    sqlstm.sqhstl[54] = (unsigned int  )51;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_3);
    sqlstm.sqhstl[55] = (unsigned int  )51;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_4);
    sqlstm.sqhstl[56] = (unsigned int  )51;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_5);
    sqlstm.sqhstl[57] = (unsigned int  )51;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_6);
    sqlstm.sqhstl[58] = (unsigned int  )51;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_7);
    sqlstm.sqhstl[59] = (unsigned int  )51;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_8);
    sqlstm.sqhstl[60] = (unsigned int  )51;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_9);
    sqlstm.sqhstl[61] = (unsigned int  )51;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_10);
    sqlstm.sqhstl[62] = (unsigned int  )51;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(IF_PACK_INFO_HIS_N.CREATE_USER_ID);
    sqlstm.sqhstl[63] = (unsigned int  )21;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(IF_PACK_INFO_HIS_N.CREATE_TIME);
    sqlstm.sqhstl[64] = (unsigned int  )15;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(IF_PACK_INFO_HIS_N.UPDATE_USER_ID);
    sqlstm.sqhstl[65] = (unsigned int  )21;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(IF_PACK_INFO_HIS_N.UPDATE_TIME);
    sqlstm.sqhstl[66] = (unsigned int  )15;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_if_pack_info_his", 0);
}


/* SQL UPDATE Function */
void DBU_update_if_pack_info_his(int sel_type, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_PACK_INFO_HIS_N_TAG IF_PACK_INFO_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_pack_info_his(&IF_PACK_INFO_HIS_N, IF_PACK_INFO_HIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE IF_PACK_INFO_HIS SET
                    IF_TIME = :IF_PACK_INFO_HIS_N.IF_TIME,
                    IF_CODE = :IF_PACK_INFO_HIS_N.IF_CODE,
                    IF_MSG = :IF_PACK_INFO_HIS_N.IF_MSG,
                    FACTORY = :IF_PACK_INFO_HIS_N.FACTORY,
                    OU_ID = :IF_PACK_INFO_HIS_N.OU_ID,
                    ORG_ID = :IF_PACK_INFO_HIS_N.ORG_ID,
                    ORG_CODE = :IF_PACK_INFO_HIS_N.ORG_CODE,
                    ORDER_HEADER_ID = :IF_PACK_INFO_HIS_N.ORDER_HEADER_ID,
                    ORDER_NUMBER = :IF_PACK_INFO_HIS_N.ORDER_NUMBER,
                    LINE_NUMBER = :IF_PACK_INFO_HIS_N.LINE_NUMBER,
                    ORDER_TYPE_ID = :IF_PACK_INFO_HIS_N.ORDER_TYPE_ID,
                    ORDERED_DATE = :IF_PACK_INFO_HIS_N.ORDERED_DATE,
                    BOOKED_DATE = :IF_PACK_INFO_HIS_N.BOOKED_DATE,
                    ITEM_ID = :IF_PACK_INFO_HIS_N.ITEM_ID,
                    ITEM_CODE = :IF_PACK_INFO_HIS_N.ITEM_CODE,
                    ITEM_DESC = :IF_PACK_INFO_HIS_N.ITEM_DESC,
                    LABEL_NAME = :IF_PACK_INFO_HIS_N.LABEL_NAME,
                    CUSTOMER_ID = :IF_PACK_INFO_HIS_N.CUSTOMER_ID,
                    CUSTOMER_NUMBER = :IF_PACK_INFO_HIS_N.CUSTOMER_NUMBER,
                    CUSTOMER_NAME = :IF_PACK_INFO_HIS_N.CUSTOMER_NAME,
                    SHIP_TO_SITE_USE_ID = :IF_PACK_INFO_HIS_N.SHIP_TO_SITE_USE_ID,
                    SHIP_TO_NAME = :IF_PACK_INFO_HIS_N.SHIP_TO_NAME,
                    END_SHIP_TO_ID = :IF_PACK_INFO_HIS_N.END_SHIP_TO_ID,
                    END_SHIP_TO_NAME = :IF_PACK_INFO_HIS_N.END_SHIP_TO_NAME,
                    DRAWING_FLAG = :IF_PACK_INFO_HIS_N.DRAWING_FLAG,
                    PACKING_INSTRUCTIONS = :IF_PACK_INFO_HIS_N.PACKING_INSTRUCTIONS,
                    ORDER_TYPE = :IF_PACK_INFO_HIS_N.ORDER_TYPE,
                    REQUEST_DATE = :IF_PACK_INFO_HIS_N.REQUEST_DATE,
                    SCHEDULE_SHIP_DATE = :IF_PACK_INFO_HIS_N.SCHEDULE_SHIP_DATE,
                    SCHEDULE_ARRIVAL_DATE = :IF_PACK_INFO_HIS_N.SCHEDULE_ARRIVAL_DATE,
                    PROMISE_DATE = :IF_PACK_INFO_HIS_N.PROMISE_DATE,
                    INCLUDE_INSPECTION = :IF_PACK_INFO_HIS_N.INCLUDE_INSPECTION,
                    LABEL_TYPE = :IF_PACK_INFO_HIS_N.LABEL_TYPE,
                    LABEL_MESH = :IF_PACK_INFO_HIS_N.LABEL_MESH,
                    LINE_DESC = :IF_PACK_INFO_HIS_N.LINE_DESC,
                    ORDER_UNIT = :IF_PACK_INFO_HIS_N.ORDER_UNIT,
                    CURRENCY_CODE = :IF_PACK_INFO_HIS_N.CURRENCY_CODE,
                    ORDERED_QTY = :IF_PACK_INFO_HIS_N.ORDERED_QTY,
                    SHIPED_QTY = :IF_PACK_INFO_HIS_N.SHIPED_QTY,
                    CANCELED_QTY = :IF_PACK_INFO_HIS_N.CANCELED_QTY,
                    UNIT_SELLING_PRICE = :IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE,
                    UNIT_SELLING_PRICE_KR = :IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE_KR,
                    ALLOCATE_FLAG = :IF_PACK_INFO_HIS_N.ALLOCATE_FLAG,
                    CUSTOMER_PO_NO = :IF_PACK_INFO_HIS_N.CUSTOMER_PO_NO,
                    CUST_ITME_NAME = :IF_PACK_INFO_HIS_N.CUST_ITME_NAME,
                    CUST_ITEM_TYPE = :IF_PACK_INFO_HIS_N.CUST_ITEM_TYPE,
                    REST = :IF_PACK_INFO_HIS_N.REST,
                    CUSTOMER_PO_LINE = :IF_PACK_INFO_HIS_N.CUSTOMER_PO_LINE,
                    FORMAT_ID = :IF_PACK_INFO_HIS_N.FORMAT_ID,
                    CUSTOMER_PO = :IF_PACK_INFO_HIS_N.CUSTOMER_PO,
                    PO_GUBUN = :IF_PACK_INFO_HIS_N.PO_GUBUN,
                    TRAN_FLAG = :IF_PACK_INFO_HIS_N.TRAN_FLAG,
                    IF_GROUP_ID = :IF_PACK_INFO_HIS_N.IF_GROUP_ID,
                    CMF_2 = :IF_PACK_INFO_HIS_N.CMF_2,
                    CMF_3 = :IF_PACK_INFO_HIS_N.CMF_3,
                    CMF_4 = :IF_PACK_INFO_HIS_N.CMF_4,
                    CMF_5 = :IF_PACK_INFO_HIS_N.CMF_5,
                    CMF_6 = :IF_PACK_INFO_HIS_N.CMF_6,
                    CMF_7 = :IF_PACK_INFO_HIS_N.CMF_7,
                    CMF_8 = :IF_PACK_INFO_HIS_N.CMF_8,
                    CMF_9 = :IF_PACK_INFO_HIS_N.CMF_9,
                    CMF_10 = :IF_PACK_INFO_HIS_N.CMF_10,
                    CREATE_USER_ID = :IF_PACK_INFO_HIS_N.CREATE_USER_ID,
                    CREATE_TIME = :IF_PACK_INFO_HIS_N.CREATE_TIME,
                    UPDATE_USER_ID = :IF_PACK_INFO_HIS_N.UPDATE_USER_ID,
                    UPDATE_TIME = :IF_PACK_INFO_HIS_N.UPDATE_TIME
                WHERE IF_SEQ = :IF_PACK_INFO_HIS_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update IF_PACK_INFO_HIS  set IF_TIME=:b0,IF_CODE=:b1,IF_MSG=:\
b2,FACTORY=:b3,OU_ID=:b4,ORG_ID=:b5,ORG_CODE=:b6,ORDER_HEADER_ID=:b7,ORDER_N\
UMBER=:b8,LINE_NUMBER=:b9,ORDER_TYPE_ID=:b10,ORDERED_DATE=:b11,BOOKED_DATE=:\
b12,ITEM_ID=:b13,ITEM_CODE=:b14,ITEM_DESC=:b15,LABEL_NAME=:b16,CUSTOMER_ID=:\
b17,CUSTOMER_NUMBER=:b18,CUSTOMER_NAME=:b19,SHIP_TO_SITE_USE_ID=:b20,SHIP_TO\
_NAME=:b21,END_SHIP_TO_ID=:b22,END_SHIP_TO_NAME=:b23,DRAWING_FLAG=:b24,PACKI\
NG_INSTRUCTIONS=:b25,ORDER_TYPE=:b26,REQUEST_DATE=:b27,SCHEDULE_SHIP_DATE=:b\
28,SCHEDULE_ARRIVAL_DATE=:b29,PROMISE_DATE=:b30,INCLUDE_INSPECTION=:b31,LABE\
L_TYPE=:b32,LABEL_MESH=:b33,LINE_DESC=:b34,ORDER_UNIT=:b35,CURRENCY_CODE=:b3\
6,ORDERED_QTY=:b37,SHIPED_QTY=:b38,CANCELED_QTY=:b39,UNIT_SELLING_PRICE=:b40\
,UNIT_SELLING_PRICE_KR=:b41,ALLOCATE_FLAG=:b42,CUSTOMER_PO_NO=:b43,CUST_ITME\
_NAME=:b44,CUST_ITEM_TYPE=:b45,REST=:b46,CUSTOMER_PO_LINE=:b47,FORMAT_ID=:b4\
8,CUSTOMER_PO=:b49,PO_GUBUN=:b50,TRAN_FLAG=:b51,IF_GROUP_ID=:b52,CMF_2=:b53,\
CMF_3=:b54,CMF_4=:b55,CMF_5=:b56,CMF_6=:b57,CMF_7=:");
            sqlstm.stmt = "b58,CMF_8=:b59,CMF_9=:b60,CMF_10=:b61,CREATE_USE\
R_ID=:b62,CREATE_TIME=:b63,UPDATE_USER_ID=:b64,UPDATE_TIME=:b65 where IF_SEQ=\
:b66";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )904;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(IF_PACK_INFO_HIS_N.IF_TIME);
            sqlstm.sqhstl[0] = (unsigned int  )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_PACK_INFO_HIS_N.IF_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_PACK_INFO_HIS_N.IF_MSG);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_PACK_INFO_HIS_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(IF_PACK_INFO_HIS_N.OU_ID);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_PACK_INFO_HIS_N.ORG_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(IF_PACK_INFO_HIS_N.ORG_CODE);
            sqlstm.sqhstl[6] = (unsigned int  )4;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_HEADER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_NUMBER);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_PACK_INFO_HIS_N.LINE_NUMBER);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_TYPE_ID);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_PACK_INFO_HIS_N.ORDERED_DATE);
            sqlstm.sqhstl[11] = (unsigned int  )15;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_PACK_INFO_HIS_N.BOOKED_DATE);
            sqlstm.sqhstl[12] = (unsigned int  )4;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(IF_PACK_INFO_HIS_N.ITEM_ID);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_PACK_INFO_HIS_N.ITEM_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )41;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_PACK_INFO_HIS_N.ITEM_DESC);
            sqlstm.sqhstl[15] = (unsigned int  )241;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_NAME);
            sqlstm.sqhstl[16] = (unsigned int  )1001;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(IF_PACK_INFO_HIS_N.CUSTOMER_ID);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_NUMBER);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_NAME);
            sqlstm.sqhstl[19] = (unsigned int  )51;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(IF_PACK_INFO_HIS_N.SHIP_TO_SITE_USE_ID);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_PACK_INFO_HIS_N.SHIP_TO_NAME);
            sqlstm.sqhstl[21] = (unsigned int  )41;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(IF_PACK_INFO_HIS_N.END_SHIP_TO_ID);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(IF_PACK_INFO_HIS_N.END_SHIP_TO_NAME);
            sqlstm.sqhstl[23] = (unsigned int  )241;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_PACK_INFO_HIS_N.DRAWING_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2001;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(IF_PACK_INFO_HIS_N.PACKING_INSTRUCTIONS);
            sqlstm.sqhstl[25] = (unsigned int  )2001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(IF_PACK_INFO_HIS_N.ORDER_TYPE);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_PACK_INFO_HIS_N.REQUEST_DATE);
            sqlstm.sqhstl[27] = (unsigned int  )15;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_PACK_INFO_HIS_N.SCHEDULE_SHIP_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )15;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_PACK_INFO_HIS_N.SCHEDULE_ARRIVAL_DATE);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_PACK_INFO_HIS_N.PROMISE_DATE);
            sqlstm.sqhstl[30] = (unsigned int  )15;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_PACK_INFO_HIS_N.INCLUDE_INSPECTION);
            sqlstm.sqhstl[31] = (unsigned int  )241;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_TYPE);
            sqlstm.sqhstl[32] = (unsigned int  )241;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_MESH);
            sqlstm.sqhstl[33] = (unsigned int  )241;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_PACK_INFO_HIS_N.LINE_DESC);
            sqlstm.sqhstl[34] = (unsigned int  )241;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_PACK_INFO_HIS_N.ORDER_UNIT);
            sqlstm.sqhstl[35] = (unsigned int  )4;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_PACK_INFO_HIS_N.CURRENCY_CODE);
            sqlstm.sqhstl[36] = (unsigned int  )16;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDERED_QTY);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(IF_PACK_INFO_HIS_N.SHIPED_QTY);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(IF_PACK_INFO_HIS_N.CANCELED_QTY);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE_KR);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_PACK_INFO_HIS_N.ALLOCATE_FLAG);
            sqlstm.sqhstl[42] = (unsigned int  )241;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO_NO);
            sqlstm.sqhstl[43] = (unsigned int  )241;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_PACK_INFO_HIS_N.CUST_ITME_NAME);
            sqlstm.sqhstl[44] = (unsigned int  )241;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_PACK_INFO_HIS_N.CUST_ITEM_TYPE);
            sqlstm.sqhstl[45] = (unsigned int  )241;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(IF_PACK_INFO_HIS_N.REST);
            sqlstm.sqhstl[46] = (unsigned int  )241;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO_LINE);
            sqlstm.sqhstl[47] = (unsigned int  )241;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(IF_PACK_INFO_HIS_N.FORMAT_ID);
            sqlstm.sqhstl[48] = (unsigned int  )241;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO);
            sqlstm.sqhstl[49] = (unsigned int  )241;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(IF_PACK_INFO_HIS_N.PO_GUBUN);
            sqlstm.sqhstl[50] = (unsigned int  )241;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(IF_PACK_INFO_HIS_N.TRAN_FLAG);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_GROUP_ID);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_2);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_3);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_4);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_5);
            sqlstm.sqhstl[56] = (unsigned int  )51;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_6);
            sqlstm.sqhstl[57] = (unsigned int  )51;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_7);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_8);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_9);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_10);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(IF_PACK_INFO_HIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(IF_PACK_INFO_HIS_N.CREATE_TIME);
            sqlstm.sqhstl[63] = (unsigned int  )15;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(IF_PACK_INFO_HIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(IF_PACK_INFO_HIS_N.UPDATE_TIME);
            sqlstm.sqhstl[65] = (unsigned int  )15;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_SEQ);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_if_pack_info_his", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_if_pack_info_his(int sel_type, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_PACK_INFO_HIS_N_TAG IF_PACK_INFO_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_pack_info_his(&IF_PACK_INFO_HIS_N, IF_PACK_INFO_HIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_IF_PACK_INFO_HIS_CUR_1 CURSOR FOR
                SELECT 
                    IF_SEQ,
                    IF_TIME,
                    IF_CODE,
                    IF_MSG,
                    FACTORY,
                    OU_ID,
                    ORG_ID,
                    ORG_CODE,
                    ORDER_HEADER_ID,
                    ORDER_NUMBER,
                    LINE_NUMBER,
                    ORDER_TYPE_ID,
                    ORDERED_DATE,
                    BOOKED_DATE,
                    ITEM_ID,
                    ITEM_CODE,
                    ITEM_DESC,
                    LABEL_NAME,
                    CUSTOMER_ID,
                    CUSTOMER_NUMBER,
                    CUSTOMER_NAME,
                    SHIP_TO_SITE_USE_ID,
                    SHIP_TO_NAME,
                    END_SHIP_TO_ID,
                    END_SHIP_TO_NAME,
                    DRAWING_FLAG,
                    PACKING_INSTRUCTIONS,
                    ORDER_TYPE,
                    REQUEST_DATE,
                    SCHEDULE_SHIP_DATE,
                    SCHEDULE_ARRIVAL_DATE,
                    PROMISE_DATE,
                    INCLUDE_INSPECTION,
                    LABEL_TYPE,
                    LABEL_MESH,
                    LINE_DESC,
                    ORDER_UNIT,
                    CURRENCY_CODE,
                    ORDERED_QTY,
                    SHIPED_QTY,
                    CANCELED_QTY,
                    UNIT_SELLING_PRICE,
                    UNIT_SELLING_PRICE_KR,
                    ALLOCATE_FLAG,
                    CUSTOMER_PO_NO,
                    CUST_ITME_NAME,
                    CUST_ITEM_TYPE,
                    REST,
                    CUSTOMER_PO_LINE,
                    FORMAT_ID,
                    CUSTOMER_PO,
                    PO_GUBUN,
                    TRAN_FLAG,
                    IF_GROUP_ID,
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
                FROM IF_PACK_INFO_HIS
                ORDER BY IF_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_IF_PACK_INFO_HIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1187;
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

    DB_stop_query_timer("DBU_open_if_pack_info_his", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_if_pack_info_his(int sel_type, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_PACK_INFO_HIS_N_TAG IF_PACK_INFO_HIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_IF_PACK_INFO_HIS_CUR_1 INTO
                :IF_PACK_INFO_HIS_N.IF_SEQ,
                :IF_PACK_INFO_HIS_N.IF_TIME,
                :IF_PACK_INFO_HIS_N.IF_CODE,
                :IF_PACK_INFO_HIS_N.IF_MSG,
                :IF_PACK_INFO_HIS_N.FACTORY,
                :IF_PACK_INFO_HIS_N.OU_ID,
                :IF_PACK_INFO_HIS_N.ORG_ID,
                :IF_PACK_INFO_HIS_N.ORG_CODE,
                :IF_PACK_INFO_HIS_N.ORDER_HEADER_ID,
                :IF_PACK_INFO_HIS_N.ORDER_NUMBER,
                :IF_PACK_INFO_HIS_N.LINE_NUMBER,
                :IF_PACK_INFO_HIS_N.ORDER_TYPE_ID,
                :IF_PACK_INFO_HIS_N.ORDERED_DATE,
                :IF_PACK_INFO_HIS_N.BOOKED_DATE,
                :IF_PACK_INFO_HIS_N.ITEM_ID,
                :IF_PACK_INFO_HIS_N.ITEM_CODE,
                :IF_PACK_INFO_HIS_N.ITEM_DESC,
                :IF_PACK_INFO_HIS_N.LABEL_NAME,
                :IF_PACK_INFO_HIS_N.CUSTOMER_ID,
                :IF_PACK_INFO_HIS_N.CUSTOMER_NUMBER,
                :IF_PACK_INFO_HIS_N.CUSTOMER_NAME,
                :IF_PACK_INFO_HIS_N.SHIP_TO_SITE_USE_ID,
                :IF_PACK_INFO_HIS_N.SHIP_TO_NAME,
                :IF_PACK_INFO_HIS_N.END_SHIP_TO_ID,
                :IF_PACK_INFO_HIS_N.END_SHIP_TO_NAME,
                :IF_PACK_INFO_HIS_N.DRAWING_FLAG,
                :IF_PACK_INFO_HIS_N.PACKING_INSTRUCTIONS,
                :IF_PACK_INFO_HIS_N.ORDER_TYPE,
                :IF_PACK_INFO_HIS_N.REQUEST_DATE,
                :IF_PACK_INFO_HIS_N.SCHEDULE_SHIP_DATE,
                :IF_PACK_INFO_HIS_N.SCHEDULE_ARRIVAL_DATE,
                :IF_PACK_INFO_HIS_N.PROMISE_DATE,
                :IF_PACK_INFO_HIS_N.INCLUDE_INSPECTION,
                :IF_PACK_INFO_HIS_N.LABEL_TYPE,
                :IF_PACK_INFO_HIS_N.LABEL_MESH,
                :IF_PACK_INFO_HIS_N.LINE_DESC,
                :IF_PACK_INFO_HIS_N.ORDER_UNIT,
                :IF_PACK_INFO_HIS_N.CURRENCY_CODE,
                :IF_PACK_INFO_HIS_N.ORDERED_QTY,
                :IF_PACK_INFO_HIS_N.SHIPED_QTY,
                :IF_PACK_INFO_HIS_N.CANCELED_QTY,
                :IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE,
                :IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE_KR,
                :IF_PACK_INFO_HIS_N.ALLOCATE_FLAG,
                :IF_PACK_INFO_HIS_N.CUSTOMER_PO_NO,
                :IF_PACK_INFO_HIS_N.CUST_ITME_NAME,
                :IF_PACK_INFO_HIS_N.CUST_ITEM_TYPE,
                :IF_PACK_INFO_HIS_N.REST,
                :IF_PACK_INFO_HIS_N.CUSTOMER_PO_LINE,
                :IF_PACK_INFO_HIS_N.FORMAT_ID,
                :IF_PACK_INFO_HIS_N.CUSTOMER_PO,
                :IF_PACK_INFO_HIS_N.PO_GUBUN,
                :IF_PACK_INFO_HIS_N.TRAN_FLAG,
                :IF_PACK_INFO_HIS_N.IF_GROUP_ID,
                :IF_PACK_INFO_HIS_N.CMF_2,
                :IF_PACK_INFO_HIS_N.CMF_3,
                :IF_PACK_INFO_HIS_N.CMF_4,
                :IF_PACK_INFO_HIS_N.CMF_5,
                :IF_PACK_INFO_HIS_N.CMF_6,
                :IF_PACK_INFO_HIS_N.CMF_7,
                :IF_PACK_INFO_HIS_N.CMF_8,
                :IF_PACK_INFO_HIS_N.CMF_9,
                :IF_PACK_INFO_HIS_N.CMF_10,
                :IF_PACK_INFO_HIS_N.CREATE_USER_ID,
                :IF_PACK_INFO_HIS_N.CREATE_TIME,
                :IF_PACK_INFO_HIS_N.UPDATE_USER_ID,
                :IF_PACK_INFO_HIS_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1202;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_PACK_INFO_HIS_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_PACK_INFO_HIS_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_PACK_INFO_HIS_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_PACK_INFO_HIS_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_PACK_INFO_HIS_N.OU_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_PACK_INFO_HIS_N.ORG_ID);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(IF_PACK_INFO_HIS_N.ORG_CODE);
            sqlstm.sqhstl[7] = (unsigned int  )4;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_HEADER_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_NUMBER);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(IF_PACK_INFO_HIS_N.LINE_NUMBER);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDER_TYPE_ID);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_PACK_INFO_HIS_N.ORDERED_DATE);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_PACK_INFO_HIS_N.BOOKED_DATE);
            sqlstm.sqhstl[13] = (unsigned int  )4;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(IF_PACK_INFO_HIS_N.ITEM_ID);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_PACK_INFO_HIS_N.ITEM_CODE);
            sqlstm.sqhstl[15] = (unsigned int  )41;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(IF_PACK_INFO_HIS_N.ITEM_DESC);
            sqlstm.sqhstl[16] = (unsigned int  )241;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_NAME);
            sqlstm.sqhstl[17] = (unsigned int  )1001;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_PACK_INFO_HIS_N.CUSTOMER_ID);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_NUMBER);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_NAME);
            sqlstm.sqhstl[20] = (unsigned int  )51;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(IF_PACK_INFO_HIS_N.SHIP_TO_SITE_USE_ID);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_PACK_INFO_HIS_N.SHIP_TO_NAME);
            sqlstm.sqhstl[22] = (unsigned int  )41;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(IF_PACK_INFO_HIS_N.END_SHIP_TO_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_PACK_INFO_HIS_N.END_SHIP_TO_NAME);
            sqlstm.sqhstl[24] = (unsigned int  )241;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(IF_PACK_INFO_HIS_N.DRAWING_FLAG);
            sqlstm.sqhstl[25] = (unsigned int  )2001;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(IF_PACK_INFO_HIS_N.PACKING_INSTRUCTIONS);
            sqlstm.sqhstl[26] = (unsigned int  )2001;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_PACK_INFO_HIS_N.ORDER_TYPE);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_PACK_INFO_HIS_N.REQUEST_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )15;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_PACK_INFO_HIS_N.SCHEDULE_SHIP_DATE);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_PACK_INFO_HIS_N.SCHEDULE_ARRIVAL_DATE);
            sqlstm.sqhstl[30] = (unsigned int  )15;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_PACK_INFO_HIS_N.PROMISE_DATE);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_PACK_INFO_HIS_N.INCLUDE_INSPECTION);
            sqlstm.sqhstl[32] = (unsigned int  )241;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_TYPE);
            sqlstm.sqhstl[33] = (unsigned int  )241;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_PACK_INFO_HIS_N.LABEL_MESH);
            sqlstm.sqhstl[34] = (unsigned int  )241;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_PACK_INFO_HIS_N.LINE_DESC);
            sqlstm.sqhstl[35] = (unsigned int  )241;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(IF_PACK_INFO_HIS_N.ORDER_UNIT);
            sqlstm.sqhstl[36] = (unsigned int  )4;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(IF_PACK_INFO_HIS_N.CURRENCY_CODE);
            sqlstm.sqhstl[37] = (unsigned int  )16;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(IF_PACK_INFO_HIS_N.ORDERED_QTY);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(IF_PACK_INFO_HIS_N.SHIPED_QTY);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(IF_PACK_INFO_HIS_N.CANCELED_QTY);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(IF_PACK_INFO_HIS_N.UNIT_SELLING_PRICE_KR);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_PACK_INFO_HIS_N.ALLOCATE_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )241;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO_NO);
            sqlstm.sqhstl[44] = (unsigned int  )241;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_PACK_INFO_HIS_N.CUST_ITME_NAME);
            sqlstm.sqhstl[45] = (unsigned int  )241;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(IF_PACK_INFO_HIS_N.CUST_ITEM_TYPE);
            sqlstm.sqhstl[46] = (unsigned int  )241;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(IF_PACK_INFO_HIS_N.REST);
            sqlstm.sqhstl[47] = (unsigned int  )241;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO_LINE);
            sqlstm.sqhstl[48] = (unsigned int  )241;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(IF_PACK_INFO_HIS_N.FORMAT_ID);
            sqlstm.sqhstl[49] = (unsigned int  )241;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(IF_PACK_INFO_HIS_N.CUSTOMER_PO);
            sqlstm.sqhstl[50] = (unsigned int  )241;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(IF_PACK_INFO_HIS_N.PO_GUBUN);
            sqlstm.sqhstl[51] = (unsigned int  )241;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(IF_PACK_INFO_HIS_N.TRAN_FLAG);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(IF_PACK_INFO_HIS_N.IF_GROUP_ID);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_2);
            sqlstm.sqhstl[54] = (unsigned int  )51;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_3);
            sqlstm.sqhstl[55] = (unsigned int  )51;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_4);
            sqlstm.sqhstl[56] = (unsigned int  )51;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_5);
            sqlstm.sqhstl[57] = (unsigned int  )51;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_6);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_7);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_8);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_9);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(IF_PACK_INFO_HIS_N.CMF_10);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(IF_PACK_INFO_HIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(IF_PACK_INFO_HIS_N.CREATE_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(IF_PACK_INFO_HIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(IF_PACK_INFO_HIS_N.UPDATE_TIME);
            sqlstm.sqhstl[66] = (unsigned int  )15;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
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
        DBU_del_null_if_pack_info_his(&IF_PACK_INFO_HIS_N, IF_PACK_INFO_HIS);
    }

    DB_stop_query_timer("DBU_fetch_if_pack_info_his", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_if_pack_info_his(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_IF_PACK_INFO_HIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 68;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1485;
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

    DB_stop_query_timer("DBU_close_if_pack_info_his", sel_type);
}


/* Initialize Function */
void DBU_init_if_pack_info_his(struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    /* memset by Space */
    memset(IF_PACK_INFO_HIS, ' ', sizeof(struct IF_PACK_INFO_HIS_TAG));
    
    IF_PACK_INFO_HIS->IF_SEQ = 0;
    IF_PACK_INFO_HIS->OU_ID = 0;
    IF_PACK_INFO_HIS->ORG_ID = 0;
    IF_PACK_INFO_HIS->ORDER_HEADER_ID = 0;
    IF_PACK_INFO_HIS->ORDER_NUMBER = 0;
    IF_PACK_INFO_HIS->LINE_NUMBER = 0;
    IF_PACK_INFO_HIS->ORDER_TYPE_ID = 0;
    IF_PACK_INFO_HIS->ITEM_ID = 0;
    IF_PACK_INFO_HIS->CUSTOMER_ID = 0;
    IF_PACK_INFO_HIS->SHIP_TO_SITE_USE_ID = 0;
    IF_PACK_INFO_HIS->END_SHIP_TO_ID = 0;
    IF_PACK_INFO_HIS->ORDERED_QTY = 0;
    IF_PACK_INFO_HIS->SHIPED_QTY = 0;
    IF_PACK_INFO_HIS->CANCELED_QTY = 0;
    IF_PACK_INFO_HIS->UNIT_SELLING_PRICE = 0;
    IF_PACK_INFO_HIS->UNIT_SELLING_PRICE_KR = 0;
    IF_PACK_INFO_HIS->IF_GROUP_ID = 0;
}


/* Add Null Function */
void DBU_add_null_if_pack_info_his(struct IF_PACK_INFO_HIS_N_TAG *IF_PACK_INFO_HIS_N, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    /* memset by NULL */
    memset(IF_PACK_INFO_HIS_N, '\0', sizeof(struct IF_PACK_INFO_HIS_N_TAG));
    
    IF_PACK_INFO_HIS_N->IF_SEQ = IF_PACK_INFO_HIS->IF_SEQ;
    MEMCPY_AN(IF_PACK_INFO_HIS_N->IF_TIME, IF_PACK_INFO_HIS->IF_TIME, sizeof(IF_PACK_INFO_HIS->IF_TIME));
    IF_PACK_INFO_HIS_N->IF_CODE[0] = IF_PACK_INFO_HIS->IF_CODE;
    MEMCPY_AN(IF_PACK_INFO_HIS_N->IF_MSG, IF_PACK_INFO_HIS->IF_MSG, sizeof(IF_PACK_INFO_HIS->IF_MSG));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->FACTORY, IF_PACK_INFO_HIS->FACTORY, sizeof(IF_PACK_INFO_HIS->FACTORY));
    IF_PACK_INFO_HIS_N->OU_ID = IF_PACK_INFO_HIS->OU_ID;
    IF_PACK_INFO_HIS_N->ORG_ID = IF_PACK_INFO_HIS->ORG_ID;
    MEMCPY_AN(IF_PACK_INFO_HIS_N->ORG_CODE, IF_PACK_INFO_HIS->ORG_CODE, sizeof(IF_PACK_INFO_HIS->ORG_CODE));
    IF_PACK_INFO_HIS_N->ORDER_HEADER_ID = IF_PACK_INFO_HIS->ORDER_HEADER_ID;
    IF_PACK_INFO_HIS_N->ORDER_NUMBER = IF_PACK_INFO_HIS->ORDER_NUMBER;
    IF_PACK_INFO_HIS_N->LINE_NUMBER = IF_PACK_INFO_HIS->LINE_NUMBER;
    IF_PACK_INFO_HIS_N->ORDER_TYPE_ID = IF_PACK_INFO_HIS->ORDER_TYPE_ID;
    MEMCPY_AN(IF_PACK_INFO_HIS_N->ORDERED_DATE, IF_PACK_INFO_HIS->ORDERED_DATE, sizeof(IF_PACK_INFO_HIS->ORDERED_DATE));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->BOOKED_DATE, IF_PACK_INFO_HIS->BOOKED_DATE, sizeof(IF_PACK_INFO_HIS->BOOKED_DATE));
    IF_PACK_INFO_HIS_N->ITEM_ID = IF_PACK_INFO_HIS->ITEM_ID;
    MEMCPY_AN(IF_PACK_INFO_HIS_N->ITEM_CODE, IF_PACK_INFO_HIS->ITEM_CODE, sizeof(IF_PACK_INFO_HIS->ITEM_CODE));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->ITEM_DESC, IF_PACK_INFO_HIS->ITEM_DESC, sizeof(IF_PACK_INFO_HIS->ITEM_DESC));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->LABEL_NAME, IF_PACK_INFO_HIS->LABEL_NAME, sizeof(IF_PACK_INFO_HIS->LABEL_NAME));
    IF_PACK_INFO_HIS_N->CUSTOMER_ID = IF_PACK_INFO_HIS->CUSTOMER_ID;
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CUSTOMER_NUMBER, IF_PACK_INFO_HIS->CUSTOMER_NUMBER, sizeof(IF_PACK_INFO_HIS->CUSTOMER_NUMBER));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CUSTOMER_NAME, IF_PACK_INFO_HIS->CUSTOMER_NAME, sizeof(IF_PACK_INFO_HIS->CUSTOMER_NAME));
    IF_PACK_INFO_HIS_N->SHIP_TO_SITE_USE_ID = IF_PACK_INFO_HIS->SHIP_TO_SITE_USE_ID;
    MEMCPY_AN(IF_PACK_INFO_HIS_N->SHIP_TO_NAME, IF_PACK_INFO_HIS->SHIP_TO_NAME, sizeof(IF_PACK_INFO_HIS->SHIP_TO_NAME));
    IF_PACK_INFO_HIS_N->END_SHIP_TO_ID = IF_PACK_INFO_HIS->END_SHIP_TO_ID;
    MEMCPY_AN(IF_PACK_INFO_HIS_N->END_SHIP_TO_NAME, IF_PACK_INFO_HIS->END_SHIP_TO_NAME, sizeof(IF_PACK_INFO_HIS->END_SHIP_TO_NAME));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->DRAWING_FLAG, IF_PACK_INFO_HIS->DRAWING_FLAG, sizeof(IF_PACK_INFO_HIS->DRAWING_FLAG));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->PACKING_INSTRUCTIONS, IF_PACK_INFO_HIS->PACKING_INSTRUCTIONS, sizeof(IF_PACK_INFO_HIS->PACKING_INSTRUCTIONS));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->ORDER_TYPE, IF_PACK_INFO_HIS->ORDER_TYPE, sizeof(IF_PACK_INFO_HIS->ORDER_TYPE));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->REQUEST_DATE, IF_PACK_INFO_HIS->REQUEST_DATE, sizeof(IF_PACK_INFO_HIS->REQUEST_DATE));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->SCHEDULE_SHIP_DATE, IF_PACK_INFO_HIS->SCHEDULE_SHIP_DATE, sizeof(IF_PACK_INFO_HIS->SCHEDULE_SHIP_DATE));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->SCHEDULE_ARRIVAL_DATE, IF_PACK_INFO_HIS->SCHEDULE_ARRIVAL_DATE, sizeof(IF_PACK_INFO_HIS->SCHEDULE_ARRIVAL_DATE));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->PROMISE_DATE, IF_PACK_INFO_HIS->PROMISE_DATE, sizeof(IF_PACK_INFO_HIS->PROMISE_DATE));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->INCLUDE_INSPECTION, IF_PACK_INFO_HIS->INCLUDE_INSPECTION, sizeof(IF_PACK_INFO_HIS->INCLUDE_INSPECTION));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->LABEL_TYPE, IF_PACK_INFO_HIS->LABEL_TYPE, sizeof(IF_PACK_INFO_HIS->LABEL_TYPE));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->LABEL_MESH, IF_PACK_INFO_HIS->LABEL_MESH, sizeof(IF_PACK_INFO_HIS->LABEL_MESH));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->LINE_DESC, IF_PACK_INFO_HIS->LINE_DESC, sizeof(IF_PACK_INFO_HIS->LINE_DESC));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->ORDER_UNIT, IF_PACK_INFO_HIS->ORDER_UNIT, sizeof(IF_PACK_INFO_HIS->ORDER_UNIT));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CURRENCY_CODE, IF_PACK_INFO_HIS->CURRENCY_CODE, sizeof(IF_PACK_INFO_HIS->CURRENCY_CODE));
    IF_PACK_INFO_HIS_N->ORDERED_QTY = IF_PACK_INFO_HIS->ORDERED_QTY;
    IF_PACK_INFO_HIS_N->SHIPED_QTY = IF_PACK_INFO_HIS->SHIPED_QTY;
    IF_PACK_INFO_HIS_N->CANCELED_QTY = IF_PACK_INFO_HIS->CANCELED_QTY;
    IF_PACK_INFO_HIS_N->UNIT_SELLING_PRICE = IF_PACK_INFO_HIS->UNIT_SELLING_PRICE;
    IF_PACK_INFO_HIS_N->UNIT_SELLING_PRICE_KR = IF_PACK_INFO_HIS->UNIT_SELLING_PRICE_KR;
    MEMCPY_AN(IF_PACK_INFO_HIS_N->ALLOCATE_FLAG, IF_PACK_INFO_HIS->ALLOCATE_FLAG, sizeof(IF_PACK_INFO_HIS->ALLOCATE_FLAG));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CUSTOMER_PO_NO, IF_PACK_INFO_HIS->CUSTOMER_PO_NO, sizeof(IF_PACK_INFO_HIS->CUSTOMER_PO_NO));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CUST_ITME_NAME, IF_PACK_INFO_HIS->CUST_ITME_NAME, sizeof(IF_PACK_INFO_HIS->CUST_ITME_NAME));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CUST_ITEM_TYPE, IF_PACK_INFO_HIS->CUST_ITEM_TYPE, sizeof(IF_PACK_INFO_HIS->CUST_ITEM_TYPE));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->REST, IF_PACK_INFO_HIS->REST, sizeof(IF_PACK_INFO_HIS->REST));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CUSTOMER_PO_LINE, IF_PACK_INFO_HIS->CUSTOMER_PO_LINE, sizeof(IF_PACK_INFO_HIS->CUSTOMER_PO_LINE));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->FORMAT_ID, IF_PACK_INFO_HIS->FORMAT_ID, sizeof(IF_PACK_INFO_HIS->FORMAT_ID));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CUSTOMER_PO, IF_PACK_INFO_HIS->CUSTOMER_PO, sizeof(IF_PACK_INFO_HIS->CUSTOMER_PO));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->PO_GUBUN, IF_PACK_INFO_HIS->PO_GUBUN, sizeof(IF_PACK_INFO_HIS->PO_GUBUN));
    IF_PACK_INFO_HIS_N->TRAN_FLAG[0] = IF_PACK_INFO_HIS->TRAN_FLAG;
    IF_PACK_INFO_HIS_N->IF_GROUP_ID = IF_PACK_INFO_HIS->IF_GROUP_ID;
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CMF_2, IF_PACK_INFO_HIS->CMF_2, sizeof(IF_PACK_INFO_HIS->CMF_2));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CMF_3, IF_PACK_INFO_HIS->CMF_3, sizeof(IF_PACK_INFO_HIS->CMF_3));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CMF_4, IF_PACK_INFO_HIS->CMF_4, sizeof(IF_PACK_INFO_HIS->CMF_4));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CMF_5, IF_PACK_INFO_HIS->CMF_5, sizeof(IF_PACK_INFO_HIS->CMF_5));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CMF_6, IF_PACK_INFO_HIS->CMF_6, sizeof(IF_PACK_INFO_HIS->CMF_6));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CMF_7, IF_PACK_INFO_HIS->CMF_7, sizeof(IF_PACK_INFO_HIS->CMF_7));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CMF_8, IF_PACK_INFO_HIS->CMF_8, sizeof(IF_PACK_INFO_HIS->CMF_8));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CMF_9, IF_PACK_INFO_HIS->CMF_9, sizeof(IF_PACK_INFO_HIS->CMF_9));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CMF_10, IF_PACK_INFO_HIS->CMF_10, sizeof(IF_PACK_INFO_HIS->CMF_10));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CREATE_USER_ID, IF_PACK_INFO_HIS->CREATE_USER_ID, sizeof(IF_PACK_INFO_HIS->CREATE_USER_ID));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->CREATE_TIME, IF_PACK_INFO_HIS->CREATE_TIME, sizeof(IF_PACK_INFO_HIS->CREATE_TIME));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->UPDATE_USER_ID, IF_PACK_INFO_HIS->UPDATE_USER_ID, sizeof(IF_PACK_INFO_HIS->UPDATE_USER_ID));
    MEMCPY_AN(IF_PACK_INFO_HIS_N->UPDATE_TIME, IF_PACK_INFO_HIS->UPDATE_TIME, sizeof(IF_PACK_INFO_HIS->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_if_pack_info_his(struct IF_PACK_INFO_HIS_N_TAG *IF_PACK_INFO_HIS_N, struct IF_PACK_INFO_HIS_TAG *IF_PACK_INFO_HIS)
{
    IF_PACK_INFO_HIS->IF_SEQ = IF_PACK_INFO_HIS_N->IF_SEQ;
    MEMCPY_DN(IF_PACK_INFO_HIS->IF_TIME, IF_PACK_INFO_HIS_N->IF_TIME, sizeof(IF_PACK_INFO_HIS->IF_TIME));
    IF_PACK_INFO_HIS->IF_CODE = IF_PACK_INFO_HIS_N->IF_CODE[0];
    MEMCPY_DN(IF_PACK_INFO_HIS->IF_MSG, IF_PACK_INFO_HIS_N->IF_MSG, sizeof(IF_PACK_INFO_HIS->IF_MSG));
    MEMCPY_DN(IF_PACK_INFO_HIS->FACTORY, IF_PACK_INFO_HIS_N->FACTORY, sizeof(IF_PACK_INFO_HIS->FACTORY));
    IF_PACK_INFO_HIS->OU_ID = IF_PACK_INFO_HIS_N->OU_ID;
    IF_PACK_INFO_HIS->ORG_ID = IF_PACK_INFO_HIS_N->ORG_ID;
    MEMCPY_DN(IF_PACK_INFO_HIS->ORG_CODE, IF_PACK_INFO_HIS_N->ORG_CODE, sizeof(IF_PACK_INFO_HIS->ORG_CODE));
    IF_PACK_INFO_HIS->ORDER_HEADER_ID = IF_PACK_INFO_HIS_N->ORDER_HEADER_ID;
    IF_PACK_INFO_HIS->ORDER_NUMBER = IF_PACK_INFO_HIS_N->ORDER_NUMBER;
    IF_PACK_INFO_HIS->LINE_NUMBER = IF_PACK_INFO_HIS_N->LINE_NUMBER;
    IF_PACK_INFO_HIS->ORDER_TYPE_ID = IF_PACK_INFO_HIS_N->ORDER_TYPE_ID;
    MEMCPY_DN(IF_PACK_INFO_HIS->ORDERED_DATE, IF_PACK_INFO_HIS_N->ORDERED_DATE, sizeof(IF_PACK_INFO_HIS->ORDERED_DATE));
    MEMCPY_DN(IF_PACK_INFO_HIS->BOOKED_DATE, IF_PACK_INFO_HIS_N->BOOKED_DATE, sizeof(IF_PACK_INFO_HIS->BOOKED_DATE));
    IF_PACK_INFO_HIS->ITEM_ID = IF_PACK_INFO_HIS_N->ITEM_ID;
    MEMCPY_DN(IF_PACK_INFO_HIS->ITEM_CODE, IF_PACK_INFO_HIS_N->ITEM_CODE, sizeof(IF_PACK_INFO_HIS->ITEM_CODE));
    MEMCPY_DN(IF_PACK_INFO_HIS->ITEM_DESC, IF_PACK_INFO_HIS_N->ITEM_DESC, sizeof(IF_PACK_INFO_HIS->ITEM_DESC));
    MEMCPY_DN(IF_PACK_INFO_HIS->LABEL_NAME, IF_PACK_INFO_HIS_N->LABEL_NAME, sizeof(IF_PACK_INFO_HIS->LABEL_NAME));
    IF_PACK_INFO_HIS->CUSTOMER_ID = IF_PACK_INFO_HIS_N->CUSTOMER_ID;
    MEMCPY_DN(IF_PACK_INFO_HIS->CUSTOMER_NUMBER, IF_PACK_INFO_HIS_N->CUSTOMER_NUMBER, sizeof(IF_PACK_INFO_HIS->CUSTOMER_NUMBER));
    MEMCPY_DN(IF_PACK_INFO_HIS->CUSTOMER_NAME, IF_PACK_INFO_HIS_N->CUSTOMER_NAME, sizeof(IF_PACK_INFO_HIS->CUSTOMER_NAME));
    IF_PACK_INFO_HIS->SHIP_TO_SITE_USE_ID = IF_PACK_INFO_HIS_N->SHIP_TO_SITE_USE_ID;
    MEMCPY_DN(IF_PACK_INFO_HIS->SHIP_TO_NAME, IF_PACK_INFO_HIS_N->SHIP_TO_NAME, sizeof(IF_PACK_INFO_HIS->SHIP_TO_NAME));
    IF_PACK_INFO_HIS->END_SHIP_TO_ID = IF_PACK_INFO_HIS_N->END_SHIP_TO_ID;
    MEMCPY_DN(IF_PACK_INFO_HIS->END_SHIP_TO_NAME, IF_PACK_INFO_HIS_N->END_SHIP_TO_NAME, sizeof(IF_PACK_INFO_HIS->END_SHIP_TO_NAME));
    MEMCPY_DN(IF_PACK_INFO_HIS->DRAWING_FLAG, IF_PACK_INFO_HIS_N->DRAWING_FLAG, sizeof(IF_PACK_INFO_HIS->DRAWING_FLAG));
    MEMCPY_DN(IF_PACK_INFO_HIS->PACKING_INSTRUCTIONS, IF_PACK_INFO_HIS_N->PACKING_INSTRUCTIONS, sizeof(IF_PACK_INFO_HIS->PACKING_INSTRUCTIONS));
    MEMCPY_DN(IF_PACK_INFO_HIS->ORDER_TYPE, IF_PACK_INFO_HIS_N->ORDER_TYPE, sizeof(IF_PACK_INFO_HIS->ORDER_TYPE));
    MEMCPY_DN(IF_PACK_INFO_HIS->REQUEST_DATE, IF_PACK_INFO_HIS_N->REQUEST_DATE, sizeof(IF_PACK_INFO_HIS->REQUEST_DATE));
    MEMCPY_DN(IF_PACK_INFO_HIS->SCHEDULE_SHIP_DATE, IF_PACK_INFO_HIS_N->SCHEDULE_SHIP_DATE, sizeof(IF_PACK_INFO_HIS->SCHEDULE_SHIP_DATE));
    MEMCPY_DN(IF_PACK_INFO_HIS->SCHEDULE_ARRIVAL_DATE, IF_PACK_INFO_HIS_N->SCHEDULE_ARRIVAL_DATE, sizeof(IF_PACK_INFO_HIS->SCHEDULE_ARRIVAL_DATE));
    MEMCPY_DN(IF_PACK_INFO_HIS->PROMISE_DATE, IF_PACK_INFO_HIS_N->PROMISE_DATE, sizeof(IF_PACK_INFO_HIS->PROMISE_DATE));
    MEMCPY_DN(IF_PACK_INFO_HIS->INCLUDE_INSPECTION, IF_PACK_INFO_HIS_N->INCLUDE_INSPECTION, sizeof(IF_PACK_INFO_HIS->INCLUDE_INSPECTION));
    MEMCPY_DN(IF_PACK_INFO_HIS->LABEL_TYPE, IF_PACK_INFO_HIS_N->LABEL_TYPE, sizeof(IF_PACK_INFO_HIS->LABEL_TYPE));
    MEMCPY_DN(IF_PACK_INFO_HIS->LABEL_MESH, IF_PACK_INFO_HIS_N->LABEL_MESH, sizeof(IF_PACK_INFO_HIS->LABEL_MESH));
    MEMCPY_DN(IF_PACK_INFO_HIS->LINE_DESC, IF_PACK_INFO_HIS_N->LINE_DESC, sizeof(IF_PACK_INFO_HIS->LINE_DESC));
    MEMCPY_DN(IF_PACK_INFO_HIS->ORDER_UNIT, IF_PACK_INFO_HIS_N->ORDER_UNIT, sizeof(IF_PACK_INFO_HIS->ORDER_UNIT));
    MEMCPY_DN(IF_PACK_INFO_HIS->CURRENCY_CODE, IF_PACK_INFO_HIS_N->CURRENCY_CODE, sizeof(IF_PACK_INFO_HIS->CURRENCY_CODE));
    IF_PACK_INFO_HIS->ORDERED_QTY = IF_PACK_INFO_HIS_N->ORDERED_QTY;
    IF_PACK_INFO_HIS->SHIPED_QTY = IF_PACK_INFO_HIS_N->SHIPED_QTY;
    IF_PACK_INFO_HIS->CANCELED_QTY = IF_PACK_INFO_HIS_N->CANCELED_QTY;
    IF_PACK_INFO_HIS->UNIT_SELLING_PRICE = IF_PACK_INFO_HIS_N->UNIT_SELLING_PRICE;
    IF_PACK_INFO_HIS->UNIT_SELLING_PRICE_KR = IF_PACK_INFO_HIS_N->UNIT_SELLING_PRICE_KR;
    MEMCPY_DN(IF_PACK_INFO_HIS->ALLOCATE_FLAG, IF_PACK_INFO_HIS_N->ALLOCATE_FLAG, sizeof(IF_PACK_INFO_HIS->ALLOCATE_FLAG));
    MEMCPY_DN(IF_PACK_INFO_HIS->CUSTOMER_PO_NO, IF_PACK_INFO_HIS_N->CUSTOMER_PO_NO, sizeof(IF_PACK_INFO_HIS->CUSTOMER_PO_NO));
    MEMCPY_DN(IF_PACK_INFO_HIS->CUST_ITME_NAME, IF_PACK_INFO_HIS_N->CUST_ITME_NAME, sizeof(IF_PACK_INFO_HIS->CUST_ITME_NAME));
    MEMCPY_DN(IF_PACK_INFO_HIS->CUST_ITEM_TYPE, IF_PACK_INFO_HIS_N->CUST_ITEM_TYPE, sizeof(IF_PACK_INFO_HIS->CUST_ITEM_TYPE));
    MEMCPY_DN(IF_PACK_INFO_HIS->REST, IF_PACK_INFO_HIS_N->REST, sizeof(IF_PACK_INFO_HIS->REST));
    MEMCPY_DN(IF_PACK_INFO_HIS->CUSTOMER_PO_LINE, IF_PACK_INFO_HIS_N->CUSTOMER_PO_LINE, sizeof(IF_PACK_INFO_HIS->CUSTOMER_PO_LINE));
    MEMCPY_DN(IF_PACK_INFO_HIS->FORMAT_ID, IF_PACK_INFO_HIS_N->FORMAT_ID, sizeof(IF_PACK_INFO_HIS->FORMAT_ID));
    MEMCPY_DN(IF_PACK_INFO_HIS->CUSTOMER_PO, IF_PACK_INFO_HIS_N->CUSTOMER_PO, sizeof(IF_PACK_INFO_HIS->CUSTOMER_PO));
    MEMCPY_DN(IF_PACK_INFO_HIS->PO_GUBUN, IF_PACK_INFO_HIS_N->PO_GUBUN, sizeof(IF_PACK_INFO_HIS->PO_GUBUN));
    IF_PACK_INFO_HIS->TRAN_FLAG = IF_PACK_INFO_HIS_N->TRAN_FLAG[0];
    IF_PACK_INFO_HIS->IF_GROUP_ID = IF_PACK_INFO_HIS_N->IF_GROUP_ID;
    MEMCPY_DN(IF_PACK_INFO_HIS->CMF_2, IF_PACK_INFO_HIS_N->CMF_2, sizeof(IF_PACK_INFO_HIS->CMF_2));
    MEMCPY_DN(IF_PACK_INFO_HIS->CMF_3, IF_PACK_INFO_HIS_N->CMF_3, sizeof(IF_PACK_INFO_HIS->CMF_3));
    MEMCPY_DN(IF_PACK_INFO_HIS->CMF_4, IF_PACK_INFO_HIS_N->CMF_4, sizeof(IF_PACK_INFO_HIS->CMF_4));
    MEMCPY_DN(IF_PACK_INFO_HIS->CMF_5, IF_PACK_INFO_HIS_N->CMF_5, sizeof(IF_PACK_INFO_HIS->CMF_5));
    MEMCPY_DN(IF_PACK_INFO_HIS->CMF_6, IF_PACK_INFO_HIS_N->CMF_6, sizeof(IF_PACK_INFO_HIS->CMF_6));
    MEMCPY_DN(IF_PACK_INFO_HIS->CMF_7, IF_PACK_INFO_HIS_N->CMF_7, sizeof(IF_PACK_INFO_HIS->CMF_7));
    MEMCPY_DN(IF_PACK_INFO_HIS->CMF_8, IF_PACK_INFO_HIS_N->CMF_8, sizeof(IF_PACK_INFO_HIS->CMF_8));
    MEMCPY_DN(IF_PACK_INFO_HIS->CMF_9, IF_PACK_INFO_HIS_N->CMF_9, sizeof(IF_PACK_INFO_HIS->CMF_9));
    MEMCPY_DN(IF_PACK_INFO_HIS->CMF_10, IF_PACK_INFO_HIS_N->CMF_10, sizeof(IF_PACK_INFO_HIS->CMF_10));
    MEMCPY_DN(IF_PACK_INFO_HIS->CREATE_USER_ID, IF_PACK_INFO_HIS_N->CREATE_USER_ID, sizeof(IF_PACK_INFO_HIS->CREATE_USER_ID));
    MEMCPY_DN(IF_PACK_INFO_HIS->CREATE_TIME, IF_PACK_INFO_HIS_N->CREATE_TIME, sizeof(IF_PACK_INFO_HIS->CREATE_TIME));
    MEMCPY_DN(IF_PACK_INFO_HIS->UPDATE_USER_ID, IF_PACK_INFO_HIS_N->UPDATE_USER_ID, sizeof(IF_PACK_INFO_HIS->UPDATE_USER_ID));
    MEMCPY_DN(IF_PACK_INFO_HIS->UPDATE_TIME, IF_PACK_INFO_HIS_N->UPDATE_TIME, sizeof(IF_PACK_INFO_HIS->UPDATE_TIME));
}


