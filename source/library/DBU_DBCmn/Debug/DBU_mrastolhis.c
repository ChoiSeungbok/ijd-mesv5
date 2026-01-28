
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
    "DBU_mrastolhis.pc"
};


static unsigned int sqlctx = 9423427;


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
            void  *sqhstv[74];
   unsigned int   sqhstl[74];
            int   sqhsts[74];
            void  *sqindv[74];
            int   sqinds[74];
   unsigned int   sqharm[74];
   unsigned int   *sqharc[74];
   unsigned short  sqadto[74];
   unsigned short  sqtdso[74];
} sqlstm = {13,74};

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
"select FACTORY ,TOOL_ID ,HIST_SEQ ,TOOL_TYPE ,TOOL_EVENT_ID ,TRAN_TIME ,SYS\
_TRAN_TIME ,TOOL_GRP ,TOOL_SET_ID ,TOOL_SET_LOCATION ,TOOL_STATUS ,LOT_ID ,SU\
BLOT_ID ,RES_ID ,SUBRES_ID ,MAT_ID ,MAT_VER ,FLOW ,OPER ,AREA_ID ,SUB_AREA_ID\
 ,TOOL_LOCATION ,VENDOR_ID ,VENDOR_TOOL_ID ,CELL_COUNT_X ,CELL_COUNT_Y ,CELL_\
COUNT_Z ,CELL_SIZE_X ,CELL_SIZE_Y ,CELL_SIZE_Z ,GRADE ,TOOL_STS_1 ,TOOL_STS_2\
 ,TOOL_STS_3 ,TOOL_STS_4 ,TOOL_STS_5 ,TOOL_STS_6 ,TOOL_STS_7 ,TOOL_STS_8 ,TOO\
L_STS_9 ,TOOL_STS_10 ,TOOL_STS_11 ,TOOL_STS_12 ,TOOL_STS_13 ,TOOL_STS_14 ,TOO\
L_STS_15 ,TOOL_STS_16 ,TOOL_STS_17 ,TOOL_STS_18 ,TOOL_STS_19 ,TOOL_STS_20 ,TO\
OL_STS_21 ,TOOL_STS_22 ,TOOL_STS_23 ,TOOL_STS_24 ,TOOL_STS_25 ,TOOL_STS_26 ,T\
OOL_STS_27 ,TOOL_STS_28 ,TOOL_STS_29 ,TOOL_STS_30 ,DELETE_FLAG ,TOOL_COMMENT \
,TRAN_USER_ID ,TRAN_COMMENT ,PREV_ACTIVE_HIST_SEQ ,HIST_DEL_FLAG ,HIST_DEL_TI\
ME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT  from MRASTOLHIS  order by FACTORY asc\
 ,TOOL_ID asc ,HIST_SEQ asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,1300,0,4,46,0,0,73,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
312,0,0,2,1397,0,4,195,0,0,74,4,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,0,0,0,1,0,0,0,
623,0,0,3,1312,0,4,382,0,0,73,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
930,0,0,4,97,0,4,567,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
961,0,0,5,79,0,2,605,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
988,0,0,6,1181,0,3,636,0,0,70,70,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1283,0,0,7,1188,0,5,801,0,0,70,70,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1578,0,0,8,962,0,9,978,0,0,0,0,0,1,0,
1593,0,0,8,0,0,13,1007,0,0,70,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1888,0,0,8,0,0,15,1107,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_mrastolhis.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2021-04-29 16:35:10
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
void DBU_add_null_mrastolhis(struct MRASTOLHIS_N_TAG *MRASTOLHIS_N, struct MRASTOLHIS_TAG *MRASTOLHIS);
void DBU_del_null_mrastolhis(struct MRASTOLHIS_N_TAG *MRASTOLHIS_N, struct MRASTOLHIS_TAG *MRASTOLHIS);


/* SQL SELECT Function */
void DBU_select_mrastolhis(int sel_type, struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTOLHIS_N_TAG MRASTOLHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastolhis(&MRASTOLHIS_N, MRASTOLHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    TOOL_ID,
                    HIST_SEQ,
                    TOOL_TYPE,
                    TOOL_EVENT_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TOOL_GRP,
                    TOOL_SET_ID,
                    TOOL_SET_LOCATION,
                    TOOL_STATUS,
                    LOT_ID,
                    SUBLOT_ID,
                    RES_ID,
                    SUBRES_ID,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    OPER,
                    AREA_ID,
                    SUB_AREA_ID,
                    TOOL_LOCATION,
                    VENDOR_ID,
                    VENDOR_TOOL_ID,
                    CELL_COUNT_X,
                    CELL_COUNT_Y,
                    CELL_COUNT_Z,
                    CELL_SIZE_X,
                    CELL_SIZE_Y,
                    CELL_SIZE_Z,
                    GRADE,
                    TOOL_STS_1,
                    TOOL_STS_2,
                    TOOL_STS_3,
                    TOOL_STS_4,
                    TOOL_STS_5,
                    TOOL_STS_6,
                    TOOL_STS_7,
                    TOOL_STS_8,
                    TOOL_STS_9,
                    TOOL_STS_10,
                    TOOL_STS_11,
                    TOOL_STS_12,
                    TOOL_STS_13,
                    TOOL_STS_14,
                    TOOL_STS_15,
                    TOOL_STS_16,
                    TOOL_STS_17,
                    TOOL_STS_18,
                    TOOL_STS_19,
                    TOOL_STS_20,
                    TOOL_STS_21,
                    TOOL_STS_22,
                    TOOL_STS_23,
                    TOOL_STS_24,
                    TOOL_STS_25,
                    TOOL_STS_26,
                    TOOL_STS_27,
                    TOOL_STS_28,
                    TOOL_STS_29,
                    TOOL_STS_30,
                    DELETE_FLAG,
                    TOOL_COMMENT,
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    PREV_ACTIVE_HIST_SEQ,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                INTO 
                    :MRASTOLHIS_N.FACTORY,
                    :MRASTOLHIS_N.TOOL_ID,
                    :MRASTOLHIS_N.HIST_SEQ,
                    :MRASTOLHIS_N.TOOL_TYPE,
                    :MRASTOLHIS_N.TOOL_EVENT_ID,
                    :MRASTOLHIS_N.TRAN_TIME,
                    :MRASTOLHIS_N.SYS_TRAN_TIME,
                    :MRASTOLHIS_N.TOOL_GRP,
                    :MRASTOLHIS_N.TOOL_SET_ID,
                    :MRASTOLHIS_N.TOOL_SET_LOCATION,
                    :MRASTOLHIS_N.TOOL_STATUS,
                    :MRASTOLHIS_N.LOT_ID,
                    :MRASTOLHIS_N.SUBLOT_ID,
                    :MRASTOLHIS_N.RES_ID,
                    :MRASTOLHIS_N.SUBRES_ID,
                    :MRASTOLHIS_N.MAT_ID,
                    :MRASTOLHIS_N.MAT_VER,
                    :MRASTOLHIS_N.FLOW,
                    :MRASTOLHIS_N.OPER,
                    :MRASTOLHIS_N.AREA_ID,
                    :MRASTOLHIS_N.SUB_AREA_ID,
                    :MRASTOLHIS_N.TOOL_LOCATION,
                    :MRASTOLHIS_N.VENDOR_ID,
                    :MRASTOLHIS_N.VENDOR_TOOL_ID,
                    :MRASTOLHIS_N.CELL_COUNT_X,
                    :MRASTOLHIS_N.CELL_COUNT_Y,
                    :MRASTOLHIS_N.CELL_COUNT_Z,
                    :MRASTOLHIS_N.CELL_SIZE_X,
                    :MRASTOLHIS_N.CELL_SIZE_Y,
                    :MRASTOLHIS_N.CELL_SIZE_Z,
                    :MRASTOLHIS_N.GRADE,
                    :MRASTOLHIS_N.TOOL_STS_1,
                    :MRASTOLHIS_N.TOOL_STS_2,
                    :MRASTOLHIS_N.TOOL_STS_3,
                    :MRASTOLHIS_N.TOOL_STS_4,
                    :MRASTOLHIS_N.TOOL_STS_5,
                    :MRASTOLHIS_N.TOOL_STS_6,
                    :MRASTOLHIS_N.TOOL_STS_7,
                    :MRASTOLHIS_N.TOOL_STS_8,
                    :MRASTOLHIS_N.TOOL_STS_9,
                    :MRASTOLHIS_N.TOOL_STS_10,
                    :MRASTOLHIS_N.TOOL_STS_11,
                    :MRASTOLHIS_N.TOOL_STS_12,
                    :MRASTOLHIS_N.TOOL_STS_13,
                    :MRASTOLHIS_N.TOOL_STS_14,
                    :MRASTOLHIS_N.TOOL_STS_15,
                    :MRASTOLHIS_N.TOOL_STS_16,
                    :MRASTOLHIS_N.TOOL_STS_17,
                    :MRASTOLHIS_N.TOOL_STS_18,
                    :MRASTOLHIS_N.TOOL_STS_19,
                    :MRASTOLHIS_N.TOOL_STS_20,
                    :MRASTOLHIS_N.TOOL_STS_21,
                    :MRASTOLHIS_N.TOOL_STS_22,
                    :MRASTOLHIS_N.TOOL_STS_23,
                    :MRASTOLHIS_N.TOOL_STS_24,
                    :MRASTOLHIS_N.TOOL_STS_25,
                    :MRASTOLHIS_N.TOOL_STS_26,
                    :MRASTOLHIS_N.TOOL_STS_27,
                    :MRASTOLHIS_N.TOOL_STS_28,
                    :MRASTOLHIS_N.TOOL_STS_29,
                    :MRASTOLHIS_N.TOOL_STS_30,
                    :MRASTOLHIS_N.DELETE_FLAG,
                    :MRASTOLHIS_N.TOOL_COMMENT,
                    :MRASTOLHIS_N.TRAN_USER_ID,
                    :MRASTOLHIS_N.TRAN_COMMENT,
                    :MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ,
                    :MRASTOLHIS_N.HIST_DEL_FLAG,
                    :MRASTOLHIS_N.HIST_DEL_TIME,
                    :MRASTOLHIS_N.HIST_DEL_USER_ID,
                    :MRASTOLHIS_N.HIST_DEL_COMMENT
                FROM MRASTOLHIS
                WHERE FACTORY = :MRASTOLHIS_N.FACTORY
                    AND TOOL_ID = :MRASTOLHIS_N.TOOL_ID
                    AND HIST_SEQ = :MRASTOLHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 73;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,TOOL_ID ,HIST_SEQ ,TOOL_TYPE ,TOOL_EVENT_ID ,\
TRAN_TIME ,SYS_TRAN_TIME ,TOOL_GRP ,TOOL_SET_ID ,TOOL_SET_LOCATION ,TOOL_STA\
TUS ,LOT_ID ,SUBLOT_ID ,RES_ID ,SUBRES_ID ,MAT_ID ,MAT_VER ,FLOW ,OPER ,AREA\
_ID ,SUB_AREA_ID ,TOOL_LOCATION ,VENDOR_ID ,VENDOR_TOOL_ID ,CELL_COUNT_X ,CE\
LL_COUNT_Y ,CELL_COUNT_Z ,CELL_SIZE_X ,CELL_SIZE_Y ,CELL_SIZE_Z ,GRADE ,TOOL\
_STS_1 ,TOOL_STS_2 ,TOOL_STS_3 ,TOOL_STS_4 ,TOOL_STS_5 ,TOOL_STS_6 ,TOOL_STS\
_7 ,TOOL_STS_8 ,TOOL_STS_9 ,TOOL_STS_10 ,TOOL_STS_11 ,TOOL_STS_12 ,TOOL_STS_\
13 ,TOOL_STS_14 ,TOOL_STS_15 ,TOOL_STS_16 ,TOOL_STS_17 ,TOOL_STS_18 ,TOOL_ST\
S_19 ,TOOL_STS_20 ,TOOL_STS_21 ,TOOL_STS_22 ,TOOL_STS_23 ,TOOL_STS_24 ,TOOL_\
STS_25 ,TOOL_STS_26 ,TOOL_STS_27 ,TOOL_STS_28 ,TOOL_STS_29 ,TOOL_STS_30 ,DEL\
ETE_FLAG ,TOOL_COMMENT ,TRAN_USER_ID ,TRAN_COMMENT ,PREV_ACTIVE_HIST_SEQ ,HI\
ST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT into :b0,:b1,\
:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18\
,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,");
            sqlstm.stmt = ":b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b3\
8,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,\
:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b\
69  from MRASTOLHIS where ((FACTORY=:b0 and TOOL_ID=:b1) and HIST_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MRASTOLHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTOLHIS_N.TOOL_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASTOLHIS_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )13;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASTOLHIS_N.TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASTOLHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASTOLHIS_N.TOOL_GRP);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASTOLHIS_N.TOOL_SET_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASTOLHIS_N.TOOL_SET_LOCATION);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASTOLHIS_N.TOOL_STATUS);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASTOLHIS_N.LOT_ID);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASTOLHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASTOLHIS_N.RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASTOLHIS_N.SUBRES_ID);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASTOLHIS_N.MAT_ID);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MRASTOLHIS_N.MAT_VER);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASTOLHIS_N.FLOW);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASTOLHIS_N.OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASTOLHIS_N.AREA_ID);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASTOLHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASTOLHIS_N.TOOL_LOCATION);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASTOLHIS_N.VENDOR_ID);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASTOLHIS_N.VENDOR_TOOL_ID);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_X);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Y);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Z);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_X);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Y);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Z);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASTOLHIS_N.GRADE);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASTOLHIS_N.TOOL_STS_1);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASTOLHIS_N.TOOL_STS_2);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASTOLHIS_N.TOOL_STS_3);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASTOLHIS_N.TOOL_STS_4);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASTOLHIS_N.TOOL_STS_5);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASTOLHIS_N.TOOL_STS_6);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASTOLHIS_N.TOOL_STS_7);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASTOLHIS_N.TOOL_STS_8);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASTOLHIS_N.TOOL_STS_9);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASTOLHIS_N.TOOL_STS_10);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASTOLHIS_N.TOOL_STS_11);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASTOLHIS_N.TOOL_STS_12);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASTOLHIS_N.TOOL_STS_13);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASTOLHIS_N.TOOL_STS_14);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASTOLHIS_N.TOOL_STS_15);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASTOLHIS_N.TOOL_STS_16);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASTOLHIS_N.TOOL_STS_17);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASTOLHIS_N.TOOL_STS_18);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASTOLHIS_N.TOOL_STS_19);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASTOLHIS_N.TOOL_STS_20);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASTOLHIS_N.TOOL_STS_21);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASTOLHIS_N.TOOL_STS_22);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASTOLHIS_N.TOOL_STS_23);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASTOLHIS_N.TOOL_STS_24);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASTOLHIS_N.TOOL_STS_25);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASTOLHIS_N.TOOL_STS_26);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASTOLHIS_N.TOOL_STS_27);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASTOLHIS_N.TOOL_STS_28);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASTOLHIS_N.TOOL_STS_29);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASTOLHIS_N.TOOL_STS_30);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASTOLHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASTOLHIS_N.TOOL_COMMENT);
            sqlstm.sqhstl[62] = (unsigned int  )401;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASTOLHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASTOLHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[64] = (unsigned int  )401;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASTOLHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASTOLHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[67] = (unsigned int  )15;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASTOLHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASTOLHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[69] = (unsigned int  )401;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[70] = (unsigned int  )11;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)&(MRASTOLHIS_N.HIST_SEQ);
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

        case 2:
            /* EXEC SQL SELECT 
                    FACTORY,
                    TOOL_ID,
                    HIST_SEQ,
                    TOOL_TYPE,
                    TOOL_EVENT_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TOOL_GRP,
                    TOOL_SET_ID,
                    TOOL_SET_LOCATION,
                    TOOL_STATUS,
                    LOT_ID,
                    SUBLOT_ID,
                    RES_ID,
                    SUBRES_ID,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    OPER,
                    AREA_ID,
                    SUB_AREA_ID,
                    TOOL_LOCATION,
                    VENDOR_ID,
                    VENDOR_TOOL_ID,
                    CELL_COUNT_X,
                    CELL_COUNT_Y,
                    CELL_COUNT_Z,
                    CELL_SIZE_X,
                    CELL_SIZE_Y,
                    CELL_SIZE_Z,
                    GRADE,
                    TOOL_STS_1,
                    TOOL_STS_2,
                    TOOL_STS_3,
                    TOOL_STS_4,
                    TOOL_STS_5,
                    TOOL_STS_6,
                    TOOL_STS_7,
                    TOOL_STS_8,
                    TOOL_STS_9,
                    TOOL_STS_10,
                    TOOL_STS_11,
                    TOOL_STS_12,
                    TOOL_STS_13,
                    TOOL_STS_14,
                    TOOL_STS_15,
                    TOOL_STS_16,
                    TOOL_STS_17,
                    TOOL_STS_18,
                    TOOL_STS_19,
                    TOOL_STS_20,
                    TOOL_STS_21,
                    TOOL_STS_22,
                    TOOL_STS_23,
                    TOOL_STS_24,
                    TOOL_STS_25,
                    TOOL_STS_26,
                    TOOL_STS_27,
                    TOOL_STS_28,
                    TOOL_STS_29,
                    TOOL_STS_30,
                    DELETE_FLAG,
                    TOOL_COMMENT,
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    PREV_ACTIVE_HIST_SEQ,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                INTO 
                    :MRASTOLHIS_N.FACTORY,
                    :MRASTOLHIS_N.TOOL_ID,
                    :MRASTOLHIS_N.HIST_SEQ,
                    :MRASTOLHIS_N.TOOL_TYPE,
                    :MRASTOLHIS_N.TOOL_EVENT_ID,
                    :MRASTOLHIS_N.TRAN_TIME,
                    :MRASTOLHIS_N.SYS_TRAN_TIME,
                    :MRASTOLHIS_N.TOOL_GRP,
                    :MRASTOLHIS_N.TOOL_SET_ID,
                    :MRASTOLHIS_N.TOOL_SET_LOCATION,
                    :MRASTOLHIS_N.TOOL_STATUS,
                    :MRASTOLHIS_N.LOT_ID,
                    :MRASTOLHIS_N.SUBLOT_ID,
                    :MRASTOLHIS_N.RES_ID,
                    :MRASTOLHIS_N.SUBRES_ID,
                    :MRASTOLHIS_N.MAT_ID,
                    :MRASTOLHIS_N.MAT_VER,
                    :MRASTOLHIS_N.FLOW,
                    :MRASTOLHIS_N.OPER,
                    :MRASTOLHIS_N.AREA_ID,
                    :MRASTOLHIS_N.SUB_AREA_ID,
                    :MRASTOLHIS_N.TOOL_LOCATION,
                    :MRASTOLHIS_N.VENDOR_ID,
                    :MRASTOLHIS_N.VENDOR_TOOL_ID,
                    :MRASTOLHIS_N.CELL_COUNT_X,
                    :MRASTOLHIS_N.CELL_COUNT_Y,
                    :MRASTOLHIS_N.CELL_COUNT_Z,
                    :MRASTOLHIS_N.CELL_SIZE_X,
                    :MRASTOLHIS_N.CELL_SIZE_Y,
                    :MRASTOLHIS_N.CELL_SIZE_Z,
                    :MRASTOLHIS_N.GRADE,
                    :MRASTOLHIS_N.TOOL_STS_1,
                    :MRASTOLHIS_N.TOOL_STS_2,
                    :MRASTOLHIS_N.TOOL_STS_3,
                    :MRASTOLHIS_N.TOOL_STS_4,
                    :MRASTOLHIS_N.TOOL_STS_5,
                    :MRASTOLHIS_N.TOOL_STS_6,
                    :MRASTOLHIS_N.TOOL_STS_7,
                    :MRASTOLHIS_N.TOOL_STS_8,
                    :MRASTOLHIS_N.TOOL_STS_9,
                    :MRASTOLHIS_N.TOOL_STS_10,
                    :MRASTOLHIS_N.TOOL_STS_11,
                    :MRASTOLHIS_N.TOOL_STS_12,
                    :MRASTOLHIS_N.TOOL_STS_13,
                    :MRASTOLHIS_N.TOOL_STS_14,
                    :MRASTOLHIS_N.TOOL_STS_15,
                    :MRASTOLHIS_N.TOOL_STS_16,
                    :MRASTOLHIS_N.TOOL_STS_17,
                    :MRASTOLHIS_N.TOOL_STS_18,
                    :MRASTOLHIS_N.TOOL_STS_19,
                    :MRASTOLHIS_N.TOOL_STS_20,
                    :MRASTOLHIS_N.TOOL_STS_21,
                    :MRASTOLHIS_N.TOOL_STS_22,
                    :MRASTOLHIS_N.TOOL_STS_23,
                    :MRASTOLHIS_N.TOOL_STS_24,
                    :MRASTOLHIS_N.TOOL_STS_25,
                    :MRASTOLHIS_N.TOOL_STS_26,
                    :MRASTOLHIS_N.TOOL_STS_27,
                    :MRASTOLHIS_N.TOOL_STS_28,
                    :MRASTOLHIS_N.TOOL_STS_29,
                    :MRASTOLHIS_N.TOOL_STS_30,
                    :MRASTOLHIS_N.DELETE_FLAG,
                    :MRASTOLHIS_N.TOOL_COMMENT,
                    :MRASTOLHIS_N.TRAN_USER_ID,
                    :MRASTOLHIS_N.TRAN_COMMENT,
                    :MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ,
                    :MRASTOLHIS_N.HIST_DEL_FLAG,
                    :MRASTOLHIS_N.HIST_DEL_TIME,
                    :MRASTOLHIS_N.HIST_DEL_USER_ID,
                    :MRASTOLHIS_N.HIST_DEL_COMMENT
                FROM MRASTOLHIS
                WHERE FACTORY = :MRASTOLHIS_N.FACTORY
                    AND TOOL_ID = :MRASTOLHIS_N.TOOL_ID
                    AND HIST_SEQ = ( SELECT NVL(MAX(HIST_SEQ),0)
                                       FROM MRASTOLHIS 
                                      WHERE FACTORY = :MRASTOLHIS_N.FACTORY
                                        AND TOOL_ID = :MRASTOLHIS_N.TOOL_ID
                                        AND RES_ID != ' '
                                    ); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,TOOL_ID ,HIST_SEQ ,TOOL_TYPE ,TOOL_EVENT_ID ,\
TRAN_TIME ,SYS_TRAN_TIME ,TOOL_GRP ,TOOL_SET_ID ,TOOL_SET_LOCATION ,TOOL_STA\
TUS ,LOT_ID ,SUBLOT_ID ,RES_ID ,SUBRES_ID ,MAT_ID ,MAT_VER ,FLOW ,OPER ,AREA\
_ID ,SUB_AREA_ID ,TOOL_LOCATION ,VENDOR_ID ,VENDOR_TOOL_ID ,CELL_COUNT_X ,CE\
LL_COUNT_Y ,CELL_COUNT_Z ,CELL_SIZE_X ,CELL_SIZE_Y ,CELL_SIZE_Z ,GRADE ,TOOL\
_STS_1 ,TOOL_STS_2 ,TOOL_STS_3 ,TOOL_STS_4 ,TOOL_STS_5 ,TOOL_STS_6 ,TOOL_STS\
_7 ,TOOL_STS_8 ,TOOL_STS_9 ,TOOL_STS_10 ,TOOL_STS_11 ,TOOL_STS_12 ,TOOL_STS_\
13 ,TOOL_STS_14 ,TOOL_STS_15 ,TOOL_STS_16 ,TOOL_STS_17 ,TOOL_STS_18 ,TOOL_ST\
S_19 ,TOOL_STS_20 ,TOOL_STS_21 ,TOOL_STS_22 ,TOOL_STS_23 ,TOOL_STS_24 ,TOOL_\
STS_25 ,TOOL_STS_26 ,TOOL_STS_27 ,TOOL_STS_28 ,TOOL_STS_29 ,TOOL_STS_30 ,DEL\
ETE_FLAG ,TOOL_COMMENT ,TRAN_USER_ID ,TRAN_COMMENT ,PREV_ACTIVE_HIST_SEQ ,HI\
ST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT into :b0,:b1,\
:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18\
,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,");
            sqlstm.stmt = ":b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b3\
8,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,\
:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b\
69  from MRASTOLHIS where ((FACTORY=:b0 and TOOL_ID=:b1) and HIST_SEQ=(select\
 NVL(max(HIST_SEQ),0)  from MRASTOLHIS where ((FACTORY=:b0 and TOOL_ID=:b1) a\
nd RES_ID<>' ')))";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )312;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MRASTOLHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTOLHIS_N.TOOL_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASTOLHIS_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )13;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASTOLHIS_N.TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASTOLHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASTOLHIS_N.TOOL_GRP);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASTOLHIS_N.TOOL_SET_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASTOLHIS_N.TOOL_SET_LOCATION);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASTOLHIS_N.TOOL_STATUS);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASTOLHIS_N.LOT_ID);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASTOLHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASTOLHIS_N.RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASTOLHIS_N.SUBRES_ID);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASTOLHIS_N.MAT_ID);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MRASTOLHIS_N.MAT_VER);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASTOLHIS_N.FLOW);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASTOLHIS_N.OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASTOLHIS_N.AREA_ID);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASTOLHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASTOLHIS_N.TOOL_LOCATION);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASTOLHIS_N.VENDOR_ID);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASTOLHIS_N.VENDOR_TOOL_ID);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_X);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Y);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Z);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_X);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Y);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Z);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASTOLHIS_N.GRADE);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASTOLHIS_N.TOOL_STS_1);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASTOLHIS_N.TOOL_STS_2);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASTOLHIS_N.TOOL_STS_3);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASTOLHIS_N.TOOL_STS_4);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASTOLHIS_N.TOOL_STS_5);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASTOLHIS_N.TOOL_STS_6);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASTOLHIS_N.TOOL_STS_7);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASTOLHIS_N.TOOL_STS_8);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASTOLHIS_N.TOOL_STS_9);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASTOLHIS_N.TOOL_STS_10);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASTOLHIS_N.TOOL_STS_11);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASTOLHIS_N.TOOL_STS_12);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASTOLHIS_N.TOOL_STS_13);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASTOLHIS_N.TOOL_STS_14);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASTOLHIS_N.TOOL_STS_15);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASTOLHIS_N.TOOL_STS_16);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASTOLHIS_N.TOOL_STS_17);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASTOLHIS_N.TOOL_STS_18);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASTOLHIS_N.TOOL_STS_19);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASTOLHIS_N.TOOL_STS_20);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASTOLHIS_N.TOOL_STS_21);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASTOLHIS_N.TOOL_STS_22);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASTOLHIS_N.TOOL_STS_23);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASTOLHIS_N.TOOL_STS_24);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASTOLHIS_N.TOOL_STS_25);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASTOLHIS_N.TOOL_STS_26);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASTOLHIS_N.TOOL_STS_27);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASTOLHIS_N.TOOL_STS_28);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASTOLHIS_N.TOOL_STS_29);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASTOLHIS_N.TOOL_STS_30);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASTOLHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASTOLHIS_N.TOOL_COMMENT);
            sqlstm.sqhstl[62] = (unsigned int  )401;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASTOLHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASTOLHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[64] = (unsigned int  )401;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASTOLHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASTOLHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[67] = (unsigned int  )15;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASTOLHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASTOLHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[69] = (unsigned int  )401;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[70] = (unsigned int  )11;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[72] = (unsigned int  )11;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
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
        DBU_del_null_mrastolhis(&MRASTOLHIS_N, MRASTOLHIS);
    }

    DB_stop_query_timer("DBU_select_mrastolhis", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_mrastolhis_for_update(int sel_type, struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTOLHIS_N_TAG MRASTOLHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastolhis(&MRASTOLHIS_N, MRASTOLHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    TOOL_ID,
                    HIST_SEQ,
                    TOOL_TYPE,
                    TOOL_EVENT_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TOOL_GRP,
                    TOOL_SET_ID,
                    TOOL_SET_LOCATION,
                    TOOL_STATUS,
                    LOT_ID,
                    SUBLOT_ID,
                    RES_ID,
                    SUBRES_ID,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    OPER,
                    AREA_ID,
                    SUB_AREA_ID,
                    TOOL_LOCATION,
                    VENDOR_ID,
                    VENDOR_TOOL_ID,
                    CELL_COUNT_X,
                    CELL_COUNT_Y,
                    CELL_COUNT_Z,
                    CELL_SIZE_X,
                    CELL_SIZE_Y,
                    CELL_SIZE_Z,
                    GRADE,
                    TOOL_STS_1,
                    TOOL_STS_2,
                    TOOL_STS_3,
                    TOOL_STS_4,
                    TOOL_STS_5,
                    TOOL_STS_6,
                    TOOL_STS_7,
                    TOOL_STS_8,
                    TOOL_STS_9,
                    TOOL_STS_10,
                    TOOL_STS_11,
                    TOOL_STS_12,
                    TOOL_STS_13,
                    TOOL_STS_14,
                    TOOL_STS_15,
                    TOOL_STS_16,
                    TOOL_STS_17,
                    TOOL_STS_18,
                    TOOL_STS_19,
                    TOOL_STS_20,
                    TOOL_STS_21,
                    TOOL_STS_22,
                    TOOL_STS_23,
                    TOOL_STS_24,
                    TOOL_STS_25,
                    TOOL_STS_26,
                    TOOL_STS_27,
                    TOOL_STS_28,
                    TOOL_STS_29,
                    TOOL_STS_30,
                    DELETE_FLAG,
                    TOOL_COMMENT,
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    PREV_ACTIVE_HIST_SEQ,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                INTO 
                    :MRASTOLHIS_N.FACTORY,
                    :MRASTOLHIS_N.TOOL_ID,
                    :MRASTOLHIS_N.HIST_SEQ,
                    :MRASTOLHIS_N.TOOL_TYPE,
                    :MRASTOLHIS_N.TOOL_EVENT_ID,
                    :MRASTOLHIS_N.TRAN_TIME,
                    :MRASTOLHIS_N.SYS_TRAN_TIME,
                    :MRASTOLHIS_N.TOOL_GRP,
                    :MRASTOLHIS_N.TOOL_SET_ID,
                    :MRASTOLHIS_N.TOOL_SET_LOCATION,
                    :MRASTOLHIS_N.TOOL_STATUS,
                    :MRASTOLHIS_N.LOT_ID,
                    :MRASTOLHIS_N.SUBLOT_ID,
                    :MRASTOLHIS_N.RES_ID,
                    :MRASTOLHIS_N.SUBRES_ID,
                    :MRASTOLHIS_N.MAT_ID,
                    :MRASTOLHIS_N.MAT_VER,
                    :MRASTOLHIS_N.FLOW,
                    :MRASTOLHIS_N.OPER,
                    :MRASTOLHIS_N.AREA_ID,
                    :MRASTOLHIS_N.SUB_AREA_ID,
                    :MRASTOLHIS_N.TOOL_LOCATION,
                    :MRASTOLHIS_N.VENDOR_ID,
                    :MRASTOLHIS_N.VENDOR_TOOL_ID,
                    :MRASTOLHIS_N.CELL_COUNT_X,
                    :MRASTOLHIS_N.CELL_COUNT_Y,
                    :MRASTOLHIS_N.CELL_COUNT_Z,
                    :MRASTOLHIS_N.CELL_SIZE_X,
                    :MRASTOLHIS_N.CELL_SIZE_Y,
                    :MRASTOLHIS_N.CELL_SIZE_Z,
                    :MRASTOLHIS_N.GRADE,
                    :MRASTOLHIS_N.TOOL_STS_1,
                    :MRASTOLHIS_N.TOOL_STS_2,
                    :MRASTOLHIS_N.TOOL_STS_3,
                    :MRASTOLHIS_N.TOOL_STS_4,
                    :MRASTOLHIS_N.TOOL_STS_5,
                    :MRASTOLHIS_N.TOOL_STS_6,
                    :MRASTOLHIS_N.TOOL_STS_7,
                    :MRASTOLHIS_N.TOOL_STS_8,
                    :MRASTOLHIS_N.TOOL_STS_9,
                    :MRASTOLHIS_N.TOOL_STS_10,
                    :MRASTOLHIS_N.TOOL_STS_11,
                    :MRASTOLHIS_N.TOOL_STS_12,
                    :MRASTOLHIS_N.TOOL_STS_13,
                    :MRASTOLHIS_N.TOOL_STS_14,
                    :MRASTOLHIS_N.TOOL_STS_15,
                    :MRASTOLHIS_N.TOOL_STS_16,
                    :MRASTOLHIS_N.TOOL_STS_17,
                    :MRASTOLHIS_N.TOOL_STS_18,
                    :MRASTOLHIS_N.TOOL_STS_19,
                    :MRASTOLHIS_N.TOOL_STS_20,
                    :MRASTOLHIS_N.TOOL_STS_21,
                    :MRASTOLHIS_N.TOOL_STS_22,
                    :MRASTOLHIS_N.TOOL_STS_23,
                    :MRASTOLHIS_N.TOOL_STS_24,
                    :MRASTOLHIS_N.TOOL_STS_25,
                    :MRASTOLHIS_N.TOOL_STS_26,
                    :MRASTOLHIS_N.TOOL_STS_27,
                    :MRASTOLHIS_N.TOOL_STS_28,
                    :MRASTOLHIS_N.TOOL_STS_29,
                    :MRASTOLHIS_N.TOOL_STS_30,
                    :MRASTOLHIS_N.DELETE_FLAG,
                    :MRASTOLHIS_N.TOOL_COMMENT,
                    :MRASTOLHIS_N.TRAN_USER_ID,
                    :MRASTOLHIS_N.TRAN_COMMENT,
                    :MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ,
                    :MRASTOLHIS_N.HIST_DEL_FLAG,
                    :MRASTOLHIS_N.HIST_DEL_TIME,
                    :MRASTOLHIS_N.HIST_DEL_USER_ID,
                    :MRASTOLHIS_N.HIST_DEL_COMMENT
                FROM MRASTOLHIS
                WHERE FACTORY = :MRASTOLHIS_N.FACTORY
                    AND TOOL_ID = :MRASTOLHIS_N.TOOL_ID
                    AND HIST_SEQ = :MRASTOLHIS_N.HIST_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,TOOL_ID ,HIST_SEQ ,TOOL_TYPE ,TOOL_EVENT_ID ,\
TRAN_TIME ,SYS_TRAN_TIME ,TOOL_GRP ,TOOL_SET_ID ,TOOL_SET_LOCATION ,TOOL_STA\
TUS ,LOT_ID ,SUBLOT_ID ,RES_ID ,SUBRES_ID ,MAT_ID ,MAT_VER ,FLOW ,OPER ,AREA\
_ID ,SUB_AREA_ID ,TOOL_LOCATION ,VENDOR_ID ,VENDOR_TOOL_ID ,CELL_COUNT_X ,CE\
LL_COUNT_Y ,CELL_COUNT_Z ,CELL_SIZE_X ,CELL_SIZE_Y ,CELL_SIZE_Z ,GRADE ,TOOL\
_STS_1 ,TOOL_STS_2 ,TOOL_STS_3 ,TOOL_STS_4 ,TOOL_STS_5 ,TOOL_STS_6 ,TOOL_STS\
_7 ,TOOL_STS_8 ,TOOL_STS_9 ,TOOL_STS_10 ,TOOL_STS_11 ,TOOL_STS_12 ,TOOL_STS_\
13 ,TOOL_STS_14 ,TOOL_STS_15 ,TOOL_STS_16 ,TOOL_STS_17 ,TOOL_STS_18 ,TOOL_ST\
S_19 ,TOOL_STS_20 ,TOOL_STS_21 ,TOOL_STS_22 ,TOOL_STS_23 ,TOOL_STS_24 ,TOOL_\
STS_25 ,TOOL_STS_26 ,TOOL_STS_27 ,TOOL_STS_28 ,TOOL_STS_29 ,TOOL_STS_30 ,DEL\
ETE_FLAG ,TOOL_COMMENT ,TRAN_USER_ID ,TRAN_COMMENT ,PREV_ACTIVE_HIST_SEQ ,HI\
ST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT into :b0,:b1,\
:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18\
,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,");
            sqlstm.stmt = ":b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b3\
8,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,\
:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b\
69  from MRASTOLHIS where ((FACTORY=:b0 and TOOL_ID=:b1) and HIST_SEQ=:b2) fo\
r update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )623;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MRASTOLHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTOLHIS_N.TOOL_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASTOLHIS_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )13;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASTOLHIS_N.TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASTOLHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASTOLHIS_N.TOOL_GRP);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASTOLHIS_N.TOOL_SET_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASTOLHIS_N.TOOL_SET_LOCATION);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASTOLHIS_N.TOOL_STATUS);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASTOLHIS_N.LOT_ID);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASTOLHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASTOLHIS_N.RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASTOLHIS_N.SUBRES_ID);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASTOLHIS_N.MAT_ID);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MRASTOLHIS_N.MAT_VER);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASTOLHIS_N.FLOW);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASTOLHIS_N.OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASTOLHIS_N.AREA_ID);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASTOLHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASTOLHIS_N.TOOL_LOCATION);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASTOLHIS_N.VENDOR_ID);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASTOLHIS_N.VENDOR_TOOL_ID);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_X);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Y);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Z);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_X);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Y);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Z);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASTOLHIS_N.GRADE);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASTOLHIS_N.TOOL_STS_1);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASTOLHIS_N.TOOL_STS_2);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASTOLHIS_N.TOOL_STS_3);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASTOLHIS_N.TOOL_STS_4);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASTOLHIS_N.TOOL_STS_5);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASTOLHIS_N.TOOL_STS_6);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASTOLHIS_N.TOOL_STS_7);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASTOLHIS_N.TOOL_STS_8);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASTOLHIS_N.TOOL_STS_9);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASTOLHIS_N.TOOL_STS_10);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASTOLHIS_N.TOOL_STS_11);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASTOLHIS_N.TOOL_STS_12);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASTOLHIS_N.TOOL_STS_13);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASTOLHIS_N.TOOL_STS_14);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASTOLHIS_N.TOOL_STS_15);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASTOLHIS_N.TOOL_STS_16);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASTOLHIS_N.TOOL_STS_17);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASTOLHIS_N.TOOL_STS_18);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASTOLHIS_N.TOOL_STS_19);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASTOLHIS_N.TOOL_STS_20);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASTOLHIS_N.TOOL_STS_21);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASTOLHIS_N.TOOL_STS_22);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASTOLHIS_N.TOOL_STS_23);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASTOLHIS_N.TOOL_STS_24);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASTOLHIS_N.TOOL_STS_25);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASTOLHIS_N.TOOL_STS_26);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASTOLHIS_N.TOOL_STS_27);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASTOLHIS_N.TOOL_STS_28);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASTOLHIS_N.TOOL_STS_29);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASTOLHIS_N.TOOL_STS_30);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASTOLHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASTOLHIS_N.TOOL_COMMENT);
            sqlstm.sqhstl[62] = (unsigned int  )401;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASTOLHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASTOLHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[64] = (unsigned int  )401;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASTOLHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASTOLHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[67] = (unsigned int  )15;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASTOLHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASTOLHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[69] = (unsigned int  )401;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[70] = (unsigned int  )11;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)&(MRASTOLHIS_N.HIST_SEQ);
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
        DBU_del_null_mrastolhis(&MRASTOLHIS_N, MRASTOLHIS);
    }

    DB_stop_query_timer("DBU_select_mrastolhis_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_mrastolhis_scalar(int sel_type, struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTOLHIS_N_TAG MRASTOLHIS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastolhis(&MRASTOLHIS_N, MRASTOLHIS);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MRASTOLHIS
                WHERE FACTORY = :MRASTOLHIS_N.FACTORY
                    AND TOOL_ID = :MRASTOLHIS_N.TOOL_ID
                    AND HIST_SEQ = :MRASTOLHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MRASTOLHIS where\
 ((FACTORY=:b1 and TOOL_ID=:b2) and HIST_SEQ=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )930;
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
            sqlstm.sqhstv[1] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MRASTOLHIS_N.HIST_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
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

    DB_stop_query_timer("DBU_select_mrastolhis_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_mrastolhis(int sel_type, struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTOLHIS_N_TAG MRASTOLHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastolhis(&MRASTOLHIS_N, MRASTOLHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MRASTOLHIS
                WHERE FACTORY = :MRASTOLHIS_N.FACTORY
                    AND TOOL_ID = :MRASTOLHIS_N.TOOL_ID
                    AND HIST_SEQ = :MRASTOLHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MRASTOLHIS  where ((FACTORY=:b0 and\
 TOOL_ID=:b1) and HIST_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )961;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MRASTOLHIS_N.HIST_SEQ);
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

    DB_stop_query_timer("DBU_delete_mrastolhis", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_mrastolhis(struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTOLHIS_N_TAG MRASTOLHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastolhis(&MRASTOLHIS_N, MRASTOLHIS);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MRASTOLHIS( 
                    FACTORY, 
                    TOOL_ID, 
                    HIST_SEQ, 
                    TOOL_TYPE, 
                    TOOL_EVENT_ID, 
                    TRAN_TIME, 
                    SYS_TRAN_TIME, 
                    TOOL_GRP, 
                    TOOL_SET_ID, 
                    TOOL_SET_LOCATION, 
                    TOOL_STATUS, 
                    LOT_ID, 
                    SUBLOT_ID, 
                    RES_ID, 
                    SUBRES_ID, 
                    MAT_ID, 
                    MAT_VER, 
                    FLOW, 
                    OPER, 
                    AREA_ID, 
                    SUB_AREA_ID, 
                    TOOL_LOCATION, 
                    VENDOR_ID, 
                    VENDOR_TOOL_ID, 
                    CELL_COUNT_X, 
                    CELL_COUNT_Y, 
                    CELL_COUNT_Z, 
                    CELL_SIZE_X, 
                    CELL_SIZE_Y, 
                    CELL_SIZE_Z, 
                    GRADE, 
                    TOOL_STS_1, 
                    TOOL_STS_2, 
                    TOOL_STS_3, 
                    TOOL_STS_4, 
                    TOOL_STS_5, 
                    TOOL_STS_6, 
                    TOOL_STS_7, 
                    TOOL_STS_8, 
                    TOOL_STS_9, 
                    TOOL_STS_10, 
                    TOOL_STS_11, 
                    TOOL_STS_12, 
                    TOOL_STS_13, 
                    TOOL_STS_14, 
                    TOOL_STS_15, 
                    TOOL_STS_16, 
                    TOOL_STS_17, 
                    TOOL_STS_18, 
                    TOOL_STS_19, 
                    TOOL_STS_20, 
                    TOOL_STS_21, 
                    TOOL_STS_22, 
                    TOOL_STS_23, 
                    TOOL_STS_24, 
                    TOOL_STS_25, 
                    TOOL_STS_26, 
                    TOOL_STS_27, 
                    TOOL_STS_28, 
                    TOOL_STS_29, 
                    TOOL_STS_30, 
                    DELETE_FLAG, 
                    TOOL_COMMENT, 
                    TRAN_USER_ID, 
                    TRAN_COMMENT, 
                    PREV_ACTIVE_HIST_SEQ, 
                    HIST_DEL_FLAG, 
                    HIST_DEL_TIME, 
                    HIST_DEL_USER_ID, 
                    HIST_DEL_COMMENT
         ) 
        VALUES (
                    :MRASTOLHIS_N.FACTORY,
                    :MRASTOLHIS_N.TOOL_ID,
                    :MRASTOLHIS_N.HIST_SEQ,
                    :MRASTOLHIS_N.TOOL_TYPE,
                    :MRASTOLHIS_N.TOOL_EVENT_ID,
                    :MRASTOLHIS_N.TRAN_TIME,
                    :MRASTOLHIS_N.SYS_TRAN_TIME,
                    :MRASTOLHIS_N.TOOL_GRP,
                    :MRASTOLHIS_N.TOOL_SET_ID,
                    :MRASTOLHIS_N.TOOL_SET_LOCATION,
                    :MRASTOLHIS_N.TOOL_STATUS,
                    :MRASTOLHIS_N.LOT_ID,
                    :MRASTOLHIS_N.SUBLOT_ID,
                    :MRASTOLHIS_N.RES_ID,
                    :MRASTOLHIS_N.SUBRES_ID,
                    :MRASTOLHIS_N.MAT_ID,
                    :MRASTOLHIS_N.MAT_VER,
                    :MRASTOLHIS_N.FLOW,
                    :MRASTOLHIS_N.OPER,
                    :MRASTOLHIS_N.AREA_ID,
                    :MRASTOLHIS_N.SUB_AREA_ID,
                    :MRASTOLHIS_N.TOOL_LOCATION,
                    :MRASTOLHIS_N.VENDOR_ID,
                    :MRASTOLHIS_N.VENDOR_TOOL_ID,
                    :MRASTOLHIS_N.CELL_COUNT_X,
                    :MRASTOLHIS_N.CELL_COUNT_Y,
                    :MRASTOLHIS_N.CELL_COUNT_Z,
                    :MRASTOLHIS_N.CELL_SIZE_X,
                    :MRASTOLHIS_N.CELL_SIZE_Y,
                    :MRASTOLHIS_N.CELL_SIZE_Z,
                    :MRASTOLHIS_N.GRADE,
                    :MRASTOLHIS_N.TOOL_STS_1,
                    :MRASTOLHIS_N.TOOL_STS_2,
                    :MRASTOLHIS_N.TOOL_STS_3,
                    :MRASTOLHIS_N.TOOL_STS_4,
                    :MRASTOLHIS_N.TOOL_STS_5,
                    :MRASTOLHIS_N.TOOL_STS_6,
                    :MRASTOLHIS_N.TOOL_STS_7,
                    :MRASTOLHIS_N.TOOL_STS_8,
                    :MRASTOLHIS_N.TOOL_STS_9,
                    :MRASTOLHIS_N.TOOL_STS_10,
                    :MRASTOLHIS_N.TOOL_STS_11,
                    :MRASTOLHIS_N.TOOL_STS_12,
                    :MRASTOLHIS_N.TOOL_STS_13,
                    :MRASTOLHIS_N.TOOL_STS_14,
                    :MRASTOLHIS_N.TOOL_STS_15,
                    :MRASTOLHIS_N.TOOL_STS_16,
                    :MRASTOLHIS_N.TOOL_STS_17,
                    :MRASTOLHIS_N.TOOL_STS_18,
                    :MRASTOLHIS_N.TOOL_STS_19,
                    :MRASTOLHIS_N.TOOL_STS_20,
                    :MRASTOLHIS_N.TOOL_STS_21,
                    :MRASTOLHIS_N.TOOL_STS_22,
                    :MRASTOLHIS_N.TOOL_STS_23,
                    :MRASTOLHIS_N.TOOL_STS_24,
                    :MRASTOLHIS_N.TOOL_STS_25,
                    :MRASTOLHIS_N.TOOL_STS_26,
                    :MRASTOLHIS_N.TOOL_STS_27,
                    :MRASTOLHIS_N.TOOL_STS_28,
                    :MRASTOLHIS_N.TOOL_STS_29,
                    :MRASTOLHIS_N.TOOL_STS_30,
                    :MRASTOLHIS_N.DELETE_FLAG,
                    :MRASTOLHIS_N.TOOL_COMMENT,
                    :MRASTOLHIS_N.TRAN_USER_ID,
                    :MRASTOLHIS_N.TRAN_COMMENT,
                    :MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ,
                    :MRASTOLHIS_N.HIST_DEL_FLAG,
                    :MRASTOLHIS_N.HIST_DEL_TIME,
                    :MRASTOLHIS_N.HIST_DEL_USER_ID,
                    :MRASTOLHIS_N.HIST_DEL_COMMENT
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 74;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MRASTOLHIS (FACTORY,TOOL_ID,HIST_SEQ,TOOL_TYPE,TOOL_EVENT\
_ID,TRAN_TIME,SYS_TRAN_TIME,TOOL_GRP,TOOL_SET_ID,TOOL_SET_LOCATION,TOOL_STAT\
US,LOT_ID,SUBLOT_ID,RES_ID,SUBRES_ID,MAT_ID,MAT_VER,FLOW,OPER,AREA_ID,SUB_AR\
EA_ID,TOOL_LOCATION,VENDOR_ID,VENDOR_TOOL_ID,CELL_COUNT_X,CELL_COUNT_Y,CELL_\
COUNT_Z,CELL_SIZE_X,CELL_SIZE_Y,CELL_SIZE_Z,GRADE,TOOL_STS_1,TOOL_STS_2,TOOL\
_STS_3,TOOL_STS_4,TOOL_STS_5,TOOL_STS_6,TOOL_STS_7,TOOL_STS_8,TOOL_STS_9,TOO\
L_STS_10,TOOL_STS_11,TOOL_STS_12,TOOL_STS_13,TOOL_STS_14,TOOL_STS_15,TOOL_ST\
S_16,TOOL_STS_17,TOOL_STS_18,TOOL_STS_19,TOOL_STS_20,TOOL_STS_21,TOOL_STS_22\
,TOOL_STS_23,TOOL_STS_24,TOOL_STS_25,TOOL_STS_26,TOOL_STS_27,TOOL_STS_28,TOO\
L_STS_29,TOOL_STS_30,DELETE_FLAG,TOOL_COMMENT,TRAN_USER_ID,TRAN_COMMENT,PREV\
_ACTIVE_HIST_SEQ,HIST_DEL_FLAG,HIST_DEL_TIME,HIST_DEL_USER_ID,HIST_DEL_COMME\
NT) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14\
,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,\
:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b3");
    sqlstm.stmt = "8,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49\
,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:\
b65,:b66,:b67,:b68,:b69)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )988;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MRASTOLHIS_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
    sqlstm.sqhstl[1] = (unsigned int  )31;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(MRASTOLHIS_N.HIST_SEQ);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MRASTOLHIS_N.TOOL_TYPE);
    sqlstm.sqhstl[3] = (unsigned int  )21;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MRASTOLHIS_N.TOOL_EVENT_ID);
    sqlstm.sqhstl[4] = (unsigned int  )13;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MRASTOLHIS_N.TRAN_TIME);
    sqlstm.sqhstl[5] = (unsigned int  )15;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MRASTOLHIS_N.SYS_TRAN_TIME);
    sqlstm.sqhstl[6] = (unsigned int  )15;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MRASTOLHIS_N.TOOL_GRP);
    sqlstm.sqhstl[7] = (unsigned int  )21;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MRASTOLHIS_N.TOOL_SET_ID);
    sqlstm.sqhstl[8] = (unsigned int  )21;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MRASTOLHIS_N.TOOL_SET_LOCATION);
    sqlstm.sqhstl[9] = (unsigned int  )21;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MRASTOLHIS_N.TOOL_STATUS);
    sqlstm.sqhstl[10] = (unsigned int  )11;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MRASTOLHIS_N.LOT_ID);
    sqlstm.sqhstl[11] = (unsigned int  )26;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MRASTOLHIS_N.SUBLOT_ID);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MRASTOLHIS_N.RES_ID);
    sqlstm.sqhstl[13] = (unsigned int  )21;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MRASTOLHIS_N.SUBRES_ID);
    sqlstm.sqhstl[14] = (unsigned int  )21;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MRASTOLHIS_N.MAT_ID);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)&(MRASTOLHIS_N.MAT_VER);
    sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MRASTOLHIS_N.FLOW);
    sqlstm.sqhstl[17] = (unsigned int  )21;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MRASTOLHIS_N.OPER);
    sqlstm.sqhstl[18] = (unsigned int  )11;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MRASTOLHIS_N.AREA_ID);
    sqlstm.sqhstl[19] = (unsigned int  )21;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MRASTOLHIS_N.SUB_AREA_ID);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MRASTOLHIS_N.TOOL_LOCATION);
    sqlstm.sqhstl[21] = (unsigned int  )21;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MRASTOLHIS_N.VENDOR_ID);
    sqlstm.sqhstl[22] = (unsigned int  )21;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MRASTOLHIS_N.VENDOR_TOOL_ID);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_X);
    sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Y);
    sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Z);
    sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_X);
    sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Y);
    sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Z);
    sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MRASTOLHIS_N.GRADE);
    sqlstm.sqhstl[30] = (unsigned int  )2;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MRASTOLHIS_N.TOOL_STS_1);
    sqlstm.sqhstl[31] = (unsigned int  )31;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MRASTOLHIS_N.TOOL_STS_2);
    sqlstm.sqhstl[32] = (unsigned int  )31;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MRASTOLHIS_N.TOOL_STS_3);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MRASTOLHIS_N.TOOL_STS_4);
    sqlstm.sqhstl[34] = (unsigned int  )31;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MRASTOLHIS_N.TOOL_STS_5);
    sqlstm.sqhstl[35] = (unsigned int  )31;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MRASTOLHIS_N.TOOL_STS_6);
    sqlstm.sqhstl[36] = (unsigned int  )31;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MRASTOLHIS_N.TOOL_STS_7);
    sqlstm.sqhstl[37] = (unsigned int  )31;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MRASTOLHIS_N.TOOL_STS_8);
    sqlstm.sqhstl[38] = (unsigned int  )31;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MRASTOLHIS_N.TOOL_STS_9);
    sqlstm.sqhstl[39] = (unsigned int  )31;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MRASTOLHIS_N.TOOL_STS_10);
    sqlstm.sqhstl[40] = (unsigned int  )31;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MRASTOLHIS_N.TOOL_STS_11);
    sqlstm.sqhstl[41] = (unsigned int  )31;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MRASTOLHIS_N.TOOL_STS_12);
    sqlstm.sqhstl[42] = (unsigned int  )31;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MRASTOLHIS_N.TOOL_STS_13);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MRASTOLHIS_N.TOOL_STS_14);
    sqlstm.sqhstl[44] = (unsigned int  )31;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MRASTOLHIS_N.TOOL_STS_15);
    sqlstm.sqhstl[45] = (unsigned int  )31;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MRASTOLHIS_N.TOOL_STS_16);
    sqlstm.sqhstl[46] = (unsigned int  )31;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MRASTOLHIS_N.TOOL_STS_17);
    sqlstm.sqhstl[47] = (unsigned int  )31;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MRASTOLHIS_N.TOOL_STS_18);
    sqlstm.sqhstl[48] = (unsigned int  )31;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MRASTOLHIS_N.TOOL_STS_19);
    sqlstm.sqhstl[49] = (unsigned int  )31;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MRASTOLHIS_N.TOOL_STS_20);
    sqlstm.sqhstl[50] = (unsigned int  )31;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MRASTOLHIS_N.TOOL_STS_21);
    sqlstm.sqhstl[51] = (unsigned int  )31;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MRASTOLHIS_N.TOOL_STS_22);
    sqlstm.sqhstl[52] = (unsigned int  )31;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MRASTOLHIS_N.TOOL_STS_23);
    sqlstm.sqhstl[53] = (unsigned int  )31;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MRASTOLHIS_N.TOOL_STS_24);
    sqlstm.sqhstl[54] = (unsigned int  )31;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MRASTOLHIS_N.TOOL_STS_25);
    sqlstm.sqhstl[55] = (unsigned int  )31;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MRASTOLHIS_N.TOOL_STS_26);
    sqlstm.sqhstl[56] = (unsigned int  )31;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MRASTOLHIS_N.TOOL_STS_27);
    sqlstm.sqhstl[57] = (unsigned int  )31;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MRASTOLHIS_N.TOOL_STS_28);
    sqlstm.sqhstl[58] = (unsigned int  )31;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MRASTOLHIS_N.TOOL_STS_29);
    sqlstm.sqhstl[59] = (unsigned int  )31;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MRASTOLHIS_N.TOOL_STS_30);
    sqlstm.sqhstl[60] = (unsigned int  )31;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MRASTOLHIS_N.DELETE_FLAG);
    sqlstm.sqhstl[61] = (unsigned int  )2;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MRASTOLHIS_N.TOOL_COMMENT);
    sqlstm.sqhstl[62] = (unsigned int  )401;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MRASTOLHIS_N.TRAN_USER_ID);
    sqlstm.sqhstl[63] = (unsigned int  )21;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MRASTOLHIS_N.TRAN_COMMENT);
    sqlstm.sqhstl[64] = (unsigned int  )401;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)&(MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ);
    sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MRASTOLHIS_N.HIST_DEL_FLAG);
    sqlstm.sqhstl[66] = (unsigned int  )2;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MRASTOLHIS_N.HIST_DEL_TIME);
    sqlstm.sqhstl[67] = (unsigned int  )15;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MRASTOLHIS_N.HIST_DEL_USER_ID);
    sqlstm.sqhstl[68] = (unsigned int  )21;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MRASTOLHIS_N.HIST_DEL_COMMENT);
    sqlstm.sqhstl[69] = (unsigned int  )401;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_mrastolhis", 0);
}


/* SQL UPDATE Function */
void DBU_update_mrastolhis(int sel_type, struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTOLHIS_N_TAG MRASTOLHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastolhis(&MRASTOLHIS_N, MRASTOLHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MRASTOLHIS SET
                    TOOL_TYPE = :MRASTOLHIS_N.TOOL_TYPE,
                    TOOL_EVENT_ID = :MRASTOLHIS_N.TOOL_EVENT_ID,
                    TRAN_TIME = :MRASTOLHIS_N.TRAN_TIME,
                    SYS_TRAN_TIME = :MRASTOLHIS_N.SYS_TRAN_TIME,
                    TOOL_GRP = :MRASTOLHIS_N.TOOL_GRP,
                    TOOL_SET_ID = :MRASTOLHIS_N.TOOL_SET_ID,
                    TOOL_SET_LOCATION = :MRASTOLHIS_N.TOOL_SET_LOCATION,
                    TOOL_STATUS = :MRASTOLHIS_N.TOOL_STATUS,
                    LOT_ID = :MRASTOLHIS_N.LOT_ID,
                    SUBLOT_ID = :MRASTOLHIS_N.SUBLOT_ID,
                    RES_ID = :MRASTOLHIS_N.RES_ID,
                    SUBRES_ID = :MRASTOLHIS_N.SUBRES_ID,
                    MAT_ID = :MRASTOLHIS_N.MAT_ID,
                    MAT_VER = :MRASTOLHIS_N.MAT_VER,
                    FLOW = :MRASTOLHIS_N.FLOW,
                    OPER = :MRASTOLHIS_N.OPER,
                    AREA_ID = :MRASTOLHIS_N.AREA_ID,
                    SUB_AREA_ID = :MRASTOLHIS_N.SUB_AREA_ID,
                    TOOL_LOCATION = :MRASTOLHIS_N.TOOL_LOCATION,
                    VENDOR_ID = :MRASTOLHIS_N.VENDOR_ID,
                    VENDOR_TOOL_ID = :MRASTOLHIS_N.VENDOR_TOOL_ID,
                    CELL_COUNT_X = :MRASTOLHIS_N.CELL_COUNT_X,
                    CELL_COUNT_Y = :MRASTOLHIS_N.CELL_COUNT_Y,
                    CELL_COUNT_Z = :MRASTOLHIS_N.CELL_COUNT_Z,
                    CELL_SIZE_X = :MRASTOLHIS_N.CELL_SIZE_X,
                    CELL_SIZE_Y = :MRASTOLHIS_N.CELL_SIZE_Y,
                    CELL_SIZE_Z = :MRASTOLHIS_N.CELL_SIZE_Z,
                    GRADE = :MRASTOLHIS_N.GRADE,
                    TOOL_STS_1 = :MRASTOLHIS_N.TOOL_STS_1,
                    TOOL_STS_2 = :MRASTOLHIS_N.TOOL_STS_2,
                    TOOL_STS_3 = :MRASTOLHIS_N.TOOL_STS_3,
                    TOOL_STS_4 = :MRASTOLHIS_N.TOOL_STS_4,
                    TOOL_STS_5 = :MRASTOLHIS_N.TOOL_STS_5,
                    TOOL_STS_6 = :MRASTOLHIS_N.TOOL_STS_6,
                    TOOL_STS_7 = :MRASTOLHIS_N.TOOL_STS_7,
                    TOOL_STS_8 = :MRASTOLHIS_N.TOOL_STS_8,
                    TOOL_STS_9 = :MRASTOLHIS_N.TOOL_STS_9,
                    TOOL_STS_10 = :MRASTOLHIS_N.TOOL_STS_10,
                    TOOL_STS_11 = :MRASTOLHIS_N.TOOL_STS_11,
                    TOOL_STS_12 = :MRASTOLHIS_N.TOOL_STS_12,
                    TOOL_STS_13 = :MRASTOLHIS_N.TOOL_STS_13,
                    TOOL_STS_14 = :MRASTOLHIS_N.TOOL_STS_14,
                    TOOL_STS_15 = :MRASTOLHIS_N.TOOL_STS_15,
                    TOOL_STS_16 = :MRASTOLHIS_N.TOOL_STS_16,
                    TOOL_STS_17 = :MRASTOLHIS_N.TOOL_STS_17,
                    TOOL_STS_18 = :MRASTOLHIS_N.TOOL_STS_18,
                    TOOL_STS_19 = :MRASTOLHIS_N.TOOL_STS_19,
                    TOOL_STS_20 = :MRASTOLHIS_N.TOOL_STS_20,
                    TOOL_STS_21 = :MRASTOLHIS_N.TOOL_STS_21,
                    TOOL_STS_22 = :MRASTOLHIS_N.TOOL_STS_22,
                    TOOL_STS_23 = :MRASTOLHIS_N.TOOL_STS_23,
                    TOOL_STS_24 = :MRASTOLHIS_N.TOOL_STS_24,
                    TOOL_STS_25 = :MRASTOLHIS_N.TOOL_STS_25,
                    TOOL_STS_26 = :MRASTOLHIS_N.TOOL_STS_26,
                    TOOL_STS_27 = :MRASTOLHIS_N.TOOL_STS_27,
                    TOOL_STS_28 = :MRASTOLHIS_N.TOOL_STS_28,
                    TOOL_STS_29 = :MRASTOLHIS_N.TOOL_STS_29,
                    TOOL_STS_30 = :MRASTOLHIS_N.TOOL_STS_30,
                    DELETE_FLAG = :MRASTOLHIS_N.DELETE_FLAG,
                    TOOL_COMMENT = :MRASTOLHIS_N.TOOL_COMMENT,
                    TRAN_USER_ID = :MRASTOLHIS_N.TRAN_USER_ID,
                    TRAN_COMMENT = :MRASTOLHIS_N.TRAN_COMMENT,
                    PREV_ACTIVE_HIST_SEQ = :MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ,
                    HIST_DEL_FLAG = :MRASTOLHIS_N.HIST_DEL_FLAG,
                    HIST_DEL_TIME = :MRASTOLHIS_N.HIST_DEL_TIME,
                    HIST_DEL_USER_ID = :MRASTOLHIS_N.HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT = :MRASTOLHIS_N.HIST_DEL_COMMENT
                WHERE FACTORY = :MRASTOLHIS_N.FACTORY
                    AND TOOL_ID = :MRASTOLHIS_N.TOOL_ID
                    AND HIST_SEQ = :MRASTOLHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MRASTOLHIS  set TOOL_TYPE=:b0,TOOL_EVENT_ID=:b1,TRAN_T\
IME=:b2,SYS_TRAN_TIME=:b3,TOOL_GRP=:b4,TOOL_SET_ID=:b5,TOOL_SET_LOCATION=:b6\
,TOOL_STATUS=:b7,LOT_ID=:b8,SUBLOT_ID=:b9,RES_ID=:b10,SUBRES_ID=:b11,MAT_ID=\
:b12,MAT_VER=:b13,FLOW=:b14,OPER=:b15,AREA_ID=:b16,SUB_AREA_ID=:b17,TOOL_LOC\
ATION=:b18,VENDOR_ID=:b19,VENDOR_TOOL_ID=:b20,CELL_COUNT_X=:b21,CELL_COUNT_Y\
=:b22,CELL_COUNT_Z=:b23,CELL_SIZE_X=:b24,CELL_SIZE_Y=:b25,CELL_SIZE_Z=:b26,G\
RADE=:b27,TOOL_STS_1=:b28,TOOL_STS_2=:b29,TOOL_STS_3=:b30,TOOL_STS_4=:b31,TO\
OL_STS_5=:b32,TOOL_STS_6=:b33,TOOL_STS_7=:b34,TOOL_STS_8=:b35,TOOL_STS_9=:b3\
6,TOOL_STS_10=:b37,TOOL_STS_11=:b38,TOOL_STS_12=:b39,TOOL_STS_13=:b40,TOOL_S\
TS_14=:b41,TOOL_STS_15=:b42,TOOL_STS_16=:b43,TOOL_STS_17=:b44,TOOL_STS_18=:b\
45,TOOL_STS_19=:b46,TOOL_STS_20=:b47,TOOL_STS_21=:b48,TOOL_STS_22=:b49,TOOL_\
STS_23=:b50,TOOL_STS_24=:b51,TOOL_STS_25=:b52,TOOL_STS_26=:b53,TOOL_STS_27=:\
b54,TOOL_STS_28=:b55,TOOL_STS_29=:b56,TOOL_STS_30=:b57,DELETE_FLAG=:b58,TOOL\
_COMMENT=:b59,TRAN_USER_ID=:b60,TRAN_COMMENT=:b61,P");
            sqlstm.stmt = "REV_ACTIVE_HIST_SEQ=:b62,HIST_DEL_FLAG=:b63,HIST\
_DEL_TIME=:b64,HIST_DEL_USER_ID=:b65,HIST_DEL_COMMENT=:b66 where ((FACTORY=:b\
67 and TOOL_ID=:b68) and HIST_SEQ=:b69)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1283;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASTOLHIS_N.TOOL_TYPE);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTOLHIS_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )13;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASTOLHIS_N.TRAN_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTOLHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASTOLHIS_N.TOOL_GRP);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASTOLHIS_N.TOOL_SET_ID);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASTOLHIS_N.TOOL_SET_LOCATION);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASTOLHIS_N.TOOL_STATUS);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASTOLHIS_N.LOT_ID);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASTOLHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASTOLHIS_N.RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASTOLHIS_N.SUBRES_ID);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASTOLHIS_N.MAT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MRASTOLHIS_N.MAT_VER);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASTOLHIS_N.FLOW);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASTOLHIS_N.OPER);
            sqlstm.sqhstl[15] = (unsigned int  )11;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASTOLHIS_N.AREA_ID);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASTOLHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASTOLHIS_N.TOOL_LOCATION);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASTOLHIS_N.VENDOR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASTOLHIS_N.VENDOR_TOOL_ID);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_X);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Y);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Z);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_X);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Y);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Z);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASTOLHIS_N.GRADE);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASTOLHIS_N.TOOL_STS_1);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASTOLHIS_N.TOOL_STS_2);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASTOLHIS_N.TOOL_STS_3);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASTOLHIS_N.TOOL_STS_4);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASTOLHIS_N.TOOL_STS_5);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASTOLHIS_N.TOOL_STS_6);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASTOLHIS_N.TOOL_STS_7);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASTOLHIS_N.TOOL_STS_8);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASTOLHIS_N.TOOL_STS_9);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASTOLHIS_N.TOOL_STS_10);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASTOLHIS_N.TOOL_STS_11);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASTOLHIS_N.TOOL_STS_12);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASTOLHIS_N.TOOL_STS_13);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASTOLHIS_N.TOOL_STS_14);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASTOLHIS_N.TOOL_STS_15);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASTOLHIS_N.TOOL_STS_16);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASTOLHIS_N.TOOL_STS_17);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASTOLHIS_N.TOOL_STS_18);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASTOLHIS_N.TOOL_STS_19);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASTOLHIS_N.TOOL_STS_20);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASTOLHIS_N.TOOL_STS_21);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASTOLHIS_N.TOOL_STS_22);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASTOLHIS_N.TOOL_STS_23);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASTOLHIS_N.TOOL_STS_24);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASTOLHIS_N.TOOL_STS_25);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASTOLHIS_N.TOOL_STS_26);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASTOLHIS_N.TOOL_STS_27);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASTOLHIS_N.TOOL_STS_28);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASTOLHIS_N.TOOL_STS_29);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASTOLHIS_N.TOOL_STS_30);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASTOLHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASTOLHIS_N.TOOL_COMMENT);
            sqlstm.sqhstl[59] = (unsigned int  )401;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASTOLHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[60] = (unsigned int  )21;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASTOLHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[61] = (unsigned int  )401;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASTOLHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASTOLHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[64] = (unsigned int  )15;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASTOLHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASTOLHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[66] = (unsigned int  )401;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[67] = (unsigned int  )11;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)&(MRASTOLHIS_N.HIST_SEQ);
            sqlstm.sqhstl[69] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_mrastolhis", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_mrastolhis(int sel_type, struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTOLHIS_N_TAG MRASTOLHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastolhis(&MRASTOLHIS_N, MRASTOLHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_MRASTOLHIS_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    TOOL_ID,
                    HIST_SEQ,
                    TOOL_TYPE,
                    TOOL_EVENT_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TOOL_GRP,
                    TOOL_SET_ID,
                    TOOL_SET_LOCATION,
                    TOOL_STATUS,
                    LOT_ID,
                    SUBLOT_ID,
                    RES_ID,
                    SUBRES_ID,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    OPER,
                    AREA_ID,
                    SUB_AREA_ID,
                    TOOL_LOCATION,
                    VENDOR_ID,
                    VENDOR_TOOL_ID,
                    CELL_COUNT_X,
                    CELL_COUNT_Y,
                    CELL_COUNT_Z,
                    CELL_SIZE_X,
                    CELL_SIZE_Y,
                    CELL_SIZE_Z,
                    GRADE,
                    TOOL_STS_1,
                    TOOL_STS_2,
                    TOOL_STS_3,
                    TOOL_STS_4,
                    TOOL_STS_5,
                    TOOL_STS_6,
                    TOOL_STS_7,
                    TOOL_STS_8,
                    TOOL_STS_9,
                    TOOL_STS_10,
                    TOOL_STS_11,
                    TOOL_STS_12,
                    TOOL_STS_13,
                    TOOL_STS_14,
                    TOOL_STS_15,
                    TOOL_STS_16,
                    TOOL_STS_17,
                    TOOL_STS_18,
                    TOOL_STS_19,
                    TOOL_STS_20,
                    TOOL_STS_21,
                    TOOL_STS_22,
                    TOOL_STS_23,
                    TOOL_STS_24,
                    TOOL_STS_25,
                    TOOL_STS_26,
                    TOOL_STS_27,
                    TOOL_STS_28,
                    TOOL_STS_29,
                    TOOL_STS_30,
                    DELETE_FLAG,
                    TOOL_COMMENT,
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    PREV_ACTIVE_HIST_SEQ,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT
                FROM MRASTOLHIS
                ORDER BY FACTORY ASC,
                    TOOL_ID ASC,
                    HIST_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_MRASTOLHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1578;
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

    DB_stop_query_timer("DBU_open_mrastolhis", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_mrastolhis(int sel_type, struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTOLHIS_N_TAG MRASTOLHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_MRASTOLHIS_CUR_1 INTO
                :MRASTOLHIS_N.FACTORY,
                :MRASTOLHIS_N.TOOL_ID,
                :MRASTOLHIS_N.HIST_SEQ,
                :MRASTOLHIS_N.TOOL_TYPE,
                :MRASTOLHIS_N.TOOL_EVENT_ID,
                :MRASTOLHIS_N.TRAN_TIME,
                :MRASTOLHIS_N.SYS_TRAN_TIME,
                :MRASTOLHIS_N.TOOL_GRP,
                :MRASTOLHIS_N.TOOL_SET_ID,
                :MRASTOLHIS_N.TOOL_SET_LOCATION,
                :MRASTOLHIS_N.TOOL_STATUS,
                :MRASTOLHIS_N.LOT_ID,
                :MRASTOLHIS_N.SUBLOT_ID,
                :MRASTOLHIS_N.RES_ID,
                :MRASTOLHIS_N.SUBRES_ID,
                :MRASTOLHIS_N.MAT_ID,
                :MRASTOLHIS_N.MAT_VER,
                :MRASTOLHIS_N.FLOW,
                :MRASTOLHIS_N.OPER,
                :MRASTOLHIS_N.AREA_ID,
                :MRASTOLHIS_N.SUB_AREA_ID,
                :MRASTOLHIS_N.TOOL_LOCATION,
                :MRASTOLHIS_N.VENDOR_ID,
                :MRASTOLHIS_N.VENDOR_TOOL_ID,
                :MRASTOLHIS_N.CELL_COUNT_X,
                :MRASTOLHIS_N.CELL_COUNT_Y,
                :MRASTOLHIS_N.CELL_COUNT_Z,
                :MRASTOLHIS_N.CELL_SIZE_X,
                :MRASTOLHIS_N.CELL_SIZE_Y,
                :MRASTOLHIS_N.CELL_SIZE_Z,
                :MRASTOLHIS_N.GRADE,
                :MRASTOLHIS_N.TOOL_STS_1,
                :MRASTOLHIS_N.TOOL_STS_2,
                :MRASTOLHIS_N.TOOL_STS_3,
                :MRASTOLHIS_N.TOOL_STS_4,
                :MRASTOLHIS_N.TOOL_STS_5,
                :MRASTOLHIS_N.TOOL_STS_6,
                :MRASTOLHIS_N.TOOL_STS_7,
                :MRASTOLHIS_N.TOOL_STS_8,
                :MRASTOLHIS_N.TOOL_STS_9,
                :MRASTOLHIS_N.TOOL_STS_10,
                :MRASTOLHIS_N.TOOL_STS_11,
                :MRASTOLHIS_N.TOOL_STS_12,
                :MRASTOLHIS_N.TOOL_STS_13,
                :MRASTOLHIS_N.TOOL_STS_14,
                :MRASTOLHIS_N.TOOL_STS_15,
                :MRASTOLHIS_N.TOOL_STS_16,
                :MRASTOLHIS_N.TOOL_STS_17,
                :MRASTOLHIS_N.TOOL_STS_18,
                :MRASTOLHIS_N.TOOL_STS_19,
                :MRASTOLHIS_N.TOOL_STS_20,
                :MRASTOLHIS_N.TOOL_STS_21,
                :MRASTOLHIS_N.TOOL_STS_22,
                :MRASTOLHIS_N.TOOL_STS_23,
                :MRASTOLHIS_N.TOOL_STS_24,
                :MRASTOLHIS_N.TOOL_STS_25,
                :MRASTOLHIS_N.TOOL_STS_26,
                :MRASTOLHIS_N.TOOL_STS_27,
                :MRASTOLHIS_N.TOOL_STS_28,
                :MRASTOLHIS_N.TOOL_STS_29,
                :MRASTOLHIS_N.TOOL_STS_30,
                :MRASTOLHIS_N.DELETE_FLAG,
                :MRASTOLHIS_N.TOOL_COMMENT,
                :MRASTOLHIS_N.TRAN_USER_ID,
                :MRASTOLHIS_N.TRAN_COMMENT,
                :MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ,
                :MRASTOLHIS_N.HIST_DEL_FLAG,
                :MRASTOLHIS_N.HIST_DEL_TIME,
                :MRASTOLHIS_N.HIST_DEL_USER_ID,
                :MRASTOLHIS_N.HIST_DEL_COMMENT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1593;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MRASTOLHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTOLHIS_N.TOOL_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MRASTOLHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTOLHIS_N.TOOL_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASTOLHIS_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )13;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASTOLHIS_N.TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASTOLHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASTOLHIS_N.TOOL_GRP);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASTOLHIS_N.TOOL_SET_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASTOLHIS_N.TOOL_SET_LOCATION);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASTOLHIS_N.TOOL_STATUS);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASTOLHIS_N.LOT_ID);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASTOLHIS_N.SUBLOT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASTOLHIS_N.RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASTOLHIS_N.SUBRES_ID);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASTOLHIS_N.MAT_ID);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MRASTOLHIS_N.MAT_VER);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASTOLHIS_N.FLOW);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASTOLHIS_N.OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASTOLHIS_N.AREA_ID);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASTOLHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASTOLHIS_N.TOOL_LOCATION);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASTOLHIS_N.VENDOR_ID);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASTOLHIS_N.VENDOR_TOOL_ID);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_X);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Y);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MRASTOLHIS_N.CELL_COUNT_Z);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_X);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Y);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MRASTOLHIS_N.CELL_SIZE_Z);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASTOLHIS_N.GRADE);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASTOLHIS_N.TOOL_STS_1);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASTOLHIS_N.TOOL_STS_2);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASTOLHIS_N.TOOL_STS_3);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASTOLHIS_N.TOOL_STS_4);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASTOLHIS_N.TOOL_STS_5);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASTOLHIS_N.TOOL_STS_6);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASTOLHIS_N.TOOL_STS_7);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASTOLHIS_N.TOOL_STS_8);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASTOLHIS_N.TOOL_STS_9);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASTOLHIS_N.TOOL_STS_10);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASTOLHIS_N.TOOL_STS_11);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASTOLHIS_N.TOOL_STS_12);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASTOLHIS_N.TOOL_STS_13);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASTOLHIS_N.TOOL_STS_14);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASTOLHIS_N.TOOL_STS_15);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASTOLHIS_N.TOOL_STS_16);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASTOLHIS_N.TOOL_STS_17);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASTOLHIS_N.TOOL_STS_18);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASTOLHIS_N.TOOL_STS_19);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASTOLHIS_N.TOOL_STS_20);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASTOLHIS_N.TOOL_STS_21);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASTOLHIS_N.TOOL_STS_22);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASTOLHIS_N.TOOL_STS_23);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASTOLHIS_N.TOOL_STS_24);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASTOLHIS_N.TOOL_STS_25);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASTOLHIS_N.TOOL_STS_26);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASTOLHIS_N.TOOL_STS_27);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASTOLHIS_N.TOOL_STS_28);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASTOLHIS_N.TOOL_STS_29);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASTOLHIS_N.TOOL_STS_30);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASTOLHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASTOLHIS_N.TOOL_COMMENT);
            sqlstm.sqhstl[62] = (unsigned int  )401;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASTOLHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASTOLHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[64] = (unsigned int  )401;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MRASTOLHIS_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASTOLHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASTOLHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[67] = (unsigned int  )15;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASTOLHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASTOLHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[69] = (unsigned int  )401;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
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
        DBU_del_null_mrastolhis(&MRASTOLHIS_N, MRASTOLHIS);
    }

    DB_stop_query_timer("DBU_fetch_mrastolhis", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_mrastolhis(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_MRASTOLHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 74;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1888;
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

    DB_stop_query_timer("DBU_close_mrastolhis", sel_type);
}


/* Initialize Function */
void DBU_init_mrastolhis(struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    /* memset by Space */
    memset(MRASTOLHIS, ' ', sizeof(struct MRASTOLHIS_TAG));
    
    MRASTOLHIS->HIST_SEQ = 0;
    MRASTOLHIS->MAT_VER = 0;
    MRASTOLHIS->CELL_COUNT_X = 0;
    MRASTOLHIS->CELL_COUNT_Y = 0;
    MRASTOLHIS->CELL_COUNT_Z = 0;
    MRASTOLHIS->CELL_SIZE_X = 0;
    MRASTOLHIS->CELL_SIZE_Y = 0;
    MRASTOLHIS->CELL_SIZE_Z = 0;
    MRASTOLHIS->PREV_ACTIVE_HIST_SEQ = 0;
}


/* Add Null Function */
void DBU_add_null_mrastolhis(struct MRASTOLHIS_N_TAG *MRASTOLHIS_N, struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    /* memset by NULL */
    memset(MRASTOLHIS_N, '\0', sizeof(struct MRASTOLHIS_N_TAG));
    
    MEMCPY_AN(MRASTOLHIS_N->FACTORY, MRASTOLHIS->FACTORY, sizeof(MRASTOLHIS->FACTORY));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_ID, MRASTOLHIS->TOOL_ID, sizeof(MRASTOLHIS->TOOL_ID));
    MRASTOLHIS_N->HIST_SEQ = MRASTOLHIS->HIST_SEQ;
    MEMCPY_AN(MRASTOLHIS_N->TOOL_TYPE, MRASTOLHIS->TOOL_TYPE, sizeof(MRASTOLHIS->TOOL_TYPE));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_EVENT_ID, MRASTOLHIS->TOOL_EVENT_ID, sizeof(MRASTOLHIS->TOOL_EVENT_ID));
    MEMCPY_AN(MRASTOLHIS_N->TRAN_TIME, MRASTOLHIS->TRAN_TIME, sizeof(MRASTOLHIS->TRAN_TIME));
    MEMCPY_AN(MRASTOLHIS_N->SYS_TRAN_TIME, MRASTOLHIS->SYS_TRAN_TIME, sizeof(MRASTOLHIS->SYS_TRAN_TIME));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_GRP, MRASTOLHIS->TOOL_GRP, sizeof(MRASTOLHIS->TOOL_GRP));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_SET_ID, MRASTOLHIS->TOOL_SET_ID, sizeof(MRASTOLHIS->TOOL_SET_ID));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_SET_LOCATION, MRASTOLHIS->TOOL_SET_LOCATION, sizeof(MRASTOLHIS->TOOL_SET_LOCATION));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STATUS, MRASTOLHIS->TOOL_STATUS, sizeof(MRASTOLHIS->TOOL_STATUS));
    MEMCPY_AN(MRASTOLHIS_N->LOT_ID, MRASTOLHIS->LOT_ID, sizeof(MRASTOLHIS->LOT_ID));
    MEMCPY_AN(MRASTOLHIS_N->SUBLOT_ID, MRASTOLHIS->SUBLOT_ID, sizeof(MRASTOLHIS->SUBLOT_ID));
    MEMCPY_AN(MRASTOLHIS_N->RES_ID, MRASTOLHIS->RES_ID, sizeof(MRASTOLHIS->RES_ID));
    MEMCPY_AN(MRASTOLHIS_N->SUBRES_ID, MRASTOLHIS->SUBRES_ID, sizeof(MRASTOLHIS->SUBRES_ID));
    MEMCPY_AN(MRASTOLHIS_N->MAT_ID, MRASTOLHIS->MAT_ID, sizeof(MRASTOLHIS->MAT_ID));
    MRASTOLHIS_N->MAT_VER = MRASTOLHIS->MAT_VER;
    MEMCPY_AN(MRASTOLHIS_N->FLOW, MRASTOLHIS->FLOW, sizeof(MRASTOLHIS->FLOW));
    MEMCPY_AN(MRASTOLHIS_N->OPER, MRASTOLHIS->OPER, sizeof(MRASTOLHIS->OPER));
    MEMCPY_AN(MRASTOLHIS_N->AREA_ID, MRASTOLHIS->AREA_ID, sizeof(MRASTOLHIS->AREA_ID));
    MEMCPY_AN(MRASTOLHIS_N->SUB_AREA_ID, MRASTOLHIS->SUB_AREA_ID, sizeof(MRASTOLHIS->SUB_AREA_ID));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_LOCATION, MRASTOLHIS->TOOL_LOCATION, sizeof(MRASTOLHIS->TOOL_LOCATION));
    MEMCPY_AN(MRASTOLHIS_N->VENDOR_ID, MRASTOLHIS->VENDOR_ID, sizeof(MRASTOLHIS->VENDOR_ID));
    MEMCPY_AN(MRASTOLHIS_N->VENDOR_TOOL_ID, MRASTOLHIS->VENDOR_TOOL_ID, sizeof(MRASTOLHIS->VENDOR_TOOL_ID));
    MRASTOLHIS_N->CELL_COUNT_X = MRASTOLHIS->CELL_COUNT_X;
    MRASTOLHIS_N->CELL_COUNT_Y = MRASTOLHIS->CELL_COUNT_Y;
    MRASTOLHIS_N->CELL_COUNT_Z = MRASTOLHIS->CELL_COUNT_Z;
    MRASTOLHIS_N->CELL_SIZE_X = MRASTOLHIS->CELL_SIZE_X;
    MRASTOLHIS_N->CELL_SIZE_Y = MRASTOLHIS->CELL_SIZE_Y;
    MRASTOLHIS_N->CELL_SIZE_Z = MRASTOLHIS->CELL_SIZE_Z;
    MRASTOLHIS_N->GRADE[0] = MRASTOLHIS->GRADE;
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_1, MRASTOLHIS->TOOL_STS_1, sizeof(MRASTOLHIS->TOOL_STS_1));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_2, MRASTOLHIS->TOOL_STS_2, sizeof(MRASTOLHIS->TOOL_STS_2));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_3, MRASTOLHIS->TOOL_STS_3, sizeof(MRASTOLHIS->TOOL_STS_3));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_4, MRASTOLHIS->TOOL_STS_4, sizeof(MRASTOLHIS->TOOL_STS_4));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_5, MRASTOLHIS->TOOL_STS_5, sizeof(MRASTOLHIS->TOOL_STS_5));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_6, MRASTOLHIS->TOOL_STS_6, sizeof(MRASTOLHIS->TOOL_STS_6));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_7, MRASTOLHIS->TOOL_STS_7, sizeof(MRASTOLHIS->TOOL_STS_7));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_8, MRASTOLHIS->TOOL_STS_8, sizeof(MRASTOLHIS->TOOL_STS_8));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_9, MRASTOLHIS->TOOL_STS_9, sizeof(MRASTOLHIS->TOOL_STS_9));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_10, MRASTOLHIS->TOOL_STS_10, sizeof(MRASTOLHIS->TOOL_STS_10));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_11, MRASTOLHIS->TOOL_STS_11, sizeof(MRASTOLHIS->TOOL_STS_11));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_12, MRASTOLHIS->TOOL_STS_12, sizeof(MRASTOLHIS->TOOL_STS_12));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_13, MRASTOLHIS->TOOL_STS_13, sizeof(MRASTOLHIS->TOOL_STS_13));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_14, MRASTOLHIS->TOOL_STS_14, sizeof(MRASTOLHIS->TOOL_STS_14));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_15, MRASTOLHIS->TOOL_STS_15, sizeof(MRASTOLHIS->TOOL_STS_15));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_16, MRASTOLHIS->TOOL_STS_16, sizeof(MRASTOLHIS->TOOL_STS_16));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_17, MRASTOLHIS->TOOL_STS_17, sizeof(MRASTOLHIS->TOOL_STS_17));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_18, MRASTOLHIS->TOOL_STS_18, sizeof(MRASTOLHIS->TOOL_STS_18));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_19, MRASTOLHIS->TOOL_STS_19, sizeof(MRASTOLHIS->TOOL_STS_19));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_20, MRASTOLHIS->TOOL_STS_20, sizeof(MRASTOLHIS->TOOL_STS_20));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_21, MRASTOLHIS->TOOL_STS_21, sizeof(MRASTOLHIS->TOOL_STS_21));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_22, MRASTOLHIS->TOOL_STS_22, sizeof(MRASTOLHIS->TOOL_STS_22));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_23, MRASTOLHIS->TOOL_STS_23, sizeof(MRASTOLHIS->TOOL_STS_23));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_24, MRASTOLHIS->TOOL_STS_24, sizeof(MRASTOLHIS->TOOL_STS_24));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_25, MRASTOLHIS->TOOL_STS_25, sizeof(MRASTOLHIS->TOOL_STS_25));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_26, MRASTOLHIS->TOOL_STS_26, sizeof(MRASTOLHIS->TOOL_STS_26));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_27, MRASTOLHIS->TOOL_STS_27, sizeof(MRASTOLHIS->TOOL_STS_27));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_28, MRASTOLHIS->TOOL_STS_28, sizeof(MRASTOLHIS->TOOL_STS_28));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_29, MRASTOLHIS->TOOL_STS_29, sizeof(MRASTOLHIS->TOOL_STS_29));
    MEMCPY_AN(MRASTOLHIS_N->TOOL_STS_30, MRASTOLHIS->TOOL_STS_30, sizeof(MRASTOLHIS->TOOL_STS_30));
    MRASTOLHIS_N->DELETE_FLAG[0] = MRASTOLHIS->DELETE_FLAG;
    MEMCPY_AN(MRASTOLHIS_N->TOOL_COMMENT, MRASTOLHIS->TOOL_COMMENT, sizeof(MRASTOLHIS->TOOL_COMMENT));
    MEMCPY_AN(MRASTOLHIS_N->TRAN_USER_ID, MRASTOLHIS->TRAN_USER_ID, sizeof(MRASTOLHIS->TRAN_USER_ID));
    MEMCPY_AN(MRASTOLHIS_N->TRAN_COMMENT, MRASTOLHIS->TRAN_COMMENT, sizeof(MRASTOLHIS->TRAN_COMMENT));
    MRASTOLHIS_N->PREV_ACTIVE_HIST_SEQ = MRASTOLHIS->PREV_ACTIVE_HIST_SEQ;
    MRASTOLHIS_N->HIST_DEL_FLAG[0] = MRASTOLHIS->HIST_DEL_FLAG;
    MEMCPY_AN(MRASTOLHIS_N->HIST_DEL_TIME, MRASTOLHIS->HIST_DEL_TIME, sizeof(MRASTOLHIS->HIST_DEL_TIME));
    MEMCPY_AN(MRASTOLHIS_N->HIST_DEL_USER_ID, MRASTOLHIS->HIST_DEL_USER_ID, sizeof(MRASTOLHIS->HIST_DEL_USER_ID));
    MEMCPY_AN(MRASTOLHIS_N->HIST_DEL_COMMENT, MRASTOLHIS->HIST_DEL_COMMENT, sizeof(MRASTOLHIS->HIST_DEL_COMMENT));
}


/* Del Null Function */
void DBU_del_null_mrastolhis(struct MRASTOLHIS_N_TAG *MRASTOLHIS_N, struct MRASTOLHIS_TAG *MRASTOLHIS)
{
    MEMCPY_DN(MRASTOLHIS->FACTORY, MRASTOLHIS_N->FACTORY, sizeof(MRASTOLHIS->FACTORY));
    MEMCPY_DN(MRASTOLHIS->TOOL_ID, MRASTOLHIS_N->TOOL_ID, sizeof(MRASTOLHIS->TOOL_ID));
    MRASTOLHIS->HIST_SEQ = MRASTOLHIS_N->HIST_SEQ;
    MEMCPY_DN(MRASTOLHIS->TOOL_TYPE, MRASTOLHIS_N->TOOL_TYPE, sizeof(MRASTOLHIS->TOOL_TYPE));
    MEMCPY_DN(MRASTOLHIS->TOOL_EVENT_ID, MRASTOLHIS_N->TOOL_EVENT_ID, sizeof(MRASTOLHIS->TOOL_EVENT_ID));
    MEMCPY_DN(MRASTOLHIS->TRAN_TIME, MRASTOLHIS_N->TRAN_TIME, sizeof(MRASTOLHIS->TRAN_TIME));
    MEMCPY_DN(MRASTOLHIS->SYS_TRAN_TIME, MRASTOLHIS_N->SYS_TRAN_TIME, sizeof(MRASTOLHIS->SYS_TRAN_TIME));
    MEMCPY_DN(MRASTOLHIS->TOOL_GRP, MRASTOLHIS_N->TOOL_GRP, sizeof(MRASTOLHIS->TOOL_GRP));
    MEMCPY_DN(MRASTOLHIS->TOOL_SET_ID, MRASTOLHIS_N->TOOL_SET_ID, sizeof(MRASTOLHIS->TOOL_SET_ID));
    MEMCPY_DN(MRASTOLHIS->TOOL_SET_LOCATION, MRASTOLHIS_N->TOOL_SET_LOCATION, sizeof(MRASTOLHIS->TOOL_SET_LOCATION));
    MEMCPY_DN(MRASTOLHIS->TOOL_STATUS, MRASTOLHIS_N->TOOL_STATUS, sizeof(MRASTOLHIS->TOOL_STATUS));
    MEMCPY_DN(MRASTOLHIS->LOT_ID, MRASTOLHIS_N->LOT_ID, sizeof(MRASTOLHIS->LOT_ID));
    MEMCPY_DN(MRASTOLHIS->SUBLOT_ID, MRASTOLHIS_N->SUBLOT_ID, sizeof(MRASTOLHIS->SUBLOT_ID));
    MEMCPY_DN(MRASTOLHIS->RES_ID, MRASTOLHIS_N->RES_ID, sizeof(MRASTOLHIS->RES_ID));
    MEMCPY_DN(MRASTOLHIS->SUBRES_ID, MRASTOLHIS_N->SUBRES_ID, sizeof(MRASTOLHIS->SUBRES_ID));
    MEMCPY_DN(MRASTOLHIS->MAT_ID, MRASTOLHIS_N->MAT_ID, sizeof(MRASTOLHIS->MAT_ID));
    MRASTOLHIS->MAT_VER = MRASTOLHIS_N->MAT_VER;
    MEMCPY_DN(MRASTOLHIS->FLOW, MRASTOLHIS_N->FLOW, sizeof(MRASTOLHIS->FLOW));
    MEMCPY_DN(MRASTOLHIS->OPER, MRASTOLHIS_N->OPER, sizeof(MRASTOLHIS->OPER));
    MEMCPY_DN(MRASTOLHIS->AREA_ID, MRASTOLHIS_N->AREA_ID, sizeof(MRASTOLHIS->AREA_ID));
    MEMCPY_DN(MRASTOLHIS->SUB_AREA_ID, MRASTOLHIS_N->SUB_AREA_ID, sizeof(MRASTOLHIS->SUB_AREA_ID));
    MEMCPY_DN(MRASTOLHIS->TOOL_LOCATION, MRASTOLHIS_N->TOOL_LOCATION, sizeof(MRASTOLHIS->TOOL_LOCATION));
    MEMCPY_DN(MRASTOLHIS->VENDOR_ID, MRASTOLHIS_N->VENDOR_ID, sizeof(MRASTOLHIS->VENDOR_ID));
    MEMCPY_DN(MRASTOLHIS->VENDOR_TOOL_ID, MRASTOLHIS_N->VENDOR_TOOL_ID, sizeof(MRASTOLHIS->VENDOR_TOOL_ID));
    MRASTOLHIS->CELL_COUNT_X = MRASTOLHIS_N->CELL_COUNT_X;
    MRASTOLHIS->CELL_COUNT_Y = MRASTOLHIS_N->CELL_COUNT_Y;
    MRASTOLHIS->CELL_COUNT_Z = MRASTOLHIS_N->CELL_COUNT_Z;
    MRASTOLHIS->CELL_SIZE_X = MRASTOLHIS_N->CELL_SIZE_X;
    MRASTOLHIS->CELL_SIZE_Y = MRASTOLHIS_N->CELL_SIZE_Y;
    MRASTOLHIS->CELL_SIZE_Z = MRASTOLHIS_N->CELL_SIZE_Z;
    MRASTOLHIS->GRADE = MRASTOLHIS_N->GRADE[0];
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_1, MRASTOLHIS_N->TOOL_STS_1, sizeof(MRASTOLHIS->TOOL_STS_1));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_2, MRASTOLHIS_N->TOOL_STS_2, sizeof(MRASTOLHIS->TOOL_STS_2));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_3, MRASTOLHIS_N->TOOL_STS_3, sizeof(MRASTOLHIS->TOOL_STS_3));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_4, MRASTOLHIS_N->TOOL_STS_4, sizeof(MRASTOLHIS->TOOL_STS_4));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_5, MRASTOLHIS_N->TOOL_STS_5, sizeof(MRASTOLHIS->TOOL_STS_5));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_6, MRASTOLHIS_N->TOOL_STS_6, sizeof(MRASTOLHIS->TOOL_STS_6));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_7, MRASTOLHIS_N->TOOL_STS_7, sizeof(MRASTOLHIS->TOOL_STS_7));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_8, MRASTOLHIS_N->TOOL_STS_8, sizeof(MRASTOLHIS->TOOL_STS_8));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_9, MRASTOLHIS_N->TOOL_STS_9, sizeof(MRASTOLHIS->TOOL_STS_9));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_10, MRASTOLHIS_N->TOOL_STS_10, sizeof(MRASTOLHIS->TOOL_STS_10));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_11, MRASTOLHIS_N->TOOL_STS_11, sizeof(MRASTOLHIS->TOOL_STS_11));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_12, MRASTOLHIS_N->TOOL_STS_12, sizeof(MRASTOLHIS->TOOL_STS_12));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_13, MRASTOLHIS_N->TOOL_STS_13, sizeof(MRASTOLHIS->TOOL_STS_13));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_14, MRASTOLHIS_N->TOOL_STS_14, sizeof(MRASTOLHIS->TOOL_STS_14));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_15, MRASTOLHIS_N->TOOL_STS_15, sizeof(MRASTOLHIS->TOOL_STS_15));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_16, MRASTOLHIS_N->TOOL_STS_16, sizeof(MRASTOLHIS->TOOL_STS_16));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_17, MRASTOLHIS_N->TOOL_STS_17, sizeof(MRASTOLHIS->TOOL_STS_17));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_18, MRASTOLHIS_N->TOOL_STS_18, sizeof(MRASTOLHIS->TOOL_STS_18));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_19, MRASTOLHIS_N->TOOL_STS_19, sizeof(MRASTOLHIS->TOOL_STS_19));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_20, MRASTOLHIS_N->TOOL_STS_20, sizeof(MRASTOLHIS->TOOL_STS_20));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_21, MRASTOLHIS_N->TOOL_STS_21, sizeof(MRASTOLHIS->TOOL_STS_21));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_22, MRASTOLHIS_N->TOOL_STS_22, sizeof(MRASTOLHIS->TOOL_STS_22));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_23, MRASTOLHIS_N->TOOL_STS_23, sizeof(MRASTOLHIS->TOOL_STS_23));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_24, MRASTOLHIS_N->TOOL_STS_24, sizeof(MRASTOLHIS->TOOL_STS_24));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_25, MRASTOLHIS_N->TOOL_STS_25, sizeof(MRASTOLHIS->TOOL_STS_25));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_26, MRASTOLHIS_N->TOOL_STS_26, sizeof(MRASTOLHIS->TOOL_STS_26));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_27, MRASTOLHIS_N->TOOL_STS_27, sizeof(MRASTOLHIS->TOOL_STS_27));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_28, MRASTOLHIS_N->TOOL_STS_28, sizeof(MRASTOLHIS->TOOL_STS_28));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_29, MRASTOLHIS_N->TOOL_STS_29, sizeof(MRASTOLHIS->TOOL_STS_29));
    MEMCPY_DN(MRASTOLHIS->TOOL_STS_30, MRASTOLHIS_N->TOOL_STS_30, sizeof(MRASTOLHIS->TOOL_STS_30));
    MRASTOLHIS->DELETE_FLAG = MRASTOLHIS_N->DELETE_FLAG[0];
    MEMCPY_DN(MRASTOLHIS->TOOL_COMMENT, MRASTOLHIS_N->TOOL_COMMENT, sizeof(MRASTOLHIS->TOOL_COMMENT));
    MEMCPY_DN(MRASTOLHIS->TRAN_USER_ID, MRASTOLHIS_N->TRAN_USER_ID, sizeof(MRASTOLHIS->TRAN_USER_ID));
    MEMCPY_DN(MRASTOLHIS->TRAN_COMMENT, MRASTOLHIS_N->TRAN_COMMENT, sizeof(MRASTOLHIS->TRAN_COMMENT));
    MRASTOLHIS->PREV_ACTIVE_HIST_SEQ = MRASTOLHIS_N->PREV_ACTIVE_HIST_SEQ;
    MRASTOLHIS->HIST_DEL_FLAG = MRASTOLHIS_N->HIST_DEL_FLAG[0];
    MEMCPY_DN(MRASTOLHIS->HIST_DEL_TIME, MRASTOLHIS_N->HIST_DEL_TIME, sizeof(MRASTOLHIS->HIST_DEL_TIME));
    MEMCPY_DN(MRASTOLHIS->HIST_DEL_USER_ID, MRASTOLHIS_N->HIST_DEL_USER_ID, sizeof(MRASTOLHIS->HIST_DEL_USER_ID));
    MEMCPY_DN(MRASTOLHIS->HIST_DEL_COMMENT, MRASTOLHIS_N->HIST_DEL_COMMENT, sizeof(MRASTOLHIS->HIST_DEL_COMMENT));
}


