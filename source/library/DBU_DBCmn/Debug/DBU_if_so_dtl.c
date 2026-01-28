
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
           char  filnam[17];
};
static const struct sqlcxp sqlfpn =
{
    16,
    "DBU_if_so_dtl.pc"
};


static unsigned int sqlctx = 4706811;


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
            void  *sqhstv[73];
   unsigned int   sqhstl[73];
            int   sqhsts[73];
            void  *sqindv[73];
            int   sqinds[73];
   unsigned int   sqharm[73];
   unsigned int   *sqharc[73];
   unsigned short  sqadto[73];
   unsigned short  sqtdso[73];
} sqlstm = {13,73};

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
"select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY ,SHIPPING_LINE_ID ,SHIPPIN\
G_LINE_NUM ,SHIPPING_HEADER_ID ,D4_SUM_ID ,OE_HEADER_ID ,OE_LINE_ID ,ORDER_TY\
PE ,PRICE_TYPE ,ITEM_ID ,ITEM_CODE ,ITEM_DESC ,SHIPPING_QTY ,SHIPPING_UOM ,SA\
LES_PRICE ,CURRENCY_CODE ,DATE_REQUESTED ,DATE_SCHEDULED ,RELEASED_STATUS ,SH\
IP_TO_ORG_ID ,INVOICE_TO_ORG_ID ,SHIP_FROM_INV_OPER ,TRX_INV_OPER ,SHIP_TO_IN\
V_OPER ,ACTUAL_DEPARTURE_DATE ,PICK_STATUS ,SHIP_STATUS ,SHIP_TO_LOCATION ,PI\
CK_CONFIRM_ID ,ORIG_SYS_LINE_REF ,DATE_SEQ ,SALESPERSON ,SHIP_CONFIRM_ID ,PAL\
LET_UNIT_QTY ,ITEM_UNIT_WEIGHT ,PALLET_WEIGHT ,PALLET_CNT ,TOTAL_WEIGHT ,ATTR\
IBUTE1 ,ATTRIBUTE2 ,ATTRIBUTE3 ,ATTRIBUTE4 ,ATTRIBUTE5 ,DEALING_NUMBER ,CUSTO\
MER_ITEM_CODE ,CUSTOMER_ITEM_DESC ,DEMAND_CLASS ,SHIPPING_DATE ,ORDER_NUMBER \
,LINE_NUMBER ,CREATED_BY ,LAST_UPDATED_BY ,LAST_UPDATE_LOGIN ,TRAN_FLAG ,CMF_\
1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USE\
R_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from IF_SO_DTL  order by IF_S\
EQ asc             ";

 static const char *sq0009 = 
"der by IF_SEQ asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,1356,0,4,46,0,0,73,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,4,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,
312,0,0,2,1368,0,4,230,0,0,73,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,4,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,
619,0,0,3,58,0,4,417,0,0,2,1,0,1,0,2,4,0,0,1,3,0,0,
642,0,0,4,40,0,2,453,0,0,1,1,0,1,0,1,3,0,0,
661,0,0,5,1273,0,3,482,0,0,72,72,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1,97,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,4,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
964,0,0,6,1268,0,5,651,0,0,72,72,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,4,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1267,0,0,7,61,0,5,727,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
1294,0,0,8,1018,0,9,837,0,0,0,0,0,1,0,
1309,0,0,9,1054,0,9,919,0,0,0,0,0,1,0,
1324,0,0,8,0,0,13,947,0,0,72,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,4,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1627,0,0,9,0,0,13,1023,0,0,72,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,4,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1930,0,0,8,0,0,15,1124,0,0,0,0,0,1,0,
1945,0,0,9,0,0,15,1128,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_if_so_dtl.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-09-28 11:32:02
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
void DBU_add_null_if_so_dtl(struct IF_SO_DTL_N_TAG *IF_SO_DTL_N, struct IF_SO_DTL_TAG *IF_SO_DTL);
void DBU_del_null_if_so_dtl(struct IF_SO_DTL_N_TAG *IF_SO_DTL_N, struct IF_SO_DTL_TAG *IF_SO_DTL);


/* SQL SELECT Function */
void DBU_select_if_so_dtl(int sel_type, struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_SO_DTL_N_TAG IF_SO_DTL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_so_dtl(&IF_SO_DTL_N, IF_SO_DTL);
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
                    SHIPPING_LINE_ID,
                    SHIPPING_LINE_NUM,
                    SHIPPING_HEADER_ID,
                    D4_SUM_ID,
                    OE_HEADER_ID,
                    OE_LINE_ID,
                    ORDER_TYPE,
                    PRICE_TYPE,
                    ITEM_ID,
                    ITEM_CODE,
                    ITEM_DESC,
                    SHIPPING_QTY,
                    SHIPPING_UOM,
                    SALES_PRICE,
                    CURRENCY_CODE,
                    DATE_REQUESTED,
                    DATE_SCHEDULED,
                    RELEASED_STATUS,
                    SHIP_TO_ORG_ID,
                    INVOICE_TO_ORG_ID,
                    SHIP_FROM_INV_OPER,
                    TRX_INV_OPER,
                    SHIP_TO_INV_OPER,
                    ACTUAL_DEPARTURE_DATE,
                    PICK_STATUS,
                    SHIP_STATUS,
                    SHIP_TO_LOCATION,
                    PICK_CONFIRM_ID,
                    ORIG_SYS_LINE_REF,
                    DATE_SEQ,
                    SALESPERSON,
                    SHIP_CONFIRM_ID,
                    PALLET_UNIT_QTY,
                    ITEM_UNIT_WEIGHT,
                    PALLET_WEIGHT,
                    PALLET_CNT,
                    TOTAL_WEIGHT,
                    ATTRIBUTE1,
                    ATTRIBUTE2,
                    ATTRIBUTE3,
                    ATTRIBUTE4,
                    ATTRIBUTE5,
                    DEALING_NUMBER,
                    CUSTOMER_ITEM_CODE,
                    CUSTOMER_ITEM_DESC,
                    DEMAND_CLASS,
                    SHIPPING_DATE,
                    ORDER_NUMBER,
                    LINE_NUMBER,
                    CREATED_BY,
                    LAST_UPDATED_BY,
                    LAST_UPDATE_LOGIN,
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
                    :IF_SO_DTL_N.IF_SEQ,
                    :IF_SO_DTL_N.IF_TIME,
                    :IF_SO_DTL_N.IF_CODE,
                    :IF_SO_DTL_N.IF_MSG,
                    :IF_SO_DTL_N.FACTORY,
                    :IF_SO_DTL_N.SHIPPING_LINE_ID,
                    :IF_SO_DTL_N.SHIPPING_LINE_NUM,
                    :IF_SO_DTL_N.SHIPPING_HEADER_ID,
                    :IF_SO_DTL_N.D4_SUM_ID,
                    :IF_SO_DTL_N.OE_HEADER_ID,
                    :IF_SO_DTL_N.OE_LINE_ID,
                    :IF_SO_DTL_N.ORDER_TYPE,
                    :IF_SO_DTL_N.PRICE_TYPE,
                    :IF_SO_DTL_N.ITEM_ID,
                    :IF_SO_DTL_N.ITEM_CODE,
                    :IF_SO_DTL_N.ITEM_DESC,
                    :IF_SO_DTL_N.SHIPPING_QTY,
                    :IF_SO_DTL_N.SHIPPING_UOM,
                    :IF_SO_DTL_N.SALES_PRICE,
                    :IF_SO_DTL_N.CURRENCY_CODE,
                    :IF_SO_DTL_N.DATE_REQUESTED,
                    :IF_SO_DTL_N.DATE_SCHEDULED,
                    :IF_SO_DTL_N.RELEASED_STATUS,
                    :IF_SO_DTL_N.SHIP_TO_ORG_ID,
                    :IF_SO_DTL_N.INVOICE_TO_ORG_ID,
                    :IF_SO_DTL_N.SHIP_FROM_INV_OPER,
                    :IF_SO_DTL_N.TRX_INV_OPER,
                    :IF_SO_DTL_N.SHIP_TO_INV_OPER,
                    :IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE,
                    :IF_SO_DTL_N.PICK_STATUS,
                    :IF_SO_DTL_N.SHIP_STATUS,
                    :IF_SO_DTL_N.SHIP_TO_LOCATION,
                    :IF_SO_DTL_N.PICK_CONFIRM_ID,
                    :IF_SO_DTL_N.ORIG_SYS_LINE_REF,
                    :IF_SO_DTL_N.DATE_SEQ,
                    :IF_SO_DTL_N.SALESPERSON,
                    :IF_SO_DTL_N.SHIP_CONFIRM_ID,
                    :IF_SO_DTL_N.PALLET_UNIT_QTY,
                    :IF_SO_DTL_N.ITEM_UNIT_WEIGHT,
                    :IF_SO_DTL_N.PALLET_WEIGHT,
                    :IF_SO_DTL_N.PALLET_CNT,
                    :IF_SO_DTL_N.TOTAL_WEIGHT,
                    :IF_SO_DTL_N.ATTRIBUTE1,
                    :IF_SO_DTL_N.ATTRIBUTE2,
                    :IF_SO_DTL_N.ATTRIBUTE3,
                    :IF_SO_DTL_N.ATTRIBUTE4,
                    :IF_SO_DTL_N.ATTRIBUTE5,
                    :IF_SO_DTL_N.DEALING_NUMBER,
                    :IF_SO_DTL_N.CUSTOMER_ITEM_CODE,
                    :IF_SO_DTL_N.CUSTOMER_ITEM_DESC,
                    :IF_SO_DTL_N.DEMAND_CLASS,
                    :IF_SO_DTL_N.SHIPPING_DATE,
                    :IF_SO_DTL_N.ORDER_NUMBER,
                    :IF_SO_DTL_N.LINE_NUMBER,
                    :IF_SO_DTL_N.CREATED_BY,
                    :IF_SO_DTL_N.LAST_UPDATED_BY,
                    :IF_SO_DTL_N.LAST_UPDATE_LOGIN,
                    :IF_SO_DTL_N.TRAN_FLAG,
                    :IF_SO_DTL_N.CMF_1,
                    :IF_SO_DTL_N.CMF_2,
                    :IF_SO_DTL_N.CMF_3,
                    :IF_SO_DTL_N.CMF_4,
                    :IF_SO_DTL_N.CMF_5,
                    :IF_SO_DTL_N.CMF_6,
                    :IF_SO_DTL_N.CMF_7,
                    :IF_SO_DTL_N.CMF_8,
                    :IF_SO_DTL_N.CMF_9,
                    :IF_SO_DTL_N.CMF_10,
                    :IF_SO_DTL_N.CREATE_USER_ID,
                    :IF_SO_DTL_N.CREATE_TIME,
                    :IF_SO_DTL_N.UPDATE_USER_ID,
                    :IF_SO_DTL_N.UPDATE_TIME
                FROM IF_SO_DTL
                WHERE IF_SEQ = :IF_SO_DTL_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY ,SHIPPING_LI\
NE_ID ,SHIPPING_LINE_NUM ,SHIPPING_HEADER_ID ,D4_SUM_ID ,OE_HEADER_ID ,OE_LI\
NE_ID ,ORDER_TYPE ,PRICE_TYPE ,ITEM_ID ,ITEM_CODE ,ITEM_DESC ,SHIPPING_QTY ,\
SHIPPING_UOM ,SALES_PRICE ,CURRENCY_CODE ,DATE_REQUESTED ,DATE_SCHEDULED ,RE\
LEASED_STATUS ,SHIP_TO_ORG_ID ,INVOICE_TO_ORG_ID ,SHIP_FROM_INV_OPER ,TRX_IN\
V_OPER ,SHIP_TO_INV_OPER ,ACTUAL_DEPARTURE_DATE ,PICK_STATUS ,SHIP_STATUS ,S\
HIP_TO_LOCATION ,PICK_CONFIRM_ID ,ORIG_SYS_LINE_REF ,DATE_SEQ ,SALESPERSON ,\
SHIP_CONFIRM_ID ,PALLET_UNIT_QTY ,ITEM_UNIT_WEIGHT ,PALLET_WEIGHT ,PALLET_CN\
T ,TOTAL_WEIGHT ,ATTRIBUTE1 ,ATTRIBUTE2 ,ATTRIBUTE3 ,ATTRIBUTE4 ,ATTRIBUTE5 \
,DEALING_NUMBER ,CUSTOMER_ITEM_CODE ,CUSTOMER_ITEM_DESC ,DEMAND_CLASS ,SHIPP\
ING_DATE ,ORDER_NUMBER ,LINE_NUMBER ,CREATED_BY ,LAST_UPDATED_BY ,LAST_UPDAT\
E_LOGIN ,TRAN_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,\
CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME into\
 :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,");
            sqlstm.stmt = ":b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b2\
1,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,\
:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b\
52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67\
,:b68,:b69,:b70,:b71  from IF_SO_DTL where IF_SEQ=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_SO_DTL_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_SO_DTL_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_SO_DTL_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_SO_DTL_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_SO_DTL_N.SHIPPING_HEADER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_SO_DTL_N.D4_SUM_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_SO_DTL_N.OE_HEADER_ID);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(IF_SO_DTL_N.OE_LINE_ID);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_SO_DTL_N.ORDER_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_SO_DTL_N.PRICE_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(IF_SO_DTL_N.ITEM_ID);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_SO_DTL_N.ITEM_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )41;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_SO_DTL_N.ITEM_DESC);
            sqlstm.sqhstl[15] = (unsigned int  )241;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(IF_SO_DTL_N.SHIPPING_QTY);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_SO_DTL_N.SHIPPING_UOM);
            sqlstm.sqhstl[17] = (unsigned int  )4;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_SO_DTL_N.SALES_PRICE);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_SO_DTL_N.CURRENCY_CODE);
            sqlstm.sqhstl[19] = (unsigned int  )16;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_SO_DTL_N.DATE_REQUESTED);
            sqlstm.sqhstl[20] = (unsigned int  )15;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_SO_DTL_N.DATE_SCHEDULED);
            sqlstm.sqhstl[21] = (unsigned int  )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_SO_DTL_N.RELEASED_STATUS);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(IF_SO_DTL_N.SHIP_TO_ORG_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(IF_SO_DTL_N.INVOICE_TO_ORG_ID);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(IF_SO_DTL_N.SHIP_FROM_INV_OPER);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(IF_SO_DTL_N.TRX_INV_OPER);
            sqlstm.sqhstl[26] = (unsigned int  )11;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_SO_DTL_N.SHIP_TO_INV_OPER);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )15;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_SO_DTL_N.PICK_STATUS);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_SO_DTL_N.SHIP_STATUS);
            sqlstm.sqhstl[30] = (unsigned int  )3;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_SO_DTL_N.SHIP_TO_LOCATION);
            sqlstm.sqhstl[31] = (unsigned int  )41;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(IF_SO_DTL_N.PICK_CONFIRM_ID);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_SO_DTL_N.ORIG_SYS_LINE_REF);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(IF_SO_DTL_N.DATE_SEQ);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_SO_DTL_N.SALESPERSON);
            sqlstm.sqhstl[35] = (unsigned int  )241;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(IF_SO_DTL_N.SHIP_CONFIRM_ID);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(IF_SO_DTL_N.PALLET_UNIT_QTY);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(IF_SO_DTL_N.ITEM_UNIT_WEIGHT);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(IF_SO_DTL_N.PALLET_WEIGHT);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(IF_SO_DTL_N.PALLET_CNT);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(IF_SO_DTL_N.TOTAL_WEIGHT);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE1);
            sqlstm.sqhstl[42] = (unsigned int  )151;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE2);
            sqlstm.sqhstl[43] = (unsigned int  )151;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE3);
            sqlstm.sqhstl[44] = (unsigned int  )151;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE4);
            sqlstm.sqhstl[45] = (unsigned int  )151;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE5);
            sqlstm.sqhstl[46] = (unsigned int  )151;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(IF_SO_DTL_N.DEALING_NUMBER);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_CODE);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_DESC);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(IF_SO_DTL_N.DEMAND_CLASS);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(IF_SO_DTL_N.SHIPPING_DATE);
            sqlstm.sqhstl[51] = (unsigned int  )15;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(IF_SO_DTL_N.ORDER_NUMBER);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(IF_SO_DTL_N.LINE_NUMBER);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(IF_SO_DTL_N.CREATED_BY);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATED_BY);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATE_LOGIN);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(IF_SO_DTL_N.TRAN_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(IF_SO_DTL_N.CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(IF_SO_DTL_N.CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(IF_SO_DTL_N.CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(IF_SO_DTL_N.CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(IF_SO_DTL_N.CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(IF_SO_DTL_N.CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )51;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(IF_SO_DTL_N.CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )51;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(IF_SO_DTL_N.CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(IF_SO_DTL_N.CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(IF_SO_DTL_N.CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(IF_SO_DTL_N.CREATE_USER_ID);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(IF_SO_DTL_N.CREATE_TIME);
            sqlstm.sqhstl[69] = (unsigned int  )15;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(IF_SO_DTL_N.UPDATE_USER_ID);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(IF_SO_DTL_N.UPDATE_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
            sqlstm.sqhstl[72] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
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
        DBU_del_null_if_so_dtl(&IF_SO_DTL_N, IF_SO_DTL);
    }

    DB_stop_query_timer("DBU_select_if_so_dtl", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_if_so_dtl_for_update(int sel_type, struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_SO_DTL_N_TAG IF_SO_DTL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_so_dtl(&IF_SO_DTL_N, IF_SO_DTL);
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
                    SHIPPING_LINE_ID,
                    SHIPPING_LINE_NUM,
                    SHIPPING_HEADER_ID,
                    D4_SUM_ID,
                    OE_HEADER_ID,
                    OE_LINE_ID,
                    ORDER_TYPE,
                    PRICE_TYPE,
                    ITEM_ID,
                    ITEM_CODE,
                    ITEM_DESC,
                    SHIPPING_QTY,
                    SHIPPING_UOM,
                    SALES_PRICE,
                    CURRENCY_CODE,
                    DATE_REQUESTED,
                    DATE_SCHEDULED,
                    RELEASED_STATUS,
                    SHIP_TO_ORG_ID,
                    INVOICE_TO_ORG_ID,
                    SHIP_FROM_INV_OPER,
                    TRX_INV_OPER,
                    SHIP_TO_INV_OPER,
                    ACTUAL_DEPARTURE_DATE,
                    PICK_STATUS,
                    SHIP_STATUS,
                    SHIP_TO_LOCATION,
                    PICK_CONFIRM_ID,
                    ORIG_SYS_LINE_REF,
                    DATE_SEQ,
                    SALESPERSON,
                    SHIP_CONFIRM_ID,
                    PALLET_UNIT_QTY,
                    ITEM_UNIT_WEIGHT,
                    PALLET_WEIGHT,
                    PALLET_CNT,
                    TOTAL_WEIGHT,
                    ATTRIBUTE1,
                    ATTRIBUTE2,
                    ATTRIBUTE3,
                    ATTRIBUTE4,
                    ATTRIBUTE5,
                    DEALING_NUMBER,
                    CUSTOMER_ITEM_CODE,
                    CUSTOMER_ITEM_DESC,
                    DEMAND_CLASS,
                    SHIPPING_DATE,
                    ORDER_NUMBER,
                    LINE_NUMBER,
                    CREATED_BY,
                    LAST_UPDATED_BY,
                    LAST_UPDATE_LOGIN,
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
                    :IF_SO_DTL_N.IF_SEQ,
                    :IF_SO_DTL_N.IF_TIME,
                    :IF_SO_DTL_N.IF_CODE,
                    :IF_SO_DTL_N.IF_MSG,
                    :IF_SO_DTL_N.FACTORY,
                    :IF_SO_DTL_N.SHIPPING_LINE_ID,
                    :IF_SO_DTL_N.SHIPPING_LINE_NUM,
                    :IF_SO_DTL_N.SHIPPING_HEADER_ID,
                    :IF_SO_DTL_N.D4_SUM_ID,
                    :IF_SO_DTL_N.OE_HEADER_ID,
                    :IF_SO_DTL_N.OE_LINE_ID,
                    :IF_SO_DTL_N.ORDER_TYPE,
                    :IF_SO_DTL_N.PRICE_TYPE,
                    :IF_SO_DTL_N.ITEM_ID,
                    :IF_SO_DTL_N.ITEM_CODE,
                    :IF_SO_DTL_N.ITEM_DESC,
                    :IF_SO_DTL_N.SHIPPING_QTY,
                    :IF_SO_DTL_N.SHIPPING_UOM,
                    :IF_SO_DTL_N.SALES_PRICE,
                    :IF_SO_DTL_N.CURRENCY_CODE,
                    :IF_SO_DTL_N.DATE_REQUESTED,
                    :IF_SO_DTL_N.DATE_SCHEDULED,
                    :IF_SO_DTL_N.RELEASED_STATUS,
                    :IF_SO_DTL_N.SHIP_TO_ORG_ID,
                    :IF_SO_DTL_N.INVOICE_TO_ORG_ID,
                    :IF_SO_DTL_N.SHIP_FROM_INV_OPER,
                    :IF_SO_DTL_N.TRX_INV_OPER,
                    :IF_SO_DTL_N.SHIP_TO_INV_OPER,
                    :IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE,
                    :IF_SO_DTL_N.PICK_STATUS,
                    :IF_SO_DTL_N.SHIP_STATUS,
                    :IF_SO_DTL_N.SHIP_TO_LOCATION,
                    :IF_SO_DTL_N.PICK_CONFIRM_ID,
                    :IF_SO_DTL_N.ORIG_SYS_LINE_REF,
                    :IF_SO_DTL_N.DATE_SEQ,
                    :IF_SO_DTL_N.SALESPERSON,
                    :IF_SO_DTL_N.SHIP_CONFIRM_ID,
                    :IF_SO_DTL_N.PALLET_UNIT_QTY,
                    :IF_SO_DTL_N.ITEM_UNIT_WEIGHT,
                    :IF_SO_DTL_N.PALLET_WEIGHT,
                    :IF_SO_DTL_N.PALLET_CNT,
                    :IF_SO_DTL_N.TOTAL_WEIGHT,
                    :IF_SO_DTL_N.ATTRIBUTE1,
                    :IF_SO_DTL_N.ATTRIBUTE2,
                    :IF_SO_DTL_N.ATTRIBUTE3,
                    :IF_SO_DTL_N.ATTRIBUTE4,
                    :IF_SO_DTL_N.ATTRIBUTE5,
                    :IF_SO_DTL_N.DEALING_NUMBER,
                    :IF_SO_DTL_N.CUSTOMER_ITEM_CODE,
                    :IF_SO_DTL_N.CUSTOMER_ITEM_DESC,
                    :IF_SO_DTL_N.DEMAND_CLASS,
                    :IF_SO_DTL_N.SHIPPING_DATE,
                    :IF_SO_DTL_N.ORDER_NUMBER,
                    :IF_SO_DTL_N.LINE_NUMBER,
                    :IF_SO_DTL_N.CREATED_BY,
                    :IF_SO_DTL_N.LAST_UPDATED_BY,
                    :IF_SO_DTL_N.LAST_UPDATE_LOGIN,
                    :IF_SO_DTL_N.TRAN_FLAG,
                    :IF_SO_DTL_N.CMF_1,
                    :IF_SO_DTL_N.CMF_2,
                    :IF_SO_DTL_N.CMF_3,
                    :IF_SO_DTL_N.CMF_4,
                    :IF_SO_DTL_N.CMF_5,
                    :IF_SO_DTL_N.CMF_6,
                    :IF_SO_DTL_N.CMF_7,
                    :IF_SO_DTL_N.CMF_8,
                    :IF_SO_DTL_N.CMF_9,
                    :IF_SO_DTL_N.CMF_10,
                    :IF_SO_DTL_N.CREATE_USER_ID,
                    :IF_SO_DTL_N.CREATE_TIME,
                    :IF_SO_DTL_N.UPDATE_USER_ID,
                    :IF_SO_DTL_N.UPDATE_TIME
                FROM IF_SO_DTL
                WHERE IF_SEQ = :IF_SO_DTL_N.IF_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY ,SHIPPING_LI\
NE_ID ,SHIPPING_LINE_NUM ,SHIPPING_HEADER_ID ,D4_SUM_ID ,OE_HEADER_ID ,OE_LI\
NE_ID ,ORDER_TYPE ,PRICE_TYPE ,ITEM_ID ,ITEM_CODE ,ITEM_DESC ,SHIPPING_QTY ,\
SHIPPING_UOM ,SALES_PRICE ,CURRENCY_CODE ,DATE_REQUESTED ,DATE_SCHEDULED ,RE\
LEASED_STATUS ,SHIP_TO_ORG_ID ,INVOICE_TO_ORG_ID ,SHIP_FROM_INV_OPER ,TRX_IN\
V_OPER ,SHIP_TO_INV_OPER ,ACTUAL_DEPARTURE_DATE ,PICK_STATUS ,SHIP_STATUS ,S\
HIP_TO_LOCATION ,PICK_CONFIRM_ID ,ORIG_SYS_LINE_REF ,DATE_SEQ ,SALESPERSON ,\
SHIP_CONFIRM_ID ,PALLET_UNIT_QTY ,ITEM_UNIT_WEIGHT ,PALLET_WEIGHT ,PALLET_CN\
T ,TOTAL_WEIGHT ,ATTRIBUTE1 ,ATTRIBUTE2 ,ATTRIBUTE3 ,ATTRIBUTE4 ,ATTRIBUTE5 \
,DEALING_NUMBER ,CUSTOMER_ITEM_CODE ,CUSTOMER_ITEM_DESC ,DEMAND_CLASS ,SHIPP\
ING_DATE ,ORDER_NUMBER ,LINE_NUMBER ,CREATED_BY ,LAST_UPDATED_BY ,LAST_UPDAT\
E_LOGIN ,TRAN_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,\
CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME into\
 :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,");
            sqlstm.stmt = ":b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b2\
1,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,\
:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b\
52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67\
,:b68,:b69,:b70,:b71  from IF_SO_DTL where IF_SEQ=:b0 for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )312;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_SO_DTL_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_SO_DTL_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_SO_DTL_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_SO_DTL_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_SO_DTL_N.SHIPPING_HEADER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_SO_DTL_N.D4_SUM_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_SO_DTL_N.OE_HEADER_ID);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(IF_SO_DTL_N.OE_LINE_ID);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_SO_DTL_N.ORDER_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_SO_DTL_N.PRICE_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(IF_SO_DTL_N.ITEM_ID);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_SO_DTL_N.ITEM_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )41;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_SO_DTL_N.ITEM_DESC);
            sqlstm.sqhstl[15] = (unsigned int  )241;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(IF_SO_DTL_N.SHIPPING_QTY);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_SO_DTL_N.SHIPPING_UOM);
            sqlstm.sqhstl[17] = (unsigned int  )4;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_SO_DTL_N.SALES_PRICE);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_SO_DTL_N.CURRENCY_CODE);
            sqlstm.sqhstl[19] = (unsigned int  )16;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_SO_DTL_N.DATE_REQUESTED);
            sqlstm.sqhstl[20] = (unsigned int  )15;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_SO_DTL_N.DATE_SCHEDULED);
            sqlstm.sqhstl[21] = (unsigned int  )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_SO_DTL_N.RELEASED_STATUS);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(IF_SO_DTL_N.SHIP_TO_ORG_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(IF_SO_DTL_N.INVOICE_TO_ORG_ID);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(IF_SO_DTL_N.SHIP_FROM_INV_OPER);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(IF_SO_DTL_N.TRX_INV_OPER);
            sqlstm.sqhstl[26] = (unsigned int  )11;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_SO_DTL_N.SHIP_TO_INV_OPER);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )15;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_SO_DTL_N.PICK_STATUS);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_SO_DTL_N.SHIP_STATUS);
            sqlstm.sqhstl[30] = (unsigned int  )3;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_SO_DTL_N.SHIP_TO_LOCATION);
            sqlstm.sqhstl[31] = (unsigned int  )41;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(IF_SO_DTL_N.PICK_CONFIRM_ID);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_SO_DTL_N.ORIG_SYS_LINE_REF);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(IF_SO_DTL_N.DATE_SEQ);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_SO_DTL_N.SALESPERSON);
            sqlstm.sqhstl[35] = (unsigned int  )241;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(IF_SO_DTL_N.SHIP_CONFIRM_ID);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(IF_SO_DTL_N.PALLET_UNIT_QTY);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(IF_SO_DTL_N.ITEM_UNIT_WEIGHT);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(IF_SO_DTL_N.PALLET_WEIGHT);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(IF_SO_DTL_N.PALLET_CNT);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(IF_SO_DTL_N.TOTAL_WEIGHT);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE1);
            sqlstm.sqhstl[42] = (unsigned int  )151;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE2);
            sqlstm.sqhstl[43] = (unsigned int  )151;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE3);
            sqlstm.sqhstl[44] = (unsigned int  )151;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE4);
            sqlstm.sqhstl[45] = (unsigned int  )151;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE5);
            sqlstm.sqhstl[46] = (unsigned int  )151;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(IF_SO_DTL_N.DEALING_NUMBER);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_CODE);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_DESC);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(IF_SO_DTL_N.DEMAND_CLASS);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(IF_SO_DTL_N.SHIPPING_DATE);
            sqlstm.sqhstl[51] = (unsigned int  )15;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(IF_SO_DTL_N.ORDER_NUMBER);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(IF_SO_DTL_N.LINE_NUMBER);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(IF_SO_DTL_N.CREATED_BY);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATED_BY);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATE_LOGIN);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(IF_SO_DTL_N.TRAN_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(IF_SO_DTL_N.CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(IF_SO_DTL_N.CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(IF_SO_DTL_N.CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(IF_SO_DTL_N.CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(IF_SO_DTL_N.CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(IF_SO_DTL_N.CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )51;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(IF_SO_DTL_N.CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )51;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(IF_SO_DTL_N.CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(IF_SO_DTL_N.CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(IF_SO_DTL_N.CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(IF_SO_DTL_N.CREATE_USER_ID);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(IF_SO_DTL_N.CREATE_TIME);
            sqlstm.sqhstl[69] = (unsigned int  )15;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(IF_SO_DTL_N.UPDATE_USER_ID);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(IF_SO_DTL_N.UPDATE_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
            sqlstm.sqhstl[72] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
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
        DBU_del_null_if_so_dtl(&IF_SO_DTL_N, IF_SO_DTL);
    }

    DB_stop_query_timer("DBU_select_if_so_dtl_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_if_so_dtl_scalar(int sel_type, struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_SO_DTL_N_TAG IF_SO_DTL_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_so_dtl(&IF_SO_DTL_N, IF_SO_DTL);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM IF_SO_DTL
                WHERE IF_SEQ = :IF_SO_DTL_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from IF_SO_DTL where \
IF_SEQ=:b1";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )619;
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
            sqlstm.sqhstv[1] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
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

    DB_stop_query_timer("DBU_select_if_so_dtl_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_if_so_dtl(int sel_type, struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_SO_DTL_N_TAG IF_SO_DTL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_so_dtl(&IF_SO_DTL_N, IF_SO_DTL);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM IF_SO_DTL
                WHERE IF_SEQ = :IF_SO_DTL_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from IF_SO_DTL  where IF_SEQ=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )642;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
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

    DB_stop_query_timer("DBU_delete_if_so_dtl", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_if_so_dtl(struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_SO_DTL_N_TAG IF_SO_DTL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_so_dtl(&IF_SO_DTL_N, IF_SO_DTL);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO IF_SO_DTL( 
                    IF_SEQ, 
                    IF_TIME, 
                    IF_CODE, 
                    IF_MSG, 
                    FACTORY, 
                    SHIPPING_LINE_ID, 
                    SHIPPING_LINE_NUM, 
                    SHIPPING_HEADER_ID, 
                    D4_SUM_ID, 
                    OE_HEADER_ID, 
                    OE_LINE_ID, 
                    ORDER_TYPE, 
                    PRICE_TYPE, 
                    ITEM_ID, 
                    ITEM_CODE, 
                    ITEM_DESC, 
                    SHIPPING_QTY, 
                    SHIPPING_UOM, 
                    SALES_PRICE, 
                    CURRENCY_CODE, 
                    DATE_REQUESTED, 
                    DATE_SCHEDULED, 
                    RELEASED_STATUS, 
                    SHIP_TO_ORG_ID, 
                    INVOICE_TO_ORG_ID, 
                    SHIP_FROM_INV_OPER, 
                    TRX_INV_OPER, 
                    SHIP_TO_INV_OPER, 
                    ACTUAL_DEPARTURE_DATE, 
                    PICK_STATUS, 
                    SHIP_STATUS, 
                    SHIP_TO_LOCATION, 
                    PICK_CONFIRM_ID, 
                    ORIG_SYS_LINE_REF, 
                    DATE_SEQ, 
                    SALESPERSON, 
                    SHIP_CONFIRM_ID, 
                    PALLET_UNIT_QTY, 
                    ITEM_UNIT_WEIGHT, 
                    PALLET_WEIGHT, 
                    PALLET_CNT, 
                    TOTAL_WEIGHT, 
                    ATTRIBUTE1, 
                    ATTRIBUTE2, 
                    ATTRIBUTE3, 
                    ATTRIBUTE4, 
                    ATTRIBUTE5, 
                    DEALING_NUMBER, 
                    CUSTOMER_ITEM_CODE, 
                    CUSTOMER_ITEM_DESC, 
                    DEMAND_CLASS, 
                    SHIPPING_DATE, 
                    ORDER_NUMBER, 
                    LINE_NUMBER, 
                    CREATED_BY, 
                    LAST_UPDATED_BY, 
                    LAST_UPDATE_LOGIN, 
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
                    :IF_SO_DTL_N.IF_SEQ,
                    :IF_SO_DTL_N.IF_TIME,
                    :IF_SO_DTL_N.IF_CODE,
                    :IF_SO_DTL_N.IF_MSG,
                    :IF_SO_DTL_N.FACTORY,
                    :IF_SO_DTL_N.SHIPPING_LINE_ID,
                    :IF_SO_DTL_N.SHIPPING_LINE_NUM,
                    :IF_SO_DTL_N.SHIPPING_HEADER_ID,
                    :IF_SO_DTL_N.D4_SUM_ID,
                    :IF_SO_DTL_N.OE_HEADER_ID,
                    :IF_SO_DTL_N.OE_LINE_ID,
                    :IF_SO_DTL_N.ORDER_TYPE,
                    :IF_SO_DTL_N.PRICE_TYPE,
                    :IF_SO_DTL_N.ITEM_ID,
                    :IF_SO_DTL_N.ITEM_CODE,
                    :IF_SO_DTL_N.ITEM_DESC,
                    :IF_SO_DTL_N.SHIPPING_QTY,
                    :IF_SO_DTL_N.SHIPPING_UOM,
                    :IF_SO_DTL_N.SALES_PRICE,
                    :IF_SO_DTL_N.CURRENCY_CODE,
                    :IF_SO_DTL_N.DATE_REQUESTED,
                    :IF_SO_DTL_N.DATE_SCHEDULED,
                    :IF_SO_DTL_N.RELEASED_STATUS,
                    :IF_SO_DTL_N.SHIP_TO_ORG_ID,
                    :IF_SO_DTL_N.INVOICE_TO_ORG_ID,
                    :IF_SO_DTL_N.SHIP_FROM_INV_OPER,
                    :IF_SO_DTL_N.TRX_INV_OPER,
                    :IF_SO_DTL_N.SHIP_TO_INV_OPER,
                    :IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE,
                    :IF_SO_DTL_N.PICK_STATUS,
                    :IF_SO_DTL_N.SHIP_STATUS,
                    :IF_SO_DTL_N.SHIP_TO_LOCATION,
                    :IF_SO_DTL_N.PICK_CONFIRM_ID,
                    :IF_SO_DTL_N.ORIG_SYS_LINE_REF,
                    :IF_SO_DTL_N.DATE_SEQ,
                    :IF_SO_DTL_N.SALESPERSON,
                    :IF_SO_DTL_N.SHIP_CONFIRM_ID,
                    :IF_SO_DTL_N.PALLET_UNIT_QTY,
                    :IF_SO_DTL_N.ITEM_UNIT_WEIGHT,
                    :IF_SO_DTL_N.PALLET_WEIGHT,
                    :IF_SO_DTL_N.PALLET_CNT,
                    :IF_SO_DTL_N.TOTAL_WEIGHT,
                    :IF_SO_DTL_N.ATTRIBUTE1,
                    :IF_SO_DTL_N.ATTRIBUTE2,
                    :IF_SO_DTL_N.ATTRIBUTE3,
                    :IF_SO_DTL_N.ATTRIBUTE4,
                    :IF_SO_DTL_N.ATTRIBUTE5,
                    :IF_SO_DTL_N.DEALING_NUMBER,
                    :IF_SO_DTL_N.CUSTOMER_ITEM_CODE,
                    :IF_SO_DTL_N.CUSTOMER_ITEM_DESC,
                    :IF_SO_DTL_N.DEMAND_CLASS,
                    :IF_SO_DTL_N.SHIPPING_DATE,
                    :IF_SO_DTL_N.ORDER_NUMBER,
                    :IF_SO_DTL_N.LINE_NUMBER,
                    :IF_SO_DTL_N.CREATED_BY,
                    :IF_SO_DTL_N.LAST_UPDATED_BY,
                    :IF_SO_DTL_N.LAST_UPDATE_LOGIN,
                    :IF_SO_DTL_N.TRAN_FLAG,
                    :IF_SO_DTL_N.CMF_1,
                    :IF_SO_DTL_N.CMF_2,
                    :IF_SO_DTL_N.CMF_3,
                    :IF_SO_DTL_N.CMF_4,
                    :IF_SO_DTL_N.CMF_5,
                    :IF_SO_DTL_N.CMF_6,
                    :IF_SO_DTL_N.CMF_7,
                    :IF_SO_DTL_N.CMF_8,
                    :IF_SO_DTL_N.CMF_9,
                    :IF_SO_DTL_N.CMF_10,
                    :IF_SO_DTL_N.CREATE_USER_ID,
                    :IF_SO_DTL_N.CREATE_TIME,
                    :IF_SO_DTL_N.UPDATE_USER_ID,
                    :IF_SO_DTL_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 73;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into IF_SO_DTL (IF_SEQ,IF_TIME,IF_CODE,IF_MSG,FACTORY,SHIPPING\
_LINE_ID,SHIPPING_LINE_NUM,SHIPPING_HEADER_ID,D4_SUM_ID,OE_HEADER_ID,OE_LINE\
_ID,ORDER_TYPE,PRICE_TYPE,ITEM_ID,ITEM_CODE,ITEM_DESC,SHIPPING_QTY,SHIPPING_\
UOM,SALES_PRICE,CURRENCY_CODE,DATE_REQUESTED,DATE_SCHEDULED,RELEASED_STATUS,\
SHIP_TO_ORG_ID,INVOICE_TO_ORG_ID,SHIP_FROM_INV_OPER,TRX_INV_OPER,SHIP_TO_INV\
_OPER,ACTUAL_DEPARTURE_DATE,PICK_STATUS,SHIP_STATUS,SHIP_TO_LOCATION,PICK_CO\
NFIRM_ID,ORIG_SYS_LINE_REF,DATE_SEQ,SALESPERSON,SHIP_CONFIRM_ID,PALLET_UNIT_\
QTY,ITEM_UNIT_WEIGHT,PALLET_WEIGHT,PALLET_CNT,TOTAL_WEIGHT,ATTRIBUTE1,ATTRIB\
UTE2,ATTRIBUTE3,ATTRIBUTE4,ATTRIBUTE5,DEALING_NUMBER,CUSTOMER_ITEM_CODE,CUST\
OMER_ITEM_DESC,DEMAND_CLASS,SHIPPING_DATE,ORDER_NUMBER,LINE_NUMBER,CREATED_B\
Y,LAST_UPDATED_BY,LAST_UPDATE_LOGIN,TRAN_FLAG,CMF_1,CMF_2,CMF_3,CMF_4,CMF_5,\
CMF_6,CMF_7,CMF_8,CMF_9,CMF_10,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPD\
ATE_TIME) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b1\
3,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:");
    sqlstm.stmt = "b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b\
33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48\
,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:\
b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )661;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(IF_SO_DTL_N.IF_TIME);
    sqlstm.sqhstl[1] = (unsigned int  )15;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(IF_SO_DTL_N.IF_CODE);
    sqlstm.sqhstl[2] = (unsigned int  )2;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(IF_SO_DTL_N.IF_MSG);
    sqlstm.sqhstl[3] = (unsigned int  )201;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(IF_SO_DTL_N.FACTORY);
    sqlstm.sqhstl[4] = (unsigned int  )11;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_ID);
    sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_NUM);
    sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)&(IF_SO_DTL_N.SHIPPING_HEADER_ID);
    sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)&(IF_SO_DTL_N.D4_SUM_ID);
    sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)&(IF_SO_DTL_N.OE_HEADER_ID);
    sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)&(IF_SO_DTL_N.OE_LINE_ID);
    sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(IF_SO_DTL_N.ORDER_TYPE);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(IF_SO_DTL_N.PRICE_TYPE);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)&(IF_SO_DTL_N.ITEM_ID);
    sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(IF_SO_DTL_N.ITEM_CODE);
    sqlstm.sqhstl[14] = (unsigned int  )41;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(IF_SO_DTL_N.ITEM_DESC);
    sqlstm.sqhstl[15] = (unsigned int  )241;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)&(IF_SO_DTL_N.SHIPPING_QTY);
    sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(IF_SO_DTL_N.SHIPPING_UOM);
    sqlstm.sqhstl[17] = (unsigned int  )4;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)&(IF_SO_DTL_N.SALES_PRICE);
    sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(IF_SO_DTL_N.CURRENCY_CODE);
    sqlstm.sqhstl[19] = (unsigned int  )16;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(IF_SO_DTL_N.DATE_REQUESTED);
    sqlstm.sqhstl[20] = (unsigned int  )15;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(IF_SO_DTL_N.DATE_SCHEDULED);
    sqlstm.sqhstl[21] = (unsigned int  )15;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(IF_SO_DTL_N.RELEASED_STATUS);
    sqlstm.sqhstl[22] = (unsigned int  )2;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)&(IF_SO_DTL_N.SHIP_TO_ORG_ID);
    sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)&(IF_SO_DTL_N.INVOICE_TO_ORG_ID);
    sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(IF_SO_DTL_N.SHIP_FROM_INV_OPER);
    sqlstm.sqhstl[25] = (unsigned int  )11;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(IF_SO_DTL_N.TRX_INV_OPER);
    sqlstm.sqhstl[26] = (unsigned int  )11;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(IF_SO_DTL_N.SHIP_TO_INV_OPER);
    sqlstm.sqhstl[27] = (unsigned int  )11;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE);
    sqlstm.sqhstl[28] = (unsigned int  )15;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(IF_SO_DTL_N.PICK_STATUS);
    sqlstm.sqhstl[29] = (unsigned int  )2;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(IF_SO_DTL_N.SHIP_STATUS);
    sqlstm.sqhstl[30] = (unsigned int  )3;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(IF_SO_DTL_N.SHIP_TO_LOCATION);
    sqlstm.sqhstl[31] = (unsigned int  )41;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)&(IF_SO_DTL_N.PICK_CONFIRM_ID);
    sqlstm.sqhstl[32] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(IF_SO_DTL_N.ORIG_SYS_LINE_REF);
    sqlstm.sqhstl[33] = (unsigned int  )51;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)&(IF_SO_DTL_N.DATE_SEQ);
    sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(IF_SO_DTL_N.SALESPERSON);
    sqlstm.sqhstl[35] = (unsigned int  )241;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)&(IF_SO_DTL_N.SHIP_CONFIRM_ID);
    sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)&(IF_SO_DTL_N.PALLET_UNIT_QTY);
    sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)&(IF_SO_DTL_N.ITEM_UNIT_WEIGHT);
    sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)&(IF_SO_DTL_N.PALLET_WEIGHT);
    sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)&(IF_SO_DTL_N.PALLET_CNT);
    sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)&(IF_SO_DTL_N.TOTAL_WEIGHT);
    sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE1);
    sqlstm.sqhstl[42] = (unsigned int  )151;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE2);
    sqlstm.sqhstl[43] = (unsigned int  )151;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE3);
    sqlstm.sqhstl[44] = (unsigned int  )151;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE4);
    sqlstm.sqhstl[45] = (unsigned int  )151;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE5);
    sqlstm.sqhstl[46] = (unsigned int  )151;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(IF_SO_DTL_N.DEALING_NUMBER);
    sqlstm.sqhstl[47] = (unsigned int  )51;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_CODE);
    sqlstm.sqhstl[48] = (unsigned int  )51;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_DESC);
    sqlstm.sqhstl[49] = (unsigned int  )1001;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(IF_SO_DTL_N.DEMAND_CLASS);
    sqlstm.sqhstl[50] = (unsigned int  )31;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(IF_SO_DTL_N.SHIPPING_DATE);
    sqlstm.sqhstl[51] = (unsigned int  )15;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)&(IF_SO_DTL_N.ORDER_NUMBER);
    sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)&(IF_SO_DTL_N.LINE_NUMBER);
    sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)&(IF_SO_DTL_N.CREATED_BY);
    sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATED_BY);
    sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATE_LOGIN);
    sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(IF_SO_DTL_N.TRAN_FLAG);
    sqlstm.sqhstl[57] = (unsigned int  )2;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(IF_SO_DTL_N.CMF_1);
    sqlstm.sqhstl[58] = (unsigned int  )51;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(IF_SO_DTL_N.CMF_2);
    sqlstm.sqhstl[59] = (unsigned int  )51;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(IF_SO_DTL_N.CMF_3);
    sqlstm.sqhstl[60] = (unsigned int  )51;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(IF_SO_DTL_N.CMF_4);
    sqlstm.sqhstl[61] = (unsigned int  )51;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(IF_SO_DTL_N.CMF_5);
    sqlstm.sqhstl[62] = (unsigned int  )51;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(IF_SO_DTL_N.CMF_6);
    sqlstm.sqhstl[63] = (unsigned int  )51;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(IF_SO_DTL_N.CMF_7);
    sqlstm.sqhstl[64] = (unsigned int  )51;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(IF_SO_DTL_N.CMF_8);
    sqlstm.sqhstl[65] = (unsigned int  )51;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(IF_SO_DTL_N.CMF_9);
    sqlstm.sqhstl[66] = (unsigned int  )51;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(IF_SO_DTL_N.CMF_10);
    sqlstm.sqhstl[67] = (unsigned int  )51;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(IF_SO_DTL_N.CREATE_USER_ID);
    sqlstm.sqhstl[68] = (unsigned int  )21;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(IF_SO_DTL_N.CREATE_TIME);
    sqlstm.sqhstl[69] = (unsigned int  )15;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(IF_SO_DTL_N.UPDATE_USER_ID);
    sqlstm.sqhstl[70] = (unsigned int  )21;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(IF_SO_DTL_N.UPDATE_TIME);
    sqlstm.sqhstl[71] = (unsigned int  )15;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_if_so_dtl", 0);
}


/* SQL UPDATE Function */
void DBU_update_if_so_dtl(int sel_type, struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_SO_DTL_N_TAG IF_SO_DTL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_so_dtl(&IF_SO_DTL_N, IF_SO_DTL);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE IF_SO_DTL SET
                    IF_TIME = :IF_SO_DTL_N.IF_TIME,
                    IF_CODE = :IF_SO_DTL_N.IF_CODE,
                    IF_MSG = :IF_SO_DTL_N.IF_MSG,
                    FACTORY = :IF_SO_DTL_N.FACTORY,
                    SHIPPING_LINE_ID = :IF_SO_DTL_N.SHIPPING_LINE_ID,
                    SHIPPING_LINE_NUM = :IF_SO_DTL_N.SHIPPING_LINE_NUM,
                    SHIPPING_HEADER_ID = :IF_SO_DTL_N.SHIPPING_HEADER_ID,
                    D4_SUM_ID = :IF_SO_DTL_N.D4_SUM_ID,
                    OE_HEADER_ID = :IF_SO_DTL_N.OE_HEADER_ID,
                    OE_LINE_ID = :IF_SO_DTL_N.OE_LINE_ID,
                    ORDER_TYPE = :IF_SO_DTL_N.ORDER_TYPE,
                    PRICE_TYPE = :IF_SO_DTL_N.PRICE_TYPE,
                    ITEM_ID = :IF_SO_DTL_N.ITEM_ID,
                    ITEM_CODE = :IF_SO_DTL_N.ITEM_CODE,
                    ITEM_DESC = :IF_SO_DTL_N.ITEM_DESC,
                    SHIPPING_QTY = :IF_SO_DTL_N.SHIPPING_QTY,
                    SHIPPING_UOM = :IF_SO_DTL_N.SHIPPING_UOM,
                    SALES_PRICE = :IF_SO_DTL_N.SALES_PRICE,
                    CURRENCY_CODE = :IF_SO_DTL_N.CURRENCY_CODE,
                    DATE_REQUESTED = :IF_SO_DTL_N.DATE_REQUESTED,
                    DATE_SCHEDULED = :IF_SO_DTL_N.DATE_SCHEDULED,
                    RELEASED_STATUS = :IF_SO_DTL_N.RELEASED_STATUS,
                    SHIP_TO_ORG_ID = :IF_SO_DTL_N.SHIP_TO_ORG_ID,
                    INVOICE_TO_ORG_ID = :IF_SO_DTL_N.INVOICE_TO_ORG_ID,
                    SHIP_FROM_INV_OPER = :IF_SO_DTL_N.SHIP_FROM_INV_OPER,
                    TRX_INV_OPER = :IF_SO_DTL_N.TRX_INV_OPER,
                    SHIP_TO_INV_OPER = :IF_SO_DTL_N.SHIP_TO_INV_OPER,
                    ACTUAL_DEPARTURE_DATE = :IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE,
                    PICK_STATUS = :IF_SO_DTL_N.PICK_STATUS,
                    SHIP_STATUS = :IF_SO_DTL_N.SHIP_STATUS,
                    SHIP_TO_LOCATION = :IF_SO_DTL_N.SHIP_TO_LOCATION,
                    PICK_CONFIRM_ID = :IF_SO_DTL_N.PICK_CONFIRM_ID,
                    ORIG_SYS_LINE_REF = :IF_SO_DTL_N.ORIG_SYS_LINE_REF,
                    DATE_SEQ = :IF_SO_DTL_N.DATE_SEQ,
                    SALESPERSON = :IF_SO_DTL_N.SALESPERSON,
                    SHIP_CONFIRM_ID = :IF_SO_DTL_N.SHIP_CONFIRM_ID,
                    PALLET_UNIT_QTY = :IF_SO_DTL_N.PALLET_UNIT_QTY,
                    ITEM_UNIT_WEIGHT = :IF_SO_DTL_N.ITEM_UNIT_WEIGHT,
                    PALLET_WEIGHT = :IF_SO_DTL_N.PALLET_WEIGHT,
                    PALLET_CNT = :IF_SO_DTL_N.PALLET_CNT,
                    TOTAL_WEIGHT = :IF_SO_DTL_N.TOTAL_WEIGHT,
                    ATTRIBUTE1 = :IF_SO_DTL_N.ATTRIBUTE1,
                    ATTRIBUTE2 = :IF_SO_DTL_N.ATTRIBUTE2,
                    ATTRIBUTE3 = :IF_SO_DTL_N.ATTRIBUTE3,
                    ATTRIBUTE4 = :IF_SO_DTL_N.ATTRIBUTE4,
                    ATTRIBUTE5 = :IF_SO_DTL_N.ATTRIBUTE5,
                    DEALING_NUMBER = :IF_SO_DTL_N.DEALING_NUMBER,
                    CUSTOMER_ITEM_CODE = :IF_SO_DTL_N.CUSTOMER_ITEM_CODE,
                    CUSTOMER_ITEM_DESC = :IF_SO_DTL_N.CUSTOMER_ITEM_DESC,
                    DEMAND_CLASS = :IF_SO_DTL_N.DEMAND_CLASS,
                    SHIPPING_DATE = :IF_SO_DTL_N.SHIPPING_DATE,
                    ORDER_NUMBER = :IF_SO_DTL_N.ORDER_NUMBER,
                    LINE_NUMBER = :IF_SO_DTL_N.LINE_NUMBER,
                    CREATED_BY = :IF_SO_DTL_N.CREATED_BY,
                    LAST_UPDATED_BY = :IF_SO_DTL_N.LAST_UPDATED_BY,
                    LAST_UPDATE_LOGIN = :IF_SO_DTL_N.LAST_UPDATE_LOGIN,
                    TRAN_FLAG = :IF_SO_DTL_N.TRAN_FLAG,
                    CMF_1 = :IF_SO_DTL_N.CMF_1,
                    CMF_2 = :IF_SO_DTL_N.CMF_2,
                    CMF_3 = :IF_SO_DTL_N.CMF_3,
                    CMF_4 = :IF_SO_DTL_N.CMF_4,
                    CMF_5 = :IF_SO_DTL_N.CMF_5,
                    CMF_6 = :IF_SO_DTL_N.CMF_6,
                    CMF_7 = :IF_SO_DTL_N.CMF_7,
                    CMF_8 = :IF_SO_DTL_N.CMF_8,
                    CMF_9 = :IF_SO_DTL_N.CMF_9,
                    CMF_10 = :IF_SO_DTL_N.CMF_10,
                    CREATE_USER_ID = :IF_SO_DTL_N.CREATE_USER_ID,
                    CREATE_TIME = :IF_SO_DTL_N.CREATE_TIME,
                    UPDATE_USER_ID = :IF_SO_DTL_N.UPDATE_USER_ID,
                    UPDATE_TIME = :IF_SO_DTL_N.UPDATE_TIME
                WHERE IF_SEQ = :IF_SO_DTL_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update IF_SO_DTL  set IF_TIME=:b0,IF_CODE=:b1,IF_MSG=:b2,FACT\
ORY=:b3,SHIPPING_LINE_ID=:b4,SHIPPING_LINE_NUM=:b5,SHIPPING_HEADER_ID=:b6,D4\
_SUM_ID=:b7,OE_HEADER_ID=:b8,OE_LINE_ID=:b9,ORDER_TYPE=:b10,PRICE_TYPE=:b11,\
ITEM_ID=:b12,ITEM_CODE=:b13,ITEM_DESC=:b14,SHIPPING_QTY=:b15,SHIPPING_UOM=:b\
16,SALES_PRICE=:b17,CURRENCY_CODE=:b18,DATE_REQUESTED=:b19,DATE_SCHEDULED=:b\
20,RELEASED_STATUS=:b21,SHIP_TO_ORG_ID=:b22,INVOICE_TO_ORG_ID=:b23,SHIP_FROM\
_INV_OPER=:b24,TRX_INV_OPER=:b25,SHIP_TO_INV_OPER=:b26,ACTUAL_DEPARTURE_DATE\
=:b27,PICK_STATUS=:b28,SHIP_STATUS=:b29,SHIP_TO_LOCATION=:b30,PICK_CONFIRM_I\
D=:b31,ORIG_SYS_LINE_REF=:b32,DATE_SEQ=:b33,SALESPERSON=:b34,SHIP_CONFIRM_ID\
=:b35,PALLET_UNIT_QTY=:b36,ITEM_UNIT_WEIGHT=:b37,PALLET_WEIGHT=:b38,PALLET_C\
NT=:b39,TOTAL_WEIGHT=:b40,ATTRIBUTE1=:b41,ATTRIBUTE2=:b42,ATTRIBUTE3=:b43,AT\
TRIBUTE4=:b44,ATTRIBUTE5=:b45,DEALING_NUMBER=:b46,CUSTOMER_ITEM_CODE=:b47,CU\
STOMER_ITEM_DESC=:b48,DEMAND_CLASS=:b49,SHIPPING_DATE=:b50,ORDER_NUMBER=:b51\
,LINE_NUMBER=:b52,CREATED_BY=:b53,LAST_UPDATED_BY=:");
            sqlstm.stmt = "b54,LAST_UPDATE_LOGIN=:b55,TRAN_FLAG=:b56,CMF_1=\
:b57,CMF_2=:b58,CMF_3=:b59,CMF_4=:b60,CMF_5=:b61,CMF_6=:b62,CMF_7=:b63,CMF_8=\
:b64,CMF_9=:b65,CMF_10=:b66,CREATE_USER_ID=:b67,CREATE_TIME=:b68,UPDATE_USER_\
ID=:b69,UPDATE_TIME=:b70 where IF_SEQ=:b71";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )964;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(IF_SO_DTL_N.IF_TIME);
            sqlstm.sqhstl[0] = (unsigned int  )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_SO_DTL_N.IF_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_SO_DTL_N.IF_MSG);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_SO_DTL_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_ID);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_SO_DTL_N.SHIPPING_HEADER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_SO_DTL_N.D4_SUM_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_SO_DTL_N.OE_HEADER_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_SO_DTL_N.OE_LINE_ID);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(IF_SO_DTL_N.ORDER_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_SO_DTL_N.PRICE_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(IF_SO_DTL_N.ITEM_ID);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(IF_SO_DTL_N.ITEM_CODE);
            sqlstm.sqhstl[13] = (unsigned int  )41;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_SO_DTL_N.ITEM_DESC);
            sqlstm.sqhstl[14] = (unsigned int  )241;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(IF_SO_DTL_N.SHIPPING_QTY);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(IF_SO_DTL_N.SHIPPING_UOM);
            sqlstm.sqhstl[16] = (unsigned int  )4;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(IF_SO_DTL_N.SALES_PRICE);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(IF_SO_DTL_N.CURRENCY_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )16;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_SO_DTL_N.DATE_REQUESTED);
            sqlstm.sqhstl[19] = (unsigned int  )15;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_SO_DTL_N.DATE_SCHEDULED);
            sqlstm.sqhstl[20] = (unsigned int  )15;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_SO_DTL_N.RELEASED_STATUS);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(IF_SO_DTL_N.SHIP_TO_ORG_ID);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(IF_SO_DTL_N.INVOICE_TO_ORG_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(IF_SO_DTL_N.SHIP_FROM_INV_OPER);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(IF_SO_DTL_N.TRX_INV_OPER);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(IF_SO_DTL_N.SHIP_TO_INV_OPER);
            sqlstm.sqhstl[26] = (unsigned int  )11;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE);
            sqlstm.sqhstl[27] = (unsigned int  )15;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_SO_DTL_N.PICK_STATUS);
            sqlstm.sqhstl[28] = (unsigned int  )2;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_SO_DTL_N.SHIP_STATUS);
            sqlstm.sqhstl[29] = (unsigned int  )3;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_SO_DTL_N.SHIP_TO_LOCATION);
            sqlstm.sqhstl[30] = (unsigned int  )41;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(IF_SO_DTL_N.PICK_CONFIRM_ID);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(IF_SO_DTL_N.ORIG_SYS_LINE_REF);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(IF_SO_DTL_N.DATE_SEQ);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(IF_SO_DTL_N.SALESPERSON);
            sqlstm.sqhstl[34] = (unsigned int  )241;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(IF_SO_DTL_N.SHIP_CONFIRM_ID);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(IF_SO_DTL_N.PALLET_UNIT_QTY);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(IF_SO_DTL_N.ITEM_UNIT_WEIGHT);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(IF_SO_DTL_N.PALLET_WEIGHT);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(IF_SO_DTL_N.PALLET_CNT);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(IF_SO_DTL_N.TOTAL_WEIGHT);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE1);
            sqlstm.sqhstl[41] = (unsigned int  )151;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE2);
            sqlstm.sqhstl[42] = (unsigned int  )151;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE3);
            sqlstm.sqhstl[43] = (unsigned int  )151;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE4);
            sqlstm.sqhstl[44] = (unsigned int  )151;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE5);
            sqlstm.sqhstl[45] = (unsigned int  )151;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(IF_SO_DTL_N.DEALING_NUMBER);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_CODE);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_DESC);
            sqlstm.sqhstl[48] = (unsigned int  )1001;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(IF_SO_DTL_N.DEMAND_CLASS);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(IF_SO_DTL_N.SHIPPING_DATE);
            sqlstm.sqhstl[50] = (unsigned int  )15;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)&(IF_SO_DTL_N.ORDER_NUMBER);
            sqlstm.sqhstl[51] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(IF_SO_DTL_N.LINE_NUMBER);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(IF_SO_DTL_N.CREATED_BY);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATED_BY);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATE_LOGIN);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(IF_SO_DTL_N.TRAN_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(IF_SO_DTL_N.CMF_1);
            sqlstm.sqhstl[57] = (unsigned int  )51;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(IF_SO_DTL_N.CMF_2);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(IF_SO_DTL_N.CMF_3);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(IF_SO_DTL_N.CMF_4);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(IF_SO_DTL_N.CMF_5);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(IF_SO_DTL_N.CMF_6);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(IF_SO_DTL_N.CMF_7);
            sqlstm.sqhstl[63] = (unsigned int  )51;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(IF_SO_DTL_N.CMF_8);
            sqlstm.sqhstl[64] = (unsigned int  )51;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(IF_SO_DTL_N.CMF_9);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(IF_SO_DTL_N.CMF_10);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(IF_SO_DTL_N.CREATE_USER_ID);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(IF_SO_DTL_N.CREATE_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(IF_SO_DTL_N.UPDATE_USER_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(IF_SO_DTL_N.UPDATE_TIME);
            sqlstm.sqhstl[70] = (unsigned int  )15;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
            sqlstm.sqhstl[71] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
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
            /* EXEC SQL UPDATE IF_SO_DTL SET
                    IF_CODE = :IF_SO_DTL_N.IF_CODE,
                    IF_MSG = :IF_SO_DTL_N.IF_MSG
                WHERE IF_SEQ = :IF_SO_DTL_N.IF_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update IF_SO_DTL  set IF_CODE=:b0,IF_MSG=:b1 whe\
re IF_SEQ=:b2";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1267;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(IF_SO_DTL_N.IF_CODE);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_SO_DTL_N.IF_MSG);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
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

    DB_stop_query_timer("DBU_update_if_so_dtl", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_if_so_dtl(int sel_type, struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_SO_DTL_N_TAG IF_SO_DTL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_if_so_dtl(&IF_SO_DTL_N, IF_SO_DTL);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_IF_SO_DTL_CUR_1 CURSOR FOR
                SELECT 
                    IF_SEQ,
                    IF_TIME,
                    IF_CODE,
                    IF_MSG,
                    FACTORY,
                    SHIPPING_LINE_ID,
                    SHIPPING_LINE_NUM,
                    SHIPPING_HEADER_ID,
                    D4_SUM_ID,
                    OE_HEADER_ID,
                    OE_LINE_ID,
                    ORDER_TYPE,
                    PRICE_TYPE,
                    ITEM_ID,
                    ITEM_CODE,
                    ITEM_DESC,
                    SHIPPING_QTY,
                    SHIPPING_UOM,
                    SALES_PRICE,
                    CURRENCY_CODE,
                    DATE_REQUESTED,
                    DATE_SCHEDULED,
                    RELEASED_STATUS,
                    SHIP_TO_ORG_ID,
                    INVOICE_TO_ORG_ID,
                    SHIP_FROM_INV_OPER,
                    TRX_INV_OPER,
                    SHIP_TO_INV_OPER,
                    ACTUAL_DEPARTURE_DATE,
                    PICK_STATUS,
                    SHIP_STATUS,
                    SHIP_TO_LOCATION,
                    PICK_CONFIRM_ID,
                    ORIG_SYS_LINE_REF,
                    DATE_SEQ,
                    SALESPERSON,
                    SHIP_CONFIRM_ID,
                    PALLET_UNIT_QTY,
                    ITEM_UNIT_WEIGHT,
                    PALLET_WEIGHT,
                    PALLET_CNT,
                    TOTAL_WEIGHT,
                    ATTRIBUTE1,
                    ATTRIBUTE2,
                    ATTRIBUTE3,
                    ATTRIBUTE4,
                    ATTRIBUTE5,
                    DEALING_NUMBER,
                    CUSTOMER_ITEM_CODE,
                    CUSTOMER_ITEM_DESC,
                    DEMAND_CLASS,
                    SHIPPING_DATE,
                    ORDER_NUMBER,
                    LINE_NUMBER,
                    CREATED_BY,
                    LAST_UPDATED_BY,
                    LAST_UPDATE_LOGIN,
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
                FROM IF_SO_DTL
                ORDER BY IF_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_IF_SO_DTL_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1294;
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
            /* EXEC SQL DECLARE DBU_IF_SO_DTL_CUR_101 CURSOR FOR
                SELECT 
                    IF_SEQ,
                    IF_TIME,
                    IF_CODE,
                    IF_MSG,
                    FACTORY,
                    SHIPPING_LINE_ID,
                    SHIPPING_LINE_NUM,
                    SHIPPING_HEADER_ID,
                    D4_SUM_ID,
                    OE_HEADER_ID,
                    OE_LINE_ID,
                    ORDER_TYPE,
                    PRICE_TYPE,
                    ITEM_ID,
                    ITEM_CODE,
                    ITEM_DESC,
                    SHIPPING_QTY,
                    SHIPPING_UOM,
                    SALES_PRICE,
                    CURRENCY_CODE,
                    DATE_REQUESTED,
                    DATE_SCHEDULED,
                    RELEASED_STATUS,
                    SHIP_TO_ORG_ID,
                    INVOICE_TO_ORG_ID,
                    SHIP_FROM_INV_OPER,
                    TRX_INV_OPER,
                    SHIP_TO_INV_OPER,
                    ACTUAL_DEPARTURE_DATE,
                    PICK_STATUS,
                    SHIP_STATUS,
                    SHIP_TO_LOCATION,
                    PICK_CONFIRM_ID,
                    ORIG_SYS_LINE_REF,
                    DATE_SEQ,
                    SALESPERSON,
                    SHIP_CONFIRM_ID,
                    PALLET_UNIT_QTY,
                    ITEM_UNIT_WEIGHT,
                    PALLET_WEIGHT,
                    PALLET_CNT,
                    TOTAL_WEIGHT,
                    ATTRIBUTE1,
                    ATTRIBUTE2,
                    ATTRIBUTE3,
                    ATTRIBUTE4,
                    ATTRIBUTE5,
                    DEALING_NUMBER,
                    CUSTOMER_ITEM_CODE,
                    CUSTOMER_ITEM_DESC,
                    DEMAND_CLASS,
                    SHIPPING_DATE,
                    ORDER_NUMBER,
                    LINE_NUMBER,
                    CREATED_BY,
                    LAST_UPDATED_BY,
                    LAST_UPDATE_LOGIN,
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
                FROM IF_SO_DTL
				WHERE IF_CODE = 'N'
				AND ROWNUM <= 2000
                ORDER BY IF_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_IF_SO_DTL_CUR_101; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select IF_SEQ ,IF_TIME ,IF_CODE ,IF_MSG ,FACTORY ,SHIPPING_LI\
NE_ID ,SHIPPING_LINE_NUM ,SHIPPING_HEADER_ID ,D4_SUM_ID ,OE_HEADER_ID ,OE_LI\
NE_ID ,ORDER_TYPE ,PRICE_TYPE ,ITEM_ID ,ITEM_CODE ,ITEM_DESC ,SHIPPING_QTY ,\
SHIPPING_UOM ,SALES_PRICE ,CURRENCY_CODE ,DATE_REQUESTED ,DATE_SCHEDULED ,RE\
LEASED_STATUS ,SHIP_TO_ORG_ID ,INVOICE_TO_ORG_ID ,SHIP_FROM_INV_OPER ,TRX_IN\
V_OPER ,SHIP_TO_INV_OPER ,ACTUAL_DEPARTURE_DATE ,PICK_STATUS ,SHIP_STATUS ,S\
HIP_TO_LOCATION ,PICK_CONFIRM_ID ,ORIG_SYS_LINE_REF ,DATE_SEQ ,SALESPERSON ,\
SHIP_CONFIRM_ID ,PALLET_UNIT_QTY ,ITEM_UNIT_WEIGHT ,PALLET_WEIGHT ,PALLET_CN\
T ,TOTAL_WEIGHT ,ATTRIBUTE1 ,ATTRIBUTE2 ,ATTRIBUTE3 ,ATTRIBUTE4 ,ATTRIBUTE5 \
,DEALING_NUMBER ,CUSTOMER_ITEM_CODE ,CUSTOMER_ITEM_DESC ,DEMAND_CLASS ,SHIPP\
ING_DATE ,ORDER_NUMBER ,LINE_NUMBER ,CREATED_BY ,LAST_UPDATED_BY ,LAST_UPDAT\
E_LOGIN ,TRAN_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,\
CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  fro\
m IF_SO_DTL where (IF_CODE='N' and ROWNUM<=2000) or");
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1309;
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

    DB_stop_query_timer("DBU_open_if_so_dtl", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_if_so_dtl(int sel_type, struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct IF_SO_DTL_N_TAG IF_SO_DTL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_IF_SO_DTL_CUR_1 INTO
                :IF_SO_DTL_N.IF_SEQ,
                :IF_SO_DTL_N.IF_TIME,
                :IF_SO_DTL_N.IF_CODE,
                :IF_SO_DTL_N.IF_MSG,
                :IF_SO_DTL_N.FACTORY,
                :IF_SO_DTL_N.SHIPPING_LINE_ID,
                :IF_SO_DTL_N.SHIPPING_LINE_NUM,
                :IF_SO_DTL_N.SHIPPING_HEADER_ID,
                :IF_SO_DTL_N.D4_SUM_ID,
                :IF_SO_DTL_N.OE_HEADER_ID,
                :IF_SO_DTL_N.OE_LINE_ID,
                :IF_SO_DTL_N.ORDER_TYPE,
                :IF_SO_DTL_N.PRICE_TYPE,
                :IF_SO_DTL_N.ITEM_ID,
                :IF_SO_DTL_N.ITEM_CODE,
                :IF_SO_DTL_N.ITEM_DESC,
                :IF_SO_DTL_N.SHIPPING_QTY,
                :IF_SO_DTL_N.SHIPPING_UOM,
                :IF_SO_DTL_N.SALES_PRICE,
                :IF_SO_DTL_N.CURRENCY_CODE,
                :IF_SO_DTL_N.DATE_REQUESTED,
                :IF_SO_DTL_N.DATE_SCHEDULED,
                :IF_SO_DTL_N.RELEASED_STATUS,
                :IF_SO_DTL_N.SHIP_TO_ORG_ID,
                :IF_SO_DTL_N.INVOICE_TO_ORG_ID,
                :IF_SO_DTL_N.SHIP_FROM_INV_OPER,
                :IF_SO_DTL_N.TRX_INV_OPER,
                :IF_SO_DTL_N.SHIP_TO_INV_OPER,
                :IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE,
                :IF_SO_DTL_N.PICK_STATUS,
                :IF_SO_DTL_N.SHIP_STATUS,
                :IF_SO_DTL_N.SHIP_TO_LOCATION,
                :IF_SO_DTL_N.PICK_CONFIRM_ID,
                :IF_SO_DTL_N.ORIG_SYS_LINE_REF,
                :IF_SO_DTL_N.DATE_SEQ,
                :IF_SO_DTL_N.SALESPERSON,
                :IF_SO_DTL_N.SHIP_CONFIRM_ID,
                :IF_SO_DTL_N.PALLET_UNIT_QTY,
                :IF_SO_DTL_N.ITEM_UNIT_WEIGHT,
                :IF_SO_DTL_N.PALLET_WEIGHT,
                :IF_SO_DTL_N.PALLET_CNT,
                :IF_SO_DTL_N.TOTAL_WEIGHT,
                :IF_SO_DTL_N.ATTRIBUTE1,
                :IF_SO_DTL_N.ATTRIBUTE2,
                :IF_SO_DTL_N.ATTRIBUTE3,
                :IF_SO_DTL_N.ATTRIBUTE4,
                :IF_SO_DTL_N.ATTRIBUTE5,
                :IF_SO_DTL_N.DEALING_NUMBER,
                :IF_SO_DTL_N.CUSTOMER_ITEM_CODE,
                :IF_SO_DTL_N.CUSTOMER_ITEM_DESC,
                :IF_SO_DTL_N.DEMAND_CLASS,
                :IF_SO_DTL_N.SHIPPING_DATE,
                :IF_SO_DTL_N.ORDER_NUMBER,
                :IF_SO_DTL_N.LINE_NUMBER,
                :IF_SO_DTL_N.CREATED_BY,
                :IF_SO_DTL_N.LAST_UPDATED_BY,
                :IF_SO_DTL_N.LAST_UPDATE_LOGIN,
                :IF_SO_DTL_N.TRAN_FLAG,
                :IF_SO_DTL_N.CMF_1,
                :IF_SO_DTL_N.CMF_2,
                :IF_SO_DTL_N.CMF_3,
                :IF_SO_DTL_N.CMF_4,
                :IF_SO_DTL_N.CMF_5,
                :IF_SO_DTL_N.CMF_6,
                :IF_SO_DTL_N.CMF_7,
                :IF_SO_DTL_N.CMF_8,
                :IF_SO_DTL_N.CMF_9,
                :IF_SO_DTL_N.CMF_10,
                :IF_SO_DTL_N.CREATE_USER_ID,
                :IF_SO_DTL_N.CREATE_TIME,
                :IF_SO_DTL_N.UPDATE_USER_ID,
                :IF_SO_DTL_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1324;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_SO_DTL_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_SO_DTL_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_SO_DTL_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_SO_DTL_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_SO_DTL_N.SHIPPING_HEADER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_SO_DTL_N.D4_SUM_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_SO_DTL_N.OE_HEADER_ID);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(IF_SO_DTL_N.OE_LINE_ID);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_SO_DTL_N.ORDER_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_SO_DTL_N.PRICE_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(IF_SO_DTL_N.ITEM_ID);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_SO_DTL_N.ITEM_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )41;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_SO_DTL_N.ITEM_DESC);
            sqlstm.sqhstl[15] = (unsigned int  )241;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(IF_SO_DTL_N.SHIPPING_QTY);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_SO_DTL_N.SHIPPING_UOM);
            sqlstm.sqhstl[17] = (unsigned int  )4;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_SO_DTL_N.SALES_PRICE);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_SO_DTL_N.CURRENCY_CODE);
            sqlstm.sqhstl[19] = (unsigned int  )16;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_SO_DTL_N.DATE_REQUESTED);
            sqlstm.sqhstl[20] = (unsigned int  )15;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_SO_DTL_N.DATE_SCHEDULED);
            sqlstm.sqhstl[21] = (unsigned int  )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_SO_DTL_N.RELEASED_STATUS);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(IF_SO_DTL_N.SHIP_TO_ORG_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(IF_SO_DTL_N.INVOICE_TO_ORG_ID);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(IF_SO_DTL_N.SHIP_FROM_INV_OPER);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(IF_SO_DTL_N.TRX_INV_OPER);
            sqlstm.sqhstl[26] = (unsigned int  )11;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_SO_DTL_N.SHIP_TO_INV_OPER);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )15;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_SO_DTL_N.PICK_STATUS);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_SO_DTL_N.SHIP_STATUS);
            sqlstm.sqhstl[30] = (unsigned int  )3;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_SO_DTL_N.SHIP_TO_LOCATION);
            sqlstm.sqhstl[31] = (unsigned int  )41;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(IF_SO_DTL_N.PICK_CONFIRM_ID);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_SO_DTL_N.ORIG_SYS_LINE_REF);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(IF_SO_DTL_N.DATE_SEQ);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_SO_DTL_N.SALESPERSON);
            sqlstm.sqhstl[35] = (unsigned int  )241;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(IF_SO_DTL_N.SHIP_CONFIRM_ID);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(IF_SO_DTL_N.PALLET_UNIT_QTY);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(IF_SO_DTL_N.ITEM_UNIT_WEIGHT);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(IF_SO_DTL_N.PALLET_WEIGHT);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(IF_SO_DTL_N.PALLET_CNT);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(IF_SO_DTL_N.TOTAL_WEIGHT);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE1);
            sqlstm.sqhstl[42] = (unsigned int  )151;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE2);
            sqlstm.sqhstl[43] = (unsigned int  )151;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE3);
            sqlstm.sqhstl[44] = (unsigned int  )151;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE4);
            sqlstm.sqhstl[45] = (unsigned int  )151;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE5);
            sqlstm.sqhstl[46] = (unsigned int  )151;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(IF_SO_DTL_N.DEALING_NUMBER);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_CODE);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_DESC);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(IF_SO_DTL_N.DEMAND_CLASS);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(IF_SO_DTL_N.SHIPPING_DATE);
            sqlstm.sqhstl[51] = (unsigned int  )15;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(IF_SO_DTL_N.ORDER_NUMBER);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(IF_SO_DTL_N.LINE_NUMBER);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(IF_SO_DTL_N.CREATED_BY);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATED_BY);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATE_LOGIN);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(IF_SO_DTL_N.TRAN_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(IF_SO_DTL_N.CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(IF_SO_DTL_N.CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(IF_SO_DTL_N.CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(IF_SO_DTL_N.CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(IF_SO_DTL_N.CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(IF_SO_DTL_N.CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )51;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(IF_SO_DTL_N.CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )51;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(IF_SO_DTL_N.CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(IF_SO_DTL_N.CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(IF_SO_DTL_N.CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(IF_SO_DTL_N.CREATE_USER_ID);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(IF_SO_DTL_N.CREATE_TIME);
            sqlstm.sqhstl[69] = (unsigned int  )15;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(IF_SO_DTL_N.UPDATE_USER_ID);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(IF_SO_DTL_N.UPDATE_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_IF_SO_DTL_CUR_101 INTO
                :IF_SO_DTL_N.IF_SEQ,
                :IF_SO_DTL_N.IF_TIME,
                :IF_SO_DTL_N.IF_CODE,
                :IF_SO_DTL_N.IF_MSG,
                :IF_SO_DTL_N.FACTORY,
                :IF_SO_DTL_N.SHIPPING_LINE_ID,
                :IF_SO_DTL_N.SHIPPING_LINE_NUM,
                :IF_SO_DTL_N.SHIPPING_HEADER_ID,
                :IF_SO_DTL_N.D4_SUM_ID,
                :IF_SO_DTL_N.OE_HEADER_ID,
                :IF_SO_DTL_N.OE_LINE_ID,
                :IF_SO_DTL_N.ORDER_TYPE,
                :IF_SO_DTL_N.PRICE_TYPE,
                :IF_SO_DTL_N.ITEM_ID,
                :IF_SO_DTL_N.ITEM_CODE,
                :IF_SO_DTL_N.ITEM_DESC,
                :IF_SO_DTL_N.SHIPPING_QTY,
                :IF_SO_DTL_N.SHIPPING_UOM,
                :IF_SO_DTL_N.SALES_PRICE,
                :IF_SO_DTL_N.CURRENCY_CODE,
                :IF_SO_DTL_N.DATE_REQUESTED,
                :IF_SO_DTL_N.DATE_SCHEDULED,
                :IF_SO_DTL_N.RELEASED_STATUS,
                :IF_SO_DTL_N.SHIP_TO_ORG_ID,
                :IF_SO_DTL_N.INVOICE_TO_ORG_ID,
                :IF_SO_DTL_N.SHIP_FROM_INV_OPER,
                :IF_SO_DTL_N.TRX_INV_OPER,
                :IF_SO_DTL_N.SHIP_TO_INV_OPER,
                :IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE,
                :IF_SO_DTL_N.PICK_STATUS,
                :IF_SO_DTL_N.SHIP_STATUS,
                :IF_SO_DTL_N.SHIP_TO_LOCATION,
                :IF_SO_DTL_N.PICK_CONFIRM_ID,
                :IF_SO_DTL_N.ORIG_SYS_LINE_REF,
                :IF_SO_DTL_N.DATE_SEQ,
                :IF_SO_DTL_N.SALESPERSON,
                :IF_SO_DTL_N.SHIP_CONFIRM_ID,
                :IF_SO_DTL_N.PALLET_UNIT_QTY,
                :IF_SO_DTL_N.ITEM_UNIT_WEIGHT,
                :IF_SO_DTL_N.PALLET_WEIGHT,
                :IF_SO_DTL_N.PALLET_CNT,
                :IF_SO_DTL_N.TOTAL_WEIGHT,
                :IF_SO_DTL_N.ATTRIBUTE1,
                :IF_SO_DTL_N.ATTRIBUTE2,
                :IF_SO_DTL_N.ATTRIBUTE3,
                :IF_SO_DTL_N.ATTRIBUTE4,
                :IF_SO_DTL_N.ATTRIBUTE5,
                :IF_SO_DTL_N.DEALING_NUMBER,
                :IF_SO_DTL_N.CUSTOMER_ITEM_CODE,
                :IF_SO_DTL_N.CUSTOMER_ITEM_DESC,
                :IF_SO_DTL_N.DEMAND_CLASS,
                :IF_SO_DTL_N.SHIPPING_DATE,
                :IF_SO_DTL_N.ORDER_NUMBER,
                :IF_SO_DTL_N.LINE_NUMBER,
                :IF_SO_DTL_N.CREATED_BY,
                :IF_SO_DTL_N.LAST_UPDATED_BY,
                :IF_SO_DTL_N.LAST_UPDATE_LOGIN,
                :IF_SO_DTL_N.TRAN_FLAG,
                :IF_SO_DTL_N.CMF_1,
                :IF_SO_DTL_N.CMF_2,
                :IF_SO_DTL_N.CMF_3,
                :IF_SO_DTL_N.CMF_4,
                :IF_SO_DTL_N.CMF_5,
                :IF_SO_DTL_N.CMF_6,
                :IF_SO_DTL_N.CMF_7,
                :IF_SO_DTL_N.CMF_8,
                :IF_SO_DTL_N.CMF_9,
                :IF_SO_DTL_N.CMF_10,
                :IF_SO_DTL_N.CREATE_USER_ID,
                :IF_SO_DTL_N.CREATE_TIME,
                :IF_SO_DTL_N.UPDATE_USER_ID,
                :IF_SO_DTL_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1627;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(IF_SO_DTL_N.IF_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(IF_SO_DTL_N.IF_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(IF_SO_DTL_N.IF_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(IF_SO_DTL_N.IF_MSG);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(IF_SO_DTL_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_ID);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(IF_SO_DTL_N.SHIPPING_LINE_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(IF_SO_DTL_N.SHIPPING_HEADER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(IF_SO_DTL_N.D4_SUM_ID);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(IF_SO_DTL_N.OE_HEADER_ID);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(IF_SO_DTL_N.OE_LINE_ID);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(IF_SO_DTL_N.ORDER_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(IF_SO_DTL_N.PRICE_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(IF_SO_DTL_N.ITEM_ID);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(IF_SO_DTL_N.ITEM_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )41;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(IF_SO_DTL_N.ITEM_DESC);
            sqlstm.sqhstl[15] = (unsigned int  )241;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(IF_SO_DTL_N.SHIPPING_QTY);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(IF_SO_DTL_N.SHIPPING_UOM);
            sqlstm.sqhstl[17] = (unsigned int  )4;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(IF_SO_DTL_N.SALES_PRICE);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(IF_SO_DTL_N.CURRENCY_CODE);
            sqlstm.sqhstl[19] = (unsigned int  )16;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(IF_SO_DTL_N.DATE_REQUESTED);
            sqlstm.sqhstl[20] = (unsigned int  )15;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(IF_SO_DTL_N.DATE_SCHEDULED);
            sqlstm.sqhstl[21] = (unsigned int  )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(IF_SO_DTL_N.RELEASED_STATUS);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(IF_SO_DTL_N.SHIP_TO_ORG_ID);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(IF_SO_DTL_N.INVOICE_TO_ORG_ID);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(IF_SO_DTL_N.SHIP_FROM_INV_OPER);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(IF_SO_DTL_N.TRX_INV_OPER);
            sqlstm.sqhstl[26] = (unsigned int  )11;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(IF_SO_DTL_N.SHIP_TO_INV_OPER);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(IF_SO_DTL_N.ACTUAL_DEPARTURE_DATE);
            sqlstm.sqhstl[28] = (unsigned int  )15;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(IF_SO_DTL_N.PICK_STATUS);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(IF_SO_DTL_N.SHIP_STATUS);
            sqlstm.sqhstl[30] = (unsigned int  )3;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(IF_SO_DTL_N.SHIP_TO_LOCATION);
            sqlstm.sqhstl[31] = (unsigned int  )41;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(IF_SO_DTL_N.PICK_CONFIRM_ID);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(IF_SO_DTL_N.ORIG_SYS_LINE_REF);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(IF_SO_DTL_N.DATE_SEQ);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(IF_SO_DTL_N.SALESPERSON);
            sqlstm.sqhstl[35] = (unsigned int  )241;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(IF_SO_DTL_N.SHIP_CONFIRM_ID);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(IF_SO_DTL_N.PALLET_UNIT_QTY);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(IF_SO_DTL_N.ITEM_UNIT_WEIGHT);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(IF_SO_DTL_N.PALLET_WEIGHT);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(IF_SO_DTL_N.PALLET_CNT);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(IF_SO_DTL_N.TOTAL_WEIGHT);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE1);
            sqlstm.sqhstl[42] = (unsigned int  )151;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE2);
            sqlstm.sqhstl[43] = (unsigned int  )151;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE3);
            sqlstm.sqhstl[44] = (unsigned int  )151;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE4);
            sqlstm.sqhstl[45] = (unsigned int  )151;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(IF_SO_DTL_N.ATTRIBUTE5);
            sqlstm.sqhstl[46] = (unsigned int  )151;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(IF_SO_DTL_N.DEALING_NUMBER);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_CODE);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(IF_SO_DTL_N.CUSTOMER_ITEM_DESC);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(IF_SO_DTL_N.DEMAND_CLASS);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(IF_SO_DTL_N.SHIPPING_DATE);
            sqlstm.sqhstl[51] = (unsigned int  )15;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(IF_SO_DTL_N.ORDER_NUMBER);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(IF_SO_DTL_N.LINE_NUMBER);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(IF_SO_DTL_N.CREATED_BY);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATED_BY);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(IF_SO_DTL_N.LAST_UPDATE_LOGIN);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(IF_SO_DTL_N.TRAN_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(IF_SO_DTL_N.CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )51;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(IF_SO_DTL_N.CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )51;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(IF_SO_DTL_N.CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )51;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(IF_SO_DTL_N.CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )51;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(IF_SO_DTL_N.CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )51;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(IF_SO_DTL_N.CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )51;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(IF_SO_DTL_N.CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )51;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(IF_SO_DTL_N.CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(IF_SO_DTL_N.CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(IF_SO_DTL_N.CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(IF_SO_DTL_N.CREATE_USER_ID);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(IF_SO_DTL_N.CREATE_TIME);
            sqlstm.sqhstl[69] = (unsigned int  )15;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(IF_SO_DTL_N.UPDATE_USER_ID);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(IF_SO_DTL_N.UPDATE_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
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
        DBU_del_null_if_so_dtl(&IF_SO_DTL_N, IF_SO_DTL);
    }

    DB_stop_query_timer("DBU_fetch_if_so_dtl", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_if_so_dtl(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_IF_SO_DTL_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1930;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 101:
            /* EXEC SQL CLOSE DBU_IF_SO_DTL_CUR_101; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1945;
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

    DB_stop_query_timer("DBU_close_if_so_dtl", sel_type);
}


/* Initialize Function */
void DBU_init_if_so_dtl(struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    /* memset by Space */
    memset(IF_SO_DTL, ' ', sizeof(struct IF_SO_DTL_TAG));
    
    IF_SO_DTL->IF_SEQ = 0;
    IF_SO_DTL->SHIPPING_LINE_ID = 0;
    IF_SO_DTL->SHIPPING_LINE_NUM = 0;
    IF_SO_DTL->SHIPPING_HEADER_ID = 0;
    IF_SO_DTL->D4_SUM_ID = 0;
    IF_SO_DTL->OE_HEADER_ID = 0;
    IF_SO_DTL->OE_LINE_ID = 0;
    IF_SO_DTL->ITEM_ID = 0;
    IF_SO_DTL->SHIPPING_QTY = 0;
    IF_SO_DTL->SALES_PRICE = 0;
    IF_SO_DTL->SHIP_TO_ORG_ID = 0;
    IF_SO_DTL->INVOICE_TO_ORG_ID = 0;
    IF_SO_DTL->PICK_CONFIRM_ID = 0;
    IF_SO_DTL->DATE_SEQ = 0;
    IF_SO_DTL->SHIP_CONFIRM_ID = 0;
    IF_SO_DTL->PALLET_UNIT_QTY = 0;
    IF_SO_DTL->ITEM_UNIT_WEIGHT = 0;
    IF_SO_DTL->PALLET_WEIGHT = 0;
    IF_SO_DTL->PALLET_CNT = 0;
    IF_SO_DTL->TOTAL_WEIGHT = 0;
    IF_SO_DTL->ORDER_NUMBER = 0;
    IF_SO_DTL->LINE_NUMBER = 0;
    IF_SO_DTL->CREATED_BY = 0;
    IF_SO_DTL->LAST_UPDATED_BY = 0;
    IF_SO_DTL->LAST_UPDATE_LOGIN = 0;
}


/* Add Null Function */
void DBU_add_null_if_so_dtl(struct IF_SO_DTL_N_TAG *IF_SO_DTL_N, struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    /* memset by NULL */
    memset(IF_SO_DTL_N, '\0', sizeof(struct IF_SO_DTL_N_TAG));
    
    IF_SO_DTL_N->IF_SEQ = IF_SO_DTL->IF_SEQ;
    MEMCPY_AN(IF_SO_DTL_N->IF_TIME, IF_SO_DTL->IF_TIME, sizeof(IF_SO_DTL->IF_TIME));
    IF_SO_DTL_N->IF_CODE[0] = IF_SO_DTL->IF_CODE;
    MEMCPY_AN(IF_SO_DTL_N->IF_MSG, IF_SO_DTL->IF_MSG, sizeof(IF_SO_DTL->IF_MSG));
    MEMCPY_AN(IF_SO_DTL_N->FACTORY, IF_SO_DTL->FACTORY, sizeof(IF_SO_DTL->FACTORY));
    IF_SO_DTL_N->SHIPPING_LINE_ID = IF_SO_DTL->SHIPPING_LINE_ID;
    IF_SO_DTL_N->SHIPPING_LINE_NUM = IF_SO_DTL->SHIPPING_LINE_NUM;
    IF_SO_DTL_N->SHIPPING_HEADER_ID = IF_SO_DTL->SHIPPING_HEADER_ID;
    IF_SO_DTL_N->D4_SUM_ID = IF_SO_DTL->D4_SUM_ID;
    IF_SO_DTL_N->OE_HEADER_ID = IF_SO_DTL->OE_HEADER_ID;
    IF_SO_DTL_N->OE_LINE_ID = IF_SO_DTL->OE_LINE_ID;
    MEMCPY_AN(IF_SO_DTL_N->ORDER_TYPE, IF_SO_DTL->ORDER_TYPE, sizeof(IF_SO_DTL->ORDER_TYPE));
    MEMCPY_AN(IF_SO_DTL_N->PRICE_TYPE, IF_SO_DTL->PRICE_TYPE, sizeof(IF_SO_DTL->PRICE_TYPE));
    IF_SO_DTL_N->ITEM_ID = IF_SO_DTL->ITEM_ID;
    MEMCPY_AN(IF_SO_DTL_N->ITEM_CODE, IF_SO_DTL->ITEM_CODE, sizeof(IF_SO_DTL->ITEM_CODE));
    MEMCPY_AN(IF_SO_DTL_N->ITEM_DESC, IF_SO_DTL->ITEM_DESC, sizeof(IF_SO_DTL->ITEM_DESC));
    IF_SO_DTL_N->SHIPPING_QTY = IF_SO_DTL->SHIPPING_QTY;
    MEMCPY_AN(IF_SO_DTL_N->SHIPPING_UOM, IF_SO_DTL->SHIPPING_UOM, sizeof(IF_SO_DTL->SHIPPING_UOM));
    IF_SO_DTL_N->SALES_PRICE = IF_SO_DTL->SALES_PRICE;
    MEMCPY_AN(IF_SO_DTL_N->CURRENCY_CODE, IF_SO_DTL->CURRENCY_CODE, sizeof(IF_SO_DTL->CURRENCY_CODE));
    MEMCPY_AN(IF_SO_DTL_N->DATE_REQUESTED, IF_SO_DTL->DATE_REQUESTED, sizeof(IF_SO_DTL->DATE_REQUESTED));
    MEMCPY_AN(IF_SO_DTL_N->DATE_SCHEDULED, IF_SO_DTL->DATE_SCHEDULED, sizeof(IF_SO_DTL->DATE_SCHEDULED));
    IF_SO_DTL_N->RELEASED_STATUS[0] = IF_SO_DTL->RELEASED_STATUS;
    IF_SO_DTL_N->SHIP_TO_ORG_ID = IF_SO_DTL->SHIP_TO_ORG_ID;
    IF_SO_DTL_N->INVOICE_TO_ORG_ID = IF_SO_DTL->INVOICE_TO_ORG_ID;
    MEMCPY_AN(IF_SO_DTL_N->SHIP_FROM_INV_OPER, IF_SO_DTL->SHIP_FROM_INV_OPER, sizeof(IF_SO_DTL->SHIP_FROM_INV_OPER));
    MEMCPY_AN(IF_SO_DTL_N->TRX_INV_OPER, IF_SO_DTL->TRX_INV_OPER, sizeof(IF_SO_DTL->TRX_INV_OPER));
    MEMCPY_AN(IF_SO_DTL_N->SHIP_TO_INV_OPER, IF_SO_DTL->SHIP_TO_INV_OPER, sizeof(IF_SO_DTL->SHIP_TO_INV_OPER));
    MEMCPY_AN(IF_SO_DTL_N->ACTUAL_DEPARTURE_DATE, IF_SO_DTL->ACTUAL_DEPARTURE_DATE, sizeof(IF_SO_DTL->ACTUAL_DEPARTURE_DATE));
    IF_SO_DTL_N->PICK_STATUS[0] = IF_SO_DTL->PICK_STATUS;
    MEMCPY_AN(IF_SO_DTL_N->SHIP_STATUS, IF_SO_DTL->SHIP_STATUS, sizeof(IF_SO_DTL->SHIP_STATUS));
    MEMCPY_AN(IF_SO_DTL_N->SHIP_TO_LOCATION, IF_SO_DTL->SHIP_TO_LOCATION, sizeof(IF_SO_DTL->SHIP_TO_LOCATION));
    IF_SO_DTL_N->PICK_CONFIRM_ID = IF_SO_DTL->PICK_CONFIRM_ID;
    MEMCPY_AN(IF_SO_DTL_N->ORIG_SYS_LINE_REF, IF_SO_DTL->ORIG_SYS_LINE_REF, sizeof(IF_SO_DTL->ORIG_SYS_LINE_REF));
    IF_SO_DTL_N->DATE_SEQ = IF_SO_DTL->DATE_SEQ;
    MEMCPY_AN(IF_SO_DTL_N->SALESPERSON, IF_SO_DTL->SALESPERSON, sizeof(IF_SO_DTL->SALESPERSON));
    IF_SO_DTL_N->SHIP_CONFIRM_ID = IF_SO_DTL->SHIP_CONFIRM_ID;
    IF_SO_DTL_N->PALLET_UNIT_QTY = IF_SO_DTL->PALLET_UNIT_QTY;
    IF_SO_DTL_N->ITEM_UNIT_WEIGHT = IF_SO_DTL->ITEM_UNIT_WEIGHT;
    IF_SO_DTL_N->PALLET_WEIGHT = IF_SO_DTL->PALLET_WEIGHT;
    IF_SO_DTL_N->PALLET_CNT = IF_SO_DTL->PALLET_CNT;
    IF_SO_DTL_N->TOTAL_WEIGHT = IF_SO_DTL->TOTAL_WEIGHT;
    MEMCPY_AN(IF_SO_DTL_N->ATTRIBUTE1, IF_SO_DTL->ATTRIBUTE1, sizeof(IF_SO_DTL->ATTRIBUTE1));
    MEMCPY_AN(IF_SO_DTL_N->ATTRIBUTE2, IF_SO_DTL->ATTRIBUTE2, sizeof(IF_SO_DTL->ATTRIBUTE2));
    MEMCPY_AN(IF_SO_DTL_N->ATTRIBUTE3, IF_SO_DTL->ATTRIBUTE3, sizeof(IF_SO_DTL->ATTRIBUTE3));
    MEMCPY_AN(IF_SO_DTL_N->ATTRIBUTE4, IF_SO_DTL->ATTRIBUTE4, sizeof(IF_SO_DTL->ATTRIBUTE4));
    MEMCPY_AN(IF_SO_DTL_N->ATTRIBUTE5, IF_SO_DTL->ATTRIBUTE5, sizeof(IF_SO_DTL->ATTRIBUTE5));
    MEMCPY_AN(IF_SO_DTL_N->DEALING_NUMBER, IF_SO_DTL->DEALING_NUMBER, sizeof(IF_SO_DTL->DEALING_NUMBER));
    MEMCPY_AN(IF_SO_DTL_N->CUSTOMER_ITEM_CODE, IF_SO_DTL->CUSTOMER_ITEM_CODE, sizeof(IF_SO_DTL->CUSTOMER_ITEM_CODE));
    MEMCPY_AN(IF_SO_DTL_N->CUSTOMER_ITEM_DESC, IF_SO_DTL->CUSTOMER_ITEM_DESC, sizeof(IF_SO_DTL->CUSTOMER_ITEM_DESC));
    MEMCPY_AN(IF_SO_DTL_N->DEMAND_CLASS, IF_SO_DTL->DEMAND_CLASS, sizeof(IF_SO_DTL->DEMAND_CLASS));
    MEMCPY_AN(IF_SO_DTL_N->SHIPPING_DATE, IF_SO_DTL->SHIPPING_DATE, sizeof(IF_SO_DTL->SHIPPING_DATE));
    IF_SO_DTL_N->ORDER_NUMBER = IF_SO_DTL->ORDER_NUMBER;
    IF_SO_DTL_N->LINE_NUMBER = IF_SO_DTL->LINE_NUMBER;
    IF_SO_DTL_N->CREATED_BY = IF_SO_DTL->CREATED_BY;
    IF_SO_DTL_N->LAST_UPDATED_BY = IF_SO_DTL->LAST_UPDATED_BY;
    IF_SO_DTL_N->LAST_UPDATE_LOGIN = IF_SO_DTL->LAST_UPDATE_LOGIN;
    IF_SO_DTL_N->TRAN_FLAG[0] = IF_SO_DTL->TRAN_FLAG;
    MEMCPY_AN(IF_SO_DTL_N->CMF_1, IF_SO_DTL->CMF_1, sizeof(IF_SO_DTL->CMF_1));
    MEMCPY_AN(IF_SO_DTL_N->CMF_2, IF_SO_DTL->CMF_2, sizeof(IF_SO_DTL->CMF_2));
    MEMCPY_AN(IF_SO_DTL_N->CMF_3, IF_SO_DTL->CMF_3, sizeof(IF_SO_DTL->CMF_3));
    MEMCPY_AN(IF_SO_DTL_N->CMF_4, IF_SO_DTL->CMF_4, sizeof(IF_SO_DTL->CMF_4));
    MEMCPY_AN(IF_SO_DTL_N->CMF_5, IF_SO_DTL->CMF_5, sizeof(IF_SO_DTL->CMF_5));
    MEMCPY_AN(IF_SO_DTL_N->CMF_6, IF_SO_DTL->CMF_6, sizeof(IF_SO_DTL->CMF_6));
    MEMCPY_AN(IF_SO_DTL_N->CMF_7, IF_SO_DTL->CMF_7, sizeof(IF_SO_DTL->CMF_7));
    MEMCPY_AN(IF_SO_DTL_N->CMF_8, IF_SO_DTL->CMF_8, sizeof(IF_SO_DTL->CMF_8));
    MEMCPY_AN(IF_SO_DTL_N->CMF_9, IF_SO_DTL->CMF_9, sizeof(IF_SO_DTL->CMF_9));
    MEMCPY_AN(IF_SO_DTL_N->CMF_10, IF_SO_DTL->CMF_10, sizeof(IF_SO_DTL->CMF_10));
    MEMCPY_AN(IF_SO_DTL_N->CREATE_USER_ID, IF_SO_DTL->CREATE_USER_ID, sizeof(IF_SO_DTL->CREATE_USER_ID));
    MEMCPY_AN(IF_SO_DTL_N->CREATE_TIME, IF_SO_DTL->CREATE_TIME, sizeof(IF_SO_DTL->CREATE_TIME));
    MEMCPY_AN(IF_SO_DTL_N->UPDATE_USER_ID, IF_SO_DTL->UPDATE_USER_ID, sizeof(IF_SO_DTL->UPDATE_USER_ID));
    MEMCPY_AN(IF_SO_DTL_N->UPDATE_TIME, IF_SO_DTL->UPDATE_TIME, sizeof(IF_SO_DTL->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_if_so_dtl(struct IF_SO_DTL_N_TAG *IF_SO_DTL_N, struct IF_SO_DTL_TAG *IF_SO_DTL)
{
    IF_SO_DTL->IF_SEQ = IF_SO_DTL_N->IF_SEQ;
    MEMCPY_DN(IF_SO_DTL->IF_TIME, IF_SO_DTL_N->IF_TIME, sizeof(IF_SO_DTL->IF_TIME));
    IF_SO_DTL->IF_CODE = IF_SO_DTL_N->IF_CODE[0];
    MEMCPY_DN(IF_SO_DTL->IF_MSG, IF_SO_DTL_N->IF_MSG, sizeof(IF_SO_DTL->IF_MSG));
    MEMCPY_DN(IF_SO_DTL->FACTORY, IF_SO_DTL_N->FACTORY, sizeof(IF_SO_DTL->FACTORY));
    IF_SO_DTL->SHIPPING_LINE_ID = IF_SO_DTL_N->SHIPPING_LINE_ID;
    IF_SO_DTL->SHIPPING_LINE_NUM = IF_SO_DTL_N->SHIPPING_LINE_NUM;
    IF_SO_DTL->SHIPPING_HEADER_ID = IF_SO_DTL_N->SHIPPING_HEADER_ID;
    IF_SO_DTL->D4_SUM_ID = IF_SO_DTL_N->D4_SUM_ID;
    IF_SO_DTL->OE_HEADER_ID = IF_SO_DTL_N->OE_HEADER_ID;
    IF_SO_DTL->OE_LINE_ID = IF_SO_DTL_N->OE_LINE_ID;
    MEMCPY_DN(IF_SO_DTL->ORDER_TYPE, IF_SO_DTL_N->ORDER_TYPE, sizeof(IF_SO_DTL->ORDER_TYPE));
    MEMCPY_DN(IF_SO_DTL->PRICE_TYPE, IF_SO_DTL_N->PRICE_TYPE, sizeof(IF_SO_DTL->PRICE_TYPE));
    IF_SO_DTL->ITEM_ID = IF_SO_DTL_N->ITEM_ID;
    MEMCPY_DN(IF_SO_DTL->ITEM_CODE, IF_SO_DTL_N->ITEM_CODE, sizeof(IF_SO_DTL->ITEM_CODE));
    MEMCPY_DN(IF_SO_DTL->ITEM_DESC, IF_SO_DTL_N->ITEM_DESC, sizeof(IF_SO_DTL->ITEM_DESC));
    IF_SO_DTL->SHIPPING_QTY = IF_SO_DTL_N->SHIPPING_QTY;
    MEMCPY_DN(IF_SO_DTL->SHIPPING_UOM, IF_SO_DTL_N->SHIPPING_UOM, sizeof(IF_SO_DTL->SHIPPING_UOM));
    IF_SO_DTL->SALES_PRICE = IF_SO_DTL_N->SALES_PRICE;
    MEMCPY_DN(IF_SO_DTL->CURRENCY_CODE, IF_SO_DTL_N->CURRENCY_CODE, sizeof(IF_SO_DTL->CURRENCY_CODE));
    MEMCPY_DN(IF_SO_DTL->DATE_REQUESTED, IF_SO_DTL_N->DATE_REQUESTED, sizeof(IF_SO_DTL->DATE_REQUESTED));
    MEMCPY_DN(IF_SO_DTL->DATE_SCHEDULED, IF_SO_DTL_N->DATE_SCHEDULED, sizeof(IF_SO_DTL->DATE_SCHEDULED));
    IF_SO_DTL->RELEASED_STATUS = IF_SO_DTL_N->RELEASED_STATUS[0];
    IF_SO_DTL->SHIP_TO_ORG_ID = IF_SO_DTL_N->SHIP_TO_ORG_ID;
    IF_SO_DTL->INVOICE_TO_ORG_ID = IF_SO_DTL_N->INVOICE_TO_ORG_ID;
    MEMCPY_DN(IF_SO_DTL->SHIP_FROM_INV_OPER, IF_SO_DTL_N->SHIP_FROM_INV_OPER, sizeof(IF_SO_DTL->SHIP_FROM_INV_OPER));
    MEMCPY_DN(IF_SO_DTL->TRX_INV_OPER, IF_SO_DTL_N->TRX_INV_OPER, sizeof(IF_SO_DTL->TRX_INV_OPER));
    MEMCPY_DN(IF_SO_DTL->SHIP_TO_INV_OPER, IF_SO_DTL_N->SHIP_TO_INV_OPER, sizeof(IF_SO_DTL->SHIP_TO_INV_OPER));
    MEMCPY_DN(IF_SO_DTL->ACTUAL_DEPARTURE_DATE, IF_SO_DTL_N->ACTUAL_DEPARTURE_DATE, sizeof(IF_SO_DTL->ACTUAL_DEPARTURE_DATE));
    IF_SO_DTL->PICK_STATUS = IF_SO_DTL_N->PICK_STATUS[0];
    MEMCPY_DN(IF_SO_DTL->SHIP_STATUS, IF_SO_DTL_N->SHIP_STATUS, sizeof(IF_SO_DTL->SHIP_STATUS));
    MEMCPY_DN(IF_SO_DTL->SHIP_TO_LOCATION, IF_SO_DTL_N->SHIP_TO_LOCATION, sizeof(IF_SO_DTL->SHIP_TO_LOCATION));
    IF_SO_DTL->PICK_CONFIRM_ID = IF_SO_DTL_N->PICK_CONFIRM_ID;
    MEMCPY_DN(IF_SO_DTL->ORIG_SYS_LINE_REF, IF_SO_DTL_N->ORIG_SYS_LINE_REF, sizeof(IF_SO_DTL->ORIG_SYS_LINE_REF));
    IF_SO_DTL->DATE_SEQ = IF_SO_DTL_N->DATE_SEQ;
    MEMCPY_DN(IF_SO_DTL->SALESPERSON, IF_SO_DTL_N->SALESPERSON, sizeof(IF_SO_DTL->SALESPERSON));
    IF_SO_DTL->SHIP_CONFIRM_ID = IF_SO_DTL_N->SHIP_CONFIRM_ID;
    IF_SO_DTL->PALLET_UNIT_QTY = IF_SO_DTL_N->PALLET_UNIT_QTY;
    IF_SO_DTL->ITEM_UNIT_WEIGHT = IF_SO_DTL_N->ITEM_UNIT_WEIGHT;
    IF_SO_DTL->PALLET_WEIGHT = IF_SO_DTL_N->PALLET_WEIGHT;
    IF_SO_DTL->PALLET_CNT = IF_SO_DTL_N->PALLET_CNT;
    IF_SO_DTL->TOTAL_WEIGHT = IF_SO_DTL_N->TOTAL_WEIGHT;
    MEMCPY_DN(IF_SO_DTL->ATTRIBUTE1, IF_SO_DTL_N->ATTRIBUTE1, sizeof(IF_SO_DTL->ATTRIBUTE1));
    MEMCPY_DN(IF_SO_DTL->ATTRIBUTE2, IF_SO_DTL_N->ATTRIBUTE2, sizeof(IF_SO_DTL->ATTRIBUTE2));
    MEMCPY_DN(IF_SO_DTL->ATTRIBUTE3, IF_SO_DTL_N->ATTRIBUTE3, sizeof(IF_SO_DTL->ATTRIBUTE3));
    MEMCPY_DN(IF_SO_DTL->ATTRIBUTE4, IF_SO_DTL_N->ATTRIBUTE4, sizeof(IF_SO_DTL->ATTRIBUTE4));
    MEMCPY_DN(IF_SO_DTL->ATTRIBUTE5, IF_SO_DTL_N->ATTRIBUTE5, sizeof(IF_SO_DTL->ATTRIBUTE5));
    MEMCPY_DN(IF_SO_DTL->DEALING_NUMBER, IF_SO_DTL_N->DEALING_NUMBER, sizeof(IF_SO_DTL->DEALING_NUMBER));
    MEMCPY_DN(IF_SO_DTL->CUSTOMER_ITEM_CODE, IF_SO_DTL_N->CUSTOMER_ITEM_CODE, sizeof(IF_SO_DTL->CUSTOMER_ITEM_CODE));
    MEMCPY_DN(IF_SO_DTL->CUSTOMER_ITEM_DESC, IF_SO_DTL_N->CUSTOMER_ITEM_DESC, sizeof(IF_SO_DTL->CUSTOMER_ITEM_DESC));
    MEMCPY_DN(IF_SO_DTL->DEMAND_CLASS, IF_SO_DTL_N->DEMAND_CLASS, sizeof(IF_SO_DTL->DEMAND_CLASS));
    MEMCPY_DN(IF_SO_DTL->SHIPPING_DATE, IF_SO_DTL_N->SHIPPING_DATE, sizeof(IF_SO_DTL->SHIPPING_DATE));
    IF_SO_DTL->ORDER_NUMBER = IF_SO_DTL_N->ORDER_NUMBER;
    IF_SO_DTL->LINE_NUMBER = IF_SO_DTL_N->LINE_NUMBER;
    IF_SO_DTL->CREATED_BY = IF_SO_DTL_N->CREATED_BY;
    IF_SO_DTL->LAST_UPDATED_BY = IF_SO_DTL_N->LAST_UPDATED_BY;
    IF_SO_DTL->LAST_UPDATE_LOGIN = IF_SO_DTL_N->LAST_UPDATE_LOGIN;
    IF_SO_DTL->TRAN_FLAG = IF_SO_DTL_N->TRAN_FLAG[0];
    MEMCPY_DN(IF_SO_DTL->CMF_1, IF_SO_DTL_N->CMF_1, sizeof(IF_SO_DTL->CMF_1));
    MEMCPY_DN(IF_SO_DTL->CMF_2, IF_SO_DTL_N->CMF_2, sizeof(IF_SO_DTL->CMF_2));
    MEMCPY_DN(IF_SO_DTL->CMF_3, IF_SO_DTL_N->CMF_3, sizeof(IF_SO_DTL->CMF_3));
    MEMCPY_DN(IF_SO_DTL->CMF_4, IF_SO_DTL_N->CMF_4, sizeof(IF_SO_DTL->CMF_4));
    MEMCPY_DN(IF_SO_DTL->CMF_5, IF_SO_DTL_N->CMF_5, sizeof(IF_SO_DTL->CMF_5));
    MEMCPY_DN(IF_SO_DTL->CMF_6, IF_SO_DTL_N->CMF_6, sizeof(IF_SO_DTL->CMF_6));
    MEMCPY_DN(IF_SO_DTL->CMF_7, IF_SO_DTL_N->CMF_7, sizeof(IF_SO_DTL->CMF_7));
    MEMCPY_DN(IF_SO_DTL->CMF_8, IF_SO_DTL_N->CMF_8, sizeof(IF_SO_DTL->CMF_8));
    MEMCPY_DN(IF_SO_DTL->CMF_9, IF_SO_DTL_N->CMF_9, sizeof(IF_SO_DTL->CMF_9));
    MEMCPY_DN(IF_SO_DTL->CMF_10, IF_SO_DTL_N->CMF_10, sizeof(IF_SO_DTL->CMF_10));
    MEMCPY_DN(IF_SO_DTL->CREATE_USER_ID, IF_SO_DTL_N->CREATE_USER_ID, sizeof(IF_SO_DTL->CREATE_USER_ID));
    MEMCPY_DN(IF_SO_DTL->CREATE_TIME, IF_SO_DTL_N->CREATE_TIME, sizeof(IF_SO_DTL->CREATE_TIME));
    MEMCPY_DN(IF_SO_DTL->UPDATE_USER_ID, IF_SO_DTL_N->UPDATE_USER_ID, sizeof(IF_SO_DTL->UPDATE_USER_ID));
    MEMCPY_DN(IF_SO_DTL->UPDATE_TIME, IF_SO_DTL_N->UPDATE_TIME, sizeof(IF_SO_DTL->UPDATE_TIME));
}


